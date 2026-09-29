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
#include "script/AotExecution.h"
#include "script/MbcProcess.h"
#include "script/MbcValue.h"
#include "script/NativeMappings.h"
#include "script/NativeCall.h"
#include "script/NativeContext.h"
#include "text/Text.h"

class PlayerLists;
struct SferaActiveEffect;
struct SferaMbcRuntime;
struct SferaScriptContainer;
class SferaTextBuffer;
struct WorldObject;
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

    SferaNativeCall *native_call = nullptr;
    std::shared_ptr<SferaNativeAddressSpace> native_space = std::make_shared<SferaNativeAddressSpace>();
    std::uint32_t native_caller_process = UINT32_MAX;

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

    SferaNativeMappings mapped_memory;
    std::unordered_map<std::uint32_t, SferaMbcRuntimeNativeResource> native_resources;
    std::unordered_map<SferaMbcRuntimeNativeResource, std::uint32_t> native_resource_ids;
    std::uint32_t next_native_handle = 1;
    std::uint64_t next_memory_lifetime = 1;
    std::span<std::uint8_t> memoryRange(std::uint32_t address, SferaMbcProcessRecord *process = nullptr) const;
    // Host pointer/count operations are bounded by their native object or mapped region.
    std::span<std::uint8_t> memoryBytes(std::uint32_t address, std::size_t count, SferaMbcProcessRecord *process = nullptr) const;
    SferaTextBuffer textBufferAt(std::uint32_t address, SferaMbcProcessRecord *process = nullptr) const;
    std::uint64_t memoryLifetime(std::uint32_t address) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process = nullptr) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32 &slice, std::size_t count, SferaMbcProcessRecord *process = nullptr) const;
    // Zero is the null native reference. MBC offsets are resolved to owned objects
    // by the generated global-access descriptors before reaching this interface.
    // MBC text arguments have C-string semantics; slice metadata may describe only an element.
    std::string textIn(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process = nullptr) const;
    std::string textIn(const SferaSliceReference32 &slice, std::size_t limit, SferaMbcProcessRecord *process = nullptr) const;
    std::uint8_t *memoryAt(std::uint32_t address, std::size_t size, SferaMbcProcessRecord *process = nullptr) const;
    std::string textAt(std::uint32_t address) const;
    std::string textAt(std::uint32_t address, std::size_t limit) const;
    SferaTextBuffer textBuffer(const SferaSliceReference32 &slice, SferaMbcProcessRecord *process = nullptr) const;
    std::uint32_t mapMemory(const void *data, std::size_t size, const void *owner = nullptr);
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
    std::uint32_t unloadProcess(std::uint32_t index);
    std::uint32_t namedValue(std::string_view name, int index = 0);
    void setNamedValue(std::string_view name, std::uint32_t value, int index = 0);
    bool reportError(std::string_view message);
    bool reportError(std::string_view prefix, std::string_view suffix);
    void enqueueProcess(int index, SferaMbcProcessRecord &process);
    void dequeueProcess(SferaMbcProcessRecord &process);
    void readValue(SferaMbcValue &slot, SferaMbcValueType type, const SferaSliceReference32 &reference, bool load, bool readAddress = false);
    void storeValue(SferaMbcValue &left, const SferaMbcValue &right);
    void dereferenceValue(SferaMbcValue &slot);
    void advanceReference(SferaSliceReference32 &source, std::uint32_t displacement);
    SferaSliceReference32 indexedReference(std::uint16_t stride, std::int32_t index, std::int32_t signedCount, std::uint32_t address, std::uint32_t width,
                                          SferaSliceReference32 *source);
    void changeValue(SferaMbcValue &slot, bool increment, bool prefix);
    void changePointer(SferaMbcValue &slot, std::uint16_t stride, bool increment, bool prefix);
    static bool hasNativeEntry(const SferaMbcProcessRecord &process, SferaNativeEntry entry);
    SferaAotStepResult resumeNativeProgram(bool stopping);
    SferaMbcValue invokeNative(SferaMbcProcessRecord &process, int program, SferaNativeEntry entry,
                               std::span<const SferaMbcValue> arguments);
    SferaSliceReference32 ownReference(SferaSliceReference32 value) const;
    void drainDeferredUnloads();
    void scriptConfiguration();
    void scriptContainerCommand();
    void scriptContainerManagement();
    void scriptFail();
    void scriptExit();
    void scriptLoadProcess();
    void scriptUnloadProcess();
    void scriptLinkProcess();
    void scriptDiscardInteger();
    void scriptNoop();
    void scriptProcessName(bool current, bool module);
    void scriptFindModule();
    void scriptFindProcess();
    void scriptSimulationTick();
    void scriptProcessModule();
    void scriptActiveTag();
    void scriptArgumentCount();
    void scriptCurrentModule();
    void scriptCurrentProcess();
    void scriptZeroResult();
    void scriptProfileValue();
    void scriptProcessFlag();
    void scriptCallerProcess();
    void scriptDiscardArgument();
    void scriptStopInterpreter();
    void scriptInvalidResult();
    void scriptOpenFile(bool create);
    void scriptCloseFile();
    void scriptTransferFile(bool reading);
    void scriptReadLine();
    void scriptLockFile();
    void scriptSeekFile();
    void scriptFileSize();
    void scriptFileTime();
    void scriptResizeFile();
    void scriptSetFileTime();
    void scriptRemoveFile();
    void scriptRenameFile();
    void scriptSin();
    void scriptCos();
    void scriptExp();
    void scriptAbsoluteReal();
    void scriptSquareRoot();
    void scriptRealValue();
    void scriptArcTangent();
    void scriptIntegerValue(bool absolute);
    void scriptRandomReal();
    void scriptPackColor();
    void scriptScaleColor();
    void scriptBitAnd();
    void scriptBitOr();
    void scriptBitXor();
    void scriptBitNot();
    void scriptShiftLeft();
    void scriptShiftRight();
    void scriptClearBit();
    void scriptSetBit();
    void scriptTestBit();
    void scriptAllocateMemory();
    void scriptDynamicArray(bool allocate);
    void scriptNamedValue(bool writing);
    void scriptRebaseSlice();
    void scriptCopyProcess(bool rawMemory);
    void scriptMemoryChecksum();
    void scriptCompareMemory();
    void scriptCopyMemory(bool fill);
    void scriptWriteScalar(std::uint32_t width, bool real);
    void scriptReadScalar(std::uint32_t width, bool real);
    void scriptTransferString(bool writing);
    void scriptLowerBoundInteger();
    void scriptConnect();
    void scriptDisconnect();
    void scriptTickDifference();
    void scriptNetworkInitialization();
    void scriptPlayerLists();
    void scriptCopyString(bool bounded, bool append);
    void scriptFindString(bool sensitive);
    void scriptStringLength();
    void scriptCompareStrings(bool insensitive, bool requiredCount, bool normalize);
    void scriptMouseMotion();
    void scriptFontSettings();
    void scriptDestroyResource(SferaMbcRuntimeResourceKind kind);
    void scriptSetRenderEnabled();
    void scriptCreateObject();
    void scriptText();
    void scriptTextColor();
    void scriptSprite();
    void scriptEffect();
    void scriptSceneContext();
    void scriptKeyboardState();
    void scriptAnimationValue(bool animation);
    void scriptAnimationLength();
    void scriptSetInterpolation();
    void scriptObjectProcess();
    void scriptWorldPosition(bool absolute);
    void scriptCommandVelocity();
    void scriptObjectVelocity(bool vertical);
    void scriptAirborne();
    void scriptObjectVector(bool position, bool basis);
    void scriptEditorPick();
    void scriptMovementContact();
    void scriptObjectComponent(bool position, std::size_t axis);
    void scriptObjectTransform(bool absoluteRotation, bool forwardOnly, bool rotate);
    template <class T> T readMemory(std::uint32_t offset) const
    {
        if (native_call != nullptr)
            native_call->scratch.synchronize();
        if constexpr (std::is_same_v<T, SferaSliceReference32>)
        {
            if (const auto object = native_space->find(offset))
                return object->readReference(offset - object->address());
            std::array<std::uint32_t, 3> words{};
            std::memcpy(words.data(), memoryAt(offset, SferaSliceReference32::scriptWidth), SferaSliceReference32::scriptWidth);
            return ownReference({words[0], words[1], words[2]});
        }
        else
        {
            static_assert(std::is_trivially_copyable_v<T>);
            T result{};
            if constexpr (sizeof(T) <= 4)
            {
                if (const auto object = native_space->find(offset))
                {
                    const auto word = object->readWord(offset - object->address(), sizeof(T));
                    std::memcpy(&result, &word, sizeof(T));
                    return result;
                }
            }
            std::memcpy(&result, memoryAt(offset, sizeof(T)), sizeof(T));
            return result;
        }
    }
    template <class T> void writeMemory(std::uint32_t offset, const T &value)
    {
        if (native_call != nullptr)
            native_call->scratch.synchronize();
        if constexpr (std::is_same_v<T, SferaSliceReference32>)
        {
            if (const auto object = native_space->find(offset))
            {
                object->writeReference(offset - object->address(), ownReference(value));
                if (native_call != nullptr) native_call->scratch.synchronize();
                return;
            }
            const std::array<std::uint32_t, 3> words{value.base, value.begin, value.end};
            std::memcpy(memoryAt(offset, SferaSliceReference32::scriptWidth), words.data(), SferaSliceReference32::scriptWidth);
        }
        else
        {
            static_assert(std::is_trivially_copyable_v<T>);
            if constexpr (sizeof(T) <= 4)
            {
                if (const auto object = native_space->find(offset))
                {
                    std::uint32_t word = 0;
                    std::memcpy(&word, &value, sizeof(T));
                    object->writeWord(offset - object->address(), word, sizeof(T));
                    if (native_call != nullptr) native_call->scratch.synchronize();
                    return;
                }
            }
            std::memcpy(memoryAt(offset, sizeof(T)), &value, sizeof(T));
        }
    }
    void writeReal(std::uint32_t offset, double value)
    {
        writeMemory(offset, SferaNumeric::real32(value));
    }
    void reportInvalidInstruction();
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
    void callFunction(bool mainProcess);
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
    std::string diagnostic_context;
    std::string first_execution_error;
    std::int32_t process_index = -1;
    const SferaNativeModule *source_module = nullptr;
    std::string_view source_function;
    std::uint32_t native_checkpoint = UINT32_MAX;
    uint32_t active_tag;
    _finddata64i32_t script_find_data;
    static constexpr std::size_t text_capacity = 10000;
    std::string text_buffer;
    SferaMbcProcessRecord processes[65536];
    uint32_t process_search_cursor;
    int instruction_step_count;
    int program_index;
    SferaMbcRuntimeHaltState halt_state;

    ScriptProgramDiagnostic *active_program_record;
    SferaMbcProcessRecord *active_process;
    std::uint64_t next_process_lifetime = 1;
    std::unordered_map<std::uint32_t, std::shared_ptr<SferaNativeObject>> dynamic_blocks;
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
    auto playerListName(int offset);
    auto findPlayerList(PlayerLists &manager, int offset);
    auto copyPlayerListName(std::uint32_t address, std::string_view value);
    static std::uint32_t copyString(SferaTextBuffer destination, std::string_view source, int capacity);

  private:
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
    static bool negativeModuleIndex(std::uint16_t index);
    template <class Value> void scanTextStoreNumber(const Value &value, const SferaSliceReference32 &reference, std::size_t characters);
    template <class Value> void scanTextStoreText(const Value &value, const SferaSliceReference32 &reference, std::size_t characters);
    template <bool Text, std::size_t Index = 0, class... Values> void scanTextStoreVariant(const std::variant<Values...> &value, const SferaSliceReference32 &reference, std::size_t characters);

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
