#include "diagnostics.h"
#include "runtime.h"

#include <exception>

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
    sfera::runtime::install_crash_diagnostics();
    try {
        sfera::runtime::set_runtime_phase(sfera::runtime::RuntimePhase::process_startup);
        sfera::runtime::diagnostic_note("frozen semantic/native runtime started");
        return sfera::runtime::run_native_program();
    } catch (const std::exception& error) {
        sfera::runtime::diagnostic_note(error.what());
        MessageBoxA(nullptr, error.what(), "Sfera frozen runtime failure", MB_OK | MB_ICONERROR);
        return 1;
    }
}
