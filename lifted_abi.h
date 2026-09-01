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
};

namespace lifted {

using LiftFunction = void (*)(LiftCpu* cpu, uint32_t stop_address);

inline constexpr uint32_t LIFT_RETURN_SENTINEL = 0xFFF0FFF0u;
void lift_push32(LiftCpu* cpu, uint32_t value);
uint32_t lift_pop32(LiftCpu* cpu);

void lift_native_call(LiftCpu* cpu, uint32_t target, uint32_t callsite);

} // namespace lifted
