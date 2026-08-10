#pragma once

#include <cstddef>
#include <cstdint>

namespace lifted {

struct CpuState;

struct MemoryWriteInfo {
    std::uint32_t address;
    std::uint32_t instruction;
    std::uint32_t size;
    std::uint64_t value;
};

enum class RuntimePhase : std::uint32_t {
    startup,
    process_startup,
    map_image,
    load_imports,
    protect_image,
    abi_self_test,
    build_index,
    execution_setup,
    interpret,
    native_call,
    callback,
    shutdown
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
    explicit DiagnosticRunScope(const CpuState* state) noexcept;
    DiagnosticRunScope(const DiagnosticRunScope&) = delete;
    DiagnosticRunScope& operator=(const DiagnosticRunScope&) = delete;
    ~DiagnosticRunScope();
private:
    const CpuState* previous_state_;
    std::uint32_t previous_instruction_;
    const char* previous_operation_;
};

class DiagnosticNativeScope {
public:
    DiagnosticNativeScope(std::uint32_t target, const char* import_name) noexcept;
    DiagnosticNativeScope(const DiagnosticNativeScope&) = delete;
    DiagnosticNativeScope& operator=(const DiagnosticNativeScope&) = delete;
    ~DiagnosticNativeScope();
private:
    std::uint32_t previous_target_;
    const char* previous_import_name_;
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
void set_diagnostic_instruction(std::uint32_t address, const char* operation) noexcept;
void set_diagnostic_memory_probe(bool active) noexcept;
void diagnostic_memory_write(std::uint32_t address, std::uint32_t size, std::uint64_t value) noexcept;
bool diagnostic_last_memory_write(std::uint32_t address, MemoryWriteInfo& result) noexcept;
void diagnostic_ir_call(std::uint32_t callsite, std::uint32_t target, std::uint32_t return_address, std::uint32_t esp) noexcept;
void diagnostic_ir_return(std::uint32_t return_address) noexcept;
void diagnostic_ir_failure(const CpuState& state, const char* message) noexcept;
void diagnostic_note(const char* message) noexcept;

} // namespace lifted
