#pragma once

#include <cstddef>
#include <cstdint>

namespace lifted {

struct CpuState;

struct GuestWriteInfo {
    std::uint32_t address;
    std::uint32_t instruction;
    std::uint32_t size;
    std::uint64_t value;
};

enum class RuntimePhase : std::uint32_t {
    startup,
    launcher,
    child_startup,
    map_image,
    load_imports,
    protect_image,
    abi_self_test,
    build_index,
    guest_setup,
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

class DiagnosticGuestRunScope {
public:
    DiagnosticGuestRunScope(std::uint32_t target, std::uint32_t stop_target, std::uint32_t esp) noexcept;
    DiagnosticGuestRunScope(const DiagnosticGuestRunScope&) = delete;
    DiagnosticGuestRunScope& operator=(const DiagnosticGuestRunScope&) = delete;
    ~DiagnosticGuestRunScope();
private:
    std::size_t previous_depth_;
};

void install_crash_diagnostics() noexcept;
void set_runtime_phase(RuntimePhase phase) noexcept;
void set_diagnostic_instruction(std::uint32_t address, const char* operation) noexcept;
void set_diagnostic_memory_probe(bool active) noexcept;
void diagnostic_guest_write(std::uint32_t address, std::uint32_t size, std::uint64_t value) noexcept;
bool diagnostic_last_guest_write(std::uint32_t address, GuestWriteInfo& result) noexcept;
void diagnostic_guest_call(std::uint32_t callsite, std::uint32_t target, std::uint32_t return_address, std::uint32_t esp) noexcept;
void diagnostic_guest_return(std::uint32_t return_address) noexcept;
void diagnostic_guest_failure(const CpuState& state, const char* message) noexcept;
void diagnostic_note(const char* message) noexcept;

} // namespace lifted
