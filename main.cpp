#include "runtime.h"
#include "diagnostics.h"

#include <exception>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
    lifted::install_crash_diagnostics();
    try {
        lifted::set_runtime_phase(lifted::RuntimePhase::process_startup);
        lifted::diagnostic_note("single-process runtime started");
        return lifted::run_native_program();
    } catch (const std::exception& error) {
        lifted::diagnostic_note(error.what());
        TerminateProcess(GetCurrentProcess(), 1u);
        return 1;
    } catch (...) {
        lifted::diagnostic_note("unknown host runtime failure");
        TerminateProcess(GetCurrentProcess(), 2u);
        return 2;
    }
}
