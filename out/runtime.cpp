#include "runtime.h"
#include "diagnostics.h"
#include "lifted_functions.h"

#include <intrin.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cwchar>
#include <cstring>
#include <limits>
#include <memory>
#include <stdexcept>

#if defined(_MSC_VER)
#pragma intrinsic(__readfsdword)
#endif


namespace lifted {

NativeRuntime* g_runtime = nullptr;
ProcessMemory* g_process_memory = nullptr;

namespace {

constexpr std::size_t kCallbackStackCopy = 16u * 1024u;
constexpr std::uint32_t kCallbackThunkSize = 10u;
constexpr std::uint32_t kCallbackThunkCapacityBytes = 0x00010000u;
constexpr std::uint32_t kCallbackThunkPageSize = 0x00001000u;
constexpr std::uint32_t kCodeTokenBase = 0xE0000000u;
constexpr wchar_t kClientRootEnvironment[] = L"SFERA_CLIENT_ROOT";
thread_local std::vector<std::unique_ptr<LocalStack>> g_callback_stacks;
thread_local std::size_t g_callback_stack_depth = 0;
thread_local std::uint32_t g_last_native_callsite = 0u;
thread_local std::uint32_t g_last_native_target = 0u;
thread_local std::uint32_t g_last_native_esp_before = 0u;
thread_local std::uint32_t g_last_native_esp_after = 0u;
class CallbackStackLease {
public:
    CallbackStackLease() { if (g_callback_stack_depth == g_callback_stacks.size()) { g_callback_stacks.push_back(std::make_unique<LocalStack>(kStackReserve)); } stack_ = g_callback_stacks[g_callback_stack_depth++].get(); }
    CallbackStackLease(const CallbackStackLease&) = delete;
    CallbackStackLease& operator=(const CallbackStackLease&) = delete;
    ~CallbackStackLease() { --g_callback_stack_depth; }
    LocalStack& stack() const noexcept { return *stack_; }
private:
    LocalStack* stack_ = nullptr;
};

std::wstring path_join(const std::wstring& directory, const std::wstring& child) {
    if (directory.empty()) { return child; }
    const wchar_t tail = directory.back();
    return directory + (tail == L'\\' || tail == L'/' ? L"" : L"\\") + child;
}

std::wstring parent_directory(const std::wstring& path) {
    const std::size_t end = path.find_last_not_of(L"\\/");
    if (end == std::wstring::npos) { return {}; }
    const std::size_t separator = path.find_last_of(L"\\/", end);
    if (separator == std::wstring::npos) { return {}; }
    if (separator == 2u && path.size() >= 3u && path[1] == L':') { return path.substr(0, 3u); }
    return path.substr(0, separator);
}

std::wstring full_path(const std::wstring& path) {
    const DWORD required = GetFullPathNameW(path.c_str(), 0, nullptr, nullptr);
    if (required == 0) { throw std::runtime_error(win32_error("GetFullPathNameW")); }
    std::vector<wchar_t> buffer(required);
    const DWORD length = GetFullPathNameW(path.c_str(), required, buffer.data(), nullptr);
    if (length == 0 || length >= required) { throw std::runtime_error(win32_error("GetFullPathNameW")); }
    return std::wstring(buffer.data(), length);
}

std::wstring current_directory() {
    const DWORD required = GetCurrentDirectoryW(0, nullptr);
    if (required == 0) { throw std::runtime_error(win32_error("GetCurrentDirectoryW")); }
    std::vector<wchar_t> buffer(required);
    const DWORD length = GetCurrentDirectoryW(required, buffer.data());
    if (length == 0 || length >= required) { throw std::runtime_error(win32_error("GetCurrentDirectoryW")); }
    return std::wstring(buffer.data(), length);
}

std::wstring host_executable_path() {
    std::vector<wchar_t> buffer(512u);
    for (;;) {
        SetLastError(ERROR_SUCCESS);
        const DWORD length = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
        if (length == 0) { throw std::runtime_error(win32_error("GetModuleFileNameW")); }
        if (length + 1u < buffer.size()) { return std::wstring(buffer.data(), length); }
        if (buffer.size() >= 32768u) { throw std::runtime_error("Host executable path is too long"); }
        buffer.resize(std::min<std::size_t>(buffer.size() * 2u, 32768u));
    }
}

std::wstring environment_path(const wchar_t* name) {
    const DWORD required = GetEnvironmentVariableW(name, nullptr, 0);
    if (required == 0) { return {}; }
    std::vector<wchar_t> buffer(required);
    const DWORD length = GetEnvironmentVariableW(name, buffer.data(), required);
    if (length == 0 || length >= required) { throw std::runtime_error(win32_error("GetEnvironmentVariableW")); }
    return full_path(std::wstring(buffer.data(), length));
}

bool regular_file_exists(const std::wstring& path) noexcept {
    const DWORD attributes = GetFileAttributesW(path.c_str());
    return attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

bool is_client_root(const std::wstring& path) noexcept {
    return regular_file_exists(path_join(path, L"mbc\\_main.mbc"));
}

bool same_path(const std::wstring& left, const std::wstring& right) noexcept {
    return _wcsicmp(left.c_str(), right.c_str()) == 0;
}

void add_candidate_with_parents(std::vector<std::wstring>& candidates, std::wstring path) {
    for (unsigned depth = 0; depth != 12u && !path.empty(); ++depth) {
        path = full_path(path);
        if (std::none_of(candidates.begin(), candidates.end(), [&path](const std::wstring& item) { return same_path(item, path); })) { candidates.push_back(path); }
        const std::wstring parent = parent_directory(path);
        if (parent.empty() || same_path(parent, path)) { break; }
        path = parent;
    }
}

std::string narrow_path(const std::wstring& value) {
    if (value.empty()) { return {}; }
    const int required = WideCharToMultiByte(CP_UTF8, 0, value.data(), static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    if (required <= 0) { return "<unprintable>"; }
    std::string result(static_cast<std::size_t>(required), '\0');
    if (WideCharToMultiByte(CP_UTF8, 0, value.data(), static_cast<int>(value.size()), result.data(), required, nullptr, nullptr) != required) { return "<unprintable>"; }
    return result;
}

bool native_executable_image_address(std::uint32_t address) noexcept {
#if defined(SFERA_PORTABLE_CHECK)
    (void)address;
    return false;
#else
    MEMORY_BASIC_INFORMATION info{};
    if (VirtualQuery(reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), &info, sizeof(info)) != sizeof(info)) { return false; }
    if (info.State != MEM_COMMIT || info.Type != MEM_IMAGE) { return false; }
    const DWORD protection = info.Protect & UINT32_C(0xFF);
    return protection == PAGE_EXECUTE || protection == PAGE_EXECUTE_READ || protection == PAGE_EXECUTE_READWRITE || protection == PAGE_EXECUTE_WRITECOPY;
#endif
}

bool safe_copy(void* destination, const void* source, std::size_t size) noexcept {
#if defined(SFERA_PORTABLE_CHECK)
    std::memcpy(destination, source, size);
    return true;
#else
    set_diagnostic_memory_probe(true);
    __try {
        std::memcpy(destination, source, size);
        set_diagnostic_memory_probe(false);
        return true;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        set_diagnostic_memory_probe(false);
        return false;
    }
#endif
}

template <class T>
bool try_memory_read(std::uint32_t address, T& value) noexcept {
    return g_process_memory && g_process_memory->try_read(address, &value, sizeof(T));
}

template <class T>
T memory_read(std::uint32_t address) {
    T value{};
    if (!g_process_memory) { throw std::runtime_error("Process memory is not initialized"); }
    g_process_memory->read(address, &value, sizeof(T));
    return value;
}

template <class T>
void memory_write(std::uint32_t address, T value) {
    if (!g_process_memory) { throw std::runtime_error("Process memory is not initialized"); }
    g_process_memory->write(address, &value, sizeof(T));
}


std::uint32_t process_module_handle() {
    const HMODULE module = GetModuleHandleW(nullptr);
    if (!module) { throw std::runtime_error(win32_error("GetModuleHandleW(host)")); }
    const std::uintptr_t value = reinterpret_cast<std::uintptr_t>(module);
    if (value > std::numeric_limits<std::uint32_t>::max()) { throw std::runtime_error("Host process module handle exceeds Win32 range"); }
    return static_cast<std::uint32_t>(value);
}

std::string local_c_string(std::uint32_t address, std::size_t limit = 2048u) noexcept {
    if (address == 0) { return "<null>"; }
    std::string result;
    result.reserve(std::min<std::size_t>(limit, 256u));
    for (std::size_t index = 0; index != limit; ++index) {
        char value = 0;
        if (!try_memory_read(address + static_cast<std::uint32_t>(index), value)) { return result + "<fault>"; }
        if (value == '\0') { return result; }
        if (value == '\r') { result += "\\r"; }
        else if (value == '\n') { result += "\\n"; }
        else if (value == '\t') { result += "\\t"; }
        else if (static_cast<unsigned char>(value) < 0x20u) { result += '?'; }
        else { result += value; }
    }
    return result + "<truncated>";
}

std::uint32_t align_up(std::uint32_t value, std::uint32_t alignment) noexcept {
    return (value + alignment - 1u) & ~(alignment - 1u);
}

std::uint64_t width_mask(std::uint16_t width) noexcept {
    return width >= 64 ? std::numeric_limits<std::uint64_t>::max() : ((std::uint64_t{1} << width) - 1u);
}

std::uint64_t sign_bit(std::uint16_t width) noexcept {
    return std::uint64_t{1} << (width - 1u);
}

std::int64_t signed_value(std::uint64_t value, std::uint16_t width) noexcept {
    const std::uint64_t mask = width_mask(width);
    value &= mask;
    if (width < 64 && (value & sign_bit(width)) != 0) { value |= ~mask; }
    return static_cast<std::int64_t>(value);
}

bool even_parity(std::uint8_t value) noexcept {
    value ^= static_cast<std::uint8_t>(value >> 4u);
    value &= 0x0Fu;
    return ((0x6996u >> value) & 1u) == 0u;
}

void assign_flag(LiftCpu& state, std::uint32_t flag, bool value) noexcept {
    state.eflags = value ? state.eflags | flag : state.eflags & ~flag;
}

bool flag(const LiftCpu& state, std::uint32_t value) noexcept {
    return (state.eflags & value) != 0;
}

void set_szp(LiftCpu& state, std::uint64_t result, std::uint16_t width) noexcept {
    result &= width_mask(width);
    assign_flag(state, LIFT_FLAG_SF, (result & sign_bit(width)) != 0);
    assign_flag(state, LIFT_FLAG_ZF, result == 0);
    assign_flag(state, LIFT_FLAG_PF, even_parity(static_cast<std::uint8_t>(result)));
}

void set_sub_flags(LiftCpu& state, std::uint64_t left, std::uint64_t right, std::uint64_t borrow, std::uint64_t result, std::uint16_t width) noexcept {
    const std::uint64_t mask = width_mask(width);
    const std::uint64_t left_value = left & mask;
    const std::uint64_t right_value = right & mask;
    const std::uint64_t truncated = result & mask;
    assign_flag(state, LIFT_FLAG_CF, left_value < right_value || (borrow != 0 && left_value == right_value));
    assign_flag(state, LIFT_FLAG_OF, (((left_value ^ right_value) & (left_value ^ truncated)) & sign_bit(width)) != 0);
    assign_flag(state, LIFT_FLAG_AF, ((left_value ^ right_value ^ truncated) & 0x10u) != 0);
    set_szp(state, truncated, width);
}


} // namespace

extern "C" std::uint32_t __cdecl lift_source_rva(std::uint32_t address) { std::uint32_t rva = 0; return g_process_memory && g_process_memory->source_rva(address, rva) ? rva : UINT32_MAX; }
extern "C" std::uint32_t __cdecl lift_code_rva(std::uint32_t address) { std::uint32_t rva = 0; return g_process_memory && g_process_memory->code_rva(address, rva) ? rva : UINT32_MAX; }
extern "C" std::uint32_t __cdecl lift_is_native_code_address(std::uint32_t address) { return native_executable_image_address(address) ? 1u : 0u; }
extern "C" std::uint32_t __cdecl lift_callback_address(LiftFunction function) { return g_process_memory ? g_process_memory->callback_for_function(function) : 0u; }
extern "C" LiftFunction __cdecl lift_callback_function(std::uint32_t address) { return g_process_memory ? g_process_memory->callback_function(address) : (LiftFunction)0; }
extern "C" std::uint32_t __cdecl lift_process_module_handle(void) { return process_module_handle(); }
extern "C" std::uint8_t __cdecl lift_load8(std::uint32_t address) { return memory_read<std::uint8_t>(address); }
extern "C" std::uint16_t __cdecl lift_load16(std::uint32_t address) { return memory_read<std::uint16_t>(address); }
extern "C" std::uint32_t __cdecl lift_load32(std::uint32_t address) { return memory_read<std::uint32_t>(address); }
extern "C" std::uint64_t __cdecl lift_load64(std::uint32_t address) { return memory_read<std::uint64_t>(address); }
extern "C" float __cdecl lift_load_f32(std::uint32_t address) { return memory_read<float>(address); }
extern "C" double __cdecl lift_load_f64(std::uint32_t address) { return memory_read<double>(address); }
extern "C" void __cdecl lift_store8(std::uint32_t address, std::uint8_t value) { memory_write(address, value); }
extern "C" void __cdecl lift_store16(std::uint32_t address, std::uint16_t value) { memory_write(address, value); }
extern "C" void __cdecl lift_store32(std::uint32_t address, std::uint32_t value) { memory_write(address, value); }
extern "C" void __cdecl lift_store64(std::uint32_t address, std::uint64_t value) { memory_write(address, value); }
extern "C" void __cdecl lift_store_f32(std::uint32_t address, float value) { memory_write(address, value); }
extern "C" void __cdecl lift_store_f64(std::uint32_t address, double value) { memory_write(address, value); }

template <class T>
T fs_load(const LiftCpu* cpu, std::uint32_t offset) {
    if (!cpu || static_cast<std::uint64_t>(offset) + sizeof(T) > sizeof(cpu->fs_data)) { throw std::runtime_error("FS access outside the virtual TEB"); }
    T value{};
    std::memcpy(&value, cpu->fs_data + offset, sizeof(value));
    return value;
}

template <class T>
void fs_store(LiftCpu* cpu, std::uint32_t offset, T value) {
    if (!cpu || static_cast<std::uint64_t>(offset) + sizeof(T) > sizeof(cpu->fs_data)) { throw std::runtime_error("FS access outside the virtual TEB"); }
    std::memcpy(cpu->fs_data + offset, &value, sizeof(value));
}

extern "C" std::uint8_t __cdecl lift_fs_load8(const LiftCpu* cpu, std::uint32_t offset) { return fs_load<std::uint8_t>(cpu, offset); }
extern "C" std::uint16_t __cdecl lift_fs_load16(const LiftCpu* cpu, std::uint32_t offset) { return fs_load<std::uint16_t>(cpu, offset); }
extern "C" std::uint32_t __cdecl lift_fs_load32(const LiftCpu* cpu, std::uint32_t offset) { return fs_load<std::uint32_t>(cpu, offset); }
extern "C" void __cdecl lift_fs_store8(LiftCpu* cpu, std::uint32_t offset, std::uint8_t value) { fs_store(cpu, offset, value); }
extern "C" void __cdecl lift_fs_store16(LiftCpu* cpu, std::uint32_t offset, std::uint16_t value) { fs_store(cpu, offset, value); }
extern "C" void __cdecl lift_fs_store32(LiftCpu* cpu, std::uint32_t offset, std::uint32_t value) { fs_store(cpu, offset, value); }

extern "C" void __cdecl lift_push32(LiftCpu* cpu, std::uint32_t value) {
    cpu->esp -= 4u;
    memory_write(cpu->esp, value);
}

extern "C" std::uint32_t __cdecl lift_pop32(LiftCpu* cpu) {
    const std::uint32_t value = memory_read<std::uint32_t>(cpu->esp);
    cpu->esp += 4u;
    return value;
}


extern "C" std::uint64_t __cdecl lift_shift_left(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width) {
    const std::uint64_t mask = width_mask(static_cast<std::uint16_t>(width));
    count &= 0x1Fu;
    value &= mask;
    if (count == 0) { return value; }
    const std::uint64_t result = (value << count) & mask;
    assign_flag(*cpu, LIFT_FLAG_CF, count <= width && ((value >> (width - count)) & 1u) != 0);
    if (count == 1) { assign_flag(*cpu, LIFT_FLAG_OF, ((result & sign_bit(static_cast<std::uint16_t>(width))) != 0) != flag(*cpu, LIFT_FLAG_CF)); }
    set_szp(*cpu, result, static_cast<std::uint16_t>(width));
    return result;
}

extern "C" std::uint64_t __cdecl lift_shift_right(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width) {
    value &= width_mask(static_cast<std::uint16_t>(width));
    count &= 0x1Fu;
    if (count == 0) { return value; }
    const std::uint64_t result = value >> count;
    assign_flag(*cpu, LIFT_FLAG_CF, count <= width && ((value >> (count - 1u)) & 1u) != 0);
    if (count == 1) { assign_flag(*cpu, LIFT_FLAG_OF, (value & sign_bit(static_cast<std::uint16_t>(width))) != 0); }
    set_szp(*cpu, result, static_cast<std::uint16_t>(width));
    return result;
}

extern "C" std::uint64_t __cdecl lift_shift_arithmetic(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width) {
    value &= width_mask(static_cast<std::uint16_t>(width));
    count &= 0x1Fu;
    if (count == 0) { return value; }
    const std::uint64_t result = static_cast<std::uint64_t>(signed_value(value, static_cast<std::uint16_t>(width)) >> count) & width_mask(static_cast<std::uint16_t>(width));
    assign_flag(*cpu, LIFT_FLAG_CF, count <= width && ((value >> (count - 1u)) & 1u) != 0);
    if (count == 1) { assign_flag(*cpu, LIFT_FLAG_OF, false); }
    set_szp(*cpu, result, static_cast<std::uint16_t>(width));
    return result;
}

std::uint64_t rotate_plain(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width, bool right) {
    const std::uint64_t mask = width_mask(static_cast<std::uint16_t>(width));
    const std::uint32_t effective = (count & 0x1Fu) % width;
    value &= mask;
    if (effective == 0) { return value; }
    const std::uint64_t result = right ? ((value >> effective) | (value << (width - effective))) & mask : ((value << effective) | (value >> (width - effective))) & mask;
    assign_flag(*cpu, LIFT_FLAG_CF, right ? (result & sign_bit(static_cast<std::uint16_t>(width))) != 0 : (result & 1u) != 0);
    if (effective == 1) { assign_flag(*cpu, LIFT_FLAG_OF, right ? ((result ^ (result << 1u)) & sign_bit(static_cast<std::uint16_t>(width))) != 0 : ((result & sign_bit(static_cast<std::uint16_t>(width))) != 0) != flag(*cpu, LIFT_FLAG_CF)); }
    return result;
}

extern "C" std::uint64_t __cdecl lift_rotate_left(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width) { return rotate_plain(cpu, value, count, width, false); }
extern "C" std::uint64_t __cdecl lift_rotate_right(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width) { return rotate_plain(cpu, value, count, width, true); }

std::uint64_t rotate_carry(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width, bool right) {
    const std::uint64_t mask = width_mask(static_cast<std::uint16_t>(width));
    const std::uint64_t sign = sign_bit(static_cast<std::uint16_t>(width));
    const std::uint32_t effective = (count & 0x1Fu) % (width + 1u);
    value &= mask;
    for (std::uint32_t index = 0; index < effective; ++index) {
        const bool old_carry = flag(*cpu, LIFT_FLAG_CF);
        const bool new_carry = right ? (value & 1u) != 0 : (value & sign) != 0;
        value = right ? (value >> 1u) | (old_carry ? sign : 0u) : ((value << 1u) & mask) | (old_carry ? 1u : 0u);
        assign_flag(*cpu, LIFT_FLAG_CF, new_carry);
    }
    if (effective == 1) {
        const bool overflow = right
            ? ((value & sign) != 0) != ((value & (sign >> 1u)) != 0)
            : ((value & sign) != 0) != flag(*cpu, LIFT_FLAG_CF);
        assign_flag(*cpu, LIFT_FLAG_OF, overflow);
    }
    return value;
}

extern "C" std::uint64_t __cdecl lift_rotate_carry_right(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width) { return rotate_carry(cpu, value, count, width, true); }
extern "C" std::uint64_t __cdecl lift_rotate_carry_left(LiftCpu* cpu, std::uint64_t value, std::uint32_t count, std::uint32_t width) { return rotate_carry(cpu, value, count, width, false); }

std::uint64_t double_shift(LiftCpu* cpu, std::uint64_t left, std::uint64_t right, std::uint32_t count, std::uint32_t width, bool toward_left) {
    const std::uint64_t mask = width_mask(static_cast<std::uint16_t>(width));
    count &= 0x1Fu;
    left &= mask;
    right &= mask;
    if (count == 0) { return left; }
    const std::uint64_t result = toward_left ? ((left << count) | (right >> (width - count))) & mask : ((left >> count) | (right << (width - count))) & mask;
    assign_flag(*cpu, LIFT_FLAG_CF, toward_left ? ((left >> (width - count)) & 1u) != 0 : ((left >> (count - 1u)) & 1u) != 0);
    if (count == 1) { assign_flag(*cpu, LIFT_FLAG_OF, toward_left ? ((result & sign_bit(static_cast<std::uint16_t>(width))) != 0) != flag(*cpu, LIFT_FLAG_CF) : ((left ^ result) & sign_bit(static_cast<std::uint16_t>(width))) != 0); }
    set_szp(*cpu, result, static_cast<std::uint16_t>(width));
    return result;
}

extern "C" std::uint64_t __cdecl lift_double_shift_left(LiftCpu* cpu, std::uint64_t left, std::uint64_t right, std::uint32_t count, std::uint32_t width) { return double_shift(cpu, left, right, count, width, true); }
extern "C" std::uint64_t __cdecl lift_double_shift_right(LiftCpu* cpu, std::uint64_t left, std::uint64_t right, std::uint32_t count, std::uint32_t width) { return double_shift(cpu, left, right, count, width, false); }

extern "C" void __cdecl lift_multiply_accumulator(LiftCpu* cpu, std::uint64_t source, std::uint32_t width, std::uint32_t is_signed) {
    if (width == 8) {
        const std::uint16_t product = is_signed ? static_cast<std::uint16_t>(static_cast<std::int16_t>(static_cast<std::int8_t>(cpu->eax)) * static_cast<std::int8_t>(source)) : static_cast<std::uint16_t>(static_cast<std::uint8_t>(cpu->eax) * static_cast<std::uint8_t>(source));
        cpu->eax = (cpu->eax & 0xFFFF0000u) | product;
        const bool overflow = is_signed ? static_cast<std::int16_t>(product) != static_cast<std::int8_t>(product) : (product & 0xFF00u) != 0;
        assign_flag(*cpu, LIFT_FLAG_CF, overflow); assign_flag(*cpu, LIFT_FLAG_OF, overflow); return;
    }
    if (width != 32) { throw std::runtime_error("Unsupported accumulator multiply width"); }
    const std::uint64_t product = is_signed ? static_cast<std::uint64_t>(static_cast<std::int64_t>(static_cast<std::int32_t>(cpu->eax)) * static_cast<std::int32_t>(source)) : static_cast<std::uint64_t>(cpu->eax) * static_cast<std::uint32_t>(source);
    cpu->eax = static_cast<std::uint32_t>(product); cpu->edx = static_cast<std::uint32_t>(product >> 32u);
    const bool overflow = is_signed ? static_cast<std::int64_t>(product) != static_cast<std::int32_t>(product) : cpu->edx != 0;
    assign_flag(*cpu, LIFT_FLAG_CF, overflow); assign_flag(*cpu, LIFT_FLAG_OF, overflow);
}

extern "C" void __cdecl lift_divide_accumulator(LiftCpu* cpu, std::uint64_t divisor, std::uint32_t width, std::uint32_t is_signed) {
    if (divisor == 0) { throw std::runtime_error("Division by zero in lifted code"); }
    if (width == 8) {
        const std::uint16_t dividend = static_cast<std::uint16_t>(cpu->eax);
        if (is_signed) {
            const std::int16_t quotient = static_cast<std::int16_t>(dividend) / static_cast<std::int8_t>(divisor);
            const std::int16_t remainder = static_cast<std::int16_t>(dividend) % static_cast<std::int8_t>(divisor);
            if (quotient < -128 || quotient > 127) { throw std::runtime_error("Signed division overflow in lifted code"); }
            cpu->eax = (cpu->eax & 0xFFFF0000u) | (static_cast<std::uint8_t>(quotient)) | (static_cast<std::uint32_t>(static_cast<std::uint8_t>(remainder)) << 8u);
        } else {
            const std::uint16_t quotient = dividend / static_cast<std::uint8_t>(divisor);
            if (quotient > 0xFFu) { throw std::runtime_error("Division overflow in lifted code"); }
            cpu->eax = (cpu->eax & 0xFFFF0000u) | static_cast<std::uint8_t>(quotient) | (static_cast<std::uint32_t>(dividend % static_cast<std::uint8_t>(divisor)) << 8u);
        }
        return;
    }
    if (width != 32) { throw std::runtime_error("Unsupported accumulator divide width"); }
    if (is_signed) {
        const std::int64_t dividend = static_cast<std::int64_t>((static_cast<std::uint64_t>(cpu->edx) << 32u) | cpu->eax);
        const std::int32_t signed_divisor = static_cast<std::int32_t>(divisor);
        if (dividend == std::numeric_limits<std::int64_t>::min() && signed_divisor == -1) { throw std::runtime_error("Signed division overflow in lifted code"); }
        const std::int64_t quotient = dividend / signed_divisor;
        if (quotient < std::numeric_limits<std::int32_t>::min() || quotient > std::numeric_limits<std::int32_t>::max()) { throw std::runtime_error("Signed division overflow in lifted code"); }
        cpu->eax = static_cast<std::uint32_t>(quotient); cpu->edx = static_cast<std::uint32_t>(dividend % signed_divisor);
    } else {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(cpu->edx) << 32u) | cpu->eax;
        const std::uint64_t quotient = dividend / static_cast<std::uint32_t>(divisor);
        if (quotient > std::numeric_limits<std::uint32_t>::max()) { throw std::runtime_error("Division overflow in lifted code"); }
        cpu->eax = static_cast<std::uint32_t>(quotient); cpu->edx = static_cast<std::uint32_t>(dividend % static_cast<std::uint32_t>(divisor));
    }
}

void require_x87(const LiftCpu* cpu, std::uint32_t count) {
    if (!cpu || cpu->fpu_depth < count) { throw std::runtime_error("x87 stack underflow"); }
}

extern "C" double __cdecl lift_x87_get(const LiftCpu* cpu, std::uint32_t index) { require_x87(cpu, index + 1u); return cpu->fpu[index]; }
extern "C" void __cdecl lift_x87_set(LiftCpu* cpu, std::uint32_t index, double value) { require_x87(cpu, index + 1u); cpu->fpu[index] = value; }
extern "C" void __cdecl lift_x87_push(LiftCpu* cpu, double value) {
    if (!cpu || cpu->fpu_depth == 8u) { throw std::runtime_error("x87 stack overflow"); }
    for (std::size_t index = cpu->fpu_depth; index > 0; --index) { cpu->fpu[index] = cpu->fpu[index - 1]; }
    cpu->fpu[0] = value; cpu->fpu_top = static_cast<std::uint8_t>((cpu->fpu_top + 7u) & 7u); ++cpu->fpu_depth;
}
extern "C" void __cdecl lift_x87_pop(LiftCpu* cpu) { require_x87(cpu, 1); for (std::size_t index = 1; index < cpu->fpu_depth; ++index) { cpu->fpu[index - 1] = cpu->fpu[index]; } --cpu->fpu_depth; cpu->fpu_top = static_cast<std::uint8_t>((cpu->fpu_top + 1u) & 7u); }
extern "C" std::int64_t __cdecl lift_x87_round(const LiftCpu* cpu, double value, std::uint32_t truncate) {
    if (truncate) { return static_cast<std::int64_t>(std::trunc(value)); }
    switch ((cpu->fpu_control >> 10u) & 3u) { case 1: return static_cast<std::int64_t>(std::floor(value)); case 2: return static_cast<std::int64_t>(std::ceil(value)); case 3: return static_cast<std::int64_t>(std::trunc(value)); default: return static_cast<std::int64_t>(std::nearbyint(value)); }
}
extern "C" void __cdecl lift_x87_compare(LiftCpu* cpu, double left, double right) { cpu->fpu_status &= static_cast<std::uint16_t>(~0x4500u); if (std::isnan(left) || std::isnan(right)) { cpu->fpu_status |= 0x4500u; } else if (left < right) { cpu->fpu_status |= 0x0100u; } else if (left == right) { cpu->fpu_status |= 0x4000u; } }
extern "C" void __cdecl lift_x87_sincos(LiftCpu* cpu) { const double value = lift_x87_get(cpu, 0); cpu->fpu[0] = std::sin(value); lift_x87_push(cpu, std::cos(value)); }

template <class T>
void move_string(LiftCpu* cpu, bool repeated) {
    std::uint32_t count = repeated ? cpu->ecx : 1u;
    if ((cpu->eflags & LIFT_FLAG_DF) == 0u && repeated) { const std::uint32_t bytes = count * static_cast<std::uint32_t>(sizeof(T)); const std::uint32_t source_end = cpu->esi + bytes; const std::uint32_t destination_end = cpu->edi + bytes; if (cpu->edi >= source_end || cpu->esi >= destination_end || bytes == 0u) { std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(cpu->edi)), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(cpu->esi)), bytes); cpu->esi = source_end; cpu->edi = destination_end; cpu->ecx = 0u; return; } }
    const std::int32_t delta = (cpu->eflags & LIFT_FLAG_DF) != 0u ? -static_cast<std::int32_t>(sizeof(T)) : static_cast<std::int32_t>(sizeof(T));
    while (count-- != 0u) { const T value = memory_read<T>(cpu->esi); memory_write<T>(cpu->edi, value); cpu->esi += delta; cpu->edi += delta; if (repeated) { --cpu->ecx; } }
}
template <class T>
void store_string(LiftCpu* cpu, bool repeated) {
    std::uint32_t count = repeated ? cpu->ecx : 1u;
    if (repeated && (cpu->eflags & LIFT_FLAG_DF) == 0u) { const std::uint32_t bytes = count * static_cast<std::uint32_t>(sizeof(T)); std::fill_n(reinterpret_cast<T*>(static_cast<std::uintptr_t>(cpu->edi)), count, static_cast<T>(cpu->eax)); cpu->edi += bytes; cpu->ecx = 0u; return; }
    const std::int32_t delta = (cpu->eflags & LIFT_FLAG_DF) != 0u ? -static_cast<std::int32_t>(sizeof(T)) : static_cast<std::int32_t>(sizeof(T));
    while (count-- != 0u) { memory_write<T>(cpu->edi, static_cast<T>(cpu->eax)); cpu->edi += delta; if (repeated) { --cpu->ecx; } }
}
template <class T>
void compare_string(LiftCpu* cpu, bool repeated, bool repeat_not_equal, bool scan) {
    std::uint32_t count = repeated ? cpu->ecx : 1u;
    const std::int32_t delta = flag(*cpu, LIFT_FLAG_DF) ? -static_cast<std::int32_t>(sizeof(T)) : static_cast<std::int32_t>(sizeof(T));
    while (count-- != 0) {
        const std::uint64_t left = scan ? static_cast<T>(cpu->eax) : memory_read<T>(cpu->esi);
        const std::uint64_t right = memory_read<T>(cpu->edi);
        if (!scan) { cpu->esi += delta; }
        cpu->edi += delta; set_sub_flags(*cpu, left, right, 0, left - right, static_cast<std::uint16_t>(sizeof(T) * 8u));
        if (!repeated) { break; }
        --cpu->ecx;
        if (repeat_not_equal ? flag(*cpu, LIFT_FLAG_ZF) : !flag(*cpu, LIFT_FLAG_ZF)) { break; }
    }
}
extern "C" void __cdecl lift_movs8(LiftCpu* cpu, std::uint32_t repeated) { move_string<std::uint8_t>(cpu, repeated != 0); }
extern "C" void __cdecl lift_movs16(LiftCpu* cpu, std::uint32_t repeated) { move_string<std::uint16_t>(cpu, repeated != 0); }
extern "C" void __cdecl lift_movs32(LiftCpu* cpu, std::uint32_t repeated) { move_string<std::uint32_t>(cpu, repeated != 0); }
extern "C" void __cdecl lift_stos8(LiftCpu* cpu, std::uint32_t repeated) { store_string<std::uint8_t>(cpu, repeated != 0); }
extern "C" void __cdecl lift_stos16(LiftCpu* cpu, std::uint32_t repeated) { store_string<std::uint16_t>(cpu, repeated != 0); }
extern "C" void __cdecl lift_stos32(LiftCpu* cpu, std::uint32_t repeated) { store_string<std::uint32_t>(cpu, repeated != 0); }
extern "C" void __cdecl lift_cmps8(LiftCpu* cpu, std::uint32_t repeated, std::uint32_t repeat_not_equal) { compare_string<std::uint8_t>(cpu, repeated != 0, repeat_not_equal != 0, false); }
extern "C" void __cdecl lift_cmps16(LiftCpu* cpu, std::uint32_t repeated, std::uint32_t repeat_not_equal) { compare_string<std::uint16_t>(cpu, repeated != 0, repeat_not_equal != 0, false); }
extern "C" void __cdecl lift_cmps32(LiftCpu* cpu, std::uint32_t repeated, std::uint32_t repeat_not_equal) { compare_string<std::uint32_t>(cpu, repeated != 0, repeat_not_equal != 0, false); }
extern "C" void __cdecl lift_scas8(LiftCpu* cpu, std::uint32_t repeated, std::uint32_t repeat_not_equal) { compare_string<std::uint8_t>(cpu, repeated != 0, repeat_not_equal != 0, true); }
extern "C" void __cdecl lift_scas16(LiftCpu* cpu, std::uint32_t repeated, std::uint32_t repeat_not_equal) { compare_string<std::uint16_t>(cpu, repeated != 0, repeat_not_equal != 0, true); }
extern "C" void __cdecl lift_scas32(LiftCpu* cpu, std::uint32_t repeated, std::uint32_t repeat_not_equal) { compare_string<std::uint32_t>(cpu, repeated != 0, repeat_not_equal != 0, true); }

extern "C" LIFT_NORETURN void __cdecl lift_trap(LiftCpu* cpu, std::uint32_t source_va, const char* reason) { if (cpu) { cpu->eip = source_va; } throw std::runtime_error(std::string("Lifted C trap at ") + hex_u32(source_va) + ": " + (reason ? reason : "unknown")); }

extern "C" LIFT_NORETURN void __cdecl lift_trap_transfer(LiftCpu* cpu, std::uint32_t origin, std::uint32_t target, std::uint32_t esp_before, std::uint32_t stack_cleanup, std::uint32_t stop_address, const char* kind) {
    auto classify = [](std::uint32_t value) -> std::string { if (LiftFunction function = lift_callback_function(value)) { const std::uint32_t index = lift_function_index(function); return "lifted-function#" + std::to_string(index); } if (lift_is_native_code_address(value)) { return "native-image"; } const std::uint32_t rva = lift_source_rva(value); if (rva == UINT32_MAX) { return "non-code"; } if (lift_has_function_rva(rva)) { return "function@" + hex_u32(UINT32_C(0x00400000) + rva); } return "local-middle@" + hex_u32(UINT32_C(0x00400000) + rva); };
    auto peek = [cpu](std::uint32_t address, std::uint32_t& value) -> bool { if (!cpu || address < cpu->stack_limit || address > cpu->stack_base - 4u) { return false; } value = *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(address)); return true; };
    std::string message = std::string("Invalid lifted control transfer kind=") + (kind ? kind : "unknown") + " origin=" + hex_u32(origin) + " target=" + hex_u32(target) + " target-class=" + classify(target) + " esp=" + hex_u32(esp_before) + " cleanup=" + std::to_string(stack_cleanup) + " stop=" + hex_u32(stop_address);
    if (g_last_native_callsite != 0u) { message += " last-native-callsite=" + hex_u32(g_last_native_callsite) + " last-native-target=" + hex_u32(g_last_native_target) + " native-esp-before=" + hex_u32(g_last_native_esp_before) + " native-esp-after=" + hex_u32(g_last_native_esp_after) + " native-esp-delta=" + std::to_string(static_cast<std::int32_t>(g_last_native_esp_after - g_last_native_esp_before)); }
    static constexpr int offsets[] = {-8, -4, 0, 4, 8, 12, 16};
    for (int offset : offsets) { std::uint32_t value = 0u; const std::uint32_t address = static_cast<std::uint32_t>(esp_before + offset); if (peek(address, value)) { message += " [esp"; if (offset >= 0) { message += "+"; } message += std::to_string(offset); message += "]=" + hex_u32(value) + "{" + classify(value) + "}"; } }
    std::uint32_t next = 0u; if (peek(esp_before + 4u, next) && target < UINT32_C(0x10000) && lift_source_rva(next) != UINT32_MAX && lift_has_function_rva(lift_source_rva(next))) { message += " probable-stack-skew=+4"; }
    std::uint32_t prev = 0u; if (esp_before >= 4u && peek(esp_before - 4u, prev) && target < UINT32_C(0x10000) && lift_source_rva(prev) != UINT32_MAX && lift_has_function_rva(lift_source_rva(prev))) { message += " probable-stack-skew=-4"; }
    if (cpu) { cpu->eip = origin; }
    throw std::runtime_error(message);
}

const std::wstring& client_root_directory() {
    static const std::wstring root = [] {
        const std::wstring configured = environment_path(kClientRootEnvironment);
        if (!configured.empty()) {
            if (!is_client_root(configured)) { throw std::runtime_error("SFERA_CLIENT_ROOT does not contain mbc\\_main.mbc: " + narrow_path(configured)); }
            return configured;
        }
        std::vector<std::wstring> candidates;
        add_candidate_with_parents(candidates, current_directory());
        add_candidate_with_parents(candidates, parent_directory(host_executable_path()));
        for (const std::wstring& candidate : candidates) {
            if (is_client_root(candidate)) { return candidate; }
        }
        throw std::runtime_error("Unable to locate mbc\\_main.mbc. Set SFERA_CLIENT_ROOT to the client directory that contains the mbc folder.");
    }();
    return root;
}

void configure_process_environment() {
    const std::wstring& root = client_root_directory();
    if (!SetCurrentDirectoryW(root.c_str())) { throw std::runtime_error(win32_error("SetCurrentDirectoryW")); }
    const std::string note = "client resource root: " + narrow_path(root);
    diagnostic_note(note.c_str());
}

std::string win32_error(const char* operation, DWORD error) {
    return std::string(operation) + " failed with Win32 error " + std::to_string(static_cast<unsigned long>(error));
}

std::string hex_u32(std::uint32_t value) {
    char buffer[11]{};
    std::snprintf(buffer, sizeof(buffer), "0x%08X", static_cast<unsigned>(value));
    return buffer;
}

LocalStack::LocalStack(std::size_t reserve_size) : size_(std::max<std::size_t>(reserve_size, 1024u * 1024u)) {
    memory_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, size_, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!memory_) { throw std::runtime_error(win32_error("VirtualAlloc(local stack)")); }
}

LocalStack::~LocalStack() {
    if (memory_) { VirtualFree(memory_, 0, MEM_RELEASE); }
}

std::uint32_t LocalStack::top() const noexcept {
    const std::uintptr_t value = reinterpret_cast<std::uintptr_t>(memory_ + size_ - 64u);
    return static_cast<std::uint32_t>(value & ~std::uintptr_t{0xFu});
}

std::uint32_t LocalStack::base() const noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(memory_ + size_));
}

std::uint32_t LocalStack::limit() const noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(memory_));
}

ProcessMemory::ProcessMemory() {
    if (g_process_memory) { throw std::runtime_error("Only one process-memory instance is supported"); }
    DiagnosticPhaseScope phase(RuntimePhase::static_storage);
    try { allocate_runtime_regions(); } catch (...) { release(); throw; }
    g_process_memory = this;
    const std::string note = "semantic native storage ready; module=" + hex_u32(load_base()) + ", callback-thunks=" + hex_u32(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_))) + ", semantic-rdata=eliminated, semantic-data=native";
    diagnostic_note(note.c_str());
}

ProcessMemory::~ProcessMemory() { release(); }

std::uint32_t ProcessMemory::load_base() const noexcept { return process_module_handle(); }

std::uint32_t ProcessMemory::entry_va() noexcept { return kCodeTokenBase + 0x000EF142u; }

bool ProcessMemory::code_rva(std::uint32_t address, std::uint32_t& rva) const noexcept {
    if (address >= 0x00400000u + UINT32_C(0x00001000) && address < 0x00400000u + UINT32_C(0x000FC200) && !native_executable_image_address(address)) { rva = address - 0x00400000u; return true; }
    const std::uint32_t token_rva = address - kCodeTokenBase;
    if (token_rva >= UINT32_C(0x00001000) && token_rva < UINT32_C(0x000FC200)) { rva = token_rva; return true; }
    return false;
}

bool ProcessMemory::source_rva(std::uint32_t address, std::uint32_t& rva) const noexcept { return code_rva(address, rva); }


void ProcessMemory::initialize_callback_registry() {
    const std::uint32_t count = lift_function_count();
    const std::size_t used_bytes = static_cast<std::size_t>(count) * kCallbackThunkSize;
    if (!callback_thunks_ || used_bytes > callback_thunks_size_) { throw std::runtime_error("Lifted function thunk pool is too small"); }
    const std::size_t committed_bytes = (used_bytes + kCallbackThunkPageSize - 1u) & ~(static_cast<std::size_t>(kCallbackThunkPageSize) - 1u);
    if (!VirtualAlloc(callback_thunks_, committed_bytes, MEM_COMMIT, PAGE_READWRITE)) { throw std::runtime_error(win32_error("VirtualAlloc(lifted function thunks)")); }
    for (std::uint32_t index = 0u; index < count; ++index) {
        const LiftFunction function = lift_function_at(index);
        if (!function) { throw std::runtime_error("Null lifted function identity"); }
        const std::uint32_t identity = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(function));
        std::uint8_t* const thunk = callback_thunks_ + static_cast<std::size_t>(index) * kCallbackThunkSize;
        thunk[0] = 0x68u;
        std::memcpy(thunk + 1, &identity, sizeof(identity));
        thunk[5] = 0xE9u;
        const std::uintptr_t bridge = reinterpret_cast<std::uintptr_t>(&callback_bridge);
        const std::intptr_t delta = static_cast<std::intptr_t>(bridge - reinterpret_cast<std::uintptr_t>(thunk + kCallbackThunkSize));
        if (delta < std::numeric_limits<std::int32_t>::min() || delta > std::numeric_limits<std::int32_t>::max()) { throw std::runtime_error("Callback bridge is outside rel32 range"); }
        const std::int32_t relative = static_cast<std::int32_t>(delta);
        std::memcpy(thunk + 6, &relative, sizeof(relative));
    }
    callback_thunk_count_ = count;
    for (std::uint32_t index = 0u; index < count; ++index) {
        const LiftFunction function = lift_function_at(index);
        const std::uint32_t identity = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(function));
        const std::uint32_t thunk_address = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_ + static_cast<std::size_t>(index) * kCallbackThunkSize));
        if (lift_function_index(function) != index || callback_function(identity) != function || callback_function(thunk_address) != function) { throw std::runtime_error("Semantic callback registry self-test failed"); }
    }
    FlushInstructionCache(GetCurrentProcess(), callback_thunks_, used_bytes);
    DWORD old = 0u;
    if (!VirtualProtect(callback_thunks_, committed_bytes, PAGE_EXECUTE_READ, &old)) { throw std::runtime_error(win32_error("VirtualProtect(lifted function thunks RX)")); }
}

std::uint32_t ProcessMemory::callback_address(LiftFunction function) const noexcept {
    const std::uint32_t index = lift_function_index(function);
    if (!callback_thunks_ || index == UINT32_MAX || index >= callback_thunk_count_) { return 0u; }
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_ + static_cast<std::size_t>(index) * kCallbackThunkSize));
}

LiftFunction ProcessMemory::callback_function(std::uint32_t address) const noexcept {
    LiftFunction direct = lift_function_from_native_address(address);
    if (direct) { return direct; }
    if (!callback_thunks_) { return (LiftFunction)0; }
    const std::uint32_t begin = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_));
    if (address < begin) { return (LiftFunction)0; }
    const std::uint32_t offset = address - begin;
    if ((offset % kCallbackThunkSize) != 0u) { return (LiftFunction)0; }
    const std::uint32_t index = offset / kCallbackThunkSize;
    if (index >= callback_thunk_count_) { return (LiftFunction)0; }
    return lift_function_at(index);
}

bool ProcessMemory::is_callback_function(LiftFunction function) const noexcept { return lift_function_index(function) != UINT32_MAX; }

bool ProcessMemory::try_read(std::uint32_t address, void* value, std::size_t size) const noexcept { if (!value) { return false; } return safe_copy(value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), size); }
bool ProcessMemory::try_write(std::uint32_t address, const void* value, std::size_t size) noexcept { if (!value) { return false; } return safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value, size); }

void ProcessMemory::read(std::uint32_t address, void* value, std::size_t size) const {
    if (!value) { throw std::runtime_error("Local memory read has a null destination"); }
    std::memcpy(value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), size);
}

void ProcessMemory::write(std::uint32_t address, const void* value, std::size_t size) {
    if (!value) { throw std::runtime_error("Local memory write has a null source"); }
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value, size);
}

void ProcessMemory::allocate_runtime_regions() {
    if (sizeof(void*) != 4 || 0x014Cu != IMAGE_FILE_MACHINE_I386) { throw std::runtime_error("Generated runtime requires Win32/x86"); }
    callback_thunks_size_ = kCallbackThunkCapacityBytes;
    callback_thunks_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, callback_thunks_size_, MEM_RESERVE, PAGE_NOACCESS));
    if (!callback_thunks_) { throw std::runtime_error(win32_error("VirtualAlloc(callback thunk pool reserve)")); }
}

void ProcessMemory::initialize_native() {
    try {
        lift_initialize_dispatch();
        initialize_callback_registry();
        resolve_static_references();
        { DiagnosticPhaseScope phase(RuntimePhase::protect_static_storage); protect_regions(); diagnostic_note("semantic static-region protections applied"); }
    } catch (...) { release(); throw; }
}

void ProcessMemory::resolve_static_references() {
    enum class ComAbiInterface : std::uint32_t { storage, inplace_frame, client_site, inplace_site, doc_host_ui_handler };
    auto com_method_function = [](ComAbiInterface interface_id, std::uint32_t slot) noexcept -> LiftFunction {
        switch (interface_id) {
        case ComAbiInterface::storage:
            if (slot == 0u || slot == 13u || slot == 16u || slot == 17u) { return &sfera_sub_00421A80; }
            if (slot == 1u || slot == 2u) { return &sfera_sub_00421980; }
            if (slot >= 3u && slot <= 5u) { return &sfera_sub_00421820; }
            if (slot == 6u) { return &sfera_sub_00421830; }
            if (slot == 7u || slot == 8u || slot == 11u || slot == 14u) { return &sfera_sub_00421840; }
            if (slot == 9u || slot == 12u) { return &sfera_sub_00421A70; }
            if (slot == 10u) { return &sfera_sub_00421A00; }
            if (slot == 15u) { return &sfera_sub_004219E0; }
            return (LiftFunction)0;
        case ComAbiInterface::inplace_frame:
            if (slot == 0u || slot == 9u || slot == 14u) { return &sfera_sub_00421A80; }
            if (slot == 1u || slot == 2u) { return &sfera_sub_00421980; }
            if (slot == 3u) { return &sfera_sub_00421A50; }
            if ((slot >= 4u && slot <= 7u) || slot == 11u) { return &sfera_sub_00421A70; }
            if (slot == 8u) { return &sfera_sub_0043B130; }
            if (slot == 10u) { return &sfera_sub_00421790; }
            if (slot == 12u || slot == 13u) { return &sfera_sub_004219E0; }
            return (LiftFunction)0;
        case ComAbiInterface::client_site:
            if (slot == 0u) { return &sfera_sub_00421850; }
            if (slot == 1u || slot == 2u) { return &sfera_sub_00421980; }
            if (slot == 3u || slot == 8u) { return &sfera_sub_00421A00; }
            if (slot == 4u) { return &sfera_sub_00421940; }
            if (slot == 5u) { return &sfera_sub_00421950; }
            if (slot == 6u) { return &sfera_sub_004219F0; }
            if (slot == 7u) { return &sfera_sub_00421A70; }
            return (LiftFunction)0;
        case ComAbiInterface::inplace_site:
            if (slot == 0u) { return &sfera_sub_00421970; }
            if (slot == 1u || slot == 2u) { return &sfera_sub_00421980; }
            if (slot == 3u) { return &sfera_sub_00421990; }
            if (slot == 4u) { return &sfera_sub_00421A70; }
            if ((slot >= 5u && slot <= 7u) || slot == 11u) { return &sfera_sub_004219F0; }
            if (slot == 8u) { return &sfera_sub_004219B0; }
            if (slot == 9u) { return &sfera_sub_00421A80; }
            if (slot == 10u) { return &sfera_sub_004219E0; }
            if (slot == 12u || slot == 13u) { return &sfera_sub_00421A00; }
            if (slot == 14u) { return &sfera_sub_00421A10; }
            return (LiftFunction)0;
        case ComAbiInterface::doc_host_ui_handler:
            if (slot == 0u) { return &sfera_sub_00421FB0; }
            if (slot == 1u || slot == 2u) { return &sfera_sub_00421980; }
            if (slot == 3u) { return &sfera_sub_00421750; }
            if (slot == 4u) { return &sfera_sub_00421760; }
            if (slot == 5u) { return &sfera_sub_00421780; }
            if (slot == 6u || slot == 7u) { return &sfera_sub_004219F0; }
            if (slot >= 8u && slot <= 10u) { return &sfera_sub_004219E0; }
            if (slot == 11u) { return &sfera_sub_00421790; }
            if (slot == 12u) { return &sfera_sub_004217A0; }
            if (slot == 13u || slot == 14u) { return &sfera_sub_004217B0; }
            if (slot == 15u) { return &sfera_sub_004217C0; }
            if (slot == 16u) { return &sfera_sub_004217E0; }
            if (slot == 17u) { return &sfera_sub_00421800; }
            return (LiftFunction)0;
        }
        return (LiftFunction)0;
    };
    auto bind_com_vtable = [&](std::uint32_t* vtable, std::uint32_t slot_count, ComAbiInterface interface_id, const char* interface_name) { for (std::uint32_t slot = 0u; slot < slot_count; ++slot) { const LiftFunction function = com_method_function(interface_id, slot); const std::uint32_t callback = callback_address(function); if (!function || callback == 0u) { throw std::runtime_error(std::string("Missing lifted ") + interface_name + " vtable handler at slot " + std::to_string(slot)); } vtable[slot] = callback; } };
    bind_com_vtable(g_sfera_ole_host_abi.storage_vtable, 18u, ComAbiInterface::storage, "IStorage");
    bind_com_vtable(g_sfera_ole_host_abi.inplace_frame_vtable, 15u, ComAbiInterface::inplace_frame, "IOleInPlaceFrame");
    bind_com_vtable(g_sfera_ole_host_abi.client_site_vtable, 9u, ComAbiInterface::client_site, "IOleClientSite");
    bind_com_vtable(g_sfera_ole_host_abi.inplace_site_vtable, 15u, ComAbiInterface::inplace_site, "IOleInPlaceSite");
    bind_com_vtable(g_sfera_ole_host_abi.doc_host_ui_handler_vtable, 18u, ComAbiInterface::doc_host_ui_handler, "IDocHostUIHandler");
    g_sfera_ole_host_abi.storage_object_vtable = (std::uint32_t)(uintptr_t)&g_sfera_ole_host_abi.storage_vtable[0];
    g_sfera_memory_runtime.critical_error_callback = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&sfera_sub_004EBF30));
}

void ProcessMemory::protect_regions() {}

void ProcessMemory::release() noexcept {
    if (g_process_memory == this) { g_process_memory = nullptr; }
    callback_thunk_count_ = 0u; if (callback_thunks_) { VirtualFree(callback_thunks_, 0, MEM_RELEASE); callback_thunks_ = nullptr; } callback_thunks_size_ = 0u;
}

namespace {

void initialize_fs(LiftCpu& state, bool inherit_exception_chain = false) {
    const std::uint32_t exception_list = inherit_exception_chain ? __readfsdword(0) : UINT32_C(0xFFFFFFFF);
    const std::uint32_t teb = __readfsdword(0x18);
    const std::uint32_t peb = __readfsdword(0x30);
    std::memcpy(state.fs_data, &exception_list, sizeof(exception_list));
    std::memcpy(state.fs_data + 0x18u, &teb, sizeof(teb));
    std::memcpy(state.fs_data + 0x30u, &peb, sizeof(peb));
}

#if !defined(SFERA_PORTABLE_CHECK) && defined(_M_IX86)

extern "C" __declspec(noinline) std::uint32_t __cdecl bridge_test_cdecl(std::uint32_t left, std::uint32_t right) { return left + right * 3u; }
extern "C" __declspec(noinline) std::uint32_t __stdcall bridge_test_stdcall(std::uint32_t left, std::uint32_t right) { return left ^ (right + 0x13579BDFu); }
extern "C" __declspec(noinline) std::uint32_t __fastcall bridge_test_fastcall(std::uint32_t left, std::uint32_t right, std::uint32_t stack_value) { return left + right + stack_value; }

void verify_native_bridge() {
    DiagnosticPhaseScope phase(RuntimePhase::abi_self_test);
    LocalStack stack(64u * 1024u);
    LiftCpu state{};
    auto prepare = [&]() {
        state = LiftCpu{};
        state.eflags = 0x202u;
        state.fpu_control = 0x027Fu;
        state.esp = stack.top();
        state.stack_base = stack.base();
        state.stack_limit = stack.limit();
        state.ebx = 0xB1B2B3B4u;
        state.ebp = 0xB5B6B7B8u;
        state.esi = 0x51525354u;
        state.edi = 0xD1D2D3D4u;
        initialize_fs(state);
    };
    auto verify_nonvolatile = [&]() {
        if (state.ebx != 0xB1B2B3B4u || state.ebp != 0xB5B6B7B8u || state.esi != 0x51525354u || state.edi != 0xD1D2D3D4u) { throw std::runtime_error("Native bridge corrupted a nonvolatile x86 register"); }
    };
    auto verify_teb = [&](const NativeCallFrame& frame, const char* convention, std::uint32_t actual_exception_list, std::uint32_t actual_stack_base, std::uint32_t actual_stack_limit) {
        const std::uint32_t expected_exception_list = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(frame.previous_exception_list));
        const std::uint32_t expected_stack_base = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(frame.previous_stack_base));
        const std::uint32_t expected_stack_limit = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(frame.previous_stack_limit));
        if (actual_exception_list == expected_exception_list && actual_stack_base == expected_stack_base && actual_stack_limit == expected_stack_limit) { return; }
        throw std::runtime_error(std::string("Native bridge failed to restore the host TEB after ") + convention + ": FS:[0] expected=" + hex_u32(expected_exception_list) + " actual=" + hex_u32(actual_exception_list) + ", FS:[4] expected=" + hex_u32(expected_stack_base) + " actual=" + hex_u32(actual_stack_base) + ", FS:[8] expected=" + hex_u32(expected_stack_limit) + " actual=" + hex_u32(actual_stack_limit));
    };
    prepare();
    lift_push32(&state, 7u);
    lift_push32(&state, 5u);
    const std::uint32_t cdecl_esp = state.esp;
    NativeCallFrame cdecl_frame{&state, reinterpret_cast<void*>(&bridge_test_cdecl), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr};
    native_call_bridge(&cdecl_frame);
    const std::uint32_t cdecl_exception_list = __readfsdword(0);
    const std::uint32_t cdecl_stack_base = __readfsdword(4);
    const std::uint32_t cdecl_stack_limit = __readfsdword(8);
    if (state.eax != 26u || state.esp != cdecl_esp) { throw std::runtime_error("Native bridge failed its cdecl stack test"); }
    verify_teb(cdecl_frame, "cdecl", cdecl_exception_list, cdecl_stack_base, cdecl_stack_limit);
    verify_nonvolatile();
    prepare();
    lift_push32(&state, 0x2468ACE0u);
    lift_push32(&state, 0x10203040u);
    const std::uint32_t stdcall_esp = state.esp;
    NativeCallFrame stdcall_frame{&state, reinterpret_cast<void*>(&bridge_test_stdcall), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr};
    native_call_bridge(&stdcall_frame);
    const std::uint32_t stdcall_exception_list = __readfsdword(0);
    const std::uint32_t stdcall_stack_base = __readfsdword(4);
    const std::uint32_t stdcall_stack_limit = __readfsdword(8);
    if (state.eax != (0x10203040u ^ (0x2468ACE0u + 0x13579BDFu)) || state.esp != stdcall_esp + 8u) { throw std::runtime_error("Native bridge failed its stdcall stack test"); }
    verify_teb(stdcall_frame, "stdcall", stdcall_exception_list, stdcall_stack_base, stdcall_stack_limit);
    verify_nonvolatile();
    prepare();
    state.ecx = 11u;
    state.edx = 13u;
    lift_push32(&state, 17u);
    const std::uint32_t fastcall_esp = state.esp;
    NativeCallFrame fastcall_frame{&state, reinterpret_cast<void*>(&bridge_test_fastcall), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr};
    native_call_bridge(&fastcall_frame);
    const std::uint32_t fastcall_exception_list = __readfsdword(0);
    const std::uint32_t fastcall_stack_base = __readfsdword(4);
    const std::uint32_t fastcall_stack_limit = __readfsdword(8);
    if (state.eax != 41u || state.esp != fastcall_esp + 4u) { throw std::runtime_error("Native bridge failed its fastcall stack test"); }
    verify_teb(fastcall_frame, "fastcall", fastcall_exception_list, fastcall_stack_base, fastcall_stack_limit);
    verify_nonvolatile();
    diagnostic_note("cdecl/stdcall/fastcall bridge self-test passed");
}

#else

void verify_native_bridge() {}

#endif

} // namespace

NativeRuntime::NativeRuntime() {
    memory_.initialize_native();
    verify_native_bridge();
    DiagnosticPhaseScope phase(RuntimePhase::function_map);
    diagnostic_note("native function dispatch initialized");
}

void NativeRuntime::call_native(LiftCpu& state, std::uint32_t target, std::uint32_t callsite) {
    struct NativeEspTrace { LiftCpu& state; NativeEspTrace(LiftCpu& value, std::uint32_t native_target, std::uint32_t native_callsite) : state(value) { g_last_native_target = native_target; g_last_native_callsite = native_callsite; g_last_native_esp_before = value.esp; g_last_native_esp_after = value.esp; } ~NativeEspTrace() { g_last_native_esp_after = state.esp; } } native_esp_trace(state, target, callsite);
    if (target < 0x10000u) { throw std::runtime_error("Invalid native call target " + hex_u32(target) + " at " + hex_u32(callsite)); }
    NativeCallFrame frame{&state, reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr};
    native_call_bridge(&frame);
}

extern "C" void __cdecl lift_native_call(LiftCpu* cpu, std::uint32_t target, std::uint32_t callsite) {
    if (!g_runtime || !cpu) { throw std::runtime_error("Native call without an active native runtime"); }
    g_runtime->call_native(*cpu, target, callsite);
}



int NativeRuntime::execute() {
    DiagnosticPhaseScope phase(RuntimePhase::execution_setup);
    LocalStack stack(kStackReserve);
    LiftCpu state{};
    state.eflags = 0x202u;
    state.fpu_control = 0x027Fu;
    state.esp = stack.top();
    state.stack_base = stack.base();
    state.stack_limit = stack.limit();
    state.eip = memory_.entry_va();
    initialize_fs(state);
    lift_push32(&state, LIFT_CALLBACK_SENTINEL);
    DiagnosticRunScope run_scope(&state);
    DiagnosticExecutionScope execution_scope(state.eip, LIFT_CALLBACK_SENTINEL, state.esp);
    diagnostic_note("entering generated C entry function");
    g_runtime = this;
    try {
        DiagnosticPhaseScope native_phase(RuntimePhase::native_c);
        lift_dispatch(&state, state.eip, LIFT_CALLBACK_SENTINEL);
        g_runtime = nullptr;
        return static_cast<int>(state.eax);
    } catch (const std::exception& error) {
        diagnostic_failure(state, error.what());
        g_runtime = nullptr;
        throw;
    } catch (...) {
        diagnostic_failure(state, "Unknown failure in generated C code");
        g_runtime = nullptr;
        throw;
    }
}

void NativeRuntime::dispatch_callback(CallbackRegisters& registers) {
    const LiftFunction function = reinterpret_cast<LiftFunction>(static_cast<std::uintptr_t>(registers.callback_function));
    if (!memory_.is_callback_function(function)) { throw std::runtime_error("Unknown semantic callback function"); }
    const std::uint32_t original_esp = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&registers.callback_function) + sizeof(registers.callback_function));
    const std::uint32_t api_return = *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(original_esp));
#if !defined(SFERA_PORTABLE_CHECK) && defined(_M_IX86)
    const std::uintptr_t stack_base = __readfsdword(4);
    const std::size_t available = stack_base > original_esp ? stack_base - original_esp : 0u;
#else
    MEMORY_BASIC_INFORMATION region{};
    if (VirtualQuery(reinterpret_cast<void*>(static_cast<std::uintptr_t>(original_esp)), &region, sizeof(region)) == 0 || region.State != MEM_COMMIT) { throw std::runtime_error("Unable to inspect native callback stack"); }
    const std::uintptr_t region_end = reinterpret_cast<std::uintptr_t>(region.BaseAddress) + region.RegionSize;
    const std::size_t available = region_end > original_esp ? region_end - original_esp : 0u;
#endif
    const std::size_t copy_size = std::min(kCallbackStackCopy, available);
    if (copy_size < 64u) { throw std::runtime_error("Native callback stack window is too small"); }
    CallbackStackLease lease;
    LocalStack& clone = lease.stack();
    const std::uint32_t clone_esp = clone.top() - static_cast<std::uint32_t>(copy_size);
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(clone_esp)), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(original_esp)), copy_size);
    *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(clone_esp)) = LIFT_CALLBACK_SENTINEL;
    LiftCpu state{};
    state.eax = registers.eax; state.ecx = registers.ecx; state.edx = registers.edx; state.ebx = registers.ebx; state.esp = clone_esp; state.ebp = registers.ebp; state.esi = registers.esi; state.edi = registers.edi; state.eip = LIFT_CALLBACK_SENTINEL; state.eflags = registers.eflags;
    state.fpu_control = 0x027Fu;
    state.stack_base = clone.base(); state.stack_limit = clone.limit();
    initialize_fs(state, true);
    function(&state, LIFT_CALLBACK_SENTINEL);
    const std::uint32_t stack_delta = state.esp - clone_esp;
    if (stack_delta < 4u || stack_delta > copy_size) { throw std::runtime_error("Lifted callback returned an invalid stack delta"); }
    if (copy_size > 4u) { std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(original_esp + 4u)), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(clone_esp + 4u)), copy_size - 4u); }
    const std::uint32_t destination = original_esp + stack_delta;
    *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(destination - 8u)) = state.eax;
    *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(destination - 4u)) = api_return;
    registers.eax = destination - 8u; registers.ecx = state.ecx; registers.edx = state.edx; registers.ebx = state.ebx; registers.ebp = state.ebp; registers.esi = state.esi; registers.edi = state.edi; registers.eflags = state.eflags;
}

extern "C" void __cdecl dispatch_native_callback(CallbackRegisters* registers) {
    if (!g_runtime || !registers) { TerminateProcess(GetCurrentProcess(), 0xE0000001u); }
    try {
        g_runtime->dispatch_callback(*registers);
    } catch (const std::exception& error) {
        diagnostic_note(error.what());
        TerminateProcess(GetCurrentProcess(), 0xE0000002u);
    }
}

#if defined(SFERA_PORTABLE_CHECK)

extern "C" void __cdecl native_call_bridge(NativeCallFrame*) {}
extern "C" void callback_bridge() {}

#elif defined(_M_IX86)

static_assert(offsetof(LiftCpu, eax) == 0 && offsetof(LiftCpu, eflags) == 36 && offsetof(LiftCpu, fpu_control) == 114);
static_assert(offsetof(LiftCpu, fs_data) == 120);
static_assert(offsetof(NativeCallFrame, state) == 0 && offsetof(NativeCallFrame, previous_stack_limit) == 36);
static_assert(offsetof(CallbackRegisters, edi) == 0 && offsetof(CallbackRegisters, eax) == 28 && offsetof(CallbackRegisters, eflags) == 32 && offsetof(CallbackRegisters, callback_function) == 36);
static_assert(sizeof(CallbackRegisters) == 40);

extern "C" __declspec(naked) void __cdecl native_call_bridge(NativeCallFrame*) {
    __asm {
        mov edx, [esp + 4]
        mov [edx + 8], esp
        mov [edx + 12], ebp
        mov [edx + 16], ebx
        mov [edx + 20], esi
        mov [edx + 24], edi
        mov eax, fs:[0]
        mov [edx + 28], eax
        mov eax, fs:[4]
        mov [edx + 32], eax
        mov eax, fs:[8]
        mov [edx + 36], eax
        mov eax, [edx]
        mov ecx, [eax + 120]
        mov fs:[0], ecx
        mov ecx, [eax + 40]
        mov fs:[4], ecx
        mov ecx, [eax + 44]
        mov fs:[8], ecx
        mov ecx, [eax + 16]
        sub ecx, 8
        mov ebx, [edx + 4]
        mov [ecx], ebx
        mov ebx, offset native_bridge_return
        mov [ecx + 4], ebx
        mov esp, ecx
        mov edi, [eax + 28]
        mov esi, [eax + 24]
        mov ebp, edx
        mov ebx, [eax + 12]
        mov edx, [eax + 8]
        mov ecx, [eax + 4]
        mov eax, [eax]
        cld
        ret
    native_bridge_return:
        pushfd
        pushad
        mov edx, [esp + 8]
        mov ecx, [edx]
        mov eax, [esp + 28]
        mov [ecx], eax
        mov eax, [esp + 24]
        mov [ecx + 4], eax
        mov eax, [esp + 20]
        mov [ecx + 8], eax
        mov eax, [esp + 16]
        mov [ecx + 12], eax
        mov eax, [esp + 12]
        add eax, 4
        mov [ecx + 16], eax
        mov eax, [esp + 4]
        mov [ecx + 24], eax
        mov eax, [esp]
        mov [ecx + 28], eax
        mov eax, [esp + 32]
        mov [ecx + 36], eax
        mov eax, [edx + 28]
        mov fs:[0], eax
        mov eax, [edx + 32]
        mov fs:[4], eax
        mov eax, [edx + 36]
        mov fs:[8], eax
        mov esp, [edx + 8]
        mov ebp, [edx + 12]
        mov ebx, [edx + 16]
        mov esi, [edx + 20]
        mov edi, [edx + 24]
        ret
    }
}

extern "C" __declspec(naked) void callback_bridge() {
    __asm {
        pushfd
        pushad
        cld
        push esp
        call dispatch_native_callback
        add esp, 4
        popad
        popfd
        mov esp, eax
        pop eax
        ret
    }
}

#else
#error The generated runtime must be compiled for Win32/x86.
#endif

int run_native_program() {
    configure_process_environment();
    diagnostic_note("generated C execution: optimized");
    NativeRuntime runtime;
    return runtime.execute();
}

} // namespace lifted
