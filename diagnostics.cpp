#include "diagnostics.h"
#include "runtime.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <cwchar>
#include <iterator>
#include <memory>
#include <new>

#if !defined(SFERA_PORTABLE_CHECK)
#include <DbgHelp.h>
#endif

namespace lifted {

namespace {

thread_local RuntimePhase g_phase = RuntimePhase::startup;
thread_local const LiftCpu* g_cpu = nullptr;
thread_local std::uint32_t g_instruction = 0;
thread_local const char* g_operation = nullptr;
thread_local bool g_memory_probe = false;

struct TraceEntry {
    std::uint32_t address;
    const char* operation;
};

struct CallEntry {
    std::uint32_t callsite;
    std::uint32_t target;
    std::uint32_t return_address;
    std::uint32_t esp;
};

struct MemoryWriteRecord {
    MemoryWriteInfo info;
    std::uint64_t sequence;
};

thread_local TraceEntry g_trace[256]{};
thread_local std::uint64_t g_trace_count = 0;
thread_local CallEntry g_calls[512]{};
thread_local std::size_t g_call_count = 0;
thread_local std::unique_ptr<MemoryWriteRecord[]> g_memory_writes;
thread_local std::uint64_t g_memory_write_sequence = 0;
constexpr std::size_t kMemoryWriteBucketCount = 65536;
constexpr std::size_t kMemoryWriteCapacity = kMemoryWriteBucketCount * 4u;

std::size_t memory_write_bucket(std::uint32_t address) noexcept {
    return static_cast<std::size_t>((address * 2654435761u) >> 16u) * 4u;
}

[[maybe_unused]] const char* phase_name(RuntimePhase phase) noexcept {
    switch (phase) {
        case RuntimePhase::startup: return "startup";
        case RuntimePhase::process_startup: return "process-startup";
        case RuntimePhase::static_storage: return "static-storage";
        case RuntimePhase::protect_static_storage: return "protect-static-storage";
        case RuntimePhase::abi_self_test: return "abi-self-test";
        case RuntimePhase::function_map: return "function-map";
        case RuntimePhase::execution_setup: return "execution-setup";
        case RuntimePhase::native_c: return "native-c";
        case RuntimePhase::native_call: return "native-call";
        case RuntimePhase::callback: return "callback";
    }
    return "unknown";
}

#if !defined(SFERA_PORTABLE_CHECK)

LONG g_report_written = 0;
wchar_t g_artifact_directory[MAX_PATH]{};
std::size_t g_artifact_directory_length = 0;

void initialize_artifact_directory() noexcept {
    const DWORD length = GetModuleFileNameW(nullptr, g_artifact_directory, MAX_PATH);
    if (length == 0 || length >= MAX_PATH) { return; }
    g_artifact_directory_length = length;
    while (g_artifact_directory_length != 0 && g_artifact_directory[g_artifact_directory_length - 1] != L'\\' && g_artifact_directory[g_artifact_directory_length - 1] != L'/') { --g_artifact_directory_length; }
    g_artifact_directory[g_artifact_directory_length] = L'\0';
}

bool artifact_path(const wchar_t* filename, wchar_t* path, std::size_t capacity) noexcept {
    if (!filename || !path || capacity == 0) { return false; }
    const std::size_t filename_length = std::wcslen(filename);
    if (g_artifact_directory_length + filename_length + 1 > capacity) { return false; }
    std::memcpy(path, g_artifact_directory, g_artifact_directory_length * sizeof(wchar_t));
    std::memcpy(path + g_artifact_directory_length, filename, (filename_length + 1) * sizeof(wchar_t));
    return true;
}

void write_bytes(const wchar_t* filename, const char* bytes, std::size_t size, DWORD creation) noexcept {
    wchar_t path[MAX_PATH]{};
    if (!artifact_path(filename, path, MAX_PATH)) { return; }
    const DWORD access = creation == OPEN_ALWAYS ? FILE_APPEND_DATA : GENERIC_WRITE;
    HANDLE file = CreateFileW(path, access, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, creation, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) { return; }
    DWORD written = 0;
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

void append_execution_context(char* report, std::size_t capacity, std::size_t& used, const LiftCpu* state) noexcept {
    if (state) {
        append_text(report, capacity, used, "lifted eip=%08X esp=%08X ebp=%08X eax=%08X ebx=%08X ecx=%08X edx=%08X esi=%08X edi=%08X eflags=%08X\r\n", state->eip, state->esp, state->ebp, state->eax, state->ebx, state->ecx, state->edx, state->esi, state->edi, state->eflags);
    }
    if (g_instruction != 0) { append_text(report, capacity, used, "instruction=%08X operation=%s\r\n", g_instruction, g_operation ? g_operation : "unknown"); }
    if (g_call_count != 0) {
        append_text(report, capacity, used, "call-stack:\r\n");
        for (std::size_t index = 0; index < g_call_count; ++index) {
            const CallEntry& entry = g_calls[index];
            if (entry.callsite == 0) { append_text(report, capacity, used, "  root target=%08X stop=%08X esp=%08X\r\n", entry.target, entry.return_address, entry.esp); }
            else { append_text(report, capacity, used, "  call=%08X target=%08X return=%08X esp=%08X\r\n", entry.callsite, entry.target, entry.return_address, entry.esp); }
        }
    }
    const std::size_t trace_size = g_trace_count < std::size(g_trace) ? static_cast<std::size_t>(g_trace_count) : std::size(g_trace);
    if (trace_size != 0) {
        append_text(report, capacity, used, "recent-blocks:\r\n");
        for (std::size_t offset = trace_size; offset != 0; --offset) {
            const std::size_t index = static_cast<std::size_t>((g_trace_count - offset) % std::size(g_trace));
            const TraceEntry& entry = g_trace[index];
            append_text(report, capacity, used, "  %08X %s\r\n", entry.address, entry.operation ? entry.operation : "unknown");
        }
    }
}

void write_minidump(EXCEPTION_POINTERS* pointers) noexcept {
    wchar_t dump_path[MAX_PATH]{};
    if (!artifact_path(L"sfera_native_crash.dmp", dump_path, MAX_PATH)) { return; }
    HANDLE file = CreateFileW(dump_path, GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file != INVALID_HANDLE_VALUE) {
        MINIDUMP_EXCEPTION_INFORMATION information{};
        information.ThreadId = GetCurrentThreadId();
        information.ExceptionPointers = pointers;
        information.ClientPointers = FALSE;
        const MINIDUMP_TYPE type = static_cast<MINIDUMP_TYPE>(MiniDumpWithDataSegs | MiniDumpWithHandleData | MiniDumpWithUnloadedModules | MiniDumpWithThreadInfo);
        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file, type, &information, nullptr, nullptr);
        CloseHandle(file);
    }
}

void write_crash_report(EXCEPTION_POINTERS* pointers) noexcept {
    if (!pointers || InterlockedCompareExchange(&g_report_written, 1, 0) != 0) { return; }
    static char report[65536]{};
    std::size_t used = 0;
    const EXCEPTION_RECORD* record = pointers->ExceptionRecord;
    const CONTEXT* context = pointers->ContextRecord;
    append_text(report, sizeof(report), used, "Sfera native-C runtime crash\r\n");
    append_text(report, sizeof(report), used, "pid=%lu tid=%lu phase=%s\r\n", GetCurrentProcessId(), GetCurrentThreadId(), phase_name(g_phase));
    if (record) {
        append_text(report, sizeof(report), used, "exception=0x%08lX address=%p\r\n", record->ExceptionCode, record->ExceptionAddress);
        if (record->ExceptionCode == EXCEPTION_ACCESS_VIOLATION && record->NumberParameters >= 2) {
            const char* access = record->ExceptionInformation[0] == 0 ? "read" : record->ExceptionInformation[0] == 1 ? "write" : record->ExceptionInformation[0] == 8 ? "execute" : "unknown";
            append_text(report, sizeof(report), used, "access=%s target=0x%08lX\r\n", access, static_cast<unsigned long>(record->ExceptionInformation[1]));
        }
    }
    if (context) {
        append_text(report, sizeof(report), used, "native eip=%08lX esp=%08lX ebp=%08lX eax=%08lX ebx=%08lX ecx=%08lX edx=%08lX esi=%08lX edi=%08lX eflags=%08lX\r\n", context->Eip, context->Esp, context->Ebp, context->Eax, context->Ebx, context->Ecx, context->Edx, context->Esi, context->Edi, context->EFlags);
    }
    append_execution_context(report, sizeof(report), used, g_cpu);
    write_bytes(L"sfera_native_crash.txt", report, used, CREATE_ALWAYS);
    OutputDebugStringA(report);
    write_minidump(pointers);
}

LONG CALLBACK vectored_exception_handler(EXCEPTION_POINTERS* pointers) noexcept {
    if (!pointers || !pointers->ExceptionRecord || g_memory_probe) { return EXCEPTION_CONTINUE_SEARCH; }
    const DWORD code = pointers->ExceptionRecord->ExceptionCode;
    if (code == EXCEPTION_ACCESS_VIOLATION || code == EXCEPTION_ILLEGAL_INSTRUCTION || code == EXCEPTION_STACK_OVERFLOW || code == EXCEPTION_ARRAY_BOUNDS_EXCEEDED) { write_crash_report(pointers); }
    return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI unhandled_exception_handler(EXCEPTION_POINTERS* pointers) noexcept {
    write_crash_report(pointers);
    return EXCEPTION_CONTINUE_SEARCH;
}

#endif

} // namespace

DiagnosticPhaseScope::DiagnosticPhaseScope(RuntimePhase phase) noexcept : previous_(g_phase) { g_phase = phase; }
DiagnosticPhaseScope::~DiagnosticPhaseScope() { g_phase = previous_; }

DiagnosticRunScope::DiagnosticRunScope(const LiftCpu* state) noexcept : previous_state_(g_cpu), previous_instruction_(g_instruction), previous_operation_(g_operation) {
    g_cpu = state;
    g_instruction = 0;
    g_operation = nullptr;
}

DiagnosticRunScope::~DiagnosticRunScope() {
    g_cpu = previous_state_;
    g_instruction = previous_instruction_;
    g_operation = previous_operation_;
}

DiagnosticExecutionScope::DiagnosticExecutionScope(std::uint32_t target, std::uint32_t stop_target, std::uint32_t esp) noexcept : previous_depth_(g_call_count) {
    diagnostic_call(0, target, stop_target, esp);
}

DiagnosticExecutionScope::~DiagnosticExecutionScope() {
    g_call_count = previous_depth_;
}

void install_crash_diagnostics() noexcept {
#if !defined(SFERA_PORTABLE_CHECK)
    initialize_artifact_directory();
    AddVectoredExceptionHandler(1, vectored_exception_handler);
    SetUnhandledExceptionFilter(unhandled_exception_handler);
    diagnostic_note("diagnostics installed");
#endif
}

void set_runtime_phase(RuntimePhase phase) noexcept { g_phase = phase; }
void set_diagnostic_instruction(std::uint32_t address, const char* operation) noexcept {
    g_instruction = address;
    g_operation = operation;
    g_trace[static_cast<std::size_t>(g_trace_count % std::size(g_trace))] = {address, operation};
    ++g_trace_count;
}
void set_diagnostic_memory_probe(bool active) noexcept { g_memory_probe = active; }

void diagnostic_memory_write(std::uint32_t address, std::uint32_t size, std::uint64_t value) noexcept {
    if (!g_memory_writes) { g_memory_writes.reset(new (std::nothrow) MemoryWriteRecord[kMemoryWriteCapacity]{}); }
    if (!g_memory_writes) { return; }
    const std::size_t bucket = memory_write_bucket(address);
    MemoryWriteRecord* selected = &g_memory_writes[bucket];
    for (std::size_t way = 0; way < 4; ++way) {
        MemoryWriteRecord& candidate = g_memory_writes[bucket + way];
        if (candidate.sequence == 0 || candidate.info.address == address) { selected = &candidate; break; }
        if (candidate.sequence < selected->sequence) { selected = &candidate; }
    }
    selected->info = {address, g_instruction, size, value};
    selected->sequence = ++g_memory_write_sequence;
}

bool diagnostic_last_memory_write(std::uint32_t address, MemoryWriteInfo& result) noexcept {
    if (!g_memory_writes) { return false; }
    const std::uint32_t search_begin = address >= 15u ? address - 15u : 0u;
    const MemoryWriteRecord* selected = nullptr;
    for (std::uint32_t candidate_address = search_begin; candidate_address <= address; ++candidate_address) {
        const std::size_t bucket = memory_write_bucket(candidate_address);
        for (std::size_t way = 0; way < 4; ++way) {
            const MemoryWriteRecord& candidate = g_memory_writes[bucket + way];
            const std::uint64_t end = static_cast<std::uint64_t>(candidate.info.address) + candidate.info.size;
            if (candidate.sequence != 0 && candidate.info.address == candidate_address && address >= candidate.info.address && address < end && (!selected || candidate.sequence > selected->sequence)) { selected = &candidate; }
        }
    }
    if (!selected) { return false; }
    result = selected->info;
    return true;
}

void diagnostic_call(std::uint32_t callsite, std::uint32_t target, std::uint32_t return_address, std::uint32_t esp) noexcept {
    if (g_call_count == std::size(g_calls)) { return; }
    g_calls[g_call_count++] = {callsite, target, return_address, esp};
}

void diagnostic_return(std::uint32_t return_address) noexcept {
    for (std::size_t index = g_call_count; index != 0; --index) {
        if (g_calls[index - 1].return_address == return_address) {
            g_call_count = index - 1;
            return;
        }
    }
}

void diagnostic_failure(const LiftCpu& state, const char* message) noexcept {
#if !defined(SFERA_PORTABLE_CHECK)
    static thread_local char report[65536]{};
    std::size_t used = 0;
    report[0] = '\0';
    append_text(report, sizeof(report), used, "Sfera native-C execution failure\r\n");
    append_text(report, sizeof(report), used, "pid=%lu tid=%lu phase=%s\r\n", GetCurrentProcessId(), GetCurrentThreadId(), phase_name(g_phase));
    append_text(report, sizeof(report), used, "%s\r\n", message ? message : "native execution failure");
    append_execution_context(report, sizeof(report), used, &state);
    write_bytes(L"sfera_native_failure.txt", report, used, CREATE_ALWAYS);
    OutputDebugStringA(report);
#else
    (void)state;
    (void)message;
#endif
}

void diagnostic_note(const char* message) noexcept {
#if !defined(SFERA_PORTABLE_CHECK)
    SYSTEMTIME time{};
    GetLocalTime(&time);
    char line[1024]{};
    const int count = _snprintf_s(line, sizeof(line), _TRUNCATE, "%04u-%02u-%02u %02u:%02u:%02u.%03u pid=%lu tid=%lu phase=%s %s\r\n", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, GetCurrentProcessId(), GetCurrentThreadId(), phase_name(g_phase), message ? message : "");
    if (count > 0) { write_bytes(L"sfera_native_runtime.log", line, static_cast<std::size_t>(count), OPEN_ALWAYS); }
#else
    (void)message;
#endif
}

} // namespace lifted
