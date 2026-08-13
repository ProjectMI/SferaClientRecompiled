#pragma once

#include "lifted_abi.h"
#include "source.h"

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <unordered_map>
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
    void* previous_stack_base;
    void* previous_stack_limit;
    double native_st0;
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
    std::uint32_t eflags;
    std::uint32_t stub_return;
};

struct ResolvedImport {
    const ImportDescriptor* descriptor;
    std::uint32_t address;
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
    std::uint32_t load_base() const noexcept;
    std::uint32_t entry_va() const noexcept;
    std::uint32_t image_address(std::uint32_t rva) const;
    std::uint32_t source_address(std::uint32_t source_va) const;
    bool image_rva(std::uint32_t address, std::uint32_t& rva) const noexcept;
    std::uint8_t* data() noexcept;
    const std::vector<ResolvedImport>& resolved_imports() const noexcept;
    bool try_read(std::uint32_t address, void* value, std::size_t size) const noexcept;
    bool try_write(std::uint32_t address, const void* value, std::size_t size) noexcept;
    void read(std::uint32_t address, void* value, std::size_t size) const;
    void write(std::uint32_t address, const void* value, std::size_t size);
    void initialize_native();
private:
    std::uint8_t* image_ = nullptr;
    std::vector<HMODULE> loaded_modules_;
    std::vector<ResolvedImport> resolved_imports_;
    void map();
    void map_file();
    void resolve_imports();
    void install_recovered_data();
    void install_jump_tables();
    void apply_relocations();
    void patch_image_base();
    void install_callback_stubs();
    void protect_image();
    void release() noexcept;
};

class NativeRuntime {
public:
    NativeRuntime();
    NativeRuntime(const NativeRuntime&) = delete;
    NativeRuntime& operator=(const NativeRuntime&) = delete;
    int execute();
    void dispatch_callback(CallbackRegisters& registers);
    ProcessMemory& memory() noexcept;
    const ImportDescriptor* find_import(std::uint32_t target) const;
    std::uint32_t import_address(std::uint32_t index) const;
    void call_native(LiftCpu& state, std::uint32_t target, std::uint32_t callsite);
private:
    ProcessMemory memory_;
    std::unordered_map<std::uint32_t, const ImportDescriptor*> imports_by_address_;
    std::vector<std::uint32_t> import_addresses_;
};

extern NativeRuntime* g_runtime;
extern ProcessMemory* g_process_memory;
extern "C" void __cdecl native_call_bridge(NativeCallFrame* frame);
extern "C" void __cdecl dispatch_native_callback(CallbackRegisters* registers);
extern "C" void callback_bridge();

std::string win32_error(const char* operation, DWORD error = GetLastError());
std::string hex_u32(std::uint32_t value);
void* checked_memory_copy(void* destination, const void* source, std::uint32_t size);
const std::wstring& client_root_directory();
void configure_process_environment();
int run_native_program();

} // namespace lifted
