#include "script/MbcRuntime.h"
#include "diagnostics/Diagnostics.h"

#include <algorithm>
#include <cstring>
#include <stdexcept>

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
    if (index >= programs.size() || programs.data() == nullptr)
        return false;
    auto &program = programs.data()[index];
    if (program.state != 1)
    {
        linkProgram(index);
        program.select(program.entry);
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

std::uint32_t SferaMbcProcessRecord::growMemory(std::size_t size)
{
    if (size == 0 || size > 4000000u)
        return UINT32_MAX;
    auto object = g_sfera_mbc_runtime.native_space->createBytes(static_cast<std::uint32_t>(size));
    const auto address = object->address();
    allocations.push_back(std::move(object));
    return address;
}

const SferaNativeExport *SferaNativeModule::findExport(std::uint32_t symbol) const
{
    const auto found = std::lower_bound(exports.begin(), exports.end(), symbol,
        [](const auto &entry, auto value) { return entry.symbol < value; });
    return found != exports.end() && found->symbol == symbol ? &*found : nullptr;
}

namespace
{
SferaMbcFunctionRecord exportRecord(const SferaNativeBinding &binding, const SferaNativeExport &entry)
{
    return {SferaNativeCatalog::symbolName(entry.symbol), {entry.callable, binding.binding_index},
            static_cast<int>(binding.program_base + entry.program_index), entry.allow_reentry};
}
}

std::optional<SferaMbcFunctionRecord> SferaMbcProcessRecord::findFunction(std::string_view name) const
{
    const auto symbol = SferaNativeCatalog::findSymbol(name);
    if (symbol != 0)
        for (const auto &binding : native_bindings)
            if (const auto *entry = binding.module->findExport(symbol))
                return exportRecord(binding, *entry);
    return std::nullopt;
}

std::optional<SferaMbcFunctionRecord> SferaMbcProcessRecord::findFunction(std::uint32_t slot) const
{
    if (slot < functionSlotCount)
        for (const auto &binding : native_bindings)
        {
            const auto index = binding.module->entry_slots[slot];
            if (index != UINT16_MAX)
                return exportRecord(binding, binding.module->exports[index]);
        }
    return std::nullopt;
}

SferaNativeEntry SferaMbcProcessRecord::selectExport(std::uint32_t callerBinding, std::uint32_t symbol, std::span<const std::uint64_t> providers, SferaNativeCallable knownCallable) const
{
    if (callerBinding >= native_bindings.size())
        return {};
    const auto select = [&](std::uint32_t index) -> SferaNativeEntry
    {
        const auto &module = *native_bindings[index].module;
        if (!providers.empty())
        {
            const auto id = static_cast<std::uint32_t>(module.catalog_id) - 1u;
            if (id / 64 >= providers.size() || (providers[id / 64] & (std::uint64_t{1} << (id % 64))) == 0)
                return {};
            if (knownCallable.valid())
                return {knownCallable, index};
        }
        if (const auto *entry = module.findExport(symbol))
            return {entry->callable, index};
        return {};
    };
    // Preserve the original ordering: latest subsequent provider overrides;
    // otherwise the first earlier provider supplies the call. Own exports were
    // never resolved as imports of the same instance. Generated provider bits
    // skip table searches for modules which cannot implement this dependency.
    for (auto i = native_bindings.size(); i > callerBinding + 1; --i)
        if (const auto target = select(static_cast<std::uint32_t>(i - 1)); target.valid())
            return target;
    for (std::uint32_t i = 0; i < callerBinding; ++i)
        if (const auto target = select(i); target.valid())
            return target;
    return {};
}

void SferaMbcProcessRecord::readRegions(std::span<const SferaNativeRegionDefinition> definitions, std::uint32_t firstProgram)
{
    for (const auto &definition : definitions)
    {
        if (definition.index >= regions.size())
            continue;
        auto &region = regions[definition.index];
        if (region.flags == -1)
        {
            region.flags = definition.flags;
            region.field_count = static_cast<int>(definition.formats.size());
            std::copy(definition.formats.begin(), definition.formats.end(), region.formats);
        }
        if (definition.program_index != UINT16_MAX && region.program_index == UINT16_MAX)
            region.program_index = static_cast<std::uint16_t>(firstProgram + definition.program_index);
    }
}
