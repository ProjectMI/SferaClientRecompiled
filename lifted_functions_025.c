#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43DB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F43DBu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x54u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43E6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F43E6u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x70u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43F1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F43F1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0xA0u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43FF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F43FFu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0xACu;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F440D(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F440D;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F440D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F440Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0xBCu;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F441B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F441Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x178u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4450u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4459u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F445B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F445Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4464u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4466(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4466u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F446Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4471(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4471u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F447Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F447C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F447Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4485u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4487(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4487u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4490u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4492(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4492u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F449Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F449D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F449Du);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44A6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44A8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44A8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44B1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44B3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44B3u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44BCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44BE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44BEu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44C7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44C9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44C9u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44D2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44D4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44D4u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44DDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44DF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44DFu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44E8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44EA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44EAu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44F3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44F5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F44F5u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F44FEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4500u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4509u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F450B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F450Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4514u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4516(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4516u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F451Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4521(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4521u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F452Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F452C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F452Cu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4535u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4537(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4537u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4540u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4542(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4542u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F454Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F454D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F454Du);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4556u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4580u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFECCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F458Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F45C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F45C0u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEB4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F45CCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F45CE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F45CEu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFEC0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F45DAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4610u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F461B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F461Bu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x54u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4626(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4626u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x70u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4631(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4631u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xA0u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F463F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F463Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xACu;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F464D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F464Du);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_return(cpu, 0u, stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4656(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4656;
    label_000B9CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9CE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CE8u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4B9CF0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F4656: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4656u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xBCu;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4664(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4664u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x178u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4672(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4672u);
    cpu->eax = g_sfera_control_reference_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_control_reference_registry_guard = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46A0;
    label_000161C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161C0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4161C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F46A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F46A0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_control_reference_registry;
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46D0;
    label_000D67A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67A0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_VA(0x4D67A7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67ADu);
    lift_return(cpu, 0u, stop_address); return;
    label_000F46D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F46D0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBB8u);
    goto label_000D67A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46DB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46DB;
    label_000D67B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67B0u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_VA(0x4D67B3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67B9u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F46DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F46DBu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBECu);
    goto label_000D67B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46E6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46E6;
    label_000D67C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67C0u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_VA(0x4D67C3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67C9u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F46E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F46E6u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBACu);
    goto label_000D67C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46F1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46F1;
    label_000D67D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67D0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D67D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67DDu);
    lift_return(cpu, 0u, stop_address); return;
    label_000F46F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F46F1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBA4u);
    goto label_000D67D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46FC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46FC;
    label_000D67C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67C0u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_VA(0x4D67C3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67C9u);
    lift_return(cpu, 0u, stop_address); return;
    label_000F46FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F46FCu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBC4u);
    goto label_000D67C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4707(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4707;
    label_000D67D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67D0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D67D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67DDu);
    lift_return(cpu, 0u, stop_address); return;
    label_000F4707: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4707u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBE4u);
    goto label_000D67D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4740u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F474Du); lift_push32(cpu, r); sfera_sub_0042B7D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4770u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4778(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4778u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47B0;
    label_000161C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161C0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4161C9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F47B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F47B0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47E0;
    label_000D7B40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7B40u);
    std::construct_at(reinterpret_cast<CCursor*>(cpu->ecx));
    lift_return(cpu, 0u, stop_address); return;
    label_000F47E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F47E0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    goto label_000D7B40;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4810u);
    cpu->eax = g_sfera_cursor_texture_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_texture_registry_guard = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F481E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F481Eu);
    cpu->eax = g_sfera_cursor_texture_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_texture_registry_guard = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4850;
    label_000DA550: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA550u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    std::construct_at(reinterpret_cast<UnmanagedResourceVector*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA564u); lift_push32(cpu, r); sfera_sub_004D9E80(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA56Du); lift_push32(cpu, r); sfera_sub_004D98D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA58B;
    lift_store32(cpu->eax, 0u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->ecx + 4u, 0u);
    lift_store32(cpu->esi + 0x10u, 0u);
    label_000DA58B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA58Bu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F4850: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4850u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x178u;
    goto label_000DA550;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4880u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F48C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F48C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF28u);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4900u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF28u);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4940u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4980u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFBECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F498Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49C0;
    label_000EA960: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA960u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EA98F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EA97E;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EA977u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA97Du);
    lift_return(cpu, 0u, stop_address); return;
    label_000EA97E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA97Eu);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(1u)) goto label_000EA98F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEA989u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEA98Fu);
    label_000EA98F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA98Fu);
    lift_return(cpu, 0u, stop_address); return;
    label_000F49C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F49C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49F0;
    label_000EA960: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA960u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EA98F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EA97E;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EA977u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA97Du);
    lift_return(cpu, 0u, stop_address); return;
    label_000EA97E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA97Eu);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(1u)) goto label_000EA98F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEA989u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEA98Fu);
    label_000EA98F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA98Fu);
    lift_return(cpu, 0u, stop_address); return;
    label_000F49F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F49F0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4A20;
    label_000EA960: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA960u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EA98F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EA97E;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EA977u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA97Du);
    lift_return(cpu, 0u, stop_address); return;
    label_000EA97E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA97Eu);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(1u)) goto label_000EA98F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEA989u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xEA98Fu);
    label_000EA98F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4EA98Fu);
    lift_return(cpu, 0u, stop_address); return;
    label_000F4A20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4A20u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4A50u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x38u;
    sfera_sub_004EE470(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4A80u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x38u;
    sfera_sub_004EE470(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4AE0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4B10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4B50u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4B80u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4BC0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4BF0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4C30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4C60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4CA0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4CD0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4D10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4D40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4D80u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4DB0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4DF0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4E20u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4E60u);
    lift_push32(cpu, (uintptr_t)"logs\\CurrentExecuting.log"); lift_push32(cpu, (uintptr_t)&g_sfera_execution_monitor_runtime.log_path[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4F4E6Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4E70u);
    cpu->esp += 8u;
    lift_push32(cpu, 4u);
    lift_native_call(cpu, native_function_address32(&::SymSetOptions), LIFT_CODE_TOKEN_VA(0x4F4E75u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4E7Bu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4F4E7Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4E85u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4F4E86u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4E8Cu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA0D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4E96u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4EA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4EA0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4ED0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4F10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4F40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4F80u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4FB0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F4FF0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F4FFAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F503D;
    g_sfera_effect_manager.effect_listeners.sentinel = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x14u, cpu->eax & 0xFFu);
    cpu->edx = g_sfera_effect_manager.effect_listeners.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA1F0));
    lift_store8(cpu->edx + 0x15u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5036u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F503D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F503Du);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 4u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F506Au); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F506Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5070u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x17CDC0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5081u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17CDC0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_effect_manager.render_slots.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F508Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5093u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    g_sfera_effect_manager.render_slots.capacity = (uint32_t)(0x2710u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F50ACu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_effect_manager.render_slots.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F50B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F50B8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA150));
    g_sfera_effect_manager.render_slots.debug_file[15] = '\0';
    g_sfera_effect_manager.render_slots.debug_line = UINT32_C(125);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F50D3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F50E0u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA170));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F50EAu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F50F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5120u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5160u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5190u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F51D0u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F51DEu); lift_push32(cpu, r); sfera_sub_0042E540(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA270));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F51E8u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F51F0u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x50u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5201u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_file_runtime.open_files.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F520Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5210u);
    cpu->esp += 0xCu;
    cpu->eax = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    g_sfera_file_runtime.open_files.capacity = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.open_files.maximum = UINT32_C(100);
    g_sfera_file_runtime.open_files.growth = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.open_files.element_size = UINT32_C(8);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5242u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_file_runtime.open_files.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5248u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F524Eu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA280));
    g_sfera_file_runtime.open_files.debug_file[15] = 0;
    g_sfera_file_runtime.open_files.debug_line = UINT32_C(25);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5269u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5270u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5281u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_file_runtime.search_paths.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->edx + 0x10u, cpu->ecx);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->edx + 0x18u, cpu->ecx);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->edx + 0x20u, cpu->ecx);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    cpu->eax = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    g_sfera_file_runtime.search_paths.capacity = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.search_paths.maximum = UINT32_C(100);
    g_sfera_file_runtime.search_paths.growth = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.search_paths.element_size = UINT32_C(4);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5305u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_file_runtime.search_paths.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F530Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5311u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA2A0));
    g_sfera_file_runtime.search_paths.debug_file[15] = 0;
    g_sfera_file_runtime.search_paths.debug_line = UINT32_C(27);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F532Cu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5330u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5360u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F53A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F53D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5450u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].transform;
    g_sfera_spatial_states[0u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5467u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA340));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5471u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5480u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F54B9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F54C0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].transform;
    g_sfera_spatial_states[1u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F54D7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA350));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F54E1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F54F0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5529u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5530u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5550u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5570(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5570;
    label_00021FC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x421FC0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4014u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x421FCBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421FD0u);
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x421FDBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421FE0u);
    cpu->esp += 0x18u;
    lift_store32(cpu->esi + 0x4008u, 0xFFFFFFFFu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F5570: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5570u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    goto label_00021FC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5580;
    label_000016E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4016E0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"";
    cpu->esi = cpu->eax;
    cpu->esi -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000016F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4016F0u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->edx, cpu->ebx & 0xFFu);
    ++cpu->edx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000016F0;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F5580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5580u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    goto label_000016E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5590u);
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (40.0));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.inverse_40, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F55B0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].transform;
    g_sfera_spatial_states[2u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F55C7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA3D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F55D1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F55E0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5619u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5620u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5631u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[2].data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F563Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5643u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].capacity, 0x7Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F565Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5662u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5668u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA3E0));
    lift_store8((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_line, 0x3A6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5683u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5690u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F56A1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[1].data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F56AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F56B3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].capacity, 0x7Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F56CCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F56D2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F56D8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA400));
    lift_store8((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_line, 0x3A7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F56F3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5700u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5711u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[0].data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F571Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5723u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].capacity, 0x7Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F573Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5742u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5748u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA420));
    lift_store8((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_line, 0x3A8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5763u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5770u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].transform;
    g_sfera_spatial_states[3u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5787u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA440));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5791u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F57A0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F57D9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F57E0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].transform;
    g_sfera_spatial_states[4u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F57F7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA450));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5801u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5810u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5849u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5850u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5870u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5890u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F58A1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.secondary_auto_array.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F58AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F58B3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.capacity, 0x1F4u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.maximum, 0x1388u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.growth, 0x64u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F58EAu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F58F0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F58F6u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA470));
    lift_store8((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_line, 0xE6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5911u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5920u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4650u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5931u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4650u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e7_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F593Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5943u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e7_records.capacity, 0x1F4u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e7_records.maximum, 0x1388u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e7_records.growth, 0x64u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e7_records.element_size, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F597Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5980u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5986u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA490));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_line, 0xE7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F59A1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F59B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F59B0u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F59C1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e8_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F59CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F59D3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e8_indices.capacity, 0x1F4u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e8_indices.maximum, 0x1388u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e8_indices.growth, 0x64u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e8_indices.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5A0Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5A10u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5A16u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA4B0));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_line, 0xE8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5A31u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5A40u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x320u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5A51u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e9_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5A5Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5A63u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e9_indices.capacity, 0xC8u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e9_indices.maximum, 0x1F4u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e9_indices.growth, 0x64u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e9_indices.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5A9Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5AA0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5AA6u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA4D0));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_line, 0xE9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5AC1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5AD0u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x109A0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5AE1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x109A0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.eb_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5AEEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5AF3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.eb_records.capacity, 0x1F4u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.eb_records.maximum, 0x3E8u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.eb_records.growth, 0x32u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.eb_records.element_size, 0x88u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5B2Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5B30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5B36u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA4F0));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_line, 0xEBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5B51u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5B60u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5B71u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.ed_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5B7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5B83u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.ed_indices.capacity, 0x32u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.ed_indices.maximum, 0xC8u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.ed_indices.growth, 0x14u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.ed_indices.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5BBAu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5BC0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5BC6u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA510));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_line, 0xEDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5BE1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5BF0u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5C01u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.contact_objects.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5C0Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5C13u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.contact_objects.capacity = (uint32_t)(0x32u);
    g_sfera_collision_runtime.contact_objects.maximum = 0x2710u;
    g_sfera_collision_runtime.contact_objects.growth = 0x14u;
    g_sfera_collision_runtime.contact_objects.element_size = 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5C4Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5C50u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5C56u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA530));
    lift_store8((uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[15], 0u);
    g_sfera_collision_runtime.contact_objects.debug_line = 0xEFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5C71u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5C80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5C80;
    label_0004B620: cpu->eip = LIFT_CODE_TOKEN_VA(0x44B620u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    cpu->eax &= 0xFFFFFFF0u;
    lift_store32(cpu->esi, cpu->eax);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u));
    cpu->ebx = 0u;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi);
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi);
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 0x18u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi);
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi);
    lift_store_f32(cpu->ecx + 0x20u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi);
    lift_store_f32(cpu->edx + 0x24u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi);
    lift_store_f32(cpu->edx + 0x30u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi);
    lift_store_f32(cpu->eax + 0x34u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi);
    lift_store_f32(cpu->ecx + 0x38u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esi + 0x13Bu);
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u));
    cpu->eax &= 0xFFFFFFF0u;
    lift_x87_push(cpu, (double)100.0f);
    cpu->ecx = (uint32_t)(cpu->esi + 0x32Fu);
    lift_store_f32(cpu->esi + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x74u, cpu->ebx);
    lift_store32(cpu->esi + 0x78u, cpu->ebx);
    lift_store32(cpu->esi + 0x7Cu, 0x280u);
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x80u, 0x1E0u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx &= 0xFFFFFFF0u;
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.9999899864196777f);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.75f);
    lift_store_f32(cpu->esi + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x31Cu, cpu->eax);
    lift_store32(cpu->esi + 0x510u, cpu->ecx);
    lift_store_f32(cpu->esi + 0x550u, lift_x87_get(cpu, 0u));
    lift_store16(cpu->esi + 0x564u, cpu->ebx & 0xFFFFu);
    lift_store_f32(cpu->esi + 0x554u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 0x566u, cpu->ebx & 0xFFu);
    lift_store_f32(cpu->esi + 0x558u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x55Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x560u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44B729u); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store32(cpu->esi + 0x514u, cpu->ebx);
    lift_store_f32(cpu->esi + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 1u;
    lift_store32(cpu->esi + 0x51Cu, cpu->eax);
    lift_store32(cpu->esi + 0x524u, cpu->eax);
    cpu->eax = 3u;
    cpu->edx = 4u;
    cpu->ecx = 2u;
    lift_store32(cpu->esi + 0x534u, cpu->eax);
    lift_store32(cpu->esi + 0x53Cu, cpu->eax);
    lift_store32(cpu->esi + 0x548u, cpu->eax);
    lift_store32(cpu->esi + 0x520u, cpu->ebx);
    lift_store32(cpu->esi + 0x52Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x538u, cpu->ebx);
    lift_store32(cpu->esi + 0x90u, cpu->ebx);
    lift_store32(cpu->esi + 0x88u, cpu->ebx);
    lift_store32(cpu->esi + 0x8Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x84u, cpu->ebx);
    lift_store32(cpu->esi + 0x518u, cpu->edx);
    lift_store32(cpu->esi + 0x528u, cpu->ecx);
    lift_store32(cpu->esi + 0x530u, cpu->ecx);
    lift_store32(cpu->esi + 0x540u, cpu->edx);
    lift_store32(cpu->esi + 0x544u, cpu->edx);
    lift_store32(cpu->esi + 0x54Cu, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000F5C80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5C80u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    goto label_0004B620;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5C90u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5CA1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_102_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5CAEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5CB3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.capacity, 0x32u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.maximum, 0x64u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.growth, 0x14u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5CEAu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5CF0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5CF6u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA550));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_line, 0x102u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5D11u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5D20u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3200u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5D31u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3200u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_105_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5D3Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5D43u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_105_records.capacity, 0xC8u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_105_records.maximum, 0x1F4u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_105_records.growth, 0x64u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_105_records.element_size, 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5D7Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5D80u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5D86u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA570));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_line, 0x105u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5DA1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5DB0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.object_01[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5DBAu); lift_push32(cpu, r); sfera_sub_0048A1A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA460));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5DC4u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5DD0;
    label_0009B950: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B950u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B967u); lift_push32(cpu, r); sfera_sub_0049B860(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x5320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49B96Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B974u);
    cpu->eax = 0x6E726157u;
    cpu->ecx = 0x73676E69u;
    cpu->edx = 0x6C2E3030u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x676F)) & 0xFFFFu);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store16(cpu->esp + 0x14u, cpu->eax & 0xFFFFu);
    lift_store8(cpu->esp + 0x16u, cpu->ecx & 0xFFu);
    lift_flags_logic(cpu,0u,32u); cpu->ebx = 0u;
    label_0009B9B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B9B0u);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->edx + 0x30u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->ebx & 0xFFu)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store8(cpu->esp + 0x11u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B9DEu); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xF4240u)) goto label_0009B9F3;
    cpu->edx = 0xF4240u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B9F3u); lift_push32(cpu, r); sfera_sub_0044C020(cpu,r); if (cpu->eip != r) return; }
    label_0009B9F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B9F3u);
    ++cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009B9B0;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F5DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5DD0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    goto label_0009B950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5DE0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C40u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5DF1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x9C40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_light_ids.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5DFEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5E03u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_light_ids.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5E1Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5E22u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5E28u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA590));
    lift_store8((uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_line, 0x16Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5E43u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5E50u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7F710u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5E61u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7F710u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_landscape_runtime.file_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5E6Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5E73u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_runtime.file_records.capacity = (uint32_t)(0x12Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5E8Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5E92u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5E98u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA5B0));
    g_sfera_landscape_runtime.file_records.debug_file[15] = 0;
    g_sfera_landscape_runtime.file_records.debug_line = 0x171u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5EB3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5EC0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x6D60u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5ED1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x6D60u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_interface_runtime.window_handle_table.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5EDEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5EE3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_interface_runtime.window_handle_table.capacity = (uint32_t)(0x1B58u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5EFCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5F02u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5F08u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA5D0));
    lift_store8((uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_line, 0x193u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5F23u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5F30u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E8480u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5F41u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1E8480u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_world_objects.object_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5F4Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5F53u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_world_objects.object_handles.capacity = (uint32_t)(0x7A120u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5F6Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5F72u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5F78u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA5F0));
    g_sfera_world_objects.object_handles.debug_file[15] = 0;
    g_sfera_world_objects.object_handles.debug_line = 0x1A2u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5F93u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5FA0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1D4C0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5FB1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1D4C0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_world_objects.extended_object_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5FBEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5FC3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_world_objects.extended_object_handles.capacity = (uint32_t)(0x7530u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F5FDCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5FE2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F5FE8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA610));
    g_sfera_world_objects.extended_object_handles.debug_file[15] = 0;
    g_sfera_world_objects.extended_object_handles.debug_line = 0x1A5u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6003u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6010u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x190u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6021u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_interface_runtime.windows.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F602Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6033u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_interface_runtime.windows.capacity = (uint32_t)(0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F604Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6052u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6058u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA630));
    g_sfera_interface_runtime.windows.debug_file[15] = 0;
    g_sfera_interface_runtime.windows.debug_line = 0x1A9u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6073u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6080u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6091u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_character_index_map.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F609Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F60A3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_character_index_map.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F60BCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_character_index_map.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F60C2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F60C8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA650));
    g_sfera_character_index_map.debug_file[15] = '\0';
    g_sfera_character_index_map.debug_line = 0x1BFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F60E3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F60F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F60F0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6101u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_visibility_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F610Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6113u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_visibility_indices.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F612Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6132u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6138u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA670));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_line, 0x1C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6153u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6160u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6171u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_sort_keys.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F617Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6183u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_sort_keys.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F619Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F61A2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F61A8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA690));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_line, 0x1C3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F61C3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F61D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F61D0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F61E1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_sort_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F61EEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F61F3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_sort_indices.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F620Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6212u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6218u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA6B0));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_line, 0x1C4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6233u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6240u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6251u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_draw_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F625Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6263u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_draw_indices.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F627Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6282u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6288u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA6D0));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_line, 0x1C5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F62A3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F62B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F62B0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F62C1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.candidate_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F62CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F62D3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.candidate_handles.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F62ECu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F62F2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F62F8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA6F0));
    g_sfera_collision_runtime.candidate_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.candidate_handles.debug_line = 0x1C6u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6313u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6320u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x54F60u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6331u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x54F60u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.scene_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F633Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6343u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.scene_records.capacity = (uint32_t)(0xBB8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F635Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6362u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6368u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA710));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_line, 0x1E3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6383u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6390u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xF0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F63A1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xF0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.reflection_targets.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F63AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F63B3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.reflection_targets.capacity = (uint32_t)(0xAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F63CCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F63D2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F63D8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA730));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_line, 0x236u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F63F3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6400u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x2A30u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6411u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x2A30u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.scene_points.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F641Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6423u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.scene_points.capacity = (uint32_t)(0x384u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F643Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6442u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6448u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA750));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_line, 0x33Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6463u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6470u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x24u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6481u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29) = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->edx + 0x10u, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->edx + 0x18u, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_store32(cpu->edx + 0x20u, cpu->ecx);
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_config_runtime.text_length_01, 9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F64E4u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.text_01[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F64EAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F64F0u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA770));
    lift_store8((uintptr_t)&g_sfera_client_config_runtime.text_01[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_config_runtime.text_capacity_01, 0x633u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F650Bu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6510u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x400u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6521u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x400u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30) = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F652Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6533u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_config_runtime.text_length_02, 0x100u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F654Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.text_02[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6552u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6558u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA790));
    lift_store8((uintptr_t)&g_sfera_client_config_runtime.text_02[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_config_runtime.text_capacity_02, 0x6B0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6573u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6580u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6591u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_client_array_runtime.line_6b1_indices.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->edx + 0x10u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->edx + 0x18u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->edx + 0x20u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.capacity, 0xAu);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.maximum, 0x14u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.growth, 5u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F661Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6620u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6626u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA7B0));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_line, 0x6B1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6641u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6650u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6661u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_recovered_static_runtime.primary_auto_array.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->edx + 0x10u, cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->edx + 0x18u, cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->edx + 0x20u, cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.capacity, 0xAu);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.maximum, 0x14u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.growth, 5u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F66EAu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F66F0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F66F6u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA7D0));
    lift_store8((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_line, 0x6B2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6711u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6720u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6731u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_client_array_runtime.line_6b3_indices.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->edx + 0x10u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->edx + 0x18u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->edx + 0x20u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.capacity, 0xAu);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.maximum, 0x14u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.growth, 5u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F67BAu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F67C0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F67C6u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA7F0));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_line, 0x6B3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F67E1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F67F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F67F0u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6801u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_client_array_runtime.line_6b4_indices.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->edx + 0x10u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->edx + 0x18u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->edx + 0x20u, cpu->ecx);
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.capacity, 0xAu);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.maximum, 0x14u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.growth, 5u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.element_size, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F688Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6890u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6896u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA810));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_line, 0x6B4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F68B1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F68C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F68C0u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F68D1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1E0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_6b5_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F68DEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F68E3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.capacity, 0xAu);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.maximum, 0x14u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.growth, 5u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.element_size, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F691Au); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6920u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6926u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA830));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_line, 0x6B5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6941u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6950u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x240u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6961u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x240u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F696Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6973u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_indices.capacity = (uint32_t)(0x90u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F698Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6992u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6998u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA850));
    lift_store8((uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_light_runtime.cell_indices.debug_line, 0x1247u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F69B3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F69C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F69C0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3600u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F69D1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3600u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F69DEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F69E3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_records.capacity = (uint32_t)(0x90u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F69FCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6A02u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6A08u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA870));
    lift_store8((uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_light_runtime.cell_records.debug_line, 0x1248u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6A23u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6A30u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C40u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6A41u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x9C40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_landscape_runtime.microtexture_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6A4Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6A53u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_runtime.microtexture_handles.capacity = (uint32_t)(0x2710u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6A6Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6A72u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6A78u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA890));
    lift_store8((uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_line, 0x124Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6A93u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6AA0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F40u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6AB1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1F40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6ABEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6AC3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_handles.capacity = (uint32_t)(0x7D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6ADCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6AE2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6AE8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA8B0));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_line, 0x124Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6B03u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6B10u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xB7980u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6B21u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xB7980u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_124d_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6B2Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6B33u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_124d_records.capacity, 0x7D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6B4Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6B52u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6B58u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA8D0));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_line, 0x124Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6B73u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6B80u);
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA00u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6B91u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFA00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.tertiary_auto_array.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6B9Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6BA3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.capacity, 0x7D0u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.maximum, 0xBB8u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.growth, 0x1F4u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.element_size, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6BDAu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6BE0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6BE6u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA8F0));
    lift_store8((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_line, 0x124Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6C01u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6C10u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x30u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6C21u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x30u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_pass_slots.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6C2Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6C30u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_pass_slots.capacity = (uint32_t)(0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6C49u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6C4Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6C55u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA910));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_line, 0x125Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6C70u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6C80u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x61A80u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6C91u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x61A80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6C9Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6CA3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_records.capacity = (uint32_t)(0x2710u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6CBCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6CC2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6CC8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA930));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_line, 0x1264u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6CE3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6CF0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6D01u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_index_map.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6D0Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6D13u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_index_map.capacity = (uint32_t)(0x9C40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6D2Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6D32u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6D38u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA950));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_line, 0x1266u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6D53u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6D60u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6D71u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6D7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6D83u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.handles.capacity = (uint32_t)(0x3E8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6D9Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6DA2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6DA8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA970));
    lift_store8((uintptr_t)&g_sfera_light_runtime.handles.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_light_runtime.handles.debug_line, 0x127Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6DC3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6DD0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6DE1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.visible_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6DEEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6DF3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.visible_handles.capacity = (uint32_t)(0x1F4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6E0Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6E12u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6E18u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA990));
    lift_store8((uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_light_runtime.visible_handles.debug_line, 0x1280u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6E33u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6E40u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6E51u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7Cu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.active_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6E5Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6E60u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.active_handles.capacity = (uint32_t)(0x1Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6E79u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6E7Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6E85u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA9B0));
    lift_store8((uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_light_runtime.active_handles.debug_line, 0x1282u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6EA0u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6EB0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3E8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6EC1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3E8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_mesh_partition_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6ECEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6ED3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_mesh_partition_indices.capacity = (uint32_t)(0x1F4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6EECu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6EF2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6EF8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA9D0));
    g_sfera_mesh_partition_indices.debug_file[15] = '\0';
    g_sfera_mesh_partition_indices.debug_line = 0x1392u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6F13u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6F20u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6F2Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F6F6D;
    g_sfera_model_registry_runtime.sentinel = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x2Cu, cpu->eax & 0xFFu);
    cpu->edx = g_sfera_model_registry_runtime.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAC90));
    lift_store8(cpu->edx + 0x2Du, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6F66u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F6F6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6F6Du);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 4u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6F9Au); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F6F9Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6FA0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x23280u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6FB1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x23280u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24de_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6FBEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6FC3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_24de_records.capacity, 0xFA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F6FDCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6FE2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F6FE8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA9F0));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_line, 0x24DEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7003u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7010u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x21D68u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7021u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x21D68u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e0_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F702Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7033u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.capacity, 0x26ACu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F704Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7052u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7058u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA10));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_line, 0x24E0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7073u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7080u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D00u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7091u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7D00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e2_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F709Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F70A3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.capacity, 0xFA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F70BCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F70C2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F70C8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA30));
    lift_store8((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_line, 0x24E2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F70E3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F70F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F70F0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4000u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7101u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.model_matrices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F710Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7113u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.model_matrices.capacity = (uint32_t)(0x100u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F712Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7132u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7138u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA50));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_line, 0x24EBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7153u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7160u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x140u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7171u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x140u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.character_matrices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F717Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7183u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.character_matrices.capacity = (uint32_t)(5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F719Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F71A2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F71A8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA70));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_line, 0x24F1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F71C3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F71D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F71D0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1D4C0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F71E1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1D4C0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_positions.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F71EEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F71F3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_positions.capacity = (uint32_t)(0x2710u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F720Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7212u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7218u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA90));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_line, 0x2539u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7233u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7240u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x960u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7251u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x960u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_vectors.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F725Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7263u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_vectors.capacity = (uint32_t)(0xC8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F727Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7282u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7288u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAAB0));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_line, 0x2A71u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F72A3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F72B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F72B0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x320u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F72C1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F72CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F72D3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_indices.capacity = (uint32_t)(0xC8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F72ECu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F72F2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F72F8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAAD0));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_line, 0x2A77u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7313u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7320u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7331u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1E0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_points.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F733Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7343u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_points.capacity = (uint32_t)(0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F735Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7362u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7368u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAAF0));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_line, 0x2A84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7383u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7390u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x27100u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F73A1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x27100u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.cloud_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F73AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F73B3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.cloud_records.capacity = (uint32_t)(0x7D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F73CCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F73D2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F73D8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB10));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_line, 0x2A85u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F73F3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7400u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x50u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7411u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.near_result_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F741Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7420u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.near_result_handles.capacity = (uint32_t)(0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7439u); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F743Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7445u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB30));
    g_sfera_collision_runtime.near_result_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.near_result_handles.debug_line = 0x2A86u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7460u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7470u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4C5BDA0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7481u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4C5BDA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.world_cell_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F748Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7493u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.world_cell_records.capacity = (uint32_t)(0x1F4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F74ACu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F74B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F74B8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB50));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_line, 0x2A94u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F74D3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F74E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F74E0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F74F1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_ranges.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F74FEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7503u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_ranges.capacity = (uint32_t)(0x1F4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F751Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7522u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7528u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB70));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_line, 0x3C0Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7543u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7550u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C400u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7561u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x9C400u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_work_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F756Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7573u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_work_records.capacity = (uint32_t)(0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F758Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7592u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7598u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB90));
    lift_store8((uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_line, 0x3C0Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F75B3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F75C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F75C0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x168u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F75D1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x168u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.type_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F75DEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F75E3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.type_records.capacity = (uint32_t)(0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F75FCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7602u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7608u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FABB0));
    lift_store8((uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_grass_runtime.type_records.debug_line, 0x4409u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7623u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7630u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xBB80u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7641u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xBB80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.instance_offsets.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F764Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7653u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.instance_offsets.capacity = (uint32_t)(0x2EE0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F766Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7672u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7678u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FABD0));
    lift_store8((uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_line, 0x440Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7693u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F76A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F76A0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xBB80u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F76B1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xBB80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.instance_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F76BEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F76C3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.instance_indices.capacity = (uint32_t)(0x2EE0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F76DCu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F76E2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F76E8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FABF0));
    lift_store8((uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_line, 0x440Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7703u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7710u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7721u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.model_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F772Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7733u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.model_handles.capacity = (uint32_t)(0x32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F774Cu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7752u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7758u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAC10));
    lift_store8((uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_grass_runtime.model_handles.debug_line, 0x440Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7773u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7780u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].transform;
    g_sfera_spatial_states[5u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7797u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FACF0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F77A1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F77B0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F77E9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F77F0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].transform;
    g_sfera_spatial_states[6u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7807u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD00));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7811u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7820u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7859u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7860u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].transform;
    g_sfera_spatial_states[7u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7877u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD10));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7881u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7890u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F78C9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F78D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F78D0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].transform;
    g_sfera_spatial_states[8u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F78E7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD20));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F78F1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7900u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7939u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7940u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].transform;
    g_sfera_spatial_states[9u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7957u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD30));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7961u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7970u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F79A9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F79B0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].transform;
    g_sfera_spatial_states[10u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F79C7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD40));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F79D1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F79E0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7A19u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7A20u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].transform;
    g_sfera_spatial_states[11u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7A37u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD50));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7A41u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7A50u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7A89u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7A90u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].transform;
    g_sfera_spatial_states[12u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7AA7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD60));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7AB1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7AC0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7AF9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7B00u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].transform;
    g_sfera_spatial_states[13u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7B17u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD70));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7B21u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7B30u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7B69u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7B70u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].transform;
    g_sfera_spatial_states[14u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7B87u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD80));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7B91u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7BA0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7BD9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7BE0u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD90));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7BEAu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7BF0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_shadow_object_storage[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_shadow_runtime.aligned_global_object;
    g_sfera_shadow_runtime.aligned_global_object = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7C07u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FADA0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7C11u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7C20u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_shadow_object_storage[0x60];
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7C59u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7CA0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].transform;
    g_sfera_spatial_states[15u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7CB7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE10));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7CC1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7CD0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7D09u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7D10u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].transform;
    g_sfera_spatial_states[16u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7D27u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE20));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7D31u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7D40u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7D79u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7D80u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].transform;
    g_sfera_spatial_states[17u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7D97u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE30));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7DA1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7DB0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7DE9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7DF0u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE40));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7DFAu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7E00u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].transform;
    g_sfera_spatial_states[18u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7E17u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAEC0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7E21u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7E30u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7E69u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7E70u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].transform;
    g_sfera_spatial_states[19u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7E87u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAED0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7E91u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7EA0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7ED9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7EE0u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAEE0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7EEAu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7EF0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].transform;
    g_sfera_spatial_states[20u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7F07u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF20));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7F11u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7F20u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7F59u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7F60u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].transform;
    g_sfera_spatial_states[21u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7F77u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF30));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7F81u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7F90u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7FC9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F7FD0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].transform;
    g_sfera_spatial_states[22u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7FE7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF40));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F7FF1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8000u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8039u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8040u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].transform;
    g_sfera_spatial_states[23u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8057u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF50));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8061u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8070u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F80A9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F80B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F80B0u);
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x190u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F80C1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_weather_runtime.sky_texture_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F80CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F80D3u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\WeatherManager.cpp";
    g_sfera_weather_runtime.sky_texture_handles.capacity = (uint32_t)(0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F80ECu); lift_push32(cpu, r); sfera_sub_00401000(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F80F2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4F80F8u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF60));
    lift_store8((uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[15], 0u);
    lift_store32((uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_line, 0x157u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8113u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8120u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].transform;
    g_sfera_spatial_states[24u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8137u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF80));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8141u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8150u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8189u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8190u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].transform;
    g_sfera_spatial_states[25u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F81A7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF90));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F81B1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F81C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F81C0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F81F9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8200u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8220u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8240u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].transform;
    g_sfera_spatial_states[26u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8257u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB000));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8261u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8270u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F82A9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F82B0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F82D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F82F0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].transform;
    g_sfera_spatial_states[27u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8307u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB070));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8311u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8320u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8359u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8360u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].transform;
    g_sfera_spatial_states[28u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8377u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB080));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8381u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8390u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F83C9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F83D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F83F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8410u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].transform;
    g_sfera_spatial_states[29u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8427u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB0F0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8431u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8440u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8479u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8480u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F84A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F84C0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].transform;
    g_sfera_spatial_states[30u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F84D7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB160));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F84E1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F84F0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8529u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8530u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8550u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8570u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].transform;
    g_sfera_spatial_states[31u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8587u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB1D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8591u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F85A0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F85D9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F85E0u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB1E0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F85EAu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F85F0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].transform;
    g_sfera_spatial_states[32u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8607u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB220));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8611u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8620u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8659u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8660u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8680u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F86A0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].transform;
    g_sfera_spatial_states[33u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F86B7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB290));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F86C1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F86D0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8709u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8710u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].transform;
    g_sfera_spatial_states[34u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8727u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB2A0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8731u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8740u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8779u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8780u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F87A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F87C0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].transform;
    g_sfera_spatial_states[35u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F87D7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB310));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F87E1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F87F0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8829u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8830u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8850u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8870u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].transform;
    g_sfera_spatial_states[36u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8887u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB380));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8891u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F88A0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F88D9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F88E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8900u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8920u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].transform;
    g_sfera_spatial_states[37u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8937u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB3F0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8941u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8950u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8989u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8990u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F89B0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F89D0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].transform;
    g_sfera_spatial_states[38u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F89E7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB460));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F89F1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8A00u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8A39u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8A40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8A60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8A80u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.lookup_object[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_12;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_12) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8A97u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB4D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8AA1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8AB0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.manager_object[0];
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8AE9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8AF0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8B10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8B30u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8B3Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8B61;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB540));
    lift_store32(cpu->eax + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8B5Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F8B61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8B61u);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 4u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8B8Eu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F8B8Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8B90u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8B9Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8BC1;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB590));
    lift_store32(cpu->eax + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8BBAu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F8BC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8BC1u);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 4u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8BEEu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F8BEEu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8BF0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8BFAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8C21;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB5E0));
    lift_store32(cpu->eax + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8C1Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F8C21: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8C21u);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 4u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8C4Eu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F8C4Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8C50u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB680));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8C5Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8C60u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = 0u;
    lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8C91u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000F8CE7;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head) = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head;
    lift_store32(cpu->eax, (uintptr_t)&g_sfera_interface_core_runtime.queue_head);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB630));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = (uint32_t)(cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8CD3u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_000F8CE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8CE7u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8D11u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F8D11u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8D20u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8D2Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8D51;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10) = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB660));
    lift_store32(cpu->eax + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8D4Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F8D51: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8D51u);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 4u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8D7Eu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F8D7Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8D80u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8D8Au); lift_push32(cpu, r); sfera_sub_004CFE70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB6D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8D94u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8DA0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].transform;
    g_sfera_spatial_states[39u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8DB7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB6E0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8DC1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8DD0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8E09u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8E10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8E30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8E50u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].transform;
    g_sfera_spatial_states[40u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8E67u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB750));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8E71u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8E80u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8EB9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8EC0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].transform;
    g_sfera_spatial_states[41u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8ED7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB760));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8EE1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8EF0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8F29u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8F30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8F50u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8F70u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].transform;
    g_sfera_spatial_states[42u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8F87u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB7D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8F91u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F8FA0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F8FD9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9080u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].transform;
    g_sfera_spatial_states[43u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9097u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB8D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F90A1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F90B0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F90E9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F90F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9110u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9130u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].transform;
    g_sfera_spatial_states[44u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9147u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB940));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9151u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9160u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9199u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F91A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F91C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F91E0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].transform;
    g_sfera_spatial_states[45u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F91F7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB9B0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9201u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9210u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9249u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9250u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].transform;
    g_sfera_spatial_states[46u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9267u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB9C0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9271u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9280u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F92B9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F92C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F92E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9300u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].transform;
    g_sfera_spatial_states[47u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9317u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBA30));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9321u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9330u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9369u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9370u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9390u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F93B0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].transform;
    g_sfera_spatial_states[48u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F93C7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBAA0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F93D1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F93E0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9419u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9420u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9440u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9460u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].transform;
    g_sfera_spatial_states[49u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9477u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBB10));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9481u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9490u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F94C9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F94D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F94F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9510u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].transform;
    g_sfera_spatial_states[50u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9527u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBB80));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9531u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9540u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9579u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9580u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F95A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F95C0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].transform;
    g_sfera_spatial_states[51u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F95D7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBBF0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F95E1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F95F0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9629u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9630u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9650u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9670u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_options_dialog_object_storage[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.aligned_storage_token;
    g_sfera_options_dialog_runtime.aligned_storage_token = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9687u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBC60));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9691u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F96A0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_object_storage[0x60];
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F96D9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F96E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9700u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9720u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBD50));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F972Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9730u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBD10));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F973Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9740u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBCD0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F974Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9750u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].transform;
    g_sfera_spatial_states[52u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9767u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBD90));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9771u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9780u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F97B9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F97C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F97E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9800u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].transform;
    g_sfera_spatial_states[53u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9817u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBE00));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9821u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9830u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9869u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9870u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].transform;
    g_sfera_spatial_states[54u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9887u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBE10));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9891u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F98A0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F98D9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F98E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9900u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9920u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].transform;
    g_sfera_spatial_states[55u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9937u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBE80));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9941u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9950u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9989u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9990u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F99B0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F99D0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].transform;
    g_sfera_spatial_states[56u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F99E7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBEF0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F99F1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9A00u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9A39u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9A40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9A60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9A80u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].transform;
    g_sfera_spatial_states[57u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9A97u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBF60));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9AA1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9AB0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9AE9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9AF0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9AFAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F9B21;
    g_sfera_win32_dialog_registry.sentinel = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = g_sfera_win32_dialog_registry.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBF70));
    lift_store32(cpu->eax + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9B1Au); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000F9B21: cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9B21u);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 4u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9B4Eu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4F9B4Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9B50u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].transform;
    g_sfera_spatial_states[58u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9B67u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBFC0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9B71u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9B80u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9BB9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9BC0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9BE0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9C00u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9C0Au); lift_push32(cpu, r); sfera_sub_004D6720(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC090));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9C14u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9C20u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].transform;
    g_sfera_spatial_states[59u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9C37u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0A0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9C41u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9C50u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9C89u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9C90u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].transform;
    g_sfera_spatial_states[60u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9CA7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0B0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9CB1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9CC0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9CF9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9D00u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].transform;
    g_sfera_spatial_states[61u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9D17u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0C0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9D21u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9D30u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9D69u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9D70u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].transform;
    g_sfera_spatial_states[62u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9D87u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0E0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9D91u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9DA0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9DD9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9DE0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].transform;
    g_sfera_spatial_states[63u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9DF7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0F0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9E01u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9E10u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9E49u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9E50u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].transform;
    g_sfera_spatial_states[64u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9E67u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC100));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9E71u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9E80u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9EB9u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9EC0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].transform;
    g_sfera_spatial_states[65u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9ED7u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC110));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9EE1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9EF0u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9F29u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9F30u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].transform;
    g_sfera_spatial_states[66u].transform.matrix_address = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9F47u); lift_push32(cpu, r); sfera_sub_00401150(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC120));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9F51u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9F60u);
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].bounds;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9F99u); lift_push32(cpu, r); sfera_sub_00401250(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9FA0u);
    lift_push32(cpu, 0x200u); lift_push32(cpu, 0u); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0xCu); lift_push32(cpu, (uintptr_t)"$d $t "); lift_push32(cpu, (uintptr_t)"LogMemory.log");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9FC2u); lift_push32(cpu, r); sfera_sub_004EC500(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC130));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9FCCu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4F9FD0u);
    lift_push32(cpu, 0x840u); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004EBEF0)); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"$d $t $u"); lift_push32(cpu, (uintptr_t)"Warnings.log");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_warnings_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9FF5u); lift_push32(cpu, r); sfera_sub_004EC500(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC140));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4F9FFFu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA010u);
    lift_push32(cpu, 0x840u); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004EBEF0)); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0xDu); lift_push32(cpu, (uintptr_t)"$d $t $u"); lift_push32(cpu, (uintptr_t)"Errors.log");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA035u); lift_push32(cpu, r); sfera_sub_004EC500(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC150));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA03Fu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA041(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA041u);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC15A));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA04Bu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA050u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA060u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA070u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA080u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA090u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA0A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA0B0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA0C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA0D0u);
    cpu->eax = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::WaitForSingleObject);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xFA0E1u), LIFT_CODE_TOKEN_RVA(0xFA0DFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA0E1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FA117;
    cpu->ecx = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->ecx);
    g_sfera_execution_monitor_runtime.stop_requested = UINT16_C(1);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xFA0F9u), LIFT_CODE_TOKEN_RVA(0xFA0F7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA0F9u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FA10C;
    cpu->edx = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_RVA(0xFA106u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xFA10Cu);
    label_000FA10C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA10Cu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_execution_monitor_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::DeleteCriticalSection), LIFT_CODE_TOKEN_RVA(0xFA111u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xFA117u);
    label_000FA117: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA117u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA120u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA130u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA140u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA150u);
    cpu->ecx = g_sfera_effect_manager.render_slots.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA162u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA170u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = g_sfera_effect_items.block_vector_end;
    cpu->eax = g_sfera_effect_items.block_vector_begin;
    cpu->ecx -= cpu->eax;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000FA1BA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_items;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA1B5u); lift_push32(cpu, r); sfera_sub_0042A290(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_effect_items.block_vector_begin;
    label_000FA1BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA1BAu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000FA1C7;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA1C4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000FA1C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA1C7u);
    g_sfera_effect_items.block_vector_begin = (uint32_t)(cpu->esi);
    g_sfera_effect_items.block_vector_end = (uint32_t)(cpu->esi);
    g_sfera_effect_items.block_vector_capacity_end = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA1F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    lift_store32(cpu->esp + 0x1Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA231u); lift_push32(cpu, r); sfera_sub_00406340(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_effect_manager.effect_listeners.sentinel;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA23Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA250u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA260u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA270(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA270;
    label_0002E630: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E630u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 8u)) == (uint32_t)(0u)) goto label_0002E681;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x104u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E649u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E680;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E677;
    cpu->edx = 0x65u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E66Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E674u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002E677: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E677u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E67Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002E680: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E680u);
    cpu->esi = lift_pop32(cpu);
    label_0002E681: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E681u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xCu)) == (uint32_t)(0u)) goto label_0002E6AD;
    cpu->edx = 0x105u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E696u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0002E6AD;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E6A4u); lift_push32(cpu, r); sfera_sub_0042E250(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E6AAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002E6AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E6ADu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000FA270: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA270u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_log_runtime.object[0];
    goto label_0002E630;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA280u);
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA292u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA2A0u);
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA2B2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA2C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA2D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA340u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA350u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA360(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA360;
    label_000D7AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7AB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x13u;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7AC2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D7AD0;
    lift_push32(cpu, 1u);
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    label_000D7AD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7AD0u);
    cpu->edx = 0x14u;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7ADFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D7AEF;
    lift_push32(cpu, 1u);
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    label_000D7AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7AEFu);
    lift_return(cpu, 0u, stop_address); return;
    label_000FA360: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA360u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    goto label_000D7AB0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA370u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA3A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA3D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA3E0u);
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[2].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA3F2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA400u);
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[1].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA412u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA420u);
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[0].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA432u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA440u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA450u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA460(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA460;
    label_0008A1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A1B0u);
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(0u)) goto label_0008A1BF;
    cpu->ecx = (uint32_t)(uintptr_t)"CReadPathManager::~CReadPathManager: object not deinitialized";
    sfera_sub_00459B10(cpu, stop_address); return;
    label_0008A1BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48A1BFu);
    lift_return(cpu, 0u, stop_address); return;
    label_000FA460: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA460u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.object_01[0];
    goto label_0008A1B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA470u);
    cpu->ecx = g_sfera_recovered_static_runtime.secondary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA482u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA490u);
    cpu->ecx = g_sfera_client_array_runtime.e7_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA4A2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA4B0u);
    cpu->ecx = g_sfera_client_array_runtime.e8_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA4C2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA4D0u);
    cpu->ecx = g_sfera_client_array_runtime.e9_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA4E2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA4F0u);
    cpu->ecx = g_sfera_client_array_runtime.eb_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA502u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA510u);
    cpu->ecx = g_sfera_client_array_runtime.ed_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA522u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA530u);
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA542u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA550u);
    cpu->ecx = g_sfera_client_array_runtime.line_102_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA562u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA570u);
    cpu->ecx = g_sfera_client_array_runtime.line_105_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA582u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA590u);
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA5A2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA5B0u);
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA5C2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA5D0u);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA5E2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA5F0u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA602u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA610u);
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA622u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA630u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA642u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA650u);
    cpu->ecx = g_sfera_character_index_map.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA662u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA670u);
    cpu->ecx = g_sfera_scene_array_runtime.object_visibility_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA682u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA690u);
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_keys.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA6A2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA6B0u);
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA6C2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA6D0u);
    cpu->ecx = g_sfera_scene_array_runtime.object_draw_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA6E2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA6F0u);
    cpu->ecx = g_sfera_collision_runtime.candidate_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA702u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA710u);
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA722u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA730u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA742u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA750u);
    cpu->ecx = g_sfera_scene_array_runtime.scene_points.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA762u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA770u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA782u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA790u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA7A2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA7B0u);
    cpu->ecx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA7C2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA7D0u);
    cpu->ecx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA7E2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA7F0u);
    cpu->ecx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA802u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA810u);
    cpu->ecx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA822u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA830u);
    cpu->ecx = g_sfera_client_array_runtime.line_6b5_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA842u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA850u);
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA862u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA870u);
    cpu->ecx = g_sfera_light_runtime.cell_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA882u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA890u);
    cpu->ecx = g_sfera_landscape_runtime.microtexture_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA8A2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA8B0u);
    cpu->ecx = g_sfera_scene_array_runtime.surface_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA8C2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA8D0u);
    cpu->ecx = g_sfera_client_array_runtime.line_124d_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA8E2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA8F0u);
    cpu->ecx = g_sfera_recovered_static_runtime.tertiary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA902u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA910u);
    cpu->ecx = g_sfera_scene_array_runtime.render_pass_slots.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA922u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA930u);
    cpu->ecx = g_sfera_scene_array_runtime.surface_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA942u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA950u);
    cpu->ecx = g_sfera_scene_array_runtime.surface_index_map.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA962u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA970u);
    cpu->ecx = g_sfera_light_runtime.handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA982u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA990u);
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA9A2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA9B0u);
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA9C2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA9D0u);
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FA9E2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FA9F0u);
    cpu->ecx = g_sfera_client_array_runtime.line_24de_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAA02u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAA10u);
    cpu->ecx = g_sfera_client_array_runtime.line_24e0_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAA22u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAA30u);
    cpu->ecx = g_sfera_client_array_runtime.line_24e2_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAA42u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAA50u);
    cpu->ecx = g_sfera_scene_array_runtime.model_matrices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAA62u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAA70u);
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAA82u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAA90u);
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAAA2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAAB0u);
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAAC2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAAD0u);
    cpu->ecx = g_sfera_scene_array_runtime.clip_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAAE2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAAF0u);
    cpu->ecx = g_sfera_scene_array_runtime.clip_points.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAB02u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAB10u);
    cpu->ecx = g_sfera_scene_array_runtime.cloud_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAB22u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAB30u);
    cpu->ecx = g_sfera_collision_runtime.near_result_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAB42u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAB50u);
    cpu->ecx = g_sfera_scene_array_runtime.world_cell_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAB62u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAB70u);
    cpu->ecx = g_sfera_scene_array_runtime.render_ranges.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAB82u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAB90u);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FABA2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FABB0u);
    cpu->ecx = g_sfera_grass_runtime.type_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FABC2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FABD0u);
    cpu->ecx = g_sfera_grass_runtime.instance_offsets.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FABE2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FABF0u);
    cpu->ecx = g_sfera_grass_runtime.instance_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAC02u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAC10u);
    cpu->ecx = g_sfera_grass_runtime.model_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAC22u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAC30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAC60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAC90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    lift_store32(cpu->esp + 0x1Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FACD1u); lift_push32(cpu, r); sfera_sub_0040D400(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FACDDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FACF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FACF0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD00u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD20u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD50u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD70u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD80u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAD90u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_server_wall;
    sfera_sub_0048A6A0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FADA0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAE10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAE20u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAE30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAE40u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = g_sfera_sound_effect_items.block_vector_end;
    cpu->eax = g_sfera_sound_effect_items.block_vector_begin;
    cpu->ecx -= cpu->eax;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000FAE8A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_effect_items;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAE85u); lift_push32(cpu, r); sfera_sub_004974B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_sound_effect_items.block_vector_begin;
    label_000FAE8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAE8Au);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000FAE97;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAE94u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000FAE97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAE97u);
    g_sfera_sound_effect_items.block_vector_begin = (uint32_t)(cpu->esi);
    g_sfera_sound_effect_items.block_vector_end = (uint32_t)(cpu->esi);
    g_sfera_sound_effect_items.block_vector_capacity_end = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAEC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAEC0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAED0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAEE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAEE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)(g_sfera_sound_runtime.tracks.first) == (uint32_t)(cpu->esi)) goto label_000FAF0F;
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_000FAEF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAEF0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000FAF07;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_runtime.tracks;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAF02u); lift_push32(cpu, r); sfera_sub_00498C30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_000FAF07: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF07u);
    if ((uint32_t)(g_sfera_sound_runtime.tracks.first) != (uint32_t)(cpu->esi)) goto label_000FAEF0;
    label_000FAF0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF0Fu);
    g_sfera_sound_runtime.tracks.last = (uint32_t)(cpu->esi);
    g_sfera_sound_runtime.tracks.first = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF20u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF50u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF60u);
    cpu->ecx = g_sfera_weather_runtime.sky_texture_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FAF72u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF80u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAF90u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAFA0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAFD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FAFD0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB000u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB010u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB040u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB070u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB080u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB090u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB0C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB0F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB100u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB130u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB160u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB170u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB1A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB1D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB1E0u);
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FB1F2;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB1EFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000FB1F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB1F2u);
    g_sfera_font_factory_runtime.fonts_begin = (uint32_t)(0u);
    g_sfera_font_factory_runtime.fonts_end = (uint32_t)(0u);
    g_sfera_font_factory_runtime.fonts_capacity = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB220u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB230u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB260u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB290u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB2A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB2B0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB2E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB310u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB320u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB350u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB380u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB390u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB3C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB3F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB400u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB430u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB460u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB470u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB4A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB4D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB4E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB510u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB540u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor) = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FB580;
    lift_push32(cpu, cpu->esi);
    label_000FB568: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB568u);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB570u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FB568;
    cpu->esi = lift_pop32(cpu);
    label_000FB580: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB580u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB586u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB590u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor) = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FB5D0;
    lift_push32(cpu, cpu->esi);
    label_000FB5B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB5B8u);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB5C0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FB5B8;
    cpu->esi = lift_pop32(cpu);
    label_000FB5D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB5D0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB5D6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB5E0u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count) = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FB620;
    lift_push32(cpu, cpu->esi);
    label_000FB608: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB608u);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB610u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FB608;
    cpu->esi = lift_pop32(cpu);
    label_000FB620: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB620u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB626u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB630u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB63Au); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB645u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head) = (uint32_t)(0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB660u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_10;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB66Au); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB675u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB680u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000FB6AE;
    cpu->eax = lift_load32(cpu->esp);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_core_runtime.object_aux);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB69Fu); lift_push32(cpu, r); sfera_sub_004BC000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FB6ABu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000FB6AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB6AEu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head) = (uint32_t)(0u);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count) = (uint32_t)(0u);
    lift_store32((uintptr_t)&g_sfera_interface_core_runtime.object_state, 0u);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB6D0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    sfera_sub_004BC9F0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB6E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB6F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB720u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB750u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB760u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB770u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB7A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB7D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB8D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB8E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB910u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB940u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB950u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB980u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB9B0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB9C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FB9D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBA00u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBA30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBA40u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBA70u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBAA0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBAB0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBAE0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBB10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBB20u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBB50u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBB80u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBB90u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBBC0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBBF0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBC00u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBC30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBC60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBC70u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBCA0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBCD0u);
    cpu->eax = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FBCE2;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FBCDFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000FBCE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBCE2u);
    g_sfera_options_dialog_runtime.chat_edit_fonts.begin = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_edit_fonts.end = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_edit_fonts.capacity_end = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBD10u);
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FBD22;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FBD1Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000FBD22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBD22u);
    g_sfera_options_dialog_runtime.chat_list_fonts.begin = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_list_fonts.end = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_list_fonts.capacity_end = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBD50u);
    cpu->eax = g_sfera_options_dialog_runtime.graphics_modes.begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FBD62;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FBD5Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000FBD62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBD62u);
    g_sfera_options_dialog_runtime.graphics_modes.begin = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.graphics_modes.end = (uint32_t)(0u);
    lift_store32((uintptr_t)&g_sfera_options_dialog_cleanup_state, 0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBD90u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBDA0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBDD0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBE00u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBE10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBE20u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBE50u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBE80u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBE90u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBEC0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBEF0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBF00u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBF30u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBF60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBF70u);
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx, cpu->ecx);
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    lift_store32(cpu->ecx + 4u, cpu->ecx);
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    g_sfera_win32_dialog_registry.size = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FBFB0;
    lift_push32(cpu, cpu->esi);
    label_000FBF98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBF98u);
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FBFA0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FBF98;
    cpu->esi = lift_pop32(cpu);
    label_000FBFB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBFB0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FBFB6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBFC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBFC0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBFD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FBFD0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC000u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC030u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_control_reference_registry;
    lift_store32(cpu->esp + 0x1Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FC071u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_control_reference_registry.sentinel;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4FC07Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC090u);
    cpu->eax = g_sfera_crash_report_runtime.previous_exception_filter;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetUnhandledExceptionFilter), LIFT_CODE_TOKEN_VA(0x4FC096u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC09Cu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC0A0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC0B0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC0C0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC0D0;
    label_000D78B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D78B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D793C;
    cpu->ebx = native_function_address32(&::DestroyCursor);
    label_000D78F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D78F0u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD78F6u), LIFT_CODE_TOKEN_RVA(0xD78F4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D78F6u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)(0u)) goto label_000D7937;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D791C;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D7937;
    (void)cpu;
    label_000D7910: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7910u);
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7910;
    goto label_000D7937;
    label_000D791C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D791Cu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D7935;
    label_000D7925: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7925u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000D7935;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7925;
    label_000D7935: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7935u);
    cpu->esi = cpu->eax;
    label_000D7937: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7937u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D78F0;
    label_000D793C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D793Cu);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7957u); lift_push32(cpu, r); sfera_sub_004D77E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7960u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_000FC0D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC0D0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    goto label_000D78B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC0E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC0F0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC100u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC110u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC120u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC130(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC130;
    label_000ED1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1A0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFD4u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1E5;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    goto label_000ED1EE;
    label_000ED1E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1E5u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    label_000ED1EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1EEu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1F9;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    label_000ED1F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1F9u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED200u); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED21Eu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED238u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED238: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED238u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED242u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED24Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED25Eu);
    cpu->esp += 0x18u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED26Eu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED27Cu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uint32_t)(uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED296u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED296: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED296u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2A0u);
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2B0u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2BEu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uint32_t)(uintptr_t)" *****\n");
    cpu->eax = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED2D8u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2D8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED2DFu); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    label_000ED2DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2DFu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2EDu); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED30D;
    label_000ED2F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2F1u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2F9u); lift_push32(cpu, r); sfera_sub_004EE4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED301u); lift_push32(cpu, r); sfera_sub_004ECE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED309u); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED2F1;
    label_000ED30D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED30Du);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED314u); lift_push32(cpu, r); sfera_sub_004ECBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED320u), LIFT_CODE_TOKEN_RVA(0xED31Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED320u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED326u), LIFT_CODE_TOKEN_RVA(0xED324u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED326u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED336;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED333u), LIFT_CODE_TOKEN_RVA(0xED331u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED333u);
    cpu->esp += 4u;
    label_000ED336: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED336u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED343;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED340u), LIFT_CODE_TOKEN_RVA(0xED33Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED340u);
    cpu->esp += 4u;
    label_000ED343: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED343u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED350;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED34Du), LIFT_CODE_TOKEN_RVA(0xED34Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED34Du);
    cpu->esp += 4u;
    label_000ED350: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED350u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED35Fu); lift_push32(cpu, r); sfera_sub_004EE470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000FC130: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC130u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC140(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC140;
    label_000ED1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1A0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFD4u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1E5;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    goto label_000ED1EE;
    label_000ED1E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1E5u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    label_000ED1EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1EEu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1F9;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    label_000ED1F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1F9u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED200u); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED21Eu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED238u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED238: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED238u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED242u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED24Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED25Eu);
    cpu->esp += 0x18u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED26Eu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED27Cu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uint32_t)(uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED296u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED296: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED296u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2A0u);
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2B0u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2BEu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uint32_t)(uintptr_t)" *****\n");
    cpu->eax = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED2D8u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2D8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED2DFu); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    label_000ED2DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2DFu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2EDu); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED30D;
    label_000ED2F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2F1u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2F9u); lift_push32(cpu, r); sfera_sub_004EE4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED301u); lift_push32(cpu, r); sfera_sub_004ECE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED309u); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED2F1;
    label_000ED30D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED30Du);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED314u); lift_push32(cpu, r); sfera_sub_004ECBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED320u), LIFT_CODE_TOKEN_RVA(0xED31Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED320u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED326u), LIFT_CODE_TOKEN_RVA(0xED324u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED326u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED336;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED333u), LIFT_CODE_TOKEN_RVA(0xED331u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED333u);
    cpu->esp += 4u;
    label_000ED336: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED336u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED343;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED340u), LIFT_CODE_TOKEN_RVA(0xED33Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED340u);
    cpu->esp += 4u;
    label_000ED343: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED343u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED350;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED34Du), LIFT_CODE_TOKEN_RVA(0xED34Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED34Du);
    cpu->esp += 4u;
    label_000ED350: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED350u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED35Fu); lift_push32(cpu, r); sfera_sub_004EE470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000FC140: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC140u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_warnings_object;
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC150(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC150;
    label_000ED1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1A0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFD4u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1E5;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    goto label_000ED1EE;
    label_000ED1E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1E5u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    label_000ED1EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1EEu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1F9;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    label_000ED1F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED1F9u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED200u); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED21Eu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED238u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED238: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED238u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED242u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED24Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED25Eu);
    cpu->esp += 0x18u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED26Eu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED27Cu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uint32_t)(uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED296u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED296: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED296u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2A0u);
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2B0u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2BEu); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uint32_t)(uintptr_t)" *****\n");
    cpu->eax = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED2D8u); lift_push32(cpu, r); sfera_sub_004EC770(cpu,r); if (cpu->eip != r) return; }
    label_000ED2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2D8u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xED2DFu); lift_push32(cpu, r); sfera_sub_004ECF60(cpu,r); if (cpu->eip != r) return; }
    label_000ED2DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2DFu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2EDu); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED30D;
    label_000ED2F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED2F1u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED2F9u); lift_push32(cpu, r); sfera_sub_004EE4D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED301u); lift_push32(cpu, r); sfera_sub_004ECE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED309u); lift_push32(cpu, r); sfera_sub_004EE4B0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED2F1;
    label_000ED30D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED30Du);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED314u); lift_push32(cpu, r); sfera_sub_004ECBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED320u), LIFT_CODE_TOKEN_RVA(0xED31Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED320u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED326u), LIFT_CODE_TOKEN_RVA(0xED324u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED326u);
    cpu->eax = lift_load32(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED336;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED333u), LIFT_CODE_TOKEN_RVA(0xED331u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED333u);
    cpu->esp += 4u;
    label_000ED336: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED336u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED343;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED340u), LIFT_CODE_TOKEN_RVA(0xED33Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED340u);
    cpu->esp += 4u;
    label_000ED343: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED343u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED350;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED34Du), LIFT_CODE_TOKEN_RVA(0xED34Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED34Du);
    cpu->esp += 4u;
    label_000ED350: cpu->eip = LIFT_CODE_TOKEN_VA(0x4ED350u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4ED35Fu); lift_push32(cpu, r); sfera_sub_004EE470(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000FC150: cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC150u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC15A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4FC15Au);
    g_sfera_crt_startup_runtime.dynamic_tls_dtor_callbacks = 0u;
    lift_return(cpu, 0u, stop_address); return;
}
