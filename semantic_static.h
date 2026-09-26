#pragma once

#include "semantic_classes.h"
#include <windows.h>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <type_traits>

// Script VM, transport and application contracts.
struct SferaSliceReference32 {
    // Byte offsets in script memory; end is inclusive and begin == 0 means unbounded.
    std::uint32_t base;
    std::uint32_t begin;
    std::uint32_t end;
    bool contains(std::uint32_t length = 1, bool allowNull = false) const;
    void diagnoseRange(std::uint32_t length);
};

struct SferaMbcValue {
    enum Type : std::uint8_t { Byte = 0, BytePointer = 1, Integer = 16, IntegerPointer = 17, Real = 32, RealPointer = 33, Address = 48 };
    Type type;
    std::size_t width;
    SferaSliceReference32 source;
    SferaSliceReference32 value;
    bool isPointer() const;
    static std::size_t storageSize(Type valueType);
    std::size_t elementSize() const;
    std::int32_t integer() const;
    std::uint32_t word() const noexcept { return value.base; }
    float real() const;
    std::int32_t asInteger() const;
    std::uint32_t asWord() const;
    float asReal() const;
    void setReal(float number);
    void setReal(double number);
    void detach();
    SferaSliceReference32& asSlice();
    void storeAs(Type destinationType, std::span<std::uint8_t> destination) const;
    static std::int32_t truncate(double number);
    static std::int64_t truncateReal(double number);
};

// Runtime names are owned strings. MBC files still encode names with a 31-byte limit.
struct ScriptProgramDiagnostic {
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

struct SferaMbcExecutionContext {
    std::int32_t process_index = -1;
    int program_index = -1;
    std::uint32_t instruction_offset{};
    std::uint32_t process_id = UINT32_MAX;
    std::uint64_t process_lifetime{};
};

struct SferaMbcFunctionRecord {
    std::string name;
    std::uint32_t entry_offset;
    int program_index;
    bool allow_reentry;

};

struct SferaWorldSlotRecord {
    static constexpr std::size_t packetPayloadCapacity = 400;
    uint32_t object_handle;
    uint32_t state;
    uint32_t linked_handle;
    uint32_t primary_state;
    uint32_t reliable_bit_count;
    uint8_t reliable_payload[packetPayloadCapacity];
    uint32_t reliable_process;
    uint32_t unreliable_bit_count;
    uint8_t unreliable_payload[packetPayloadCapacity];
    uint32_t unreliable_process;
    int origin[3];
};

struct SferaMbcRegionRecord {
    static constexpr SferaMbcRegionRecord undefined() {
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

struct SferaMbcModuleRecord {
    std::string name;
};

struct SferaMbcModuleImage {
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

struct SferaMbcRegionPacket {
    std::vector<std::uint8_t> data;
    std::uint32_t timestamp{};
    std::array<int, 3> origin{};
};

class SferaMbcBitStream {
    static constexpr std::array<unsigned, 4> variableIntegerWidths{3, 7, 14, 31};
    static constexpr unsigned coordinateMagnitudeBits = 11;
    static constexpr std::uint32_t coordinateSignBit = 1u << coordinateMagnitudeBits;
    static constexpr std::uint32_t coordinateMagnitudeMask = coordinateSignBit - 1u;
    std::span<const std::uint8_t> data_;
    std::uint8_t* output_ = nullptr;
    std::size_t position_ = 0;
    bool valid_ = true;
public:
    explicit SferaMbcBitStream(std::span<const std::uint8_t> data, std::size_t position = 0) : data_(data), position_(position) {}
    explicit SferaMbcBitStream(std::span<std::uint8_t> data, std::size_t position = 0) : data_(data), output_(data.data()), position_(position) {}
    bool valid() const { return valid_; }
    std::size_t position() const { return position_; }
    std::size_t remaining() const { return position_ <= data_.size() * 8 ? data_.size() * 8 - position_ : 0; }
    std::uint32_t read(unsigned width);
    void write(std::uint32_t value, unsigned width);
    void append(std::span<const std::uint8_t> data, std::size_t bits);
    bool skipRegion(const SferaMbcRegionRecord& region);
    std::uint32_t readField(std::int8_t format, std::span<const int, 3> origin);
    bool writeField(std::int8_t format, std::uint32_t value, std::span<const int, 3> origin);
    static std::uint32_t encodeCoordinate(int origin, float coordinate);
    static float decodeCoordinate(int origin, std::uint32_t code);
};

using SferaMbcModuleIds = std::array<std::uint16_t, 8>;
struct SferaMbcBytecodeKey {
    SferaMbcModuleIds modules;
    std::uint32_t memory_size;
    bool operator<(const SferaMbcBytecodeKey& other) const noexcept { return modules == other.modules ? memory_size < other.memory_size : modules < other.modules; }
};

struct SferaMbcProcessRecord {
    enum Flags : std::uint32_t { unloadAfterExecution = 1u << 2, markedForUnload = 1u << 5 };
    enum class ResourceKind { worldObject, file, fileSearch, dynamicArray, textControl, spriteControl, gameWindow, interfaceWindow, container };
    struct CleanupEntry { std::uint32_t handle; ResourceKind kind; std::uint64_t resource_lifetime = 0; };
    void registerResource(std::uint32_t handle, ResourceKind kind);
    void unregisterResource(std::uint32_t handle, ResourceKind kind);
    void linkProgram(std::size_t index);
    bool activateProgram(std::size_t index);
    bool activateProgram(std::string_view name);
    void appendCommand(std::string_view command);
    std::uint32_t growMemory(std::size_t size);
    SferaMbcFunctionRecord* findFunction(std::string_view name);
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
    const std::uint8_t* codeData() const noexcept { return bytecode ? bytecode->data() : nullptr; }
    std::uint32_t codeSize() const noexcept { return bytecode ? SferaNumeric::lowWord(bytecode->size()) : 0; }
    int32_t chain_prev_index = -1;
    int32_t chain_next_index = -1;
    uint16_t program_map_a[4];
    uint16_t program_map_b[4];
    uint32_t field_084;
    uint32_t flags;
    std::vector<CleanupEntry> cleanup_entries;
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

};

struct SferaMbcRuntime {
    std::array<SferaMbcValue, 256> values{};
    std::array<SferaMbcModuleRecord, 4096> modules{};
    struct OutgoingField { std::uint32_t word; std::int8_t format; };
    std::array<OutgoingField, 4088> outgoing_fields{};
    uint32_t game_calendar{};
    WorldObject* current_object{};
    SferaWorldSlotRecord world_slots[401]{};
    std::size_t active_world_slot{};
    uint32_t simulation_tick{};
    float inverse_coordinate_scale{};
    SferaSliceReference32 slice_fallback{};
    SferaSliceReference32 sliceup_fallback{};
    std::int32_t dispatch_slot = -1;

    enum class HaltState { Running, Requested, Dispatched };
    using ResourceKind = SferaMbcProcessRecord::ResourceKind;
    enum class WindowOperation : std::uint32_t { Create = 0, Destroy = 1, DisplayWidth = 2, DisplayHeight = 3, TextHeight = 4, FontHeight = 5, LineOffset = 6, TakeInput = 7, HitTest = 8, Visible = 9, Bounds = 10, TextSize = 11, GlyphWidth = 12, Scrollable = 13, CursorPosition = 14, SystemCursorVisible = 15, SystemCursorKind = 16, CursorKind = 17, CursorImage = 18, CursorText = 19, Open = 20, Close = 21, PollEvent = 22, SetText = 23, ControlAt = 24, SendMessage = 25, GetText = 26, SystemEvent = 27, WindowUnderCursor = 28, ItemAt = 29, SavedPositionsSize = 30, ReadSavedPositions = 31, WriteSavedPositions = 32, Position = 33, Size = 34, Description = 35, Tooltip = 36, Options = 37, EscapeWindow = 38, LegacyCreateDialog = 39, LegacyDestroyDialog = 40, LegacyPollDialogEvent = 41, LegacySendDialogMessage = 42, LegacyDialogItem = 43, LegacySetDialogText = 44, LegacyGetDialogText = 45, Shutdown = 46, LegacyPumpMessages = 47, ActiveWindow = 55, LoadingProgress = 78, FinishLoading = 79 };
    enum class Builtin : std::uint8_t { Fail = 0, FailAlternate = 1, Exit = 2, LoadProcess = 16, UnloadProcess = 17, LinkProcess = 18, Connect = 30, Disconnect = 31, FormatText = 67, NamedFormattedLog = 91, System = 103, DiscardInteger = 120, Reserved122 = 122, BoundedFormatText = 123, FormattedLog = 126, Reserved130 = 130, Reserved133 = 133, CallFunction = 20, CallMainFunction = 21, Distance = 81, ScanText = 9, ScriptLog = 38, ParseText = 128, ChatUtility = 129, Window = 10, Send = 26, Receive = 33, Configuration = 117, CreateFile = 40, OpenFile = 41, CloseFile = 42, ReadFile = 44, WriteFile = 43, ReadLine = 124, LockFile = 116, SeekFile = 65, FileSize = 66, FileTime = 70, ResizeFile = 71, SetFileTime = 72, RemoveFile = 69, RenameFile = 68, SetAnimation = 87, SetFrame = 88, AnimationLength = 89, SetInterpolation = 90, MouseMotion = 98, ThisProcessName = 104, ProcessName = 107, ModuleName = 109, FindModule = 110, FontSettings = 118, DestroyObject = 60, DestroyText = 62, DestroySprite = 105, ObjectProcess = 84, SetRenderEnabled = 99, CreateObject = 47, SetPosition = 48, MoveWorld = 49, CommandVelocity = 92, VerticalVelocity = 93, AngularVelocity = 94, Airborne = 97, ObjectBasis = 100, ObjectPosition = 101, ObjectRotation = 102, EditorPick = 131, AllocateMemory = 15, AllocateDynamic = 113, FreeDynamic = 112, SetNamedValue = 114, NamedValue = 115, RebaseSlice = 121, CopyProcessMemory = 77, CopyProcessString = 108, Text = 61, TextColor = 63, Sprite = 73, Effect = 111, MovementContact = 83, FileChecksum = 74, MemoryChecksum = 163, CompareMemory = 147, PlayerLists = 132, FindProcess = 28, Sin = 3, Cos = 4, Exp = 125, ArcTangent = 7, AbsoluteInteger = 6, AbsoluteReal = 5, SimulationTick = 8, RandomReal = 106, PackColor = 11, ScaleColor = 134, SquareRoot = 12, SceneContext = 13, KeyboardState = 14, ProcessModule = 19, ActiveTag = 22, ArgumentCount = 23, CurrentModule = 24, CurrentProcess = 39, ZeroResult = 25, ZeroResultAlternate = 27, TickDifference = 80, ProfileValue = 29, ProcessFlag = 32, CopyString = 34, CopyStringCount = 136, AppendString = 35, FindString = 95, FindStringInsensitive = 135, StringLength = 36, CompareStrings = 37, CompareStringsInsensitive = 75, CompareStringsCount = 76, CompareStringsCountInsensitive = 137, DiscardArgument = 86, IntegerValue = 45, RealValue = 46, NextDefaultValue = 64, CallerProcess = 127, CopyMemory = 78, MoveMemory = 96, FillMemory = 79, StopInterpreter = 82, NetworkInitialization = 85, InvalidResult = 119, BitAnd = 138, BitOr = 139, BitXor = 140, BitNot = 141, ShiftLeft = 142, ShiftRight = 143, ClearBit = 144, SetBit = 145, TestBit = 146, WriteByte = 148, WriteShort = 149, WriteThreeBytes = 150, WriteWord = 151, WriteReal = 152, WriteString = 153, ReadByte = 154, ReadShort = 155, ReadThreeBytes = 156, ReadWord = 157, ReadReal = 158, ReadString = 159, LowerBoundInteger = 160, ContainerCommand = 161, ContainerManagement = 162, PositionX = 54, PositionY = 55, PositionZ = 56, RotationX = 57, RotationY = 58, RotationZ = 59, SetRotation = 52, MoveLocal = 50, MoveForward = 51, Rotate = 53 };
    enum class Instruction : std::uint8_t {
        Yield = '|', EndProgram = '#', InvokeBuiltin = 'f', ReturnFunction = 'r', BindParameters = 'O', DispatchCommand = 201, LoadVariable = 105, JumpIfFalse = 73, JumpIfFalseShort = 75, ArrayElement = 97, SliceElement = 98, PointerElement = 109, FieldValue = 100, FieldSlice = 104, CallLocal = 99,         Jump = 'G', JumpShort = 'J', ArgumentCount = ',', ResetStack = '0', LiteralWord = '9', LiteralShort = '(', LiteralByte = ')', StringLiteral = 'A', SliceVariable = 'e', SliceLiteral = 'l', StartProgram = 'R', CallProgram = 'U', StopProgram = 'S', PauseProgram = 'P', ResumeProgram = 'C', ReturnLocal = 't', Assign = '=', Dereference = '^', AddressOf = '&', Add = '+', Subtract = '-', Multiply = '*', Divide = '/', Remainder = '%', Equal = 240, NotEqual = 237, Greater = '>', Less = '<', GreaterEqual = 225, LessEqual = 236, ShortCircuitOr = 'L', ShortCircuitAnd = 'M', IntegerResult = 235, IntegerResultAlternate = 232, Negate = 241, LogicalNot = '!', PreIncrement = 239, PreDecrement = 243, PostIncrement = 246, PostDecrement = 247, Halt = 'H', IntegerToReal = '.', PreviousIntegerToReal = ':', Swap = '~', PointerAdd = '[', PointerSubtract = ']', RealToInteger = '`', PreviousRealToInteger = '"', PointerPreIncrement = 207, PointerPreDecrement = 211, PointerPostIncrement = 214, PointerPostDecrement = 215, IntegerPair = ';', EnterFrame = '1', LeaveFrame = '2', UnlinkedFunction = 'g'
    };
    // Script words remain 32-bit; mapped addresses never contain truncated native pointers.
    static constexpr std::uint32_t mappedAddressBegin = 1u << 31;
    struct MemoryRegion {
        const std::uint8_t* data;
        std::size_t size;
        SferaMbcProcessRecord* process;
        const void* owner;
        std::uint64_t lifetime = 0;
        const void* address() const noexcept { return data; }
    };
    using NativeResource = std::variant<SphereUI::Window*, SferaActiveEffect*, SferaScriptContainer*, std::intptr_t>;
    std::map<std::uint32_t, MemoryRegion> mapped_memory;
    std::unordered_map<std::uint32_t, NativeResource> native_resources;
    std::unordered_map<NativeResource, std::uint32_t> native_resource_ids;
    std::uint32_t next_native_handle = 1;
    std::uint64_t next_memory_lifetime = 1;
    std::span<std::uint8_t> memoryRange(std::uint32_t address, SferaMbcProcessRecord* process = nullptr) const;
    // Legacy pointer/count operations are bounded by their process or mapped region.
    std::span<std::uint8_t> memoryBytes(std::uint32_t address, std::size_t count, SferaMbcProcessRecord* process = nullptr) const;
    SferaText::Buffer textBufferAt(std::uint32_t address, SferaMbcProcessRecord* process = nullptr) const;
    std::uint64_t memoryLifetime(std::uint32_t address) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32& slice, SferaMbcProcessRecord* process = nullptr) const;
    std::span<std::uint8_t> sliceBytes(const SferaSliceReference32& slice, std::size_t count, SferaMbcProcessRecord* process = nullptr) const;
    // A VM address is an offset: zero can name the first byte of process memory.
    // Required-pointer APIs reject zero at their call sites, not in memory adapters.
    // MBC text arguments have C-string semantics; slice metadata may describe only an element.
    std::string textIn(const SferaSliceReference32& slice, SferaMbcProcessRecord* process = nullptr) const;
    std::string textIn(const SferaSliceReference32& slice, std::size_t limit, SferaMbcProcessRecord* process = nullptr) const;
    std::uint8_t* memoryAt(std::uint32_t address, std::size_t size, SferaMbcProcessRecord* process = nullptr) const;
    std::string textAt(std::uint32_t address) const;
    std::string textAt(std::uint32_t address, std::size_t limit) const;
    SferaText::Buffer textBuffer(const SferaSliceReference32& slice, SferaMbcProcessRecord* process = nullptr) const;
    std::uint32_t mapMemory(const void* data, std::size_t size, const void* owner = nullptr);
    std::uint32_t mapProcessMemory(SferaMbcProcessRecord& process);
    SferaSliceReference32 rebaseSlice(SferaSliceReference32 slice, SferaMbcProcessRecord& source);
    void forgetMemory(const void* owner);
    std::uint32_t addMemoryRegion(MemoryRegion region);
    template<class T> std::uint32_t nativeHandle(T value) {
        if constexpr (std::is_pointer_v<T>) { if (value == nullptr) return 0; }
        else if (value == -1) return UINT32_MAX;
        const NativeResource resource{value};
        if (const auto existing = native_resource_ids.find(resource); existing != native_resource_ids.end()) return existing->second;
        if (next_native_handle >= INT32_MAX) throw std::length_error("Script resource handles exhausted");
        const auto handle = next_native_handle++;
        native_resources.emplace(handle, resource);
        try { native_resource_ids.emplace(resource, handle); } catch (...) { native_resources.erase(handle); throw; }
        return handle;
    }
    template<class T> T nativeResource(std::uint32_t handle) const {
        if (const auto entry = native_resources.find(handle); entry != native_resources.end()) if (const auto* value = std::get_if<T>(&entry->second)) return *value;
        if constexpr (std::is_pointer_v<T>) return nullptr; else return -1;
    }
    void forgetNativeResource(const NativeResource& resource);

    std::int32_t popInteger();
    std::uint32_t popWord();
    SferaSliceReference32& popSlice();
    std::int32_t nextInteger();
    std::uint32_t nextWord();
    float nextReal();
    SferaSliceReference32& nextSliceReference(std::string_view diagnostic = "popsliceupref(): stack underflow");
    SferaSliceReference32 nextSlice();
    // Legacy address arguments use numeric conversion for scalar values, as nextInteger did.
    SferaSliceReference32 nextAddress();
    void pushInteger(std::uint32_t value);
    template<class Integer>
        requires (std::is_integral_v<Integer> && !std::is_same_v<std::remove_cv_t<Integer>, std::uint32_t>)
    void pushInteger(Integer value) {
        static_assert(sizeof(Integer) <= sizeof(std::uint32_t), "MBC integer result must fit the 32-bit VM word");
        if constexpr (std::is_signed_v<Integer>) {
            std::int32_t signed_value = value;
            pushInteger(SferaNumeric::word(signed_value));
        } else {
            std::uint32_t word = value;
            pushInteger(word);
        }
    }
    void pushReal(float value);
    void pushReal(double value);
    void pushSlice(const SferaSliceReference32& value, SferaMbcValue::Type type);
    void pushReference(SferaMbcValue::Type type, const SferaSliceReference32& reference, bool load);
    SferaMbcProcessRecord* findProcess(std::uint32_t id);
    std::uint32_t loadProcess(std::string_view name, std::uint32_t requestedIndex);
    std::uint32_t linkProcess(std::string_view name);
    std::uint32_t unloadProcess(std::uint32_t index);
    std::shared_ptr<const std::vector<std::uint8_t>> cacheBytecode(
        std::shared_ptr<const std::vector<std::uint8_t>> code, const SferaMbcModuleIds& modules, std::uint32_t memorySize);
    void resetBytecodeCache();
    std::shared_ptr<const std::vector<std::uint8_t>> findBytecode(const SferaMbcModuleIds& modules, std::uint32_t memorySize) const;
    std::uint32_t namedValue(std::string_view name, int index = 0);
    void setNamedValue(std::string_view name, std::uint32_t value, int index = 0);
    bool reportError(std::string_view message);
    bool reportError(std::string_view prefix, std::string_view suffix);
    void enqueueProcess(int index, SferaMbcProcessRecord& process);
    void dequeueProcess(SferaMbcProcessRecord& process);
    bool executeInstruction(Instruction instruction);
    bool executeBuiltin(Builtin builtin);
    template<class T> T readOperand() { T result; std::memcpy(&result, instruction_cursor, sizeof(result)); instruction_cursor += sizeof(result); return result; }
    template<class T> T readMemory(std::uint32_t offset) const { T result; std::memcpy(&result, memoryAt(offset, sizeof(result)), sizeof(result)); return result; }
    template<class T> void writeMemory(std::uint32_t offset, const T& value) { std::memcpy(memoryAt(offset, sizeof(value)), &value, sizeof(value)); }
    void writeReal(std::uint32_t offset, double value) { writeMemory(offset, SferaNumeric::real32(value)); }
    void reportInvalidInstruction();
    void exportSlice(SferaSliceReference32& destination, const void* data, std::size_t size, const void* owner);
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
    void copyText(const SferaSliceReference32& destination, std::string_view text);

    int32_t execution_chain_tail;
    int32_t execution_chain_head;
    std::size_t execution_chain_count;
    int32_t process_chain_first;
    int32_t process_chain_last;
    ScriptProgramDiagnostic* program_table_base;
    const std::uint8_t* instruction_cursor;
    std::string diagnostic_context;
    std::string first_execution_error;
    int argument_count;
    std::size_t argument_end;
    std::int32_t process_index = -1;
    const std::uint8_t* current_instruction_address;
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
    const std::uint8_t* bytecode_base;
    SferaMbcExecutionContext execution_context_stack[100];
    std::size_t argument_cursor;
    std::size_t frame_stack_base[22];
    HaltState halt_state;

    ScriptProgramDiagnostic* active_program_record;
    std::size_t value_stack_size;
    SferaMbcProcessRecord* active_process;
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
    std::uint8_t* process_memory_base;
    std::size_t send_field_count;
    bool execution_failed;
    Instruction current_opcode;

    std::unordered_map<std::string, std::vector<std::uint32_t>, SferaText::Hash, std::equal_to<>> named_vectors;
};

struct SferaDataContainerHeader {
    enum class Kind : std::uint32_t { List = 1, Vector, Set, Map, HashMap };
    enum class ValueType : std::uint32_t { Integer = 1, Real, Byte, String, Binary };
    Kind kind;
    bool iteration_active;

};

struct SferaScriptContainer {
    using Kind = SferaDataContainerHeader::Kind;
    using ValueType = SferaDataContainerHeader::ValueType;
    using Binary = std::vector<std::uint8_t>;
    enum class Command : int { Write = 0, Erase = 1, Read = 2, First = 3, Next = 4, IteratorState = 5, Clear = 9, Append = 10, Prepend = 11 };
    enum class Lifecycle : int { Create = 1, Destroy, Kind, ValueType, KeyType };
    template<class C, bool HashStorage = false> struct Content {
        using Value = typename C::value_type;
        static constexpr bool Hashed = HashStorage;
        static constexpr bool Mapped = Hashed || requires { typename C::mapped_type; };
        static constexpr bool Indexed = !Mapped && requires(C& values) { values[0]; };
        static constexpr bool Unique = requires { typename C::key_type; };
        C values;
        std::conditional_t<Indexed, std::size_t, typename C::iterator> cursor{};
        std::conditional_t<Hashed, std::vector<std::pair<typename C::iterator, typename C::iterator>>, std::monostate> buckets;
        Content();
        template<class K> std::size_t bucketIndex(const K& key) const requires Hashed;
        template<class K> typename C::iterator find(const K& key) requires Hashed;
        template<class K, class V> void assign(K&& key, V&& value) requires Hashed;
        void erase(typename C::iterator position) requires Hashed;
        void rehash(std::size_t count) requires Hashed;
    };
    SferaDataContainerHeader header;
    ValueType value_type;
    ValueType key_type;
    std::variant<Content<std::list<int>>, Content<std::list<float>>, Content<std::list<std::string>>, Content<std::list<Binary>>, Content<std::vector<int>>, Content<std::vector<float>>, Content<std::vector<std::uint8_t>>, Content<std::vector<std::string>>, Content<std::vector<Binary>>, Content<std::set<int>>, Content<std::set<std::string>>, Content<std::map<int, int>>, Content<std::map<int, float>>, Content<std::map<int, std::string>>, Content<std::map<int, Binary>>, Content<std::map<std::string, int>>, Content<std::map<std::string, float>>, Content<std::map<std::string, std::string>>, Content<std::map<std::string, Binary>>, Content<std::list<std::pair<const int, int>>, true>, Content<std::list<std::pair<const int, float>>, true>, Content<std::list<std::pair<const int, std::string>>, true>, Content<std::list<std::pair<const int, Binary>>, true>, Content<std::list<std::pair<const std::string, int>>, true>, Content<std::list<std::pair<const std::string, float>>, true>, Content<std::list<std::pair<const std::string, std::string>>, true>, Content<std::list<std::pair<const std::string, Binary>>, true>, Content<std::list<std::pair<const Binary, int>>, true>, Content<std::list<std::pair<const Binary, float>>, true>, Content<std::list<std::pair<const Binary, std::string>>, true>, Content<std::list<std::pair<const Binary, Binary>>, true>> content;
    template<class C, bool Hashed> SferaScriptContainer(Kind kind, ValueType type, std::in_place_type_t<Content<C, Hashed>>, ValueType keyType) : header{kind, false}, value_type(type), key_type(keyType), content(std::in_place_type<Content<C, Hashed>>) {}
    SferaScriptContainer(const SferaScriptContainer&) = delete;
    SferaScriptContainer& operator=(const SferaScriptContainer&) = delete;
    static std::unique_ptr<SferaScriptContainer> create(Kind kind, ValueType type, ValueType keyType = ValueType::Integer);
    void execute(SferaMbcRuntime& runtime);
};

struct SferaNetworkStatistics {
    std::uint32_t round_trip_latency_ms{};
    std::uint32_t sent_bytes_per_second{};
    std::uint32_t received_bytes_per_second{};
    std::uint32_t throughputBytesPerSecond() const noexcept {
        return sent_bytes_per_second + received_bytes_per_second;
    }
};

inline constexpr std::size_t kSferaNetworkMessageSlotCount = 3048u;
inline constexpr std::size_t kTcpReceiveBufferCapacity = 60000u;
struct SferaNetworkRuntime;

enum class TcpMessage : std::uint16_t {
    connection_limit = 100u,
    handshake = 200u,
    payload = 300u,
    client_mode = 400u,
    keepalive = 500u,
    sequence_reset = 600u,
    packet_counter = 700u
};

// All socket calls finish before Socket and WinsockSession are destroyed.
// The three workers retain their receive / dispatch / maintenance roles.
struct SferaTcpConnectionContext {
    explicit SferaTcpConnectionContext(SferaNetworkRuntime& owner) noexcept;
    ~SferaTcpConnectionContext();
    SferaTcpConnectionContext(const SferaTcpConnectionContext&) = delete;
    SferaTcpConnectionContext& operator=(const SferaTcpConnectionContext&) = delete;
    int initialize(const std::string& hostname, std::uint16_t port);
    void shutdown() noexcept;
    static constexpr std::uint32_t sendCapacity = 80000;
    bool queuePacket(std::uint32_t payloadSize, TcpMessage message, const void* payload) noexcept;
    void sendPending() noexcept;
    SferaNetworkStatistics statistics() const;
    bool isConnected() const noexcept { return connected_.load(); }
private:
    struct WinsockSession {
        bool active = false;
        bool start() noexcept;
        void reset() noexcept;
        ~WinsockSession() { reset(); }
    } winsock_;
    struct Socket {
        SOCKET value = INVALID_SOCKET;
        void reset(SOCKET replacement = INVALID_SOCKET) noexcept;
        ~Socket() { reset(); }
    } socket_;
    SferaNetworkRuntime& owner_;
    std::array<std::jthread, 3> workers_;
    std::atomic<bool> connected_{false};
    std::atomic<bool> handshake_complete_{false};
    // Recursion is intentional: maintenance encodes packets while holding
    // the same lock that serializes sequence/checksum and the send queue.
    std::recursive_mutex send_mutex_;
    // Serialized wire packets use native string storage only as a length-delimited byte buffer.
    // Embedded NUL bytes are data; no text conversion is performed by the transport.
    std::deque<std::string> outgoing_;
    std::size_t outgoing_offset_ = 0;
    std::size_t outgoing_bytes_ = 0;
    std::uint16_t sequence_ = 0;
    std::uint16_t checksum_seed_ = 0;
    std::uint32_t packet_counter_ = 0;
    std::mutex receive_mutex_;
    std::condition_variable_any receive_ready_;
    std::deque<std::vector<std::uint8_t>> incoming_;
    std::size_t incoming_bytes_ = 0;
    mutable std::mutex statistics_mutex_;
    SferaNetworkStatistics statistics_{};
    std::uint32_t received_bytes_window_ = 0;
    std::uint32_t sent_bytes_window_ = 0;
    std::uint32_t keepalive_started_at_ = 0;
    bool keepalive_answered_ = false;
    void fail() noexcept;
    void receive(std::stop_token stop) noexcept;
    void dispatch(std::stop_token stop) noexcept;
    void maintain(std::stop_token stop) noexcept;
    bool acceptPacket(std::string_view packet, std::stop_token stop);
};

struct SferaTcpIncomingHeader {
    static constexpr std::uint32_t encodedSize = 4;
    std::uint16_t size;
    std::uint16_t message;
    static SferaTcpIncomingHeader decode(std::span<const std::byte> bytes) {
        const auto header = SferaBinary::range(bytes, 0, encodedSize);
        return {SferaBinary::readLittleEndian<std::uint16_t>(header.data()),
            SferaBinary::readLittleEndian<std::uint16_t>(header.data() + 2)};
    }
};

struct SferaTcpHandshakePacket {
    static constexpr std::uint32_t encodedSize = SferaTcpIncomingHeader::encodedSize + 6;
    std::uint32_t remote_id;
    std::uint16_t checksum_seed;
    static SferaTcpHandshakePacket decode(std::span<const std::byte> bytes) {
        const auto payload = SferaBinary::range(bytes, SferaTcpIncomingHeader::encodedSize, 6);
        return {SferaBinary::readLittleEndian<std::uint32_t>(payload.data()),
            SferaBinary::readLittleEndian<std::uint16_t>(payload.data() + 4)};
    }
};

struct SferaTcpOutgoingHeader {
    static constexpr std::uint32_t encodedSize = 8;
    static constexpr std::uint32_t checksumOffset = 2;
    static constexpr std::uint32_t checksumPayloadOffset = 4;
    std::uint16_t size;
    std::uint16_t checksum;
    std::uint16_t sequence;
    std::uint16_t message;
    void encode(std::span<std::byte> bytes) const {
        const auto header = SferaBinary::range(bytes, 0, encodedSize);
        SferaBinary::writeLittleEndian(header.data(), size);
        SferaBinary::writeLittleEndian(header.data() + checksumOffset, checksum);
        SferaBinary::writeLittleEndian(header.data() + checksumPayloadOffset, sequence);
        SferaBinary::writeLittleEndian(header.data() + 6, message);
    }
};

struct SferaNetworkRuntime {
    int statistics_poll_ticks{};

    std::atomic<std::uint32_t> initialization_result{UINT32_MAX};
    std::uint16_t server_port = 25858u;
    std::uint32_t connection_slot = UINT32_MAX;

    std::uint32_t client_mode = 0; // immutable while workers run
    std::atomic<bool> connection_lost{false};
    std::atomic<std::uint64_t> sent_bytes{0}, received_bytes{0};
    SferaNetworkStatistics connection_info{}; // published on the main thread
    std::mutex receive_mutex;
    std::deque<std::vector<std::uint8_t>> messages;
    std::uint64_t dropped_messages = 0; // protected by receive_mutex
    std::unique_ptr<SferaTcpConnectionContext> connection;
    ~SferaNetworkRuntime();
    int initialize(const std::string& hostname, std::uint32_t mode);
    void shutdown();
    void enqueueMessage(std::span<const std::uint8_t> payload) noexcept;
    void receiveMessages();
    void receiveMessage(std::span<const std::uint8_t> message);
    void receiveEvents(std::span<const std::uint8_t> payload);
    bool sendPacket(std::uint32_t flags, std::span<const std::uint8_t> payload);
    static int tickDifference(std::uint32_t current, std::uint32_t previous);
    static void encodePayload(std::uint8_t* data, std::size_t length);
    void updateTcpStatistics();
};

class SferaGameCalendar {
    struct Field { unsigned shift; unsigned width; std::uint32_t bias; constexpr std::uint32_t mask() const { return (1u << width) - 1u; } };
    static constexpr std::array<Field, 6> fields{{{0, 2, 0}, {2, 6, 0}, {8, 5, 0}, {13, 5, 0}, {18, 4, 0}, {22, 10, 7800}}};
    static constexpr const Field& field(int index) { return fields[index >= 1 && index <= 5 ? index - 1 : 5]; }
public:
    enum Component : int { Quarter = 1, Minute, Hour, Day, Month, Year };
    static constexpr std::uint32_t firstYear = 7800;
    static constexpr std::uint32_t quartersPerMinute = 4, minutesPerHour = 60, hoursPerDay = 24, daysPerYear = 365;
    static constexpr std::uint32_t quartersPerHour = quartersPerMinute * minutesPerHour, quartersPerDay = quartersPerHour * hoursPerDay, quartersPerYear = quartersPerDay * daysPerYear;
    static constexpr std::array<std::uint32_t, 13> monthStarts{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    static constexpr std::uint32_t daysInMonth(std::uint32_t month) { return month >= 1 && month <= 12 ? monthStarts[month] - monthStarts[month - 1] : 0; }
    static constexpr std::uint32_t daysBeforeMonth(std::uint32_t month) { return month >= 1 && month <= 13 ? monthStarts[month - 1] : 0; }
    static constexpr std::uint32_t pack(std::uint32_t year, std::uint32_t month, std::uint32_t day, std::uint32_t hour, std::uint32_t minute, std::uint32_t quarter = 0) { return ((year - firstYear) << field(Year).shift) | (month << field(Month).shift) | ((day & field(Day).mask()) << field(Day).shift) | (hour << field(Hour).shift) | (minute << field(Minute).shift) | quarter; }
    static std::uint32_t fromUnixTime(std::int64_t timestamp);
    static std::uint32_t advance(std::uint32_t calendar);
    static std::uint32_t component(std::uint32_t calendar, int index);
    static std::uint32_t withComponent(std::uint32_t calendar, int index, std::uint32_t value);
    static std::uint32_t ticks(std::uint32_t calendar);
};

class SferaClientApplication {
public:
    static int frame_samples;
    static std::uint64_t frame_anchor;
    static uint32_t frame_elapsed_ticks;
    static bool main_loop_started;
    static HINSTANCE instance_handle;
    static bool interpreter_initialized;
    static uint32_t language;
    static bool resources_loaded;
    static bool windowed;
    static HWND main_window;
    static float measured_fps;
    static bool interrupted;
    static bool quit_requested;
    static bool startup_complete;
    static std::string locale;
    static uint32_t desktop_width;
    static bool application_active;
    enum class Lifecycle { Dormant, Running, Stopping, Stopped };
    static Lifecycle lifecycle;
    static bool com_initialized;
    static bool window_class_registered;
    struct ExitRequested {};
    SferaClientApplication() = default;
    SferaClientApplication(const SferaClientApplication&) = delete;
    SferaClientApplication& operator=(const SferaClientApplication&) = delete;
    ~SferaClientApplication() noexcept;
    static bool fatal_error_in_progress;
    static int server_number;
    static uint32_t desktop_height;
    static bool storage_initialized;

    static int run(HINSTANCE instance);
    static void initializeStorage();
    static void releaseStorage() noexcept;
    static std::string_view commandLineArguments(std::string_view commandLine);
    static void loadResources();
    static void shutdown() noexcept;
    [[noreturn]] static void terminateWithError(std::string_view message);
    [[noreturn]] static void arrayBoundsError(int index);
private:
    static void configureResourceDirectory();
    static void resetWorld();
    static void renderFrame();
    bool initialize();
    bool runStartupScripts();
    void runMainLoop();
    void updateSimulation();
    int advanceClock();
    std::uint32_t previous_tick_ = 0;
    int tick_remainder_ = 0;
    std::uint32_t object_update_ticks_ = 0;
    std::uint32_t effect_update_ticks_ = 0;
    std::uint32_t maintenance_ticks_ = 0;
};

namespace SphereUI { struct SavedWindowPosition; struct LocalizedTextEntry; struct DisplayMode; }
struct IDirect3D9;
struct IDirect3DDevice9;
namespace SphereUI { struct UiSprite; }

std::string_view sfera_cursor_texture_name(uint32_t slot);

struct WorldObject;

struct SferaLightRecord {
    SferaVec3F position;
    float color[4];
    float radius;
    SferaVec3F bounds_min;
    SferaVec3F bounds_max;
    float viewer_distance_squared;

    void update(const SferaVec3F& new_position, const float* new_color, float new_radius);
};

struct SferaLightRuntime {
    SferaLightRecord render_candidates[30]{};

    std::vector<std::unique_ptr<SferaLightRecord>> handles;
    std::vector<SferaLightRecord*> visible_handles;
    std::array<bool, 31> active_lights{};
    std::array<std::uint32_t, 30> render_candidate_indices{};
    std::array<bool, 30> render_candidate_active{};
    std::size_t active_count = 0;
    std::size_t candidate_count = 0;

    SferaLightRecord* record(int handle) const;
    void setActive(std::uint32_t index, bool enabled, std::uint32_t sourceLine);
    void activateMask(std::uint32_t mask);
    void setDirectionalLight(const SferaVec3F& direction, const SferaVec3F& color);
    void invalidateActiveLights();
    void disableActiveLights();
    int create(const SferaVec3F& position, const float* color, float radius);
    void write(int handle, const SferaVec3F& position, const float* color, float radius);
    void release(int handle);
};

struct SferaNatureManager {
    NatureRainListener rain_listener;
    LightingListener lighting_listener;
    CRainEffect* rain_effect = nullptr;
    float rain_intensity = 0.5f;
    float rain_scale = 0.0f;
    CScriptedEffect* lighting_effect = nullptr;
    float lighting_level = 0.5f;
    SferaActiveEffect* rain_effect_handle = nullptr;
    SferaActiveEffect* lighting_effect_handle = nullptr;
    std::array<SferaActiveEffect*, 3> ambient_rain_handles{};

    static void updateRain();
    static void updateLightning();
    bool initialize();
    void shutdown();
    void forgetEffect(const SferaActiveEffect& item);
    bool attachRainEffect(IEffect& effect);
    void detachRainEffect();
    bool attachLightingEffect(IEffect& effect);
    void detachLightingEffect();
    void onLightingEffectChanged(IEffect& effect, SferaActiveEffect& item);
    void startRain();
    void stopRain();
    void startLighting();
    void stopLighting();
    void setRainIntensity(float value);
    void setLightingLevel(float value);
    void updateAmbientRainEffects();
};

SferaNatureManager* sfera_nature_manager();

struct SferaEffectManager {
    enum class CreateFailure : std::size_t {
        Stopping, Capacity, SoundUnavailable, MissingDefinition, Factory,
        FilteredType, InvalidSource, Listener, Allocation, Count
    };
    struct Diagnostics {
        bool enabled{};
        std::uint32_t details_written{};
        std::uint64_t last_sample{}, samples{}, vm_requests{}, create_requests{}, created{};
        std::uint64_t updates{}, distance_culled{}, frustum_culled{}, activation_rejected{};
        std::uint64_t daytime_rejected{}, budget_rejected{}, expired{};
        std::uint64_t render_calls{}, submitted_quads{}, alpha_vertices{}, light_activations{};
        std::array<std::uint64_t, SferaNumeric::enumBits(CreateFailure::Count)> failures{};
    } diagnostics;

    void traceFailure(CreateFailure failure, std::uint32_t effect, std::uint32_t source,
        std::optional<std::string_view> name = std::nullopt) noexcept;
    void traceFailure(CreateFailure, std::uint32_t, std::uint32_t, std::nullptr_t) noexcept = delete;
    void traceEffect(std::string_view event, const SferaActiveEffect& item) noexcept;
    void writeDiagnostics() noexcept;
    bool rain_enabled{};
    bool lightning_enabled{};
    SferaActiveEffect* pending_effect{};

    uint32_t render_cycle{};
    bool effects_enabled{};
    std::size_t render_slot_count{};
    std::array<std::uint16_t, 65536> particle_random_table{};
    std::vector<std::shared_ptr<const SferaEffectMeshResource>> mesh_resources;
    std::vector<std::shared_ptr<IEffect>> definitions;
    bool initialized{};
    std::vector<std::size_t> render_order;
    std::list<std::shared_ptr<SferaActiveEffect>> active_effects;
    std::unique_ptr<SferaNatureManager> nature;
    std::unique_ptr<SferaBloodEffectRuntime> blood;
    bool shutting_down = false;
    bool updating = false;
    uint32_t generation{};
    uint32_t last_processed_generation{};
    enum class FlareTransition { Idle, FadeOut, FadeIn };
    FlareTransition flare_transition{};
    bool flare_enabled{};
    int flare_alpha{};
    SferaVec3F viewer_position{};
    std::vector<SferaEffectRenderSlot> render_slots;
    std::vector<SferaEffectListenerEntry> effect_listeners;

    void reportError(std::string_view message) const;
    SferaEffectRenderSlot* acquireRenderSlot();
    void finalizeBillboard(SferaEffectRenderSlot& slot, const SferaVec3F& position, float size) const;
    float viewerDistance(const SferaVec3F& position) const;
    float viewerDistance(std::uint32_t source_handle) const;
    void appendDefinition(std::shared_ptr<IEffect> effect);
    std::shared_ptr<IEffect> findDefinition(uint32_t effect_id) const;
    std::shared_ptr<IEffect> findDefinition(std::string_view script_name) const;
    std::uint32_t findDefinitionId(std::string_view script_name) const;
    IEffectListener* findListener(uint32_t effect_id) const;
    bool registerListener(std::uint32_t effect_id, IEffectListener& listener);
    void unregisterListener(IEffectListener& listener);
    void clearListeners();
    void registerEffectMeshFile(const std::string& filename);
    void reportLoadProgress(std::uint32_t progress);
    void initializeBloodEffect();
    void shutdownBloodEffect();
    void loadDefinitions();
    void destroyDefinitions();
    void sortRenderSlots();
    void renderParticles();
    void drawFlare(int x, int y, int size, bool enabled);
    std::uint32_t listenerKey(const SferaActiveEffect* handle) const;
    bool removeActiveEffect(SferaActiveEffect* handle);
    bool initialize();
    void shutdown();
    SferaActiveEffect* createActiveEffect(std::uint32_t effect_id, std::uint32_t source_handle);
    SferaActiveEffect* createActiveEffect(std::string_view script_name, std::uint32_t source_handle);
    bool removeActiveEffect(SferaActiveEffect& item);
    bool setEffectParameters(std::uint32_t source_handle, std::span<const SferaEffectParameter> parameters);
    void retireEffect(SferaActiveEffect& item);
    void updateActiveEffects();
    void updateActiveEffect(SferaActiveEffect& item, std::uint16_t state_flags, float viewer_distance);
};

extern SferaServerWall g_sfera_server_wall;
extern SferaNetworkRuntime g_sfera_network_runtime;

extern SferaGraphicsRuntime g_sfera_graphics_runtime;
extern SferaConfigTextRuntime g_sfera_config_text_runtime;

extern WorldObjects g_sfera_world_objects;
extern SferaLightRuntime g_sfera_light_runtime;
extern SferaWeatherRuntime g_sfera_weather_runtime;
extern SferaErrorLogRuntime g_sfera_error_log_runtime;
extern SferaLogRuntime g_sfera_log_runtime;

extern SferaEffectManager g_sfera_effect_manager;
extern SferaMbcRuntime g_sfera_mbc_runtime;

// UI owners must be destroyed while the VM registration tables are still alive.
extern SphereUI::InterfaceManager g_sfera_interface;
