#include "network/Network.h"
#include "numeric/Numeric.h"
#include "script/MbcBitStream.h"
#include "script/MbcRuntime.h"

// Packet-to-native-instance activation is independent of the Windows transport.
int SferaNetworkRuntime::tickDifference(std::uint32_t current, std::uint32_t previous)
{
    constexpr int maximumDistance = 14400;
    constexpr std::uint32_t period = 32768;
    const auto difference = current - previous;
    const auto signedDifference = SferaNumeric::signedWord(difference);
    const auto magnitude = signedDifference < 0 ? std::uint32_t{0} - difference : difference;
    if (SferaNumeric::signedWord(magnitude) <= maximumDistance)
        return signedDifference;
    return SferaNumeric::signedWord(signedDifference < 0 ? difference + period : difference - period);
}

void SferaNetworkRuntime::receiveEvents(std::span<const std::uint8_t> payload)
{
    if (payload.empty())
        return;
    auto &runtime = g_sfera_mbc_runtime;
    SferaMbcBitStream stream(payload);
    int origin[3]{};
    if (stream.read(1) != 0)
    {
        origin[0] = stream.read(16) - 32768;
        origin[1] = stream.read(13) - 1200;
        origin[2] = stream.read(16) - 32768;
    }
    const auto timestamp = stream.read(15);
    while (stream.valid())
    {
        const auto processId = stream.read(18);
        const auto moduleTag = stream.read(12);
        if (!stream.valid())
            return;
        auto *process = runtime.findProcess(processId);
        if (moduleTag == 0)
        {
            if (process != nullptr)
            {
                runtime.active_process = process;
                if (!process->activateProgram("EKill"))
                {
                    process->flags |= 4;
                    process->programs_queued = true;
                    runtime.enqueueProcess(processId, *process);
                }
                process->flags |= SferaMbcProcessRecordFlagsmarkedForUnload;
            }
            const auto next = stream.read(7);
            if (!stream.valid() || next == 0)
                return;
            if (next == 63)
                continue;
        }
        if (processId >= std::size(runtime.processes) || moduleTag >= 4096u)
            return;
        if (process == nullptr)
        {
            process = &runtime.processes[processId];
            if (process->process_id != processId)
            {
                const auto loaded = runtime.loadProcess(SferaNativeCatalog::moduleName(moduleTag), processId);
                process = runtime.findProcess(loaded);
                if (process == nullptr)
                    return;
            }
            process->flags |= 4;
            process->programs_queued = true;
            runtime.enqueueProcess(processId, *process);
        }
        runtime.active_process = process;
        while (stream.valid())
        {
            const auto command = stream.read(7);
            if (!stream.valid() || command == 0)
                return;
            if (command == 63)
                break;
            const auto regionIndex = command - 1;
            if (regionIndex > 61)
            {
                if (process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution)
                    runtime.unloadProcess(processId);
                return;
            }
            if (regionIndex == 0 || regionIndex == 61)
            {
                if (process->chain_prev_index == -1 || (process->flags & SferaMbcProcessRecordFlagsmarkedForUnload))
                {
                    if (process->chain_prev_index != -1)
                        runtime.unloadProcess(processId);
                    if (runtime.loadProcess(SferaNativeCatalog::moduleName(moduleTag), processId) == UINT32_MAX)
                        return;
                }
                process->flags &= ~4u;
                process->programs_queued = true;
                runtime.enqueueProcess(processId, *process);
            }
            if (process->regions.empty())
                return;
            const auto &region = process->regions[regionIndex];
            if (region.program_index != UINT16_MAX)
                process->activateProgram(region.program_index);
            if (region.field_count < 0)
            {
                if (process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution)
                    runtime.unloadProcess(processId);
                return;
            }
            const auto firstBit = stream.position();
            if (!stream.skipRegion(region))
                return;
            if (process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution)
                continue;
            if ((region.flags & 1) == 0 && SferaNumeric::signedWord(process->region_timestamps[regionIndex]) >= 0 && tickDifference(timestamp, process->region_timestamps[regionIndex]) < 0)
                continue;
            process->queueRegion(regionIndex, timestamp, origin, payload, firstBit, stream.position() - firstBit, true);
        }
    }
}
