#pragma once

#include "lifted_abi.h"

#include <windows.h>

#include <cstddef>
#include <cstdint>
#include <string>

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
    std::uint32_t lifted_exception_list;
};


class ProcessMemory {
public:
    ProcessMemory();
    ProcessMemory(const ProcessMemory&) = delete;
    ProcessMemory& operator=(const ProcessMemory&) = delete;
    ~ProcessMemory();
    bool try_read(std::uint32_t address, void* value, std::size_t size) const noexcept;
    bool try_write(std::uint32_t address, const void* value, std::size_t size) noexcept;
    void read(std::uint32_t address, void* value, std::size_t size) const;
    void write(std::uint32_t address, const void* value, std::size_t size);
    void initialize_native();
private:
    void protect_regions();
    void release() noexcept;
};

class NativeRuntime {
public:
    NativeRuntime();
    NativeRuntime(const NativeRuntime&) = delete;
    NativeRuntime& operator=(const NativeRuntime&) = delete;
    int execute();
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
