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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4429(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4429;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4429, UINT32_C(0x004F4429));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F443A));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CA08_ADDR);
    goto label_000EE936;
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4558(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4558;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4558, UINT32_C(0x004F4558));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4569));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CA64_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4580));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFECC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F458C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F458E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F458E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F458E, UINT32_C(0x004F458E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFEBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFEB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F45A5));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F45B2));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CB50_ADDR);
    goto label_000EE936;
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F45DC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F45DC;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F45DC, UINT32_C(0x004F45DC));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFEAC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFEA8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F45F3));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4600));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CB84_ADDR);
    goto label_000EE936;
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
    LIFT_IMPORT_INDEX_RETURN(399u, UINT32_C(0x004F4650));
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
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4A518_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04F4A518_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4680(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4680;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4680, UINT32_C(0x004F4680));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4691));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CBA8_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46A0;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F46A0, UINT32_C(0x004F46A0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A508_ADDR);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46AA(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46AA;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F46AA, UINT32_C(0x004F46AA));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F46BB));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CC1C_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F46D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F46D0;
    LIFT_BLOCK(label_000D67A0, UINT32_C(0x004D67A0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_IMPORT_INDEX(111u, UINT32_C(0x004D67A7), UINT32_C(0x004D67AD));
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
    LIFT_IMPORT_INDEX(163u, UINT32_C(0x004D67B3), UINT32_C(0x004D67B9));
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
    LIFT_IMPORT_INDEX(165u, UINT32_C(0x004D67C3), UINT32_C(0x004D67C9));
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
    LIFT_IMPORT_INDEX(162u, UINT32_C(0x004D67D7), UINT32_C(0x004D67DD));
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
    LIFT_IMPORT_INDEX(165u, UINT32_C(0x004D67C3), UINT32_C(0x004D67C9));
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
    LIFT_IMPORT_INDEX(162u, UINT32_C(0x004D67D7), UINT32_C(0x004D67DD));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F4707, UINT32_C(0x004F4707));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBE4))));
    goto label_000D67D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4712(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4712;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4712, UINT32_C(0x004F4712));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFB9C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFB98));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4729));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4736));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CC7C_ADDR);
    goto label_000EE936;
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4751(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4751;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4751, UINT32_C(0x004F4751));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4762));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CD0C_ADDR);
    goto label_000EE936;
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4780(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4780;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4780, UINT32_C(0x004F4780));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF8C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF88));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4791));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F479E));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CD40_ADDR);
    goto label_000EE936;
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47B8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F47B8, UINT32_C(0x004F47B8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F47C9));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CD6C_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47E0;
    LIFT_BLOCK(label_000D7B40, UINT32_C(0x004D7B40));
    LIFT_STORE32(cpu->ecx, SFERA_STATIC_0050A2FC_ADDR);
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F47E0, UINT32_C(0x004F47E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_000D7B40;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F47E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F47E8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F47E8, UINT32_C(0x004F47E8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F47F9));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CD98_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4810));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4C8C0_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04F4C8C0_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F481E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F481E));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4C8C0_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04F4C8C0_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F482C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F482C;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F482C, UINT32_C(0x004F482C));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F483D));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CDCC_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4850;
    LIFT_BLOCK(label_000DA550, UINT32_C(0x004DA550));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_PUSH2(cpu->eax, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi, SFERA_STATIC_0050A580_ADDR);
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F485E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F485E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F485E, UINT32_C(0x004F485E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F486F));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CDF8_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4880(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4880));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F488B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F488B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F488B, UINT32_C(0x004F488B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF18))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF14));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F48A2));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F48AF));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CE24_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F48C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F48C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF28))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F48CB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F48CB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F48CB, UINT32_C(0x004F48CB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF18))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF14));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F48E2));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F48EF));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CE50_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4900));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF28))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F490B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F490B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F490B, UINT32_C(0x004F490B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF24))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF20));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4922));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F492F));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CE7C_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4940));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F494B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F494B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F494B, UINT32_C(0x004F494B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF1C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF18));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4962));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F496F));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CEA8_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4980(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4980));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F498C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F498E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F498E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F498E, UINT32_C(0x004F498E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFBE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFBE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F49A5));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F49B2));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CED4_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49C0;
    LIFT_BLOCK(label_000EA960, UINT32_C(0x004EA960));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EA98F, UINT32_C(0x004EA966));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA97E, UINT32_C(0x004EA96B));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    SFERA_STATIC_04F90415_U8 = (uint8_t)(UINT32_C(0x00000000));
    LIFT_IMPORT_INDEX(46u, UINT32_C(0x004EA977), UINT32_C(0x004EA97D));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EA97E, UINT32_C(0x004EA97E));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000004)))), UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA98F, UINT32_C(0x004EA984));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    lift_import_call(cpu, 46u, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA989)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA98F));
    LIFT_BLOCK(label_000EA98F, UINT32_C(0x004EA98F));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F49C0, UINT32_C(0x004F49C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49C8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49C8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F49C8, UINT32_C(0x004F49C8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F49D9));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CF00_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49F0;
    LIFT_BLOCK(label_000EA960, UINT32_C(0x004EA960));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EA98F, UINT32_C(0x004EA966));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA97E, UINT32_C(0x004EA96B));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    SFERA_STATIC_04F90415_U8 = (uint8_t)(UINT32_C(0x00000000));
    LIFT_IMPORT_INDEX(46u, UINT32_C(0x004EA977), UINT32_C(0x004EA97D));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EA97E, UINT32_C(0x004EA97E));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000004)))), UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA98F, UINT32_C(0x004EA984));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    lift_import_call(cpu, 46u, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA989)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA98F));
    LIFT_BLOCK(label_000EA98F, UINT32_C(0x004EA98F));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F49F0, UINT32_C(0x004F49F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F49F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F49F8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F49F8, UINT32_C(0x004F49F8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4A09));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CF2C_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4A20;
    LIFT_BLOCK(label_000EA960, UINT32_C(0x004EA960));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EA98F, UINT32_C(0x004EA966));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA97E, UINT32_C(0x004EA96B));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    SFERA_STATIC_04F90415_U8 = (uint8_t)(UINT32_C(0x00000000));
    LIFT_IMPORT_INDEX(46u, UINT32_C(0x004EA977), UINT32_C(0x004EA97D));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EA97E, UINT32_C(0x004EA97E));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000004)))), UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EA98F, UINT32_C(0x004EA984));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    lift_import_call(cpu, 46u, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA989)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EA98F));
    LIFT_BLOCK(label_000EA98F, UINT32_C(0x004EA98F));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F4A20, UINT32_C(0x004F4A20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    goto label_000EA960;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A28(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4A28;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4A28, UINT32_C(0x004F4A28));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4A39));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CF58_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4A50));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000038), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004EE470);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A5B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4A5B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4A5B, UINT32_C(0x004F4A5B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4A6C));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CF84_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4A80));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000038), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004EE470);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4A8B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4A8B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4A8B, UINT32_C(0x004F4A8B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4A9C));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4AA6));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051CFB0_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4AB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4AB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_IMPORT_INDEX_RETURN(391u, UINT32_C(0x004F4AB3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4AB9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4AB9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_INDEX_RETURN(326u, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4AB9, UINT32_C(0x004F4AB9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4ACA));
    cpu->eax = (uint32_t)(SFERA_RDATA_RTTI_0051D09C_ADDR);
    goto label_000EE936;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4AE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4AE0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_005255F0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_005255E0_ADDR);
    SFERA_STATIC_005255E0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4AF7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000840))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4B01));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4B10));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525650_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4B49));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4B50));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_005256C0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_005256B0_ADDR);
    SFERA_STATIC_005256B0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4B67));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000841))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4B71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4B80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4B80));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525720_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4BB9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4BC0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525790_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525780_ADDR);
    SFERA_STATIC_00525780_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4BD7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000842))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4BE1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4BF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4BF0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_005257F0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4C29));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4C30));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525860_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525850_ADDR);
    SFERA_STATIC_00525850_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4C47));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000843))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4C51));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4C60));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_005258C0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4C99));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4CA0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525938_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525928_ADDR);
    SFERA_STATIC_00525928_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4CB7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000844))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4CC1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4CD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4CD0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525998_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4D09));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4D10));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525A08_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_005259F8_ADDR);
    SFERA_STATIC_005259F8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4D27));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000845))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4D31));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4D40));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525A68_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4D79));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4D80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4D80));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525AF0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525AE0_ADDR);
    SFERA_STATIC_00525AE0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4D97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000846))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4DA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4DB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525B50_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4DE9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4DF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4DF0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525BC8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525BB8_ADDR);
    SFERA_STATIC_00525BB8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4E07));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000847))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4E11));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4E20));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525C28_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4E59));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4E60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4E60));
    LIFT_PUSH2(SFERA_RSTR_004FED24_ADDR, SFERA_DATA_CALL_ARGUMENT_00525C96_ADDR);
    LIFT_IMPORT_INDEX(317u, UINT32_C(0x004F4E6A), UINT32_C(0x004F4E70));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000004)));
    LIFT_IMPORT_INDEX(182u, UINT32_C(0x004F4E75), UINT32_C(0x004F4E7B));
    LIFT_PUSH2(UINT32_C(0x00000001), UINT32_C(0x00000000));
    LIFT_IMPORT_INDEX(56u, UINT32_C(0x004F4E7F), UINT32_C(0x004F4E85));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_INDEX(183u, UINT32_C(0x004F4E86), UINT32_C(0x004F4E8C));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000848))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4E96));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4EA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4EA0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525D00_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525CF0_ADDR);
    SFERA_STATIC_00525CF0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4EB7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000849))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4EC1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4ED0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4ED0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525D60_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4F09));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4F10));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525DD8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525DC8_ADDR);
    SFERA_STATIC_00525DC8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4F27));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000084A))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4F31));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4F40));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525E38_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4F79));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4F80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4F80));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525EF0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525EE0_ADDR);
    SFERA_STATIC_00525EE0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F4F97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000084B))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F4FA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4FB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4FB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00525F78_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F4FE9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
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
    SFERA_STATIC_00525FDC_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525FDC_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525FDC_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000008), cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525FDC_U32);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->ecx + UINT32_C(0x00000014), (cpu->eax & UINT32_C(0xFF)));
    cpu->edx = (uint32_t)(SFERA_STATIC_00525FDC_U32);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000084E))));
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
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F504D), UINT32_C(0x004F5053));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_STATIC_004FDEB4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F506A));
    LIFT_TRAP_RETURN(UINT32_C(0x004F506A), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5070));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0017CDC0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5081));
    LIFT_PUSH3(UINT32_C(0x0017CDC0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_00525F4C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5093));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_004FF078_ADDR);
    SFERA_STATIC_00525F50_U32 = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F50AC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_00525F54_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F50B2), UINT32_C(0x004F50B8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000084C))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00525F63)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00525F74)), UINT32_C(0x0000007D));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F50D3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F50E0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000084D))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F50EA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F50F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F50F0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00526008_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525FF8_ADDR);
    SFERA_STATIC_00525FF8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F5107));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000084F))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5111));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5120));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00526068_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5159));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5160));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_005260D8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_005260C8_ADDR);
    SFERA_STATIC_005260C8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F5177));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000850))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5181));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5190(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5190));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00526138_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F51C9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F51D0));
    LIFT_PUSH2(UINT32_C(0x00000000), UINT32_C(0x00000000));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00526198_ADDR);
    LIFT_CALL_ENTER(sfera_sub_0042E540, UINT32_C(0x004F51DE));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000851))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F51E8));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F51F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F51F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000050));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5201));
    LIFT_PUSH3(UINT32_C(0x00000050), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_0052627C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5210));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    cpu->eax = (uint32_t)(UINT32_C(0x0000000A));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_004FFAC4_ADDR);
    SFERA_STATIC_00526280_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00526284)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00526288)), cpu->eax);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0052628C)), UINT32_C(0x00000008));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5242));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_00526290_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5248), UINT32_C(0x004F524E));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000852))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0052629F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005262B0)), UINT32_C(0x00000019));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5269));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5270));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5281));
    SFERA_STATIC_00526244_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00526244_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    cpu->eax = (uint32_t)(UINT32_C(0x0000000A));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_004FFAC4_ADDR);
    SFERA_STATIC_00526248_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0052624C)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00526250)), cpu->eax);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00526254)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5305));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_00526258_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F530B), UINT32_C(0x004F5311));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000853))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00526267)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00526278)), UINT32_C(0x0000001B));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F532C));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5330(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5330));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_005262C8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_005262B8_ADDR);
    SFERA_STATIC_005262B8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F5347));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000854))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5351));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5360(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5360));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00526328_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5399));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F53A0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_00526398_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_00526388_ADDR);
    SFERA_STATIC_00526388_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F53B7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000855))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F53C1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F53D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F53D0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_005263F8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5409));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5410(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5410));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00520704_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5421));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000856))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F542B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5430(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5430));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00520720_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5441));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000857))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F544B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5450(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5450));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_006BE1F8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_006BE1E8_ADDR);
    SFERA_STATIC_006BE1E8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F5467));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000858))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5471));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5480(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5480));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_006BE258_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F54B9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F54C0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04DBC4A0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DBC490_ADDR);
    SFERA_STATIC_04DBC490_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F54D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000859))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F54E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F54F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F54F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04DC0520_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5529));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5530(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5530));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521058_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5541));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000085B))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F554B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5550));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521074_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5561));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000085C))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F556B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DBC508_ADDR);
    goto label_00021FC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5580;
    LIFT_BLOCK(label_000016E0, UINT32_C(0x004016E0));
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_004FDE7A_ADDR);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DC0580_ADDR);
    goto label_000016E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5590(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5590));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (SFERA_STATIC_00500420_F64));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_RDIV_POP(1u);
    LIFT_X87_STORE_F32_POP(SFERA_STATIC_04DC051C_ADDR);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F55B0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04DD0A30_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DD0A20_ADDR);
    SFERA_STATIC_04DD0A20_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F55C7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000085D))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F55D1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F55E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F55E0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04DD0A98_ADDR);
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
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000001F8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5631));
    LIFT_PUSH3(UINT32_C(0x000001F8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04DD0B50_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5643));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502794_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B54)), UINT32_C(0x0000007E));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F565C));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04DD0B58_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5662), UINT32_C(0x004F5668));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000085E))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B67)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B78)), UINT32_C(0x000003A6));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5683));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5690(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5690));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000001F8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F56A1));
    LIFT_PUSH3(UINT32_C(0x000001F8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04DD0B24_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F56B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502794_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B28)), UINT32_C(0x0000007E));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F56CC));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04DD0B2C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F56D2), UINT32_C(0x004F56D8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000085F))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B3B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B4C)), UINT32_C(0x000003A7));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F56F3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5700));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000001F8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5711));
    LIFT_PUSH3(UINT32_C(0x000001F8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04DD0AF8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5723));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502794_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0AFC)), UINT32_C(0x0000007E));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F573C));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04DD0B00_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5742), UINT32_C(0x004F5748));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000860))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B0F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04DD0B20)), UINT32_C(0x000003A8));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5763));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5770));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04DD0B90_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DD0B80_ADDR);
    SFERA_STATIC_04DD0B80_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F5787));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000861))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5791));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F57A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04DD0BF0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F57D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F57E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F57E0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04ED0DB8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED0DA8_ADDR);
    SFERA_STATIC_04ED0DA8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F57F7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000862))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5801));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5810));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04ED0F88_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F5849));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5850(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5850));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521584_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5861));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A2))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F586B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5870));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005215A0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F5881));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A3))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F588B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5890));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F58A1));
    LIFT_PUSH3(UINT32_C(0x000007D0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCD98_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F58B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCD9C)), UINT32_C(0x000001F4));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDA0)), UINT32_C(0x00001388));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDA4)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDA8)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F58EA));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04EDCDAC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F58F0), UINT32_C(0x004F58F6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000864))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDBB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDCC)), UINT32_C(0x000000E6));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5911));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5920(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5920));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00004650));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5931));
    LIFT_PUSH3(UINT32_C(0x00004650), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED0D70_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5943));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0D74)), UINT32_C(0x000001F4));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0D78)), UINT32_C(0x00001388));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0D7C)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0D80)), UINT32_C(0x00000024));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F597A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED0D84_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5980), UINT32_C(0x004F5986));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000865))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0D93)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0DA4)), UINT32_C(0x000000E7));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F59A1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F59B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F59B0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F59C1));
    LIFT_PUSH3(UINT32_C(0x000007D0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2BA8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F59D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BAC)), UINT32_C(0x000001F4));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BB0)), UINT32_C(0x00001388));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BB4)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BB8)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5A0A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED2BBC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5A10), UINT32_C(0x004F5A16));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000866))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BCB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2BDC)), UINT32_C(0x000000E8));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5A31));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5A40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5A40));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000320));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5A51));
    LIFT_PUSH3(UINT32_C(0x00000320), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED1220_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5A63));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1224)), UINT32_C(0x000000C8));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1228)), UINT32_C(0x000001F4));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED122C)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1230)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5A9A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED1234_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5AA0), UINT32_C(0x004F5AA6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000867))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1243)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1254)), UINT32_C(0x000000E9));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5AC1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5AD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5AD0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000109A0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5AE1));
    LIFT_PUSH3(UINT32_C(0x000109A0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED3038_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5AF3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED303C)), UINT32_C(0x000001F4));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3040)), UINT32_C(0x000003E8));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3044)), UINT32_C(0x00000032));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3048)), UINT32_C(0x00000088));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5B2A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED304C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5B30), UINT32_C(0x004F5B36));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000868))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED305B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED306C)), UINT32_C(0x000000EB));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5B51));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5B60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5B60));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5B71));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED1A68_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5B83));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A6C)), UINT32_C(0x00000032));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A70)), UINT32_C(0x000000C8));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A74)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A78)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5BBA));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED1A7C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5BC0), UINT32_C(0x004F5BC6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000869))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A8B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A9C)), UINT32_C(0x000000ED));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5BE1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5BF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5BF0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5C01));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED12F0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5C13));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED12F4_U32 = (uint32_t)(UINT32_C(0x00000032));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED12F8)), UINT32_C(0x00002710));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED12FC)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1300)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5C4A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED1304_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5C50), UINT32_C(0x004F5C56));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000086A))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1313)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1324)), UINT32_C(0x000000EF));
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
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FEC48_ADDR);
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
    LIFT_X87_LOAD_F32(SFERA_RCONST_0050292C_ADDR);
    LIFT_X87_STORE_F32_POP(cpu->esi + UINT32_C(0x00000070));
    LIFT_X87_LOAD_F32(SFERA_STATIC_00502928_ADDR);
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
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (SFERA_STATIC_004FE7F8_F64));
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED3138_ADDR);
    goto label_0004B620;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5C90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5C90));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5CA1));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED1A30_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5CB3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A34)), UINT32_C(0x00000032));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A38)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A3C)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A40)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5CEA));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED1A44_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5CF0), UINT32_C(0x004F5CF6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000086B))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A53)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1A64)), UINT32_C(0x00000102));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5D11));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5D20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5D20));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00003200));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5D31));
    LIFT_PUSH3(UINT32_C(0x00003200), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED30C8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5D43));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30CC)), UINT32_C(0x000000C8));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30D0)), UINT32_C(0x000001F4));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30D4)), UINT32_C(0x00000064));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30D8)), UINT32_C(0x00000040));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5D7A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED30DC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5D80), UINT32_C(0x004F5D86));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000086C))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30EB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30FC)), UINT32_C(0x00000105));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5DA1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5DB0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EC4FB0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_0048A1A0, UINT32_C(0x004F5DBA));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000863))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5DC4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5DD0;
    LIFT_BLOCK(label_0009B950, UINT32_C(0x0049B950));
    LIFT_SP_SUB(UINT32_C(0x00000014));
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->eax);
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_0049B860, UINT32_C(0x0049B967));
    LIFT_PUSH3(UINT32_C(0x00005320), UINT32_C(0x00000000), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x0049B974));
    cpu->eax = (uint32_t)(SFERA_STATIC_004FFA40_U32);
    cpu->ecx = (uint32_t)(SFERA_STATIC_004FFA44_U32);
    cpu->edx = (uint32_t)(SFERA_STATIC_004FFA48_U32);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), cpu->eax);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFF0000)) | ((uint32_t)(SFERA_STATIC_004FFA4C_U16) & UINT32_C(0xFFFF));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->ecx);
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(SFERA_STATIC_004FFA4E_U8) & UINT32_C(0xFF));
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ECBA50_ADDR);
    goto label_0009B950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5DE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5DE0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00009C40));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5DF1));
    LIFT_PUSH3(UINT32_C(0x00009C40), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED1190_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5E03));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED1194_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5E1C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED1198_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5E22), UINT32_C(0x004F5E28));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000086D))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11A7)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11B8)), UINT32_C(0x0000016C));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5E43));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5E50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5E50));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0007F710));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5E61));
    LIFT_PUSH3(UINT32_C(0x0007F710), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED29F8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5E73));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED29FC_U32 = (uint32_t)(UINT32_C(0x0000012C));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5E8C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2A00_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5E92), UINT32_C(0x004F5E98));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000086E))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A0F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A20)), UINT32_C(0x00000171));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5EB3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5EC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5EC0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00006D60));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5ED1));
    LIFT_PUSH3(UINT32_C(0x00006D60), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2F74_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5EE3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2F78_U32 = (uint32_t)(UINT32_C(0x00001B58));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5EFC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2F7C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5F02), UINT32_C(0x004F5F08));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000086F))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F8B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F9C)), UINT32_C(0x00000193));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5F23));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5F30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5F30));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x001E8480));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5F41));
    LIFT_PUSH3(UINT32_C(0x001E8480), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2F48_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5F53));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2F4C_U32 = (uint32_t)(UINT32_C(0x0007A120));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5F6C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2F50_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5F72), UINT32_C(0x004F5F78));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000870))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F5F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F70)), UINT32_C(0x000001A2));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F5F93));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F5FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F5FA0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0001D4C0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F5FB1));
    LIFT_PUSH3(UINT32_C(0x0001D4C0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2AD4_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F5FC3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2AD8_U32 = (uint32_t)(UINT32_C(0x00007530));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F5FDC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2ADC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F5FE2), UINT32_C(0x004F5FE8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000871))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AEB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AFC)), UINT32_C(0x000001A5));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6003));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000190));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6021));
    LIFT_PUSH3(UINT32_C(0x00000190), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2A24_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6033));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2A28_U32 = (uint32_t)(UINT32_C(0x00000064));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F604C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2A2C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6052), UINT32_C(0x004F6058));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000872))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A3B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A4C)), UINT32_C(0x000001A9));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6073));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6080));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6091));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED29A0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F60A3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED29A4_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F60BC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED29A8_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F60C2), UINT32_C(0x004F60C8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000873))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29B7)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29C8)), UINT32_C(0x000001BF));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F60E3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F60F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F60F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6101));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED309C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6113));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED30A0_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F612C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED30A4_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6132), UINT32_C(0x004F6138));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000874))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30B3)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED30C4)), UINT32_C(0x000001C0));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6153));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6160));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6171));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2F1C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6183));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2F20_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F619C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2F24_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F61A2), UINT32_C(0x004F61A8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000875))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F33)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F44)), UINT32_C(0x000001C3));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F61C3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F61D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F61D0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F61E1));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCE28_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F61F3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04EDCE2C_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F620C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04EDCE30_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6212), UINT32_C(0x004F6218));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000876))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE3F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE50)), UINT32_C(0x000001C4));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6233));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6240));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6251));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED3070_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6263));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED3074_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F627C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED3078_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6282), UINT32_C(0x004F6288));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000877))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3087)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3098)), UINT32_C(0x000001C5));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F62A3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F62B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F62B0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F62C1));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2C44_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F62D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2C48_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F62EC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2C4C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F62F2), UINT32_C(0x004F62F8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000878))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C5B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C6C)), UINT32_C(0x000001C6));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6313));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6320));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00054F60));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6331));
    LIFT_PUSH3(UINT32_C(0x00054F60), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED0F30_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6343));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED0F34_U32 = (uint32_t)(UINT32_C(0x00000BB8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F635C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED0F38_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6362), UINT32_C(0x004F6368));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000879))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F47)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F58)), UINT32_C(0x000001E3));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6383));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6390));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000000F0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F63A1));
    LIFT_PUSH3(UINT32_C(0x000000F0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2EC4_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F63B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2EC8_U32 = (uint32_t)(UINT32_C(0x0000000A));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F63CC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2ECC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F63D2), UINT32_C(0x004F63D8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000087A))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EDB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EEC)), UINT32_C(0x00000236));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F63F3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6400));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00002A30));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6411));
    LIFT_PUSH3(UINT32_C(0x00002A30), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2AA8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6423));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2AAC_U32 = (uint32_t)(UINT32_C(0x00000384));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F643C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2AB0_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6442), UINT32_C(0x004F6448));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000087B))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2ABF)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AD0)), UINT32_C(0x0000033C));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6463));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6470));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000024));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6481));
    SFERA_STATIC_04EC4F84_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F88)), UINT32_C(0x00000009));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F64E4));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04EC4F8C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F64EA), UINT32_C(0x004F64F0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000087C))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4F9B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FAC)), UINT32_C(0x00000633));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F650B));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6510));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000400));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6521));
    LIFT_PUSH3(UINT32_C(0x00000400), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EC4FBC_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6533));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FC0)), UINT32_C(0x00000100));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F654C));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04EC4FC4_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6552), UINT32_C(0x004F6558));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000087D))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FD3)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EC4FE4)), UINT32_C(0x000006B0));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6573));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6580));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6591));
    SFERA_STATIC_04ED1158_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED115C)), UINT32_C(0x0000000A));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1160)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1164)), UINT32_C(0x00000005));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1168)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F661A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED116C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6620), UINT32_C(0x004F6626));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000087E))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED117B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED118C)), UINT32_C(0x000006B1));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6641));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6650(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6650));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6661));
    SFERA_STATIC_04ED1120_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1124)), UINT32_C(0x0000000A));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1128)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED112C)), UINT32_C(0x00000005));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1130)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F66EA));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED1134_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F66F0), UINT32_C(0x004F66F6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000087F))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1143)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1154)), UINT32_C(0x000006B2));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6711));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6720(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6720));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6731));
    SFERA_STATIC_04ED11E8_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11EC)), UINT32_C(0x0000000A));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11F0)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11F4)), UINT32_C(0x00000005));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11F8)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F67BA));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED11FC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F67C0), UINT32_C(0x004F67C6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000880))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED120B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED121C)), UINT32_C(0x000006B3));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F67E1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F67F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F67F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6801));
    SFERA_STATIC_04EDD030_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000008), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000000C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000014), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000018), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x0000001C), cpu->ecx);
    cpu->edx = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000020), cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000024), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD034)), UINT32_C(0x0000000A));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD038)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD03C)), UINT32_C(0x00000005));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD040)), UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F688A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04EDD044_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6890), UINT32_C(0x004F6896));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000881))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD053)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDD064)), UINT32_C(0x000006B4));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F68B1));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F68C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F68C0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000001E0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F68D1));
    LIFT_PUSH3(UINT32_C(0x000001E0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2D28_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F68E3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D2C)), UINT32_C(0x0000000A));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D30)), UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D34)), UINT32_C(0x00000005));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D38)), UINT32_C(0x00000030));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F691A));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED2D3C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6920), UINT32_C(0x004F6926));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000882))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D4B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2D5C)), UINT32_C(0x000006B5));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6941));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6950));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000240));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6961));
    LIFT_PUSH3(UINT32_C(0x00000240), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2E34_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6973));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2E38_U32 = (uint32_t)(UINT32_C(0x00000090));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F698C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2E3C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6992), UINT32_C(0x004F6998));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000883))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E4B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E5C)), UINT32_C(0x00001247));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F69B3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F69C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F69C0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00003600));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F69D1));
    LIFT_PUSH3(UINT32_C(0x00003600), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2A7C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F69E3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2A80_U32 = (uint32_t)(UINT32_C(0x00000090));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F69FC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2A84_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6A02), UINT32_C(0x004F6A08));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000884))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A93)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2AA4)), UINT32_C(0x00001248));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6A23));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6A30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6A30));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00009C40));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6A41));
    LIFT_PUSH3(UINT32_C(0x00009C40), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCF78_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6A53));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04EDCF7C_U32 = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6A6C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04EDCF80_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6A72), UINT32_C(0x004F6A78));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000885))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF8F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCFA0)), UINT32_C(0x0000124A));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6A93));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6AA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6AA0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00001F40));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6AB1));
    LIFT_PUSH3(UINT32_C(0x00001F40), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED11BC_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6AC3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED11C0_U32 = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6ADC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED11C4_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6AE2), UINT32_C(0x004F6AE8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000886))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11D3)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED11E4)), UINT32_C(0x0000124B));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6B03));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6B10));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000B7980));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6B21));
    LIFT_PUSH3(UINT32_C(0x000B7980), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2DB8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6B33));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DBC)), UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6B4C));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED2DC0_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6B52), UINT32_C(0x004F6B58));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000887))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DCF)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DE0)), UINT32_C(0x0000124D));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6B73));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6B80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6B80));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000066)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0000FA00));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6B91));
    LIFT_PUSH3(UINT32_C(0x0000FA00), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCF40_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6BA3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF44)), UINT32_C(0x000007D0));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF48)), UINT32_C(0x00000BB8));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF4C)), UINT32_C(0x000001F4));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF50)), UINT32_C(0x00000020));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6BDA));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04EDCF54_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6BE0), UINT32_C(0x004F6BE6));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000888))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF63)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCF74)), UINT32_C(0x0000124F));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6C01));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6C10));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000030));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6C21));
    LIFT_PUSH3(UINT32_C(0x00000030), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED1014_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6C30));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED1018_U32 = (uint32_t)(UINT32_C(0x0000000C));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6C49));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED101C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6C4F), UINT32_C(0x004F6C55));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000889))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED102B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED103C)), UINT32_C(0x0000125B));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6C70));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6C80));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00061A80));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6C91));
    LIFT_PUSH3(UINT32_C(0x00061A80), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED29CC_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6CA3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED29D0_U32 = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6CBC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED29D4_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6CC2), UINT32_C(0x004F6CC8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000088A))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29E3)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED29F4)), UINT32_C(0x00001264));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6CE3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6CF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6CF0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00013880));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6D01));
    LIFT_PUSH3(UINT32_C(0x00013880), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED0EC4_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6D13));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED0EC8_U32 = (uint32_t)(UINT32_C(0x00009C40));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6D2C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED0ECC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6D32), UINT32_C(0x004F6D38));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000088B))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EDB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0EEC)), UINT32_C(0x00001266));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6D53));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6D60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6D60));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6D71));
    LIFT_PUSH3(UINT32_C(0x00000FA0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCDFC_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6D83));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04EDCE00_U32 = (uint32_t)(UINT32_C(0x000003E8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6D9C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04EDCE04_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6DA2), UINT32_C(0x004F6DA8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000088C))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE13)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE24)), UINT32_C(0x0000127E));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6DC3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6DD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6DD0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6DE1));
    LIFT_PUSH3(UINT32_C(0x000007D0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCFA4_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6DF3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04EDCFA8_U32 = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6E0C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04EDCFAC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6E12), UINT32_C(0x004F6E18));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000088D))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCFBB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCFCC)), UINT32_C(0x00001280));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6E33));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6E40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6E40));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0000007C));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6E51));
    LIFT_PUSH3(UINT32_C(0x0000007C), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED300C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6E60));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED3010_U32 = (uint32_t)(UINT32_C(0x0000001F));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6E79));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED3014_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6E7F), UINT32_C(0x004F6E85));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000088E))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3023)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3034)), UINT32_C(0x00001282));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F6EA0));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6EB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6EB0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000003E8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6EC1));
    LIFT_PUSH3(UINT32_C(0x000003E8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCCA0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6ED3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04EDCCA4_U32 = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6EEC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04EDCCA8_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6EF2), UINT32_C(0x004F6EF8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000088F))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCB7)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCC8)), UINT32_C(0x00001392));
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
    SFERA_STATIC_04EDCD74_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDCD74_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDCD74_U32);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000008), cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCD74_U32);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->ecx + UINT32_C(0x0000002C), (cpu->eax & UINT32_C(0xFF)));
    cpu->edx = (uint32_t)(SFERA_STATIC_04EDCD74_U32);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A4))));
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
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F6F7D), UINT32_C(0x004F6F83));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_STATIC_004FDEB4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F6F9A));
    LIFT_TRAP_RETURN(UINT32_C(0x004F6F9A), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F6FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F6FA0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00023280));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F6FB1));
    LIFT_PUSH3(UINT32_C(0x00023280), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2EF0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F6FC3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EF4)), UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F6FDC));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED2EF8_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F6FE2), UINT32_C(0x004F6FE8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000890))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F07)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2F18)), UINT32_C(0x000024DE));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7003));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00021D68));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7021));
    LIFT_PUSH3(UINT32_C(0x00021D68), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2A50_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7033));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A54)), UINT32_C(0x000026AC));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F704C));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04ED2A58_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7052), UINT32_C(0x004F7058));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000891))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A67)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2A78)), UINT32_C(0x000024E0));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7073));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7080));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00007D00));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7091));
    LIFT_PUSH3(UINT32_C(0x00007D00), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCCCC_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F70A3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCD0)), UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F70BC));
    LIFT_PUSH2(cpu->eax, SFERA_DATA_CALL_ARGUMENT_04EDCCD4_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F70C2), UINT32_C(0x004F70C8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000892))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCE3)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCCF4)), UINT32_C(0x000024E2));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F70E3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F70F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F70F0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00004000));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7101));
    LIFT_PUSH3(UINT32_C(0x00004000), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2DE4_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7113));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2DE8_U32 = (uint32_t)(UINT32_C(0x00000100));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F712C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2DEC_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7132), UINT32_C(0x004F7138));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000893))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2DFB)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E0C)), UINT32_C(0x000024EB));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7153));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7160));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000140));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7171));
    LIFT_PUSH3(UINT32_C(0x00000140), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCDD0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7183));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04EDCDD4_U32 = (uint32_t)(UINT32_C(0x00000005));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F719C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04EDCDD8_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F71A2), UINT32_C(0x004F71A8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000894))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDE7)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCDF8)), UINT32_C(0x000024F1));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F71C3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F71D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F71D0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0001D4C0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F71E1));
    LIFT_PUSH3(UINT32_C(0x0001D4C0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2BEC_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F71F3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2BF0_U32 = (uint32_t)(UINT32_C(0x00002710));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F720C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2BF4_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7212), UINT32_C(0x004F7218));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000895))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C03)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C14)), UINT32_C(0x00002539));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7233));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7240));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000960));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7251));
    LIFT_PUSH3(UINT32_C(0x00000960), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED1284_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7263));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED1288_U32 = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F727C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED128C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7282), UINT32_C(0x004F7288));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000896))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED129B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED12AC)), UINT32_C(0x00002A71));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F72A3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F72B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F72B0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000320));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F72C1));
    LIFT_PUSH3(UINT32_C(0x00000320), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04EDCE54_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F72D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04EDCE58_U32 = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F72EC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04EDCE5C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F72F2), UINT32_C(0x004F72F8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000897))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE6B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04EDCE7C)), UINT32_C(0x00002A77));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7313));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7320));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000001E0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7331));
    LIFT_PUSH3(UINT32_C(0x000001E0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED3100_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7343));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED3104_U32 = (uint32_t)(UINT32_C(0x00000028));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F735C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED3108_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7362), UINT32_C(0x004F7368));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000898))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3117)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3128)), UINT32_C(0x00002A84));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7383));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7390));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00027100));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F73A1));
    LIFT_PUSH3(UINT32_C(0x00027100), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED0E14_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F73B3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED0E18_U32 = (uint32_t)(UINT32_C(0x000007D0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F73CC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED0E1C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F73D2), UINT32_C(0x004F73D8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000899))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E2B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0E3C)), UINT32_C(0x00002A85));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F73F3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7400));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000050));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7411));
    LIFT_PUSH3(UINT32_C(0x00000050), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2C18_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7420));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2C1C_U32 = (uint32_t)(UINT32_C(0x00000014));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F7439));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2C20_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F743F), UINT32_C(0x004F7445));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000089A))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C2F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2C40)), UINT32_C(0x00002A86));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7460));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7470));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x04C5BDA0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7481));
    LIFT_PUSH3(UINT32_C(0x04C5BDA0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2E60_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7493));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2E64_U32 = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F74AC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2E68_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F74B2), UINT32_C(0x004F74B8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000089B))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E77)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2E88)), UINT32_C(0x00002A94));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F74D3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F74E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F74E0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000FA0));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F74F1));
    LIFT_PUSH3(UINT32_C(0x00000FA0), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2FE0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7503));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2FE4_U32 = (uint32_t)(UINT32_C(0x000001F4));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F751C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2FE8_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7522), UINT32_C(0x004F7528));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000089C))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2FF7)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED3008)), UINT32_C(0x00003C0D));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7543));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7550));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0009C400));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7561));
    LIFT_PUSH3(UINT32_C(0x0009C400), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2E8C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7573));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2E90_U32 = (uint32_t)(UINT32_C(0x00004E20));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F758C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2E94_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7592), UINT32_C(0x004F7598));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000089D))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EA3)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2EB4)), UINT32_C(0x00003C0F));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F75B3));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F75C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F75C0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000168));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F75D1));
    LIFT_PUSH3(UINT32_C(0x00000168), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED2B0C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F75E3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED2B10_U32 = (uint32_t)(UINT32_C(0x00000014));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F75FC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED2B14_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7602), UINT32_C(0x004F7608));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000089E))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B23)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED2B34)), UINT32_C(0x00004409));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7623));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7630));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0000BB80));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7641));
    LIFT_PUSH3(UINT32_C(0x0000BB80), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED0F5C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7653));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED0F60_U32 = (uint32_t)(UINT32_C(0x00002EE0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F766C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED0F64_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7672), UINT32_C(0x004F7678));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000089F))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F73)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0F84)), UINT32_C(0x0000440A));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7693));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F76A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F76A0));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x0000BB80));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F76B1));
    LIFT_PUSH3(UINT32_C(0x0000BB80), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED1258_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F76C3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED125C_U32 = (uint32_t)(UINT32_C(0x00002EE0));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F76DC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED1260_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F76E2), UINT32_C(0x004F76E8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A0))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED126F)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1280)), UINT32_C(0x0000440B));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7703));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7710));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000040)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x000000C8));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F7721));
    LIFT_PUSH3(UINT32_C(0x000000C8), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04ED0FE8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F7733));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00502968_ADDR);
    SFERA_STATIC_04ED0FEC_U32 = (uint32_t)(UINT32_C(0x00000032));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F774C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04ED0FF0_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F7752), UINT32_C(0x004F7758));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A1))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED0FFF)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04ED1010)), UINT32_C(0x0000440C));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7773));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7780));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EE04B8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EE04A8_ADDR);
    SFERA_STATIC_04EE04A8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7797));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A5))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F77A1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F77B0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EE0518_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F77E9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F77F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F77F0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EE8570_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EE8560_ADDR);
    SFERA_STATIC_04EE8560_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7807));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A6))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7811));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7820(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7820));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EE85D0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7859));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7860(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7860));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EE8640_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EE8630_ADDR);
    SFERA_STATIC_04EE8630_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7877));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A7))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7881));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7890));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EE86A0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F78C9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F78D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F78D0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEA020_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEA010_ADDR);
    SFERA_STATIC_04EEA010_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F78E7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A8))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F78F1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7900));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEA080_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7939));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7940));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEA830_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEA820_ADDR);
    SFERA_STATIC_04EEA820_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7957));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008A9))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7961));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7970(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7970));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEA890_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F79A9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F79B0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEA900_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEA8F0_ADDR);
    SFERA_STATIC_04EEA8F0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F79C7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008AA))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F79D1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F79E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F79E0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEA960_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7A19));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7A20));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEA9D0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEA9C0_ADDR);
    SFERA_STATIC_04EEA9C0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7A37));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008AB))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7A41));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7A50));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAA30_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7A89));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7A90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7A90));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAAA0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEAA90_ADDR);
    SFERA_STATIC_04EEAA90_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7AA7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008AC))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7AB1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7AC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7AC0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAB00_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7AF9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7B00));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAB70_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEAB60_ADDR);
    SFERA_STATIC_04EEAB60_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7B17));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008AD))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7B21));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7B30));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEABD0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7B69));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7B70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7B70));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAC40_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEAC30_ADDR);
    SFERA_STATIC_04EEAC30_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7B87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008AE))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7B91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7BA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEACA0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7BD9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7BE0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008AF))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7BEA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7BF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7BF0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAD20_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEAD10_ADDR);
    SFERA_STATIC_04EEAD10_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7C07));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B0))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7C11));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7C20));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAD80_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7C59));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7C60));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005217F4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F7C71));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B1))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7C7B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7C80));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521810_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F7C91));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B2))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7C9B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7CA0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAEF0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEAEE0_ADDR);
    SFERA_STATIC_04EEAEE0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7CB7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B3))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7CC1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7CD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7CD0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAF50_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7D09));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7D10));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEAFC0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEAFB0_ADDR);
    SFERA_STATIC_04EEAFB0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7D27));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B4))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7D31));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7D40));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB020_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7D79));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7D80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7D80));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB098_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEB088_ADDR);
    SFERA_STATIC_04EEB088_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7D97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B5))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7DA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7DB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB0F8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7DE9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7DF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7DF0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B6))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7DFA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7E00));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB170_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEB160_ADDR);
    SFERA_STATIC_04EEB160_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7E17));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B7))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7E21));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7E30));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB1D0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7E69));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7E70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7E70));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB448_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEB438_ADDR);
    SFERA_STATIC_04EEB438_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7E87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B8))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7E91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7EA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB4A8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7ED9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7EE0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008B9))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7EEA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7EF0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB520_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEB510_ADDR);
    SFERA_STATIC_04EEB510_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7F07));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008BA))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7F11));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7F20));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04EEB580_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7F59));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7F60));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F379F8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F379E8_ADDR);
    SFERA_STATIC_04F379E8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7F77));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008BB))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7F81));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7F90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7F90));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F37A58_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F7FC9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F7FD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F7FD0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F37AC8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F37AB8_ADDR);
    SFERA_STATIC_04F37AB8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F7FE7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008BC))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F7FF1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8000));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F37B28_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8039));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8040));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38828_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F38818_ADDR);
    SFERA_STATIC_04F38818_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8057));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008BD))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8061));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8070));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F388B0_ADDR);
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
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000190));
    LIFT_CALL_ENTER(sfera_sub_004EBE60, UINT32_C(0x004F80C1));
    LIFT_PUSH3(UINT32_C(0x00000190), UINT32_C(0x00000000), cpu->eax);
    SFERA_STATIC_04F38884_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004F80D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000F)));
    cpu->ecx = (uint32_t)(SFERA_RSTR_00506410_ADDR);
    SFERA_STATIC_04F38888_U32 = (uint32_t)(UINT32_C(0x00000064));
    LIFT_CALL_ENTER(sfera_sub_00401000, UINT32_C(0x004F80EC));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04F3888C_ADDR);
    LIFT_IMPORT_INDEX(346u, UINT32_C(0x004F80F2), UINT32_C(0x004F80F8));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008BE))));
    LIFT_STORE8(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3889B)), UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F388AC)), UINT32_C(0x00000157));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8113));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8120));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F389F8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F389E8_ADDR);
    SFERA_STATIC_04F389E8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8137));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008BF))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8141));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8150));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38A58_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8189));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8190(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8190));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38BC8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F38BB8_ADDR);
    SFERA_STATIC_04F38BB8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F81A7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C0))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F81B1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F81C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F81C0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38C28_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F81F9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8200(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8200));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521A38_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8211));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C1))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F821B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8220));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521A54_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8231));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C2))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F823B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8240));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38D98_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F38D88_ADDR);
    SFERA_STATIC_04F38D88_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8257));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C3))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8261));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8270));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38DF8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F82A9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F82B0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521A90_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F82C1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C4))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F82CB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F82D0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521AAC_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F82E1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C5))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F82EB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F82F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F82F0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38E68_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F38E58_ADDR);
    SFERA_STATIC_04F38E58_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8307));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C6))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8311));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8320));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38EC8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8359));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8360(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8360));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38F40_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F38F30_ADDR);
    SFERA_STATIC_04F38F30_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8377));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C7))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8381));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8390));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F38FA0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F83C9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F83D0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521B20_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F83E1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C8))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F83EB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F83F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F83F0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521B3C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8401));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008C9))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F840B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8410(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8410));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F39010_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F39000_ADDR);
    SFERA_STATIC_04F39000_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8427));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008CA))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8431));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8440(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8440));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F39070_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8479));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8480(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8480));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521B78_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8491));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008CB))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F849B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F84A0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521B94_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F84B1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008CC))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F84BB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F84C0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F390E0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F390D0_ADDR);
    SFERA_STATIC_04F390D0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F84D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008CD))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F84E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F84F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F84F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F39140_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8529));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8530(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8530));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521BF8_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8541));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008CE))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F854B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8550));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521C14_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8561));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008CF))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F856B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8570(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8570));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3A478_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3A468_ADDR);
    SFERA_STATIC_04F3A468_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8587));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D0))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8591));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F85A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3A4E8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F85D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F85E0));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D1))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F85EA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F85F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F85F0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3A558_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3A548_ADDR);
    SFERA_STATIC_04F3A548_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8607));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D2))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8611));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8620(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8620));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3A5B8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8659));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8660(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8660));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521C54_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8671));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D3))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F867B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8680(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8680));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521C70_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8691));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D4))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F869B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F86A0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3A928_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3A918_ADDR);
    SFERA_STATIC_04F3A918_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F86B7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D5))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F86C1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F86D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F86D0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3A988_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8709));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8710));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3A9F8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3A9E8_ADDR);
    SFERA_STATIC_04F3A9E8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8727));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D6))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8731));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8740(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8740));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3AA58_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8779));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8780));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521C94_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8791));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D7))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F879B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F87A0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521CB0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F87B1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D8))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F87BB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F87C0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3AAC8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3AAB8_ADDR);
    SFERA_STATIC_04F3AAB8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F87D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008D9))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F87E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F87F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F87F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3AB28_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8829));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8830));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521CFC_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8841));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008DA))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F884B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8850(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8850));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521D18_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8861));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008DB))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F886B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8870));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3AC98_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3AC88_ADDR);
    SFERA_STATIC_04F3AC88_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8887));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008DC))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8891));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F88A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3ACF8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F88D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F88E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F88E0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521D5C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F88F1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008DD))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F88FB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8900));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521D78_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8911));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008DE))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F891B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8920(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8920));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3AD70_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3AD60_ADDR);
    SFERA_STATIC_04F3AD60_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8937));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008DF))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8941));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8950));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3ADD0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8989));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8990));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521DEC_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F89A1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E0))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F89AB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F89B0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521E08_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F89C1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E1))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F89CB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F89D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F89D0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3AF40_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3AF30_ADDR);
    SFERA_STATIC_04F3AF30_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F89E7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E2))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F89F1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A00));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3AFA0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8A39));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A40));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522068_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8A51));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E3))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8A5B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A60));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522084_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8A71));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E4))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8A7B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8A80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8A80));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3B0C0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B0B0_ADDR);
    SFERA_STATIC_04F3B0B0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8A97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E5))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8AA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8AB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3B128_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8AE9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8AF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8AF0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005220BC_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8B01));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E6))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8B0B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8B10));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005220D8_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8B21));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E7))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8B2B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8B30));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000C)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F8B3A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000F8B61, UINT32_C(0x004F8B41));
    SFERA_STATIC_04F3B1AC_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3B1AC_U32);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E8))));
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
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F8B71), UINT32_C(0x004F8B77));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_STATIC_004FDEB4_ADDR);
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
    SFERA_STATIC_04F3B1A0_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3B1A0_U32);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008E9))));
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
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F8BD1), UINT32_C(0x004F8BD7));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_STATIC_004FDEB4_ADDR);
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
    SFERA_STATIC_04F3B11C_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3B11C_U32);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008EA))));
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
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F8C31), UINT32_C(0x004F8C37));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_STATIC_004FDEB4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F8C4E));
    LIFT_TRAP_RETURN(UINT32_C(0x004F8C4E), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8C50));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008ED))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8C5A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8C60));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x0000062D)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000018))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    LIFT_ZERO(cpu->esi, 32u);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004F8C91));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000F8CE7, UINT32_C(0x004F8C98));
    SFERA_STATIC_04F3B188_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->edx);
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3B188_U32);
    LIFT_STORE32(cpu->eax, SFERA_STATIC_04F3B188_ADDR);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008EB))));
    SFERA_STATIC_04F3B18C_U32 = (uint32_t)(cpu->esi);
    SFERA_STATIC_04F3B190_U32 = (uint32_t)(cpu->esi);
    SFERA_STATIC_04F3B194_U32 = (uint32_t)(cpu->esi);
    SFERA_STATIC_04F3B198_U32 = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8CD3));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000018));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x0000001C));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F8CE7, UINT32_C(0x004F8CE7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->esi);
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F8CF4), UINT32_C(0x004F8CFA));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), SFERA_STATIC_004FDEB4_ADDR);
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
    SFERA_STATIC_04F3B0A4_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3B0A4_U32);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008EC))));
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
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F8D61), UINT32_C(0x004F8D67));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_STATIC_004FDEB4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F8D7E));
    LIFT_TRAP_RETURN(UINT32_C(0x004F8D7E), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8D80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8D80));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1C8_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004CFE70, UINT32_C(0x004F8D8A));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008EE))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8D94));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8DA0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3BAD8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3BAC8_ADDR);
    SFERA_STATIC_04F3BAC8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8DB7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008EF))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8DC1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8DD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8DD0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3BB38_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8E09));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E10));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005221C0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8E21));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F0))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8E2B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E30));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005221DC_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8E41));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F1))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8E4B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E50));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3BBA8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3BB98_ADDR);
    SFERA_STATIC_04F3BB98_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8E67));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F2))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8E71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8E80));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F3BC08_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8EB9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8EC0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47C78_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F47C68_ADDR);
    SFERA_STATIC_04F47C68_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8ED7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F3))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8EE1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8EF0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47CD8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8F29));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8F30));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005227E8_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8F41));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F4))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8F4B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8F50));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522804_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8F61));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F5))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8F6B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8F70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8F70));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47D48_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F47D38_ADDR);
    SFERA_STATIC_04F47D38_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F8F87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F6))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8F91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8FA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47DA8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F8FD9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F8FE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F8FE0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522848_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F8FF1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F7))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F8FFB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9000));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522864_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9011));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F8))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F901B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9020(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9020));
    LIFT_PUSH2(UINT32_C(0x0000004D), SFERA_RSTR_00508258_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522880_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9031));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008F9))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F903B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9040));
    LIFT_PUSH2(UINT32_C(0x0000003B), SFERA_RSTR_00507268_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_0052289C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9051));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008FA))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F905B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9060(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9060));
    LIFT_PUSH2(UINT32_C(0x00000020), SFERA_RSTR_005082A8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005228B8_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9071));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008FB))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F907B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9080));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47E18_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F47E08_ADDR);
    SFERA_STATIC_04F47E08_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9097));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008FC))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F90A1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F90B0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47E78_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F90E9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F90F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F90F0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_0052291C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9101));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008FD))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F910B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9110(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9110));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522938_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9121));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008FE))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F912B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9130(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9130));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47EE8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F47ED8_ADDR);
    SFERA_STATIC_04F47ED8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9147));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000008FF))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9151));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9160));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47F48_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9199));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F91A0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_0052297C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F91B1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000900))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F91BB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F91C0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522998_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F91D1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000901))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F91DB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F91E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F91E0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F47FC0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F47FB0_ADDR);
    SFERA_STATIC_04F47FB0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F91F7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000902))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9201));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9210(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9210));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48020_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9249));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9250(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9250));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48190_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F48180_ADDR);
    SFERA_STATIC_04F48180_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9267));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000903))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9271));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9280));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F481F0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F92B9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F92C0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005229D8_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F92D1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000904))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F92DB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F92E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F92E0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_005229F4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F92F1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000905))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F92FB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9300(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9300));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48260_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F48250_ADDR);
    SFERA_STATIC_04F48250_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9317));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000906))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9321));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9330(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9330));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F482C0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9369));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9370(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9370));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522A38_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9381));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000907))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F938B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9390));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522A54_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F93A1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000908))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F93AB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F93B0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48330_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F48320_ADDR);
    SFERA_STATIC_04F48320_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F93C7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000909))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F93D1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F93E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F93E0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48390_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9419));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9420(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9420));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522A94_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9431));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000090A))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F943B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9440(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9440));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522AB0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9451));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000090B))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F945B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9460(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9460));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48500_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F484F0_ADDR);
    SFERA_STATIC_04F484F0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9477));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000090C))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9481));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9490(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9490));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48560_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F94C9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F94D0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522AF0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F94E1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000090D))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F94EB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F94F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F94F0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522B0C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9501));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000090E))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F950B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9510));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F486D0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F486C0_ADDR);
    SFERA_STATIC_04F486C0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9527));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000090F))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9531));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9540(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9540));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48730_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9579));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9580));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522B4C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9591));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000910))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F959B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F95A0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522B68_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F95B1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000911))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F95BB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F95C0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F488A0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F48890_ADDR);
    SFERA_STATIC_04F48890_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F95D7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000912))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F95E1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F95F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F95F0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F48900_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9629));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9630));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522BA4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9641));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000913))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F964B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9650(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9650));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522BC0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9661));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000914))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F966B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9670(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9670));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F49AB0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F49AA0_ADDR);
    SFERA_STATIC_04F49AA0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9687));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000915))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9691));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F96A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F49B10_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F96D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F96E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F96E0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522BE0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F96F1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000916))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F96FB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9700));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522BFC_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9711));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000917))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F971B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9720(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9720));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000091A))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F972A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9730));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000919))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F973A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9740(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9740));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000918))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F974A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9750(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9750));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F49CB0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F49CA0_ADDR);
    SFERA_STATIC_04F49CA0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9767));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000091B))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9771));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9780));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F49D10_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F97B9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F97C0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522C3C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F97D1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000091C))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F97DB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F97E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F97E0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522C58_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F97F1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000091D))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F97FB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9800(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9800));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F49E80_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F49E70_ADDR);
    SFERA_STATIC_04F49E70_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9817));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000091E))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9821));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9830));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F49EE0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9869));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9870));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A0D0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A0C0_ADDR);
    SFERA_STATIC_04F4A0C0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9887));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000091F))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9891));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F98A0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A130_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F98D9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F98E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F98E0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522C98_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F98F1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000920))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F98FB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9900));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522CB4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9911));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000921))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F991B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9920(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9920));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A2A0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A290_ADDR);
    SFERA_STATIC_04F4A290_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9937));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000922))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9941));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9950));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A300_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9989));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9990));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522CD0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F99A1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000923))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F99AB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F99B0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522CEC_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F99C1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000924))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F99CB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F99D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F99D0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A370_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A360_ADDR);
    SFERA_STATIC_04F4A360_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F99E7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000925))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F99F1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A00));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A3D0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9A39));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A40));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522D34_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9A51));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000926))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9A5B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A60));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522D50_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9A71));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000927))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9A7B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9A80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9A80));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A440_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A430_ADDR);
    SFERA_STATIC_04F4A430_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9A97));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000928))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9AA1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9AB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9AB0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A4A8_ADDR);
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
    SFERA_STATIC_04F4A49C_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->eax, cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4A49C_U32);
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000929))));
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
    LIFT_IMPORT_INDEX(320u, UINT32_C(0x004F9B31), UINT32_C(0x004F9B37));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00517CB8_ADDR));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), SFERA_STATIC_004FDEB4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004F9B4E));
    LIFT_TRAP_RETURN(UINT32_C(0x004F9B4E), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9B50));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A530_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A520_ADDR);
    SFERA_STATIC_04F4A520_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9B67));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000092A))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9B71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9B80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9B80));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4A590_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9BB9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9BC0));
    LIFT_PUSH2(UINT32_C(0x00000004), SFERA_STATIC_004FFD7C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522D6C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9BD1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000092B))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9BDB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9BE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9BE0));
    LIFT_PUSH2(UINT32_C(0x00000002), SFERA_STATIC_004FFD84_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_00522D88_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00406820, UINT32_C(0x004F9BF1));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000092C))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9BFB));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C00));
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C708_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004D6720, UINT32_C(0x004F9C0A));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000092E))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9C14));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C20));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C720_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4C710_ADDR);
    SFERA_STATIC_04F4C710_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9C37));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000092F))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9C41));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C50));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C780_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9C89));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9C90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9C90));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C7F0_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4C7E0_ADDR);
    SFERA_STATIC_04F4C7E0_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9CA7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000930))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9CB1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9CC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9CC0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C850_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9CF9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9D00));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C8D8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4C8C8_ADDR);
    SFERA_STATIC_04F4C8C8_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9D17));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000931))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9D21));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9D30));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C938_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9D69));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9D70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9D70));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4C9A8_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4C998_ADDR);
    SFERA_STATIC_04F4C998_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9D87));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000933))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9D91));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9DA0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CA08_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9DD9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9DE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9DE0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CA78_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4CA68_ADDR);
    SFERA_STATIC_04F4CA68_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9DF7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000934))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9E01));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9E10));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CAD8_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9E49));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9E50));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CB50_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4CB40_ADDR);
    SFERA_STATIC_04F4CB40_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9E67));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000935))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9E71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9E80));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CBB0_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9EB9));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9EC0));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CC28_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4CC18_ADDR);
    SFERA_STATIC_04F4CC18_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9ED7));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000936))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9EE1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9EF0));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CC88_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9F29));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9F30));
    cpu->eax = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CE20_ADDR);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFF0), &, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4CE10_ADDR);
    SFERA_STATIC_04F4CE10_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_00401150, UINT32_C(0x004F9F47));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000937))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9F51));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9F60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9F60));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEAC_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_X87_STORE_F32(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_X87_LOAD_F32(SFERA_STATIC_004FDEA8_ADDR);
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F4CE80_ADDR);
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000014));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x0000001C));
    LIFT_CALL_ENTER(sfera_sub_00401250, UINT32_C(0x004F9F99));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9FA0));
    LIFT_PUSH6(UINT32_C(0x00000200), UINT32_C(0x00000000), UINT32_C(0x000F4240), UINT32_C(0x0000000C), SFERA_RSTR_00515D54_ADDR, SFERA_RSTR_00515D44_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8F780_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EC500, UINT32_C(0x004F9FC2));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000938))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9FCC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F9FD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F9FD0));
    LIFT_PUSH6(UINT32_C(0x00000840), LIFT_CALLBACK_INDEX(UINT32_C(0x0000027E)), UINT32_C(0x000F4240), UINT32_C(0x00000000), SFERA_STATIC_00515E30_ADDR, SFERA_RSTR_00515E20_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FAD8_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EC500, UINT32_C(0x004F9FF5));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x00000939))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004F9FFF));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA010));
    LIFT_PUSH6(UINT32_C(0x00000840), LIFT_CALLBACK_INDEX(UINT32_C(0x0000027E)), UINT32_C(0x000F4240), UINT32_C(0x0000000D), SFERA_STATIC_00515E30_ADDR, SFERA_RSTR_00515E3C_ADDR);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FDA0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EC500, UINT32_C(0x004FA035));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000093A))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004FA03F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA041(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA041));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x0000093B))));
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
    cpu->eax = (uint32_t)(SFERA_STATIC_00525C88_U32);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(g_sfera_import_addresses[UINT32_C(0x00000031)]);
    LIFT_PUSH2(UINT32_C(0x00000000), cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0E1)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0DF)))) { return; }
    LIFT_ENTER(UINT32_C(0x004FA0E1));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FA117, UINT32_C(0x004FA0E5));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525C88_U32);
    LIFT_PUSH2(UINT32_C(0x00000064), cpu->ecx);
    LIFT_STORE16(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00525C94)), UINT32_C(0x00000001));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0F9)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA0F7)))) { return; }
    LIFT_ENTER(UINT32_C(0x004FA0F9));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FA10C, UINT32_C(0x004FA0FD));
    cpu->edx = (uint32_t)(SFERA_STATIC_00525C88_U32);
    LIFT_PUSH2(UINT32_C(0x00000000), cpu->edx);
    lift_import_call(cpu, 48u, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA106)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA10C));
    LIFT_BLOCK(label_000FA10C, UINT32_C(0x004FA10C));
    lift_push32(cpu, (uint32_t)(SFERA_DATA_CALL_ARGUMENT_00525CCC_ADDR));
    lift_import_call(cpu, 59u, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000FA111)));
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525F4C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA162));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA170));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000003E4)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH2(cpu->eax, cpu->esi);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00520248_U32);
    cpu->eax = (uint32_t)(SFERA_STATIC_00520244_U32);
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ZERO(cpu->esi, 32u);
    cpu->ecx = (uint32_t)(lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000002)), 32u));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000FA1BA, UINT32_C(0x004FA1AB));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00520244_ADDR);
    LIFT_CALL_ENTER(sfera_sub_0042A290, UINT32_C(0x004FA1B5));
    cpu->eax = (uint32_t)(SFERA_STATIC_00520244_U32);
    LIFT_BLOCK(label_000FA1BA, UINT32_C(0x004FA1BA));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000FA1C7, UINT32_C(0x004FA1BE));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA1C4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA1C7, UINT32_C(0x004FA1C7));
    SFERA_STATIC_00520244_U32 = (uint32_t)(cpu->esi);
    SFERA_STATIC_00520248_U32 = (uint32_t)(cpu->esi);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0052024C)), cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA1F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA1F0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000003E6)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(SFERA_STATIC_00525FDC_U32);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525FD8_ADDR);
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_00406340, UINT32_C(0x004FA231));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00525FDC_U32);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA23D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_004FF878_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x0042E649));
    LIFT_LOAD32(cpu->esi, cpu->edi + UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_0002E680, UINT32_C(0x0042E650));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000004)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->esi, SFERA_STATIC_004FF874_ADDR);
    LIFT_JZ(label_0002E677, UINT32_C(0x0042E65C));
    cpu->edx = (uint32_t)(UINT32_C(0x00000065));
    cpu->ecx = (uint32_t)(SFERA_STATIC_004FF878_ADDR);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_004FF878_ADDR);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_00526198_ADDR);
    goto label_0002E630;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA280));
    cpu->ecx = (uint32_t)(SFERA_STATIC_0052627C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA292));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA2A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA2A0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00526244_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
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
    LIFT_CMP(SFERA_STATIC_00520718_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FA2F7, UINT32_C(0x004FA2E9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00520704_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA2F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA2F7, UINT32_C(0x004FA2F7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00520718_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00520714)), cpu->eax);
    SFERA_STATIC_00520704_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA310(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA310));
    LIFT_CMP(SFERA_STATIC_00520734_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FA327, UINT32_C(0x004FA319));
    cpu->eax = (uint32_t)(SFERA_STATIC_00520720_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA324));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA327, UINT32_C(0x004FA327));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00520734_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00520730)), cpu->eax);
    SFERA_STATIC_00520720_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_0050A2E4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x004D7AC2));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000D7AD0, UINT32_C(0x004D7AC8));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->edx, cpu->eax);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000D7AD0)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000D7ACE)))) { return; }
    LIFT_BLOCK(label_000D7AD0, UINT32_C(0x004D7AD0));
    cpu->edx = (uint32_t)(UINT32_C(0x00000014));
    cpu->ecx = (uint32_t)(SFERA_STATIC_0050A2E4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x004D7ADF));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000D7AEF, UINT32_C(0x004D7AE7));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->edx, cpu->eax);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000D7AEF)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000D7AED)))) { return; }
    LIFT_BLOCK(label_000D7AEF, UINT32_C(0x004D7AEF));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FA360, UINT32_C(0x004FA360));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DC0680_ADDR);
    goto label_000D7AB0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA370(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA370));
    LIFT_CMP(SFERA_STATIC_0052106C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FA387, UINT32_C(0x004FA379));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521058_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA384));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA387, UINT32_C(0x004FA387));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_0052106C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521068)), cpu->eax);
    SFERA_STATIC_00521058_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA3A0));
    LIFT_CMP(SFERA_STATIC_00521088_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FA3B7, UINT32_C(0x004FA3A9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521074_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FA3B4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FA3B7, UINT32_C(0x004FA3B7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521088_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521084)), cpu->eax);
    SFERA_STATIC_00521074_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA3D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA3E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA3E0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DD0B50_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA3F2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA400));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DD0B24_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA412));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA420(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA420));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04DD0AF8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
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
    cpu->ecx = (uint32_t)(SFERA_RSTR_005058FC_ADDR);
    LIFT_TAIL(sfera_sub_00459B10);
    LIFT_BLOCK(label_0008A1BF, UINT32_C(0x0048A1BF));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FA460, UINT32_C(0x004FA460));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EC4FB0_ADDR);
    goto label_0008A1B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA470));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCD98_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA482));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA490(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA490));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED0D70_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA4A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA4B0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2BA8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA4C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA4D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1220_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA4E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA4F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA4F0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED3038_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA502));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA510));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1A68_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA522));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA530(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA530));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED12F0_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA542));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA550));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1A30_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA562));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA570(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA570));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED30C8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA582));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA590(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA590));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1190_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA5A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA5B0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED29F8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA5C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA5D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2F74_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA5E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA5F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA5F0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2F48_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA602));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA610(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA610));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2AD4_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA622));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA630));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2A24_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA642));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA650(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA650));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED29A0_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA662));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA670(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA670));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED309C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA682));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA690(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA690));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2F1C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA6A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA6B0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCE28_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA6C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA6D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED3070_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA6E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA6F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA6F0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2C44_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA702));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA710));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED0F30_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA722));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA730));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2EC4_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA742));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA750(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA750));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2AA8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA762));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA770));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EC4F84_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA782));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA790(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA790));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EC4FBC_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA7A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA7B0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1158_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA7C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA7D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1120_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA7E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA7F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA7F0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED11E8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA802));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA810));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDD030_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA822));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA830));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2D28_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA842));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA850(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA850));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2E34_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA862));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA870));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2A7C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA882));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA890));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCF78_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA8A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA8B0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED11BC_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA8C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA8D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2DB8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA8E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA8F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA8F0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCF40_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA902));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA910(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA910));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1014_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA922));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA930));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED29CC_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA942));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA950));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED0EC4_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA962));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA970(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA970));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCDFC_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA982));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA990));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCFA4_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA9A2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA9B0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED300C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA9C2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA9D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCCA0_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FA9E2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FA9F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FA9F0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2EF0_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA02));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA10));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2A50_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA22));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA30));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCCCC_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA42));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA50));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2DE4_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA62));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA70));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCDD0_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAA82));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAA90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAA90));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2BEC_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAAA2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAAB0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1284_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAAC2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAAD0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCE54_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAAE2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAAF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAAF0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED3100_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB02));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB10));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED0E14_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB22));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB30));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2C18_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB42));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB50));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2E60_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB62));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB70));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2FE0_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAB82));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAB90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAB90));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2E8C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FABA2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FABB0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED2B0C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FABC2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FABD0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED0F5C_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FABE2));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FABF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FABF0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED1258_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAC02));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC10));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04ED0FE8_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004FAC22));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC30));
    LIFT_CMP(SFERA_STATIC_00521598_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FAC47, UINT32_C(0x004FAC39));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521584_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FAC44));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FAC47, UINT32_C(0x004FAC47));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521598_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521594)), cpu->eax);
    SFERA_STATIC_00521584_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC60));
    LIFT_CMP(SFERA_STATIC_005215B4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FAC77, UINT32_C(0x004FAC69));
    cpu->eax = (uint32_t)(SFERA_STATIC_005215A0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FAC74));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FAC77, UINT32_C(0x004FAC77));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005215B4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005215B0)), cpu->eax);
    SFERA_STATIC_005215A0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAC90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAC90));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x00000435)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDCD74_U32);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCD70_ADDR);
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D400, UINT32_C(0x004FACD1));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCD74_U32);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FACDD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_005217D8_ADDR);
    LIFT_TAIL(sfera_sub_0048A6A0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FADA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FADB0));
    LIFT_CMP(SFERA_STATIC_00521808_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FADC7, UINT32_C(0x004FADB9));
    cpu->eax = (uint32_t)(SFERA_STATIC_005217F4_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FADC4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FADC7, UINT32_C(0x004FADC7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521808_U32 = (uint32_t)(UINT32_C(0x0000000F));
    SFERA_STATIC_00521804_U32 = (uint32_t)(cpu->eax);
    SFERA_STATIC_005217F4_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FADE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FADE0));
    LIFT_CMP(SFERA_STATIC_00521824_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FADF7, UINT32_C(0x004FADE9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521810_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FADF4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FADF7, UINT32_C(0x004FADF7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521824_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521820)), cpu->eax);
    SFERA_STATIC_00521810_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
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
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000004D2)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH2(cpu->eax, cpu->esi);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(SFERA_STATIC_00521840_U32);
    cpu->eax = (uint32_t)(SFERA_STATIC_0052183C_U32);
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ZERO(cpu->esi, 32u);
    cpu->ecx = (uint32_t)(lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000002)), 32u));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000FAE8A, UINT32_C(0x004FAE7B));
    cpu->ecx = (uint32_t)(SFERA_STATIC_0052183C_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004974B0, UINT32_C(0x004FAE85));
    cpu->eax = (uint32_t)(SFERA_STATIC_0052183C_U32);
    LIFT_BLOCK(label_000FAE8A, UINT32_C(0x004FAE8A));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000FAE97, UINT32_C(0x004FAE8E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FAE94));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FAE97, UINT32_C(0x004FAE97));
    SFERA_STATIC_0052183C_U32 = (uint32_t)(cpu->esi);
    SFERA_STATIC_00521840_U32 = (uint32_t)(cpu->esi);
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521844)), cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
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
    LIFT_CMP(SFERA_STATIC_04EEB508_U32, cpu->esi, 32u);
    LIFT_JZ(label_000FAF0F, UINT32_C(0x004FAEEB));
    cpu->eax = (uint32_t)(SFERA_STATIC_04EEB50C_U32);
    LIFT_BLOCK(label_000FAEF0, UINT32_C(0x004FAEF0));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JZ(label_000FAF07, UINT32_C(0x004FAEF4));
    LIFT_LOAD32(cpu->eax, cpu->eax + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EEB508_ADDR);
    LIFT_CALL_ENTER(sfera_sub_00498C30, UINT32_C(0x004FAF02));
    cpu->eax = (uint32_t)(SFERA_STATIC_04EEB50C_U32);
    LIFT_BLOCK(label_000FAF07, UINT32_C(0x004FAF07));
    LIFT_CMP(SFERA_STATIC_04EEB508_U32, cpu->esi, 32u);
    LIFT_JNZ_GOTO(label_000FAEF0);
    LIFT_BLOCK(label_000FAF0F, UINT32_C(0x004FAF0F));
    SFERA_STATIC_04EEB50C_U32 = (uint32_t)(cpu->esi);
    SFERA_STATIC_04EEB508_U32 = (uint32_t)(cpu->esi);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F38884_U32);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000004B)));
    cpu->edx = (uint32_t)(SFERA_STATIC_004FF230_ADDR);
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
    LIFT_CMP(SFERA_STATIC_00521A4C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FAFB7, UINT32_C(0x004FAFA9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521A38_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FAFB4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FAFB7, UINT32_C(0x004FAFB7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521A4C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521A48)), cpu->eax);
    SFERA_STATIC_00521A38_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FAFD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FAFD0));
    LIFT_CMP(SFERA_STATIC_00521A68_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FAFE7, UINT32_C(0x004FAFD9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521A54_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FAFE4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FAFE7, UINT32_C(0x004FAFE7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521A68_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521A64)), cpu->eax);
    SFERA_STATIC_00521A54_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB010(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB010));
    LIFT_CMP(SFERA_STATIC_00521AA4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB027, UINT32_C(0x004FB019));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521A90_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB024));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB027, UINT32_C(0x004FB027));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521AA4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521AA0)), cpu->eax);
    SFERA_STATIC_00521A90_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB040));
    LIFT_CMP(SFERA_STATIC_00521AC0_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB057, UINT32_C(0x004FB049));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521AAC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB054));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB057, UINT32_C(0x004FB057));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521AC0_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521ABC)), cpu->eax);
    SFERA_STATIC_00521AAC_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
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
    LIFT_CMP(SFERA_STATIC_00521B34_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB0A7, UINT32_C(0x004FB099));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521B20_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB0A4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB0A7, UINT32_C(0x004FB0A7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521B34_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521B30)), cpu->eax);
    SFERA_STATIC_00521B20_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB0C0));
    LIFT_CMP(SFERA_STATIC_00521B50_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB0D7, UINT32_C(0x004FB0C9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521B3C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB0D4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB0D7, UINT32_C(0x004FB0D7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521B50_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521B4C)), cpu->eax);
    SFERA_STATIC_00521B3C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB0F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB0F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB100(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB100));
    LIFT_CMP(SFERA_STATIC_00521B8C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB117, UINT32_C(0x004FB109));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521B78_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB114));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB117, UINT32_C(0x004FB117));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521B8C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521B88)), cpu->eax);
    SFERA_STATIC_00521B78_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB130(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB130));
    LIFT_CMP(SFERA_STATIC_00521BA8_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB147, UINT32_C(0x004FB139));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521B94_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB144));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB147, UINT32_C(0x004FB147));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521BA8_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521BA4)), cpu->eax);
    SFERA_STATIC_00521B94_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB160(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB160));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB170));
    LIFT_CMP(SFERA_STATIC_00521C0C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB187, UINT32_C(0x004FB179));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521BF8_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB184));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB187, UINT32_C(0x004FB187));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521C0C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521C08)), cpu->eax);
    SFERA_STATIC_00521BF8_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB1A0));
    LIFT_CMP(SFERA_STATIC_00521C28_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB1B7, UINT32_C(0x004FB1A9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521C14_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB1B4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB1B7, UINT32_C(0x004FB1B7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521C28_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521C24)), cpu->eax);
    SFERA_STATIC_00521C14_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB1D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB1E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB1E0));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3A4D4_U32);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FB1F2, UINT32_C(0x004FB1E9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB1EF));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB1F2, UINT32_C(0x004FB1F2));
    SFERA_STATIC_04F3A4D4_U32 = (uint32_t)(UINT32_C(0x00000000));
    SFERA_STATIC_04F3A4D8_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3A4DC)), UINT32_C(0x00000000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB220));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB230));
    LIFT_CMP(SFERA_STATIC_00521C68_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB247, UINT32_C(0x004FB239));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521C54_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB244));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB247, UINT32_C(0x004FB247));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521C68_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521C64)), cpu->eax);
    SFERA_STATIC_00521C54_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB260(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB260));
    LIFT_CMP(SFERA_STATIC_00521C84_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB277, UINT32_C(0x004FB269));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521C70_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB274));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB277, UINT32_C(0x004FB277));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521C84_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521C80)), cpu->eax);
    SFERA_STATIC_00521C70_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
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
    LIFT_CMP(SFERA_STATIC_00521CA8_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB2C7, UINT32_C(0x004FB2B9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521C94_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB2C4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB2C7, UINT32_C(0x004FB2C7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521CA8_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521CA4)), cpu->eax);
    SFERA_STATIC_00521C94_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB2E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB2E0));
    LIFT_CMP(SFERA_STATIC_00521CC4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB2F7, UINT32_C(0x004FB2E9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521CB0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB2F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB2F7, UINT32_C(0x004FB2F7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521CC4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521CC0)), cpu->eax);
    SFERA_STATIC_00521CB0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB310(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB310));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB320));
    LIFT_CMP(SFERA_STATIC_00521D10_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB337, UINT32_C(0x004FB329));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521CFC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB334));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB337, UINT32_C(0x004FB337));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521D10_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521D0C)), cpu->eax);
    SFERA_STATIC_00521CFC_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB350));
    LIFT_CMP(SFERA_STATIC_00521D2C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB367, UINT32_C(0x004FB359));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521D18_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB364));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB367, UINT32_C(0x004FB367));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521D2C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521D28)), cpu->eax);
    SFERA_STATIC_00521D18_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB380(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB380));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB390));
    LIFT_CMP(SFERA_STATIC_00521D70_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB3A7, UINT32_C(0x004FB399));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521D5C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB3A4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB3A7, UINT32_C(0x004FB3A7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521D70_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521D6C)), cpu->eax);
    SFERA_STATIC_00521D5C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB3C0));
    LIFT_CMP(SFERA_STATIC_00521D8C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB3D7, UINT32_C(0x004FB3C9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521D78_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB3D4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB3D7, UINT32_C(0x004FB3D7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521D8C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521D88)), cpu->eax);
    SFERA_STATIC_00521D78_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB3F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB3F0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB400(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB400));
    LIFT_CMP(SFERA_STATIC_00521E00_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB417, UINT32_C(0x004FB409));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521DEC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB414));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB417, UINT32_C(0x004FB417));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521E00_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521DFC)), cpu->eax);
    SFERA_STATIC_00521DEC_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB430(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB430));
    LIFT_CMP(SFERA_STATIC_00521E1C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB447, UINT32_C(0x004FB439));
    cpu->eax = (uint32_t)(SFERA_STATIC_00521E08_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB444));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB447, UINT32_C(0x004FB447));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00521E1C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00521E18)), cpu->eax);
    SFERA_STATIC_00521E08_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB460(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB460));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB470));
    LIFT_CMP(SFERA_STATIC_0052207C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB487, UINT32_C(0x004FB479));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522068_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB484));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB487, UINT32_C(0x004FB487));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_0052207C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522078)), cpu->eax);
    SFERA_STATIC_00522068_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB4A0));
    LIFT_CMP(SFERA_STATIC_00522098_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB4B7, UINT32_C(0x004FB4A9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522084_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB4B4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB4B7, UINT32_C(0x004FB4B7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522098_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522094)), cpu->eax);
    SFERA_STATIC_00522084_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB4D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB4E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB4E0));
    LIFT_CMP(SFERA_STATIC_005220D0_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB4F7, UINT32_C(0x004FB4E9));
    cpu->eax = (uint32_t)(SFERA_STATIC_005220BC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB4F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB4F7, UINT32_C(0x004FB4F7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005220D0_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005220CC)), cpu->eax);
    SFERA_STATIC_005220BC_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB510));
    LIFT_CMP(SFERA_STATIC_005220EC_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB527, UINT32_C(0x004FB519));
    cpu->eax = (uint32_t)(SFERA_STATIC_005220D8_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB524));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB527, UINT32_C(0x004FB527));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005220EC_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005220E8)), cpu->eax);
    SFERA_STATIC_005220D8_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB540(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB540));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1AC_U32);
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1AC_U32);
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1AC_U32);
    SFERA_STATIC_04F3B1B0_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FB580, UINT32_C(0x004FB567));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FB568, UINT32_C(0x004FB568));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB570));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1AC_U32);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1A0_U32);
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1A0_U32);
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1A0_U32);
    SFERA_STATIC_04F3B1A4_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FB5D0, UINT32_C(0x004FB5B7));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FB5B8, UINT32_C(0x004FB5B8));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB5C0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1A0_U32);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B11C_U32);
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B11C_U32);
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B11C_U32);
    SFERA_STATIC_04F3B120_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FB620, UINT32_C(0x004FB607));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FB608, UINT32_C(0x004FB608));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB610));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B11C_U32);
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
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B188_ADDR);
    LIFT_CALL_ENTER(sfera_sub_0049FA40, UINT32_C(0x004FB63A));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3B188_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB645));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    SFERA_STATIC_04F3B188_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB660(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB660));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B0A4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004BC130, UINT32_C(0x004FB66A));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F3B0A4_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB675));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB680(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB680));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1B8_U32);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000FB6AE, UINT32_C(0x004FB68B));
    LIFT_LOAD32(cpu->eax, cpu->esp);
    cpu->edx = (uint32_t)(SFERA_STATIC_04F3B1BC_U32);
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_04F3B1C4_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004BC000, UINT32_C(0x004FB69F));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1B8_U32);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB6AB));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB6AE, UINT32_C(0x004FB6AE));
    SFERA_STATIC_04F3B1B8_U32 = (uint32_t)(UINT32_C(0x00000000));
    SFERA_STATIC_04F3B1BC_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F3B1C0)), UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB6D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B1C8_ADDR);
    LIFT_TAIL(sfera_sub_004BC9F0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB6E0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB6F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB6F0));
    LIFT_CMP(SFERA_STATIC_005221D4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB707, UINT32_C(0x004FB6F9));
    cpu->eax = (uint32_t)(SFERA_STATIC_005221C0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB704));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB707, UINT32_C(0x004FB707));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005221D4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005221D0)), cpu->eax);
    SFERA_STATIC_005221C0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB720(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB720));
    LIFT_CMP(SFERA_STATIC_005221F0_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB737, UINT32_C(0x004FB729));
    cpu->eax = (uint32_t)(SFERA_STATIC_005221DC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB734));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB737, UINT32_C(0x004FB737));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005221F0_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005221EC)), cpu->eax);
    SFERA_STATIC_005221DC_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
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
    LIFT_CMP(SFERA_STATIC_005227FC_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB787, UINT32_C(0x004FB779));
    cpu->eax = (uint32_t)(SFERA_STATIC_005227E8_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB784));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB787, UINT32_C(0x004FB787));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005227FC_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005227F8)), cpu->eax);
    SFERA_STATIC_005227E8_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB7A0));
    LIFT_CMP(SFERA_STATIC_00522818_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB7B7, UINT32_C(0x004FB7A9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522804_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB7B4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB7B7, UINT32_C(0x004FB7B7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522818_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522814)), cpu->eax);
    SFERA_STATIC_00522804_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB7D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB7E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB7E0));
    LIFT_CMP(SFERA_STATIC_0052285C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB7F7, UINT32_C(0x004FB7E9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522848_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB7F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB7F7, UINT32_C(0x004FB7F7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_0052285C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522858)), cpu->eax);
    SFERA_STATIC_00522848_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB810));
    LIFT_CMP(SFERA_STATIC_00522878_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB827, UINT32_C(0x004FB819));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522864_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB824));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB827, UINT32_C(0x004FB827));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522878_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522874)), cpu->eax);
    SFERA_STATIC_00522864_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB840(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB840));
    LIFT_CMP(SFERA_STATIC_00522894_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB857, UINT32_C(0x004FB849));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522880_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB854));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB857, UINT32_C(0x004FB857));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522894_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522890)), cpu->eax);
    SFERA_STATIC_00522880_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB870));
    LIFT_CMP(SFERA_STATIC_005228B0_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB887, UINT32_C(0x004FB879));
    cpu->eax = (uint32_t)(SFERA_STATIC_0052289C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB884));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB887, UINT32_C(0x004FB887));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005228B0_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005228AC)), cpu->eax);
    SFERA_STATIC_0052289C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB8A0));
    LIFT_CMP(SFERA_STATIC_005228CC_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB8B7, UINT32_C(0x004FB8A9));
    cpu->eax = (uint32_t)(SFERA_STATIC_005228B8_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB8B4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB8B7, UINT32_C(0x004FB8B7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005228CC_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005228C8)), cpu->eax);
    SFERA_STATIC_005228B8_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB8D0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB8E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB8E0));
    LIFT_CMP(SFERA_STATIC_00522930_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB8F7, UINT32_C(0x004FB8E9));
    cpu->eax = (uint32_t)(SFERA_STATIC_0052291C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB8F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB8F7, UINT32_C(0x004FB8F7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522930_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0052292C)), cpu->eax);
    SFERA_STATIC_0052291C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB910(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB910));
    LIFT_CMP(SFERA_STATIC_0052294C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB927, UINT32_C(0x004FB919));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522938_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB924));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB927, UINT32_C(0x004FB927));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_0052294C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522948)), cpu->eax);
    SFERA_STATIC_00522938_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB940));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB950));
    LIFT_CMP(SFERA_STATIC_00522990_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB967, UINT32_C(0x004FB959));
    cpu->eax = (uint32_t)(SFERA_STATIC_0052297C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB964));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB967, UINT32_C(0x004FB967));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522990_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x0052298C)), cpu->eax);
    SFERA_STATIC_0052297C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FB980(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FB980));
    LIFT_CMP(SFERA_STATIC_005229AC_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB997, UINT32_C(0x004FB989));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522998_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB994));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB997, UINT32_C(0x004FB997));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005229AC_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005229A8)), cpu->eax);
    SFERA_STATIC_00522998_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
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
    LIFT_CMP(SFERA_STATIC_005229EC_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FB9E7, UINT32_C(0x004FB9D9));
    cpu->eax = (uint32_t)(SFERA_STATIC_005229D8_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FB9E4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FB9E7, UINT32_C(0x004FB9E7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_005229EC_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x005229E8)), cpu->eax);
    SFERA_STATIC_005229D8_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA00));
    LIFT_CMP(SFERA_STATIC_00522A08_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBA17, UINT32_C(0x004FBA09));
    cpu->eax = (uint32_t)(SFERA_STATIC_005229F4_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBA14));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBA17, UINT32_C(0x004FBA17));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522A08_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522A04)), cpu->eax);
    SFERA_STATIC_005229F4_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA30));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA40));
    LIFT_CMP(SFERA_STATIC_00522A4C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBA57, UINT32_C(0x004FBA49));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522A38_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBA54));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBA57, UINT32_C(0x004FBA57));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522A4C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522A48)), cpu->eax);
    SFERA_STATIC_00522A38_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBA70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBA70));
    LIFT_CMP(SFERA_STATIC_00522A68_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBA87, UINT32_C(0x004FBA79));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522A54_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBA84));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBA87, UINT32_C(0x004FBA87));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522A68_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522A64)), cpu->eax);
    SFERA_STATIC_00522A54_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBAA0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBAB0));
    LIFT_CMP(SFERA_STATIC_00522AA8_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBAC7, UINT32_C(0x004FBAB9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522A94_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBAC4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBAC7, UINT32_C(0x004FBAC7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522AA8_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522AA4)), cpu->eax);
    SFERA_STATIC_00522A94_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBAE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBAE0));
    LIFT_CMP(SFERA_STATIC_00522AC4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBAF7, UINT32_C(0x004FBAE9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522AB0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBAF4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBAF7, UINT32_C(0x004FBAF7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522AC4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522AC0)), cpu->eax);
    SFERA_STATIC_00522AB0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB10));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB20));
    LIFT_CMP(SFERA_STATIC_00522B04_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBB37, UINT32_C(0x004FBB29));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522AF0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBB34));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBB37, UINT32_C(0x004FBB37));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522B04_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522B00)), cpu->eax);
    SFERA_STATIC_00522AF0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB50));
    LIFT_CMP(SFERA_STATIC_00522B20_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBB67, UINT32_C(0x004FBB59));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522B0C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBB64));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBB67, UINT32_C(0x004FBB67));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522B20_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522B1C)), cpu->eax);
    SFERA_STATIC_00522B0C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBB90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBB90));
    LIFT_CMP(SFERA_STATIC_00522B60_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBBA7, UINT32_C(0x004FBB99));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522B4C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBBA4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBBA7, UINT32_C(0x004FBBA7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522B60_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522B5C)), cpu->eax);
    SFERA_STATIC_00522B4C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBBC0));
    LIFT_CMP(SFERA_STATIC_00522B7C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBBD7, UINT32_C(0x004FBBC9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522B68_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBBD4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBBD7, UINT32_C(0x004FBBD7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522B7C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522B78)), cpu->eax);
    SFERA_STATIC_00522B68_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBBF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBBF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC00));
    LIFT_CMP(SFERA_STATIC_00522BB8_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBC17, UINT32_C(0x004FBC09));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522BA4_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBC14));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBC17, UINT32_C(0x004FBC17));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522BB8_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522BB4)), cpu->eax);
    SFERA_STATIC_00522BA4_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC30));
    LIFT_CMP(SFERA_STATIC_00522BD4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBC47, UINT32_C(0x004FBC39));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522BC0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBC44));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBC47, UINT32_C(0x004FBC47));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522BD4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522BD0)), cpu->eax);
    SFERA_STATIC_00522BC0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBC70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBC70));
    LIFT_CMP(SFERA_STATIC_00522BF4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBC87, UINT32_C(0x004FBC79));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522BE0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBC84));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBC87, UINT32_C(0x004FBC87));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522BF4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522BF0)), cpu->eax);
    SFERA_STATIC_00522BE0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBCA0));
    LIFT_CMP(SFERA_STATIC_00522C10_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBCB7, UINT32_C(0x004FBCA9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522BFC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBCB4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBCB7, UINT32_C(0x004FBCB7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522C10_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522C0C)), cpu->eax);
    SFERA_STATIC_00522BFC_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBCD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBCD0));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F49B80_U32);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FBCE2, UINT32_C(0x004FBCD9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBCDF));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBCE2, UINT32_C(0x004FBCE2));
    SFERA_STATIC_04F49B80_U32 = (uint32_t)(UINT32_C(0x00000000));
    SFERA_STATIC_04F49B84_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B88)), UINT32_C(0x00000000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBD10));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F49B70_U32);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FBD22, UINT32_C(0x004FBD19));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBD1F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBD22, UINT32_C(0x004FBD22));
    SFERA_STATIC_04F49B70_U32 = (uint32_t)(UINT32_C(0x00000000));
    SFERA_STATIC_04F49B74_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B78)), UINT32_C(0x00000000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBD50));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F49B90_U32);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000FBD62, UINT32_C(0x004FBD59));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBD5F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBD62, UINT32_C(0x004FBD62));
    SFERA_STATIC_04F49B90_U32 = (uint32_t)(UINT32_C(0x00000000));
    SFERA_STATIC_04F49B94_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F49B98)), UINT32_C(0x00000000));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBD90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBD90));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBDA0));
    LIFT_CMP(SFERA_STATIC_00522C50_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBDB7, UINT32_C(0x004FBDA9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522C3C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBDB4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBDB7, UINT32_C(0x004FBDB7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522C50_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522C4C)), cpu->eax);
    SFERA_STATIC_00522C3C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBDD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBDD0));
    LIFT_CMP(SFERA_STATIC_00522C6C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBDE7, UINT32_C(0x004FBDD9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522C58_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBDE4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBDE7, UINT32_C(0x004FBDE7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522C6C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522C68)), cpu->eax);
    SFERA_STATIC_00522C58_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
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
    LIFT_CMP(SFERA_STATIC_00522CAC_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBE37, UINT32_C(0x004FBE29));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522C98_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBE34));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBE37, UINT32_C(0x004FBE37));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522CAC_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522CA8)), cpu->eax);
    SFERA_STATIC_00522C98_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE50));
    LIFT_CMP(SFERA_STATIC_00522CC8_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBE67, UINT32_C(0x004FBE59));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522CB4_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBE64));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBE67, UINT32_C(0x004FBE67));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522CC8_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522CC4)), cpu->eax);
    SFERA_STATIC_00522CB4_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE80));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBE90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBE90));
    LIFT_CMP(SFERA_STATIC_00522CE4_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBEA7, UINT32_C(0x004FBE99));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522CD0_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBEA4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBEA7, UINT32_C(0x004FBEA7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522CE4_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522CE0)), cpu->eax);
    SFERA_STATIC_00522CD0_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBEC0));
    LIFT_CMP(SFERA_STATIC_00522D00_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBED7, UINT32_C(0x004FBEC9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522CEC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBED4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBED7, UINT32_C(0x004FBED7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522D00_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522CFC)), cpu->eax);
    SFERA_STATIC_00522CEC_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBEF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBEF0));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF00));
    LIFT_CMP(SFERA_STATIC_00522D48_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBF17, UINT32_C(0x004FBF09));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522D34_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBF14));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBF17, UINT32_C(0x004FBF17));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522D48_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522D44)), cpu->eax);
    SFERA_STATIC_00522D34_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF30));
    LIFT_CMP(SFERA_STATIC_00522D64_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBF47, UINT32_C(0x004FBF39));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522D50_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBF44));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBF47, UINT32_C(0x004FBF47));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522D64_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522D60)), cpu->eax);
    SFERA_STATIC_00522D50_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF60));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FBF70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FBF70));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A49C_U32);
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_STORE32(cpu->ecx, cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A49C_U32);
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A49C_U32);
    SFERA_STATIC_04F4A4A0_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000FBFB0, UINT32_C(0x004FBF97));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_BLOCK(label_000FBF98, UINT32_C(0x004FBF98));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBFA0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A49C_U32);
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
    LIFT_CMP(SFERA_STATIC_00522D80_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FBFE7, UINT32_C(0x004FBFD9));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522D6C_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FBFE4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FBFE7, UINT32_C(0x004FBFE7));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522D80_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522D7C)), cpu->eax);
    SFERA_STATIC_00522D6C_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC000));
    LIFT_CMP(SFERA_STATIC_00522D9C_U32, UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000FC017, UINT32_C(0x004FC009));
    cpu->eax = (uint32_t)(SFERA_STATIC_00522D88_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FC014));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000FC017, UINT32_C(0x004FC017));
    LIFT_ZERO(cpu->eax, 32u);
    SFERA_STATIC_00522D9C_U32 = (uint32_t)(UINT32_C(0x0000000F));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x00522D98)), cpu->eax);
    SFERA_STATIC_00522D88_U8 = (uint8_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC030(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC030));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000006C1)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4A50C_U32);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A508_ADDR);
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004B2C40, UINT32_C(0x004FC071));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4A50C_U32);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004FC07D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000008));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC090(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004FC090));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4C6FC_U32);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_INDEX(42u, UINT32_C(0x004FC096), UINT32_C(0x004FC09C));
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
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000006CF)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000018))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->edi);
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    LIFT_CMP(cpu->esi, cpu->eax, 32u);
    LIFT_JZ(label_000D793C, UINT32_C(0x004D78E5));
    cpu->ebx = g_sfera_import_addresses[UINT32_C(0x00000080)];
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FC0D0, UINT32_C(0x004FC0D0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4C8B0_ADDR);
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
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000006EA)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000020));
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_PUSH4(cpu->ebx, cpu->esi, cpu->edi, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    SFERA_STATIC_04F9006C_U32 = (uint32_t)(cpu->edx);
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
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F24_ADDR));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED21E));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED238, UINT32_C(0x004ED224));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F24_ADDR));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED238)));
    LIFT_BLOCK(label_000ED238, UINT32_C(0x004ED238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_INDEX(345u, UINT32_C(0x004ED23C), UINT32_C(0x004ED242));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_INDEX(344u, UINT32_C(0x004ED246), UINT32_C(0x004ED24C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_00515F08_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->eax);
    LIFT_IMPORT_INDEX(347u, UINT32_C(0x004ED258), UINT32_C(0x004ED25E));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->ecx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED26E));
    LIFT_PUSH3(SFERA_STATIC_005002E0_ADDR, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED27C));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED296, UINT32_C(0x004ED282));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_005002E0_ADDR));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED296)));
    LIFT_BLOCK(label_000ED296, UINT32_C(0x004ED296));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_INDEX(290u, UINT32_C(0x004ED29A), UINT32_C(0x004ED2A0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->edx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2B0));
    LIFT_PUSH3(SFERA_STATIC_00515F1C_ADDR, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2BE));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED2D8, UINT32_C(0x004ED2C4));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F1C_ADDR));
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
    cpu->edi = (uint32_t)(g_sfera_import_addresses[UINT32_C(0x0000015F)]);
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED377));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000FC130, UINT32_C(0x004FC130));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8F780_ADDR);
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC140(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC140;
    LIFT_BLOCK(label_000ED1A0, UINT32_C(0x004ED1A0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000006EA)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000020));
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_PUSH4(cpu->ebx, cpu->esi, cpu->edi, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    SFERA_STATIC_04F9006C_U32 = (uint32_t)(cpu->edx);
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
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F24_ADDR));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED21E));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED238, UINT32_C(0x004ED224));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F24_ADDR));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED238)));
    LIFT_BLOCK(label_000ED238, UINT32_C(0x004ED238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_INDEX(345u, UINT32_C(0x004ED23C), UINT32_C(0x004ED242));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_INDEX(344u, UINT32_C(0x004ED246), UINT32_C(0x004ED24C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_00515F08_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->eax);
    LIFT_IMPORT_INDEX(347u, UINT32_C(0x004ED258), UINT32_C(0x004ED25E));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->ecx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED26E));
    LIFT_PUSH3(SFERA_STATIC_005002E0_ADDR, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED27C));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED296, UINT32_C(0x004ED282));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_005002E0_ADDR));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED296)));
    LIFT_BLOCK(label_000ED296, UINT32_C(0x004ED296));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_INDEX(290u, UINT32_C(0x004ED29A), UINT32_C(0x004ED2A0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->edx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2B0));
    LIFT_PUSH3(SFERA_STATIC_00515F1C_ADDR, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2BE));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED2D8, UINT32_C(0x004ED2C4));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F1C_ADDR));
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
    cpu->edi = (uint32_t)(g_sfera_import_addresses[UINT32_C(0x0000015F)]);
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED377));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000FC140, UINT32_C(0x004FC140));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FAD8_ADDR);
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC150(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC150;
    LIFT_BLOCK(label_000ED1A0, UINT32_C(0x004ED1A0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), LIFT_CALLBACK_INDEX(UINT32_C(0x000006EA)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000020));
    cpu->eax = (uint32_t)(SFERA_STATIC_00525490_U32);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_PUSH4(cpu->ebx, cpu->esi, cpu->edi, cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    SFERA_STATIC_04F9006C_U32 = (uint32_t)(cpu->edx);
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
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F24_ADDR));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED21E));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED238, UINT32_C(0x004ED224));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F24_ADDR));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED238)));
    LIFT_BLOCK(label_000ED238, UINT32_C(0x004ED238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_INDEX(345u, UINT32_C(0x004ED23C), UINT32_C(0x004ED242));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_INDEX(344u, UINT32_C(0x004ED246), UINT32_C(0x004ED24C));
    LIFT_PUSH2(cpu->eax, SFERA_STATIC_00515F08_ADDR);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->eax);
    LIFT_IMPORT_INDEX(347u, UINT32_C(0x004ED258), UINT32_C(0x004ED25E));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->ecx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED26E));
    LIFT_PUSH3(SFERA_STATIC_005002E0_ADDR, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED27C));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED296, UINT32_C(0x004ED282));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_005002E0_ADDR));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED296)));
    LIFT_BLOCK(label_000ED296, UINT32_C(0x004ED296));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_INDEX(290u, UINT32_C(0x004ED29A), UINT32_C(0x004ED2A0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_PUSH3(cpu->edx, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2B0));
    LIFT_PUSH3(SFERA_STATIC_00515F1C_ADDR, cpu->edi, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED2BE));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED2D8, UINT32_C(0x004ED2C4));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_00515F1C_ADDR));
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
    cpu->edi = (uint32_t)(g_sfera_import_addresses[UINT32_C(0x0000015F)]);
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED377));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000FC150, UINT32_C(0x004FC150));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FDA0_ADDR);
    goto label_000ED1A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004FC15A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC15A;
    LIFT_BLOCK(label_000EF606, UINT32_C(0x004EF606));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000004)));
    cpu->eax = (uint32_t)(LIFT_CALLBACK_INDEX(UINT32_C(0x000006EC)));
    LIFT_CALL_ENTER(sfera_sub_004EF781, UINT32_C(0x004EF612));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_IMPORT_INDEX(389u, UINT32_C(0x004EF617), UINT32_C(0x004EF61D));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    goto label_000EF63A;
    LIFT_BLOCK(label_000EF623, UINT32_C(0x004EF623));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi);
    SFERA_STATIC_04F9076C_U32 = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EF5C6, UINT32_C(0x004EF633));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004EF639));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EF63A, UINT32_C(0x004EF63A));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F9076C_U32);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EF623, UINT32_C(0x004EF643));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0xFFFFFFFF), |, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_IMPORT_INDEX(391u, UINT32_C(0x004EF64A), UINT32_C(0x004EF650));
    LIFT_CALL_ENTER(sfera_sub_004EF7B4, UINT32_C(0x004EF655));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000FC15A, UINT32_C(0x004FC15A));
    cpu->ecx = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F90770_ADDR);
    goto label_000EF606;
}
