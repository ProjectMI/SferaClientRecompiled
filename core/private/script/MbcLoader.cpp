#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "binary/Binary.h"
#include "diagnostics/Diagnostics.h"
#include "numeric/Numeric.h"
#include "resources/FileResources.h"
#include "script/MbcProcess.h"
#include "script/MbcRuntime.h"

bool SferaMbcRuntime::relocationFits(std::size_t size, std::size_t width, std::uint32_t offset)
{
    return offset <= size && width <= size - offset;
}

SferaMbcProcessRecord *SferaMbcRuntime::findProcess(std::uint32_t id)
{
    if (id >= std::size(processes))
        return nullptr;
    auto &process = processes[id];
    return process.process_id == id && process.chain_prev_index >= 0 ? &process : nullptr;
}

std::shared_ptr<const std::vector<std::uint8_t>> SferaMbcRuntime::cacheBytecode(std::shared_ptr<const std::vector<std::uint8_t>> code, const SferaMbcModuleIds &moduleIds, std::uint32_t memorySize)
{
    return bytecode_cache.try_emplace(SferaMbcBytecodeKey{moduleIds, memorySize}, std::move(code)).first->second;
}

std::shared_ptr<const std::vector<std::uint8_t>> SferaMbcRuntime::findBytecode(const SferaMbcModuleIds &moduleIds, std::uint32_t memorySize) const
{
    const auto found = bytecode_cache.find(SferaMbcBytecodeKey{moduleIds, memorySize});
    return found == bytecode_cache.end() ? nullptr : found->second;
}

void SferaMbcRuntime::resetBytecodeCache()
{
    bytecode_cache.clear();
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
    if (name.size() >= 32 || !quick_files)
        return UINT32_MAX;
    const auto *file = quick_files->find(std::string(name) + ".mbc");
    if (!file || file->bytes.size() < 16)
        return UINT32_MAX;
    std::uint32_t index = requestedIndex;
    if (index == UINT32_MAX)
    {
        index = process_search_cursor;
        const auto first = index;
        while (processes[index].chain_prev_index >= 0)
        {
            index = (index + 1) % std::size(processes);
            if (index == first)
                return UINT32_MAX;
        }
    }
    else if (index >= std::size(processes) || processes[index].chain_prev_index >= 0)
        return UINT32_MAX;
    SferaMbcModuleImage module;
    if (!module.read(file->bytes, false) || module.memory.size() >= mappedAddressBegin || module.bytecode.size() > UINT32_MAX || module.programs.size() > 32767 || module.functions.size() > 65535)
        return UINT32_MAX;

    // Nothing is published in the slot table or scheduler until all allocations and decoding succeed.
    SferaMbcProcessRecord replacement{};
    replacement.linked_modules.fill(0);
    replacement.linked_modules.front() = SferaNumeric::lowHalf(SferaNumeric::lowWord(file->module_id));
    replacement.name = name;
    replacement.module_tag = module.module_tag;
    replacement.bytecode = findBytecode(replacement.linked_modules, SferaNumeric::lowWord(module.memory.size()));
    if (!replacement.bytecode)
    {
        auto code = std::make_shared<std::vector<std::uint8_t>>(module.bytecode.begin(), module.bytecode.end());
        replacement.bytecode = cacheBytecode(std::move(code), replacement.linked_modules, SferaNumeric::lowWord(module.memory.size()));
    }
    replacement.memory.assign(module.memory.begin(), module.memory.end());
    replacement.programs = std::move(module.programs);
    replacement.functions = std::move(module.functions);
    replacement.function_map = module.function_map;
    replacement.regions.assign(62, SferaMbcRegionRecord::undefined());
    replacement.readRegions(module.region_definitions, 0);
    replacement.field_084 = module.position_memory_offset;
    replacement.code_range_ids[0] = SferaNumeric::lowHalf(module.module_tag);
    replacement.code_range_size[0] = replacement.codeSize();
    replacement.code_range_count = 1;
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
        processes[process_chain_last].chain_next_index = index;
    else
        process_chain_first = index;
    process_chain_last = index;
    process_search_cursor = (index + 1) % std::size(processes);
    for (std::uint32_t program = 0; program < process.programs.size(); ++program)
        if (process.programs[program].state == 1)
            process.linkProgram(program);
    if (process.programs_queued)
        enqueueProcess(index, process);
    return process.process_id;
}

auto SferaMbcRuntime::linkProcessValidRelocations(const auto &table, std::size_t size, std::size_t width)
{
    return std::all_of(table.begin(), table.end(), std::bind_front(&SferaMbcRuntime::relocationFits, size, width));
}

template <class T> auto SferaMbcRuntime::linkProcessRelocate(std::uint8_t *destination, const auto &table, std::uint32_t increment)
{
    for (const auto offset : table)
    {
        const auto value = SferaBinary::readLittleEndian<T>(destination + offset);
        if constexpr (sizeof(T) == sizeof(std::uint16_t))
            SferaBinary::writeLittleEndian(destination + offset, SferaNumeric::lowHalf(value + increment));
        else
            SferaBinary::writeLittleEndian(destination + offset, SferaNumeric::lowWord(value + increment));
    }
}

auto SferaMbcRuntime::linkProcessResolve(const std::vector<SferaMbcFunctionRecord> &functions, const std::shared_ptr<std::vector<std::uint8_t>> &writable, std::uint32_t first, std::uint32_t last,
                                         std::uint32_t targetFirst, std::uint32_t targetLast)
{
    for (auto index = first; index < last; ++index)
    {
        const auto &declaration = functions[index];
        if (declaration.program_index != -1)
            continue;
        for (auto target = targetFirst; target < targetLast; ++target)
        {
            const auto &implementation = functions[target];
            if (implementation.program_index == -1 || declaration.name != implementation.name)
                continue;
            if (declaration.entry_offset <= writable->size() && writable->size() - declaration.entry_offset >= 5)
            {
                auto *instruction = writable->data() + declaration.entry_offset;
                *instruction = 'G';
                SferaBinary::writeLittleEndian(instruction + 1, implementation.entry_offset - declaration.entry_offset - 1u);
            }
            break;
        }
    }
}

std::uint32_t SferaMbcRuntime::linkProcess(std::string_view name)
{
    if (name.size() >= 32 || process_index < 0 || std::cmp_greater_equal(process_index, std::size(processes)) || !quick_files)
        return UINT32_MAX;
    const auto filename = std::string(name) + ".mbc";
    const auto *file = quick_files->find(filename);
    if (!file || file->bytes.size() < 16)
        return UINT32_MAX;
    SferaMbcModuleImage module;
    if (!module.read(file->bytes, true))
        return UINT32_MAX;
    auto &process = processes[process_index];
    if (process.chain_prev_index < 0 || !process.bytecode)
        return UINT32_MAX;
    auto linkedModules = process.linked_modules;
    const auto freeModule = std::find(linkedModules.begin(), linkedModules.end(), std::uint16_t{});
    if (freeModule == linkedModules.end())
    {
        reportError("Cannot link a process - increase MAX_LINKED_PRCS! Linked prc: ", filename);
        return UINT32_MAX;
    }
    const auto codeOffset = process.codeSize();
    if (process.memory.size() > mappedAddressBegin - 4u || process.programs.size() > 32767u || process.functions.size() > 65535u)
        return UINT32_MAX;
    const auto alignedMemoryOffset = (process.memory.size() + 3u) & ~std::size_t{3};
    const auto firstProgramCount = process.programs.size();
    const auto firstFunctionCount = process.functions.size();
    if (module.bytecode.size() > UINT32_MAX - codeOffset || module.memory.size() >= mappedAddressBegin - alignedMemoryOffset || module.programs.size() > 32767u - firstProgramCount ||
        module.functions.size() > 65535u - firstFunctionCount)
        return UINT32_MAX;
    const std::uint32_t memoryOffset = SferaNumeric::lowWord(alignedMemoryOffset);
    const std::uint32_t firstProgram = SferaNumeric::lowWord(firstProgramCount);
    const std::uint32_t firstFunction = SferaNumeric::lowWord(firstFunctionCount);

    if (!linkProcessValidRelocations(module.relocations[0], module.bytecode.size(), 4) || !linkProcessValidRelocations(module.relocations[1], module.memory.size(), 4) ||
        !linkProcessValidRelocations(module.relocations[2], module.bytecode.size(), 2))
        return UINT32_MAX;
    const auto instructionOffset = SferaNumeric::lowWord(instruction_cursor - process.codeData());
    const auto currentOffset = SferaNumeric::lowWord(current_instruction_address - process.codeData());
    *freeModule = SferaNumeric::lowHalf(SferaNumeric::lowWord(file->module_id));

    auto memory = process.memory;
    memory.resize(memoryOffset + module.memory.size(), 0);
    std::copy(module.memory.begin(), module.memory.end(), memory.begin() + memoryOffset);
    auto programs = process.programs;
    programs.insert(programs.end(), module.programs.begin(), module.programs.end());
    for (auto index = firstProgram; index < programs.size(); ++index)
    {
        auto &program = programs[index];
        program.entry_offset += codeOffset;
        program.stop_offset += codeOffset;
        program.instruction_offset = program.entry_offset;
    }
    auto functions = process.functions;
    functions.insert(functions.end(), module.functions.begin(), module.functions.end());
    for (auto index = firstFunction; index < functions.size(); ++index)
    {
        auto &function = functions[index];
        function.entry_offset += codeOffset;
        if (function.program_index != -1)
            function.program_index += firstProgram;
    }
    auto functionMap = process.function_map;
    for (std::size_t index = 0; index < functionMap.size(); ++index)
        if (functionMap[index] == UINT16_MAX && module.function_map[index] != UINT16_MAX)
            functionMap[index] = SferaNumeric::lowHalf(module.function_map[index] + firstFunction);
    // Reuse only the region decoder; it writes no scheduler or global state.
    SferaMbcProcessRecord bindings{};
    bindings.regions = process.regions;
    bindings.readRegions(module.region_definitions, firstProgram);

    linkProcessRelocate<std::uint32_t>(memory.data() + memoryOffset, module.relocations[1], memoryOffset);
    auto code = findBytecode(linkedModules, memoryOffset);
    if (!code)
    {
        auto writable = std::make_shared<std::vector<std::uint8_t>>(*process.bytecode);
        writable->insert(writable->end(), module.bytecode.begin(), module.bytecode.end());

        linkProcessResolve(functions, writable, firstFunction, SferaNumeric::lowWord(functions.size()), 0, firstFunction);
        linkProcessResolve(functions, writable, 0, firstFunction, firstFunction, SferaNumeric::lowWord(functions.size()));
        linkProcessRelocate<std::uint32_t>(writable->data() + codeOffset, module.relocations[0], memoryOffset);
        linkProcessRelocate<std::uint16_t>(writable->data() + codeOffset, module.relocations[2], firstProgram);
        code = cacheBytecode(std::move(writable), linkedModules, memoryOffset);
    }
    // Commit consists solely of nonthrowing owner moves and scalar updates.
    process.bytecode = std::move(code);
    process.memory.swap(memory);
    process.programs.swap(programs);
    process.functions.swap(functions);
    process.function_map = functionMap;
    process.regions.swap(bindings.regions);
    process.linked_modules = linkedModules;
    if (process.code_range_count < std::size(process.code_range_ids))
    {
        const auto range = process.code_range_count++;
        process.code_range_ids[range] = SferaNumeric::lowHalf(module.module_tag);
        process.code_range_begin[range] = codeOffset;
        process.code_range_size[range] = SferaNumeric::lowWord(module.bytecode.size());
    }
    bytecode_base = process.codeData();
    instruction_cursor = bytecode_base + instructionOffset;
    current_instruction_address = bytecode_base + currentOffset;
    process_memory_base = process.memory.data();
    program_table_base = process.programs.data();
    active_program_record = &process.programs[program_index];
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
    forgetMemory(&process);
    process.programs.clear();
    process.functions.clear();
    process.memory.clear();
    process.bytecode.reset();
    process.physics_commands.clear();
    process.regions.clear();
    process.function_map.fill(UINT16_MAX);
    for (std::size_t region = 0; region < process.received_regions.size(); ++region)
    {
        process.region_timestamps[region] = UINT32_MAX;
        process.received_regions[region].reset();
    }
    process.process_id = UINT32_MAX;
    // Keep execution_prev_index until the scheduler has advanced past this slot.
    return 0;
}

bool SferaMbcModuleImage::read(std::span<const std::uint8_t> data, bool linking)
{
    SferaBinaryReader reader(data);
    try
    {
        const auto signature = reader.take(16);
        const auto version = (signature[12] - '0') * 10 + signature[14] - '0';
        reader.read<std::uint32_t>(); // Reserved header word remains part of the encoded image.
        module_tag = reader.read<std::uint32_t>();
        const auto codeSize = reader.read<std::uint32_t>();
        const auto memorySize = reader.read<std::uint32_t>();
        if (module_tag >= 4096 || codeSize > UINT32_MAX - 2)
            return false;
        bytecode = reader.take(codeSize);
        memory = reader.take(memorySize);
        const auto programCount = reader.read<std::uint32_t>();
        if (programCount > 32766 || programCount > reader.remaining() / 15)
            return false;
        programs.assign(programCount, {});
        for (auto &program : programs)
        {
            program.name = reader.readTerminated(32u);
            program.entry_offset = reader.read<std::uint32_t>();
            program.stop_offset = reader.read<std::uint32_t>();
            program.state = reader.read<std::int8_t>();
            program.priority = reader.read<std::uint8_t>();
            (void)reader.read<std::uint32_t>(); // Reserved local-memory word in the module format.
            program.instruction_offset = program.entry_offset;
            program.caller_program = -1;
            if (program.priority >= 4)
                return false;
        }
        const auto functionCount = reader.read<std::uint32_t>();
        if (functionCount > 65535 || functionCount > reader.remaining() / 13)
            return false;
        functions.assign(functionCount, {});
        for (auto &function : functions)
        {
            function.name = reader.readTerminated(32u);
            function.entry_offset = reader.read<std::uint32_t>();
            function.program_index = reader.read<int>();
            function.allow_reentry = reader.read<std::uint32_t>() != 0;
        }
        // Older modules store only the first 30 function slots.
        function_map.fill(UINT16_MAX);
        const auto mapBytes = reader.take((version <= 22 ? 30 : function_map.size()) * sizeof(std::uint16_t));
        for (std::size_t index = 0; index < mapBytes.size() / sizeof(std::uint16_t); ++index)
            function_map[index] = SferaBinary::readLittleEndian<std::uint16_t>(mapBytes.data() + index * sizeof(std::uint16_t));
        region_definitions = reader.take(reader.read<std::uint32_t>());
        position_memory_offset = reader.read<std::uint32_t>();
        reader.take(2 * sizeof(std::uint32_t)); // Reserved exports; consume without storing runtime mirrors.
        if (linking)
            for (auto &table : relocations)
            {
                const auto count = reader.read<std::uint32_t>();
                if (count > reader.remaining() / sizeof(std::uint32_t))
                    return false;
                table.resize(count);
                for (auto &offset : table)
                    offset = reader.read<std::uint32_t>();
            }
        return true;
    }
    catch (const SferaBinaryReadError &)
    {
        return false;
    }
}
