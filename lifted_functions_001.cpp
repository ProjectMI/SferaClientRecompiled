#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_0040A270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_0000A2FD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::memmove);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = cpu->ecx + 0x14u;
    cpu->ebx = 0u;
    (void)cpu;
    label_0000A290:
    cpu->eax = cpu->esi + 0xFFFFFFECu;
    if (cpu->edi == cpu->eax) goto label_0000A2E6;
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000A2A8;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A2A5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A2A5u));
    cpu->esp += 4u;
    label_0000A2A8:
    *(uint32_t*)(cpu->edi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    *(uint8_t*)(cpu->edi) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi) >= 0x10u) goto label_0000A2CA;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    ++cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0xFFFFFFECu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0xA2C5u), LIFT_CODE_TOKEN_RVA(0xA2C3u))) { return; }
    cpu->esp += 0xCu;
    goto label_0000A2D2;
    label_0000A2CA:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFECu);
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xFFFFFFECu) = cpu->ebx;
    label_0000A2D2:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_0000A2E6:
    cpu->esi += 0x1Cu;
    cpu->ecx = cpu->esi + 0xFFFFFFECu;
    cpu->edi += 0x1Cu;
    if (cpu->ecx != cpu->edx) goto label_0000A290;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000A2FD:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A33C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A332u)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40A332u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A33C:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if (cpu->ebx != *(uint32_t*)(cpu->eax)) goto label_0000A36E;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->ebx + 0xCu)) goto label_0000A44D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A362u)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40A362u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A36E:
    if (cpu->ebx != cpu->eax) goto label_0000A39B;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->edi + 0xCu)) goto label_0000A44D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A38Fu)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40A38Fu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A39B:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0xCu);
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0xCu), r=cpu->ebp, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0000A3F6;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A3B0u)); sfera_sub_00402660(cpu, LIFT_CODE_TOKEN_VA(0x40A3B0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->ebp) goto label_0000A3F3;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x19u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A3DE;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A3D2u)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40A3D2u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A3DE:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A3E7u)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40A3E7u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A3F3:
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0xCu), r=cpu->ebp, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0000A3F6:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0000A44D;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A405u)); sfera_sub_004023F0(cpu, LIFT_CODE_TOKEN_VA(0x40A405u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_0000A413;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_0000A44D;
    label_0000A413:
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    { uint64_t l=*(uint8_t*)(cpu->edx + 0x19u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A438;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A42Cu)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40A42Cu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A438:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A441u)); sfera_sub_00407C80(cpu, LIFT_CODE_TOKEN_VA(0x40A441u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A44D:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A45Cu)); sfera_sub_00408FF0(cpu, LIFT_CODE_TOKEN_VA(0x40A45Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi += 8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A4C5;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A4B9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40A4B9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A4C2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A4C2u));
    cpu->esp += 4u;
    label_0000A4C5:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000A4D6;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A4D3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A4D3u));
    cpu->esp += 4u;
    label_0000A4D6:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A500(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A512u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x40A512u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->edi = cpu->eax + 1u;
    label_0000A530:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0000A530;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A542u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x40A542u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == cpu->ecx) goto label_0000A582;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    label_0000A560:
    if (cpu->edx == cpu->esi) goto label_0000A56B;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->ecx) goto label_0000A560;
    label_0000A56B:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_0000A582;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A57Du)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x40A57Du));
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000A582:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A590(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 8u);
    if ((int32_t)cpu->edi < 0) goto label_0000A5D7;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->esi -= *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->esi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->esi = lift_pop32(cpu);
    if (cpu->edi >= cpu->eax) goto label_0000A5D7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = cpu->edi * 8u;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ecx + (cpu->eax * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A5D1u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x40A5D1u));
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000A5D7:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->eax < 0) goto label_0000A66F;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    { uint64_t l=cpu->ecx, r=*(uint32_t*)(cpu->esi + 0x10u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = (int32_t)(cpu->ecx) >> 3u;
    if (cpu->eax >= cpu->ecx) goto label_0000A66F;
    { uint64_t l=*(uint8_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A60E;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    { uint64_t l=cpu->edi, r=*(uint32_t*)(cpu->esi + 0x10u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = (int32_t)(cpu->edi) >> 3u;
    goto label_0000A612;
    label_0000A60E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    label_0000A612:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->eax + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A629u)); sfera_sub_004024D0(cpu, LIFT_CODE_TOKEN_VA(0x40A629u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx + 0xFFFFFFF8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A63Du)); sfera_sub_004063F0(cpu, LIFT_CODE_TOKEN_VA(0x40A63Du));
    *(uint32_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x14u)) + (uint64_t)(0xFFFFFFF8u) + (uint64_t)(0u);
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_0000A668;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    { uint64_t l=cpu->edx, r=*(uint32_t*)(cpu->esi + 0x10u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    if (cpu->edi >= cpu->edx) goto label_0000A664;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = cpu->eax + (cpu->edi * 8u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000A664:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_0000A668:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000A66F:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000A6DD;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000A6B3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A6B0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A6B0u));
    cpu->esp += 4u;
    label_0000A6B3:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A6C8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40A6C8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000A6DD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A6F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->esi >= cpu->eax) goto label_0000A744;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if (cpu->ecx > cpu->esi) goto label_0000A744;
    { uint64_t l=cpu->esi, r=cpu->ecx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = (int32_t)(cpu->esi) >> 3u;
    if (cpu->eax != *(uint32_t*)(cpu->edi + 8u)) goto label_0000A718;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA718u)); sfera_sub_00409790(cpu, LIFT_CODE_TOKEN_RVA(0xA718u));
    label_0000A718:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->eax + (cpu->esi * 8u);
    if (cpu->ecx == 0u) goto label_0000A770;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000A744:
    if (cpu->eax != *(uint32_t*)(cpu->edi + 8u)) goto label_0000A752;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xA752u)); sfera_sub_00409790(cpu, LIFT_CODE_TOKEN_RVA(0xA752u));
    label_0000A752:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax == 0u) goto label_0000A770;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi) = 0u;
    label_0000A770:
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A796u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x40A796u));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A7A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000A7EA;
    if (cpu->edx != cpu->eax) goto label_0000A7EA;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A7C2u)); sfera_sub_004097F0(cpu, LIFT_CODE_TOKEN_VA(0x40A7C2u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000A7EA:
    if (cpu->ecx == cpu->edx) goto label_0000A85F;
    label_0000A7F0:
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x29u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A848;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x29u) != 0u) goto label_0000A820;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x29u) != 0u) goto label_0000A81A;
    label_0000A810:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x29u) == 0u) goto label_0000A810;
    label_0000A81A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_0000A848;
    label_0000A820:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x29u) != 0u) goto label_0000A844;
    label_0000A830:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_0000A844;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x29u) == 0u) goto label_0000A830;
    label_0000A844:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0000A848:
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A855u)); sfera_sub_00409850(cpu, LIFT_CODE_TOKEN_VA(0x40A855u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0000A7F0;
    label_0000A85F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040AB60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AB73u)); sfera_sub_004089F0(cpu, LIFT_CODE_TOKEN_VA(0x40AB73u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    *(uint8_t*)(cpu->edi + 8u) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040AB90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx += cpu->eax;
    cpu->esi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_0000ABC1;
    lift_push32(cpu, cpu->ebx);
    label_0000ABB0:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->ebx;
    if (cpu->eax != cpu->edx) goto label_0000ABB0;
    cpu->ebx = lift_pop32(cpu);
    label_0000ABC1:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    { uint64_t l=*(uint32_t*)(cpu->ecx + 0x24u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000ABD6;
    cpu->edx >>= 1u;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_0000ABD6:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    { uint64_t l=*(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = cpu->edx + (cpu->eax * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000ABFF;
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000ABF7;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) = cpu->esi;
    goto label_0000AC07;
    label_0000ABF7:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    goto label_0000AC07;
    label_0000ABFF:
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000AC0B;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_0000AC07:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000AC0B:
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AC19u)); sfera_sub_00406BA0(cpu, LIFT_CODE_TOKEN_VA(0x40AC19u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040AC20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_0000AC50;
    label_0000AC40:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edi ^= cpu->ebx;
    if (cpu->eax != cpu->edx) goto label_0000AC40;
    label_0000AC50:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->edi;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x24u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000AC65;
    cpu->edx >>= 1u;
    cpu->edi |= 0xFFFFFFFFu;
    cpu->edi -= cpu->edx;
    cpu->eax += cpu->edi;
    label_0000AC65:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { uint64_t l=*(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u), r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = cpu->edx + (cpu->eax * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000AC8E;
    if (*(uint32_t*)(cpu->edx) != cpu->ecx) goto label_0000AC86;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) = cpu->ecx;
    goto label_0000AC96;
    label_0000AC86:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    goto label_0000AC96;
    label_0000AC8E:
    if (*(uint32_t*)(cpu->edx) != cpu->ecx) goto label_0000AC9A;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    label_0000AC96:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000AC9A:
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    cpu->edi = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esi + 4u)) goto label_0000ACC5;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->ecx + 4u;
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ACB9u)); sfera_sub_00403C10(cpu, LIFT_CODE_TOKEN_VA(0x40ACB9u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ACBFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40ACBFu));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 8u);
    label_0000ACC5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040ACE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x30u) < 0x10u) goto label_0000ACF5;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ACF2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40ACF2u));
    cpu->esp += 4u;
    label_0000ACF5:
    *(uint32_t*)(cpu->esi + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x2Cu) = 0u;
    *(uint8_t*)(cpu->esi + 0x1Cu) = 0u;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000AD18;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AD15u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40AD15u));
    cpu->esp += 4u;
    label_0000AD18:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040AD30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000AD81;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AD75u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40AD75u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AD7Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40AD7Eu));
    cpu->esp += 4u;
    label_0000AD81:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000AD92;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AD8Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40AD8Fu));
    cpu->esp += 4u;
    label_0000AD92:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040ADC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if (cpu->eax < 0x7FFFFFEu) goto label_0000AE05;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_0000ADE2;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ADDFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40ADDFu));
    cpu->esp += 4u;
    label_0000ADE2:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ADF7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40ADF7u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40ADE2u), "std::length_error");
    label_0000AE05:
    ++cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if (cpu->eax != cpu->edx) goto label_0000AE2E;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_0000AE4F;
    label_0000AE2E:
    if (*(uint8_t*)(cpu->esp + 0x14u) == (cpu->ebx & 0xFFu)) goto label_0000AE41;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000AE4F;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_0000AE4F;
    label_0000AE41:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000AE4F;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_0000AE4F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000AFED;
    lift_push32(cpu, cpu->edi);
    label_0000AE60:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_0000AF2F;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000AE92;
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    *(uint8_t*)(cpu->esi + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000AFE0;
    label_0000AE92:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000AED1;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000AEAB;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000AEAB:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000AEBE;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000AECC;
    label_0000AEBE:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_0000AEC9;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_0000AECC;
    label_0000AEC9:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_0000AECC:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000AED1:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000AEF9;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000AEF9:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000AF12;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000AFDD;
    label_0000AF12:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_0000AF25;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000AFDD;
    label_0000AF25:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000AFDD;
    label_0000AF2F:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000AF52;
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    *(uint8_t*)(cpu->esi + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000AFE0;
    label_0000AF52:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000AF92;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000AF6A;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000AF6A:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000AF7D;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000AF8C;
    label_0000AF7D:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0000AF8A;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000AF8C;
    label_0000AF8A:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000AF8C:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000AF92:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000AFBA;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000AFBA:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000AFCD;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_0000AFDB;
    label_0000AFCD:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000AFD8;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_0000AFDB;
    label_0000AFD8:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_0000AFDB:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000AFDD:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_0000AFE0:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) == (cpu->ebx & 0xFFu)) goto label_0000AE60;
    cpu->edi = lift_pop32(cpu);
    label_0000AFED:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x2Cu) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if (cpu->eax < 0x7FFFFFEu) goto label_0000B055;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    if (*(uint32_t*)(cpu->esi + 0x24u) < 0x10u) goto label_0000B032;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B02Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B02Fu));
    cpu->esp += 4u;
    label_0000B032:
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B047u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B047u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40B032u), "std::length_error");
    label_0000B055:
    ++cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if (cpu->eax != cpu->edx) goto label_0000B07E;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_0000B09F;
    label_0000B07E:
    if (*(uint8_t*)(cpu->esp + 0x14u) == (cpu->ebx & 0xFFu)) goto label_0000B091;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000B09F;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_0000B09F;
    label_0000B091:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000B09F;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_0000B09F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000B23D;
    lift_push32(cpu, cpu->edi);
    label_0000B0B0:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_0000B17F;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000B0E2;
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    *(uint8_t*)(cpu->esi + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000B230;
    label_0000B0E2:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000B121;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000B0FB;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000B0FB:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000B10E;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000B11C;
    label_0000B10E:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_0000B119;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_0000B11C;
    label_0000B119:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_0000B11C:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000B121:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000B149;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000B149:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000B162;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B22D;
    label_0000B162:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_0000B175;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B22D;
    label_0000B175:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B22D;
    label_0000B17F:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000B1A2;
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    *(uint8_t*)(cpu->esi + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000B230;
    label_0000B1A2:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000B1E2;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000B1BA;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000B1BA:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000B1CD;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000B1DC;
    label_0000B1CD:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0000B1DA;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B1DC;
    label_0000B1DA:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000B1DC:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000B1E2:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000B20A;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000B20A:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000B21D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_0000B22B;
    label_0000B21D:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000B228;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_0000B22B;
    label_0000B228:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_0000B22B:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000B22D:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_0000B230:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) == (cpu->ebx & 0xFFu)) goto label_0000B0B0;
    cpu->edi = lift_pop32(cpu);
    label_0000B23D:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x2Cu) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (cpu->eax < 0x4924923u) goto label_0000B2C6;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp = 0x10u;
    if (*(uint32_t*)(cpu->esi + 0x3Cu) < cpu->ebp) goto label_0000B288;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B285u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B285u));
    cpu->esp += 4u;
    label_0000B288:
    cpu->ebx = 0u;
    cpu->edi = 0xFu;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x28u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x20u) < cpu->ebp) goto label_0000B2A9;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B2A6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B2A6u));
    cpu->esp += 4u;
    label_0000B2A9:
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B2B8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B2B8u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40B2A9u), "std::length_error");
    label_0000B2C6:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if (cpu->eax != cpu->edx) goto label_0000B2EE;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    goto label_0000B30F;
    label_0000B2EE:
    if (*(uint8_t*)(cpu->esp + 0x18u) == (cpu->ebx & 0xFFu)) goto label_0000B301;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000B30F;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_0000B30F;
    label_0000B301:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000B30F;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_0000B30F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000B4AC;
    label_0000B320:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_0000B3EF;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000B352;
    *(uint8_t*)(cpu->edx + 0x44u) = 1u;
    *(uint8_t*)(cpu->esi + 0x44u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x44u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000B4A0;
    label_0000B352:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000B391;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x45u) != (cpu->ebx & 0xFFu)) goto label_0000B36B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000B36B:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000B37E;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000B38C;
    label_0000B37E:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_0000B389;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_0000B38C;
    label_0000B389:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_0000B38C:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000B391:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x44u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x44u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x45u) != (cpu->ebx & 0xFFu)) goto label_0000B3B9;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000B3B9:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000B3D2;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B49D;
    label_0000B3D2:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_0000B3E5;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B49D;
    label_0000B3E5:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B49D;
    label_0000B3EF:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000B412;
    *(uint8_t*)(cpu->edx + 0x44u) = 1u;
    *(uint8_t*)(cpu->esi + 0x44u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x44u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000B4A0;
    label_0000B412:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000B452;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x45u) != (cpu->ebx & 0xFFu)) goto label_0000B42A;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000B42A:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000B43D;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000B44C;
    label_0000B43D:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0000B44A;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B44C;
    label_0000B44A:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000B44C:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000B452:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x44u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x44u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x45u) != (cpu->ebx & 0xFFu)) goto label_0000B47A;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000B47A:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000B48D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_0000B49B;
    label_0000B48D:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000B498;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_0000B49B;
    label_0000B498:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_0000B49B:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000B49D:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_0000B4A0:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x44u) == (cpu->ebx & 0xFFu)) goto label_0000B320;
    label_0000B4AC:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x44u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->esi);
    if (cpu->eax < 0x71C71C6u) goto label_0000B4FE;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->esi + 0xCu;
    cpu->ecx += 0xDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B4EAu)); sfera_sub_0040AD30(cpu, LIFT_CODE_TOKEN_VA(0x40B4EAu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B4F0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B4F0u));
    cpu->esp += 4u;
    lift_push32(cpu, (uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40B4D0u), "std::length_error");
    label_0000B4FE:
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->ebp + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (cpu->eax != cpu->edx) goto label_0000B525;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    goto label_0000B543;
    label_0000B525:
    if (*(uint8_t*)(cpu->esp + 0x14u) == (cpu->ebx & 0xFFu)) goto label_0000B538;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000B546;
    *(uint32_t*)(cpu->edx) = cpu->ebp;
    goto label_0000B546;
    label_0000B538:
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000B546;
    label_0000B543:
    *(uint32_t*)(cpu->edx + 8u) = cpu->ebp;
    label_0000B546:
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if (*(uint8_t*)(cpu->edx + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000B6E2;
    lift_push32(cpu, cpu->edi);
    label_0000B555:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->esi)) goto label_0000B624;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000B587;
    *(uint8_t*)(cpu->edx + 0x30u) = 1u;
    *(uint8_t*)(cpu->esi + 0x30u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x30u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000B6D5;
    label_0000B587:
    if (cpu->eax != *(uint32_t*)(cpu->edx + 8u)) goto label_0000B5C6;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->esi + 0x31u) != (cpu->ebx & 0xFFu)) goto label_0000B5A0;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000B5A0:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000B5B3;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000B5C1;
    label_0000B5B3:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi)) goto label_0000B5BE;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_0000B5C1;
    label_0000B5BE:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    label_0000B5C1:
    *(uint32_t*)(cpu->edx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000B5C6:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x30u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x30u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->edi + 0x31u) != (cpu->ebx & 0xFFu)) goto label_0000B5EE;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000B5EE:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000B607;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B6D2;
    label_0000B607:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 8u)) goto label_0000B61A;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B6D2;
    label_0000B61A:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B6D2;
    label_0000B624:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->esi + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000B647;
    *(uint8_t*)(cpu->edx + 0x30u) = 1u;
    *(uint8_t*)(cpu->esi + 0x30u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x30u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    goto label_0000B6D5;
    label_0000B647:
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_0000B687;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->esi + 0x31u) != (cpu->ebx & 0xFFu)) goto label_0000B65F;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_0000B65F:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0000B672;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    goto label_0000B681;
    label_0000B672:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 8u)) goto label_0000B67F;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    goto label_0000B681;
    label_0000B67F:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000B681:
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0000B687:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint8_t*)(cpu->edx + 0x30u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint8_t*)(cpu->edx + 0x30u) = cpu->ebx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->edi + 0x31u) != (cpu->ebx & 0xFFu)) goto label_0000B6AF;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    label_0000B6AF:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi + 4u)) goto label_0000B6C2;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    goto label_0000B6D0;
    label_0000B6C2:
    cpu->edi = *(uint32_t*)(cpu->edx + 4u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000B6CD;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    goto label_0000B6D0;
    label_0000B6CD:
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    label_0000B6D0:
    *(uint32_t*)(cpu->esi) = cpu->edx;
    label_0000B6D2:
    *(uint32_t*)(cpu->edx + 4u) = cpu->esi;
    label_0000B6D5:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->edx + 0x30u) == (cpu->ebx & 0xFFu)) goto label_0000B555;
    cpu->edi = lift_pop32(cpu);
    label_0000B6E2:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0x30u) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == cpu->esi) goto label_0000B752;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000B712:
    if (cpu->edx == cpu->ebx) goto label_0000B71D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    ++cpu->edx;
    if (cpu->eax != cpu->esi) goto label_0000B712;
    label_0000B71D:
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax == cpu->esi) goto label_0000B752;
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_0000B73D;
    if (*(uint32_t*)(cpu->ecx + 0x1Cu) != cpu->eax) goto label_0000B73D;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edx;
    if (cpu->edx != cpu->esi) goto label_0000B73D;
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_0000B73D:
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ecx + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B74Bu)); sfera_sub_0040A680(cpu, LIFT_CODE_TOKEN_VA(0x40B74Bu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000B752:
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=*(uint8_t*)(cpu->ebx + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = cpu->ebx + 0x10u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000B790;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x20u);
    { uint64_t l=cpu->esi, r=*(uint32_t*)(cpu->ebx + 0x10u), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = (int32_t)(cpu->esi) >> 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B781u)); sfera_sub_0040A6F0(cpu, LIFT_CODE_TOKEN_VA(0x40B781u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->ecx + (cpu->esi * 8u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000B790:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B796u)); sfera_sub_0040A6F0(cpu, LIFT_CODE_TOKEN_VA(0x40B796u));
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B7A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x10u;
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B7B6u)); sfera_sub_004097F0(cpu, LIFT_CODE_TOKEN_VA(0x40B7B6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->eax + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B7E8u)); sfera_sub_0040A270(cpu, LIFT_CODE_TOKEN_VA(0x40B7E8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edx + 0xFFFFFFE4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B7FCu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x40B7FCu));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B82Cu)); sfera_sub_00403620(cpu, LIFT_CODE_TOKEN_VA(0x40B82Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B842u)); sfera_sub_00409F90(cpu, LIFT_CODE_TOKEN_VA(0x40B842u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B850(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x24u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    if (*(uint8_t*)(cpu->eax + 0x19u) != (cpu->ebx & 0xFFu)) goto label_0000B8A3;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    label_0000B890:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->edx) goto label_0000B89A;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_0000B89E;
    label_0000B89A:
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000B89E:
    if (*(uint8_t*)(cpu->eax + 0x19u) == (cpu->ebx & 0xFFu)) goto label_0000B890;
    label_0000B8A3:
    if (cpu->edi == *(uint32_t*)(cpu->esi + 4u)) goto label_0000B8AF;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->edi + 0xCu)) goto label_0000B928;
    label_0000B8AF:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x30u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B8DAu)); sfera_sub_00406610(cpu, LIFT_CODE_TOKEN_VA(0x40B8DAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B8E8u)); sfera_sub_0040A310(cpu, LIFT_CODE_TOKEN_VA(0x40B8E8u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->ebx & 0xFFu;
    if (cpu->edi == cpu->ebx) goto label_0000B910;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B907u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40B907u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B90Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B90Du));
    cpu->esp += 4u;
    label_0000B910:
    cpu->eax = cpu->esi + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000B928:
    cpu->eax = cpu->edi + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B940(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000B98F;
    label_0000B953:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B95Eu)); sfera_sub_0040B940(cpu, LIFT_CODE_TOKEN_VA(0x40B95Eu));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000B972;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B96Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B96Fu));
    cpu->esp += 4u;
    label_0000B972:
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B985u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B985u));
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x2Du) == (cpu->ebx & 0xFFu)) goto label_0000B953;
    label_0000B98F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040B9A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_0000B9EF;
    label_0000B9B3:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B9BEu)); sfera_sub_0040B9A0(cpu, LIFT_CODE_TOKEN_VA(0x40B9BEu));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x24u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000B9D2;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B9CFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B9CFu));
    cpu->esp += 4u;
    label_0000B9D2:
    *(uint32_t*)(cpu->esi + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40B9E5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40B9E5u));
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x2Du) == (cpu->ebx & 0xFFu)) goto label_0000B9B3;
    label_0000B9EF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BA00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->edi = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x45u) != (cpu->ebx & 0xFFu)) goto label_0000BA76;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ebx + 0xFu;
    label_0000BA20:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BA2Du)); sfera_sub_0040BA00(cpu, LIFT_CODE_TOKEN_VA(0x40BA2Du));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x3Cu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BA41;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BA3Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BA3Eu));
    cpu->esp += 4u;
    label_0000BA41:
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x28u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_0000BA5C;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BA59u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BA59u));
    cpu->esp += 4u;
    label_0000BA5C:
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BA6Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BA6Bu));
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x45u) == (cpu->ebx & 0xFFu)) goto label_0000BA20;
    cpu->ebp = lift_pop32(cpu);
    label_0000BA76:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BA80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebx = 0u;
    cpu->edi = cpu->ebp;
    if (*(uint8_t*)(cpu->ebp + 0x31u) != (cpu->ebx & 0xFFu)) goto label_0000BB25;
    label_0000BAB6:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BAC3u)); sfera_sub_0040BA80(cpu, LIFT_CODE_TOKEN_VA(0x40BAC3u));
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->esi = cpu->ebp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esi + 0x20u) == cpu->ebx) goto label_0000BAF0;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BAE4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40BAE4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BAEDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BAEDu));
    cpu->esp += 4u;
    label_0000BAF0:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BB09;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BB06u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BB06u));
    cpu->esp += 4u;
    label_0000BB09:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->ebp);
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BB1Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BB1Bu));
    cpu->esp += 4u;
    cpu->ebp = cpu->edi;
    if (*(uint8_t*)(cpu->edi + 0x31u) == (cpu->ebx & 0xFFu)) goto label_0000BAB6;
    label_0000BB25:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BB40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000BB91;
    lift_push32(cpu, cpu->ebp);
    label_0000BB60:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BB74;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BB71u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BB71u));
    cpu->esp += 4u;
    label_0000BB74:
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BB87u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BB87u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_0000BB60;
    cpu->ebp = lift_pop32(cpu);
    label_0000BB91:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BBA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000BC10;
    lift_push32(cpu, cpu->ebp);
    label_0000BBC0:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x38u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BBD4;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BBD1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BBD1u));
    cpu->esp += 4u;
    label_0000BBD4:
    *(uint32_t*)(cpu->esi + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x24u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000BBF3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BBF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BBF0u));
    cpu->esp += 4u;
    label_0000BBF3:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BC06u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BC06u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_0000BBC0;
    cpu->ebp = lift_pop32(cpu);
    label_0000BC10:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BC20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = 0u;
    if (cpu->edi == *(uint32_t*)(cpu->ebx)) goto label_0000BCC8;
    label_0000BC5D:
    cpu->ebp = *(uint32_t*)(cpu->edi);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000BC8F;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BC83u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40BC83u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BC8Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BC8Cu));
    cpu->esp += 4u;
    label_0000BC8F:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BCA8;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BCA5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BCA5u));
    cpu->esp += 4u;
    label_0000BCA8:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BCBFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BCBFu));
    cpu->esp += 4u;
    cpu->edi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->ebx)) goto label_0000BC5D;
    label_0000BCC8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BCE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000BCFD;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40BCE0u), "std::out_of_range");
    label_0000BCFD:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BD0Bu)); sfera_sub_004022D0(cpu, LIFT_CODE_TOKEN_VA(0x40BD0Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    if (*(uint8_t*)(cpu->ecx + 0x2Du) == 0u) goto label_0000BD19;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    goto label_0000BD31;
    label_0000BD19:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0000BD26;
    cpu->edi = cpu->ecx;
    goto label_0000BD31;
    label_0000BD26:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebp) goto label_0000BD94;
    label_0000BD31:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000BD3D;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_0000BD3D:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebp) goto label_0000BD4A;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_0000BD55;
    label_0000BD4A:
    if (*(uint32_t*)(cpu->esi) != cpu->ebp) goto label_0000BD52;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_0000BD55;
    label_0000BD52:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_0000BD55:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ebx) != cpu->ebp) goto label_0000BD6F;
    if (*(uint8_t*)(cpu->edi + 0x2Du) == 0u) goto label_0000BD66;
    cpu->eax = cpu->esi;
    goto label_0000BD6D;
    label_0000BD66:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBD6Du)); sfera_sub_00402290(cpu, LIFT_CODE_TOKEN_RVA(0xBD6Du));
    label_0000BD6D:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_0000BD6F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->ebp) goto label_0000BDEC;
    if (*(uint8_t*)(cpu->edi + 0x2Du) == 0u) goto label_0000BD88;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000BDEC;
    label_0000BD88:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BD8Fu)); sfera_sub_00402270(cpu, LIFT_CODE_TOKEN_VA(0x40BD8Fu));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000BDEC;
    label_0000BD94:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebp + 8u)) goto label_0000BDA5;
    cpu->esi = cpu->eax;
    goto label_0000BDBF;
    label_0000BDA5:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000BDB1;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_0000BDB1:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_0000BDBF:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebp) goto label_0000BDCC;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000BDDA;
    label_0000BDCC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebp) goto label_0000BDD7;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_0000BDDA;
    label_0000BDD7:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000BDDA:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x2Cu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x2Cu));
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0x2Cu) = cpu->ecx & 0xFFu;
    label_0000BDEC:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->ebp + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000BEF6;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->eax + 4u)) goto label_0000BEF3;
    label_0000BE07:
    if (*(uint8_t*)(cpu->edi + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000BEF3;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_0000BE7D;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x2Cu) != 0u) goto label_0000BE33;
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BE2Cu)); sfera_sub_00402EC0(cpu, LIFT_CODE_TOKEN_VA(0x40BE2Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000BE33:
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000BEAF;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000BE48;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) == (cpu->ebx & 0xFFu)) goto label_0000BEAB;
    label_0000BE48:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000BE66;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BE5Fu)); sfera_sub_00402E60(cpu, LIFT_CODE_TOKEN_VA(0x40BE5Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000BE66:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x2Cu));
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BE7Bu)); sfera_sub_00402EC0(cpu, LIFT_CODE_TOKEN_VA(0x40BE7Bu));
    goto label_0000BEF3;
    label_0000BE7D:
    if (*(uint8_t*)(cpu->eax + 0x2Cu) != 0u) goto label_0000BE96;
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BE90u)); sfera_sub_00402E60(cpu, LIFT_CODE_TOKEN_VA(0x40BE90u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000BE96:
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000BEAF;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000BEC2;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000BEC2;
    label_0000BEAB:
    *(uint8_t*)(cpu->eax + 0x2Cu) = 0u;
    label_0000BEAF:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax + 4u)) goto label_0000BE07;
    goto label_0000BEF3;
    label_0000BEC2:
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000BEDF;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BED9u)); sfera_sub_00402EC0(cpu, LIFT_CODE_TOKEN_VA(0x40BED9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000BEDF:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x2Cu));
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBEF3u)); sfera_sub_00402E60(cpu, LIFT_CODE_TOKEN_RVA(0xBEF3u));
    label_0000BEF3:
    *(uint8_t*)(cpu->edi + 0x2Cu) = cpu->ebx & 0xFFu;
    label_0000BEF6:
    if (*(uint32_t*)(cpu->ebp + 0x20u) < 0x10u) goto label_0000BF08;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BF05u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BF05u));
    cpu->esp += 4u;
    label_0000BF08:
    *(uint32_t*)(cpu->ebp + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = 0u;
    lift_push32(cpu, cpu->ebp);
    *(uint8_t*)(cpu->ebp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BF20u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40BF20u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_0000BF35;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000BF35:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BF50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000BF6D;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40BF50u), "std::out_of_range");
    label_0000BF6D:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BF7Bu)); sfera_sub_004022D0(cpu, LIFT_CODE_TOKEN_VA(0x40BF7Bu));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    if (*(uint8_t*)(cpu->ecx + 0x2Du) == 0u) goto label_0000BF89;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    goto label_0000BFA1;
    label_0000BF89:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0000BF96;
    cpu->edi = cpu->ecx;
    goto label_0000BFA1;
    label_0000BF96:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebp) goto label_0000C004;
    label_0000BFA1:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000BFAD;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_0000BFAD:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebp) goto label_0000BFBA;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_0000BFC5;
    label_0000BFBA:
    if (*(uint32_t*)(cpu->esi) != cpu->ebp) goto label_0000BFC2;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_0000BFC5;
    label_0000BFC2:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_0000BFC5:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ebx) != cpu->ebp) goto label_0000BFDF;
    if (*(uint8_t*)(cpu->edi + 0x2Du) == 0u) goto label_0000BFD6;
    cpu->eax = cpu->esi;
    goto label_0000BFDD;
    label_0000BFD6:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBFDDu)); sfera_sub_00402290(cpu, LIFT_CODE_TOKEN_RVA(0xBFDDu));
    label_0000BFDD:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_0000BFDF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->ebp) goto label_0000C05C;
    if (*(uint8_t*)(cpu->edi + 0x2Du) == 0u) goto label_0000BFF8;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000C05C;
    label_0000BFF8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40BFFFu)); sfera_sub_00402270(cpu, LIFT_CODE_TOKEN_VA(0x40BFFFu));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000C05C;
    label_0000C004:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebp + 8u)) goto label_0000C015;
    cpu->esi = cpu->eax;
    goto label_0000C02F;
    label_0000C015:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C021;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_0000C021:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_0000C02F:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebp) goto label_0000C03C;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000C04A;
    label_0000C03C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebp) goto label_0000C047;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_0000C04A;
    label_0000C047:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000C04A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x2Cu));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x2Cu));
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0x2Cu) = cpu->ecx & 0xFFu;
    label_0000C05C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->ebp + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000C166;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->eax + 4u)) goto label_0000C163;
    label_0000C077:
    if (*(uint8_t*)(cpu->edi + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000C163;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_0000C0ED;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x2Cu) != 0u) goto label_0000C0A3;
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C09Cu)); sfera_sub_00402EC0(cpu, LIFT_CODE_TOKEN_VA(0x40C09Cu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C0A3:
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000C11F;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000C0B8;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) == (cpu->ebx & 0xFFu)) goto label_0000C11B;
    label_0000C0B8:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000C0D6;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C0CFu)); sfera_sub_00402E60(cpu, LIFT_CODE_TOKEN_VA(0x40C0CFu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C0D6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x2Cu));
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C0EBu)); sfera_sub_00402EC0(cpu, LIFT_CODE_TOKEN_VA(0x40C0EBu));
    goto label_0000C163;
    label_0000C0ED:
    if (*(uint8_t*)(cpu->eax + 0x2Cu) != 0u) goto label_0000C106;
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C100u)); sfera_sub_00402E60(cpu, LIFT_CODE_TOKEN_VA(0x40C100u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C106:
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000C11F;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000C132;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000C132;
    label_0000C11B:
    *(uint8_t*)(cpu->eax + 0x2Cu) = 0u;
    label_0000C11F:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax + 4u)) goto label_0000C077;
    goto label_0000C163;
    label_0000C132:
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x2Cu) != (cpu->ebx & 0xFFu)) goto label_0000C14F;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint8_t*)(cpu->edx + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C149u)); sfera_sub_00402EC0(cpu, LIFT_CODE_TOKEN_VA(0x40C149u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C14F:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x2Cu));
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x2Cu) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x2Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC163u)); sfera_sub_00402E60(cpu, LIFT_CODE_TOKEN_RVA(0xC163u));
    label_0000C163:
    *(uint8_t*)(cpu->edi + 0x2Cu) = cpu->ebx & 0xFFu;
    label_0000C166:
    if (*(uint32_t*)(cpu->ebp + 0x24u) < 0x10u) goto label_0000C178;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C175u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C175u));
    cpu->esp += 4u;
    label_0000C178:
    *(uint32_t*)(cpu->ebp + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->ebp + 0x20u) = 0u;
    lift_push32(cpu, cpu->ebp);
    *(uint8_t*)(cpu->ebp + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C190u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C190u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_0000C1A5;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000C1A5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C1C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x45u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000C1DE;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40C1C0u), "std::out_of_range");
    label_0000C1DE:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C1E9u)); sfera_sub_00402360(cpu, LIFT_CODE_TOKEN_VA(0x40C1E9u));
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if (*(uint8_t*)(cpu->ecx + 0x45u) == 0u) goto label_0000C1F6;
    cpu->ebp = *(uint32_t*)(cpu->edi + 8u);
    goto label_0000C20E;
    label_0000C1F6:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x45u) == 0u) goto label_0000C203;
    cpu->ebp = cpu->ecx;
    goto label_0000C20E;
    label_0000C203:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->edi) goto label_0000C271;
    label_0000C20E:
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0x45u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C21A;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->esi;
    label_0000C21A:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->edi) goto label_0000C227;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebp;
    goto label_0000C232;
    label_0000C227:
    if (*(uint32_t*)(cpu->esi) != cpu->edi) goto label_0000C22F;
    *(uint32_t*)(cpu->esi) = cpu->ebp;
    goto label_0000C232;
    label_0000C22F:
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebp;
    label_0000C232:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ebx) != cpu->edi) goto label_0000C24C;
    if (*(uint8_t*)(cpu->ebp + 0x45u) == 0u) goto label_0000C243;
    cpu->eax = cpu->esi;
    goto label_0000C24A;
    label_0000C243:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC24Au)); sfera_sub_00402340(cpu, LIFT_CODE_TOKEN_RVA(0xC24Au));
    label_0000C24A:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_0000C24C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->edi) goto label_0000C2C8;
    if (*(uint8_t*)(cpu->ebp + 0x45u) == 0u) goto label_0000C265;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000C2C8;
    label_0000C265:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C26Cu)); sfera_sub_00402320(cpu, LIFT_CODE_TOKEN_VA(0x40C26Cu));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000C2C8;
    label_0000C271:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->edi + 8u)) goto label_0000C281;
    cpu->esi = cpu->eax;
    goto label_0000C29B;
    label_0000C281:
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0x45u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C28D;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->esi;
    label_0000C28D:
    *(uint32_t*)(cpu->esi) = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_0000C29B:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->edi) goto label_0000C2A8;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000C2B6;
    label_0000C2A8:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000C2B3;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_0000C2B6;
    label_0000C2B3:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000C2B6:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x44u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x44u));
    *(uint8_t*)(cpu->eax + 0x44u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->edi + 0x44u) = cpu->ecx & 0xFFu;
    label_0000C2C8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->edi + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000C3D2;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->ebp == *(uint32_t*)(cpu->eax + 4u)) goto label_0000C3CF;
    label_0000C2E3:
    if (*(uint8_t*)(cpu->ebp + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000C3CF;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->ebp != cpu->eax) goto label_0000C359;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x44u) != 0u) goto label_0000C30F;
    *(uint8_t*)(cpu->eax + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x44u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C308u)); sfera_sub_00402F10(cpu, LIFT_CODE_TOKEN_VA(0x40C308u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C30F:
    if (*(uint8_t*)(cpu->eax + 0x45u) != 0u) goto label_0000C38B;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000C324;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x44u) == (cpu->ebx & 0xFFu)) goto label_0000C387;
    label_0000C324:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000C342;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->edx + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x44u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C33Bu)); sfera_sub_00402F60(cpu, LIFT_CODE_TOKEN_VA(0x40C33Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C342:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x44u));
    *(uint8_t*)(cpu->eax + 0x44u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x44u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C357u)); sfera_sub_00402F10(cpu, LIFT_CODE_TOKEN_VA(0x40C357u));
    goto label_0000C3CF;
    label_0000C359:
    if (*(uint8_t*)(cpu->eax + 0x44u) != 0u) goto label_0000C372;
    *(uint8_t*)(cpu->eax + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x44u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C36Cu)); sfera_sub_00402F60(cpu, LIFT_CODE_TOKEN_VA(0x40C36Cu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C372:
    if (*(uint8_t*)(cpu->eax + 0x45u) != 0u) goto label_0000C38B;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000C39E;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000C39E;
    label_0000C387:
    *(uint8_t*)(cpu->eax + 0x44u) = 0u;
    label_0000C38B:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebp = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ebp != *(uint32_t*)(cpu->eax + 4u)) goto label_0000C2E3;
    goto label_0000C3CF;
    label_0000C39E:
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x44u) != (cpu->ebx & 0xFFu)) goto label_0000C3BB;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint8_t*)(cpu->edx + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x44u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C3B5u)); sfera_sub_00402F10(cpu, LIFT_CODE_TOKEN_VA(0x40C3B5u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000C3BB:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x44u));
    *(uint8_t*)(cpu->eax + 0x44u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x44u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC3CFu)); sfera_sub_00402F60(cpu, LIFT_CODE_TOKEN_RVA(0xC3CFu));
    label_0000C3CF:
    *(uint8_t*)(cpu->ebp + 0x44u) = cpu->ebx & 0xFFu;
    label_0000C3D2:
    cpu->ebp = 0x10u;
    if (*(uint32_t*)(cpu->edi + 0x3Cu) < cpu->ebp) goto label_0000C3E8;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C3E5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C3E5u));
    cpu->esp += 4u;
    label_0000C3E8:
    cpu->esi = 0u;
    cpu->ebx = 0xFu;
    *(uint32_t*)(cpu->edi + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x38u) = cpu->esi;
    *(uint8_t*)(cpu->edi + 0x28u) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x20u) < cpu->ebp) goto label_0000C40A;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C407u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C407u));
    cpu->esp += 4u;
    label_0000C40A:
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->esi;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->edi + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C41Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C41Au));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esp += 4u;
    { uint64_t l=cpu->eax, r=cpu->esi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0000C42E;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000C42E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C440(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    if (*(uint8_t*)(cpu->eax + 0x31u) == 0u) goto label_0000C482;
    lift_push32(cpu, (uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x40C440u), "std::out_of_range");
    label_0000C482:
    cpu->ecx = cpu->esp + 0x30u;
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C48Du)); sfera_sub_00402480(cpu, LIFT_CODE_TOKEN_VA(0x40C48Du));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    if (*(uint8_t*)(cpu->ecx + 0x31u) == 0u) goto label_0000C49B;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    goto label_0000C4B3;
    label_0000C49B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (*(uint8_t*)(cpu->eax + 0x31u) == 0u) goto label_0000C4A8;
    cpu->edi = cpu->ecx;
    goto label_0000C4B3;
    label_0000C4A8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->eax != cpu->ebp) goto label_0000C516;
    label_0000C4B3:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x31u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C4BF;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_0000C4BF:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->eax + 4u) != cpu->ebp) goto label_0000C4CC;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    goto label_0000C4D7;
    label_0000C4CC:
    if (*(uint32_t*)(cpu->esi) != cpu->ebp) goto label_0000C4D4;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_0000C4D7;
    label_0000C4D4:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    label_0000C4D7:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ebx) != cpu->ebp) goto label_0000C4F1;
    if (*(uint8_t*)(cpu->edi + 0x31u) == 0u) goto label_0000C4E8;
    cpu->eax = cpu->esi;
    goto label_0000C4EF;
    label_0000C4E8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC4EFu)); sfera_sub_00402460(cpu, LIFT_CODE_TOKEN_RVA(0xC4EFu));
    label_0000C4EF:
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_0000C4F1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->ebx + 8u) != cpu->ebp) goto label_0000C56E;
    if (*(uint8_t*)(cpu->edi + 0x31u) == 0u) goto label_0000C50A;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000C56E;
    label_0000C50A:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C511u)); sfera_sub_00402440(cpu, LIFT_CODE_TOKEN_VA(0x40C511u));
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    goto label_0000C56E;
    label_0000C516:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->eax != *(uint32_t*)(cpu->ebp + 8u)) goto label_0000C527;
    cpu->esi = cpu->eax;
    goto label_0000C541;
    label_0000C527:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0x31u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C533;
    *(uint32_t*)(cpu->edi + 4u) = cpu->esi;
    label_0000C533:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_0000C541:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->ebp) goto label_0000C54E;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000C55C;
    label_0000C54E:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    if (*(uint32_t*)(cpu->ecx) != cpu->ebp) goto label_0000C559;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    goto label_0000C55C;
    label_0000C559:
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000C55C:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x30u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x30u));
    *(uint8_t*)(cpu->eax + 0x30u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0x30u) = cpu->ecx & 0xFFu;
    label_0000C56E:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->ebp + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000C67F;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == *(uint32_t*)(cpu->eax + 4u)) goto label_0000C67C;
    label_0000C590:
    if (*(uint8_t*)(cpu->edi + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000C67C;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->edi != cpu->eax) goto label_0000C606;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x30u) != 0u) goto label_0000C5BC;
    *(uint8_t*)(cpu->eax + 0x30u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C5B5u)); sfera_sub_00403070(cpu, LIFT_CODE_TOKEN_VA(0x40C5B5u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000C5BC:
    if (*(uint8_t*)(cpu->eax + 0x31u) != 0u) goto label_0000C638;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000C5D1;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x30u) == (cpu->ebx & 0xFFu)) goto label_0000C634;
    label_0000C5D1:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000C5EF;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->edx + 0x30u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C5E8u)); sfera_sub_004030C0(cpu, LIFT_CODE_TOKEN_VA(0x40C5E8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000C5EF:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x30u));
    *(uint8_t*)(cpu->eax + 0x30u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x30u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x30u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C604u)); sfera_sub_00403070(cpu, LIFT_CODE_TOKEN_VA(0x40C604u));
    goto label_0000C67C;
    label_0000C606:
    if (*(uint8_t*)(cpu->eax + 0x30u) != 0u) goto label_0000C61F;
    *(uint8_t*)(cpu->eax + 0x30u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C619u)); sfera_sub_004030C0(cpu, LIFT_CODE_TOKEN_VA(0x40C619u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000C61F:
    if (*(uint8_t*)(cpu->eax + 0x31u) != 0u) goto label_0000C638;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->edx + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000C64B;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000C64B;
    label_0000C634:
    *(uint8_t*)(cpu->eax + 0x30u) = 0u;
    label_0000C638:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax + 4u)) goto label_0000C590;
    goto label_0000C67C;
    label_0000C64B:
    cpu->edx = *(uint32_t*)(cpu->eax);
    if (*(uint8_t*)(cpu->edx + 0x30u) != (cpu->ebx & 0xFFu)) goto label_0000C668;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint8_t*)(cpu->edx + 0x30u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C662u)); sfera_sub_00403070(cpu, LIFT_CODE_TOKEN_VA(0x40C662u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000C668:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0x30u));
    *(uint8_t*)(cpu->eax + 0x30u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0x30u) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->eax + 0x30u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC67Cu)); sfera_sub_004030C0(cpu, LIFT_CODE_TOKEN_RVA(0xC67Cu));
    label_0000C67C:
    *(uint8_t*)(cpu->edi + 0x30u) = cpu->ebx & 0xFFu;
    label_0000C67F:
    cpu->esi = cpu->ebp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x20u) == cpu->edi) goto label_0000C6AA;
    cpu->edx = cpu->edi + 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C69Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40C69Eu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C6A7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C6A7u));
    cpu->esp += 4u;
    label_0000C6AA:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000C6BB;
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C6B8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C6B8u));
    cpu->esp += 4u;
    label_0000C6BB:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    lift_push32(cpu, cpu->ebp);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C6CEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C6CEu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esp += 4u;
    if (cpu->eax <= cpu->edi) goto label_0000C6E0;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    label_0000C6E0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000C75D;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_0000C733;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C730u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C730u));
    cpu->esp += 4u;
    label_0000C733:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C748u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C748u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000C75D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000C7E3;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x38u) < 0x10u) goto label_0000C7A3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C7A0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C7A0u));
    cpu->esp += 4u;
    label_0000C7A3:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x24u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000C7C5;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C7C2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C7C2u));
    cpu->esp += 4u;
    label_0000C7C5:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C7D8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C7D8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = lift_pop32(cpu);
    label_0000C7E3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C7F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000C82A;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi + 8u;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C81Au)); sfera_sub_0040A470(cpu, LIFT_CODE_TOKEN_VA(0x40C81Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C820u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C820u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000C82A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C840(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C874u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40C874u));
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if (cpu->esi == cpu->eax) goto label_0000C8EB;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi + 0xCu;
    *(uint16_t*)(cpu->esi + 0x28u) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->ecx == cpu->eax) goto label_0000C8C0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC8C0u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0xC8C0u));
    label_0000C8C0:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000C8EB:
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C910u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40C910u));
    lift_trap(cpu, 0x40C910u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040C8D6(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C8DFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C8DFu));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C8EBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40C8EBu));
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C910u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40C910u));
    lift_trap(cpu, 0x40C910u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040C920(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C952u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40C952u));
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if (cpu->esi == cpu->eax) goto label_0000C9BF;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->ecx = cpu->esi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->ecx;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->ecx == cpu->eax) goto label_0000C994;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xC994u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0xC994u));
    label_0000C994:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000C9BF:
    cpu->edx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C9E4u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40C9E4u));
    lift_trap(cpu, 0x40C9E4u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040C9AA(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C9B3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40C9B3u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C9BFu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40C9BFu));
    cpu->edx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C9E4u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40C9E4u));
    lift_trap(cpu, 0x40C9E4u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040C9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebp += 0xCu;
    { uint64_t l=*(uint8_t*)(cpu->ebx + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CAEC;
    label_0000CA20:
    { uint64_t l=*(uint8_t*)(cpu->esp + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->eax = cpu->ebx + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000CA82;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_0000CA39;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_0000CA3B;
    label_0000CA39:
    cpu->edx = cpu->ebp;
    label_0000CA3B:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_0000CA44;
    label_0000CA44:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_0000CA4F;
    cpu->ecx = cpu->edi;
    label_0000CA4F:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0000CA57;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000CA57:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CA5Fu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40CA5Fu));
    cpu->esp += 0xCu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CA7D;
    if (cpu->esi >= cpu->edi) goto label_0000CA74;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CACB;
    label_0000CA74:
    cpu->eax = 0u;
    { uint64_t l=cpu->esi, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    label_0000CA7D:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CACB;
    label_0000CA82:
    { uint64_t l=*(uint32_t*)(cpu->eax + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CA8D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000CA8D:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_0000CA9A;
    cpu->edx = cpu->edi;
    label_0000CA9A:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_0000CAA5;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_0000CAA7;
    label_0000CAA5:
    cpu->ecx = cpu->ebp;
    label_0000CAA7:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CAAFu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40CAAFu));
    cpu->esp += 0xCu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CAC8;
    if (cpu->esi >= cpu->edi) goto label_0000CABF;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0000CAC6;
    label_0000CABF:
    cpu->eax = 0u;
    { uint64_t l=cpu->esi, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CAC6:
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    label_0000CAC8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CACB:
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000CAD7;
    cpu->ebx = *(uint32_t*)(cpu->ebx);
    goto label_0000CADA;
    label_0000CAD7:
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    label_0000CADA:
    if (*(uint8_t*)(cpu->ebx + 0x2Du) == 0u) goto label_0000CA20;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000CAEC:
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000CB32;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_0000CB25;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    label_0000CB0A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CB0Fu)); sfera_sub_0040ADC0(cpu, LIFT_CODE_TOKEN_VA(0x40CB0Fu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000CB25:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CB2Eu)); sfera_sub_00402540(cpu, LIFT_CODE_TOKEN_VA(0x40CB2Eu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000CB32:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ebx = 0x10u;
    cpu->ecx = cpu->esi + 0xCu;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->ebx) goto label_0000CB47;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    goto label_0000CB49;
    label_0000CB47:
    cpu->eax = cpu->ebp;
    label_0000CB49:
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CB56u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40CB56u));
    if ((int32_t)cpu->eax >= 0) goto label_0000CB70;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    goto label_0000CB0A;
    label_0000CB70:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->ebx) goto label_0000CB81;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CB7Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40CB7Eu));
    cpu->esp += 4u;
    label_0000CB81:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->ebp + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ebp + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CB9Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40CB9Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040CBC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CC0E;
    cpu->ebp = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Cu));
    label_0000CBE5:
    cpu->esi = cpu->eax;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0000CBF3;
    { uint64_t l=*(uint32_t*)(cpu->eax + 0xCu), r=cpu->ebp, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CBF9;
    label_0000CBF3:
    { uint64_t l=cpu->ebp, r=*(uint32_t*)(cpu->eax + 0xCu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    label_0000CBF9:
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0000CC05;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_0000CC08;
    label_0000CC05:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_0000CC08:
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0000CBE5;
    label_0000CC0E:
    cpu->ebp = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0000CC4B;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->esp + 0x1Cu;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_0000CC42;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CC2Fu)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40CC2Fu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000CC42:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CC47u)); sfera_sub_00402540(cpu, LIFT_CODE_TOKEN_VA(0x40CC47u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000CC4B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->edi + 0xCu)) goto label_0000CC79;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CC66u)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40CC66u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000CC79:
    if (*(uint32_t*)(cpu->edi + 0x24u) < 0x10u) goto label_0000CC8B;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CC88u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40CC88u));
    cpu->esp += 4u;
    label_0000CC8B:
    *(uint32_t*)(cpu->edi + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x20u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->edi + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CCA3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40CCA3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040CCC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebx += 0xCu;
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0x45u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CDBB;
    label_0000CCF0:
    { uint64_t l=*(uint8_t*)(cpu->esp + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    cpu->eax = cpu->ebp + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000CD51;
    if (*(uint32_t*)(cpu->ebx + 0x14u) < 0x10u) goto label_0000CD08;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    goto label_0000CD0A;
    label_0000CD08:
    cpu->edx = cpu->ebx;
    label_0000CD0A:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_0000CD13;
    label_0000CD13:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_0000CD1E;
    cpu->ecx = cpu->edi;
    label_0000CD1E:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0000CD26;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000CD26:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CD2Eu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40CD2Eu));
    cpu->esp += 0xCu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CD4C;
    if (cpu->esi >= cpu->edi) goto label_0000CD43;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CD99;
    label_0000CD43:
    cpu->eax = 0u;
    { uint64_t l=cpu->esi, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    label_0000CD4C:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CD99;
    label_0000CD51:
    { uint64_t l=*(uint32_t*)(cpu->eax + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CD5C;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000CD5C:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_0000CD69;
    cpu->edx = cpu->edi;
    label_0000CD69:
    if (*(uint32_t*)(cpu->ebx + 0x14u) < 0x10u) goto label_0000CD73;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    goto label_0000CD75;
    label_0000CD73:
    cpu->ecx = cpu->ebx;
    label_0000CD75:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CD7Du)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40CD7Du));
    cpu->esp += 0xCu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CD96;
    if (cpu->esi >= cpu->edi) goto label_0000CD8D;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0000CD94;
    label_0000CD8D:
    cpu->eax = 0u;
    { uint64_t l=cpu->esi, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CD94:
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    label_0000CD96:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CD99:
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000CDA6;
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    goto label_0000CDA9;
    label_0000CDA6:
    cpu->ebp = *(uint32_t*)(cpu->ebp + 8u);
    label_0000CDA9:
    if (*(uint8_t*)(cpu->ebp + 0x45u) == 0u) goto label_0000CCF0;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000CDBB:
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000CE01;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_0000CDF4;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    label_0000CDD9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CDDEu)); sfera_sub_0040B260(cpu, LIFT_CODE_TOKEN_VA(0x40CDDEu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000CDF4:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CDFDu)); sfera_sub_00402600(cpu, LIFT_CODE_TOKEN_VA(0x40CDFDu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000CE01:
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CE11;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    goto label_0000CE13;
    label_0000CE11:
    cpu->eax = cpu->ebx;
    label_0000CE13:
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CE20u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40CE20u));
    if ((int32_t)cpu->eax >= 0) goto label_0000CE3A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    goto label_0000CDD9;
    label_0000CE3A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += 0xDu;
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CE48u)); sfera_sub_0040ACE0(cpu, LIFT_CODE_TOKEN_VA(0x40CE48u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CE52u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40CE52u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040CE70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebx += 0xCu;
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0x31u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CF6B;
    label_0000CEA0:
    { uint64_t l=*(uint8_t*)(cpu->esp + 0x28u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    cpu->eax = cpu->ebp + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000CF01;
    if (*(uint32_t*)(cpu->ebx + 0x14u) < 0x10u) goto label_0000CEB8;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    goto label_0000CEBA;
    label_0000CEB8:
    cpu->edx = cpu->ebx;
    label_0000CEBA:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_0000CEC3;
    label_0000CEC3:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_0000CECE;
    cpu->ecx = cpu->edi;
    label_0000CECE:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0000CED6;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000CED6:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CEDEu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40CEDEu));
    cpu->esp += 0xCu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CEFC;
    if (cpu->esi >= cpu->edi) goto label_0000CEF3;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CF49;
    label_0000CEF3:
    cpu->eax = 0u;
    { uint64_t l=cpu->esi, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    label_0000CEFC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CF49;
    label_0000CF01:
    { uint64_t l=*(uint32_t*)(cpu->eax + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CF0C;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000CF0C:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_0000CF19;
    cpu->edx = cpu->edi;
    label_0000CF19:
    if (*(uint32_t*)(cpu->ebx + 0x14u) < 0x10u) goto label_0000CF23;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    goto label_0000CF25;
    label_0000CF23:
    cpu->ecx = cpu->ebx;
    label_0000CF25:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CF2Du)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40CF2Du));
    cpu->esp += 0xCu;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CF46;
    if (cpu->esi >= cpu->edi) goto label_0000CF3D;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0000CF44;
    label_0000CF3D:
    cpu->eax = 0u;
    { uint64_t l=cpu->esi, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CF44:
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    label_0000CF46:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CF49:
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000CF56;
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    goto label_0000CF59;
    label_0000CF56:
    cpu->ebp = *(uint32_t*)(cpu->ebp + 8u);
    label_0000CF59:
    if (*(uint8_t*)(cpu->ebp + 0x31u) == 0u) goto label_0000CEA0;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000CF6B:
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000CFB1;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_0000CFA4;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    label_0000CF89:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CF8Eu)); sfera_sub_0040B4D0(cpu, LIFT_CODE_TOKEN_VA(0x40CF8Eu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000CFA4:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CFADu)); sfera_sub_004026C0(cpu, LIFT_CODE_TOKEN_VA(0x40CFADu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000CFB1:
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CFC1;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    goto label_0000CFC3;
    label_0000CFC1:
    cpu->eax = cpu->ebx;
    label_0000CFC3:
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CFD0u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40CFD0u));
    if ((int32_t)cpu->eax >= 0) goto label_0000CFEA;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    goto label_0000CF89;
    label_0000CFEA:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += 0xDu;
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40CFF8u)); sfera_sub_0040AD30(cpu, LIFT_CODE_TOKEN_VA(0x40CFF8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D002u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D002u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D020(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1Cu;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx + 0x14u;
    cpu->ebp = cpu->ebx + 0xFu;
    label_0000D057:
    cpu->eax = cpu->edi + 0xFFFFFFECu;
    if (cpu->eax == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000D0C3;
    if (cpu->esi == cpu->ebx) goto label_0000D0BB;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    if (cpu->esi == cpu->eax) goto label_0000D0BB;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000D081;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D07Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D07Eu));
    cpu->esp += 4u;
    label_0000D081:
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->edi) >= 0x10u) goto label_0000D0A3;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xFFFFFFFCu);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->edi + 0xFFFFFFECu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40D098u));
    cpu->esp += 0xCu;
    goto label_0000D0AB;
    label_0000D0A3:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xFFFFFFECu);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0xFFFFFFECu) = cpu->ebx;
    label_0000D0AB:
    cpu->edx = *(uint32_t*)(cpu->edi + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    label_0000D0BB:
    cpu->esi += 0x1Cu;
    cpu->edi += 0x1Cu;
    goto label_0000D057;
    label_0000D0C3:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D250(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ebx < 0) goto label_0000D328;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->ebx >= cpu->eax) goto label_0000D328;
    { uint64_t l=*(uint8_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000D2A3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    goto label_0000D2A7;
    label_0000D2A3:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000D2A7:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = cpu->ebx * 8u;
    cpu->ecx -= cpu->ebx;
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->eax + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D2C7u)); sfera_sub_0040A270(cpu, LIFT_CODE_TOKEN_VA(0x40D2C7u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx + 0xFFFFFFE4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D2DBu)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x40D2DBu));
    *(uint32_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x14u)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u);
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_0000D320;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_0000D31C;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = cpu->edi * 8u;
    cpu->ecx -= cpu->edi;
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000D31C:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_0000D320:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0000D328:
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_0000D37D;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    { uint64_t l=*(uint32_t*)(cpu->eax + 0x14u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000D353;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000D353:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D362u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40D362u));
    if (cpu->eax != 0u) goto label_0000D37C;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx = cpu->esi + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D372u)); sfera_sub_00402AF0(cpu, LIFT_CODE_TOKEN_VA(0x40D372u));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D37C;
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_0000D37C:
    cpu->edi = lift_pop32(cpu);
    label_0000D37D:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D38Bu)); sfera_sub_00403F00(cpu, LIFT_CODE_TOKEN_VA(0x40D38Bu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D3A2u)); sfera_sub_0040A7A0(cpu, LIFT_CODE_TOKEN_VA(0x40D3A2u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D3B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D3BFu)); sfera_sub_0040B850(cpu, LIFT_CODE_TOKEN_VA(0x40D3BFu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_0000D3FB;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D3D8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40D3D8u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D3E1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D3E1u));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_0000D3FB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000D44A;
    if (cpu->edx != cpu->eax) goto label_0000D44A;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D422u)); sfera_sub_0040B940(cpu, LIFT_CODE_TOKEN_VA(0x40D422u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000D44A:
    if (cpu->ecx == cpu->edx) goto label_0000D4BF;
    label_0000D450:
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D4A8;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000D480;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000D47A;
    label_0000D470:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0000D470;
    label_0000D47A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_0000D4A8;
    label_0000D480:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000D4A4;
    label_0000D490:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_0000D4A4;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0000D490;
    label_0000D4A4:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0000D4A8:
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D4B5u)); sfera_sub_0040BCE0(cpu, LIFT_CODE_TOKEN_VA(0x40D4B5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0000D450;
    label_0000D4BF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D4D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000D51A;
    if (cpu->edx != cpu->eax) goto label_0000D51A;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D4F2u)); sfera_sub_0040B9A0(cpu, LIFT_CODE_TOKEN_VA(0x40D4F2u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000D51A:
    if (cpu->ecx == cpu->edx) goto label_0000D58F;
    label_0000D520:
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D578;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000D550;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000D54A;
    label_0000D540:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0000D540;
    label_0000D54A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_0000D578;
    label_0000D550:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0000D574;
    label_0000D560:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_0000D574;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0000D560;
    label_0000D574:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0000D578:
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D585u)); sfera_sub_0040BF50(cpu, LIFT_CODE_TOKEN_VA(0x40D585u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0000D520;
    label_0000D58F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D5A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000D5EA;
    if (cpu->edx != cpu->eax) goto label_0000D5EA;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D5C2u)); sfera_sub_0040BA00(cpu, LIFT_CODE_TOKEN_VA(0x40D5C2u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000D5EA:
    if (cpu->ecx == cpu->edx) goto label_0000D65F;
    label_0000D5F0:
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x45u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D648;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x45u) != 0u) goto label_0000D620;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x45u) != 0u) goto label_0000D61A;
    label_0000D610:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x45u) == 0u) goto label_0000D610;
    label_0000D61A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_0000D648;
    label_0000D620:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x45u) != 0u) goto label_0000D644;
    label_0000D630:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_0000D644;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x45u) == 0u) goto label_0000D630;
    label_0000D644:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0000D648:
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D655u)); sfera_sub_0040C1C0(cpu, LIFT_CODE_TOKEN_VA(0x40D655u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0000D5F0;
    label_0000D65F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D670(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000D6BA;
    if (cpu->edx != cpu->eax) goto label_0000D6BA;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D692u)); sfera_sub_0040BA80(cpu, LIFT_CODE_TOKEN_VA(0x40D692u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000D6BA:
    if (cpu->ecx == cpu->edx) goto label_0000D72F;
    label_0000D6C0:
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x31u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D718;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x31u) != 0u) goto label_0000D6F0;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x31u) != 0u) goto label_0000D6EA;
    label_0000D6E0:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (*(uint8_t*)(cpu->eax + 0x31u) == 0u) goto label_0000D6E0;
    label_0000D6EA:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_0000D718;
    label_0000D6F0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x31u) != 0u) goto label_0000D714;
    label_0000D700:
    if (cpu->ecx != *(uint32_t*)(cpu->eax + 8u)) goto label_0000D714;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x31u) == 0u) goto label_0000D700;
    label_0000D714:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_0000D718:
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D725u)); sfera_sub_0040C440(cpu, LIFT_CODE_TOKEN_VA(0x40D725u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0000D6C0;
    label_0000D72F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000D7B1;
    lift_push32(cpu, cpu->ebp);
    label_0000D760:
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x24u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000D774;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D771u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D771u));
    cpu->esp += 4u;
    label_0000D774:
    *(uint32_t*)(cpu->esi + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xCu) == cpu->ebx) goto label_0000D7A1;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D795u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40D795u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D79Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D79Eu));
    cpu->esp += 4u;
    label_0000D7A1:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D7A7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D7A7u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_0000D760;
    cpu->ebp = lift_pop32(cpu);
    label_0000D7B1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D7C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = cpu->edi + 0x10u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->esi == cpu->edx) goto label_0000D7F2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000D7EF;
    lift_push32(cpu, cpu->ebx);
    label_0000D7E0:
    cpu->ebx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    cpu->eax += 4u;
    cpu->esi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000D7E0;
    cpu->ebx = lift_pop32(cpu);
    label_0000D7EF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    label_0000D7F2:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D807u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40D807u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->edi + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40D831u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000D850;
    cpu->edx += 0x7FFFFFFFu;
    label_0000D850:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x24u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000D865;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_0000D865:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    { uint64_t l=*(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u), r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D892;
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000D88A;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->edx;
    goto label_0000D89A;
    label_0000D88A:
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000D89A;
    label_0000D892:
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000D89E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0000D89A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000D89E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D8ACu)); sfera_sub_0040C700(cpu, LIFT_CODE_TOKEN_VA(0x40D8ACu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->edi + 8u;
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D8D5u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40D8D5u));
    cpu->eax &= cpu->ebx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x24u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000D8E5;
    cpu->ebx >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->ebx;
    cpu->eax += cpu->ecx;
    label_0000D8E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    { uint64_t l=*(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->edx + (cpu->eax * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D90E;
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000D906;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->edx;
    goto label_0000D916;
    label_0000D906:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000D916;
    label_0000D90E:
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000D91A;
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0000D916:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000D91A:
    cpu->ebx = *(uint32_t*)(cpu->edi);
    if (cpu->edi == *(uint32_t*)(cpu->esi + 4u)) goto label_0000D943;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0xCu;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D937u)); sfera_sub_0040A470(cpu, LIFT_CODE_TOKEN_VA(0x40D937u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D93Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D93Du));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 8u);
    label_0000D943:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D950(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000D9C0;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x24u) < 0x10u) goto label_0000D983;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D980u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D980u));
    cpu->esp += 4u;
    label_0000D983:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->eax & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xCu) == cpu->eax) goto label_0000D9B0;
    cpu->edx = cpu->eax + 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D9A4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x40D9A4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D9ADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D9ADu));
    cpu->esp += 4u;
    label_0000D9B0:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D9B6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40D9B6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000D9C0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DA01;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D9F6u)); sfera_sub_0040ADC0(cpu, LIFT_CODE_TOKEN_VA(0x40D9F6u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DA01:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000DA4F;
    { uint64_t l=*(uint32_t*)(cpu->ecx + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->ecx + 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000DA18;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000DA18:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DA27u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40DA27u));
    if ((int32_t)cpu->eax >= 0) goto label_0000DB6A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DA43u)); sfera_sub_0040ADC0(cpu, LIFT_CODE_TOKEN_VA(0x40DA43u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DA4F:
    if (cpu->ecx != cpu->eax) goto label_0000DA8C;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DA62u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DA62u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DB6A;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DA80u)); sfera_sub_0040ADC0(cpu, LIFT_CODE_TOKEN_VA(0x40DA80u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DA8C:
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DA98u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DA98u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DAEA;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DAADu)); sfera_sub_00402540(cpu, LIFT_CODE_TOKEN_VA(0x40DAADu));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DABDu)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DABDu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DAEA;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DB40;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DADEu)); sfera_sub_0040ADC0(cpu, LIFT_CODE_TOKEN_VA(0x40DADEu));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DAEA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DAFAu)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DAFAu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DB6A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DB0Fu)); sfera_sub_004022D0(cpu, LIFT_CODE_TOKEN_VA(0x40DB0Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_0000DB30;
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DB24u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DB24u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DB6A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    label_0000DB30:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DB55;
    label_0000DB40:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DB49u)); sfera_sub_0040ADC0(cpu, LIFT_CODE_TOKEN_VA(0x40DB49u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DB55:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DB5Eu)); sfera_sub_0040ADC0(cpu, LIFT_CODE_TOKEN_VA(0x40DB5Eu));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DB6A:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DB79u)); sfera_sub_0040C9F0(cpu, LIFT_CODE_TOKEN_VA(0x40DB79u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040DB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DBBC;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DBB2u)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40DBB2u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DBBC:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if (cpu->ebx != *(uint32_t*)(cpu->eax)) goto label_0000DBEE;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->ebx + 0xCu)) goto label_0000DCCD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DBE2u)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40DBE2u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DBEE:
    if (cpu->ebx != cpu->eax) goto label_0000DC1B;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->edi + 0xCu)) goto label_0000DCCD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DC0Fu)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40DC0Fu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DC1B:
    cpu->ebp = *(uint32_t*)(cpu->edi + 0xCu);
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0xCu), r=cpu->ebp, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0000DC76;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DC30u)); sfera_sub_00402540(cpu, LIFT_CODE_TOKEN_VA(0x40DC30u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->ebp) goto label_0000DC73;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DC5E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DC52u)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40DC52u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DC5E:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DC67u)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40DC67u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DC73:
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0xCu), r=cpu->ebp, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0000DC76:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0000DCCD;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DC85u)); sfera_sub_004022D0(cpu, LIFT_CODE_TOKEN_VA(0x40DC85u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_0000DC93;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_0000DCCD;
    label_0000DC93:
    cpu->edx = *(uint32_t*)(cpu->ebx + 8u);
    { uint64_t l=*(uint8_t*)(cpu->edx + 0x2Du), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DCB8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DCACu)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40DCACu));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DCB8:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DCC1u)); sfera_sub_0040B010(cpu, LIFT_CODE_TOKEN_VA(0x40DCC1u));
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DCCD:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DCDCu)); sfera_sub_0040CBC0(cpu, LIFT_CODE_TOKEN_VA(0x40DCDCu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040DCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DD21;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DD16u)); sfera_sub_0040B260(cpu, LIFT_CODE_TOKEN_VA(0x40DD16u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DD21:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000DD6F;
    { uint64_t l=*(uint32_t*)(cpu->ecx + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->ecx + 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000DD38;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000DD38:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DD47u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40DD47u));
    if ((int32_t)cpu->eax >= 0) goto label_0000DE8A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DD63u)); sfera_sub_0040B260(cpu, LIFT_CODE_TOKEN_VA(0x40DD63u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DD6F:
    if (cpu->ecx != cpu->eax) goto label_0000DDAC;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DD82u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DD82u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DE8A;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DDA0u)); sfera_sub_0040B260(cpu, LIFT_CODE_TOKEN_VA(0x40DDA0u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DDAC:
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DDB8u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DDB8u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DE0A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DDCDu)); sfera_sub_00402600(cpu, LIFT_CODE_TOKEN_VA(0x40DDCDu));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DDDDu)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DDDDu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DE0A;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x45u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DE60;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DDFEu)); sfera_sub_0040B260(cpu, LIFT_CODE_TOKEN_VA(0x40DDFEu));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DE0A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DE1Au)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DE1Au));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DE8A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DE2Fu)); sfera_sub_00402360(cpu, LIFT_CODE_TOKEN_VA(0x40DE2Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_0000DE50;
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DE44u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DE44u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DE8A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    label_0000DE50:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x45u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DE75;
    label_0000DE60:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DE69u)); sfera_sub_0040B260(cpu, LIFT_CODE_TOKEN_VA(0x40DE69u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DE75:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DE7Eu)); sfera_sub_0040B260(cpu, LIFT_CODE_TOKEN_VA(0x40DE7Eu));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DE8A:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DE99u)); sfera_sub_0040CCC0(cpu, LIFT_CODE_TOKEN_VA(0x40DE99u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040DEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DEE1;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DED6u)); sfera_sub_0040B4D0(cpu, LIFT_CODE_TOKEN_VA(0x40DED6u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DEE1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000DF2F;
    { uint64_t l=*(uint32_t*)(cpu->ecx + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->ecx + 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000DEF8;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000DEF8:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DF07u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40DF07u));
    if ((int32_t)cpu->eax >= 0) goto label_0000E04A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DF23u)); sfera_sub_0040B4D0(cpu, LIFT_CODE_TOKEN_VA(0x40DF23u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DF2F:
    if (cpu->ecx != cpu->eax) goto label_0000DF6C;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DF42u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DF42u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000E04A;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DF60u)); sfera_sub_0040B4D0(cpu, LIFT_CODE_TOKEN_VA(0x40DF60u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DF6C:
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DF78u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DF78u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DFCA;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DF8Du)); sfera_sub_004026C0(cpu, LIFT_CODE_TOKEN_VA(0x40DF8Du));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DF9Du)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DF9Du));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000DFCA;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x31u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E020;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DFBEu)); sfera_sub_0040B4D0(cpu, LIFT_CODE_TOKEN_VA(0x40DFBEu));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000DFCA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DFDAu)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40DFDAu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000E04A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40DFEFu)); sfera_sub_00402480(cpu, LIFT_CODE_TOKEN_VA(0x40DFEFu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_0000E010;
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E004u)); sfera_sub_00403E60(cpu, LIFT_CODE_TOKEN_VA(0x40E004u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0000E04A;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    label_0000E010:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + 0x31u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000E035;
    label_0000E020:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E029u)); sfera_sub_0040B4D0(cpu, LIFT_CODE_TOKEN_VA(0x40E029u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000E035:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E03Eu)); sfera_sub_0040B4D0(cpu, LIFT_CODE_TOKEN_VA(0x40E03Eu));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000E04A:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E059u)); sfera_sub_0040CE70(cpu, LIFT_CODE_TOKEN_VA(0x40E059u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E070(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E08B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E08B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E09F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E09F:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E118;
    cpu->eax = 0u;
    label_0000E0B4:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E0C4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E0B4;
    label_0000E0C4:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E0F2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E0EF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E0E0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E0E0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E0EF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E0F2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E103u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E103u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E117u)); sfera_sub_0040FAC0(cpu, LIFT_CODE_TOKEN_VA(0x40E117u));
    cpu->edi = lift_pop32(cpu);
    label_0000E118:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E120(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E13B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E13B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E14F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E14F:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E1C8;
    cpu->eax = 0u;
    label_0000E164:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E174;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E164;
    label_0000E174:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E1A2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E19F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E190:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E190;
    cpu->ebp = lift_pop32(cpu);
    label_0000E19F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E1A2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E1B3u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E1B3u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E1C7u)); sfera_sub_0040FB10(cpu, LIFT_CODE_TOKEN_VA(0x40E1C7u));
    cpu->edi = lift_pop32(cpu);
    label_0000E1C8:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E1D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E1EB;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E1EB:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E1FF;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E1FF:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E278;
    cpu->eax = 0u;
    label_0000E214:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E224;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E214;
    label_0000E224:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E252;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E24F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E240:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E240;
    cpu->ebp = lift_pop32(cpu);
    label_0000E24F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E252:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E263u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E263u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E277u)); sfera_sub_0040FB60(cpu, LIFT_CODE_TOKEN_VA(0x40E277u));
    cpu->edi = lift_pop32(cpu);
    label_0000E278:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E280(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E29B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E29B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E2AF;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E2AF:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E328;
    cpu->eax = 0u;
    label_0000E2C4:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E2D4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E2C4;
    label_0000E2D4:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E302;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E2FF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E2F0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E2F0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E2FF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E302:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E313u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E313u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E327u)); sfera_sub_0040FBB0(cpu, LIFT_CODE_TOKEN_VA(0x40E327u));
    cpu->edi = lift_pop32(cpu);
    label_0000E328:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E330(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E34B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E34B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E35F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E35F:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E3D8;
    cpu->eax = 0u;
    label_0000E374:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E384;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E374;
    label_0000E384:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E3B2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E3AF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E3A0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E3A0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E3AF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E3B2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E3C3u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E3C3u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E3D7u)); sfera_sub_0040FC00(cpu, LIFT_CODE_TOKEN_VA(0x40E3D7u));
    cpu->edi = lift_pop32(cpu);
    label_0000E3D8:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E3E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E3FB;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E3FB:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E40F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E40F:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E488;
    cpu->eax = 0u;
    label_0000E424:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E434;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E424;
    label_0000E434:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E462;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E45F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E450:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E450;
    cpu->ebp = lift_pop32(cpu);
    label_0000E45F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E462:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E473u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E473u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E487u)); sfera_sub_0040FC50(cpu, LIFT_CODE_TOKEN_VA(0x40E487u));
    cpu->edi = lift_pop32(cpu);
    label_0000E488:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E490(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E4AB;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E4AB:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E4BF;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E4BF:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E538;
    cpu->eax = 0u;
    label_0000E4D4:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E4E4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E4D4;
    label_0000E4E4:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E512;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E50F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E500:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E500;
    cpu->ebp = lift_pop32(cpu);
    label_0000E50F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E512:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E523u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E523u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E537u)); sfera_sub_0040FCA0(cpu, LIFT_CODE_TOKEN_VA(0x40E537u));
    cpu->edi = lift_pop32(cpu);
    label_0000E538:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E55B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E55B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E56F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E56F:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E5E8;
    cpu->eax = 0u;
    label_0000E584:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E594;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E584;
    label_0000E594:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E5C2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E5BF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E5B0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E5B0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E5BF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E5C2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E5D3u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E5D3u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E5E7u)); sfera_sub_0040FCF0(cpu, LIFT_CODE_TOKEN_VA(0x40E5E7u));
    cpu->edi = lift_pop32(cpu);
    label_0000E5E8:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E5F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E60B;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E60B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E61F;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0000E61F:
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E698;
    cpu->eax = 0u;
    label_0000E634:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E644;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E634;
    label_0000E644:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E672;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E66F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E660:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E660;
    cpu->ebp = lift_pop32(cpu);
    label_0000E66F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E672:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E683u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E683u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E697u)); sfera_sub_0040FD40(cpu, LIFT_CODE_TOKEN_VA(0x40E697u));
    cpu->edi = lift_pop32(cpu);
    label_0000E698:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x10u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E6B5u)); sfera_sub_0040C840(cpu, LIFT_CODE_TOKEN_VA(0x40E6B5u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E6C2u)); sfera_sub_00409AC0(cpu, LIFT_CODE_TOKEN_VA(0x40E6C2u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E860(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E873u)); sfera_sub_0040B940(cpu, LIFT_CODE_TOKEN_VA(0x40E873u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    *(uint8_t*)(cpu->edi + 8u) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E8A3u)); sfera_sub_0040B9A0(cpu, LIFT_CODE_TOKEN_VA(0x40E8A3u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    *(uint8_t*)(cpu->edi + 8u) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E8D3u)); sfera_sub_0040BA00(cpu, LIFT_CODE_TOKEN_VA(0x40E8D3u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    *(uint8_t*)(cpu->edi + 8u) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E8F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E903u)); sfera_sub_0040BA80(cpu, LIFT_CODE_TOKEN_VA(0x40E903u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    *(uint8_t*)(cpu->edi + 8u) = cpu->eax & 0xFFu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E920(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_0000E953;
    lift_push32(cpu, cpu->edi);
    label_0000E940:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E948u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40E948u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 4u)) goto label_0000E940;
    cpu->edi = lift_pop32(cpu);
    label_0000E953:
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E95Cu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40E95Cu));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E960(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_0000E99E;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->eax) goto label_0000E99E;
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E983u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x40E983u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E98Cu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40E98Cu));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000E99E:
    { uint64_t l=cpu->esi, r=*(uint32_t*)(cpu->esp + 0x1Cu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000EA92;
    lift_push32(cpu, cpu->ebp);
    label_0000E9B0:
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx >>= 3u;
    cpu->ebp = 0u;
    ++cpu->edx;
    cpu->ebx = 0x811C9DC5u;
    if (cpu->ecx == 0u) goto label_0000E9F0;
    (void)cpu;
    label_0000E9D0:
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000E9DB;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    goto label_0000E9DE;
    label_0000E9DB:
    cpu->eax = cpu->esi + 8u;
    label_0000E9DE:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ebp));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1000193u);
    cpu->ebp += cpu->edx;
    cpu->ebx ^= cpu->eax;
    if (cpu->ebp < cpu->ecx) goto label_0000E9D0;
    label_0000E9F0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->ebx;
    { uint64_t l=*(uint32_t*)(cpu->edx + 0x24u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EA09;
    cpu->ecx >>= 1u;
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->ebx -= cpu->ecx;
    cpu->eax += cpu->ebx;
    label_0000EA09:
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    { uint64_t l=*(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u), r=cpu->esi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000EA32;
    if (*(uint32_t*)(cpu->ecx) != cpu->esi) goto label_0000EA2A;
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->ebx;
    goto label_0000EA3A;
    label_0000EA2A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000EA3A;
    label_0000EA32:
    if (*(uint32_t*)(cpu->ecx) != cpu->esi) goto label_0000EA3A;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_0000EA3A:
    { uint64_t l=cpu->esi, r=*(uint32_t*)(cpu->edx + 4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->edx + 4u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000EA81;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000EA63;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EA60u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40EA60u));
    cpu->esp += 4u;
    label_0000EA63:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = 0u;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EA7Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40EA7Bu));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->ebx + 4u);
    label_0000EA81:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    { uint64_t l=cpu->esi, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E9B0;
    cpu->ebp = lift_pop32(cpu);
    label_0000EA92:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EAA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EADA;
    if (cpu->edx != cpu->eax) goto label_0000EADA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EAC0u)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x40EAC0u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EAC9u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EAC9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EADA:
    if (cpu->ecx == cpu->edx) goto label_0000EAFD;
    label_0000EAE0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EAF3u)); sfera_sub_0040AB90(cpu, LIFT_CODE_TOKEN_VA(0x40EAF3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EAE0;
    label_0000EAFD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EB10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EB3E;
    if (cpu->edx != cpu->eax) goto label_0000EB3E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB2Eu)); sfera_sub_0040E920(cpu, LIFT_CODE_TOKEN_VA(0x40EB2Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EB3E:
    if (cpu->ecx == cpu->edx) goto label_0000EB5F;
    label_0000EB42:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB55u)); sfera_sub_00407BD0(cpu, LIFT_CODE_TOKEN_VA(0x40EB55u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0000EB42;
    label_0000EB5F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EB70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EBAA;
    if (cpu->edx != cpu->eax) goto label_0000EBAA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB90u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x40EB90u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB99u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EB99u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EBAA:
    if (cpu->ecx == cpu->edx) goto label_0000EBCD;
    label_0000EBB0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EBC3u)); sfera_sub_0040D820(cpu, LIFT_CODE_TOKEN_VA(0x40EBC3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EBB0;
    label_0000EBCD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EBE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_0000EC1E;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->eax) goto label_0000EC1E;
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EC03u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x40EC03u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EC0Cu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EC0Cu));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EC1E:
    { uint64_t l=cpu->edi, r=*(uint32_t*)(cpu->esp + 0x1Cu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000ED30;
    lift_push32(cpu, cpu->ebp);
    label_0000EC30:
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx >>= 3u;
    cpu->ebp = 0u;
    ++cpu->edx;
    cpu->ebx = 0x811C9DC5u;
    if (cpu->ecx == 0u) goto label_0000EC70;
    (void)cpu;
    label_0000EC50:
    if (*(uint32_t*)(cpu->edi + 0x1Cu) < 0x10u) goto label_0000EC5B;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    goto label_0000EC5E;
    label_0000EC5B:
    cpu->eax = cpu->edi + 8u;
    label_0000EC5E:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ebp));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1000193u);
    cpu->ebp += cpu->edx;
    cpu->ebx ^= cpu->eax;
    if (cpu->ebp < cpu->ecx) goto label_0000EC50;
    label_0000EC70:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->ebx;
    { uint64_t l=*(uint32_t*)(cpu->edx + 0x24u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EC89;
    cpu->ecx >>= 1u;
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->ebx -= cpu->ecx;
    cpu->eax += cpu->ebx;
    label_0000EC89:
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    { uint64_t l=*(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000ECB2;
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000ECAA;
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->ebx;
    goto label_0000ECBA;
    label_0000ECAA:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000ECBA;
    label_0000ECB2:
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000ECBA;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_0000ECBA:
    { uint64_t l=cpu->edi, r=*(uint32_t*)(cpu->edx + 4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->edx + 4u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000ED1F;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x38u) < 0x10u) goto label_0000ECE3;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ECE0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40ECE0u));
    cpu->esp += 4u;
    label_0000ECE3:
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->edi + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x34u) = cpu->ebp;
    *(uint8_t*)(cpu->edi + 0x24u) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x1Cu) < 0x10u) goto label_0000ED05;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED02u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40ED02u));
    cpu->esp += 4u;
    label_0000ED05:
    *(uint32_t*)(cpu->edi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->edi + 8u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED19u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40ED19u));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->ebx + 4u);
    label_0000ED1F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    { uint64_t l=cpu->edi, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000EC30;
    cpu->ebp = lift_pop32(cpu);
    label_0000ED30:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040ED40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000ED7A;
    if (cpu->edx != cpu->eax) goto label_0000ED7A;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED60u)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x40ED60u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED69u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40ED69u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000ED7A:
    if (cpu->ecx == cpu->edx) goto label_0000ED9D;
    label_0000ED80:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED93u)); sfera_sub_0040A180(cpu, LIFT_CODE_TOKEN_VA(0x40ED93u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000ED80;
    label_0000ED9D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EDB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EDEA;
    if (cpu->edx != cpu->eax) goto label_0000EDEA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EDD0u)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x40EDD0u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EDD9u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EDD9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EDEA:
    if (cpu->ecx == cpu->edx) goto label_0000EE0D;
    label_0000EDF0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE03u)); sfera_sub_0040D8C0(cpu, LIFT_CODE_TOKEN_VA(0x40EE03u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EDF0;
    label_0000EE0D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EE20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EE5A;
    if (cpu->edx != cpu->eax) goto label_0000EE5A;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE40u)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x40EE40u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE49u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EE49u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EE5A:
    if (cpu->ecx == cpu->edx) goto label_0000EE7D;
    label_0000EE60:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE73u)); sfera_sub_0040AC20(cpu, LIFT_CODE_TOKEN_VA(0x40EE73u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EE60;
    label_0000EE7D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EE90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx += cpu->eax;
    cpu->esi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_0000EEC1;
    lift_push32(cpu, cpu->ebx);
    label_0000EEB0:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->ebx;
    if (cpu->eax != cpu->edx) goto label_0000EEB0;
    cpu->ebx = lift_pop32(cpu);
    label_0000EEC1:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    { uint64_t l=*(uint32_t*)(cpu->ecx + 0x24u), r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EED6;
    cpu->edx >>= 1u;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_0000EED6:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    { uint64_t l=*(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = cpu->edx + (cpu->eax * 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000EEFF;
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000EEF7;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) = cpu->esi;
    goto label_0000EF07;
    label_0000EEF7:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    goto label_0000EF07;
    label_0000EEFF:
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000EF0B;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_0000EF07:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000EF0B:
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EF19u)); sfera_sub_0040D950(cpu, LIFT_CODE_TOKEN_VA(0x40EF19u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40EF32u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000EF51;
    cpu->edx += 0x7FFFFFFFu;
    label_0000EF51:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x24u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EF66;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000EF66:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    cpu->edi = cpu->ebp + 4u;
    if (cpu->esi == cpu->ecx) goto label_0000EF94;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (cpu->esi == cpu->ecx) goto label_0000EF94;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000EF88:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->eax) goto label_0000EFCA;
    if (cpu->esi != cpu->ecx) goto label_0000EF88;
    label_0000EF94:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000EFAF;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EFABu)); sfera_sub_004039D0(cpu, LIFT_CODE_TOKEN_VA(0x40EFABu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000EFAF:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000EFFE;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F024;
    label_0000EFCA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax == *(uint32_t*)(cpu->edi)) goto label_0000EFED;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EFE7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40EFE7u));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000EFED:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EFFE:
    if (cpu->edx != cpu->esi) goto label_0000F006;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F024;
    label_0000F006:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000F024;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F024:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F02Bu)); sfera_sub_0040E070(cpu, LIFT_CODE_TOKEN_VA(0x40F02Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_0000F070;
    label_0000F060:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_0000F060;
    label_0000F070:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0x24u), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F085;
    cpu->eax >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F085:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->ebp = cpu->ebx + 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_0000F0BF;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F0BF;
    label_0000F0A5:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F0B5u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F0B5u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F0F6;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x10u)) goto label_0000F0A5;
    label_0000F0BF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F0DA;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F0D6u)); sfera_sub_00404EF0(cpu, LIFT_CODE_TOKEN_VA(0x40F0D6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0000F0DA:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F12E;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u) = cpu->ecx;
    goto label_0000F154;
    label_0000F0F6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F103u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F103u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F10B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F0BF;
    label_0000F10B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F11Cu)); sfera_sub_00406BA0(cpu, LIFT_CODE_TOKEN_VA(0x40F11Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F12E:
    if (cpu->edx != cpu->esi) goto label_0000F136;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F154;
    label_0000F136:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F154;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->edi * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F154:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F15Bu)); sfera_sub_0040E120(cpu, LIFT_CODE_TOKEN_VA(0x40F15Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F196u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40F196u));
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x24u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F1B0;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0000F1B0:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->ebp + 4u;
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->esi == cpu->ecx) goto label_0000F232;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F232;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0000F1E2:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1Cu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = cpu->esi + 8u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F1F3;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F1F3:
    cpu->edx = cpu->ebx;
    if (cpu->ebx < cpu->edi) goto label_0000F1FB;
    cpu->edx = cpu->edi;
    label_0000F1FB:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F208;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0000F208:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F210u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40F210u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000F224;
    if (cpu->ebx < cpu->edi) goto label_0000F224;
    { uint64_t l=cpu->ebx, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if (cpu->eax == 0u) goto label_0000F265;
    label_0000F224:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F1E2;
    label_0000F22A:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000F232:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F24D;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F249u)); sfera_sub_00403A60(cpu, LIFT_CODE_TOKEN_VA(0x40F249u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0000F24D:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000F2B7;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F2DB;
    label_0000F265:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->esi + 8u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F277;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    goto label_0000F27B;
    label_0000F277:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000F27B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F288u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40F288u));
    if (cpu->eax == 0u) goto label_0000F290;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F22A;
    label_0000F290:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F2A3u)); sfera_sub_0040A680(cpu, LIFT_CODE_TOKEN_VA(0x40F2A3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F2B7:
    if (cpu->edx != cpu->esi) goto label_0000F2BF;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F2DB;
    label_0000F2BF:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_0000F2DB;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F2DB:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F2E2u)); sfera_sub_0040E1D0(cpu, LIFT_CODE_TOKEN_VA(0x40F2E2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40F312u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000F331;
    cpu->edx += 0x7FFFFFFFu;
    label_0000F331:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->edi + 0x24u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F346;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000F346:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    cpu->ebp = cpu->edi + 4u;
    if (cpu->esi == cpu->ecx) goto label_0000F374;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (cpu->esi == cpu->ecx) goto label_0000F374;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F368:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->eax) goto label_0000F3B0;
    if (cpu->esi != cpu->ecx) goto label_0000F368;
    label_0000F374:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F38F;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F38Bu)); sfera_sub_00403A60(cpu, LIFT_CODE_TOKEN_VA(0x40F38Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000F38F:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F3D2;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 8u) + 4u) = cpu->edx;
    goto label_0000F3F8;
    label_0000F3B0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F3C1u)); sfera_sub_0040C700(cpu, LIFT_CODE_TOKEN_VA(0x40F3C1u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F3D2:
    if (cpu->edx != cpu->esi) goto label_0000F3DA;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F3F8;
    label_0000F3DA:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000F3F8;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u);
    cpu->eax = cpu->edx + (cpu->ebx * 8u) + 4u;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F3F8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F3FFu)); sfera_sub_0040E280(cpu, LIFT_CODE_TOKEN_VA(0x40F3FFu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F436u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40F436u));
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x24u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F450;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0000F450:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->ebp + 4u;
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->esi == cpu->ecx) goto label_0000F4D2;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F4D2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0000F482:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1Cu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = cpu->esi + 8u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F493;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F493:
    cpu->edx = cpu->ebx;
    if (cpu->ebx < cpu->edi) goto label_0000F49B;
    cpu->edx = cpu->edi;
    label_0000F49B:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F4A8;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0000F4A8:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F4B0u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40F4B0u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000F4C4;
    if (cpu->ebx < cpu->edi) goto label_0000F4C4;
    { uint64_t l=cpu->ebx, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if (cpu->eax == 0u) goto label_0000F505;
    label_0000F4C4:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F482;
    label_0000F4CA:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000F4D2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F4ED;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F4E9u)); sfera_sub_00403AF0(cpu, LIFT_CODE_TOKEN_VA(0x40F4E9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0000F4ED:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000F557;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F57B;
    label_0000F505:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->esi + 8u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F517;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    goto label_0000F51B;
    label_0000F517:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000F51B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F528u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40F528u));
    if (cpu->eax == 0u) goto label_0000F530;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F4CA;
    label_0000F530:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F543u)); sfera_sub_0040C770(cpu, LIFT_CODE_TOKEN_VA(0x40F543u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F557:
    if (cpu->edx != cpu->esi) goto label_0000F55F;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F57B;
    label_0000F55F:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_0000F57B;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F57B:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F582u)); sfera_sub_0040E330(cpu, LIFT_CODE_TOKEN_VA(0x40F582u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F5A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_0000F5D0;
    label_0000F5C0:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_0000F5C0;
    label_0000F5D0:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0x24u), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F5E5;
    cpu->eax >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F5E5:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->ebp = cpu->ebx + 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_0000F61F;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F61F;
    label_0000F605:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F615u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F615u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F656;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x10u)) goto label_0000F605;
    label_0000F61F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F63A;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F636u)); sfera_sub_00403B80(cpu, LIFT_CODE_TOKEN_VA(0x40F636u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0000F63A:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F68E;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u) = cpu->ecx;
    goto label_0000F6B4;
    label_0000F656:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F663u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F663u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F66B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F61F;
    label_0000F66B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F67Cu)); sfera_sub_0040D950(cpu, LIFT_CODE_TOKEN_VA(0x40F67Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F68E:
    if (cpu->edx != cpu->esi) goto label_0000F696;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F6B4;
    label_0000F696:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F6B4;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->edi * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F6B4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F6BBu)); sfera_sub_0040E3E0(cpu, LIFT_CODE_TOKEN_VA(0x40F6BBu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40F6F2u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000F711;
    cpu->edx += 0x7FFFFFFFu;
    label_0000F711:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->edi + 0x24u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F726;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000F726:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    cpu->ebp = cpu->edi + 4u;
    if (cpu->esi == cpu->ecx) goto label_0000F754;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (cpu->esi == cpu->ecx) goto label_0000F754;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F748:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->eax) goto label_0000F790;
    if (cpu->esi != cpu->ecx) goto label_0000F748;
    label_0000F754:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F76F;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F76Bu)); sfera_sub_00404EF0(cpu, LIFT_CODE_TOKEN_VA(0x40F76Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000F76F:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F7B2;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 8u) + 4u) = cpu->edx;
    goto label_0000F7D8;
    label_0000F790:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F7A1u)); sfera_sub_00408D20(cpu, LIFT_CODE_TOKEN_VA(0x40F7A1u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F7B2:
    if (cpu->edx != cpu->esi) goto label_0000F7BA;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F7D8;
    label_0000F7BA:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000F7D8;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u);
    cpu->eax = cpu->edx + (cpu->ebx * 8u) + 4u;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F7D8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F7DFu)); sfera_sub_0040E490(cpu, LIFT_CODE_TOKEN_VA(0x40F7DFu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F816u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40F816u));
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x24u), r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F830;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0000F830:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->ebp + 4u;
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->esi == cpu->ecx) goto label_0000F8B2;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F8B2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0000F862:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1Cu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = cpu->esi + 8u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F873;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F873:
    cpu->edx = cpu->ebx;
    if (cpu->ebx < cpu->edi) goto label_0000F87B;
    cpu->edx = cpu->edi;
    label_0000F87B:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F888;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0000F888:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F890u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40F890u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000F8A4;
    if (cpu->ebx < cpu->edi) goto label_0000F8A4;
    { uint64_t l=cpu->ebx, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if (cpu->eax == 0u) goto label_0000F8E5;
    label_0000F8A4:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F862;
    label_0000F8AA:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000F8B2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F8CD;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F8C9u)); sfera_sub_00403B80(cpu, LIFT_CODE_TOKEN_VA(0x40F8C9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0000F8CD:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000F937;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F95B;
    label_0000F8E5:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x18u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->esi + 8u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F8F7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    goto label_0000F8FB;
    label_0000F8F7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000F8FB:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F908u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40F908u));
    if (cpu->eax == 0u) goto label_0000F910;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F8AA;
    label_0000F910:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F923u)); sfera_sub_0040C7F0(cpu, LIFT_CODE_TOKEN_VA(0x40F923u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F937:
    if (cpu->edx != cpu->esi) goto label_0000F93F;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F95B;
    label_0000F93F:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_0000F95B;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F95B:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F962u)); sfera_sub_0040E540(cpu, LIFT_CODE_TOKEN_VA(0x40F962u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_0000F9B0;
    label_0000F9A0:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_0000F9A0;
    label_0000F9B0:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    { uint64_t l=*(uint32_t*)(cpu->ebx + 0x24u), r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F9C5;
    cpu->eax >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F9C5:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->ebp = cpu->ebx + 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_0000F9FF;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F9FF;
    label_0000F9E5:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F9F5u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F9F5u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000FA36;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x10u)) goto label_0000F9E5;
    label_0000F9FF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000FA1A;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA16u)); sfera_sub_00404F80(cpu, LIFT_CODE_TOKEN_VA(0x40FA16u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0000FA1A:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000FA6E;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u) = cpu->ecx;
    goto label_0000FA94;
    label_0000FA36:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA43u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40FA43u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000FA4B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F9FF;
    label_0000FA4B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA5Cu)); sfera_sub_0040A220(cpu, LIFT_CODE_TOKEN_VA(0x40FA5Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FA6E:
    if (cpu->edx != cpu->esi) goto label_0000FA76;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000FA94;
    label_0000FA76:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000FA94;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->edi * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000FA94:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA9Bu)); sfera_sub_0040E5F0(cpu, LIFT_CODE_TOKEN_VA(0x40FA9Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FB02;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FAE0:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FAFDu)); sfera_sub_0040EF20(cpu, LIFT_CODE_TOKEN_VA(0x40FAFDu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FAE0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FB02:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FB52;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FB30:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FB4Du)); sfera_sub_0040F040(cpu, LIFT_CODE_TOKEN_VA(0x40FB4Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FB30;
    cpu->ebx = lift_pop32(cpu);
    label_0000FB52:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FB60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FBA2;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FB80:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FB9Du)); sfera_sub_0040F180(cpu, LIFT_CODE_TOKEN_VA(0x40FB9Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FB80;
    cpu->ebx = lift_pop32(cpu);
    label_0000FBA2:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FBF2;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FBD0:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FBEDu)); sfera_sub_0040F300(cpu, LIFT_CODE_TOKEN_VA(0x40FBEDu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FBD0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FBF2:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FC42;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FC20:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FC3Du)); sfera_sub_0040F420(cpu, LIFT_CODE_TOKEN_VA(0x40FC3Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FC20;
    cpu->ebx = lift_pop32(cpu);
    label_0000FC42:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FC92;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FC70:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FC8Du)); sfera_sub_0040F5A0(cpu, LIFT_CODE_TOKEN_VA(0x40FC8Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FC70;
    cpu->ebx = lift_pop32(cpu);
    label_0000FC92:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FCE2;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FCC0:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FCDDu)); sfera_sub_0040F6E0(cpu, LIFT_CODE_TOKEN_VA(0x40FCDDu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FCC0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FCE2:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FD32;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FD10:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FD2Du)); sfera_sub_0040F800(cpu, LIFT_CODE_TOKEN_VA(0x40FD2Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FD10;
    cpu->ebx = lift_pop32(cpu);
    label_0000FD32:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FD82;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FD60:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esp + 0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FD7Du)); sfera_sub_0040F980(cpu, LIFT_CODE_TOKEN_VA(0x40FD7Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FD60;
    cpu->ebx = lift_pop32(cpu);
    label_0000FD82:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FD90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FDC2u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40FDC2u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_0000FE37;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0000FE0C;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE06u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x40FE06u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    label_0000FE0C:
    cpu->eax = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FE37:
    cpu->edx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE5Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FE5Cu));
    lift_trap(cpu, 0x40FE5Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040FE22(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE2Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40FE2Bu));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE37u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FE37u));
    cpu->edx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE5Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FE5Cu));
    lift_trap(cpu, 0x40FE5Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040FE60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE92u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40FE92u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_0000FF07;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0000FEDC;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FED6u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x40FED6u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x1Cu));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0000FEDC:
    cpu->eax = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FF07:
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FF2Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FF2Cu));
    lift_trap(cpu, 0x40FF2Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040FEF2(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FEFBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40FEFBu));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FF07u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FF07u));
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FF2Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FF2Cu));
    lift_trap(cpu, 0x40FF2Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040FF30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FF62u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x40FF62u));
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_0000FFD9;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = cpu->esi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->eax == cpu->ebx) goto label_0000FFAE;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 4u;
    cpu->edx += 4u;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xFFAEu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0xFFAEu));
    label_0000FFAE:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FFD9:
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FFFEu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FFFEu));
    lift_trap(cpu, 0x40FFFEu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0040FFC4(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FFCDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x40FFCDu));
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FFD9u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FFD9u));
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FFFEu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FFFEu));
    lift_trap(cpu, 0x40FFFEu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410032u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410032u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_000100C6;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0001009B;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41007Au)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x41007Au));
    cpu->ecx = cpu->esi + 0x1Cu;
    cpu->ebx += 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1009Bu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0x1009Bu));
    label_0001009B:
    cpu->eax = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000100C6:
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4100EBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4100EBu));
    lift_trap(cpu, 0x4100EBu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004100B1(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4100BAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4100BAu));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4100C6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4100C6u));
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4100EBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4100EBu));
    lift_trap(cpu, 0x4100EBu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004100F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410122u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410122u));
    cpu->ebx = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    if (cpu->ebx == cpu->eax) goto label_000101A5;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->ebx + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->ebx) = cpu->ecx;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0001017A;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410166u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x410166u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    label_0001017A:
    cpu->eax = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000101A5:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4101CAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4101CAu));
    lift_trap(cpu, 0x4101CAu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410190(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410199u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410199u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4101A5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4101A5u));
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4101CAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4101CAu));
    lift_trap(cpu, 0x4101CAu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4103A9u)); sfera_sub_0040C920(cpu, LIFT_CODE_TOKEN_VA(0x4103A9u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x9249248u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000103C3;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x410390u), "std::length_error");
    label_000103C3:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004103E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4103FBu)); sfera_sub_0040C920(cpu, LIFT_CODE_TOKEN_VA(0x4103FBu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x9249248u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010415;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4103E0u), "std::length_error");
    label_00010415:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0041052E(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410537u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410537u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410543u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410543u));
    lift_trap(cpu, 0x410543u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41056Cu)); sfera_sub_00404750(cpu, LIFT_CODE_TOKEN_VA(0x41056Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410582u)); sfera_sub_0040D400(cpu, LIFT_CODE_TOKEN_VA(0x410582u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4105ACu)); sfera_sub_00403590(cpu, LIFT_CODE_TOKEN_VA(0x4105ACu));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4105C2u)); sfera_sub_0040D4D0(cpu, LIFT_CODE_TOKEN_VA(0x4105C2u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004105D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4105ECu)); sfera_sub_00404990(cpu, LIFT_CODE_TOKEN_VA(0x4105ECu));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410602u)); sfera_sub_0040D5A0(cpu, LIFT_CODE_TOKEN_VA(0x410602u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41062Cu)); sfera_sub_00404BD0(cpu, LIFT_CODE_TOKEN_VA(0x41062Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410642u)); sfera_sub_0040D670(cpu, LIFT_CODE_TOKEN_VA(0x410642u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410650(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->ebp + 0x1Cu) = 0u;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x18u)) goto label_00010683;
    lift_push32(cpu, cpu->edi);
    label_00010670:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410678u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410678u));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->ebp + 0x18u)) goto label_00010670;
    cpu->edi = lift_pop32(cpu);
    label_00010683:
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41068Du)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41068Du));
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ebp + 8u) = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004106A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_000106DA;
    if (cpu->edx != cpu->eax) goto label_000106DA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4106C0u)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x4106C0u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4106C9u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4106C9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000106DA:
    if (cpu->ecx == cpu->edx) goto label_000106FD;
    label_000106E0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4106F3u)); sfera_sub_0040EE90(cpu, LIFT_CODE_TOKEN_VA(0x4106F3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_000106E0;
    label_000106FD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410710(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41072Cu)); sfera_sub_004050B0(cpu, LIFT_CODE_TOKEN_VA(0x41072Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010746;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x410710u), "std::length_error");
    label_00010746:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410768u)); sfera_sub_0040EF20(cpu, LIFT_CODE_TOKEN_VA(0x410768u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41078Cu)); sfera_sub_00406690(cpu, LIFT_CODE_TOKEN_VA(0x41078Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000107A6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x410770u), "std::length_error");
    label_000107A6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4107C8u)); sfera_sub_0040F040(cpu, LIFT_CODE_TOKEN_VA(0x4107C8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004107D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4107ECu)); sfera_sub_00405120(cpu, LIFT_CODE_TOKEN_VA(0x4107ECu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010806;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4107D0u), "std::length_error");
    label_00010806:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410828u)); sfera_sub_0040EF20(cpu, LIFT_CODE_TOKEN_VA(0x410828u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410830(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41084Cu)); sfera_sub_00406710(cpu, LIFT_CODE_TOKEN_VA(0x41084Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010866;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x410830u), "std::length_error");
    label_00010866:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410888u)); sfera_sub_0040F040(cpu, LIFT_CODE_TOKEN_VA(0x410888u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4108ACu)); sfera_sub_00405190(cpu, LIFT_CODE_TOKEN_VA(0x4108ACu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000108C6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x410890u), "std::length_error");
    label_000108C6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4108E8u)); sfera_sub_0040F6E0(cpu, LIFT_CODE_TOKEN_VA(0x4108E8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004108F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41090Cu)); sfera_sub_00406790(cpu, LIFT_CODE_TOKEN_VA(0x41090Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0xFFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010926;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4108F0u), "std::length_error");
    label_00010926:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410948u)); sfera_sub_0040F980(cpu, LIFT_CODE_TOKEN_VA(0x410948u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410950(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410984u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410984u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_00010A03;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esi = cpu->edi + 0xCu;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ecx;
    *(uint16_t*)(cpu->edi + 0x2Cu) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_000109D8;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4109D2u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4109D2u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    label_000109D8:
    cpu->eax = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00010A03:
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410A28u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410A28u));
    lift_trap(cpu, 0x410A28u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004109EE(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4109F7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4109F7u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410A03u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410A03u));
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410A28u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410A28u));
    lift_trap(cpu, 0x410A28u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410A30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410A64u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410A64u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_00010AE3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esi = cpu->edi + 0xCu;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ecx;
    *(uint16_t*)(cpu->edi + 0x2Cu) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_00010AB8;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410AB2u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x410AB2u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x1Cu));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00010AB8:
    cpu->eax = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00010AE3:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410B08u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410B08u));
    lift_trap(cpu, 0x410B08u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410ACE(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410AD7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410AD7u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410AE3u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410AE3u));
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410B08u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410B08u));
    lift_trap(cpu, 0x410B08u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410B10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410B44u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410B44u));
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_00010BC5;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = cpu->esi + 0xCu;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    *(uint16_t*)(cpu->esi + 0x2Cu) = cpu->ebx & 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->eax == cpu->ebx) goto label_00010B9A;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 4u;
    cpu->edx += 4u;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x10B9Au)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0x10B9Au));
    label_00010B9A:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00010BC5:
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410BEAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410BEAu));
    lift_trap(cpu, 0x410BEAu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410BB0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410BB9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410BB9u));
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410BC5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410BC5u));
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410BEAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410BEAu));
    lift_trap(cpu, 0x410BEAu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410BF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x48u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410C24u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410C24u));
    cpu->edi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->ebx) goto label_00010CC0;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esi = cpu->edi + 0xCu;
    *(uint32_t*)(cpu->edi + 8u) = cpu->edx;
    *(uint16_t*)(cpu->edi + 0x44u) = cpu->ebx & 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_00010C95;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410C76u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x410C76u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->esi + 0x1Cu;
    cpu->edx += 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x10C95u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0x10C95u));
    label_00010C95:
    cpu->eax = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00010CC0:
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410CE5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410CE5u));
    lift_trap(cpu, 0x410CE5u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410CAB(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410CB4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410CB4u));
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410CC0u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410CC0u));
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410CE5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410CE5u));
    lift_trap(cpu, 0x410CE5u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410D24u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410D24u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_00010DB1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esi = cpu->edi + 0xCu;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ecx;
    *(uint16_t*)(cpu->edi + 0x30u) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_00010D86;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410D72u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x410D72u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x1Cu) = cpu->eax;
    label_00010D86:
    cpu->eax = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00010DB1:
    cpu->edx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410DD6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410DD6u));
    lift_trap(cpu, 0x410DD6u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410D9C(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410DA5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410DA5u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410DB1u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410DB1u));
    cpu->edx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410DD6u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410DD6u));
    lift_trap(cpu, 0x410DD6u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410E12u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x410E12u));
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_00010E98;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = cpu->esi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->eax == cpu->ebx) goto label_00010E6D;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->ecx = cpu->eax + 8u;
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x10E6Du)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0x10E6Du));
    label_00010E6D:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00010E98:
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410EBDu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410EBDu));
    lift_trap(cpu, 0x410EBDu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00410E83(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410E8Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x410E8Cu));
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410E98u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410E98u));
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410EBDu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410EBDu));
    lift_trap(cpu, 0x410EBDu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00411060(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00011060;
    label_00010430:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    (void)0; /* source SEH registration eliminated */
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->ebx <= 0x9249249u) goto label_00010473;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x410430u), "std::length_error");
    label_00010473:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= cpu->ebx) goto label_0001051A;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41049Eu)); sfera_sub_00402B40(cpu, LIFT_CODE_TOKEN_VA(0x41049Eu));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4104BAu)); sfera_sub_0040D020(cpu, LIFT_CODE_TOKEN_VA(0x4104BAu));
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ecx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->edi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx == 0u) goto label_000104F4;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4104E9u)); sfera_sub_00408FB0(cpu, LIFT_CODE_TOKEN_VA(0x4104E9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4104F1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4104F1u));
    cpu->esp += 4u;
    label_000104F4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = cpu->edi * 8u;
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->edx = cpu->eax + (cpu->ecx * 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_0001051A:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00011060:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    { uint64_t l=cpu->edx, r=cpu->esi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = 0x9249249u;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->esi) goto label_00011096;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x411060u), "std::length_error");
    label_00011096:
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->edi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    { uint64_t l=cpu->esi, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000110DC;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->edi = 0x9249249u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000110C8;
    cpu->eax = 0u;
    goto label_000110CA;
    label_000110C8:
    cpu->eax += cpu->edx;
    label_000110CA:
    if (cpu->eax >= cpu->esi) goto label_000110D0;
    cpu->eax = cpu->esi;
    label_000110D0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    goto label_00010430;
    label_000110DC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004110F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41110Cu)); sfera_sub_004079E0(cpu, LIFT_CODE_TOKEN_VA(0x41110Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011126;
    label_00011120:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011120;
    label_00011126:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411134u)); sfera_sub_0040E960(cpu, LIFT_CODE_TOKEN_VA(0x411134u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41115Cu)); sfera_sub_004076E0(cpu, LIFT_CODE_TOKEN_VA(0x41115Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011176;
    label_00011170:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011170;
    label_00011176:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411184u)); sfera_sub_0040EAA0(cpu, LIFT_CODE_TOKEN_VA(0x411184u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4111ACu)); sfera_sub_004077C0(cpu, LIFT_CODE_TOKEN_VA(0x4111ACu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_000111C6;
    label_000111C0:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000111C0;
    label_000111C6:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4111D4u)); sfera_sub_0040EB10(cpu, LIFT_CODE_TOKEN_VA(0x4111D4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004111E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4111FCu)); sfera_sub_004077C0(cpu, LIFT_CODE_TOKEN_VA(0x4111FCu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011216;
    label_00011210:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011210;
    label_00011216:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411224u)); sfera_sub_0040EB70(cpu, LIFT_CODE_TOKEN_VA(0x411224u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41124Cu)); sfera_sub_004079E0(cpu, LIFT_CODE_TOKEN_VA(0x41124Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011266;
    label_00011260:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011260;
    label_00011266:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411274u)); sfera_sub_0040EBE0(cpu, LIFT_CODE_TOKEN_VA(0x411274u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41129Cu)); sfera_sub_004077C0(cpu, LIFT_CODE_TOKEN_VA(0x41129Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_000112B6;
    label_000112B0:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000112B0;
    label_000112B6:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4112C4u)); sfera_sub_0040ED40(cpu, LIFT_CODE_TOKEN_VA(0x4112C4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004112D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4112ECu)); sfera_sub_004079E0(cpu, LIFT_CODE_TOKEN_VA(0x4112ECu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011306;
    label_00011300:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011300;
    label_00011306:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411314u)); sfera_sub_0040EDB0(cpu, LIFT_CODE_TOKEN_VA(0x411314u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41133Cu)); sfera_sub_004076E0(cpu, LIFT_CODE_TOKEN_VA(0x41133Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011356;
    label_00011350:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011350;
    label_00011356:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411364u)); sfera_sub_0040EE20(cpu, LIFT_CODE_TOKEN_VA(0x411364u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4113A6u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x4113A6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_0001142B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4113EAu)); sfera_sub_00410770(cpu, LIFT_CODE_TOKEN_VA(0x4113EAu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    if (cpu->edi == 0u) goto label_00011414;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41140Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x41140Bu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411411u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411411u));
    cpu->esp += 4u;
    label_00011414:
    cpu->eax = cpu->esi + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001142B:
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411450(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411486u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x411486u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_00011509;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4114C8u)); sfera_sub_00410830(cpu, LIFT_CODE_TOKEN_VA(0x4114C8u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    if (cpu->edi == 0u) goto label_000114F2;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4114E9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4114E9u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4114EFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4114EFu));
    cpu->esp += 4u;
    label_000114F2:
    cpu->eax = cpu->esi + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00011509:
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411520(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x2Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411557u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x411557u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_000115CE;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x3Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411592u)); sfera_sub_00410890(cpu, LIFT_CODE_TOKEN_VA(0x411592u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->esp + 0x34u) = cpu->ebx & 0xFFu;
    if (cpu->edi == cpu->ebx) goto label_000115B6;
    cpu->edx = cpu->ebx + 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4115ADu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4115ADu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4115B3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4115B3u));
    cpu->esp += 4u;
    label_000115B6:
    cpu->eax = cpu->esi + 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000115CE:
    cpu->eax = cpu->ecx + 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004115F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x30u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411627u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x411627u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_00011695;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x40u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41166Eu)); sfera_sub_004108F0(cpu, LIFT_CODE_TOKEN_VA(0x41166Eu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41167Du)); sfera_sub_00402D20(cpu, LIFT_CODE_TOKEN_VA(0x41167Du));
    cpu->eax = cpu->esi + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00011695:
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004116F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->esi >= cpu->ecx) goto label_0001176F;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if (cpu->eax > cpu->esi) goto label_0001176F;
    cpu->esi -= cpu->eax;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=cpu->edx, r=cpu->esi, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_00011749;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x11749u)); sfera_sub_00411060(cpu, LIFT_CODE_TOKEN_RVA(0x11749u));
    label_00011749:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi * 8u;
    cpu->eax -= cpu->esi;
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if (cpu->ecx == cpu->edx) goto label_000117A8;
    lift_push32(cpu, cpu->eax);
    goto label_00011797;
    label_0001176F:
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 8u)) goto label_0001177D;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1177Du)); sfera_sub_00411060(cpu, LIFT_CODE_TOKEN_RVA(0x1177Du));
    label_0001177D:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (cpu->ecx == cpu->edx) goto label_000117A8;
    lift_push32(cpu, cpu->esi);
    label_00011797:
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x117A8u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0x117A8u));
    label_000117A8:
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004117C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4117D9u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x4117D9u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_00011803;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411801u)); sfera_sub_00410710(cpu, LIFT_CODE_TOKEN_VA(0x411801u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00011803:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411839u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x411839u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_00011872;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_x87_push(cpu, 0.0);
    cpu->edx = cpu->esp + 8u;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41185Fu)); sfera_sub_004107D0(cpu, LIFT_CODE_TOKEN_VA(0x41185Fu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00011872:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4118ACu)); sfera_sub_004076E0(cpu, LIFT_CODE_TOKEN_VA(0x4118ACu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_000118C6;
    label_000118C0:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000118C0;
    label_000118C6:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4118D4u)); sfera_sub_004106A0(cpu, LIFT_CODE_TOKEN_VA(0x4118D4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004118E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4118EFu)); sfera_sub_00411520(cpu, LIFT_CODE_TOKEN_VA(0x4118EFu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_0001192B;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411908u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x411908u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411911u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411911u));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_0001192B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41193Fu)); sfera_sub_004115F0(cpu, LIFT_CODE_TOKEN_VA(0x41193Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_0001197B;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411958u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x411958u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411961u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411961u));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_0001197B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4119BEu)); sfera_sub_00404900(cpu, LIFT_CODE_TOKEN_VA(0x4119BEu));
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if (cpu->ebp == *(uint32_t*)(cpu->esi + 4u)) goto label_000119E7;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->ebp + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000119D5;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000119D5:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4119E3u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x4119E3u));
    if ((int32_t)cpu->eax >= 0) goto label_00011A40;
    label_000119E7:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411A01u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x411A01u));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411A15u)); sfera_sub_00410950(cpu, LIFT_CODE_TOKEN_VA(0x411A15u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411A23u)); sfera_sub_0040D9D0(cpu, LIFT_CODE_TOKEN_VA(0x411A23u));
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x2Cu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011A3B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411A38u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411A38u));
    cpu->esp += 4u;
    label_00011A3B:
    cpu->eax = cpu->esi + 0x28u;
    goto label_00011A43;
    label_00011A40:
    cpu->eax = cpu->ebp + 0x28u;
    label_00011A43:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411A70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x38u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411AADu)); sfera_sub_00404900(cpu, LIFT_CODE_TOKEN_VA(0x411AADu));
    cpu->ebp = cpu->eax;
    if (cpu->ebp == *(uint32_t*)(cpu->esi + 4u)) goto label_00011AD5;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->ebp + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011AC2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00011AC2:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411AD1u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x411AD1u));
    if ((int32_t)cpu->eax >= 0) goto label_00011B39;
    label_00011AD5:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    *(uint8_t*)(cpu->esp + 0x18u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411AF4u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x411AF4u));
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x44u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411B0Eu)); sfera_sub_00410A30(cpu, LIFT_CODE_TOKEN_VA(0x411B0Eu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411B1Cu)); sfera_sub_0040D9D0(cpu, LIFT_CODE_TOKEN_VA(0x411B1Cu));
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x28u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011B34;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411B31u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411B31u));
    cpu->esp += 4u;
    label_00011B34:
    cpu->eax = cpu->esi + 0x28u;
    goto label_00011B3C;
    label_00011B39:
    cpu->eax = cpu->ebp + 0x28u;
    label_00011B3C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411B60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x54u;
    (void)0; /* source SEH registration eliminated */
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx;
    if (*(uint8_t*)(cpu->eax + 0x2Du) != (cpu->ebx & 0xFFu)) goto label_00011BBB;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    label_00011BA8:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0xCu) >= (int32_t)cpu->ecx) goto label_00011BB2;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_00011BB6;
    label_00011BB2:
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00011BB6:
    if (*(uint8_t*)(cpu->eax + 0x2Du) == (cpu->ebx & 0xFFu)) goto label_00011BA8;
    label_00011BBB:
    if (cpu->edi == *(uint32_t*)(cpu->esi + 4u)) goto label_00011BCB;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->edi + 0xCu)) goto label_00011C66;
    label_00011BCB:
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp + 0x48u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x34u) = cpu->ebx & 0xFFu;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411C03u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x411C03u));
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x60u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411C14u)); sfera_sub_00410B10(cpu, LIFT_CODE_TOKEN_VA(0x411C14u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411C22u)); sfera_sub_0040DB90(cpu, LIFT_CODE_TOKEN_VA(0x411C22u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) < cpu->edi) goto label_00011C3E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411C3Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411C3Bu));
    cpu->esp += 4u;
    label_00011C3E:
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x48u) < cpu->edi) goto label_00011C61;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411C5Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411C5Eu));
    cpu->esp += 4u;
    label_00011C61:
    cpu->eax = cpu->esi + 0x10u;
    goto label_00011C69;
    label_00011C66:
    cpu->eax = cpu->edi + 0x10u;
    label_00011C69:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411C90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x5Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x70u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411CD1u)); sfera_sub_00404B40(cpu, LIFT_CODE_TOKEN_VA(0x411CD1u));
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if (cpu->ebp == *(uint32_t*)(cpu->esi + 4u)) goto label_00011CFE;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->ebp + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011CE8;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00011CE8:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411CF6u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x411CF6u));
    if ((int32_t)cpu->eax >= 0) goto label_00011DC6;
    label_00011CFE:
    cpu->eax = 0xFu;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x50u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411D29u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x411D29u));
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->ecx);
    cpu->edi = 0xFu;
    cpu->ecx = cpu->esp + 0x38u;
    *(uint8_t*)(cpu->esp + 0x7Cu) = 1u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411D4Du)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x411D4Du));
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x7Cu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411D5Eu)); sfera_sub_00410BF0(cpu, LIFT_CODE_TOKEN_VA(0x411D5Eu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411D6Cu)); sfera_sub_0040DCF0(cpu, LIFT_CODE_TOKEN_VA(0x411D6Cu));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x48u) < cpu->esi) goto label_00011D88;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411D85u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411D85u));
    cpu->esp += 4u;
    label_00011D88:
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x34u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) < cpu->esi) goto label_00011DA7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411DA4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411DA4u));
    cpu->esp += 4u;
    label_00011DA7:
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x64u) < cpu->esi) goto label_00011DC6;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411DC3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411DC3u));
    cpu->esp += 4u;
    label_00011DC6:
    cpu->eax = cpu->ebp + 0x28u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x68u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411DF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x48u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411E2Eu)); sfera_sub_00404D80(cpu, LIFT_CODE_TOKEN_VA(0x411E2Eu));
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if (cpu->ebp == *(uint32_t*)(cpu->esi + 4u)) goto label_00011E5B;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x20u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->ebp + 0xCu;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011E45;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00011E45:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411E53u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x411E53u));
    if ((int32_t)cpu->eax >= 0) goto label_00011EF4;
    label_00011E5B:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411E81u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x411E81u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x54u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411EA2u)); sfera_sub_00410CF0(cpu, LIFT_CODE_TOKEN_VA(0x411EA2u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411EB0u)); sfera_sub_0040DEB0(cpu, LIFT_CODE_TOKEN_VA(0x411EB0u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint8_t*)(cpu->esp + 0x50u) = 2u;
    if (*(uint32_t*)(cpu->esp + 0x40u) == cpu->ebx) goto label_00011EDB;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411ECEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x411ECEu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411ED8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411ED8u));
    cpu->esp += 4u;
    label_00011EDB:
    if (*(uint32_t*)(cpu->esp + 0x34u) < 0x10u) goto label_00011EEF;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411EECu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x411EECu));
    cpu->esp += 4u;
    label_00011EEF:
    cpu->eax = cpu->esi + 0x28u;
    goto label_00011EF7;
    label_00011EF4:
    cpu->eax = cpu->ebp + 0x28u;
    label_00011EF7:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411F20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411F3Cu)); sfera_sub_0040FD90(cpu, LIFT_CODE_TOKEN_VA(0x411F3Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00011F56;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x411F20u), "std::length_error");
    label_00011F56:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411F78u)); sfera_sub_0040F180(cpu, LIFT_CODE_TOKEN_VA(0x411F78u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411F80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411F9Cu)); sfera_sub_0040FE60(cpu, LIFT_CODE_TOKEN_VA(0x411F9Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00011FB6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x411F80u), "std::length_error");
    label_00011FB6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411FD8u)); sfera_sub_0040F180(cpu, LIFT_CODE_TOKEN_VA(0x411FD8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411FE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411FFCu)); sfera_sub_0040FF30(cpu, LIFT_CODE_TOKEN_VA(0x411FFCu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00012016;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x411FE0u), "std::length_error");
    label_00012016:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412038u)); sfera_sub_0040F300(cpu, LIFT_CODE_TOKEN_VA(0x412038u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41205Cu)); sfera_sub_00410000(cpu, LIFT_CODE_TOKEN_VA(0x41205Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x4924923u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00012076;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x412040u), "std::length_error");
    label_00012076:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412098u)); sfera_sub_0040F420(cpu, LIFT_CODE_TOKEN_VA(0x412098u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004120A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4120BCu)); sfera_sub_004100F0(cpu, LIFT_CODE_TOKEN_VA(0x4120BCu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x71C71C6u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000120D6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4120A0u), "std::length_error");
    label_000120D6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4120F8u)); sfera_sub_0040F800(cpu, LIFT_CODE_TOKEN_VA(0x4120F8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412100(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if (*(uint8_t*)(cpu->ebx + 8u) == 0u) goto label_00012149;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->ecx -= *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    { uint64_t l=cpu->edx, r=cpu->ecx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->esi >>= 31u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x10u;
    cpu->esi += cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412131u)); sfera_sub_004116F0(cpu, LIFT_CODE_TOKEN_VA(0x412131u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi * 8u;
    cpu->ecx -= cpu->esi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00012149:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412156u)); sfera_sub_004116F0(cpu, LIFT_CODE_TOKEN_VA(0x412156u));
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412B7Fu)); sfera_sub_00411DF0(cpu, LIFT_CODE_TOKEN_VA(0x412B7Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_00012BBB;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412B98u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x412B98u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412BA1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412BA1u));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_00012BBB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412BC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x40u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412C02u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412C02u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012C5B;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412C27u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412C27u));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412C40u)); sfera_sub_00411F20(cpu, LIFT_CODE_TOKEN_VA(0x412C40u));
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x30u), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = *(uint32_t*)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00012C56;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412C53u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412C53u));
    cpu->esp += 4u;
    label_00012C56:
    cpu->eax = cpu->esi + 0x24u;
    goto label_00012C5E;
    label_00012C5B:
    cpu->eax = cpu->ecx + 0x24u;
    label_00012C5E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412C80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412CC1u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412CC1u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012D23;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412CE9u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412CE9u));
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412D08u)); sfera_sub_00411F80(cpu, LIFT_CODE_TOKEN_VA(0x412D08u));
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x2Cu), r=0x10u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = *(uint32_t*)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00012D1E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412D1Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412D1Bu));
    cpu->esp += 4u;
    label_00012D1E:
    cpu->eax = cpu->esi + 0x24u;
    goto label_00012D26;
    label_00012D23:
    cpu->eax = cpu->ecx + 0x24u;
    label_00012D26:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x58u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412D92u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x412D92u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012E31;
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412DD9u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412DD9u));
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x68u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412DEFu)); sfera_sub_00411FE0(cpu, LIFT_CODE_TOKEN_VA(0x412DEFu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x30u) < cpu->edi) goto label_00012E09;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412E06u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412E06u));
    cpu->esp += 4u;
    label_00012E09:
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) < cpu->edi) goto label_00012E2C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412E29u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412E29u));
    cpu->esp += 4u;
    label_00012E2C:
    cpu->eax = cpu->esi + 0xCu;
    goto label_00012E34;
    label_00012E31:
    cpu->eax = cpu->ecx + 0xCu;
    label_00012E34:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412E60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x78u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412EA6u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412EA6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012F7B;
    cpu->ebx = 0u;
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412EE3u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412EE3u));
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x40u;
    *(uint8_t*)(cpu->esp + 0x84u) = 1u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x40u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412F05u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412F05u));
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x88u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412F1Eu)); sfera_sub_00412040(cpu, LIFT_CODE_TOKEN_VA(0x412F1Eu));
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->esi) goto label_00012F38;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412F35u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412F35u));
    cpu->esp += 4u;
    label_00012F38:
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->esi) goto label_00012F57;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412F54u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412F54u));
    cpu->esp += 4u;
    label_00012F57:
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x6Cu) < cpu->esi) goto label_00012F76;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412F73u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x412F73u));
    cpu->esp += 4u;
    label_00012F76:
    cpu->eax = cpu->edi + 0x24u;
    goto label_00012F7E;
    label_00012F7B:
    cpu->eax = cpu->ecx + 0x24u;
    label_00012F7E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x48u;
    (void)0; /* source SEH registration eliminated */
    cpu->edi = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412FE2u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412FE2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_0001307D;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413017u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x413017u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x58u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41303Du)); sfera_sub_004120A0(cpu, LIFT_CODE_TOKEN_VA(0x41303Du));
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->esp + 0x50u) = 2u;
    if (*(uint32_t*)(cpu->esp + 0x40u) == cpu->ebx) goto label_00013064;
    cpu->edx = cpu->ebx + 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413057u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x413057u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413061u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x413061u));
    cpu->esp += 4u;
    label_00013064:
    if (*(uint32_t*)(cpu->esp + 0x34u) < 0x10u) goto label_00013078;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413075u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x413075u));
    cpu->esp += 4u;
    label_00013078:
    cpu->eax = cpu->esi + 0x24u;
    goto label_00013080;
    label_0001307D:
    cpu->eax = cpu->ecx + 0x24u;
    label_00013080:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004130A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4130BCu)); sfera_sub_00410DE0(cpu, LIFT_CODE_TOKEN_VA(0x4130BCu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x71C71C6u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000130D6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4130A0u), "std::length_error");
    label_000130D6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4130F8u)); sfera_sub_0040F5A0(cpu, LIFT_CODE_TOKEN_VA(0x4130F8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00413B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413B3Fu)); sfera_sub_00412FA0(cpu, LIFT_CODE_TOKEN_VA(0x413B3Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_00013B7B;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413B58u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x413B58u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413B61u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x413B61u));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_00013B7B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00413B80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x5Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = *(uint32_t*)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413BC2u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x413BC2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_00013C98;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x50u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x68u) = 1u;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C1Au)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x413C1Au));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x6Cu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C30u)); sfera_sub_004130A0(cpu, LIFT_CODE_TOKEN_VA(0x413C30u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edi = 0x10u;
    *(uint8_t*)(cpu->esp + 0x64u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->edi) goto label_00013C4E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C4Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x413C4Bu));
    cpu->esp += 4u;
    label_00013C4E:
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) == cpu->ebx) goto label_00013C80;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C73u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x413C73u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C7Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x413C7Du));
    cpu->esp += 4u;
    label_00013C80:
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->edi) goto label_00013C93;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C90u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x413C90u));
    cpu->esp += 4u;
    label_00013C93:
    cpu->eax = cpu->esi + 0x10u;
    goto label_00013C9B;
    label_00013C98:
    cpu->eax = cpu->ecx + 0x10u;
    label_00013C9B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
