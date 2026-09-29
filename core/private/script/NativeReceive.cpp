#include "script/MbcRuntime.h"
#include "script/MbcBitStream.h"

#include "network/Network.h"

#include <algorithm>
#include <cstring>

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
    if (native_call->count == 0 || native_call->cursor >= native_call->arguments.size())
    {
        receiveRegionWrongCount();
        return nullptr;
    }
    --native_call->count;
    return &native_call->arguments[native_call->cursor++];
}

auto SferaMbcRuntime::receiveRegionStore(const SferaMbcValue &target, std::uint32_t value)
{
    // Loading a signed byte promotes its expression type to Integer. Its
    // destination remains one byte; type alone cannot determine the store width.
    const auto size = target.width;
    if ((size != 1 && size != 4) || target.isPointer() || target.source.base == UINT32_MAX)
    {
        receiveRegionWrongData();
        return false;
    }
    std::memcpy(memoryAt(target.source.base, size), &value, size);
    return true;
}

void SferaMbcRuntime::receiveRegion()
{
    if (native_call->count == 0)
    {
        receiveRegionWrongCount();
        return;
    }
    const std::uint32_t region = nextInteger();
    --native_call->count;
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

void SferaMbcProcessRecord::queueRegion(std::size_t region, std::uint32_t timestamp, std::span<const int, 3> origin, std::span<const std::uint8_t> payload, std::size_t firstBit, std::size_t bitCount,
                                        bool ordered)
{
    if (region >= received_regions.size() || payload.size() > SIZE_MAX / 8 || firstBit > payload.size() * 8 || bitCount > payload.size() * 8 - firstBit)
        return;
    SferaMbcRegionPacket packet;
    packet.timestamp = timestamp;
    std::copy(origin.begin(), origin.end(), packet.origin.begin());
    // Ordered packets have a legacy trailing byte even when the payload ends on a byte boundary.
    const auto byteCount = bitCount / 8 + (ordered || bitCount % 8 != 0 ? 1 : 0);
    packet.data.resize(byteCount);
    SferaMbcBitStream source(payload, firstBit);
    SferaMbcBitStream destination{std::span<std::uint8_t>(packet.data)};
    for (auto remaining = bitCount; remaining != 0;)
    {
        const unsigned width = SferaNumeric::lowWord(std::min<std::size_t>(remaining, 32));
        destination.write(source.read(width), width);
        remaining -= width;
    }
    if (!source.valid() || !destination.valid())
        return;
    auto &queue = received_regions[region];
    if (queue == nullptr)
    {
        auto created = std::make_unique<std::list<SferaMbcRegionPacket>>();
        created->push_back(std::move(packet));
        queue = std::move(created);
        return;
    }
    auto position = queue->end();
    if (ordered)
    {
        position = queue->begin();
        while (position != queue->end() && SferaNetworkRuntime::tickDifference(timestamp, position->timestamp) >= 0)
            ++position;
    }
    queue->insert(position, std::move(packet));
}
