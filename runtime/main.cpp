#include "runtime.h"
#include "diagnostics.h"

#include <stdexcept>
#include <string>
#include <vector>

namespace {

constexpr wchar_t kReservationMarker[] = L"SFERA_IR_GUEST_PRERESERVED_V2";

bool is_reserved_child() {
    wchar_t value[2]{};
    return GetEnvironmentVariableW(kReservationMarker, value, 2u) != 0;
}

int launch_reserved_child() {
    lifted::DiagnosticPhaseScope phase(lifted::RuntimePhase::launcher);
    lifted::configure_guest_environment();
    const std::wstring& guest_root = lifted::guest_root_directory();
    wchar_t executable[MAX_PATH]{};
    const DWORD length = GetModuleFileNameW(nullptr, executable, MAX_PATH);
    if (length == 0 || length >= MAX_PATH) { throw std::runtime_error(lifted::win32_error("GetModuleFileNameW")); }
    std::wstring command_line = GetCommandLineW();
    std::vector<wchar_t> command_buffer(command_line.begin(), command_line.end());
    command_buffer.push_back(L'\0');
    if (!SetEnvironmentVariableW(kReservationMarker, L"1")) { throw std::runtime_error(lifted::win32_error("SetEnvironmentVariableW")); }
    STARTUPINFOW startup{};
    startup.cb = sizeof(startup);
    PROCESS_INFORMATION process{};
    const BOOL created = CreateProcessW(executable, command_buffer.data(), nullptr, nullptr, FALSE, CREATE_SUSPENDED, nullptr, guest_root.c_str(), &startup, &process);
    const DWORD create_error = created ? ERROR_SUCCESS : GetLastError();
    SetEnvironmentVariableW(kReservationMarker, nullptr);
    if (!created) { throw std::runtime_error(lifted::win32_error("CreateProcessW", create_error)); }
    auto close_handles = [&process]() noexcept { if (process.hThread) { CloseHandle(process.hThread); } if (process.hProcess) { CloseHandle(process.hProcess); } };
    void* const requested = reinterpret_cast<void*>(static_cast<std::uintptr_t>(lifted::kPreferredImageBase));
    void* const reservation = VirtualAllocEx(process.hProcess, requested, lifted::kImageSize, MEM_RESERVE, PAGE_NOACCESS);
    if (reservation != requested) {
        TerminateProcess(process.hProcess, 1);
        close_handles();
        throw std::runtime_error("Unable to reserve guest image at " + lifted::hex_u32(lifted::kPreferredImageBase));
    }
    if (ResumeThread(process.hThread) == static_cast<DWORD>(-1)) {
        const DWORD error = GetLastError();
        TerminateProcess(process.hProcess, 1);
        close_handles();
        throw std::runtime_error(lifted::win32_error("ResumeThread", error));
    }
    WaitForSingleObject(process.hProcess, INFINITE);
    DWORD exit_code = 1;
    GetExitCodeProcess(process.hProcess, &exit_code);
    const std::string exit_note = "reserved child exited with code " + lifted::hex_u32(exit_code);
    lifted::diagnostic_note(exit_note.c_str());
    close_handles();
    if (exit_code != 0) { MessageBoxA(nullptr, "The interpreted child stopped. See sfera_ir_guest_failure.txt or sfera_ir_crash.txt beside the executable.", "Compiled IR runtime failure", MB_OK | MB_ICONERROR); }
    return static_cast<int>(exit_code);
}

} // namespace

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
    lifted::install_crash_diagnostics();
    const bool reserved_child = is_reserved_child();
    try {
        if (!reserved_child) { return launch_reserved_child(); }
        lifted::set_runtime_phase(lifted::RuntimePhase::child_startup);
        lifted::diagnostic_note("reserved child started");
        return lifted::run_compiled_slice();
    } catch (const std::exception& error) {
        lifted::diagnostic_note(error.what());
        if (!reserved_child) { MessageBoxA(nullptr, error.what(), "Compiled IR runtime failure", MB_OK | MB_ICONERROR); }
        return 1;
    }
}
