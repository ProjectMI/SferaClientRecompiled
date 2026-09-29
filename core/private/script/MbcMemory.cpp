#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <format>
#include <functional>
#include <iterator>
#include <memory>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "binary/Binary.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "math/Vector.h"
#include "network/Network.h"
#include "numeric/Numeric.h"
#include "resources/FileResources.h"
#include "script/MbcBitStream.h"
#include "script/MbcRuntime.h"
#include "script/MbcValue.h"
#include "script/ScriptContainer.h"
#include "text/Text.h"
#include "text/TextBuffer.h"

// The runtime owns incomplete resource types; instantiate their lifetimes here.
SferaMbcRuntime::SferaMbcRuntime() = default;
SferaMbcRuntime::~SferaMbcRuntime() = default;

void SferaMbcRuntime::forgetNativeResource(const SferaMbcRuntimeNativeResource &resource)
{
    const auto entry = native_resource_ids.find(resource);
    if (entry == native_resource_ids.end())
        return;
    native_resources.erase(entry->second);
    native_resource_ids.erase(entry);
}

std::uint32_t SferaMbcRuntime::allocateDynamic(std::size_t size)
{
    if (size == 0 || size >= mappedAddressBegin)
        throw std::length_error("Invalid dynamic array size");
    auto block = native_space->createBytes(static_cast<std::uint32_t>(size));
    const auto address = block->address();
    dynamic_blocks.emplace(address, std::move(block));
    return address;
}

bool SferaMbcRuntime::releaseDynamic(std::uint32_t address) noexcept
{
    const auto found = dynamic_blocks.find(address);
    if (found == dynamic_blocks.end())
        return false;
    forgetMemory(found->second.get());
    dynamic_blocks.erase(found);
    native_space->requestCollection();
    return true;
}

void SferaMbcRuntime::destroyContainer(std::uint32_t handle) noexcept
{
    const auto found = containers.find(handle);
    if (found == containers.end())
        return;
    auto *container = found->second.get();
    forgetMemory(container);
    forgetNativeResource(container);
    containers.erase(found);
}

void SferaMbcRuntime::exportSlice(SferaSliceReference32 &destination, const void *data, std::size_t size, const void *owner)
{
    if (!destination.contains(SferaSliceReference32::scriptWidth))
        destination.diagnoseRange(SferaSliceReference32::scriptWidth);
    if (size >= mappedAddressBegin)
        throw std::length_error("Script container value too large");
    const auto offset = mapMemory(data, size, owner);
    writeMemory(destination.base, SferaSliceReference32{offset, offset, offset + SferaNumeric::lowWord(size) - 1u});
}

std::string SferaMbcRuntime::nextText()
{
    const auto slice = nextSlice();
    if (slice.base == 0)
    {
        reportError("poppointerup(): unexpected NULL-pointer fetched");
        return {};
    }
    return textIn(slice);
}

void SferaMbcRuntime::copyText(const SferaSliceReference32 &destination, std::string_view text)
{
    const auto length = text.size() + 1;
    if (length > UINT32_MAX || !destination.contains(SferaNumeric::lowWord(length)))
    {
        auto invalid = destination;
        invalid.diagnoseRange(SferaNumeric::lowWord(std::min<std::size_t>(length, UINT32_MAX)));
        return;
    }
    auto output = textBuffer(destination);
    if (length > output.size())
        throw std::out_of_range("Script string destination is too small");
    output.assign(text);
}


auto SferaMbcRuntime::sendRegionCaptureOrigin(SferaWorldSlotRecord &slot)
{
    SferaVec3F position;
    std::memcpy(&position, memoryAt(active_process->field_084, sizeof(position)), sizeof(position));
    slot.origin[0] = SferaMbcValue::truncate(position.x);
    slot.origin[1] = SferaMbcValue::truncate(position.y);
    slot.origin[2] = SferaMbcValue::truncate(position.z);
}

void SferaMbcRuntime::sendRegion(int slotIndex, std::uint32_t region, std::uint32_t flags)
{
    if (slotIndex < 0 || slotIndex >= std::size(g_sfera_mbc_runtime.world_slots) || active_process == nullptr)
        return;
    auto &slot = g_sfera_mbc_runtime.world_slots[slotIndex];
    if ((slot.state & 4) || findProcess(slot.linked_handle) == nullptr)
        return;
    const bool reliable = (flags & 1) != 0;
    auto &bitCount = reliable ? slot.reliable_bit_count : slot.unreliable_bit_count;
    auto &lastProcess = reliable ? slot.reliable_process : slot.unreliable_process;
    auto payload = std::span<std::uint8_t>(reliable ? slot.reliable_payload : slot.unreliable_payload, sizeof(slot.reliable_payload));

    if (!reliable && bitCount == 0)
        sendRegionCaptureOrigin(slot);
    constexpr std::size_t regionBitLimit = 4096;
    constexpr std::size_t maximumFieldBits = 34;
    std::array<std::uint8_t, (regionBitLimit + maximumFieldBits + 7) / 8> regionBuffer{};
    std::size_t regionBits = 0;
    SferaMbcBitStream encoded{std::span<std::uint8_t>(regionBuffer)};
    encoded.write(region + 1, 7);
    bool coordinatesValid = true;
    if (send_field_count > outgoing_fields.size())
    {
        reportError("Too long data for region");
        return;
    }
    for (std::uint32_t field = 0; field < send_field_count; ++field)
    {
        regionBits = encoded.position();
        if (regionBits >= regionBitLimit)
        {
            reportError("Too long data for region");
            return;
        }
        if (!encoded.writeField(outgoing_fields[field].format, outgoing_fields[field].word, slot.origin))
            coordinatesValid = false;
    }
    regionBits = encoded.position();
    if (!coordinatesValid)
    {
        regionBits = 0;
        return;
    }
    if (!encoded.valid() || bitCount > payload.size() * 8)
    {
        reportError("Too long data for region");
        return;
    }
    if (bitCount != 0 && bitCount + regionBits + 37 > 1600)
    {
        if (!g_sfera_network_runtime.sendPacket(reliable ? 8 : 0, payload.first((bitCount + 7) / 8)))
            return;
        lastProcess = UINT32_MAX;
        bitCount = 0;
        std::fill(payload.begin(), payload.end(), std::uint8_t{});
        if (!reliable)
            sendRegionCaptureOrigin(slot);
    }
    SferaMbcBitStream output(payload, bitCount);
    if (bitCount == 0)
    {
        const bool hasOrigin = !reliable && (active_process->flags & 2) == 0;
        output.write(hasOrigin, 1);
        if (hasOrigin)
        {
            output.write(slot.origin[0] + 32768u, 16);
            output.write(slot.origin[1] + 1200u, 13);
            output.write(slot.origin[2] + 32768u, 16);
        }
        output.write(SferaNumeric::word(SferaNumeric::signedWord(g_sfera_mbc_runtime.simulation_tick) >> 3), 15);
        lastProcess = UINT32_MAX;
    }
    if (lastProcess != active_process->process_id)
    {
        if (lastProcess != UINT32_MAX)
            output.write(63, 7);
        output.write(active_process->process_id, 18);
        output.write(active_process->module_tag, 12);
        lastProcess = active_process->process_id;
    }
    output.append(regionBuffer, regionBits);
    bitCount = SferaNumeric::lowWord(output.position());
    if (!output.valid())
        reportError("Too long data for region");
}

auto SferaMbcRuntime::buildRegionEmit(std::uint32_t value, std::int8_t width)
{
    if (send_field_count >= outgoing_fields.size())
    {
        reportError("Wrong data for 'send' function");
        return false;
    }
    outgoing_fields[send_field_count].word = value;
    outgoing_fields[send_field_count++].format = width;
    return true;
}

void SferaMbcRuntime::buildRegion()
{
    if (native_call->count < 1)
    {
        reportError("Wrong number of parameters for 'send' function");
        return;
    }
    auto region = nextInteger();
    --native_call->count;
    if (region == -2 || region == -4 || region == -5 || region == -7)
    {
        const auto prefix = region;
        region = nextInteger();
        --native_call->count;
        if (prefix == -7)
        {
            const auto cursor = native_call->cursor;
            nextInteger();
            nextSliceReference();
            nextInteger();
            nextSliceReference();
            nextInteger();
            if (execution_failed)
                return;
            native_call->cursor = cursor;
        }
    }
    else if (region == -1 || region == -3)
        return;
    if (region < 0 || region > 61 || active_process->regions.empty())
    {
        reportError("Wrong region for 'send' function");
        return;
    }
    const auto &definition = active_process->regions[region];
    if (definition.flags == -1)
    {
        reportError("Wrong flags for 'send' function");
        return;
    }
    send_field_count = 0;

    for (int field = 0; field < definition.field_count; ++field)
    {
        if (native_call->cursor >= native_call->arguments.size() || --native_call->count < 0)
        {
            reportError("Wrong number of parameters for 'send' function");
            return;
        }
        const auto value = native_call->arguments[native_call->cursor++].value.base;
        const int width = definition.formats[field];
        if ((width >= -32 && width <= 32) || (width >= 103 && width <= 108))
        {
            if (!buildRegionEmit(value, SferaNumeric::signedByte(SferaNumeric::lowByte(std::abs(width)))))
                return;
            continue;
        }
        if (width != 101 && width != 102)
        {
            reportError("Wrong data for 'send' function");
            return;
        }
        const auto count = std::clamp(SferaNumeric::signedWord(value), 0, width == 101 ? 15 : 255);
        if (!buildRegionEmit(count, width == 101 ? 4 : 8))
            return;
        if (--native_call->count < 0 || ++field >= definition.field_count || native_call->cursor >= native_call->arguments.size())
        {
            reportError("Wrong data for 'send' function");
            return;
        }
        const auto elementWidth = std::abs(definition.formats[field]);
        const auto &array = native_call->arguments[native_call->cursor];
        if (elementWidth > 32 || !array.isPointer())
        {
            reportError("Wrong data for 'send' function");
            return;
        }
        const auto elementSize = array.elementSize();
        ++native_call->cursor;
        if (elementSize > 4)
        {
            reportError("Wrong data for 'send' function");
            return;
        }
        const auto *data = memoryBytes(array.value.base, count * elementSize).data();
        for (int index = 0; index < count; ++index)
        {
            std::uint32_t item = 0;
            std::memcpy(&item, data, elementSize);
            data += elementSize;
            if (!buildRegionEmit(item, SferaNumeric::signedByte(SferaNumeric::lowByte(elementWidth))))
                return;
        }
    }
    sendRegion(400, SferaNumeric::word(region), SferaNumeric::word(definition.flags));
}


std::uint32_t SferaMbcRuntime::namedValue(std::string_view name, int index)
{
    const auto found = named_vectors.find(name);
    if (found == named_vectors.end())
        return 0;
    const auto &namedEntries = found->second;
    if (index < 0)
        return SferaNumeric::lowWord(namedEntries.size());
    const std::size_t offset = index;
    return offset < namedEntries.size() ? namedEntries[offset] : 0;
}

void SferaMbcRuntime::setNamedValue(std::string_view name, std::uint32_t value, int index)
{
    if (index < 0)
        return;
    auto found = named_vectors.find(name);
    if (found == named_vectors.end())
    {
        if (named_vectors.size() >= 1000u)
            return;
        found = named_vectors.try_emplace(std::string(name)).first;
    }
    auto &namedEntries = found->second;
    const std::size_t offset = index;
    const auto required = offset + 1u;
    if (required > namedEntries.max_size())
        throw std::length_error("Named values exceed array capacity");
    if (required > namedEntries.size())
        namedEntries.resize(required);
    namedEntries[offset] = value;
}


