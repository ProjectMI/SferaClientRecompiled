#include "runtime.h"
#include "diagnostics.h"

#include <exception>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
    lifted::install_crash_diagnostics();
    try {
        lifted::set_runtime_phase(lifted::RuntimePhase::process_startup);
        lifted::diagnostic_note("single-process runtime started");
        return lifted::run_compiled_slice();
    } catch (const std::exception& error) {
        lifted::diagnostic_note(error.what());
        MessageBoxA(nullptr, error.what(), "Compiled IR runtime failure", MB_OK | MB_ICONERROR);
        return 1;
    }
}
