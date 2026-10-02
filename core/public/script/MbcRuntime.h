#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

#include "network/WorldReplication.h"
#include "numeric/Numeric.h"
#include "script/MbcProcess.h"
#include "script/MbcValue.h"
#include "text/Text.h"

class PlayerLists;
struct SferaActiveEffect;
struct SferaMbcRuntime;
struct SferaScriptContainer;
class SferaTextBuffer;
struct WorldObject;
enum class SferaMbcRuntimeBuiltin : std::uint8_t;
enum class SferaMbcRuntimeWindowOperation : std::uint32_t;

enum class SferaMbcRuntimeHaltState
{
    Running,
    Requested,
    Dispatched
};
struct SferaMbcRuntime : SphereScripts::Host
{
    SferaMbcRuntime();
    ~SferaMbcRuntime();

    std::span<SferaMbcValue> engine_arguments;
    std::optional<SferaMbcRuntimeBuiltin> active_builtin;
    std::optional<SferaMbcValue> engine_result;

    std::array<SferaMbcRuntimeOutgoingField, 4088> outgoing_fields{};
    uint32_t game_calendar{};
    WorldObject *current_object{};
    SferaWorldSlotRecord world_slots[401]{};
    std::size_t active_world_slot{};
    uint32_t simulation_tick{};
    float inverse_coordinate_scale{};
    SferaSliceReference32 slice_fallback{};
    SferaSliceReference32 sliceup_fallback{};
    std::int32_t dispatch_slot = -1;

    // Script words remain 32-bit; mapped addresses never contain truncated native pointers.
    static constexpr std::uint32_t mappedAddressBegin = 1u << 31;

    using MemoryRegions = std::map<std::uint32_t, SferaMbcRuntimeMemoryRegion>;
    MemoryRegions mapped_memory;
    // The last legacy String supplied to Configuration owns this borrowed native span.
    // It is invalidated at release, never resolved through a numeric address on access.
    const SferaMbcRuntimeMemoryRegion *configuration_source{};

  private:
    // Non-overlapping native ranges have one predecessor lookup. Overlapping
    // registrations keep the original lowest-script-address alias precedence.
    std::map<std::uintptr_t, MemoryRegions::iterator> mapped_native_memory;
    std::map<std::uint32_t, MemoryRegions::iterator> overlapping_native_memory;
    std::unordered_multimap<const void *, MemoryRegions::iterator> mapped_memory_owners;
    std::uint64_t memory_search_start = mappedAddressBegin;

  public:
    std::unordered_map<std::uint32_t, SferaMbcRuntimeNativeResource> native_resources;
    std::unordered_map<SferaMbcRuntimeNativeResource, std::uint32_t> native_resource_ids;
    std::uint32_t next_native_handle = 1;
    std::span<std::uint8_t> memoryRange(std::uint32_t address) const;
    // Legacy pointer/count operations are bounded by their mapped region.
    std::span<std::uint8_t> memoryBytes(std::uint32_t address, std::size_t count) const;
    SferaTextBuffer textBufferAt(std::uint32_t address) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32 &slice) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32 &slice, std::size_t count) const;
    // MBC text arguments have C-string semantics; slice metadata may describe only an element.
    std::string textIn(const SferaSliceReference32 &slice) const;
    std::string textIn(const SferaSliceReference32 &slice, std::size_t limit) const;
    std::string memoryDiagnostic(std::string_view message, std::uint32_t address, std::size_t size) const;
    std::uint8_t *memoryAt(std::uint32_t address, std::size_t size) const;
    std::string textAt(std::uint32_t address) const;
    std::string textAt(std::uint32_t address, std::size_t limit) const;
    SferaTextBuffer textBuffer(const SferaSliceReference32 &slice) const;
    std::uint32_t mapMemory(const void *data, std::size_t size, const void *owner = nullptr);
    void forgetMemory(const void *owner, const void *data = nullptr, std::size_t size = 0);
    void clearMappedMemory() noexcept;
    std::uint32_t addMemoryRegion(SferaMbcRuntimeMemoryRegion region);
    template <class T> std::uint32_t nativeHandle(T value)
    {
        if (value == nullptr)
            return 0;
        const SferaMbcRuntimeNativeResource resource{value};
        if (const auto existing = native_resource_ids.find(resource); existing != native_resource_ids.end())
            return existing->second;
        if (next_native_handle >= INT32_MAX)
            throw std::length_error("Script resource handles exhausted");
        const auto handle = next_native_handle++;
        native_resources.emplace(handle, resource);
        try
        {
            native_resource_ids.emplace(resource, handle);
        }
        catch (...)
        {
            native_resources.erase(handle);
            throw;
        }
        return handle;
    }
    template <class T> T nativeResource(std::uint32_t handle) const
    {
        if (const auto entry = native_resources.find(handle); entry != native_resources.end())
            if (const auto *value = std::get_if<T>(&entry->second))
                return *value;
        return nullptr;
    }
    void forgetNativeResource(const SferaMbcRuntimeNativeResource &resource);

    std::int32_t nextInteger();
    std::uint32_t nextWord();
    float nextReal();
    SferaSliceReference32 &nextSliceReference(std::string_view diagnostic = "popsliceupref(): stack underflow");
    SferaSliceReference32 nextSlice();
    // Legacy address arguments use numeric conversion for scalar values, as nextInteger did.
    SferaSliceReference32 nextAddress();
    void pushInteger(std::uint32_t value);
    template <class Integer>
        requires(std::is_integral_v<Integer> && !std::is_same_v<std::remove_cv_t<Integer>, std::uint32_t>)
    void pushInteger(Integer value)
    {
        static_assert(sizeof(Integer) <= sizeof(std::uint32_t), "MBC integer result must fit the 32-bit VM word");
        if constexpr (std::is_signed_v<Integer>)
        {
            std::int32_t signed_value = value;
            pushInteger(SferaNumeric::word(signed_value));
        }
        else
        {
            std::uint32_t word = value;
            pushInteger(word);
        }
    }
    void pushReal(float value);
    void pushReal(double value);
    void pushSlice(const SferaSliceReference32 &value, SferaMbcValueType type);
    SferaMbcProcessRecord *findProcess(std::uint32_t id);
    std::uint32_t loadProcess(std::string_view name, std::uint32_t requestedIndex);
    std::uint32_t linkProcess(std::string_view name);
    static std::string_view moduleName(std::uint32_t tag) noexcept;
    static std::uint32_t moduleTag(std::string_view name) noexcept;
    std::uint32_t unloadProcess(std::uint32_t index);
    std::uint32_t namedValue(std::string_view name, int index = 0) override;
    void setNamedValue(std::string_view name, std::uint32_t value, int index = 0) override;
    bool reportError(std::string_view message);
    bool reportError(std::string_view prefix, std::string_view suffix);
    void enqueueProcess(int index, SferaMbcProcessRecord &process);
    void dequeueProcess(SferaMbcProcessRecord &process);
    bool executeBuiltin(SferaMbcRuntimeBuiltin builtin);

    template <class T> T readMemory(std::uint32_t offset) const
    {
        T result;
        std::memcpy(&result, memoryAt(offset, sizeof(result)), sizeof(result));
        return result;
    }
    template <class T> void writeMemory(std::uint32_t offset, const T &value)
    {
        std::memcpy(memoryAt(offset, sizeof(value)), &value, sizeof(value));
    }
    void writeReal(std::uint32_t offset, double value)
    {
        writeMemory(offset, SferaNumeric::real32(value));
    }
    void exportSlice(SferaSliceReference32 &destination, const void *data, std::size_t size, const void *owner);
    void initialize();
    void tick();
    void systemCommand();
    void buildRegion();
    std::string formatArguments(std::string_view pattern, std::size_t limit = std::numeric_limits<std::size_t>::max());
    void formatText(bool bounded);
    void writeFormattedLog(bool named);
    void receiveRegion();
    void sendRegion(int slotIndex, std::uint32_t region, std::uint32_t flags);
    void windowCommand();
    std::int32_t processModule(std::uint32_t id) const override;
    std::int32_t nextProcessByModule(std::uint32_t module, std::optional<std::int32_t> previous = {}) const;
    std::int32_t nextProcessByName(std::string_view name, std::optional<std::int32_t> previous = {}) const;
    std::int32_t tickValue() const override;
    std::int32_t keyState(std::uint32_t key) const override;
    std::string stringValue(SphereScripts::Address value, std::size_t limit = SIZE_MAX) const override;
    void diagnoseBuffer(SphereScripts::Address &value, std::uint32_t count) override;
    std::uint32_t copyText(std::span<std::byte> destination, std::string_view source, int capacity = 0) override;
    std::int32_t stringLength(SphereScripts::Address source, std::optional<std::int32_t> limit = {}) override;
    using SphereScripts::Host::copyString;
    using SphereScripts::Host::stringValue;
    using SphereScripts::Host::stringLength;
    void setAnimation(std::int32_t handle, std::int32_t value, bool secondary = false) override;
    void setFrame(std::int32_t handle, std::int32_t value, bool secondary = false) override;
    std::int32_t animationLength(std::int32_t handle, std::int32_t animation) override;
    void setInterpolation(std::int32_t handle, float value) override;
    std::int32_t objectProcess(std::int32_t handle) override;
    void setPosition(std::int32_t handle, SferaVec3F value, bool updateSpatial = false,
                             std::optional<std::int32_t> membership = {}) override;
    void moveWorld(std::int32_t handle, SferaVec3F value) override;
    void setRotation(std::int32_t handle, SferaVec3F value) override;
    void moveLocal(std::int32_t handle, SferaVec3F value) override;
    void rotateObject(std::int32_t handle, SferaVec3F value) override;
    void setCommandVelocity(std::int32_t handle, float x, float z, std::optional<float> y = {}) override;
    void setVerticalVelocity(std::int32_t handle, float value) override;
    void setVerticalResponse(std::int32_t handle, std::int32_t response) override;
    void setAngularVelocity(std::int32_t handle, float value) override;
    std::optional<SferaVec3F> objectPosition(std::int32_t handle) override;
    std::optional<SferaVec3F> objectRotation(std::int32_t handle) override;
    std::optional<SferaVec3F> objectBasis(std::int32_t handle) override;
    float positionComponent(std::int32_t handle, std::size_t axis) override;
    float rotationComponent(std::int32_t handle, std::size_t axis) override;
    void setRenderEnabled(std::int32_t handle, bool enabled) override;
    void destroyObject(std::int32_t handle) override;
    void destroyText(std::int32_t handle) override;
    void destroySprite(std::int32_t handle) override;
    std::int32_t createObject(std::string_view name, std::uint32_t kind, std::int32_t independent = 0) override;
    std::int32_t interfaceControl(std::uint32_t handle, std::int32_t id, bool listItem = false) override;
    void closeInterface(std::uint32_t handle) override;
    std::int32_t sendInterfaceMessage(std::uint32_t handle, SphereUIUiMessage message,
                                    std::uint32_t first, std::uint32_t second, std::uint32_t flags) override;
    bool validateBorrowed(SphereScripts::Address value) override;
    SphereScripts::String processReference(std::uint32_t process, SphereScripts::Address value) override;
    void checkEngineFailure() const;
    WorldObject *selectWorldObject(std::int32_t handle);
    void trackControlledPosition(std::int32_t handle, const WorldObject &object);
    SphereScripts::Module &selectModule(SphereScripts::Module &caller, bool (*accepts)(SphereScripts::Module &)) override;
    SphereScripts::Module &mainModule() override;
    SphereScripts::Value invokeEngine(SferaMbcRuntimeBuiltin command, std::span<const SphereScripts::Argument> arguments) override;
    SphereScripts::Task<SphereScripts::Value> callProcess(SphereScripts::Module &caller, bool mainProcess, std::vector<SphereScripts::Argument> arguments) override;
    SphereScripts::Address mapObject(const void *address, std::size_t size, const void *owner) override;
    void forgetObject(const void *owner) noexcept override;
    std::span<std::byte> memory(SphereScripts::Address address, std::size_t size) override;
    std::span<std::byte> memory(SphereScripts::Address address) override;
    bool alive(const SphereScripts::Module &module) const noexcept override;
    void warning(std::string_view message) override;
    void selectContext(SphereScripts::Context context) override;
    void programAction(SphereScripts::Module &module, std::string_view name, SphereScripts::ProgramAction action) override;
    void halt() override;
    void returnFirstArgument();
    void runProgram(SferaMbcProcessRecord &process, std::size_t index);
    std::string nextText();
    void copyText(const SferaSliceReference32 &destination, std::string_view text);

    int32_t execution_chain_tail;
    int32_t execution_chain_head;
    std::size_t execution_chain_count;
    int32_t process_chain_first;
    int32_t process_chain_last;
    ScriptProgramDiagnostic *program_table_base;
    std::string diagnostic_context;
    std::string first_execution_error;
    int argument_count;
    std::size_t argument_end;
    std::int32_t process_index = -1;
    uint32_t active_tag;
    static constexpr std::size_t text_capacity = 10000;
    std::string text_buffer;
    SferaMbcProcessRecord processes[65536];
    uint32_t process_search_cursor;
    int program_index;
    std::size_t argument_cursor;
    SferaMbcRuntimeHaltState halt_state;

    ScriptProgramDiagnostic *active_program_record;
    SferaMbcProcessRecord *active_process;
    std::uint64_t next_process_lifetime = 1;
    std::unordered_map<std::uint32_t, std::unique_ptr<std::vector<std::uint8_t>>> dynamic_blocks;
    std::unordered_map<std::uint32_t, std::unique_ptr<SferaScriptContainer>> containers;
    std::uint32_t allocateDynamic(std::size_t size);
    bool releaseDynamic(std::uint32_t address) noexcept;
    void destroyContainer(std::uint32_t handle) noexcept;
    void shutdown();
    bool final_shutdown = false;
    std::size_t send_field_count;
    bool execution_failed;

    std::unordered_map<std::string, std::vector<std::uint32_t>, SferaTextHash, std::equal_to<>> named_vectors;

  private:
    static std::uint32_t copyString(SferaTextBuffer destination, std::string_view source, int capacity);

  private:
    auto executeBuiltinText(int offset);
    auto executeBuiltinName(int offset);
    auto executeBuiltinLookup(PlayerLists &manager, int offset);
    auto executeBuiltinCopyName(std::uint32_t address, std::string_view value);
    auto windowCommandRead(std::array<std::int32_t, 6> &arguments, std::size_t count);
    auto windowCommandInputText(std::int32_t offset);
    auto windowCommandOptionalInputText(std::int32_t offset) -> std::optional<std::string>;
    auto windowCommandWarnNull(SferaMbcRuntimeWindowOperation operation, std::int32_t offset, std::uint32_t argument);
    auto receiveRegionWrongCount();
    auto receiveRegionWrongData();
    auto receiveRegionNextOutput() -> const SferaMbcValue *;
    auto receiveRegionStore(const SferaMbcValue &target, std::uint32_t value);
    auto sendRegionCaptureOrigin(SferaWorldSlotRecord &slot);
    auto formatArgumentsInvalid();
    auto formatArgumentsWord(std::size_t &next, const std::vector<std::variant<int, double, SferaSliceReference32>> &arguments) -> std::uint32_t;
    auto formatArgumentsPointer(std::size_t &next, const std::vector<std::variant<int, double, SferaSliceReference32>> &arguments) -> SferaSliceReference32;
    auto formatArgumentsAppend(std::size_t limit, std::string &result, const std::string &specifier, auto value);
    auto formatArgumentsCharacterAt(std::string_view pattern, std::size_t position);
    std::uint32_t systemCommandAddress(std::string_view name);
    std::string systemCommandText(std::uint32_t offset);
    auto systemCommandSelectedObject() -> WorldObject *;
    auto systemCommandReadArray(std::int32_t count, const SferaSliceReference32 &reference);
    auto tickFlush(std::uint32_t &bits, auto &payload, std::uint32_t &owner, std::uint32_t flags);
    auto buildRegionEmit(std::uint32_t value, std::int8_t width);

  private:
    static bool activeEffectMatches(const SferaActiveEffect *created, const std::shared_ptr<SferaActiveEffect> &item);
    static bool crossesBoundary(float first, float second, float value);

  private:
    void executeSystemWorld(std::int32_t operation);
    void executeSystemEnvironment(std::int32_t operation);
    void executeSystemInterface(std::int32_t operation);
    void executeSystemRuntime(std::int32_t operation);
    void executeSystemResources(std::int32_t operation);
    void executeSystemCompatibility(std::int32_t operation);
    void executeSystemValues(std::int32_t operation);
};

extern SferaMbcRuntime g_sfera_mbc_runtime;
