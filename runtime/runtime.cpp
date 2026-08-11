#include "runtime.h"
#include "diagnostics.h"

#include <intrin.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cwchar>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <string_view>

#if defined(_MSC_VER)
#pragma intrinsic(__readfsdword)
#endif

namespace lifted {

NativeRuntime* g_runtime = nullptr;
ProcessMemory* g_process_memory = nullptr;

namespace {

constexpr std::size_t kCallbackStackCopy = 64u * 1024u;
constexpr wchar_t kClientRootEnvironment[] = L"SFERA_CLIENT_ROOT";
constexpr wchar_t kDeepDiagnosticsEnvironment[] = L"SFERA_NATIVE_DEEP_TRACE";
bool g_deep_diagnostics = false;

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

std::uint32_t local_image_address(std::uint32_t source_va) {
    if (!g_process_memory) { throw std::runtime_error("Process memory is not initialized"); }
    return g_process_memory->source_address(source_va);
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

void set_logic_flags(LiftCpu& state, std::uint64_t result, std::uint16_t width) noexcept {
    assign_flag(state, LIFT_FLAG_CF, false);
    assign_flag(state, LIFT_FLAG_OF, false);
    assign_flag(state, LIFT_FLAG_AF, false);
    set_szp(state, result, width);
}

void set_add_flags(LiftCpu& state, std::uint64_t left, std::uint64_t right, std::uint64_t carry, std::uint64_t result, std::uint16_t width) noexcept {
    const std::uint64_t mask = width_mask(width);
    const std::uint64_t left_value = left & mask;
    const std::uint64_t right_value = right & mask;
    const std::uint64_t partial = (left_value + right_value) & mask;
    const std::uint64_t truncated = result & mask;
    assign_flag(state, LIFT_FLAG_CF, partial < left_value || (carry != 0 && truncated < partial));
    assign_flag(state, LIFT_FLAG_OF, ((~(left_value ^ right_value) & (left_value ^ truncated)) & sign_bit(width)) != 0);
    assign_flag(state, LIFT_FLAG_AF, ((left_value ^ right_value ^ truncated) & 0x10u) != 0);
    set_szp(state, truncated, width);
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

extern "C" std::uint32_t __cdecl lift_image_va(std::uint32_t source_va) { return local_image_address(source_va); }
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

extern "C" void __cdecl lift_flags_add(LiftCpu* cpu, std::uint64_t left, std::uint64_t right, std::uint64_t carry, std::uint64_t result, std::uint32_t width) { set_add_flags(*cpu, left, right, carry, result, static_cast<std::uint16_t>(width)); }
extern "C" void __cdecl lift_flags_sub(LiftCpu* cpu, std::uint64_t left, std::uint64_t right, std::uint64_t borrow, std::uint64_t result, std::uint32_t width) { set_sub_flags(*cpu, left, right, borrow, result, static_cast<std::uint16_t>(width)); }
extern "C" void __cdecl lift_flags_logic(LiftCpu* cpu, std::uint64_t result, std::uint32_t width) { set_logic_flags(*cpu, result, static_cast<std::uint16_t>(width)); }

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
    const std::int32_t delta = flag(*cpu, LIFT_FLAG_DF) ? -static_cast<std::int32_t>(sizeof(T)) : static_cast<std::int32_t>(sizeof(T));
    while (count-- != 0) { memory_write(cpu->edi, memory_read<T>(cpu->esi)); cpu->esi += delta; cpu->edi += delta; if (repeated) { --cpu->ecx; } }
}
template <class T>
void store_string(LiftCpu* cpu, bool repeated) {
    std::uint32_t count = repeated ? cpu->ecx : 1u;
    const std::int32_t delta = flag(*cpu, LIFT_FLAG_DF) ? -static_cast<std::int32_t>(sizeof(T)) : static_cast<std::int32_t>(sizeof(T));
    while (count-- != 0) { memory_write(cpu->edi, static_cast<T>(cpu->eax)); cpu->edi += delta; if (repeated) { --cpu->ecx; } }
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

extern "C" void __cdecl lift_enter_block(LiftCpu* cpu, std::uint32_t source_va) { cpu->eip = local_image_address(source_va); set_diagnostic_instruction(cpu->eip, "native-c"); }
extern "C" LIFT_NORETURN void __cdecl lift_trap(LiftCpu* cpu, std::uint32_t source_va, const char* reason) { lift_enter_block(cpu, source_va); throw std::runtime_error(std::string("Lifted C trap at ") + hex_u32(cpu->eip) + ": " + (reason ? reason : "unknown")); }

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
    DiagnosticPhaseScope phase(RuntimePhase::map_image);
    map();
    g_process_memory = this;
    const std::string note = "local image mapped at " + hex_u32(load_base()) + " from source base " + hex_u32(kSourceImageBase);
    diagnostic_note(note.c_str());
}

ProcessMemory::~ProcessMemory() {
    release();
}

std::uint32_t ProcessMemory::load_base() const noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(image_));
}

std::uint32_t ProcessMemory::entry_va() const noexcept {
    return load_base() + kEntryRva;
}

std::uint32_t ProcessMemory::image_address(std::uint32_t rva) const {
    if (!image_ || rva >= kImageSize) { throw std::runtime_error("Image RVA is outside local process memory: " + hex_u32(rva)); }
    return load_base() + rva;
}

std::uint32_t ProcessMemory::source_address(std::uint32_t source_va) const {
    if (source_va < kSourceImageBase || static_cast<std::uint64_t>(source_va) >= static_cast<std::uint64_t>(kSourceImageBase) + kImageSize) { throw std::runtime_error("Source image address is outside the generated image: " + hex_u32(source_va)); }
    return image_address(source_va - kSourceImageBase);
}

bool ProcessMemory::image_rva(std::uint32_t address, std::uint32_t& rva) const noexcept {
    if (!image_ || address < load_base() || static_cast<std::uint64_t>(address) >= static_cast<std::uint64_t>(load_base()) + kImageSize) { return false; }
    rva = address - load_base();
    return true;
}

std::uint8_t* ProcessMemory::data() noexcept {
    return image_;
}

const std::vector<ResolvedImport>& ProcessMemory::resolved_imports() const noexcept {
    return resolved_imports_;
}

bool ProcessMemory::try_read(std::uint32_t address, void* value, std::size_t size) const noexcept {
    return value && safe_copy(value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), size);
}

bool ProcessMemory::try_write(std::uint32_t address, const void* value, std::size_t size) noexcept {
    return value && safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value, size);
}

void ProcessMemory::read(std::uint32_t address, void* value, std::size_t size) const {
    if (!value) { throw std::runtime_error("Local memory read has a null destination"); }
    if (!g_deep_diagnostics) { std::memcpy(value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), size); return; }
    if (!try_read(address, value, size)) { throw std::runtime_error("Local process read fault at " + hex_u32(address) + ", size=" + std::to_string(size)); }
}

void ProcessMemory::write(std::uint32_t address, const void* value, std::size_t size) {
    if (!value) { throw std::runtime_error("Local memory write has a null source"); }
    if (!g_deep_diagnostics) { std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value, size); return; }
    if (!try_write(address, value, size)) { throw std::runtime_error("Local process write fault at " + hex_u32(address) + ", size=" + std::to_string(size)); }
    std::uint64_t diagnostic_value = 0;
    std::memcpy(&diagnostic_value, value, std::min(size, sizeof(diagnostic_value)));
    diagnostic_memory_write(address, static_cast<std::uint32_t>(size), diagnostic_value);
}

void ProcessMemory::map() {
    if (sizeof(void*) != 4 || kMachine != IMAGE_FILE_MACHINE_I386) { throw std::runtime_error("Generated runtime requires Win32/x86"); }
    image_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, kImageSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!image_) { throw std::runtime_error(win32_error("VirtualAlloc(local image)")); }
    try {
        map_file();
    } catch (...) {
        release();
        throw;
    }
}

void ProcessMemory::initialize_native() {
    try {
        install_recovered_data();
        install_jump_tables();
        apply_relocations();
        patch_image_base();
        install_callback_stubs();
        {
            DiagnosticPhaseScope phase(RuntimePhase::load_imports);
            resolve_imports();
            diagnostic_note("native imports resolved in the current process");
        }
        {
            DiagnosticPhaseScope phase(RuntimePhase::protect_image);
            protect_image();
            diagnostic_note("local image protections applied");
        }
        FlushInstructionCache(GetCurrentProcess(), image_, kImageSize);
    } catch (...) {
        release();
        throw;
    }
}

void ProcessMemory::map_file() {
    const std::vector<std::uint8_t> file = decode_mapped_payload();
    if (kHeadersSize > file.size() || kHeadersSize > kImageSize) { throw std::runtime_error("Invalid generated PE headers"); }
    std::memcpy(image_, file.data(), kHeadersSize);
    for (const SectionDescriptor& section : kSections) {
        const std::uint64_t source_end = static_cast<std::uint64_t>(section.raw_offset) + section.raw_size;
        const std::uint64_t target_end = static_cast<std::uint64_t>(section.virtual_address) + std::max(section.virtual_size, section.raw_size);
        if (source_end > file.size() || target_end > kImageSize) { throw std::runtime_error("Invalid generated PE section range"); }
        if ((section.access & kExecute) == 0 && section.raw_size != 0) { std::memcpy(image_ + section.virtual_address, file.data() + section.raw_offset, section.raw_size); }
    }
}

void ProcessMemory::resolve_imports() {
    std::unordered_map<std::string, HMODULE> modules;
    for (const ImportDescriptor& item : kImports) {
        const std::string dll(item.dll);
        HMODULE module = nullptr;
        const auto found = modules.find(dll);
        if (found != modules.end()) { module = found->second; }
        else {
            module = LoadLibraryA(dll.c_str());
            if (!module) { throw std::runtime_error(win32_error(("LoadLibraryA(" + dll + ")").c_str())); }
            modules.emplace(dll, module);
            loaded_modules_.push_back(module);
        }
        const char* symbol = item.by_ordinal ? reinterpret_cast<const char*>(static_cast<std::uintptr_t>(item.ordinal)) : item.name.data();
        FARPROC address = GetProcAddress(module, symbol);
        if (!address) {
            const std::string label = item.by_ordinal ? "ordinal " + std::to_string(item.ordinal) : std::string(item.name);
            throw std::runtime_error(win32_error(("GetProcAddress(" + dll + ", " + label + ")").c_str()));
        }
        const std::uint32_t value = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(address));
        std::memcpy(image_ + item.iat_rva, &value, sizeof(value));
        resolved_imports_.push_back({&item, value});
    }
}

void ProcessMemory::install_recovered_data() {
    for (const RecoveredDataDescriptor& range : kRecoveredData) {
        if ((range.hex.size() & 1u) != 0u || range.rva + range.hex.size() / 2u > kImageSize) { throw std::runtime_error("Invalid recovered lookup-data range"); }
        for (std::size_t index = 0; index < range.hex.size(); index += 2u) { image_[range.rva + index / 2u] = static_cast<std::uint8_t>((decode_hex_digit(range.hex[index]) << 4u) | decode_hex_digit(range.hex[index + 1u])); }
    }
}

void ProcessMemory::install_jump_tables() {
    for (const JumpTableDescriptor& entry : kJumpTableEntries) { std::memcpy(image_ + entry.rva, &entry.target, sizeof(entry.target)); }
}

void ProcessMemory::apply_relocations() {
    for (const RelocationDescriptor& relocation : kLocalRelocations) {
        if (relocation.rva + sizeof(std::uint32_t) > kImageSize) { throw std::runtime_error("Invalid local relocation RVA " + hex_u32(relocation.rva)); }
        std::uint32_t source_va = 0;
        std::memcpy(&source_va, image_ + relocation.rva, sizeof(source_va));
        const std::uint32_t local_va = source_address(source_va);
        std::memcpy(image_ + relocation.rva, &local_va, sizeof(local_va));
    }
}

void ProcessMemory::patch_image_base() {
    if (kHeadersSize < 0x40u || image_[0] != 'M' || image_[1] != 'Z') { throw std::runtime_error("Invalid mapped DOS header"); }
    std::uint32_t pe_offset = 0;
    std::memcpy(&pe_offset, image_ + 0x3Cu, sizeof(pe_offset));
    const std::uint64_t image_base_offset = static_cast<std::uint64_t>(pe_offset) + 24u + 28u;
    if (image_base_offset + sizeof(std::uint32_t) > kHeadersSize) { throw std::runtime_error("Invalid mapped PE optional header"); }
    const std::uint32_t local_base = load_base();
    std::memcpy(image_ + image_base_offset, &local_base, sizeof(local_base));
}

void ProcessMemory::install_callback_stubs() {
    const std::uintptr_t bridge = reinterpret_cast<std::uintptr_t>(&callback_bridge);
    for (const CallbackDescriptor& callback : kCallbacks) {
        std::uint8_t* const source = image_ + callback.rva;
        const std::intptr_t delta = static_cast<std::intptr_t>(bridge - reinterpret_cast<std::uintptr_t>(source + 5));
        if (delta < std::numeric_limits<std::int32_t>::min() || delta > std::numeric_limits<std::int32_t>::max()) { throw std::runtime_error("Callback bridge is outside rel32 range"); }
        source[0] = 0xE8u;
        const std::int32_t relative = static_cast<std::int32_t>(delta);
        std::memcpy(source + 1, &relative, sizeof(relative));
    }
}

void ProcessMemory::protect_image() {
    constexpr std::uint32_t page_size = 0x1000u;
    auto protect = [this](std::uint32_t rva, std::uint32_t size, DWORD protection) {
        if (size == 0) { return; }
        const std::uint32_t begin = align_down(rva, page_size);
        const std::uint32_t end = align_up(rva + size, page_size);
        DWORD old_protection = 0;
        if (end > kImageSize || !VirtualProtect(image_ + begin, end - begin, protection, &old_protection)) { throw std::runtime_error(win32_error("VirtualProtect(section)")); }
    };
    protect(0, kHeadersSize, PAGE_READONLY);
    for (const SectionDescriptor& section : kSections) { protect(section.virtual_address, std::max(section.virtual_size, section.raw_size), page_protection(section.access)); }
}

void ProcessMemory::release() noexcept {
    if (g_process_memory == this) { g_process_memory = nullptr; }
    resolved_imports_.clear();
    for (auto iterator = loaded_modules_.rbegin(); iterator != loaded_modules_.rend(); ++iterator) { if (*iterator) { FreeLibrary(*iterator); } }
    loaded_modules_.clear();
    if (image_) { VirtualFree(image_, 0, MEM_RELEASE); image_ = nullptr; }
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
    import_addresses_.reserve(memory_.resolved_imports().size());
    for (const ResolvedImport& item : memory_.resolved_imports()) {
        imports_by_address_.try_emplace(item.address, item.descriptor);
        import_addresses_.push_back(item.address);
    }
    if (import_addresses_.size() != kImports.size()) { throw std::runtime_error("Generated import table and loaded import table disagree"); }
    diagnostic_note("native C function map initialized");
}

ProcessMemory& NativeRuntime::memory() noexcept {
    return memory_;
}

const ImportDescriptor* NativeRuntime::find_import(std::uint32_t target) const {
    const auto found = imports_by_address_.find(target);
    return found == imports_by_address_.end() ? nullptr : found->second;
}

std::uint32_t NativeRuntime::import_address(std::uint32_t index) const {
    if (index >= import_addresses_.size()) { throw std::runtime_error("Generated import index is outside the resolved import table"); }
    return import_addresses_[index];
}

void NativeRuntime::call_native(LiftCpu& state, std::uint32_t target, std::uint32_t callsite) {
    const ImportDescriptor* descriptor = find_import(target);
    const std::string_view name = descriptor ? descriptor->name : std::string_view{};
    DiagnosticPhaseScope phase(RuntimePhase::native_call);
    DiagnosticNativeScope native_scope(target, descriptor ? descriptor->name.data() : nullptr);
    MEMORY_BASIC_INFORMATION target_region{};
    const DWORD executable_protection = PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;
    if (target == 0 || VirtualQuery(reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), &target_region, sizeof(target_region)) == 0 || target_region.State != MEM_COMMIT || (target_region.Protect & executable_protection) == 0 || (target_region.Protect & (PAGE_GUARD | PAGE_NOACCESS)) != 0) { throw std::runtime_error("Invalid native call target " + hex_u32(target)); }
    if (name == "_CxxThrowException" || name == "RaiseException") { throw std::runtime_error("SEH/C++ exception crossed the lifted/native ABI boundary at " + hex_u32(callsite)); }
    if ((name == "GetModuleHandleA" || name == "GetModuleHandleW") && memory_read<std::uint32_t>(state.esp) == 0) {
        state.eax = memory_.load_base();
        state.esp += 4u;
        return;
    }
    if ((name == "GetModuleFileNameA" || name == "GetModuleFileNameW") && (memory_read<std::uint32_t>(state.esp) == 0 || memory_read<std::uint32_t>(state.esp) == memory_.load_base())) {
        const std::uint32_t buffer = memory_read<std::uint32_t>(state.esp + 4u);
        const std::uint32_t capacity = memory_read<std::uint32_t>(state.esp + 8u);
        state.eax = name == "GetModuleFileNameW" ? write_local_path(buffer, capacity, client_executable_path()) : write_local_path(buffer, capacity, client_executable_path_ansi());
        state.esp += 12u;
        const std::string note = "virtualized " + std::string(name) + ": " + narrow_path(client_executable_path());
        diagnostic_note(note.c_str());
        return;
    }
    if (name == "_CIatan2" || name == "_CIpow") {
        require_x87(&state, 2);
        state.fpu[1] = name == "_CIpow" ? std::pow(state.fpu[1], state.fpu[0]) : std::atan2(state.fpu[1], state.fpu[0]);
        lift_x87_pop(&state);
        return;
    }
    if (name == "_CIacos" || name == "_CIasin" || name == "_CIatan" || name == "_CIcos" || name == "_CIexp" || name == "_CIsin" || name == "_CIsqrt" || name == "_CItan") {
        require_x87(&state, 1);
        const double value = state.fpu[0];
        if (name == "_CIacos") { state.fpu[0] = std::acos(value); }
        else if (name == "_CIasin") { state.fpu[0] = std::asin(value); }
        else if (name == "_CIatan") { state.fpu[0] = std::atan(value); }
        else if (name == "_CIcos") { state.fpu[0] = std::cos(value); }
        else if (name == "_CIexp") { state.fpu[0] = std::exp(value); }
        else if (name == "_CIsin") { state.fpu[0] = std::sin(value); }
        else if (name == "_CIsqrt") { state.fpu[0] = std::sqrt(value); }
        else { state.fpu[0] = std::tan(value); }
        return;
    }
    std::string resource_note;
    if (name == "_findfirst64i32") { resource_note = "resource enumeration callsite=" + hex_u32(callsite) + ", pattern=\"" + local_c_string(memory_read<std::uint32_t>(state.esp)) + "\""; }
    else if (name == "fopen") { resource_note = "resource fopen callsite=" + hex_u32(callsite) + ", path=\"" + local_c_string(memory_read<std::uint32_t>(state.esp)) + "\", mode=\"" + local_c_string(memory_read<std::uint32_t>(state.esp + 4u)) + "\""; }
    NativeCallArguments arguments(state.esp);
    std::string module_note;
    if (descriptor && descriptor->process_module_argument >= 0) {
        const std::uint8_t argument = static_cast<std::uint8_t>(descriptor->process_module_argument);
        const std::uint32_t image_handle = arguments.read(argument);
        const std::uint32_t native_handle = process_module_handle();
        if (native_handle != image_handle) { arguments.alias(argument, image_handle, native_handle); }
        module_note = "module identity import=" + std::string(name) + ", argument=" + std::to_string(argument) + ", image=" + hex_u32(image_handle) + ", process=" + hex_u32(native_handle);
        if (name == "DirectInput8Create") { module_note += ", version=" + hex_u32(arguments.read(1)) + ", iid=" + hex_u32(arguments.read(2)) + ", output=" + hex_u32(arguments.read(3)) + ", outer=" + hex_u32(arguments.read(4)); }
    }
    NativeCallFrame frame{&state, reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, 0.0};
    native_call_bridge(&frame);
    if (name == "_findnext64i32" && state.eax == 0xFFFFFFFFu) { resource_note = "resource enumeration complete"; }
    if (!resource_note.empty()) { resource_note += ", result=" + hex_u32(state.eax); diagnostic_note(resource_note.c_str()); }
    if (!module_note.empty()) { module_note += ", result=" + hex_u32(state.eax); diagnostic_note(module_note.c_str()); }
    if (descriptor && is_float_return(name)) { lift_x87_push(&state, frame.native_st0); }
}

extern "C" void __cdecl lift_import_call(LiftCpu* cpu, std::uint32_t import_index, std::uint32_t callsite) {
    if (!g_runtime || !cpu) { throw std::runtime_error("Import call without an active native runtime"); }
    g_runtime->call_native(*cpu, g_runtime->import_address(import_index), callsite);
}

extern "C" void __cdecl lift_native_call(LiftCpu* cpu, std::uint32_t target, std::uint32_t callsite) {
    if (!g_runtime || !cpu) { throw std::runtime_error("Native call without an active native runtime"); }
    g_runtime->call_native(*cpu, target, callsite);
}

extern "C" void __cdecl lift_note_config_lookup(std::uint32_t key_address, std::uint32_t value_address) {
    const std::string key = local_c_string(key_address, 160u);
    if (key.rfind("NEW_FONT_", 0) != 0) { return; }
    std::string note = "normalized config lookup key=\"" + key + "\"";
    note += value_address == 0 ? ", result=missing" : ", value=\"" + local_c_string(value_address, 160u) + "\"";
    diagnostic_note(note.c_str());
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
    DiagnosticPhaseScope phase(RuntimePhase::callback);
    const std::uint32_t target = registers.stub_return - 5u;
    const std::uint32_t original_esp = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&registers.stub_return) + sizeof(registers.stub_return));
    const std::uint32_t api_return = memory_read<std::uint32_t>(original_esp);
    MEMORY_BASIC_INFORMATION region{};
    if (VirtualQuery(reinterpret_cast<void*>(static_cast<std::uintptr_t>(original_esp)), &region, sizeof(region)) == 0 || region.State != MEM_COMMIT) { throw std::runtime_error("Unable to inspect native callback stack"); }
    const std::uintptr_t region_end = reinterpret_cast<std::uintptr_t>(region.BaseAddress) + region.RegionSize;
    const std::size_t available = region_end > original_esp ? region_end - original_esp : 0;
    const std::size_t copy_size = std::min(kCallbackStackCopy, available);
    if (copy_size < 64u) { throw std::runtime_error("Native callback stack window is too small"); }
    LocalStack clone(std::max<std::size_t>(kStackReserve, 1024u * 1024u));
    const std::uint32_t clone_esp = clone.top() - static_cast<std::uint32_t>(copy_size);
    if (!safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(clone_esp)), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(original_esp)), copy_size)) { throw std::runtime_error("Unable to clone native callback arguments"); }
    memory_write(clone_esp, LIFT_CALLBACK_SENTINEL);
    LiftCpu state{};
    state.eax = registers.eax; state.ecx = registers.ecx; state.edx = registers.edx; state.ebx = registers.ebx; state.esp = clone_esp; state.ebp = registers.ebp; state.esi = registers.esi; state.edi = registers.edi; state.eip = target; state.eflags = registers.eflags;
    state.fpu_control = 0x027Fu;
    state.stack_base = clone.base(); state.stack_limit = clone.limit();
    initialize_fs(state);
    DiagnosticRunScope run_scope(&state);
    DiagnosticExecutionScope execution_scope(target, LIFT_CALLBACK_SENTINEL, state.esp);
    lift_dispatch(&state, target, LIFT_CALLBACK_SENTINEL);
    const std::uint32_t stack_delta = state.esp - clone_esp;
    if (stack_delta < 4u || stack_delta > copy_size) { throw std::runtime_error("Lifted callback returned an invalid stack delta"); }
    if (copy_size > 4u) { safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(original_esp + 4u)), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(clone_esp + 4u)), copy_size - 4u); }
    const std::uint32_t destination = original_esp + stack_delta;
    memory_write(destination - 8u, state.eax);
    memory_write(destination - 4u, api_return);
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
extern "C" void callback_bridge() {}

#elif defined(_M_IX86)

static_assert(offsetof(LiftCpu, eax) == 0 && offsetof(LiftCpu, eflags) == 36 && offsetof(LiftCpu, fpu_control) == 114);
static_assert(offsetof(LiftCpu, fs_data) == 248);
static_assert(offsetof(NativeCallFrame, state) == 0 && offsetof(NativeCallFrame, native_st0) == 40);
static_assert(offsetof(CallbackRegisters, edi) == 0 && offsetof(CallbackRegisters, eax) == 28 && offsetof(CallbackRegisters, eflags) == 32 && offsetof(CallbackRegisters, stub_return) == 36);
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
        mov ecx, [eax + 248]
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
    g_deep_diagnostics = GetEnvironmentVariableW(kDeepDiagnosticsEnvironment, nullptr, 0) != 0;
    diagnostic_note(g_deep_diagnostics ? "generated C execution: deep diagnostics" : "generated C execution: fast");
    NativeRuntime runtime;
    return runtime.execute();
}

} // namespace lifted
