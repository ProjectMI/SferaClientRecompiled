#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43DB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43DB));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000054), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43E6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43E6));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000070), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43F1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43F1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000A0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43FF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43FF));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000AC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F440D(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F440D;
    LIFT_BLOCK(label_000B9CE0, UINT32_C(0x004B9CE0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_0049FA40, UINT32_C(0x004B9CE8));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004B9CF0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F440D, UINT32_C(0x004F440D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000BC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F441B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F441B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000178), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4450(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4450));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4459));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F445B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F445B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4464));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4466(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4466));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F446F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4471(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4471));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F447A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F447C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F447C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4485));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4487(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4487));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4490));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4492(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4492));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F449B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F449D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F449D));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44A6));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44A8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44A8));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44B1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44B3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44B3));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44BC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44BE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44BE));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44C7));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44C9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44C9));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44D2));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44D4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44D4));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44DD));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44DF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44DF));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44E8));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44EA(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44EA));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44F3));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F44F5(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F44F5));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F44FE));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4500(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4500));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4509));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F450B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F450B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4514));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4516(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4516));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F451F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4521(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4521));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F452A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F452C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F452C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4535));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4537(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4537));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4540));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4542(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4542));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F454B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F454D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F454D));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4556));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4580));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFECC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F458C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F45C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F45C0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEB4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F45CC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F45CE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F45CE));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEC0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F45DA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4610(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4610));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F461B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F461B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000054), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4626(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4626));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000070), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4631(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4631));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000A0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F463F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F463F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000AC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F464D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F464D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFCC));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F4650));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4656(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4656;
    LIFT_BLOCK(label_000B9CE0, UINT32_C(0x004B9CE0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_0049FA40, UINT32_C(0x004B9CE8));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004B9CF0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F4656, UINT32_C(0x004F4656));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000BC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4664(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4664));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000178), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4672(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4672));
    cpu->eax = (uint32_t)(g_sfera_control_reference_registry_guard);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    g_sfera_control_reference_registry_guard = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46A0;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F46A0, UINT32_C(0x004F46A0));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_control_reference_registry));
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46D0;
    LIFT_BLOCK(label_000D67A0, UINT32_C(0x004D67A0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_USER32_ReleaseDC, UINT32_C(0x004D67A7), UINT32_C(0x004D67AD));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F46D0, UINT32_C(0x004F46D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBB8))));
    goto label_000D67A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46DB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46DB;
    LIFT_BLOCK(label_000D67B0, UINT32_C(0x004D67B0));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_GDI32_DeleteDC, UINT32_C(0x004D67B3), UINT32_C(0x004D67B9));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F46DB, UINT32_C(0x004F46DB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBEC))));
    goto label_000D67B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46E6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46E6;
    LIFT_BLOCK(label_000D67C0, UINT32_C(0x004D67C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_GDI32_DeleteObject, UINT32_C(0x004D67C3), UINT32_C(0x004D67C9));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F46E6, UINT32_C(0x004F46E6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBAC))));
    goto label_000D67C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46F1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46F1;
    LIFT_BLOCK(label_000D67D0, UINT32_C(0x004D67D0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_GDI32_SelectObject, UINT32_C(0x004D67D7), UINT32_C(0x004D67DD));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F46F1, UINT32_C(0x004F46F1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBA4))));
    goto label_000D67D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46FC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46FC;
    LIFT_BLOCK(label_000D67C0, UINT32_C(0x004D67C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_GDI32_DeleteObject, UINT32_C(0x004D67C3), UINT32_C(0x004D67C9));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F46FC, UINT32_C(0x004F46FC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBC4))));
    goto label_000D67C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4707(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4707;
    LIFT_BLOCK(label_000D67D0, UINT32_C(0x004D67D0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_GDI32_SelectObject, UINT32_C(0x004D67D7), UINT32_C(0x004D67DD));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F4707, UINT32_C(0x004F4707));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBE4))));
    goto label_000D67D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4740(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4740));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F474D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4770));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4778(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4778));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47B0;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F47B0, UINT32_C(0x004F47B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47E0;
    LIFT_BLOCK(label_000D7B40, UINT32_C(0x004D7B40));
    std::construct_at(reinterpret_cast<CCursor*>(cpu->ecx));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F47E0, UINT32_C(0x004F47E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_000D7B40;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4810));
    cpu->eax = (uint32_t)(g_sfera_cursor_texture_registry_guard);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    g_sfera_cursor_texture_registry_guard = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F481E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F481E));
    cpu->eax = (uint32_t)(g_sfera_cursor_texture_registry_guard);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    g_sfera_cursor_texture_registry_guard = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4850;
    LIFT_BLOCK(label_000DA550, UINT32_C(0x004DA550));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_PUSH2(cpu->eax, UINT32_C(0x00000000));
    std::construct_at(reinterpret_cast<UnmanagedResourceVector*>(cpu->esi));
    LIFT_CALL_ENTER(sfera_sub_004D9E80, UINT32_C(0x004DA564));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004D98D0, UINT32_C(0x004DA56D));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000DA58B, UINT32_C(0x004DA574));
    LIFT_STORE32(cpu->eax, UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000010));
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), UINT32_C(0x00000000));
    LIFT_BLOCK(label_000DA58B, UINT32_C(0x004DA58B));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F4850, UINT32_C(0x004F4850));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000178), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000DA550;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4880(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4880));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F48C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F48C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF28))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4900));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF28))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4940));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4980(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4980));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F498C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49C0;
    LIFT_BLOCK(label_000EA960, UINT32_C(0x004EA960));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EA98F, UINT32_C(0x004EA966));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA97E, UINT32_C(0x004EA96B));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words)));
    g_sfera_memory_runtime.lock_held = (uint8_t)(UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_LeaveCriticalSection, UINT32_C(0x004EA977), UINT32_C(0x004EA97D));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EA97E, UINT32_C(0x004EA97E));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000004)))), UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA98F, UINT32_C(0x004EA984));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words)));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_LeaveCriticalSection, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA989)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA98F));
    LIFT_BLOCK(label_000EA98F, UINT32_C(0x004EA98F));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F49C0, UINT32_C(0x004F49C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49F0;
    LIFT_BLOCK(label_000EA960, UINT32_C(0x004EA960));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EA98F, UINT32_C(0x004EA966));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA97E, UINT32_C(0x004EA96B));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words)));
    g_sfera_memory_runtime.lock_held = (uint8_t)(UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_LeaveCriticalSection, UINT32_C(0x004EA977), UINT32_C(0x004EA97D));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EA97E, UINT32_C(0x004EA97E));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000004)))), UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA98F, UINT32_C(0x004EA984));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words)));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_LeaveCriticalSection, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA989)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA98F));
    LIFT_BLOCK(label_000EA98F, UINT32_C(0x004EA98F));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F49F0, UINT32_C(0x004F49F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4A20;
    LIFT_BLOCK(label_000EA960, UINT32_C(0x004EA960));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EA98F, UINT32_C(0x004EA966));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA97E, UINT32_C(0x004EA96B));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words)));
    g_sfera_memory_runtime.lock_held = (uint8_t)(UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_LeaveCriticalSection, UINT32_C(0x004EA977), UINT32_C(0x004EA97D));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EA97E, UINT32_C(0x004EA97E));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000004)))), UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA98F, UINT32_C(0x004EA984));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)g_sfera_memory_runtime.lock_words)));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_LeaveCriticalSection, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA989)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA98F));
    LIFT_BLOCK(label_000EA98F, UINT32_C(0x004EA98F));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F4A20, UINT32_C(0x004F4A20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4A50));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000038), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004EE470);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4A80));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000038), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004EE470);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4AB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4AB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Lockit_dtor, UINT32_C(0x004F4AB3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4AE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4AE0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4B10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4B50));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4B80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4BC0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4BF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4C30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4C60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4CA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4CD0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4D10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4D40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4D80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4DB0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4DF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4E20));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4E60));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"logs\\CurrentExecuting.log"), ((uint32_t)(uintptr_t)&g_sfera_execution_monitor_runtime.log_path[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_sprintf, UINT32_C(0x004F4E6A), UINT32_C(0x004F4E70));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000004)));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_SymSetOptions, UINT32_C(0x004F4E75), UINT32_C(0x004F4E7B));
    LIFT_PUSH2(UINT32_C(0x00000001), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentProcess, UINT32_C(0x004F4E7F), UINT32_C(0x004F4E85));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_SymInitialize, UINT32_C(0x004F4E86), UINT32_C(0x004F4E8C));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA0D0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4E96));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4EA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4EA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4ED0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4ED0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4F10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4F40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4F80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4FB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4FB0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4FF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4FF0));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000018)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F4FFA));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F503D, UINT32_C(0x004F5001));
    g_sfera_effect_manager.effect_listeners.head = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(g_sfera_effect_manager.effect_listeners.head);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    cpu->eax = (uint32_t)(g_sfera_effect_manager.effect_listeners.head);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000008), cpu->eax);
    cpu->ecx = (uint32_t)(g_sfera_effect_manager.effect_listeners.head);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->ecx + UINT32_C(0x00000014), (cpu->eax & UINT32_C(0xFF)));
    cpu->edx = (uint32_t)(g_sfera_effect_manager.effect_listeners.head);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA1F0)));
    LIFT_STORE8(cpu->edx + UINT32_C(0x00000015), (cpu->eax & UINT32_C(0xFF)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5036));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F503D, UINT32_C(0x004F503D));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F504D), UINT32_C(0x004F5053));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F506A));
    LIFT_TRAP_RETURN(UINT32_C(0x004F506A), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5070));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0017CDC0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5081));
    LIFT_PUSH3(UINT32_C(0x0017CDC0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_effect_manager.render_slots.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5093));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp"));
    g_sfera_effect_manager.render_slots.capacity = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F50AC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F50B2), UINT32_C(0x004F50B8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA150)));
    g_sfera_effect_manager.render_slots.debug_file[15] = '\0';
    g_sfera_effect_manager.render_slots.debug_line = UINT32_C(125);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F50D3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F50E0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA170)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F50EA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F50F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5120));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5160));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5190(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5190));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F51D0));
    LIFT_PUSH2(UINT32_C(0x00000000), UINT32_C(0x00000000));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_error_log_runtime.object[0]));
    LIFT_CALL_ENTER(sfera_sub_0042E540, UINT32_C(0x004F51DE));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA270)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F51E8));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F51F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000050));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5201));
    LIFT_PUSH3(UINT32_C(0x00000050), UINT32_C(0x00000000), cpu->eax);
    g_sfera_file_runtime.open_files.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5210));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    cpu->eax = (uint32_t)(UINT32_C(0x0000000A));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp"));
    g_sfera_file_runtime.open_files.capacity = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.open_files.maximum = UINT32_C(100);
    g_sfera_file_runtime.open_files.growth = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.open_files.element_size = UINT32_C(8);
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5242));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)g_sfera_file_runtime.open_files.debug_file));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5248), UINT32_C(0x004F524E));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA280)));
    g_sfera_file_runtime.open_files.debug_file[15] = 0;
    g_sfera_file_runtime.open_files.debug_line = UINT32_C(25);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5269));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5270));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5281));
    g_sfera_file_runtime.search_paths.data = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    cpu->eax = (uint32_t)(UINT32_C(0x0000000A));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp"));
    g_sfera_file_runtime.search_paths.capacity = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.search_paths.maximum = UINT32_C(100);
    g_sfera_file_runtime.search_paths.growth = (uint32_t)(cpu->eax);
    g_sfera_file_runtime.search_paths.element_size = UINT32_C(4);
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5305));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)g_sfera_file_runtime.search_paths.debug_file));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F530B), UINT32_C(0x004F5311));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA2A0)));
    g_sfera_file_runtime.search_paths.debug_file[15] = 0;
    g_sfera_file_runtime.search_paths.debug_line = UINT32_C(27);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F532C));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5330(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5330));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5360(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5360));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F53A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F53D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5410(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5410));
    LIFT_PUSH2(UINT32_C(0x00000004), ((uint32_t)(uintptr_t)"\t\n\r "));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_shared_parser_whitespace));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5421));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA2E0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F542B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5430(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5430));
    LIFT_PUSH2(UINT32_C(0x00000002), ((uint32_t)(uintptr_t)"\\/"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_shared_parser_path_separators));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5441));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA310)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F544B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5450(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5450));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].transform));
    g_sfera_spatial_states[0u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F5467));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA340)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5471));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5480(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5480));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[0u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F54B9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F54C0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].transform));
    g_sfera_spatial_states[1u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F54D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA350)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F54E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F54F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[1u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5529));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5530(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5530));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5550));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5570(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5570;
    LIFT_BLOCK(label_00021FC0, UINT32_C(0x00421FC0));
    LIFT_PUSH2(cpu->esi, UINT32_C(0x00004014));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_PUSH2(UINT32_C(0x00000000), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x00421FD0));
    LIFT_PUSH3(UINT32_C(0x00004000), UINT32_C(0x000000FF), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x00421FE0));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00004008), UINT32_C(0xFFFFFFFF));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F5570, UINT32_C(0x004F5570));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0]));
    goto label_00021FC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5580;
    LIFT_BLOCK(label_000016E0, UINT32_C(0x004016E0));
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ecx);
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)""));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_SUB(cpu->esi, cpu->edx, 0u, 32u, cpu->esi = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ecx)));
    LIFT_BLOCK(label_000016F0, UINT32_C(0x004016F0));
    cpu->ebx = (cpu->ebx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->edx)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->esi + cpu->edx, (cpu->ebx & UINT32_C(0xFF)));
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_TEST((cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000016F0, UINT32_C(0x004016FA));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ebx);
    LIFT_BLOCK(label_000F5580, UINT32_C(0x004F5580));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0]));
    goto label_000016E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5590(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5590));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (40.0));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_RDIV_POP(1u);
    LIFT_X87_STORE_F32_POP(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.inverse_40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F55B0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].transform));
    g_sfera_spatial_states[2u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F55C7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA3D0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F55D1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F55E0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[2u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5619));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5620(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5620));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000001F8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5631));
    LIFT_PUSH3(UINT32_C(0x000001F8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[2].data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5643));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].capacity), UINT32_C(0x0000007E));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F565C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5662), UINT32_C(0x004F5668));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA3E0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_line), UINT32_C(0x000003A6));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5683));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5690(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5690));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000001F8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F56A1));
    LIFT_PUSH3(UINT32_C(0x000001F8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[1].data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F56B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].capacity), UINT32_C(0x0000007E));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F56CC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F56D2), UINT32_C(0x004F56D8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA400)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_line), UINT32_C(0x000003A7));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F56F3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5700));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000001F8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5711));
    LIFT_PUSH3(UINT32_C(0x000001F8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[0].data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5723));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\light.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].capacity), UINT32_C(0x0000007E));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F573C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5742), UINT32_C(0x004F5748));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA420)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_line), UINT32_C(0x000003A8));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5763));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5770));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].transform));
    g_sfera_spatial_states[3u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F5787));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA440)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5791));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F57A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[3u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F57D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F57E0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].transform));
    g_sfera_spatial_states[4u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F57F7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA450)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5801));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5810));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[4u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5849));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5850(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5850));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5870));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5890));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F58A1));
    LIFT_PUSH3(UINT32_C(0x000007D0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_recovered_static_runtime.secondary_auto_array.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F58B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.capacity), UINT32_C(0x000001F4));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.maximum), UINT32_C(0x00001388));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.growth), UINT32_C(0x00000064));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F58EA));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F58F0), UINT32_C(0x004F58F6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA470)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_line), UINT32_C(0x000000E6));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5911));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5920(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5920));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00004650));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5931));
    LIFT_PUSH3(UINT32_C(0x00004650), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.e7_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5943));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e7_records.capacity), UINT32_C(0x000001F4));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e7_records.maximum), UINT32_C(0x00001388));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e7_records.growth), UINT32_C(0x00000064));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e7_records.element_size), UINT32_C(0x00000024));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F597A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5980), UINT32_C(0x004F5986));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA490)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_line), UINT32_C(0x000000E7));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F59A1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F59B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F59B0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F59C1));
    LIFT_PUSH3(UINT32_C(0x000007D0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.e8_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F59D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e8_indices.capacity), UINT32_C(0x000001F4));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e8_indices.maximum), UINT32_C(0x00001388));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e8_indices.growth), UINT32_C(0x00000064));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e8_indices.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5A0A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5A10), UINT32_C(0x004F5A16));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA4B0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_line), UINT32_C(0x000000E8));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5A31));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5A40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5A40));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000320));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5A51));
    LIFT_PUSH3(UINT32_C(0x00000320), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.e9_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5A63));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e9_indices.capacity), UINT32_C(0x000000C8));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e9_indices.maximum), UINT32_C(0x000001F4));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e9_indices.growth), UINT32_C(0x00000064));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e9_indices.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5A9A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5AA0), UINT32_C(0x004F5AA6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA4D0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_line), UINT32_C(0x000000E9));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5AC1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5AD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5AD0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000109A0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5AE1));
    LIFT_PUSH3(UINT32_C(0x000109A0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.eb_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5AF3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.eb_records.capacity), UINT32_C(0x000001F4));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.eb_records.maximum), UINT32_C(0x000003E8));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.eb_records.growth), UINT32_C(0x00000032));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.eb_records.element_size), UINT32_C(0x00000088));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5B2A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5B30), UINT32_C(0x004F5B36));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA4F0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_line), UINT32_C(0x000000EB));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5B51));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5B60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5B60));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5B71));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.ed_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5B83));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.ed_indices.capacity), UINT32_C(0x00000032));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.ed_indices.maximum), UINT32_C(0x000000C8));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.ed_indices.growth), UINT32_C(0x00000014));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.ed_indices.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5BBA));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5BC0), UINT32_C(0x004F5BC6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA510)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_line), UINT32_C(0x000000ED));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5BE1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5BF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5BF0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5C01));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_collision_runtime.contact_objects.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5C13));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_collision_runtime.contact_objects.capacity = (uint32_t)(UINT32_C(0x00000032));
    g_sfera_collision_runtime.contact_objects.maximum = UINT32_C(0x00002710);
    g_sfera_collision_runtime.contact_objects.growth = UINT32_C(0x00000014);
    g_sfera_collision_runtime.contact_objects.element_size = UINT32_C(0x00000004);
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5C4A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5C50), UINT32_C(0x004F5C56));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA530)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[15]), UINT32_C(0x00000000));
    g_sfera_collision_runtime.contact_objects.debug_line = UINT32_C(0x000000EF);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5C71));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5C80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5C80;
    LIFT_BLOCK(label_0004B620, UINT32_C(0x0044B620));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, 1.0);
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000010))));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_X87_STORE_F32(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_x87_push(cpu, 0.0);
    LIFT_X87_STORE_F32(cpu->eax + UINT32_C(0x00000004));
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_X87_STORE_F32(cpu->ecx + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    LIFT_X87_STORE_F32(cpu->edx + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_X87_STORE_F32(cpu->eax + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    LIFT_X87_STORE_F32(cpu->ecx + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    LIFT_X87_STORE_F32(cpu->edx + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_X87_STORE_F32(cpu->eax + UINT32_C(0x0000001C));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_X87_STORE_F32(cpu->ecx + UINT32_C(0x00000020));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    LIFT_X87_STORE_F32(cpu->edx + UINT32_C(0x00000024));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    LIFT_X87_STORE_F32(cpu->eax + UINT32_C(0x00000028));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    LIFT_X87_STORE_F32(cpu->ecx + UINT32_C(0x0000002C));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    LIFT_X87_STORE_F32(cpu->edx + UINT32_C(0x00000030));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_X87_STORE_F32(cpu->eax + UINT32_C(0x00000034));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_X87_STORE_F32(cpu->ecx + UINT32_C(0x00000038));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    LIFT_X87_STORE_F32(cpu->edx + UINT32_C(0x0000003C));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000013B))));
    LIFT_X87_STORE_F32(cpu->esi + UINT32_C(0x00000050));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    lift_x87_push(cpu, (double)100.0f);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000032F))));
    LIFT_X87_STORE_F32_POP(cpu->esi + UINT32_C(0x00000054));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000074), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000078), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000007C), UINT32_C(0x00000280));
    LIFT_X87_STORE_F32(cpu->esi + UINT32_C(0x00000058));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000080), UINT32_C(0x000001E0));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xFFFFFFF0), &, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_X87_STORE_F32(cpu->esi + UINT32_C(0x0000006C));
    lift_x87_push(cpu, (double)0.9999899864196777f);
    LIFT_X87_STORE_F32_POP(cpu->esi + UINT32_C(0x00000070));
    lift_x87_push(cpu, (double)0.75f);
    LIFT_X87_STORE_F32_POP(cpu->esi + UINT32_C(0x00000094));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000031C), cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000510), cpu->ecx);
    LIFT_X87_STORE_F32(cpu->esi + UINT32_C(0x00000550));
    LIFT_STORE16(cpu->esi + UINT32_C(0x00000564), (cpu->ebx & UINT32_C(0xFFFF)));
    LIFT_X87_STORE_F32_POP(cpu->esi + UINT32_C(0x00000554));
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000566), (cpu->ebx & UINT32_C(0xFF)));
    LIFT_X87_STORE_F32(cpu->esi + UINT32_C(0x00000558));
    LIFT_X87_STORE_F32(cpu->esi + UINT32_C(0x0000055C));
    LIFT_X87_STORE_F32_POP(cpu->esi + UINT32_C(0x00000560));
    LIFT_X87_LOAD_F32(cpu->esi + UINT32_C(0x00000058));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x00000008));
    LIFT_X87_LOAD_F32(cpu->esp + UINT32_C(0x00000008));
    LIFT_CALL_ENTER(sfera_sub_004EED54, UINT32_C(0x0044B729));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x00000008));
    LIFT_X87_LOAD_F32(cpu->esp + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000514), cpu->ebx);
    LIFT_X87_STORE_F32_POP(cpu->esi + UINT32_C(0x00000098));
    cpu->eax = (uint32_t)(UINT32_C(0x00000001));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000051C), cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000524), cpu->eax);
    cpu->eax = (uint32_t)(UINT32_C(0x00000003));
    cpu->edx = (uint32_t)(UINT32_C(0x00000004));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000002));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000534), cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000053C), cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000548), cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000520), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000052C), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000538), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000090), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000088), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000008C), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000084), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000518), cpu->edx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000528), cpu->ecx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000530), cpu->ecx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000540), cpu->edx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000544), cpu->edx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000054C), cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE3(0u, cpu->esi, cpu->ebx, cpu->ecx);
    LIFT_BLOCK(label_000F5C80, UINT32_C(0x004F5C80));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0]));
    goto label_0004B620;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5C90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5C90));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5CA1));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.line_102_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5CB3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_102_indices.capacity), UINT32_C(0x00000032));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_102_indices.maximum), UINT32_C(0x00000064));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_102_indices.growth), UINT32_C(0x00000014));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_102_indices.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5CEA));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5CF0), UINT32_C(0x004F5CF6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA550)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_line), UINT32_C(0x00000102));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5D11));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5D20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5D20));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00003200));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5D31));
    LIFT_PUSH3(UINT32_C(0x00003200), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.line_105_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5D43));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_105_records.capacity), UINT32_C(0x000000C8));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_105_records.maximum), UINT32_C(0x000001F4));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_105_records.growth), UINT32_C(0x00000064));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_105_records.element_size), UINT32_C(0x00000040));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5D7A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5D80), UINT32_C(0x004F5D86));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA570)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_line), UINT32_C(0x00000105));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5DA1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5DB0));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000D0)]));
    LIFT_CALL_ENTER(sfera_sub_0048A1A0, UINT32_C(0x004F5DBA));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA460)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5DC4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5DD0;
    LIFT_BLOCK(label_0009B950, UINT32_C(0x0049B950));
    LIFT_SP_SUB(UINT32_C(0x00000014));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->eax);
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_0049B860, UINT32_C(0x0049B967));
    LIFT_PUSH3(UINT32_C(0x00005320), UINT32_C(0x00000000), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x0049B974));
    cpu->eax = (uint32_t)(UINT32_C(0x6E726157));
    cpu->ecx = (uint32_t)(UINT32_C(0x73676E69));
    cpu->edx = (uint32_t)(UINT32_C(0x6C2E3030));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), cpu->eax);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFF0000)) | ((uint32_t)(UINT16_C(0x676F)) & UINT32_C(0xFFFF));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->ecx);
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT8_C(0x00)) & UINT32_C(0xFF));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->edx);
    LIFT_STORE16(cpu->esp + UINT32_C(0x00000014), (cpu->eax & UINT32_C(0xFFFF)));
    LIFT_STORE8(cpu->esp + UINT32_C(0x00000016), (cpu->ecx & UINT32_C(0xFF)));
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_BLOCK(label_0009B9B0, UINT32_C(0x0049B9B0));
    cpu->eax = (uint32_t)(UINT32_C(0xCCCCCCCD));
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 0u);
    cpu->edx = (uint32_t)(lift_shift_right(cpu, cpu->edx, (uint32_t)(UINT32_C(0x00000003)), 32u));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((cpu->edx & UINT32_C(0xFF))) & UINT32_C(0xFF));
    LIFT_ADD((cpu->ecx & UINT32_C(0xFF)), (cpu->ecx & UINT32_C(0xFF)), 0u, 8u, cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x00000030))));
    LIFT_ADD((cpu->ecx & UINT32_C(0xFF)), (cpu->ecx & UINT32_C(0xFF)), 0u, 8u, cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    LIFT_STORE8(cpu->esp + UINT32_C(0x00000010), (cpu->eax & UINT32_C(0xFF)));
    LIFT_ADD((cpu->edx & UINT32_C(0xFF)), (cpu->ecx & UINT32_C(0xFF)), 0u, 8u, cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    LIFT_ADD((cpu->edx & UINT32_C(0xFF)), (cpu->edx & UINT32_C(0xFF)), 0u, 8u, cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)((cpu->ebx & UINT32_C(0xFF))) & UINT32_C(0xFF));
    LIFT_SUB((cpu->eax & UINT32_C(0xFF)), (cpu->edx & UINT32_C(0xFF)), 0u, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    LIFT_ADD((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000030), 0u, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE8(cpu->esp + UINT32_C(0x00000011), (cpu->eax & UINT32_C(0xFF)));
    LIFT_CALL_ENTER(sfera_sub_0042F2A0, UINT32_C(0x0049B9DE));
    LIFT_CMP(cpu->eax, UINT32_C(0x000F4240), 32u);
    LIFT_JLE(label_0009B9F3, UINT32_C(0x0049B9E5));
    cpu->edx = (uint32_t)(UINT32_C(0x000F4240));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_CALL(sfera_sub_0044C020, LIFT_CODE_TOKEN_RVA(UINT32_C(0x0009B9F3)));
    LIFT_BLOCK(label_0009B9F3, UINT32_C(0x0049B9F3));
    LIFT_INC(cpu->ebx, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_CMP(cpu->ebx, UINT32_C(0x00000014), 32u);
    LIFT_JL(label_0009B9B0, UINT32_C(0x0049B9F9));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000018));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_POP2(cpu->esi, cpu->ebx);
    LIFT_LOGIC(cpu->ecx, cpu->esp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x0049BA08));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F5DD0, UINT32_C(0x004F5DD0));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0]));
    goto label_0009B950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5DE0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00009C40));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5DF1));
    LIFT_PUSH3(UINT32_C(0x00009C40), UINT32_C(0x00000000), cpu->eax);
    g_sfera_light_runtime.cell_light_ids.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5E03));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_light_runtime.cell_light_ids.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5E1C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5E22), UINT32_C(0x004F5E28));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA590)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_line), UINT32_C(0x0000016C));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5E43));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5E50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5E50));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0007F710));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5E61));
    LIFT_PUSH3(UINT32_C(0x0007F710), UINT32_C(0x00000000), cpu->eax);
    g_sfera_landscape_runtime.file_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5E73));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_landscape_runtime.file_records.capacity = (uint32_t)(UINT32_C(0x0000012C));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5E8C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5E92), UINT32_C(0x004F5E98));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA5B0)));
    g_sfera_landscape_runtime.file_records.debug_file[15] = 0;
    g_sfera_landscape_runtime.file_records.debug_line = UINT32_C(0x00000171);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5EB3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5EC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5EC0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00006D60));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5ED1));
    LIFT_PUSH3(UINT32_C(0x00006D60), UINT32_C(0x00000000), cpu->eax);
    g_sfera_interface_runtime.window_handle_table.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5EE3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_interface_runtime.window_handle_table.capacity = (uint32_t)(UINT32_C(0x00001B58));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5EFC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5F02), UINT32_C(0x004F5F08));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA5D0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_line), UINT32_C(0x00000193));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5F23));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5F30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5F30));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x001E8480));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5F41));
    LIFT_PUSH3(UINT32_C(0x001E8480), UINT32_C(0x00000000), cpu->eax);
    g_sfera_world_objects.object_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5F53));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_world_objects.object_handles.capacity = (uint32_t)(UINT32_C(0x0007A120));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5F6C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5F72), UINT32_C(0x004F5F78));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA5F0)));
    g_sfera_world_objects.object_handles.debug_file[15] = 0;
    g_sfera_world_objects.object_handles.debug_line = UINT32_C(0x000001A2);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5F93));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5FA0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0001D4C0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5FB1));
    LIFT_PUSH3(UINT32_C(0x0001D4C0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_world_objects.extended_object_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5FC3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_world_objects.extended_object_handles.capacity = (uint32_t)(UINT32_C(0x00007530));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5FDC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F5FE2), UINT32_C(0x004F5FE8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA610)));
    g_sfera_world_objects.extended_object_handles.debug_file[15] = 0;
    g_sfera_world_objects.extended_object_handles.debug_line = UINT32_C(0x000001A5);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6003));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000190));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6021));
    LIFT_PUSH3(UINT32_C(0x00000190), UINT32_C(0x00000000), cpu->eax);
    g_sfera_interface_runtime.windows.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6033));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_interface_runtime.windows.capacity = (uint32_t)(UINT32_C(0x00000064));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F604C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6052), UINT32_C(0x004F6058));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA630)));
    g_sfera_interface_runtime.windows.debug_file[15] = 0;
    g_sfera_interface_runtime.windows.debug_line = UINT32_C(0x000001A9);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6073));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6080));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6091));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    g_sfera_character_index_map.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F60A3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_character_index_map.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F60BC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_character_index_map.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F60C2), UINT32_C(0x004F60C8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA650)));
    g_sfera_character_index_map.debug_file[15] = '\0';
    g_sfera_character_index_map.debug_line = UINT32_C(0x000001BF);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F60E3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F60F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F60F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6101));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.object_visibility_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6113));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.object_visibility_indices.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F612C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6132), UINT32_C(0x004F6138));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA670)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_line), UINT32_C(0x000001C0));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6153));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6160));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6171));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.object_sort_keys.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6183));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.object_sort_keys.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F619C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F61A2), UINT32_C(0x004F61A8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA690)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_line), UINT32_C(0x000001C3));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F61C3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F61D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F61D0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F61E1));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.object_sort_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F61F3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.object_sort_indices.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F620C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6212), UINT32_C(0x004F6218));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA6B0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_line), UINT32_C(0x000001C4));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6233));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6240));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6251));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.object_draw_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6263));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.object_draw_indices.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F627C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6282), UINT32_C(0x004F6288));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA6D0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_line), UINT32_C(0x000001C5));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F62A3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F62B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F62B0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F62C1));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    g_sfera_collision_runtime.candidate_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F62D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_collision_runtime.candidate_handles.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F62EC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F62F2), UINT32_C(0x004F62F8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA6F0)));
    g_sfera_collision_runtime.candidate_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.candidate_handles.debug_line = UINT32_C(0x000001C6);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6313));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6320));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00054F60));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6331));
    LIFT_PUSH3(UINT32_C(0x00054F60), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.scene_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6343));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.scene_records.capacity = (uint32_t)(UINT32_C(0x00000BB8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F635C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6362), UINT32_C(0x004F6368));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA710)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_line), UINT32_C(0x000001E3));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6383));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6390));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000000F0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F63A1));
    LIFT_PUSH3(UINT32_C(0x000000F0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.reflection_targets.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F63B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.reflection_targets.capacity = (uint32_t)(UINT32_C(0x0000000A));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F63CC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F63D2), UINT32_C(0x004F63D8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA730)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_line), UINT32_C(0x00000236));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F63F3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6400));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00002A30));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6411));
    LIFT_PUSH3(UINT32_C(0x00002A30), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.scene_points.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6423));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.scene_points.capacity = (uint32_t)(UINT32_C(0x00000384));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F643C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6442), UINT32_C(0x004F6448));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA750)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_line), UINT32_C(0x0000033C));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6463));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6470));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000024));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6481));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]) = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A8)]), UINT32_C(0x00000009));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F64E4));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000AC)]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F64EA), UINT32_C(0x004F64F0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA770)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000BB)]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000CC)]), UINT32_C(0x00000633));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F650B));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6510));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000400));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6521));
    LIFT_PUSH3(UINT32_C(0x00000400), UINT32_C(0x00000000), cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000DC)]) = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6533));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000E0)]), UINT32_C(0x00000100));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F654C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000E4)]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6552), UINT32_C(0x004F6558));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA790)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000F3)]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x00000104)]), UINT32_C(0x000006B0));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6573));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6580));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6591));
    g_sfera_client_array_runtime.line_6b1_indices.data = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.capacity), UINT32_C(0x0000000A));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.maximum), UINT32_C(0x00000014));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.growth), UINT32_C(0x00000005));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F661A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6620), UINT32_C(0x004F6626));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA7B0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_line), UINT32_C(0x000006B1));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6641));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6650(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6650));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6661));
    g_sfera_recovered_static_runtime.primary_auto_array.data = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.capacity), UINT32_C(0x0000000A));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.maximum), UINT32_C(0x00000014));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.growth), UINT32_C(0x00000005));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F66EA));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F66F0), UINT32_C(0x004F66F6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA7D0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_line), UINT32_C(0x000006B2));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6711));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6720(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6720));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6731));
    g_sfera_client_array_runtime.line_6b3_indices.data = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.capacity), UINT32_C(0x0000000A));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.maximum), UINT32_C(0x00000014));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.growth), UINT32_C(0x00000005));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F67BA));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F67C0), UINT32_C(0x004F67C6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA7F0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_line), UINT32_C(0x000006B3));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F67E1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F67F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F67F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6801));
    g_sfera_client_array_runtime.line_6b4_indices.data = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.capacity), UINT32_C(0x0000000A));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.maximum), UINT32_C(0x00000014));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.growth), UINT32_C(0x00000005));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.element_size), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F688A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6890), UINT32_C(0x004F6896));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA810)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_line), UINT32_C(0x000006B4));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F68B1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F68C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F68C0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000001E0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F68D1));
    LIFT_PUSH3(UINT32_C(0x000001E0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.line_6b5_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F68E3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.capacity), UINT32_C(0x0000000A));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.maximum), UINT32_C(0x00000014));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.growth), UINT32_C(0x00000005));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.element_size), UINT32_C(0x00000030));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F691A));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6920), UINT32_C(0x004F6926));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA830)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_line), UINT32_C(0x000006B5));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6941));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6950));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000240));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6961));
    LIFT_PUSH3(UINT32_C(0x00000240), UINT32_C(0x00000000), cpu->eax);
    g_sfera_light_runtime.cell_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6973));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_light_runtime.cell_indices.capacity = (uint32_t)(UINT32_C(0x00000090));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F698C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6992), UINT32_C(0x004F6998));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA850)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_line), UINT32_C(0x00001247));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F69B3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F69C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F69C0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00003600));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F69D1));
    LIFT_PUSH3(UINT32_C(0x00003600), UINT32_C(0x00000000), cpu->eax);
    g_sfera_light_runtime.cell_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F69E3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_light_runtime.cell_records.capacity = (uint32_t)(UINT32_C(0x00000090));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F69FC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6A02), UINT32_C(0x004F6A08));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA870)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_line), UINT32_C(0x00001248));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6A23));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6A30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6A30));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00009C40));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6A41));
    LIFT_PUSH3(UINT32_C(0x00009C40), UINT32_C(0x00000000), cpu->eax);
    g_sfera_landscape_runtime.microtexture_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6A53));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_landscape_runtime.microtexture_handles.capacity = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6A6C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6A72), UINT32_C(0x004F6A78));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA890)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_line), UINT32_C(0x0000124A));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6A93));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6AA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6AA0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00001F40));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6AB1));
    LIFT_PUSH3(UINT32_C(0x00001F40), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.surface_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6AC3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.surface_handles.capacity = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6ADC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6AE2), UINT32_C(0x004F6AE8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA8B0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_line), UINT32_C(0x0000124B));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6B03));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6B10));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000B7980));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6B21));
    LIFT_PUSH3(UINT32_C(0x000B7980), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.line_124d_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6B33));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_124d_records.capacity), UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6B4C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6B52), UINT32_C(0x004F6B58));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA8D0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_line), UINT32_C(0x0000124D));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6B73));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6B80));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0000FA00));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6B91));
    LIFT_PUSH3(UINT32_C(0x0000FA00), UINT32_C(0x00000000), cpu->eax);
    g_sfera_recovered_static_runtime.tertiary_auto_array.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6BA3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.capacity), UINT32_C(0x000007D0));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.maximum), UINT32_C(0x00000BB8));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.growth), UINT32_C(0x000001F4));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.element_size), UINT32_C(0x00000020));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6BDA));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6BE0), UINT32_C(0x004F6BE6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA8F0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_line), UINT32_C(0x0000124F));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6C01));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6C10));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000030));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6C21));
    LIFT_PUSH3(UINT32_C(0x00000030), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.render_pass_slots.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6C30));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.render_pass_slots.capacity = (uint32_t)(UINT32_C(0x0000000C));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6C49));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6C4F), UINT32_C(0x004F6C55));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA910)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_line), UINT32_C(0x0000125B));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6C70));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6C80));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00061A80));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6C91));
    LIFT_PUSH3(UINT32_C(0x00061A80), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.surface_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6CA3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.surface_records.capacity = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6CBC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6CC2), UINT32_C(0x004F6CC8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA930)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_line), UINT32_C(0x00001264));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6CE3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6CF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6CF0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6D01));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.surface_index_map.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6D13));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.surface_index_map.capacity = (uint32_t)(UINT32_C(0x00009C40));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6D2C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6D32), UINT32_C(0x004F6D38));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA950)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_line), UINT32_C(0x00001266));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6D53));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6D60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6D60));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6D71));
    LIFT_PUSH3(UINT32_C(0x00000FA0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_light_runtime.handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6D83));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_light_runtime.handles.capacity = (uint32_t)(UINT32_C(0x000003E8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6D9C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6DA2), UINT32_C(0x004F6DA8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA970)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_line), UINT32_C(0x0000127E));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6DC3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6DD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6DD0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6DE1));
    LIFT_PUSH3(UINT32_C(0x000007D0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_light_runtime.visible_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6DF3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_light_runtime.visible_handles.capacity = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6E0C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6E12), UINT32_C(0x004F6E18));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA990)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_line), UINT32_C(0x00001280));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6E33));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6E40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6E40));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0000007C));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6E51));
    LIFT_PUSH3(UINT32_C(0x0000007C), UINT32_C(0x00000000), cpu->eax);
    g_sfera_light_runtime.active_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6E60));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_light_runtime.active_handles.capacity = (uint32_t)(UINT32_C(0x0000001F));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6E79));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6E7F), UINT32_C(0x004F6E85));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA9B0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_line), UINT32_C(0x00001282));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6EA0));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6EB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6EB0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000003E8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6EC1));
    LIFT_PUSH3(UINT32_C(0x000003E8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_mesh_partition_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6ED3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_mesh_partition_indices.capacity = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6EEC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6EF2), UINT32_C(0x004F6EF8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA9D0)));
    g_sfera_mesh_partition_indices.debug_file[15] = '\0';
    g_sfera_mesh_partition_indices.debug_line = UINT32_C(0x00001392);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6F13));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6F20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6F20));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000030)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F6F2A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F6F6D, UINT32_C(0x004F6F31));
    g_sfera_model_registry_runtime.sentinel = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(g_sfera_model_registry_runtime.sentinel);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    cpu->eax = (uint32_t)(g_sfera_model_registry_runtime.sentinel);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000008), cpu->eax);
    cpu->ecx = (uint32_t)(g_sfera_model_registry_runtime.sentinel);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->ecx + UINT32_C(0x0000002C), (cpu->eax & UINT32_C(0xFF)));
    cpu->edx = (uint32_t)(g_sfera_model_registry_runtime.sentinel);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAC90)));
    LIFT_STORE8(cpu->edx + UINT32_C(0x0000002D), (cpu->eax & UINT32_C(0xFF)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6F66));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F6F6D, UINT32_C(0x004F6F6D));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F6F7D), UINT32_C(0x004F6F83));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F6F9A));
    LIFT_TRAP_RETURN(UINT32_C(0x004F6F9A), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6FA0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00023280));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6FB1));
    LIFT_PUSH3(UINT32_C(0x00023280), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.line_24de_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6FC3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24de_records.capacity), UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6FDC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F6FE2), UINT32_C(0x004F6FE8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FA9F0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_line), UINT32_C(0x000024DE));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7003));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00021D68));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7021));
    LIFT_PUSH3(UINT32_C(0x00021D68), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.line_24e0_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7033));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.capacity), UINT32_C(0x000026AC));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F704C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7052), UINT32_C(0x004F7058));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAA10)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_line), UINT32_C(0x000024E0));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7073));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7080));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00007D00));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7091));
    LIFT_PUSH3(UINT32_C(0x00007D00), UINT32_C(0x00000000), cpu->eax);
    g_sfera_client_array_runtime.line_24e2_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F70A3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.capacity), UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F70BC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F70C2), UINT32_C(0x004F70C8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAA30)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_line), UINT32_C(0x000024E2));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F70E3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F70F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F70F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00004000));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7101));
    LIFT_PUSH3(UINT32_C(0x00004000), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.model_matrices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7113));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.model_matrices.capacity = (uint32_t)(UINT32_C(0x00000100));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F712C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7132), UINT32_C(0x004F7138));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAA50)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_line), UINT32_C(0x000024EB));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7153));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7160));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000140));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7171));
    LIFT_PUSH3(UINT32_C(0x00000140), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.character_matrices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7183));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.character_matrices.capacity = (uint32_t)(UINT32_C(0x00000005));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F719C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F71A2), UINT32_C(0x004F71A8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAA70)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_line), UINT32_C(0x000024F1));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F71C3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F71D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F71D0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0001D4C0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F71E1));
    LIFT_PUSH3(UINT32_C(0x0001D4C0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.object_positions.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F71F3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.object_positions.capacity = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F720C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7212), UINT32_C(0x004F7218));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAA90)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_line), UINT32_C(0x00002539));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7233));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7240));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000960));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7251));
    LIFT_PUSH3(UINT32_C(0x00000960), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.clip_vectors.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7263));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.clip_vectors.capacity = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F727C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7282), UINT32_C(0x004F7288));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAAB0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_line), UINT32_C(0x00002A71));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F72A3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F72B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F72B0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000320));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F72C1));
    LIFT_PUSH3(UINT32_C(0x00000320), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.clip_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F72D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.clip_indices.capacity = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F72EC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F72F2), UINT32_C(0x004F72F8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAAD0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_line), UINT32_C(0x00002A77));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7313));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7320));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000001E0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7331));
    LIFT_PUSH3(UINT32_C(0x000001E0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.clip_points.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7343));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.clip_points.capacity = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F735C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7362), UINT32_C(0x004F7368));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAAF0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_line), UINT32_C(0x00002A84));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7383));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7390));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00027100));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F73A1));
    LIFT_PUSH3(UINT32_C(0x00027100), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.cloud_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F73B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.cloud_records.capacity = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F73CC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F73D2), UINT32_C(0x004F73D8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAB10)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_line), UINT32_C(0x00002A85));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F73F3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7400));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000050));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7411));
    LIFT_PUSH3(UINT32_C(0x00000050), UINT32_C(0x00000000), cpu->eax);
    g_sfera_collision_runtime.near_result_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7420));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_collision_runtime.near_result_handles.capacity = (uint32_t)(UINT32_C(0x00000014));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F7439));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F743F), UINT32_C(0x004F7445));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAB30)));
    g_sfera_collision_runtime.near_result_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.near_result_handles.debug_line = UINT32_C(0x00002A86);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7460));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7470));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x04C5BDA0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7481));
    LIFT_PUSH3(UINT32_C(0x04C5BDA0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.world_cell_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7493));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.world_cell_records.capacity = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F74AC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F74B2), UINT32_C(0x004F74B8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAB50)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_line), UINT32_C(0x00002A94));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F74D3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F74E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F74E0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F74F1));
    LIFT_PUSH3(UINT32_C(0x00000FA0), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.render_ranges.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7503));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.render_ranges.capacity = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F751C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7522), UINT32_C(0x004F7528));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAB70)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_line), UINT32_C(0x00003C0D));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7543));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7550));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0009C400));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7561));
    LIFT_PUSH3(UINT32_C(0x0009C400), UINT32_C(0x00000000), cpu->eax);
    g_sfera_scene_array_runtime.render_work_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7573));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_scene_array_runtime.render_work_records.capacity = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F758C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7592), UINT32_C(0x004F7598));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAB90)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_line), UINT32_C(0x00003C0F));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F75B3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F75C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F75C0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000168));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F75D1));
    LIFT_PUSH3(UINT32_C(0x00000168), UINT32_C(0x00000000), cpu->eax);
    g_sfera_grass_runtime.type_records.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F75E3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_grass_runtime.type_records.capacity = (uint32_t)(UINT32_C(0x00000014));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F75FC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7602), UINT32_C(0x004F7608));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FABB0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_line), UINT32_C(0x00004409));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7623));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7630));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0000BB80));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7641));
    LIFT_PUSH3(UINT32_C(0x0000BB80), UINT32_C(0x00000000), cpu->eax);
    g_sfera_grass_runtime.instance_offsets.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7653));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_grass_runtime.instance_offsets.capacity = (uint32_t)(UINT32_C(0x00002EE0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F766C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7672), UINT32_C(0x004F7678));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FABD0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_line), UINT32_C(0x0000440A));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7693));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F76A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F76A0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x0000BB80));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F76B1));
    LIFT_PUSH3(UINT32_C(0x0000BB80), UINT32_C(0x00000000), cpu->eax);
    g_sfera_grass_runtime.instance_indices.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F76C3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_grass_runtime.instance_indices.capacity = (uint32_t)(UINT32_C(0x00002EE0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F76DC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F76E2), UINT32_C(0x004F76E8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FABF0)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_line), UINT32_C(0x0000440B));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7703));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7710));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7721));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    g_sfera_grass_runtime.model_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7733));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp"));
    g_sfera_grass_runtime.model_handles.capacity = (uint32_t)(UINT32_C(0x00000032));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F774C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F7752), UINT32_C(0x004F7758));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAC10)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.debug_line), UINT32_C(0x0000440C));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7773));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7780));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].transform));
    g_sfera_spatial_states[5u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7797));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FACF0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F77A1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F77B0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[5u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F77E9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F77F0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].transform));
    g_sfera_spatial_states[6u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7807));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD00)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7811));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7820(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7820));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[6u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7859));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7860(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7860));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].transform));
    g_sfera_spatial_states[7u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7877));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD10)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7881));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7890));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[7u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F78C9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F78D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F78D0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].transform));
    g_sfera_spatial_states[8u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F78E7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD20)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F78F1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7900));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[8u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7939));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7940));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].transform));
    g_sfera_spatial_states[9u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7957));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD30)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7961));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7970(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7970));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[9u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F79A9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F79B0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].transform));
    g_sfera_spatial_states[10u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F79C7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD40)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F79D1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F79E0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[10u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7A19));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7A20));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].transform));
    g_sfera_spatial_states[11u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7A37));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD50)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7A41));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7A50));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[11u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7A89));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7A90));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].transform));
    g_sfera_spatial_states[12u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7AA7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD60)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7AB1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7AC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7AC0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[12u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7AF9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7B00));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].transform));
    g_sfera_spatial_states[13u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7B17));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD70)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7B21));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7B30));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[13u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7B69));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7B70));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].transform));
    g_sfera_spatial_states[14u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7B87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD80)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7B91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7BA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[14u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7BD9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7BE0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAD90)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7BEA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7BF0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_shadow_object_storage[0]));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_shadow_runtime.aligned_global_object));
    g_sfera_shadow_runtime.aligned_global_object = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7C07));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FADA0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7C11));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7C20));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_shadow_object_storage[0x60]));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7C59));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7C60));
    LIFT_PUSH2(UINT32_C(0x00000004), ((uint32_t)(uintptr_t)"\t\n\r "));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_server_parser_whitespace));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F7C71));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FADB0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7C7B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7C80));
    LIFT_PUSH2(UINT32_C(0x00000002), ((uint32_t)(uintptr_t)"\\/"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_server_parser_path_separators));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F7C91));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FADE0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7C9B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7CA0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].transform));
    g_sfera_spatial_states[15u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7CB7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAE10)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7CC1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7CD0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[15u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7D09));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7D10));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].transform));
    g_sfera_spatial_states[16u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7D27));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAE20)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7D31));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7D40));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[16u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7D79));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7D80));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].transform));
    g_sfera_spatial_states[17u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7D97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAE30)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7DA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7DB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[17u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7DE9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7DF0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAE40)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7DFA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7E00));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].transform));
    g_sfera_spatial_states[18u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7E17));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAEC0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7E21));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7E30));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[18u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7E69));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7E70));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].transform));
    g_sfera_spatial_states[19u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7E87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAED0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7E91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7EA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[19u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7ED9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7EE0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAEE0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7EEA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7EF0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].transform));
    g_sfera_spatial_states[20u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7F07));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAF20)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7F11));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7F20));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[20u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7F59));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7F60));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].transform));
    g_sfera_spatial_states[21u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7F77));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAF30)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7F81));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7F90));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[21u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7FC9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7FD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7FD0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].transform));
    g_sfera_spatial_states[22u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7FE7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAF40)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7FF1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8000));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[22u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8039));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8040));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].transform));
    g_sfera_spatial_states[23u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8057));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAF50)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8061));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8070));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[23u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F80A9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F80B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F80B0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    cpu->ecx = (uint32_t)(UINT32_C(0x00000190));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F80C1));
    LIFT_PUSH3(UINT32_C(0x00000190), UINT32_C(0x00000000), cpu->eax);
    g_sfera_weather_runtime.sky_texture_handles.data = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F80D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\WeatherManager.cpp"));
    g_sfera_weather_runtime.sky_texture_handles.capacity = (uint32_t)(UINT32_C(0x00000064));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F80EC));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0]));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004F80F2), UINT32_C(0x004F80F8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAF60)));
    LIFT_STORE8(((uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[15]), UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_line), UINT32_C(0x00000157));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8113));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8120));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].transform));
    g_sfera_spatial_states[24u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8137));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAF80)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8141));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8150));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[24u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8189));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8190(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8190));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].transform));
    g_sfera_spatial_states[25u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F81A7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FAF90)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F81B1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F81C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F81C0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[25u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F81F9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8200(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8200));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8220));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8240));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].transform));
    g_sfera_spatial_states[26u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8257));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB000)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8261));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8270));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[26u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F82A9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F82B0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F82D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F82F0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].transform));
    g_sfera_spatial_states[27u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8307));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB070)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8311));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8320));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[27u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8359));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8360(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8360));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].transform));
    g_sfera_spatial_states[28u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8377));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB080)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8381));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8390));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[28u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F83C9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F83D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F83F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8410(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8410));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].transform));
    g_sfera_spatial_states[29u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8427));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB0F0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8431));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8440(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8440));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[29u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8479));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8480(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8480));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F84A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F84C0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].transform));
    g_sfera_spatial_states[30u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F84D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB160)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F84E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F84F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[30u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8529));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8530(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8530));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8550));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8570(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8570));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].transform));
    g_sfera_spatial_states[31u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8587));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB1D0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8591));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F85A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[31u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F85D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F85E0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB1E0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F85EA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F85F0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].transform));
    g_sfera_spatial_states[32u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8607));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB220)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8611));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8620(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8620));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[32u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8659));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8660(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8660));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8680(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8680));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F86A0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].transform));
    g_sfera_spatial_states[33u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F86B7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB290)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F86C1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F86D0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[33u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8709));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8710));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].transform));
    g_sfera_spatial_states[34u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8727));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB2A0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8731));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8740(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8740));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[34u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8779));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8780));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F87A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F87C0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].transform));
    g_sfera_spatial_states[35u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F87D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB310)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F87E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F87F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[35u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8829));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8830));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8850(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8850));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8870));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].transform));
    g_sfera_spatial_states[36u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8887));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB380)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8891));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F88A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[36u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F88D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F88E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8900));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8920(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8920));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].transform));
    g_sfera_spatial_states[37u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8937));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB3F0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8941));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8950));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[37u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8989));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8990));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F89B0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F89D0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].transform));
    g_sfera_spatial_states[38u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F89E7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB460)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F89F1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A00));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[38u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8A39));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A80));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000040)]));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000030)]));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000030)]) = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8A97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB4D0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8AA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8AB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x000000A8)]));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8AE9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8AF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8B10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8B30));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000C)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F8B3A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F8B61, UINT32_C(0x004F8B41));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000012C)]) = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000012C)]));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB540)));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8B5A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F8B61, UINT32_C(0x004F8B61));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F8B71), UINT32_C(0x004F8B77));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F8B8E));
    LIFT_TRAP_RETURN(UINT32_C(0x004F8B8E), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8B90));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000C)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F8B9A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F8BC1, UINT32_C(0x004F8BA1));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000120)]) = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000120)]));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB590)));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8BBA));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F8BC1, UINT32_C(0x004F8BC1));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F8BD1), UINT32_C(0x004F8BD7));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F8BEE));
    LIFT_TRAP_RETURN(UINT32_C(0x004F8BEE), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8BF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8BF0));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000C)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F8BFA));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F8C21, UINT32_C(0x004F8C01));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000009C)]) = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000009C)]));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB5E0)));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8C1A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F8C21, UINT32_C(0x004F8C21));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F8C31), UINT32_C(0x004F8C37));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F8C4E));
    LIFT_TRAP_RETURN(UINT32_C(0x004F8C4E), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8C50));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB680)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8C5A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8C60));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000018))));
    (void)0; /* source SEH registration eliminated */
    LIFT_ZERO(cpu->esi, 32u);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F8C91));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000F8CE7, UINT32_C(0x004F8C98));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000108)]) = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->edx);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000108)]));
    LIFT_STORE32(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000108)]));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB630)));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000010C)]) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000110)]) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000114)]) = (uint32_t)(cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000118)]) = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8CD3));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000018));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x0000001C));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F8CE7, UINT32_C(0x004F8CE7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->esi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F8CF4), UINT32_C(0x004F8CFA));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F8D11));
    LIFT_TRAP_RETURN(UINT32_C(0x004F8D11), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8D20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8D20));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000002C)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F8D2A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F8D51, UINT32_C(0x004F8D31));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000024)]) = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000024)]));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB660)));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8D4A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F8D51, UINT32_C(0x004F8D51));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F8D61), UINT32_C(0x004F8D67));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F8D7E));
    LIFT_TRAP_RETURN(UINT32_C(0x004F8D7E), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8D80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8D80));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000148)]));
    LIFT_CALL_ENTER(sfera_sub_004CFE70, UINT32_C(0x004F8D8A));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB6D0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8D94));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8DA0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].transform));
    g_sfera_spatial_states[39u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8DB7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB6E0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8DC1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8DD0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[39u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8E09));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E50));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].transform));
    g_sfera_spatial_states[40u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8E67));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB750)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8E71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E80));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[40u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8EB9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8EC0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].transform));
    g_sfera_spatial_states[41u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8ED7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB760)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8EE1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8EF0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[41u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8F29));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8F30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8F50));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8F70));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].transform));
    g_sfera_spatial_states[42u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8F87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB7D0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8F91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8FA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[42u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8FD9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8FE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8FE0));
    LIFT_PUSH2(UINT32_C(0x00000004), ((uint32_t)(uintptr_t)"\t\n\r "));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_menu_parser_whitespace));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8FF1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB7E0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8FFB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9000));
    LIFT_PUSH2(UINT32_C(0x00000002), ((uint32_t)(uintptr_t)"\\/"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_menu_parser_path_separators));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9011));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB810)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F901B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9020(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9020));
    LIFT_PUSH2(UINT32_C(0x0000004D), ((uint32_t)(uintptr_t)"%s(): MenuList control must have '%s' parameter in file '%s', lines: [%d, %d]"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_menu_list_missing_parameter_message));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9031));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB840)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F903B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9040));
    LIFT_PUSH2(UINT32_C(0x0000003B), ((uint32_t)(uintptr_t)"%s(): Not enough args in '%s' in file '%s', lines: [%d, %d]"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_menu_not_enough_arguments_message));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9051));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB870)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F905B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9060(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9060));
    LIFT_PUSH2(UINT32_C(0x00000020), ((uint32_t)(uintptr_t)"%s(): failed to find sprite '%s'"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_menu_sprite_not_found_message));
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9071));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB8A0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F907B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9080));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].transform));
    g_sfera_spatial_states[43u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9097));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB8D0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F90A1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F90B0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[43u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F90E9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F90F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9110(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9110));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9130(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9130));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].transform));
    g_sfera_spatial_states[44u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9147));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB940)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9151));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9160));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[44u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9199));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F91A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F91C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F91E0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].transform));
    g_sfera_spatial_states[45u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F91F7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB9B0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9201));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9210(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9210));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[45u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9249));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9250(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9250));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].transform));
    g_sfera_spatial_states[46u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9267));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FB9C0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9271));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9280));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[46u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F92B9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F92C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F92E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9300(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9300));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].transform));
    g_sfera_spatial_states[47u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9317));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBA30)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9321));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9330(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9330));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[47u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9369));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9370(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9370));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9390));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F93B0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].transform));
    g_sfera_spatial_states[48u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F93C7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBAA0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F93D1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F93E0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[48u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9419));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9420(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9420));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9440(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9440));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9460(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9460));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].transform));
    g_sfera_spatial_states[49u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9477));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBB10)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9481));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9490(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9490));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[49u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F94C9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F94D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F94F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9510));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].transform));
    g_sfera_spatial_states[50u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9527));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBB80)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9531));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9540(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9540));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[50u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9579));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9580));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F95A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F95C0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].transform));
    g_sfera_spatial_states[51u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F95D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBBF0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F95E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F95F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[51u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9629));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9630));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9650(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9650));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9670(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9670));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_options_dialog_object_storage[0]));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.aligned_storage_token));
    g_sfera_options_dialog_runtime.aligned_storage_token = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9687));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBC60)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9691));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F96A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_options_dialog_object_storage[0x60]));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F96D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F96E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9700));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9720(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9720));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBD50)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F972A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9730));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBD10)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F973A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9740(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9740));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBCD0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F974A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9750(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9750));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].transform));
    g_sfera_spatial_states[52u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9767));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBD90)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9771));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9780));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[52u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F97B9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F97C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F97E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9800(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9800));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].transform));
    g_sfera_spatial_states[53u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9817));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBE00)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9821));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9830));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[53u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9869));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9870));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].transform));
    g_sfera_spatial_states[54u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9887));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBE10)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9891));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F98A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[54u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F98D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F98E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9900));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9920(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9920));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].transform));
    g_sfera_spatial_states[55u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9937));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBE80)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9941));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9950));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[55u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9989));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9990));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F99B0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F99D0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].transform));
    g_sfera_spatial_states[56u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F99E7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBEF0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F99F1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A00));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[56u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9A39));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A80));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].transform));
    g_sfera_spatial_states[57u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9A97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBF60)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9AA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9AB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9AB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[57u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9AE9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9AF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9AF0));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000C)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F9AFA));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F9B21, UINT32_C(0x004F9B01));
    g_sfera_win32_dialog_registry.sentinel = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(g_sfera_win32_dialog_registry.sentinel);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBF70)));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9B1A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F9B21, UINT32_C(0x004F9B21));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_exception_ctor, UINT32_C(0x004F9B31), UINT32_C(0x004F9B37));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_LEGACY_VPTR_BAD_ALLOC);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F9B4E));
    LIFT_TRAP_RETURN(UINT32_C(0x004F9B4E), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9B50));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].transform));
    g_sfera_spatial_states[58u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9B67));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FBFC0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9B71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9B80));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[58u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9BB9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9BC0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9BE0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C00));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_crash_report_runtime));
    LIFT_CALL_ENTER(sfera_sub_004D6720, UINT32_C(0x004F9C0A));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC090)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9C14));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C20));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].transform));
    g_sfera_spatial_states[59u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9C37));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC0A0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9C41));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C50));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[59u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9C89));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C90));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].transform));
    g_sfera_spatial_states[60u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9CA7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC0B0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9CB1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9CC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9CC0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[60u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9CF9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9D00));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].transform));
    g_sfera_spatial_states[61u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9D17));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC0C0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9D21));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9D30));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[61u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9D69));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9D70));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].transform));
    g_sfera_spatial_states[62u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9D87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC0E0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9D91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9DA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[62u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9DD9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9DE0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].transform));
    g_sfera_spatial_states[63u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9DF7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC0F0)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9E01));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9E10));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[63u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9E49));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9E50));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].transform));
    g_sfera_spatial_states[64u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9E67));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC100)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9E71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9E80));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[64u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9EB9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9EC0));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].transform));
    g_sfera_spatial_states[65u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9ED7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC110)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9EE1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9EF0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[65u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9F29));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9F30));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].transform.matrix));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].transform));
    g_sfera_spatial_states[66u].transform.matrix_address = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9F47));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC120)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9F51));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9F60));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_x87_push(cpu, (double)-3.4028234663852886e+38f);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_spatial_states[66u].bounds));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9F99));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9FA0));
    LIFT_PUSH6(UINT32_C(0x00000200), UINT32_C(0x00000000), UINT32_C(0x000F4240), UINT32_C(0x0000000C), ((uint32_t)(uintptr_t)"$d $t "), ((uint32_t)(uintptr_t)"LogMemory.log"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_log_memory_object));
    LIFT_CALL_ENTER(sfera_sub_004EC500, UINT32_C(0x004F9FC2));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC130)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9FCC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9FD0));
    LIFT_PUSH6(UINT32_C(0x00000840), LIFT_CALLBACK(sfera_sub_004EBEF0), UINT32_C(0x000F4240), UINT32_C(0x00000000), ((uint32_t)(uintptr_t)"$d $t $u"), ((uint32_t)(uintptr_t)"Warnings.log"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_log_warnings_object));
    LIFT_CALL_ENTER(sfera_sub_004EC500, UINT32_C(0x004F9FF5));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC140)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9FFF));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA010));
    LIFT_PUSH6(UINT32_C(0x00000840), LIFT_CALLBACK(sfera_sub_004EBEF0), UINT32_C(0x000F4240), UINT32_C(0x0000000D), ((uint32_t)(uintptr_t)"$d $t $u"), ((uint32_t)(uintptr_t)"Errors.log"));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_log_errors_object));
    LIFT_CALL_ENTER(sfera_sub_004EC500, UINT32_C(0x004FA035));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC150)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004FA03F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA041(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA041));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK(sfera_sub_004FC15A)));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004FA04B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA050(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA050));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA060(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA060));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA070));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA080));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA090(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA090));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA0A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA0B0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA0C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA0D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA0D0));
    cpu->eax = (uint32_t)(g_sfera_execution_monitor_runtime.thread_handle);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(SFERA_IMPORT_KERNEL32_WaitForSingleObject);
    LIFT_PUSH2(UINT32_C(0x00000000), cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0E1)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0DF)))) { return; }
    LIFT_ENTER(UINT32_C(0x004FA0E1));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FA117, UINT32_C(0x004FA0E5));
    cpu->ecx = (uint32_t)(g_sfera_execution_monitor_runtime.thread_handle);
    LIFT_PUSH2(UINT32_C(0x00000064), cpu->ecx);
    g_sfera_execution_monitor_runtime.stop_requested = UINT16_C(1);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0F9)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0F7)))) { return; }
    LIFT_ENTER(UINT32_C(0x004FA0F9));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FA10C, UINT32_C(0x004FA0FD));
    cpu->edx = (uint32_t)(g_sfera_execution_monitor_runtime.thread_handle);
    LIFT_PUSH2(UINT32_C(0x00000000), cpu->edx);
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_TerminateThread, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA106)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA10C));
    LIFT_BLOCK(label_000FA10C, UINT32_C(0x004FA10C));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_execution_monitor_runtime.critical_section[0])));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_DeleteCriticalSection, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA111)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA117));
    LIFT_BLOCK(label_000FA117, UINT32_C(0x004FA117));
    LIFT_EPILOGUE1(0u, cpu->esi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA120));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA130(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA130));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA140(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA140));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA150));
    cpu->ecx = (uint32_t)(g_sfera_effect_manager.render_slots.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA162));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA170));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH2(cpu->eax, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(g_sfera_effect_items.block_vector_end);
    cpu->eax = (uint32_t)(g_sfera_effect_items.block_vector_begin);
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ZERO(cpu->esi, 32u);
    cpu->ecx = (uint32_t)(lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000002)), 32u));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000FA1BA, UINT32_C(0x004FA1AB));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_effect_items));
    LIFT_CALL_ENTER(sfera_sub_0042A290, UINT32_C(0x004FA1B5));
    cpu->eax = (uint32_t)(g_sfera_effect_items.block_vector_begin);
    LIFT_BLOCK(label_000FA1BA, UINT32_C(0x004FA1BA));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000FA1C7, UINT32_C(0x004FA1BE));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA1C4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA1C7, UINT32_C(0x004FA1C7));
    g_sfera_effect_items.block_vector_begin = (uint32_t)(cpu->esi);
    g_sfera_effect_items.block_vector_end = (uint32_t)(cpu->esi);
    g_sfera_effect_items.block_vector_capacity_end = cpu->esi;
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA1F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA1F0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (uint32_t)(g_sfera_effect_manager.effect_listeners.head);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_00406340, UINT32_C(0x004FA231));
    cpu->ecx = (uint32_t)(g_sfera_effect_manager.effect_listeners.head);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA23D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA250(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA250));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA260(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA260));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA270(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA270;
    LIFT_BLOCK(label_0002E630, UINT32_C(0x0042E630));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->edi + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_0002E681, UINT32_C(0x0042E639));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->edx = (uint32_t)(UINT32_C(0x00000104));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x0042E649));
    LIFT_LOAD32(cpu->esi, cpu->edi + UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_0002E680, UINT32_C(0x0042E650));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000004)))), UINT32_C(0x00000000), 32u);
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    LIFT_JZ(label_0002E677, UINT32_C(0x0042E65C));
    cpu->edx = (uint32_t)(UINT32_C(0x00000065));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x0042E66B));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0042E674));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_0002E677, UINT32_C(0x0042E677));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0042E67D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_0002E680, UINT32_C(0x0042E680));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_0002E681, UINT32_C(0x0042E681));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->edi + UINT32_C(0x0000000C)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_0002E6AD, UINT32_C(0x0042E687));
    cpu->edx = (uint32_t)(UINT32_C(0x00000105));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x0042E696));
    LIFT_LOAD32(cpu->edi, cpu->edi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JZ(label_0002E6AD, UINT32_C(0x0042E69D));
    cpu->ecx = (uint32_t)(cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_0042E250, UINT32_C(0x0042E6A4));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0042E6AA));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_0002E6AD, UINT32_C(0x0042E6AD));
    LIFT_EPILOGUE1(0u, cpu->edi);
    LIFT_BLOCK(label_000FA270, UINT32_C(0x004FA270));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_error_log_runtime.object[0]));
    goto label_0002E630;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA280));
    cpu->ecx = (uint32_t)(g_sfera_file_runtime.open_files.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA292));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA2A0));
    cpu->ecx = (uint32_t)(g_sfera_file_runtime.search_paths.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA2B2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA2C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA2D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA2E0));
    LIFT_CMP(g_sfera_shared_parser_whitespace.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FA2F7, UINT32_C(0x004FA2E9));
    cpu->eax = (uint32_t)(g_sfera_shared_parser_whitespace.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA2F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA2F7, UINT32_C(0x004FA2F7));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_shared_parser_whitespace.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_shared_parser_whitespace.size = cpu->eax;
    g_sfera_shared_parser_whitespace.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA310(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA310));
    LIFT_CMP(g_sfera_shared_parser_path_separators.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FA327, UINT32_C(0x004FA319));
    cpu->eax = (uint32_t)(g_sfera_shared_parser_path_separators.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA324));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA327, UINT32_C(0x004FA327));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_shared_parser_path_separators.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_shared_parser_path_separators.size = cpu->eax;
    g_sfera_shared_parser_path_separators.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA340(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA340));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA350));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA360(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA360;
    LIFT_BLOCK(label_000D7AB0, UINT32_C(0x004D7AB0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    cpu->edx = (uint32_t)(UINT32_C(0x00000013));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"CursorManager.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x004D7AC2));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000D7AD0, UINT32_C(0x004D7AC8));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    LIFT_BLOCK(label_000D7AD0, UINT32_C(0x004D7AD0));
    cpu->edx = (uint32_t)(UINT32_C(0x00000014));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"CursorManager.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x004D7ADF));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000D7AEF, UINT32_C(0x004D7AE7));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    LIFT_BLOCK(label_000D7AEF, UINT32_C(0x004D7AEF));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FA360, UINT32_C(0x004FA360));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0]));
    goto label_000D7AB0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA370(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA370));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA3A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA3D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA3E0));
    cpu->ecx = (uint32_t)(g_sfera_recovered_static_runtime.legacy_light_arrays[2].data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA3F2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA400));
    cpu->ecx = (uint32_t)(g_sfera_recovered_static_runtime.legacy_light_arrays[1].data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA412));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA420(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA420));
    cpu->ecx = (uint32_t)(g_sfera_recovered_static_runtime.legacy_light_arrays[0].data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA432));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA440(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA440));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA450(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA450));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA460(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA460;
    LIFT_BLOCK(label_0008A1B0, UINT32_C(0x0048A1B0));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_0008A1BF, UINT32_C(0x0048A1B5));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"CReadPathManager::~CReadPathManager: object not deinitialized"));
    LIFT_TAIL(sfera_sub_00459B10);
    LIFT_BLOCK(label_0008A1BF, UINT32_C(0x0048A1BF));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FA460, UINT32_C(0x004FA460));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000D0)]));
    goto label_0008A1B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA470));
    cpu->ecx = (uint32_t)(g_sfera_recovered_static_runtime.secondary_auto_array.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA482));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA490(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA490));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.e7_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA4A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA4B0));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.e8_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA4C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA4D0));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.e9_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA4E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA4F0));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.eb_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA502));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA510));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.ed_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA522));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA530(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA530));
    cpu->ecx = (uint32_t)(g_sfera_collision_runtime.contact_objects.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA542));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA550));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_102_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA562));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA570(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA570));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_105_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA582));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA590(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA590));
    cpu->ecx = (uint32_t)(g_sfera_light_runtime.cell_light_ids.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA5A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA5B0));
    cpu->ecx = (uint32_t)(g_sfera_landscape_runtime.file_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA5C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA5D0));
    cpu->ecx = (uint32_t)(g_sfera_interface_runtime.window_handle_table.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA5E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA5F0));
    cpu->ecx = (uint32_t)(g_sfera_world_objects.object_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA602));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA610(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA610));
    cpu->ecx = (uint32_t)(g_sfera_world_objects.extended_object_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA622));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA630));
    cpu->ecx = (uint32_t)(g_sfera_interface_runtime.windows.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA642));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA650(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA650));
    cpu->ecx = (uint32_t)(g_sfera_character_index_map.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA662));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA670(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA670));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.object_visibility_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA682));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA690(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA690));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.object_sort_keys.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA6A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA6B0));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.object_sort_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA6C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA6D0));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.object_draw_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA6E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA6F0));
    cpu->ecx = (uint32_t)(g_sfera_collision_runtime.candidate_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA702));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA710));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.scene_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA722));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA730));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.reflection_targets.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA742));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA750(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA750));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.scene_points.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA762));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA770));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000A4)]));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA782));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA790(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA790));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.storage[UINT32_C(0x000000DC)]));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA7A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA7B0));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_6b1_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA7C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA7D0));
    cpu->ecx = (uint32_t)(g_sfera_recovered_static_runtime.primary_auto_array.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA7E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA7F0));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_6b3_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA802));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA810));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_6b4_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA822));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA830));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_6b5_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA842));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA850(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA850));
    cpu->ecx = (uint32_t)(g_sfera_light_runtime.cell_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA862));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA870));
    cpu->ecx = (uint32_t)(g_sfera_light_runtime.cell_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA882));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA890));
    cpu->ecx = (uint32_t)(g_sfera_landscape_runtime.microtexture_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA8A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA8B0));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.surface_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA8C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA8D0));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_124d_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA8E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA8F0));
    cpu->ecx = (uint32_t)(g_sfera_recovered_static_runtime.tertiary_auto_array.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA902));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA910(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA910));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.render_pass_slots.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA922));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA930));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.surface_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA942));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA950));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.surface_index_map.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA962));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA970(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA970));
    cpu->ecx = (uint32_t)(g_sfera_light_runtime.handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA982));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA990));
    cpu->ecx = (uint32_t)(g_sfera_light_runtime.visible_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA9A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA9B0));
    cpu->ecx = (uint32_t)(g_sfera_light_runtime.active_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA9C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA9D0));
    cpu->ecx = (uint32_t)(g_sfera_mesh_partition_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA9E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA9F0));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_24de_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA02));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA10));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_24e0_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA22));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA30));
    cpu->ecx = (uint32_t)(g_sfera_client_array_runtime.line_24e2_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA42));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA50));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.model_matrices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA62));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA70));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.character_matrices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA82));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA90));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.object_positions.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAAA2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAAB0));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.clip_vectors.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAAC2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAAD0));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.clip_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAAE2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAAF0));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.clip_points.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB02));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB10));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.cloud_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB22));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB30));
    cpu->ecx = (uint32_t)(g_sfera_collision_runtime.near_result_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB42));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB50));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.world_cell_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB62));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB70));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.render_ranges.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB82));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB90));
    cpu->ecx = (uint32_t)(g_sfera_scene_array_runtime.render_work_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FABA2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FABB0));
    cpu->ecx = (uint32_t)(g_sfera_grass_runtime.type_records.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FABC2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FABD0));
    cpu->ecx = (uint32_t)(g_sfera_grass_runtime.instance_offsets.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FABE2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FABF0));
    cpu->ecx = (uint32_t)(g_sfera_grass_runtime.instance_indices.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAC02));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC10));
    cpu->ecx = (uint32_t)(g_sfera_grass_runtime.model_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAC22));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC90));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (uint32_t)(g_sfera_model_registry_runtime.sentinel);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_model_registry_runtime));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D400, UINT32_C(0x004FACD1));
    cpu->ecx = (uint32_t)(g_sfera_model_registry_runtime.sentinel);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FACDD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FACF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FACF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD00));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD20));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD50));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD70));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAD90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAD90));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_server_wall));
    LIFT_TAIL(sfera_sub_0048A6A0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FADA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FADB0));
    LIFT_CMP(g_sfera_server_parser_whitespace.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FADC7, UINT32_C(0x004FADB9));
    cpu->eax = (uint32_t)(g_sfera_server_parser_whitespace.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FADC4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FADC7, UINT32_C(0x004FADC7));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_server_parser_whitespace.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_server_parser_whitespace.size = (uint32_t)(cpu->eax);
    g_sfera_server_parser_whitespace.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FADE0));
    LIFT_CMP(g_sfera_server_parser_path_separators.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FADF7, UINT32_C(0x004FADE9));
    cpu->eax = (uint32_t)(g_sfera_server_parser_path_separators.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FADF4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FADF7, UINT32_C(0x004FADF7));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_server_parser_path_separators.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_server_parser_path_separators.size = cpu->eax;
    g_sfera_server_parser_path_separators.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAE10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAE20));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAE30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAE40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAE40));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH2(cpu->eax, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(g_sfera_sound_effect_items.block_vector_end);
    cpu->eax = (uint32_t)(g_sfera_sound_effect_items.block_vector_begin);
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ZERO(cpu->esi, 32u);
    cpu->ecx = (uint32_t)(lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000002)), 32u));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000FAE8A, UINT32_C(0x004FAE7B));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_sound_effect_items));
    LIFT_CALL_ENTER(sfera_sub_004974B0, UINT32_C(0x004FAE85));
    cpu->eax = (uint32_t)(g_sfera_sound_effect_items.block_vector_begin);
    LIFT_BLOCK(label_000FAE8A, UINT32_C(0x004FAE8A));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000FAE97, UINT32_C(0x004FAE8E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FAE94));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FAE97, UINT32_C(0x004FAE97));
    g_sfera_sound_effect_items.block_vector_begin = (uint32_t)(cpu->esi);
    g_sfera_sound_effect_items.block_vector_end = (uint32_t)(cpu->esi);
    g_sfera_sound_effect_items.block_vector_capacity_end = cpu->esi;
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAEC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAEC0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAED0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAED0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAEE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAEE0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_ZERO(cpu->esi, 32u);
    LIFT_CMP(g_sfera_sound_runtime.tracks.head, cpu->esi, 32u);
    LIFT_JZ(label_000FAF0F, UINT32_C(0x004FAEEB));
    cpu->eax = (uint32_t)(g_sfera_sound_runtime.tracks.tail);
    LIFT_BLOCK(label_000FAEF0, UINT32_C(0x004FAEF0));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000FAF07, UINT32_C(0x004FAEF4));
    LIFT_LOAD32(cpu->eax, cpu->eax + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_sound_runtime.tracks));
    LIFT_CALL_ENTER(sfera_sub_00498C30, UINT32_C(0x004FAF02));
    cpu->eax = (uint32_t)(g_sfera_sound_runtime.tracks.tail);
    LIFT_BLOCK(label_000FAF07, UINT32_C(0x004FAF07));
    LIFT_CMP(g_sfera_sound_runtime.tracks.head, cpu->esi, 32u);
    LIFT_JNZ_GOTO(label_000FAEF0);
    LIFT_BLOCK(label_000FAF0F, UINT32_C(0x004FAF0F));
    g_sfera_sound_runtime.tracks.tail = (uint32_t)(cpu->esi);
    g_sfera_sound_runtime.tracks.head = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE1(0u, cpu->esi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAF20));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAF30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAF40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAF50));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAF60));
    cpu->ecx = (uint32_t)(g_sfera_weather_runtime.sky_texture_handles.data);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAF72));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAF80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAF90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAF90));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAFA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAFA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAFD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAFD0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB040));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB070));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB080));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB090(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB090));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB0C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB0F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB100(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB100));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB130(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB130));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB160));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB170));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB1A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB1D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB1E0));
    cpu->eax = (uint32_t)(g_sfera_font_factory_runtime.fonts_begin);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FB1F2, UINT32_C(0x004FB1E9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB1EF));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB1F2, UINT32_C(0x004FB1F2));
    g_sfera_font_factory_runtime.fonts_begin = (uint32_t)(UINT32_C(0x00000000));
    g_sfera_font_factory_runtime.fonts_end = (uint32_t)(UINT32_C(0x00000000));
    g_sfera_font_factory_runtime.fonts_capacity = UINT32_C(0x00000000);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB220));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB230));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB260(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB260));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB290(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB290));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB2A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB2B0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB2E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB310(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB310));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB320));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB350));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB380(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB380));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB390));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB3C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB3F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB400));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB430(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB430));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB460(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB460));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB470));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB4A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB4D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB4E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB510));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB540(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB540));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000012C)]));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000012C)]));
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000012C)]));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000130)]) = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FB580, UINT32_C(0x004FB567));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FB568, UINT32_C(0x004FB568));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB570));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000012C)]));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_CMP(cpu->esi, cpu->ecx, 32u);
    LIFT_JNZ(label_000FB568, UINT32_C(0x004FB57F));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000FB580, UINT32_C(0x004FB580));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB586));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB590(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB590));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000120)]));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000120)]));
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000120)]));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000124)]) = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FB5D0, UINT32_C(0x004FB5B7));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FB5B8, UINT32_C(0x004FB5B8));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB5C0));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000120)]));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_CMP(cpu->esi, cpu->ecx, 32u);
    LIFT_JNZ(label_000FB5B8, UINT32_C(0x004FB5CF));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000FB5D0, UINT32_C(0x004FB5D0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB5D6));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB5E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB5E0));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000009C)]));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000009C)]));
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000009C)]));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x000000A0)]) = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FB620, UINT32_C(0x004FB607));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FB608, UINT32_C(0x004FB608));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB610));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000009C)]));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_CMP(cpu->esi, cpu->ecx, 32u);
    LIFT_JNZ(label_000FB608, UINT32_C(0x004FB61F));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000FB620, UINT32_C(0x004FB620));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB626));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB630));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000108)]));
    LIFT_CALL_ENTER(sfera_sub_0049FA40, UINT32_C(0x004FB63A));
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000108)]));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB645));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000108)]) = (uint32_t)(UINT32_C(0x00000000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB660(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB660));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000024)]));
    LIFT_CALL_ENTER(sfera_sub_004BC130, UINT32_C(0x004FB66A));
    cpu->eax = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000024)]));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB675));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB680(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB680));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000138)]));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000FB6AE, UINT32_C(0x004FB68B));
    LIFT_LOAD32(cpu->eax, cpu->esp);
    cpu->edx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000013C)]));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000144)]));
    LIFT_CALL_ENTER(sfera_sub_004BC000, UINT32_C(0x004FB69F));
    cpu->ecx = (uint32_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000138)]));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB6AB));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB6AE, UINT32_C(0x004FB6AE));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000138)]) = (uint32_t)(UINT32_C(0x00000000));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.storage[UINT32_C(0x0000013C)]) = (uint32_t)(UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000140)]), UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB6D0));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_interface_core_runtime.storage[UINT32_C(0x00000148)]));
    LIFT_TAIL(sfera_sub_004BC9F0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB6E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB6F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB720(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB720));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB750(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB750));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB760(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB760));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB770));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB7A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB7D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB7E0));
    LIFT_CMP(g_sfera_menu_parser_whitespace.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB7F7, UINT32_C(0x004FB7E9));
    cpu->eax = (uint32_t)(g_sfera_menu_parser_whitespace.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB7F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB7F7, UINT32_C(0x004FB7F7));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_menu_parser_whitespace.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_menu_parser_whitespace.size = (uint32_t)(cpu->eax);
    g_sfera_menu_parser_whitespace.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB810));
    LIFT_CMP(g_sfera_menu_parser_path_separators.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB827, UINT32_C(0x004FB819));
    cpu->eax = (uint32_t)(g_sfera_menu_parser_path_separators.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB824));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB827, UINT32_C(0x004FB827));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_menu_parser_path_separators.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_menu_parser_path_separators.size = (uint32_t)(cpu->eax);
    g_sfera_menu_parser_path_separators.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB840(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB840));
    LIFT_CMP(g_sfera_menu_list_missing_parameter_message.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB857, UINT32_C(0x004FB849));
    cpu->eax = (uint32_t)(g_sfera_menu_list_missing_parameter_message.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB854));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB857, UINT32_C(0x004FB857));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_menu_list_missing_parameter_message.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_menu_list_missing_parameter_message.size = (uint32_t)(cpu->eax);
    g_sfera_menu_list_missing_parameter_message.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB870));
    LIFT_CMP(g_sfera_menu_not_enough_arguments_message.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB887, UINT32_C(0x004FB879));
    cpu->eax = (uint32_t)(g_sfera_menu_not_enough_arguments_message.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB884));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB887, UINT32_C(0x004FB887));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_menu_not_enough_arguments_message.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_menu_not_enough_arguments_message.size = (uint32_t)(cpu->eax);
    g_sfera_menu_not_enough_arguments_message.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB8A0));
    LIFT_CMP(g_sfera_menu_sprite_not_found_message.capacity, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB8B7, UINT32_C(0x004FB8A9));
    cpu->eax = (uint32_t)(g_sfera_menu_sprite_not_found_message.storage.heap_pointer);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB8B4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB8B7, UINT32_C(0x004FB8B7));
    LIFT_ZERO(cpu->eax, 32u);
    g_sfera_menu_sprite_not_found_message.capacity = (uint32_t)(UINT32_C(0x0000000F));
    g_sfera_menu_sprite_not_found_message.size = (uint32_t)(cpu->eax);
    g_sfera_menu_sprite_not_found_message.storage.inline_buffer[0] = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB8D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB8E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB910(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB910));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB940));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB950));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB980(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB980));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB9B0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB9C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB9D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB9D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA00));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA70));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBAA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBAB0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBAE0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB20));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB50));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB90));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBBC0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBBF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC00));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC70));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBCA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBCD0));
    cpu->eax = (uint32_t)(g_sfera_options_dialog_runtime.chat_edit_fonts.begin);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FBCE2, UINT32_C(0x004FBCD9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBCDF));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBCE2, UINT32_C(0x004FBCE2));
    g_sfera_options_dialog_runtime.chat_edit_fonts.begin = (uint32_t)(UINT32_C(0x00000000));
    g_sfera_options_dialog_runtime.chat_edit_fonts.end = (uint32_t)(UINT32_C(0x00000000));
    g_sfera_options_dialog_runtime.chat_edit_fonts.capacity_end = UINT32_C(0x00000000);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBD10));
    cpu->eax = (uint32_t)(g_sfera_options_dialog_runtime.chat_list_fonts.begin);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FBD22, UINT32_C(0x004FBD19));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBD1F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBD22, UINT32_C(0x004FBD22));
    g_sfera_options_dialog_runtime.chat_list_fonts.begin = (uint32_t)(UINT32_C(0x00000000));
    g_sfera_options_dialog_runtime.chat_list_fonts.end = (uint32_t)(UINT32_C(0x00000000));
    g_sfera_options_dialog_runtime.chat_list_fonts.capacity_end = UINT32_C(0x00000000);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBD50));
    cpu->eax = (uint32_t)(g_sfera_options_dialog_runtime.graphics_modes.begin);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FBD62, UINT32_C(0x004FBD59));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBD5F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBD62, UINT32_C(0x004FBD62));
    g_sfera_options_dialog_runtime.graphics_modes.begin = (uint32_t)(UINT32_C(0x00000000));
    g_sfera_options_dialog_runtime.graphics_modes.end = (uint32_t)(UINT32_C(0x00000000));
    LIFT_STORE32(((uint32_t)(uintptr_t)&g_sfera_options_dialog_cleanup_state), UINT32_C(0x00000000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBD90));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBDA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBDD0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE00));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE20));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE50));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE90));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBEC0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBEF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF00));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF70));
    cpu->ecx = (uint32_t)(g_sfera_win32_dialog_registry.sentinel);
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)(g_sfera_win32_dialog_registry.sentinel);
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)(g_sfera_win32_dialog_registry.sentinel);
    g_sfera_win32_dialog_registry.size = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FBFB0, UINT32_C(0x004FBF97));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FBF98, UINT32_C(0x004FBF98));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBFA0));
    cpu->ecx = (uint32_t)(g_sfera_win32_dialog_registry.sentinel);
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_CMP(cpu->esi, cpu->ecx, 32u);
    LIFT_JNZ(label_000FBF98, UINT32_C(0x004FBFAF));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000FBFB0, UINT32_C(0x004FBFB0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBFB6));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBFC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBFC0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBFD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBFD0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC030(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC030));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (uint32_t)(g_sfera_control_reference_registry.sentinel);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_control_reference_registry));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004B2C40, UINT32_C(0x004FC071));
    cpu->ecx = (uint32_t)(g_sfera_control_reference_registry.sentinel);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FC07D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC090(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC090));
    cpu->eax = (uint32_t)(g_sfera_crash_report_runtime.previous_exception_filter);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_SetUnhandledExceptionFilter, UINT32_C(0x004FC096), UINT32_C(0x004FC09C));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC0A0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC0B0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC0C0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC0D0;
    LIFT_BLOCK(label_000D78B0, UINT32_C(0x004D78B0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000018))));
    (void)0; /* source SEH registration eliminated */
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->edi);
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    LIFT_CMP(cpu->esi, cpu->eax, 32u);
    LIFT_JZ(label_000D793C, UINT32_C(0x004D78E5));
    cpu->ebx = SFERA_IMPORT_USER32_DestroyCursor;
    LIFT_BLOCK(label_000D78F0, UINT32_C(0x004D78F0));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000028));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000D78F6)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000D78F4)))) { return; }
    LIFT_ENTER(UINT32_C(0x004D78F6));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000035)))), UINT32_C(0x00000000), 8u);
    LIFT_JNZ(label_000D7937, UINT32_C(0x004D78FC));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + UINT32_C(0x00000035)))), UINT32_C(0x00000000), 8u);
    LIFT_JNZ(label_000D791C, UINT32_C(0x004D7905));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + UINT32_C(0x00000035)))), UINT32_C(0x00000000), 8u);
    LIFT_JNZ(label_000D7937, UINT32_C(0x004D790F));
    (void)cpu;
    LIFT_BLOCK(label_000D7910, UINT32_C(0x004D7910));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + UINT32_C(0x00000035)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000D7910, UINT32_C(0x004D791A));
    goto label_000D7937;
    LIFT_BLOCK(label_000D791C, UINT32_C(0x004D791C));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + UINT32_C(0x00000035)))), UINT32_C(0x00000000), 8u);
    LIFT_JNZ_GOTO(label_000D7935);
    LIFT_BLOCK(label_000D7925, UINT32_C(0x004D7925));
    LIFT_CMP(cpu->esi, lift_load32(((uint32_t)(cpu->eax + UINT32_C(0x00000008)))), 32u);
    LIFT_JNZ(label_000D7935, UINT32_C(0x004D792A));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->eax + UINT32_C(0x00000004));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + UINT32_C(0x00000035)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ_GOTO(label_000D7925);
    LIFT_BLOCK(label_000D7935, UINT32_C(0x004D7935));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_BLOCK(label_000D7937, UINT32_C(0x004D7937));
    LIFT_CMP(cpu->esi, lift_load32(((uint32_t)(cpu->edi + UINT32_C(0x00000004)))), 32u);
    LIFT_JNZ_GOTO(label_000D78F0);
    LIFT_BLOCK(label_000D793C, UINT32_C(0x004D793C));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000001C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->edi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000002C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004D77E0, UINT32_C(0x004D7957));
    LIFT_LOAD32(cpu->ecx, cpu->edi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004D7960));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000018));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FC0D0, UINT32_C(0x004FC0D0));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry));
    goto label_000D78B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC0E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC0F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC0F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC100(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC100));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC110(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC110));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC120));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC130(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC130;
    LIFT_BLOCK(label_000ED1A0, UINT32_C(0x004ED1A0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000020));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_PUSH4(cpu->ebx, cpu->esi, cpu->edi, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD4), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED1E5, UINT32_C(0x004ED1DD));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    goto label_000ED1EE;
    LIFT_BLOCK(label_000ED1E5, UINT32_C(0x004ED1E5));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    LIFT_BLOCK(label_000ED1EE, UINT32_C(0x004ED1EE));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED1F9, UINT32_C(0x004ED1F5));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_BLOCK(label_000ED1F9, UINT32_C(0x004ED1F9));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED200));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED2DF, UINT32_C(0x004ED20A));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"***** Quit  ")));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED21E));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED238, UINT32_C(0x004ED224));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"***** Quit  ")));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED238)));
    LIFT_BLOCK(label_000ED238, UINT32_C(0x004ED238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004ED23C), UINT32_C(0x004ED242));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_localtime64, UINT32_C(0x004ED246), UINT32_C(0x004ED24C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"%d/%m/%y"));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strftime, UINT32_C(0x004ED258), UINT32_C(0x004ED25E));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->ecx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED26E));
    LIFT_PUSH3(((uint32_t)(uintptr_t)" "), cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED27C));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED296, UINT32_C(0x004ED282));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)" ")));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED296)));
    LIFT_BLOCK(label_000ED296, UINT32_C(0x004ED296));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strtime, UINT32_C(0x004ED29A), UINT32_C(0x004ED2A0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->edx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2B0));
    LIFT_PUSH3(((uint32_t)(uintptr_t)" *****\n"), cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2BE));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED2D8, UINT32_C(0x004ED2C4));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)" *****\n")));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED2D8)));
    LIFT_BLOCK(label_000ED2D8, UINT32_C(0x004ED2D8));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECF60, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED2DF)));
    LIFT_BLOCK(label_000ED2DF, UINT32_C(0x004ED2DF));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED30D, UINT32_C(0x004ED2E5));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED2ED));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE_GOTO(label_000ED30D);
    LIFT_BLOCK(label_000ED2F1, UINT32_C(0x004ED2F1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4D0, UINT32_C(0x004ED2F9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECE80, UINT32_C(0x004ED301));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED309));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JG_GOTO(label_000ED2F1);
    LIFT_BLOCK(label_000ED30D, UINT32_C(0x004ED30D));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECBB0, UINT32_C(0x004ED314));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    cpu->edi = (uint32_t)(SFERA_IMPORT_MSVCR100_free);
    lift_push32(cpu, (uint32_t)(cpu->edx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED320)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED31E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED320));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED326)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED324)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED326));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000002C));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED336, UINT32_C(0x004ED330));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED333)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED331)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED333));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED336, UINT32_C(0x004ED336));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED343, UINT32_C(0x004ED33D));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED340)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED33E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED340));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED343, UINT32_C(0x004ED343));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000018));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED350, UINT32_C(0x004ED34A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED34D)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED34B)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED34D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED350, UINT32_C(0x004ED350));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFF));
    LIFT_CALL_ENTER(sfera_sub_004EE470, UINT32_C(0x004ED35F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED377));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000FC130, UINT32_C(0x004FC130));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_log_memory_object));
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC140(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC140;
    LIFT_BLOCK(label_000ED1A0, UINT32_C(0x004ED1A0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000020));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_PUSH4(cpu->ebx, cpu->esi, cpu->edi, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD4), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED1E5, UINT32_C(0x004ED1DD));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    goto label_000ED1EE;
    LIFT_BLOCK(label_000ED1E5, UINT32_C(0x004ED1E5));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    LIFT_BLOCK(label_000ED1EE, UINT32_C(0x004ED1EE));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED1F9, UINT32_C(0x004ED1F5));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_BLOCK(label_000ED1F9, UINT32_C(0x004ED1F9));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED200));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED2DF, UINT32_C(0x004ED20A));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"***** Quit  ")));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED21E));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED238, UINT32_C(0x004ED224));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"***** Quit  ")));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED238)));
    LIFT_BLOCK(label_000ED238, UINT32_C(0x004ED238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004ED23C), UINT32_C(0x004ED242));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_localtime64, UINT32_C(0x004ED246), UINT32_C(0x004ED24C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"%d/%m/%y"));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strftime, UINT32_C(0x004ED258), UINT32_C(0x004ED25E));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->ecx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED26E));
    LIFT_PUSH3(((uint32_t)(uintptr_t)" "), cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED27C));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED296, UINT32_C(0x004ED282));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)" ")));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED296)));
    LIFT_BLOCK(label_000ED296, UINT32_C(0x004ED296));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strtime, UINT32_C(0x004ED29A), UINT32_C(0x004ED2A0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->edx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2B0));
    LIFT_PUSH3(((uint32_t)(uintptr_t)" *****\n"), cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2BE));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED2D8, UINT32_C(0x004ED2C4));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)" *****\n")));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED2D8)));
    LIFT_BLOCK(label_000ED2D8, UINT32_C(0x004ED2D8));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECF60, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED2DF)));
    LIFT_BLOCK(label_000ED2DF, UINT32_C(0x004ED2DF));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED30D, UINT32_C(0x004ED2E5));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED2ED));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE_GOTO(label_000ED30D);
    LIFT_BLOCK(label_000ED2F1, UINT32_C(0x004ED2F1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4D0, UINT32_C(0x004ED2F9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECE80, UINT32_C(0x004ED301));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED309));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JG_GOTO(label_000ED2F1);
    LIFT_BLOCK(label_000ED30D, UINT32_C(0x004ED30D));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECBB0, UINT32_C(0x004ED314));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    cpu->edi = (uint32_t)(SFERA_IMPORT_MSVCR100_free);
    lift_push32(cpu, (uint32_t)(cpu->edx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED320)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED31E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED320));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED326)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED324)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED326));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000002C));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED336, UINT32_C(0x004ED330));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED333)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED331)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED333));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED336, UINT32_C(0x004ED336));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED343, UINT32_C(0x004ED33D));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED340)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED33E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED340));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED343, UINT32_C(0x004ED343));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000018));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED350, UINT32_C(0x004ED34A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED34D)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED34B)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED34D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED350, UINT32_C(0x004ED350));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFF));
    LIFT_CALL_ENTER(sfera_sub_004EE470, UINT32_C(0x004ED35F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED377));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000FC140, UINT32_C(0x004FC140));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_log_warnings_object));
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC150(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC150;
    LIFT_BLOCK(label_000ED1A0, UINT32_C(0x004ED1A0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000020));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_PUSH4(cpu->ebx, cpu->esi, cpu->edi, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD4), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED1E5, UINT32_C(0x004ED1DD));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    goto label_000ED1EE;
    LIFT_BLOCK(label_000ED1E5, UINT32_C(0x004ED1E5));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    g_sfera_critical_diagnostics_runtime.log_chain_head = (uint32_t)(cpu->edx);
    LIFT_BLOCK(label_000ED1EE, UINT32_C(0x004ED1EE));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED1F9, UINT32_C(0x004ED1F5));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_BLOCK(label_000ED1F9, UINT32_C(0x004ED1F9));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED200));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED2DF, UINT32_C(0x004ED20A));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"***** Quit  ")));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED21E));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED238, UINT32_C(0x004ED224));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"***** Quit  ")));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED238)));
    LIFT_BLOCK(label_000ED238, UINT32_C(0x004ED238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004ED23C), UINT32_C(0x004ED242));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_localtime64, UINT32_C(0x004ED246), UINT32_C(0x004ED24C));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"%d/%m/%y"));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strftime, UINT32_C(0x004ED258), UINT32_C(0x004ED25E));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->ecx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED26E));
    LIFT_PUSH3(((uint32_t)(uintptr_t)" "), cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED27C));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED296, UINT32_C(0x004ED282));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)" ")));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED296)));
    LIFT_BLOCK(label_000ED296, UINT32_C(0x004ED296));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strtime, UINT32_C(0x004ED29A), UINT32_C(0x004ED2A0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->edx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2B0));
    LIFT_PUSH3(((uint32_t)(uintptr_t)" *****\n"), cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2BE));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED2D8, UINT32_C(0x004ED2C4));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)" *****\n")));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED2D8)));
    LIFT_BLOCK(label_000ED2D8, UINT32_C(0x004ED2D8));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECF60, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED2DF)));
    LIFT_BLOCK(label_000ED2DF, UINT32_C(0x004ED2DF));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED30D, UINT32_C(0x004ED2E5));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED2ED));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE_GOTO(label_000ED30D);
    LIFT_BLOCK(label_000ED2F1, UINT32_C(0x004ED2F1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4D0, UINT32_C(0x004ED2F9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECE80, UINT32_C(0x004ED301));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED309));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JG_GOTO(label_000ED2F1);
    LIFT_BLOCK(label_000ED30D, UINT32_C(0x004ED30D));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECBB0, UINT32_C(0x004ED314));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    cpu->edi = (uint32_t)(SFERA_IMPORT_MSVCR100_free);
    lift_push32(cpu, (uint32_t)(cpu->edx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED320)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED31E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED320));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED326)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED324)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED326));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000002C));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED336, UINT32_C(0x004ED330));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED333)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED331)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED333));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED336, UINT32_C(0x004ED336));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED343, UINT32_C(0x004ED33D));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED340)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED33E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED340));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED343, UINT32_C(0x004ED343));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000018));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED350, UINT32_C(0x004ED34A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED34D)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED34B)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED34D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ED350, UINT32_C(0x004ED350));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFF));
    LIFT_CALL_ENTER(sfera_sub_004EE470, UINT32_C(0x004ED35F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED377));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000FC150, UINT32_C(0x004FC150));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_log_errors_object));
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC15A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC15A;
    LIFT_BLOCK(label_000EF606, UINT32_C(0x004EF606));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000004)));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EF781, UINT32_C(0x004EF612));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_Lockit_ctor, UINT32_C(0x004EF617), UINT32_C(0x004EF61D));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    goto label_000EF63A;
    LIFT_BLOCK(label_000EF623, UINT32_C(0x004EF623));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi);
    g_sfera_crt_startup_runtime.dynamic_tls_dtor_callbacks = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EF5C6, UINT32_C(0x004EF633));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004EF639));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EF63A, UINT32_C(0x004EF63A));
    cpu->eax = (uint32_t)(g_sfera_crt_startup_runtime.dynamic_tls_dtor_callbacks);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EF623, UINT32_C(0x004EF643));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0xFFFFFFFF), |, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_Lockit_dtor, UINT32_C(0x004EF64A), UINT32_C(0x004EF650));
    LIFT_CALL_ENTER(sfera_sub_004EF7B4, UINT32_C(0x004EF655));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FC15A, UINT32_C(0x004FC15A));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_crt_startup_runtime.tls_cleanup_object));
    goto label_000EF606;
}
