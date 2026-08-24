#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43DB(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x54u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43E6(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x70u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43F1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0xA0u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43FF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0xACu;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F440D(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F440D;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F440D:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0xBCu;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F441B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->ecx += 0x178u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4459u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4459u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F445B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4464u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4464u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4466(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F446Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F446Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4471(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F447Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F447Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F447C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4485u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4485u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4487(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4490u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4490u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4492(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F449Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F449Bu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F449D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44A6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44A6u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44A8(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44B1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44B1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44B3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44BCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44BCu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44BE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44C7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44C7u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44C9(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44D2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44D2u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44D4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44DDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44DDu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44DF(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44E8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44E8u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44EA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44F3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44F3u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44F5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F44FEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F44FEu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4509u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4509u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F450B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4514u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4514u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4516(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F451Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F451Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4521(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F452Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F452Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F452C(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4535u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4535u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4537(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4540u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4540u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4542(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F454Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F454Bu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F454D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4556u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F4556u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFECCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F458Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F458Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F45C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFEB4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F45CCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F45CCu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F45CE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFEC0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F45DAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F45DAu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 8u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F461B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x54u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4626(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x70u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4631(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xA0u;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F463F(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xACu;
    sfera_sub_00416610(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F464D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4F464Du), "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4656(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4656;
    label_000B9CE0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4B9CE8u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4B9CF0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F4656:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0xBCu;
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4664(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    cpu->ecx += 0x178u;
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4672(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_control_reference_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_control_reference_registry_guard = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46A0;
    label_000161C0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F46A0:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_control_reference_registry;
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46D0;
    label_000D67A0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_VA(0x4D67A7u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F46D0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBB8u);
    goto label_000D67A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46DB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46DB;
    label_000D67B0:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_VA(0x4D67B3u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F46DB:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBECu);
    goto label_000D67B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46E6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46E6;
    label_000D67C0:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_VA(0x4D67C3u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F46E6:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBACu);
    goto label_000D67C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46F1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46F1;
    label_000D67D0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D67D7u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F46F1:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBA4u);
    goto label_000D67D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46FC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46FC;
    label_000D67C0:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DeleteObject), LIFT_CODE_TOKEN_VA(0x4D67C3u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F46FC:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBC4u);
    goto label_000D67C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4707(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4707;
    label_000D67D0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D67D7u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F4707:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFBE4u);
    goto label_000D67D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F474Du)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4F474Du));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFACu);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4778(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC8u);
    sfera_sub_004061B0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47B0;
    label_000161C0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4161C9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F47B0:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47E0;
    label_000D7B40:
    std::construct_at(reinterpret_cast<CCursor*>(cpu->ecx));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F47E0:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    goto label_000D7B40;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_cursor_texture_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_texture_registry_guard = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F481E(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_cursor_texture_registry_guard;
    cpu->eax &= 0xFFFFFFFEu;
    g_sfera_cursor_texture_registry_guard = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4850;
    label_000DA550:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    std::construct_at(reinterpret_cast<UnmanagedResourceVector*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA564u)); sfera_sub_004D9E80(cpu, LIFT_CODE_TOKEN_VA(0x4DA564u));
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA56Du)); sfera_sub_004D98D0(cpu, LIFT_CODE_TOKEN_VA(0x4DA56Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA58B;
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    label_000DA58B:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F4850:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x178u;
    goto label_000DA550;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F48C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF28u);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF28u);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF2Cu);
    sfera_sub_004ED8E0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFBECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F498Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4F498Cu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49C0;
    label_000EA960:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EA98F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EA97E;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EA977u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EA97E:
    if (*(uint32_t*)(cpu->ecx + 4u) != (uint32_t)(1u)) goto label_000EA98F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEA989u));
    label_000EA98F:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F49C0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE4u);
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49F0;
    label_000EA960:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EA98F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EA97E;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EA977u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EA97E:
    if (*(uint32_t*)(cpu->ecx + 4u) != (uint32_t)(1u)) goto label_000EA98F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEA989u));
    label_000EA98F:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F49F0:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4A20;
    label_000EA960:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000EA98F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000EA97E;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    g_sfera_memory_runtime.lock_held = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x4EA977u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EA97E:
    if (*(uint32_t*)(cpu->ecx + 4u) != (uint32_t)(1u)) goto label_000EA98F;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_RVA(0xEA989u));
    label_000EA98F:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F4A20:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->ecx += 0x38u;
    sfera_sub_004EE470(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    cpu->ecx += 0x38u;
    sfera_sub_004EE470(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)"logs\\CurrentExecuting.log"); lift_push32(cpu, (uintptr_t)&g_sfera_execution_monitor_runtime.log_path[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4F4E6Au));
    cpu->esp += 8u;
    lift_push32(cpu, 4u);
    lift_native_call(cpu, native_function_address32(&::SymSetOptions), LIFT_CODE_TOKEN_VA(0x4F4E75u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4F4E7Fu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4F4E86u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA0D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4E96u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F4E96u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4EA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4FFAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F4FFAu));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F503D;
    g_sfera_effect_manager.effect_listeners.sentinel = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    *(uint8_t*)(cpu->ecx + 0x14u) = cpu->eax & 0xFFu;
    cpu->edx = g_sfera_effect_manager.effect_listeners.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA1F0));
    *(uint8_t*)(cpu->edx + 0x15u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5036u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5036u));
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F503D:
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F506Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F506Au));
    lift_trap(cpu, 0x4F506Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5070(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x17CDC0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5081u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5081u));
    lift_push32(cpu, 0x17CDC0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_effect_manager.render_slots.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F508Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    g_sfera_effect_manager.render_slots.capacity = (uint32_t)(0x2710u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F50ACu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F50ACu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_effect_manager.render_slots.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F50B2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA150));
    g_sfera_effect_manager.render_slots.debug_file[15] = '\0';
    g_sfera_effect_manager.render_slots.debug_line = UINT32_C(125);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F50D3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F50D3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA170));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F50EAu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F50EAu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F51DEu)); sfera_sub_0042E540(cpu, LIFT_CODE_TOKEN_VA(0x4F51DEu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA270));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F51E8u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F51E8u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5201u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5201u));
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_file_runtime.open_files.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F520Bu));
    cpu->esp += 0xCu;
    cpu->eax = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    g_sfera_file_runtime.open_files.capacity = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.open_files.maximum = UINT32_C(100);
    g_sfera_file_runtime.open_files.growth = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.open_files.element_size = UINT32_C(8);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5242u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5242u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_file_runtime.open_files.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5248u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA280));
    g_sfera_file_runtime.open_files.debug_file[15] = 0;
    g_sfera_file_runtime.open_files.debug_line = UINT32_C(25);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5269u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5269u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5281u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5281u));
    g_sfera_file_runtime.search_paths.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    cpu->eax = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    g_sfera_file_runtime.search_paths.capacity = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.search_paths.maximum = UINT32_C(100);
    g_sfera_file_runtime.search_paths.growth = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.search_paths.element_size = UINT32_C(4);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5305u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5305u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_file_runtime.search_paths.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F530Bu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA2A0));
    g_sfera_file_runtime.search_paths.debug_file[15] = 0;
    g_sfera_file_runtime.search_paths.debug_line = UINT32_C(27);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F532Cu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F532Cu));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].transform;
    g_sfera_spatial_states[0u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5467u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F5467u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA340));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5471u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5471u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F54B9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F54B9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].transform;
    g_sfera_spatial_states[1u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F54D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F54D7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA350));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F54E1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F54E1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5529u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F5529u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5570(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5570;
    label_00021FC0:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4014u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x421FCBu));
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x421FDBu));
    cpu->esp += 0x18u;
    *(uint32_t*)(cpu->esi + 0x4008u) = 0xFFFFFFFFu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5570:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    goto label_00021FC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5580;
    label_000016E0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"";
    cpu->esi = cpu->eax;
    cpu->esi -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000016F0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edx)) & 0xFFu);
    *(uint8_t*)(cpu->esi + cpu->edx) = cpu->ebx & 0xFFu;
    ++cpu->edx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000016F0;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5580:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    goto label_000016E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5590(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, 0.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (40.0);
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.inverse_40) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].transform;
    g_sfera_spatial_states[2u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F55C7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F55C7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA3D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F55D1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F55D1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5619u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F5619u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5631u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5631u));
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[2].data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F563Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].capacity) = 0x7Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F565Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F565Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5662u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA3E0));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_line) = 0x3A6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5683u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5683u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5690(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F56A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F56A1u));
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[1].data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F56AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].capacity) = 0x7Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F56CCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F56CCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F56D2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA400));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_line) = 0x3A7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F56F3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F56F3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5711u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5711u));
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[0].data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F571Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].capacity) = 0x7Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F573Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F573Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5742u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA420));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_line) = 0x3A8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5763u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5763u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].transform;
    g_sfera_spatial_states[3u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5787u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F5787u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA440));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5791u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5791u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F57D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F57D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].transform;
    g_sfera_spatial_states[4u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F57F7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F57F7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA450));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5801u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5801u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5849u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F5849u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F58A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F58A1u));
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.secondary_auto_array.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F58AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.capacity) = 0x1F4u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.maximum) = 0x1388u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.growth) = 0x64u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F58EAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F58EAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F58F0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA470));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_line) = 0xE6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5911u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5911u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5920(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4650u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5931u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5931u));
    lift_push32(cpu, 0x4650u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e7_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F593Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e7_records.capacity) = 0x1F4u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e7_records.maximum) = 0x1388u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e7_records.growth) = 0x64u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e7_records.element_size) = 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F597Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F597Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5980u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA490));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_line) = 0xE7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F59A1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F59A1u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F59B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F59C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F59C1u));
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e8_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F59CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e8_indices.capacity) = 0x1F4u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e8_indices.maximum) = 0x1388u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e8_indices.growth) = 0x64u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e8_indices.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5A0Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5A0Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5A10u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA4B0));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_line) = 0xE8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5A31u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5A31u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x320u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5A51u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5A51u));
    lift_push32(cpu, 0x320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e9_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5A5Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e9_indices.capacity) = 0xC8u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e9_indices.maximum) = 0x1F4u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e9_indices.growth) = 0x64u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e9_indices.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5A9Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5A9Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5AA0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA4D0));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_line) = 0xE9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5AC1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5AC1u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5AD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x109A0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5AE1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5AE1u));
    lift_push32(cpu, 0x109A0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.eb_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5AEEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.eb_records.capacity) = 0x1F4u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.eb_records.maximum) = 0x3E8u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.eb_records.growth) = 0x32u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.eb_records.element_size) = 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5B2Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5B2Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5B30u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA4F0));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_line) = 0xEBu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5B51u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5B51u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5B60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5B71u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5B71u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.ed_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5B7Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.ed_indices.capacity) = 0x32u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.ed_indices.maximum) = 0xC8u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.ed_indices.growth) = 0x14u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.ed_indices.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5BBAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5BBAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5BC0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA510));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_line) = 0xEDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5BE1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5BE1u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5BF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5C01u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5C01u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.contact_objects.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5C0Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.contact_objects.capacity = (uint32_t)(0x32u);
    g_sfera_collision_runtime.contact_objects.maximum = 0x2710u;
    g_sfera_collision_runtime.contact_objects.growth = 0x14u;
    g_sfera_collision_runtime.contact_objects.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5C4Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5C4Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5C50u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA530));
    *(uint8_t*)((uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[15]) = 0u;
    g_sfera_collision_runtime.contact_objects.debug_line = 0xEFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5C71u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5C71u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5C80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5C80;
    label_0004B620:
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    cpu->eax &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(float*)(cpu->eax) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u];
    cpu->ebx = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->ecx + 8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->edx + 0xCu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->eax + 0x10u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->ecx + 0x14u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->edx + 0x18u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->eax + 0x1Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->ecx + 0x20u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->edx + 0x24u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->eax + 0x28u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->ecx + 0x2Cu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->edx + 0x30u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->eax + 0x34u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->ecx + 0x38u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->edx + 0x3Cu) = cpu->fpu[0u];
    cpu->eax = (uint32_t)(cpu->esi + 0x13Bu);
    *(float*)(cpu->esi + 0x50u) = cpu->fpu[0u];
    cpu->eax &= 0xFFFFFFF0u;
    lift_x87_push(cpu, (double)100.0f);
    cpu->ecx = (uint32_t)(cpu->esi + 0x32Fu);
    *(float*)(cpu->esi + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x74u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x78u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x7Cu) = 0x280u;
    *(float*)(cpu->esi + 0x58u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x80u) = 0x1E0u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->ecx &= 0xFFFFFFF0u;
    *(float*)(cpu->esi + 0x6Cu) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)0.9999899864196777f);
    *(float*)(cpu->esi + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.75f);
    *(float*)(cpu->esi + 0x94u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x31Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x510u) = cpu->ecx;
    *(float*)(cpu->esi + 0x550u) = cpu->fpu[0u];
    *(uint16_t*)(cpu->esi + 0x564u) = cpu->ebx & 0xFFFFu;
    *(float*)(cpu->esi + 0x554u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint8_t*)(cpu->esi + 0x566u) = cpu->ebx & 0xFFu;
    *(float*)(cpu->esi + 0x558u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x55Cu) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x560u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B729u)); sfera_sub_004EED54(cpu, LIFT_CODE_TOKEN_VA(0x44B729u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(uint32_t*)(cpu->esi + 0x514u) = cpu->ebx;
    *(float*)(cpu->esi + 0x98u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esi + 0x51Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x524u) = cpu->eax;
    cpu->eax = 3u;
    cpu->edx = 4u;
    cpu->ecx = 2u;
    *(uint32_t*)(cpu->esi + 0x534u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x53Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x548u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x520u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x52Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x538u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x88u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x8Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x518u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x528u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x530u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x540u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x544u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x54Cu) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5C80:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    goto label_0004B620;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5C90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5CA1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5CA1u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_102_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5CAEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.capacity) = 0x32u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.maximum) = 0x64u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.growth) = 0x14u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5CEAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5CEAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5CF0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA550));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_line) = 0x102u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5D11u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5D11u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5D31u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5D31u));
    lift_push32(cpu, 0x3200u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_105_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5D3Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_105_records.capacity) = 0xC8u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_105_records.maximum) = 0x1F4u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_105_records.growth) = 0x64u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_105_records.element_size) = 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5D7Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5D7Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5D80u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA570));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_line) = 0x105u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5DA1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5DA1u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.object_01[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5DBAu)); sfera_sub_0048A1A0(cpu, LIFT_CODE_TOKEN_VA(0x4F5DBAu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA460));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5DC4u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5DC4u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5DD0;
    label_0009B950:
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B967u)); sfera_sub_0049B860(cpu, LIFT_CODE_TOKEN_VA(0x49B967u));
    lift_push32(cpu, 0x5320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49B96Fu));
    cpu->eax = 0x6E726157u;
    cpu->ecx = 0x73676E69u;
    cpu->edx = 0x6C2E3030u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x676F)) & 0xFFFFu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint16_t*)(cpu->esp + 0x14u) = cpu->eax & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0x16u) = cpu->ecx & 0xFFu;
    lift_flags_logic(cpu,0u,32u); cpu->ebx = 0u;
    label_0009B9B0:
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 0u);
    cpu->edx >>= 3u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->edx + 0x30u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->ebx & 0xFFu)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint8_t*)(cpu->esp + 0x11u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B9DEu)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x49B9DEu));
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xF4240u)) goto label_0009B9F3;
    cpu->edx = 0xF4240u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B9F3u)); sfera_sub_0044C020(cpu, LIFT_CODE_TOKEN_RVA(0x9B9F3u));
    label_0009B9F3:
    ++cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009B9B0;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5DD0:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    goto label_0009B950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5DF1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5DF1u));
    lift_push32(cpu, 0x9C40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_light_ids.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5DFEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_light_ids.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5E1Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5E1Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5E22u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA590));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_line) = 0x16Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5E43u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5E43u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5E50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7F710u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5E61u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5E61u));
    lift_push32(cpu, 0x7F710u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_landscape_runtime.file_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5E6Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_runtime.file_records.capacity = (uint32_t)(0x12Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5E8Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5E8Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5E92u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA5B0));
    g_sfera_landscape_runtime.file_records.debug_file[15] = 0;
    g_sfera_landscape_runtime.file_records.debug_line = 0x171u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5EB3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5EB3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5EC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x6D60u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5ED1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5ED1u));
    lift_push32(cpu, 0x6D60u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_interface_runtime.window_handle_table.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5EDEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_interface_runtime.window_handle_table.capacity = (uint32_t)(0x1B58u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5EFCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5EFCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5F02u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA5D0));
    *(uint8_t*)((uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_line) = 0x193u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5F23u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5F23u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5F30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E8480u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5F41u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5F41u));
    lift_push32(cpu, 0x1E8480u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_world_objects.object_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5F4Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_world_objects.object_handles.capacity = (uint32_t)(0x7A120u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5F6Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5F6Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5F72u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA5F0));
    g_sfera_world_objects.object_handles.debug_file[15] = 0;
    g_sfera_world_objects.object_handles.debug_line = 0x1A2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5F93u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F5F93u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1D4C0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5FB1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5FB1u));
    lift_push32(cpu, 0x1D4C0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_world_objects.extended_object_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5FBEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_world_objects.extended_object_handles.capacity = (uint32_t)(0x7530u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5FDCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5FDCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5FE2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA610));
    g_sfera_world_objects.extended_object_handles.debug_file[15] = 0;
    g_sfera_world_objects.extended_object_handles.debug_line = 0x1A5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6003u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6003u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x190u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6021u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6021u));
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_interface_runtime.windows.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F602Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_interface_runtime.windows.capacity = (uint32_t)(0x64u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F604Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F604Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6052u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA630));
    g_sfera_interface_runtime.windows.debug_file[15] = 0;
    g_sfera_interface_runtime.windows.debug_line = 0x1A9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6073u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6073u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6091u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6091u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_character_index_map.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F609Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_character_index_map.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F60BCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F60BCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_character_index_map.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F60C2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA650));
    g_sfera_character_index_map.debug_file[15] = '\0';
    g_sfera_character_index_map.debug_line = 0x1BFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F60E3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F60E3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F60F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6101u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6101u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_visibility_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F610Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_visibility_indices.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F612Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F612Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6132u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA670));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_line) = 0x1C0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6153u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6153u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6171u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6171u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_sort_keys.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F617Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_sort_keys.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F619Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F619Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F61A2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA690));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_line) = 0x1C3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F61C3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F61C3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F61D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F61E1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F61E1u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_sort_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F61EEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_sort_indices.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F620Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F620Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6212u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA6B0));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_line) = 0x1C4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6233u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6233u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6251u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6251u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_draw_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F625Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_draw_indices.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F627Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F627Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6282u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA6D0));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_line) = 0x1C5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F62A3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F62A3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F62B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F62C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F62C1u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.candidate_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F62CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.candidate_handles.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F62ECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F62ECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F62F2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA6F0));
    g_sfera_collision_runtime.candidate_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.candidate_handles.debug_line = 0x1C6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6313u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6313u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6320(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x54F60u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6331u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6331u));
    lift_push32(cpu, 0x54F60u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.scene_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F633Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.scene_records.capacity = (uint32_t)(0xBB8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F635Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F635Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6362u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA710));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_line) = 0x1E3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6383u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6383u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xF0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F63A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F63A1u));
    lift_push32(cpu, 0xF0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.reflection_targets.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F63AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.reflection_targets.capacity = (uint32_t)(0xAu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F63CCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F63CCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F63D2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA730));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_line) = 0x236u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F63F3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F63F3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x2A30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6411u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6411u));
    lift_push32(cpu, 0x2A30u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.scene_points.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F641Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.scene_points.capacity = (uint32_t)(0x384u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F643Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F643Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6442u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA750));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_line) = 0x33Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6463u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6463u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6481u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6481u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29) = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_config_runtime.text_length_01) = 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F64E4u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F64E4u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.text_01[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F64EAu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA770));
    *(uint8_t*)((uintptr_t)&g_sfera_client_config_runtime.text_01[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_config_runtime.text_capacity_01) = 0x633u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F650Bu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F650Bu));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x400u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6521u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6521u));
    lift_push32(cpu, 0x400u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30) = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F652Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_config_runtime.text_length_02) = 0x100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F654Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F654Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.text_02[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6552u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA790));
    *(uint8_t*)((uintptr_t)&g_sfera_client_config_runtime.text_02[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_config_runtime.text_capacity_02) = 0x6B0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6573u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6573u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6580(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6591u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6591u));
    g_sfera_client_array_runtime.line_6b1_indices.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.capacity) = 0xAu;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.maximum) = 0x14u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.growth) = 5u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F661Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F661Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6620u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA7B0));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_line) = 0x6B1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6641u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6641u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6650(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6661u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6661u));
    g_sfera_recovered_static_runtime.primary_auto_array.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.capacity) = 0xAu;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.maximum) = 0x14u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.growth) = 5u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F66EAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F66EAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F66F0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA7D0));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_line) = 0x6B2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6711u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6711u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6731u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6731u));
    g_sfera_client_array_runtime.line_6b3_indices.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.capacity) = 0xAu;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.maximum) = 0x14u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.growth) = 5u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F67BAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F67BAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F67C0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA7F0));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_line) = 0x6B3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F67E1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F67E1u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F67F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6801u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6801u));
    g_sfera_client_array_runtime.line_6b4_indices.data = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.capacity) = 0xAu;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.maximum) = 0x14u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.growth) = 5u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.element_size) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F688Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F688Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6890u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA810));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_line) = 0x6B4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F68B1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F68B1u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F68C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F68D1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F68D1u));
    lift_push32(cpu, 0x1E0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_6b5_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F68DEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.capacity) = 0xAu;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.maximum) = 0x14u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.growth) = 5u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.element_size) = 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F691Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F691Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6920u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA830));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_line) = 0x6B5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6941u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6941u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6950(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x240u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6961u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6961u));
    lift_push32(cpu, 0x240u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F696Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_indices.capacity = (uint32_t)(0x90u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F698Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F698Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6992u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA850));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_light_runtime.cell_indices.debug_line) = 0x1247u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F69B3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F69B3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F69C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3600u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F69D1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F69D1u));
    lift_push32(cpu, 0x3600u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F69DEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_records.capacity = (uint32_t)(0x90u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F69FCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F69FCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6A02u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA870));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_light_runtime.cell_records.debug_line) = 0x1248u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6A23u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6A23u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6A30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6A41u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6A41u));
    lift_push32(cpu, 0x9C40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_landscape_runtime.microtexture_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6A4Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_runtime.microtexture_handles.capacity = (uint32_t)(0x2710u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6A6Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6A6Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6A72u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA890));
    *(uint8_t*)((uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_line) = 0x124Au;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6A93u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6A93u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6AA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6AB1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6AB1u));
    lift_push32(cpu, 0x1F40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6ABEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_handles.capacity = (uint32_t)(0x7D0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6ADCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6ADCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6AE2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA8B0));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_line) = 0x124Bu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B03u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6B03u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xB7980u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B21u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6B21u));
    lift_push32(cpu, 0xB7980u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_124d_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6B2Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_124d_records.capacity) = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B4Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6B4Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6B52u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA8D0));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_line) = 0x124Du;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B73u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6B73u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA00u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B91u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6B91u));
    lift_push32(cpu, 0xFA00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.tertiary_auto_array.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6B9Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.capacity) = 0x7D0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.maximum) = 0xBB8u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.growth) = 0x1F4u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.element_size) = 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6BDAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6BDAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6BE0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA8F0));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_line) = 0x124Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C01u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6C01u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C21u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6C21u));
    lift_push32(cpu, 0x30u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_pass_slots.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6C2Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_pass_slots.capacity = (uint32_t)(0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C49u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6C49u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6C4Fu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA910));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_line) = 0x125Bu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C70u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6C70u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x61A80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C91u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6C91u));
    lift_push32(cpu, 0x61A80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6C9Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_records.capacity = (uint32_t)(0x2710u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6CBCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6CBCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6CC2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA930));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_line) = 0x1264u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6CE3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6CE3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D01u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6D01u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_index_map.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6D0Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_index_map.capacity = (uint32_t)(0x9C40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D2Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6D2Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6D32u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA950));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_line) = 0x1266u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D53u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6D53u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6D60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D71u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6D71u));
    lift_push32(cpu, 0xFA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6D7Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.handles.capacity = (uint32_t)(0x3E8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D9Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6D9Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6DA2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA970));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.handles.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_light_runtime.handles.debug_line) = 0x127Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6DC3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6DC3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6DD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6DE1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6DE1u));
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.visible_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6DEEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.visible_handles.capacity = (uint32_t)(0x1F4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6E0Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6E0Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6E12u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA990));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_light_runtime.visible_handles.debug_line) = 0x1280u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6E33u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6E33u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6E40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6E51u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6E51u));
    lift_push32(cpu, 0x7Cu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.active_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6E5Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.active_handles.capacity = (uint32_t)(0x1Fu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6E79u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6E79u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6E7Fu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA9B0));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_light_runtime.active_handles.debug_line) = 0x1282u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6EA0u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6EA0u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6EB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3E8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6EC1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6EC1u));
    lift_push32(cpu, 0x3E8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_mesh_partition_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6ECEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_mesh_partition_indices.capacity = (uint32_t)(0x1F4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6EECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6EECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6EF2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA9D0));
    g_sfera_mesh_partition_indices.debug_file[15] = '\0';
    g_sfera_mesh_partition_indices.debug_line = 0x1392u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6F13u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6F13u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6F2Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F6F2Au));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F6F6D;
    g_sfera_model_registry_runtime.sentinel = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    *(uint8_t*)(cpu->ecx + 0x2Cu) = cpu->eax & 0xFFu;
    cpu->edx = g_sfera_model_registry_runtime.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAC90));
    *(uint8_t*)(cpu->edx + 0x2Du) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6F66u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F6F66u));
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F6F6D:
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6F9Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F6F9Au));
    lift_trap(cpu, 0x4F6F9Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x23280u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6FB1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6FB1u));
    lift_push32(cpu, 0x23280u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24de_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6FBEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24de_records.capacity) = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6FDCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6FDCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6FE2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA9F0));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_line) = 0x24DEu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7003u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7003u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x21D68u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7021u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7021u));
    lift_push32(cpu, 0x21D68u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e0_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F702Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.capacity) = 0x26ACu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F704Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F704Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7052u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA10));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_line) = 0x24E0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7073u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7073u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D00u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7091u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7091u));
    lift_push32(cpu, 0x7D00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e2_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F709Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.capacity) = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F70BCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F70BCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F70C2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA30));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_line) = 0x24E2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F70E3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F70E3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F70F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4000u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7101u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7101u));
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.model_matrices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F710Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.model_matrices.capacity = (uint32_t)(0x100u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F712Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F712Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7132u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA50));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_line) = 0x24EBu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7153u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7153u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x140u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7171u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7171u));
    lift_push32(cpu, 0x140u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.character_matrices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F717Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.character_matrices.capacity = (uint32_t)(5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F719Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F719Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F71A2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA70));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_line) = 0x24F1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F71C3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F71C3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F71D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1D4C0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F71E1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F71E1u));
    lift_push32(cpu, 0x1D4C0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_positions.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F71EEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_positions.capacity = (uint32_t)(0x2710u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F720Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F720Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7212u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAA90));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_line) = 0x2539u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7233u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7233u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x960u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7251u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7251u));
    lift_push32(cpu, 0x960u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_vectors.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F725Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_vectors.capacity = (uint32_t)(0xC8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F727Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F727Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7282u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAAB0));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_line) = 0x2A71u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F72A3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F72A3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F72B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x320u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F72C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F72C1u));
    lift_push32(cpu, 0x320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F72CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_indices.capacity = (uint32_t)(0xC8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F72ECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F72ECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F72F2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAAD0));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_line) = 0x2A77u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7313u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7313u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7320(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7331u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7331u));
    lift_push32(cpu, 0x1E0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_points.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F733Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_points.capacity = (uint32_t)(0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F735Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F735Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7362u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAAF0));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_line) = 0x2A84u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7383u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7383u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x27100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F73A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F73A1u));
    lift_push32(cpu, 0x27100u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.cloud_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F73AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.cloud_records.capacity = (uint32_t)(0x7D0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F73CCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F73CCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F73D2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB10));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_line) = 0x2A85u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F73F3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F73F3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7411u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7411u));
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.near_result_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F741Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.near_result_handles.capacity = (uint32_t)(0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7439u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F7439u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F743Fu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB30));
    g_sfera_collision_runtime.near_result_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.near_result_handles.debug_line = 0x2A86u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7460u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7460u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4C5BDA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7481u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7481u));
    lift_push32(cpu, 0x4C5BDA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.world_cell_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F748Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.world_cell_records.capacity = (uint32_t)(0x1F4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F74ACu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F74ACu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F74B2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB50));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_line) = 0x2A94u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F74D3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F74D3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F74E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F74F1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F74F1u));
    lift_push32(cpu, 0xFA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_ranges.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F74FEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_ranges.capacity = (uint32_t)(0x1F4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F751Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F751Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7522u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB70));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_line) = 0x3C0Du;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7543u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7543u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7550(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C400u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7561u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7561u));
    lift_push32(cpu, 0x9C400u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_work_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F756Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_work_records.capacity = (uint32_t)(0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F758Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F758Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7592u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAB90));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_line) = 0x3C0Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F75B3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F75B3u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F75C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x168u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F75D1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F75D1u));
    lift_push32(cpu, 0x168u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.type_records.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F75DEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.type_records.capacity = (uint32_t)(0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F75FCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F75FCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7602u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FABB0));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_grass_runtime.type_records.debug_line) = 0x4409u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7623u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7623u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7630(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xBB80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7641u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7641u));
    lift_push32(cpu, 0xBB80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.instance_offsets.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F764Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.instance_offsets.capacity = (uint32_t)(0x2EE0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F766Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F766Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7672u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FABD0));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_line) = 0x440Au;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7693u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7693u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F76A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xBB80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F76B1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F76B1u));
    lift_push32(cpu, 0xBB80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.instance_indices.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F76BEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.instance_indices.capacity = (uint32_t)(0x2EE0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F76DCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F76DCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F76E2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FABF0));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_line) = 0x440Bu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7703u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7703u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7710(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7721u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7721u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.model_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F772Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.model_handles.capacity = (uint32_t)(0x32u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F774Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F774Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7752u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAC10));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_grass_runtime.model_handles.debug_line) = 0x440Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7773u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7773u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].transform;
    g_sfera_spatial_states[5u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7797u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7797u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FACF0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F77A1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F77A1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F77E9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F77E9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].transform;
    g_sfera_spatial_states[6u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7807u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7807u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD00));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7811u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7811u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7859u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7859u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].transform;
    g_sfera_spatial_states[7u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7877u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7877u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD10));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7881u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7881u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F78C9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F78C9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F78D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].transform;
    g_sfera_spatial_states[8u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F78E7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F78E7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD20));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F78F1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F78F1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7939u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7939u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].transform;
    g_sfera_spatial_states[9u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7957u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7957u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD30));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7961u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7961u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F79A9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F79A9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].transform;
    g_sfera_spatial_states[10u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F79C7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F79C7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD40));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F79D1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F79D1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7A19u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7A19u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].transform;
    g_sfera_spatial_states[11u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7A37u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7A37u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD50));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7A41u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7A41u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7A89u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7A89u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].transform;
    g_sfera_spatial_states[12u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7AA7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7AA7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD60));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7AB1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7AB1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7AF9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7AF9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].transform;
    g_sfera_spatial_states[13u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B17u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7B17u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD70));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B21u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7B21u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B69u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7B69u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].transform;
    g_sfera_spatial_states[14u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7B87u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD80));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B91u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7B91u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7BD9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7BD9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAD90));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7BEAu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7BEAu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_shadow_object_storage[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_shadow_runtime.aligned_global_object;
    g_sfera_shadow_runtime.aligned_global_object = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7C07u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7C07u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FADA0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7C11u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7C11u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_shadow_object_storage[0x60];
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7C59u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7C59u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].transform;
    g_sfera_spatial_states[15u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7CB7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7CB7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE10));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7CC1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7CC1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D09u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7D09u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].transform;
    g_sfera_spatial_states[16u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D27u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7D27u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE20));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D31u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7D31u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D79u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7D79u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].transform;
    g_sfera_spatial_states[17u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D97u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7D97u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE30));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7DA1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7DA1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7DE9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7DE9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAE40));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7DFAu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7DFAu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].transform;
    g_sfera_spatial_states[18u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E17u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7E17u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAEC0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E21u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7E21u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E69u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7E69u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].transform;
    g_sfera_spatial_states[19u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7E87u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAED0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E91u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7E91u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7ED9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7ED9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAEE0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7EEAu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7EEAu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].transform;
    g_sfera_spatial_states[20u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F07u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7F07u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF20));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F11u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7F11u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F59u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7F59u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].transform;
    g_sfera_spatial_states[21u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F77u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7F77u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF30));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F81u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7F81u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7FC9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7FC9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].transform;
    g_sfera_spatial_states[22u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7FE7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7FE7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF40));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7FF1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F7FF1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8039u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8039u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].transform;
    g_sfera_spatial_states[23u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8057u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8057u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF50));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8061u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8061u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F80A9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F80A9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F80B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x190u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F80C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F80C1u));
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_weather_runtime.sky_texture_handles.data = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F80CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\WeatherManager.cpp";
    g_sfera_weather_runtime.sky_texture_handles.capacity = (uint32_t)(0x64u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F80ECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F80ECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F80F2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF60));
    *(uint8_t*)((uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_line) = 0x157u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8113u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8113u));
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].transform;
    g_sfera_spatial_states[24u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8137u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8137u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF80));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8141u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8141u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8189u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8189u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].transform;
    g_sfera_spatial_states[25u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F81A7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F81A7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FAF90));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F81B1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F81B1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F81C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F81F9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F81F9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].transform;
    g_sfera_spatial_states[26u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8257u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8257u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB000));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8261u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8261u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F82A9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F82A9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].transform;
    g_sfera_spatial_states[27u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8307u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8307u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB070));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8311u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8311u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8359u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8359u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].transform;
    g_sfera_spatial_states[28u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8377u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8377u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB080));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8381u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8381u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F83C9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F83C9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].transform;
    g_sfera_spatial_states[29u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8427u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8427u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB0F0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8431u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8431u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8479u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8479u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].transform;
    g_sfera_spatial_states[30u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F84D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F84D7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB160));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F84E1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F84E1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8529u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8529u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].transform;
    g_sfera_spatial_states[31u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8587u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8587u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB1D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8591u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8591u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F85D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F85D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB1E0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F85EAu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F85EAu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].transform;
    g_sfera_spatial_states[32u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8607u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8607u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB220));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8611u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8611u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8659u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8659u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].transform;
    g_sfera_spatial_states[33u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F86B7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F86B7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB290));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F86C1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F86C1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8709u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8709u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].transform;
    g_sfera_spatial_states[34u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8727u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8727u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB2A0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8731u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8731u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8779u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8779u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].transform;
    g_sfera_spatial_states[35u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F87D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F87D7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB310));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F87E1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F87E1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8829u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8829u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].transform;
    g_sfera_spatial_states[36u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8887u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8887u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB380));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8891u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8891u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F88D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F88D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].transform;
    g_sfera_spatial_states[37u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8937u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8937u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB3F0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8941u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8941u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8989u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8989u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].transform;
    g_sfera_spatial_states[38u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F89E7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F89E7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB460));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F89F1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F89F1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8A39u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8A39u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.lookup_object[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_12;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_12) = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8A97u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8A97u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB4D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8AA1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8AA1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.manager_object[0];
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8AE9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8AE9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8B3Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8B3Au));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8B61;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB540));
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8B5Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8B5Au));
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8B61:
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8B8Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8B8Eu));
    lift_trap(cpu, 0x4F8B8Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8B9Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8B9Au));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8BC1;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB590));
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8BBAu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8BBAu));
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8BC1:
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8BEEu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8BEEu));
    lift_trap(cpu, 0x4F8BEEu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8BFAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8BFAu));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8C21;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB5E0));
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8C1Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8C1Au));
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8C21:
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8C4Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8C4Eu));
    lift_trap(cpu, 0x4F8C4Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB680));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8C5Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8C5Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C60(LiftCpu* cpu, uint32_t stop_address) {
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
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8C91u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8C91u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000F8CE7;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head) = (uint32_t)(cpu->eax);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head;
    *(uint32_t*)(cpu->eax) = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB630));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = (uint32_t)(cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8CD3u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8CD3u));
    cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8CE7:
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D11u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8D11u));
    lift_trap(cpu, 0x4F8D11u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D2Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8D2Au));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F8D51;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10) = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB660));
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D4Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8D4Au));
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8D51:
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D7Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8D7Eu));
    lift_trap(cpu, 0x4F8D7Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D8Au)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4F8D8Au));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB6D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D94u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8D94u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].transform;
    g_sfera_spatial_states[39u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8DB7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8DB7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB6E0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8DC1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8DC1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8E09u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8E09u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].transform;
    g_sfera_spatial_states[40u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8E67u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8E67u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB750));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8E71u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8E71u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8EB9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8EB9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].transform;
    g_sfera_spatial_states[41u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8ED7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8ED7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB760));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8EE1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8EE1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8F29u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8F29u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].transform;
    g_sfera_spatial_states[42u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8F87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8F87u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB7D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8F91u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F8F91u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8FD9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8FD9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].transform;
    g_sfera_spatial_states[43u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9097u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9097u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB8D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F90A1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F90A1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F90E9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F90E9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].transform;
    g_sfera_spatial_states[44u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9147u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9147u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB940));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9151u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9151u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9199u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9199u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].transform;
    g_sfera_spatial_states[45u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F91F7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F91F7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB9B0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9201u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9201u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9249u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9249u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].transform;
    g_sfera_spatial_states[46u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9267u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9267u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FB9C0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9271u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9271u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F92B9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F92B9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].transform;
    g_sfera_spatial_states[47u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9317u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9317u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBA30));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9321u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9321u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9369u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9369u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].transform;
    g_sfera_spatial_states[48u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F93C7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F93C7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBAA0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F93D1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F93D1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9419u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9419u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].transform;
    g_sfera_spatial_states[49u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9477u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9477u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBB10));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9481u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9481u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F94C9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F94C9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].transform;
    g_sfera_spatial_states[50u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9527u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9527u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBB80));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9531u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9531u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9579u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9579u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].transform;
    g_sfera_spatial_states[51u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F95D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F95D7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBBF0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F95E1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F95E1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9629u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9629u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_options_dialog_object_storage[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.aligned_storage_token;
    g_sfera_options_dialog_runtime.aligned_storage_token = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9687u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9687u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBC60));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9691u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9691u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_object_storage[0x60];
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F96D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F96D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBD50));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F972Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F972Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9730(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBD10));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F973Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F973Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBCD0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F974Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F974Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].transform;
    g_sfera_spatial_states[52u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9767u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9767u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBD90));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9771u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9771u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F97B9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F97B9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].transform;
    g_sfera_spatial_states[53u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9817u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9817u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBE00));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9821u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9821u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9869u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9869u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].transform;
    g_sfera_spatial_states[54u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9887u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9887u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBE10));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9891u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9891u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F98D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F98D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].transform;
    g_sfera_spatial_states[55u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9937u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9937u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBE80));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9941u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9941u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9989u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9989u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].transform;
    g_sfera_spatial_states[56u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F99E7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F99E7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBEF0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F99F1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F99F1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9A39u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9A39u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].transform;
    g_sfera_spatial_states[57u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9A97u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9A97u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBF60));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9AA1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9AA1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9AE9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9AE9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9AFAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F9AFAu));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000F9B21;
    g_sfera_win32_dialog_registry.sentinel = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_win32_dialog_registry.sentinel;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBF70));
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9B1Au)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9B1Au));
    cpu->esp += 4u;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F9B21:
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9B4Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F9B4Eu));
    lift_trap(cpu, 0x4F9B4Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].transform;
    g_sfera_spatial_states[58u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9B67u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9B67u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FBFC0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9B71u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9B71u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9BB9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9BB9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C0Au)); sfera_sub_004D6720(cpu, LIFT_CODE_TOKEN_VA(0x4F9C0Au));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC090));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C14u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9C14u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].transform;
    g_sfera_spatial_states[59u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C37u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9C37u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0A0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C41u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9C41u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C89u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9C89u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].transform;
    g_sfera_spatial_states[60u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9CA7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9CA7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0B0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9CB1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9CB1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9CC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9CF9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9CF9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].transform;
    g_sfera_spatial_states[61u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D17u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9D17u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0C0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D21u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9D21u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D69u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9D69u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].transform;
    g_sfera_spatial_states[62u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9D87u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0E0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D91u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9D91u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9DD9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9DD9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].transform;
    g_sfera_spatial_states[63u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9DF7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9DF7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0F0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9E01u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9E01u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9E49u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9E49u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].transform;
    g_sfera_spatial_states[64u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9E67u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9E67u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC100));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9E71u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9E71u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9EB9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9EB9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].transform;
    g_sfera_spatial_states[65u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9ED7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9ED7u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC110));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9EE1u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9EE1u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9F29u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9F29u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].transform;
    g_sfera_spatial_states[66u].transform.matrix_address = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9F47u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9F47u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC120));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9F51u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9F51u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(cpu->esp);
    *(float*)(cpu->esp) = cpu->fpu[0u];
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].bounds;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9F99u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9F99u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x200u); lift_push32(cpu, 0u); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0xCu); lift_push32(cpu, (uintptr_t)"$d $t "); lift_push32(cpu, (uintptr_t)"LogMemory.log");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9FC2u)); sfera_sub_004EC500(cpu, LIFT_CODE_TOKEN_VA(0x4F9FC2u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC130));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9FCCu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9FCCu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x840u); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004EBEF0)); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"$d $t $u"); lift_push32(cpu, (uintptr_t)"Warnings.log");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_warnings_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9FF5u)); sfera_sub_004EC500(cpu, LIFT_CODE_TOKEN_VA(0x4F9FF5u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC140));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9FFFu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4F9FFFu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x840u); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004EBEF0)); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0xDu); lift_push32(cpu, (uintptr_t)"$d $t $u"); lift_push32(cpu, (uintptr_t)"Errors.log");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA035u)); sfera_sub_004EC500(cpu, LIFT_CODE_TOKEN_VA(0x4FA035u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC150));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA03Fu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4FA03Fu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA041(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC15A));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA04Bu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4FA04Bu));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::WaitForSingleObject);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xFA0E1u), LIFT_CODE_TOKEN_RVA(0xFA0DFu))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FA117;
    cpu->ecx = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->ecx);
    g_sfera_execution_monitor_runtime.stop_requested = UINT16_C(1);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xFA0F9u), LIFT_CODE_TOKEN_RVA(0xFA0F7u))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FA10C;
    cpu->edx = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_RVA(0xFA106u));
    label_000FA10C:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_execution_monitor_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::DeleteCriticalSection), LIFT_CODE_TOKEN_RVA(0xFA111u));
    label_000FA117:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_effect_manager.render_slots.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA162u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA162u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA170(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->ecx = (uint32_t)((int32_t)(cpu->ecx) >> 2u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000FA1BA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_items;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA1B5u)); sfera_sub_0042A290(cpu, LIFT_CODE_TOKEN_VA(0x4FA1B5u));
    cpu->eax = g_sfera_effect_items.block_vector_begin;
    label_000FA1BA:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000FA1C7;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA1C4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FA1C4u));
    cpu->esp += 4u;
    label_000FA1C7:
    g_sfera_effect_items.block_vector_begin = (uint32_t)(cpu->esi);
    g_sfera_effect_items.block_vector_end = (uint32_t)(cpu->esi);
    g_sfera_effect_items.block_vector_capacity_end = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA1F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA231u)); sfera_sub_00406340(cpu, LIFT_CODE_TOKEN_VA(0x4FA231u));
    cpu->ecx = g_sfera_effect_manager.effect_listeners.sentinel;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA23Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FA23Du));
    cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA270(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA270;
    label_0002E630:
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 8u) == (uint32_t)(0u)) goto label_0002E681;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x104u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E649u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E649u));
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E680;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E677;
    cpu->edx = 0x65u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E66Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E66Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E674u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E674u));
    cpu->esp += 4u;
    label_0002E677:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E67Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E67Du));
    cpu->esp += 4u;
    label_0002E680:
    cpu->esi = lift_pop32(cpu);
    label_0002E681:
    if (*(uint32_t*)(cpu->edi + 0xCu) == (uint32_t)(0u)) goto label_0002E6AD;
    cpu->edx = 0x105u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E696u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E696u));
    cpu->edi = *(uint32_t*)(cpu->edi + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0002E6AD;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6A4u)); sfera_sub_0042E250(cpu, LIFT_CODE_TOKEN_VA(0x42E6A4u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6AAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E6AAu));
    cpu->esp += 4u;
    label_0002E6AD:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA270:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_log_runtime.object[0];
    goto label_0002E630;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA292u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA292u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA2B2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA2B2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA360(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA360;
    label_000D7AB0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x13u;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7AC2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7AC2u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D7AD0;
    lift_push32(cpu, 1u);
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    label_000D7AD0:
    cpu->edx = 0x14u;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7ADFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7ADFu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D7AEF;
    lift_push32(cpu, 1u);
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    label_000D7AEF:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA360:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    goto label_000D7AB0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[2].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA3F2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA3F2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[1].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA412u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA412u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[0].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA432u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA432u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA460(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA460;
    label_0008A1B0:
    if (*(uint32_t*)(cpu->ecx) == (uint32_t)(0u)) goto label_0008A1BF;
    cpu->ecx = (uint32_t)(uintptr_t)"CReadPathManager::~CReadPathManager: object not deinitialized";
    sfera_sub_00459B10(cpu, stop_address); return;
    label_0008A1BF:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA460:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.object_01[0];
    goto label_0008A1B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.secondary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA482u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA482u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e7_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA4A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA4A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e8_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA4C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA4C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e9_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA4E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA4E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.eb_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA502u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA502u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.ed_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA522u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA522u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA542u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA542u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_102_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA562u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA562u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_105_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA582u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA582u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA5A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA5A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA5C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA5C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA5E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA5E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA602u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA602u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA622u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA622u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA642u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA642u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_character_index_map.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA662u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA662u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_visibility_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA682u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA682u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_keys.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA6A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA6A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA6C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA6C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_draw_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA6E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA6E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_collision_runtime.candidate_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA702u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA702u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA722u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA722u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA742u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA742u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.scene_points.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA762u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA762u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA782u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA782u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA7A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA7A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA7C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA7C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA7E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA7E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA802u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA802u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA822u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA822u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b5_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA842u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA842u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA862u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA862u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.cell_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA882u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA882u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_landscape_runtime.microtexture_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA8A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA8A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.surface_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA8C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA8C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_124d_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA8E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA8E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.tertiary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA902u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA902u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.render_pass_slots.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA922u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA922u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.surface_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA942u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA942u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.surface_index_map.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA962u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA962u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA982u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA982u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA9A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA9A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA9C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA9C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA9E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA9E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_24de_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA02u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA02u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_24e0_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA22u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA22u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_24e2_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA42u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA42u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.model_matrices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA62u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA62u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA82u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA82u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAAA2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAAA2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAAC2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAAC2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.clip_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAAE2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAAE2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.clip_points.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB02u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB02u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.cloud_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB22u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB22u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_collision_runtime.near_result_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB42u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB42u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.world_cell_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB62u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB62u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.render_ranges.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB82u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB82u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FABA2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FABA2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.type_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FABC2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FABC2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.instance_offsets.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FABE2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FABE2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.instance_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAC02u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAC02u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.model_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAC22u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAC22u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FACD1u)); sfera_sub_0040D400(cpu, LIFT_CODE_TOKEN_VA(0x4FACD1u));
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FACDDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FACDDu));
    cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FACF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_server_wall;
    sfera_sub_0048A6A0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE40(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->ecx = (uint32_t)((int32_t)(cpu->ecx) >> 2u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000FAE8A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_effect_items;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAE85u)); sfera_sub_004974B0(cpu, LIFT_CODE_TOKEN_VA(0x4FAE85u));
    cpu->eax = g_sfera_sound_effect_items.block_vector_begin;
    label_000FAE8A:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000FAE97;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAE94u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FAE94u));
    cpu->esp += 4u;
    label_000FAE97:
    g_sfera_sound_effect_items.block_vector_begin = (uint32_t)(cpu->esi);
    g_sfera_sound_effect_items.block_vector_end = (uint32_t)(cpu->esi);
    g_sfera_sound_effect_items.block_vector_capacity_end = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAEC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAEE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)(g_sfera_sound_runtime.tracks.first) == (uint32_t)(cpu->esi)) goto label_000FAF0F;
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_000FAEF0:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000FAF07;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_runtime.tracks;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAF02u)); sfera_sub_00498C30(cpu, LIFT_CODE_TOKEN_VA(0x4FAF02u));
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_000FAF07:
    if ((uint32_t)(g_sfera_sound_runtime.tracks.first) != (uint32_t)(cpu->esi)) goto label_000FAEF0;
    label_000FAF0F:
    g_sfera_sound_runtime.tracks.last = (uint32_t)(cpu->esi);
    g_sfera_sound_runtime.tracks.first = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_weather_runtime.sky_texture_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAF72u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAF72u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAFD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FB1F2;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB1EFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB1EFu));
    cpu->esp += 4u;
    label_000FB1F2:
    g_sfera_font_factory_runtime.fonts_begin = (uint32_t)(0u);
    g_sfera_font_factory_runtime.fonts_end = (uint32_t)(0u);
    g_sfera_font_factory_runtime.fonts_capacity = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor) = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FB580;
    lift_push32(cpu, cpu->esi);
    label_000FB568:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB570u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB570u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FB568;
    cpu->esi = lift_pop32(cpu);
    label_000FB580:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB586u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB586u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor) = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FB5D0;
    lift_push32(cpu, cpu->esi);
    label_000FB5B8:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB5C0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB5C0u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FB5B8;
    cpu->esi = lift_pop32(cpu);
    label_000FB5D0:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB5D6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB5D6u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count) = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FB620;
    lift_push32(cpu, cpu->esi);
    label_000FB608:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB610u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB610u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FB608;
    cpu->esi = lift_pop32(cpu);
    label_000FB620:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB626u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB626u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB63Au)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4FB63Au));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB645u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB645u));
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head) = (uint32_t)(0u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB66Au)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x4FB66Au));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB675u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB675u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000FB6AE;
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_core_runtime.object_aux);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB69Fu)); sfera_sub_004BC000(cpu, LIFT_CODE_TOKEN_VA(0x4FB69Fu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB6ABu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB6ABu));
    cpu->esp += 4u;
    label_000FB6AE:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head) = (uint32_t)(0u);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count) = (uint32_t)(0u);
    *(uint32_t*)((uintptr_t)&g_sfera_interface_core_runtime.object_state) = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    sfera_sub_004BC9F0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FBCE2;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBCDFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBCDFu));
    cpu->esp += 4u;
    label_000FBCE2:
    g_sfera_options_dialog_runtime.chat_edit_fonts.begin = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_edit_fonts.end = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_edit_fonts.capacity_end = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FBD22;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBD1Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBD1Fu));
    cpu->esp += 4u;
    label_000FBD22:
    g_sfera_options_dialog_runtime.chat_list_fonts.begin = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_list_fonts.end = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.chat_list_fonts.capacity_end = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.graphics_modes.begin;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000FBD62;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBD5Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBD5Fu));
    cpu->esp += 4u;
    label_000FBD62:
    g_sfera_options_dialog_runtime.graphics_modes.begin = (uint32_t)(0u);
    g_sfera_options_dialog_runtime.graphics_modes.end = (uint32_t)(0u);
    *(uint32_t*)((uintptr_t)&g_sfera_options_dialog_cleanup_state) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    g_sfera_win32_dialog_registry.size = (uint32_t)(0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000FBFB0;
    lift_push32(cpu, cpu->esi);
    label_000FBF98:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBFA0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBFA0u));
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000FBF98;
    cpu->esi = lift_pop32(cpu);
    label_000FBFB0:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBFB6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBFB6u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBFC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBFD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC030(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_control_reference_registry;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FC071u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4FC071u));
    cpu->ecx = g_sfera_control_reference_registry.sentinel;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FC07Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FC07Du));
    cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_crash_report_runtime.previous_exception_filter;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetUnhandledExceptionFilter), LIFT_CODE_TOKEN_VA(0x4FC096u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC0D0;
    label_000D78B0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D793C;
    cpu->ebx = native_function_address32(&::DestroyCursor);
    label_000D78F0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0xD78F6u), LIFT_CODE_TOKEN_RVA(0xD78F4u))) { return; }
    if (*(uint8_t*)(cpu->esi + 0x35u) != (uint8_t)(0u)) goto label_000D7937;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x35u) != (uint8_t)(0u)) goto label_000D791C;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->eax + 0x35u) != (uint8_t)(0u)) goto label_000D7937;
    (void)cpu;
    label_000D7910:
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->eax + 0x35u) == (uint8_t)(0u)) goto label_000D7910;
    goto label_000D7937;
    label_000D791C:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint8_t*)(cpu->eax + 0x35u) != (uint8_t)(0u)) goto label_000D7935;
    label_000D7925:
    if ((uint32_t)(cpu->esi) != *(uint32_t*)(cpu->eax + 8u)) goto label_000D7935;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x35u) == (uint8_t)(0u)) goto label_000D7925;
    label_000D7935:
    cpu->esi = cpu->eax;
    label_000D7937:
    if ((uint32_t)(cpu->esi) != *(uint32_t*)(cpu->edi + 4u)) goto label_000D78F0;
    label_000D793C:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7957u)); sfera_sub_004D77E0(cpu, LIFT_CODE_TOKEN_VA(0x4D7957u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7960u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D7960u));
    cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC0D0:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    goto label_000D78B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC130(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC130;
    label_000ED1A0:
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
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1E5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    goto label_000ED1EE;
    label_000ED1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    label_000ED1EE:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1F9;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000ED1F9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED238u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED238u));
    label_000ED238:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu));
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u));
    cpu->esp += 0x18u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu));
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uint32_t)(uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED296u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED296u));
    label_000ED296:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au));
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u));
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uint32_t)(uintptr_t)" *****\n");
    cpu->eax = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u));
    label_000ED2D8:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu));
    label_000ED2DF:
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu));
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED30D;
    label_000ED2F1:
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u));
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u));
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED2F1;
    label_000ED30D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u)); sfera_sub_004ECBB0(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED320u), LIFT_CODE_TOKEN_RVA(0xED31Eu))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED326u), LIFT_CODE_TOKEN_RVA(0xED324u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED336;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED333u), LIFT_CODE_TOKEN_RVA(0xED331u))) { return; }
    cpu->esp += 4u;
    label_000ED336:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED343;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED340u), LIFT_CODE_TOKEN_RVA(0xED33Eu))) { return; }
    cpu->esp += 4u;
    label_000ED343:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED350;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED34Du), LIFT_CODE_TOKEN_RVA(0xED34Bu))) { return; }
    cpu->esp += 4u;
    label_000ED350:
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu)); sfera_sub_004EE470(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC130:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_memory_object;
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC140(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC140;
    label_000ED1A0:
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
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1E5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    goto label_000ED1EE;
    label_000ED1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    label_000ED1EE:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1F9;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000ED1F9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED238u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED238u));
    label_000ED238:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu));
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u));
    cpu->esp += 0x18u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu));
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uint32_t)(uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED296u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED296u));
    label_000ED296:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au));
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u));
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uint32_t)(uintptr_t)" *****\n");
    cpu->eax = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u));
    label_000ED2D8:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu));
    label_000ED2DF:
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu));
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED30D;
    label_000ED2F1:
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u));
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u));
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED2F1;
    label_000ED30D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u)); sfera_sub_004ECBB0(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED320u), LIFT_CODE_TOKEN_RVA(0xED31Eu))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED326u), LIFT_CODE_TOKEN_RVA(0xED324u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED336;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED333u), LIFT_CODE_TOKEN_RVA(0xED331u))) { return; }
    cpu->esp += 4u;
    label_000ED336:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED343;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED340u), LIFT_CODE_TOKEN_RVA(0xED33Eu))) { return; }
    cpu->esp += 4u;
    label_000ED343:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED350;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED34Du), LIFT_CODE_TOKEN_RVA(0xED34Bu))) { return; }
    cpu->esp += 4u;
    label_000ED350:
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu)); sfera_sub_004EE470(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC140:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_warnings_object;
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC150(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC150;
    label_000ED1A0:
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
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1E5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    goto label_000ED1EE;
    label_000ED1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    label_000ED1EE:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED1F9;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000ED1F9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uint32_t)(uintptr_t)"***** Quit  ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED238u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED238u));
    label_000ED238:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu));
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u));
    cpu->esp += 0x18u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu));
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uint32_t)(uintptr_t)" ");
    cpu->edx = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED296u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED296u));
    label_000ED296:
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au));
    cpu->esp += 4u;
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u));
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu));
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uint32_t)(uintptr_t)" *****\n");
    cpu->eax = (uint32_t)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u));
    label_000ED2D8:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu));
    label_000ED2DF:
    if ((uint8_t)((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu));
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000ED30D;
    label_000ED2F1:
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u));
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u));
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_000ED2F1;
    label_000ED30D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u)); sfera_sub_004ECBB0(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED320u), LIFT_CODE_TOKEN_RVA(0xED31Eu))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED326u), LIFT_CODE_TOKEN_RVA(0xED324u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED336;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED333u), LIFT_CODE_TOKEN_RVA(0xED331u))) { return; }
    cpu->esp += 4u;
    label_000ED336:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED343;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED340u), LIFT_CODE_TOKEN_RVA(0xED33Eu))) { return; }
    cpu->esp += 4u;
    label_000ED343:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000ED350;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xED34Du), LIFT_CODE_TOKEN_RVA(0xED34Bu))) { return; }
    cpu->esp += 4u;
    label_000ED350:
    cpu->ecx = (uint32_t)(cpu->esi + 0x38u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu)); sfera_sub_004EE470(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC150:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_log_errors_object;
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC15A(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.dynamic_tls_dtor_callbacks = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
