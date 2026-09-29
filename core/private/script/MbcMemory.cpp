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

std::uint8_t *SferaMbcRuntime::memoryAt(std::uint32_t address, std::size_t size, SferaMbcProcessRecord *process) const
{
    if (address < mappedAddressBegin)
    {
        auto *source = process != nullptr ? process : active_process;
        if (source == nullptr || source->memory.data() == nullptr || address > source->memory.size() || size > source->memory.size() - address)
            throw std::out_of_range("Script memory access outside process memory");
        return source->memory.data() + address;
    }
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin())
        throw std::out_of_range("Unknown script memory address");
    --entry;
    const auto &region = entry->second;
    const std::size_t offset = address - entry->first;
    if (offset > region.size || size > region.size - offset)
        throw std::out_of_range("Script memory access outside mapped region");
    if (region.process != nullptr)
    {
        if (region.process->memory.data() == nullptr || offset > region.process->memory.size() || size > region.process->memory.size() - offset)
            throw std::out_of_range("Script process memory is no longer available");
        return region.process->memory.data() + offset;
    }
    return const_cast<std::uint8_t *>(region.data) + offset;
}

std::span<std::uint8_t> SferaMbcRuntime::memoryRange(std::uint32_t address, SferaMbcProcessRecord *process) const
{
    if (address < mappedAddressBegin)
    {
        const auto *source = process ? process : active_process;
        if (!source || address > source->memory.size())
            throw std::out_of_range("Invalid process memory range");
        return {memoryAt(address, 0, process), source->memory.size() - address};
    }
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin())
        throw std::out_of_range("Unknown mapped memory range");
    --entry;
    const auto offset = (address - entry->first);
    const auto &region = entry->second;
    const auto size = region.process ? std::min(region.size, region.process->memory.size()) : region.size;
    if (offset > size)
        throw std::out_of_range("Invalid mapped memory range");
    return {memoryAt(address, size - offset), size - offset};
}
std::span<std::uint8_t> SferaMbcRuntime::memoryBytes(std::uint32_t address, std::size_t count, SferaMbcProcessRecord *process) const
{
    if (count == 0)
        return {};
    return {memoryAt(address, count, process), count};
}

SferaTextBuffer SferaMbcRuntime::textBufferAt(std::uint32_t address, SferaMbcProcessRecord *process) const
{
    return SferaTextBuffer(memoryRange(address, process));
}

std::uint64_t SferaMbcRuntime::memoryLifetime(std::uint32_t address) const
{
    if (address < mappedAddressBegin)
        return 0;
    auto entry = mapped_memory.upper_bound(address);
    if (entry == mapped_memory.begin())
        throw std::out_of_range("Unknown mapped memory lifetime");
    --entry;
    if (address - entry->first >= entry->second.size)
        throw std::out_of_range("Invalid mapped memory lifetime");
    return entry->second.lifetime;
}
std::span<std::uint8_t> SferaMbcRuntime::sliceBytes(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process) const
{
    auto bytes = memoryRange(slice.base, process);
    if (slice.begin != 0)
    {
        if (slice.base < slice.begin || slice.base > slice.end)
            throw std::out_of_range("Invalid bounded script slice");
        const std::uint64_t end = slice.end;
        const auto count = end - slice.base + 1;
        if (count < bytes.size())
            bytes = bytes.first(count);
    }
    return bytes;
}

std::span<std::uint8_t> SferaMbcRuntime::sliceBytes(const SferaSliceReference32 &slice, std::size_t count, SferaMbcProcessRecord *process) const
{
    if (count == 0)
        return {};
    return SferaBinary::range(sliceBytes(slice, process), 0, count);
}

SferaTextBuffer SferaMbcRuntime::textBuffer(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process) const
{
    return SferaTextBuffer(sliceBytes(slice, process));
}

std::string SferaMbcRuntime::textIn(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process) const
{
    // Preserve the MBC string ABI: the declared extent may exclude the NUL or
    // describe an addressed element. The owning memory region is the hard boundary.
    return SferaText::terminated(memoryRange(slice.base, process));
}

std::string SferaMbcRuntime::textIn(const SferaSliceReference32 &slice, std::size_t limit, SferaMbcProcessRecord *process) const
{
    if (limit == 0)
        return {};
    return SferaText::prefix(memoryRange(slice.base, process), limit);
}

std::string SferaMbcRuntime::textAt(std::uint32_t address) const
{
    return textIn({address, 0, 0});
}
std::string SferaMbcRuntime::textAt(std::uint32_t address, std::size_t limit) const
{
    return textIn({address, 0, 0}, limit);
}

std::uint32_t SferaMbcRuntime::addMemoryRegion(SferaMbcRuntimeMemoryRegion region)
{
    region.size = std::max<std::size_t>(region.size, 1);
    if (region.size >= mappedAddressBegin)
        throw std::length_error("Mapped script region too large");
    std::uint64_t candidate = mappedAddressBegin;
    for (const auto &[address, existing] : mapped_memory)
    {
        if (candidate + region.size < address)
            break;
        std::uint64_t candidate_address = address;
        candidate_address += existing.size + 1;
        candidate = candidate_address;
    }
    if (candidate + region.size > UINT32_MAX - 3u)
        throw std::length_error("Script address space exhausted");
    const std::uint32_t address = SferaNumeric::lowWord(candidate);
    if (next_memory_lifetime == 0)
        throw std::overflow_error("Memory mapping lifetime exhausted");
    region.lifetime = next_memory_lifetime++;
    mapped_memory.emplace(address, region);
    return address;
}

std::uint32_t SferaMbcRuntime::mapMemory(const void *data, std::size_t size, const void *owner)
{
    if (data == nullptr)
        return 0;
    const auto address = reinterpret_cast<std::uintptr_t>(data);
    if (active_process != nullptr && active_process->memory.data() != nullptr)
    {
        const auto base = reinterpret_cast<std::uintptr_t>(active_process->memory.data());
        if (address >= base && address - base <= active_process->memory.size() && size <= active_process->memory.size() - (address - base))
            return SferaNumeric::lowWord(address - base);
    }
    for (const auto &[mapped, region] : mapped_memory)
    {
        const auto *source = region.process != nullptr ? region.process->memory.data() : region.data;
        const auto base = reinterpret_cast<std::uintptr_t>(source);
        if (source != nullptr && address >= base && address - base <= region.size && size <= region.size - (address - base))
            return mapped + SferaNumeric::lowWord(address - base);
    }
    return addMemoryRegion({static_cast<const std::uint8_t *>(data), size, nullptr, owner});
}

std::uint32_t SferaMbcRuntime::mapProcessMemory(SferaMbcProcessRecord &process)
{
    if (&process == active_process)
        return 0;
    for (const auto &[address, region] : mapped_memory)
        if (region.process == &process && region.size >= process.memory.size())
            return address;
    return addMemoryRegion({nullptr, process.memory.size(), &process, &process});
}

SferaSliceReference32 SferaMbcRuntime::rebaseSlice(SferaSliceReference32 slice, SferaMbcProcessRecord &source)
{
    if (slice.base == 0 || slice.base >= mappedAddressBegin || &source == active_process)
        return slice;
    if (slice.base > source.memory.size() || (slice.begin != 0 && (slice.begin > source.memory.size() || slice.end >= source.memory.size())))
        throw std::out_of_range("Invalid cross-process script slice");
    const auto base = mapProcessMemory(source);
    slice.base += base;
    if (slice.begin != 0)
    {
        slice.begin += base;
        slice.end += base;
    }
    return slice;
}

bool SferaMbcRuntime::memoryOwnedBy(const void *owner, const std::pair<const std::uint32_t, SferaMbcRuntimeMemoryRegion> &entry)
{
    return entry.second.owner == owner;
}

void SferaMbcRuntime::forgetMemory(const void *owner)
{
    if (owner != nullptr)
        std::erase_if(mapped_memory, std::bind_front(&SferaMbcRuntime::memoryOwnedBy, owner));
}

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
    auto block = std::make_unique<std::vector<std::uint8_t>>(size);
    const auto *owner = block.get();
    const auto address = mapMemory(block->data(), block->size(), owner);
    try
    {
        dynamic_blocks.emplace(address, std::move(block));
    }
    catch (...)
    {
        forgetMemory(owner);
        throw;
    }
    return address;
}

bool SferaMbcRuntime::releaseDynamic(std::uint32_t address) noexcept
{
    const auto found = dynamic_blocks.find(address);
    if (found == dynamic_blocks.end())
        return false;
    forgetMemory(found->second.get());
    dynamic_blocks.erase(found);
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
    if (!destination.contains(sizeof(SferaSliceReference32)))
        destination.diagnoseRange(sizeof(SferaSliceReference32));
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

std::uint32_t SferaMbcRuntime::copyString(SferaTextBuffer destination, std::string_view source, int capacity)
{
    const auto limit = capacity > 0 ? std::min<std::size_t>(capacity, destination.size()) : destination.size();
    if (limit == 0)
        throw std::out_of_range("Empty script string destination");
    if (capacity <= 0 && source.size() >= limit)
        throw std::out_of_range("Script string destination is too small");
    if (source.size() >= limit)
    {
        g_sfera_mbc_runtime.diagnostic_context = std::format("MBINTER MESSAGE: Wrong string to copy: '{}', strlen: {}\n", source, source.size());
        g_sfera_log_runtime.write(g_sfera_mbc_runtime.diagnostic_context);
    }
    const auto copied = destination.limited(limit).write(source);
    return SferaNumeric::lowWord(copied + 1);
}

auto SferaMbcRuntime::receiveRegionWrongCount()
{
    reportError("Wrong number of parameters for 'receive' function");
}

auto SferaMbcRuntime::receiveRegionWrongData()
{
    reportError("Wrong data for 'receive' function");
}

auto SferaMbcRuntime::receiveRegionNextOutput() -> const SferaMbcValue *
{
    if (argument_count == 0 || argument_cursor >= argument_end || argument_cursor >= std::size(g_sfera_mbc_runtime.values))
    {
        receiveRegionWrongCount();
        return nullptr;
    }
    --argument_count;
    return &g_sfera_mbc_runtime.values[argument_cursor++];
}

auto SferaMbcRuntime::receiveRegionStore(const SferaMbcValue &target, std::uint32_t value)
{
    const auto size = SferaMbcValue::storageSize(target.type);
    if (size > sizeof(value) || target.source.base == UINT32_MAX)
    {
        receiveRegionWrongData();
        return false;
    }
    std::memcpy(memoryAt(target.source.base, size), &value, size);
    return true;
}

void SferaMbcRuntime::receiveRegion()
{
    if (argument_count == 0)
    {
        receiveRegionWrongCount();
        return;
    }
    const std::uint32_t region = nextInteger();
    --argument_count;
    if (execution_failed)
        return;
    if (region > 61 || active_process == nullptr || active_process->regions.empty())
    {
        reportError("Wrong region for 'receive' function");
        return;
    }
    auto &queue = active_process->received_regions[region];
    if (queue == nullptr || queue->empty())
    {
        pushInteger(UINT32_MAX);
        return;
    }
    auto packet = std::move(queue->front());
    queue->pop_front();
    if (queue->empty())
        queue.reset();
    SferaMbcBitStream stream{std::span<const std::uint8_t>(packet.data)};
    const auto &description = active_process->regions[region];
    if (std::cmp_greater(description.field_count, std::size(description.formats)))
    {
        receiveRegionWrongData();
        return;
    }

    for (int field = 0; field < description.field_count; ++field)
    {
        const auto format = description.formats[field];
        if (format == 'e' || format == 'f')
        {
            const auto encodedCount = stream.read(format == 'e' ? 4 : 8);
            if (!stream.valid() || field + 1 >= description.field_count)
            {
                receiveRegionWrongData();
                return;
            }
            const auto count = SferaMbcFieldHelper::mbc_array_count(encodedCount, format, description.formats[field + 1], stream.remaining());
            const auto *countOutput = receiveRegionNextOutput();
            if (countOutput == nullptr || !receiveRegionStore(*countOutput, count))
                return;
            const auto *array = receiveRegionNextOutput();
            if (array == nullptr)
                return;
            if (!array->isPointer())
            {
                receiveRegionWrongData();
                return;
            }
            ++field;
            const auto elementSize = array->elementSize();
            if (elementSize > sizeof(std::uint32_t))
            {
                receiveRegionWrongData();
                return;
            }
            if (count > SIZE_MAX / elementSize)
            {
                receiveRegionWrongData();
                return;
            }
            auto *destination = memoryAt(array->value.base, count * elementSize);
            for (std::uint32_t index = 0; index < count; ++index)
            {
                const auto value = stream.readField(description.formats[field], packet.origin);
                if (!stream.valid())
                {
                    receiveRegionWrongData();
                    return;
                }
                std::memcpy(destination, &value, elementSize);
                destination += elementSize;
            }
        }
        else
        {
            const auto value = stream.readField(format, packet.origin);
            if (!stream.valid())
            {
                receiveRegionWrongData();
                return;
            }
            const auto *destination = receiveRegionNextOutput();
            if (destination == nullptr || !receiveRegionStore(*destination, value))
                return;
        }
    }
    if ((description.flags & 1) == 0)
        active_process->region_timestamps[region] = packet.timestamp;
    pushInteger(packet.timestamp);
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
    if (argument_count < 1)
    {
        reportError("Wrong number of parameters for 'send' function");
        return;
    }
    auto region = nextInteger();
    --argument_count;
    if (region == -2 || region == -4 || region == -5 || region == -7)
    {
        const auto prefix = region;
        region = nextInteger();
        --argument_count;
        if (prefix == -7)
        {
            const auto stackSize = value_stack_size, cursor = argument_cursor;
            nextInteger();
            nextSliceReference();
            nextInteger();
            nextSliceReference();
            nextInteger();
            if (execution_failed)
                return;
            value_stack_size = stackSize;
            argument_cursor = cursor;
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
        if (argument_cursor >= argument_end || --argument_count < 0)
        {
            reportError("Wrong number of parameters for 'send' function");
            return;
        }
        const auto value = g_sfera_mbc_runtime.values[argument_cursor++].value.base;
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
        if (--argument_count < 0 || ++field >= definition.field_count || argument_cursor >= argument_end)
        {
            reportError("Wrong data for 'send' function");
            return;
        }
        const auto elementWidth = std::abs(definition.formats[field]);
        const auto &array = g_sfera_mbc_runtime.values[argument_cursor];
        if (elementWidth > 32 || !array.isPointer())
        {
            reportError("Wrong data for 'send' function");
            return;
        }
        const auto elementSize = array.elementSize();
        ++argument_cursor;
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

bool SferaSliceReference32::contains(std::uint32_t length, bool allowNull) const
{
    return (allowNull || (base >= 4 && base < UINT32_MAX - 3)) && (begin == 0 || (base >= begin && base <= end && (length == 0 || length - 1 <= end - base)));
}
void SferaSliceReference32::diagnoseRange(std::uint32_t length)
{
    WorldDiagnostics::describeScript(true);
    std::string message;
    if (length == 0)
        message = std::format("{}\n Slice out of range! ptr = {}, begin = {}, end = {}", g_sfera_mbc_runtime.diagnostic_context, SferaNumeric::signedWord(base), SferaNumeric::signedWord(begin),
                              SferaNumeric::signedWord(end + 1));
    else
        message = std::format("{}\n Slice out of range! ptr = {}, ptr+offset = {}, begin = {}, end = {}", g_sfera_mbc_runtime.diagnostic_context, SferaNumeric::signedWord(base),
                              SferaNumeric::signedWord(base + length), SferaNumeric::signedWord(begin), SferaNumeric::signedWord(end + 1));
    WorldDiagnostics::warning(message);
    // The interpreter diagnoses and extends the recorded bounds; it does not clamp the pointer.
    if (base == 0 || begin == 0 || (base >= begin && base <= end))
        return;
    if (SferaNumeric::signedWord(base) < SferaNumeric::signedWord(begin))
        begin = base;
    else if (SferaNumeric::signedWord(base + length - 1) > SferaNumeric::signedWord(end))
        end = base + length - 1;
}
bool SferaMbcValue::isPointer() const
{
    return type % 16 != 0;
}
std::int32_t SferaMbcValue::integer() const
{
    std::int32_t result{};
    std::memcpy(&result, &value.base, sizeof(result));
    return result;
}
float SferaMbcValue::real() const
{
    float result{};
    std::memcpy(&result, &value.base, sizeof(result));
    return result;
}
std::int32_t SferaMbcValue::truncate(double number)
{
    constexpr double minimum = INT32_MIN;
    constexpr double maximumExclusive = double{INT32_MAX} + 1.0;
    if (!std::isfinite(number) || number < minimum || number >= maximumExclusive)
        return INT32_MIN;
    return SferaNumeric::truncateInt(number);
}
std::int32_t SferaMbcValue::asInteger() const
{
    switch (type)
    {
    case SferaMbcValueTypeByte:
    {
        const std::uint8_t byte = value.base & 0xffu;
        std::int8_t signedByte{};
        std::memcpy(&signedByte, &byte, sizeof(byte));
        return signedByte;
    }
    case SferaMbcValueTypeReal:
        return truncate(real());
    default:
        return integer();
    }
}
std::uint32_t SferaMbcValue::asWord() const
{
    const std::int32_t number = asInteger();
    std::uint32_t result{};
    std::memcpy(&result, &number, sizeof(result));
    return result;
}
float SferaMbcValue::asReal() const
{
    if (type == SferaMbcValueTypeReal)
        return real();
    const std::int32_t number = asInteger();
    return SferaNumeric::real32(number);
}
void SferaMbcValue::setReal(float number)
{
    std::memcpy(&value.base, &number, sizeof(number));
}
void SferaMbcValue::setReal(double number)
{
    setReal(SferaNumeric::real32(number));
}
void SferaMbcValue::detach()
{
    source = {UINT32_MAX, 1, 1};
}
SferaSliceReference32 &SferaMbcValue::asSlice()
{
    if (!isPointer())
        value.begin = value.end = 0;
    return value;
}

std::size_t SferaMbcValue::storageSize(SferaMbcValueType valueType)
{
    return valueType == SferaMbcValueTypeByte ? sizeof(std::int8_t) : valueType % SferaMbcValueTypeInteger == 0 ? sizeof(std::uint32_t) : sizeof(SferaSliceReference32);
}

std::size_t SferaMbcValue::elementSize() const
{
    return storageSize(SferaNumeric::enumFromBits<SferaMbcValueType>(SferaNumeric::lowByte(SferaNumeric::enumBits(type) - 1u)));
}

void SferaMbcValue::storeAs(SferaMbcValueType destinationType, std::span<std::uint8_t> destination) const
{
    const auto required = destinationType == SferaMbcValueTypeByte                                                  ? sizeof(std::uint8_t)
                          : destinationType == SferaMbcValueTypeInteger || destinationType == SferaMbcValueTypeReal ? sizeof(std::uint32_t)
                                                                                                                    : sizeof(SferaSliceReference32);
    if (destination.size() < required)
        throw std::out_of_range("Script parameter destination is too small");
    const auto sourceType = type;
    const auto integerValue = sourceType == SferaMbcValueTypeReal ? truncate(real()) : integer();
    switch (destinationType)
    {
    case SferaMbcValueTypeByte:
    {
        const std::uint8_t number = SferaNumeric::lowByte(integerValue);
        std::memcpy(destination.data(), &number, sizeof(number));
        break;
    }
    case SferaMbcValueTypeInteger:
        std::memcpy(destination.data(), &integerValue, sizeof(integerValue));
        break;
    case SferaMbcValueTypeReal:
    {
        const float number = sourceType == SferaMbcValueTypeReal ? real() : integer();
        std::memcpy(destination.data(), &number, sizeof(number));
        break;
    }
    default:
    {
        const auto reference = sourceType == SferaMbcValueTypeByte || sourceType == SferaMbcValueTypeInteger || sourceType == SferaMbcValueTypeReal
                                   ? SferaSliceReference32{SferaNumeric::word(integerValue), 0, 0}
                                   : value;
        std::memcpy(destination.data(), &reference, sizeof(reference));
        break;
    }
    }
}

std::int64_t SferaMbcValue::truncateReal(double number)
{
    return SferaNumeric::truncateInt64(number);
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
