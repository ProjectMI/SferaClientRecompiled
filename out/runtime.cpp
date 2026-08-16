#include "runtime.h"
#include "diagnostics.h"

#include <intrin.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cwchar>
#include <cstring>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string_view>
#include <unordered_map>

#if defined(_MSC_VER)
#pragma intrinsic(__readfsdword)
#endif

extern "C" {
std::uint32_t g_lift_header_base = 0;
std::uint32_t g_lift_rsrc_base = 0;
std::uint32_t g_lift_callback_thunk_base = 0;
}

namespace lifted {

NativeRuntime* g_runtime = nullptr;
ProcessMemory* g_process_memory = nullptr;

namespace {

constexpr std::size_t kCallbackStackCopy = 16u * 1024u;
constexpr std::uint32_t kCompactResourceRva = 0x00001000u;
constexpr std::uint32_t kCallbackThunkSize = 10u;
constexpr std::uint32_t kCodeTokenBase = 0xE0000000u;
constexpr wchar_t kClientRootEnvironment[] = L"SFERA_CLIENT_ROOT";
thread_local std::vector<std::unique_ptr<LocalStack>> g_callback_stacks;
thread_local std::size_t g_callback_stack_depth = 0;
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

std::wstring wide_client_filename() {
    return std::wstring(kClientExecutableName.begin(), kClientExecutableName.end());
}

std::wstring client_executable_path() {
    return path_join(client_root_directory(), wide_client_filename());
}

std::string client_executable_path_ansi() {
    const std::wstring wide = client_executable_path();
    const int required = WideCharToMultiByte(CP_ACP, 0, wide.data(), static_cast<int>(wide.size()), nullptr, 0, nullptr, nullptr);
    if (required <= 0) { throw std::runtime_error(win32_error("WideCharToMultiByte")); }
    std::string result(static_cast<std::size_t>(required), '\0');
    if (WideCharToMultiByte(CP_ACP, 0, wide.data(), static_cast<int>(wide.size()), result.data(), required, nullptr, nullptr) != required) { throw std::runtime_error(win32_error("WideCharToMultiByte")); }
    return result;
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


class NativeCallArguments {
public:
    explicit NativeCallArguments(std::uint32_t stack) noexcept : stack_(stack) {}
    NativeCallArguments(const NativeCallArguments&) = delete;
    NativeCallArguments& operator=(const NativeCallArguments&) = delete;
    ~NativeCallArguments() { while (patch_count_ != 0) { const Patch& patch = patches_[--patch_count_]; if (g_process_memory) { g_process_memory->try_write(patch.address, &patch.original, sizeof(patch.original)); } } }
    std::uint32_t read(std::uint8_t index) const { return memory_read<std::uint32_t>(stack_ + static_cast<std::uint32_t>(index) * 4u); }
    void alias(std::uint8_t index, std::uint32_t expected, std::uint32_t replacement) {
        const std::uint32_t address = stack_ + static_cast<std::uint32_t>(index) * 4u;
        const std::uint32_t original = memory_read<std::uint32_t>(address);
        if (original != expected) { throw std::runtime_error("Native argument changed before aliasing"); }
        if (patch_count_ == patches_.size()) { throw std::runtime_error("Too many native argument aliases"); }
        if (!g_process_memory || !g_process_memory->try_write(address, &replacement, sizeof(replacement))) { throw std::runtime_error("Unable to alias native argument at " + hex_u32(address)); }
        patches_[patch_count_++] = {address, original};
    }
private:
    struct Patch { std::uint32_t address; std::uint32_t original; };
    std::uint32_t stack_;
    std::array<Patch, 4> patches_{};
    std::size_t patch_count_ = 0;
};

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

template <class Char>
std::uint32_t write_local_path(std::uint32_t address, std::uint32_t capacity, const std::basic_string<Char>& path) {
    if (address == 0 || capacity == 0) { SetLastError(ERROR_INSUFFICIENT_BUFFER); return 0; }
    const std::size_t copy_count = std::min<std::size_t>(path.size(), static_cast<std::size_t>(capacity - 1u));
    std::vector<Char> output(copy_count + 1u, Char{});
    std::copy_n(path.data(), copy_count, output.data());
    const std::size_t byte_count = output.size() * sizeof(Char);
    if (!g_process_memory) { throw std::runtime_error("Process memory is not initialized"); }
    g_process_memory->write(address, output.data(), byte_count);
    diagnostic_memory_write(address, static_cast<std::uint32_t>(byte_count), 0);
    if (copy_count != path.size()) { SetLastError(ERROR_INSUFFICIENT_BUFFER); return capacity; }
    return static_cast<std::uint32_t>(path.size());
}

std::uint32_t align_down(std::uint32_t value, std::uint32_t alignment) noexcept {
    return value & ~(alignment - 1u);
}

std::uint32_t align_up(std::uint32_t value, std::uint32_t alignment) noexcept {
    return (value + alignment - 1u) & ~(alignment - 1u);
}

DWORD page_protection(std::uint8_t access) noexcept {
    switch (access & (kRead | kWrite | kExecute)) {
        case kExecute: return PAGE_EXECUTE;
        case kRead | kExecute: return PAGE_EXECUTE_READ;
        case kWrite | kExecute: return PAGE_EXECUTE_READWRITE;
        case kRead | kWrite | kExecute: return PAGE_EXECUTE_READWRITE;
        case kWrite: return PAGE_READWRITE;
        case kRead | kWrite: return PAGE_READWRITE;
        case kRead: return PAGE_READONLY;
        default: return PAGE_NOACCESS;
    }
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

bool is_float_return(std::string_view name) {
    return name == "atof" || name == "floor" || name == "ceil" || name == "frexp" || name == "ldexp" || name == "fmod";
}

} // namespace

extern "C" std::uint32_t __cdecl lift_source_rva(std::uint32_t address) { std::uint32_t rva = 0; return g_process_memory && g_process_memory->source_rva(address, rva) ? rva : UINT32_MAX; }
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
    if ((cpu->eflags & LIFT_FLAG_DF) == 0u && repeated) { const std::uint32_t bytes = count * static_cast<std::uint32_t>(sizeof(T)); const std::uint32_t source_end = cpu->esi + bytes; const std::uint32_t destination_end = cpu->edi + bytes; if (cpu->edi >= source_end || cpu->esi >= destination_end || bytes == 0u) { const std::uint32_t source = sfera_data_deref_range(cpu->esi, bytes); const std::uint32_t destination = sfera_data_deref_range(cpu->edi, bytes); std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(destination)), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(source)), bytes); cpu->esi = source_end; cpu->edi = destination_end; cpu->ecx = 0u; return; } }
    const std::int32_t delta = (cpu->eflags & LIFT_FLAG_DF) != 0u ? -static_cast<std::int32_t>(sizeof(T)) : static_cast<std::int32_t>(sizeof(T));
    while (count-- != 0u) { const T value = memory_read<T>(cpu->esi); memory_write<T>(cpu->edi, value); cpu->esi += delta; cpu->edi += delta; if (repeated) { --cpu->ecx; } }
}
template <class T>
void store_string(LiftCpu* cpu, bool repeated) {
    std::uint32_t count = repeated ? cpu->ecx : 1u;
    if (repeated && (cpu->eflags & LIFT_FLAG_DF) == 0u) { const std::uint32_t bytes = count * static_cast<std::uint32_t>(sizeof(T)); const std::uint32_t destination = sfera_data_deref_range(cpu->edi, bytes); std::fill_n(reinterpret_cast<T*>(static_cast<std::uintptr_t>(destination)), count, static_cast<T>(cpu->eax)); cpu->edi += bytes; cpu->ecx = 0u; return; }
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
    try { allocate_static_regions(); install_initial_static_data(); } catch (...) { release(); throw; }
    g_process_memory = this;
    const std::string note = "semantic static storage initialized; compact module=" + hex_u32(load_base()) + ", code-token=" + hex_u32(source_address(kSourceImageBase + 0x1000u)) + ", static-table-bytes=" + std::to_string(SFERA_STATIC_TABLE_STORAGE_SIZE) + ", callback-thunks=" + hex_u32(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_))) + ", semantic-rdata-bytes=" + std::to_string(SFERA_RDATA_SEMANTIC_SIZE) + ", data compatibility=" + hex_u32(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_data_compat_base))) + ", compatibility-segments=" + std::to_string(data_compat_segments_.size()) + ", semantic-spans=" + std::to_string(SFERA_DATA_SEMANTIC_SPAN_COUNT);
    diagnostic_note(note.c_str());
}

ProcessMemory::~ProcessMemory() { release(); }

std::uint32_t ProcessMemory::load_base() const noexcept { return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(module_shell_)); }

std::uint32_t ProcessMemory::entry_va() const noexcept {
    try { return source_address(kSourceImageBase + kEntryRva); } catch (...) { return 0; }
}

std::uint8_t* ProcessMemory::region_pointer(std::uint32_t rva, std::size_t size) const {
    if (rva >= UINT32_C(0x000FD000) && rva < UINT32_C(0x0011FE00)) { const std::uint32_t source_va = kSourceImageBase + rva; const std::uint32_t first = sfera_rdata_mutable_semantic_address(source_va); const std::uint32_t last = size == 0u ? first : sfera_rdata_mutable_semantic_address(source_va + static_cast<std::uint32_t>(size - 1u)); if (first != 0u && (size == 0u || (last != 0u && last - first == size - 1u))) { return reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(first)); } throw std::runtime_error("Source RVA targets immutable/dead semantic .rdata: " + hex_u32(rva) + ", size=" + std::to_string(size)); }
    for (const StaticRegion& region : regions_) {
        if (!region.memory || rva < region.rva) { continue; }
        const std::uint64_t offset = static_cast<std::uint64_t>(rva) - region.rva;
        if (offset + size <= region.size) { return reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uintptr_t>(region.memory) + static_cast<std::uintptr_t>(offset)); }
    }
    throw std::runtime_error("Source RVA is outside generated static regions: " + hex_u32(rva) + ", size=" + std::to_string(size));
}

std::uint32_t ProcessMemory::static_address(std::uint32_t rva) const { return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(region_pointer(rva))); }

std::uint32_t ProcessMemory::source_address(std::uint32_t source_va) const {
    if (source_va < kSourceImageBase || static_cast<std::uint64_t>(source_va) >= static_cast<std::uint64_t>(kSourceImageBase) + kImageSize) { throw std::runtime_error("Source image address is outside the generated address space: " + hex_u32(source_va)); }
    const std::uint32_t rva = source_va - kSourceImageBase;
    if (rva >= 0x00001000u && rva < 0x00001000u + 0x000FB200u) {
        const std::uint32_t callback = callback_address(rva);
        if (callback != 0u) { return callback; }
        if (is_static_table_rva(rva)) { return static_address(rva); }
        return kCodeTokenBase + rva;
    }
    if (source_va >= SFERA_RDATA_SOURCE_BEGIN && source_va < SFERA_RDATA_SOURCE_BEGIN + SFERA_RDATA_SOURCE_SIZE) { const std::uint32_t semantic = sfera_rdata_semantic_address(source_va); if (semantic != 0u) { return semantic; } throw std::runtime_error(source_va < SFERA_RDATA_SEMANTIC_BEGIN ? "Eliminated source IAT address escaped into data flow: " + hex_u32(source_va) : "Source .rdata address is outside semantic storage: " + hex_u32(source_va)); }
    if (source_va >= SFERA_DATA_SOURCE_BEGIN && source_va < SFERA_DATA_SOURCE_BEGIN + SFERA_DATA_SOURCE_SIZE) { return static_address(rva); }
    return static_address(rva);
}

bool ProcessMemory::source_rva(std::uint32_t address, std::uint32_t& rva) const noexcept {
    const std::uint32_t token_rva = address - kCodeTokenBase;
    if (token_rva >= 0x00001000u && token_rva < 0x00001000u + 0x000FB200u) { rva = token_rva; return true; }
    if (callback_rva(address, rva)) { return true; }
    { const std::uint32_t rdata_rva = sfera_rdata_source_rva(address); if (rdata_rva != UINT32_MAX) { rva = rdata_rva; return true; } }
    { const std::uint32_t data_rva = sfera_data_source_rva(address); if (data_rva != UINT32_MAX) { rva = data_rva; return true; } }
    for (const StaticRegion& region : regions_) {
        if (!region.memory) { continue; }
        const std::uint32_t begin = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(region.memory));
        if (address >= begin && static_cast<std::uint64_t>(address - begin) < region.size) { rva = region.rva + (address - begin); return true; }
    }
    return false;
}

bool ProcessMemory::is_static_table_rva(std::uint32_t rva) const noexcept {
    for (const StaticTableRegionDescriptor& region : kStaticTableRegions) { if (rva >= region.rva && static_cast<std::uint64_t>(rva - region.rva) < region.size) { return true; } }
    return false;
}

std::uint32_t ProcessMemory::callback_address(std::uint32_t rva) const noexcept {
    if (!callback_thunks_) { return 0u; }
    const auto found = std::lower_bound(kCallbacks.begin(), kCallbacks.end(), rva, [](const CallbackDescriptor& callback, std::uint32_t value) { return callback.rva < value; });
    if (found == kCallbacks.end() || found->rva != rva) { return 0u; }
    const std::size_t index = static_cast<std::size_t>(found - kCallbacks.begin());
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_ + index * kCallbackThunkSize));
}

bool ProcessMemory::callback_rva(std::uint32_t address, std::uint32_t& rva) const noexcept {
    if (!callback_thunks_) { return false; }
    const std::uint32_t begin = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_));
    if (address < begin || address - begin >= callback_thunks_size_) { return false; }
    const std::uint32_t offset = address - begin;
    if ((offset % kCallbackThunkSize) != 0u) { return false; }
    const std::size_t index = offset / kCallbackThunkSize;
    if (index >= kCallbacks.size()) { return false; }
    rva = kCallbacks[index].rva;
    return true;
}

const std::vector<ResolvedImport>& ProcessMemory::resolved_imports() const noexcept { return resolved_imports_; }

bool ProcessMemory::try_read(std::uint32_t address, void* value, std::size_t size) const noexcept { address = sfera_data_deref_range(address, static_cast<std::uint32_t>(size)); return value && safe_copy(value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), size); }
bool ProcessMemory::try_write(std::uint32_t address, const void* value, std::size_t size) noexcept { address = sfera_data_deref_range(address, static_cast<std::uint32_t>(size)); return value && safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value, size); }

void ProcessMemory::read(std::uint32_t address, void* value, std::size_t size) const {
    if (!value) { throw std::runtime_error("Local memory read has a null destination"); }
    address = sfera_data_deref_range(address, static_cast<std::uint32_t>(size));
    std::memcpy(value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), size);
}

void ProcessMemory::write(std::uint32_t address, const void* value, std::size_t size) {
    if (!value) { throw std::runtime_error("Local memory write has a null source"); }
    address = sfera_data_deref_range(address, static_cast<std::uint32_t>(size));
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value, size);
}

void ProcessMemory::allocate_static_regions() {
    if (sizeof(void*) != 4 || kMachine != IMAGE_FILE_MACHINE_I386) { throw std::runtime_error("Generated runtime requires Win32/x86"); }
    const std::uint32_t resource_size = align_up(std::max(kResourceVirtualSize, kResourceRawSize), 0x1000u);
    module_shell_size_ = kCompactResourceRva + resource_size;
    module_shell_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, module_shell_size_, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!module_shell_) { throw std::runtime_error(win32_error("VirtualAlloc(compact module shell)")); }
    callback_thunks_size_ = static_cast<std::uint32_t>(kCallbacks.size()) * kCallbackThunkSize;
    callback_thunks_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, callback_thunks_size_, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!callback_thunks_) { throw std::runtime_error(win32_error("VirtualAlloc(callback thunk pool)")); }
    owned_regions_.push_back(callback_thunks_);
    g_lift_callback_thunk_base = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_));
    {
        constexpr std::uint32_t kPage = 0x1000u;
        const std::uint32_t prefix = (kPage - (SFERA_RDATA_SEMANTIC_SIZE & (kPage - 1u))) & (kPage - 1u);
        rdata_commit_size_ = align_up(prefix + SFERA_RDATA_SEMANTIC_SIZE, kPage);
        const std::uint32_t reserve_size = rdata_commit_size_ + 2u * kPage;
        rdata_reservation_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, reserve_size, MEM_RESERVE, PAGE_NOACCESS));
        if (!rdata_reservation_) { throw std::runtime_error(win32_error("VirtualAlloc(rdata reserve)")); }
        rdata_commit_base_ = rdata_reservation_ + kPage;
        if (!VirtualAlloc(rdata_commit_base_, rdata_commit_size_, MEM_COMMIT, PAGE_READWRITE)) { throw std::runtime_error(win32_error("VirtualAlloc(rdata commit)")); }
        sfera_rdata_bind_storage(rdata_commit_base_ + prefix);
    }
    struct DataMappingPlan { std::uint32_t offset; std::uint32_t size; std::int32_t semantic_index; HANDLE backing; };
    std::vector<DataMappingPlan> data_plans;
    std::uint32_t data_cursor = 0u;
    for (std::uint32_t index = 0u; index < SFERA_DATA_SEMANTIC_SPAN_COUNT; ++index) {
        const std::uint32_t offset = g_sfera_data_semantic_span_source_begin[index] - SFERA_DATA_SOURCE_BEGIN;
        const std::uint32_t size = g_sfera_data_semantic_span_size[index];
        if (offset < data_cursor || offset + size > SFERA_DATA_STORAGE_SIZE) { throw std::runtime_error("Invalid semantic data-span layout"); }
        if (data_cursor < offset) { data_plans.push_back({data_cursor, offset - data_cursor, -1, nullptr}); }
        data_plans.push_back({offset, size, static_cast<std::int32_t>(index), nullptr});
        data_cursor = offset + size;
    }
    if (data_cursor < SFERA_DATA_STORAGE_SIZE) { data_plans.push_back({data_cursor, SFERA_DATA_STORAGE_SIZE - data_cursor, -1, nullptr}); }
    auto close_data_backings = [&]() noexcept { for (DataMappingPlan& plan : data_plans) { if (plan.backing) { CloseHandle(plan.backing); plan.backing = nullptr; } } };
    for (DataMappingPlan& plan : data_plans) {
        plan.backing = CreateFileMappingW(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0u, plan.size, nullptr);
        if (!plan.backing) { close_data_backings(); throw std::runtime_error(win32_error("CreateFileMappingW(data segment)")); }
    }
    for (std::uint32_t attempt = 0u; attempt < 8u && !data_compat_view_; ++attempt) {
        void* candidate = VirtualAlloc(nullptr, SFERA_DATA_STORAGE_SIZE, MEM_RESERVE, PAGE_NOACCESS);
        if (!candidate) { break; }
        VirtualFree(candidate, 0u, MEM_RELEASE);
        data_compat_segments_.clear();
        bool mapped = true;
        for (DataMappingPlan& plan : data_plans) {
            std::uint8_t* const target = reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uintptr_t>(candidate) + plan.offset);
            std::uint8_t* const view = static_cast<std::uint8_t*>(MapViewOfFileEx(plan.backing, FILE_MAP_ALL_ACCESS, 0u, 0u, plan.size, target));
            if (!view) { mapped = false; break; }
            data_compat_segments_.push_back(view);
        }
        if (!mapped) { for (std::uint8_t* view : data_compat_segments_) { if (view) { UnmapViewOfFile(view); } } data_compat_segments_.clear(); continue; }
        data_compat_view_ = static_cast<std::uint8_t*>(candidate);
    }
    if (!data_compat_view_) { close_data_backings(); throw std::runtime_error(win32_error("MapViewOfFileEx(data compatibility mosaic)")); }
    g_sfera_data_compat_base = data_compat_view_;
    for (DataMappingPlan& plan : data_plans) {
        if (plan.semantic_index < 0) { continue; }
        const std::uint32_t index = static_cast<std::uint32_t>(plan.semantic_index);
        g_sfera_data_semantic_spans[index] = static_cast<std::uint8_t*>(MapViewOfFile(plan.backing, FILE_MAP_ALL_ACCESS, 0u, 0u, plan.size));
        if (!g_sfera_data_semantic_spans[index]) { close_data_backings(); throw std::runtime_error(win32_error("MapViewOfFile(data semantic span)")); }
        const std::uint32_t first_page = (g_sfera_data_semantic_span_source_begin[index] - SFERA_DATA_SOURCE_BEGIN) >> SFERA_DATA_PAGE_SHIFT;
        const std::uint32_t page_count = g_sfera_data_semantic_span_size[index] >> SFERA_DATA_PAGE_SHIFT;
        for (std::uint32_t page = 0u; page < page_count; ++page) { g_sfera_data_semantic_page_alias[first_page + page] = g_sfera_data_semantic_spans[index] + page * SFERA_DATA_PAGE_SIZE; }
    }
    close_data_backings();
    regions_.clear();
    regions_.reserve(kStaticTableRegions.size() + 4u);
    regions_.push_back({0u, kHeadersSize, module_shell_, kRead, "headers", true});
    for (const StaticTableRegionDescriptor& region : kStaticTableRegions) { regions_.push_back({region.rva, region.size, g_sfera_static_table_storage + region.storage_offset, kRead, "semantic static table", false}); }
    regions_.push_back({SFERA_DATA_SOURCE_BEGIN - kSourceImageBase, SFERA_DATA_SOURCE_SIZE, data_compat_view_, kRead | kWrite, ".data compatibility view", false});
    regions_.push_back({kResourceSourceRva, std::max(kResourceVirtualSize, kResourceRawSize), module_shell_ + kCompactResourceRva, kRead, ".rsrc shell", true});
    g_lift_header_base = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(module_shell_));
    g_lift_rsrc_base = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(module_shell_ + kCompactResourceRva));
}
void ProcessMemory::install_initial_static_data() {
    for (const InitialStaticChunk& chunk : kInitialStaticChunks) {
        if ((chunk.hex.size() & 1u) != 0u) { throw std::runtime_error("Odd generated static-data chunk length"); }
        std::uint8_t* const destination = region_pointer(chunk.rva, chunk.hex.size() / 2u);
        for (std::size_t index = 0; index < chunk.hex.size(); index += 2u) { destination[index / 2u] = static_cast<std::uint8_t>((decode_hex_digit(chunk.hex[index]) << 4u) | decode_hex_digit(chunk.hex[index + 1u])); }
    }
}

void ProcessMemory::initialize_native() {
    try {
        install_callback_thunks(); apply_static_pointer_fixups(); verify_semantic_data_views(); patch_module_shell();
        { DiagnosticPhaseScope phase(RuntimePhase::load_imports); resolve_imports(); diagnostic_note("native imports resolved in the current process"); }
        { DiagnosticPhaseScope phase(RuntimePhase::protect_static_storage); protect_regions(); diagnostic_note("independent static-region protections applied"); }
        FlushInstructionCache(GetCurrentProcess(), callback_thunks_, callback_thunks_size_);
    } catch (...) { release(); throw; }
}

void ProcessMemory::resolve_imports() {
    std::unordered_map<std::string, HMODULE> modules;
    std::size_t import_index = 0u;
    for (const ImportDescriptor& item : kImports) {
        const std::string dll(item.dll); HMODULE module = nullptr; const auto found = modules.find(dll);
        if (found != modules.end()) { module = found->second; } else { module = LoadLibraryA(dll.c_str()); if (!module) { throw std::runtime_error(win32_error(("LoadLibraryA(" + dll + ")").c_str())); } modules.emplace(dll, module); loaded_modules_.push_back(module); }
        const char* symbol = item.by_ordinal ? reinterpret_cast<const char*>(static_cast<std::uintptr_t>(item.ordinal)) : item.name.data();
        FARPROC address = GetProcAddress(module, symbol);
        if (!address) { const std::string label = item.by_ordinal ? "ordinal " + std::to_string(item.ordinal) : std::string(item.name); throw std::runtime_error(win32_error(("GetProcAddress(" + dll + ", " + label + ")").c_str())); }
        const std::uint32_t value = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(address));
        if (import_index >= kImports.size()) { throw std::runtime_error("Resolved import index exceeds generated import table"); }
        g_sfera_import_addresses[import_index++] = value;
        resolved_imports_.push_back({&item, value});
    }
    if (import_index != kImports.size()) { throw std::runtime_error("Resolved import count does not match generated import table"); }
}


void ProcessMemory::apply_static_pointer_fixups() {
    for (const CallbackPointerFixup& fixup : kCallbackPointerFixups) {
        const std::uint32_t value = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback_thunks_ + static_cast<std::uint32_t>(fixup.callback_index) * kCallbackThunkSize));
        std::memcpy(region_pointer(fixup.slot_rva, sizeof(value)), &value, sizeof(value));
    }
    for (const RdataPointerFixup& fixup : kRdataPointerFixups) {
        const std::uint32_t value = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_rdata_semantic_storage + fixup.target_offset));
        std::memcpy(region_pointer(fixup.slot_rva, sizeof(value)), &value, sizeof(value));
    }
    for (const DataPointerFixup& fixup : kDataPointerFixups) {
        const std::uint32_t value = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_data_compat_base + fixup.target_offset));
        std::memcpy(region_pointer(fixup.slot_rva, sizeof(value)), &value, sizeof(value));
    }
}


void ProcessMemory::verify_semantic_data_views() const {
    if (!g_sfera_data_compat_base) { throw std::runtime_error("Data compatibility view is not initialized"); }
    for (std::uint32_t index = 0u; index < SFERA_DATA_SEMANTIC_SPAN_COUNT; ++index) {
        const std::uint8_t* const semantic = g_sfera_data_semantic_spans[index];
        if (!semantic) { throw std::runtime_error("Data semantic span is not initialized"); }
        const std::uint32_t source_begin = g_sfera_data_semantic_span_source_begin[index];
        const std::uint32_t size = g_sfera_data_semantic_span_size[index];
        const std::uint8_t* const compatibility = reinterpret_cast<const std::uint8_t*>(reinterpret_cast<std::uintptr_t>(g_sfera_data_compat_base) + (source_begin - SFERA_DATA_SOURCE_BEGIN));
        const std::uintptr_t semantic_begin = reinterpret_cast<std::uintptr_t>(semantic);
        const std::uintptr_t semantic_end = semantic_begin + size;
        const std::uintptr_t compatibility_begin = reinterpret_cast<std::uintptr_t>(compatibility);
        const std::uintptr_t compatibility_end = compatibility_begin + size;
        if (semantic_begin < compatibility_end && compatibility_begin < semantic_end) { throw std::runtime_error("Semantic and compatibility data views unexpectedly overlap"); }
        if (std::memcmp(semantic, compatibility, size) != 0) { throw std::runtime_error("Semantic data view is not coherent with compatibility backing"); }
    }
}

void ProcessMemory::patch_module_shell() {
    if (kHeadersSize < sizeof(IMAGE_DOS_HEADER) || module_shell_[0] != 'M' || module_shell_[1] != 'Z') { throw std::runtime_error("Invalid generated DOS header"); }
    auto* dos = reinterpret_cast<IMAGE_DOS_HEADER*>(module_shell_);
    if (dos->e_lfanew <= 0 || static_cast<std::uint32_t>(dos->e_lfanew) + sizeof(IMAGE_NT_HEADERS32) > kHeadersSize) { throw std::runtime_error("Invalid generated PE header offset"); }
    auto* nt = reinterpret_cast<IMAGE_NT_HEADERS32*>(module_shell_ + dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE || nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC) { throw std::runtime_error("Invalid generated PE optional header"); }
    const std::uint32_t old_resource_rva = kResourceSourceRva;
    const std::uint32_t resource_size = std::max(kResourceVirtualSize, kResourceRawSize);
    std::uint8_t* const resource_root = module_shell_ + kCompactResourceRva;
    auto rebase_directory = [&](auto&& self, std::uint32_t directory_offset, std::uint32_t depth) -> void {
        if (depth > 16u || directory_offset > resource_size || resource_size - directory_offset < sizeof(IMAGE_RESOURCE_DIRECTORY)) { throw std::runtime_error("Invalid generated resource directory"); }
        auto* directory = reinterpret_cast<IMAGE_RESOURCE_DIRECTORY*>(resource_root + directory_offset);
        const std::uint32_t count = static_cast<std::uint32_t>(directory->NumberOfNamedEntries) + static_cast<std::uint32_t>(directory->NumberOfIdEntries);
        const std::uint64_t entries_end = static_cast<std::uint64_t>(directory_offset) + sizeof(IMAGE_RESOURCE_DIRECTORY) + static_cast<std::uint64_t>(count) * sizeof(IMAGE_RESOURCE_DIRECTORY_ENTRY);
        if (entries_end > resource_size) { throw std::runtime_error("Generated resource directory entries are outside .rsrc"); }
        auto* entries = reinterpret_cast<IMAGE_RESOURCE_DIRECTORY_ENTRY*>(directory + 1);
        for (std::uint32_t index = 0; index < count; ++index) {
            const std::uint32_t raw = entries[index].OffsetToData;
            const std::uint32_t child = raw & 0x7FFFFFFFu;
            if ((raw & 0x80000000u) != 0u) { self(self, child, depth + 1u); continue; }
            if (child > resource_size || resource_size - child < sizeof(IMAGE_RESOURCE_DATA_ENTRY)) { throw std::runtime_error("Generated resource data entry is outside .rsrc"); }
            auto* data = reinterpret_cast<IMAGE_RESOURCE_DATA_ENTRY*>(resource_root + child);
            if (data->OffsetToData >= old_resource_rva && data->OffsetToData < old_resource_rva + resource_size) { data->OffsetToData = kCompactResourceRva + (data->OffsetToData - old_resource_rva); }
        }
    };
    rebase_directory(rebase_directory, 0u, 0u);
    IMAGE_SECTION_HEADER* const first_section = IMAGE_FIRST_SECTION(nt);
    IMAGE_SECTION_HEADER* resource_section = nullptr;
    for (std::uint16_t index = 0; index < nt->FileHeader.NumberOfSections; ++index) {
        IMAGE_SECTION_HEADER* const section = first_section + index;
        char name[9]{}; std::memcpy(name, section->Name, 8u);
        if (std::string_view(name) == ".rsrc") { resource_section = section; break; }
    }
    if (!resource_section) { throw std::runtime_error("Generated PE resource section header is missing"); }
    IMAGE_SECTION_HEADER compact_resource = *resource_section;
    compact_resource.VirtualAddress = kCompactResourceRva;
    compact_resource.Misc.VirtualSize = kResourceVirtualSize;
    compact_resource.SizeOfRawData = kResourceRawSize;
    compact_resource.PointerToRawData = 0u;
    *first_section = compact_resource;
    nt->FileHeader.NumberOfSections = 1u;
    nt->OptionalHeader.ImageBase = load_base();
    nt->OptionalHeader.AddressOfEntryPoint = 0u;
    nt->OptionalHeader.BaseOfCode = 0u;
    nt->OptionalHeader.BaseOfData = kCompactResourceRva;
    nt->OptionalHeader.SizeOfCode = 0u;
    nt->OptionalHeader.SizeOfInitializedData = resource_size;
    nt->OptionalHeader.SizeOfUninitializedData = 0u;
    nt->OptionalHeader.SizeOfImage = module_shell_size_;
    for (std::uint32_t index = 0; index < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; ++index) { nt->OptionalHeader.DataDirectory[index] = {}; }
    nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_RESOURCE].VirtualAddress = kCompactResourceRva;
    nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_RESOURCE].Size = resource_size;
}

void ProcessMemory::install_callback_thunks() {
    if (!callback_thunks_ || callback_thunks_size_ != kCallbacks.size() * kCallbackThunkSize) { throw std::runtime_error("Callback thunk pool is not initialized"); }
    const std::uintptr_t bridge = reinterpret_cast<std::uintptr_t>(&callback_bridge);
    for (std::size_t index = 0; index < kCallbacks.size(); ++index) {
        std::uint8_t* const thunk = callback_thunks_ + index * kCallbackThunkSize;
        thunk[0] = 0x68u;
        const std::uint32_t target = kCodeTokenBase + kCallbacks[index].rva;
        std::memcpy(thunk + 1, &target, sizeof(target));
        thunk[5] = 0xE9u;
        const std::intptr_t delta = static_cast<std::intptr_t>(bridge - reinterpret_cast<std::uintptr_t>(thunk + kCallbackThunkSize));
        if (delta < std::numeric_limits<std::int32_t>::min() || delta > std::numeric_limits<std::int32_t>::max()) { throw std::runtime_error("Callback bridge is outside rel32 range"); }
        const std::int32_t relative = static_cast<std::int32_t>(delta);
        std::memcpy(thunk + 6, &relative, sizeof(relative));
    }
    DWORD old_protection = 0;
    if (!VirtualProtect(callback_thunks_, callback_thunks_size_, PAGE_EXECUTE_READ, &old_protection)) { throw std::runtime_error(win32_error("VirtualProtect(callback thunk pool)")); }
}

void ProcessMemory::protect_regions() {
    for (const StaticRegion& region : regions_) {
        if (!region.protect) { continue; }
        DWORD old_protection = 0;
        DWORD protection = page_protection(region.access);
        if (!VirtualProtect(region.memory, region.size, protection, &old_protection)) { throw std::runtime_error(win32_error(("VirtualProtect(" + std::string(region.name ? region.name : "region") + ")").c_str())); }
    }
    if (rdata_commit_base_ && rdata_commit_size_) {
        DWORD old_protection = 0;
        if (!VirtualProtect(rdata_commit_base_, rdata_commit_size_, PAGE_READONLY, &old_protection)) { throw std::runtime_error(win32_error("VirtualProtect(semantic rdata)")); }
    }
}

void ProcessMemory::release() noexcept {
    if (g_process_memory == this) { g_process_memory = nullptr; }
    resolved_imports_.clear(); for (auto iterator = loaded_modules_.rbegin(); iterator != loaded_modules_.rend(); ++iterator) { if (*iterator) { FreeLibrary(*iterator); } } loaded_modules_.clear();
    for (std::uint32_t page = 0u; page < SFERA_DATA_PAGE_COUNT; ++page) { g_sfera_data_semantic_page_alias[page] = nullptr; }
    for (std::uint32_t index = 0u; index < SFERA_DATA_SEMANTIC_SPAN_COUNT; ++index) {
        if (g_sfera_data_semantic_spans[index]) { UnmapViewOfFile(g_sfera_data_semantic_spans[index]); g_sfera_data_semantic_spans[index] = nullptr; }
    }
    for (std::uint8_t* view : data_compat_segments_) { if (view) { UnmapViewOfFile(view); } }
    data_compat_segments_.clear();
    data_compat_view_ = nullptr;
    g_sfera_data_compat_base = nullptr;
    callback_thunks_ = nullptr; callback_thunks_size_ = 0;
    sfera_rdata_bind_storage(nullptr);
    if (rdata_reservation_) { VirtualFree(rdata_reservation_, 0, MEM_RELEASE); rdata_reservation_ = nullptr; rdata_commit_base_ = nullptr; rdata_commit_size_ = 0; }
    for (void* memory : owned_regions_) { if (memory) { VirtualFree(memory, 0, MEM_RELEASE); } } owned_regions_.clear();
    if (module_shell_) { VirtualFree(module_shell_, 0, MEM_RELEASE); module_shell_ = nullptr; }
    regions_.clear(); module_shell_size_ = 0;
    g_lift_header_base = 0; g_lift_rsrc_base = 0; g_lift_callback_thunk_base = 0;
}

namespace {

void initialize_fs(LiftCpu& state) {
    const std::uint32_t end_of_chain = 0xFFFFFFFFu;
    const std::uint32_t teb = __readfsdword(0x18);
    const std::uint32_t peb = __readfsdword(0x30);
    std::memcpy(state.fs_data, &end_of_chain, sizeof(end_of_chain));
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
    NativeCallFrame cdecl_frame{&state, reinterpret_cast<void*>(&bridge_test_cdecl), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, 0.0};
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
    NativeCallFrame stdcall_frame{&state, reinterpret_cast<void*>(&bridge_test_stdcall), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, 0.0};
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
    NativeCallFrame fastcall_frame{&state, reinterpret_cast<void*>(&bridge_test_fastcall), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, 0.0};
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
    std::size_t import_index = 0u;
    for (const ResolvedImport& item : memory_.resolved_imports()) {
        if (import_index >= import_addresses_.size()) { throw std::runtime_error("Resolved import table is larger than generated import metadata"); }
        std::size_t slot = ((item.address >> 4u) * UINT32_C(2654435761)) & (kImportLookupSize - 1u);
        while (import_lookup_addresses_[slot] != 0u && import_lookup_addresses_[slot] != item.address) { slot = (slot + 1u) & (kImportLookupSize - 1u); }
        if (import_lookup_addresses_[slot] == 0u) { import_lookup_addresses_[slot] = item.address; import_lookup_descriptors_[slot] = item.descriptor; }
        import_addresses_[import_index++] = item.address;
    }
    if (import_index != import_addresses_.size()) { throw std::runtime_error("Generated import table and loaded import table disagree: resolved=" + std::to_string(import_index) + ", generated=" + std::to_string(import_addresses_.size())); }
    lift_initialize_dispatch();
    diagnostic_note("native C function map initialized");
}


const ImportDescriptor* NativeRuntime::find_import(std::uint32_t target) const {
    std::size_t slot = ((target >> 4u) * UINT32_C(2654435761)) & (kImportLookupSize - 1u);
    for (std::size_t probe = 0u; probe != kImportLookupSize; ++probe) { const std::uint32_t address = import_lookup_addresses_[slot]; if (address == target) { return import_lookup_descriptors_[slot]; } if (address == 0u) { return nullptr; } slot = (slot + 1u) & (kImportLookupSize - 1u); }
    return nullptr;
}

std::uint32_t NativeRuntime::import_address(std::uint32_t index) const {
    if (index >= import_addresses_.size()) { throw std::runtime_error("Generated import index " + std::to_string(index) + " is outside fixed import table size " + std::to_string(import_addresses_.size())); }
    return import_addresses_[index];
}

void NativeRuntime::call_import(LiftCpu& state, std::uint32_t index, std::uint32_t callsite) {
    if (index >= import_addresses_.size()) { throw std::runtime_error("Generated import index " + std::to_string(index) + " is outside fixed import table size " + std::to_string(import_addresses_.size()) + " at " + hex_u32(callsite)); }
    call_native_resolved(state, import_addresses_[index], callsite, &kImports[index]);
}

void NativeRuntime::call_native(LiftCpu& state, std::uint32_t target, std::uint32_t callsite) {
    call_native_resolved(state, target, callsite, find_import(target));
}

void NativeRuntime::call_native_resolved(LiftCpu& state, std::uint32_t target, std::uint32_t callsite, const ImportDescriptor* descriptor) {
    if (target == 0u) { throw std::runtime_error("Invalid native call target 0x00000000"); }
    if (!descriptor) { NativeCallFrame frame{&state, reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, 0.0}; native_call_bridge_fast(&frame); return; }
    const std::string_view name = descriptor->name;
    if (name == "_CxxThrowException" || name == "RaiseException") { throw std::runtime_error("SEH/C++ exception crossed the lifted/native ABI boundary at " + hex_u32(callsite)); }
    if ((name == "GetModuleHandleA" || name == "GetModuleHandleW") && memory_read<std::uint32_t>(state.esp) == 0u) { state.eax = memory_.load_base(); state.esp += 4u; return; }
    if ((name == "GetModuleFileNameA" || name == "GetModuleFileNameW") && (memory_read<std::uint32_t>(state.esp) == 0u || memory_read<std::uint32_t>(state.esp) == memory_.load_base())) {
        const std::uint32_t buffer = memory_read<std::uint32_t>(state.esp + 4u);
        const std::uint32_t capacity = memory_read<std::uint32_t>(state.esp + 8u);
        state.eax = name == "GetModuleFileNameW" ? write_local_path(buffer, capacity, client_executable_path()) : write_local_path(buffer, capacity, client_executable_path_ansi());
        state.esp += 12u;
        return;
    }
    if (name == "_CIatan2" || name == "_CIpow") { require_x87(&state, 2); state.fpu[1] = name == "_CIpow" ? std::pow(state.fpu[1], state.fpu[0]) : std::atan2(state.fpu[1], state.fpu[0]); lift_x87_pop(&state); return; }
    if (name == "_CIacos" || name == "_CIasin" || name == "_CIatan" || name == "_CIcos" || name == "_CIexp" || name == "_CIsin" || name == "_CIsqrt" || name == "_CItan") {
        require_x87(&state, 1);
        const double value = state.fpu[0];
        if (name == "_CIacos") { state.fpu[0] = std::acos(value); } else if (name == "_CIasin") { state.fpu[0] = std::asin(value); } else if (name == "_CIatan") { state.fpu[0] = std::atan(value); } else if (name == "_CIcos") { state.fpu[0] = std::cos(value); } else if (name == "_CIexp") { state.fpu[0] = std::exp(value); } else if (name == "_CIsin") { state.fpu[0] = std::sin(value); } else if (name == "_CIsqrt") { state.fpu[0] = std::sqrt(value); } else { state.fpu[0] = std::tan(value); }
        return;
    }
    NativeCallArguments arguments(state.esp);
    if (descriptor && descriptor->process_module_argument >= 0) {
        const std::uint8_t argument = static_cast<std::uint8_t>(descriptor->process_module_argument);
        const std::uint32_t image_handle = arguments.read(argument);
        const std::uint32_t native_handle = process_module_handle();
        if (native_handle != image_handle) { arguments.alias(argument, image_handle, native_handle); }
    }
    NativeCallFrame frame{&state, reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, 0.0};
    const bool float_return = is_float_return(name);
    if (float_return) { native_call_bridge(&frame); lift_x87_push(&state, frame.native_st0); } else { native_call_bridge_fast(&frame); }
}

extern "C" void __cdecl lift_import_call(LiftCpu* cpu, std::uint32_t import_index, std::uint32_t callsite) {
    if (!g_runtime || !cpu) { throw std::runtime_error("Import call without an active native runtime"); }
    g_runtime->call_import(*cpu, import_index, callsite);
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
    const std::uint32_t target = registers.callback_target;
    const std::uint32_t original_esp = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&registers.callback_target) + sizeof(registers.callback_target));
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
    state.eax = registers.eax; state.ecx = registers.ecx; state.edx = registers.edx; state.ebx = registers.ebx; state.esp = clone_esp; state.ebp = registers.ebp; state.esi = registers.esi; state.edi = registers.edi; state.eip = target; state.eflags = registers.eflags;
    state.fpu_control = 0x027Fu;
    state.stack_base = clone.base(); state.stack_limit = clone.limit();
    initialize_fs(state);
    lift_dispatch(&state, target, LIFT_CALLBACK_SENTINEL);
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
        MessageBoxA(nullptr, error.what(), "Native C callback failure", MB_OK | MB_ICONERROR);
        TerminateProcess(GetCurrentProcess(), 0xE0000002u);
    }
}

#if defined(SFERA_PORTABLE_CHECK)

extern "C" void __cdecl native_call_bridge(NativeCallFrame*) {}
extern "C" void __cdecl native_call_bridge_fast(NativeCallFrame*) {}
extern "C" void callback_bridge() {}

#elif defined(_M_IX86)

static_assert(offsetof(LiftCpu, eax) == 0 && offsetof(LiftCpu, eflags) == 36 && offsetof(LiftCpu, fpu_control) == 114);
static_assert(offsetof(LiftCpu, fs_data) == 120);
static_assert(offsetof(NativeCallFrame, state) == 0 && offsetof(NativeCallFrame, native_st0) == 40);
static_assert(offsetof(CallbackRegisters, edi) == 0 && offsetof(CallbackRegisters, eax) == 28 && offsetof(CallbackRegisters, eflags) == 32 && offsetof(CallbackRegisters, callback_target) == 36);
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
        fninit
        mov eax, [edx]
        fldcw word ptr [eax + 114]
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
        fst qword ptr [edx + 40]
        mov ecx, [edx]
        fnstcw word ptr [ecx + 114]
        fninit
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

extern "C" __declspec(naked) void __cdecl native_call_bridge_fast(NativeCallFrame*) {
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
        mov ebx, offset native_bridge_fast_return
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
    native_bridge_fast_return:
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
