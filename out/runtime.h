#pragma once

#include "lifted_abi.h"
#include "semantic_native.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <cstddef>
#include <cstdint>
#include <string>
#include <array>
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
    std::uint32_t callback_target;
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
    std::uint32_t static_address(std::uint32_t rva) const;
    std::uint32_t source_address(std::uint32_t source_va) const;
    bool source_rva(std::uint32_t address, std::uint32_t& rva) const noexcept;
    const std::vector<ResolvedImport>& resolved_imports() const noexcept;
    bool try_read(std::uint32_t address, void* value, std::size_t size) const noexcept;
    bool try_write(std::uint32_t address, const void* value, std::size_t size) noexcept;
    void read(std::uint32_t address, void* value, std::size_t size) const;
    void write(std::uint32_t address, const void* value, std::size_t size);
    void initialize_native();
private:
    struct StaticRegion { std::uint32_t rva = 0; std::uint32_t size = 0; std::uint8_t* memory = nullptr; std::uint8_t access = 0; const char* name = nullptr; bool protect = false; };
    std::uint8_t* module_shell_ = nullptr;
    std::uint32_t module_shell_size_ = 0;
    std::uint8_t* callback_thunks_ = nullptr;
    std::uint32_t callback_thunks_size_ = 0;
    std::uint8_t* rdata_reservation_ = nullptr;
    std::uint8_t* rdata_commit_base_ = nullptr;
    std::uint32_t rdata_commit_size_ = 0;
    std::uint8_t* data_compat_view_ = nullptr;
    std::vector<std::uint8_t*> data_compat_segments_;
    std::vector<StaticRegion> regions_;
    std::vector<void*> owned_regions_;
    std::vector<HMODULE> loaded_modules_;
    std::vector<ResolvedImport> resolved_imports_;
    void allocate_static_regions();
    std::uint8_t* region_pointer(std::uint32_t rva, std::size_t size = 1u) const;
    void install_initial_static_data();
    void resolve_imports();
    void apply_static_pointer_fixups();
    void verify_semantic_data_views() const;
    void patch_module_shell();
    void install_callback_thunks();
    std::uint32_t callback_address(std::uint32_t rva) const noexcept;
    bool callback_rva(std::uint32_t address, std::uint32_t& rva) const noexcept;
    bool is_static_table_rva(std::uint32_t rva) const noexcept;
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
    const ImportDescriptor* find_import(std::uint32_t target) const;
    std::uint32_t import_address(std::uint32_t index) const;
    void call_import(LiftCpu& state, std::uint32_t index, std::uint32_t callsite);
    void call_native(LiftCpu& state, std::uint32_t target, std::uint32_t callsite);
private:
    ProcessMemory memory_;
    static constexpr std::size_t kImportLookupSize = 1024u;
    std::array<std::uint32_t, kImportLookupSize> import_lookup_addresses_{};
    std::array<const ImportDescriptor*, kImportLookupSize> import_lookup_descriptors_{};
    std::array<std::uint32_t, kImports.size()> import_addresses_{};
    void call_native_resolved(LiftCpu& state, std::uint32_t target, std::uint32_t callsite, const ImportDescriptor* descriptor);
};

extern NativeRuntime* g_runtime;
extern ProcessMemory* g_process_memory;
extern "C" void __cdecl native_call_bridge(NativeCallFrame* frame);
extern "C" void __cdecl native_call_bridge_fast(NativeCallFrame* frame);
extern "C" void __cdecl dispatch_native_callback(CallbackRegisters* registers);
extern "C" void callback_bridge();

std::string win32_error(const char* operation, DWORD error = GetLastError());
std::string hex_u32(std::uint32_t value);
const std::wstring& client_root_directory();
void configure_process_environment();
int run_native_program();

} // namespace lifted
