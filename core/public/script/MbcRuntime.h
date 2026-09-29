#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <io.h>
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
class QuickFile;
struct SferaActiveEffect;
struct SferaMbcRuntime;
struct SferaScriptContainer;
class SferaTextBuffer;
struct WorldObject;
enum class SferaMbcRuntimeBuiltin : std::uint8_t;
enum class SferaMbcRuntimeInstruction : std::uint8_t;
enum class SferaMbcRuntimeWindowOperation : std::uint32_t;

enum class SferaMbcRuntimeHaltState
{
    Running,
    Requested,
    Dispatched
};
struct SferaMbcRuntime
{
    SferaMbcRuntime();
    ~SferaMbcRuntime();

    std::array<SferaMbcValue, 256> values{};
    std::array<SferaMbcModuleRecord, 4096> modules{};

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

    std::map<std::uint32_t, SferaMbcRuntimeMemoryRegion> mapped_memory;
    std::unordered_map<std::uint32_t, SferaMbcRuntimeNativeResource> native_resources;
    std::unordered_map<SferaMbcRuntimeNativeResource, std::uint32_t> native_resource_ids;
    std::uint32_t next_native_handle = 1;
    std::uint64_t next_memory_lifetime = 1;
    std::span<std::uint8_t> memoryRange(std::uint32_t address, SferaMbcProcessRecord *process = nullptr) const;
    // Legacy pointer/count operations are bounded by their process or mapped region.
    std::span<std::uint8_t> memoryBytes(std::uint32_t address, std::size_t count, SferaMbcProcessRecord *process = nullptr) const;
    SferaTextBuffer textBufferAt(std::uint32_t address, SferaMbcProcessRecord *process = nullptr) const;
    std::uint64_t memoryLifetime(std::uint32_t address) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process = nullptr) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32 &slice, std::size_t count, SferaMbcProcessRecord *process = nullptr) const;
    // A VM address is an offset: zero can name the first byte of process memory.
    // Required-pointer APIs reject zero at their call sites, not in memory adapters.
    // MBC text arguments have C-string semantics; slice metadata may describe only an element.
    std::string textIn(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process = nullptr) const;
    std::string textIn(const SferaSliceReference32 &slice, std::size_t limit, SferaMbcProcessRecord *process = nullptr) const;
    std::uint8_t *memoryAt(std::uint32_t address, std::size_t size, SferaMbcProcessRecord *process = nullptr) const;
    std::string textAt(std::uint32_t address) const;
    std::string textAt(std::uint32_t address, std::size_t limit) const;
    SferaTextBuffer textBuffer(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process = nullptr) const;
    std::uint32_t mapMemory(const void *data, std::size_t size, const void *owner = nullptr);
    std::uint32_t mapProcessMemory(SferaMbcProcessRecord &process);
    SferaSliceReference32 rebaseSlice(SferaSliceReference32 slice, SferaMbcProcessRecord &source);
    void forgetMemory(const void *owner);
    std::uint32_t addMemoryRegion(SferaMbcRuntimeMemoryRegion region);
    template <class T> std::uint32_t nativeHandle(T value)
    {
        if constexpr (std::is_pointer_v<T>)
        {
            if (value == nullptr)
                return 0;
        }
        else if (value == -1)
            return UINT32_MAX;
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
        if constexpr (std::is_pointer_v<T>)
            return nullptr;
        else
            return -1;
    }
    void forgetNativeResource(const SferaMbcRuntimeNativeResource &resource);

    std::int32_t popInteger();
    std::uint32_t popWord();
    SferaSliceReference32 &popSlice();
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
    void pushReference(SferaMbcValueType type, const SferaSliceReference32 &reference, bool load);
    SferaMbcProcessRecord *findProcess(std::uint32_t id);
    std::uint32_t loadProcess(std::string_view name, std::uint32_t requestedIndex);
    std::uint32_t linkProcess(std::string_view name);
    std::uint32_t unloadProcess(std::uint32_t index);
    std::shared_ptr<const std::vector<std::uint8_t>> cacheBytecode(std::shared_ptr<const std::vector<std::uint8_t>> code, const SferaMbcModuleIds &modules, std::uint32_t memorySize);
    void resetBytecodeCache();
    std::shared_ptr<const std::vector<std::uint8_t>> findBytecode(const SferaMbcModuleIds &modules, std::uint32_t memorySize) const;
    std::uint32_t namedValue(std::string_view name, int index = 0);
    void setNamedValue(std::string_view name, std::uint32_t value, int index = 0);
    bool reportError(std::string_view message);
    bool reportError(std::string_view prefix, std::string_view suffix);
    void enqueueProcess(int index, SferaMbcProcessRecord &process);
    void dequeueProcess(SferaMbcProcessRecord &process);
    bool executeInstruction(SferaMbcRuntimeInstruction instruction);
    bool executeBuiltin(SferaMbcRuntimeBuiltin builtin);
    template <class T> T readOperand()
    {
        T result;
        std::memcpy(&result, instruction_cursor, sizeof(result));
        instruction_cursor += sizeof(result);
        return result;
    }
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
    void reportInvalidInstruction();
    void exportSlice(SferaSliceReference32 &destination, const void *data, std::size_t size, const void *owner);
    void initialize();
    void tick();
    void reloadQuickFiles();
    void systemCommand();
    void buildRegion();
    std::string formatArguments(std::string_view pattern, std::size_t limit = std::numeric_limits<std::size_t>::max());
    void formatText(bool bounded);
    void writeFormattedLog(bool named);
    void receiveRegion();
    void sendRegion(int slotIndex, std::uint32_t region, std::uint32_t flags);
    void bindParameters();
    void callFunction(bool mainProcess);
    void returnFromFunction();
    void calculateDistance();
    void scanText();
    void chatUtility();
    void parseText();
    void windowCommand();
    void writeScriptLog();
    std::string nextText();
    void copyText(const SferaSliceReference32 &destination, std::string_view text);

    int32_t execution_chain_tail;
    int32_t execution_chain_head;
    std::size_t execution_chain_count;
    int32_t process_chain_first;
    int32_t process_chain_last;
    ScriptProgramDiagnostic *program_table_base;
    const std::uint8_t *instruction_cursor;
    std::string diagnostic_context;
    std::string first_execution_error;
    int argument_count;
    std::size_t argument_end;
    std::int32_t process_index = -1;
    const std::uint8_t *current_instruction_address;
    uint32_t active_tag;
    _finddata64i32_t script_find_data;
    static constexpr std::size_t text_capacity = 10000;
    std::string text_buffer;
    int call_frame_depth;
    SferaMbcProcessRecord processes[65536];
    uint32_t process_search_cursor;
    int instruction_step_count;
    int program_index;
    int execution_context_depth;
    const std::uint8_t *bytecode_base;
    SferaMbcExecutionContext execution_context_stack[100];
    std::size_t argument_cursor;
    std::size_t frame_stack_base[22];
    SferaMbcRuntimeHaltState halt_state;

    ScriptProgramDiagnostic *active_program_record;
    std::size_t value_stack_size;
    SferaMbcProcessRecord *active_process;
    std::map<SferaMbcBytecodeKey, std::shared_ptr<const std::vector<std::uint8_t>>> bytecode_cache;
    std::unique_ptr<QuickFile> quick_files;
    std::uint64_t next_process_lifetime = 1;
    std::unordered_map<std::uint32_t, std::unique_ptr<std::vector<std::uint8_t>>> dynamic_blocks;
    std::unordered_map<std::uint32_t, std::unique_ptr<SferaScriptContainer>> containers;
    std::uint32_t allocateDynamic(std::size_t size);
    bool releaseDynamic(std::uint32_t address) noexcept;
    void destroyContainer(std::uint32_t handle) noexcept;
    void shutdown();
    bool final_shutdown = false;
    std::uint8_t *process_memory_base;
    std::size_t send_field_count;
    bool execution_failed;
    SferaMbcRuntimeInstruction current_opcode;

    std::unordered_map<std::string, std::vector<std::uint32_t>, SferaTextHash, std::equal_to<>> named_vectors;

  private:
    static std::uint32_t copyString(SferaTextBuffer destination, std::string_view source, int capacity);

  private:
    auto executeBuiltinText(int offset);
    auto executeBuiltinName(int offset);
    auto executeBuiltinLookup(PlayerLists &manager, int offset);
    auto executeBuiltinCopyName(std::uint32_t address, std::string_view value);
    auto callFunctionFail();
    template <class T> auto scanTextNumber(auto &references, std::size_t &output, auto &numbers, auto &destinations);
    auto scanTextCharacter(const std::string &pattern, std::size_t position);
    template <std::size_t Index>
    auto scanTextScan(const std::string &text, const std::string &normalized, const std::array<unsigned, 4> &capacities, const std::array<void *, 4> &destinations, std::array<int, 4> &completed,
                      auto... arguments) -> int;
    auto parseTextDigit(std::uint8_t value);
    auto parseTextLetter(std::uint8_t value);
    auto parseTextSpace(std::uint8_t value);
    auto windowCommandRead(std::array<std::int32_t, 6> &arguments, std::size_t count);
    auto windowCommandInputText(std::int32_t offset);
    auto windowCommandOptionalInputText(std::int32_t offset) -> std::optional<std::string>;
    auto windowCommandWarnNull(SferaMbcRuntimeWindowOperation operation, std::int32_t offset, std::uint32_t argument);
    auto receiveRegionWrongCount();
    auto receiveRegionWrongData();
    auto receiveRegionNextOutput() -> const SferaMbcValue *;
    auto receiveRegionStore(const SferaMbcValue &target, std::uint32_t value);
    auto sendRegionCaptureOrigin(SferaWorldSlotRecord &slot);
    auto linkProcessValidRelocations(const auto &table, std::size_t size, std::size_t width);
    template <class T> auto linkProcessRelocate(std::uint8_t *destination, const auto &table, std::uint32_t increment);
    auto linkProcessResolve(const std::vector<SferaMbcFunctionRecord> &functions, const std::shared_ptr<std::vector<std::uint8_t>> &writable, std::uint32_t first, std::uint32_t last,
                            std::uint32_t targetFirst, std::uint32_t targetLast);
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
    static bool memoryOwnedBy(const void *owner, const std::pair<const std::uint32_t, SferaMbcRuntimeMemoryRegion> &entry);
    bool moduleMatches(std::int32_t address, const SferaMbcModuleRecord &module);
    static bool activeEffectMatches(const SferaActiveEffect *created, const std::shared_ptr<SferaActiveEffect> &item);
    static bool relocationFits(std::size_t size, std::size_t width, std::uint32_t offset);
    static bool crossesBoundary(float first, float second, float value);
    static bool negativeModuleIndex(std::uint16_t index);
    template <class Value> void scanTextStoreNumber(const Value &value, const SferaSliceReference32 &reference, std::size_t characters);
    template <class Value> void scanTextStoreText(const Value &value, const SferaSliceReference32 &reference, std::size_t characters);
    template <bool Text, std::size_t Index = 0, class... Values> void scanTextStoreVariant(const std::variant<Values...> &value, const SferaSliceReference32 &reference, std::size_t characters);

  private:
    bool executeControlBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeNetworkBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeTextBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeVisualBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeMathBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeConfigurationBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeFilesBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeWorldBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeMemoryBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executePlayersBuiltin(SferaMbcRuntimeBuiltin builtin);
    bool executeContainersBuiltin(SferaMbcRuntimeBuiltin builtin);
    void executeSystemWorld(std::int32_t operation);
    void executeSystemEnvironment(std::int32_t operation);
    void executeSystemInterface(std::int32_t operation);
    void executeSystemRuntime(std::int32_t operation);
    void executeSystemResources(std::int32_t operation);
    void executeSystemCompatibility(std::int32_t operation);
    void executeSystemValues(std::int32_t operation);
};

extern SferaMbcRuntime g_sfera_mbc_runtime;
