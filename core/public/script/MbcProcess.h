#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <list>
#include <memory>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "numeric/Numeric.h"

struct ScriptProgramDiagnostic;
struct SferaMbcExecutionContext;
struct SferaMbcFunctionRecord;

struct ScriptProgramDiagnostic
{
    std::string name;
    std::uint32_t entry_offset;
    std::uint32_t stop_offset;
    std::int8_t state;
    std::uint8_t priority;
    std::uint32_t return_offsets[20];
    std::uint8_t callDepth;

    std::uint32_t instruction_offset;

    bool executing;

    int caller_program;
    std::uint16_t previous_program;
    std::uint16_t next_program;
};

struct SferaMbcExecutionContext
{
    std::int32_t process_index = -1;
    int program_index = -1;
    std::uint32_t instruction_offset{};
    std::uint32_t process_id = UINT32_MAX;
    std::uint64_t process_lifetime{};
};

struct SferaMbcFunctionRecord
{
    std::string name;
    std::uint32_t entry_offset;
    int program_index;
    bool allow_reentry;
};

// Runtime names are owned strings. MBC files still encode names with a 31-byte limit.

struct SferaMbcBytecodeKey;
struct SferaMbcModuleImage;
struct SferaMbcModuleRecord;

struct SferaMbcModuleRecord
{
    std::string name;
};

struct SferaMbcModuleImage
{
    static constexpr std::size_t functionSlotCount = 80;
    std::uint32_t module_tag = 0;
    std::span<const std::uint8_t> bytecode;
    std::span<const std::uint8_t> memory;
    std::vector<ScriptProgramDiagnostic> programs;
    std::vector<SferaMbcFunctionRecord> functions;
    std::array<std::uint16_t, functionSlotCount> function_map;
    std::span<const std::uint8_t> region_definitions;
    std::uint32_t position_memory_offset = 0;
    std::array<std::vector<std::uint32_t>, 3> relocations;
    bool read(std::span<const std::uint8_t> data, bool linking);
};

using SferaMbcModuleIds = std::array<std::uint16_t, 8>;
struct SferaMbcBytecodeKey
{
    SferaMbcModuleIds modules;
    std::uint32_t memory_size;
    bool operator<(const SferaMbcBytecodeKey &other) const noexcept
    {
        return modules == other.modules ? memory_size < other.memory_size : modules < other.modules;
    }
};

struct SferaMbcRegionPacket;
struct SferaMbcRegionRecord;
struct SferaMbcRuntimeOutgoingField;

struct SferaMbcRegionRecord
{
    static constexpr SferaMbcRegionRecord undefined()
    {
        SferaMbcRegionRecord result{};
        std::fill(std::begin(result.formats), std::end(result.formats), std::int8_t{-1});
        result.field_count = -1;
        result.flags = -1;
        result.program_index = UINT16_MAX;
        return result;
    }
    std::int8_t formats[28];
    int field_count;
    std::int8_t flags;

    std::uint16_t program_index;
};

struct SferaMbcRegionPacket
{
    std::vector<std::uint8_t> data;
    std::uint32_t timestamp{};
    std::array<int, 3> origin{};
};

struct SferaMbcRuntimeOutgoingField
{
    std::uint32_t word;
    std::int8_t format;
};

struct SferaMbcProcessRecord;
struct SferaMbcProcessRecordCleanupEntry;

enum SferaMbcProcessRecordFlags : std::uint32_t
{
    SferaMbcProcessRecordFlagsunloadAfterExecution = 1u << 2,
    SferaMbcProcessRecordFlagsmarkedForUnload = 1u << 5
};
enum class SferaMbcProcessRecordResourceKind
{
    worldObject,
    file,
    fileSearch,
    dynamicArray,
    textControl,
    spriteControl,
    gameWindow,
    interfaceWindow,
    container
};
struct SferaMbcProcessRecordCleanupEntry
{
    std::uint32_t handle;
    SferaMbcProcessRecordResourceKind kind;
    std::uint64_t resource_lifetime = 0;
};

struct SferaMbcProcessRecord
{
    void registerResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind);
    void unregisterResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind);
    void linkProgram(std::size_t index);
    bool activateProgram(std::size_t index);
    bool activateProgram(std::string_view name);
    void appendCommand(std::string_view command);
    std::uint32_t growMemory(std::size_t size);
    SferaMbcFunctionRecord *findFunction(std::string_view name);
    void readRegions(std::span<const std::uint8_t> definitions, std::uint32_t firstProgram);
    void releaseResources();
    void queueRegion(std::size_t region, std::uint32_t timestamp, std::span<const int, 3> origin, std::span<const std::uint8_t> payload, std::size_t firstBit, std::size_t bitCount, bool ordered);
    std::string name;
    SferaMbcModuleIds linked_modules;
    uint32_t module_tag;
    std::shared_ptr<const std::vector<std::uint8_t>> bytecode;
    std::vector<std::uint8_t> memory;
    std::vector<ScriptProgramDiagnostic> programs;
    std::vector<SferaMbcFunctionRecord> functions;
    const std::uint8_t *codeData() const noexcept
    {
        return bytecode ? bytecode->data() : nullptr;
    }
    std::uint32_t codeSize() const noexcept
    {
        return bytecode ? SferaNumeric::lowWord(bytecode->size()) : 0;
    }
    int32_t chain_prev_index = -1;
    int32_t chain_next_index = -1;
    uint16_t program_map_a[4];
    uint16_t program_map_b[4];
    uint32_t field_084;
    uint32_t flags;
    std::vector<SferaMbcProcessRecordCleanupEntry> cleanup_entries;
    std::string physics_commands;
    uint32_t process_id = UINT32_MAX;
    std::uint64_t lifetime{};
    bool programs_queued;
    bool execution_linked;
    std::array<std::uint16_t, SferaMbcModuleImage::functionSlotCount> function_map{};
    int32_t execution_prev_index;
    int32_t execution_next_index;
    std::vector<SferaMbcRegionRecord> regions; // Bindings belong to this process, not to the shared module catalogue.
    std::uint32_t region_timestamps[63];
    std::array<std::unique_ptr<std::list<SferaMbcRegionPacket>>, 63> received_regions;
    uint16_t code_range_ids[8];
    uint32_t code_range_begin[8];
    uint32_t code_range_size[8];
    uint16_t code_range_count;

  private:
    static std::uint64_t *resourceLifetime(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind);
    static bool resourceIsCurrent(const SferaMbcProcessRecordCleanupEntry &entry);
};

using SferaMbcRuntimeResourceKind = SferaMbcProcessRecordResourceKind;
