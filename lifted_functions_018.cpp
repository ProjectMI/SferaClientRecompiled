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

} // namespace lifted
