#pragma once

#include "source.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

namespace lifted {

inline constexpr std::uint32_t kFlagCF = 0x00000001u;
inline constexpr std::uint32_t kFlagPF = 0x00000004u;
inline constexpr std::uint32_t kFlagAF = 0x00000010u;
inline constexpr std::uint32_t kFlagZF = 0x00000040u;
inline constexpr std::uint32_t kFlagSF = 0x00000080u;
inline constexpr std::uint32_t kFlagDF = 0x00000400u;
inline constexpr std::uint32_t kFlagOF = 0x00000800u;
inline constexpr std::uint32_t kCallbackSentinel = 0xFFF0FFF0u;

struct CpuState {
    std::uint32_t eax = 0;
    std::uint32_t ecx = 0;
    std::uint32_t edx = 0;
    std::uint32_t ebx = 0;
    std::uint32_t esp = 0;
    std::uint32_t ebp = 0;
    std::uint32_t esi = 0;
    std::uint32_t edi = 0;
    std::uint32_t eip = 0;
    std::uint32_t eflags = 0x202u;
    std::uint32_t guest_stack_base = 0;
    std::uint32_t guest_stack_limit = 0;
    std::array<double, 8> fpu{};
    std::uint8_t fpu_depth = 0;
    std::uint8_t fpu_top = 0;
    std::uint16_t fpu_control = 0x037Fu;
    std::uint16_t fpu_status = 0;
    std::uint16_t reserved = 0;
    std::array<std::array<std::uint8_t, 16>, 8> xmm{};
    std::array<std::uint8_t, 4096> fs_data{};
    bool stopped = false;
};

struct NativeCallFrame {
    CpuState* state;
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

class GuestStack {
public:
    explicit GuestStack(std::size_t reserve_size);
    GuestStack(const GuestStack&) = delete;
    GuestStack& operator=(const GuestStack&) = delete;
    ~GuestStack();
    std::uint32_t top() const noexcept;
    std::uint32_t base() const noexcept;
    std::uint32_t limit() const noexcept;
private:
    std::uint8_t* memory_ = nullptr;
    std::size_t size_ = 0;
};

class NativeGuestMemory {
public:
    NativeGuestMemory();
    NativeGuestMemory(const NativeGuestMemory&) = delete;
    NativeGuestMemory& operator=(const NativeGuestMemory&) = delete;
    ~NativeGuestMemory();
    std::uint32_t load_base() const noexcept;
    std::uint32_t entry_va() const noexcept;
    std::uint8_t* data() noexcept;
    const std::vector<ResolvedImport>& resolved_imports() const noexcept;
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
    void install_callback_stubs();
    void protect_image();
    void release() noexcept;
};

class Runtime {
public:
    Runtime();
    Runtime(const Runtime&) = delete;
    Runtime& operator=(const Runtime&) = delete;
    int execute();
    void run(CpuState& state, std::uint32_t stop_target = 0);
    void dispatch_callback(CallbackRegisters& registers);
    NativeGuestMemory& memory() noexcept;
private:
    NativeGuestMemory memory_;
    std::vector<const InstructionDescriptor*> instruction_index_;
    const InstructionDescriptor* const* instruction_index_data_ = nullptr;
    std::unordered_map<std::uint32_t, const ImportDescriptor*> imports_by_address_;
    const InstructionDescriptor& lookup(std::uint32_t eip) const;
    bool has_instruction(std::uint32_t eip) const noexcept;
    void step(CpuState& state, const InstructionDescriptor& instruction, std::uint32_t stop_target);
    void call_native(CpuState& state, std::uint32_t target);
    const ImportDescriptor* find_import(std::uint32_t target) const;
};

extern Runtime* g_runtime;
extern "C" void __cdecl native_call_bridge(NativeCallFrame* frame);
extern "C" void __cdecl dispatch_native_callback(CallbackRegisters* registers);
extern "C" void callback_bridge();

std::string win32_error(const char* operation, DWORD error = GetLastError());
std::string hex_u32(std::uint32_t value);
const std::wstring& guest_root_directory();
void configure_guest_environment();
int run_compiled_slice();

} // namespace lifted
