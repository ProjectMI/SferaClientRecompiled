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

Runtime* g_runtime = nullptr;

namespace {

constexpr std::size_t kCallbackStackCopy = 64u * 1024u;
constexpr wchar_t kGuestRootEnvironment[] = L"SFERA_GUEST_ROOT";
constexpr wchar_t kDeepDiagnosticsEnvironment[] = L"SFERA_IR_DEEP_TRACE";
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

bool is_guest_root(const std::wstring& path) noexcept {
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

std::wstring wide_guest_filename() {
    return std::wstring(kGuestExecutableName.begin(), kGuestExecutableName.end());
}

std::wstring guest_executable_path() {
    return path_join(guest_root_directory(), wide_guest_filename());
}

std::string guest_executable_path_ansi() {
    const std::wstring wide = guest_executable_path();
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
    return safe_copy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), sizeof(T));
}

template <class T>
T memory_read(std::uint32_t address) {
    T value{};
    if (!g_deep_diagnostics) { std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), sizeof(T)); return value; }
    if (!try_memory_read(address, value)) { throw std::runtime_error("Guest read fault at " + hex_u32(address) + ", size=" + std::to_string(sizeof(T))); }
    return value;
}

template <class T>
void memory_write(std::uint32_t address, T value) {
    if (!g_deep_diagnostics) { std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), &value, sizeof(T)); return; }
    if (!safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), &value, sizeof(T))) { throw std::runtime_error("Guest write fault at " + hex_u32(address) + ", size=" + std::to_string(sizeof(T))); }
    std::uint64_t diagnostic_value = 0;
    std::memcpy(&diagnostic_value, &value, std::min(sizeof(value), sizeof(diagnostic_value)));
    diagnostic_guest_write(address, static_cast<std::uint32_t>(sizeof(T)), diagnostic_value);
}

class NativeCallArguments {
public:
    explicit NativeCallArguments(std::uint32_t stack) noexcept : stack_(stack) {}
    NativeCallArguments(const NativeCallArguments&) = delete;
    NativeCallArguments& operator=(const NativeCallArguments&) = delete;
    ~NativeCallArguments() { while (patch_count_ != 0) { const Patch& patch = patches_[--patch_count_]; safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(patch.address)), &patch.original, sizeof(patch.original)); } }
    std::uint32_t read(std::uint8_t index) const { return memory_read<std::uint32_t>(stack_ + static_cast<std::uint32_t>(index) * 4u); }
    void alias(std::uint8_t index, std::uint32_t expected, std::uint32_t replacement) {
        const std::uint32_t address = stack_ + static_cast<std::uint32_t>(index) * 4u;
        const std::uint32_t original = memory_read<std::uint32_t>(address);
        if (original != expected) { throw std::runtime_error("Native argument changed before aliasing"); }
        if (patch_count_ == patches_.size()) { throw std::runtime_error("Too many native argument aliases"); }
        if (!safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), &replacement, sizeof(replacement))) { throw std::runtime_error("Unable to alias native argument at " + hex_u32(address)); }
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

std::string guest_c_string(std::uint32_t address, std::size_t limit = 2048u) noexcept {
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

std::size_t guest_string_length(std::uint32_t address, std::size_t limit) {
    if (address == 0) { throw std::runtime_error("Null guest string"); }
    for (std::size_t length = 0; length != limit; ++length) {
        if (memory_read<char>(address + static_cast<std::uint32_t>(length)) == '\0') { return length; }
    }
    throw std::runtime_error("Unterminated guest string at " + hex_u32(address));
}

bool guest_string_starts_with(std::uint32_t address, std::string_view prefix) {
    if (address == 0) { return false; }
    for (std::size_t index = 0; index != prefix.size(); ++index) {
        if (memory_read<char>(address + static_cast<std::uint32_t>(index)) != prefix[index]) { return false; }
    }
    return true;
}

std::uint32_t summarized_config_lookup(std::uint32_t key_address) {
    const std::uint32_t text_address = memory_read<std::uint32_t>(kConfigTextPointerAddress);
    const std::uint32_t text_length = memory_read<std::uint32_t>(kConfigTextLengthAddress);
    if (text_address == 0) { return 0; }
    const std::size_t key_length = guest_string_length(key_address, 4096u);
    const std::size_t scan_limit = static_cast<std::size_t>(std::min(text_length, kConfigTextCapacity)) + 1u;
    if (static_cast<std::uint64_t>(text_address) + scan_limit > 0x100000000ull) { throw std::runtime_error("Guest config text crosses the Win32 address boundary"); }
    const auto text_at = [text_address](std::size_t offset) {
        return memory_read<char>(text_address + static_cast<std::uint32_t>(offset));
    };
    const auto key_at = [key_address](std::size_t offset) {
        return memory_read<char>(key_address + static_cast<std::uint32_t>(offset));
    };

    std::size_t line = 0;
    while (line < scan_limit) {
        std::size_t token_end = line;
        while (token_end < scan_limit) {
            const char value = text_at(token_end);
            if (value == ' ' || value == '\t' || value == '\r' || value == '\0') { break; }
            ++token_end;
        }

        bool matches = token_end - line == key_length;
        for (std::size_t index = 0; matches && index != key_length; ++index) {
            matches = text_at(line + index) == key_at(index);
        }
        if (matches) {
            std::size_t value = token_end;
            while (value < scan_limit && (text_at(value) == ' ' || text_at(value) == '\t')) { ++value; }
            if (value < scan_limit) { return text_address + static_cast<std::uint32_t>(value); }
            return 0;
        }

        std::size_t next_line = token_end;
        while (next_line < scan_limit && text_at(next_line) != '\n' && text_at(next_line) != '\0') { ++next_line; }
        if (next_line == scan_limit || text_at(next_line) == '\0') { return 0; }
        line = next_line + 1u;
    }
    return 0;
}

void summarize_unsigned_decimal_string(CpuState& state) {
    const std::uint32_t destination = state.ecx;
    std::uint32_t value = memory_read<std::uint32_t>(state.edx);
    std::array<char, 16> reversed{};
    std::size_t length = 0;
    do {
        reversed[length++] = static_cast<char>('0' + value % 10u);
        value /= 10u;
    } while (value != 0);

    for (std::size_t index = 0; index != 16u; ++index) {
        const char output = index < length ? reversed[length - index - 1u] : '\0';
        memory_write(destination + static_cast<std::uint32_t>(index), output);
    }
    memory_write(destination + 0x10u, static_cast<std::uint32_t>(length));
    memory_write(destination + 0x14u, 15u);
    state.eax = destination;
}

bool execute_semantic_summary(CpuState& state, std::uint32_t callsite, std::uint32_t target) {
    if (kConfigLookupTarget != 0 && kConfigTextPointerAddress != 0 && kConfigTextLengthAddress != 0 && kConfigTextCapacity != 0 && target == kConfigLookupTarget) {
        const std::uint32_t key_address = memory_read<std::uint32_t>(state.esp);
        state.eax = summarized_config_lookup(key_address);
        state.esp += 4u; // The lifted function returns with ret 4.
        if (guest_string_starts_with(key_address, "NEW_FONT_")) {
            const std::string key = guest_c_string(key_address, 160u);
            std::string note = "semantic config lookup key=\"" + key + "\"";
            note += state.eax == 0 ? ", result=missing" : ", value=\"" + guest_c_string(state.eax, 160u) + "\"";
            diagnostic_note(note.c_str());
        }
        return true;
    }
    if (kUnsignedDecimalStringTarget != 0 && target == kUnsignedDecimalStringTarget && callsite == kUnsignedDecimalStringCallsite) {
        summarize_unsigned_decimal_string(state);
        return true; // The lifted function uses a plain ret.
    }
    return false;
}

template <class Char>
std::uint32_t write_guest_path(std::uint32_t address, std::uint32_t capacity, const std::basic_string<Char>& path) {
    if (address == 0 || capacity == 0) { SetLastError(ERROR_INSUFFICIENT_BUFFER); return 0; }
    const std::size_t copy_count = std::min<std::size_t>(path.size(), static_cast<std::size_t>(capacity - 1u));
    std::vector<Char> output(copy_count + 1u, Char{});
    std::copy_n(path.data(), copy_count, output.data());
    const std::size_t byte_count = output.size() * sizeof(Char);
    if (!safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), output.data(), byte_count)) { throw std::runtime_error("Guest write fault at " + hex_u32(address) + ", size=" + std::to_string(byte_count)); }
    diagnostic_guest_write(address, static_cast<std::uint32_t>(byte_count), 0);
    if (copy_count != path.size()) { SetLastError(ERROR_INSUFFICIENT_BUFFER); return capacity; }
    return static_cast<std::uint32_t>(path.size());
}

std::string fatal_handler_failure(const CpuState& state, std::uint32_t callsite) {
    const std::string fatal_text = guest_c_string(state.ecx);
    std::string message = "Guest fatal handler trap: call=" + hex_u32(callsite) + ", message-address=" + hex_u32(state.ecx) + ", message=\"" + fatal_text + "\"";
    if (fatal_text.rfind("Can't load font", 0) == 0) { message += ", last-config-key=\"" + guest_c_string(0x006BE618u, 160u) + "\""; }
    std::uint32_t quick_file = 0;
    std::int16_t loaded_files = -1;
    if (try_memory_read(0x04016680u, quick_file) && quick_file != 0 && try_memory_read(quick_file + 0x20C98u, loaded_files)) { message += ", loaded-mbc-files=" + std::to_string(loaded_files) + ", quick-file=" + hex_u32(quick_file); }
    message += ", guest-root=\"" + narrow_path(guest_root_directory()) + "\"";
    return message;
}

void append_write_origin(std::string& message, std::string_view label, std::uint32_t address) {
    GuestWriteInfo origin{};
    message += ", " + std::string(label) + "=" + hex_u32(address);
    if (diagnostic_last_guest_write(address, origin)) { message += "{writer=" + hex_u32(origin.instruction) + ",write=" + hex_u32(origin.address) + ",size=" + std::to_string(origin.size) + ",value=" + hex_u32(static_cast<std::uint32_t>(origin.value)) + "}"; }
    else { message += "{writer=unobserved}"; }
}

void append_mbc_provenance(std::string& message, std::uint32_t callsite) {
    if (callsite != 0x0047670Cu) { return; }
    std::uint32_t cursor = 0;
    std::uint32_t mbc_base = 0;
    std::uint32_t mbc_pointer = 0;
    if (!try_memory_read(0x0401661Cu, cursor) || !try_memory_read(0x04B5FE78u, mbc_base) || !try_memory_read(0x006BE2D4u, mbc_pointer) || cursor == 0 || cursor > 0x10000u) { return; }
    const std::uint32_t token = 0x0401A688u + (cursor - 1u) * 32u;
    std::uint32_t token_type = 0;
    std::uint32_t source_offset = 0;
    std::uint32_t token_value = 0;
    if (!try_memory_read(token, token_type) || !try_memory_read(token + 0x0Cu, source_offset) || !try_memory_read(token + 0x14u, token_value)) { return; }
    message += ", mbc={cursor=" + std::to_string(cursor) + ",token=" + hex_u32(token) + ",type=" + hex_u32(token_type) + ",offset=" + hex_u32(source_offset) + ",value=" + hex_u32(token_value) + ",base=" + hex_u32(mbc_base) + ",ip=" + hex_u32(mbc_pointer) + "}";
    append_write_origin(message, "token-origin", token + 0x14u);
    const std::uint64_t source_address = static_cast<std::uint64_t>(mbc_base) + source_offset;
    if ((token_type == 0x10u || token_type == 0x20u) && source_address <= 0xFFFFFFFFu) {
        std::uint32_t source_value = 0;
        if (try_memory_read(static_cast<std::uint32_t>(source_address), source_value)) { message += ", variable-value=" + hex_u32(source_value); }
        append_write_origin(message, "variable-origin", static_cast<std::uint32_t>(source_address));
    }
}

std::string bound_check_failure(const CpuState& state, std::uint32_t callsite, std::uint32_t target) {
    const char* kind = target == 0x00401120u ? "upper" : "lower";
    std::string message = std::string("Guest BoundCheckArray ") + kind + "-bound trap: call=" + hex_u32(callsite) + ", index=" + std::to_string(static_cast<std::int32_t>(state.edx)) + " (" + hex_u32(state.edx) + "), metadata=" + hex_u32(state.ecx);
    std::uint32_t array_data = 0;
    std::uint32_t array_count = 0;
    std::uint32_t source_line = 0;
    if (state.ecx >= 8u && try_memory_read(state.ecx - 8u, array_data) && try_memory_read(state.ecx - 4u, array_count)) { message += ", data=" + hex_u32(array_data) + ", count=" + std::to_string(array_count); }
    if (state.ecx != 0 && state.ecx <= 0xFFFFFFDFu && try_memory_read(state.ecx + 0x20u, source_line)) { message += ", source-line=" + std::to_string(source_line); }
    append_mbc_provenance(message, callsite);
    return message;
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

void assign_flag(CpuState& state, std::uint32_t flag, bool value) noexcept {
    state.eflags = value ? state.eflags | flag : state.eflags & ~flag;
}

bool flag(const CpuState& state, std::uint32_t value) noexcept {
    return (state.eflags & value) != 0;
}

void set_szp(CpuState& state, std::uint64_t result, std::uint16_t width) noexcept {
    result &= width_mask(width);
    assign_flag(state, kFlagSF, (result & sign_bit(width)) != 0);
    assign_flag(state, kFlagZF, result == 0);
    assign_flag(state, kFlagPF, even_parity(static_cast<std::uint8_t>(result)));
}

void set_logic_flags(CpuState& state, std::uint64_t result, std::uint16_t width) noexcept {
    assign_flag(state, kFlagCF, false);
    assign_flag(state, kFlagOF, false);
    assign_flag(state, kFlagAF, false);
    set_szp(state, result, width);
}

void set_add_flags(CpuState& state, std::uint64_t left, std::uint64_t right, std::uint64_t carry, std::uint64_t result, std::uint16_t width) noexcept {
    const std::uint64_t mask = width_mask(width);
    const std::uint64_t left_value = left & mask;
    const std::uint64_t right_value = right & mask;
    const std::uint64_t partial = (left_value + right_value) & mask;
    const std::uint64_t truncated = result & mask;
    assign_flag(state, kFlagCF, partial < left_value || (carry != 0 && truncated < partial));
    assign_flag(state, kFlagOF, ((~(left_value ^ right_value) & (left_value ^ truncated)) & sign_bit(width)) != 0);
    assign_flag(state, kFlagAF, ((left_value ^ right_value ^ truncated) & 0x10u) != 0);
    set_szp(state, truncated, width);
}

void set_sub_flags(CpuState& state, std::uint64_t left, std::uint64_t right, std::uint64_t borrow, std::uint64_t result, std::uint16_t width) noexcept {
    const std::uint64_t mask = width_mask(width);
    const std::uint64_t left_value = left & mask;
    const std::uint64_t right_value = right & mask;
    const std::uint64_t truncated = result & mask;
    assign_flag(state, kFlagCF, left_value < right_value || (borrow != 0 && left_value == right_value));
    assign_flag(state, kFlagOF, (((left_value ^ right_value) & (left_value ^ truncated)) & sign_bit(width)) != 0);
    assign_flag(state, kFlagAF, ((left_value ^ right_value ^ truncated) & 0x10u) != 0);
    set_szp(state, truncated, width);
}

std::uint32_t& full_register(CpuState& state, Reg reg) {
    switch (reg) {
        case Reg::eax: case Reg::ax: case Reg::al: case Reg::ah: return state.eax;
        case Reg::ecx: case Reg::cx: case Reg::cl: case Reg::ch: return state.ecx;
        case Reg::edx: case Reg::dx: case Reg::dl: case Reg::dh: return state.edx;
        case Reg::ebx: case Reg::bx: case Reg::bl: case Reg::bh: return state.ebx;
        case Reg::esp: case Reg::sp: return state.esp;
        case Reg::ebp: case Reg::bp: return state.ebp;
        case Reg::esi: case Reg::si: return state.esi;
        case Reg::edi: case Reg::di: return state.edi;
        default: throw std::runtime_error("Register has no 32-bit storage");
    }
}

std::uint64_t read_register(CpuState& state, Reg reg) {
    switch (reg) {
        case Reg::al: case Reg::cl: case Reg::dl: case Reg::bl: return full_register(state, reg) & 0xFFu;
        case Reg::ah: case Reg::ch: case Reg::dh: case Reg::bh: return (full_register(state, reg) >> 8u) & 0xFFu;
        case Reg::ax: case Reg::cx: case Reg::dx: case Reg::bx: case Reg::sp: case Reg::bp: case Reg::si: case Reg::di: return full_register(state, reg) & 0xFFFFu;
        case Reg::eax: case Reg::ecx: case Reg::edx: case Reg::ebx: case Reg::esp: case Reg::ebp: case Reg::esi: case Reg::edi: return full_register(state, reg);
        case Reg::cs: return 0x1Bu;
        case Reg::ds: case Reg::es: case Reg::ss: return 0x23u;
        case Reg::fs: return 0x3Bu;
        case Reg::gs: return 0u;
        case Reg::none: return 0u;
        default: throw std::runtime_error("Unsupported integer register read");
    }
}

void write_register(CpuState& state, Reg reg, std::uint64_t value) {
    switch (reg) {
        case Reg::al: case Reg::cl: case Reg::dl: case Reg::bl: {
            std::uint32_t& target = full_register(state, reg);
            target = (target & 0xFFFFFF00u) | static_cast<std::uint8_t>(value);
            return;
        }
        case Reg::ah: case Reg::ch: case Reg::dh: case Reg::bh: {
            std::uint32_t& target = full_register(state, reg);
            target = (target & 0xFFFF00FFu) | ((static_cast<std::uint32_t>(value) & 0xFFu) << 8u);
            return;
        }
        case Reg::ax: case Reg::cx: case Reg::dx: case Reg::bx: case Reg::sp: case Reg::bp: case Reg::si: case Reg::di: {
            std::uint32_t& target = full_register(state, reg);
            target = (target & 0xFFFF0000u) | (static_cast<std::uint32_t>(value) & 0xFFFFu);
            return;
        }
        case Reg::eax: case Reg::ecx: case Reg::edx: case Reg::ebx: case Reg::esp: case Reg::ebp: case Reg::esi: case Reg::edi: full_register(state, reg) = static_cast<std::uint32_t>(value); return;
        case Reg::cs: case Reg::ds: case Reg::es: case Reg::ss: case Reg::fs: case Reg::gs: return;
        default: throw std::runtime_error("Unsupported integer register write");
    }
}

std::uint32_t effective_address(CpuState& state, const OperandDescriptor& operand) {
    const std::uint64_t base = read_register(state, operand.base);
    const std::uint64_t index = read_register(state, operand.index);
    return static_cast<std::uint32_t>(base + index * operand.scale + operand.value);
}

std::uint64_t fs_read(CpuState& state, std::uint32_t offset, std::uint16_t width) {
    const std::size_t size = width / 8u;
    if (offset + size > state.fs_data.size()) { throw std::runtime_error("Guest FS read outside virtual TEB"); }
    std::uint64_t value = 0;
    std::memcpy(&value, state.fs_data.data() + offset, size);
    return value;
}

void fs_write(CpuState& state, std::uint32_t offset, std::uint16_t width, std::uint64_t value) {
    const std::size_t size = width / 8u;
    if (offset + size > state.fs_data.size()) { throw std::runtime_error("Guest FS write outside virtual TEB"); }
    std::memcpy(state.fs_data.data() + offset, &value, size);
}

std::uint64_t read_operand(CpuState& state, const OperandDescriptor& operand) {
    if (operand.kind == OperandKind::reg) { return read_register(state, operand.reg) & width_mask(operand.width); }
    if (operand.kind == OperandKind::imm || operand.kind == OperandKind::branch) { return operand.value & width_mask(operand.width); }
    if (operand.kind != OperandKind::mem) { throw std::runtime_error("Instruction reads an empty operand"); }
    const std::uint32_t address = effective_address(state, operand);
    if (operand.segment == Reg::fs) { return fs_read(state, address, operand.width); }
    switch (operand.width) {
        case 8: return memory_read<std::uint8_t>(address);
        case 16: return memory_read<std::uint16_t>(address);
        case 32: return memory_read<std::uint32_t>(address);
        case 64: return memory_read<std::uint64_t>(address);
        default: throw std::runtime_error("Unsupported integer memory width " + std::to_string(operand.width));
    }
}

void write_operand(CpuState& state, const OperandDescriptor& operand, std::uint64_t value) {
    value &= width_mask(operand.width);
    if (operand.kind == OperandKind::reg) { write_register(state, operand.reg, value); return; }
    if (operand.kind != OperandKind::mem) { throw std::runtime_error("Instruction writes a non-writable operand"); }
    const std::uint32_t address = effective_address(state, operand);
    if (operand.segment == Reg::fs) { fs_write(state, address, operand.width, value); return; }
    switch (operand.width) {
        case 8: memory_write(address, static_cast<std::uint8_t>(value)); return;
        case 16: memory_write(address, static_cast<std::uint16_t>(value)); return;
        case 32: memory_write(address, static_cast<std::uint32_t>(value)); return;
        case 64: memory_write(address, static_cast<std::uint64_t>(value)); return;
        default: throw std::runtime_error("Unsupported integer memory width " + std::to_string(operand.width));
    }
}

std::array<std::uint8_t, 16>& xmm_register(CpuState& state, Reg reg) {
    const int index = static_cast<int>(reg) - static_cast<int>(Reg::xmm0);
    if (index < 0 || index >= static_cast<int>(state.xmm.size())) { throw std::runtime_error("Invalid XMM register"); }
    return state.xmm[static_cast<std::size_t>(index)];
}

std::array<std::uint8_t, 16> read_vector(CpuState& state, const OperandDescriptor& operand) {
    if (operand.kind == OperandKind::reg) { return xmm_register(state, operand.reg); }
    if (operand.kind != OperandKind::mem) { throw std::runtime_error("Unsupported SIMD source operand"); }
    std::array<std::uint8_t, 16> value{};
    const std::uint32_t address = effective_address(state, operand);
    if (!g_deep_diagnostics) { std::memcpy(value.data(), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), value.size()); return value; }
    if (!safe_copy(value.data(), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)), value.size())) { throw std::runtime_error("Guest SIMD read fault at " + hex_u32(address)); }
    return value;
}

void write_vector(CpuState& state, const OperandDescriptor& operand, const std::array<std::uint8_t, 16>& value) {
    if (operand.kind == OperandKind::reg) { xmm_register(state, operand.reg) = value; return; }
    if (operand.kind != OperandKind::mem) { throw std::runtime_error("Unsupported SIMD destination operand"); }
    const std::uint32_t address = effective_address(state, operand);
    if (!g_deep_diagnostics) { std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value.data(), value.size()); return; }
    if (!safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)), value.data(), value.size())) { throw std::runtime_error("Guest SIMD write fault at " + hex_u32(address)); }
}

double read_scalar_double(CpuState& state, const OperandDescriptor& operand) {
    if (operand.kind == OperandKind::mem) { return memory_read<double>(effective_address(state, operand)); }
    const auto& value = xmm_register(state, operand.reg);
    double result = 0;
    std::memcpy(&result, value.data(), sizeof(result));
    return result;
}

void push32(CpuState& state, std::uint32_t value) {
    state.esp -= 4u;
    memory_write(state.esp, value);
}

std::uint32_t pop32(CpuState& state) {
    const std::uint32_t value = memory_read<std::uint32_t>(state.esp);
    state.esp += 4u;
    return value;
}

int st_index(Reg reg) noexcept {
    switch (reg) {
        case Reg::st0: return 0;
        case Reg::st1: return 1;
        case Reg::st2: return 2;
        case Reg::st3: return 3;
        case Reg::st4: return 4;
        case Reg::st5: return 5;
        case Reg::st6: return 6;
        case Reg::st7: return 7;
        default: return -1;
    }
}

void fpu_require(const CpuState& state, std::size_t count = 1) {
    if (state.fpu_depth < count) { throw std::runtime_error("x87 stack underflow"); }
}

void fpu_push(CpuState& state, double value) {
    if (state.fpu_depth == state.fpu.size()) { throw std::runtime_error("x87 stack overflow"); }
    for (std::size_t index = state.fpu_depth; index > 0; --index) { state.fpu[index] = state.fpu[index - 1]; }
    state.fpu[0] = value;
    state.fpu_top = static_cast<std::uint8_t>((state.fpu_top + 7u) & 7u);
    ++state.fpu_depth;
}

void fpu_pop(CpuState& state) {
    fpu_require(state);
    for (std::size_t index = 1; index < state.fpu_depth; ++index) { state.fpu[index - 1] = state.fpu[index]; }
    --state.fpu_depth;
    state.fpu_top = static_cast<std::uint8_t>((state.fpu_top + 1u) & 7u);
}

double& fpu_register(CpuState& state, Reg reg) {
    const int index = st_index(reg);
    if (index < 0 || index >= state.fpu_depth) { throw std::runtime_error("Invalid x87 register"); }
    return state.fpu[static_cast<std::size_t>(index)];
}

double read_float_memory(CpuState& state, const OperandDescriptor& operand) {
    const std::uint32_t address = effective_address(state, operand);
    if (operand.width == 32) { return static_cast<double>(memory_read<float>(address)); }
    if (operand.width == 64) { return memory_read<double>(address); }
    throw std::runtime_error("Unsupported x87 floating memory width");
}

void write_float_memory(CpuState& state, const OperandDescriptor& operand, double value) {
    const std::uint32_t address = effective_address(state, operand);
    if (operand.width == 32) { memory_write(address, static_cast<float>(value)); return; }
    if (operand.width == 64) { memory_write(address, value); return; }
    throw std::runtime_error("Unsupported x87 floating memory width");
}

double read_float_operand(CpuState& state, const OperandDescriptor& operand) {
    if (operand.kind == OperandKind::reg) { return fpu_register(state, operand.reg); }
    if (operand.kind == OperandKind::mem) { return read_float_memory(state, operand); }
    throw std::runtime_error("Unsupported x87 source operand");
}

void write_float_operand(CpuState& state, const OperandDescriptor& operand, double value) {
    if (operand.kind == OperandKind::reg) { fpu_register(state, operand.reg) = value; return; }
    if (operand.kind == OperandKind::mem) { write_float_memory(state, operand, value); return; }
    throw std::runtime_error("Unsupported x87 destination operand");
}

std::int64_t rounded_integer(double value, std::uint16_t control, bool truncate) {
    if (truncate) { return static_cast<std::int64_t>(std::trunc(value)); }
    switch ((control >> 10u) & 3u) {
        case 1: return static_cast<std::int64_t>(std::floor(value));
        case 2: return static_cast<std::int64_t>(std::ceil(value));
        case 3: return static_cast<std::int64_t>(std::trunc(value));
        default: return static_cast<std::int64_t>(std::nearbyint(value));
    }
}

void fpu_compare(CpuState& state, double left, double right) {
    state.fpu_status &= static_cast<std::uint16_t>(~(0x0100u | 0x0400u | 0x4000u));
    if (std::isnan(left) || std::isnan(right)) { state.fpu_status |= 0x4500u; }
    else if (left < right) { state.fpu_status |= 0x0100u; }
    else if (left == right) { state.fpu_status |= 0x4000u; }
}

bool is_float_return(std::string_view name) {
    return name == "atof" || name == "floor" || name == "ceil" || name == "frexp" || name == "ldexp" || name == "fmod";
}

} // namespace

const std::wstring& guest_root_directory() {
    static const std::wstring root = [] {
        const std::wstring configured = environment_path(kGuestRootEnvironment);
        if (!configured.empty()) {
            if (!is_guest_root(configured)) { throw std::runtime_error("SFERA_GUEST_ROOT does not contain mbc\\_main.mbc: " + narrow_path(configured)); }
            return configured;
        }
        std::vector<std::wstring> candidates;
        add_candidate_with_parents(candidates, current_directory());
        add_candidate_with_parents(candidates, parent_directory(host_executable_path()));
        for (const std::wstring& candidate : candidates) {
            if (is_guest_root(candidate)) { return candidate; }
        }
        throw std::runtime_error("Unable to locate mbc\\_main.mbc. Set SFERA_GUEST_ROOT to the original client directory that contains the mbc folder.");
    }();
    return root;
}

void configure_guest_environment() {
    const std::wstring& root = guest_root_directory();
    if (!SetCurrentDirectoryW(root.c_str())) { throw std::runtime_error(win32_error("SetCurrentDirectoryW")); }
    const std::string note = "guest resource root: " + narrow_path(root);
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

GuestStack::GuestStack(std::size_t reserve_size) : size_(std::max<std::size_t>(reserve_size, 1024u * 1024u)) {
    memory_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, size_, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!memory_) { throw std::runtime_error(win32_error("VirtualAlloc(guest stack)")); }
}

GuestStack::~GuestStack() {
    if (memory_) { VirtualFree(memory_, 0, MEM_RELEASE); }
}

std::uint32_t GuestStack::top() const noexcept {
    const std::uintptr_t value = reinterpret_cast<std::uintptr_t>(memory_ + size_ - 64u);
    return static_cast<std::uint32_t>(value & ~std::uintptr_t{0xFu});
}

std::uint32_t GuestStack::base() const noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(memory_ + size_));
}

std::uint32_t GuestStack::limit() const noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(memory_));
}

NativeGuestMemory::NativeGuestMemory() {
    DiagnosticPhaseScope phase(RuntimePhase::map_image);
    map();
    diagnostic_note("guest image mapped without executable payload");
}

NativeGuestMemory::~NativeGuestMemory() {
    release();
}

std::uint32_t NativeGuestMemory::load_base() const noexcept {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(image_));
}

std::uint32_t NativeGuestMemory::entry_va() const noexcept {
    return load_base() + kEntryRva;
}

std::uint8_t* NativeGuestMemory::data() noexcept {
    return image_;
}

const std::vector<ResolvedImport>& NativeGuestMemory::resolved_imports() const noexcept {
    return resolved_imports_;
}

void NativeGuestMemory::map() {
    if (sizeof(void*) != 4 || kMachine != IMAGE_FILE_MACHINE_I386) { throw std::runtime_error("Generated runtime requires Win32/x86"); }
    void* const requested = reinterpret_cast<void*>(static_cast<std::uintptr_t>(kPreferredImageBase));
    MEMORY_BASIC_INFORMATION region{};
    const SIZE_T queried = VirtualQuery(requested, &region, sizeof(region));
    const bool pre_reserved = queried != 0 && region.State == MEM_RESERVE && region.AllocationBase == requested;
    image_ = static_cast<std::uint8_t*>(pre_reserved ? VirtualAlloc(requested, kImageSize, MEM_COMMIT, PAGE_READWRITE) : VirtualAlloc(requested, kImageSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!image_) { throw std::runtime_error("Unable to reserve guest image at " + hex_u32(kPreferredImageBase)); }
    try {
        map_file();
    } catch (...) {
        release();
        throw;
    }
}

void NativeGuestMemory::initialize_native() {
    try {
        install_recovered_data();
        install_jump_tables();
        install_callback_stubs();
        {
            DiagnosticPhaseScope phase(RuntimePhase::load_imports);
            resolve_imports();
            diagnostic_note("native imports resolved");
        }
        {
            DiagnosticPhaseScope phase(RuntimePhase::protect_image);
            protect_image();
            diagnostic_note("guest image protections applied");
        }
        FlushInstructionCache(GetCurrentProcess(), image_, kImageSize);
    } catch (...) {
        release();
        throw;
    }
}

void NativeGuestMemory::map_file() {
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

void NativeGuestMemory::resolve_imports() {
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

void NativeGuestMemory::install_recovered_data() {
    for (const RecoveredDataDescriptor& range : kRecoveredData) {
        if ((range.hex.size() & 1u) != 0u || range.rva + range.hex.size() / 2u > kImageSize) { throw std::runtime_error("Invalid recovered lookup-data range"); }
        for (std::size_t index = 0; index < range.hex.size(); index += 2u) { image_[range.rva + index / 2u] = static_cast<std::uint8_t>((decode_hex_digit(range.hex[index]) << 4u) | decode_hex_digit(range.hex[index + 1u])); }
    }
}

void NativeGuestMemory::install_jump_tables() {
    for (const JumpTableDescriptor& entry : kJumpTableEntries) { std::memcpy(image_ + entry.rva, &entry.target, sizeof(entry.target)); }
}

void NativeGuestMemory::install_callback_stubs() {
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

void NativeGuestMemory::protect_image() {
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

void NativeGuestMemory::release() noexcept {
    resolved_imports_.clear();
    for (auto iterator = loaded_modules_.rbegin(); iterator != loaded_modules_.rend(); ++iterator) { if (*iterator) { FreeLibrary(*iterator); } }
    loaded_modules_.clear();
    if (image_) { VirtualFree(image_, 0, MEM_RELEASE); image_ = nullptr; }
}

namespace {

bool condition(CpuState& state, Op op) {
    const bool cf = flag(state, kFlagCF);
    const bool pf = flag(state, kFlagPF);
    const bool zf = flag(state, kFlagZF);
    const bool sf = flag(state, kFlagSF);
    const bool of = flag(state, kFlagOF);
    switch (op) {
        case Op::jo: case Op::seto: case Op::cmovo: return of;
        case Op::jno: case Op::setno: case Op::cmovno: return !of;
        case Op::jb: case Op::setb: case Op::cmovb: return cf;
        case Op::jae: case Op::setae: case Op::cmovae: return !cf;
        case Op::je: case Op::sete: case Op::cmove: return zf;
        case Op::jne: case Op::setne: case Op::cmovne: return !zf;
        case Op::jbe: case Op::setbe: case Op::cmovbe: return cf || zf;
        case Op::ja: case Op::seta: case Op::cmova: return !cf && !zf;
        case Op::js: case Op::sets: case Op::cmovs: return sf;
        case Op::jns: case Op::setns: case Op::cmovns: return !sf;
        case Op::jp: case Op::setp: case Op::cmovp: return pf;
        case Op::jnp: case Op::setnp: case Op::cmovnp: return !pf;
        case Op::jl: case Op::setl: case Op::cmovl: return sf != of;
        case Op::jge: case Op::setge: case Op::cmovge: return sf == of;
        case Op::jle: case Op::setle: case Op::cmovle: return zf || sf != of;
        case Op::jg: case Op::setg: case Op::cmovg: return !zf && sf == of;
        default: throw std::runtime_error("Opcode is not conditional");
    }
}

void execute_binary(CpuState& state, const InstructionDescriptor& instruction) {
    const OperandDescriptor& destination = instruction.operands[0];
    const std::uint16_t width = destination.width;
    const std::uint64_t left = read_operand(state, destination);
    const std::uint64_t right = read_operand(state, instruction.operands[1]);
    std::uint64_t result = 0;
    switch (instruction.op) {
        case Op::add: result = left + right; set_add_flags(state, left, right, 0, result, width); write_operand(state, destination, result); return;
        case Op::adc: {
            const std::uint64_t carry = flag(state, kFlagCF) ? 1u : 0u;
            result = left + right + carry;
            set_add_flags(state, left, right, carry, result, width);
            write_operand(state, destination, result);
            return;
        }
        case Op::sub: result = left - right; set_sub_flags(state, left, right, 0, result, width); write_operand(state, destination, result); return;
        case Op::sbb: {
            const std::uint64_t borrow = flag(state, kFlagCF) ? 1u : 0u;
            result = left - right - borrow;
            set_sub_flags(state, left, right, borrow, result, width);
            write_operand(state, destination, result);
            return;
        }
        case Op::cmp: result = left - right; set_sub_flags(state, left, right, 0, result, width); return;
        case Op::and_: result = left & right; set_logic_flags(state, result, width); write_operand(state, destination, result); return;
        case Op::or_: result = left | right; set_logic_flags(state, result, width); write_operand(state, destination, result); return;
        case Op::xor_: result = left ^ right; set_logic_flags(state, result, width); write_operand(state, destination, result); return;
        case Op::test: result = left & right; set_logic_flags(state, result, width); return;
        default: throw std::runtime_error("Invalid binary arithmetic opcode");
    }
}

void execute_shift(CpuState& state, const InstructionDescriptor& instruction) {
    const OperandDescriptor& destination = instruction.operands[0];
    const std::uint16_t width = destination.width;
    const std::uint64_t mask = width_mask(width);
    const std::uint64_t original = read_operand(state, destination) & mask;
    const std::uint32_t count = static_cast<std::uint32_t>(read_operand(state, instruction.operands[1])) & 0x1Fu;
    if (count == 0) { return; }
    std::uint64_t result = original;
    if (instruction.op == Op::shl || instruction.op == Op::sal) {
        result = (original << count) & mask;
        assign_flag(state, kFlagCF, count <= width && ((original >> (width - count)) & 1u) != 0);
        if (count == 1) { assign_flag(state, kFlagOF, ((result & sign_bit(width)) != 0) != flag(state, kFlagCF)); }
    } else if (instruction.op == Op::shr) {
        result = original >> count;
        assign_flag(state, kFlagCF, count <= width && ((original >> (count - 1u)) & 1u) != 0);
        if (count == 1) { assign_flag(state, kFlagOF, (original & sign_bit(width)) != 0); }
    } else if (instruction.op == Op::sar) {
        result = static_cast<std::uint64_t>(signed_value(original, width) >> count) & mask;
        assign_flag(state, kFlagCF, count <= width && ((original >> (count - 1u)) & 1u) != 0);
        if (count == 1) { assign_flag(state, kFlagOF, false); }
    } else if (instruction.op == Op::rol) {
        const std::uint32_t effective = count % width;
        result = effective == 0 ? original : ((original << effective) | (original >> (width - effective))) & mask;
        assign_flag(state, kFlagCF, (result & 1u) != 0);
        if (effective == 1) {
            const bool overflow = instruction.op == Op::rcr ? ((result ^ (result << 1u)) & sign_bit(width)) != 0 : ((result & sign_bit(width)) != 0) != flag(state, kFlagCF);
            assign_flag(state, kFlagOF, overflow);
        }
        write_operand(state, destination, result);
        return;
    } else if (instruction.op == Op::ror) {
        const std::uint32_t effective = count % width;
        result = effective == 0 ? original : ((original >> effective) | (original << (width - effective))) & mask;
        assign_flag(state, kFlagCF, (result & sign_bit(width)) != 0);
        if (effective == 1) { assign_flag(state, kFlagOF, ((result ^ (result << 1u)) & sign_bit(width)) != 0); }
        write_operand(state, destination, result);
        return;
    } else if (instruction.op == Op::rcr || instruction.op == Op::rcl) {
        const std::uint32_t effective = count % (width + 1u);
        result = original;
        for (std::uint32_t index = 0; index < effective; ++index) {
            const bool old_carry = flag(state, kFlagCF);
            if (instruction.op == Op::rcr) {
                const bool new_carry = (result & 1u) != 0;
                result = (result >> 1u) | (old_carry ? sign_bit(width) : 0u);
                assign_flag(state, kFlagCF, new_carry);
            } else {
                const bool new_carry = (result & sign_bit(width)) != 0;
                result = ((result << 1u) & mask) | (old_carry ? 1u : 0u);
                assign_flag(state, kFlagCF, new_carry);
            }
        }
        if (effective == 1) { assign_flag(state, kFlagOF, ((result & sign_bit(width)) != 0) != flag(state, kFlagCF)); }
        write_operand(state, destination, result);
        return;
    } else {
        throw std::runtime_error("Unsupported shift opcode");
    }
    set_szp(state, result, width);
    write_operand(state, destination, result);
}

void execute_double_shift(CpuState& state, const InstructionDescriptor& instruction) {
    const OperandDescriptor& destination = instruction.operands[0];
    const std::uint16_t width = destination.width;
    const std::uint32_t count = static_cast<std::uint32_t>(read_operand(state, instruction.operands[2])) & 0x1Fu;
    if (count == 0) { return; }
    const std::uint64_t left = read_operand(state, destination) & width_mask(width);
    const std::uint64_t right = read_operand(state, instruction.operands[1]) & width_mask(width);
    std::uint64_t result = 0;
    if (instruction.op == Op::shld) {
        result = ((left << count) | (right >> (width - count))) & width_mask(width);
        assign_flag(state, kFlagCF, ((left >> (width - count)) & 1u) != 0);
        if (count == 1) { assign_flag(state, kFlagOF, ((result & sign_bit(width)) != 0) != flag(state, kFlagCF)); }
    } else {
        result = ((left >> count) | (right << (width - count))) & width_mask(width);
        assign_flag(state, kFlagCF, ((left >> (count - 1u)) & 1u) != 0);
        if (count == 1) { assign_flag(state, kFlagOF, ((left ^ result) & sign_bit(width)) != 0); }
    }
    set_szp(state, result, width);
    write_operand(state, destination, result);
}

void execute_compare_string(CpuState& state, const InstructionDescriptor& instruction, std::uint32_t width, bool scan) {
    const bool repeated = (instruction.prefixes & (kPrefixRep | kPrefixRepe | kPrefixRepne)) != 0;
    std::uint32_t count = repeated ? state.ecx : 1u;
    const std::int32_t delta = flag(state, kFlagDF) ? -static_cast<std::int32_t>(width) : static_cast<std::int32_t>(width);
    while (count != 0) {
        std::uint64_t left = 0;
        std::uint64_t right = 0;
        if (scan) {
            left = width == 1 ? read_register(state, Reg::al) : width == 2 ? read_register(state, Reg::ax) : state.eax;
            right = width == 1 ? memory_read<std::uint8_t>(state.edi) : width == 2 ? memory_read<std::uint16_t>(state.edi) : memory_read<std::uint32_t>(state.edi);
        } else {
            left = width == 1 ? memory_read<std::uint8_t>(state.esi) : width == 2 ? memory_read<std::uint16_t>(state.esi) : memory_read<std::uint32_t>(state.esi);
            right = width == 1 ? memory_read<std::uint8_t>(state.edi) : width == 2 ? memory_read<std::uint16_t>(state.edi) : memory_read<std::uint32_t>(state.edi);
            state.esi += delta;
        }
        state.edi += delta;
        set_sub_flags(state, left, right, 0, left - right, static_cast<std::uint16_t>(width * 8u));
        if (!repeated) { break; }
        --state.ecx;
        --count;
        if ((instruction.prefixes & kPrefixRepne) != 0 ? flag(state, kFlagZF) : !flag(state, kFlagZF)) { break; }
    }
}

void execute_multiply(CpuState& state, const InstructionDescriptor& instruction, bool signed_multiply) {
    const OperandDescriptor& source = instruction.operands[instruction.operand_count - 1u];
    const std::uint16_t width = source.width;
    if (instruction.operand_count >= 2) {
        const std::int64_t left = signed_value(read_operand(state, instruction.operands[instruction.operand_count == 2 ? 0 : 1]), width);
        const std::int64_t right = signed_value(read_operand(state, source), width);
        const std::int64_t result = left * right;
        write_operand(state, instruction.operands[0], static_cast<std::uint64_t>(result));
        const std::int64_t truncated = signed_value(static_cast<std::uint64_t>(result), instruction.operands[0].width);
        assign_flag(state, kFlagCF, truncated != result);
        assign_flag(state, kFlagOF, truncated != result);
        return;
    }
    const std::uint64_t source_value = read_operand(state, source);
    if (width == 8) {
        const std::uint16_t product = signed_multiply ? static_cast<std::uint16_t>(static_cast<std::int16_t>(static_cast<std::int8_t>(state.eax)) * static_cast<std::int8_t>(source_value)) : static_cast<std::uint16_t>(static_cast<std::uint8_t>(state.eax) * static_cast<std::uint8_t>(source_value));
        write_register(state, Reg::ax, product);
        const bool overflow = signed_multiply ? static_cast<std::int16_t>(product) != static_cast<std::int8_t>(product) : (product & 0xFF00u) != 0;
        assign_flag(state, kFlagCF, overflow);
        assign_flag(state, kFlagOF, overflow);
        return;
    }
    if (width == 32) {
        const std::uint64_t product = signed_multiply ? static_cast<std::uint64_t>(static_cast<std::int64_t>(static_cast<std::int32_t>(state.eax)) * static_cast<std::int32_t>(source_value)) : static_cast<std::uint64_t>(state.eax) * static_cast<std::uint32_t>(source_value);
        state.eax = static_cast<std::uint32_t>(product);
        state.edx = static_cast<std::uint32_t>(product >> 32u);
        const bool overflow = signed_multiply ? static_cast<std::int64_t>(product) != static_cast<std::int32_t>(product) : state.edx != 0;
        assign_flag(state, kFlagCF, overflow);
        assign_flag(state, kFlagOF, overflow);
        return;
    }
    throw std::runtime_error("Unsupported multiply width");
}

void execute_divide(CpuState& state, const InstructionDescriptor& instruction, bool signed_divide) {
    const OperandDescriptor& source = instruction.operands[0];
    const std::uint16_t width = source.width;
    const std::uint64_t divisor = read_operand(state, source);
    if (divisor == 0) { throw std::runtime_error("Guest division by zero"); }
    if (width == 8) {
        if (signed_divide) {
            const std::int16_t dividend = static_cast<std::int16_t>(state.eax & 0xFFFFu);
            const std::int16_t quotient = dividend / static_cast<std::int8_t>(divisor);
            const std::int16_t remainder = dividend % static_cast<std::int8_t>(divisor);
            if (quotient < -128 || quotient > 127) { throw std::runtime_error("Guest signed division overflow"); }
            write_register(state, Reg::al, quotient);
            write_register(state, Reg::ah, remainder);
        } else {
            const std::uint16_t dividend = static_cast<std::uint16_t>(state.eax);
            const std::uint16_t quotient = dividend / static_cast<std::uint8_t>(divisor);
            if (quotient > 0xFFu) { throw std::runtime_error("Guest division overflow"); }
            write_register(state, Reg::al, quotient);
            write_register(state, Reg::ah, dividend % static_cast<std::uint8_t>(divisor));
        }
        return;
    }
    if (width == 32) {
        if (signed_divide) {
            const std::int64_t dividend = static_cast<std::int64_t>((static_cast<std::uint64_t>(state.edx) << 32u) | state.eax);
            const std::int32_t signed_divisor = static_cast<std::int32_t>(divisor);
            if (dividend == std::numeric_limits<std::int64_t>::min() && signed_divisor == -1) { throw std::runtime_error("Guest signed division overflow"); }
            const std::int64_t quotient = dividend / signed_divisor;
            const std::int64_t remainder = dividend % signed_divisor;
            if (quotient < std::numeric_limits<std::int32_t>::min() || quotient > std::numeric_limits<std::int32_t>::max()) { throw std::runtime_error("Guest signed division overflow"); }
            state.eax = static_cast<std::uint32_t>(quotient);
            state.edx = static_cast<std::uint32_t>(remainder);
        } else {
            const std::uint64_t dividend = (static_cast<std::uint64_t>(state.edx) << 32u) | state.eax;
            const std::uint64_t quotient = dividend / static_cast<std::uint32_t>(divisor);
            if (quotient > std::numeric_limits<std::uint32_t>::max()) { throw std::runtime_error("Guest division overflow"); }
            state.eax = static_cast<std::uint32_t>(quotient);
            state.edx = static_cast<std::uint32_t>(dividend % static_cast<std::uint32_t>(divisor));
        }
        return;
    }
    throw std::runtime_error("Unsupported division width");
}

bool execute_x87(CpuState& state, const InstructionDescriptor& instruction) {
    const OperandDescriptor& first = instruction.operands[0];
    const OperandDescriptor& comparison_source = instruction.operand_count >= 2 ? instruction.operands[1] : first;
    switch (instruction.op) {
        case Op::fld: fpu_push(state, read_float_operand(state, first)); return true;
        case Op::fld1: fpu_push(state, 1.0); return true;
        case Op::fldz: fpu_push(state, 0.0); return true;
        case Op::fild: fpu_push(state, static_cast<double>(signed_value(read_operand(state, first), first.width))); return true;
        case Op::fst: fpu_require(state); write_float_operand(state, first, state.fpu[0]); return true;
        case Op::fstp: fpu_require(state); write_float_operand(state, first, state.fpu[0]); fpu_pop(state); return true;
        case Op::fist: case Op::fistp: case Op::fisttp: {
            fpu_require(state);
            const std::int64_t value = rounded_integer(state.fpu[0], state.fpu_control, instruction.op == Op::fisttp);
            write_operand(state, first, static_cast<std::uint64_t>(value));
            if (instruction.op != Op::fist) { fpu_pop(state); }
            return true;
        }
        case Op::fxch: fpu_require(state); std::swap(state.fpu[0], fpu_register(state, comparison_source.reg)); return true;
        case Op::fabs: fpu_require(state); state.fpu[0] = std::fabs(state.fpu[0]); return true;
        case Op::fchs: fpu_require(state); state.fpu[0] = -state.fpu[0]; return true;
        case Op::fldcw: state.fpu_control = static_cast<std::uint16_t>(read_operand(state, first)); return true;
        case Op::fnstcw: write_operand(state, first, state.fpu_control); return true;
        case Op::fnstsw: write_operand(state, first, static_cast<std::uint16_t>(state.fpu_status | ((state.fpu_top & 7u) << 11u))); return true;
        case Op::fcom: case Op::fcomp: case Op::fucomp: {
            fpu_require(state);
            fpu_compare(state, state.fpu[0], read_float_operand(state, comparison_source));
            if (instruction.op != Op::fcom) { fpu_pop(state); }
            return true;
        }
        case Op::fcompp: case Op::fucompp: fpu_require(state, 2); fpu_compare(state, state.fpu[0], state.fpu[1]); fpu_pop(state); fpu_pop(state); return true;
        case Op::fsincos: {
            fpu_require(state);
            const double value = state.fpu[0];
            state.fpu[0] = std::sin(value);
            fpu_push(state, std::cos(value));
            return true;
        }
        default: break;
    }
    const bool integer_source = instruction.op == Op::fiadd || instruction.op == Op::fisub || instruction.op == Op::fisubr || instruction.op == Op::fimul || instruction.op == Op::fidiv || instruction.op == Op::fidivr;
    const bool arithmetic = integer_source || instruction.op == Op::fadd || instruction.op == Op::faddp || instruction.op == Op::fsub || instruction.op == Op::fsubp || instruction.op == Op::fsubr || instruction.op == Op::fsubrp || instruction.op == Op::fmul || instruction.op == Op::fmulp || instruction.op == Op::fdiv || instruction.op == Op::fdivp || instruction.op == Op::fdivr || instruction.op == Op::fdivrp;
    if (!arithmetic) { return false; }
    fpu_require(state);
    const bool pop = instruction.op == Op::faddp || instruction.op == Op::fsubp || instruction.op == Op::fsubrp || instruction.op == Op::fmulp || instruction.op == Op::fdivp || instruction.op == Op::fdivrp;
    double* destination = &state.fpu[0];
    double source = 0;
    if (integer_source) { source = static_cast<double>(signed_value(read_operand(state, first), first.width)); }
    else if (instruction.operand_count >= 2) { destination = &fpu_register(state, first.reg); source = read_float_operand(state, instruction.operands[1]); }
    else { source = read_float_operand(state, first); }
    if (instruction.op == Op::fadd || instruction.op == Op::faddp || instruction.op == Op::fiadd) { *destination += source; }
    else if (instruction.op == Op::fmul || instruction.op == Op::fmulp || instruction.op == Op::fimul) { *destination *= source; }
    else if (instruction.op == Op::fsub || instruction.op == Op::fsubp || instruction.op == Op::fisub) { *destination -= source; }
    else if (instruction.op == Op::fsubr || instruction.op == Op::fsubrp || instruction.op == Op::fisubr) { *destination = source - *destination; }
    else if (instruction.op == Op::fdiv || instruction.op == Op::fdivp || instruction.op == Op::fidiv) { *destination /= source; }
    else { *destination = source / *destination; }
    if (pop) { fpu_pop(state); }
    return true;
}

void initialize_fs(CpuState& state) {
    const std::uint32_t end_of_chain = 0xFFFFFFFFu;
    const std::uint32_t teb = __readfsdword(0x18);
    const std::uint32_t peb = __readfsdword(0x30);
    std::memcpy(state.fs_data.data(), &end_of_chain, sizeof(end_of_chain));
    std::memcpy(state.fs_data.data() + 0x18u, &teb, sizeof(teb));
    std::memcpy(state.fs_data.data() + 0x30u, &peb, sizeof(peb));
}

#if !defined(SFERA_PORTABLE_CHECK) && defined(_M_IX86)

extern "C" __declspec(noinline) std::uint32_t __cdecl bridge_test_cdecl(std::uint32_t left, std::uint32_t right) { return left + right * 3u; }
extern "C" __declspec(noinline) std::uint32_t __stdcall bridge_test_stdcall(std::uint32_t left, std::uint32_t right) { return left ^ (right + 0x13579BDFu); }
extern "C" __declspec(noinline) std::uint32_t __fastcall bridge_test_fastcall(std::uint32_t left, std::uint32_t right, std::uint32_t stack_value) { return left + right + stack_value; }

void verify_native_bridge() {
    DiagnosticPhaseScope phase(RuntimePhase::abi_self_test);
    GuestStack stack(64u * 1024u);
    CpuState state{};
    auto prepare = [&]() {
        state = CpuState{};
        state.esp = stack.top();
        state.guest_stack_base = stack.base();
        state.guest_stack_limit = stack.limit();
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
    push32(state, 7u);
    push32(state, 5u);
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
    push32(state, 0x2468ACE0u);
    push32(state, 0x10203040u);
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
    push32(state, 17u);
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

Runtime::Runtime() {
    memory_.initialize_native();
    verify_native_bridge();
    DiagnosticPhaseScope phase(RuntimePhase::build_index);
    instruction_index_.resize(kCodeMaxRva - kCodeMinRva);
    for (const InstructionChunk& chunk : kInstructionChunks) {
        for (std::size_t index = 0; index < chunk.size; ++index) {
            const InstructionDescriptor& instruction = chunk.data[index];
            if (instruction.rva >= kCodeMinRva && instruction.rva < kCodeMaxRva) { instruction_index_[instruction.rva - kCodeMinRva] = &instruction; }
        }
    }
    instruction_index_data_ = instruction_index_.data();
    for (const ResolvedImport& item : memory_.resolved_imports()) { imports_by_address_.try_emplace(item.address, item.descriptor); }
    diagnostic_note("IR index constructed");
    const std::string summary_note = "generated semantic summaries: config=" + (kConfigLookupTarget == 0 ? std::string("disabled") : hex_u32(kConfigLookupTarget)) + ", unsigned-decimal=" + (kUnsignedDecimalStringTarget == 0 ? std::string("disabled") : hex_u32(kUnsignedDecimalStringTarget)) + ", callsite=" + (kUnsignedDecimalStringCallsite == 0 ? std::string("disabled") : hex_u32(kUnsignedDecimalStringCallsite));
    diagnostic_note(summary_note.c_str());
}

NativeGuestMemory& Runtime::memory() noexcept {
    return memory_;
}

const InstructionDescriptor& Runtime::lookup(std::uint32_t eip) const {
    if (eip < kPreferredImageBase + kCodeMinRva || eip >= kPreferredImageBase + kCodeMaxRva) { throw std::runtime_error("No decoded IR instruction at guest EIP " + hex_u32(eip)); }
    const InstructionDescriptor* instruction = instruction_index_data_[eip - kPreferredImageBase - kCodeMinRva];
    if (!instruction) { throw std::runtime_error("No decoded IR instruction at guest EIP " + hex_u32(eip)); }
    return *instruction;
}

bool Runtime::has_instruction(std::uint32_t eip) const noexcept {
    if (eip < kPreferredImageBase + kCodeMinRva || eip >= kPreferredImageBase + kCodeMaxRva) { return false; }
    return instruction_index_data_[eip - kPreferredImageBase - kCodeMinRva] != nullptr;
}

const ImportDescriptor* Runtime::find_import(std::uint32_t target) const {
    const auto found = imports_by_address_.find(target);
    return found == imports_by_address_.end() ? nullptr : found->second;
}

void Runtime::run(CpuState& state, std::uint32_t stop_target) {
    DiagnosticPhaseScope phase(RuntimePhase::interpret);
    DiagnosticRunScope run_scope(&state);
    DiagnosticGuestRunScope guest_run_scope(state.eip, stop_target, state.esp);
    state.stopped = false;
    while (!state.stopped) {
        const std::uint32_t current_eip = state.eip;
        const InstructionDescriptor* instruction = nullptr;
        try {
            instruction = &lookup(current_eip);
            set_diagnostic_instruction(kPreferredImageBase + instruction->rva, op_name(instruction->op).data());
            step(state, *instruction, stop_target);
        } catch (const std::exception& error) {
            const std::string operation = instruction ? std::string(op_name(instruction->op)) : "lookup";
            const std::string failure = "IR failure at " + hex_u32(current_eip) + " [" + operation + "]: " + error.what();
            diagnostic_guest_failure(state, failure.c_str());
            throw std::runtime_error(failure);
        }
    }
}

void Runtime::call_native(CpuState& state, std::uint32_t target) {
    const ImportDescriptor* descriptor = find_import(target);
    const std::string_view name = descriptor ? descriptor->name : std::string_view{};
    DiagnosticPhaseScope phase(RuntimePhase::native_call);
    DiagnosticNativeScope native_scope(target, descriptor ? descriptor->name.data() : nullptr);
    MEMORY_BASIC_INFORMATION target_region{};
    const DWORD executable_protection = PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;
    if (target == 0 || VirtualQuery(reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), &target_region, sizeof(target_region)) == 0 || target_region.State != MEM_COMMIT || (target_region.Protect & executable_protection) == 0 || (target_region.Protect & (PAGE_GUARD | PAGE_NOACCESS)) != 0) { throw std::runtime_error("Invalid native call target " + hex_u32(target)); }
    if (name == "_CxxThrowException" || name == "RaiseException") { throw std::runtime_error("Guest SEH/C++ exception crossed the interpreter boundary"); }
    if ((name == "GetModuleHandleA" || name == "GetModuleHandleW") && memory_read<std::uint32_t>(state.esp) == 0) {
        state.eax = memory_.load_base();
        state.esp += 4u;
        return;
    }
    if ((name == "GetModuleFileNameA" || name == "GetModuleFileNameW") && (memory_read<std::uint32_t>(state.esp) == 0 || memory_read<std::uint32_t>(state.esp) == memory_.load_base())) {
        const std::uint32_t buffer = memory_read<std::uint32_t>(state.esp + 4u);
        const std::uint32_t capacity = memory_read<std::uint32_t>(state.esp + 8u);
        state.eax = name == "GetModuleFileNameW" ? write_guest_path(buffer, capacity, guest_executable_path()) : write_guest_path(buffer, capacity, guest_executable_path_ansi());
        state.esp += 12u;
        const std::string note = "virtualized " + std::string(name) + ": " + narrow_path(guest_executable_path());
        diagnostic_note(note.c_str());
        return;
    }
    if (name == "_CIatan2" || name == "_CIpow") {
        fpu_require(state, 2);
        state.fpu[1] = name == "_CIpow" ? std::pow(state.fpu[1], state.fpu[0]) : std::atan2(state.fpu[1], state.fpu[0]);
        fpu_pop(state);
        return;
    }
    if (name == "_CIacos" || name == "_CIasin" || name == "_CIatan" || name == "_CIcos" || name == "_CIexp" || name == "_CIsin" || name == "_CIsqrt" || name == "_CItan") {
        fpu_require(state);
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
    if (name == "_findfirst64i32") { resource_note = "resource enumeration pattern=\"" + guest_c_string(memory_read<std::uint32_t>(state.esp)) + "\""; }
    else if (name == "fopen") { resource_note = "resource fopen path=\"" + guest_c_string(memory_read<std::uint32_t>(state.esp)) + "\", mode=\"" + guest_c_string(memory_read<std::uint32_t>(state.esp + 4u)) + "\""; }
    NativeCallArguments arguments(state.esp);
    std::string module_note;
    if (descriptor && descriptor->process_module_argument >= 0) {
        const std::uint8_t argument = static_cast<std::uint8_t>(descriptor->process_module_argument);
        const std::uint32_t guest_handle = arguments.read(argument);
        const std::uint32_t native_handle = process_module_handle();
        if (native_handle != guest_handle) { arguments.alias(argument, guest_handle, native_handle); }
        module_note = "module identity import=" + std::string(name) + ", argument=" + std::to_string(argument) + ", guest=" + hex_u32(guest_handle) + ", native=" + hex_u32(native_handle);
        if (name == "DirectInput8Create") { module_note += ", version=" + hex_u32(arguments.read(1)) + ", iid=" + hex_u32(arguments.read(2)) + ", output=" + hex_u32(arguments.read(3)) + ", outer=" + hex_u32(arguments.read(4)); }
    }
    NativeCallFrame frame{&state, reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, 0.0};
    native_call_bridge(&frame);
    if (name == "_findnext64i32" && state.eax == 0xFFFFFFFFu) { resource_note = "resource enumeration complete"; }
    if (!resource_note.empty()) { resource_note += ", result=" + hex_u32(state.eax); diagnostic_note(resource_note.c_str()); }
    if (!module_note.empty()) { module_note += ", result=" + hex_u32(state.eax); diagnostic_note(module_note.c_str()); }
    if (descriptor && is_float_return(name)) { fpu_push(state, frame.native_st0); }
}

void Runtime::step(CpuState& state, const InstructionDescriptor& instruction, std::uint32_t stop_target) {
    const std::uint32_t next = kPreferredImageBase + instruction.rva + instruction.size;
    state.eip = next;
    if (execute_x87(state, instruction)) { return; }
    switch (instruction.op) {
        case Op::mov: write_operand(state, instruction.operands[0], read_operand(state, instruction.operands[1])); return;
        case Op::lea: write_operand(state, instruction.operands[0], effective_address(state, instruction.operands[1])); return;
        case Op::movzx: write_operand(state, instruction.operands[0], read_operand(state, instruction.operands[1])); return;
        case Op::movsx: write_operand(state, instruction.operands[0], static_cast<std::uint64_t>(signed_value(read_operand(state, instruction.operands[1]), instruction.operands[1].width))); return;
        case Op::add: case Op::adc: case Op::sub: case Op::sbb: case Op::cmp: case Op::and_: case Op::or_: case Op::xor_: case Op::test: execute_binary(state, instruction); return;
        case Op::inc: {
            const bool old_carry = flag(state, kFlagCF);
            const std::uint64_t left = read_operand(state, instruction.operands[0]);
            const std::uint64_t result = left + 1u;
            set_add_flags(state, left, 1u, 0, result, instruction.operands[0].width);
            assign_flag(state, kFlagCF, old_carry);
            write_operand(state, instruction.operands[0], result);
            return;
        }
        case Op::dec: {
            const bool old_carry = flag(state, kFlagCF);
            const std::uint64_t left = read_operand(state, instruction.operands[0]);
            const std::uint64_t result = left - 1u;
            set_sub_flags(state, left, 1u, 0, result, instruction.operands[0].width);
            assign_flag(state, kFlagCF, old_carry);
            write_operand(state, instruction.operands[0], result);
            return;
        }
        case Op::neg: {
            const OperandDescriptor& operand = instruction.operands[0];
            const std::uint64_t value = read_operand(state, operand);
            const std::uint64_t result = 0u - value;
            set_sub_flags(state, 0, value, 0, result, operand.width);
            assign_flag(state, kFlagCF, value != 0);
            write_operand(state, operand, result);
            return;
        }
        case Op::not_: write_operand(state, instruction.operands[0], ~read_operand(state, instruction.operands[0])); return;
        case Op::shl: case Op::sal: case Op::shr: case Op::sar: case Op::rol: case Op::ror: case Op::rcl: case Op::rcr: execute_shift(state, instruction); return;
        case Op::shld: case Op::shrd: execute_double_shift(state, instruction); return;
        case Op::imul: execute_multiply(state, instruction, true); return;
        case Op::mul: execute_multiply(state, instruction, false); return;
        case Op::idiv: execute_divide(state, instruction, true); return;
        case Op::div: execute_divide(state, instruction, false); return;
        case Op::cdq: state.edx = (state.eax & 0x80000000u) != 0 ? 0xFFFFFFFFu : 0u; return;
        case Op::cwde: state.eax = static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(state.eax))); return;
        case Op::push: {
            std::uint64_t value = read_operand(state, instruction.operands[0]);
            if (instruction.operands[0].kind == OperandKind::imm && instruction.operands[0].width < 32) { value = static_cast<std::uint32_t>(signed_value(value, instruction.operands[0].width)); }
            push32(state, static_cast<std::uint32_t>(value));
            return;
        }
        case Op::pop: write_operand(state, instruction.operands[0], pop32(state)); return;
        case Op::pushfd: push32(state, state.eflags); return;
        case Op::popfd: state.eflags = pop32(state) | 0x2u; return;
        case Op::pushad: {
            const std::uint32_t original_esp = state.esp;
            push32(state, state.eax); push32(state, state.ecx); push32(state, state.edx); push32(state, state.ebx); push32(state, original_esp); push32(state, state.ebp); push32(state, state.esi); push32(state, state.edi);
            return;
        }
        case Op::popad: {
            state.edi = pop32(state); state.esi = pop32(state); state.ebp = pop32(state); state.esp += 4u; state.ebx = pop32(state); state.edx = pop32(state); state.ecx = pop32(state); state.eax = pop32(state);
            return;
        }
        case Op::xchg: {
            const std::uint64_t left = read_operand(state, instruction.operands[0]);
            const std::uint64_t right = read_operand(state, instruction.operands[1]);
            write_operand(state, instruction.operands[0], right);
            write_operand(state, instruction.operands[1], left);
            return;
        }
        case Op::jmp: {
            const std::uint32_t target = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0]));
            if (target == 0x00459B10u) { throw std::runtime_error(fatal_handler_failure(state, kPreferredImageBase + instruction.rva)); }
            if (has_instruction(target)) { state.eip = target; return; }
            const std::uint32_t return_target = pop32(state);
            call_native(state, target);
            diagnostic_guest_return(return_target);
            if (return_target == stop_target) { state.stopped = true; }
            else { state.eip = return_target; }
            return;
        }
        case Op::call: {
            const std::uint32_t target = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0]));
            const std::uint32_t callsite = kPreferredImageBase + instruction.rva;
            if (target == 0x004010F0u || target == 0x00401120u) { throw std::runtime_error(bound_check_failure(state, callsite, target)); }
            if (target == 0x00459B10u) { throw std::runtime_error(fatal_handler_failure(state, callsite)); }
            diagnostic_guest_call(callsite, target, next, state.esp);
            if (execute_semantic_summary(state, callsite, target)) { diagnostic_guest_return(next); return; }
            if (has_instruction(target)) { push32(state, next); state.eip = target; }
            else { call_native(state, target); diagnostic_guest_return(next); }
            return;
        }
        case Op::ret: {
            const std::uint32_t target = pop32(state);
            if (instruction.operand_count != 0) { state.esp += static_cast<std::uint32_t>(read_operand(state, instruction.operands[0]) & 0xFFFFu); }
            diagnostic_guest_return(target);
            if (target == stop_target) { state.stopped = true; }
            else { state.eip = target; }
            return;
        }
        case Op::leave: state.esp = state.ebp; state.ebp = pop32(state); return;
        case Op::jo: case Op::jno: case Op::jb: case Op::jae: case Op::je: case Op::jne: case Op::jbe: case Op::ja: case Op::js: case Op::jns: case Op::jp: case Op::jnp: case Op::jl: case Op::jge: case Op::jle: case Op::jg: if (condition(state, instruction.op)) { state.eip = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0])); } return;
        case Op::jecxz: if (state.ecx == 0) { state.eip = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0])); } return;
        case Op::jcxz: if ((state.ecx & 0xFFFFu) == 0) { state.eip = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0])); } return;
        case Op::loop: state.ecx -= 1u; if (state.ecx != 0) { state.eip = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0])); } return;
        case Op::loope: state.ecx -= 1u; if (state.ecx != 0 && flag(state, kFlagZF)) { state.eip = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0])); } return;
        case Op::loopne: state.ecx -= 1u; if (state.ecx != 0 && !flag(state, kFlagZF)) { state.eip = static_cast<std::uint32_t>(read_operand(state, instruction.operands[0])); } return;
        case Op::seta: case Op::setae: case Op::setb: case Op::setbe: case Op::sete: case Op::setg: case Op::setge: case Op::setl: case Op::setle: case Op::setne: case Op::setno: case Op::setnp: case Op::setns: case Op::seto: case Op::setp: case Op::sets: write_operand(state, instruction.operands[0], condition(state, instruction.op) ? 1u : 0u); return;
        case Op::cmova: case Op::cmovae: case Op::cmovb: case Op::cmovbe: case Op::cmove: case Op::cmovg: case Op::cmovge: case Op::cmovl: case Op::cmovle: case Op::cmovne: case Op::cmovno: case Op::cmovnp: case Op::cmovns: case Op::cmovo: case Op::cmovp: case Op::cmovs: if (condition(state, instruction.op)) { write_operand(state, instruction.operands[0], read_operand(state, instruction.operands[1])); } return;
        case Op::clc: assign_flag(state, kFlagCF, false); return;
        case Op::stc: assign_flag(state, kFlagCF, true); return;
        case Op::cmc: assign_flag(state, kFlagCF, !flag(state, kFlagCF)); return;
        case Op::cld: assign_flag(state, kFlagDF, false); return;
        case Op::std_: assign_flag(state, kFlagDF, true); return;
        case Op::lahf: write_register(state, Reg::ah, (state.eflags & 0xD5u) | 0x02u); return;
        case Op::sahf: state.eflags = (state.eflags & ~0xD5u) | (static_cast<std::uint32_t>(read_register(state, Reg::ah)) & 0xD5u) | 0x2u; return;
        case Op::movsb: case Op::movsw: case Op::movsd: {
            const bool string_form = instruction.operand_count == 2 && instruction.operands[0].kind == OperandKind::mem && instruction.operands[1].kind == OperandKind::mem;
            if (!string_form) {
                const OperandDescriptor& destination = instruction.operands[0];
                const OperandDescriptor& source = instruction.operands[1];
                const double value = read_scalar_double(state, source);
                if (destination.kind == OperandKind::mem) { memory_write(effective_address(state, destination), value); }
                else {
                    auto& target = xmm_register(state, destination.reg);
                    if (source.kind == OperandKind::mem) { target.fill(0); }
                    std::memcpy(target.data(), &value, sizeof(value));
                }
                return;
            }
            const std::uint32_t width = instruction.op == Op::movsb ? 1u : instruction.op == Op::movsw ? 2u : 4u;
            std::uint32_t count = (instruction.prefixes & kPrefixRep) != 0 ? state.ecx : 1u;
            const std::int32_t delta = flag(state, kFlagDF) ? -static_cast<std::int32_t>(width) : static_cast<std::int32_t>(width);
            while (count--) {
                if (width == 1) { memory_write(state.edi, memory_read<std::uint8_t>(state.esi)); }
                else if (width == 2) { memory_write(state.edi, memory_read<std::uint16_t>(state.esi)); }
                else { memory_write(state.edi, memory_read<std::uint32_t>(state.esi)); }
                state.esi += delta; state.edi += delta;
                if ((instruction.prefixes & kPrefixRep) != 0) { --state.ecx; }
            }
            return;
        }
        case Op::stosb: case Op::stosw: case Op::stosd: {
            const std::uint32_t width = instruction.op == Op::stosb ? 1u : instruction.op == Op::stosw ? 2u : 4u;
            std::uint32_t count = (instruction.prefixes & kPrefixRep) != 0 ? state.ecx : 1u;
            const std::int32_t delta = flag(state, kFlagDF) ? -static_cast<std::int32_t>(width) : static_cast<std::int32_t>(width);
            while (count--) {
                if (width == 1) { memory_write(state.edi, static_cast<std::uint8_t>(state.eax)); }
                else if (width == 2) { memory_write(state.edi, static_cast<std::uint16_t>(state.eax)); }
                else { memory_write(state.edi, state.eax); }
                state.edi += delta;
                if ((instruction.prefixes & kPrefixRep) != 0) { --state.ecx; }
            }
            return;
        }
        case Op::lodsb: case Op::lodsw: case Op::lodsd: {
            const std::uint32_t width = instruction.op == Op::lodsb ? 1u : instruction.op == Op::lodsw ? 2u : 4u;
            std::uint32_t count = (instruction.prefixes & (kPrefixRep | kPrefixRepe | kPrefixRepne)) != 0 ? state.ecx : 1u;
            const std::int32_t delta = flag(state, kFlagDF) ? -static_cast<std::int32_t>(width) : static_cast<std::int32_t>(width);
            while (count--) {
                if (width == 1) { write_register(state, Reg::al, memory_read<std::uint8_t>(state.esi)); }
                else if (width == 2) { write_register(state, Reg::ax, memory_read<std::uint16_t>(state.esi)); }
                else { state.eax = memory_read<std::uint32_t>(state.esi); }
                state.esi += delta;
                if ((instruction.prefixes & (kPrefixRep | kPrefixRepe | kPrefixRepne)) != 0) { --state.ecx; }
            }
            return;
        }
        case Op::cmpsb: case Op::cmpsw: case Op::cmpsd: execute_compare_string(state, instruction, instruction.op == Op::cmpsb ? 1u : instruction.op == Op::cmpsw ? 2u : 4u, false); return;
        case Op::scasb: case Op::scasw: case Op::scasd: execute_compare_string(state, instruction, instruction.op == Op::scasb ? 1u : instruction.op == Op::scasw ? 2u : 4u, true); return;
        case Op::movups: write_vector(state, instruction.operands[0], read_vector(state, instruction.operands[1])); return;
        case Op::cvttsd2si: {
            const double value = read_scalar_double(state, instruction.operands[1]);
            write_operand(state, instruction.operands[0], static_cast<std::uint32_t>(static_cast<std::int32_t>(std::trunc(value))));
            return;
        }
        case Op::nop: case Op::wait: return;
        case Op::int3: throw std::runtime_error("Guest INT3");
        case Op::invalid: throw std::runtime_error("Invalid x86 encoding reached");
        default: throw std::runtime_error("Unsupported opcode " + std::string(op_name(instruction.op)));
    }
}

int Runtime::execute() {
    DiagnosticPhaseScope phase(RuntimePhase::guest_setup);
    GuestStack stack(kStackReserve);
    CpuState state{};
    state.esp = stack.top();
    state.guest_stack_base = stack.base();
    state.guest_stack_limit = stack.limit();
    state.eip = memory_.entry_va();
    initialize_fs(state);
    push32(state, kCallbackSentinel);
    diagnostic_note("entering guest entry point");
    g_runtime = this;
    try {
        run(state, kCallbackSentinel);
        g_runtime = nullptr;
        return static_cast<int>(state.eax);
    } catch (...) {
        g_runtime = nullptr;
        throw;
    }
}

void Runtime::dispatch_callback(CallbackRegisters& registers) {
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
    GuestStack clone(std::max<std::size_t>(kStackReserve, 1024u * 1024u));
    const std::uint32_t clone_esp = clone.top() - static_cast<std::uint32_t>(copy_size);
    if (!safe_copy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(clone_esp)), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(original_esp)), copy_size)) { throw std::runtime_error("Unable to clone native callback arguments"); }
    memory_write(clone_esp, kCallbackSentinel);
    CpuState state{};
    state.eax = registers.eax; state.ecx = registers.ecx; state.edx = registers.edx; state.ebx = registers.ebx; state.esp = clone_esp; state.ebp = registers.ebp; state.esi = registers.esi; state.edi = registers.edi; state.eip = target; state.eflags = registers.eflags;
    state.guest_stack_base = clone.base(); state.guest_stack_limit = clone.limit();
    initialize_fs(state);
    run(state, kCallbackSentinel);
    const std::uint32_t stack_delta = state.esp - clone_esp;
    if (stack_delta < 4u || stack_delta > copy_size) { throw std::runtime_error("Guest callback returned an invalid stack delta"); }
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
        MessageBoxA(nullptr, error.what(), "Compiled IR callback failure", MB_OK | MB_ICONERROR);
        TerminateProcess(GetCurrentProcess(), 0xE0000002u);
    }
}

#if defined(SFERA_PORTABLE_CHECK)

extern "C" void __cdecl native_call_bridge(NativeCallFrame*) {}
extern "C" void callback_bridge() {}

#elif defined(_M_IX86)

static_assert(offsetof(CpuState, eax) == 0 && offsetof(CpuState, eflags) == 36 && offsetof(CpuState, fpu_control) == 114);
static_assert(offsetof(CpuState, fs_data) == 248);
static_assert(offsetof(NativeCallFrame, state) == 0 && offsetof(NativeCallFrame, native_st0) == 40);

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

int run_compiled_slice() {
    configure_guest_environment();
    g_deep_diagnostics = GetEnvironmentVariableW(kDeepDiagnosticsEnvironment, nullptr, 0) != 0;
    diagnostic_note(g_deep_diagnostics ? "structured IR execution mode: deep diagnostics" : "structured IR execution mode: fast");
    Runtime runtime;
    return runtime.execute();
}

} // namespace lifted
