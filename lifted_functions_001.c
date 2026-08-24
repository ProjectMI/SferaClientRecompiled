#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A270u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000A2FD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::memmove);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    cpu->ebx = 0u;
    (void)cpu;
    label_0000A290: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A290u);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFECu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_0000A2E6;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000A2A8;
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A2A5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000A2A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A2A8u);
    lift_store32(cpu->edi + 0x14u, 0xFu);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    lift_store8(cpu->edi, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi)) >= (uint32_t)(0x10u)) goto label_0000A2CA;
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFFFCu);
    ++cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0xA2C5u), LIFT_CODE_TOKEN_RVA(0xA2C3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A2C5u);
    cpu->esp += 0xCu;
    goto label_0000A2D2;
    label_0000A2CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A2CAu);
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFECu);
    lift_store32(cpu->edi, cpu->ecx);
    lift_store32(cpu->esi + 0xFFFFFFECu, cpu->ebx);
    label_0000A2D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A2D2u);
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFFFCu);
    lift_store32(cpu->edi + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->esi, cpu->ebx);
    label_0000A2E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A2E6u);
    cpu->esi += 0x1Cu;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFECu);
    cpu->edi += 0x1Cu;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_0000A290;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000A2FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A2FDu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A310u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A33C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A332u); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000A33C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A33Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000A36E;
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_0000A44D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A362u); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000A36E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A36Eu);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_0000A39B;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xCu))) goto label_0000A44D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A38Fu); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000A39B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A39Bu);
    cpu->ebp = lift_load32(cpu->edi + 0xCu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0xCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0000A3F6;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A3B0u); lift_push32(cpu, r); sfera_sub_00402660(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0000A3F3;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A3DE;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A3D2u); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000A3DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A3DEu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A3E7u); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000A3F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A3F3u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0xCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0000A3F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A3F6u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0000A44D;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A405u); lift_push32(cpu, r); sfera_sub_004023F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000A413;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_0000A44D;
    label_0000A413: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A413u);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A438;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A42Cu); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000A438: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A438u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A441u); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000A44D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A44Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A45Cu); lift_push32(cpu, r); sfera_sub_00408FF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A470u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->esi += 8u;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A4C5;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A4B9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A4C2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000A4C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A4C5u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000A4D6;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A4D3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000A4D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A4D6u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A500u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A512u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + 0x14u, 0xFu);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_0000A530: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A530u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0000A530;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A542u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A550u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000A582;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    label_0000A560: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A560u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0000A56B;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0000A560;
    label_0000A56B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A56Bu);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000A582;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A57Du); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_0000A582: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A582u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A590u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_0000A5D7;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x14u);
    cpu->esi -= lift_load32(cpu->ecx + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0000A5D7;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A5D1u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000A5D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A5D7u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A5E0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0000A66F;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0000A66F;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A60E;
    cpu->edi = lift_load32(cpu->esi + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    goto label_0000A612;
    label_0000A60E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A60Eu);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    label_0000A612: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A612u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A629u); lift_push32(cpu, r); sfera_sub_004024D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFF8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A63Du); lift_push32(cpu, r); sfera_sub_004063F0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + (uint64_t)(0xFFFFFFF8u) + (uint64_t)(0u));
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_0000A668;
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_0000A664;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000A664: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A664u);
    lift_store8(cpu->esi + 8u, 0u);
    label_0000A668: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A668u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000A66F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A66Fu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A680u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000A6DD;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_0000A6B3;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A6B0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000A6B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A6B3u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 8u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A6C8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000A6DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A6DDu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A6F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->eax)) goto label_0000A744;
    cpu->ecx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->esi)) goto label_0000A744;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0000A718;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA718u); lift_push32(cpu, r); sfera_sub_00409790(cpu,r); if (cpu->eip != r) return; }
    label_0000A718: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A718u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 8u));
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0000A770;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->edx);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000A744: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A744u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0000A752;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xA752u); lift_push32(cpu, r); sfera_sub_00409790(cpu,r); if (cpu->eip != r) return; }
    label_0000A752: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A752u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000A770;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi, 0u);
    label_0000A770: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A770u);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A780u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A796u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A7A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A7A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000A7EA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000A7EA;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A7C2u); lift_push32(cpu, r); sfera_sub_004097F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000A7EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A7EAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000A85F;
    cpu->edi = cpu->edi;
    label_0000A7F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A7F0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x29u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A848;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) != (uint8_t)(0u)) goto label_0000A820;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) != (uint8_t)(0u)) goto label_0000A81A;
    label_0000A810: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A810u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) == (uint8_t)(0u)) goto label_0000A810;
    label_0000A81A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A81Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_0000A848;
    label_0000A820: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A820u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) != (uint8_t)(0u)) goto label_0000A844;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000A830: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A830u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0000A844;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) == (uint8_t)(0u)) goto label_0000A830;
    label_0000A844: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A844u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0000A848: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A848u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A855u); lift_push32(cpu, r); sfera_sub_00409850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0000A7F0;
    label_0000A85F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A85Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040AB60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40AB60u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AB73u); lift_push32(cpu, r); sfera_sub_004089F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    lift_store8(cpu->edi + 8u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040AB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40AB90u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->edx += cpu->eax;
    cpu->esi = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_0000ABC1;
    lift_push32(cpu, cpu->ebx);
    label_0000ABB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ABB0u);
    cpu->ebx = (int8_t)(lift_load8(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->ebx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000ABB0;
    cpu->ebx = lift_pop32(cpu);
    label_0000ABC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ABC1u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000ABD6;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_0000ABD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ABD6u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000ABFF;
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->edi)) goto label_0000ABF7;
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->esi);
    goto label_0000AC07;
    label_0000ABF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ABF7u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    goto label_0000AC07;
    label_0000ABFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ABFFu);
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->edi)) goto label_0000AC0B;
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->edx, cpu->eax);
    label_0000AC07: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC07u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0000AC0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC0Bu);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AC19u); lift_push32(cpu, r); sfera_sub_00406BA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040AC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_0000AC50;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0000AC40: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC40u);
    cpu->ebx = (int8_t)(lift_load8(cpu->eax));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edi ^= cpu->ebx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000AC40;
    label_0000AC50: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC50u);
    cpu->edx = lift_load32(cpu->esi + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000AC65;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->edi -= cpu->edx;
    cpu->eax += cpu->edi;
    label_0000AC65: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC65u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000AC8E;
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->ecx)) goto label_0000AC86;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->ecx);
    goto label_0000AC96;
    label_0000AC86: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC86u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    goto label_0000AC96;
    label_0000AC8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC8Eu);
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->ecx)) goto label_0000AC9A;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->edx, cpu->ecx);
    label_0000AC96: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC96u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000AC9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AC9Au);
    cpu->ebx = lift_load32(cpu->ecx);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000ACC5;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebx);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ACB9u); lift_push32(cpu, r); sfera_sub_00403C10(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ACBFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 8u, (uint64_t)(lift_load32(cpu->esi + 8u)) - 1u);
    label_0000ACC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ACC5u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040ACE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40ACE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) < (uint32_t)(0x10u)) goto label_0000ACF5;
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ACF2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000ACF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ACF5u);
    lift_store32(cpu->esi + 0x30u, 0xFu);
    lift_store32(cpu->esi + 0x2Cu, 0u);
    lift_store8(cpu->esi + 0x1Cu, 0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000AD18;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AD15u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000AD18: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AD18u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040AD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40AD30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->edx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000AD81;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AD75u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AD7Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000AD81: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AD81u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000AD92;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40AD8Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000AD92: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AD92u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040ADC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40ADC0u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x7FFFFFEu)) goto label_0000AE05;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) < (uint32_t)(0x10u)) goto label_0000ADE2;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ADDFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000ADE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ADE2u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ADF7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xAE05u);
    label_0000AE05: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AE05u);
    ++cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000AE2E;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_0000AE4F;
    label_0000AE2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AE2Eu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AE41;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000AE4F;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_0000AE4F;
    label_0000AE41: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AE41u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000AE4F;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_0000AE4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AE4Fu);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AFED;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_0000AE60: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AE60u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000AF2F;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AE92;
    lift_store8(cpu->edx + 0x2Cu, 1u);
    lift_store8(cpu->esi + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000AFE0;
    label_0000AE92: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AE92u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000AED1;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AEAB;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000AEAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AEABu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000AEBE;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000AECC;
    label_0000AEBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AEBEu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000AEC9;
    lift_store32(cpu->esi, cpu->edx);
    goto label_0000AECC;
    label_0000AEC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AEC9u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_0000AECC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AECCu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000AED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AED1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AEF9;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000AEF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AEF9u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000AF12;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000AFDD;
    label_0000AF12: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF12u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0000AF25;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000AFDD;
    label_0000AF25: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF25u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000AFDD;
    label_0000AF2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF2Fu);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AF52;
    lift_store8(cpu->edx + 0x2Cu, 1u);
    lift_store8(cpu->esi + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000AFE0;
    label_0000AF52: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF52u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000AF92;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AF6A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000AF6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF6Au);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000AF7D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000AF8C;
    label_0000AF7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF7Du);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0000AF8A;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000AF8C;
    label_0000AF8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF8Au);
    lift_store32(cpu->esi, cpu->edx);
    label_0000AF8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF8Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000AF92: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AF92u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AFBA;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000AFBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AFBAu);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000AFCD;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_0000AFDB;
    label_0000AFCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AFCDu);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000AFD8;
    lift_store32(cpu->edi, cpu->esi);
    goto label_0000AFDB;
    label_0000AFD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AFD8u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_0000AFDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AFDBu);
    lift_store32(cpu->esi, cpu->edx);
    label_0000AFDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AFDDu);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_0000AFE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AFE0u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000AE60;
    cpu->edi = lift_pop32(cpu);
    label_0000AFED: cpu->eip = LIFT_CODE_TOKEN_VA(0x40AFEDu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x2Cu, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B010u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x7FFFFFEu)) goto label_0000B055;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x24u)) < (uint32_t)(0x10u)) goto label_0000B032;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B02Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000B032: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B032u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x24u, 0xFu);
    lift_store32(cpu->esi + 0x20u, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x10u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B047u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB055u);
    label_0000B055: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B055u);
    ++cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000B07E;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_0000B09F;
    label_0000B07E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B07Eu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B091;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000B09F;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_0000B09F;
    label_0000B091: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B091u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000B09F;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_0000B09F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B09Fu);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B23D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_0000B0B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B0B0u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000B17F;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B0E2;
    lift_store8(cpu->edx + 0x2Cu, 1u);
    lift_store8(cpu->esi + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000B230;
    label_0000B0E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B0E2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000B121;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B0FB;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000B0FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B0FBu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000B10E;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000B11C;
    label_0000B10E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B10Eu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000B119;
    lift_store32(cpu->esi, cpu->edx);
    goto label_0000B11C;
    label_0000B119: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B119u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_0000B11C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B11Cu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000B121: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B121u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B149;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000B149: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B149u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000B162;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B22D;
    label_0000B162: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B162u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0000B175;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B22D;
    label_0000B175: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B175u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B22D;
    label_0000B17F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B17Fu);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B1A2;
    lift_store8(cpu->edx + 0x2Cu, 1u);
    lift_store8(cpu->esi + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000B230;
    label_0000B1A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B1A2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000B1E2;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B1BA;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000B1BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B1BAu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000B1CD;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000B1DC;
    label_0000B1CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B1CDu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0000B1DA;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B1DC;
    label_0000B1DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B1DAu);
    lift_store32(cpu->esi, cpu->edx);
    label_0000B1DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B1DCu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000B1E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B1E2u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x2Cu, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B20A;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000B20A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B20Au);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000B21D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_0000B22B;
    label_0000B21D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B21Du);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000B228;
    lift_store32(cpu->edi, cpu->esi);
    goto label_0000B22B;
    label_0000B228: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B228u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_0000B22B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B22Bu);
    lift_store32(cpu->esi, cpu->edx);
    label_0000B22D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B22Du);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_0000B230: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B230u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B0B0;
    cpu->edi = lift_pop32(cpu);
    label_0000B23D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B23Du);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x2Cu, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B260u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x4924923u)) goto label_0000B2C6;
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->ebp = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x3Cu)) < (uint32_t)(cpu->ebp)) goto label_0000B288;
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B285u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000B288: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B288u);
    cpu->ebx = 0u;
    cpu->edi = 0xFu;
    lift_store32(cpu->esi + 0x3Cu, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    lift_store8(cpu->esi + 0x28u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) < (uint32_t)(cpu->ebp)) goto label_0000B2A9;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B2A6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000B2A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B2A9u);
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B2B8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB2C6u);
    label_0000B2C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B2C6u);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    ++cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000B2EE;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_0000B30F;
    label_0000B2EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B2EEu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x18u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B301;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000B30F;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_0000B30F;
    label_0000B301: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B301u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000B30F;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_0000B30F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B30Fu);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B4AC;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0000B320: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B320u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000B3EF;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B352;
    lift_store8(cpu->edx + 0x44u, 1u);
    lift_store8(cpu->esi + 0x44u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x44u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000B4A0;
    label_0000B352: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B352u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000B391;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x45u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B36B;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000B36B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B36Bu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000B37E;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000B38C;
    label_0000B37E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B37Eu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000B389;
    lift_store32(cpu->esi, cpu->edx);
    goto label_0000B38C;
    label_0000B389: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B389u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_0000B38C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B38Cu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000B391: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B391u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x44u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x44u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x45u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B3B9;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000B3B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B3B9u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000B3D2;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B49D;
    label_0000B3D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B3D2u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0000B3E5;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B49D;
    label_0000B3E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B3E5u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B49D;
    label_0000B3EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B3EFu);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B412;
    lift_store8(cpu->edx + 0x44u, 1u);
    lift_store8(cpu->esi + 0x44u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x44u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000B4A0;
    label_0000B412: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B412u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000B452;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x45u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B42A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000B42A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B42Au);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000B43D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000B44C;
    label_0000B43D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B43Du);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0000B44A;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B44C;
    label_0000B44A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B44Au);
    lift_store32(cpu->esi, cpu->edx);
    label_0000B44C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B44Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000B452: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B452u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x44u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x44u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x45u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B47A;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000B47A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B47Au);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000B48D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_0000B49B;
    label_0000B48D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B48Du);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000B498;
    lift_store32(cpu->edi, cpu->esi);
    goto label_0000B49B;
    label_0000B498: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B498u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_0000B49B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B49Bu);
    lift_store32(cpu->esi, cpu->edx);
    label_0000B49D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B49Du);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_0000B4A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B4A0u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B320;
    label_0000B4AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B4ACu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x44u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B4D0u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x71C71C6u)) goto label_0000B4FE;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    cpu->ecx += 0xDu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B4EAu); lift_push32(cpu, r); sfera_sub_0040AD30(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B4F0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xB4FEu);
    label_0000B4FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B4FEu);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000B525;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    goto label_0000B543;
    label_0000B525: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B525u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B538;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000B546;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_0000B546;
    label_0000B538: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B538u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000B546;
    label_0000B543: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B543u);
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_0000B546: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B546u);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B6E2;
    lift_push32(cpu, cpu->edi);
    label_0000B555: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B555u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000B624;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B587;
    lift_store8(cpu->edx + 0x30u, 1u);
    lift_store8(cpu->esi + 0x30u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x30u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000B6D5;
    label_0000B587: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B587u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000B5C6;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x31u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B5A0;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000B5A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B5A0u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000B5B3;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000B5C1;
    label_0000B5B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B5B3u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_0000B5BE;
    lift_store32(cpu->esi, cpu->edx);
    goto label_0000B5C1;
    label_0000B5BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B5BEu);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_0000B5C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B5C1u);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000B5C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B5C6u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x30u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x30u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x31u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B5EE;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000B5EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B5EEu);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000B607;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B6D2;
    label_0000B607: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B607u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0000B61A;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B6D2;
    label_0000B61A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B61Au);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B6D2;
    label_0000B624: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B624u);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B647;
    lift_store8(cpu->edx + 0x30u, 1u);
    lift_store8(cpu->esi + 0x30u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x30u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_0000B6D5;
    label_0000B647: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B647u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000B687;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x31u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B65F;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000B65F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B65Fu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000B672;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000B681;
    label_0000B672: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B672u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0000B67F;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000B681;
    label_0000B67F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B67Fu);
    lift_store32(cpu->esi, cpu->edx);
    label_0000B681: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B681u);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0000B687: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B687u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x30u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x30u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x31u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B6AF;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000B6AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B6AFu);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000B6C2;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_0000B6D0;
    label_0000B6C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B6C2u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000B6CD;
    lift_store32(cpu->edi, cpu->esi);
    goto label_0000B6D0;
    label_0000B6CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B6CDu);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_0000B6D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B6D0u);
    lift_store32(cpu->esi, cpu->edx);
    label_0000B6D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B6D2u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_0000B6D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B6D5u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B555;
    cpu->edi = lift_pop32(cpu);
    label_0000B6E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B6E2u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x30u, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B700u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0000B752;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0000B712: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B712u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebx)) goto label_0000B71D;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_0000B712;
    label_0000B71D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B71Du);
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0000B752;
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_0000B73D;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x1Cu)) != (uint32_t)(cpu->eax)) goto label_0000B73D;
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x1Cu, cpu->edx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000B73D;
    lift_store8(cpu->ecx + 8u, 0u);
    label_0000B73D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B73Du);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ecx + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B74Bu); lift_push32(cpu, r); sfera_sub_0040A680(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000B752: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B752u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B760u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000B790;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x20u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->ebx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(3u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B781u); lift_push32(cpu, r); sfera_sub_0040A6F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 8u));
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0x20u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000B790: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B790u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B796u); lift_push32(cpu, r); sfera_sub_0040A6F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B7A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B7A0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B7B6u); lift_push32(cpu, r); sfera_sub_004097F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B7D0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->ecx;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B7E8u); lift_push32(cpu, r); sfera_sub_0040A270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B7FCu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u));
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B810u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B82Cu); lift_push32(cpu, r); sfera_sub_00403620(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B842u); lift_push32(cpu, r); sfera_sub_00409F90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B850u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B8A3;
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0000B890: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B890u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0000B89A;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_0000B89E;
    label_0000B89A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B89Au);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_0000B89E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B89Eu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B890;
    label_0000B8A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B8A3u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000B8AF;
    cpu->eax = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xCu))) goto label_0000B928;
    label_0000B8AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B8AFu);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x30u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B8DAu); lift_push32(cpu, r); sfera_sub_00406610(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B8E8u); lift_push32(cpu, r); sfera_sub_0040A310(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    lift_store8(cpu->esp + 0x2Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_0000B910;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B907u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B90Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000B910: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B910u);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
    label_0000B928: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B928u);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B940u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B98F;
    label_0000B953: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B953u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B95Eu); lift_push32(cpu, r); sfera_sub_0040B940(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000B972;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B96Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000B972: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B972u);
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B985u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B953;
    label_0000B98F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B98Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040B9A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40B9A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B9EF;
    label_0000B9B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B9B3u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B9BEu); lift_push32(cpu, r); sfera_sub_0040B9A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000B9D2;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B9CFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000B9D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B9D2u);
    lift_store32(cpu->esi + 0x24u, 0xFu);
    lift_store32(cpu->esi + 0x20u, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x10u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40B9E5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000B9B3;
    label_0000B9EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40B9EFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040BA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40BA00u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->edi = cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi + 0x45u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BA76;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->ebx + 0xFu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000BA20: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BA20u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BA2Du); lift_push32(cpu, r); sfera_sub_0040BA00(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x3Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BA41;
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BA3Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BA41: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BA41u);
    lift_store32(cpu->esi + 0x3Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    lift_store8(cpu->esi + 0x28u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) < (uint32_t)(0x10u)) goto label_0000BA5C;
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BA59u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BA5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BA5Cu);
    lift_store32(cpu->esi + 0x20u, cpu->ebp);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BA6Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x45u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BA20;
    cpu->ebp = lift_pop32(cpu);
    label_0000BA76: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BA76u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040BA80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40BA80u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    cpu->ebx = 0u;
    cpu->edi = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x31u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BB25;
    label_0000BAB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BAB6u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BAC3u); lift_push32(cpu, r); sfera_sub_0040BA80(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi);
    cpu->esi = (uint32_t)(cpu->ebp + 0xCu);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) == (uint32_t)(cpu->ebx)) goto label_0000BAF0;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BAE4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BAEDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BAF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BAF0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BB09;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BB06u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BB09: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BB09u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BB1Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebp = cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x31u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BAB6;
    label_0000BB25: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BB25u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040BB40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40BB40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->ebx = 0u;
    lift_store32(cpu->edi + 4u, cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000BB91;
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0000BB60: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BB60u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BB74;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BB71u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BB74: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BB74u);
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BB87u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000BB60;
    cpu->ebp = lift_pop32(cpu);
    label_0000BB91: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BB91u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040BBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40BBA0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->ebx = 0u;
    lift_store32(cpu->edi + 4u, cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000BC10;
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0000BBC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BBC0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x38u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BBD4;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BBD1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BBD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BBD4u);
    lift_store32(cpu->esi + 0x38u, 0xFu);
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    lift_store8(cpu->esi + 0x24u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_0000BBF3;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BBF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BBF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BBF3u);
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BC06u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000BBC0;
    cpu->ebp = lift_pop32(cpu);
    label_0000BC10: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BC10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040BC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40BC20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->ebx + 4u, 0u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebx))) goto label_0000BCC8;
    label_0000BC5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BC5Du);
    cpu->ebp = lift_load32(cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000BC8F;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BC83u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BC8Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BC8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BC8Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000BCA8;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BCA5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BCA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BCA8u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BCBFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edi = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->ebx))) goto label_0000BC5D;
    label_0000BCC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BCC8u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040BCE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40BCE0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000BCFD;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBCFDu);
    label_0000BCFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BCFDu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BD0Bu); lift_push32(cpu, r); sfera_sub_004022D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2Du)) == (uint8_t)(0u)) goto label_0000BD19;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    goto label_0000BD31;
    label_0000BD19: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD19u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0000BD26;
    cpu->edi = cpu->ecx;
    goto label_0000BD31;
    label_0000BD26: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD26u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_0000BD94;
    label_0000BD31: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD31u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000BD3D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_0000BD3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD3Du);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebp)) goto label_0000BD4A;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_0000BD55;
    label_0000BD4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD4Au);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebp)) goto label_0000BD52;
    lift_store32(cpu->esi, cpu->edi);
    goto label_0000BD55;
    label_0000BD52: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD52u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_0000BD55: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD55u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->ebp)) goto label_0000BD6F;
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) == (uint8_t)(0u)) goto label_0000BD66;
    cpu->eax = cpu->esi;
    goto label_0000BD6D;
    label_0000BD66: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD66u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBD6Du); lift_push32(cpu, r); sfera_sub_00402290(cpu,r); if (cpu->eip != r) return; }
    label_0000BD6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD6Du);
    lift_store32(cpu->ebx, cpu->eax);
    label_0000BD6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD6Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->ebp)) goto label_0000BDEC;
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) == (uint8_t)(0u)) goto label_0000BD88;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000BDEC;
    label_0000BD88: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD88u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BD8Fu); lift_push32(cpu, r); sfera_sub_00402270(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000BDEC;
    label_0000BD94: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BD94u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_0000BDA5;
    cpu->esi = cpu->eax;
    goto label_0000BDBF;
    label_0000BDA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BDA5u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000BDB1;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_0000BDB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BDB1u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_0000BDBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BDBFu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebp)) goto label_0000BDCC;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000BDDA;
    label_0000BDCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BDCCu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebp)) goto label_0000BDD7;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_0000BDDA;
    label_0000BDD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BDD7u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000BDDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BDDAu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x2Cu)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x2Cu)) & 0xFFu);
    lift_store8(cpu->eax + 0x2Cu, cpu->edx & 0xFFu);
    lift_store8(cpu->ebp + 0x2Cu, cpu->ecx & 0xFFu);
    label_0000BDEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BDECu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BEF6;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000BEF3;
    label_0000BE07: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BE07u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BEF3;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0000BE7D;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Cu)) != (uint8_t)(0u)) goto label_0000BE33;
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BE2Cu); lift_push32(cpu, r); sfera_sub_00402EC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000BE33: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BE33u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000BEAF;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BE48;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BEAB;
    label_0000BE48: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BE48u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BE66;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BE5Fu); lift_push32(cpu, r); sfera_sub_00402E60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000BE66: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BE66u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x2Cu)) & 0xFFu);
    lift_store8(cpu->eax + 0x2Cu, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BE7Bu); lift_push32(cpu, r); sfera_sub_00402EC0(cpu,r); if (cpu->eip != r) return; }
    goto label_0000BEF3;
    label_0000BE7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BE7Du);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Cu)) != (uint8_t)(0u)) goto label_0000BE96;
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BE90u); lift_push32(cpu, r); sfera_sub_00402E60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000BE96: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BE96u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000BEAF;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BEC2;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BEC2;
    label_0000BEAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BEABu);
    lift_store8(cpu->eax + 0x2Cu, 0u);
    label_0000BEAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BEAFu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000BE07;
    goto label_0000BEF3;
    label_0000BEC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BEC2u);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000BEDF;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BED9u); lift_push32(cpu, r); sfera_sub_00402EC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000BEDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BEDFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x2Cu)) & 0xFFu);
    lift_store8(cpu->eax + 0x2Cu, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBEF3u); lift_push32(cpu, r); sfera_sub_00402E60(cpu,r); if (cpu->eip != r) return; }
    label_0000BEF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BEF3u);
    lift_store8(cpu->edi + 0x2Cu, cpu->ebx & 0xFFu);
    label_0000BEF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BEF6u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x20u)) < (uint32_t)(0x10u)) goto label_0000BF08;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BF05u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000BF08: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BF08u);
    lift_store32(cpu->ebp + 0x20u, 0xFu);
    lift_store32(cpu->ebp + 0x1Cu, 0u);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->ebp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BF20u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000BF35;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000BF35: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BF35u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040BF50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40BF50u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000BF6D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xBF6Du);
    label_0000BF6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BF6Du);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BF7Bu); lift_push32(cpu, r); sfera_sub_004022D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2Du)) == (uint8_t)(0u)) goto label_0000BF89;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    goto label_0000BFA1;
    label_0000BF89: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BF89u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0000BF96;
    cpu->edi = cpu->ecx;
    goto label_0000BFA1;
    label_0000BF96: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BF96u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_0000C004;
    label_0000BFA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFA1u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000BFAD;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_0000BFAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFADu);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebp)) goto label_0000BFBA;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_0000BFC5;
    label_0000BFBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFBAu);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebp)) goto label_0000BFC2;
    lift_store32(cpu->esi, cpu->edi);
    goto label_0000BFC5;
    label_0000BFC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFC2u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_0000BFC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFC5u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->ebp)) goto label_0000BFDF;
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) == (uint8_t)(0u)) goto label_0000BFD6;
    cpu->eax = cpu->esi;
    goto label_0000BFDD;
    label_0000BFD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFD6u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xBFDDu); lift_push32(cpu, r); sfera_sub_00402290(cpu,r); if (cpu->eip != r) return; }
    label_0000BFDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFDDu);
    lift_store32(cpu->ebx, cpu->eax);
    label_0000BFDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFDFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->ebp)) goto label_0000C05C;
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) == (uint8_t)(0u)) goto label_0000BFF8;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000C05C;
    label_0000BFF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40BFF8u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40BFFFu); lift_push32(cpu, r); sfera_sub_00402270(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000C05C;
    label_0000C004: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C004u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_0000C015;
    cpu->esi = cpu->eax;
    goto label_0000C02F;
    label_0000C015: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C015u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C021;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_0000C021: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C021u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_0000C02F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C02Fu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebp)) goto label_0000C03C;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000C04A;
    label_0000C03C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C03Cu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebp)) goto label_0000C047;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_0000C04A;
    label_0000C047: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C047u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000C04A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C04Au);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x2Cu)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x2Cu)) & 0xFFu);
    lift_store8(cpu->eax + 0x2Cu, cpu->edx & 0xFFu);
    lift_store8(cpu->ebp + 0x2Cu, cpu->ecx & 0xFFu);
    label_0000C05C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C05Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C166;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000C163;
    label_0000C077: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C077u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C163;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0000C0ED;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Cu)) != (uint8_t)(0u)) goto label_0000C0A3;
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C09Cu); lift_push32(cpu, r); sfera_sub_00402EC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C0A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C0A3u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000C11F;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C0B8;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C11B;
    label_0000C0B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C0B8u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C0D6;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C0CFu); lift_push32(cpu, r); sfera_sub_00402E60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C0D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C0D6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x2Cu)) & 0xFFu);
    lift_store8(cpu->eax + 0x2Cu, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C0EBu); lift_push32(cpu, r); sfera_sub_00402EC0(cpu,r); if (cpu->eip != r) return; }
    goto label_0000C163;
    label_0000C0ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C0EDu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Cu)) != (uint8_t)(0u)) goto label_0000C106;
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C100u); lift_push32(cpu, r); sfera_sub_00402E60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C106: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C106u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000C11F;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C132;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C132;
    label_0000C11B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C11Bu);
    lift_store8(cpu->eax + 0x2Cu, 0u);
    label_0000C11F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C11Fu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000C077;
    goto label_0000C163;
    label_0000C132: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C132u);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Cu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C14F;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x2Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C149u); lift_push32(cpu, r); sfera_sub_00402EC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C14F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C14Fu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x2Cu)) & 0xFFu);
    lift_store8(cpu->eax + 0x2Cu, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x2Cu, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x2Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC163u); lift_push32(cpu, r); sfera_sub_00402E60(cpu,r); if (cpu->eip != r) return; }
    label_0000C163: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C163u);
    lift_store8(cpu->edi + 0x2Cu, cpu->ebx & 0xFFu);
    label_0000C166: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C166u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x24u)) < (uint32_t)(0x10u)) goto label_0000C178;
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C175u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C178: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C178u);
    lift_store32(cpu->ebp + 0x24u, 0xFu);
    lift_store32(cpu->ebp + 0x20u, 0u);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->ebp + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C190u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000C1A5;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000C1A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C1A5u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C1C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C1C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000C1DE;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xC1DEu);
    label_0000C1DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C1DEu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C1E9u); lift_push32(cpu, r); sfera_sub_00402360(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x45u)) == (uint8_t)(0u)) goto label_0000C1F6;
    cpu->ebp = lift_load32(cpu->edi + 8u);
    goto label_0000C20E;
    label_0000C1F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C1F6u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) == (uint8_t)(0u)) goto label_0000C203;
    cpu->ebp = cpu->ecx;
    goto label_0000C20E;
    label_0000C203: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C203u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edi)) goto label_0000C271;
    label_0000C20E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C20Eu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->edi + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C21A;
    lift_store32(cpu->ebp + 4u, cpu->esi);
    label_0000C21A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C21Au);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->edi)) goto label_0000C227;
    lift_store32(cpu->eax + 4u, cpu->ebp);
    goto label_0000C232;
    label_0000C227: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C227u);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->edi)) goto label_0000C22F;
    lift_store32(cpu->esi, cpu->ebp);
    goto label_0000C232;
    label_0000C22F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C22Fu);
    lift_store32(cpu->esi + 8u, cpu->ebp);
    label_0000C232: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C232u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->edi)) goto label_0000C24C;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x45u)) == (uint8_t)(0u)) goto label_0000C243;
    cpu->eax = cpu->esi;
    goto label_0000C24A;
    label_0000C243: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C243u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC24Au); lift_push32(cpu, r); sfera_sub_00402340(cpu,r); if (cpu->eip != r) return; }
    label_0000C24A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C24Au);
    lift_store32(cpu->ebx, cpu->eax);
    label_0000C24C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C24Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->edi)) goto label_0000C2C8;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x45u)) == (uint8_t)(0u)) goto label_0000C265;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000C2C8;
    label_0000C265: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C265u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C26Cu); lift_push32(cpu, r); sfera_sub_00402320(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000C2C8;
    label_0000C271: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C271u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0000C281;
    cpu->esi = cpu->eax;
    goto label_0000C29B;
    label_0000C281: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C281u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C28D;
    lift_store32(cpu->ebp + 4u, cpu->esi);
    label_0000C28D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C28Du);
    lift_store32(cpu->esi, cpu->ebp);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_0000C29B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C29Bu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->edi)) goto label_0000C2A8;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000C2B6;
    label_0000C2A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C2A8u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edi)) goto label_0000C2B3;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_0000C2B6;
    label_0000C2B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C2B3u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000C2B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C2B6u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x44u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x44u)) & 0xFFu);
    lift_store8(cpu->eax + 0x44u, cpu->edx & 0xFFu);
    lift_store8(cpu->edi + 0x44u, cpu->ecx & 0xFFu);
    label_0000C2C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C2C8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->edi + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C3D2;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000C3CF;
    label_0000C2E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C2E3u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C3CF;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->eax)) goto label_0000C359;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x44u)) != (uint8_t)(0u)) goto label_0000C30F;
    lift_store8(cpu->eax + 0x44u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x44u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C308u); lift_push32(cpu, r); sfera_sub_00402F10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C30F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C30Fu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) != (uint8_t)(0u)) goto label_0000C38B;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C324;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C387;
    label_0000C324: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C324u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C342;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x44u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x44u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C33Bu); lift_push32(cpu, r); sfera_sub_00402F60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C342: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C342u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x44u)) & 0xFFu);
    lift_store8(cpu->eax + 0x44u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x44u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x44u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C357u); lift_push32(cpu, r); sfera_sub_00402F10(cpu,r); if (cpu->eip != r) return; }
    goto label_0000C3CF;
    label_0000C359: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C359u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x44u)) != (uint8_t)(0u)) goto label_0000C372;
    lift_store8(cpu->eax + 0x44u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x44u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C36Cu); lift_push32(cpu, r); sfera_sub_00402F60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C372: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C372u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) != (uint8_t)(0u)) goto label_0000C38B;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C39E;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C39E;
    label_0000C387: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C387u);
    lift_store8(cpu->eax + 0x44u, 0u);
    label_0000C38B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C38Bu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebp = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000C2E3;
    goto label_0000C3CF;
    label_0000C39E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C39Eu);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x44u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C3BB;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x44u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x44u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C3B5u); lift_push32(cpu, r); sfera_sub_00402F10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_0000C3BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C3BBu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x44u)) & 0xFFu);
    lift_store8(cpu->eax + 0x44u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x44u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x44u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC3CFu); lift_push32(cpu, r); sfera_sub_00402F60(cpu,r); if (cpu->eip != r) return; }
    label_0000C3CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C3CFu);
    lift_store8(cpu->ebp + 0x44u, cpu->ebx & 0xFFu);
    label_0000C3D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C3D2u);
    cpu->ebp = 0x10u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x3Cu)) < (uint32_t)(cpu->ebp)) goto label_0000C3E8;
    cpu->ecx = lift_load32(cpu->edi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C3E5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C3E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C3E8u);
    cpu->esi = 0u;
    cpu->ebx = 0xFu;
    lift_store32(cpu->edi + 0x3Cu, cpu->ebx);
    lift_store32(cpu->edi + 0x38u, cpu->esi);
    lift_store8(cpu->edi + 0x28u, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x20u)) < (uint32_t)(cpu->ebp)) goto label_0000C40A;
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C407u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C40A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C40Au);
    lift_store32(cpu->edi + 0x20u, cpu->ebx);
    lift_store32(cpu->edi + 0x1Cu, cpu->esi);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->edi + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C41Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0000C42E;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000C42E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C42Eu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C440u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) == (uint8_t)(0u)) goto label_0000C482;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xC482u);
    label_0000C482: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C482u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C48Du); lift_push32(cpu, r); sfera_sub_00402480(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x31u)) == (uint8_t)(0u)) goto label_0000C49B;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    goto label_0000C4B3;
    label_0000C49B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C49Bu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) == (uint8_t)(0u)) goto label_0000C4A8;
    cpu->edi = cpu->ecx;
    goto label_0000C4B3;
    label_0000C4A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4A8u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_0000C516;
    label_0000C4B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4B3u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C4BF;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_0000C4BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4BFu);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebp)) goto label_0000C4CC;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_0000C4D7;
    label_0000C4CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4CCu);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebp)) goto label_0000C4D4;
    lift_store32(cpu->esi, cpu->edi);
    goto label_0000C4D7;
    label_0000C4D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4D4u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_0000C4D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4D7u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->ebp)) goto label_0000C4F1;
    if ((uint8_t)(lift_load8(cpu->edi + 0x31u)) == (uint8_t)(0u)) goto label_0000C4E8;
    cpu->eax = cpu->esi;
    goto label_0000C4EF;
    label_0000C4E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4E8u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC4EFu); lift_push32(cpu, r); sfera_sub_00402460(cpu,r); if (cpu->eip != r) return; }
    label_0000C4EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4EFu);
    lift_store32(cpu->ebx, cpu->eax);
    label_0000C4F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C4F1u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->ebp)) goto label_0000C56E;
    if ((uint8_t)(lift_load8(cpu->edi + 0x31u)) == (uint8_t)(0u)) goto label_0000C50A;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000C56E;
    label_0000C50A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C50Au);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C511u); lift_push32(cpu, r); sfera_sub_00402440(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000C56E;
    label_0000C516: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C516u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_0000C527;
    cpu->esi = cpu->eax;
    goto label_0000C541;
    label_0000C527: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C527u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000C533;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_0000C533: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C533u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_0000C541: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C541u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebp)) goto label_0000C54E;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000C55C;
    label_0000C54E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C54Eu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebp)) goto label_0000C559;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_0000C55C;
    label_0000C559: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C559u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000C55C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C55Cu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x30u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x30u)) & 0xFFu);
    lift_store8(cpu->eax + 0x30u, cpu->edx & 0xFFu);
    lift_store8(cpu->ebp + 0x30u, cpu->ecx & 0xFFu);
    label_0000C56E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C56Eu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C67F;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000C67C;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000C590: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C590u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C67C;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0000C606;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x30u)) != (uint8_t)(0u)) goto label_0000C5BC;
    lift_store8(cpu->eax + 0x30u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C5B5u); lift_push32(cpu, r); sfera_sub_00403070(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000C5BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C5BCu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) != (uint8_t)(0u)) goto label_0000C638;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C5D1;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C634;
    label_0000C5D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C5D1u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C5EF;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x30u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C5E8u); lift_push32(cpu, r); sfera_sub_004030C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000C5EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C5EFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x30u)) & 0xFFu);
    lift_store8(cpu->eax + 0x30u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x30u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x30u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C604u); lift_push32(cpu, r); sfera_sub_00403070(cpu,r); if (cpu->eip != r) return; }
    goto label_0000C67C;
    label_0000C606: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C606u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x30u)) != (uint8_t)(0u)) goto label_0000C61F;
    lift_store8(cpu->eax + 0x30u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C619u); lift_push32(cpu, r); sfera_sub_004030C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000C61F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C61Fu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) != (uint8_t)(0u)) goto label_0000C638;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C64B;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C64B;
    label_0000C634: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C634u);
    lift_store8(cpu->eax + 0x30u, 0u);
    label_0000C638: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C638u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_0000C590;
    goto label_0000C67C;
    label_0000C64B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C64Bu);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x30u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000C668;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x30u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C662u); lift_push32(cpu, r); sfera_sub_00403070(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000C668: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C668u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x30u)) & 0xFFu);
    lift_store8(cpu->eax + 0x30u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x30u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x30u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC67Cu); lift_push32(cpu, r); sfera_sub_004030C0(cpu,r); if (cpu->eip != r) return; }
    label_0000C67C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C67Cu);
    lift_store8(cpu->edi + 0x30u, cpu->ebx & 0xFFu);
    label_0000C67F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C67Fu);
    cpu->esi = (uint32_t)(cpu->ebp + 0xCu);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) == (uint32_t)(cpu->edi)) goto label_0000C6AA;
    cpu->edx = (uint32_t)(cpu->edi + 0x27u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C69Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C6A7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C6AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C6AAu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000C6BB;
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C6B8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C6BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C6BBu);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C6CEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->edi)) goto label_0000C6E0;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000C6E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C6E0u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C700u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000C75D;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) < (uint32_t)(0x10u)) goto label_0000C733;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C730u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C733: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C733u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C748u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000C75D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C75Du);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C770u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000C7E3;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0x38u)) < (uint32_t)(0x10u)) goto label_0000C7A3;
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C7A0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C7A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C7A3u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x38u, 0xFu);
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    lift_store8(cpu->esi + 0x24u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_0000C7C5;
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C7C2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000C7C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C7C5u);
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 8u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C7D8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    cpu->ebx = lift_pop32(cpu);
    label_0000C7E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C7E3u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C7F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000C82A;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C81Au); lift_push32(cpu, r); sfera_sub_0040A470(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C820u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    label_0000C82A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C82Au);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C840u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C874u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000C8EB;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_store16(cpu->esi + 0x28u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ecx);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_0000C8C0;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC8C0u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_0000C8C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C8C0u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000C8EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C8EBu);
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C910u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40C910u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C8D6(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C8D6u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C8DFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C8EBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C910u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40C910u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C920u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C952u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000C9BF;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->ebp + 8u, cpu->ecx);
    lift_store32(cpu->ebp + 0xCu, cpu->ecx);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_0000C994;
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xC994u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_0000C994: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C994u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000C9BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40C9BFu);
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C9E4u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40C9E4u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C9AA(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C9AAu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C9B3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C9BFu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40C9E4u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40C9E4u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040C9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40C9F0u);
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CAEC;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0000CA20: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA20u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000CA82;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CA39;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_0000CA3B;
    label_0000CA39: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA39u);
    cpu->edx = cpu->ebp;
    label_0000CA3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA3Bu);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_0000CA44;
    label_0000CA44: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA44u);
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_0000CA4F;
    cpu->ecx = cpu->edi;
    label_0000CA4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA4Fu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CA57;
    cpu->eax = lift_load32(cpu->eax);
    label_0000CA57: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA57u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CA5Fu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CA7D;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0000CA74;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CACB;
    label_0000CA74: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA74u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_0000CA7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA7Du);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CACB;
    label_0000CA82: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA82u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CA8D;
    cpu->eax = lift_load32(cpu->eax);
    label_0000CA8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA8Du);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_0000CA9A;
    cpu->edx = cpu->edi;
    label_0000CA9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CA9Au);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CAA5;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_0000CAA7;
    label_0000CAA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CAA5u);
    cpu->ecx = cpu->ebp;
    label_0000CAA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CAA7u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CAAFu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CAC8;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0000CABF;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0000CAC6;
    label_0000CABF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CABFu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CAC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CAC6u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_0000CAC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CAC8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CACB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CACBu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000CAD7;
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_0000CADA;
    label_0000CAD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CAD7u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_0000CADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CADAu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x2Du)) == (uint8_t)(0u)) goto label_0000CA20;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000CAEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CAECu);
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000CB32;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000CB25;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    label_0000CB0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CB0Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CB0Fu); lift_push32(cpu, r); sfera_sub_0040ADC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0000CB25: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CB25u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CB2Eu); lift_push32(cpu, r); sfera_sub_00402540(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_0000CB32: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CB32u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ebx = 0x10u;
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_0000CB47;
    cpu->eax = lift_load32(cpu->ebp);
    goto label_0000CB49;
    label_0000CB47: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CB47u);
    cpu->eax = cpu->ebp;
    label_0000CB49: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CB49u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CB56u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000CB70;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    goto label_0000CB0A;
    label_0000CB70: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CB70u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_0000CB81;
    cpu->edx = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CB7Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000CB81: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CB81u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->ebp + 0x14u, 0xFu);
    lift_store32(cpu->ebp + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CB9Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040CBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40CBC0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CC0E;
    cpu->ebp = lift_load32(cpu->edi + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    label_0000CBE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CBE5u);
    cpu->esi = cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0000CBF3;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CBF9;
    label_0000CBF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CBF3u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->eax + 0xCu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    label_0000CBF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CBF9u);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0000CC05;
    cpu->eax = lift_load32(cpu->eax);
    goto label_0000CC08;
    label_0000CC05: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CC05u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_0000CC08: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CC08u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0000CBE5;
    label_0000CC0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CC0Eu);
    cpu->ebp = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0000CC4B;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000CC42;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CC2Fu); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000CC42: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CC42u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CC47u); lift_push32(cpu, r); sfera_sub_00402540(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_0000CC4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CC4Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xCu))) goto label_0000CC79;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CC66u); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000CC79: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CC79u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x24u)) < (uint32_t)(0x10u)) goto label_0000CC8B;
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CC88u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000CC8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CC8Bu);
    lift_store32(cpu->edi + 0x24u, 0xFu);
    lift_store32(cpu->edi + 0x20u, 0u);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->edi + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CCA3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040CCC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40CCC0u);
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebx += 0xCu;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CDBB;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0000CCF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CCF0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000CD51;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CD08;
    cpu->edx = lift_load32(cpu->ebx);
    goto label_0000CD0A;
    label_0000CD08: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD08u);
    cpu->edx = cpu->ebx;
    label_0000CD0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD0Au);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_0000CD13;
    label_0000CD13: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD13u);
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_0000CD1E;
    cpu->ecx = cpu->edi;
    label_0000CD1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD1Eu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CD26;
    cpu->eax = lift_load32(cpu->eax);
    label_0000CD26: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD26u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CD2Eu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CD4C;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0000CD43;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CD99;
    label_0000CD43: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD43u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_0000CD4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD4Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CD99;
    label_0000CD51: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD51u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CD5C;
    cpu->eax = lift_load32(cpu->eax);
    label_0000CD5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD5Cu);
    cpu->esi = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_0000CD69;
    cpu->edx = cpu->edi;
    label_0000CD69: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD69u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CD73;
    cpu->ecx = lift_load32(cpu->ebx);
    goto label_0000CD75;
    label_0000CD73: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD73u);
    cpu->ecx = cpu->ebx;
    label_0000CD75: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD75u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CD7Du); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CD96;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0000CD8D;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0000CD94;
    label_0000CD8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD8Du);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CD94: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD94u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_0000CD96: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD96u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CD99: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CD99u);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000CDA6;
    cpu->ebp = lift_load32(cpu->ebp);
    goto label_0000CDA9;
    label_0000CDA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CDA6u);
    cpu->ebp = lift_load32(cpu->ebp + 8u);
    label_0000CDA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CDA9u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x45u)) == (uint8_t)(0u)) goto label_0000CCF0;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000CDBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CDBBu);
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000CE01;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000CDF4;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    label_0000CDD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CDD9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CDDEu); lift_push32(cpu, r); sfera_sub_0040B260(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0000CDF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CDF4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CDFDu); lift_push32(cpu, r); sfera_sub_00402600(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_0000CE01: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CE01u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CE11;
    cpu->eax = lift_load32(cpu->ebx);
    goto label_0000CE13;
    label_0000CE11: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CE11u);
    cpu->eax = cpu->ebx;
    label_0000CE13: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CE13u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CE20u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000CE3A;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    goto label_0000CDD9;
    label_0000CE3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CE3Au);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += 0xDu;
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CE48u); lift_push32(cpu, r); sfera_sub_0040ACE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CE52u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040CE70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40CE70u);
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebx += 0xCu;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CF6B;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0000CEA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CEA0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000CF01;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CEB8;
    cpu->edx = lift_load32(cpu->ebx);
    goto label_0000CEBA;
    label_0000CEB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CEB8u);
    cpu->edx = cpu->ebx;
    label_0000CEBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CEBAu);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_0000CEC3;
    label_0000CEC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CEC3u);
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_0000CECE;
    cpu->ecx = cpu->edi;
    label_0000CECE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CECEu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CED6;
    cpu->eax = lift_load32(cpu->eax);
    label_0000CED6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CED6u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CEDEu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CEFC;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0000CEF3;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CF49;
    label_0000CEF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CEF3u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_0000CEFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CEFCu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_0000CF49;
    label_0000CF01: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF01u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CF0C;
    cpu->eax = lift_load32(cpu->eax);
    label_0000CF0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF0Cu);
    cpu->esi = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_0000CF19;
    cpu->edx = cpu->edi;
    label_0000CF19: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF19u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) < (uint32_t)(0x10u)) goto label_0000CF23;
    cpu->ecx = lift_load32(cpu->ebx);
    goto label_0000CF25;
    label_0000CF23: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF23u);
    cpu->ecx = cpu->ebx;
    label_0000CF25: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF25u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CF2Du); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000CF46;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_0000CF3D;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0000CF44;
    label_0000CF3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF3Du);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CF44: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF44u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_0000CF46: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF46u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_0000CF49: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF49u);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000CF56;
    cpu->ebp = lift_load32(cpu->ebp);
    goto label_0000CF59;
    label_0000CF56: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF56u);
    cpu->ebp = lift_load32(cpu->ebp + 8u);
    label_0000CF59: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF59u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x31u)) == (uint8_t)(0u)) goto label_0000CEA0;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_0000CF6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF6Bu);
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000CFB1;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000CFA4;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    label_0000CF89: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CF89u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CF8Eu); lift_push32(cpu, r); sfera_sub_0040B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0000CFA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CFA4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CFADu); lift_push32(cpu, r); sfera_sub_004026C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_0000CFB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CFB1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000CFC1;
    cpu->eax = lift_load32(cpu->ebx);
    goto label_0000CFC3;
    label_0000CFC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CFC1u);
    cpu->eax = cpu->ebx;
    label_0000CFC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CFC3u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CFD0u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000CFEA;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    goto label_0000CF89;
    label_0000CFEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40CFEAu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += 0xDu;
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40CFF8u); lift_push32(cpu, r); sfera_sub_0040AD30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D002u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D020u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(cpu->ecx + 0x14u);
    cpu->ebp = (uint32_t)(cpu->ebx + 0xFu);
    label_0000D057: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D057u);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFECu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000D0C3;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_0000D0BB;
    lift_store32(cpu->esi + 0x14u, cpu->ebp);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000D0BB;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000D081;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D07Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000D081: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D081u);
    lift_store32(cpu->esi + 0x14u, cpu->ebp);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->edi)) >= (uint32_t)(0x10u)) goto label_0000D0A3;
    cpu->eax = lift_load32(cpu->edi + 0xFFFFFFFCu);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40D098u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40D09Eu);
    cpu->esp += 0xCu;
    goto label_0000D0AB;
    label_0000D0A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D0A3u);
    cpu->ecx = lift_load32(cpu->edi + 0xFFFFFFECu);
    lift_store32(cpu->esi, cpu->ecx);
    lift_store32(cpu->edi + 0xFFFFFFECu, cpu->ebx);
    label_0000D0AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D0ABu);
    cpu->edx = lift_load32(cpu->edi + 0xFFFFFFFCu);
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->edi + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->edi, cpu->ebx);
    label_0000D0BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D0BBu);
    cpu->esi += 0x1Cu;
    cpu->edi += 0x1Cu;
    goto label_0000D057;
    label_0000D0C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D0C3u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D250u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_0000D328;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx -= lift_load32(cpu->esi + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->eax)) goto label_0000D328;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000D2A3;
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    cpu->ecx -= lift_load32(cpu->esi + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    goto label_0000D2A7;
    label_0000D2A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D2A3u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0000D2A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D2A7u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebx) * 8u));
    cpu->ecx -= cpu->ebx;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D2C7u); lift_push32(cpu, r); sfera_sub_0040A270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFE4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D2DBu); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + (uint64_t)(0xFFFFFFE4u) + (uint64_t)(0u));
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_0000D320;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx -= lift_load32(cpu->esi + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0000D31C;
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->ecx -= cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000D31C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D31Cu);
    lift_store8(cpu->esi + 8u, 0u);
    label_0000D320: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D320u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000D328: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D328u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D330u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_0000D37D;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000D353;
    cpu->eax = lift_load32(cpu->eax);
    label_0000D353: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D353u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D362u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0000D37C;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D372u); lift_push32(cpu, r); sfera_sub_00402AF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D37C;
    lift_store8(cpu->esi + 8u, 0u);
    label_0000D37C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D37Cu);
    cpu->edi = lift_pop32(cpu);
    label_0000D37D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D37Du);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D38Bu); lift_push32(cpu, r); sfera_sub_00403F00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D3A2u); lift_push32(cpu, r); sfera_sub_0040A7A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D3B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D3B0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D3BFu); lift_push32(cpu, r); sfera_sub_0040B850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0000D3FB;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D3D8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D3E1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    label_0000D3FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D3FBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D400u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000D44A;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000D44A;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D422u); lift_push32(cpu, r); sfera_sub_0040B940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000D44A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D44Au);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000D4BF;
    cpu->edi = cpu->edi;
    label_0000D450: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D450u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D4A8;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000D480;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000D47A;
    label_0000D470: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D470u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0000D470;
    label_0000D47A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D47Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_0000D4A8;
    label_0000D480: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D480u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000D4A4;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000D490: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D490u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0000D4A4;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0000D490;
    label_0000D4A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D4A4u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0000D4A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D4A8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D4B5u); lift_push32(cpu, r); sfera_sub_0040BCE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0000D450;
    label_0000D4BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D4BFu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D4D0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000D51A;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000D51A;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D4F2u); lift_push32(cpu, r); sfera_sub_0040B9A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000D51A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D51Au);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000D58F;
    cpu->edi = cpu->edi;
    label_0000D520: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D520u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D578;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000D550;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000D54A;
    label_0000D540: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D540u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0000D540;
    label_0000D54A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D54Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_0000D578;
    label_0000D550: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D550u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_0000D574;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000D560: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D560u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0000D574;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_0000D560;
    label_0000D574: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D574u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0000D578: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D578u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D585u); lift_push32(cpu, r); sfera_sub_0040BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0000D520;
    label_0000D58F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D58Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D5A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D5A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000D5EA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000D5EA;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D5C2u); lift_push32(cpu, r); sfera_sub_0040BA00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000D5EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D5EAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000D65F;
    cpu->edi = cpu->edi;
    label_0000D5F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D5F0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D648;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) != (uint8_t)(0u)) goto label_0000D620;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) != (uint8_t)(0u)) goto label_0000D61A;
    label_0000D610: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D610u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) == (uint8_t)(0u)) goto label_0000D610;
    label_0000D61A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D61Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_0000D648;
    label_0000D620: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D620u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) != (uint8_t)(0u)) goto label_0000D644;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000D630: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D630u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0000D644;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) == (uint8_t)(0u)) goto label_0000D630;
    label_0000D644: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D644u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0000D648: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D648u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D655u); lift_push32(cpu, r); sfera_sub_0040C1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0000D5F0;
    label_0000D65F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D65Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D670u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000D6BA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000D6BA;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D692u); lift_push32(cpu, r); sfera_sub_0040BA80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000D6BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D6BAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000D72F;
    cpu->edi = cpu->edi;
    label_0000D6C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D6C0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D718;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) != (uint8_t)(0u)) goto label_0000D6F0;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) != (uint8_t)(0u)) goto label_0000D6EA;
    label_0000D6E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D6E0u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) == (uint8_t)(0u)) goto label_0000D6E0;
    label_0000D6EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D6EAu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_0000D718;
    label_0000D6F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D6F0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) != (uint8_t)(0u)) goto label_0000D714;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000D700: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D700u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0000D714;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) == (uint8_t)(0u)) goto label_0000D700;
    label_0000D714: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D714u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0000D718: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D718u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D725u); lift_push32(cpu, r); sfera_sub_0040C440(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0000D6C0;
    label_0000D72F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D72Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D740u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->ebx = 0u;
    lift_store32(cpu->edi + 4u, cpu->ebx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000D7B1;
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0000D760: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D760u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000D774;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D771u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000D774: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D774u);
    lift_store32(cpu->esi + 0x24u, 0xFu);
    lift_store32(cpu->esi + 0x20u, cpu->ebx);
    lift_store8(cpu->esi + 0x10u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) == (uint32_t)(cpu->ebx)) goto label_0000D7A1;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D795u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D79Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000D7A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D7A1u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D7A7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000D760;
    cpu->ebp = lift_pop32(cpu);
    label_0000D7B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D7B1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D7C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D7C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->edx = lift_load32(cpu->edi + 0x14u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edx)) goto label_0000D7F2;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000D7EF;
    lift_push32(cpu, cpu->ebx);
    label_0000D7E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D7E0u);
    cpu->ebx = lift_load32(cpu->eax);
    lift_store32(cpu->esi, cpu->ebx);
    cpu->eax += 4u;
    cpu->esi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000D7E0;
    cpu->ebx = lift_pop32(cpu);
    label_0000D7EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D7EFu);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    label_0000D7F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D7F2u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D807u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->edi + 0x24u, cpu->esi);
    lift_store32(cpu->edi + 0x20u, cpu->eax);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D820u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40D831u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40D837u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000D850;
    cpu->edx += 0x7FFFFFFFu;
    label_0000D850: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D850u);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000D865;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_0000D865: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D865u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D892;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edx)) goto label_0000D88A;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->edx);
    goto label_0000D89A;
    label_0000D88A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D88Au);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000D89A;
    label_0000D892: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D892u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edx)) goto label_0000D89E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_0000D89A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D89Au);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_0000D89E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D89Eu);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D8ACu); lift_push32(cpu, r); sfera_sub_0040C700(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D8C0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->edi + 8u);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D8D5u); lift_push32(cpu, r); sfera_sub_00403170(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= cpu->ebx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000D8E5;
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->ebx;
    cpu->eax += cpu->ecx;
    label_0000D8E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D8E5u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000D90E;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edi)) goto label_0000D906;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->edx);
    goto label_0000D916;
    label_0000D906: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D906u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000D916;
    label_0000D90E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D90Eu);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edi)) goto label_0000D91A;
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->ecx, cpu->edx);
    label_0000D916: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D916u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_0000D91A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D91Au);
    cpu->ebx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000D943;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->ecx, cpu->ebx);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_store32(cpu->edx + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D937u); lift_push32(cpu, r); sfera_sub_0040A470(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D93Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 8u, (uint64_t)(lift_load32(cpu->esi + 8u)) - 1u);
    label_0000D943: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D943u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D950u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000D9C0;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0x24u)) < (uint32_t)(0x10u)) goto label_0000D983;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D980u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000D983: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D983u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x24u, 0xFu);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store8(cpu->esi + 0x10u, cpu->eax & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) == (uint32_t)(cpu->eax)) goto label_0000D9B0;
    cpu->edx = (uint32_t)(cpu->eax + 0x27u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D9A4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D9ADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000D9B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D9B0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D9B6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    label_0000D9C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40D9C0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040D9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40D9D0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DA01;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40D9F6u); lift_push32(cpu, r); sfera_sub_0040ADC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DA01: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DA01u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000DA4F;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000DA18;
    cpu->eax = lift_load32(cpu->eax);
    label_0000DA18: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DA18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DA27u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000DB6A;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DA43u); lift_push32(cpu, r); sfera_sub_0040ADC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DA4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DA4Fu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0000DA8C;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DA62u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DB6A;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DA80u); lift_push32(cpu, r); sfera_sub_0040ADC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DA8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DA8Cu);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DA98u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DAEA;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DAADu); lift_push32(cpu, r); sfera_sub_00402540(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DABDu); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DAEA;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DB40;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DADEu); lift_push32(cpu, r); sfera_sub_0040ADC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DAEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DAEAu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DAFAu); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DB6A;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DB0Fu); lift_push32(cpu, r); sfera_sub_004022D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000DB30;
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DB24u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DB6A;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_0000DB30: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DB30u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DB55;
    label_0000DB40: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DB40u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DB49u); lift_push32(cpu, r); sfera_sub_0040ADC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DB55: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DB55u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DB5Eu); lift_push32(cpu, r); sfera_sub_0040ADC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DB6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DB6Au);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DB79u); lift_push32(cpu, r); sfera_sub_0040C9F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040DB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40DB90u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DBBC;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DBB2u); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DBBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DBBCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000DBEE;
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_0000DCCD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DBE2u); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DBEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DBEEu);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_0000DC1B;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xCu))) goto label_0000DCCD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DC0Fu); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DC1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DC1Bu);
    cpu->ebp = lift_load32(cpu->edi + 0xCu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0xCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0000DC76;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DC30u); lift_push32(cpu, r); sfera_sub_00402540(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0000DC73;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DC5E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DC52u); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DC5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DC5Eu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DC67u); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DC73: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DC73u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0xCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0000DC76: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DC76u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0000DCCD;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DC85u); lift_push32(cpu, r); sfera_sub_004022D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000DC93;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_0000DCCD;
    label_0000DC93: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DC93u);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DCB8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DCACu); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DCB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DCB8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DCC1u); lift_push32(cpu, r); sfera_sub_0040B010(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DCCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DCCDu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DCDCu); lift_push32(cpu, r); sfera_sub_0040CBC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040DCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40DCF0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DD21;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DD16u); lift_push32(cpu, r); sfera_sub_0040B260(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DD21: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DD21u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000DD6F;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000DD38;
    cpu->eax = lift_load32(cpu->eax);
    label_0000DD38: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DD38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DD47u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000DE8A;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DD63u); lift_push32(cpu, r); sfera_sub_0040B260(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DD6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DD6Fu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0000DDAC;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DD82u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DE8A;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DDA0u); lift_push32(cpu, r); sfera_sub_0040B260(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DDAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DDACu);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DDB8u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DE0A;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DDCDu); lift_push32(cpu, r); sfera_sub_00402600(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DDDDu); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DE0A;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DE60;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DDFEu); lift_push32(cpu, r); sfera_sub_0040B260(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DE0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DE0Au);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DE1Au); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DE8A;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DE2Fu); lift_push32(cpu, r); sfera_sub_00402360(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000DE50;
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DE44u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DE8A;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_0000DE50: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DE50u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000DE75;
    label_0000DE60: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DE60u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DE69u); lift_push32(cpu, r); sfera_sub_0040B260(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DE75: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DE75u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DE7Eu); lift_push32(cpu, r); sfera_sub_0040B260(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DE8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DE8Au);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DE99u); lift_push32(cpu, r); sfera_sub_0040CCC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040DEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40DEB0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000DEE1;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DED6u); lift_push32(cpu, r); sfera_sub_0040B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DEE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DEE1u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000DF2F;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000DEF8;
    cpu->eax = lift_load32(cpu->eax);
    label_0000DEF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DEF8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DF07u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E04A;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DF23u); lift_push32(cpu, r); sfera_sub_0040B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DF2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DF2Fu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0000DF6C;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DF42u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000E04A;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DF60u); lift_push32(cpu, r); sfera_sub_0040B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DF6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DF6Cu);
    cpu->ecx += 0xCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DF78u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DFCA;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DF8Du); lift_push32(cpu, r); sfera_sub_004026C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DF9Du); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000DFCA;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E020;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DFBEu); lift_push32(cpu, r); sfera_sub_0040B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000DFCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40DFCAu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DFDAu); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000E04A;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40DFEFu); lift_push32(cpu, r); sfera_sub_00402480(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000E010;
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E004u); lift_push32(cpu, r); sfera_sub_00403E60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0000E04A;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_0000E010: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E010u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000E035;
    label_0000E020: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E020u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E029u); lift_push32(cpu, r); sfera_sub_0040B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000E035: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E035u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E03Eu); lift_push32(cpu, r); sfera_sub_0040B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000E04A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E04Au);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E059u); lift_push32(cpu, r); sfera_sub_0040CE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E070u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E08B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E08B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E08Bu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E09F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E09F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E09Fu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E118;
    cpu->eax = 0u;
    label_0000E0B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E0B4u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E0C4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E0B4;
    label_0000E0C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E0C4u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E0F2;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E0EF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E0E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E0E0u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E0E0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E0EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E0EFu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E0F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E0F2u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E103u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E117u); lift_push32(cpu, r); sfera_sub_0040FAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E118: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E118u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E120u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E13B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E13B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E13Bu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E14F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E14F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E14Fu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E1C8;
    cpu->eax = 0u;
    label_0000E164: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E164u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E174;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E164;
    label_0000E174: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E174u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E1A2;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E19F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E190: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E190u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E190;
    cpu->ebp = lift_pop32(cpu);
    label_0000E19F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E19Fu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E1A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E1A2u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E1B3u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E1C7u); lift_push32(cpu, r); sfera_sub_0040FB10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E1C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E1C8u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E1D0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E1EB;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E1EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E1EBu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E1FF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E1FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E1FFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E278;
    cpu->eax = 0u;
    label_0000E214: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E214u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E224;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E214;
    label_0000E224: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E224u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E252;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E24F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E240: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E240u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E240;
    cpu->ebp = lift_pop32(cpu);
    label_0000E24F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E24Fu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E252: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E252u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E263u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E277u); lift_push32(cpu, r); sfera_sub_0040FB60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E278: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E278u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E280u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E29B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E29B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E29Bu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E2AF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E2AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E2AFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E328;
    cpu->eax = 0u;
    label_0000E2C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E2C4u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E2D4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E2C4;
    label_0000E2D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E2D4u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E302;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E2FF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E2F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E2F0u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E2F0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E2FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E2FFu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E302: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E302u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E313u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E327u); lift_push32(cpu, r); sfera_sub_0040FBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E328: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E328u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E330u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E34B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E34B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E34Bu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E35F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E35F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E35Fu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E3D8;
    cpu->eax = 0u;
    label_0000E374: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E374u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E384;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E374;
    label_0000E384: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E384u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E3B2;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E3AF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E3A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E3A0u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E3A0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E3AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E3AFu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E3B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E3B2u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E3C3u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E3D7u); lift_push32(cpu, r); sfera_sub_0040FC00(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E3D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E3D8u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E3E0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E3FB;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E3FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E3FBu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E40F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E40F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E40Fu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E488;
    cpu->eax = 0u;
    label_0000E424: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E424u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E434;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E424;
    label_0000E434: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E434u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E462;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E45F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E450: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E450u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E450;
    cpu->ebp = lift_pop32(cpu);
    label_0000E45F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E45Fu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E462: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E462u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E473u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E487u); lift_push32(cpu, r); sfera_sub_0040FC50(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E488: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E488u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E490u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E4AB;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E4AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E4ABu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E4BF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E4BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E4BFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E538;
    cpu->eax = 0u;
    label_0000E4D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E4D4u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E4E4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E4D4;
    label_0000E4E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E4E4u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E512;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E50F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E500: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E500u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E500;
    cpu->ebp = lift_pop32(cpu);
    label_0000E50F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E50Fu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E512: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E512u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E523u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E537u); lift_push32(cpu, r); sfera_sub_0040FCA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E538: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E538u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E540u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E55B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E55B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E55Bu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E56F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E56F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E56Fu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E5E8;
    cpu->eax = 0u;
    label_0000E584: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E584u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E594;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E584;
    label_0000E594: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E594u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E5C2;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E5BF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E5B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E5B0u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E5B0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E5BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E5BFu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E5C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E5C2u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E5D3u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E5E7u); lift_push32(cpu, r); sfera_sub_0040FCF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E5E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E5E8u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E5F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E5F0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x28u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0000E60B;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E60B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E60Bu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0000E61F;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0000E61F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E61Fu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0000E698;
    cpu->eax = 0u;
    label_0000E634: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E634u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(0x1FFFFFFFu)) goto label_0000E644;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(3u)) goto label_0000E634;
    label_0000E644: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E644u);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->edx)) goto label_0000E672;
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edx)) goto label_0000E66F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E660: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E660u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->eax += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000E660;
    cpu->ebp = lift_pop32(cpu);
    label_0000E66F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E66Fu);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    label_0000E672: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E672u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E683u); lift_push32(cpu, r); sfera_sub_00408D90(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E697u); lift_push32(cpu, r); sfera_sub_0040FD40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_0000E698: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E698u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E6A0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E6B5u); lift_push32(cpu, r); sfera_sub_0040C840(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E6C2u); lift_push32(cpu, r); sfera_sub_00409AC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E860u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E873u); lift_push32(cpu, r); sfera_sub_0040B940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    lift_store8(cpu->edi + 8u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E890u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E8A3u); lift_push32(cpu, r); sfera_sub_0040B9A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    lift_store8(cpu->edi + 8u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E8C0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E8D3u); lift_push32(cpu, r); sfera_sub_0040BA00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    lift_store8(cpu->edi + 8u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E8F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E8F0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E903u); lift_push32(cpu, r); sfera_sub_0040BA80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    lift_store8(cpu->edi + 8u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E920u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_store32(cpu->esi + 8u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000E953;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0000E940: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E940u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E948u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000E940;
    cpu->edi = lift_pop32(cpu);
    label_0000E953: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E953u);
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E95Cu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040E960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40E960u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000E99E;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->eax)) goto label_0000E99E;
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E983u); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40E98Cu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000E99E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E99Eu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000EA92;
    lift_push32(cpu, cpu->ebp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000E9B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E9B0u);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ebp = 0u;
    ++cpu->edx;
    cpu->ebx = 0x811C9DC5u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0000E9F0;
    (void)cpu;
    label_0000E9D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E9D0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_0000E9DB;
    cpu->eax = lift_load32(cpu->esi + 8u);
    goto label_0000E9DE;
    label_0000E9DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E9DBu);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    label_0000E9DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E9DEu);
    cpu->eax = (int8_t)(lift_load8(cpu->eax + cpu->ebp));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1000193u);
    cpu->ebp += cpu->edx;
    cpu->ebx ^= cpu->eax;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->ecx)) goto label_0000E9D0;
    label_0000E9F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40E9F0u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->ebx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EA09;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->ebx -= cpu->ecx;
    cpu->eax += cpu->ebx;
    label_0000EA09: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EA09u);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000EA32;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->esi)) goto label_0000EA2A;
    cpu->ebx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx, cpu->ebx);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    cpu->ebx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->ebx);
    goto label_0000EA3A;
    label_0000EA2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EA2Au);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000EA3A;
    label_0000EA32: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EA32u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->esi)) goto label_0000EA3A;
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->ecx, cpu->eax);
    label_0000EA3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EA3Au);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->edx + 4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->edx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000EA81;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_0000EA63;
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EA60u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000EA63: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EA63u);
    lift_store32(cpu->esi + 0x1Cu, 0xFu);
    lift_store32(cpu->esi + 0x18u, 0u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EA7Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebx + 4u, (uint64_t)(lift_load32(cpu->ebx + 4u)) - 1u);
    label_0000EA81: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EA81u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000E9B0;
    cpu->ebp = lift_pop32(cpu);
    label_0000EA92: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EA92u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EAA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EAA0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000EADA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000EADA;
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EAC0u); lift_push32(cpu, r); sfera_sub_0040A060(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EAC9u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000EADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EADAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000EAFD;
    cpu->edi = cpu->edi;
    label_0000EAE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EAE0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EAF3u); lift_push32(cpu, r); sfera_sub_0040AB90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000EAE0;
    label_0000EAFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EAFDu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EB10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000EB3E;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000EB3E;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EB2Eu); lift_push32(cpu, r); sfera_sub_0040E920(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000EB3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EB3Eu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000EB5F;
    label_0000EB42: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EB42u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EB55u); lift_push32(cpu, r); sfera_sub_00407BD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0000EB42;
    label_0000EB5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EB5Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EB70u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000EBAA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000EBAA;
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EB90u); lift_push32(cpu, r); sfera_sub_0040BB40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EB99u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000EBAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EBAAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000EBCD;
    cpu->edi = cpu->edi;
    label_0000EBB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EBB0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EBC3u); lift_push32(cpu, r); sfera_sub_0040D820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000EBB0;
    label_0000EBCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EBCDu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EBE0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000EC1E;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->eax)) goto label_0000EC1E;
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EC03u); lift_push32(cpu, r); sfera_sub_0040BBA0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EC0Cu); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000EC1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EC1Eu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000ED30;
    lift_push32(cpu, cpu->ebp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000EC30: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EC30u);
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 0x18u);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ebp = 0u;
    ++cpu->edx;
    cpu->ebx = 0x811C9DC5u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0000EC70;
    (void)cpu;
    label_0000EC50: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EC50u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_0000EC5B;
    cpu->eax = lift_load32(cpu->edi + 8u);
    goto label_0000EC5E;
    label_0000EC5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EC5Bu);
    cpu->eax = (uint32_t)(cpu->edi + 8u);
    label_0000EC5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EC5Eu);
    cpu->eax = (int8_t)(lift_load8(cpu->eax + cpu->ebp));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1000193u);
    cpu->ebp += cpu->edx;
    cpu->ebx ^= cpu->eax;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->ecx)) goto label_0000EC50;
    label_0000EC70: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EC70u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->ebx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EC89;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->ebx -= cpu->ecx;
    cpu->eax += cpu->ebx;
    label_0000EC89: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EC89u);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000ECB2;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edi)) goto label_0000ECAA;
    cpu->ebx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx, cpu->ebx);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    cpu->ebx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->ebx);
    goto label_0000ECBA;
    label_0000ECAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ECAAu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000ECBA;
    label_0000ECB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ECB2u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edi)) goto label_0000ECBA;
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->ecx, cpu->eax);
    label_0000ECBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ECBAu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->edx + 4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->edx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000ED1F;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->edi + 0x38u)) < (uint32_t)(0x10u)) goto label_0000ECE3;
    cpu->edx = lift_load32(cpu->edi + 0x24u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ECE0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000ECE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ECE3u);
    cpu->ebp = 0u;
    lift_store32(cpu->edi + 0x38u, 0xFu);
    lift_store32(cpu->edi + 0x34u, cpu->ebp);
    lift_store8(cpu->edi + 0x24u, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x1Cu)) < (uint32_t)(0x10u)) goto label_0000ED05;
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ED02u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000ED05: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ED05u);
    lift_store32(cpu->edi + 0x1Cu, 0xFu);
    lift_store32(cpu->edi + 0x18u, cpu->ebp);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->edi + 8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ED19u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebx + 4u, (uint64_t)(lift_load32(cpu->ebx + 4u)) - 1u);
    label_0000ED1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ED1Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000EC30;
    cpu->ebp = lift_pop32(cpu);
    label_0000ED30: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ED30u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040ED40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40ED40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000ED7A;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000ED7A;
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ED60u); lift_push32(cpu, r); sfera_sub_00408A50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ED69u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000ED7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ED7Au);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000ED9D;
    cpu->edi = cpu->edi;
    label_0000ED80: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ED80u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40ED93u); lift_push32(cpu, r); sfera_sub_0040A180(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000ED80;
    label_0000ED9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40ED9Du);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EDB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000EDEA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000EDEA;
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EDD0u); lift_push32(cpu, r); sfera_sub_0040BC20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EDD9u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000EDEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EDEAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000EE0D;
    cpu->edi = cpu->edi;
    label_0000EDF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EDF0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EE03u); lift_push32(cpu, r); sfera_sub_0040D8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000EDF0;
    label_0000EE0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EE0Du);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EE20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000EE5A;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000EE5A;
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EE40u); lift_push32(cpu, r); sfera_sub_0040A0C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EE49u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000EE5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EE5Au);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000EE7D;
    cpu->edi = cpu->edi;
    label_0000EE60: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EE60u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EE73u); lift_push32(cpu, r); sfera_sub_0040AC20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000EE60;
    label_0000EE7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EE7Du);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EE90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EE90u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->edx += cpu->eax;
    cpu->esi = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_0000EEC1;
    lift_push32(cpu, cpu->ebx);
    label_0000EEB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EEB0u);
    cpu->ebx = (int8_t)(lift_load8(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->ebx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_0000EEB0;
    cpu->ebx = lift_pop32(cpu);
    label_0000EEC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EEC1u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EED6;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_0000EED6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EED6u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000EEFF;
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->edi)) goto label_0000EEF7;
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->esi);
    goto label_0000EF07;
    label_0000EEF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EEF7u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    goto label_0000EF07;
    label_0000EEFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EEFFu);
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->edi)) goto label_0000EF0B;
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->edx, cpu->eax);
    label_0000EF07: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF07u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0000EF0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF0Bu);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EF19u); lift_push32(cpu, r); sfera_sub_0040D950(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040EF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF20u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40EF32u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF38u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000EF51;
    cpu->edx += 0x7FFFFFFFu;
    label_0000EF51: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF51u);
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x24u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000EF66;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000EF66: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF66u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->esi = lift_load32(cpu->ebp + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->edi = (uint32_t)(cpu->ebp + 4u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000EF94;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000EF94;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->eax);
    label_0000EF88: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF88u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->eax)) goto label_0000EFCA;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_0000EF88;
    label_0000EF94: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EF94u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000EFAF;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EFABu); lift_push32(cpu, r); sfera_sub_004039D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_0000EFAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EFAFu);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000EFFE;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u, cpu->ecx);
    goto label_0000F024;
    label_0000EFCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EFCAu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000EFED;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax);
    lift_store32(cpu->edx, cpu->ebx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40EFE7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    label_0000EFED: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EFEDu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000EFFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40EFFEu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F006;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F024;
    label_0000F006: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F006u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000F024;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F024: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F024u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F02Bu); lift_push32(cpu, r); sfera_sub_0040E070(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F040u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000F070;
    label_0000F060: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F060u);
    cpu->esi = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0000F060;
    label_0000F070: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F070u);
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x24u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F085;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F085: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F085u);
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->esi = lift_load32(cpu->ebx + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F0BF;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F0BF;
    label_0000F0A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F0A5u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F0B5u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000F0F6;
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0000F0A5;
    label_0000F0BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F0BFu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000F0DA;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F0D6u); lift_push32(cpu, r); sfera_sub_00404EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0000F0DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F0DAu);
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ebp))) goto label_0000F12E;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u, cpu->ecx);
    goto label_0000F154;
    label_0000F0F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F0F6u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F103u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000F10B;
    cpu->esi = lift_load32(cpu->esi);
    goto label_0000F0BF;
    label_0000F10B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F10Bu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F11Cu); lift_push32(cpu, r); sfera_sub_00406BA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000F12E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F12Eu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F136;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F154;
    label_0000F136: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F136u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0000F154;
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F154: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F154u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F15Bu); lift_push32(cpu, r); sfera_sub_0040E120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F180u);
    cpu->esp -= 0x10u;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F196u); lift_push32(cpu, r); sfera_sub_00403170(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x24u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F1B0;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    label_0000F1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F1B0u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    cpu->esi = lift_load32(cpu->ebp + 4u);
    cpu->edi = (uint32_t)(cpu->ebp + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F232;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F232;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->ebx = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_0000F1E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F1E2u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F1F3;
    cpu->eax = lift_load32(cpu->eax);
    label_0000F1F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F1F3u);
    cpu->edx = cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->edi)) goto label_0000F1FB;
    cpu->edx = cpu->edi;
    label_0000F1FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F1FBu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F208;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0000F208: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F208u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F210u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0000F224;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->edi)) goto label_0000F224;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000F265;
    label_0000F224: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F224u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0000F1E2;
    label_0000F22A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F22Au);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0000F232: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F232u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000F24D;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F249u); lift_push32(cpu, r); sfera_sub_00403A60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    label_0000F24D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F24Du);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000F2B7;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u, cpu->ecx);
    goto label_0000F2DB;
    label_0000F265: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F265u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F277;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->edx);
    goto label_0000F27B;
    label_0000F277: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F277u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    label_0000F27B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F27Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F288u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000F290;
    cpu->esi = lift_load32(cpu->esi);
    goto label_0000F22A;
    label_0000F290: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F290u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F2A3u); lift_push32(cpu, r); sfera_sub_0040A680(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000F2B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F2B7u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F2BF;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F2DB;
    label_0000F2BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F2BFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_0000F2DB;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F2DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F2DBu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F2E2u); lift_push32(cpu, r); sfera_sub_0040E1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F300u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40F312u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40F318u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000F331;
    cpu->edx += 0x7FFFFFFFu;
    label_0000F331: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F331u);
    cpu->eax = lift_load32(cpu->edi + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x24u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F346;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000F346: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F346u);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->ebp = (uint32_t)(cpu->edi + 4u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F374;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F374;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->eax);
    label_0000F368: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F368u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->eax)) goto label_0000F3B0;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_0000F368;
    label_0000F374: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F374u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000F38F;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F38Bu); lift_push32(cpu, r); sfera_sub_00403A60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_0000F38F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F38Fu);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ebp))) goto label_0000F3D2;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebx) * 8u) + 4u, cpu->edx);
    goto label_0000F3F8;
    label_0000F3B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F3B0u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F3C1u); lift_push32(cpu, r); sfera_sub_0040C700(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000F3D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F3D2u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F3DA;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F3F8;
    label_0000F3DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F3DAu);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000F3F8;
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F3F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F3F8u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F3FFu); lift_push32(cpu, r); sfera_sub_0040E280(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F420u);
    cpu->esp -= 0x10u;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F436u); lift_push32(cpu, r); sfera_sub_00403170(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x24u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F450;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    label_0000F450: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F450u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    cpu->esi = lift_load32(cpu->ebp + 4u);
    cpu->edi = (uint32_t)(cpu->ebp + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F4D2;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F4D2;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->ebx = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_0000F482: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F482u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F493;
    cpu->eax = lift_load32(cpu->eax);
    label_0000F493: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F493u);
    cpu->edx = cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->edi)) goto label_0000F49B;
    cpu->edx = cpu->edi;
    label_0000F49B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F49Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F4A8;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0000F4A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F4A8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F4B0u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0000F4C4;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->edi)) goto label_0000F4C4;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000F505;
    label_0000F4C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F4C4u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0000F482;
    label_0000F4CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F4CAu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0000F4D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F4D2u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000F4ED;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F4E9u); lift_push32(cpu, r); sfera_sub_00403AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    label_0000F4ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F4EDu);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000F557;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u, cpu->ecx);
    goto label_0000F57B;
    label_0000F505: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F505u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F517;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->edx);
    goto label_0000F51B;
    label_0000F517: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F517u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    label_0000F51B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F51Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F528u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000F530;
    cpu->esi = lift_load32(cpu->esi);
    goto label_0000F4CA;
    label_0000F530: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F530u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F543u); lift_push32(cpu, r); sfera_sub_0040C770(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000F557: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F557u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F55F;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F57B;
    label_0000F55F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F55Fu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_0000F57B;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F57B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F57Bu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F582u); lift_push32(cpu, r); sfera_sub_0040E330(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F5A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F5A0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000F5D0;
    label_0000F5C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F5C0u);
    cpu->esi = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0000F5C0;
    label_0000F5D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F5D0u);
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x24u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F5E5;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F5E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F5E5u);
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->esi = lift_load32(cpu->ebx + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F61F;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F61F;
    label_0000F605: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F605u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F615u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000F656;
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0000F605;
    label_0000F61F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F61Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000F63A;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F636u); lift_push32(cpu, r); sfera_sub_00403B80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0000F63A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F63Au);
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ebp))) goto label_0000F68E;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u, cpu->ecx);
    goto label_0000F6B4;
    label_0000F656: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F656u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F663u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000F66B;
    cpu->esi = lift_load32(cpu->esi);
    goto label_0000F61F;
    label_0000F66B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F66Bu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F67Cu); lift_push32(cpu, r); sfera_sub_0040D950(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000F68E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F68Eu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F696;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F6B4;
    label_0000F696: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F696u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0000F6B4;
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F6B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F6B4u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F6BBu); lift_push32(cpu, r); sfera_sub_0040E3E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F6E0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40F6F2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40F6F8u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000F711;
    cpu->edx += 0x7FFFFFFFu;
    label_0000F711: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F711u);
    cpu->eax = lift_load32(cpu->edi + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x24u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F726;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000F726: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F726u);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->ebp = (uint32_t)(cpu->edi + 4u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F754;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F754;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->eax);
    label_0000F748: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F748u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->eax)) goto label_0000F790;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_0000F748;
    label_0000F754: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F754u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000F76F;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F76Bu); lift_push32(cpu, r); sfera_sub_00404EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_0000F76F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F76Fu);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ebp))) goto label_0000F7B2;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebx) * 8u) + 4u, cpu->edx);
    goto label_0000F7D8;
    label_0000F790: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F790u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F7A1u); lift_push32(cpu, r); sfera_sub_00408D20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000F7B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F7B2u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F7BA;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F7D8;
    label_0000F7BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F7BAu);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0000F7D8;
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F7D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F7D8u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F7DFu); lift_push32(cpu, r); sfera_sub_0040E490(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F800u);
    cpu->esp -= 0x10u;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F816u); lift_push32(cpu, r); sfera_sub_00403170(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x24u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F830;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    label_0000F830: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F830u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    cpu->esi = lift_load32(cpu->ebp + 4u);
    cpu->edi = (uint32_t)(cpu->ebp + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 8u));
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F8B2;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F8B2;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->ebx = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_0000F862: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F862u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->esi + 0x18u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F873;
    cpu->eax = lift_load32(cpu->eax);
    label_0000F873: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F873u);
    cpu->edx = cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->edi)) goto label_0000F87B;
    cpu->edx = cpu->edi;
    label_0000F87B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F87Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F888;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0000F888: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F888u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F890u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0000F8A4;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->edi)) goto label_0000F8A4;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000F8E5;
    label_0000F8A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F8A4u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0000F862;
    label_0000F8AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F8AAu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0000F8B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F8B2u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000F8CD;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F8C9u); lift_push32(cpu, r); sfera_sub_00403B80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    label_0000F8CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F8CDu);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u));
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000F937;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u) + 4u, cpu->ecx);
    goto label_0000F95B;
    label_0000F8E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F8E5u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000F8F7;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->edx);
    goto label_0000F8FB;
    label_0000F8F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F8F7u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    label_0000F8FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F8FBu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F908u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000F910;
    cpu->esi = lift_load32(cpu->esi);
    goto label_0000F8AA;
    label_0000F910: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F910u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F923u); lift_push32(cpu, r); sfera_sub_0040C7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000F937: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F937u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000F93F;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000F95B;
    label_0000F93F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F93Fu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_0000F95B;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000F95B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F95Bu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F962u); lift_push32(cpu, r); sfera_sub_0040E540(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040F980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40F980u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000F9B0;
    label_0000F9A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F9A0u);
    cpu->esi = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0000F9A0;
    label_0000F9B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F9B0u);
    cpu->eax = lift_load32(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x24u)), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000F9C5;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F9C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F9C5u);
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->esi = lift_load32(cpu->ebx + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F9FF;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0000F9FF;
    label_0000F9E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F9E5u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40F9F5u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000FA36;
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0000F9E5;
    label_0000F9FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x40F9FFu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000FA1A;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FA16u); lift_push32(cpu, r); sfera_sub_00404F80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0000FA1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FA1Au);
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ebp))) goto label_0000FA6E;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u, cpu->ecx);
    goto label_0000FA94;
    label_0000FA36: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FA36u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FA43u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000FA4B;
    cpu->esi = lift_load32(cpu->esi);
    goto label_0000F9FF;
    label_0000FA4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FA4Bu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FA5Cu); lift_push32(cpu, r); sfera_sub_0040A220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000FA6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FA6Eu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000FA76;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_0000FA94;
    label_0000FA76: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FA76u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0000FA94;
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 4u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000FA94: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FA94u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FA9Bu); lift_push32(cpu, r); sfera_sub_0040E5F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FAC0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FB02;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FAE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FAE0u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FAFDu); lift_push32(cpu, r); sfera_sub_0040EF20(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FAE0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FB02: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FB02u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FB10u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FB52;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FB30: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FB30u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FB4Du); lift_push32(cpu, r); sfera_sub_0040F040(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FB30;
    cpu->ebx = lift_pop32(cpu);
    label_0000FB52: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FB52u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FB60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FB60u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FBA2;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FB80: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FB80u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FB9Du); lift_push32(cpu, r); sfera_sub_0040F180(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FB80;
    cpu->ebx = lift_pop32(cpu);
    label_0000FBA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FBA2u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FBB0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FBF2;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FBD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FBD0u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FBEDu); lift_push32(cpu, r); sfera_sub_0040F300(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FBD0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FBF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FBF2u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FC00u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FC42;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FC20: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FC20u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FC3Du); lift_push32(cpu, r); sfera_sub_0040F420(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FC20;
    cpu->ebx = lift_pop32(cpu);
    label_0000FC42: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FC42u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FC50u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FC92;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FC70: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FC70u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FC8Du); lift_push32(cpu, r); sfera_sub_0040F5A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FC70;
    cpu->ebx = lift_pop32(cpu);
    label_0000FC92: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FC92u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FCA0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FCE2;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FCC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FCC0u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FCDDu); lift_push32(cpu, r); sfera_sub_0040F6E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FCC0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FCE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FCE2u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FCF0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FD32;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FD10: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FD10u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FD2Du); lift_push32(cpu, r); sfera_sub_0040F800(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FD10;
    cpu->ebx = lift_pop32(cpu);
    label_0000FD32: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FD32u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FD40u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(cpu->eax)) goto label_0000FD82;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000FD60: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FD60u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FD7Du); lift_push32(cpu, r); sfera_sub_0040F980(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0000FD60;
    cpu->ebx = lift_pop32(cpu);
    label_0000FD82: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FD82u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FD90u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FDC2u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_0000FE37;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->esi = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->edi, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->edx);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_store32(cpu->ebp + 0xCu, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000FE0C;
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FE06u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    label_0000FE0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FE0Cu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000FE37: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FE37u);
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FE5Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40FE5Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FE22(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FE22u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FE2Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FE37u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FE5Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40FE5Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FE60u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FE92u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_0000FF07;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->esi = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->edi, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->edx);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_store32(cpu->ebp + 0xCu, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0000FEDC;
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FED6u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1Cu));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0000FEDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FEDCu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000FF07: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FF07u);
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FF2Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40FF2Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FEF2(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FEF2u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FEFBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FF07u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FF2Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40FF2Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FF30u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FF62u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_0000FFD9;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0000FFAE;
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 4u);
    cpu->edx += 4u;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xFFAEu); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_0000FFAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FFAEu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000FFD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x40FFD9u);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FFFEu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40FFFEu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040FFC4(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40FFC4u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FFCDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FFD9u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40FFFEu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40FFFEu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410000u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410032u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000100C6;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->esi = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->edi, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->edx);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_store32(cpu->ebp + 0xCu, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0001009B;
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41007Au); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    cpu->ebx += 0x1Cu;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_store8(cpu->ecx, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1009Bu); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_0001009B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41009Bu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000100C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4100C6u);
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4100EBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4100EBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004100B1(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4100B1u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4100BAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4100C6u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4100EBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4100EBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004100F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4100F0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410122u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_000101A5;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->esi = (uint32_t)(cpu->ebx + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebx, cpu->ecx);
    lift_store32(cpu->ebx + 4u, cpu->edx);
    lift_store32(cpu->ebp + 8u, cpu->esi);
    lift_store32(cpu->ebp + 0xCu, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0001017A;
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410166u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x1Cu);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x1Cu, cpu->ecx);
    lift_store32(cpu->edi + 0x20u, cpu->eax);
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    label_0001017A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41017Au);
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000101A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4101A5u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4101CAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4101CAu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410190(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410190u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410199u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4101A5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4101CAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4101CAu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410390u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4103A9u); lift_push32(cpu, r); sfera_sub_0040C920(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x9249248u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000103C3;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x103C3u);
    label_000103C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4103C3u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004103E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4103E0u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4103FBu); lift_push32(cpu, r); sfera_sub_0040C920(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x9249248u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00010415;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x10415u);
    label_00010415: cpu->eip = LIFT_CODE_TOKEN_VA(0x410415u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0041052E(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x41052Eu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410537u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410543u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410543u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410550u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41056Cu); lift_push32(cpu, r); sfera_sub_00404750(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410582u); lift_push32(cpu, r); sfera_sub_0040D400(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410590u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4105ACu); lift_push32(cpu, r); sfera_sub_00403590(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4105C2u); lift_push32(cpu, r); sfera_sub_0040D4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004105D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4105D0u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4105ECu); lift_push32(cpu, r); sfera_sub_00404990(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410602u); lift_push32(cpu, r); sfera_sub_0040D5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410610u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41062Cu); lift_push32(cpu, r); sfera_sub_00404BD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410642u); lift_push32(cpu, r); sfera_sub_0040D670(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410650u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebp + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x18u);
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->ebp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x18u))) goto label_00010683;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_00010670: cpu->eip = LIFT_CODE_TOKEN_VA(0x410670u);
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410678u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->ebp + 0x18u))) goto label_00010670;
    cpu->edi = lift_pop32(cpu);
    label_00010683: cpu->eip = LIFT_CODE_TOKEN_VA(0x410683u);
    lift_push32(cpu, 8u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41068Du); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ebp + 8u, 0u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004106A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4106A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_000106DA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_000106DA;
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4106C0u); lift_push32(cpu, r); sfera_sub_0040D740(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4106C9u); lift_push32(cpu, r); sfera_sub_0040D7C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000106DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4106DAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000106FD;
    cpu->edi = cpu->edi;
    label_000106E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4106E0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4106F3u); lift_push32(cpu, r); sfera_sub_0040EE90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000106E0;
    label_000106FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4106FDu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410710u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41072Cu); lift_push32(cpu, r); sfera_sub_004050B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00010746;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x10746u);
    label_00010746: cpu->eip = LIFT_CODE_TOKEN_VA(0x410746u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410768u); lift_push32(cpu, r); sfera_sub_0040EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410770u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41078Cu); lift_push32(cpu, r); sfera_sub_00406690(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000107A6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x107A6u);
    label_000107A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4107A6u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4107C8u); lift_push32(cpu, r); sfera_sub_0040F040(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004107D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4107D0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4107ECu); lift_push32(cpu, r); sfera_sub_00405120(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00010806;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x10806u);
    label_00010806: cpu->eip = LIFT_CODE_TOKEN_VA(0x410806u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410828u); lift_push32(cpu, r); sfera_sub_0040EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410830u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41084Cu); lift_push32(cpu, r); sfera_sub_00406710(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00010866;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x10866u);
    label_00010866: cpu->eip = LIFT_CODE_TOKEN_VA(0x410866u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410888u); lift_push32(cpu, r); sfera_sub_0040F040(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410890u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4108ACu); lift_push32(cpu, r); sfera_sub_00405190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000108C6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x108C6u);
    label_000108C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4108C6u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4108E8u); lift_push32(cpu, r); sfera_sub_0040F6E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004108F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4108F0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41090Cu); lift_push32(cpu, r); sfera_sub_00406790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0xFFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00010926;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x10926u);
    label_00010926: cpu->eip = LIFT_CODE_TOKEN_VA(0x410926u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410948u); lift_push32(cpu, r); sfera_sub_0040F980(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410950u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410984u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_00010A03;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esi = (uint32_t)(cpu->edi + 0xCu);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    lift_store16(cpu->edi + 0x2Cu, cpu->eax & 0xFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000109D8;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4109D2u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    label_000109D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4109D8u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00010A03: cpu->eip = LIFT_CODE_TOKEN_VA(0x410A03u);
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410A28u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410A28u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004109EE(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4109EEu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4109F7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410A03u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410A28u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410A28u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410A30u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410A64u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_00010AE3;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esi = (uint32_t)(cpu->edi + 0xCu);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    lift_store16(cpu->edi + 0x2Cu, cpu->eax & 0xFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_00010AB8;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410AB2u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1Cu));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00010AB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x410AB8u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00010AE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x410AE3u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410B08u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410B08u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410ACE(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410ACEu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410AD7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410AE3u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410B08u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410B08u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410B10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410B44u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_00010BC5;
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store16(cpu->esi + 0x2Cu, cpu->ebx & 0xFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00010B9A;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 4u);
    cpu->edx += 4u;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x10B9Au); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_00010B9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x410B9Au);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00010BC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x410BC5u);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410BEAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410BEAu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410BB0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410BB0u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410BB9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410BC5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410BEAu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410BEAu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410BF0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x48u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410C24u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_00010CC0;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->esi = (uint32_t)(cpu->edi + 0xCu);
    lift_store32(cpu->edi + 8u, cpu->edx);
    lift_store16(cpu->edi + 0x44u, cpu->ebx & 0xFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_00010C95;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410C76u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    cpu->edx += 0x1Cu;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x10C95u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_00010C95: cpu->eip = LIFT_CODE_TOKEN_VA(0x410C95u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00010CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x410CC0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410CE5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410CE5u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410CAB(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410CABu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410CB4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410CC0u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410CE5u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410CE5u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410CF0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410D24u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_00010DB1;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esi = (uint32_t)(cpu->edi + 0xCu);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    lift_store16(cpu->edi + 0x30u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_00010D86;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410D72u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    lift_store32(cpu->ebx + 0x1Cu, cpu->eax);
    label_00010D86: cpu->eip = LIFT_CODE_TOKEN_VA(0x410D86u);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00010DB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x410DB1u);
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410DD6u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410DD6u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410D9C(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410D9Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410DA5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410DB1u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410DD6u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410DD6u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410DE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410E12u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_00010E98;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->ebx);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00010E6D;
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->edx + 4u, cpu->ebx);
    lift_store32(cpu->edx, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->eax + 8u);
    cpu->edx += 8u;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 2u);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x10E6Du); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_00010E6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x410E6Du);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00010E98: cpu->eip = LIFT_CODE_TOKEN_VA(0x410E98u);
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410EBDu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410EBDu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00410E83(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410E83u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410E8Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410E98u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_store32(cpu->ebp + 8u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x410EBDu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x410EBDu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411060(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00011060;
    label_00010430: cpu->eip = LIFT_CODE_TOKEN_VA(0x410430u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0x9249249u)) goto label_00010473;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x10473u);
    label_00010473: cpu->eip = LIFT_CODE_TOKEN_VA(0x410473u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx -= lift_load32(cpu->esi);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_0001051A;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41049Eu); lift_push32(cpu, r); sfera_sub_00402B40(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4104BAu); lift_push32(cpu, r); sfera_sub_0040D020(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ecx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000104F4;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4104E9u); lift_push32(cpu, r); sfera_sub_00408FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4104F1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000104F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4104F4u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->ecx -= cpu->edi;
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->esi, cpu->eax);
    label_0001051A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41051Au);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00011060: cpu->eip = LIFT_CODE_TOKEN_VA(0x411060u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    cpu->esi -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    cpu->edx = 0x9249249u;
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->esi)) goto label_00011096;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x11096u);
    label_00011096: cpu->eip = LIFT_CODE_TOKEN_VA(0x411096u);
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000110DC;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0x9249249u;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000110C8;
    cpu->eax = 0u;
    goto label_000110CA;
    label_000110C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4110C8u);
    cpu->eax += cpu->edx;
    label_000110CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4110CAu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_000110D0;
    cpu->eax = cpu->esi;
    label_000110D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4110D0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    goto label_00010430;
    label_000110DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4110DCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004110F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4110F0u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41110Cu); lift_push32(cpu, r); sfera_sub_004079E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00011126;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00011120: cpu->eip = LIFT_CODE_TOKEN_VA(0x411120u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00011120;
    label_00011126: cpu->eip = LIFT_CODE_TOKEN_VA(0x411126u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411134u); lift_push32(cpu, r); sfera_sub_0040E960(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411140u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41115Cu); lift_push32(cpu, r); sfera_sub_004076E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00011176;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00011170: cpu->eip = LIFT_CODE_TOKEN_VA(0x411170u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00011170;
    label_00011176: cpu->eip = LIFT_CODE_TOKEN_VA(0x411176u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411184u); lift_push32(cpu, r); sfera_sub_0040EAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411190u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4111ACu); lift_push32(cpu, r); sfera_sub_004077C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_000111C6;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000111C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4111C0u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000111C0;
    label_000111C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4111C6u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4111D4u); lift_push32(cpu, r); sfera_sub_0040EB10(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004111E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4111E0u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4111FCu); lift_push32(cpu, r); sfera_sub_004077C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00011216;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00011210: cpu->eip = LIFT_CODE_TOKEN_VA(0x411210u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00011210;
    label_00011216: cpu->eip = LIFT_CODE_TOKEN_VA(0x411216u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411224u); lift_push32(cpu, r); sfera_sub_0040EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411230u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41124Cu); lift_push32(cpu, r); sfera_sub_004079E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00011266;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00011260: cpu->eip = LIFT_CODE_TOKEN_VA(0x411260u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00011260;
    label_00011266: cpu->eip = LIFT_CODE_TOKEN_VA(0x411266u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411274u); lift_push32(cpu, r); sfera_sub_0040EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411280u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41129Cu); lift_push32(cpu, r); sfera_sub_004077C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_000112B6;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000112B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4112B0u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000112B0;
    label_000112B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4112B6u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4112C4u); lift_push32(cpu, r); sfera_sub_0040ED40(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004112D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4112D0u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4112ECu); lift_push32(cpu, r); sfera_sub_004079E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00011306;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00011300: cpu->eip = LIFT_CODE_TOKEN_VA(0x411300u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00011300;
    label_00011306: cpu->eip = LIFT_CODE_TOKEN_VA(0x411306u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411314u); lift_push32(cpu, r); sfera_sub_0040EDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411320u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41133Cu); lift_push32(cpu, r); sfera_sub_004076E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00011356;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00011350: cpu->eip = LIFT_CODE_TOKEN_VA(0x411350u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00011350;
    label_00011356: cpu->eip = LIFT_CODE_TOKEN_VA(0x411356u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411364u); lift_push32(cpu, r); sfera_sub_0040EE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411370u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4113A6u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0001142B;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4113EAu); lift_push32(cpu, r); sfera_sub_00410770(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00011414;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41140Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411411u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011414: cpu->eip = LIFT_CODE_TOKEN_VA(0x411414u);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
    label_0001142B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41142Bu);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411450u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411486u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00011509;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->esi);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4114C8u); lift_push32(cpu, r); sfera_sub_00410830(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000114F2;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4114E9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4114EFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000114F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4114F2u);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
    label_00011509: cpu->eip = LIFT_CODE_TOKEN_VA(0x411509u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411520u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411557u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000115CE;
    cpu->eax = lift_load32(cpu->edi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x3Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411592u); lift_push32(cpu, r); sfera_sub_00410890(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->esi = lift_load32(cpu->eax);
    lift_store8(cpu->esp + 0x34u, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000115B6;
    cpu->edx = (uint32_t)(cpu->ebx + 0x27u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4115ADu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4115B3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000115B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4115B6u);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 4u, stop_address); return;
    label_000115CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4115CEu);
    cpu->eax = (uint32_t)(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004115F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4115F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411627u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00011695;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x40u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41166Eu); lift_push32(cpu, r); sfera_sub_004108F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store8(cpu->esp + 0x38u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41167Du); lift_push32(cpu, r); sfera_sub_00402D20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_00011695: cpu->eip = LIFT_CODE_TOKEN_VA(0x411695u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004116F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4116F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_0001176F;
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->esi)) goto label_0001176F;
    cpu->esi -= cpu->eax;
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    cpu->esi += cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_00011749;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x11749u); lift_push32(cpu, r); sfera_sub_00411060(cpu,r); if (cpu->eip != r) return; }
    label_00011749: cpu->eip = LIFT_CODE_TOKEN_VA(0x411749u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi) * 8u));
    cpu->eax -= cpu->esi;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000117A8;
    lift_push32(cpu, cpu->eax);
    goto label_00011797;
    label_0001176F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41176Fu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0001177D;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1177Du); lift_push32(cpu, r); sfera_sub_00411060(cpu,r); if (cpu->eip != r) return; }
    label_0001177D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41177Du);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000117A8;
    lift_push32(cpu, cpu->esi);
    label_00011797: cpu->eip = LIFT_CODE_TOKEN_VA(0x411797u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    lift_store8(cpu->ecx, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x117A8u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    label_000117A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4117A8u);
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004117C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4117C0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4117D9u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00011803;
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411801u); lift_push32(cpu, r); sfera_sub_00410710(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax);
    label_00011803: cpu->eip = LIFT_CODE_TOKEN_VA(0x411803u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411820u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411839u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00011872;
    cpu->ecx = lift_load32(cpu->edi);
    lift_x87_push(cpu, 0.0);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41185Fu); lift_push32(cpu, r); sfera_sub_004107D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
    label_00011872: cpu->eip = LIFT_CODE_TOKEN_VA(0x411872u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411890u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4118ACu); lift_push32(cpu, r); sfera_sub_004076E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_000118C6;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000118C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4118C0u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000118C0;
    label_000118C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4118C6u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4118D4u); lift_push32(cpu, r); sfera_sub_004106A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004118E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4118E0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4118EFu); lift_push32(cpu, r); sfera_sub_00411520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0001192B;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411908u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411911u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    label_0001192B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41192Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411930u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41193Fu); lift_push32(cpu, r); sfera_sub_004115F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0001197B;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411958u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411961u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    label_0001197B: cpu->eip = LIFT_CODE_TOKEN_VA(0x41197Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411980u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4119BEu); lift_push32(cpu, r); sfera_sub_00404900(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000119E7;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000119D5;
    cpu->eax = lift_load32(cpu->eax);
    label_000119D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4119D5u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4119E3u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00011A40;
    label_000119E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4119E7u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411A01u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411A15u); lift_push32(cpu, r); sfera_sub_00410950(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411A23u); lift_push32(cpu, r); sfera_sub_0040D9D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011A3B;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411A38u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011A3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x411A3Bu);
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    goto label_00011A43;
    label_00011A40: cpu->eip = LIFT_CODE_TOKEN_VA(0x411A40u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x28u);
    label_00011A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x411A43u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411A70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411AADu); lift_push32(cpu, r); sfera_sub_00404900(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00011AD5;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011AC2;
    cpu->eax = lift_load32(cpu->eax);
    label_00011AC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x411AC2u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411AD1u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00011B39;
    label_00011AD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x411AD5u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x2Cu, 0xFu);
    lift_store32(cpu->esp + 0x28u, 0u);
    lift_store8(cpu->esp + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411AF4u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x44u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411B0Eu); lift_push32(cpu, r); sfera_sub_00410A30(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411B1Cu); lift_push32(cpu, r); sfera_sub_0040D9D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011B34;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411B31u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011B34: cpu->eip = LIFT_CODE_TOKEN_VA(0x411B34u);
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    goto label_00011B3C;
    label_00011B39: cpu->eip = LIFT_CODE_TOKEN_VA(0x411B39u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x28u);
    label_00011B3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x411B3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411B60u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x54u);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = lift_load32(cpu->esp + 0x64u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00011BBB;
    cpu->ecx = lift_load32(cpu->edx);
    label_00011BA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x411BA8u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_00011BB2;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_00011BB6;
    label_00011BB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x411BB2u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_00011BB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x411BB6u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00011BA8;
    label_00011BBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x411BBBu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00011BCB;
    cpu->eax = lift_load32(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xCu))) goto label_00011C66;
    label_00011BCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x411BCBu);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->esp + 0x48u, 0xFu);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    lift_store8(cpu->esp + 0x34u, cpu->ebx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x60u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411C03u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x60u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411C14u); lift_push32(cpu, r); sfera_sub_00410B10(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411C22u); lift_push32(cpu, r); sfera_sub_0040DB90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) < (uint32_t)(cpu->edi)) goto label_00011C3E;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411C3Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011C3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x411C3Eu);
    lift_store32(cpu->esp + 0x2Cu, 0xFu);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store8(cpu->esp + 0x18u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x48u)) < (uint32_t)(cpu->edi)) goto label_00011C61;
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411C5Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011C61: cpu->eip = LIFT_CODE_TOKEN_VA(0x411C61u);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    goto label_00011C69;
    label_00011C66: cpu->eip = LIFT_CODE_TOKEN_VA(0x411C66u);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    label_00011C69: cpu->eip = LIFT_CODE_TOKEN_VA(0x411C69u);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411C90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x5Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x70u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411CD1u); lift_push32(cpu, r); sfera_sub_00404B40(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00011CFE;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011CE8;
    cpu->eax = lift_load32(cpu->eax);
    label_00011CE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x411CE8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411CF6u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00011DC6;
    label_00011CFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x411CFEu);
    cpu->eax = 0xFu;
    lift_store32(cpu->esp + 0x64u, cpu->eax);
    lift_store32(cpu->esp + 0x60u, cpu->ebx);
    lift_store8(cpu->esp + 0x50u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x7Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411D29u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->edi = 0xFu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_store8(cpu->esp + 0x7Cu, 1u);
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    lift_store8(cpu->esp + 0x38u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411D4Du); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x7Cu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411D5Eu); lift_push32(cpu, r); sfera_sub_00410BF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411D6Cu); lift_push32(cpu, r); sfera_sub_0040DCF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x48u)) < (uint32_t)(cpu->esi)) goto label_00011D88;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411D85u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011D88: cpu->eip = LIFT_CODE_TOKEN_VA(0x411D88u);
    lift_store32(cpu->esp + 0x48u, cpu->edi);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    lift_store8(cpu->esp + 0x34u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) < (uint32_t)(cpu->esi)) goto label_00011DA7;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411DA4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011DA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x411DA7u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store8(cpu->esp + 0x18u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x64u)) < (uint32_t)(cpu->esi)) goto label_00011DC6;
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411DC3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011DC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x411DC6u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x68u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411DF0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411E2Eu); lift_push32(cpu, r); sfera_sub_00404D80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00011E5B;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00011E45;
    cpu->eax = lift_load32(cpu->eax);
    label_00011E45: cpu->eip = LIFT_CODE_TOKEN_VA(0x411E45u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411E53u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00011EF4;
    label_00011E5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x411E5Bu);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store32(cpu->esp + 0x38u, 0xFu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411E81u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x54u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411EA2u); lift_push32(cpu, r); sfera_sub_00410CF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411EB0u); lift_push32(cpu, r); sfera_sub_0040DEB0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_store8(cpu->esp + 0x50u, 2u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x40u)) == (uint32_t)(cpu->ebx)) goto label_00011EDB;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411ECEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411ED8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011EDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x411EDBu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(0x10u)) goto label_00011EEF;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411EECu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00011EEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x411EEFu);
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    goto label_00011EF7;
    label_00011EF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x411EF4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x28u);
    label_00011EF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x411EF7u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411F20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411F3Cu); lift_push32(cpu, r); sfera_sub_0040FD90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00011F56;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x11F56u);
    label_00011F56: cpu->eip = LIFT_CODE_TOKEN_VA(0x411F56u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411F78u); lift_push32(cpu, r); sfera_sub_0040F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411F80u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411F9Cu); lift_push32(cpu, r); sfera_sub_0040FE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00011FB6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x11FB6u);
    label_00011FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x411FB6u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411FD8u); lift_push32(cpu, r); sfera_sub_0040F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00411FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411FE0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x411FFCu); lift_push32(cpu, r); sfera_sub_0040FF30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00012016;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x12016u);
    label_00012016: cpu->eip = LIFT_CODE_TOKEN_VA(0x412016u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412038u); lift_push32(cpu, r); sfera_sub_0040F300(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412040u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41205Cu); lift_push32(cpu, r); sfera_sub_00410000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x4924923u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00012076;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x12076u);
    label_00012076: cpu->eip = LIFT_CODE_TOKEN_VA(0x412076u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412098u); lift_push32(cpu, r); sfera_sub_0040F420(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004120A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4120A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4120BCu); lift_push32(cpu, r); sfera_sub_004100F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x71C71C6u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000120D6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x120D6u);
    label_000120D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4120D6u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4120F8u); lift_push32(cpu, r); sfera_sub_0040F800(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412100u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->ebx + 8u)) == (uint8_t)(0u)) goto label_00012149;
    cpu->ecx = lift_load32(cpu->ebx + 0x20u);
    cpu->ecx -= lift_load32(cpu->ebx + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(0x1Fu), 32u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    cpu->esi += cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412131u); lift_push32(cpu, r); sfera_sub_004116F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi) * 8u));
    cpu->ecx -= cpu->esi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0x20u, cpu->eax);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00012149: cpu->eip = LIFT_CODE_TOKEN_VA(0x412149u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412156u); lift_push32(cpu, r); sfera_sub_004116F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412B70u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412B7Fu); lift_push32(cpu, r); sfera_sub_00411DF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00012BBB;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412B98u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412BA1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    label_00012BBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x412BBBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412BC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412C02u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00012C5B;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412C27u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x50u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412C40u); lift_push32(cpu, r); sfera_sub_00411F20(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00012C56;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412C53u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00012C56: cpu->eip = LIFT_CODE_TOKEN_VA(0x412C56u);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    goto label_00012C5E;
    label_00012C5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x412C5Bu);
    cpu->eax = (uint32_t)(cpu->ecx + 0x24u);
    label_00012C5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x412C5Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412C80u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412CC1u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00012D23;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    lift_store8(cpu->esp + 0x1Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412CE9u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x4Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412D08u); lift_push32(cpu, r); sfera_sub_00411F80(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00012D1E;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412D1Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00012D1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x412D1Eu);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    goto label_00012D26;
    label_00012D23: cpu->eip = LIFT_CODE_TOKEN_VA(0x412D23u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x24u);
    label_00012D26: cpu->eip = LIFT_CODE_TOKEN_VA(0x412D26u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412D50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412D92u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00012E31;
    cpu->edi = lift_load32(cpu->edi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x4Cu, 0xFu);
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    lift_store8(cpu->esp + 0x38u, cpu->ebx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412DD9u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x68u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412DEFu); lift_push32(cpu, r); sfera_sub_00411FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->edi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) < (uint32_t)(cpu->edi)) goto label_00012E09;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412E06u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00012E09: cpu->eip = LIFT_CODE_TOKEN_VA(0x412E09u);
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x4Cu)) < (uint32_t)(cpu->edi)) goto label_00012E2C;
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412E29u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00012E2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x412E2Cu);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    goto label_00012E34;
    label_00012E31: cpu->eip = LIFT_CODE_TOKEN_VA(0x412E31u);
    cpu->eax = (uint32_t)(cpu->ecx + 0xCu);
    label_00012E34: cpu->eip = LIFT_CODE_TOKEN_VA(0x412E34u);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412E60u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412EA6u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00012F7B;
    cpu->ebx = 0u;
    cpu->ebp = 0xFu;
    lift_store32(cpu->esp + 0x6Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x68u, cpu->ebx);
    lift_store8(cpu->esp + 0x58u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x84u, cpu->ebx);
    lift_store32(cpu->esp + 0x38u, cpu->ebp);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412EE3u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x84u, 1u);
    lift_store32(cpu->esp + 0x54u, cpu->ebp);
    lift_store32(cpu->esp + 0x50u, cpu->ebx);
    lift_store8(cpu->esp + 0x40u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412F05u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x88u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412F1Eu); lift_push32(cpu, r); sfera_sub_00412040(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->esi)) goto label_00012F38;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412F35u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00012F38: cpu->eip = LIFT_CODE_TOKEN_VA(0x412F38u);
    lift_store32(cpu->esp + 0x50u, cpu->ebp);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->esi)) goto label_00012F57;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412F54u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00012F57: cpu->eip = LIFT_CODE_TOKEN_VA(0x412F57u);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x6Cu)) < (uint32_t)(cpu->esi)) goto label_00012F76;
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412F73u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00012F76: cpu->eip = LIFT_CODE_TOKEN_VA(0x412F76u);
    cpu->eax = (uint32_t)(cpu->edi + 0x24u);
    goto label_00012F7E;
    label_00012F7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x412F7Bu);
    cpu->eax = (uint32_t)(cpu->ecx + 0x24u);
    label_00012F7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x412F7Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00412FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412FA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x412FE2u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0001307D;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store32(cpu->esp + 0x38u, 0xFu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413017u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x58u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41303Du); lift_push32(cpu, r); sfera_sub_004120A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    lift_store8(cpu->esp + 0x50u, 2u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x40u)) == (uint32_t)(cpu->ebx)) goto label_00013064;
    cpu->edx = (uint32_t)(cpu->ebx + 0x27u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413057u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413061u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00013064: cpu->eip = LIFT_CODE_TOKEN_VA(0x413064u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(0x10u)) goto label_00013078;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413075u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00013078: cpu->eip = LIFT_CODE_TOKEN_VA(0x413078u);
    cpu->eax = (uint32_t)(cpu->esi + 0x24u);
    goto label_00013080;
    label_0001307D: cpu->eip = LIFT_CODE_TOKEN_VA(0x41307Du);
    cpu->eax = (uint32_t)(cpu->ecx + 0x24u);
    label_00013080: cpu->eip = LIFT_CODE_TOKEN_VA(0x413080u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004130A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4130A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4130BCu); lift_push32(cpu, r); sfera_sub_00410DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->edx = 0x71C71C6u;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000130D6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x130D6u);
    label_000130D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4130D6u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->ecx;
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4130F8u); lift_push32(cpu, r); sfera_sub_0040F5A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00413B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x413B30u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413B3Fu); lift_push32(cpu, r); sfera_sub_00412FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00013B7B;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413B58u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413B61u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    label_00013B7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x413B7Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00413B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x413B80u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413BC2u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00013C98;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x50u, 0xFu);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x68u, 1u);
    lift_store32(cpu->esp + 0x38u, 0xFu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413C1Au); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x6Cu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413C30u); lift_push32(cpu, r); sfera_sub_004130A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->edi = 0x10u;
    lift_store8(cpu->esp + 0x64u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->edi)) goto label_00013C4E;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413C4Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00013C4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x413C4Eu);
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) == (uint32_t)(cpu->ebx)) goto label_00013C80;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413C73u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413C7Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00013C80: cpu->eip = LIFT_CODE_TOKEN_VA(0x413C80u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->edi)) goto label_00013C93;
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x413C90u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00013C93: cpu->eip = LIFT_CODE_TOKEN_VA(0x413C93u);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    goto label_00013C9B;
    label_00013C98: cpu->eip = LIFT_CODE_TOKEN_VA(0x413C98u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    label_00013C9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x413C9Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 4u, stop_address); return;
}
