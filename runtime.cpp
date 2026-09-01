#include "runtime.h"
#include "diagnostics.h"
#include "lifted_functions.h"
#include "semantic_static.h"
#include "native_callbacks.h"

#include <intrin.h>
#include <algorithm>
#include <cstdio>
#include <cwchar>
#include <cstring>
#include <limits>
#include <malloc.h>
#include <stdexcept>
#include <vector>

#if defined(_MSC_VER)
#pragma intrinsic(__readfsdword)
#endif

namespace lifted {

static NativeRuntime* g_runtime = nullptr;
static ProcessMemory* g_process_memory = nullptr;

static void __cdecl native_call_bridge(NativeCallFrame* frame);

namespace {

constexpr wchar_t kClientRootEnvironment[] = L"SFERA_CLIENT_ROOT";
thread_local std::uint32_t g_lifted_exception_list = 0xFFFFFFFFu;
std::vector<LiftFunction> g_lifted_finalizers;

std::uint32_t native_stack_top(void* memory, std::size_t size) noexcept { const std::uintptr_t value = reinterpret_cast<std::uintptr_t>(static_cast<std::uint8_t*>(memory) + size - 64u); return static_cast<std::uint32_t>(value & ~std::uintptr_t{0xFu}); }

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


} // namespace


bool register_lifted_finalizer(LiftFunction function) {
    if (!function) { return false; }
    try { g_lifted_finalizers.push_back(function); return true; } catch (...) { return false; }
}


void lift_push32(LiftCpu* cpu, std::uint32_t value) {
    cpu->esp -= 4u;
    memory_write(cpu->esp, value);
}

std::uint32_t lift_pop32(LiftCpu* cpu) {
    const std::uint32_t value = memory_read<std::uint32_t>(cpu->esp);
    cpu->esp += 4u;
    return value;
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

ProcessMemory::ProcessMemory() {
    if (g_process_memory) { throw std::runtime_error("Only one process-memory instance is supported"); }
    if (sizeof(void*) != 4 || 0x014Cu != IMAGE_FILE_MACHINE_I386) { throw std::runtime_error("Generated runtime requires Win32/x86"); }
    DiagnosticPhaseScope phase(RuntimePhase::static_storage);
    g_process_memory = this;
    diagnostic_note("semantic native storage ready; native entries=static, lifted targets=direct, semantic-rdata=eliminated, semantic-data=native");
}

ProcessMemory::~ProcessMemory() { release(); }

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

void ProcessMemory::initialize_native() {
    try {
        { DiagnosticPhaseScope phase(RuntimePhase::protect_static_storage); protect_regions(); diagnostic_note("semantic static-region protections applied"); }
    } catch (...) { release(); throw; }
}

void ProcessMemory::protect_regions() {}

void ProcessMemory::release() noexcept { if (g_process_memory == this) { g_process_memory = nullptr; } }

namespace {


#if !defined(SFERA_PORTABLE_CHECK) && defined(_M_IX86)

__declspec(noinline) std::uint32_t __cdecl bridge_test_cdecl(std::uint32_t left, std::uint32_t right) { return left + right * 3u; }
__declspec(noinline) std::uint32_t __stdcall bridge_test_stdcall(std::uint32_t left, std::uint32_t right) { return left ^ (right + 0x13579BDFu); }
__declspec(noinline) std::uint32_t __fastcall bridge_test_fastcall(std::uint32_t left, std::uint32_t right, std::uint32_t stack_value) { return left + right + stack_value; }

void verify_native_bridge() {
    DiagnosticPhaseScope phase(RuntimePhase::abi_self_test);
    void* stack_memory = _alloca(64u * 1024u + 64u);
    LiftCpu state{};
    auto prepare = [&]() {
        state = LiftCpu{};
        state.esp = native_stack_top(stack_memory, 64u * 1024u + 64u);
        state.ebx = 0xB1B2B3B4u;
        state.ebp = 0xB5B6B7B8u;
        state.esi = 0x51525354u;
        state.edi = 0xD1D2D3D4u;
    };
    auto verify_nonvolatile = [&]() {
        if (state.ebx != 0xB1B2B3B4u || state.ebp != 0xB5B6B7B8u || state.esi != 0x51525354u || state.edi != 0xD1D2D3D4u) { throw std::runtime_error("Native bridge corrupted a nonvolatile x86 register"); }
    };
    auto verify_teb = [&](const NativeCallFrame& frame, const char* convention, std::uint32_t actual_exception_list, std::uint32_t actual_stack_high, std::uint32_t actual_stack_low, std::uint32_t expected_stack_high, std::uint32_t expected_stack_low) {
        const std::uint32_t expected_exception_list = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(frame.previous_exception_list));
        if (actual_exception_list == expected_exception_list && actual_stack_high == expected_stack_high && actual_stack_low == expected_stack_low) { return; }
        throw std::runtime_error(std::string("Native bridge failed to restore the host TEB after ") + convention);
    };
    const std::uint32_t host_stack_high = __readfsdword(4);
    const std::uint32_t host_stack_low = __readfsdword(8);
    prepare();
    lift_push32(&state, 7u);
    lift_push32(&state, 5u);
    const std::uint32_t cdecl_esp = state.esp;
    NativeCallFrame cdecl_frame{&state, reinterpret_cast<void*>(&bridge_test_cdecl), 0, 0, 0, 0, 0, nullptr, 0xFFFFFFFFu};
    native_call_bridge(&cdecl_frame);
    const std::uint32_t cdecl_exception_list = __readfsdword(0);
    const std::uint32_t cdecl_stack_high = __readfsdword(4);
    const std::uint32_t cdecl_stack_low = __readfsdword(8);
    if (state.eax != 26u || state.esp != cdecl_esp) { throw std::runtime_error("Native bridge failed its cdecl stack test"); }
    verify_teb(cdecl_frame, "cdecl", cdecl_exception_list, cdecl_stack_high, cdecl_stack_low, host_stack_high, host_stack_low);
    verify_nonvolatile();
    prepare();
    lift_push32(&state, 0x2468ACE0u);
    lift_push32(&state, 0x10203040u);
    const std::uint32_t stdcall_esp = state.esp;
    NativeCallFrame stdcall_frame{&state, reinterpret_cast<void*>(&bridge_test_stdcall), 0, 0, 0, 0, 0, nullptr, 0xFFFFFFFFu};
    native_call_bridge(&stdcall_frame);
    const std::uint32_t stdcall_exception_list = __readfsdword(0);
    const std::uint32_t stdcall_stack_high = __readfsdword(4);
    const std::uint32_t stdcall_stack_low = __readfsdword(8);
    if (state.eax != (0x10203040u ^ (0x2468ACE0u + 0x13579BDFu)) || state.esp != stdcall_esp + 8u) { throw std::runtime_error("Native bridge failed its stdcall stack test"); }
    verify_teb(stdcall_frame, "stdcall", stdcall_exception_list, stdcall_stack_high, stdcall_stack_low, host_stack_high, host_stack_low);
    verify_nonvolatile();
    prepare();
    state.ecx = 11u;
    state.edx = 13u;
    lift_push32(&state, 17u);
    const std::uint32_t fastcall_esp = state.esp;
    NativeCallFrame fastcall_frame{&state, reinterpret_cast<void*>(&bridge_test_fastcall), 0, 0, 0, 0, 0, nullptr, 0xFFFFFFFFu};
    native_call_bridge(&fastcall_frame);
    const std::uint32_t fastcall_exception_list = __readfsdword(0);
    const std::uint32_t fastcall_stack_high = __readfsdword(4);
    const std::uint32_t fastcall_stack_low = __readfsdword(8);
    if (state.eax != 41u || state.esp != fastcall_esp + 4u) { throw std::runtime_error("Native bridge failed its fastcall stack test"); }
    verify_teb(fastcall_frame, "fastcall", fastcall_exception_list, fastcall_stack_high, fastcall_stack_low, host_stack_high, host_stack_low);
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
    diagnostic_note("native runtime initialized");
}

void NativeRuntime::call_native(LiftCpu& state, std::uint32_t target, std::uint32_t callsite) {
    if (target < 0x10000u) { throw std::runtime_error("Invalid native call target " + hex_u32(target) + " at " + hex_u32(callsite)); }
    NativeCallFrame frame{&state, reinterpret_cast<void*>(static_cast<std::uintptr_t>(target)), 0, 0, 0, 0, 0, nullptr, g_lifted_exception_list};
    native_call_bridge(&frame);
}

void lift_native_call(LiftCpu* cpu, std::uint32_t target, std::uint32_t callsite) {
    if (!g_runtime || !cpu) { throw std::runtime_error("Native call without an active native runtime"); }
    g_runtime->call_native(*cpu, target, callsite);
}

int NativeRuntime::execute() {
    DiagnosticPhaseScope phase(RuntimePhase::execution_setup);
    void* stack_memory = _alloca(kStackReserve + 64u);
    LiftCpu state{};
    state.esp = native_stack_top(stack_memory, kStackReserve + 64u);
    state.eip = LIFT_CODE_TOKEN_RVA(0x000EF142u);
    lift_push32(&state, LIFT_RETURN_SENTINEL);
    DiagnosticRunScope run_scope(&state);
    DiagnosticExecutionScope execution_scope(state.eip, LIFT_RETURN_SENTINEL, state.esp);
    diagnostic_note("entering generated entry function");
    g_runtime = this;
    try {
        DiagnosticPhaseScope native_phase(RuntimePhase::native_c);
        sfera_sub_004EF142(&state, LIFT_RETURN_SENTINEL);
        const int result = static_cast<int>(state.eax);
        const std::uint32_t finalizer_stack_top = native_stack_top(stack_memory, kStackReserve + 64u);
        while (!g_lifted_finalizers.empty()) {
            const LiftFunction function = g_lifted_finalizers.back();
            g_lifted_finalizers.pop_back();
            LiftCpu finalizer_state{};
            finalizer_state.esp = finalizer_stack_top;
            lift_push32(&finalizer_state, LIFT_RETURN_SENTINEL);
            function(&finalizer_state, LIFT_RETURN_SENTINEL);
        }
        g_runtime = nullptr;
        return result;
    } catch (const std::exception& error) {
        g_lifted_finalizers.clear();
        diagnostic_failure(state, error.what());
        g_runtime = nullptr;
        throw;
    } catch (...) {
        g_lifted_finalizers.clear();
        diagnostic_failure(state, "Unknown failure in generated code");
        g_runtime = nullptr;
        throw;
    }
}

#if defined(SFERA_PORTABLE_CHECK)

static void __cdecl native_call_bridge(NativeCallFrame*) {}

#elif defined(_M_IX86)

static_assert(offsetof(LiftCpu, eax) == 0 && offsetof(LiftCpu, eip) == 32 && sizeof(LiftCpu) == 36);
static_assert(offsetof(NativeCallFrame, state) == 0 && offsetof(NativeCallFrame, previous_exception_list) == 28 && offsetof(NativeCallFrame, lifted_exception_list) == 32 && sizeof(NativeCallFrame) == 36);

__declspec(naked) static void __cdecl native_call_bridge(NativeCallFrame*) {
    __asm {
        mov edx, [esp + 4]
        mov [edx + 8], esp
        mov [edx + 12], ebp
        mov [edx + 16], ebx
        mov [edx + 20], esi
        mov [edx + 24], edi
        mov eax, fs:[0]
        mov [edx + 28], eax
        mov eax, [edx]
        mov ecx, [edx + 32]
        mov fs:[0], ecx
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
        mov eax, [edx + 28]
        mov fs:[0], eax
        mov esp, [edx + 8]
        mov ebp, [edx + 12]
        mov ebx, [edx + 16]
        mov esi, [edx + 20]
        mov edi, [edx + 24]
        ret
    }
}


#else
#error The generated runtime must be compiled for Win32/x86.
#endif

int run_native_program() {
    configure_process_environment();
    diagnostic_note("generated execution: optimized");
    NativeRuntime runtime;
    return runtime.execute();
}

} // namespace lifted
