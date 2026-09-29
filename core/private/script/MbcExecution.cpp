#include <windows.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <filesystem>
#include <format>
#include <io.h>
#include <iterator>
#include <list>
#include <memory>
#include <mmsystem.h>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
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
#include "script/NativeModule.h"
#include "script/ConfigText.h"
#include "script/MbcBitStream.h"
#include "script/MbcCommands.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"
#include "script/MbcValue.h"
#include "script/ScriptContainer.h"
#include "ui/GameInterfaceManager.h"
#include "ui/ScriptInterface.h"
#include "ui/Window.h"
#include "world/GameCalendar.h"
#include "world/WorldObjects.h"


void SferaMbcRuntime::reportInvalidInstruction()
{
    reportError("Invalid native script entry");
}

auto SferaMbcRuntime::callFunctionFail()
{
    active_tag = UINT32_MAX;
    pushInteger(UINT32_MAX);
}

void SferaMbcRuntime::callFunction(bool mainProcess)
{
    const auto required = mainProcess ? 1u : 2u;
    native_call->count -= required;

    if (native_call->count < 0)
    {
        callFunctionFail();
        return;
    }
    const auto target_word = mainProcess ? 0u : nextWord();
    auto *target = mainProcess ? &processes[0] : target_word == 0 ? nullptr : findProcess(target_word);
    if (target == nullptr || target->native_bindings.empty())
    {
        callFunctionFail();
        return;
    }
    if (native_call->cursor >= native_call->arguments.size())
    {
        reportError("Too few parameters");
        callFunctionFail();
        return;
    }
    std::optional<SferaMbcFunctionRecord> function;
    if (native_call->arguments[native_call->cursor].type == SferaMbcValueTypeBytePointer)
    {
        const auto name = nextSlice();
        const auto text = textIn(name, 31);
        function = target->findFunction(text);
    }
    else
    {
        const std::uint32_t tag = nextInteger();
        if (tag < SferaMbcProcessRecord::functionSlotCount)
        {
            function = target->findFunction(tag);
        }
    }
    if (!function || function->program_index < 0 || function->program_index >= target->programs.size())
    {
        callFunctionFail();
        return;
    }
    const auto targetProgram = function->program_index;
    const auto entry = function->entry;
    if (target->programs[targetProgram].executing && !function->allow_reentry)
        WorldDiagnostics::warning("Reentrant native function call: " + std::string(function->name));
    active_tag = 0;
    const auto first = native_call->cursor;
    const auto count = static_cast<std::size_t>(native_call->count);
    if (first > native_call->arguments.size() || count > native_call->arguments.size() - first)
    {
        reportError("Too few function parameters");
        callFunctionFail();
        return;
    }
    const auto arguments = std::span<const SferaMbcValue>(native_call->arguments).subspan(first, count);
    native_call->result = invokeNative(*target, targetProgram, entry, arguments);
}


bool SferaMbcRuntime::negativeModuleIndex(std::uint16_t index)
{
    return SferaNumeric::signedHalf(index) < 0;
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
    mapped_memory.clear();
    native_resources.clear();
    native_resource_ids.clear();
    named_vectors.clear();
    active_process = nullptr;
    active_program_record = nullptr;
    program_table_base = nullptr;
    source_module = nullptr;
    source_function = {};
    native_checkpoint = UINT32_MAX;
    process_chain_first = process_chain_last = execution_chain_head = execution_chain_tail = -1;
    execution_chain_count = 0;
    native_caller_process = UINT32_MAX;
    native_space->collectCycles();
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
    auto &log = g_sfera_log_runtime;
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
    process_index = execution_chain_tail;
    while (process_index >= 0 && std::cmp_less(process_index, std::size(processes)) && processes[process_index].chain_prev_index >= 0)
    {
        g_sfera_mbc_runtime.dispatch_slot = process_index;
        active_process = &processes[process_index];
        program_table_base = active_process->programs.data();
        execution_failed = false;
        bool unload = false;
        for (std::size_t priority = 0; priority <= priorityLimit && !unload; ++priority)
        {
            program_index = SferaNumeric::signedHalf(active_process->program_map_a[priority]);
            while (program_index >= 0)
            {
                active_program_record = &program_table_base[program_index];
                const auto initialProgram = program_index;
                bool finishPriority = false;
                if (active_program_record->state > 0)
                {
                    instruction_step_count = 0;
                    auto caller = program_index;
                    do
                    {
                        caller = program_table_base[caller].caller_program;
                    } while (caller >= 0 && program_table_base[caller].state > 0);
                    const bool pausedCaller = caller >= 0 && program_table_base[caller].state == 0;
                    if (!pausedCaller)
                    {
                        do
                        {
                            const auto stepResult = resumeNativeProgram(caller >= 0);
                            if (stepResult == SferaAotStepResult::BudgetExceeded)
                            {
                                WorldDiagnostics::scriptContext();
                                log.write("\n---exit_inter start---\nMBINTER MESSAGE:Endless cycle found\n");
                                log.write(diagnostic_context);
                                log.write("---exit_inter end-----\n");
                                execution_failed = true;
                                if (process_index == 0)
                                    SferaClientApplication::terminateWithError(diagnostic_context);
                                processes[0].activateProgram("EError");
                                unload = true;
                                break;
                            }
                            if (stepResult == SferaAotStepResult::Yield)
                            {
                                break;
                            }
                            if (stepResult == SferaAotStepResult::EndProgram)
                            {
                                active_program_record->state = -1;
                                auto pending_program_index = SferaNumeric::signedHalf(active_process->program_map_b[priority]);
                                auto &head = active_process->program_map_a[priority];
                                auto &tail = active_process->program_map_b[priority];
                                if (program_index == SferaNumeric::signedHalf(tail))
                                {
                                    if (head == tail)
                                    {
                                        head = UINT16_MAX;
                                        tail = UINT16_MAX;
                                        if (std::all_of(std::begin(active_process->program_map_a), std::begin(active_process->program_map_a) + 3, &SferaMbcRuntime::negativeModuleIndex))
                                        {
                                            dequeueProcess(*active_process);
                                            active_process->programs_queued = false;
                                        }
                                    }
                                    else
                                    {
                                        pending_program_index = SferaNumeric::signedHalf(active_program_record->previous_program);
                                        tail = pending_program_index;
                                        program_table_base[pending_program_index].next_program = tail;
                                    }
                                    finishPriority = true;
                                }
                                else if (program_index == head)
                                {
                                    head = active_program_record->next_program;
                                    program_table_base[head].previous_program = head;
                                }
                                else
                                {
                                    program_table_base[active_program_record->next_program].previous_program = active_program_record->previous_program;
                                    program_table_base[active_program_record->previous_program].next_program = active_program_record->next_program;
                                }
                                break;
                            }
                            if (stepResult == SferaAotStepResult::Failed)
                            {
                                unload = true;
                                break;
                            }
                        } while (false);
                    }
                }
                if (finishPriority || unload)
                    break;
                program_index = SferaNumeric::signedHalf(active_program_record->next_program);
                if (initialProgram == SferaNumeric::signedHalf(active_process->program_map_b[priority]))
                    break;
            }
        }
        if (unload || (active_process->flags & SferaMbcProcessRecordFlagsunloadAfterExecution) != 0)
        {
            unloadProcess(process_index);
            if (process_index == process_chain_last)
                break;
        }
        const auto previousActive = g_sfera_mbc_runtime.dispatch_slot;
        process_index = active_process->execution_prev_index;
        if (previousActive == execution_chain_head)
            break;
    }
    g_sfera_mbc_runtime.dispatch_slot = -1;
    drainDeferredUnloads();
    native_space->collectCyclesIfNeeded();
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
            case SferaMbcProcessRecordResourceKind::file:
                ::_close(SferaNumeric::signedWord(entry.handle));
                break;
            case SferaMbcProcessRecordResourceKind::fileSearch:
            {
                const auto search = g_sfera_mbc_runtime.nativeResource<std::intptr_t>(entry.handle);
                if (search != -1)
                {
                    ::_findclose(search);
                    g_sfera_mbc_runtime.forgetNativeResource(search);
                }
                break;
            }
            case SferaMbcProcessRecordResourceKind::dynamicArray:
            {
                const auto offset = g_sfera_mbc_runtime.readMemory<std::uint32_t>(entry.handle);
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
