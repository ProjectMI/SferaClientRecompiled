#pragma once

#include <cstdint>

namespace sfera::runtime {

enum class RuntimePhase : std::uint32_t {
    startup,
    process_startup,
    map_image,
    load_imports,
    protect_image,
    native_execution
};

class DiagnosticPhaseScope {
public:
    explicit DiagnosticPhaseScope(RuntimePhase phase) noexcept;
    DiagnosticPhaseScope(const DiagnosticPhaseScope&) = delete;
    DiagnosticPhaseScope& operator=(const DiagnosticPhaseScope&) = delete;
    ~DiagnosticPhaseScope();
private:
    RuntimePhase previous_;
};

void install_crash_diagnostics() noexcept;
void set_runtime_phase(RuntimePhase phase) noexcept;
void set_mapped_image(std::uint32_t runtime_base, std::uint32_t image_size, std::uint32_t source_base) noexcept;
void diagnostic_note(const char* message) noexcept;

} // namespace sfera::runtime
