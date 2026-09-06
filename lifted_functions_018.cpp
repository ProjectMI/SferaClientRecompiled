#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004B1370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000B13BA;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x11u) != 0u) goto label_000B139D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000B139A;
    label_000B1390:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000B1390;
    label_000B139A:
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B139D:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x11u) != 0u) goto label_000B13B8;
    label_000B13A6:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->edx + 8u)) goto label_000B13B8;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->edx + 0x11u) == 0u) goto label_000B13A6;
    label_000B13B8:
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000B13BA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B19D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x11u) != 0u) goto label_000B19E8;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_000B19E8:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_000B1A02;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A02:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx)) goto label_000B1A13;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A13:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B1A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->esi + 0x11u) != 0u) goto label_000B1A38;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    label_000B1A38:
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 4u)) goto label_000B1A53;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A53:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->ecx + 8u)) goto label_000B1A67;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B1A67:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2000(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x11u) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (sub_pred[0]) goto label_000B2019;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B2000u); throw std::out_of_range("std::out_of_range");
    label_000B2019:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B202Bu)); sfera_sub_004B1370(cpu, LIFT_CODE_TOKEN_VA(0x4B202Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (*(uint8_t*)(cpu->ecx + 0x11u) == 0u) goto label_000B2038;
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    goto label_000B2050;
    label_000B2038:
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2045;
    cpu->edi = cpu->ecx;
    goto label_000B2050;
    label_000B2045:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebx) goto label_000B20B7;
    label_000B2050:
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint8_t*)(cpu->edi + 0x11u) != 0u) goto label_000B205C;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_000B205C:
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebx) goto label_000B2069;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_000B2074;
    label_000B2069:
    if (*(uint32_t*)(cpu->esi) != cpu->ebx) goto label_000B2071;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_000B2074;
    label_000B2071:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_000B2074:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x10u)) goto label_000B2092;
    if (*(uint8_t*)(cpu->edi + 0x11u) == 0u) goto label_000B2089;
    cpu->eax = cpu->esi;
    goto label_000B2090;
    label_000B2089:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB2090u)); sfera_sub_004D1C30(cpu, LIFT_CODE_TOKEN_RVA(0xB2090u));
    label_000B2090:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_000B2092:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->edx) goto label_000B210E;
    if (*(uint8_t*)(cpu->edi + 0x11u) == 0u) goto label_000B20AB;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_000B210E;
    label_000B20AB:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B20B2u)); sfera_sub_00402100(cpu, LIFT_CODE_TOKEN_VA(0x4B20B2u));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_000B210E;
    label_000B20B7:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebx + 8u)) goto label_000B20C7;
    cpu->esi = cpu->eax;
    goto label_000B20E1;
    label_000B20C7:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edi + 0x11u) != 0u) goto label_000B20D3;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_000B20D3:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_000B20E1:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebx) goto label_000B20EE;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_000B20FC;
    label_000B20EE:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebx) goto label_000B20F9;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_000B20FC;
    label_000B20F9:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_000B20FC:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x10u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x10u));
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebx + 0x10u) = cpu->ecx & 0xFFu;
    label_000B210E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->eax + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B2216;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->ecx + 4u)) goto label_000B2213;
    label_000B2130:
    if (*(uint8_t*)(cpu->edi + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B2213;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_000B21A2;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x10u) != 0u) goto label_000B215A;
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2157u)); sfera_sub_004B19D0(cpu, LIFT_CODE_TOKEN_VA(0x4B2157u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    label_000B215A:
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B21D2;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B216F;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x10u) == (cpu->ebx & 0xFFu)) goto label_000B21CE;
    label_000B216F:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B2189;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->eax + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2186u)); sfera_sub_004B1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B2186u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    label_000B2189:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x10u));
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B21A0u)); sfera_sub_004B19D0(cpu, LIFT_CODE_TOKEN_VA(0x4B21A0u));
    goto label_000B2213;
    label_000B21A2:
    if (*(uint8_t*)(cpu->eax + 0x10u) != 0u) goto label_000B21B9;
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B21B7u)); sfera_sub_004B1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B21B7u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    label_000B21B9:
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B21D2;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B21E5;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B21E5;
    label_000B21CE:
    *(uint8_t*)(cpu->eax + 0x10u) = 0u;
    label_000B21D2:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->edx + 4u)) goto label_000B2130;
    goto label_000B2213;
    label_000B21E5:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->ecx + 0x10u) != (cpu->ebx & 0xFFu)) goto label_000B21FD;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->eax + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B21FBu)); sfera_sub_004B19D0(cpu, LIFT_CODE_TOKEN_VA(0x4B21FBu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    label_000B21FD:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x10u));
    *(uint8_t*)(cpu->eax + 0x10u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->edx + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB2213u)); sfera_sub_004B1A20(cpu, LIFT_CODE_TOKEN_RVA(0xB2213u));
    label_000B2213:
    *(uint8_t*)(cpu->edi + 0x10u) = cpu->ebx & 0xFFu;
    label_000B2216:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2220u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B2220u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000B2231;
    --cpu->eax;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    label_000B2231:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->ecx;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x11u) != 0u) goto label_000B226F;
    label_000B2251:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B225Cu)); sfera_sub_004B2240(cpu, LIFT_CODE_TOKEN_VA(0x4B225Cu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2264u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B2264u));
    cpu->esp += 4u;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x11u) == 0u) goto label_000B2251;
    label_000B226F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2440(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x11u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (!sub_pred[0]) goto label_000B246A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    label_000B2455:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->esi) goto label_000B245F;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_000B2463;
    label_000B245F:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B2463:
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2455;
    cpu->esi = lift_pop32(cpu);
    label_000B246A:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->edx == cpu->eax) goto label_000B248D;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->edx + 0xCu)) goto label_000B248D;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000B248D:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B24B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->ebx;
    if (*(uint8_t*)(cpu->ebx + 0x11u) != 0u) goto label_000B24E1;
    label_000B24C3:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B24CEu)); sfera_sub_004B2240(cpu, LIFT_CODE_TOKEN_VA(0x4B24CEu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B24D6u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B24D6u));
    cpu->esp += 4u;
    cpu->ebx = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x11u) == 0u) goto label_000B24C3;
    label_000B24E1:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2500(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ebx;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    sub_pred[0] = *(uint8_t*)(cpu->edi + 0x11u) == 0u;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    if (!sub_pred[0]) goto label_000B2587;
    cpu->ecx = cpu->edi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B254Au)); sfera_sub_004D23B0(cpu, LIFT_CODE_TOKEN_VA(0x4B254Au));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x10u));
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->eax & 0xFFu;
    if (*(uint8_t*)(cpu->ecx + 0x11u) == 0u) goto label_000B2564;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    label_000B2564:
    cpu->edx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2576u)); sfera_sub_004B2500(cpu, LIFT_CODE_TOKEN_VA(0x4B2576u));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2584u)); sfera_sub_004B2500(cpu, LIFT_CODE_TOKEN_VA(0x4B2584u));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_000B2587:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B2C40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_000B2C6E;
    if (cpu->edx != cpu->eax) goto label_000B2C6E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2C5Eu)); sfera_sub_004B24B0(cpu, LIFT_CODE_TOKEN_VA(0x4B2C5Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B2C6E:
    if (cpu->ecx == cpu->edx) goto label_000B2CDF;
    label_000B2C72:
    cpu->edx = cpu->ecx;
    if (*(uint8_t*)(cpu->ecx + 0x11u) != 0u) goto label_000B2CC8;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2CA0;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2C9A;
    label_000B2C90:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2C90;
    label_000B2C9A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_000B2CC8;
    label_000B2CA0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x11u) != 0u) goto label_000B2CC4;
    label_000B2CB0:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_000B2CC4;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x11u) == 0u) goto label_000B2CB0;
    label_000B2CC4:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000B2CC8:
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B2CD5u)); sfera_sub_004B2000(cpu, LIFT_CODE_TOKEN_VA(0x4B2CD5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000B2C72;
    label_000B2CDF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8150(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint8_t)(*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_000B8160;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B8160:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2Eu); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4B8165u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebx != 0u) goto label_000B81AC;
    cpu->edx = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax = cpu->edi;
    cpu->edx -= cpu->edi;
    label_000B8180:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B8180;
    cpu->eax = (uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->edx = cpu->eax;
    label_000B8191:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B8191;
    cpu->edi = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_000B81A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000B81A0;
    cpu->esi = cpu->edx;
    goto label_000B8219;
    label_000B81AC:
    cpu->esi = cpu->ebx;
    cpu->esi -= cpu->edi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4B81B7u));
    cpu->eax = (uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + ((uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0])) = 0u;
    cpu->ecx = cpu->eax;
    label_000B81D0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B81D0;
    cpu->edi = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000B81E1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000B81E1;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->ebx;
    cpu->ecx = cpu->eax;
    label_000B8200:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B8200;
    cpu->edi = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000B8211:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000B8211;
    label_000B8219:
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (uintptr_t)&g_sfera_ui_load_scratch_runtime.resolved_ui_path[0];
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8250(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = cpu->ecx;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08 == 0u) goto label_000B82B4;
    cpu->esi = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09 <= cpu->esi) goto label_000B82B4;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->edi = 0u;
    label_000B8292:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = *(uint32_t*)(cpu->edi + cpu->eax);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->ebx);

    if (cpu->eax == 0u) goto label_000B831D;
    ++cpu->esi;
    cpu->edi += 0x98u;
    if (cpu->esi < *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) goto label_000B8292;
    label_000B82B4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82BBu)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4B82BBu));
    if (cpu->eax == 0xFFFFFFFFu) goto label_000B8347;
    cpu->edx = 0x2E9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82D3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B82D3u));
    lift_push32(cpu, 0x98u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82DDu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4B82DDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_000B82F7;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B82F5u)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4B82F5u));
    cpu->esi = cpu->eax;
    label_000B82F7:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8307u)); sfera_sub_004CF1A0(cpu, LIFT_CODE_TOKEN_VA(0x4B8307u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B831D:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x98u);
    ++*(uint32_t*)(cpu->esi + cpu->ecx + 0x8Cu);
    cpu->eax = cpu->esi + cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B8347:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B83C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) != cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B84B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B8550;
    cpu->eax += 0xFFFFFFC0u;
    if (cpu->eax > 0xBFu) goto label_000B8550;
    switch (cpu->eax) {
        case 0u: case 1u: goto label_000B84F6;
        case 2u: goto label_000B8515;
        case 3u: goto label_000B8534;
        case 191u: goto label_000B84DC;
        default: goto label_000B8550;
    }
label_000B84DC: ;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B84E9u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B84E9u));
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B84F6:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"curseye"); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8508u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8508u));
    g_sfera_interface_runtime.cursor_kind = 0x40u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B8515:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"cursman"); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8527u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8527u));
    g_sfera_interface_runtime.cursor_kind = 0x42u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B8534:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"cursman"); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8546u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8546u));
    g_sfera_interface_runtime.cursor_kind = 0x43u;
    label_000B8550:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8630(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B867A;
    if (cpu->esi != 0u) goto label_000B8656;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B864Bu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B864Bu));
    g_sfera_ui_load_scratch_runtime.cursor_name[0] = (uint8_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B8656:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8664u)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B8664u));
    cpu->edx = (uintptr_t)g_sfera_ui_load_scratch_runtime.cursor_name;
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_000B8670:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B8670;
    label_000B867A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B869F;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B869Eu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4B869Eu));
    cpu->esi = lift_pop32(cpu);
    label_000B869F:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B86B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B86CA;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B86C9u)); sfera_sub_004A1AD0(cpu, LIFT_CODE_TOKEN_VA(0x4B86C9u));
    cpu->esi = lift_pop32(cpu);
    label_000B86CA:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B86D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == 0u) goto label_000B86F3;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B86F2u)); sfera_sub_004A1B00(cpu, LIFT_CODE_TOKEN_VA(0x4B86F2u));
    cpu->esi = lift_pop32(cpu);
    label_000B86F3:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->esi == 0u) goto label_000B8737;
    if (*(uint32_t*)(cpu->esi + 0xD8u) == 0u) goto label_000B8727;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B871Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B871Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8724u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8724u));
    cpu->esp += 0xCu;
    label_000B8727:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->edi!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8737u)); sfera_ui_window_begin_close(cpu, LIFT_CODE_TOKEN_RVA(0xB8737u));
    label_000B8737:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8740(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx != 0u) goto label_000B8747;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B8747:
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B874Du)); sfera_ui_window_poll_event(cpu, LIFT_CODE_TOKEN_VA(0x4B874Du));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->esi != 0u) goto label_000B875F;
    label_000B875A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B875F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8764u)); sfera_ui_window_control_kind(cpu, LIFT_CODE_TOKEN_VA(0x4B8764u));
    if (cpu->eax != 0xCu) goto label_000B875A;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8771u)); sfera_ui_list_item_ctrl_item_at(cpu, LIFT_CODE_TOKEN_VA(0x4B8771u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8780(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000B8792;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    label_000B8792:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B87A0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000B87B2;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x30u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    label_000B87B2:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8850(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->edi = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08 == cpu->edi) goto label_000B88C4;
    cpu->edx = 0x216u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8895u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8895u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    if (cpu->eax == cpu->edi) goto label_000B88BE;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = cpu->eax + 0xFFFFFFFCu;
    { uint32_t current = cpu->eax + 0x98u * cpu->ecx; uint32_t count = cpu->ecx; while (count-- != 0u) { current -= 0x98u; cpu->ecx = current; lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88B5u)); sfera_sub_004CF160(cpu, LIFT_CODE_TOKEN_VA(0x4B88B5u)); } }
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88BBu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B88BBu));
    cpu->esp += 4u;
    label_000B88BE:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = cpu->edi;
    label_000B88C4:
    cpu->edx = 0x21Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88D9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B88D9u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B88E3u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4B88E3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_000B88FD;
    cpu->ecx = cpu->eax;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->initialize(); cpu->eax = cpu->ecx; }
    cpu->esi = cpu->eax;
    goto label_000B88FF;
    label_000B88FD:
    cpu->esi = 0u;
    label_000B88FF:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    { const uint32_t __parser_arg_018_31_0 = static_cast<uint32_t>(cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->load(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_018_31_0))); }
    { const uint32_t __parser_arg_018_32_0 = static_cast<uint32_t>(cpu->edi); const uint32_t __parser_arg_018_32_1 = static_cast<uint32_t>((uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(__parser_direct->countBlocks(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_018_32_1)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_018_32_0)))); }
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi <= 0) goto label_000B8A07;
    cpu->edx = 0x226u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8938u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8938u));
    cpu->eax = cpu->edi;
    cpu->edx = 0x98u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    cpu->eax = 0u;
    cpu->ecx += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->ecx < 4u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B895Cu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4B895Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    if (cpu->eax == 0u) goto label_000B8991;
    cpu->ebx = cpu->eax + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    { uint32_t base = cpu->ebx; uint32_t total = cpu->edi; uint32_t current = base; uint32_t built = 0u; try { while (built < total) { cpu->ecx = current; lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B898Au)); sfera_sub_004CDF00(cpu, LIFT_CODE_TOKEN_VA(0x4B898Au)); current += 0x98u; ++built; } } catch (...) { current = base + 0x98u * built; while (built-- != 0u) { current -= 0x98u; cpu->ecx = current; lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B898Au)); sfera_sub_004CF160(cpu, LIFT_CODE_TOKEN_VA(0x4B898Au)); } throw; } }
    cpu->eax = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    goto label_000B8993;
    label_000B8991:
    cpu->eax = 0u;
    label_000B8993:
    { const uint32_t __parser_arg_018_33_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setBlockRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_018_33_0))); }
    cpu->ecx = cpu->esp + 0x14u;
    { const uint32_t __parser_arg_018_34_0 = static_cast<uint32_t>(cpu->ecx); const uint32_t __parser_arg_018_34_1 = static_cast<uint32_t>((uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_018_34_1)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_018_34_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000B8A00;
    cpu->edi = 0u;
    label_000B89D0:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi + cpu->edx;
    lift_push32(cpu, cpu->ebx);
    cpu->edi += 0x98u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B89EBu)); sfera_sub_004CE8A0(cpu, LIFT_CODE_TOKEN_VA(0x4B89EBu));
    cpu->ecx = cpu->esp + 0x14u;
    { const uint32_t __parser_arg_018_35_0 = static_cast<uint32_t>(cpu->ecx); const uint32_t __parser_arg_018_35_1 = static_cast<uint32_t>((uintptr_t)"sprite");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_018_35_1)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_018_35_0))) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000B89D0;
    label_000B8A00:
    cpu->ecx = cpu->esi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->clearBlockRange(); }
    label_000B8A07:
    cpu->edx = 0x234u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A16u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B8A16u));
    if (cpu->esi == 0u) goto label_000B8A2A;
    cpu->ecx = cpu->esi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->release(); }
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A27u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B8A27u));
    cpu->esp += 4u;
    label_000B8A2A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    if (cpu->ecx != 0u) goto label_000B8A5C;
    if (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready != (cpu->ecx & 0xFFu)) goto label_000B8A93;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    cpu->esp += 8u;
    sfera_ui_tool_tip_ctrl_reset(cpu, stop_address); return;
    label_000B8A5C:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0xBB9u);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A6Eu)); sfera_ui_tool_tip_ctrl_handle_message(cpu, LIFT_CODE_TOKEN_VA(0x4B8A6Eu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8A73u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4B8A73u));
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8A93u)); sfera_ui_tool_tip_ctrl_show_at(cpu, LIFT_CODE_TOKEN_RVA(0xB8A93u));
    label_000B8A93:
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B8AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000B8AFF;
    if (cpu->ecx > 0x4924924u) goto label_000B8AD1;
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B8ACAu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4B8ACAu));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000B8AFF;
    label_000B8AD1:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB8AFFu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xB8AFFu));
    label_000B8AFF:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B90A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->esi = 0u;
    if ((cpu->eax += cpu->edx) == 0u) goto label_000B9114;
    cpu->ebx = 0u;
    label_000B90D0:
    cpu->eax = cpu->ebx + cpu->edi;
    if (*(uint32_t*)(cpu->ebx + cpu->edi + 0x14u) < 0x10u) goto label_000B90DC;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B90DC:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4B90DEu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000B911C;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx -= cpu->edi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    ++cpu->esi;
    cpu->ecx += cpu->edx;
    cpu->ebx += 0x38u;
    if (cpu->esi < cpu->ecx) goto label_000B90D0;
    label_000B9114:
    cpu->eax = cpu->edi + 0x1Cu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B911C:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->edx = cpu->esi * 8u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx -= cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->eax + (cpu->edx * 8u) + 0x1Cu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9145u)); sfera_sub_004B90A0(cpu, LIFT_CODE_TOKEN_VA(0x4B9145u));
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000B914D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B914D:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->ecx == 0u) goto label_000B9185;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax == 0u) goto label_000B9185;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x64u);
    if (cpu->esi <= cpu->eax) goto label_000B9169;
    cpu->esi = cpu->eax;
    label_000B9169:
    cpu->eax = cpu->ecx + 0x54u;
    if (*(uint32_t*)(cpu->ecx + 0x68u) < 0x10u) goto label_000B9174;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9174:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4B9177u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + cpu->edi) = 0u;
    cpu->esi = lift_pop32(cpu);
    label_000B9185:
    cpu->edi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B919Au)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4B919Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000B91C3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_000B91BD;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_000B91BD:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000B91C3:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B91F1u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4B91F1u));
    cpu->eip = 0x4B91F1u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004B92D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    if (cpu->edi != 0u) goto label_000B92D9;
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B92D9:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx);
    if (cpu->esi == cpu->ebx) goto label_000B932E;
    label_000B92E7:
    cpu->eax = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_000B92F2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B92F2:
    cpu->ecx = cpu->edi;
    label_000B92F4:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000B9314;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000B9310;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000B9314;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000B92F4;
    label_000B9310:
    cpu->eax = 0u;
    goto label_000B9319;
    label_000B9314:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000B9319:
    if (cpu->eax == 0u) goto label_000B932A;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->ebx) goto label_000B92E7;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B932A:
    if (cpu->esi != cpu->ebx) goto label_000B9335;
    label_000B932E:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000B9335:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->eax) goto label_000B9380;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_000B9366:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->edi);

    if (cpu->eax == 0u) goto label_000B9386;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) goto label_000B9366;
    label_000B9380:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9386:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000B93D2;
    lift_push32(cpu, cpu->edi);
    label_000B93A0:
    cpu->edx = 0x1A8u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93AFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B93AFu));
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->edi == 0u) goto label_000B93C6;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93BDu)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4B93BDu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93C3u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B93C3u));
    cpu->esp += 4u;
    label_000B93C6:
    cpu->esi = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    if (cpu->esi != cpu->eax) goto label_000B93A0;
    cpu->edi = lift_pop32(cpu);
    label_000B93D2:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor) = 0u;
    if (cpu->ecx == *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) goto label_000B9405;
    label_000B93F0:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B93F8u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B93F8u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) goto label_000B93F0;
    label_000B9405:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9410(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor <= 0u) goto label_000B9496;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->ecx) goto label_000B945B;
    label_000B9430:
    cpu->edx = 0x273u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B943Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B943Fu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->ecx == 0u) goto label_000B944F;
    lift_push32(cpu, 1u);
    { auto* destroyed_window = reinterpret_cast<SphereUI::Window*>(cpu->ecx); destroyed_window->destroy((*(uint32_t*)(cpu->esp) & 1u) != 0u); cpu->eax = address32(destroyed_window); } cpu->esp += 4u;
    label_000B944F:
    cpu->esi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    if (cpu->esi != cpu->ecx) goto label_000B9430;
    label_000B945B:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor) = 0u;
    if (cpu->eax == *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) goto label_000B9495;
    label_000B9480:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9488u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B9488u));
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) goto label_000B9480;
    label_000B9495:
    cpu->esi = lift_pop32(cpu);
    label_000B9496:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B94A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->eax == cpu->ecx) goto label_000B9534;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_000B94B4:
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    if (*(uint32_t*)(cpu->edi + 0xD8u) == 0u) goto label_000B94DC;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(0x%X) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B94CDu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4B94CDu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B94D3u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4B94D3u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 0xCu;
    label_000B94DC:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->ebp = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_000B950A;
    label_000B94E4:
    if (*(uint32_t*)(cpu->esi + 8u) != cpu->edi) goto label_000B9504;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B94F9u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4B94F9u));
    cpu->esp += 4u;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    goto label_000B9506;
    label_000B9504:
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000B9506:
    if (cpu->esi != cpu->ebp) goto label_000B94E4;
    label_000B950A:
    cpu->edx = 0x283u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9519u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4B9519u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { auto* destroyed_window = reinterpret_cast<SphereUI::Window*>(cpu->ecx); destroyed_window->destroy((*(uint32_t*)(cpu->esp) & 1u) != 0u); cpu->eax = address32(destroyed_window); } cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = cpu->ebx;
    if (cpu->ebx != cpu->ecx) goto label_000B94B4;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000B9534:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9620(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9650u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4B9650u));
    cpu->eax = g_sfera_screen_clip_runtime.top;
    cpu->ecx = g_sfera_screen_clip_runtime.bottom;
    cpu->edi = g_sfera_screen_clip_runtime.left;
    cpu->ebp = g_sfera_screen_clip_runtime.right;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((uint8_t)(g_sfera_interface_runtime.primary_gate) == 0u) goto label_000B96B2;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000B9698;
    label_000B9683:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->draw();
    cpu->esi = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    if (cpu->esi != cpu->eax) goto label_000B9683;
    label_000B9698:
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000B96B2;
    label_000B96A0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B96A8u)); sfera_ui_window_draw_tool_tips(cpu, LIFT_CODE_TOKEN_VA(0x4B96A8u));
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) goto label_000B96A0;
    label_000B96B2:
    if (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready != 0u) goto label_000B96C5;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB96C5u)); sfera_ui_tool_tip_ctrl_draw(cpu, LIFT_CODE_TOKEN_RVA(0xB96C5u));
    label_000B96C5:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->eax == 0u) goto label_000B97D8;
    if (*(uint8_t*)(cpu->eax) == 0u) goto label_000B97D8;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->esi |= 0xFFFFFFFFu;
    lift_test[0]=((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)&1u)==0u;
    g_sfera_screen_clip_runtime.left = 0u;
    g_sfera_screen_clip_runtime.top = 0u;
    g_sfera_screen_clip_runtime.bottom = cpu->ecx;
    g_sfera_screen_clip_runtime.right = cpu->edx;
    if (!lift_test[0]) goto label_000B973D;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B972Cu)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x4B972Cu));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA360) ? 0u : 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    label_000B973D:
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if (cpu->ecx != 0u) goto label_000B9757;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9751u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4B9751u));
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    label_000B9757:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    if ((((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_000B9796;
    cpu->eax = 1u;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9785u)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x4B9785u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA360) ? 0u : 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    label_000B9796:
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if (cpu->ecx != 0u) goto label_000B97B0;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B97AAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4B97AAu));
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    label_000B97B0:
    cpu->eax = reinterpret_cast<CCursor*>(cpu->ecx)->isInsideViewport() ? 1u : 0u;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000B97D8;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB97D8u)); sfera_sub_004A1B70(cpu, LIFT_CODE_TOKEN_RVA(0xB97D8u));
    label_000B97D8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    g_sfera_screen_clip_runtime.top = cpu->ecx;
    cpu->ecx = 0u;
    g_sfera_screen_clip_runtime.left = cpu->edi;
    g_sfera_screen_clip_runtime.right = cpu->ebp;
    g_sfera_screen_clip_runtime.bottom = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B97FFu)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x4B97FFu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9820(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000B9849;
    if (cpu->edx != 0u) goto label_000B982B;
    cpu->eax = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B982B:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->edx <= 1u) goto label_000B9845;
    cpu->ecx = cpu->edx + 0xFFFFFFFFu;
    label_000B9840:
    --cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != 0u) goto label_000B9840;
    label_000B9845:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9849:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->eax) goto label_000B9895;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_000B9870:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000B9880;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9880:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->edi);

    if (cpu->eax == 0u) goto label_000B989B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) goto label_000B9870;
    label_000B9895:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B989B:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B98B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B98BCu)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4B98BCu));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ebp = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->ebp) goto label_000B995B;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    (void)cpu;
    label_000B98E0:
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000B9941;
    if (*(uint8_t*)(cpu->esi + 0x4Fu) != 0u) goto label_000B9941;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000B9915;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9915u)); sfera_ui_window_get_absolute_position(cpu, LIFT_CODE_TOKEN_RVA(0xB9915u));
    label_000B9915:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->eax > (int32_t)cpu->ebx) goto label_000B9941;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->ebx >= (int32_t)cpu->edx) goto label_000B9941;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ecx > (int32_t)cpu->eax) goto label_000B9941;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000B9951;
    label_000B9941:
    cpu->eax = cpu->edi;
    if (cpu->eax != cpu->ebp) goto label_000B98E0;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9951:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B995B:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B99E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->eax = 0u;
    if (cpu->ecx == cpu->edx) goto label_000B9A05;
    lift_push32(cpu, cpu->esi);
    (void)cpu;
    label_000B99F0:
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->eax + cpu->esi + 9u;
    if (cpu->ecx != cpu->edx) goto label_000B99F0;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000B9A05;
    cpu->eax += 4u;
    label_000B9A05:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
