#include "diagnostics.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <DbgHelp.h>

#include <array>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <cwchar>

namespace sfera::runtime {
namespace {

thread_local RuntimePhase g_phase = RuntimePhase::startup;
thread_local bool g_writing_report = false;
std::uint32_t g_runtime_image_base = 0u;
std::uint32_t g_runtime_image_size = 0u;
std::uint32_t g_source_image_base = 0u;
wchar_t g_artifact_directory[MAX_PATH]{};
std::size_t g_artifact_directory_length = 0u;

const char* phase_name(RuntimePhase phase) noexcept {
    switch (phase) {
        case RuntimePhase::startup: return "startup";
        case RuntimePhase::process_startup: return "process-startup";
        case RuntimePhase::map_image: return "map-image";
        case RuntimePhase::load_imports: return "load-imports";
        case RuntimePhase::protect_image: return "protect-image";
        case RuntimePhase::native_execution: return "native-execution";
    }
    return "unknown";
}

void initialize_artifact_directory() noexcept {
    const DWORD length = GetModuleFileNameW(nullptr, g_artifact_directory, MAX_PATH);
    if (length == 0u || length >= MAX_PATH) { return; }
    g_artifact_directory_length = length;
    while (g_artifact_directory_length != 0u && g_artifact_directory[g_artifact_directory_length - 1u] != L'\\' && g_artifact_directory[g_artifact_directory_length - 1u] != L'/') { --g_artifact_directory_length; }
    g_artifact_directory[g_artifact_directory_length] = L'\0';
}

bool artifact_path(const wchar_t* filename, wchar_t* path, std::size_t capacity) noexcept {
    if (!filename || !path || capacity == 0u) { return false; }
    const std::size_t filename_length = std::wcslen(filename);
    if (g_artifact_directory_length + filename_length + 1u > capacity) { return false; }
    std::memcpy(path, g_artifact_directory, g_artifact_directory_length * sizeof(wchar_t));
    std::memcpy(path + g_artifact_directory_length, filename, (filename_length + 1u) * sizeof(wchar_t));
    return true;
}

void write_bytes(const wchar_t* filename, const char* bytes, std::size_t size, DWORD creation) noexcept {
    wchar_t path[MAX_PATH]{};
    if (!artifact_path(filename, path, MAX_PATH)) { return; }
    const DWORD access = creation == OPEN_ALWAYS ? FILE_APPEND_DATA : GENERIC_WRITE;
    HANDLE file = CreateFileW(path, access, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, creation, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) { return; }
    if (creation == OPEN_ALWAYS) { SetFilePointer(file, 0, nullptr, FILE_END); }
    DWORD written = 0u;
    WriteFile(file, bytes, static_cast<DWORD>(size), &written, nullptr);
    if (creation != OPEN_ALWAYS) { FlushFileBuffers(file); }
    CloseHandle(file);
}

void append_text(char* buffer, std::size_t capacity, std::size_t& used, const char* format, ...) noexcept {
    if (used >= capacity) { return; }
    va_list arguments;
    va_start(arguments, format);
    const int count = _vsnprintf_s(buffer + used, capacity - used, _TRUNCATE, format, arguments);
    va_end(arguments);
    if (count >= 0) { used += static_cast<std::size_t>(count); }
    else { used = std::strlen(buffer); }
}

void append_module_location(char* report, std::size_t capacity, std::size_t& used, std::uintptr_t address) noexcept {
    if (g_runtime_image_base != 0u && address >= g_runtime_image_base && address < static_cast<std::uintptr_t>(g_runtime_image_base) + g_runtime_image_size) {
        const std::uint32_t rva = static_cast<std::uint32_t>(address - g_runtime_image_base);
        append_text(report, capacity, used, "mapped-image-base=%08X rva=%08X source-va=%08X\r\n", g_runtime_image_base, rva, g_source_image_base + rva);
        return;
    }
    MEMORY_BASIC_INFORMATION memory{};
    if (VirtualQuery(reinterpret_cast<const void*>(address), &memory, sizeof(memory)) != sizeof(memory) || !memory.AllocationBase) { return; }
    char module_path[MAX_PATH]{};
    const DWORD length = GetModuleFileNameA(static_cast<HMODULE>(memory.AllocationBase), module_path, MAX_PATH);
    if (length == 0u) { return; }
    const auto base = reinterpret_cast<std::uintptr_t>(memory.AllocationBase);
    append_text(report, capacity, used, "module=%s base=%08lX rva=%08lX\r\n", module_path, static_cast<unsigned long>(base), static_cast<unsigned long>(address - base));
}

void append_runtime_state(char* report, std::size_t capacity, std::size_t& used) noexcept {
    if (g_runtime_image_base == 0u || g_source_image_base == 0u) { return; }
    struct Probe { const char* name; std::uint32_t source_va; };
    constexpr Probe probes[] = {{"renderer", UINT32_C(0x04F4CC10)}, {"client-hinstance", UINT32_C(0x04E2C8DC)}, {"directinput", UINT32_C(0x04DD9170)}};
    append_text(report, capacity, used, "runtime-globals:");
    for (const Probe& probe : probes) {
        if (probe.source_va < g_source_image_base) { continue; }
        const std::uint32_t rva = probe.source_va - g_source_image_base;
        if (rva > g_runtime_image_size || g_runtime_image_size - rva < sizeof(std::uint32_t)) { continue; }
        std::uint32_t value = 0u;
        SIZE_T read = 0u;
        if (ReadProcessMemory(GetCurrentProcess(), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(g_runtime_image_base + rva)), &value, sizeof(value), &read) && read == sizeof(value)) { append_text(report, capacity, used, " %s=%08X", probe.name, value); }
    }
    append_text(report, capacity, used, "\r\n");
}

void append_stack(char* report, std::size_t capacity, std::size_t& used, std::uint32_t esp) noexcept {
    std::array<std::uint32_t, 24> stack{};
    SIZE_T read = 0u;
    if (!ReadProcessMemory(GetCurrentProcess(), reinterpret_cast<const void*>(static_cast<std::uintptr_t>(esp)), stack.data(), sizeof(stack), &read) || read < sizeof(std::uint32_t)) { return; }
    append_text(report, capacity, used, "stack-dwords:");
    const std::size_t count = read / sizeof(std::uint32_t);
    for (std::size_t index = 0; index < count; ++index) { append_text(report, capacity, used, " %08X", stack[index]); }
    append_text(report, capacity, used, "\r\n");
}

void write_minidump(EXCEPTION_POINTERS* pointers) noexcept {
    wchar_t dump_path[MAX_PATH]{};
    wchar_t system_path[MAX_PATH]{};
    if (!artifact_path(L"sfera_native_crash.dmp", dump_path, MAX_PATH)) { return; }
    const UINT system_length = GetSystemDirectoryW(system_path, MAX_PATH);
    constexpr wchar_t suffix[] = L"\\dbghelp.dll";
    if (system_length == 0u || system_length + std::size(suffix) > MAX_PATH) { return; }
    std::memcpy(system_path + system_length, suffix, sizeof(suffix));
    HMODULE dbghelp = LoadLibraryW(system_path);
    if (!dbghelp) { return; }
    using WriteDump = BOOL(WINAPI*)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, const MINIDUMP_EXCEPTION_INFORMATION*, const MINIDUMP_USER_STREAM_INFORMATION*, const MINIDUMP_CALLBACK_INFORMATION*);
    const auto write_dump = reinterpret_cast<WriteDump>(GetProcAddress(dbghelp, "MiniDumpWriteDump"));
    HANDLE file = CreateFileW(dump_path, GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (write_dump && file != INVALID_HANDLE_VALUE) {
        MINIDUMP_EXCEPTION_INFORMATION information{};
        information.ThreadId = GetCurrentThreadId();
        information.ExceptionPointers = pointers;
        information.ClientPointers = FALSE;
        const MINIDUMP_TYPE type = static_cast<MINIDUMP_TYPE>(MiniDumpWithDataSegs | MiniDumpWithHandleData | MiniDumpWithUnloadedModules | MiniDumpWithThreadInfo);
        write_dump(GetCurrentProcess(), GetCurrentProcessId(), file, type, &information, nullptr, nullptr);
    }
    if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); }
    FreeLibrary(dbghelp);
}

void write_crash_report(EXCEPTION_POINTERS* pointers) noexcept {
    if (!pointers || !pointers->ExceptionRecord || !pointers->ContextRecord || g_writing_report) { return; }
    g_writing_report = true;
    char report[32768]{};
    std::size_t used = 0u;
    const EXCEPTION_RECORD& record = *pointers->ExceptionRecord;
    const CONTEXT& context = *pointers->ContextRecord;
    append_text(report, sizeof(report), used, "Sfera frozen native-image runtime crash\r\n");
    append_text(report, sizeof(report), used, "pid=%lu tid=%lu phase=%s\r\n", GetCurrentProcessId(), GetCurrentThreadId(), phase_name(g_phase));
    append_text(report, sizeof(report), used, "exception=0x%08lX address=%p\r\n", record.ExceptionCode, record.ExceptionAddress);
    append_module_location(report, sizeof(report), used, reinterpret_cast<std::uintptr_t>(record.ExceptionAddress));
    append_runtime_state(report, sizeof(report), used);
    if (record.ExceptionCode == EXCEPTION_ACCESS_VIOLATION && record.NumberParameters >= 2u) {
        const char* access = record.ExceptionInformation[0] == 0u ? "read" : record.ExceptionInformation[0] == 1u ? "write" : record.ExceptionInformation[0] == 8u ? "execute" : "unknown";
        append_text(report, sizeof(report), used, "access=%s target=0x%08lX\r\n", access, static_cast<unsigned long>(record.ExceptionInformation[1]));
    }
#if defined(_M_IX86)
    append_text(report, sizeof(report), used, "eip=%08lX esp=%08lX ebp=%08lX eax=%08lX ebx=%08lX ecx=%08lX edx=%08lX esi=%08lX edi=%08lX eflags=%08lX\r\n", context.Eip, context.Esp, context.Ebp, context.Eax, context.Ebx, context.Ecx, context.Edx, context.Esi, context.Edi, context.EFlags);
    append_stack(report, sizeof(report), used, context.Esp);
#endif
    write_bytes(L"sfera_native_crash.txt", report, used, CREATE_ALWAYS);
    OutputDebugStringA(report);
    write_minidump(pointers);
    g_writing_report = false;
}

LONG CALLBACK vectored_exception_handler(EXCEPTION_POINTERS* pointers) noexcept {
    if (!pointers || !pointers->ExceptionRecord) { return EXCEPTION_CONTINUE_SEARCH; }
    const DWORD code = pointers->ExceptionRecord->ExceptionCode;
    if (code == EXCEPTION_ACCESS_VIOLATION || code == EXCEPTION_ILLEGAL_INSTRUCTION || code == EXCEPTION_STACK_OVERFLOW || code == EXCEPTION_ARRAY_BOUNDS_EXCEEDED || code == EXCEPTION_PRIV_INSTRUCTION) { write_crash_report(pointers); }
    return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI unhandled_exception_handler(EXCEPTION_POINTERS* pointers) noexcept {
    write_crash_report(pointers);
    return EXCEPTION_CONTINUE_SEARCH;
}

} // namespace

DiagnosticPhaseScope::DiagnosticPhaseScope(RuntimePhase phase) noexcept : previous_(g_phase) { g_phase = phase; }
DiagnosticPhaseScope::~DiagnosticPhaseScope() { g_phase = previous_; }
void set_runtime_phase(RuntimePhase phase) noexcept { g_phase = phase; }
void set_mapped_image(std::uint32_t runtime_base, std::uint32_t image_size, std::uint32_t source_base) noexcept { g_runtime_image_base = runtime_base; g_runtime_image_size = image_size; g_source_image_base = source_base; }

void install_crash_diagnostics() noexcept {
    initialize_artifact_directory();
    AddVectoredExceptionHandler(1u, vectored_exception_handler);
    SetUnhandledExceptionFilter(unhandled_exception_handler);
}

void diagnostic_note(const char* message) noexcept {
    if (!message) { return; }
    char line[2048]{};
    const int count = _snprintf_s(line, sizeof(line), _TRUNCATE, "pid=%lu tid=%lu phase=%s %s\r\n", GetCurrentProcessId(), GetCurrentThreadId(), phase_name(g_phase), message);
    const std::size_t size = count >= 0 ? static_cast<std::size_t>(count) : std::strlen(line);
    write_bytes(L"sfera_native_runtime.log", line, size, OPEN_ALWAYS);
    OutputDebugStringA(line);
}

} // namespace sfera::runtime
