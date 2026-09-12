#include "lifted_functions.h"
#include <cmath>
namespace lifted {


























__declspec(noinline) void sfera_sub_004D1C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000D1C4A;
    label_000D1C40:
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000D1C40;
    label_000D1C4A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}



__declspec(noinline) void sfera_sub_004D2180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->eax < 0x3FFFFFFEu) goto label_000D21A2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D2194u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4D2194u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D2180u); throw std::length_error("std::length_error");
    label_000D21A2:
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (cpu->eax != cpu->edx) goto label_000D21CC;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_000D21ED;
    label_000D21CC:
    if (*(uint8_t*)(cpu->esp + 0x10u) == (cpu->ebx & 0xFFu)) goto label_000D21DF;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_000D21ED;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_000D21ED;
    label_000D21DF:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_000D21ED;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_000D21ED:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000D238E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000D2200:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_000D22CF;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000D2232;
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    *(uint8_t*)(cpu->esi + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000D2380;
    label_000D2232:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_000D2271;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D224B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000D224B:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_000D225E;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_000D226C;
    label_000D225E:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_000D2269;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_000D226C;
    label_000D2269:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_000D226C:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_000D2271:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D2299;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_000D2299:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_000D22B2;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D237D;
    label_000D22B2:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_000D22C5;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D237D;
    label_000D22C5:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D237D;
    label_000D22CF:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000D22F2;
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    *(uint8_t*)(cpu->esi + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_000D2380;
    label_000D22F2:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_000D2332;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D230A;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000D230A:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_000D231D;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_000D232C;
    label_000D231D:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_000D232A;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_000D232C;
    label_000D232A:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_000D232C:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_000D2332:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x11u) != (cpu->ebx & 0xFFu)) goto label_000D235A;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_000D235A:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_000D236D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_000D237B;
    label_000D236D:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_000D2378;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_000D237B;
    label_000D2378:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_000D237B:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_000D237D:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_000D2380:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x10u) == (cpu->ebx & 0xFFu)) goto label_000D2200;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000D238E:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x10u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004D23B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x14u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D23BDu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4D23BDu));
    cpu->edx = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->edx) goto label_000D23F1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->eax + 0xCu;
    *(uint16_t*)(cpu->eax + 0x10u) = cpu->edx & 0xFFFFu;
    if (cpu->ecx == cpu->edx) goto label_000D23EA;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000D23EA:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D23F1:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D241Bu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D241Bu));
    cpu->eip = 0x4D241Bu; ::DebugBreak(); return;
}




















} // namespace lifted
