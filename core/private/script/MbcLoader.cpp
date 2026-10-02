#include <algorithm>
#include <cstdint>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "diagnostics/Diagnostics.h"
#include "numeric/Numeric.h"
#include "resources/FileResources.h"
#include "script/GeneratedScripts.h"
#include "script/MbcRuntime.h"

SferaMbcProcessRecord *SferaMbcRuntime::findProcess(std::uint32_t id)
{
    if (id >= std::size(processes))
        return nullptr;
    auto &process = processes[id];
    return process.process_id == id && process.chain_prev_index >= 0 ? &process : nullptr;
}

int SferaMbcProcessRecord::findProgram(const SphereScripts::Module &module, std::string_view name) const
{
    for (std::size_t index = 0; index < programs.size(); ++index)
        if (programs[index].module.get() == &module && programs[index].name == name)
            return SferaNumeric::signedWord(SferaNumeric::lowWord(index));
    return -1;
}

void SferaMbcProcessRecord::appendModule(std::shared_ptr<SphereScripts::Module> module)
{
    std::size_t count = 0;
    for (const auto definitions : module->programs())
        for (const auto &definition : definitions)
        {
            ++count;
            if (!module->method(definition.name) &&
                (definition.initialState != 0 || definition.priority != 0 || definition.cleanup != SphereScripts::Entry::None))
                throw std::logic_error("Scheduled program has no bound native function: " +
                                       std::string(module->moduleName()) + "::" +
                                       std::string(SphereScripts::entryName(definition.name)));
        }
    if (count > 32767u - programs.size() || module->functionCount() > 65535u - functionCount())
        throw std::length_error("Too many native script programs or callable names");
    auto expanded = programs;
    expanded.reserve(programs.size() + count);
    for (const auto definitions : module->programs())
        for (const auto &definition : definitions)
        {
            ScriptProgramDiagnostic program;
            program.name = SphereScripts::entryName(definition.name);
            program.cleanup = SphereScripts::entryName(definition.cleanup);
            program.module = module;
            program.body = module->method(definition.name);
            program.cleanupBody = module->method(definition.cleanup);
            program.state = definition.initialState;
            program.priority = definition.priority;
            expanded.push_back(std::move(program));
        }
    modules.reserve(modules.size() + 1);
    programs.swap(expanded);
    for (const auto &[index, method] : module->callbacks())
    {
        if (index >= function_map.size() || function_slot_declared[index])
            continue;
        function_slot_declared[index] = true;
        function_map[index] = method;
    }
    modules.push_back(std::move(module));
    readRegions(*modules.back());
}

std::size_t SferaMbcProcessRecord::functionCount() const noexcept
{
    std::size_t count = 0;
    for (const auto &module : modules)
        count += module->functionCount();
    return count;
}

std::string_view SferaMbcProcessRecord::functionNameAt(std::size_t index) const noexcept
{
    for (const auto &module : modules)
    {
        const auto count = module->functionCount();
        if (index < count)
            return module->functionNameAt(index);
        index -= count;
    }
    return {};
}

SphereScripts::Module &SferaMbcRuntime::selectModule(SphereScripts::Module &caller, bool (*accepts)(SphereScripts::Module &))
{
    if (!alive(caller))
        throw std::runtime_error("Call from an expired native script module");
    const auto &instances = processes[caller.processId].modules;
    const auto origin = std::find_if(instances.begin(), instances.end(), [&caller](const auto &value) { return value.get() == &caller; });
    if (origin == instances.end())
        throw std::logic_error("Native caller does not belong to its process");
    // A later provider replaces an earlier one; an initially resolved provider
    // before the caller is the first matching instance in load order.
    for (auto candidate = instances.end(); candidate != std::next(origin);)
        if (accepts(**--candidate))
            return **candidate;
    for (auto candidate = instances.begin(); candidate != origin; ++candidate)
        if (accepts(**candidate))
            return **candidate;
    throw std::runtime_error("Required native script module is not loaded");
}

SphereScripts::Module &SferaMbcRuntime::mainModule()
{
    auto *process = findProcess(0);
    if (!process || process->modules.empty())
        throw std::runtime_error("Main native script module is not loaded");
    return *process->modules.front();
}

std::uint32_t SferaMbcRuntime::loadProcess(std::string_view name, std::uint32_t requestedIndex)
{
    text_buffer.clear();
    if (name.starts_with('@'))
    {
        const auto end = name.find('@', 1);
        if (end == std::string_view::npos)
            return UINT32_MAX;
        for (const auto character : name.substr(1, end - 1))
        {
            const auto needed = character == ';' ? 2u : 1u;
            if (needed >= text_capacity - text_buffer.size())
                return UINT32_MAX;
            if (character == ';')
                text_buffer += "\r\n";
            else
                text_buffer.push_back(character == '\'' ? '"' : character);
        }
        name.remove_prefix(end + 1);
    }
    if (name.size() >= 32)
        return UINT32_MAX;
    std::shared_ptr<SphereScripts::Module> module;
    try { module = SphereScripts::createModule(*this, name); }
    catch (const std::invalid_argument &) { return UINT32_MAX; }
    auto index = requestedIndex;
    if (index == UINT32_MAX)
    {
        index = process_search_cursor;
        const auto first = index;
        while (processes[index].chain_prev_index >= 0)
        {
            index = (index + 1u) % std::size(processes);
            if (index == first)
                return UINT32_MAX;
        }
    }
    else if (index >= std::size(processes) || processes[index].chain_prev_index >= 0)
        return UINT32_MAX;
    SferaMbcProcessRecord replacement{};
    replacement.name = name;
    replacement.module_tag = module->tag();
    replacement.regions.assign(62, SferaMbcRegionRecord::undefined());
    std::fill(std::begin(replacement.program_map_a), std::end(replacement.program_map_a), UINT16_MAX);
    std::fill(std::begin(replacement.program_map_b), std::end(replacement.program_map_b), UINT16_MAX);
    std::fill(std::begin(replacement.region_timestamps), std::end(replacement.region_timestamps), UINT32_MAX);
    replacement.process_id = index;
    replacement.lifetime = next_process_lifetime++;
    module->processId = index;
    module->lifetime = replacement.lifetime;
    module->initializeMembers();
    replacement.appendModule(module);
    replacement.field_084 = module->position().base;
    replacement.execution_prev_index = replacement.execution_next_index = index;
    replacement.chain_prev_index = process_chain_last < 0 ? index : process_chain_last;
    replacement.chain_next_index = index;
    auto &process = processes[index];
    process = std::move(replacement);
    if (process_chain_last >= 0)
        processes[process_chain_last].chain_next_index = index;
    else
        process_chain_first = index;
    process_chain_last = index;
    process_search_cursor = (index + 1u) % std::size(processes);
    for (std::size_t program = 0; program < process.programs.size(); ++program)
        if (process.programs[program].state == 1)
            process.linkProgram(program);
    return process.process_id;
}

std::uint32_t SferaMbcRuntime::linkProcess(std::string_view name)
{
    if (name.size() >= 32 || process_index < 0 || std::cmp_greater_equal(process_index, std::size(processes)))
        return UINT32_MAX;
    auto &process = processes[process_index];
    if (process.chain_prev_index < 0)
        return UINT32_MAX;
    if (process.modules.size() >= 8)
    {
        reportError("Cannot link more than eight native module instances: ", name);
        checkEngineFailure();
        return UINT32_MAX;
    }
    std::shared_ptr<SphereScripts::Module> module;
    try { module = SphereScripts::createModule(*this, name); }
    catch (const std::invalid_argument &) { return UINT32_MAX; }
    module->processId = process.process_id;
    module->lifetime = process.lifetime;
    module->initializeMembers();
    const auto firstProgram = process.programs.size();
    process.appendModule(std::move(module));
    program_table_base = process.programs.data();
    active_program_record = program_index >= 0 && std::cmp_less(program_index, process.programs.size()) ? &process.programs[program_index] : nullptr;
    for (auto index = firstProgram; index < process.programs.size(); ++index)
        if (process.programs[index].state == 1)
            process.linkProgram(index);
    return 0;
}

std::uint32_t SferaMbcRuntime::unloadProcess(std::uint32_t index)
{
    if (index >= std::size(processes))
        return UINT32_MAX;
    auto &process = processes[index];
    if (process.chain_prev_index < 0)
        return UINT32_MAX;
    if (index == 0)
        g_sfera_log_runtime.write("prc_unload _main.mbl\n");
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
        process.releaseResources();
    g_sfera_files.releaseOwner(process.lifetime);
    for (auto &program : process.programs)
        if (program.continuation)
            program.continuation->execution.cancelled = true;
    for (const auto &module : process.modules)
        forgetMemory(module.get());
    forgetMemory(&process);
    process.programs.clear();
    process.function_map.fill({});
    process.function_slot_declared.fill(false);
    process.modules.clear();
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

std::string_view SferaMbcRuntime::moduleName(std::uint32_t tag) noexcept
{
    return SphereScripts::moduleName(tag);
}

std::uint32_t SferaMbcRuntime::moduleTag(std::string_view name) noexcept
{
    return SphereScripts::moduleTag(name);
}
