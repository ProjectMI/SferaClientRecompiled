#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <list>
#include <memory>
#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "script/NativeModule.h"

struct ScriptProgramDiagnostic;
struct SferaMbcFunctionRecord;

struct ScriptProgramDiagnostic
{
    std::string_view name;
    SferaNativeEntry entry;
    SferaNativeEntry stop;
    SferaNativeEntry selected;
    std::optional<SferaNativeEntry> pending_start;
    std::shared_ptr<SferaNativeTask> task;
    std::int8_t state = -1;
    std::uint8_t priority = 0;
    bool executing = false;
    int caller_program = -1;
    std::uint16_t previous_program = UINT16_MAX;
    std::uint16_t next_program = UINT16_MAX;

    void select(SferaNativeEntry target)
    {
        if (executing)
        {
            pending_start = target;
            return;
        }
        task.reset();
        selected = target;
        pending_start.reset();
    }
};

struct SferaMbcFunctionRecord
{
    std::string_view name;
    SferaNativeEntry entry;
    int program_index;
    bool allow_reentry;
};

// Declaration names refer to immutable native catalogue storage; process names remain owned.

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
struct SferaNativeModule;

struct SferaNativeBinding
{
    const SferaNativeModule *module;
    std::shared_ptr<SferaNativeModuleState> storage;
    std::uint32_t program_base;
    std::uint32_t binding_index = 0;
};

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
    static constexpr std::size_t functionSlotCount = 80;
    void registerResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind);
    void unregisterResource(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind);
    void linkProgram(std::size_t index);
    bool activateProgram(std::size_t index);
    bool activateProgram(std::string_view name);
    void appendCommand(std::string_view command);
    std::uint32_t growMemory(std::size_t size);
    std::optional<SferaMbcFunctionRecord> findFunction(std::string_view name) const;
    std::optional<SferaMbcFunctionRecord> findFunction(std::uint32_t slot) const;
    SferaNativeEntry selectExport(std::uint32_t callerBinding, std::uint32_t symbol, std::span<const std::uint64_t> providers = {}, SferaNativeCallable knownCallable = {}) const;
    void readRegions(std::span<const SferaNativeRegionDefinition> definitions, std::uint32_t firstProgram);
    void releaseResources();
    void queueRegion(std::size_t region, std::uint32_t timestamp, std::span<const int, 3> origin, std::span<const std::uint8_t> payload, std::size_t firstBit, std::size_t bitCount, bool ordered);
    std::string name;
    uint32_t module_tag;
    std::vector<std::shared_ptr<SferaNativeObject>> allocations;
    unsigned native_depth = 0;
    std::vector<ScriptProgramDiagnostic> programs;
    std::vector<SferaNativeBinding> native_bindings;
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
    int32_t execution_prev_index;
    int32_t execution_next_index;
    std::vector<SferaMbcRegionRecord> regions; // Bindings belong to this process, not to the shared module catalogue.
    std::uint32_t region_timestamps[63];
    std::array<std::unique_ptr<std::list<SferaMbcRegionPacket>>, 63> received_regions;

  private:
    static std::uint64_t *resourceLifetime(std::uint32_t handle, SferaMbcProcessRecordResourceKind kind);
    static bool resourceIsCurrent(const SferaMbcProcessRecordCleanupEntry &entry);
};

using SferaMbcRuntimeResourceKind = SferaMbcProcessRecordResourceKind;
