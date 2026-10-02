#include <windows.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fcntl.h>
#include <format>
#include <iterator>
#include <list>
#include <memory>
#include <mmsystem.h>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "application/ClientApplication.h"
#include "binary/Binary.h"
#include "diagnostics/ClientDiagnostics.h"
#include "diagnostics/Diagnostics.h"
#include "effects/EffectManager.h"
#include "input/DirectInputDevices.h"
#include "lifetime/Restore.h"
#include "network/Network.h"
#include "numeric/Numeric.h"
#include "players/PlayerLists.h"
#include "resources/FileResources.h"
#include "script/ConfigText.h"
#include "script/MbcBitStream.h"
#include "script/MbcCommands.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/GeneratedScripts.h"
#include "script/MbcValue.h"
#include "script/ScriptContainer.h"
#include "ui/GameInterfaceManager.h"
#include "ui/ScriptInterface.h"
#include "ui/Window.h"
#include "world/GameCalendar.h"
#include "world/WorldObjects.h"

void SferaMbcRuntime::enqueueProcess(int index, SferaMbcProcessRecord &process)
{
    if (process.execution_linked || index < 0)
        return;
    ++execution_chain_count;
    process.execution_linked = true;
    process.execution_prev_index = -1;
    if (execution_chain_tail < 0)
    {
        if (execution_chain_head >= 0)
            g_sfera_log_runtime.write("internal error 34096874309");
        execution_chain_head = execution_chain_tail = index;
        process.execution_next_index = -1;
    }
    else
    {
        if (execution_chain_head < 0)
        {
            reportError("internal error 04975350934760");
            return;
        }
        processes[execution_chain_head].execution_prev_index = index;
        process.execution_next_index = execution_chain_head;
        execution_chain_head = index;
    }
}
void SferaMbcRuntime::dequeueProcess(SferaMbcProcessRecord &process)
{
    if (!process.execution_linked)
        return;
    --execution_chain_count;
    process.execution_linked = false;
    if (process.execution_next_index != -1)
        processes[process.execution_next_index].execution_prev_index = process.execution_prev_index;
    else
        execution_chain_tail = process.execution_prev_index;
    if (process.execution_prev_index != -1)
        processes[process.execution_prev_index].execution_next_index = process.execution_next_index;
    else
        execution_chain_head = process.execution_next_index;
}

void SferaMbcRuntime::shutdown()
{
    final_shutdown = true;
    g_sfera_config_text_runtime.clear();
    dispatch_slot = -1;
    g_sfera_network_runtime.shutdown();
    for (std::uint32_t index = 0; index < std::size(processes); ++index)
        if (processes[index].chain_prev_index >= 0)
            unloadProcess(index);
    while (!containers.empty())
        destroyContainer(containers.begin()->first);
    while (!dynamic_blocks.empty())
        releaseDynamic(dynamic_blocks.begin()->first);
    clearMappedMemory();
    native_resources.clear();
    native_resource_ids.clear();
    named_vectors.clear();
    active_process = nullptr;
    active_program_record = nullptr;
    program_table_base = nullptr;
    process_chain_first = process_chain_last = execution_chain_head = execution_chain_tail = -1;
    execution_chain_count = 0;
    engine_arguments = {};
    engine_result.reset();
    current = {};
    execution = nullptr;
    g_sfera_mbc_runtime.dispatch_slot = -1;
}

void SferaMbcRuntime::initialize()
{
    std::srand(::timeGetTime());
    g_sfera_player_lists.clear();
    shutdown();
    first_execution_error.clear();
    final_shutdown = false;
    next_native_handle = 1;
    process_search_cursor = 0;
    g_sfera_mbc_runtime.dispatch_slot = -1;
    g_sfera_mbc_runtime.simulation_tick = 0;
    g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::pack(7801, 1, 1, 8, 0);
    halt_state = SferaMbcRuntimeHaltState::Running;
    g_sfera_world_objects.controlled_object_handle = UINT32_MAX;
    g_sfera_config_text_runtime.clear();
    g_sfera_direct_input_runtime.text_filter = 0;
    for (std::size_t index = 0; index < 400; ++index)
        g_sfera_mbc_runtime.world_slots[index].state = 4;
    g_sfera_mbc_runtime.active_world_slot = 400;
    auto &slot = g_sfera_mbc_runtime.world_slots[400];
    slot.primary_state = UINT32_MAX;
    slot.state = 2;
    slot.object_handle = 1;
    slot.reliable_bit_count = 0;
    slot.unreliable_bit_count = 0;
    std::fill(std::begin(slot.reliable_payload), std::end(slot.reliable_payload), std::uint8_t{});
    std::fill(std::begin(slot.unreliable_payload), std::end(slot.unreliable_payload), std::uint8_t{});
    slot.reliable_process = UINT32_MAX;
    slot.unreliable_process = UINT32_MAX;
    g_sfera_config_text_runtime.load("connectn.cfg");
    int port = 0;
    if (g_sfera_config_text_runtime.readInteger("PORT", port))
        g_sfera_network_runtime.server_port = SferaNumeric::lowHalf(SferaNumeric::word(port));
    if (loadProcess("_main", 0) == UINT32_MAX)
        SferaClientApplication::terminateWithError("MBInter: Process '_main' not found");
    named_vectors.clear();
    g_sfera_effect_manager.pending_effect = nullptr;
    g_sfera_mbc_runtime.game_calendar = SferaGameCalendar::fromUnixTime(::_time64(nullptr));
}

auto SferaMbcRuntime::tickFlush(std::uint32_t &bits, auto &payload, std::uint32_t &owner, std::uint32_t flags)
{
    if (SferaNumeric::signedWord(bits) <= 0)
        return;
    const auto bytes = (bits + 7) >> 3;
    if (!g_sfera_network_runtime.sendPacket(flags, std::span<const std::uint8_t>(payload, bytes)))
        return;
    bits = 0;
    std::fill(std::begin(payload), std::end(payload), std::uint8_t{});
    owner = UINT32_MAX;
}

void SferaMbcRuntime::tick()
{
    if (dispatch_slot >= 0)
        return;
    SferaRestore dispatchScope(dispatch_slot);
    ++g_sfera_mbc_runtime.simulation_tick;
    if (++g_sfera_network_runtime.statistics_poll_ticks >= 192)
    {
        g_sfera_network_runtime.updateTcpStatistics();
        g_sfera_network_runtime.statistics_poll_ticks = 0;
    }
    if (halt_state != SferaMbcRuntimeHaltState::Running)
    {
        for (auto &process : processes)
        {
            if (process.chain_prev_index == -1)
                continue;
            active_process = &process;
            std::fill(std::begin(process.program_map_a), std::end(process.program_map_a), UINT16_MAX);
            std::fill(std::begin(process.program_map_b), std::end(process.program_map_b), UINT16_MAX);
            process.activateProgram("EPHalt");
        }
        halt_state = SferaMbcRuntimeHaltState::Dispatched;
    }
    const int simulationTick = g_sfera_mbc_runtime.simulation_tick;
    const std::size_t priorityLimit = simulationTick % 24 == 0 ? 2 : simulationTick % 8 == 0 ? 1 : 0;
    auto scheduled = execution_chain_tail;
    while (scheduled >= 0 && std::cmp_less(scheduled, std::size(processes)))
    {
        auto &process = processes[scheduled];
        const auto lifetime = process.lifetime;
        const auto next = process.execution_prev_index;
        const bool last = scheduled == execution_chain_head;
        if (process.chain_prev_index >= 0)
        {
            dispatch_slot = scheduled;
            execution_failed = false;
            for (std::size_t priority = 0; priority <= priorityLimit && !execution_failed; ++priority)
            {
                auto index = SferaNumeric::signedHalf(process.program_map_a[priority]);
                std::size_t visits = 0;
                while (index >= 0 && std::cmp_less(index, process.programs.size()) && visits++ < 32768)
                {
                    const auto following = process.programs[index].next_program;
                    const bool tail = index == SferaNumeric::signedHalf(process.program_map_b[priority]);
                    try { runProgram(process, std::size_t(index)); }
                    catch (const SferaClientApplicationExitRequested &) { throw; }
                    catch (const std::exception &error) { reportError(error.what()); }
                    if (execution_failed || process.chain_prev_index < 0 || process.lifetime != lifetime || tail)
                        break;
                    index = SferaNumeric::signedHalf(following);
                }
            }
            if (process.lifetime == lifetime && process.chain_prev_index >= 0 &&
                (execution_failed || (process.flags & SferaMbcProcessRecordFlagsunloadAfterExecution) != 0))
                unloadProcess(SferaNumeric::word(scheduled));
        }
        if (last)
            break;
        scheduled = next;
    }
    execution = nullptr;
    current = {};
    g_sfera_mbc_runtime.dispatch_slot = -1;
    if (halt_state == SferaMbcRuntimeHaltState::Dispatched)
    {
        if (!final_shutdown)
            initialize();
        return;
    }
    if (SferaNumeric::signedWord(g_sfera_mbc_runtime.simulation_tick) % 3 == 0)
    {
        g_sfera_network_runtime.receiveMessages();
        for (int index = SferaNumeric::signedWord(SferaNumeric::lowWord(g_sfera_mbc_runtime.active_world_slot)); index >= 0;)
        {
            auto &slot = g_sfera_mbc_runtime.world_slots[index];
            index = slot.primary_state;

            tickFlush(slot.reliable_bit_count, slot.reliable_payload, slot.reliable_process, 8);
            tickFlush(slot.unreliable_bit_count, slot.unreliable_payload, slot.unreliable_process, 0);
        }
    }
}

void SferaMbcProcessRecord::appendCommand(std::string_view command)
{
    // The leading CRLF and conservative 127-byte command limit are part of ReadCommands.
    if (command.size() > 123u || physics_commands.size() > 123u - command.size())
        return;
    physics_commands += "\r\n";
    physics_commands.append(command);
}

void SferaMbcProcessRecord::linkProgram(std::size_t index)
{
    auto &program = programs.data()[index];
    const std::int16_t previous = program_map_b[program.priority];
    if (previous < 0)
    {
        program_map_a[program.priority] = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
        program.previous_program = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
    }
    else
    {
        programs.data()[previous].next_program = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
        program.previous_program = SferaNumeric::lowHalf(SferaNumeric::word(previous));
    }
    program_map_b[program.priority] = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
    program.next_program = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
    programs_queued = true;
    g_sfera_mbc_runtime.enqueueProcess(process_id, *this);
}
bool SferaMbcProcessRecord::activateProgram(std::size_t index)
{
    if (index >= programs.size())
        return false;
    auto &program = programs[index];
    if (program.state < 0)
        linkProgram(index);
    if (program.state != 1 && (!program.continuation || !program.continuation->running))
    {
        program.continuation.reset();
        program.cleanup_requested = false;
    }
    program.state = 1;
    programs_queued = true;
    return true;
}
bool SferaMbcProcessRecord::activateProgram(std::string_view programName)
{
    if (programs.empty())
        return false;
    for (std::size_t index = 0; index < programs.size(); ++index)
    {
        if (programs[index].name != programName)
            continue;
        activateProgram(index);
        g_sfera_mbc_runtime.enqueueProcess(process_id, *this);
        return true;
    }
    return false;
}

std::uint64_t *SferaMbcProcessRecord::resourceLifetime(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind)
{
    if (kind == SferaMbcProcessRecordResourceKind::gameWindow)
    {
        if (auto *item = GameInterface::window(handle))
            return &item->resource_lifetime;
    }
    else if (kind == SferaMbcProcessRecordResourceKind::worldObject)
    {
        if (auto *item = g_sfera_world_objects.object(handle))
            return &item->resource_lifetime;
    }
    else if (kind == SferaMbcProcessRecordResourceKind::textControl || kind == SferaMbcProcessRecordResourceKind::spriteControl)
    {
        if (auto *item = WorldGuiControls::control(handle))
            return &item->resource_lifetime;
    }
    return nullptr;
}

bool SferaMbcProcessRecord::resourceIsCurrent(const SferaMbcProcessRecordCleanupEntry &entry)
{
    if (entry.resource_lifetime == 0)
        return true;
    const auto *lifetime = resourceLifetime(entry.handle, entry.kind);
    return lifetime && *lifetime == entry.resource_lifetime;
}

void SferaMbcProcessRecord::registerResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind)
{
    auto *resourceLifetimeValue = resourceLifetime(handle, kind);
    static std::uint64_t nextLifetime = 1;
    if (resourceLifetimeValue && *resourceLifetimeValue == 0 && nextLifetime == 0)
        throw std::overflow_error("Resource lifetime IDs exhausted");
    const auto id = resourceLifetimeValue ? (*resourceLifetimeValue != 0 ? *resourceLifetimeValue : nextLifetime) : 0;
    cleanup_entries.push_back({handle, kind, id});
    if (resourceLifetimeValue && *resourceLifetimeValue == 0)
    {
        *resourceLifetimeValue = id;
        ++nextLifetime;
    }
}

void SferaMbcProcessRecord::unregisterResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind)
{
    auto found = cleanup_entries.begin();
    while (found != cleanup_entries.end() && !(found->handle == handle && found->kind == kind))
        ++found;
    if (found != cleanup_entries.end())
        cleanup_entries.erase(found);
}

SphereScripts::Method SferaMbcProcessRecord::findFunction(std::string_view name)
{
    for (const auto &module : modules)
        if (auto method = module->localMethod(name, true))
            return method;
    return {};
}

void SferaMbcProcessRecord::readRegions(SphereScripts::Module &module)
{
    for (const auto &definition : module.regions())
    {
        if (definition.index >= regions.size())
            continue;
        auto &region = regions[definition.index];
        if (region.flags == -1)
        {
            region.flags = definition.flags;
            region.field_count = SferaNumeric::signedWord(SferaNumeric::lowWord(std::min(definition.format.size(), std::size(region.formats))));
            std::copy_n(definition.format.begin(), region.field_count, region.formats);
        }
        if (region.program_index == UINT16_MAX && definition.program != SphereScripts::Entry::None)
        {
            const auto index = findProgram(module, SphereScripts::entryName(definition.program));
            if (index >= 0)
                region.program_index = SferaNumeric::lowHalf(SferaNumeric::word(index));
        }
    }
}

void SferaMbcProcessRecord::releaseResources()
{
    const auto pending = std::exchange(cleanup_entries, {});
    for (const auto &entry : pending)
    {
        try
        {
            if (!resourceIsCurrent(entry))
                continue;
            if (entry.kind == SferaMbcProcessRecordResourceKind::textControl)
                WorldGuiControls::destroyText(entry.handle);
            else if (entry.kind == SferaMbcProcessRecordResourceKind::spriteControl)
                WorldGuiControls::destroySprite(entry.handle);
        }
        catch (const std::exception &error)
        {
            ::OutputDebugStringA(error.what());
        }
        catch (...)
        {
            ::OutputDebugStringA("Process resource cleanup failed");
        }
    }
    for (const auto &entry : pending)
    {
        try
        {
            if (!resourceIsCurrent(entry))
                continue;
            switch (entry.kind)
            {
            case SferaMbcProcessRecordResourceKind::worldObject:
                g_sfera_world_objects.destroy(entry.handle);
                break;
            case SferaMbcProcessRecordResourceKind::dynamicArray:
            {
                std::uint32_t offset{};
                const auto *source = g_sfera_mbc_runtime.memoryAt(entry.handle, sizeof(offset));
                if (source == nullptr)
                    break;
                std::memcpy(&offset, source, sizeof(offset));
                g_sfera_mbc_runtime.releaseDynamic(offset);
                break;
            }
            case SferaMbcProcessRecordResourceKind::gameWindow:
                GameInterface::destroyWindow(entry.handle);
                break;
            case SferaMbcProcessRecordResourceKind::interfaceWindow:
                g_sfera_interface.closeWindow(g_sfera_mbc_runtime.nativeResource<SphereUIWindow *>(entry.handle), true);
                break;
            case SferaMbcProcessRecordResourceKind::container:
            {
                auto *container = g_sfera_mbc_runtime.nativeResource<SferaScriptContainer *>(entry.handle);
                if (container != nullptr && container->header.kind >= SferaDataContainerHeaderKind::List && container->header.kind <= SferaDataContainerHeaderKind::HashMap)
                    g_sfera_mbc_runtime.destroyContainer(entry.handle);
                break;
            }
            default:
                break;
            }
        }
        catch (const std::exception &error)
        {
            ::OutputDebugStringA(error.what());
        }
        catch (...)
        {
            ::OutputDebugStringA("Process resource cleanup failed");
        }
    }
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

std::int32_t SferaMbcRuntime::nextInteger()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return 0;
    }
    return engine_arguments[argument_cursor++].asInteger();
}
std::uint32_t SferaMbcRuntime::nextWord()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return 0u;
    }
    return engine_arguments[argument_cursor++].asWord();
}
float SferaMbcRuntime::nextReal()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return 0;
    }
    return engine_arguments[argument_cursor++].asReal();
}
SferaSliceReference32 &SferaMbcRuntime::nextSliceReference(std::string_view diagnostic)
{
    if (argument_cursor >= argument_end)
    {
        reportError(diagnostic);
        g_sfera_mbc_runtime.sliceup_fallback = {};
        return g_sfera_mbc_runtime.sliceup_fallback;
    }
    return engine_arguments[argument_cursor++].asSlice();
}
SferaSliceReference32 SferaMbcRuntime::nextSlice()
{
    return nextSliceReference("popsliceup(): stack underflow");
}
SferaSliceReference32 SferaMbcRuntime::nextAddress()
{
    if (argument_cursor >= argument_end)
    {
        reportError("Too few parameters");
        return {};
    }
    const auto &argument = engine_arguments[argument_cursor++];
    if (argument.isPointer())
        return argument.value;
    return {argument.asWord(), 0, 0};
}
void SferaMbcRuntime::pushInteger(std::uint32_t number)
{
    SferaMbcValue result{};
    result.type = SferaMbcValueTypeInteger;
    result.value.base = number;
    result.detach();
    engine_result = result;
}
void SferaMbcRuntime::pushReal(float number)
{
    SferaMbcValue result{};
    result.type = SferaMbcValueTypeReal;
    result.setReal(number);
    result.detach();
    engine_result = result;
}
void SferaMbcRuntime::pushReal(double number)
{
    pushReal(SferaNumeric::real32(number));
}
void SferaMbcRuntime::pushSlice(const SferaSliceReference32 &value, SferaMbcValueType type)
{
    SferaMbcValue result{};
    result.type = type;
    result.value = value;
    result.detach();
    engine_result = result;
}

SphereScripts::Address SferaMbcRuntime::mapObject(const void *address, std::size_t size, const void *owner)
{
    const auto base = mapMemory(address, size, owner);
    return {base, base, base + SferaNumeric::lowWord(size) - 1u};
}

void SferaMbcRuntime::forgetObject(const void *owner) noexcept
{
    forgetMemory(owner);
}

std::span<std::byte> SferaMbcRuntime::memory(SphereScripts::Address address)
{
    return std::as_writable_bytes(memoryRange(address.base));
}

std::span<std::byte> SferaMbcRuntime::memory(SphereScripts::Address address, std::size_t size)
{
    return std::as_writable_bytes(std::span(memoryAt(address.base, size), size));
}

bool SferaMbcRuntime::alive(const SphereScripts::Module &module) const noexcept
{
    return module.processId < std::size(processes) && processes[module.processId].chain_prev_index >= 0 &&
           processes[module.processId].lifetime == module.lifetime;
}

void SferaMbcRuntime::warning(std::string_view message)
{
    WorldDiagnostics::warning(message);
}

void SferaMbcRuntime::selectContext(SphereScripts::Context context)
{
    if (!context.module)
    {
        current = context;
        return;
    }
    if (!alive(*context.module))
        throw std::runtime_error("Return to defunct native script process");
    current = context;
    process_index = SferaNumeric::signedWord(context.module->processId);
    active_process = &processes[process_index];
    program_table_base = active_process->programs.data();
    const auto *module = execution ? execution->rootModule : context.module;
    std::string_view program = execution ? std::string_view(execution->rootProgram) : context.function;
    auto *cachedIndex = execution ? &execution->rootProgramIndex : nullptr;
    if (execution && !execution->calls.empty())
    {
        module = execution->calls.back().callee;
        program = execution->calls.back().program;
        cachedIndex = &execution->calls.back().programIndex;
    }
    if (cachedIndex && *cachedIndex >= 0 && std::cmp_less(*cachedIndex, active_process->programs.size()) &&
        active_process->programs[*cachedIndex].module.get() == module && active_process->programs[*cachedIndex].name == program)
        program_index = *cachedIndex;
    else
    {
        program_index = module ? active_process->findProgram(*module, program) : -1;
        if (cachedIndex)
            *cachedIndex = program_index;
    }
    active_program_record = program_index >= 0 ? &active_process->programs[program_index] : nullptr;
}

void SferaMbcRuntime::returnFirstArgument()
{
    if (engine_arguments.empty())
        throw std::invalid_argument("Engine call has no destination argument");
    engine_result = engine_arguments.front();
}

SphereScripts::Value SferaMbcRuntime::invokeEngine(SferaMbcRuntimeBuiltin command, std::span<const SphereScripts::Argument> arguments)
{
    if (!current.module || !alive(*current.module))
        throw std::runtime_error("Engine call from an expired native script");
    if (arguments.size() > 256)
        throw std::length_error("Too many engine call arguments");
    std::array<SferaMbcValue, 16> localValues;
    std::vector<SferaMbcValue> overflowValues;
    if (arguments.size() > localValues.size())
        overflowValues.resize(arguments.size());
    auto values = arguments.size() <= localValues.size() ? std::span(localValues).first(arguments.size()) : std::span(overflowValues);
    for (std::size_t index = 0; index < arguments.size(); ++index)
    {
        const auto &argument = arguments[index];
        auto &value = values[index];
        value.type = SferaNumeric::enumFromBits<SferaMbcValueType>(SferaNumeric::lowByte(argument.value.type));
        value.width = SferaMbcValue::storageSize(value.type);
        value.value = {argument.value.bits.base, argument.value.bits.begin, argument.value.bits.end};
        value.source = {argument.source.base, argument.source.begin, argument.source.end};
    }
    SferaRestore builtinScope(active_builtin);
    active_builtin = command;
    SferaRestore argumentsScope(engine_arguments);
    SferaRestore resultScope(engine_result);
    SferaRestore countScope(argument_count);
    SferaRestore cursorScope(argument_cursor);
    SferaRestore endScope(argument_end);
    engine_arguments = values;
    engine_result.reset();
    argument_count = SferaNumeric::signedWord(SferaNumeric::lowWord(values.size()));
    argument_cursor = 0;
    argument_end = values.size();
    if (!executeBuiltin(command))
        throw std::runtime_error("Unknown native script engine command");
    if (execution_failed)
        throw std::runtime_error(first_execution_error.empty() ? "Native script engine call failed" : first_execution_error);
    if (!engine_result)
        return {};
    SphereScripts::Value result;
    result.type = SferaNumeric::enumBits(engine_result->type);
    result.bits = {engine_result->value.base, engine_result->value.begin, engine_result->value.end};
    result.present = true;
    return result;
}

SphereScripts::Task<SphereScripts::Value> SferaMbcRuntime::callProcess(SphereScripts::Module &caller, bool mainProcess,
                                                                     std::vector<SphereScripts::Argument> arguments)
{
    const auto required = mainProcess ? 1u : 2u;
    const auto failed = [this]
    {
        active_tag = UINT32_MAX;
        return SphereScripts::Value(std::int32_t{-1});
    };
    if (arguments.size() < required)
        co_return failed();
    const auto targetId = mainProcess ? 0u : SphereScripts::word(SphereScripts::integer(arguments.front().value));
    auto *target = !mainProcess && !targetId ? nullptr : findProcess(targetId);
    if (!target)
        co_return failed();
    const auto selector = arguments[required - 1].value;
    SphereScripts::Method method;
    if (selector.type == 1)
        method = target->findFunction(textIn({selector.bits.base, selector.bits.begin, selector.bits.end}, 31));
    else
    {
        const auto slot = SphereScripts::word(SphereScripts::integer(selector));
        if (slot < target->function_map.size() && target->function_map[slot])
            method = *target->function_map[slot];
    }
    if (!method || !alive(*method.owner))
        co_return failed();
    const auto index = target->findProgram(*method.owner, method.program);
    if (index < 0)
        co_return failed();
    if (!execution || execution->calls.size() >= 100)
        throw std::runtime_error("Native cross-process call depth exhausted");
    auto owner = method.owner->shared_from_this();
    const auto lifetime = target->lifetime;
    if (target->programs[index].executing && !method.reentrant)
        warning("Reentrant native script call to a non-reentrant function: " + std::string(method.name));
    const bool wasExecuting = target->programs[index].executing;
    auto *continuation = execution;
    continuation->calls.push_back({{&caller, current.function}, method.owner, method.program, continuation->depth});
    target->programs[index].executing = true;
    struct CallScope
    {
        SphereScripts::Execution &execution;
        SferaMbcProcessRecord &process;
        std::uint64_t lifetime;
        std::size_t index;
        bool previous;
        ~CallScope()
        {
            execution.calls.pop_back();
            if (process.lifetime == lifetime && index < process.programs.size())
                process.programs[index].executing = previous;
        }
    } scope{*continuation, *target, lifetime, std::size_t(index), wasExecuting};
    active_tag = 0;
    arguments.erase(arguments.begin(), arguments.begin() + required);
    co_return co_await method.start(std::move(arguments));
}

void SferaMbcProcessRecord::finishProgram(std::size_t index)
{
    if (index >= programs.size())
        return;
    auto &program = programs[index];
    auto &head = program_map_a[program.priority];
    auto &tail = program_map_b[program.priority];
    const auto number = SferaNumeric::lowHalf(SferaNumeric::lowWord(index));
    // Inactive functions are callable without belonging to a scheduler queue.
    if (program.previous_program != UINT16_MAX && program.next_program != UINT16_MAX)
    {
        if (head == number && tail == number)
            head = tail = UINT16_MAX;
        else if (head == number)
        {
            head = program.next_program;
            programs[head].previous_program = head;
        }
        else if (tail == number)
        {
            tail = program.previous_program;
            programs[tail].next_program = tail;
        }
        else
        {
            programs[program.previous_program].next_program = program.next_program;
            programs[program.next_program].previous_program = program.previous_program;
        }
    }
    program.previous_program = program.next_program = UINT16_MAX;
    program.state = -1;
    program.executing = false;
    program.continuation.reset();
    program.cleanup_requested = false;
    programs_queued = std::any_of(std::begin(program_map_a), std::begin(program_map_a) + 3, [](auto value) { return value != UINT16_MAX; });
    if (!programs_queued)
        g_sfera_mbc_runtime.dequeueProcess(*this);
}

void SferaMbcRuntime::programAction(SphereScripts::Module &module, std::string_view name, SphereScripts::ProgramAction action)
{
    if (!alive(module))
        throw std::runtime_error("Controlling a defunct native script process");
    auto &process = processes[module.processId];
    const auto found = process.findProgram(module, name);
    if (found < 0)
        throw std::out_of_range("Unknown native script program: " + std::string(name));
    const auto index = std::size_t(found);
    auto &program = process.programs[index];
    const bool running = program.continuation && program.continuation->running;
    switch (action)
    {
    case SphereScripts::ProgramAction::Stop:
        if (!running)
        {
            program.continuation.reset();
            program.cleanup_requested = true;
        }
        return;
    case SphereScripts::ProgramAction::Pause:
        program.state = 0;
        return;
    case SphereScripts::ProgramAction::Start:
    case SphereScripts::ProgramAction::StartChild:
        if (!running)
        {
            program.continuation.reset();
            program.cleanup_requested = false;
        }
        program.caller_program = action == SphereScripts::ProgramAction::StartChild ? program_index : -1;
        break;
    case SphereScripts::ProgramAction::Resume:
        break;
    }
    if (program.previous_program == UINT16_MAX)
        process.linkProgram(index);
    program.state = 1;
}

void SferaMbcRuntime::halt()
{
    if (active_process)
        active_process->flags |= SferaMbcProcessRecordFlagsunloadAfterExecution;
}

void SferaMbcRuntime::runProgram(SferaMbcProcessRecord &process, std::size_t index)
{
    SferaRestore previousExecution(execution);
    SferaRestore previousContext(current);
    if (index >= process.programs.size() || process.programs[index].state <= 0)
        return;
    const auto lifetime = process.lifetime;
    auto ancestor = process.programs[index].caller_program;
    std::size_t visited = 0;
    while (ancestor >= 0 && std::cmp_less(ancestor, process.programs.size()) && process.programs[ancestor].state > 0)
    {
        if (++visited > process.programs.size())
            throw std::runtime_error("Cyclic native program parent relation");
        ancestor = process.programs[ancestor].caller_program;
    }
    if (ancestor >= 0 && std::cmp_less(ancestor, process.programs.size()))
    {
        if (process.programs[ancestor].state == 0)
            return;
        process.programs[index].continuation.reset();
        process.programs[index].cleanup_requested = true;
    }
    auto module = process.programs[index].module;
    const auto function = process.programs[index].cleanup_requested ? process.programs[index].cleanup : std::string_view(process.programs[index].name);
    if (function.empty())
    {
        process.finishProgram(index);
        return;
    }
    auto continuation = process.programs[index].continuation;
    if (!continuation)
    {
        const auto *method = process.programs[index].cleanup_requested ? process.programs[index].cleanupBody : process.programs[index].body;
        if (!method)
            throw std::runtime_error("Native program has no bound implementation: " + std::string(function));
        continuation = std::make_shared<SphereScripts::Continuation>();
        continuation->execution.rootModule = module.get();
        // Source program identity stays stable while its cleanup method executes.
        continuation->execution.rootProgram = process.programs[index].name;
        continuation->execution.rootProgramIndex = SferaNumeric::signedWord(SferaNumeric::lowWord(index));
        continuation->task = method->start({});
        continuation->task.start(continuation->execution);
        process.programs[index].continuation = continuation;
    }
    if (continuation->running)
        throw std::runtime_error("Native program is already running in this scheduler");
    continuation->execution.work = 0;
    continuation->running = true;
    try
    {
        SphereScripts::activate(continuation->execution.context, &continuation->execution);
        if (!continuation->execution.suspended)
            throw std::logic_error("Native program lost its continuation");
        SphereScripts::resume(continuation->execution);
        if (continuation->task.done())
            continuation->task.result();
    }
    catch (...)
    {
        continuation->running = false;
        throw;
    }
    continuation->running = false;
    if (process.lifetime == lifetime && process.chain_prev_index >= 0 && index < process.programs.size() &&
        (continuation->execution.finished || continuation->task.done()))
        process.finishProgram(index);
}
