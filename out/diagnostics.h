#pragma once

#include "lifted_abi.h"

#include <cstddef>
#include <cstdint>

namespace lifted {

struct MemoryWriteInfo {
    std::uint32_t address;
    std::uint32_t instruction;
    std::uint32_t size;
    std::uint64_t value;
};

struct MemoryReadInfo {
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
    function_map,
    execution_setup,
    native_c,
    native_call,
    callback
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

class DiagnosticSemanticScope {
public:
    DiagnosticSemanticScope(std::uint32_t source_va, const char* name) noexcept;
    DiagnosticSemanticScope(const DiagnosticSemanticScope&) = delete;
    DiagnosticSemanticScope& operator=(const DiagnosticSemanticScope&) = delete;
    ~DiagnosticSemanticScope();
private:
    std::uint32_t previous_source_va_;
    const char* previous_name_;
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
void set_diagnostic_semantic_argument(std::size_t index, std::uint64_t word, std::uint8_t width, bool floating) noexcept;
void set_diagnostic_memory_probe(bool active) noexcept;
void diagnostic_memory_read(std::uint32_t address, std::uint32_t size, std::uint64_t value) noexcept;
void diagnostic_memory_write(std::uint32_t address, std::uint32_t size, std::uint64_t value) noexcept;
bool diagnostic_last_memory_write(std::uint32_t address, MemoryWriteInfo& result) noexcept;
bool diagnostic_recent_read_value(std::uint32_t value, MemoryReadInfo& result) noexcept;
void diagnostic_memory_fault(std::uint32_t address, std::uint32_t size, bool write) noexcept;
void diagnostic_call(std::uint32_t callsite, std::uint32_t target, std::uint32_t return_address, std::uint32_t esp) noexcept;
void diagnostic_return(std::uint32_t return_address) noexcept;
void diagnostic_failure(const LiftCpu& state, const char* message) noexcept;
void diagnostic_note(const char* message) noexcept;

} // namespace lifted
