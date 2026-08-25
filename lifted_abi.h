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
    uint32_t stack_base;
    uint32_t stack_limit;
    double fpu[8];
    uint16_t x87_reserved;
    uint16_t fpu_control;
    uint16_t fpu_status;
    uint16_t reserved;
    uint8_t fs_data[64];
};

namespace lifted {

using LiftFunction = void (*)(LiftCpu* cpu, uint32_t stop_address);

inline constexpr uint32_t LIFT_CALLBACK_SENTINEL = 0xFFF0FFF0u;

uint32_t lift_callback_address(LiftFunction function);

void lift_push32(LiftCpu* cpu, uint32_t value);
uint32_t lift_pop32(LiftCpu* cpu);

void lift_native_call(LiftCpu* cpu, uint32_t target, uint32_t callsite);
[[noreturn]] void lift_trap(LiftCpu* cpu, uint32_t source_va, const char* reason);
int lift_call_indirect(LiftCpu* cpu, uint32_t target, uint32_t return_address, uint32_t callsite);
void lift_tail_indirect(LiftCpu* cpu, uint32_t target, uint32_t stop_address, uint32_t callsite);





} // namespace lifted
