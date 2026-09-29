#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "binary/Binary.h"
#include "diagnostics/Diagnostics.h"
#include "numeric/Numeric.h"
#include "script/NativeModule.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"

SferaMbcProcessRecord *SferaMbcRuntime::findProcess(std::uint32_t id)
{
    if (id >= std::size(processes))
    {
        return nullptr;
    }
    auto &process = processes[id];
    return process.process_id == id && process.chain_prev_index >= 0 ? &process : nullptr;
}

namespace
{
void appendPrograms(const SferaNativeModule &module, std::uint32_t binding, std::vector<ScriptProgramDiagnostic> &programs)
{
    for (const auto &declaration : module.programs)
    {
        auto &program = programs.emplace_back();
        program.name = declaration.name;
        program.entry = {declaration.entry, binding};
        program.stop = {declaration.stop, binding};
        program.selected = program.entry;
        program.state = declaration.initial_state;
        program.priority = declaration.priority;
    }
}
}

std::uint32_t SferaMbcRuntime::loadProcess(std::string_view name, std::uint32_t requestedIndex)
{
    text_buffer.clear();
    if (name.starts_with('@'))
    {
        const auto end = name.find('@', 1);
        if (end == std::string_view::npos)
        {
            return UINT32_MAX;
        }
        for (const auto character : name.substr(1, end - 1))
        {
            const auto needed = character == ';' ? 2u : 1u;
            if (needed >= text_capacity - text_buffer.size())
            {
                return UINT32_MAX;
            }
            if (character == ';')
            {
                text_buffer += "\r\n";
            }
            else
            {
                text_buffer.push_back(character == '\'' ? '"' : character);
            }
        }
        name.remove_prefix(end + 1);
    }
    if (name.size() >= 32)
    {
        return UINT32_MAX;
    }
    const auto *nativeModule = SferaNativeCatalog::find(name);
    if (nativeModule == nullptr)
    {
        return UINT32_MAX;
    }
    std::uint32_t index = requestedIndex;
    if (index == UINT32_MAX)
    {
        index = process_search_cursor;
        const auto first = index;
        while (processes[index].chain_prev_index >= 0)
        {
            index = (index + 1) % std::size(processes);
            if (index == first)
            {
                return UINT32_MAX;
            }
        }
    }
    else if (index >= std::size(processes) || processes[index].chain_prev_index >= 0)
    {
        return UINT32_MAX;
    }

    // Construct an independent instance from native descriptors before publishing it to the scheduler.
    SferaMbcProcessRecord replacement{};
    replacement.name = name;
    replacement.module_tag = nativeModule->module_tag;
    auto storage = std::make_shared<SferaNativeModuleState>(*nativeModule, native_space);
    replacement.programs.reserve(nativeModule->programs.size());
    appendPrograms(*nativeModule, 0, replacement.programs);
    replacement.native_bindings.reserve(8);
    replacement.native_bindings.push_back({nativeModule, storage, 0, 0});
    replacement.regions.assign(62, SferaMbcRegionRecord::undefined());
    replacement.readRegions(nativeModule->regions, 0);
    replacement.field_084 = nativeModule->position_access == UINT32_MAX ? 0u : storage->reference(nativeModule->position_access, 12u).base;
    std::fill(std::begin(replacement.program_map_a), std::end(replacement.program_map_a), UINT16_MAX);
    std::fill(std::begin(replacement.program_map_b), std::end(replacement.program_map_b), UINT16_MAX);
    std::fill(std::begin(replacement.region_timestamps), std::end(replacement.region_timestamps), UINT32_MAX);
    replacement.process_id = index;
    replacement.lifetime = next_process_lifetime++;
    replacement.execution_prev_index = replacement.execution_next_index = index;
    replacement.chain_prev_index = process_chain_last < 0 ? index : process_chain_last;
    replacement.chain_next_index = index;
    auto &process = processes[index];
    process = std::move(replacement);
    if (process_chain_last >= 0)
    {
        processes[process_chain_last].chain_next_index = index;
    }
    else
    {
        process_chain_first = index;
    }
    process_chain_last = index;
    process_search_cursor = (index + 1) % std::size(processes);
    for (std::uint32_t program = 0; program < process.programs.size(); ++program)
    {
        if (process.programs[program].state == 1)
        {
            process.linkProgram(program);
        }
    }
    if (process.programs_queued)
    {
        enqueueProcess(index, process);
    }
    return process.process_id;
}

std::uint32_t SferaMbcRuntime::linkProcess(std::string_view name)
{
    // Host ABI name retained. This activates an instance; it does not link code,
    // patch imports, relocate data or copy existing program/function tables.
    if (name.size() >= 32 || process_index < 0 || std::cmp_greater_equal(process_index, std::size(processes)))
        return UINT32_MAX;
    const auto *module = SferaNativeCatalog::find(name);
    if (module == nullptr)
        return UINT32_MAX;
    auto &process = processes[process_index];
    if (process.chain_prev_index < 0 || process.native_bindings.empty())
        return UINT32_MAX;
    if (process.native_bindings.size() >= 8)
    {
        reportError("Too many active native modules: ", name);
        return UINT32_MAX;
    }
    const auto first = static_cast<std::uint32_t>(process.programs.size());
    if (module->programs.size() > 32767u - first)
        return UINT32_MAX;
    const auto index = static_cast<std::uint32_t>(process.native_bindings.size());
    auto storage = std::make_shared<SferaNativeModuleState>(*module, native_space);
    SferaMbcProcessRecord regionBindings{};
    regionBindings.regions = process.regions;
    regionBindings.readRegions(module->regions, first);
    const auto needed = process.programs.size() + module->programs.size();
    if (needed > process.programs.capacity())
        process.programs.reserve(std::max(needed, process.programs.capacity() * 2));
    // Capacity was reserved before publication; all following operations are
    // nonthrowing. Contexts and suspended tasks own stable module states.
    appendPrograms(*module, index, process.programs);
    process.native_bindings.push_back({module, std::move(storage), first, index});
    process.regions.swap(regionBindings.regions);
    program_table_base = process.programs.data();
    active_program_record = program_index >= 0 && static_cast<std::size_t>(program_index) < process.programs.size()
        ? &process.programs[program_index] : nullptr;
    for (auto program = first; program < process.programs.size(); ++program)
        if (process.programs[program].state == 1)
            process.linkProgram(program);
    return 0;
}

std::uint32_t SferaMbcRuntime::unloadProcess(std::uint32_t index)
{
    if (index >= std::size(processes))
    {
        return UINT32_MAX;
    }
    auto &process = processes[index];
    if (process.chain_prev_index < 0)
    {
        return UINT32_MAX;
    }
    if (process.native_depth != 0)
    {
        process.flags |= SferaMbcProcessRecordFlagsmarkedForUnload;
        return 0;
    }
    if (index == 0)
    {
        g_sfera_log_runtime.write("prc_unload _main.mbl\n");
    }
    const auto previous = process.chain_prev_index;
    const auto next = process.chain_next_index;
    if (SferaNumeric::word(process_chain_first) == index && SferaNumeric::word(process_chain_last) == index)
    {
        process_chain_first = process_chain_last = -1;
    }
    else if (SferaNumeric::word(process_chain_last) == index)
    {
        process_chain_last = previous;
        processes[previous].chain_next_index = previous;
    }
    else if (SferaNumeric::word(process_chain_first) == index)
    {
        process_chain_first = next;
        processes[next].chain_prev_index = next;
    }
    else
    {
        processes[next].chain_prev_index = previous;
        processes[previous].chain_next_index = next;
    }
    dequeueProcess(process);
    process.flags |= SferaMbcProcessRecordFlagsunloadAfterExecution;
    // Mark first to protect against callbacks reentering unload. Resources still see valid memory.
    process.chain_prev_index = -1;
    if (!process.cleanup_entries.empty())
    {
        process.releaseResources();
    }
    forgetMemory(&process);
    process.programs.clear();
    process.native_bindings.clear();
    native_space->requestCollection();
    process.allocations.clear();
    process.physics_commands.clear();
    process.regions.clear();
    for (std::size_t region = 0; region < process.received_regions.size(); ++region)
    {
        process.region_timestamps[region] = UINT32_MAX;
        process.received_regions[region].reset();
    }
    process.process_id = UINT32_MAX;
    // Keep execution_prev_index until the scheduler has advanced past this slot.
    return 0;
}
