#include "runtime.h"

#include "diagnostics.h"
#include "native_image.h"
#include "semantic_bridge.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <unordered_map>

namespace sfera::runtime {
namespace {

constexpr wchar_t kClientRootEnvironment[] = L"SFERA_CLIENT_ROOT";
std::uint8_t* g_mapped_image = nullptr;
std::string g_client_executable_ansi;
FARPROC g_direct_input8_create = nullptr;

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

std::string narrow_path(const std::wstring& value, UINT code_page = CP_UTF8) {
    if (value.empty()) { return {}; }
    const int required = WideCharToMultiByte(code_page, 0, value.data(), static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    if (required <= 0) { throw std::runtime_error(win32_error("WideCharToMultiByte")); }
    std::string result(static_cast<std::size_t>(required), '\0');
    if (WideCharToMultiByte(code_page, 0, value.data(), static_cast<int>(value.size()), result.data(), required, nullptr, nullptr) != required) { throw std::runtime_error(win32_error("WideCharToMultiByte")); }
    return result;
}

std::wstring client_executable_path() {
    const std::wstring filename(sfera::image::kClientExecutableName.begin(), sfera::image::kClientExecutableName.end());
    return path_join(client_root_directory(), filename);
}

DWORD page_protection(std::uint8_t access) {
    const bool read = (access & sfera::image::kRead) != 0;
    const bool write = (access & sfera::image::kWrite) != 0;
    const bool execute = (access & sfera::image::kExecute) != 0;
    if (execute && write) { return PAGE_EXECUTE_READWRITE; }
    if (execute && read) { return PAGE_EXECUTE_READ; }
    if (execute) { return PAGE_EXECUTE; }
    if (write) { return PAGE_READWRITE; }
    if (read) { return PAGE_READONLY; }
    return PAGE_NOACCESS;
}

std::uint32_t align_down(std::uint32_t value, std::uint32_t alignment) noexcept { return value & ~(alignment - 1u); }
std::uint32_t align_up(std::uint32_t value, std::uint32_t alignment) noexcept { return (value + alignment - 1u) & ~(alignment - 1u); }

HMODULE WINAPI image_get_module_handle_a(LPCSTR module_name) {
    if (!module_name || module_name[0] == '\0') { return reinterpret_cast<HMODULE>(g_mapped_image); }
    return GetModuleHandleA(module_name);
}

DWORD WINAPI image_get_module_file_name_a(HMODULE module, LPSTR filename, DWORD capacity) {
    if (module && module != reinterpret_cast<HMODULE>(g_mapped_image)) { return GetModuleFileNameA(module, filename, capacity); }
    if (!filename || capacity == 0u) { SetLastError(ERROR_INSUFFICIENT_BUFFER); return 0u; }
    const std::size_t length = g_client_executable_ansi.size();
    if (length >= capacity) {
        const std::size_t copied = capacity > 1u ? static_cast<std::size_t>(capacity - 1u) : 0u;
        if (copied != 0u) { std::memcpy(filename, g_client_executable_ansi.data(), copied); }
        filename[copied] = '\0';
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        return capacity;
    }
    std::memcpy(filename, g_client_executable_ansi.data(), length);
    filename[length] = '\0';
    return static_cast<DWORD>(length);
}

LONG WINAPI image_direct_input8_create(HINSTANCE instance, DWORD version, const void* iid, void** output, void* outer) {
    using DirectInput8CreateFn = LONG (WINAPI*)(HINSTANCE, DWORD, const void*, void**, void*);
    const auto real = reinterpret_cast<DirectInput8CreateFn>(g_direct_input8_create);
    if (!real) { return static_cast<LONG>(0x80004005u); }
    HINSTANCE native_instance = instance;
    if (instance == reinterpret_cast<HINSTANCE>(g_mapped_image)) { native_instance = reinterpret_cast<HINSTANCE>(GetModuleHandleA(nullptr)); }
    const LONG result = real(native_instance, version, iid, output, outer);
    if (native_instance != instance) {
        char note[192]{};
        _snprintf_s(note, sizeof(note), _TRUNCATE, "virtualized DirectInput8Create module image=%08lX host=%08lX result=%08lX", static_cast<unsigned long>(reinterpret_cast<std::uintptr_t>(instance)), static_cast<unsigned long>(reinterpret_cast<std::uintptr_t>(native_instance)), static_cast<unsigned long>(result));
        diagnostic_note(note);
    }
    return result;
}

FARPROC virtualized_import(const sfera::image::ImportDescriptor& item) noexcept {
    if (!item.by_ordinal && _stricmp(std::string(item.dll).c_str(), "KERNEL32.dll") == 0) {
        if (item.name == "GetModuleHandleA") { return reinterpret_cast<FARPROC>(&image_get_module_handle_a); }
        if (item.name == "GetModuleFileNameA") { return reinterpret_cast<FARPROC>(&image_get_module_file_name_a); }
    }
    return nullptr;
}

} // namespace

std::string win32_error(const char* operation, DWORD error) {
    return std::string(operation ? operation : "Win32 operation") + " failed with Win32 error " + std::to_string(static_cast<unsigned long>(error));
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
        for (const std::wstring& candidate : candidates) { if (is_client_root(candidate)) { return candidate; } }
        throw std::runtime_error("Unable to locate mbc\\_main.mbc. Set SFERA_CLIENT_ROOT to the client directory that contains the mbc folder.");
    }();
    return root;
}

void configure_process_environment() {
    const std::wstring& root = client_root_directory();
    if (!SetCurrentDirectoryW(root.c_str())) { throw std::runtime_error(win32_error("SetCurrentDirectoryW")); }
    g_client_executable_ansi = narrow_path(client_executable_path(), CP_ACP);
    diagnostic_note(("client resource root: " + narrow_path(root)).c_str());
}

ProcessImage::ProcessImage() { reserve_image(); }
ProcessImage::~ProcessImage() { release(); }

std::uint32_t ProcessImage::load_base() const noexcept { return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(image_)); }
std::uint32_t ProcessImage::entry_va() const noexcept { return load_base() + sfera::image::kEntryRva; }
std::uint8_t* ProcessImage::data() noexcept { return image_; }
const std::uint8_t* ProcessImage::data() const noexcept { return image_; }

std::uint32_t ProcessImage::source_address(std::uint32_t source_va) const {
    if (source_va < sfera::image::kSourceImageBase || source_va >= sfera::image::kSourceImageBase + sfera::image::kImageSize) { throw std::runtime_error("Source VA is outside the embedded image"); }
    return load_base() + (source_va - sfera::image::kSourceImageBase);
}

void ProcessImage::reserve_image() {
    if (sizeof(void*) != 4 || sfera::image::kMachine != IMAGE_FILE_MACHINE_I386) { throw std::runtime_error("Sfera frozen runtime requires Win32/x86"); }
    image_ = static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(static_cast<std::uintptr_t>(sfera::image::kSourceImageBase)), sfera::image::kImageSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!image_) { image_ = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, sfera::image::kImageSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE)); }
    if (!image_) { throw std::runtime_error(win32_error("VirtualAlloc(native image)")); }
    if (reinterpret_cast<std::uintptr_t>(image_) >= UINT32_C(0x80000000)) { release(); throw std::runtime_error("Mapped image is outside the non-LAA Win32 address space"); }
    g_mapped_image = image_;
    set_mapped_image(load_base(), sfera::image::kImageSize, sfera::image::kSourceImageBase);
}

void ProcessImage::copy_image() {
    const std::vector<std::uint8_t> file = sfera::image::decode_mapped_payload();
    if (sfera::image::kHeadersSize > file.size() || sfera::image::kHeadersSize > sfera::image::kImageSize) { throw std::runtime_error("Invalid embedded PE headers"); }
    std::memcpy(image_, file.data(), sfera::image::kHeadersSize);
    for (const sfera::image::SectionDescriptor& section : sfera::image::kSections) {
        const std::uint64_t source_end = static_cast<std::uint64_t>(section.raw_offset) + section.raw_size;
        const std::uint64_t target_end = static_cast<std::uint64_t>(section.virtual_address) + std::max(section.virtual_size, section.raw_size);
        if (source_end > file.size() || target_end > sfera::image::kImageSize) { throw std::runtime_error("Invalid embedded PE section range"); }
        if (section.raw_size != 0u) { std::memcpy(image_ + section.virtual_address, file.data() + section.raw_offset, section.raw_size); }
    }
}

void ProcessImage::apply_relocations() {
    const std::uint32_t delta = load_base() - sfera::image::kSourceImageBase;
    if (delta == 0u) { return; }
    if (sfera::image::kHeadersSize < sizeof(IMAGE_DOS_HEADER)) { throw std::runtime_error("Invalid mapped DOS header size"); }
    const auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(image_);
    if (dos->e_magic != IMAGE_DOS_SIGNATURE || dos->e_lfanew <= 0) { throw std::runtime_error("Invalid mapped DOS header"); }
    const std::uint32_t pe_rva = static_cast<std::uint32_t>(dos->e_lfanew);
    if (pe_rva > sfera::image::kHeadersSize || sfera::image::kHeadersSize - pe_rva < sizeof(IMAGE_NT_HEADERS32)) { throw std::runtime_error("Invalid mapped PE header"); }
    const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS32*>(image_ + pe_rva);
    if (nt->Signature != IMAGE_NT_SIGNATURE || nt->FileHeader.Machine != IMAGE_FILE_MACHINE_I386 || nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC) { throw std::runtime_error("Invalid mapped PE32 header"); }
    if (nt->OptionalHeader.NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_BASERELOC) { throw std::runtime_error("Mapped PE has no relocation directory"); }
    const IMAGE_DATA_DIRECTORY& directory = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
    if (directory.VirtualAddress == 0u || directory.Size < sizeof(IMAGE_BASE_RELOCATION)) { throw std::runtime_error("Mapped PE relocation directory is empty"); }
    const std::uint64_t directory_end = static_cast<std::uint64_t>(directory.VirtualAddress) + directory.Size;
    if (directory_end > sfera::image::kImageSize) { throw std::runtime_error("Mapped PE relocation directory is outside the image"); }
    std::uint32_t cursor = directory.VirtualAddress;
    std::size_t applied = 0u;
    while (cursor < directory_end) {
        if (directory_end - cursor < sizeof(IMAGE_BASE_RELOCATION)) { throw std::runtime_error("Truncated PE relocation block"); }
        const auto* block = reinterpret_cast<const IMAGE_BASE_RELOCATION*>(image_ + cursor);
        if (block->SizeOfBlock < sizeof(IMAGE_BASE_RELOCATION) || (block->SizeOfBlock & 1u) != 0u || static_cast<std::uint64_t>(cursor) + block->SizeOfBlock > directory_end) { throw std::runtime_error("Invalid PE relocation block"); }
        const std::uint32_t entry_count = (block->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(std::uint16_t);
        const auto* entries = reinterpret_cast<const std::uint16_t*>(image_ + cursor + sizeof(IMAGE_BASE_RELOCATION));
        for (std::uint32_t index = 0; index < entry_count; ++index) {
            const std::uint16_t entry = entries[index];
            const std::uint16_t type = entry >> 12u;
            if (type == IMAGE_REL_BASED_ABSOLUTE) { continue; }
            if (type != IMAGE_REL_BASED_HIGHLOW) { throw std::runtime_error("Unsupported PE32 relocation type " + std::to_string(type)); }
            const std::uint32_t target_rva = block->VirtualAddress + (entry & 0x0FFFu);
            if (target_rva > sfera::image::kImageSize || sfera::image::kImageSize - target_rva < sizeof(std::uint32_t)) { throw std::runtime_error("PE relocation target is outside the image"); }
            std::uint32_t value = 0u;
            std::memcpy(&value, image_ + target_rva, sizeof(value));
            value += delta;
            std::memcpy(image_ + target_rva, &value, sizeof(value));
            ++applied;
        }
        cursor += block->SizeOfBlock;
    }
    diagnostic_note(("applied " + std::to_string(applied) + " PE HIGHLOW relocations, delta=0x" + [] (std::uint32_t value) { char buffer[9]{}; std::snprintf(buffer, sizeof(buffer), "%08X", static_cast<unsigned>(value)); return std::string(buffer); }(delta)).c_str());
}

void ProcessImage::patch_image_base() {
    if (sfera::image::kHeadersSize < 0x40u || image_[0] != 'M' || image_[1] != 'Z') { throw std::runtime_error("Invalid mapped DOS header"); }
    std::uint32_t pe_offset = 0;
    std::memcpy(&pe_offset, image_ + 0x3Cu, sizeof(pe_offset));
    const std::uint64_t image_base_offset = static_cast<std::uint64_t>(pe_offset) + 24u + 28u;
    if (image_base_offset + sizeof(std::uint32_t) > sfera::image::kHeadersSize) { throw std::runtime_error("Invalid mapped PE optional header"); }
    const std::uint32_t base = load_base();
    std::memcpy(image_ + image_base_offset, &base, sizeof(base));
}

void ProcessImage::resolve_imports() {
    std::unordered_map<std::string, HMODULE> modules;
    for (const sfera::image::ImportDescriptor& item : sfera::image::kImports) {
        FARPROC address = virtualized_import(item);
        if (!address) {
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
            address = GetProcAddress(module, symbol);
            if (!address) {
                const std::string label = item.by_ordinal ? "ordinal " + std::to_string(item.ordinal) : std::string(item.name);
                throw std::runtime_error(win32_error(("GetProcAddress(" + dll + ", " + label + ")").c_str()));
            }
            if (!item.by_ordinal && item.process_module_argument == 0 && _stricmp(dll.c_str(), "DINPUT8.dll") == 0 && item.name == "DirectInput8Create") {
                g_direct_input8_create = address;
                address = reinterpret_cast<FARPROC>(&image_direct_input8_create);
            }
        }
        const std::uintptr_t raw = reinterpret_cast<std::uintptr_t>(address);
        if (raw > std::numeric_limits<std::uint32_t>::max()) { throw std::runtime_error("Resolved Win32 import is outside the x86 address space"); }
        const std::uint32_t value = static_cast<std::uint32_t>(raw);
        std::memcpy(image_ + item.iat_rva, &value, sizeof(value));
    }
}

void ProcessImage::protect_image() {
    constexpr std::uint32_t page_size = 0x1000u;
    auto protect = [this](std::uint32_t rva, std::uint32_t size, DWORD protection) {
        if (size == 0u) { return; }
        const std::uint32_t begin = align_down(rva, page_size);
        const std::uint32_t end = align_up(rva + size, page_size);
        DWORD old_protection = 0;
        if (end > sfera::image::kImageSize || !VirtualProtect(image_ + begin, end - begin, protection, &old_protection)) { throw std::runtime_error(win32_error("VirtualProtect(native image)")); }
    };
    protect(0u, sfera::image::kHeadersSize, PAGE_READONLY);
    for (const sfera::image::SectionDescriptor& section : sfera::image::kSections) { protect(section.virtual_address, std::max(section.virtual_size, section.raw_size), page_protection(section.access)); }
}

void ProcessImage::initialize() {
    DiagnosticPhaseScope map_scope(RuntimePhase::map_image);
    copy_image();
    apply_relocations();
    patch_image_base();
    {
        DiagnosticPhaseScope import_scope(RuntimePhase::load_imports);
        resolve_imports();
    }
    bridge::attach_semantic_runtime(load_base());
    {
        DiagnosticPhaseScope protect_scope(RuntimePhase::protect_image);
        protect_image();
    }
    FlushInstructionCache(GetCurrentProcess(), image_, sfera::image::kImageSize);
    diagnostic_note(("native image mapped at 0x" + [] (std::uint32_t value) { char buffer[9]{}; std::snprintf(buffer, sizeof(buffer), "%08X", static_cast<unsigned>(value)); return std::string(buffer); }(load_base())).c_str());
}

[[noreturn]] void ProcessImage::execute_entrypoint() {
    using EntryPoint = void (__cdecl*)();
    const auto entry = reinterpret_cast<EntryPoint>(static_cast<std::uintptr_t>(entry_va()));
    set_runtime_phase(RuntimePhase::native_execution);
    diagnostic_note("entering original native image entry point");
    entry();
    throw std::runtime_error("Original PE entry point returned unexpectedly");
}

void ProcessImage::release() noexcept {
    if (g_mapped_image == image_) { g_mapped_image = nullptr; }
    g_direct_input8_create = nullptr;
    for (auto iterator = loaded_modules_.rbegin(); iterator != loaded_modules_.rend(); ++iterator) { if (*iterator) { FreeLibrary(*iterator); } }
    loaded_modules_.clear();
    if (image_) { VirtualFree(image_, 0, MEM_RELEASE); image_ = nullptr; }
}

int run_native_program() {
    configure_process_environment();
    ProcessImage image;
    image.initialize();
    image.execute_entrypoint();
}

} // namespace sfera::runtime
