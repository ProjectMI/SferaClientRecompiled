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
void lift_x87_compare(LiftCpu* cpu, double left, double right);
void lift_x87_sincos(LiftCpu* cpu);

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

constexpr uint64_t lift_flag_width_mask(uint32_t width) {
    return width == 8u ? 0xFFull : width == 16u ? 0xFFFFull : width == 32u ? 0xFFFFFFFFull : ~uint64_t{0};
}

constexpr uint64_t lift_flag_sign_bit(uint32_t width) {
    return width == 8u ? 0x80ull : width == 16u ? 0x8000ull : width == 32u ? 0x80000000ull : 0x8000000000000000ull;
}

constexpr uint32_t lift_flag_parity(uint64_t value) {
    uint32_t byte = static_cast<uint32_t>(value) & 0xFFu;
    byte ^= byte >> 4u;
    byte &= 0xFu;
    return (((0x6996u >> byte) & 1u) == 0u) ? LIFT_FLAG_PF : 0u;
}

constexpr uint32_t lift_flag_szp(uint64_t value, uint32_t width) {
    const uint64_t truncated = value & lift_flag_width_mask(width);
    uint32_t flags = lift_flag_parity(truncated);
    if (truncated == 0u) { flags |= LIFT_FLAG_ZF; }
    if ((truncated & lift_flag_sign_bit(width)) != 0u) { flags |= LIFT_FLAG_SF; }
    return flags;
}

inline void lift_flags_logic(LiftCpu* cpu, uint64_t result, uint32_t width) {
    cpu->eflags = (cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_PF | LIFT_FLAG_AF | LIFT_FLAG_ZF | LIFT_FLAG_SF | LIFT_FLAG_OF)) | lift_flag_szp(result, width);
}

inline void lift_flags_add(LiftCpu* cpu, uint64_t left, uint64_t right, uint64_t carry, uint64_t result, uint32_t width) {
    const uint64_t mask = lift_flag_width_mask(width);
    const uint64_t sign = lift_flag_sign_bit(width);
    const uint64_t l = left & mask;
    const uint64_t r = right & mask;
    const uint64_t partial = (l + r) & mask;
    const uint64_t truncated = result & mask;
    uint32_t flags = lift_flag_szp(truncated, width);
    if (partial < l || (carry != 0u && truncated < partial)) { flags |= LIFT_FLAG_CF; }
    if (((~(l ^ r) & (l ^ truncated)) & sign) != 0u) { flags |= LIFT_FLAG_OF; }
    if (((l ^ r ^ truncated) & 0x10u) != 0u) { flags |= LIFT_FLAG_AF; }
    cpu->eflags = (cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_PF | LIFT_FLAG_AF | LIFT_FLAG_ZF | LIFT_FLAG_SF | LIFT_FLAG_OF)) | flags;
}

inline void lift_flags_sub(LiftCpu* cpu, uint64_t left, uint64_t right, uint64_t borrow, uint64_t result, uint32_t width) {
    const uint64_t mask = lift_flag_width_mask(width);
    const uint64_t sign = lift_flag_sign_bit(width);
    const uint64_t l = left & mask;
    const uint64_t r = right & mask;
    const uint64_t truncated = result & mask;
    uint32_t flags = lift_flag_szp(truncated, width);
    if (l < r || (borrow != 0u && l == r)) { flags |= LIFT_FLAG_CF; }
    if ((((l ^ r) & (l ^ truncated)) & sign) != 0u) { flags |= LIFT_FLAG_OF; }
    if (((l ^ r ^ truncated) & 0x10u) != 0u) { flags |= LIFT_FLAG_AF; }
    cpu->eflags = (cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_PF | LIFT_FLAG_AF | LIFT_FLAG_ZF | LIFT_FLAG_SF | LIFT_FLAG_OF)) | flags;
}

} // namespace lifted
