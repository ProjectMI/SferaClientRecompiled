#pragma once

#include <cstddef>
#include <cstdint>

struct LiftCpu;

namespace lifted {

struct MemoryWriteInfo {
    std::uint32_t address;
    std::uint32_t instruction;
    std::uint32_t size;
    std::uint64_t value;
};

enum class RuntimePhase : std::uint32_t {
    startup,
    process_startup,
    static_storage,
    protect_static_storage,
    abi_self_test,
    execution_setup,
    native_c,
    native_call
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

class DiagnosticRunScope {
public:
    explicit DiagnosticRunScope(const LiftCpu* state) noexcept;
    DiagnosticRunScope(const DiagnosticRunScope&) = delete;
    DiagnosticRunScope& operator=(const DiagnosticRunScope&) = delete;
    ~DiagnosticRunScope();
private:
    const LiftCpu* previous_state_;
    std::uint32_t previous_instruction_;
    const char* previous_operation_;
};

class DiagnosticExecutionScope {
public:
    DiagnosticExecutionScope(std::uint32_t target, std::uint32_t stop_target, std::uint32_t esp) noexcept;
    DiagnosticExecutionScope(const DiagnosticExecutionScope&) = delete;
    DiagnosticExecutionScope& operator=(const DiagnosticExecutionScope&) = delete;
    ~DiagnosticExecutionScope();
private:
    std::size_t previous_depth_;
};

void install_crash_diagnostics() noexcept;
void set_runtime_phase(RuntimePhase phase) noexcept;
void diagnostic_call(std::uint32_t callsite, std::uint32_t target, std::uint32_t return_address, std::uint32_t esp) noexcept;
void diagnostic_failure(const LiftCpu& state, const char* message) noexcept;
void diagnostic_note(const char* message) noexcept;

} // namespace lifted
