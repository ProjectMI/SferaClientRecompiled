#pragma once

#include "lifted_abi.h"

#include <windows.h>

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace lifted {

struct NativeCallFrame {
    LiftCpu* state;
    void* target;
    std::uint32_t host_esp;
    std::uint32_t host_ebp;
    std::uint32_t host_ebx;
    std::uint32_t host_esi;
    std::uint32_t host_edi;
    void* previous_exception_list;
    void* previous_stack_high;
    void* previous_stack_low;
    std::uint32_t guest_exception_list;
    std::uint32_t guest_stack_high;
    std::uint32_t guest_stack_low;
};

struct CallbackRegisters {
    std::uint32_t edi;
    std::uint32_t esi;
    std::uint32_t ebp;
    std::uint32_t saved_esp;
    std::uint32_t ebx;
    std::uint32_t edx;
    std::uint32_t ecx;
    std::uint32_t eax;
    std::uint32_t saved_flags;
    std::uint32_t callback_function;
};

class LocalStack {
public:
    explicit LocalStack(std::size_t reserve_size);
    LocalStack(const LocalStack&) = delete;
    LocalStack& operator=(const LocalStack&) = delete;
    ~LocalStack();
    std::uint32_t top() const noexcept;
    std::uint32_t base() const noexcept;
    std::uint32_t limit() const noexcept;
private:
    std::uint8_t* memory_ = nullptr;
    std::size_t size_ = 0;
};

class ProcessMemory {
public:
    ProcessMemory();
    ProcessMemory(const ProcessMemory&) = delete;
    ProcessMemory& operator=(const ProcessMemory&) = delete;
    ~ProcessMemory();
    std::uint32_t entry_va() noexcept;
    bool code_rva(std::uint32_t address, std::uint32_t& rva) const noexcept;
    bool try_read(std::uint32_t address, void* value, std::size_t size) const noexcept;
    bool try_write(std::uint32_t address, const void* value, std::size_t size) noexcept;
    void read(std::uint32_t address, void* value, std::size_t size) const;
    void write(std::uint32_t address, const void* value, std::size_t size);
    void initialize_native();
    std::uint32_t callback_for_function(LiftFunction function) const noexcept { return callback_address(function); }
    LiftFunction callback_function(std::uint32_t address) const noexcept;
    bool is_callback_function(LiftFunction function) const noexcept;
private:
    std::uint8_t* callback_thunks_ = nullptr;
    std::uint32_t callback_thunks_size_ = 0;
    std::uint32_t callback_thunk_count_ = 0u;
    void allocate_runtime_regions();
    void resolve_static_references();
    void initialize_callback_registry();
    std::uint32_t callback_address(LiftFunction function) const noexcept;
    void protect_regions();
    void release() noexcept;
};

class NativeRuntime {
public:
    NativeRuntime();
    NativeRuntime(const NativeRuntime&) = delete;
    NativeRuntime& operator=(const NativeRuntime&) = delete;
    int execute();
    void dispatch_callback(CallbackRegisters& registers);
    void call_native(LiftCpu& state, std::uint32_t target, std::uint32_t callsite);
private:
    ProcessMemory memory_;
};

std::string win32_error(const char* operation, DWORD error = GetLastError());
std::string hex_u32(std::uint32_t value);
const std::wstring& client_root_directory();
void configure_process_environment();
int run_native_program();

} // namespace lifted
