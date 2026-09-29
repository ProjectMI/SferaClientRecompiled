#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string_view>
#include <vector>

#include "script/AotExecution.h"
#include "script/NativeStorage.h"

struct SferaNativeProgramDeclaration
{
    std::string_view name;
    SferaNativeCallable entry;
    SferaNativeCallable stop;
    std::int8_t initial_state;
    std::uint8_t priority;
};

struct SferaNativeExport
{
    std::uint16_t symbol;
    SferaNativeCallable callable;
    std::uint16_t program_index;
    bool allow_reentry;
};

struct SferaNativeRegionDefinition
{
    std::uint8_t index;
    std::int8_t flags;
    std::uint16_t program_index;
    std::span<const std::int8_t> formats;
};

struct SferaNativeModule
{
    std::uint16_t catalog_id;
    std::uint16_t module_tag;
    std::string_view name;
    std::span<const SferaNativeProgramDeclaration> programs;
    std::span<const SferaNativeExport> exports;
    std::span<const std::uint16_t> object_types;
    std::span<const std::uint16_t> function_names;
    std::span<const std::uint16_t> entry_slots;
    std::span<const SferaNativeRegionDefinition> regions;
    std::uint32_t position_access;
    std::uint32_t integer_count = 0;
    std::uint32_t real_count = 0;
    std::uint32_t byte_count = 0;
    std::span<const std::uint32_t> initial_integers{};
    std::span<const std::uint32_t> initial_reals{};
    std::string_view initial_bytes{};

    const SferaNativeExport *findExport(std::uint32_t symbol) const;
};

// A global operand is an allocation index plus a byte offset within that
// allocation. These coordinates never refer to a contiguous process image.
struct SferaNativeGlobalAccess
{
    static constexpr std::uint32_t object(std::uint32_t access) noexcept { return access >> 16; }
    static constexpr std::uint32_t offset(std::uint32_t access) noexcept { return access & 0xffffu; }
};

struct SferaNativeModuleState
{
    const SferaNativeModule *module;
    mutable std::vector<std::shared_ptr<SferaNativeObject>> objects;
    std::shared_ptr<SferaNativeAddressSpace> space;
    std::vector<std::uint32_t> integers;
    std::vector<float> reals;
    std::vector<std::uint8_t> bytes;

    SferaNativeModuleState(const SferaNativeModule &module, const std::shared_ptr<SferaNativeAddressSpace> &space);
    bool hasObject(std::size_t index) const noexcept
    {
        return index < module->object_types.size() && module->object_types[index] != UINT16_MAX;
    }
    const std::shared_ptr<SferaNativeObject> &object(std::size_t index) const;
    SferaSliceReference32 reference(std::uint32_t access, std::uint32_t width) const;
};

class SferaNativeCatalog
{
public:
    static std::uint32_t findSymbol(std::string_view name);
    static std::string_view symbolName(std::uint32_t symbol);
    static std::string_view moduleName(std::uint32_t tag);
    static std::uint32_t findModuleTag(std::string_view name);
    static std::span<const SferaNativeModule> modules();
    static const SferaNativeModule *find(std::string_view name);
    static const SferaNativeObjectInitializer &objectType(std::uint16_t type);
};
