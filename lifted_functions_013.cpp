#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint8_t sfera_buffer_cipher_key(uint32_t index) {
    switch (index % 9u) {
        case 0u: return UINT8_C(0x4B);
        case 1u: return UINT8_C(0x0D);
        case 2u: return UINT8_C(0xEF);
        case 3u: return UINT8_C(0x60);
        case 4u: return UINT8_C(0xC9);
        case 5u: return UINT8_C(0x9A);
        case 6u: return UINT8_C(0x70);
        case 7u: return UINT8_C(0x0E);
        default: return UINT8_C(0x03);
    }
}

__declspec(noinline) void sfera_sub_0048A1C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp <= 0) goto label_0008A203;
    label_0008A1D6:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (uint32_t)sfera_buffer_cipher_key(cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    *(uint8_t*)(cpu->esp + 0x13u) = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (uint16_t)((int16_t)(int8_t)cpu->eax * (int16_t)(int8_t)(*(uint8_t*)(cpu->esp + 0x13u)));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    ++cpu->esi;
    if ((int32_t)cpu->ecx < (int32_t)cpu->ebp) goto label_0008A1D6;
    label_0008A203:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
