#pragma once

#include <cstddef>
#include <cstdint>

struct LiftCpu {
    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;
    uint32_t esp;
    uint32_t ebp;
    uint32_t esi;
    uint32_t edi;
    uint32_t eip;
    uint32_t eflags;
    uint32_t stack_base;
    uint32_t stack_limit;
    double fpu[8];
    uint8_t fpu_depth;
    uint8_t fpu_top;
    uint16_t fpu_control;
    uint16_t fpu_status;
    uint16_t reserved;
    uint8_t fs_data[64];
};

namespace lifted {

using LiftFunction = void (*)(LiftCpu* cpu, uint32_t stop_address);

inline constexpr uint32_t LIFT_FLAG_CF = 0x00000001u;
inline constexpr uint32_t LIFT_FLAG_PF = 0x00000004u;
inline constexpr uint32_t LIFT_FLAG_AF = 0x00000010u;
inline constexpr uint32_t LIFT_FLAG_ZF = 0x00000040u;
inline constexpr uint32_t LIFT_FLAG_SF = 0x00000080u;
inline constexpr uint32_t LIFT_FLAG_DF = 0x00000400u;
inline constexpr uint32_t LIFT_FLAG_OF = 0x00000800u;
inline constexpr uint32_t LIFT_CALLBACK_SENTINEL = 0xFFF0FFF0u;

uint32_t lift_callback_address(LiftFunction function);
uint32_t lift_process_module_handle();

void lift_push32(LiftCpu* cpu, uint32_t value);
uint32_t lift_pop32(LiftCpu* cpu);
uint64_t lift_shift_left(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t lift_shift_right(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t lift_shift_arithmetic(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t lift_rotate_carry_right(LiftCpu* cpu, uint64_t value, uint32_t count, uint32_t width);
uint64_t lift_double_shift_left(LiftCpu* cpu, uint64_t left, uint64_t right, uint32_t count, uint32_t width);
uint64_t lift_double_shift_right(LiftCpu* cpu, uint64_t left, uint64_t right, uint32_t count, uint32_t width);
void lift_multiply_accumulator(LiftCpu* cpu, uint64_t source, uint32_t width, uint32_t is_signed);
void lift_divide_accumulator(LiftCpu* cpu, uint64_t divisor, uint32_t width, uint32_t is_signed);

void lift_x87_push(LiftCpu* cpu, double value);
void lift_x87_pop(LiftCpu* cpu);
int64_t lift_x87_round(const LiftCpu* cpu, double value, uint32_t truncate);

void lift_movs8(LiftCpu* cpu, uint32_t repeated);
void lift_movs16(LiftCpu* cpu, uint32_t repeated);
void lift_movs32(LiftCpu* cpu, uint32_t repeated);
void lift_stos16(LiftCpu* cpu, uint32_t repeated);
void lift_stos32(LiftCpu* cpu, uint32_t repeated);

void lift_native_call(LiftCpu* cpu, uint32_t target, uint32_t callsite);
uint32_t lift_source_rva(uint32_t address);
uint32_t lift_is_native_code_address(uint32_t address);
[[noreturn]] void lift_trap(LiftCpu* cpu, uint32_t source_va, const char* reason);
int lift_call_indirect(LiftCpu* cpu, uint32_t target, uint32_t return_address, uint32_t callsite);
void lift_tail_indirect(LiftCpu* cpu, uint32_t target, uint32_t stop_address, uint32_t callsite);





} // namespace lifted
