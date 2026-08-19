#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EB520(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EB520));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x0000001C));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    (void)0; /* source SEH registration eliminated */
    cpu->edi = (uint32_t)(cpu->edx);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_CMP(cpu->esi, cpu->ebx, 32u);
    LIFT_JZ(label_000EB884, UINT32_C(0x004EB556));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000001));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), cpu->ebx);
    LIFT_CMP(SFERA_STATIC_04F90414_U8, (cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB57A, UINT32_C(0x004EB568));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_InitializeCriticalSection, UINT32_C(0x004EB56D), UINT32_C(0x004EB573));
    SFERA_STATIC_04F90414_U8 = (uint8_t)(UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EB57A, UINT32_C(0x004EB57A));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_EnterCriticalSection, UINT32_C(0x004EB57F), UINT32_C(0x004EB585));
    SFERA_STATIC_04F90415_U8 = (uint8_t)(UINT32_C(0x00000001));
    LIFT_CMP(SFERA_STATIC_04F8F770_U8, UINT32_C(0x00000000), 8u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    LIFT_JNZ(label_000EB5BE, UINT32_C(0x004EB598));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"free2: test system not initialized"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), UINT32_C(0x000001E4));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB5BB));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EB5BE, UINT32_C(0x004EB5BE));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH3(UINT32_C(0x00000001), cpu->ebx, cpu->edi);
    cpu->edx = (uint32_t)(UINT32_C(0x00000005));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000A)));
    cpu->ecx = (uint32_t)(cpu->edx);
    LIFT_CALL_ENTER(sfera_sub_004EB1D0, UINT32_C(0x004EB5D3));
    LIFT_ADD(cpu->esi, UINT32_C(0xFFFFFFFC), 0u, 32u, cpu->esi = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4D760_ADDR);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EDDF0, UINT32_C(0x004EB5E4));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EB61A, UINT32_C(0x004EB5EC));
    LIFT_PUSH3(cpu->esi, cpu->ebx, cpu->edi);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Free of wrong pointer or double free. %s %d %d"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), UINT32_C(0x000000DB));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000001));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB612));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    goto label_000EB868;
    LIFT_BLOCK(label_000EB61A, UINT32_C(0x004EB61A));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F4D760_U32);
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_LOAD32(cpu->ecx, cpu->eax + cpu->edx + UINT32_C(0x00000008));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax + cpu->edx + UINT32_C(0x00000004))));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + cpu->eax + UINT32_C(0x00000004)))), UINT32_C(0x61CCC864), 32u);
    LIFT_STORE8(cpu->ebp + UINT32_C(0x0000000B), (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax))), UINT32_C(0x61CCC864), 32u);
    LIFT_JZ(label_000EB6DD, UINT32_C(0x004EB645));
    LIFT_STORE32(cpu->eax, UINT32_C(0x61CCC864));
    cpu->eax = (uint32_t)(cpu->edi);
    SFERA_STATIC_04F8F771_U8 = (uint8_t)(UINT32_C(0x00000001));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000EB657, UINT32_C(0x004EB657));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB657, UINT32_C(0x004EB65E));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JS_GOTO(label_000EB66C);
    LIFT_BLOCK(label_000EB663, UINT32_C(0x004EB663));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + cpu->edi))), UINT32_C(0x0000005C), 8u);
    LIFT_JZ(label_000EB66C, UINT32_C(0x004EB669));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EB663);
    LIFT_BLOCK(label_000EB66C, UINT32_C(0x004EB66C));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F90068_U8);
    LIFT_PUSH4(cpu->edx, ((uint32_t)(uintptr_t)"\n"), cpu->ebx, ((uint32_t)(uintptr_t)" "));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax + cpu->edi + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)". "));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EB68E));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"free: MEM CORRUPTED! "));
    LIFT_PUSH3(cpu->eax, ((uint32_t)(uintptr_t)" (underflow). "), cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8F780_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB6A5));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB6AC));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB6B3));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB6BA));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB6C1));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB6C8));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED390, UINT32_C(0x004EB6CF));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB6D6));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL(sfera_sub_004ED380, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EB6DD)));
    LIFT_BLOCK(label_000EB6DD, UINT32_C(0x004EB6DD));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x0000000B)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EB789, UINT32_C(0x004EB6E7));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_STORE32(cpu->edx + cpu->eax + UINT32_C(0x00000004), UINT32_C(0x61CCC864));
    cpu->eax = (uint32_t)(cpu->edi);
    SFERA_STATIC_04F8F771_U8 = (uint8_t)(UINT32_C(0x00000001));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000EB700, UINT32_C(0x004EB700));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB700, UINT32_C(0x004EB707));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JS(label_000EB719, UINT32_C(0x004EB70C));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EB710, UINT32_C(0x004EB710));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + cpu->edi))), UINT32_C(0x0000005C), 8u);
    LIFT_JZ(label_000EB719, UINT32_C(0x004EB716));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EB710);
    LIFT_BLOCK(label_000EB719, UINT32_C(0x004EB719));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F90068_U8);
    LIFT_PUSH4(cpu->ecx, ((uint32_t)(uintptr_t)"\n"), cpu->ebx, ((uint32_t)(uintptr_t)" "));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + cpu->edi + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->edx, ((uint32_t)(uintptr_t)". "));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EB73B));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)"free: MEM CORRUPTED! "));
    LIFT_PUSH2(((uint32_t)(uintptr_t)" (overflow). "), cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8F780_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB751));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB758));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB75F));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB766));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB76D));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB774));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED390, UINT32_C(0x004EB77B));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EB782));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL(sfera_sub_004ED380, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EB789)));
    LIFT_BLOCK(label_000EB789, UINT32_C(0x004EB789));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4D760_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EDE50, UINT32_C(0x004EB797));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB7C1, UINT32_C(0x004EB79B));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"validate_and_remove_pointer: pointer not in hash"), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), UINT32_C(0x000000E9));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB7BE));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EB7C1, UINT32_C(0x004EB7C1));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_CMP(cpu->eax, g_sfera_memory_runtime.tracker_floor, 32u);
    LIFT_JNZ(label_000EB7D5, UINT32_C(0x004EB7CC));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    g_sfera_memory_runtime.tracker_floor = (uint32_t)(cpu->ecx);
    LIFT_BLOCK(label_000EB7D5, UINT32_C(0x004EB7D5));
    LIFT_CMP(cpu->eax, g_sfera_memory_runtime.tracker_ceiling, 32u);
    LIFT_JNZ(label_000EB7E6, UINT32_C(0x004EB7DD));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x0000000C));
    g_sfera_memory_runtime.tracker_ceiling = (uint32_t)(cpu->edx);
    LIFT_BLOCK(label_000EB7E6, UINT32_C(0x004EB7E6));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EB802, UINT32_C(0x004EB7F0));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F4D760_U32);
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    goto label_000EB80A;
    LIFT_BLOCK(label_000EB802, UINT32_C(0x004EB802));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->eax);
    LIFT_BLOCK(label_000EB80A, UINT32_C(0x004EB80A));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EB826, UINT32_C(0x004EB814));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F4D760_U32);
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x0000000C), cpu->ecx);
    goto label_000EB82E;
    LIFT_BLOCK(label_000EB826, UINT32_C(0x004EB826));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->eax);
    LIFT_BLOCK(label_000EB82E, UINT32_C(0x004EB82E));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8E770_ADDR))), 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8E770_ADDR)), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8E770_ADDR)));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8D770_ADDR))), cpu->ecx, 0u, 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8D770_ADDR)), (uint32_t)(result)););
    LIFT_DEC(SFERA_STATIC_04F8F774_U32, 32u, lift_store32(((uint32_t)(SFERA_STATIC_04F8F774_ADDR)), (uint32_t)(result)););
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8D770_ADDR)));
    LIFT_BLOCK(label_000EB868, UINT32_C(0x004EB868));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_free, UINT32_C(0x004EB869), UINT32_C(0x004EB86F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    SFERA_STATIC_04F90415_U8 = (uint8_t)(UINT32_C(0x00000000));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_LeaveCriticalSection, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EB87E)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EB884));
    LIFT_BLOCK(label_000EB884, UINT32_C(0x004EB884));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EB8A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EB8A0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    (void)0; /* source SEH registration eliminated */
    cpu->edi = (uint32_t)(cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->edi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_CMP(cpu->esi, cpu->ebx, 32u);
    LIFT_JNZ(label_000EB8FB, UINT32_C(0x004EB8D5));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EB300, UINT32_C(0x004EB8E7));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(12u, cpu->ebp);
    LIFT_BLOCK(label_000EB8FB, UINT32_C(0x004EB8FB));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x00000001));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->ebx);
    LIFT_CMP(SFERA_STATIC_04F90414_U8, (cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB91F, UINT32_C(0x004EB90D));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_InitializeCriticalSection, UINT32_C(0x004EB912), UINT32_C(0x004EB918));
    SFERA_STATIC_04F90414_U8 = (uint8_t)(UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EB91F, UINT32_C(0x004EB91F));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_EnterCriticalSection, UINT32_C(0x004EB924), UINT32_C(0x004EB92A));
    SFERA_STATIC_04F90415_U8 = (uint8_t)(UINT32_C(0x00000001));
    LIFT_CMP(SFERA_STATIC_04F8F770_U8, UINT32_C(0x00000000), 8u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    LIFT_JNZ(label_000EB95F, UINT32_C(0x004EB93D));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00001388)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4D760_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EDD40, UINT32_C(0x004EB94C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000032)));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4CF50_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EDA60, UINT32_C(0x004EB958));
    SFERA_STATIC_04F8F770_U8 = (uint8_t)(UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EB95F, UINT32_C(0x004EB95F));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_PUSH3(UINT32_C(0x00000001), cpu->edx, cpu->ebx);
    cpu->edx = (uint32_t)(UINT32_C(0x00000005));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000A)));
    cpu->ecx = (uint32_t)(cpu->edx);
    LIFT_CALL_ENTER(sfera_sub_004EB1D0, UINT32_C(0x004EB977));
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JG(label_000EB9A2, UINT32_C(0x004EB97B));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"realloc2: Wrong size value. Size = %d"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000001FB));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB99F));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EB9A2, UINT32_C(0x004EB9A2));
    LIFT_ADD(cpu->esi, UINT32_C(0xFFFFFFFC), 0u, 32u, cpu->esi = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4D760_ADDR);
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000008), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EDDF0, UINT32_C(0x004EB9B3));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EB9E5, UINT32_C(0x004EB9BA));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"realloc2 with wrong pointer"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000000DE));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB9DD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    goto label_000EBC39;
    LIFT_BLOCK(label_000EB9E5, UINT32_C(0x004EB9E5));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4D760_U32);
    cpu->edx = (uint32_t)(cpu->edi);
    LIFT_IMUL32(cpu->edx, UINT32_C(0x0000001A));
    LIFT_LOAD32(cpu->ecx, cpu->edx + cpu->eax + UINT32_C(0x00000008));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->edx + cpu->eax + UINT32_C(0x00000004))));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax + cpu->ecx + UINT32_C(0x00000004)))), UINT32_C(0x61CCC864), 32u);
    LIFT_STORE8(cpu->ebp + UINT32_C(0x0000000F), (((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax))), UINT32_C(0x61CCC864), 32u);
    LIFT_JZ(label_000EBAAC, UINT32_C(0x004EBA11));
    LIFT_STORE32(cpu->eax, UINT32_C(0x61CCC864));
    cpu->eax = (uint32_t)(cpu->ebx);
    SFERA_STATIC_04F8F771_U8 = (uint8_t)(UINT32_C(0x00000001));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000EBA23, UINT32_C(0x004EBA23));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EBA23, UINT32_C(0x004EBA2A));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JS(label_000EBA39, UINT32_C(0x004EBA2F));
    (void)cpu;
    LIFT_BLOCK(label_000EBA30, UINT32_C(0x004EBA30));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + cpu->ebx))), UINT32_C(0x0000005C), 8u);
    LIFT_JZ(label_000EBA39, UINT32_C(0x004EBA36));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EBA30);
    LIFT_BLOCK(label_000EBA39, UINT32_C(0x004EBA39));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F90068_U8);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_PUSH4(cpu->edx, ((uint32_t)(uintptr_t)"\n"), cpu->ecx, ((uint32_t)(uintptr_t)" "));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + cpu->ebx + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->edx, ((uint32_t)(uintptr_t)". "));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EBA5E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)"realloc: MEM CORRUPTED! "));
    LIFT_PUSH2(((uint32_t)(uintptr_t)" (underflow). "), cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8F780_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBA74));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBA7B));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBA82));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBA89));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBA90));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBA97));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED390, UINT32_C(0x004EBA9E));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBAA5));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL(sfera_sub_004ED380, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EBAAC)));
    LIFT_BLOCK(label_000EBAAC, UINT32_C(0x004EBAAC));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x0000000F)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EBB5D, UINT32_C(0x004EBAB6));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebx);
    LIFT_STORE32(cpu->ecx + cpu->edx + UINT32_C(0x00000004), UINT32_C(0x61CCC864));
    SFERA_STATIC_04F8F771_U8 = (uint8_t)(UINT32_C(0x00000001));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    (void)cpu;
    LIFT_BLOCK(label_000EBAD0, UINT32_C(0x004EBAD0));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EBAD0, UINT32_C(0x004EBAD7));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JS(label_000EBAE9, UINT32_C(0x004EBADC));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EBAE0, UINT32_C(0x004EBAE0));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + cpu->ebx))), UINT32_C(0x0000005C), 8u);
    LIFT_JZ(label_000EBAE9, UINT32_C(0x004EBAE6));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EBAE0);
    LIFT_BLOCK(label_000EBAE9, UINT32_C(0x004EBAE9));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F90068_U8);
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_PUSH4(cpu->ecx, ((uint32_t)(uintptr_t)"\n"), cpu->edx, ((uint32_t)(uintptr_t)" "));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax + cpu->ebx + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)". "));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EBB0E));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"realloc: MEM CORRUPTED! "));
    LIFT_PUSH3(cpu->eax, ((uint32_t)(uintptr_t)" (overflow). "), cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8F780_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBB25));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBB2C));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBB33));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBB3A));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBB41));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBB48));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED390, UINT32_C(0x004EBB4F));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EBB56));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL(sfera_sub_004ED380, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EBB5D)));
    LIFT_BLOCK(label_000EBB5D, UINT32_C(0x004EBB5D));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4D760_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EDE50, UINT32_C(0x004EBB6B));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EBB95, UINT32_C(0x004EBB6F));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"validate_and_remove_pointer: pointer not in hash"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000000E9));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EBB92));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EBB95, UINT32_C(0x004EBB95));
    LIFT_CMP(cpu->edi, g_sfera_memory_runtime.tracker_floor, 32u);
    LIFT_JNZ(label_000EBBA6, UINT32_C(0x004EBB9D));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    g_sfera_memory_runtime.tracker_floor = (uint32_t)(cpu->ecx);
    LIFT_BLOCK(label_000EBBA6, UINT32_C(0x004EBBA6));
    LIFT_CMP(cpu->edi, g_sfera_memory_runtime.tracker_ceiling, 32u);
    LIFT_JNZ(label_000EBBB7, UINT32_C(0x004EBBAE));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x0000000C));
    g_sfera_memory_runtime.tracker_ceiling = (uint32_t)(cpu->edx);
    LIFT_BLOCK(label_000EBBB7, UINT32_C(0x004EBBB7));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EBBD3, UINT32_C(0x004EBBC1));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F4D760_U32);
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    goto label_000EBBDB;
    LIFT_BLOCK(label_000EBBD3, UINT32_C(0x004EBBD3));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->eax);
    LIFT_BLOCK(label_000EBBDB, UINT32_C(0x004EBBDB));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EBBF7, UINT32_C(0x004EBBE5));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F4D760_U32);
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x0000000C), cpu->ecx);
    goto label_000EBBFF;
    LIFT_BLOCK(label_000EBBF7, UINT32_C(0x004EBBF7));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->eax);
    LIFT_BLOCK(label_000EBBFF, UINT32_C(0x004EBBFF));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8E770_ADDR))), 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8E770_ADDR)), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8E770_ADDR)));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8D770_ADDR))), cpu->ecx, 0u, 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8D770_ADDR)), (uint32_t)(result)););
    LIFT_DEC(SFERA_STATIC_04F8F774_U32, 32u, lift_store32(((uint32_t)(SFERA_STATIC_04F8F774_ADDR)), (uint32_t)(result)););
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + SFERA_STATIC_04F8D770_ADDR)));
    LIFT_BLOCK(label_000EBC39, UINT32_C(0x004EBC39));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0x00000008))));
    LIFT_PUSH2(cpu->edx, cpu->esi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_realloc, UINT32_C(0x004EBC41), UINT32_C(0x004EBC47));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JNZ(label_000EBC77, UINT32_C(0x004EBC50));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"realloc2: Not enough memory. Request size = %d"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000203));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EBC74));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EBC77, UINT32_C(0x004EBC77));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esi, UINT32_C(0x61CCC864));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4D760_ADDR);
    LIFT_STORE32(cpu->esi + cpu->edi + UINT32_C(0x00000004), UINT32_C(0x61CCC864));
    LIFT_STORE32(cpu->ebp + UINT32_C(0x0000000C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EDEF0, UINT32_C(0x004EBC9B));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JNS(label_000EBCC7, UINT32_C(0x004EBCA1));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"store_pointer: pointer already in hash"), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), ((uint32_t)(uintptr_t)"Memory\\MemoryMgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000000FE));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EBCC4));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EBCC7, UINT32_C(0x004EBCC7));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F4CF50_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004EDC70, UINT32_C(0x004EBCD2));
    cpu->edx = (uint32_t)(g_sfera_memory_runtime.tracker_primary);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    cpu->eax = (uint32_t)((cpu->eax & UINT32_C(0xFFFF)));
    LIFT_CMP(cpu->edx, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EBCFB, UINT32_C(0x004EBCE6));
    cpu->ebx = (uint32_t)(SFERA_STATIC_04F4D760_U32);
    LIFT_IMUL32(cpu->edx, UINT32_C(0x0000001A));
    LIFT_STORE32(cpu->edx + cpu->ebx + UINT32_C(0x0000000C), cpu->edi);
    cpu->edx = (uint32_t)(g_sfera_memory_runtime.tracker_primary);
    goto label_000EBD01;
    LIFT_BLOCK(label_000EBCFB, UINT32_C(0x004EBCFB));
    g_sfera_memory_runtime.tracker_auxiliary = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EBD01, UINT32_C(0x004EBD01));
    LIFT_STORE32(cpu->ecx + UINT32_C(0x0000000C), cpu->edx);
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000008), UINT32_C(0x3B9ACA00));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000004), cpu->ecx);
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_STORE16(cpu->edx + UINT32_C(0x00000014), (cpu->eax & UINT32_C(0xFFFF)));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    g_sfera_memory_runtime.tracker_primary = (uint32_t)(cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000010));
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->edi);
    LIFT_ADD(cpu->eax, cpu->eax, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(lift_load32(((uint32_t)(cpu->eax + cpu->eax + SFERA_STATIC_04F8D770_ADDR))), cpu->ecx, 0u, 32u, lift_store32(((uint32_t)(cpu->eax + cpu->eax + SFERA_STATIC_04F8D770_ADDR)), (uint32_t)(result)););
    LIFT_ADD(cpu->eax, cpu->eax, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edx = (uint32_t)(UINT32_C(0x00000001));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->eax + SFERA_STATIC_04F8E770_ADDR))), cpu->edx, 0u, 32u, lift_store32(((uint32_t)(cpu->eax + SFERA_STATIC_04F8E770_ADDR)), (uint32_t)(result)););
    LIFT_ADD(SFERA_STATIC_04F8F774_U32, cpu->edx, 0u, 32u, lift_store32(((uint32_t)(SFERA_STATIC_04F8F774_ADDR)), (uint32_t)(result)););
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    SFERA_STATIC_04F90415_U8 = (uint8_t)(UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_LeaveCriticalSection, UINT32_C(0x004EBD5C), UINT32_C(0x004EBD62));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000004))));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(12u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBD80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBD80));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    (void)0; /* source SEH registration eliminated */
    LIFT_CMP(SFERA_STATIC_04F90414_U8, UINT32_C(0x00000000), 8u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_JNZ(label_000EBDC7, UINT32_C(0x004EBDB5));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_InitializeCriticalSection, UINT32_C(0x004EBDBA), UINT32_C(0x004EBDC0));
    SFERA_STATIC_04F90414_U8 = (uint8_t)(UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EBDC7, UINT32_C(0x004EBDC7));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_TryEnterCriticalSection, UINT32_C(0x004EBDCC), UINT32_C(0x004EBDD2));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EBE07, UINT32_C(0x004EBDE1));
    LIFT_CMP(SFERA_STATIC_04F90415_U8, UINT32_C(0x00000000), 8u);
    LIFT_JNZ(label_000EBDFC, UINT32_C(0x004EBDEA));
    LIFT_PUSH3(UINT32_C(0x00000000), ((uint32_t)(uintptr_t)"verify before terminate"), UINT32_C(0xFFFFFFFF));
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CALL(sfera_sub_004EAA20, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EBDFC)));
    LIFT_BLOCK(label_000EBDFC, UINT32_C(0x004EBDFC));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F903FC_ADDR));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_LeaveCriticalSection, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EBE01)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EBE07));
    LIFT_BLOCK(label_000EBE07, UINT32_C(0x004EBE07));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBE20));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000EBE4F, UINT32_C(0x004EBE2A));
    cpu->eax = (uint32_t)(g_sfera_memory_runtime.allocation_source_line);
    cpu->edx = (uint32_t)(g_sfera_memory_runtime.allocation_source_file);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004EBE3B));
    g_sfera_memory_runtime.allocation_source_file = (uint32_t)(((uint32_t)(uintptr_t)"Unknown"));
    g_sfera_memory_runtime.allocation_source_line = (uint32_t)(UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EBE4F, UINT32_C(0x004EBE4F));
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBE60));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->eax, cpu->edx);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_CALL_ENTER(sfera_sub_004EB300, UINT32_C(0x004EBE6F));
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBE80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBE80));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->eax, UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EB8A0, UINT32_C(0x004EBE92));
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBEA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBEA0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    cpu->eax = (uint32_t)(g_sfera_memory_runtime.allocation_source_line);
    cpu->ecx = (uint32_t)(g_sfera_memory_runtime.allocation_source_file);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_ZERO(cpu->edx, 32u);
    cpu->ecx = (uint32_t)(cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EB300, UINT32_C(0x004EBEBE));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_PUSH2(UINT32_C(0x00000000), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004EBEC9));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    cpu->eax = (uint32_t)(cpu->esi);
    g_sfera_memory_runtime.allocation_source_file = (uint32_t)(((uint32_t)(uintptr_t)"Unknown"));
    g_sfera_memory_runtime.allocation_source_line = (uint32_t)(UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBEF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBEF0));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F8FACC_U32);
    LIFT_PUSH3(cpu->esi, cpu->edi, cpu->eax);
    cpu->esi = (uint32_t)(cpu->edx);
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"%d ")));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_snprintf, UINT32_C(0x004EBF03), UINT32_C(0x004EBF09));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_STORE8(cpu->edi + cpu->esi + UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->edi, cpu->esi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBF20));
    SFERA_STATIC_04F8FAD0_U32 = (uint32_t)(cpu->ecx);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBF30));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_printf, UINT32_C(0x004EBF31), UINT32_C(0x004EBF37));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), (cpu->eax & UINT32_C(0xFF)), ^, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EBF40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBF40));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    cpu->eax = (uint32_t)(UINT32_C(0x00001204));
    LIFT_CALL_ENTER(sfera_sub_004EEAF0, UINT32_C(0x004EBF4D));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(UINT32_C(0x00000014));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFEE0C))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFEDFC), ((uint32_t)(uintptr_t)"stackdump.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFEE00), ((uint32_t)(uintptr_t)"errorsmgr.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFEE04), ((uint32_t)(uintptr_t)"crt0.c"));
    LIFT_CALL_ENTER(sfera_sub_004EE2C0, UINT32_C(0x004EBF86));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFF6CC), UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE(label_000EC06D, UINT32_C(0x004EBF95));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFEE30))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFEE08), cpu->eax);
    LIFT_BLOCK(label_000EBFA4, UINT32_C(0x004EBFA4));
    LIFT_ZERO(cpu->esi, 32u);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebx + UINT32_C(0xFFFFFFDC))));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EBFB0, UINT32_C(0x004EBFB0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + ((uint32_t)(cpu->esi) * 4u) + UINT32_C(0xFFFFEDFC));
    LIFT_PUSH2(cpu->edi, cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_stricmp, UINT32_C(0x004EBFB9), UINT32_C(0x004EBFBF));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EBFCE, UINT32_C(0x004EBFC6));
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_CMP(cpu->esi, UINT32_C(0x00000003), 32u);
    LIFT_JL(label_000EBFB0, UINT32_C(0x004EBFCC));
    goto label_000EBFD3;
    LIFT_BLOCK(label_000EBFCE, UINT32_C(0x004EBFCE));
    LIFT_CMP(cpu->esi, UINT32_C(0x00000003), 32u);
    LIFT_JL_GOTO(label_000EC026);
    LIFT_BLOCK(label_000EBFD3, UINT32_C(0x004EBFD3));
    LIFT_LOAD32(cpu->ecx, cpu->ebx + UINT32_C(0x00000048));
    LIFT_LOAD32(cpu->edx, cpu->ebx + UINT32_C(0x00000044));
    LIFT_LOAD32(cpu->eax, cpu->ebx + UINT32_C(0xFFFFFFFC));
    LIFT_PUSH6(cpu->ecx, cpu->edx, cpu->ebx, cpu->eax, cpu->edi, ((uint32_t)(uintptr_t)"(%s:%u)\t(%hs+%I64X)\n"));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF8C))));
    LIFT_PUSH2(UINT32_C(0x0000006F), cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_snprintf, UINT32_C(0x004EBFEC), UINT32_C(0x004EBFF2));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF8C))));
    LIFT_SP_ADD(UINT32_C(0x00000020));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFB), UINT32_C(0x00000000));
    cpu->esi = (uint32_t)(cpu->eax);
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EC000, UINT32_C(0x004EC000));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC000, UINT32_C(0x004EC007));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF6CC))));
    LIFT_SUB(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_BLOCK(label_000EC010, UINT32_C(0x004EC010));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->edi + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC010, UINT32_C(0x004EC018));
    cpu->ecx = (uint32_t)(cpu->eax);
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000002)), 32u));
    lift_movs32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOGIC(cpu->ecx, UINT32_C(0x00000003), &, 32u, cpu->ecx = (uint32_t)(result););
    lift_movs8(cpu, 1u);
    LIFT_BLOCK(label_000EC026, UINT32_C(0x004EC026));
    LIFT_ADD(cpu->ebx, UINT32_C(0x00000070), 0u, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_DEC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFEE08)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFEE08))), (uint32_t)(result)););
    LIFT_JNZ(label_000EBFA4, UINT32_C(0x004EC035));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF6CC)))), UINT32_C(0x00000000), 8u);
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_JZ(label_000EC06D, UINT32_C(0x004EC041));
    cpu->edx = (uint32_t)(SFERA_STATIC_04F90068_U8);
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF6CC))));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"Stack:\n"));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FDA0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EC05F));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EC066));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL(sfera_sub_004ED380, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC06D)));
    LIFT_BLOCK(label_000EC06D, UINT32_C(0x004EC06D));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F8FAD0_U32);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EC07D, UINT32_C(0x004EC076));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FDA0_ADDR);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC07D)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC07B)))) { return; }
    LIFT_BLOCK(label_000EC07D, UINT32_C(0x004EC07D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC087));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC090(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC090));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000010));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_PUSH2(((uint32_t)(uintptr_t)"critLogTmp.$$$"), cpu->edi);
    cpu->esi = (uint32_t)(cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004EC0AD), UINT32_C(0x004EC0B3));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC1A6, UINT32_C(0x004EC0BE));
    LIFT_PUSH3(cpu->eax, UINT32_C(0x00008000), ((uint32_t)(uintptr_t)"critLogTmp.$$$"));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z, UINT32_C(0x004EC0C9), UINT32_C(0x004EC0CF));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EC0ED, UINT32_C(0x004EC0D9));
    LIFT_PUSH2(cpu->edi, ((uint32_t)(uintptr_t)"critLogTmp.$$$"));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004EC0DF), UINT32_C(0x004EC0E5));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    goto label_000EC1A6;
    LIFT_BLOCK(label_000EC0ED, UINT32_C(0x004EC0ED));
    LIFT_PUSH3(UINT32_C(0x00000180), UINT32_C(0x00008302), cpu->edi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z, UINT32_C(0x004EC0F8), UINT32_C(0x004EC0FE));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EC11F, UINT32_C(0x004EC109));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_close, UINT32_C(0x004EC10A), UINT32_C(0x004EC110));
    LIFT_PUSH2(cpu->edi, ((uint32_t)(uintptr_t)"critLogTmp.$$$"));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004EC116), UINT32_C(0x004EC11C));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC11F, UINT32_C(0x004EC11F));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EEA10, UINT32_C(0x004EC126));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->esp);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE(label_000EC189, UINT32_C(0x004EC137));
    cpu->edi = (uint32_t)(cpu->esi);
    LIFT_IMUL32(cpu->edi, cpu->eax);
    LIFT_NEG(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EC140, UINT32_C(0x004EC140));
    LIFT_PUSH3(UINT32_C(0x00000002), cpu->edi, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_lseek, UINT32_C(0x004EC144), UINT32_C(0x004EC14A));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EC189, UINT32_C(0x004EC152));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_PUSH3(cpu->esi, cpu->eax, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_read, UINT32_C(0x004EC158), UINT32_C(0x004EC15E));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EC189, UINT32_C(0x004EC165));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_PUSH3(cpu->esi, cpu->ecx, cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_write, UINT32_C(0x004EC16E), UINT32_C(0x004EC174));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EC189, UINT32_C(0x004EC17B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(cpu->edi, cpu->esi, 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), 32u);
    LIFT_JL_GOTO(label_000EC140);
    LIFT_BLOCK(label_000EC189, UINT32_C(0x004EC189));
    cpu->esi = (uint32_t)(SFERA_IMPORT_MSVCR100_close);
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC192)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC190)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC192));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC198)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC196)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC198));
    lift_push32(cpu, (uint32_t)(((uint32_t)(uintptr_t)"critLogTmp.$$$")));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_remove, UINT32_C(0x004EC19D), UINT32_C(0x004EC1A3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC1A6, UINT32_C(0x004EC1A6));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC1B6));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC1C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC1C0));
    g_sfera_memory_runtime.critical_error_callback = (uint32_t)(cpu->ecx);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JNZ(label_000EC1D4, UINT32_C(0x004EC1CA));
    g_sfera_memory_runtime.critical_error_callback = (uint32_t)(LIFT_CALLBACK_RVA(UINT32_C(0x000EBF30)));
    LIFT_BLOCK(label_000EC1D4, UINT32_C(0x004EC1D4));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC1E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC1E0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000040));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)"Criticals.log"));
    LIFT_PUSH4(cpu->ebx, cpu->esi, ((uint32_t)(uintptr_t)"at"), cpu->eax);
    cpu->ebx = (cpu->ebx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((cpu->edx & UINT32_C(0xFF))) & UINT32_C(0xFF));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFC8), cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fopen, UINT32_C(0x004EC202), UINT32_C(0x004EC208));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000EC2CC, UINT32_C(0x004EC215));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(SFERA_IMPORT_MSVCR100_fputs);
    LIFT_TEST((cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000EC273, UINT32_C(0x004EC220));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004EC224), UINT32_C(0x004EC22A));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC0))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_localtime64, UINT32_C(0x004EC22E), UINT32_C(0x004EC234));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"%d/%m/%y %H:%M:%S "));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strftime, UINT32_C(0x004EC240), UINT32_C(0x004EC246));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FACC_U32);
    LIFT_PUSH2(cpu->ecx, ((uint32_t)(uintptr_t)"%d "));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_snprintf, UINT32_C(0x004EC258), UINT32_C(0x004EC25E));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(cpu->esi, cpu->eax);
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFB), UINT32_C(0x00000000));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC269)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC267)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC269));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(cpu->esi, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC270)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC26E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC270));
    LIFT_SP_ADD(UINT32_C(0x00000038));
    LIFT_BLOCK(label_000EC273, UINT32_C(0x004EC273));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFC8));
    LIFT_PUSH2(cpu->esi, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC27A)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC278)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC27A));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EC28E, UINT32_C(0x004EC283));
    LIFT_PUSH2(cpu->esi, ((uint32_t)(uintptr_t)"\n"));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC28B)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC289)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC28B));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EC28E, UINT32_C(0x004EC28E));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fflush, UINT32_C(0x004EC28F), UINT32_C(0x004EC295));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_ftell, UINT32_C(0x004EC296), UINT32_C(0x004EC29C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fclose, UINT32_C(0x004EC29F), UINT32_C(0x004EC2A5));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EC2CB, UINT32_C(0x004EC2AE));
    LIFT_CMP(cpu->edi, UINT32_C(0x00108000), 32u);
    LIFT_JLE(label_000EC2CB, UINT32_C(0x004EC2B6));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"Criticals.log"));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000200)));
    cpu->edx = (uint32_t)(UINT32_C(0x00000800));
    LIFT_CALL(sfera_sub_004EC090, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC2CB)));
    LIFT_BLOCK(label_000EC2CB, UINT32_C(0x004EC2CB));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EC2CC, UINT32_C(0x004EC2CC));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC2D8));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC2E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC2E0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000083C));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    cpu->eax = (uint32_t)(SFERA_STATIC_04F8FAC8_U32);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(UINT32_C(0x00000001));
    LIFT_ADD(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->edi));
    SFERA_STATIC_04F8FAC8_U32 = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JLE(label_000EC3D0, UINT32_C(0x004EC30E));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000002), 32u);
    LIFT_JNZ(label_000EC3C1, UINT32_C(0x004EC317));
    cpu->eax = (uint32_t)(((uint32_t)(uintptr_t)"Criticals.log"));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"at"), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fopen, UINT32_C(0x004EC322), UINT32_C(0x004EC328));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000EC3BC, UINT32_C(0x004EC335));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7C4))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004EC33C), UINT32_C(0x004EC342));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7C4))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_localtime64, UINT32_C(0x004EC349), UINT32_C(0x004EC34F));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"%d/%m/%y %H:%M:%S "));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strftime, UINT32_C(0x004EC35B), UINT32_C(0x004EC361));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FACC_U32);
    LIFT_PUSH2(cpu->ecx, ((uint32_t)(uintptr_t)"%d "));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_snprintf, UINT32_C(0x004EC373), UINT32_C(0x004EC379));
    cpu->edi = (uint32_t)(SFERA_IMPORT_MSVCR100_fputs);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(cpu->esi, cpu->eax);
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFB), UINT32_C(0x00000000));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC38A)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC388)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC38A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(cpu->esi, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC391)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC38F)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC391));
    LIFT_PUSH2(cpu->esi, ((uint32_t)(uintptr_t)"Error processing reenter. Terminating"));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC399)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC397)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC399));
    LIFT_SP_ADD(UINT32_C(0x00000040));
    LIFT_PUSH2(cpu->esi, ((uint32_t)(uintptr_t)"\n"));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC3A4)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC3A2)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC3A4));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fflush, UINT32_C(0x004EC3A5), UINT32_C(0x004EC3AB));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_ftell, UINT32_C(0x004EC3AC), UINT32_C(0x004EC3B2));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fclose, UINT32_C(0x004EC3B3), UINT32_C(0x004EC3B9));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_BLOCK(label_000EC3BC, UINT32_C(0x004EC3BC));
    cpu->esi = (uint32_t)(UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EC3C1, UINT32_C(0x004EC3C1));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentProcess, UINT32_C(0x004EC3C3), UINT32_C(0x004EC3C9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_TerminateProcess, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC3CA)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC3D0));
    LIFT_BLOCK(label_000EC3D0, UINT32_C(0x004EC3D0));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F8FACC_U32);
    LIFT_ADD(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04F8FACC_U32 = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0x000003E8), 32u);
    LIFT_JNZ(label_000EC3ED, UINT32_C(0x004EC3E3));
    SFERA_STATIC_04F8FACC_U32 = (uint32_t)(UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EC3ED, UINT32_C(0x004EC3ED));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000010))));
    LIFT_PUSH2(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_PUSH2(UINT32_C(0x00000800), cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_vsnprintf, UINT32_C(0x004EC401), UINT32_C(0x004EC407));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFCB), UINT32_C(0x00000000));
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_BLOCK(label_000EC415, UINT32_C(0x004EC415));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->edi + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC415, UINT32_C(0x004EC41D));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->eax, cpu->eax + UINT32_C(0x00000008));
    LIFT_SUB(cpu->eax, UINT32_C(0x00000000), 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edx = (cpu->edx & UINT32_C(0xFFFF0000)) | ((uint32_t)(UINT16_C(0x000A)) & UINT32_C(0xFFFF));
    LIFT_STORE16(cpu->edi, (cpu->edx & UINT32_C(0xFFFF)));
    LIFT_JZ(label_000EC4D4, UINT32_C(0x004EC436));
    LIFT_SUB(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000EC47D, UINT32_C(0x004EC43A));
    LIFT_SUB(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNZ(label_000EC4E9, UINT32_C(0x004EC442));
    LIFT_PUSH2(cpu->esi, cpu->esi);
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_CALL_ENTER(sfera_sub_004EC1E0, UINT32_C(0x004EC451));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_PUSH2(cpu->ecx, cpu->edx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FDA0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004ED100, UINT32_C(0x004EC466));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CALL_ENTER(sfera_sub_004EBF40, UINT32_C(0x004EC46D));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_memory_runtime.critical_error_callback), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC47B)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC475)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC47B));
    goto label_000EC4B9;
    LIFT_BLOCK(label_000EC47D, UINT32_C(0x004EC47D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FDA0_ADDR);
    LIFT_CALL_ENTER(sfera_sub_004ED100, UINT32_C(0x004EC492));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CALL_ENTER(sfera_sub_004EBF40, UINT32_C(0x004EC499));
    LIFT_LOGIC((cpu->edx & UINT32_C(0xFF)), (cpu->edx & UINT32_C(0xFF)), ^, 8u, cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    if (!lift_call_indirect(cpu, (uint32_t)(g_sfera_memory_runtime.critical_error_callback), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC4A7)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC4A1)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC4A7));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC4E9, UINT32_C(0x004EC4AB));
    LIFT_PUSH2(cpu->esi, cpu->esi);
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"terminating cause of LERROR"));
    LIFT_CALL(sfera_sub_004EC1E0, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC4B9)));
    LIFT_BLOCK(label_000EC4B9, UINT32_C(0x004EC4B9));
    LIFT_CALL_ENTER(sfera_sub_004EBD80, UINT32_C(0x004EC4BE));
    LIFT_CALL_ENTER(sfera_sub_004ED150, UINT32_C(0x004EC4C3));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentProcess, UINT32_C(0x004EC4C5), UINT32_C(0x004EC4CB));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_TerminateProcess, UINT32_C(0x004EC4CC), UINT32_C(0x004EC4D2));
    goto label_000EC4E9;
    LIFT_BLOCK(label_000EC4D4, UINT32_C(0x004EC4D4));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_PUSH2(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F8FAD8_ADDR);
    LIFT_CALL(sfera_sub_004ED100, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC4E9)));
    LIFT_BLOCK(label_000EC4E9, UINT32_C(0x004EC4E9));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_SUB(SFERA_STATIC_04F8FAC8_U32, cpu->esi, 0u, 32u, lift_store32(((uint32_t)(SFERA_STATIC_04F8FAC8_ADDR)), (uint32_t)(result)););
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC4FB));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC500(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC500));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->esi);
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000001C));
    cpu->eax = (uint32_t)(cpu->ebx);
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000003)), 32u));
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->ecx = (uint32_t)((cpu->eax & UINT32_C(0xFF)));
    LIFT_PUSH2(cpu->ecx, cpu->edx);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE390, UINT32_C(0x004EC547));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_JLE(label_000EC583, UINT32_C(0x004EC554));
    LIFT_LOGIC_FLAGS((cpu->ebx & UINT32_C(0xFF)), UINT32_C(0x00000002), &, 8u);
    LIFT_JZ(label_000EC583, UINT32_C(0x004EC559));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Log::Log: trunc log %s and dayly files are mutualy exclusive capabilities."), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), ((uint32_t)(uintptr_t)"Logs\\Log.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x0000001F));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC580));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC583, UINT32_C(0x004EC583));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EC590, UINT32_C(0x004EC590));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC590, UINT32_C(0x004EC597));
    cpu->ebx = (uint32_t)(SFERA_IMPORT_MSVCR100_malloc);
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC5A5)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC5A3)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC5A5));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC5D6, UINT32_C(0x004EC5AF));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Log::Log: Not enough memory. Len = %d"), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), ((uint32_t)(uintptr_t)"Logs\\Log.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x00000023));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC5D3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC5D6, UINT32_C(0x004EC5D6));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EC5E0, UINT32_C(0x004EC5E0));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->edx, (cpu->eax & UINT32_C(0xFF)));
    LIFT_INC(cpu->ecx, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC5E0, UINT32_C(0x004EC5EA));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC5F6, UINT32_C(0x004EC5F1));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000000C), cpu->eax);
    goto label_000EC650;
    LIFT_BLOCK(label_000EC5F6, UINT32_C(0x004EC5F6));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EC600, UINT32_C(0x004EC600));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC600, UINT32_C(0x004EC607));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC60F)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC60D)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC60F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000000C), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC640, UINT32_C(0x004EC619));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Log::Log: Not enough memory. Len = %d"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), ((uint32_t)(uintptr_t)"Logs\\Log.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x0000002D));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC63D));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC640, UINT32_C(0x004EC640));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC646, UINT32_C(0x004EC646));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->edx, (cpu->eax & UINT32_C(0xFF)));
    LIFT_INC(cpu->ecx, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ_GOTO(label_000EC646);
    LIFT_BLOCK(label_000EC650, UINT32_C(0x004EC650));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x0000001C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000018));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000001C), UINT32_C(0x000001F4));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), cpu->ecx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->edx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000020), cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000028), cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC672)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC670)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC672));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000024), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC6A3, UINT32_C(0x004EC67C));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Log::Log: Not enough memory. Len = %d"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), ((uint32_t)(uintptr_t)"Logs\\Log.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x00000038));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC6A0));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC6A3, UINT32_C(0x004EC6A3));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000024));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_STORE8(cpu->edx, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000002C), cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000030), cpu->eax);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014)))), cpu->eax, 32u);
    LIFT_JG(label_000EC6BB, UINT32_C(0x004EC6B6));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->eax);
    goto label_000EC6F7;
    LIFT_BLOCK(label_000EC6BB, UINT32_C(0x004EC6BB));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00002000)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC6C2)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC6C0)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC6C2));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC6F7, UINT32_C(0x004EC6CC));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00002000)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Log::Log: Not enough memory. Len = %d"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), ((uint32_t)(uintptr_t)"Logs\\Log.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x00000043));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC6F4));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC6F7, UINT32_C(0x004EC6F7));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000EC73A, UINT32_C(0x004EC6FD));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000030), cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC703)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC701)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC703));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000002C), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC734, UINT32_C(0x004EC70D));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Log::Log: Not enough memory. Len = %d"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), ((uint32_t)(uintptr_t)"Logs\\Log.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x0000004B));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC731));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC734, UINT32_C(0x004EC734));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x0000002C));
    LIFT_STORE8(cpu->edx, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EC73A, UINT32_C(0x004EC73A));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F9006C_U32);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->eax);
    SFERA_STATIC_04F9006C_U32 = (uint32_t)(cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EC757, UINT32_C(0x004EC755));
    LIFT_STORE32(cpu->eax, cpu->esi);
    LIFT_BLOCK(label_000EC757, UINT32_C(0x004EC757));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(24u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC770));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000010));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EC780, UINT32_C(0x004EC780));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC780, UINT32_C(0x004EC787));
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->esi);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EC7A0, UINT32_C(0x004EC7A0));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC7A0, UINT32_C(0x004EC7A7));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->ebx = (uint32_t)(cpu->eax);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ebx + cpu->esi + UINT32_C(0x00000001))));
    LIFT_CMP(cpu->esi, lift_load32(((uint32_t)(cpu->ecx))), 32u);
    LIFT_JLE(label_000EC7FA, UINT32_C(0x004EC7B6));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + cpu->esi)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_realloc, UINT32_C(0x004EC7BF), UINT32_C(0x004EC7C5));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->edi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC7FA, UINT32_C(0x004EC7CE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->edx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Log::append_realloc(): Not enough memory. Len = %d"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), ((uint32_t)(uintptr_t)"Logs\\Log.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), UINT32_C(0x00000127));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC7F7));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC7FA, UINT32_C(0x004EC7FA));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->eax, cpu->edi);
    LIFT_PUSH2(cpu->ecx, cpu->edx);
    LIFT_ADD(cpu->eax, cpu->ebx, 0u, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EE804, UINT32_C(0x004EC80C));
    LIFT_LOAD32(cpu->ecx, cpu->edi);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE8(cpu->ecx + cpu->esi + UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_POP2(cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(12u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC830));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, cpu->ecx + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(cpu->ebx);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->ecx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EC850, UINT32_C(0x004EC850));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC850, UINT32_C(0x004EC857));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->eax = (uint32_t)(cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EEA10, UINT32_C(0x004EC863));
    cpu->esi = (uint32_t)(cpu->esp);
    cpu->ecx = (uint32_t)(cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi);
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EC870, UINT32_C(0x004EC870));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->edx, (cpu->eax & UINT32_C(0xFF)));
    LIFT_INC(cpu->ecx, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC870, UINT32_C(0x004EC87A));
    LIFT_PUSH2(UINT32_C(0x00000180), cpu->esi);
    LIFT_STORE8(cpu->esi + cpu->edi + UINT32_C(0xFFFFFFFE), UINT32_C(0x00000024));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_chmod, UINT32_C(0x004EC885), UINT32_C(0x004EC88B));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_remove, UINT32_C(0x004EC88C), UINT32_C(0x004EC892));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_LOAD32(cpu->ecx, cpu->eax + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004EC89A), UINT32_C(0x004EC8A0));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC8B3));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC8C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC8C0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000002C));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004EC8DB), UINT32_C(0x004EC8E1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_localtime64, UINT32_C(0x004EC8E5), UINT32_C(0x004EC8EB));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"_%y%m%d"));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strftime, UINT32_C(0x004EC8F7), UINT32_C(0x004EC8FD));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_CMP((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x0000002E), 8u);
    LIFT_JZ(label_000EC923, UINT32_C(0x004EC90B));
    LIFT_BLOCK(label_000EC910, UINT32_C(0x004EC910));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000EC923, UINT32_C(0x004EC914));
    LIFT_STORE8(cpu->edi, (cpu->eax & UINT32_C(0xFF)));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->edx + cpu->ecx + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_CMP((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x0000002E), 8u);
    LIFT_JNZ_GOTO(label_000EC910);
    LIFT_BLOCK(label_000EC923, UINT32_C(0x004EC923));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    cpu->ebx = (uint32_t)(cpu->edi);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_SUB(cpu->ebx, cpu->ecx, 0u, 32u, cpu->ebx = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ecx)));
    LIFT_BLOCK(label_000EC930, UINT32_C(0x004EC930));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->ebx + cpu->eax, (cpu->ecx & UINT32_C(0xFF)));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC930, UINT32_C(0x004EC93A));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_ADD(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(cpu->eax);
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EC942, UINT32_C(0x004EC942));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->edx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC942, UINT32_C(0x004EC949));
    LIFT_SUB(cpu->eax, cpu->ecx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EC950, UINT32_C(0x004EC950));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->edi + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC950, UINT32_C(0x004EC958));
    cpu->ecx = (uint32_t)(cpu->eax);
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000002)), 32u));
    lift_movs32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOGIC(cpu->ecx, UINT32_C(0x00000003), &, 32u, cpu->ecx = (uint32_t)(result););
    lift_movs8(cpu, 1u);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC972));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EC980(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC980));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000084));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000020));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC9BC, UINT32_C(0x004EC99D));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000EC9A3, UINT32_C(0x004EC9A3));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC9A3, UINT32_C(0x004EC9AA));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC9B8));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000EC9BC, UINT32_C(0x004EC9BC));
    cpu->edx = (uint32_t)(UINT32_C(0x00000080));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF7C))));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFF7C), UINT32_C(0x00000000));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC9D0)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EC9CE)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC9D0));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF7C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004EC9E6));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC9F1));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECA00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECA00));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000014));
    cpu->edx = ((int32_t)cpu->eax < 0) ? UINT32_C(0xFFFFFFFF) : 0u;
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOGIC(cpu->edx, UINT32_C(0x00001FFF), &, 32u, cpu->edx = (uint32_t)(result););
    cpu->esi = (uint32_t)(((uint32_t)(cpu->edx + cpu->eax)));
    cpu->esi = (uint32_t)(lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(UINT32_C(0x0000000D)), 32u));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JLE(label_000ECA7F, UINT32_C(0x004ECA20));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000010));
    LIFT_STORE32(cpu->ebp + UINT32_C(0x0000000C), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->esi);
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000ECA30, UINT32_C(0x004ECA30));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_PUSH3(UINT32_C(0x00000000), cpu->ecx, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_lseek, UINT32_C(0x004ECA37), UINT32_C(0x004ECA3D));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECA73, UINT32_C(0x004ECA45));
    LIFT_LOAD32(cpu->edx, cpu->edi + UINT32_C(0x00000018));
    LIFT_PUSH3(UINT32_C(0x00002000), cpu->edx, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_read, UINT32_C(0x004ECA4F), UINT32_C(0x004ECA55));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECA73, UINT32_C(0x004ECA5D));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH3(UINT32_C(0x00002000), cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_write, UINT32_C(0x004ECA6A), UINT32_C(0x004ECA70));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000ECA73, UINT32_C(0x004ECA73));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), UINT32_C(0x00002000), 0u, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C))), (uint32_t)(result)););
    LIFT_DEC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_JNZ_GOTO(label_000ECA30);
    LIFT_BLOCK(label_000ECA7F, UINT32_C(0x004ECA7F));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000014));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x80001FFF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS(label_000ECA90, UINT32_C(0x004ECA89));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFE000), |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_BLOCK(label_000ECA90, UINT32_C(0x004ECA90));
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000014), cpu->eax);
    LIFT_JZ(label_000ECAD6, UINT32_C(0x004ECA95));
    cpu->esi = (uint32_t)(lift_shift_left(cpu, cpu->esi, (uint32_t)(UINT32_C(0x0000000D)), 32u));
    LIFT_ADD(cpu->esi, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_PUSH3(UINT32_C(0x00000000), cpu->esi, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_lseek, UINT32_C(0x004ECA9F), UINT32_C(0x004ECAA5));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECAD6, UINT32_C(0x004ECAAD));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->edx, cpu->edi + UINT32_C(0x00000018));
    LIFT_PUSH3(cpu->esi, cpu->edx, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_read, UINT32_C(0x004ECAB6), UINT32_C(0x004ECABC));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECAD6, UINT32_C(0x004ECAC4));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH3(cpu->esi, cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_write, UINT32_C(0x004ECACD), UINT32_C(0x004ECAD3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000ECAD6, UINT32_C(0x004ECAD6));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(16u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECAE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECAE0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000002), &, 8u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->esi + UINT32_C(0x00000008));
    LIFT_JZ(label_000ECB1C, UINT32_C(0x004ECAFC));
    cpu->eax = (uint32_t)(cpu->edi);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000ECB01, UINT32_C(0x004ECB01));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECB01, UINT32_C(0x004ECB08));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(cpu->eax, UINT32_C(0x00000020), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EEA10, UINT32_C(0x004ECB12));
    cpu->edi = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC8C0, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECB1C)));
    LIFT_BLOCK(label_000ECB1C, UINT32_C(0x004ECB1C));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"at"), cpu->edi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fopen, UINT32_C(0x004ECB22), UINT32_C(0x004ECB28));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JZ(label_000ECB93, UINT32_C(0x004ECB31));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->edi, cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fputs, UINT32_C(0x004ECB36), UINT32_C(0x004ECB3C));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000004), &, 8u);
    LIFT_JZ(label_000ECB4F, UINT32_C(0x004ECB45));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fflush, UINT32_C(0x004ECB46), UINT32_C(0x004ECB4C));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ECB4F, UINT32_C(0x004ECB4F));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), UINT32_C(0x00000000), 32u);
    LIFT_JLE(label_000ECB89, UINT32_C(0x004ECB55));
    LIFT_INC(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C)))), 32u, lift_store32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C))), (uint32_t)(result)););
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C)))), UINT32_C(0x000001F4), 32u);
    LIFT_JL(label_000ECB89, UINT32_C(0x004ECB61));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_ftell, UINT32_C(0x004ECB69), UINT32_C(0x004ECB6F));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fclose, UINT32_C(0x004ECB72), UINT32_C(0x004ECB78));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_CMP(cpu->ebx, lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), 32u);
    LIFT_JLE(label_000ECB93, UINT32_C(0x004ECB80));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC830, UINT32_C(0x004ECB87));
    goto label_000ECB93;
    LIFT_BLOCK(label_000ECB89, UINT32_C(0x004ECB89));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_fclose, UINT32_C(0x004ECB8A), UINT32_C(0x004ECB90));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ECB93, UINT32_C(0x004ECB93));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ECBA3));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECBB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECBB0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000018));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000018)))), UINT32_C(0x00000000), 32u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_JZ(label_000ECE61, UINT32_C(0x004ECBCF));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000ECBD5, UINT32_C(0x004ECBD5));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECBD5, UINT32_C(0x004ECBDC));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->eax = (uint32_t)(cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EEA10, UINT32_C(0x004ECBEB));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    cpu->ebx = (uint32_t)(cpu->esp);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), cpu->ebx);
    cpu->edx = (uint32_t)(cpu->ebx);
    LIFT_BLOCK(label_000ECBF5, UINT32_C(0x004ECBF5));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->edx, (cpu->eax & UINT32_C(0xFF)));
    LIFT_INC(cpu->ecx, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECBF5, UINT32_C(0x004ECBFF));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_STORE8(cpu->ebx + cpu->edi + UINT32_C(0xFFFFFFFE), UINT32_C(0x00000024));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_PUSH2(UINT32_C(0x00008000), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z, UINT32_C(0x004ECC0F), UINT32_C(0x004ECC15));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECC24, UINT32_C(0x004ECC1F));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    goto label_000ECC3E;
    LIFT_BLOCK(label_000ECC24, UINT32_C(0x004ECC24));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_filelength, UINT32_C(0x004ECC25), UINT32_C(0x004ECC2B));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_close, UINT32_C(0x004ECC2F), UINT32_C(0x004ECC35));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    LIFT_BLOCK(label_000ECC3E, UINT32_C(0x004ECC3E));
    LIFT_PUSH3(UINT32_C(0x00000000), UINT32_C(0x00008000), cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z, UINT32_C(0x004ECC46), UINT32_C(0x004ECC4C));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECC5B, UINT32_C(0x004ECC56));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    goto label_000ECC7A;
    LIFT_BLOCK(label_000ECC5B, UINT32_C(0x004ECC5B));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_filelength, UINT32_C(0x004ECC5C), UINT32_C(0x004ECC62));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_close, UINT32_C(0x004ECC66), UINT32_C(0x004ECC6C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ_GOTO(label_000ECC91);
    LIFT_BLOCK(label_000ECC7A, UINT32_C(0x004ECC7A));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECE61, UINT32_C(0x004ECC86));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), 32u);
    LIFT_JLE(label_000ECE61, UINT32_C(0x004ECC8F));
    goto label_000ECC94;
    LIFT_BLOCK(label_000ECC91, UINT32_C(0x004ECC91));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_BLOCK(label_000ECC94, UINT32_C(0x004ECC94));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECCA9, UINT32_C(0x004ECC99));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->ecx, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004ECC9E), UINT32_C(0x004ECCA4));
    goto label_000ECE5E;
    LIFT_BLOCK(label_000ECCA9, UINT32_C(0x004ECCA9));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_CALL_ENTER(sfera_sub_004EEA10, UINT32_C(0x004ECCB1));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    cpu->ebx = (uint32_t)(cpu->esp);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->ebx);
    cpu->edx = (uint32_t)(cpu->ebx);
    LIFT_BLOCK(label_000ECCC0, UINT32_C(0x004ECCC0));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->edx, (cpu->eax & UINT32_C(0xFF)));
    LIFT_INC(cpu->ecx, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECCC0, UINT32_C(0x004ECCCA));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_STORE16(cpu->ebx + cpu->eax + UINT32_C(0xFFFFFFFD), UINT32_C(0x00002424));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->ebx, cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004ECCD9), UINT32_C(0x004ECCDF));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000ECE61, UINT32_C(0x004ECCEA));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_PUSH3(UINT32_C(0x00000180), UINT32_C(0x00008302), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z, UINT32_C(0x004ECCF8), UINT32_C(0x004ECCFE));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECD34, UINT32_C(0x004ECD08));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_remove, UINT32_C(0x004ECD0C), UINT32_C(0x004ECD12));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->edx, cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004ECD17), UINT32_C(0x004ECD1D));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ECD30));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ECD34, UINT32_C(0x004ECD34));
    LIFT_LOGIC(cpu->ebx, UINT32_C(0xFFFFFFFF), |, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8)))), cpu->ebx, 32u);
    LIFT_JZ(label_000ECD8D, UINT32_C(0x004ECD3C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_PUSH3(UINT32_C(0x00000000), UINT32_C(0x00008000), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z, UINT32_C(0x004ECD47), UINT32_C(0x004ECD4D));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECD8D, UINT32_C(0x004ECD57));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_close, UINT32_C(0x004ECD58), UINT32_C(0x004ECD5E));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_remove, UINT32_C(0x004ECD62), UINT32_C(0x004ECD68));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_PUSH2(cpu->edx, cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004ECD70), UINT32_C(0x004ECD76));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ECD89));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ECD8D, UINT32_C(0x004ECD8D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_PUSH3(UINT32_C(0x00000000), UINT32_C(0x00008000), cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_open_YAHPBDHH_Z, UINT32_C(0x004ECD98), UINT32_C(0x004ECD9E));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECDE4, UINT32_C(0x004ECDA9));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ebx = (uint32_t)(SFERA_IMPORT_MSVCR100_close);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECDB2)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECDB0)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECDB2));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECDB5)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECDB3)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECDB5));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_remove, UINT32_C(0x004ECDB9), UINT32_C(0x004ECDBF));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_rename, UINT32_C(0x004ECDC7), UINT32_C(0x004ECDCD));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ECDE0));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ECDE4, UINT32_C(0x004ECDE4));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_CMP(cpu->edx, cpu->ecx, 32u);
    LIFT_JL(label_000ECDF4, UINT32_C(0x004ECDEE));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_SUB(cpu->edx, cpu->ecx, 0u, 32u, cpu->edx = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->edx));
    goto label_000ECE29;
    LIFT_BLOCK(label_000ECDF4, UINT32_C(0x004ECDF4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_CMP(cpu->ecx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECE26, UINT32_C(0x004ECDFC));
    LIFT_ADD(cpu->edx, cpu->ecx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_CMP(cpu->edx, lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), 32u);
    LIFT_JLE(label_000ECE14, UINT32_C(0x004ECE03));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000014));
    LIFT_SUB(cpu->ecx, lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_SUB(cpu->edx, cpu->eax, 0u, 32u, cpu->edx = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_ADD(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    goto label_000ECE17;
    LIFT_BLOCK(label_000ECE14, UINT32_C(0x004ECE14));
    LIFT_PUSH2(cpu->ecx, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000ECE17, UINT32_C(0x004ECE17));
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECA00, UINT32_C(0x004ECE20));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_BLOCK(label_000ECE26, UINT32_C(0x004ECE26));
    LIFT_PUSH2(cpu->edx, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000ECE29, UINT32_C(0x004ECE29));
    LIFT_PUSH2(cpu->eax, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECA00, UINT32_C(0x004ECE32));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(SFERA_IMPORT_MSVCR100_close);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE3B)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE39)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE3B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE41)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE3F)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE41));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    cpu->esi = (uint32_t)(SFERA_IMPORT_MSVCR100_remove);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE4D)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE4B)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE4D));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECE61, UINT32_C(0x004ECE55));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE58)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE56)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE58));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE5E)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECE5C)))) { return; }
    LIFT_BLOCK(label_000ECE5E, UINT32_C(0x004ECE5E));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000ECE61, UINT32_C(0x004ECE61));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ECE71));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECE80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECE80));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000028));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->edi))), UINT32_C(0x00000001), 8u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), cpu->ecx);
    LIFT_JZ(label_000ECF41, UINT32_C(0x004ECEA2));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000014));
    LIFT_STORE8(cpu->edi, UINT32_C(0x00000001));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000ECEB6, UINT32_C(0x004ECEAD));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    goto label_000ECF3C;
    LIFT_BLOCK(label_000ECEB6, UINT32_C(0x004ECEB6));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"[%d] "));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_snprintf, UINT32_C(0x004ECEC2), UINT32_C(0x004ECEC8));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000004));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFB), UINT32_C(0x00000000));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000ECED5, UINT32_C(0x004ECED5));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECED5, UINT32_C(0x004ECEDC));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edx = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000ECEE6, UINT32_C(0x004ECEE6));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECEE6, UINT32_C(0x004ECEED));
    LIFT_SUB(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax + cpu->edx + UINT32_C(0x00000001))));
    LIFT_CALL_ENTER(sfera_sub_004EEA10, UINT32_C(0x004ECEF8));
    cpu->ebx = (uint32_t)(cpu->esp);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    cpu->edx = (uint32_t)(cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_SUB(cpu->edx, cpu->ecx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_BLOCK(label_000ECF03, UINT32_C(0x004ECF03));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->edx + cpu->eax, (cpu->ecx & UINT32_C(0xFF)));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECF03, UINT32_C(0x004ECF0D));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(cpu->eax);
    LIFT_BLOCK(label_000ECF12, UINT32_C(0x004ECF12));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECF12, UINT32_C(0x004ECF19));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebx + UINT32_C(0xFFFFFFFF))));
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000ECF20, UINT32_C(0x004ECF20));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->edi + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECF20, UINT32_C(0x004ECF28));
    cpu->ecx = (uint32_t)(cpu->eax);
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000002)), 32u));
    cpu->esi = (uint32_t)(cpu->edx);
    lift_movs32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOGIC(cpu->ecx, UINT32_C(0x00000003), &, 32u, cpu->ecx = (uint32_t)(result););
    lift_movs8(cpu, 1u);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_BLOCK(label_000ECF3C, UINT32_C(0x004ECF3C));
    LIFT_CALL(sfera_sub_004ECAE0, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECF41)));
    LIFT_BLOCK(label_000ECF41, UINT32_C(0x004ECF41));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ECF51));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECF60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECF60));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000ECFD5, UINT32_C(0x004ECF6B));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JNZ(label_000ECF79, UINT32_C(0x004ECF71));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004ECAE0, UINT32_C(0x004ECF77));
    goto label_000ECFC3;
    LIFT_BLOCK(label_000ECF79, UINT32_C(0x004ECF79));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000002C));
    LIFT_PUSH2(cpu->edi, cpu->eax);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE5D0, UINT32_C(0x004ECF86));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000ECFC2, UINT32_C(0x004ECF8A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4C0, UINT32_C(0x004ECF92));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000ECFA6, UINT32_C(0x004ECF96));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4D0, UINT32_C(0x004ECF9E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECE80, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECFA6)));
    LIFT_BLOCK(label_000ECFA6, UINT32_C(0x004ECFA6));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000002C));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000024));
    LIFT_PUSH2(cpu->ecx, cpu->edx);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE690, UINT32_C(0x004ECFB6));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ECFC2, UINT32_C(0x004ECFBA));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECE80, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ECFC2)));
    LIFT_BLOCK(label_000ECFC2, UINT32_C(0x004ECFC2));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000ECFC3, UINT32_C(0x004ECFC3));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    LIFT_STORE8(cpu->eax, UINT32_C(0x00000000));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ECFD5, UINT32_C(0x004ECFCF));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000002C));
    LIFT_STORE8(cpu->ecx, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000ECFD5, UINT32_C(0x004ECFD5));
    LIFT_EPILOGUE1(0u, cpu->esi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ECFE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECFE0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000002C));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000000C)))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000ED00D, UINT32_C(0x004ECFF9));
    cpu->eax = (uint32_t)(UINT32_C(0x00000001));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED009));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ED00D, UINT32_C(0x004ED00D));
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->esi + UINT32_C(0x0000000C));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->edi))), UINT32_C(0x00000000), 8u);
    cpu->ecx = (uint32_t)(cpu->edi);
    LIFT_JZ(label_000ED0DB, UINT32_C(0x004ED01D));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ecx)));
    LIFT_BLOCK(label_000ED020, UINT32_C(0x004ED020));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->edi))), UINT32_C(0x00000024), 8u);
    LIFT_JNZ(label_000ED0D1, UINT32_C(0x004ED029));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    LIFT_PUSH2(cpu->ebx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE8(cpu->edi, UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED03C));
    LIFT_STORE8(cpu->edi, UINT32_C(0x00000024));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->edi + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000ED0EB, UINT32_C(0x004ED04A));
    LIFT_CMP((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x00000064), 8u);
    LIFT_JNZ(label_000ED08F, UINT32_C(0x004ED04F));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004ED053), UINT32_C(0x004ED059));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_localtime64, UINT32_C(0x004ED05D), UINT32_C(0x004ED063));
    LIFT_PUSH2(cpu->eax, ((uint32_t)(uintptr_t)"%d/%m/%y"));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strftime, UINT32_C(0x004ED06F), UINT32_C(0x004ED075));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(cpu->eax, cpu->ebx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED088));
    LIFT_ADD(cpu->edi, UINT32_C(0x00000002), 0u, 32u, cpu->edi = (uint32_t)(result););
    cpu->ecx = (uint32_t)(cpu->edi);
    goto label_000ED0D2;
    LIFT_BLOCK(label_000ED08F, UINT32_C(0x004ED08F));
    LIFT_CMP((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x00000074), 8u);
    LIFT_JNZ(label_000ED0B8, UINT32_C(0x004ED094));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strtime, UINT32_C(0x004ED098), UINT32_C(0x004ED09E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(cpu->edx, cpu->ebx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED0B1));
    LIFT_ADD(cpu->edi, UINT32_C(0x00000002), 0u, 32u, cpu->edi = (uint32_t)(result););
    cpu->ecx = (uint32_t)(cpu->edi);
    goto label_000ED0D2;
    LIFT_BLOCK(label_000ED0B8, UINT32_C(0x004ED0B8));
    LIFT_CMP((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x00000075), 8u);
    LIFT_JNZ(label_000ED0CA, UINT32_C(0x004ED0BD));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000020)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_000ED0CA, UINT32_C(0x004ED0C3));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC980, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED0CA)));
    LIFT_BLOCK(label_000ED0CA, UINT32_C(0x004ED0CA));
    LIFT_ADD(cpu->edi, UINT32_C(0x00000002), 0u, 32u, cpu->edi = (uint32_t)(result););
    cpu->ecx = (uint32_t)(cpu->edi);
    goto label_000ED0D2;
    LIFT_BLOCK(label_000ED0D1, UINT32_C(0x004ED0D1));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_BLOCK(label_000ED0D2, UINT32_C(0x004ED0D2));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->edi))), UINT32_C(0x00000000), 8u);
    LIFT_JNZ_GOTO(label_000ED020);
    LIFT_BLOCK(label_000ED0DB, UINT32_C(0x004ED0DB));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED0EB)));
    LIFT_BLOCK(label_000ED0EB, UINT32_C(0x004ED0EB));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_POP2(cpu->edi, cpu->ebx);
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED0F8));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED100(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED100));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED10B));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECFE0, UINT32_C(0x004ED112));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED125));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED13E, UINT32_C(0x004ED12B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED13E)));
    LIFT_BLOCK(label_000ED13E, UINT32_C(0x004ED13E));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED145));
    LIFT_EPILOGUE2(8u, cpu->esi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED150));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(SFERA_STATIC_04F9006C_U32);
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000ED196, UINT32_C(0x004ED15B));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000ED160, UINT32_C(0x004ED160));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000ED18E, UINT32_C(0x004ED166));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED16E));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE_GOTO(label_000ED18E);
    LIFT_BLOCK(label_000ED172, UINT32_C(0x004ED172));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4D0, UINT32_C(0x004ED17A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECE80, UINT32_C(0x004ED182));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000038))));
    LIFT_CALL_ENTER(sfera_sub_004EE4B0, UINT32_C(0x004ED18A));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JG_GOTO(label_000ED172);
    LIFT_BLOCK(label_000ED18E, UINT32_C(0x004ED18E));
    LIFT_LOAD32(cpu->esi, cpu->esi + UINT32_C(0x00000004));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JNZ(label_000ED160, UINT32_C(0x004ED195));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000ED196, UINT32_C(0x004ED196));
    LIFT_EPILOGUE1(0u, cpu->esi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED380(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED380));
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED385));
    LIFT_RET(4u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED390));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000014));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax))), UINT32_C(0x00000000), 8u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    LIFT_JNZ(label_000ED3B4, UINT32_C(0x004ED3AF));
    LIFT_CALL(sfera_sub_004ECFE0, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED3B4)));
    LIFT_BLOCK(label_000ED3B4, UINT32_C(0x004ED3B4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->ecx, ((uint32_t)(uintptr_t)"%d"));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_snprintf, UINT32_C(0x004ED3C3), UINT32_C(0x004ED3C9));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    LIFT_PUSH2(cpu->ecx, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFB), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED3E0));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000800), 32u);
    LIFT_JLE(label_000ED3EE, UINT32_C(0x004ED3E7));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECF60, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED3EE)));
    LIFT_BLOCK(label_000ED3EE, UINT32_C(0x004ED3EE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED3FC));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED410(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED410));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax))), UINT32_C(0x00000000), 8u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    LIFT_JNZ(label_000ED427, UINT32_C(0x004ED422));
    LIFT_CALL(sfera_sub_004ECFE0, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED427)));
    LIFT_BLOCK(label_000ED427, UINT32_C(0x004ED427));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000028))));
    LIFT_PUSH2(cpu->ecx, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC770, UINT32_C(0x004ED438));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_JZ(label_000ED450, UINT32_C(0x004ED440));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000030))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000002C))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004EC770, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED450)));
    LIFT_BLOCK(label_000ED450, UINT32_C(0x004ED450));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    LIFT_CMP(cpu->edi, UINT32_C(0x00000800), 32u);
    LIFT_JLE(label_000ED460, UINT32_C(0x004ED459));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECF60, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED460)));
    LIFT_BLOCK(label_000ED460, UINT32_C(0x004ED460));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE2(4u, cpu->esi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED470));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_BLOCK(label_000ED474, UINT32_C(0x004ED474));
    cpu->eax = (uint32_t)(cpu->edx);
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->edx & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED48A, UINT32_C(0x004ED47F));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xEDB88320), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_BLOCK(label_000ED48A, UINT32_C(0x004ED48A));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED49F, UINT32_C(0x004ED490));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xEDB88320), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000ED4A1;
    LIFT_BLOCK(label_000ED49F, UINT32_C(0x004ED49F));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_BLOCK(label_000ED4A1, UINT32_C(0x004ED4A1));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED4B6, UINT32_C(0x004ED4A7));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xEDB88320), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000ED4B8;
    LIFT_BLOCK(label_000ED4B6, UINT32_C(0x004ED4B6));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_BLOCK(label_000ED4B8, UINT32_C(0x004ED4B8));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED4CD, UINT32_C(0x004ED4BE));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xEDB88320), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000ED4CF;
    LIFT_BLOCK(label_000ED4CD, UINT32_C(0x004ED4CD));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_BLOCK(label_000ED4CF, UINT32_C(0x004ED4CF));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED4E4, UINT32_C(0x004ED4D5));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xEDB88320), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000ED4E6;
    LIFT_BLOCK(label_000ED4E4, UINT32_C(0x004ED4E4));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_BLOCK(label_000ED4E6, UINT32_C(0x004ED4E6));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED4FB, UINT32_C(0x004ED4EC));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xEDB88320), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000ED4FD;
    LIFT_BLOCK(label_000ED4FB, UINT32_C(0x004ED4FB));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_BLOCK(label_000ED4FD, UINT32_C(0x004ED4FD));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED512, UINT32_C(0x004ED503));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xEDB88320), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000ED514;
    LIFT_BLOCK(label_000ED512, UINT32_C(0x004ED512));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_BLOCK(label_000ED514, UINT32_C(0x004ED514));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC_FLAGS((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000ED520, UINT32_C(0x004ED51A));
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xEDB88320), ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_BLOCK(label_000ED520, UINT32_C(0x004ED520));
    LIFT_STORE16(((uint32_t)(cpu->edx) * 2u) + SFERA_STATIC_04F90070_ADDR, (cpu->ecx & UINT32_C(0xFFFF)));
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_CMP(cpu->edx, UINT32_C(0x00000100), 32u);
    LIFT_JL(label_000ED474, UINT32_C(0x004ED535));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED5C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000ED5C0;
    LIFT_BLOCK(label_000ED540, UINT32_C(0x004ED540));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000003C));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000006));
    cpu->esi = (uint32_t)(((uint32_t)(uintptr_t)"QWERTYUIOPASDFGHJKLZXCVBNM"));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000006));
    cpu->esi = (uint32_t)(((uint32_t)(uintptr_t)"qwertyuiopasdfghjklzxcvbnm"));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC4))));
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_ZERO(cpu->eax, 32u);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->ebx)));
    LIFT_BLOCK(label_000ED580, UINT32_C(0x004ED580));
    LIFT_STORE8(cpu->eax + SFERA_STATIC_04F90270_ADDR, (cpu->eax & UINT32_C(0xFF)));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_CMP(cpu->eax, UINT32_C(0x00000100), 32u);
    LIFT_JL(label_000ED580, UINT32_C(0x004ED58E));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_BLOCK(label_000ED590, UINT32_C(0x004ED590));
    cpu->ecx = (uint32_t)(lift_load8(((uint32_t)(cpu->ebp + cpu->eax + UINT32_C(0xFFFFFFE0)))));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ebp + cpu->eax + UINT32_C(0xFFFFFFC4))))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE8(cpu->ecx + SFERA_STATIC_04F90270_ADDR, (cpu->edx & UINT32_C(0xFF)));
    LIFT_CMP(cpu->eax, UINT32_C(0x0000001B), 32u);
    LIFT_JB(label_000ED590, UINT32_C(0x004ED5A5));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED5AF));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ED5C0, UINT32_C(0x004ED5C0));
    LIFT_CMP(SFERA_STATIC_04F90370_U32, UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000ED5DD, UINT32_C(0x004ED5C9));
    SFERA_STATIC_04F90370_U32 = (uint32_t)(UINT32_C(0x00000001));
    LIFT_CALL_ENTER(sfera_sub_004ED470, UINT32_C(0x004ED5D8));
    goto label_000ED540;
    LIFT_BLOCK(label_000ED5DD, UINT32_C(0x004ED5DD));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED5E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED5E0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000014));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_PUSH5(cpu->ecx, ((uint32_t)(uintptr_t)"operator[]: out of range. Size=%d, Index=%d"), UINT32_C(0x00000001), UINT32_C(0x00000013), ((uint32_t)(uintptr_t)"Containers\\Containers.cpp"));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_CALL_ENTER(sfera_sub_004013B0, UINT32_C(0x004ED60A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED610));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED620(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED620));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004ED5C0, UINT32_C(0x004ED631));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFF), (cpu->edx & UINT32_C(0xFF)));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFF)))))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_isalpha, UINT32_C(0x004ED644), UINT32_C(0x004ED64A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED6ED, UINT32_C(0x004ED655));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFF)))))));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx + SFERA_STATIC_04F90270_ADDR)))) & UINT32_C(0xFF));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFF), (cpu->edx & UINT32_C(0xFF)));
    goto label_000ED66D;
    LIFT_BLOCK(label_000ED664, UINT32_C(0x004ED664));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000001), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    LIFT_BLOCK(label_000ED66D, UINT32_C(0x004ED66D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ecx))))));
    LIFT_TEST(cpu->edx, 32u);
    LIFT_JZ(label_000ED6EB, UINT32_C(0x004ED677));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->eax))))));
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ecx + SFERA_STATIC_04F90270_ADDR))))));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFF)))))));
    LIFT_CMP(cpu->edx, cpu->eax, 32u);
    LIFT_JNZ(label_000ED6E6, UINT32_C(0x004ED68C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000001), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->ecx);
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->edx, UINT32_C(0x00000001), 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->edx);
    goto label_000ED6B2;
    LIFT_BLOCK(label_000ED6A0, UINT32_C(0x004ED6A0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000001), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000001), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->ecx);
    LIFT_BLOCK(label_000ED6B2, UINT32_C(0x004ED6B2));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx))))));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000ED6C4, UINT32_C(0x004ED6BC));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    goto label_000ED76B;
    LIFT_BLOCK(label_000ED6C4, UINT32_C(0x004ED6C4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF8));
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ecx))))));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx + SFERA_STATIC_04F90270_ADDR))))));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ecx))))));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx + SFERA_STATIC_04F90270_ADDR))))));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JZ(label_000ED6E4, UINT32_C(0x004ED6E2));
    goto label_000ED6E6;
    LIFT_BLOCK(label_000ED6E4, UINT32_C(0x004ED6E4));
    goto label_000ED6A0;
    LIFT_BLOCK(label_000ED6E6, UINT32_C(0x004ED6E6));
    goto label_000ED664;
    LIFT_BLOCK(label_000ED6EB, UINT32_C(0x004ED6EB));
    goto label_000ED769;
    LIFT_BLOCK(label_000ED6ED, UINT32_C(0x004ED6ED));
    goto label_000ED6F8;
    LIFT_BLOCK(label_000ED6EF, UINT32_C(0x004ED6EF));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_ADD(cpu->edx, UINT32_C(0x00000001), 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->edx);
    LIFT_BLOCK(label_000ED6F8, UINT32_C(0x004ED6F8));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->eax))))));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000ED769, UINT32_C(0x004ED702));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx))))));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFF)))))));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JNZ(label_000ED767, UINT32_C(0x004ED710));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_ADD(cpu->edx, UINT32_C(0x00000001), 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->edx);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000001), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    goto label_000ED736;
    LIFT_BLOCK(label_000ED724, UINT32_C(0x004ED724));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000001), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->ecx);
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->edx, UINT32_C(0x00000001), 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->edx);
    LIFT_BLOCK(label_000ED736, UINT32_C(0x004ED736));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->eax))))));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JNZ(label_000ED745, UINT32_C(0x004ED740));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    goto label_000ED76B;
    LIFT_BLOCK(label_000ED745, UINT32_C(0x004ED745));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF8));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx))))));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->eax + SFERA_STATIC_04F90270_ADDR))))));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx))))));
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->eax + SFERA_STATIC_04F90270_ADDR))))));
    LIFT_CMP(cpu->ecx, cpu->edx, 32u);
    LIFT_JZ(label_000ED765, UINT32_C(0x004ED763));
    goto label_000ED767;
    LIFT_BLOCK(label_000ED765, UINT32_C(0x004ED765));
    goto label_000ED724;
    LIFT_BLOCK(label_000ED767, UINT32_C(0x004ED767));
    goto label_000ED6EF;
    LIFT_BLOCK(label_000ED769, UINT32_C(0x004ED769));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_BLOCK(label_000ED76B, UINT32_C(0x004ED76B));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED770));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(UINT32_C(0x00000017), ((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB300, UINT32_C(0x004ED785));
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED790(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED790));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH3(UINT32_C(0x0000001C), ((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h"), cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EB8A0, UINT32_C(0x004ED7A9));
    LIFT_EPILOGUE1(12u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED7B0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000021)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\Allocator.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004ED7C2));
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED7D0));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED7E1, UINT32_C(0x004ED7D6));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JZ(label_000ED7E1, UINT32_C(0x004ED7DB));
    cpu->eax = (uint32_t)(UINT32_C(0x00000001));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000ED7E1, UINT32_C(0x004ED7E1));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED7F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED7F0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000ED834, UINT32_C(0x004ED7FE));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000ED808, UINT32_C(0x004ED801));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ED808, UINT32_C(0x004ED808));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"FileMap::size: open file %s error"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Files\\FileMap.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000075));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->edx);
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED82B));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_ZERO(cpu->eax, 32u);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ED834, UINT32_C(0x004ED834));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"FileMap::size: file is not opened"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), ((uint32_t)(uintptr_t)"Files\\FileMap.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000072));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->edx);
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED853));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_ZERO(cpu->eax, 32u);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED860(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED860));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000018));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_SUB(cpu->eax, UINT32_C(0x00000000), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000ED87A, UINT32_C(0x004ED870));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000ED8A0, UINT32_C(0x004ED873));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ED87A, UINT32_C(0x004ED87A));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"FileMap::get_ptr: file is not opened"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Files\\FileMap.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000085));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED89D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000ED8A0, UINT32_C(0x004ED8A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"FileMap::get_ptr: open file %s error"), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), ((uint32_t)(uintptr_t)"Files\\FileMap.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000087));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED8C7));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED8E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED8E0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED92B, UINT32_C(0x004ED8EF));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JZ(label_000ED92B, UINT32_C(0x004ED8F4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_UnmapViewOfFile, UINT32_C(0x004ED8F5), UINT32_C(0x004ED8FB));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000ED925, UINT32_C(0x004ED8FF));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Error unmappnig file %s"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Files\\FileMap.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000063));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED922));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000ED925, UINT32_C(0x004ED925));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000ED92B, UINT32_C(0x004ED92B));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004ED930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED930));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED97C, UINT32_C(0x004ED940));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JZ(label_000ED97C, UINT32_C(0x004ED945));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_UnmapViewOfFile, UINT32_C(0x004ED946), UINT32_C(0x004ED94C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000ED976, UINT32_C(0x004ED950));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Error unmappnig file %s"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Files\\FileMap.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000063));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED973));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000ED976, UINT32_C(0x004ED976));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000ED97C, UINT32_C(0x004ED97C));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000020)));
    cpu->ecx = (uint32_t)(cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EE7D0, UINT32_C(0x004ED988));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004ED98D), UINT32_C(0x004ED993));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_PUSH7(UINT32_C(0x00000000), UINT32_C(0x08000000), UINT32_C(0x00000003), UINT32_C(0x00000000), UINT32_C(0x00000001), UINT32_C(0x80000000), cpu->edi);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000027), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_CreateFileA, UINT32_C(0x004ED9AD), UINT32_C(0x004ED9B3));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ED9CA, UINT32_C(0x004ED9BA));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000001));
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), (cpu->eax & UINT32_C(0xFF)), ^, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000ED9CA, UINT32_C(0x004ED9CA));
    LIFT_PUSH3(cpu->ebx, UINT32_C(0x00000000), cpu->edi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetFileSize, UINT32_C(0x004ED9CE), UINT32_C(0x004ED9D4));
    LIFT_PUSH6(UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000002), UINT32_C(0x00000000), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_CreateFileMappingA, UINT32_C(0x004ED9E2), UINT32_C(0x004ED9E8));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EDA11, UINT32_C(0x004ED9EF));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(SFERA_IMPORT_KERNEL32_CloseHandle);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED9F8)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000ED9F6)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED9F8));
    LIFT_PUSH5(UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000004), cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_MapViewOfFile, UINT32_C(0x004EDA01), UINT32_C(0x004EDA07));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_STORE32(cpu->esi, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EDA0C)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EDA0A)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EDA0C));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ_GOTO(label_000EDA22);
    LIFT_BLOCK(label_000EDA11, UINT32_C(0x004EDA11));
    LIFT_POP2(cpu->ebx, cpu->edi);
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000001));
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), (cpu->eax & UINT32_C(0xFF)), ^, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000EDA22, UINT32_C(0x004EDA22));
    LIFT_POP2(cpu->ebx, cpu->edi);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDA30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDA30));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_ZERO(cpu->eax, 32u);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000008), (cpu->eax & UINT32_C(0xFF)));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004ED930, UINT32_C(0x004EDA49));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE2(4u, cpu->esi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDA50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDA50));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_dbghelp_MiniDumpWriteDump, UINT32_C(0x004EDA50));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDA60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDA60));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->ebx = (uint32_t)(((uint32_t)(((uint32_t)(cpu->edi) * 8u))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_malloc, UINT32_C(0x004EDA76), UINT32_C(0x004EDA7C));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EDAAB, UINT32_C(0x004EDA85));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"CHash8Mem: init error"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Memory\\hash8mem.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EDAA8));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EDAAB, UINT32_C(0x004EDAAB));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000800)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000000A))));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_PUSH2(UINT32_C(0x000000FF), cpu->edx);
    LIFT_STORE16(cpu->esi + UINT32_C(0x00000008), (cpu->ecx & UINT32_C(0xFFFF)));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004EDAC7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFF))));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JLE_GOTO(label_000EDAEB);
    LIFT_BLOCK(label_000EDAD3, UINT32_C(0x004EDAD3));
    LIFT_LOAD32(cpu->edi, cpu->esi);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_STORE16(cpu->edi + ((uint32_t)(cpu->eax) * 8u) + UINT32_C(0x00000004), (cpu->edx & UINT32_C(0xFFFF)));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    LIFT_STORE32(cpu->edx + ((uint32_t)(cpu->eax) * 8u), UINT32_C(0x00000000));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JL_GOTO(label_000EDAD3);
    LIFT_BLOCK(label_000EDAEB, UINT32_C(0x004EDAEB));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    cpu->ecx = (uint32_t)(UINT32_C(0x0000FFFF));
    LIFT_STORE16(cpu->ebx + cpu->eax + UINT32_C(0xFFFFFFFC), (cpu->ecx & UINT32_C(0xFFFF)));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_STORE32(cpu->ebx + cpu->edx + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000000));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDB10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDB10));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    cpu->eax = (uint32_t)(UINT32_C(0x0000FFFF));
    LIFT_CMP(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))), (cpu->eax & UINT32_C(0xFFFF)), 16u);
    LIFT_JNZ(label_000EDC32, UINT32_C(0x004EDB28));
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    cpu->ebx = (uint32_t)(UINT32_C(0x00000002));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000004)))), cpu->eax, 32u);
    LIFT_JNZ(label_000EDB56, UINT32_C(0x004EDB34));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"CHash8Mem::register_str: more than 65535 elements"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Memory\\hash8mem.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000031));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EDB53));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EDB56, UINT32_C(0x004EDB56));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(UINT32_C(0x55555556));
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = (uint32_t)(cpu->edx);
    cpu->edi = (uint32_t)(lift_shift_right(cpu, cpu->edi, (uint32_t)(UINT32_C(0x0000001F)), 32u));
    LIFT_ADD(cpu->edi, cpu->edx, 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_CMP(cpu->edi, UINT32_C(0x00000032), 32u);
    LIFT_JGE(label_000EDB71, UINT32_C(0x004EDB6C));
    cpu->edi = (uint32_t)(UINT32_C(0x00000032));
    LIFT_BLOCK(label_000EDB71, UINT32_C(0x004EDB71));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000004)))), cpu->edi, 0u, 32u, lift_store32(((uint32_t)(cpu->esi + UINT32_C(0x00000004))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFF0000)) | ((uint32_t)((cpu->ecx & UINT32_C(0xFFFF))) & UINT32_C(0xFFFF));
    LIFT_STORE16(cpu->esi + UINT32_C(0x00000008), (cpu->edx & UINT32_C(0xFFFF)));
    LIFT_CMP(cpu->eax, UINT32_C(0x0000FFFF), 32u);
    LIFT_JLE(label_000EDB95, UINT32_C(0x004EDB85));
    cpu->ecx = (uint32_t)(UINT32_C(0x0000FFFF));
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->edi, cpu->ecx, 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), UINT32_C(0x0000FFFF));
    LIFT_BLOCK(label_000EDB95, UINT32_C(0x004EDB95));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_ADD(cpu->edx, cpu->edx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_ADD(cpu->edx, cpu->edx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_ADD(cpu->edx, cpu->edx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_PUSH2(cpu->edx, cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_realloc, UINT32_C(0x004EDBA2), UINT32_C(0x004EDBA8));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EDBDD, UINT32_C(0x004EDBB1));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    LIFT_ADD(cpu->ecx, cpu->ecx, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->ecx, cpu->ecx, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->ecx, cpu->ecx, 0u, 32u, cpu->ecx = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"CHash8Memory::register_str: Not enough memory. Request size = %d"), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Memory\\hash8mem.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x0000003D));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EDBDA));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EDBDD, UINT32_C(0x004EDBDD));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFF))));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JLE_GOTO(label_000EDC0E);
    LIFT_BLOCK(label_000EDBE6, UINT32_C(0x004EDBE6));
    cpu->ecx = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))));
    LIFT_LOAD32(cpu->ebx, cpu->esi);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx + cpu->eax + UINT32_C(0x00000001))));
    LIFT_ADD(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_STORE16(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u) + UINT32_C(0x00000004), (cpu->edx & UINT32_C(0xFFFF)));
    cpu->edx = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_ADD(cpu->edx, cpu->eax, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_STORE32(cpu->ecx + ((uint32_t)(cpu->edx) * 8u), UINT32_C(0x00000000));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFF))));
    LIFT_CMP(cpu->eax, cpu->ecx, 32u);
    LIFT_JL_GOTO(label_000EDBE6);
    LIFT_BLOCK(label_000EDC0E, UINT32_C(0x004EDC0E));
    cpu->edx = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_ADD(cpu->edx, cpu->edi, 0u, 32u, cpu->edx = (uint32_t)(result););
    cpu->ecx = (uint32_t)(UINT32_C(0x0000FFFF));
    LIFT_STORE16(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + UINT32_C(0xFFFFFFFC), (cpu->ecx & UINT32_C(0xFFFF)));
    cpu->edx = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_ADD(cpu->edx, cpu->edi, 0u, 32u, cpu->edx = (uint32_t)(result););
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE32(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000000));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EDC32, UINT32_C(0x004EDC32));
    cpu->ecx = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u))));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFF0000)) | ((uint32_t)(lift_load16(((uint32_t)(cpu->eax + UINT32_C(0x00000004))))) & UINT32_C(0xFFFF));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))));
    LIFT_STORE16(cpu->esi + UINT32_C(0x00000008), (cpu->edx & UINT32_C(0xFFFF)));
    cpu->edx = (uint32_t)(lift_load16(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + UINT32_C(0x0000000A))));
    cpu->esi = (cpu->esi & UINT32_C(0xFFFF0000)) | ((uint32_t)(lift_load16(((uint32_t)(cpu->edx)))) & UINT32_C(0xFFFF));
    LIFT_STORE16(cpu->eax + UINT32_C(0x00000004), (cpu->esi & UINT32_C(0xFFFF)));
    LIFT_STORE16(cpu->edx, (cpu->ecx & UINT32_C(0xFFFF)));
    cpu->eax = (uint32_t)(cpu->ecx);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDC70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDC70));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH4(cpu->ecx, cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->ebx = (uint32_t)(cpu->edi);
    cpu->ebx = (uint32_t)(lift_shift_right(cpu, cpu->ebx, (uint32_t)(UINT32_C(0x00000004)), 32u));
    LIFT_LOGIC(cpu->ebx, UINT32_C(0x000003FF), &, 32u, cpu->ebx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_load16(((uint32_t)(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + UINT32_C(0x0000000A)))));
    cpu->edx = (uint32_t)(UINT32_C(0x0000FFFF));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ecx);
    LIFT_CMP((cpu->esi & UINT32_C(0xFFFF)), (cpu->edx & UINT32_C(0xFFFF)), 16u);
    LIFT_JZ(label_000EDCD0, UINT32_C(0x004EDC97));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 8u) + UINT32_C(0x00000004)))));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 8u)))), cpu->edi, 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 8u))));
    LIFT_JZ_GOTO(label_000EDCC1);
    LIFT_BLOCK(label_000EDCA6, UINT32_C(0x004EDCA6));
    cpu->edx = (uint32_t)(UINT32_C(0x0000FFFF));
    LIFT_CMP((cpu->eax & UINT32_C(0xFFFF)), (cpu->edx & UINT32_C(0xFFFF)), 16u);
    LIFT_JZ(label_000EDCCD, UINT32_C(0x004EDCB0));
    cpu->edx = (uint32_t)((cpu->eax & UINT32_C(0xFFFF)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 8u))));
    cpu->esi = (uint32_t)((cpu->eax & UINT32_C(0xFFFF)));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->edx + UINT32_C(0x00000004)))));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->edx))), cpu->edi, 32u);
    LIFT_JNZ_GOTO(label_000EDCA6);
    LIFT_BLOCK(label_000EDCC1, UINT32_C(0x004EDCC1));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    cpu->eax = (uint32_t)((cpu->esi & UINT32_C(0xFFFF)));
    LIFT_POP2(cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000EDCCD, UINT32_C(0x004EDCCD));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_BLOCK(label_000EDCD0, UINT32_C(0x004EDCD0));
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EDB10, UINT32_C(0x004EDCD7));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDCE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDCE0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_STORE8(cpu->edi, UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JS(label_000EDD35, UINT32_C(0x004EDCF1));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000004)))), 32u);
    LIFT_JGE(label_000EDD35, UINT32_C(0x004EDCF6));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u))));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000EDD35, UINT32_C(0x004EDD01));
    cpu->eax = (uint32_t)(cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000EDD07, UINT32_C(0x004EDD07));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->edx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EDD07, UINT32_C(0x004EDD0E));
    LIFT_SUB(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JS_GOTO(label_000EDD1C);
    LIFT_BLOCK(label_000EDD13, UINT32_C(0x004EDD13));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ecx + cpu->eax))), UINT32_C(0x0000005C), 8u);
    LIFT_JZ(label_000EDD1C, UINT32_C(0x004EDD19));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EDD13);
    LIFT_BLOCK(label_000EDD1C, UINT32_C(0x004EDD1C));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x00000010));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx + cpu->eax + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->edx, cpu->edi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004EDD26), UINT32_C(0x004EDD2C));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE8(cpu->edi + cpu->esi + UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EDD35, UINT32_C(0x004EDD35));
    LIFT_EPILOGUE2(12u, cpu->edi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDD40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDD40));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->ebx = (uint32_t)(cpu->edi);
    LIFT_IMUL32(cpu->ebx, UINT32_C(0x0000001A));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_malloc, UINT32_C(0x004EDD54), UINT32_C(0x004EDD5A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EDD89, UINT32_C(0x004EDD63));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"CHash32Mem: init. Not enough memory"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Memory\\hash32mem.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x0000000B));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EDD86));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EDD89, UINT32_C(0x004EDD89));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00040000)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000000C))));
    LIFT_PUSH2(UINT32_C(0x000000FF), cpu->ecx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004EDDA6));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFF))));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_TEST(cpu->edx, 32u);
    LIFT_JLE(label_000EDDD4, UINT32_C(0x004EDDB2));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_BLOCK(label_000EDDB4, UINT32_C(0x004EDDB4));
    LIFT_LOAD32(cpu->edi, cpu->esi);
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ecx + cpu->edi, cpu->eax);
    LIFT_ADD(cpu->ecx, UINT32_C(0x0000001A), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CMP(cpu->eax, cpu->edx, 32u);
    LIFT_JL(label_000EDDB4, UINT32_C(0x004EDDC1));
    LIFT_LOAD32(cpu->edx, cpu->esi);
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_STORE32(cpu->ebx + cpu->edx + UINT32_C(0xFFFFFFE6), UINT32_C(0xFFFFFFFF));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000EDDD4, UINT32_C(0x004EDDD4));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_STORE32(cpu->ebx + cpu->eax + UINT32_C(0xFFFFFFE6), UINT32_C(0xFFFFFFFF));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDDF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDDF0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(cpu->edi);
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000009)), 32u));
    cpu->edx = (uint32_t)((cpu->eax & UINT32_C(0xFFFF)));
    LIFT_LOAD32(cpu->eax, cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EDE0F, UINT32_C(0x004EDE08));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_EPILOGUE2(4u, cpu->edi, cpu->ebp);
    LIFT_BLOCK(label_000EDE0F, UINT32_C(0x004EDE0F));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->esi, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_IMUL32(cpu->ecx, UINT32_C(0x0000001A));
    LIFT_LOAD32(cpu->edx, cpu->ecx + cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + cpu->esi + UINT32_C(0x00000004)))), cpu->edi, 32u);
    LIFT_JZ_GOTO(label_000EDE3E);
    LIFT_BLOCK(label_000EDE20, UINT32_C(0x004EDE20));
    LIFT_CMP(cpu->edx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EDE3B, UINT32_C(0x004EDE25));
    cpu->ecx = (uint32_t)(cpu->edx);
    LIFT_IMUL32(cpu->ecx, UINT32_C(0x0000001A));
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_LOAD32(cpu->edx, cpu->ecx + cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + cpu->esi + UINT32_C(0x00000004)))), cpu->edi, 32u);
    LIFT_JNZ(label_000EDE20, UINT32_C(0x004EDE35));
    LIFT_EPILOGUE3(4u, cpu->esi, cpu->edi, cpu->ebp);
    LIFT_BLOCK(label_000EDE3B, UINT32_C(0x004EDE3B));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFF), |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_BLOCK(label_000EDE3E, UINT32_C(0x004EDE3E));
    LIFT_EPILOGUE3(4u, cpu->esi, cpu->edi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDE50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDE50));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(cpu->ecx, cpu->ebx);
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(cpu->ebx);
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000009)), 32u));
    cpu->edx = (uint32_t)((cpu->eax & UINT32_C(0xFFFF)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->esi, cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000008), cpu->eax);
    LIFT_CMP(cpu->esi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EDE7C, UINT32_C(0x004EDE72));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), (cpu->eax & UINT32_C(0xFF)), ^, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000EDE7C, UINT32_C(0x004EDE7C));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->ecx);
    LIFT_LOAD32(cpu->edx, cpu->eax + cpu->edi);
    LIFT_ADD(cpu->eax, cpu->edi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax + UINT32_C(0x00000004)))), cpu->ebx, 32u);
    LIFT_JZ(label_000EDEC6, UINT32_C(0x004EDE8E));
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EDE90, UINT32_C(0x004EDE90));
    LIFT_CMP(cpu->edx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EDEDE, UINT32_C(0x004EDE95));
    cpu->ecx = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_ADD(cpu->eax, cpu->edi, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->esi = (uint32_t)(cpu->edx);
    LIFT_LOAD32(cpu->edx, cpu->eax);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax + UINT32_C(0x00000004)))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EDE90, UINT32_C(0x004EDEA7));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000EDEC3, UINT32_C(0x004EDEAB));
    LIFT_STORE32(cpu->ecx, cpu->edx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->eax, cpu->edx);
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000008), cpu->esi);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000EDEC3, UINT32_C(0x004EDEC3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_BLOCK(label_000EDEC6, UINT32_C(0x004EDEC6));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->edi, cpu->edx);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->eax, cpu->edx);
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000008), cpu->esi);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000EDEDE, UINT32_C(0x004EDEDE));
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), (cpu->eax & UINT32_C(0xFF)), ^, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EDEF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDEF0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->esi, cpu->ebx);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004EDDF0, UINT32_C(0x004EDF03));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EDF13, UINT32_C(0x004EDF08));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFF), |, 32u, cpu->eax = (uint32_t)(result););
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
    LIFT_BLOCK(label_000EDF13, UINT32_C(0x004EDF13));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))), UINT32_C(0xFFFFFFFF), 32u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_JNZ(label_000EDFBD, UINT32_C(0x004EDF1E));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(UINT32_C(0x55555556));
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = (uint32_t)(cpu->edx);
    cpu->edi = (uint32_t)(lift_shift_right(cpu, cpu->edi, (uint32_t)(UINT32_C(0x0000001F)), 32u));
    LIFT_ADD(cpu->edi, cpu->edx, 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_CMP(cpu->edi, UINT32_C(0x00000032), 32u);
    LIFT_JGE(label_000EDF39, UINT32_C(0x004EDF34));
    cpu->edi = (uint32_t)(UINT32_C(0x00000032));
    LIFT_BLOCK(label_000EDF39, UINT32_C(0x004EDF39));
    cpu->eax = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), cpu->eax);
    LIFT_ADD(cpu->eax, cpu->edi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->eax);
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_realloc, UINT32_C(0x004EDF4A), UINT32_C(0x004EDF50));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EDF86, UINT32_C(0x004EDF59));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    LIFT_IMUL32(cpu->ecx, UINT32_C(0x0000001A));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"CHash32Mem: register_str. Not enough memory. Requested size = %d"), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Memory\\hash32mem.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000036));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EDF83));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EDF86, UINT32_C(0x004EDF86));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFF))));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE(label_000EDFAB, UINT32_C(0x004EDF8F));
    (void)cpu;
    LIFT_BLOCK(label_000EDF90, UINT32_C(0x004EDF90));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ebx, cpu->esi);
    LIFT_ADD(cpu->eax, cpu->ecx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_STORE32(cpu->eax + cpu->ebx, cpu->edx);
    LIFT_INC(cpu->ecx, 32u, cpu->ecx = (uint32_t)(result););
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFF))));
    LIFT_CMP(cpu->ecx, cpu->eax, 32u);
    LIFT_JL(label_000EDF90, UINT32_C(0x004EDFA8));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EDFAB, UINT32_C(0x004EDFAB));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_ADD(cpu->eax, cpu->edi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_STORE32(cpu->eax + cpu->ecx + UINT32_C(0xFFFFFFE6), UINT32_C(0xFFFFFFFF));
    LIFT_BLOCK(label_000EDFBD, UINT32_C(0x004EDFBD));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    LIFT_IMUL32(cpu->ecx, UINT32_C(0x0000001A));
    LIFT_ADD(cpu->ecx, lift_load32(((uint32_t)(cpu->esi))), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_STORE32(cpu->ecx + UINT32_C(0x00000004), cpu->ebx);
    LIFT_LOAD32(cpu->edi, cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), cpu->edi);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x00000004))));
    cpu->ebx = (uint32_t)(lift_shift_right(cpu, cpu->ebx, (uint32_t)(UINT32_C(0x00000009)), 32u));
    cpu->edi = (uint32_t)((cpu->ebx & UINT32_C(0xFFFF)));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->edi, cpu->esi);
    LIFT_STORE32(cpu->ecx, cpu->edi);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE32(cpu->esi, cpu->eax);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE32(cpu->ecx, cpu->edx);
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE000));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000534));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAEC), cpu->edx);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAF0), cpu->ebx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentProcess, UINT32_C(0x004EE027), UINT32_C(0x004EE02D));
    cpu->edi = (uint32_t)(cpu->eax);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x000000A4)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFB00))));
    LIFT_PUSH2(UINT32_C(0x00000000), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAF4), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004EE048));
    LIFT_LOAD32(cpu->edx, cpu->ebx + UINT32_C(0x000000C4));
    LIFT_LOAD32(cpu->ecx, cpu->ebx + UINT32_C(0x000000B8));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->eax = (uint32_t)(UINT32_C(0x00000003));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB24), cpu->edx);
    cpu->edx = (uint32_t)(SFERA_IMPORT_dbghelp_SymGetModuleBase);
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB08), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB2C), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB20), cpu->eax);
    cpu->eax = (uint32_t)(SFERA_IMPORT_dbghelp_SymFunctionTableAccess);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB00), cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->ebx + UINT32_C(0x000000B4));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB18), cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFB00))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAF8), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentThread, UINT32_C(0x004EE0A9), UINT32_C(0x004EE0AF));
    LIFT_PUSH3(cpu->eax, cpu->edi, UINT32_C(0x0000014C));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_StackWalk, UINT32_C(0x004EE0B6), UINT32_C(0x004EE0BC));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE2A4, UINT32_C(0x004EE0C4));
    LIFT_ADD(cpu->esi, UINT32_C(0x00000068), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_BLOCK(label_000EE0D0, UINT32_C(0x004EE0D0));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFB18)))), cpu->eax, 32u);
    LIFT_JZ(label_000EE2A4, UINT32_C(0x004EE0DE));
    LIFT_STORE32(cpu->esi + UINT32_C(0xFFFFFFB8), cpu->eax);
    cpu->edx = (uint32_t)(UINT32_C(0x6E6B6E55));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0xFFFFFF98))));
    LIFT_STORE32(cpu->ebx, cpu->edx);
    LIFT_LOAD32(cpu->ecx, (((uint32_t)(uintptr_t)"Unknown") + UINT32_C(0x00000004)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFAD0))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->eax);
    LIFT_STORE8(cpu->esi + UINT32_C(0xFFFFFFBC), (cpu->eax & UINT32_C(0xFF)));
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFAFF), (cpu->eax & UINT32_C(0xFF)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAD4), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAD8), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFADC), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAE0), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFACC))));
    LIFT_STORE32(cpu->ebx + UINT32_C(0x00000004), cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFB00));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAD0), UINT32_C(0x00000014));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_SymGetLineFromAddr, UINT32_C(0x004EE13B), UINT32_C(0x004EE141));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE1AD, UINT32_C(0x004EE145));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFADC));
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFAFF), UINT32_C(0x00000001));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000EE157, UINT32_C(0x004EE157));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EE157, UINT32_C(0x004EE15E));
    LIFT_SUB(cpu->eax, cpu->edi, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFF))));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JS(label_000EE179, UINT32_C(0x004EE169));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EE170, UINT32_C(0x004EE170));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + cpu->edx))), UINT32_C(0x0000005C), 8u);
    LIFT_JZ(label_000EE179, UINT32_C(0x004EE176));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EE170);
    LIFT_BLOCK(label_000EE179, UINT32_C(0x004EE179));
    LIFT_LOGIC(cpu->ecx, UINT32_C(0xFFFFFFFF), |, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->edi, cpu->ecx, 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_CMP(cpu->edi, UINT32_C(0x0000001F), 32u);
    LIFT_JL(label_000EE18C, UINT32_C(0x004EE185));
    cpu->edi = (uint32_t)(UINT32_C(0x0000001F));
    goto label_000EE190;
    LIFT_BLOCK(label_000EE18C, UINT32_C(0x004EE18C));
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JLE_GOTO(label_000EE1AD);
    LIFT_BLOCK(label_000EE190, UINT32_C(0x004EE190));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFAD8));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + cpu->edx + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->edx, cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0xFFFFFFB8), cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004EE1A0), UINT32_C(0x004EE1A6));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE8(cpu->ebx + cpu->edi, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EE1AD, UINT32_C(0x004EE1AD));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0xFFFFFAF4));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBA4))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_ZERO(cpu->eax, 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFAE4))));
    LIFT_PUSH2(cpu->edx, cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAE4), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAE8), cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFB00));
    LIFT_PUSH2(cpu->eax, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFBA4), UINT32_C(0x00000458));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFBF4), UINT32_C(0x00000400));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_SymFromAddr, UINT32_C(0x004EE1EC), UINT32_C(0x004EE1F2));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE243, UINT32_C(0x004EE1F6));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBF8))));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    (void)cpu;
    LIFT_BLOCK(label_000EE200, UINT32_C(0x004EE200));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EE200, UINT32_C(0x004EE207));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->edi, UINT32_C(0x0000003F), 32u);
    LIFT_JL(label_000EE217, UINT32_C(0x004EE210));
    cpu->edi = (uint32_t)(UINT32_C(0x0000003F));
    goto label_000EE21B;
    LIFT_BLOCK(label_000EE217, UINT32_C(0x004EE217));
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JLE_GOTO(label_000EE24C);
    LIFT_BLOCK(label_000EE21B, UINT32_C(0x004EE21B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFAE4));
    cpu->edx = ((int32_t)cpu->eax < 0) ? UINT32_C(0xFFFFFFFF) : 0u;
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFBF8))));
    LIFT_STORE32(cpu->esi, cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0xFFFFFFBC))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->edx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_strncpy, UINT32_C(0x004EE233), UINT32_C(0x004EE239));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE8(cpu->ebx + cpu->edi + UINT32_C(0x00000024), UINT32_C(0x00000000));
    goto label_000EE24C;
    LIFT_BLOCK(label_000EE243, UINT32_C(0x004EE243));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFAFF)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ_GOTO(label_000EE26A);
    LIFT_BLOCK(label_000EE24C, UINT32_C(0x004EE24C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFAF8));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(cpu->esi, UINT32_C(0x00000070), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAF8), cpu->eax);
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFAEC)))), 32u);
    LIFT_JZ(label_000EE2AA, UINT32_C(0x004EE264));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0xFFFFFAF4));
    LIFT_BLOCK(label_000EE26A, UINT32_C(0x004EE26A));
    cpu->edx = (uint32_t)(SFERA_IMPORT_dbghelp_SymGetModuleBase);
    cpu->eax = (uint32_t)(SFERA_IMPORT_dbghelp_SymFunctionTableAccess);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFAF0));
    LIFT_PUSH5(UINT32_C(0x00000000), cpu->edx, cpu->eax, UINT32_C(0x00000000), cpu->ecx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFB00))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentThread, UINT32_C(0x004EE289), UINT32_C(0x004EE28F));
    LIFT_PUSH3(cpu->eax, cpu->edi, UINT32_C(0x0000014C));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_StackWalk, UINT32_C(0x004EE296), UINT32_C(0x004EE29C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ_GOTO(label_000EE0D0);
    LIFT_BLOCK(label_000EE2A4, UINT32_C(0x004EE2A4));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFAF8));
    LIFT_BLOCK(label_000EE2AA, UINT32_C(0x004EE2AA));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EE2B7));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE2C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE2C0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x000002EC));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFD14), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFD18), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000004)));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_SymSetOptions, UINT32_C(0x004EE2E3), UINT32_C(0x004EE2E9));
    LIFT_PUSH2(UINT32_C(0x00000001), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentProcess, UINT32_C(0x004EE2ED), UINT32_C(0x004EE2F3));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_dbghelp_SymInitialize, UINT32_C(0x004EE2F4), UINT32_C(0x004EE2FA));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_000EE315, UINT32_C(0x004EE300));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->esi, cpu->eax + UINT32_C(0x00000004));
    cpu->ecx = (uint32_t)(UINT32_C(0x000000B3));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFD28))));
    lift_movs32(cpu, 1u);
    goto label_000EE366;
    LIFT_BLOCK(label_000EE315, UINT32_C(0x004EE315));
    LIFT_CALL(sfera_sub_004EE31A, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE31A)));
    LIFT_TAIL(sfera_sub_004EE31A);
    LIFT_BLOCK(label_000EE366, UINT32_C(0x004EE366));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFD28))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFD14));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFD18));
    LIFT_CALL_ENTER(sfera_sub_004EE000, UINT32_C(0x004EE37E));
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EE38A));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE31A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE31A));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFD24), lift_pop32(cpu));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFD20), cpu->ebp);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFD1C), cpu->esp);
    LIFT_PUSH2(UINT32_C(0x000002CC), UINT32_C(0x00000000));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFD28))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004EE33F));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFD24));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFDE0), cpu->edx);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFD20));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFDDC), cpu->eax);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFD1C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFDEC), cpu->ecx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFD28))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFD14));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFD18));
    LIFT_CALL_ENTER(sfera_sub_004EE000, UINT32_C(0x004EE37E));
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EE38A));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE390));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000001C));
    LIFT_PUSH3(cpu->esi, cpu->edi, UINT32_C(0x00000280));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_ZERO(cpu->esi, 32u);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EE80A, UINT32_C(0x004EE3AB));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), UINT32_C(0x00000000), 8u);
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000280), cpu->esi);
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000284), cpu->esi);
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000288), cpu->esi);
    LIFT_JZ(label_000EE461, UINT32_C(0x004EE3CA));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ebx = (uint32_t)(SFERA_IMPORT_MSVCR100_malloc);
    LIFT_ADD(cpu->edi, UINT32_C(0x00000004), 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0x0000000C), UINT32_C(0x00000014));
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EE3E0, UINT32_C(0x004EE3E0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000004), cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE3E6)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE3E4)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE3E6));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->edi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EE416, UINT32_C(0x004EE3EF));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Not enough memory. len = %d"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), ((uint32_t)(uintptr_t)"Logs\\AntifloodQueue.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), UINT32_C(0x0000001B));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EE413));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EE416, UINT32_C(0x004EE416));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->edi + UINT32_C(0x0000000C), cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE41C)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE41A)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE41C));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000008), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EE44D, UINT32_C(0x004EE426));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"Not enough memory. len = %d"), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), ((uint32_t)(uintptr_t)"Logs\\AntifloodQueue.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x00000020));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EE44A));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EE44D, UINT32_C(0x004EE44D));
    LIFT_ADD(cpu->edi, UINT32_C(0x00000020), 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_DEC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C))), (uint32_t)(result)););
    LIFT_JNZ(label_000EE3E0, UINT32_C(0x004EE455));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_POP3(cpu->ebx, cpu->edi, cpu->esi);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
    LIFT_BLOCK(label_000EE461, UINT32_C(0x004EE461));
    cpu->eax = (uint32_t)(cpu->edi);
    LIFT_POP2(cpu->edi, cpu->esi);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE470));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ebx = (uint32_t)(SFERA_IMPORT_MSVCR100_free);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x0000000C))));
    cpu->edi = (uint32_t)(UINT32_C(0x00000014));
    LIFT_BLOCK(label_000EE481, UINT32_C(0x004EE481));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0xFFFFFFF8));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE48E, UINT32_C(0x004EE488));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE48B)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE489)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE48B));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000EE48E, UINT32_C(0x004EE48E));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE49A, UINT32_C(0x004EE494));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE497)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE495)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE497));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000EE49A, UINT32_C(0x004EE49A));
    LIFT_ADD(cpu->esi, UINT32_C(0x00000020), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_JNZ(label_000EE481, UINT32_C(0x004EE4A0));
    LIFT_EPILOGUE3(0u, cpu->edi, cpu->esi, cpu->ebx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE4B0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000280));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE4C0));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000280)))), UINT32_C(0x00000014), 32u);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & UINT32_C(0xFF));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE4D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE4D0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000280)))), UINT32_C(0x00000000), 32u);
    LIFT_JG(label_000EE508, UINT32_C(0x004EE4E2));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"AntifloodQueue::pop_record: queue underflow"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Logs\\AntifloodQueue.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000074));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EE505));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EE508, UINT32_C(0x004EE508));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000288));
    LIFT_DEC(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000280)))), 32u, lift_store32(((uint32_t)(cpu->esi + UINT32_C(0x00000280))), (uint32_t)(result)););
    cpu->eax = (uint32_t)(cpu->ecx);
    cpu->eax = (uint32_t)(lift_shift_left(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000005)), 32u));
    LIFT_INC(cpu->ecx, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000288), cpu->ecx);
    LIFT_CMP(cpu->ecx, UINT32_C(0x00000014), 32u);
    LIFT_JNZ(label_000EE531, UINT32_C(0x004EE527));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000288), UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EE531, UINT32_C(0x004EE531));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE540(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE540));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000010));
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EE550, UINT32_C(0x004EE550));
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->ecx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EE550, UINT32_C(0x004EE557));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    LIFT_CMP(cpu->esi, lift_load32(((uint32_t)(cpu->ebx))), 32u);
    LIFT_JLE(label_000EE5AA, UINT32_C(0x004EE569));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + cpu->esi)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->ebx, cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_realloc, UINT32_C(0x004EE572), UINT32_C(0x004EE578));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->edi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EE5AA, UINT32_C(0x004EE581));
    LIFT_LOAD32(cpu->ecx, cpu->ebx);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"AntifloodQueue::copy_str: not enough memory. Len = %d"), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), ((uint32_t)(uintptr_t)"Logs\\AntifloodQueue.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000098));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EE5A7));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EE5AA, UINT32_C(0x004EE5AA));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->ecx, cpu->edi);
    LIFT_PUSH3(cpu->esi, cpu->eax, cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004EE804, UINT32_C(0x004EE5B7));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(12u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE5D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE5D0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000280));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->ecx + UINT32_C(0x00000288));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), UINT32_C(0xFFFFFFFF));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JLE(label_000EE684, UINT32_C(0x004EE5F9));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EE600, UINT32_C(0x004EE600));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    cpu->esi = (uint32_t)(cpu->edi);
    cpu->esi = (uint32_t)(lift_shift_left(cpu, cpu->esi, (uint32_t)(UINT32_C(0x00000005)), 32u));
    LIFT_LOAD32(cpu->edx, cpu->esi + cpu->ecx + UINT32_C(0x0000000C));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EE610, UINT32_C(0x004EE610));
    cpu->ebx = (cpu->ebx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_CMP((cpu->ebx & UINT32_C(0xFF)), lift_load8(((uint32_t)(cpu->edx))), 8u);
    LIFT_JNZ(label_000EE630, UINT32_C(0x004EE616));
    LIFT_TEST((cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000EE62C, UINT32_C(0x004EE61A));
    cpu->ebx = (cpu->ebx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_CMP((cpu->ebx & UINT32_C(0xFF)), lift_load8(((uint32_t)(cpu->edx + UINT32_C(0x00000001)))), 8u);
    LIFT_JNZ(label_000EE630, UINT32_C(0x004EE622));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000002), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(cpu->edx, UINT32_C(0x00000002), 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_TEST((cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ_GOTO(label_000EE610);
    LIFT_BLOCK(label_000EE62C, UINT32_C(0x004EE62C));
    LIFT_ZERO(cpu->eax, 32u);
    goto label_000EE635;
    LIFT_BLOCK(label_000EE630, UINT32_C(0x004EE630));
    LIFT_SUB(cpu->eax, cpu->eax, ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->eax, UINT32_C(0xFFFFFFFF), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_BLOCK(label_000EE635, UINT32_C(0x004EE635));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EE648, UINT32_C(0x004EE639));
    LIFT_LOAD32(cpu->edx, cpu->esi + cpu->ecx + UINT32_C(0x00000014));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), cpu->edx, 0u, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_CMP(lift_load8(((uint32_t)(cpu->esi + cpu->ecx))), (cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EE648, UINT32_C(0x004EE645));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->edi);
    LIFT_BLOCK(label_000EE648, UINT32_C(0x004EE648));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_CMP(cpu->edi, UINT32_C(0x00000014), 32u);
    LIFT_JNZ(label_000EE650, UINT32_C(0x004EE64E));
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_BLOCK(label_000EE650, UINT32_C(0x004EE650));
    LIFT_DEC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))), (uint32_t)(result)););
    LIFT_JNZ(label_000EE600, UINT32_C(0x004EE655));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_POP2(cpu->esi, cpu->ebx);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EE684, UINT32_C(0x004EE65F));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x0000000A), 32u);
    LIFT_JL(label_000EE684, UINT32_C(0x004EE665));
    cpu->eax = (uint32_t)(lift_shift_left(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000005)), 32u));
    LIFT_INC(lift_load32(((uint32_t)(cpu->eax + cpu->ecx + UINT32_C(0x00000014)))), 32u, lift_store32(((uint32_t)(cpu->eax + cpu->ecx + UINT32_C(0x00000014))), (uint32_t)(result)););
    LIFT_ADD(cpu->eax, cpu->ecx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(cpu->eax, UINT32_C(0x00000018), 0u, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004EE672), UINT32_C(0x004EE678));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
    LIFT_BLOCK(label_000EE684, UINT32_C(0x004EE684));
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), (cpu->eax & UINT32_C(0xFF)), ^, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE690(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE690));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000280)))), UINT32_C(0x00000014), 32u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_JL(label_000EE6CA, UINT32_C(0x004EE6A4));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_PUSH2(((uint32_t)(uintptr_t)"AntifloodQueue::push_record: queue overflow"), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), ((uint32_t)(uintptr_t)"Logs\\AntifloodQueue.cpp"));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x0000004E));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EE6C7));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EE6CA, UINT32_C(0x004EE6CA));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000284));
    cpu->edi = (uint32_t)(cpu->eax);
    cpu->edi = (uint32_t)(lift_shift_left(cpu, cpu->edi, (uint32_t)(UINT32_C(0x00000005)), 32u));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(cpu->edi, cpu->esi, 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000284), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0x00000014), 32u);
    LIFT_JNZ(label_000EE6EB, UINT32_C(0x004EE6E5));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000284), cpu->ebx);
    LIFT_BLOCK(label_000EE6EB, UINT32_C(0x004EE6EB));
    LIFT_INC(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000280)))), 32u, lift_store32(((uint32_t)(cpu->esi + UINT32_C(0x00000280))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0x00000018))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_time64, UINT32_C(0x004EE6F5), UINT32_C(0x004EE6FB));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0x00000004))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000014), UINT32_C(0x00000001));
    LIFT_STORE8(cpu->edi, UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EE540, UINT32_C(0x004EE71B));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0x00000010))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EE540, UINT32_C(0x004EE72E));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000280)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000008), cpu->ebx);
    LIFT_LOAD32(cpu->ebx, cpu->esi + UINT32_C(0x00000288));
    LIFT_JLE(label_000EE7C2, UINT32_C(0x004EE743));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000280));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->edx);
    cpu->esp = (uint32_t)(((uint32_t)(cpu->esp)));
    LIFT_BLOCK(label_000EE750, UINT32_C(0x004EE750));
    cpu->eax = (uint32_t)(cpu->ebx);
    cpu->eax = (uint32_t)(lift_shift_left(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000005)), 32u));
    LIFT_LOAD32(cpu->ecx, cpu->eax + cpu->esi + UINT32_C(0x0000000C));
    LIFT_ADD(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EE761, UINT32_C(0x004EE761));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_CMP((cpu->edx & UINT32_C(0xFF)), lift_load8(((uint32_t)(cpu->ecx))), 8u);
    LIFT_JNZ(label_000EE781, UINT32_C(0x004EE767));
    LIFT_TEST((cpu->edx & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000EE77D, UINT32_C(0x004EE76B));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax + UINT32_C(0x00000001))))) & UINT32_C(0xFF));
    LIFT_CMP((cpu->edx & UINT32_C(0xFF)), lift_load8(((uint32_t)(cpu->ecx + UINT32_C(0x00000001)))), 8u);
    LIFT_JNZ(label_000EE781, UINT32_C(0x004EE773));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000002), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000002), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TEST((cpu->edx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ_GOTO(label_000EE761);
    LIFT_BLOCK(label_000EE77D, UINT32_C(0x004EE77D));
    LIFT_ZERO(cpu->eax, 32u);
    goto label_000EE786;
    LIFT_BLOCK(label_000EE781, UINT32_C(0x004EE781));
    LIFT_SUB(cpu->eax, cpu->eax, ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->eax, UINT32_C(0xFFFFFFFF), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_BLOCK(label_000EE786, UINT32_C(0x004EE786));
    LIFT_TEST(cpu->eax, 32u);
    cpu->eax = (uint32_t)(UINT32_C(0x00000001));
    LIFT_JNZ(label_000EE792, UINT32_C(0x004EE78F));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), cpu->eax, 0u, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008))), (uint32_t)(result)););
    LIFT_BLOCK(label_000EE792, UINT32_C(0x004EE792));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ecx))), UINT32_C(0x00000000), 8u);
    LIFT_JNZ(label_000EE79D, UINT32_C(0x004EE79A));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), cpu->eax, 0u, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_BLOCK(label_000EE79D, UINT32_C(0x004EE79D));
    LIFT_ADD(cpu->ebx, cpu->eax, 0u, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_CMP(cpu->ebx, UINT32_C(0x00000014), 32u);
    LIFT_JNZ(label_000EE7A6, UINT32_C(0x004EE7A4));
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_BLOCK(label_000EE7A6, UINT32_C(0x004EE7A6));
    LIFT_SUB(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8)))), cpu->eax, 0u, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))), (uint32_t)(result)););
    LIFT_JNZ(label_000EE750, UINT32_C(0x004EE7AB));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x0000000A), 32u);
    LIFT_JGE(label_000EE7C2, UINT32_C(0x004EE7B1));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EE7C2, UINT32_C(0x004EE7B7));
    cpu->eax = (uint32_t)(cpu->edi);
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
    LIFT_BLOCK(label_000EE7C2, UINT32_C(0x004EE7C2));
    LIFT_POP2(cpu->edi, cpu->esi);
    LIFT_ZERO(cpu->eax, 32u);
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE7D0));
    cpu->eax = (uint32_t)(cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    LIFT_BLOCK(label_000EE7D6, UINT32_C(0x004EE7D6));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->eax)))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_TEST((cpu->edx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EE7D6, UINT32_C(0x004EE7DD));
    LIFT_SUB(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_JS_GOTO(label_000EE7EC);
    LIFT_BLOCK(label_000EE7E3, UINT32_C(0x004EE7E3));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax + cpu->ecx))), UINT32_C(0x0000005C), 8u);
    LIFT_JZ(label_000EE7EC, UINT32_C(0x004EE7E9));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EE7E3);
    LIFT_BLOCK(label_000EE7EC, UINT32_C(0x004EE7EC));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax + cpu->ecx + UINT32_C(0x00000001))));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE7F2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE7F2));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_Sound_CSound_Play, UINT32_C(0x004EE7F2));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE7F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE7F8));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_Sound_CSound_Stop, UINT32_C(0x004EE7F8));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE7FE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE7FE));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_Sound_CSound_Rewind, UINT32_C(0x004EE7FE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE804(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE804));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_memcpy, UINT32_C(0x004EE804));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE80A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE80A));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_memset, UINT32_C(0x004EE80A));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE810));
    (void)stop_address;
    if (cpu->ecx == g_sfera_security_cookie) { LIFT_RET(0u); }
    lift_push32(cpu, UINT32_C(0xC0000409));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentProcess, UINT32_C(0x004EF249), UINT32_C(0x004EF24F));
    lift_push32(cpu, cpu->eax);
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_TerminateProcess, UINT32_C(0x004EF250), UINT32_C(0x004EF256));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE81F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE81F));
    LIFT_PUSH2(UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EE82B));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F9078C_U32));
    cpu->esi = SFERA_IMPORT_KERNEL32_DecodePointer;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE839)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE837)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE839));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EE84D, UINT32_C(0x004EE841));
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008))))));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_onexit, UINT32_C(0x004EE844), UINT32_C(0x004EE84A));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    goto label_000EE8B1;
    LIFT_BLOCK(label_000EE84D, UINT32_C(0x004EE84D));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EF264, UINT32_C(0x004EE854));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F9078C_U32));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE861)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE85F)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE861));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->eax);
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F90788_U32));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE86C)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE86A)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE86C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))));
    cpu->esi = SFERA_IMPORT_KERNEL32_EncodePointer;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE882)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE880)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE882));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EF25E, UINT32_C(0x004EE888));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), cpu->eax);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))))));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE893)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE891)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE893));
    SFERA_STATIC_04F9078C_U32 = (uint32_t)(cpu->eax);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))))));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE89D)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EE89B)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE89D));
    SFERA_STATIC_04F90788_U32 = (uint32_t)(cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EE8B7, UINT32_C(0x004EE8AE));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFDC));
    LIFT_BLOCK(label_000EE8B1, UINT32_C(0x004EE8B1));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EE8B6));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE8B7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE8B7));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EF258, UINT32_C(0x004EE8BE));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE8C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE8C0));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008))))));
    LIFT_CALL_ENTER(sfera_sub_004EE81F, UINT32_C(0x004EE8CD));
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->eax, cpu->eax, ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_DEC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE8D7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE8D7));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000002), &, 8u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_JZ(label_000EE90A, UINT32_C(0x004EE8E5));
    LIFT_PUSH2(cpu->esi, LIFT_CALLBACK_RVA(UINT32_C(0x000EF5B4)));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0xFFFFFFFC))));
    LIFT_PUSH3(lift_load32(((uint32_t)(cpu->esi))), UINT32_C(0x0000000C), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_004EEB86, UINT32_C(0x004EE8F8));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000EE905, UINT32_C(0x004EE8FE));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004EE904));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EE905, UINT32_C(0x004EE905));
    cpu->eax = (uint32_t)(cpu->esi);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    goto label_000EE91E;
    LIFT_BLOCK(label_000EE90A, UINT32_C(0x004EE90A));
    LIFT_CALL_ENTER(sfera_sub_004EF5B4, UINT32_C(0x004EE90F));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000EE91C, UINT32_C(0x004EE915));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004EE91B));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EE91C, UINT32_C(0x004EE91C));
    cpu->eax = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EE91E, UINT32_C(0x004EE91E));
    LIFT_EPILOGUE2(4u, cpu->edi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE924(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE924));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_exception_what, UINT32_C(0x004EE924));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE92A(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(UINT32_C(0x004EE92A)); (void)stop_address; lift_trap(cpu, UINT32_C(0x004EE92A), "client C++ exception path reached"); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE930));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_exception_ctor_325, UINT32_C(0x004EE930));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE940));
    LIFT_CMP(SFERA_STATIC_04F9077C_U32, UINT32_C(0x00000000), 32u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u)) {
        sfera_sub_004EE976(cpu, stop_address);
        return;
    }
    LIFT_ENTER(UINT32_C(0x004EE949));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000008));
    LIFT_LOGIC(cpu->esp, UINT32_C(0xFFFFFFF8), &, 32u, cpu->esp = (uint32_t)(result););
    lift_store_f64(((uint32_t)(cpu->esp)), (double)(lift_x87_get(cpu, 0u)));
    lift_x87_pop(cpu);
    cpu->eax = (uint32_t)((uint32_t)(int32_t)trunc(lift_load_f64(((uint32_t)(cpu->esp)))));
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE976(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE976));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000020));
    LIFT_LOGIC(cpu->esp, UINT32_C(0xFFFFFFF0), &, 32u, cpu->esp = (uint32_t)(result););
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    LIFT_X87_STORE_F32(cpu->esp + UINT32_C(0x00000018));
    lift_store64(((uint32_t)(cpu->esp + UINT32_C(0x00000010))), (uint64_t)(lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u)));
    lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(((uint32_t)(cpu->esp + UINT32_C(0x00000010))))))));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ_GOTO(label_000EE9D5);
    LIFT_BLOCK(label_000EE999, UINT32_C(0x004EE999));
    LIFT_X87_SUB_POP(1u);
    LIFT_TEST(cpu->edx, 32u);
    LIFT_JNS(label_000EE9BD, UINT32_C(0x004EE99F));
    LIFT_X87_STORE_F32_POP(cpu->esp);
    LIFT_LOAD32(cpu->ecx, cpu->esp);
    LIFT_LOGIC(cpu->ecx, UINT32_C(0x80000000), ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->ecx, UINT32_C(0x7FFFFFFF), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->eax, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000014));
    LIFT_ADD(cpu->edx, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->edx = (uint32_t)(result););
    goto label_000EE9E9;
    LIFT_BLOCK(label_000EE9BD, UINT32_C(0x004EE9BD));
    LIFT_X87_STORE_F32_POP(cpu->esp);
    LIFT_LOAD32(cpu->ecx, cpu->esp);
    LIFT_ADD(cpu->ecx, UINT32_C(0x7FFFFFFF), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_SUB(cpu->eax, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000014));
    LIFT_SUB(cpu->edx, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->edx = (uint32_t)(result););
    goto label_000EE9E9;
    LIFT_BLOCK(label_000EE9D5, UINT32_C(0x004EE9D5));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000014));
    LIFT_LOGIC_FLAGS(cpu->edx, UINT32_C(0x7FFFFFFF), &, 32u);
    LIFT_JNZ(label_000EE999, UINT32_C(0x004EE9E1));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x00000018));
    LIFT_X87_STORE_F32_POP(cpu->esp + UINT32_C(0x00000018));
    LIFT_BLOCK(label_000EE9E9, UINT32_C(0x004EE9E9));
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9EC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9EC));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIsqrt, UINT32_C(0x004EE9EC));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9F2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9F2));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIcos, UINT32_C(0x004EE9F2));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9F8));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIsin, UINT32_C(0x004EE9F8));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EE9FE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9FE));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIpow, UINT32_C(0x004EE9FE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEA10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEA10));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000008))));
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_LOGIC(cpu->ecx, UINT32_C(0x0000000F), &, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_ADD(cpu->eax, cpu->ecx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->ecx, cpu->ecx, ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->ecx = (uint32_t)(result););
    LIFT_LOGIC(cpu->eax, cpu->ecx, |, 32u, cpu->eax = (uint32_t)(result););
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_TAIL(sfera_sub_004EEAF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEA40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEA40));
    LIFT_PUSH3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000014));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JGE(label_000EEA61, UINT32_C(0x004EEA4D));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000010));
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_NEG(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_SUB(cpu->eax, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), cpu->eax);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->edx);
    LIFT_BLOCK(label_000EEA61, UINT32_C(0x004EEA61));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x0000001C));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JGE(label_000EEA7D, UINT32_C(0x004EEA69));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000018));
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_NEG(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_SUB(cpu->eax, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000001C), cpu->eax);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->edx);
    LIFT_BLOCK(label_000EEA7D, UINT32_C(0x004EEA7D));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNZ(label_000EEA99, UINT32_C(0x004EEA81));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000014));
    LIFT_ZERO(cpu->edx, 32u);
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx = (uint32_t)(cpu->ebx);
    goto label_000EEADA;
    LIFT_BLOCK(label_000EEA99, UINT32_C(0x004EEA99));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    LIFT_BLOCK(label_000EEAA7, UINT32_C(0x004EEAA7));
    cpu->ebx = (uint32_t)(lift_shift_right(cpu, cpu->ebx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->ecx = (uint32_t)(lift_rotate_carry_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->edx = (uint32_t)(lift_shift_right(cpu, cpu->edx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->eax = (uint32_t)(lift_rotate_carry_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->ebx, cpu->ebx, |, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_JNZ(label_000EEAA7, UINT32_C(0x004EEAB3));
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->esi = (uint32_t)(cpu->eax);
    lift_multiply_accumulator(cpu, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x0000001C)))), 32u, 0u);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000018));
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 0u);
    LIFT_ADD(cpu->edx, cpu->ecx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_JB(label_000EEAD5, UINT32_C(0x004EEAC7));
    LIFT_CMP(cpu->edx, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000014)))), 32u);
    LIFT_JA(label_000EEAD5, UINT32_C(0x004EEACD));
    LIFT_JB(label_000EEAD6, UINT32_C(0x004EEACF));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000010)))), 32u);
    LIFT_JBE_GOTO(label_000EEAD6);
    LIFT_BLOCK(label_000EEAD5, UINT32_C(0x004EEAD5));
    LIFT_DEC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_BLOCK(label_000EEAD6, UINT32_C(0x004EEAD6));
    LIFT_ZERO(cpu->edx, 32u);
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_BLOCK(label_000EEADA, UINT32_C(0x004EEADA));
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_JNZ(label_000EEAE4, UINT32_C(0x004EEADD));
    LIFT_NEG(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->edx, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->edx = (uint32_t)(result););
    LIFT_BLOCK(label_000EEAE4, UINT32_C(0x004EEAE4));
    LIFT_EPILOGUE3(16u, cpu->ebx, cpu->esi, cpu->edi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEAF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEAF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000004))));
    LIFT_SUB(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_SUB(cpu->eax, cpu->eax, ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    cpu->eax = (uint32_t)(~((uint64_t)(cpu->eax)));
    LIFT_LOGIC(cpu->ecx, cpu->eax, &, 32u, cpu->ecx = (uint32_t)(result););
    cpu->eax = (uint32_t)(cpu->esp);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFF000), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_BLOCK(label_000EEB04, UINT32_C(0x004EEB04));
    LIFT_CMP(cpu->ecx, cpu->eax, 32u);
    LIFT_JB(label_000EEB12, UINT32_C(0x004EEB08));
    cpu->eax = (uint32_t)(cpu->ecx);
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    {
        uint64_t left = cpu->esp;
        uint64_t right = cpu->eax;
        cpu->esp = (uint32_t)(right);
        cpu->eax = (uint32_t)(left);
    }
    LIFT_LOAD32(cpu->eax, cpu->eax);
    LIFT_STORE32(cpu->esp, cpu->eax);
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EEB12, UINT32_C(0x004EEB12));
    LIFT_SUB(cpu->eax, UINT32_C(0x00001000), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC_FLAGS(lift_load32(((uint32_t)(cpu->eax))), cpu->eax, &, 32u);
    goto label_000EEB04;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB1C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB1C));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_free, UINT32_C(0x004EEB1C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB22(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB22));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_purecall, UINT32_C(0x004EEB22));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB28(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB28));
    LIFT_PUSH2(UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EEB34));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_BLOCK(label_000EEB38, UINT32_C(0x004EEB38));
    LIFT_DEC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010))), (uint32_t)(result)););
    LIFT_JS(label_000EEB77, UINT32_C(0x004EEB3D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_SUB(cpu->ecx, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000008), cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014))))), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEB49)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEB46)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EEB49));
    goto label_000EEB38;
    LIFT_BLOCK(label_000EEB77, UINT32_C(0x004EEB77));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EEB83));
    LIFT_RET(16u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB4B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB4B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_LOAD32(cpu->eax, cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax))), UINT32_C(0xE06D7363), 32u);
    LIFT_JZ(label_000EEB6F, UINT32_C(0x004EEB64));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFDC));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EEB6F, UINT32_C(0x004EEB6F));
    LIFT_CALL(sfera_sub_004EF2DA, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEB74)));
    LIFT_TAIL(sfera_sub_004EEB74);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB74(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB74));
    LIFT_LOAD32(cpu->esp, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EEB83));
    LIFT_RET(16u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEB86(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB86));
    LIFT_PUSH2(UINT32_C(0x0000000C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EEB92));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x0000000C));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_IMUL32(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), cpu->eax, 0u, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008))), (uint32_t)(result)););
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_BLOCK(label_000EEBA6, UINT32_C(0x004EEBA6));
    LIFT_DEC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010))), (uint32_t)(result)););
    LIFT_JS(label_000EEBB6, UINT32_C(0x004EEBAB));
    LIFT_SUB(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), cpu->esi, 0u, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014))))), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEBB4)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEBB1)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EEBB4));
    goto label_000EEBA6;
    LIFT_BLOCK(label_000EEBB6, UINT32_C(0x004EEBB6));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000001));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EEBD1, UINT32_C(0x004EEBC9));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EEBCE));
    LIFT_RET(16u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEBD1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEBD1));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000EEBE8, UINT32_C(0x004EEBD7));
    LIFT_PUSH4(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))));
    LIFT_CALL(sfera_sub_004EEB28, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEBE8)));
    LIFT_BLOCK(label_000EEBE8, UINT32_C(0x004EEBE8));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEBE9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEBE9));
    LIFT_PUSH2(UINT32_C(0x00000010), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EEBF5));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->eax);
    LIFT_BLOCK(label_000EEC00, UINT32_C(0x004EEC00));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), 32u);
    LIFT_JGE(label_000EEC1B, UINT32_C(0x004EEC08));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x00000008));
    cpu->ecx = (uint32_t)(cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014))))), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEC10)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEC0D)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EEC10));
    LIFT_ADD(cpu->esi, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000008), cpu->esi);
    LIFT_INC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))), (uint32_t)(result)););
    goto label_000EEC00;
    LIFT_BLOCK(label_000EEC1B, UINT32_C(0x004EEC1B));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000001));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EEC36, UINT32_C(0x004EEC2E));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EEC33));
    LIFT_RET(20u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC36(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEC36));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0)))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000EEC4D, UINT32_C(0x004EEC3C));
    LIFT_PUSH4(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000018)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))));
    LIFT_CALL(sfera_sub_004EEB28, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEC4D)));
    LIFT_BLOCK(label_000EEC4D, UINT32_C(0x004EEC4D));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC4E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEC4E));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIatan2, UINT32_C(0x004EEC4E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC54(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEC54));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIexp, UINT32_C(0x004EEC54));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEC60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEC60));
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JGE(label_000EEC80, UINT32_C(0x004EEC6C));
    LIFT_INC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x0000000C));
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_NEG(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_SUB(cpu->eax, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->eax);
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->edx);
    LIFT_BLOCK(label_000EEC80, UINT32_C(0x004EEC80));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000018));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JGE(label_000EEC9B, UINT32_C(0x004EEC88));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000014));
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_NEG(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_SUB(cpu->eax, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->eax);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), cpu->edx);
    LIFT_BLOCK(label_000EEC9B, UINT32_C(0x004EEC9B));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNZ(label_000EECBA, UINT32_C(0x004EEC9F));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    LIFT_ZERO(cpu->edx, 32u);
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x0000000C));
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_JNS(label_000EED06, UINT32_C(0x004EECB8));
    goto label_000EED0D;
    LIFT_BLOCK(label_000EECBA, UINT32_C(0x004EECBA));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EECC8, UINT32_C(0x004EECC8));
    cpu->ebx = (uint32_t)(lift_shift_right(cpu, cpu->ebx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->ecx = (uint32_t)(lift_rotate_carry_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->edx = (uint32_t)(lift_shift_right(cpu, cpu->edx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->eax = (uint32_t)(lift_rotate_carry_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->ebx, cpu->ebx, |, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_JNZ(label_000EECC8, UINT32_C(0x004EECD4));
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ecx = (uint32_t)(cpu->eax);
    lift_multiply_accumulator(cpu, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000018)))), 32u, 0u);
    {
        uint64_t left = cpu->ecx;
        uint64_t right = cpu->eax;
        cpu->ecx = (uint32_t)(right);
        cpu->eax = (uint32_t)(left);
    }
    lift_multiply_accumulator(cpu, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000014)))), 32u, 0u);
    LIFT_ADD(cpu->edx, cpu->ecx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_JB(label_000EECF3, UINT32_C(0x004EECE5));
    LIFT_CMP(cpu->edx, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000010)))), 32u);
    LIFT_JA(label_000EECF3, UINT32_C(0x004EECEB));
    LIFT_JB(label_000EECFB, UINT32_C(0x004EECED));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x0000000C)))), 32u);
    LIFT_JBE_GOTO(label_000EECFB);
    LIFT_BLOCK(label_000EECF3, UINT32_C(0x004EECF3));
    LIFT_SUB(cpu->eax, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000014)))), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->edx, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000018)))), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->edx = (uint32_t)(result););
    LIFT_BLOCK(label_000EECFB, UINT32_C(0x004EECFB));
    LIFT_SUB(cpu->eax, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x0000000C)))), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->edx, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000010)))), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->edx = (uint32_t)(result););
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_JNS_GOTO(label_000EED0D);
    LIFT_BLOCK(label_000EED06, UINT32_C(0x004EED06));
    LIFT_NEG(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_NEG(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(cpu->edx, UINT32_C(0x00000000), ((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), 32u, cpu->edx = (uint32_t)(result););
    LIFT_BLOCK(label_000EED0D, UINT32_C(0x004EED0D));
    LIFT_EPILOGUE2(16u, cpu->edi, cpu->ebx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED20));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    LIFT_LOGIC(cpu->ecx, cpu->eax, |, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    LIFT_JNZ(label_000EED39, UINT32_C(0x004EED30));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000004));
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    LIFT_RET(16u);
    LIFT_BLOCK(label_000EED39, UINT32_C(0x004EED39));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000008));
    lift_multiply_accumulator(cpu, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000014)))), 32u, 0u);
    LIFT_ADD(cpu->ebx, cpu->eax, 0u, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000008));
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 0u);
    LIFT_ADD(cpu->edx, cpu->ebx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_EPILOGUE1(16u, cpu->ebx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED54(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED54));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CItan, UINT32_C(0x004EED54));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED5A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED5A));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIacos, UINT32_C(0x004EED5A));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED60));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIatan, UINT32_C(0x004EED60));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED66(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED66));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_floor, UINT32_C(0x004EED66));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED6C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED6C));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_CIasin, UINT32_C(0x004EED6C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EED80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED80));
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000018));
    LIFT_LOGIC(cpu->eax, cpu->eax, |, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JNZ(label_000EEDA2, UINT32_C(0x004EED8A));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    LIFT_ZERO(cpu->edx, 32u);
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x0000000C));
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx = (uint32_t)(cpu->ebx);
    goto label_000EEDE3;
    LIFT_BLOCK(label_000EEDA2, UINT32_C(0x004EEDA2));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->ebx, cpu->esp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EEDB0, UINT32_C(0x004EEDB0));
    cpu->ecx = (uint32_t)(lift_shift_right(cpu, cpu->ecx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->ebx = (uint32_t)(lift_rotate_carry_right(cpu, cpu->ebx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->edx = (uint32_t)(lift_shift_right(cpu, cpu->edx, (uint32_t)(UINT32_C(0x00000001)), 32u));
    cpu->eax = (uint32_t)(lift_rotate_carry_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000001)), 32u));
    LIFT_LOGIC(cpu->ecx, cpu->ecx, |, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_JNZ(label_000EEDB0, UINT32_C(0x004EEDBC));
    lift_divide_accumulator(cpu, cpu->ebx, 32u, 0u);
    cpu->esi = (uint32_t)(cpu->eax);
    lift_multiply_accumulator(cpu, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000018)))), 32u, 0u);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000014));
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 0u);
    LIFT_ADD(cpu->edx, cpu->ecx, 0u, 32u, cpu->edx = (uint32_t)(result););
    LIFT_JB(label_000EEDDE, UINT32_C(0x004EEDD0));
    LIFT_CMP(cpu->edx, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x00000010)))), 32u);
    LIFT_JA(label_000EEDDE, UINT32_C(0x004EEDD6));
    LIFT_JB(label_000EEDDF, UINT32_C(0x004EEDD8));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x0000000C)))), 32u);
    LIFT_JBE_GOTO(label_000EEDDF);
    LIFT_BLOCK(label_000EEDDE, UINT32_C(0x004EEDDE));
    LIFT_DEC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_BLOCK(label_000EEDDF, UINT32_C(0x004EEDDF));
    LIFT_ZERO(cpu->edx, 32u);
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_BLOCK(label_000EEDE3, UINT32_C(0x004EEDE3));
    LIFT_EPILOGUE2(16u, cpu->esi, cpu->ebx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEDF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEDF0));
    LIFT_CMP((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x00000040), 8u);
    LIFT_JAE(label_000EEE0A, UINT32_C(0x004EEDF5));
    LIFT_CMP((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x00000020), 8u);
    LIFT_JAE(label_000EEE00, UINT32_C(0x004EEDFA));
    cpu->edx = (uint32_t)(lift_double_shift_left(cpu, cpu->edx, cpu->eax, (uint32_t)((cpu->ecx & UINT32_C(0xFF))), 32u));
    cpu->eax = (uint32_t)(lift_shift_left(cpu, cpu->eax, (uint32_t)((cpu->ecx & UINT32_C(0xFF))), 32u));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EEE00, UINT32_C(0x004EEE00));
    cpu->edx = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_LOGIC((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x0000001F), &, 8u, cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->edx = (uint32_t)(lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & UINT32_C(0xFF))), 32u));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EEE0A, UINT32_C(0x004EEE0A));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE10));
    LIFT_CMP((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x00000040), 8u);
    LIFT_JAE(label_000EEE2A, UINT32_C(0x004EEE15));
    LIFT_CMP((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x00000020), 8u);
    LIFT_JAE(label_000EEE20, UINT32_C(0x004EEE1A));
    cpu->eax = (uint32_t)(lift_double_shift_right(cpu, cpu->eax, cpu->edx, (uint32_t)((cpu->ecx & UINT32_C(0xFF))), 32u));
    cpu->edx = (uint32_t)(lift_shift_right(cpu, cpu->edx, (uint32_t)((cpu->ecx & UINT32_C(0xFF))), 32u));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EEE20, UINT32_C(0x004EEE20));
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_LOGIC((cpu->ecx & UINT32_C(0xFF)), UINT32_C(0x0000001F), &, 8u, cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)((cpu->ecx & UINT32_C(0xFF))), 32u));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EEE2A, UINT32_C(0x004EEE2A));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE30));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_bad_cast_dtor, UINT32_C(0x004EEE30));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE36(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE36));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_bad_cast_ctor, UINT32_C(0x004EEE36));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EEE61(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE61));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_RVA(UINT32_C(0x000EF362))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004EEE6B));
    LIFT_LOAD32(cpu->eax, SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90760)));
    LIFT_STORE32(cpu->esp, SFERA_STATIC_04F9042C_ADDR);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F9075C)))))));
    SFERA_STATIC_04F9042C_U32 = (uint32_t)(cpu->eax);
    LIFT_PUSH3(SFERA_DATA_CALL_ARGUMENT_04F9041C_ADDR, SFERA_DATA_CALL_ARGUMENT_04F90420_ADDR, SFERA_DATA_CALL_ARGUMENT_04F90418_ADDR);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_getmainargs, UINT32_C(0x004EEE91), UINT32_C(0x004EEE97));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_STORE32(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90428)), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNS(label_000EEEAB, UINT32_C(0x004EEEA3));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EF336, UINT32_C(0x004EEEAA));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EEEAB, UINT32_C(0x004EEEAB));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF038(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF038));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), cpu->ecx);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004EF388, UINT32_C(0x004EF049));
    LIFT_EPILOGUE2(0u, cpu->ecx, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF04C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF04C));
    LIFT_LOAD32(cpu->esp, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFD8));
    SFERA_STATIC_04F90430_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_CMP(SFERA_STATIC_04F90424_U32, cpu->ebx, 32u);
    LIFT_JNZ(label_000EF068, UINT32_C(0x004EF061));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    lift_import_call(cpu, SFERA_IMPORT_MSVCR100_exit, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF062)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF068));
    LIFT_BLOCK(label_000EF068, UINT32_C(0x004EF068));
    LIFT_CMP(SFERA_STATIC_04F90434_U32, cpu->ebx, 32u);
    LIFT_JNZ(label_000EF076, UINT32_C(0x004EF070));
    lift_import_call(cpu, SFERA_IMPORT_MSVCR100_cexit, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF070)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF076));
    LIFT_BLOCK(label_000EF076, UINT32_C(0x004EF076));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F90430_U32);
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EF087));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF088(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF088));
    cpu->eax = 0u;
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000002)));
    SFERA_STATIC_04F90424_U32 = 0u;
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_set_app_type, UINT32_C(0x004EF0D6), UINT32_C(0x004EF0DC));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    lift_push32(cpu, (uint32_t)(UINT32_C(0xFFFFFFFF)));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_EncodePointer, UINT32_C(0x004EF0DF), UINT32_C(0x004EF0E5));
    LIFT_LOAD32(cpu->ecx, SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90768)));
    SFERA_STATIC_04F90788_U32 = (uint32_t)(cpu->eax);
    SFERA_STATIC_04F9078C_U32 = (uint32_t)(cpu->eax);
    cpu->eax = SFERA_IMPORT_MSVCR100_fmode;
    LIFT_STORE32(cpu->eax, cpu->ecx);
    cpu->eax = SFERA_IMPORT_MSVCR100_commode;
    LIFT_LOAD32(cpu->ecx, SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90764)));
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004EF33C, UINT32_C(0x004EF10E));
    LIFT_CALL_ENTER(sfera_sub_004EF510, UINT32_C(0x004EF113));
    LIFT_BLOCK(label_000EF128, UINT32_C(0x004EF128));
    LIFT_CALL_ENTER(sfera_sub_004EF4E8, UINT32_C(0x004EF12D));
    LIFT_BLOCK(label_000EF13F, UINT32_C(0x004EF13F));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF142(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF142;
    LIFT_BLOCK(label_000EEEAF, UINT32_C(0x004EEEAF));
    LIFT_PUSH2(UINT32_C(0x0000005C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EEEBB));
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->ebx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF94))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetStartupInfoW, UINT32_C(0x004EEEC4), UINT32_C(0x004EEECA));
    LIFT_CMP(lift_load32(((uint32_t)(SFERA_DATA_SEMANTIC_VA(UINT32_C(0x04F90780))))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EEEDD, UINT32_C(0x004EEED2));
    LIFT_PUSH4(cpu->ebx, cpu->ebx, UINT32_C(0x00000001), cpu->ebx);
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_HeapSetInformation, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEED7)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEEDD));
    LIFT_BLOCK(label_000EEEDD, UINT32_C(0x004EEEDD));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000018)))));
    LIFT_LOAD32(cpu->esi, cpu->eax + UINT32_C(0x00000004));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), cpu->ebx);
    cpu->edi = (uint32_t)(SFERA_DATA_GLOBAL_OBJECT_04F90778_ADDR);
    LIFT_BLOCK(label_000EEEF1, UINT32_C(0x004EEEF1));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_InterlockedCompareExchange, UINT32_C(0x004EEEF4), UINT32_C(0x004EEEFA));
    LIFT_CMP(cpu->eax, cpu->ebx, 32u);
    LIFT_JZ(label_000EEF17, UINT32_C(0x004EEEFE));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EEF0A, UINT32_C(0x004EEF02));
    LIFT_ZERO(cpu->esi, 32u);
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), cpu->esi);
    goto label_000EEF1A;
    LIFT_BLOCK(label_000EEF0A, UINT32_C(0x004EEF0A));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x000003E8)));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_Sleep, UINT32_C(0x004EEF0F), UINT32_C(0x004EEF15));
    goto label_000EEEF1;
    LIFT_BLOCK(label_000EEF17, UINT32_C(0x004EEF17));
    LIFT_ZERO(cpu->esi, 32u);
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_BLOCK(label_000EEF1A, UINT32_C(0x004EEF1A));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F90774_U32);
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EEF2D, UINT32_C(0x004EEF23));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000001F)));
    LIFT_CALL_ENTER(sfera_sub_004EF336, UINT32_C(0x004EEF2A));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    goto label_000EEF68;
    LIFT_BLOCK(label_000EEF2D, UINT32_C(0x004EEF2D));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F90774_U32);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EEF62, UINT32_C(0x004EEF36));
    SFERA_STATIC_04F90774_U32 = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EF088, UINT32_C(0x004EEF4B));
    if (cpu->eax == 0u) {
        LIFT_CALL_ENTER(sfera_sub_004EF2C9, UINT32_C(0x004EEF4B));
        if (cpu->eax == 0u) {
            LIFT_CALL_ENTER(sfera_sub_004EF328, UINT32_C(0x004EEF4B));
        }
    }
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EEF68, UINT32_C(0x004EEF51));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    cpu->eax = (uint32_t)(UINT32_C(0x000000FF));
    goto label_000EF082;
    LIFT_BLOCK(label_000EEF62, UINT32_C(0x004EEF62));
    SFERA_STATIC_04F90434_U32 = (uint32_t)(cpu->esi);
    LIFT_BLOCK(label_000EEF68, UINT32_C(0x004EEF68));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F90774_U32);
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EEF8C, UINT32_C(0x004EEF71));
    LIFT_CALL_ENTER(sfera_sub_004EEE61, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004FA041, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4AE0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4B10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4B50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4B80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4BC0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4BF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4C30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4C60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4CA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4CD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4D10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4D40, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4D80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4DB0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4DF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4E20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4E60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4EA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4ED0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4F10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4F40, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4F80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4FB0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F4FF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5070, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F50E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F50F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5120, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5160, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5190, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F51D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F51F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5270, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5330, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5360, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F53A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F53D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5410, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5430, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5450, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5480, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F54C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F54F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5530, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5550, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5570, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5580, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5590, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F55B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F55E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5620, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5690, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5700, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5770, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F57A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F57E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5810, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5850, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5870, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5890, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5920, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F59B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5A40, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5AD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5B60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5BF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5C80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5C90, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5D20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5DB0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5DD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5DE0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5E50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5EC0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5F30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F5FA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6010, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6080, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F60F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6160, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F61D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6240, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F62B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6320, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6390, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6400, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6470, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6510, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6580, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6650, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6720, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F67F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F68C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6950, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F69C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6A30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6AA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6B10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6B80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6C10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6C80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6CF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6D60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6DD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6E40, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6EB0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6F20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F6FA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7010, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7080, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F70F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7160, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F71D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7240, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F72B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7320, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7390, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7400, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7470, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F74E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7550, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F75C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7630, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F76A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7710, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7780, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F77B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F77F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7820, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7860, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7890, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F78D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7900, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7940, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7970, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F79B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F79E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7A20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7A50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7A90, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7AC0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7B00, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7B30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7B70, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7BA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7BE0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7BF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7C20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7C60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7C80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7CA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7CD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7D10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7D40, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7D80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7DB0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7DF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7E00, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7E30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7E70, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7EA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7EE0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7EF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7F20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7F60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7F90, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F7FD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8000, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8040, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8070, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F80B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8120, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8150, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8190, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F81C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8200, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8220, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8240, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8270, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F82B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F82D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F82F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8320, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8360, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8390, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F83D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F83F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8410, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8440, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8480, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F84A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F84C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F84F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8530, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8550, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8570, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F85A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F85E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F85F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8620, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8660, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8680, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F86A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F86D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8710, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8740, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8780, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F87A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F87C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F87F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8830, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8850, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8870, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F88A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F88E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8900, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8920, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8950, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8990, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F89B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F89D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8A00, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8A40, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8A60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8A80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8AB0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8AF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8B10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8B30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8B90, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8BF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8C50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8C60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8D20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8D80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8DA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8DD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8E10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8E30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8E50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8E80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8EC0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8EF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8F30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8F50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8F70, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8FA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F8FE0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9000, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9020, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9040, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9060, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9080, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F90B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F90F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9110, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9130, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9160, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F91A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F91C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F91E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9210, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9250, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9280, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F92C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F92E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9300, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9330, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9370, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9390, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F93B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F93E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9420, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9440, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9460, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9490, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F94D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F94F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9510, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9540, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9580, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F95A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F95C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F95F0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9630, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9650, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9670, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F96A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F96E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9700, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9720, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9730, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9740, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9750, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9780, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F97C0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F97E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9800, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9830, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9870, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F98A0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F98E0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9900, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9920, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9950, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9990, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F99B0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F99D0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9A00, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9A40, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9A60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9A80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9AB0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9AF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9B50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9B80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9BC0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9BE0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9C00, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9C20, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9C50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9C90, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9CC0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9D00, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9D30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9D70, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9DA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9DE0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9E10, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9E50, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9E80, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9EC0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9EF0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9F30, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9F60, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9FA0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004F9FD0, UINT32_C(0x004EEF80));
    LIFT_CALL_ENTER(sfera_sub_004FA010, UINT32_C(0x004EEF80));
    SFERA_STATIC_04F90774_U32 = (uint32_t)(UINT32_C(0x00000002));
    LIFT_BLOCK(label_000EEF8C, UINT32_C(0x004EEF8C));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC)))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EEF99, UINT32_C(0x004EEF91));
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_InterlockedExchange, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEF93)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEF99));
    LIFT_BLOCK(label_000EEF99, UINT32_C(0x004EEF99));
    LIFT_CMP(SFERA_STATIC_04F90784_U32, cpu->ebx, 32u);
    LIFT_JZ(label_000EEFBA, UINT32_C(0x004EEFA1));
    lift_push32(cpu, (uint32_t)(SFERA_STATIC_04F90784_ADDR));
    LIFT_CALL_ENTER(sfera_sub_004EF420, UINT32_C(0x004EEFAB));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EEFBA, UINT32_C(0x004EEFB0));
    LIFT_PUSH3(cpu->ebx, UINT32_C(0x00000002), cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(SFERA_STATIC_04F90784_U32), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEFBA)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EEFB4)))) { return; }
    LIFT_BLOCK(label_000EEFBA, UINT32_C(0x004EEFBA));
    cpu->eax = SFERA_IMPORT_MSVCR100_acmdln;
    LIFT_LOAD32(cpu->esi, cpu->eax);
    LIFT_BLOCK(label_000EEFC1, UINT32_C(0x004EEFC1));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->esi);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->esi)))) & UINT32_C(0xFF));
    LIFT_CMP((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000020), 8u);
    LIFT_JA(label_000EF013, UINT32_C(0x004EEFCA));
    LIFT_CMP((cpu->eax & UINT32_C(0xFF)), (cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000EEFD3, UINT32_C(0x004EEFCE));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), cpu->ebx, 32u);
    LIFT_JNZ_GOTO(label_000EF013);
    LIFT_BLOCK(label_000EEFD3, UINT32_C(0x004EEFD3));
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->esi)))) & UINT32_C(0xFF));
    LIFT_CMP((cpu->eax & UINT32_C(0xFF)), (cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000EEFE3, UINT32_C(0x004EEFD9));
    LIFT_CMP((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000020), 8u);
    LIFT_JA(label_000EEFE3, UINT32_C(0x004EEFDD));
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->esi);
    goto label_000EEFD3;
    LIFT_BLOCK(label_000EEFE3, UINT32_C(0x004EEFE3));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC0)))), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000EEFEF, UINT32_C(0x004EEFE9));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC4)))));
    goto label_000EEFF2;
    LIFT_BLOCK(label_000EEFEF, UINT32_C(0x004EEFEF));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000A)));
    cpu->eax = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EEFF2, UINT32_C(0x004EEFF2));
    LIFT_PUSH4(cpu->eax, cpu->esi, cpu->ebx, lift_process_module_handle());
    LIFT_CALL_ENTER(sfera_sub_0047D770, UINT32_C(0x004EEFFF));
    SFERA_STATIC_04F90430_U32 = (uint32_t)(cpu->eax);
    LIFT_CMP(SFERA_STATIC_04F90424_U32, cpu->ebx, 32u);
    LIFT_JNZ(label_000EF068, UINT32_C(0x004EF00C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    lift_import_call(cpu, SFERA_IMPORT_MSVCR100_exit_288, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF00D)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF013));
    LIFT_BLOCK(label_000EF013, UINT32_C(0x004EF013));
    LIFT_CMP((cpu->eax & UINT32_C(0xFF)), UINT32_C(0x00000022), 8u);
    LIFT_JNZ(label_000EF022, UINT32_C(0x004EF017));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), cpu->ebx, 32u);
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & UINT32_C(0xFF));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->ecx);
    LIFT_BLOCK(label_000EF022, UINT32_C(0x004EF022));
    cpu->eax = (uint32_t)((cpu->eax & UINT32_C(0xFF)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCR100_ismbblead, UINT32_C(0x004EF026), UINT32_C(0x004EF02C));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF035, UINT32_C(0x004EF031));
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->esi);
    LIFT_BLOCK(label_000EF035, UINT32_C(0x004EF035));
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    goto label_000EEFC1;
    LIFT_BLOCK(label_000EF068, UINT32_C(0x004EF068));
    LIFT_CMP(SFERA_STATIC_04F90434_U32, cpu->ebx, 32u);
    LIFT_JNZ(label_000EF076, UINT32_C(0x004EF070));
    lift_import_call(cpu, SFERA_IMPORT_MSVCR100_cexit, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF070)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF076));
    LIFT_BLOCK(label_000EF076, UINT32_C(0x004EF076));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F90430_U32);
    LIFT_BLOCK(label_000EF082, UINT32_C(0x004EF082));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EF087));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EF142, UINT32_C(0x004EF142));
    LIFT_CALL_ENTER(sfera_sub_004EF513, UINT32_C(0x004EF147));
    goto label_000EEEAF;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF14C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF14C));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_calloc, UINT32_C(0x004EF14C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF258(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF258));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_unlock, UINT32_C(0x004EF258));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF25E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF25E));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_dllonexit, UINT32_C(0x004EF25E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF264(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF264));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_lock, UINT32_C(0x004EF264));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF270));
    LIFT_PUSH2(UINT32_C(0x00000000), UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->ebp);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_SP_SUB(cpu->eax);
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), cpu->eax, ^, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), cpu->esp);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))))));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    (void)0; /* source SEH registration eliminated */
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2B5(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2B5));
    LIFT_POP5(cpu->ecx, cpu->edi, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    cpu->ebp = (uint32_t)(lift_pop32(cpu));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2C9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2C9));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000A)));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_IsProcessorFeaturePresent, UINT32_C(0x004EF2CB), UINT32_C(0x004EF2D1));
    SFERA_STATIC_04F9077C_U32 = (uint32_t)(cpu->eax);
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2DA(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2DA));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_terminate_YAXXZ, UINT32_C(0x004EF2DA));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF2E6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2E6));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->eax, cpu->eax);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax))), UINT32_C(0xE06D7363), 32u);
    LIFT_JNZ(label_000EF322, UINT32_C(0x004EF2F8));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax + UINT32_C(0x00000010)))), UINT32_C(0x00000003), 32u);
    LIFT_JNZ(label_000EF322, UINT32_C(0x004EF2FE));
    LIFT_LOAD32(cpu->eax, cpu->eax + UINT32_C(0x00000014));
    LIFT_CMP(cpu->eax, UINT32_C(0x19930520), 32u);
    LIFT_JZ(label_000EF31D, UINT32_C(0x004EF308));
    LIFT_CMP(cpu->eax, UINT32_C(0x19930521), 32u);
    LIFT_JZ(label_000EF31D, UINT32_C(0x004EF30F));
    LIFT_CMP(cpu->eax, UINT32_C(0x19930522), 32u);
    LIFT_JZ(label_000EF31D, UINT32_C(0x004EF316));
    LIFT_CMP(cpu->eax, UINT32_C(0x01994000), 32u);
    LIFT_JNZ_GOTO(label_000EF322);
    LIFT_BLOCK(label_000EF31D, UINT32_C(0x004EF31D));
    LIFT_CALL(sfera_sub_004EF2DA, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF322)));
    LIFT_BLOCK(label_000EF322, UINT32_C(0x004EF322));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF328(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF328));
    lift_push32(cpu, (uint32_t)(LIFT_CALLBACK_RVA(UINT32_C(0x000EF2E6))));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_SetUnhandledExceptionFilter, UINT32_C(0x004EF32D), UINT32_C(0x004EF333));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF336(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF336));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_amsg_exit, UINT32_C(0x004EF336));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF33C(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(UINT32_C(0x004EF33C)); (void)stop_address; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF362(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(UINT32_C(0x004EF362)); (void)stop_address; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF388(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF388));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_XcptFilter, UINT32_C(0x004EF388));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF390(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(UINT32_C(0x004EF390)); (void)stop_address; cpu->eax = lift_load32(cpu->esp + 4u) == lift_process_module_handle() ? 1u : 0u; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF3D0(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(UINT32_C(0x004EF3D0)); (void)stop_address; cpu->eax = 0u; LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF420(LiftCpu* cpu, uint32_t stop_address) { LIFT_ENTER(UINT32_C(0x004EF420)); (void)stop_address; { uint32_t target = lift_load32(cpu->esp + 4u); uint32_t rva = lift_source_rva(target); cpu->eax = sfera_vtable_token_address(target) || (rva >= UINT32_C(0x00001000) && rva < UINT32_C(0x000FC200)) ? 1u : 0u; } LIFT_RET(0u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4AB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4AB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx))), UINT32_C(0xC0000005), 32u);
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & UINT32_C(0xFF));
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4BE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4BE));
    LIFT_LOAD32(cpu->esp, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4DC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4DC));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_initterm, UINT32_C(0x004EF4DC));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4E2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4E2));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_initterm_e, UINT32_C(0x004EF4E2));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF4E8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4E8));
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_PUSH3(cpu->esi, UINT32_C(0x00030000), UINT32_C(0x00010000));
    LIFT_ZERO(cpu->esi, 32u);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_CALL_ENTER(sfera_sub_004EF5C0, UINT32_C(0x004EF4FD));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF50E, UINT32_C(0x004EF504));
    LIFT_PUSH5(cpu->esi, cpu->esi, cpu->esi, cpu->esi, cpu->esi);
    LIFT_CALL(sfera_sub_004EF5BA, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF50E)));
    LIFT_BLOCK(label_000EF50E, UINT32_C(0x004EF50E));
    LIFT_EPILOGUE1(0u, cpu->esi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF510));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF513(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF513));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000010));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))), (uint32_t)(result)););
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    cpu->edi = (uint32_t)(UINT32_C(0xBB40E64E));
    cpu->ebx = (uint32_t)(UINT32_C(0xFFFF0000));
    LIFT_CMP(cpu->eax, cpu->edi, 32u);
    LIFT_JZ(label_000EF545, UINT32_C(0x004EF538));
    LIFT_LOGIC_FLAGS(cpu->ebx, cpu->eax, &, 32u);
    LIFT_JZ(label_000EF545, UINT32_C(0x004EF53C));
    cpu->eax = (uint32_t)(~((uint64_t)(cpu->eax)));
    g_sfera_security_cookie_complement = (uint32_t)(cpu->eax);
    goto label_000EF5AA;
    LIFT_BLOCK(label_000EF545, UINT32_C(0x004EF545));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetSystemTimeAsFileTime, UINT32_C(0x004EF54A), UINT32_C(0x004EF550));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->esi, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8)))), ^, 32u, cpu->esi = (uint32_t)(result););
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentProcessId, UINT32_C(0x004EF556), UINT32_C(0x004EF55C));
    LIFT_LOGIC(cpu->esi, cpu->eax, ^, 32u, cpu->esi = (uint32_t)(result););
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetCurrentThreadId, UINT32_C(0x004EF55E), UINT32_C(0x004EF564));
    LIFT_LOGIC(cpu->esi, cpu->eax, ^, 32u, cpu->esi = (uint32_t)(result););
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_GetTickCount, UINT32_C(0x004EF566), UINT32_C(0x004EF56C));
    LIFT_LOGIC(cpu->esi, cpu->eax, ^, 32u, cpu->esi = (uint32_t)(result););
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_QueryPerformanceCounter, UINT32_C(0x004EF572), UINT32_C(0x004EF578));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0)))), ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOGIC(cpu->esi, cpu->eax, ^, 32u, cpu->esi = (uint32_t)(result););
    LIFT_CMP(cpu->esi, cpu->edi, 32u);
    LIFT_JNZ(label_000EF58B, UINT32_C(0x004EF584));
    cpu->esi = (uint32_t)(UINT32_C(0xBB40E64F));
    goto label_000EF59B;
    LIFT_BLOCK(label_000EF58B, UINT32_C(0x004EF58B));
    LIFT_LOGIC_FLAGS(cpu->ebx, cpu->esi, &, 32u);
    LIFT_JNZ(label_000EF59B, UINT32_C(0x004EF58F));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00004711), |, 32u, cpu->eax = (uint32_t)(result););
    cpu->eax = (uint32_t)(lift_shift_left(cpu, cpu->eax, (uint32_t)(UINT32_C(0x00000010)), 32u));
    LIFT_LOGIC(cpu->esi, cpu->eax, |, 32u, cpu->esi = (uint32_t)(result););
    LIFT_BLOCK(label_000EF59B, UINT32_C(0x004EF59B));
    g_sfera_security_cookie = (uint32_t)(cpu->esi);
    cpu->esi = (uint32_t)(~((uint64_t)(cpu->esi)));
    g_sfera_security_cookie_complement = (uint32_t)(cpu->esi);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EF5AA, UINT32_C(0x004EF5AA));
    LIFT_POP2(cpu->edi, cpu->ebx);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5AE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5AE));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_crt_debugger_hook, UINT32_C(0x004EF5AE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5B4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5B4));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_type_info_type_info_dtor_internal_method, UINT32_C(0x004EF5B4));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5BA(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5BA));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_invoke_watson, UINT32_C(0x004EF5BA));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5C0));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCR100_controlfp_s, UINT32_C(0x004EF5C0));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5C6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5C6));
    LIFT_LOAD32(cpu->ecx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_facet_Decref, UINT32_C(0x004EF5C9), UINT32_C(0x004EF5CF));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF5DB, UINT32_C(0x004EF5D3));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    cpu->ecx = (uint32_t)(cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->edx)))), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF5DB)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF5D9)))) { return; }
    LIFT_BLOCK(label_000EF5DB, UINT32_C(0x004EF5DB));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF5DC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5DC));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004EF5E8));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF5FD, UINT32_C(0x004EF5ED));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F9076C_U32);
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    goto label_000EF5FF;
    LIFT_BLOCK(label_000EF5FD, UINT32_C(0x004EF5FD));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_BLOCK(label_000EF5FF, UINT32_C(0x004EF5FF));
    SFERA_STATIC_04F9076C_U32 = (uint32_t)(cpu->eax);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF656(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF656));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_showmanyc, UINT32_C(0x004EF656));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF65C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF65C));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_xsgetn, UINT32_C(0x004EF65C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF662(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF662));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_xsputn, UINT32_C(0x004EF662));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF668(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF668));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_Lock, UINT32_C(0x004EF668));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF66E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF66E));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_Unlock, UINT32_C(0x004EF66E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF674(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF674));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_uflow, UINT32_C(0x004EF674));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF67A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF67A));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_setbuf, UINT32_C(0x004EF67A));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF680(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF680));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_sync, UINT32_C(0x004EF680));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF686(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF686));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_imbue, UINT32_C(0x004EF686));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF690(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF690));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi, SFERA_VPTR_COM_ERROR);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF6AA, UINT32_C(0x004EF6A2));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF6AA)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF6A8)))) { return; }
    LIFT_BLOCK(label_000EF6AA, UINT32_C(0x004EF6AA));
    LIFT_LOAD32(cpu->esi, cpu->esi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000EF6B8, UINT32_C(0x004EF6B1));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_LocalFree, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF6B2)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF6B8));
    LIFT_BLOCK(label_000EF6B8, UINT32_C(0x004EF6B8));
    LIFT_EPILOGUE1(0u, cpu->esi);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF6C0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    LIFT_ENTER(UINT32_C(0x004EF6C0));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), SFERA_VPTR_COM_ERROR);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004EF6F0));
    LIFT_TRAP_RETURN(UINT32_C(0x004EF6F0), "INT3");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF700));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esi, SFERA_VPTR_COM_ERROR);
    LIFT_LOAD32(cpu->ecx, cpu->eax + UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->ecx);
    LIFT_LOAD32(cpu->edx, cpu->eax + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), cpu->edx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000000C), UINT32_C(0x00000000));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF732, UINT32_C(0x004EF72A));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF732)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF730)))) { return; }
    LIFT_BLOCK(label_000EF732, UINT32_C(0x004EF732));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE2(4u, cpu->esi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF740(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF740));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi, SFERA_VPTR_COM_ERROR);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF75D, UINT32_C(0x004EF755));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF75D)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF75B)))) { return; }
    LIFT_BLOCK(label_000EF75D, UINT32_C(0x004EF75D));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF76B, UINT32_C(0x004EF764));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    lift_import_call(cpu, SFERA_IMPORT_KERNEL32_LocalFree, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF765)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000EF76B));
    LIFT_BLOCK(label_000EF76B, UINT32_C(0x004EF76B));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000001), &, 8u);
    LIFT_JZ(label_000EF77A, UINT32_C(0x004EF771));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004EF777));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000EF77A, UINT32_C(0x004EF77A));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE2(4u, cpu->esi, cpu->ebp);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF781(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF781));
    LIFT_PUSH2(cpu->eax, lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    LIFT_SP_SUB(lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x0000000C)))));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_STORE32(cpu->eax, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_PUSH2(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFF));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF7B4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF7B4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP5(cpu->ecx, cpu->edi, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    cpu->ebp = (uint32_t)(lift_pop32(cpu));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF7D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF860(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF860));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF868(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF868));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF870));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF8A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF8A0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF8D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF8D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF900));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF908(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF908;
    LIFT_BLOCK(label_00002CC0, UINT32_C(0x00402CC0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_00002CE4, UINT32_C(0x00402CC9));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x00402CD8));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00402CE1));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00002CE4, UINT32_C(0x00402CE4));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000EF908, UINT32_C(0x004EF908));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    goto label_00002CC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF930));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF960(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF960));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF990));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF9C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF9C0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EF9CD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EF9F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF9F0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EF9FD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA20));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFA2D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA50));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA58(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA58));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFA80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFA8D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFAB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFAB0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFABD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFAE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFAE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFAED));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFB1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB21(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB21));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFB5D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB88));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFB98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFBF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFBF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFBFD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC20));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFC2D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFC5D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFC8D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFC91(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC91));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFCC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFCC0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFCCD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFCF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFCF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFCFD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD01(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD01));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD38(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD38));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD40));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFD70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD70));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFDA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDA8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFDA8;
    LIFT_BLOCK(label_00002CC0, UINT32_C(0x00402CC0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_00002CE4, UINT32_C(0x00402CC9));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x00402CD8));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00402CE1));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00002CE4, UINT32_C(0x00402CE4));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000EFDA8, UINT32_C(0x004EFDA8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    goto label_00002CC0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFDD0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFDD8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFDD8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_TAIL(sfera_sub_00402D20);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFE00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFE30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFE60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFE68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFE68;
    LIFT_BLOCK(label_000061E0, UINT32_C(0x004061E0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000018)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000061F5, UINT32_C(0x004061E9));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004061F2));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000061F5, UINT32_C(0x004061F5));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), UINT32_C(0x0000000F));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->eax);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000004), (cpu->eax & UINT32_C(0xFF)));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000EFE68, UINT32_C(0x004EFE68));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB4))));
    goto label_000061E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEA8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEA8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFEE8;
    LIFT_BLOCK(label_00006260, UINT32_C(0x00406260));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000020)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_JZ(label_000062B1, UINT32_C(0x00406296));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x004062A5));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000020));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004062AE));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000062B1, UINT32_C(0x004062B1));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000062C2, UINT32_C(0x004062B7));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004062BF));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000062C2, UINT32_C(0x004062C2));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), UINT32_C(0x0000000F));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), UINT32_C(0x00000000));
    LIFT_STORE8(cpu->esi, UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EFEE8, UINT32_C(0x004EFEE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_00006260;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFEF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF28(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF28));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFF98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFFA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFA8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFFA8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004EFFD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFFD0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0000));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0030(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0030));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0038(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0038;
    LIFT_BLOCK(label_000061E0, UINT32_C(0x004061E0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000018)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000061F5, UINT32_C(0x004061E9));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004061F2));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000061F5, UINT32_C(0x004061F5));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), UINT32_C(0x0000000F));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->eax);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000004), (cpu->eax & UINT32_C(0xFF)));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F0038, UINT32_C(0x004F0038));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB4))));
    goto label_000061E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0070));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0078(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0078));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0080));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFBC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F00B8;
    LIFT_BLOCK(label_00006260, UINT32_C(0x00406260));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000020)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_JZ(label_000062B1, UINT32_C(0x00406296));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x004062A5));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000020));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004062AE));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000062B1, UINT32_C(0x004062B1));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000062C2, UINT32_C(0x004062B7));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004062BF));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000062C2, UINT32_C(0x004062C2));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), UINT32_C(0x0000000F));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), UINT32_C(0x00000000));
    LIFT_STORE8(cpu->esi, UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F00B8, UINT32_C(0x004F00B8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_00006260;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F00F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0130(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0130));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0138(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0138));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0140(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0140));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0170));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0178(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0178));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0180(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0180;
    LIFT_BLOCK(label_000062F0, UINT32_C(0x004062F0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_00006305, UINT32_C(0x004062F9));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00406302));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00006305, UINT32_C(0x00406305));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000001C), UINT32_C(0x0000000F));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->eax);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000008), (cpu->eax & UINT32_C(0xFF)));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000004)))), cpu->eax, 32u);
    LIFT_JZ(label_00006332, UINT32_C(0x00406319));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000027))));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x00406326));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0040632F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00006332, UINT32_C(0x00406332));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F0180, UINT32_C(0x004F0180));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    goto label_000062F0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01B8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01B8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F01F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0220));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0228(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0228));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0230));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0238(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0270));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0278(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0278));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0280));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0288(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0288));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02C8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02C8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F02D8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02D8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0310(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0310;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0310, UINT32_C(0x004F0310));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0318(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0318));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0340(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0340;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0340, UINT32_C(0x004F0340));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0348(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0348;
    LIFT_BLOCK(label_00014B90, UINT32_C(0x00414B90));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004149A0, UINT32_C(0x00414BC5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00414BCD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0348, UINT32_C(0x004F0348));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00014B90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0370(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0370;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0370, UINT32_C(0x004F0370));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0378(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0378;
    LIFT_BLOCK(label_00014D30, UINT32_C(0x00414D30));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004BC130, UINT32_C(0x00414D38));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00414D40));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F0378, UINT32_C(0x004F0378));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00014D30;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03A0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03A9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03AB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03AB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03B4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03B6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03B6));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03BF));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03C1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03C1));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03CA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F03F0, UINT32_C(0x004F03F0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F03F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F8;
    LIFT_BLOCK(label_00015050, UINT32_C(0x00415050));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_00406340, UINT32_C(0x00415095));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041509E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F03F8, UINT32_C(0x004F03F8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015050;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0420(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0420;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F0420, UINT32_C(0x004F0420));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0450(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0450;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0450, UINT32_C(0x004F0450));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0458(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0458;
    LIFT_BLOCK(label_00015300, UINT32_C(0x00415300));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_00409F90, UINT32_C(0x00415345));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041534E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0458, UINT32_C(0x004F0458));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015300;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0480(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0480;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0480, UINT32_C(0x004F0480));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0488(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0488;
    LIFT_BLOCK(label_000154E0, UINT32_C(0x004154E0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D400, UINT32_C(0x00415525));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041552E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0488, UINT32_C(0x004F0488));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000154E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F04B0, UINT32_C(0x004F04B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B8;
    LIFT_BLOCK(label_00015550, UINT32_C(0x00415550));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D4D0, UINT32_C(0x00415595));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041559E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F04B8, UINT32_C(0x004F04B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015550;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F04E0, UINT32_C(0x004F04E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F04E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E8;
    LIFT_BLOCK(label_000155C0, UINT32_C(0x004155C0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D5A0, UINT32_C(0x00415605));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041560E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F04E8, UINT32_C(0x004F04E8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000155C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0510(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0510;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0510, UINT32_C(0x004F0510));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0518(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0518;
    LIFT_BLOCK(label_00015630, UINT32_C(0x00415630));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D670, UINT32_C(0x00415675));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041567E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0518, UINT32_C(0x004F0518));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015630;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0540(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0540));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0549));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F054B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F054B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0554));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0580;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0580, UINT32_C(0x004F0580));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0588(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0588;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004B2C40, UINT32_C(0x004B3D15));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004B3D1E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0588, UINT32_C(0x004F0588));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F05B0, UINT32_C(0x004F05B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B8;
    LIFT_BLOCK(label_00016330, UINT32_C(0x00416330));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040A7A0, UINT32_C(0x00416375));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041637E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F05B8, UINT32_C(0x004F05B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016330;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F05E0, UINT32_C(0x004F05E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F05E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05E8;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F05E8, UINT32_C(0x004F05E8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0610(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0610;
    LIFT_BLOCK(label_00014990, UINT32_C(0x00414990));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00414998));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F0610, UINT32_C(0x004F0610));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0640(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0640;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0640, UINT32_C(0x004F0640));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0648(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0648));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0653(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0653));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F065E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F065E;
    LIFT_BLOCK(label_000166B0, UINT32_C(0x004166B0));
    LIFT_TAIL(sfera_sub_00416650);
    LIFT_BLOCK(label_000F065E, UINT32_C(0x004F065E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000166B0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0690(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0690;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0690, UINT32_C(0x004F0690));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0698(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0698;
    LIFT_BLOCK(label_000166C0, UINT32_C(0x004166C0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040A060, UINT32_C(0x004166F5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004166FD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0698, UINT32_C(0x004F0698));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000166C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06A3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F06A3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06AE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06AE;
    LIFT_BLOCK(label_000167E0, UINT32_C(0x004167E0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_CMP(cpu->eax, cpu->edi, 32u);
    LIFT_JZ(label_00016817, UINT32_C(0x0041680E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00416814));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00016817, UINT32_C(0x00416817));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->edi);
    LIFT_ADD(cpu->esi, UINT32_C(0x00000004), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_0040A060, UINT32_C(0x00416832));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041683A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F06AE, UINT32_C(0x004F06AE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000167E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F06E0, UINT32_C(0x004F06E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E8;
    LIFT_BLOCK(label_00016720, UINT32_C(0x00416720));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_00408A50, UINT32_C(0x00416755));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041675D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F06E8, UINT32_C(0x004F06E8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016720;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06F3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F06F3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F06FE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06FE;
    LIFT_BLOCK(label_00016850, UINT32_C(0x00416850));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_CMP(cpu->eax, cpu->edi, 32u);
    LIFT_JZ(label_00016887, UINT32_C(0x0041687E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00416884));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00016887, UINT32_C(0x00416887));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->edi);
    LIFT_ADD(cpu->esi, UINT32_C(0x00000004), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_00408A50, UINT32_C(0x004168A2));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004168AA));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F06FE, UINT32_C(0x004F06FE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016850;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0730(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0730;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0730, UINT32_C(0x004F0730));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0738(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0738;
    LIFT_BLOCK(label_00016780, UINT32_C(0x00416780));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040A0C0, UINT32_C(0x004167B5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004167BD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0738, UINT32_C(0x004F0738));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016780;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0743(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0743));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F074E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F074E;
    LIFT_BLOCK(label_000168C0, UINT32_C(0x004168C0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_CMP(cpu->eax, cpu->edi, 32u);
    LIFT_JZ(label_000168F7, UINT32_C(0x004168EE));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004168F4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000168F7, UINT32_C(0x004168F7));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->edi);
    LIFT_ADD(cpu->esi, UINT32_C(0x00000004), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_0040A0C0, UINT32_C(0x00416912));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041691A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F074E, UINT32_C(0x004F074E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000168C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0780(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0780;
    LIFT_BLOCK(label_00014990, UINT32_C(0x00414990));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00414998));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F0780, UINT32_C(0x004F0780));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F07B0, UINT32_C(0x004F07B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07B8;
    LIFT_BLOCK(label_00014D30, UINT32_C(0x00414D30));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004BC130, UINT32_C(0x00414D38));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00414D40));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F07B8, UINT32_C(0x004F07B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00014D30;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07C3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F07C3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F07CE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07CE;
    LIFT_BLOCK(label_00017150, UINT32_C(0x00417150));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_00017163, UINT32_C(0x0041715A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00417160));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00017163, UINT32_C(0x00417163));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000004))));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004BC130, UINT32_C(0x00417180));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00417189));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F07CE, UINT32_C(0x004F07CE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00017150;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0800(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0800;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0800, UINT32_C(0x004F0800));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0808(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0808;
    LIFT_BLOCK(label_00016930, UINT32_C(0x00416930));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_0040BB40, UINT32_C(0x00416938));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00416940));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F0808, UINT32_C(0x004F0808));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016930;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0813(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0813));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F081E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F081E;
    LIFT_BLOCK(label_00017190, UINT32_C(0x00417190));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000171A3, UINT32_C(0x0041719A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004171A0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000171A3, UINT32_C(0x004171A3));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000004))));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040BB40, UINT32_C(0x004171C0));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004171C9));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F081E, UINT32_C(0x004F081E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00017190;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0850;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0850, UINT32_C(0x004F0850));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0858(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0858;
    LIFT_BLOCK(label_00016950, UINT32_C(0x00416950));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_0040BBA0, UINT32_C(0x00416958));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00416960));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F0858, UINT32_C(0x004F0858));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0863(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0863));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F086E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F086E;
    LIFT_BLOCK(label_000171D0, UINT32_C(0x004171D0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000171E3, UINT32_C(0x004171DA));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004171E0));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000171E3, UINT32_C(0x004171E3));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000004))));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040BBA0, UINT32_C(0x00417200));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00417209));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F086E, UINT32_C(0x004F086E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000171D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F08A0, UINT32_C(0x004F08A0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A8;
    LIFT_BLOCK(label_00016970, UINT32_C(0x00416970));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D740, UINT32_C(0x004169A5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004169AD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F08A8, UINT32_C(0x004F08A8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016970;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08B3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F08B3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08BE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08BE;
    LIFT_BLOCK(label_00017210, UINT32_C(0x00417210));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_CMP(cpu->eax, cpu->edi, 32u);
    LIFT_JZ(label_00017247, UINT32_C(0x0041723E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00417244));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00017247, UINT32_C(0x00417247));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->edi);
    LIFT_ADD(cpu->esi, UINT32_C(0x00000004), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_0040D740, UINT32_C(0x00417262));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041726A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F08BE, UINT32_C(0x004F08BE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00017210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F08F0, UINT32_C(0x004F08F0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F08F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F8;
    LIFT_BLOCK(label_000169D0, UINT32_C(0x004169D0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040BC20, UINT32_C(0x00416A05));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00416A0D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F08F8, UINT32_C(0x004F08F8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000169D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0903(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0903));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F090E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F090E;
    LIFT_BLOCK(label_00017280, UINT32_C(0x00417280));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000010));
    LIFT_ZERO(cpu->edi, 32u);
    LIFT_CMP(cpu->eax, cpu->edi, 32u);
    LIFT_JZ(label_000172B7, UINT32_C(0x004172AE));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004172B4));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000172B7, UINT32_C(0x004172B7));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000010), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000014), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->edi);
    LIFT_ADD(cpu->esi, UINT32_C(0x00000004), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->esp + UINT32_C(0x0000000C), cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000018), cpu->edi);
    LIFT_CALL_ENTER(sfera_sub_0040BC20, UINT32_C(0x004172D2));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004172DA));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F090E, UINT32_C(0x004F090E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00017280;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0940));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0949));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F094B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F094B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0954));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0956(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0956));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F095F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0980(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0980;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0980, UINT32_C(0x004F0980));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0988(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0988;
    LIFT_BLOCK(label_00014990, UINT32_C(0x00414990));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00414998));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F0988, UINT32_C(0x004F0988));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00014990;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F09B0, UINT32_C(0x004F09B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09B8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F09B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F09E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F09E0, UINT32_C(0x004F09E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A10(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A10;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0A10, UINT32_C(0x004F0A10));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A18(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A18;
    LIFT_BLOCK(label_00018270, UINT32_C(0x00418270));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ebx = (uint32_t)(cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->esi, cpu->ebx);
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_0001829C, UINT32_C(0x0041827A));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, cpu->ebx + UINT32_C(0x00000004));
    LIFT_CMP(cpu->esi, cpu->edi, 32u);
    LIFT_JZ_GOTO(label_00018290);
    LIFT_BLOCK(label_00018282, UINT32_C(0x00418282));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_00402CF0, UINT32_C(0x00418289));
    LIFT_ADD(cpu->esi, UINT32_C(0x00000008), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_CMP(cpu->esi, cpu->edi, 32u);
    LIFT_JNZ_GOTO(label_00018282);
    LIFT_BLOCK(label_00018290, UINT32_C(0x00418290));
    LIFT_LOAD32(cpu->eax, cpu->ebx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00418298));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_0001829C, UINT32_C(0x0041829C));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_STORE32(cpu->ebx, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->ebx + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->ebx + UINT32_C(0x00000008), UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->ebx);
    LIFT_BLOCK(label_000F0A18, UINT32_C(0x004F0A18));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00018270;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A40(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A40;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0A40, UINT32_C(0x004F0A40));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A48(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A48;
    LIFT_BLOCK(label_000183C0, UINT32_C(0x004183C0));
    LIFT_PUSH2(cpu->ecx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000183E6, UINT32_C(0x004183CA));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00408FB0, UINT32_C(0x004183DB));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004183E3));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000183E6, UINT32_C(0x004183E6));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ecx);
    LIFT_BLOCK(label_000F0A48, UINT32_C(0x004F0A48));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A70));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A79));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A7B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A7B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A84));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A86(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A86));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A8F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A91(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A91));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A9A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0A9C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A9C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0AA5));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0AD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0AD0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_0042B7D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B00(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B00;
    LIFT_BLOCK(label_00018890, UINT32_C(0x00418890));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_LeaveCriticalSection, UINT32_C(0x00418893), UINT32_C(0x00418899));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0B00, UINT32_C(0x004F0B00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    goto label_00018890;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0B30));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_0042B7D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0B60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B60;
    LIFT_BLOCK(label_00018890, UINT32_C(0x00418890));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(SFERA_IMPORT_KERNEL32_LeaveCriticalSection, UINT32_C(0x00418893), UINT32_C(0x00418899));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0B60, UINT32_C(0x004F0B60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFDD8))));
    goto label_00018890;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0BA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0BA0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0BA9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0BD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0BD0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0BD9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_0047ED10);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB4))));
    LIFT_TAIL(sfera_sub_0047ED10);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C3B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C3B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB0))));
    LIFT_TAIL(sfera_sub_0047EDB0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFB4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0C89));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0CC0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0CC9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0CF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0CF9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0CFB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0CFB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D04));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D06(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D06));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D0F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D11(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D11));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D1A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D1C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D1C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D25));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D5C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D5E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D5E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D6A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D6C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D6C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D78));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D7A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D7A));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D86));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D88));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D94));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0D96(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D96));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0DA2));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0DE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0DE0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00425E70);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E19));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E1B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E24));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E26));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E2F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E31(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E31));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E3A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E3C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E3C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E45));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E47(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E47));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E50));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E52(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E52));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E5B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E5D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E5D));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E66));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0E90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E90));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_effect_items));
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0EC0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0EC0;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F0EC0, UINT32_C(0x004F0EC0));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners));
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0EF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0EF9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0F20));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_00425E70);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0F50));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_00425E70);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0F80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0F80));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00425E70);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0FB0;
    LIFT_BLOCK(label_0002E1E0, UINT32_C(0x0042E1E0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000004)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->esi, SFERA_VPTR_IOUTPUTDEVICE);
    LIFT_JZ(label_0002E20A, UINT32_C(0x0042E1EF));
    cpu->edx = (uint32_t)(UINT32_C(0x00000065));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp"));
    LIFT_CALL_ENTER(sfera_sub_004EB1C0, UINT32_C(0x0042E1FE));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0042E207));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_0002E20A, UINT32_C(0x0042E20A));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F0FB0, UINT32_C(0x004F0FB0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_0002E1E0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0FE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0FE9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F0FEB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0FEB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0FF4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1020(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1020;
    LIFT_BLOCK(label_000313C0, UINT32_C(0x004313C0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_000313D5, UINT32_C(0x004313C9));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004313D2));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000313D5, UINT32_C(0x004313D5));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000001C), UINT32_C(0x0000000F));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->eax);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000008), (cpu->eax & UINT32_C(0xFF)));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F1020, UINT32_C(0x004F1020));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_000313C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1050(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1050;
    LIFT_BLOCK(label_00031410, UINT32_C(0x00431410));
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000048)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_00031426, UINT32_C(0x0043141A));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000034));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00431423));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00031426, UINT32_C(0x00431426));
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000048), UINT32_C(0x0000000F));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000044), cpu->ebx);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000034), (cpu->ebx & UINT32_C(0xFF)));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C)))), UINT32_C(0x00000010), 32u);
    LIFT_JB(label_00031447, UINT32_C(0x0043143B));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00431444));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_00031447, UINT32_C(0x00431447));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->ebx);
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000001C), UINT32_C(0x0000000F));
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000008), (cpu->ebx & UINT32_C(0xFF)));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ebx);
    LIFT_BLOCK(label_000F1050, UINT32_C(0x004F1050));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00031410;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1080));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE14));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F108C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F10C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F10C0));
    cpu->eax = (uint32_t)(SFERA_STATIC_04DC068C_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04DC068C_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F10F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F10F0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F10F9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1120));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1129));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F112B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F112B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1134));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1170));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE44));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F117C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F117E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F117E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE44));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F118A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F11C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F11C0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFC8));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F11C8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F11C8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1200(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1200));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1230));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1238(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1270));
    cpu->eax = (uint32_t)(SFERA_STATIC_04EDD0C8_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04EDD0C8_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A0;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12A0, UINT32_C(0x004F12A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A8;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12A8, UINT32_C(0x004F12A8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E0;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12E0, UINT32_C(0x004F12E0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F12E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E8;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(((uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h"));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12E8, UINT32_C(0x004F12E8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    goto label_00051CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1320));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_TAIL(sfera_sub_00480390);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1350));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1359));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F135B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F135B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1364));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1366(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1366));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F136F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1371(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1371));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F137A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F137C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F137C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1385));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1387(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1387));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1390));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1392(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1392));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F139B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F13D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE1C))));
    LIFT_TAIL(sfera_sub_00480390);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13DB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F13DB));
    cpu->eax = (uint32_t)(SFERA_STATIC_04DC068C_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04DC068C_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F13E9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F13E9));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE0C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F13F5));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1430(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1430));
    cpu->eax = (uint32_t)(SFERA_STATIC_04DC068C_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04DC068C_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1460(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1460));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1490(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1490));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1498(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1498));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F14D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F14D0));
    cpu->eax = (uint32_t)(SFERA_STATIC_04EE0498_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04EE0498_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1510));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F151C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F151E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F151E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F152A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F152C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F152C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1538));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F153A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F153A));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1546));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1548(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1548));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1554));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1556(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1556));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1562));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1564(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1564));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1570));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1572(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1572));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F157E));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F15B0;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F15B0, UINT32_C(0x004F15B0));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04EDCD70_ADDR);
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F15E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F15E9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F15EB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F15EB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F15F4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1620(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1620));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEC4))));
    LIFT_TAIL(sfera_sub_0047ED10);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F162B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F162B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_0047EDB0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1670(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1670));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFBC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1679));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F16B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F16B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFBC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F16B9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F16F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F16F0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFBC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F16F9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1730));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF68));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F173C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F173E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F173E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF68));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F174A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F174C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F174C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF58));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1758));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1790(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1790));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1799));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F17D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F17D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000C80), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00430BC0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1800(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1800));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFF2C4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000C80), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00430BC0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1860(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1860));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1868(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1868));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFAC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1871));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F18A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F18A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F18D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F18D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1900));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFB4));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F1918, UINT32_C(0x004F190C));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB4)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB4))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F1918, UINT32_C(0x004F1918));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1950(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1950));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F1968, UINT32_C(0x004F195C));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F1968, UINT32_C(0x004F1968));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1969(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1969));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F19A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F19A0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F19B8, UINT32_C(0x004F19AC));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F19B8, UINT32_C(0x004F19B8));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F19E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F19E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F19F8, UINT32_C(0x004F19EC));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F19F8, UINT32_C(0x004F19F8));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A28(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A28));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF90));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F1A40, UINT32_C(0x004F1A34));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF90)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF90))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F1A40, UINT32_C(0x004F1A40));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A41(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A41));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF90));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000002), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F1A59, UINT32_C(0x004F1A4D));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF90)))), UINT32_C(0xFFFFFFFD), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF90))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F1A59, UINT32_C(0x004F1A59));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1A98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AD0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AD8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AD8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AEB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AEB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AF3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AF3));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1AFE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AFE));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B09(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B09));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B14(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B14));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B1C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B1C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B27(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B27));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B2F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B2F));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1B3B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B3D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B3D));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B45(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B45));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1B51));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B53(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B53));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B5B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B5B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1B66(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B66));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1B72));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE4C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BBB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BBB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE30))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BC6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BC6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFDF8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BD1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BD1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BDC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BDC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE84))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BE7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BE7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE14))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BF2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BF2));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1BFD(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BFD));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C08(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C08));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C10));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C1B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C26));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE68))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C31(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C31));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEA0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C3C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C3C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C44(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C44));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C4F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C4F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C57(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C57));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1C62(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C62));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1CA0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F1CB8, UINT32_C(0x004F1CAC));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F1CB8, UINT32_C(0x004F1CB8));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1CE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CE8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1CE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1CF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1CF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D30));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D39));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D3B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D3B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D43(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D43));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D4B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D4B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D54));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D56(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D56));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D5E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D5E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D67));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D69(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D69));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D72));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1D74(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D74));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D7D));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF70))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F1DB6));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DBC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1DBC;
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
    LIFT_BLOCK(label_000F1DBC, UINT32_C(0x004F1DBC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF70))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DC7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DC7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DCF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DCF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DD7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DD7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1DDF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DDF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F1E23));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E29(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1E29;
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
    LIFT_BLOCK(label_000F1E29, UINT32_C(0x004F1E29));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E31(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E31));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E39(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E39));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E41(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E41));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x0000003C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E88));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000020))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1E98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EA3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EA3));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE84))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EAE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EAE));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE68))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EB9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EB9));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EC1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EC1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE4C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1ECC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1ECC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEA0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1ED7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1ED7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EDF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EDF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EEA(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EEA));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1EF5(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EF5));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F08(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F08));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F13(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F13));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F1B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F26));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F68(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F68));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF4C))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F1F6E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F74(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1F74;
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
    LIFT_BLOCK(label_000F1F74, UINT32_C(0x004F1F74));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF4C))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F7F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F7F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1F87(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F87));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FC0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FC8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FC8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF38))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F1FCE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FD4(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1FD4;
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
    LIFT_BLOCK(label_000F1FD4, UINT32_C(0x004F1FD4));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF38))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FDF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FDF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FE7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FE7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FEF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FEF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FF7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FF7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F1FFF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FFF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2040));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2048(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2048));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF6C))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F204E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2054(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2054;
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
    LIFT_BLOCK(label_000F2054, UINT32_C(0x004F2054));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF6C))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F205F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F205F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2067(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2067));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F206F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F206F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F20B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F20B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00480390);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F20E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F20E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFDA4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F20EC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2120));
    cpu->ecx = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_sound_effect_items));
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2150));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2159));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2180(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2180));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F218C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F21C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F21C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFDC8))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2200(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2200));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_00480390);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2230));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F22A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F22A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF88))));
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2320));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2350));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F235D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2380(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2380));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F238D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F23D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F23D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F23D8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F23D8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2410(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2410));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2419));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2480(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2480));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F248B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F248B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000030), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2496(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2496));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000040), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24A1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24A1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24DB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24DB));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000030), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24E6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24E6));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000040), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F24F1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24F1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2520(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2520));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2529));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2550));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2580));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F25B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F25B0;
    LIFT_BLOCK(label_000A8F90, UINT32_C(0x004A8F90));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004A8F9B));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F25B0, UINT32_C(0x004F25B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2600(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2600));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2608(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2608;
    LIFT_BLOCK(label_000AA210, UINT32_C(0x004AA210));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004A9AA0, UINT32_C(0x004AA245));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004AA24D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2608, UINT32_C(0x004F2608));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AA210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2616(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2616));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2624(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2624));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2632(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2632));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001D0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2640(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2640));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000208), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F264E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F264E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000224), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F265C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F265C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000288), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F266A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F266A;
    LIFT_BLOCK(label_000A8F90, UINT32_C(0x004A8F90));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004A8F9B));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F266A, UINT32_C(0x004F266A));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F26B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F26B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F26B3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F26B9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F26B9;
    LIFT_BLOCK(label_000A8F90, UINT32_C(0x004A8F90));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004A8F9B));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F26B9, UINT32_C(0x004F26B9));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    goto label_000A8F90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2700));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2730));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2738(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2738));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x0000001C), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2743(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2743;
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
    LIFT_BLOCK(label_000F2743, UINT32_C(0x004F2743));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000040), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2770));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF88))));
    LIFT_TAIL(sfera_sub_004AE200);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27BB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27BB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27C6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27C6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27D1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27D1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27D9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27D9));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27E4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27E4));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27EF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27EF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F27F7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27F7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2802(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2802));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2840(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2840));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2890));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF88))));
    LIFT_TAIL(sfera_sub_004AE200);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F28D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F28D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2900));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2908(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2908));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F290B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2911(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2911;
    LIFT_BLOCK(label_000AA210, UINT32_C(0x004AA210));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004A9AA0, UINT32_C(0x004AA245));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004AA24D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2911, UINT32_C(0x004F2911));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AA210;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F291F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F291F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F292D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F292D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F293B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F293B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001D0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2949(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2949));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000208), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2957(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2957));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000224), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2965(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2965));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000288), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2990));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2998(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2998));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F29A1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29A3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F29A3));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFAC));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F29BB, UINT32_C(0x004F29AF));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F29BB, UINT32_C(0x004F29BB));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F29F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F29F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F29F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A0B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A0B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A13(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A13));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A1E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A1E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A26));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A2E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A2E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A36(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A36));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A3E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A3E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A49(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A49));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF18));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A55));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A57(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A57));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF20));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A63));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A65(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A65));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF20));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A73(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A73));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A7B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A7B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF20));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A87));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A89(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A89));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A91(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A91));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2A9C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A9C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF0C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2AA8));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2AE0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AE8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2AE8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x0000001C), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AF3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2AF3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F2AF6));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2AFC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2AFC;
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
    LIFT_BLOCK(label_000F2AFC, UINT32_C(0x004F2AFC));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000040), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B07(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B07));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEE4))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F2B36));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B3C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2B3C;
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
    LIFT_BLOCK(label_000F2B3C, UINT32_C(0x004F2B3C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEE4))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B47(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B47));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B4F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B4F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B5A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B5A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B62(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B62));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B6A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B6A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2B75(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B75));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2BB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F2BB3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BB9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2BB9;
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
    LIFT_BLOCK(label_000F2BB9, UINT32_C(0x004F2BB9));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2BE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2BE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F2BED));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2C40));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C48(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2C48;
    LIFT_BLOCK(label_000AF880, UINT32_C(0x004AF880));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004AF470, UINT32_C(0x004AF888));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004AF890));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F2C48, UINT32_C(0x004F2C48));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000002DC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2C80));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2C88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2C88));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F2C8B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2CB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2CB0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFB4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2CB9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2CBB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2CBB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2D10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2D19));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2D1B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2D24));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2D50));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Lockit_dtor, UINT32_C(0x004F2D53));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2D80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2D80;
    LIFT_BLOCK(label_000B1300, UINT32_C(0x004B1300));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000B131A, UINT32_C(0x004B1306));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_facet_Decref, UINT32_C(0x004B1306), UINT32_C(0x004B130C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B131A, UINT32_C(0x004B1310));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B131A)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1318)))) { return; }
    LIFT_BLOCK(label_000B131A, UINT32_C(0x004B131A));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2D80, UINT32_C(0x004F2D80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C))));
    goto label_000B1300;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DB0;
    LIFT_BLOCK(label_000B1320, UINT32_C(0x004B1320));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B1338, UINT32_C(0x004B132F));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DB0, UINT32_C(0x004F2DB0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DE0;
    LIFT_BLOCK(label_000B1320, UINT32_C(0x004B1320));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B1338, UINT32_C(0x004B132F));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DE0, UINT32_C(0x004F2DE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DE8;
    LIFT_BLOCK(label_000B1950, UINT32_C(0x004B1950));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_std_uncaught_exception, UINT32_C(0x004B1980), UINT32_C(0x004B1986));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000B1992, UINT32_C(0x004B198A));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    lift_import_call(cpu, SFERA_IMPORT_MSVCP100_basic_ostream_Osfx, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B198C)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1992));
    LIFT_BLOCK(label_000B1992, UINT32_C(0x004B1992));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0xFFFFFFFF));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B19B2, UINT32_C(0x004B19A9));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B19B2)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B19B0)))) { return; }
    LIFT_BLOCK(label_000B19B2, UINT32_C(0x004B19B2));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DE8, UINT32_C(0x004F2DE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    goto label_000B1950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2DF0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DF0;
    LIFT_BLOCK(label_000B1320, UINT32_C(0x004B1320));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B1338, UINT32_C(0x004B132F));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DF0, UINT32_C(0x004F2DF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E20;
    LIFT_BLOCK(label_000B1320, UINT32_C(0x004B1320));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B1338, UINT32_C(0x004B132F));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2E20, UINT32_C(0x004F2E20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E28(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E28;
    LIFT_BLOCK(label_000B1950, UINT32_C(0x004B1950));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_std_uncaught_exception, UINT32_C(0x004B1980), UINT32_C(0x004B1986));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000B1992, UINT32_C(0x004B198A));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    lift_import_call(cpu, SFERA_IMPORT_MSVCP100_basic_ostream_Osfx, LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B198C)));
    cpu->eip = LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1992));
    LIFT_BLOCK(label_000B1992, UINT32_C(0x004B1992));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0xFFFFFFFF));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B19B2, UINT32_C(0x004B19A9));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B19B2)), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B19B0)))) { return; }
    LIFT_BLOCK(label_000B19B2, UINT32_C(0x004B19B2));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2E28, UINT32_C(0x004F2E28));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_000B1950;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E30(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E30;
    LIFT_BLOCK(label_000B1320, UINT32_C(0x004B1320));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B1338, UINT32_C(0x004B132F));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2E30, UINT32_C(0x004F2E30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2E80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2EB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EE0;
    LIFT_BLOCK(label_000B1320, UINT32_C(0x004B1320));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B1338, UINT32_C(0x004B132F));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2EE0, UINT32_C(0x004F2EE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2EE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EE8;
    LIFT_BLOCK(label_000B1320, UINT32_C(0x004B1320));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->edx + cpu->eax + UINT32_C(0x00000038));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B1338, UINT32_C(0x004B132F));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx + UINT32_C(0x00000008));
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(UINT32_C(0x000B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2EE8, UINT32_C(0x004F2EE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    goto label_000B1320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F10));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F18(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F18));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F50));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F58(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F58));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2F90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2FC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2FC0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F2FF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2FF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F300C, UINT32_C(0x004F2FFC));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000060), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_ios_dtor, UINT32_C(0x004F3006));
    LIFT_BLOCK(label_000F300C, UINT32_C(0x004F300C));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F300D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F300D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_ostream_dtor, UINT32_C(0x004F3013));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3019(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3019));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_dtor, UINT32_C(0x004F301C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3040));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_SUB(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_ostream_dtor, UINT32_C(0x004F3046));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F304C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F304C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_dtor, UINT32_C(0x004F304F));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3070));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_dtor, UINT32_C(0x004F3073));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F30A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30A8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F30A8));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F30B1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F30B3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F30B3));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFC8));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F30CB, UINT32_C(0x004F30BF));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC8)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC8))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F30CB, UINT32_C(0x004F30CB));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3100(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3100));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F3118, UINT32_C(0x004F310C));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F3118, UINT32_C(0x004F3118));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3140(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3140));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF7C))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F3146));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F314C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F314C;
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
    LIFT_BLOCK(label_000F314C, UINT32_C(0x004F314C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF7C))));
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3157(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3157));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F315F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F315F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F31A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F31D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31D0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F31EC, UINT32_C(0x004F31DC));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000068), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_ios_dtor, UINT32_C(0x004F31E6));
    LIFT_BLOCK(label_000F31EC, UINT32_C(0x004F31EC));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F31ED(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31ED));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_istream_dtor, UINT32_C(0x004F31F3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F31F9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31F9));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_dtor, UINT32_C(0x004F31FC));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3220));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_SUB(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_istream_dtor, UINT32_C(0x004F3226));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F322C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F322C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_dtor, UINT32_C(0x004F322F));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3250(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3250));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3258(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3258));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F325B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3261(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3261;
    LIFT_BLOCK(label_000AF880, UINT32_C(0x004AF880));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004AF470, UINT32_C(0x004AF888));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004AF890));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F3261, UINT32_C(0x004F3261));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F326F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F326F;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004B2C40, UINT32_C(0x004B3D15));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004B3D1E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F326F, UINT32_C(0x004F326F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F327D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F327D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F328B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F328B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001E4), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3299(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3299));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F329C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32C8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32C8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32D8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32D8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F32E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF74));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F32EC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3320));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEE4));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F3341, UINT32_C(0x004F332F));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEE4)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEE4))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFEE8));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F3341, UINT32_C(0x004F3341));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3342(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3342));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F334A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F334A;
    LIFT_BLOCK(label_000B5320, UINT32_C(0x004B5320));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x00000068))));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004B4CE0, UINT32_C(0x004B532B));
    cpu->eax = (uint32_t)(SFERA_IMPORT_MSVCP100_basic_ios_vftable);
    LIFT_STORE32(cpu->esi, cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_IMPORT_MSVCP100_ios_base_vftable);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_ios_base_Ios_base_dtor, UINT32_C(0x004B533B), UINT32_C(0x004B5341));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F334A, UINT32_C(0x004F334A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEEC))));
    goto label_000B5320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3355(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3355));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F335D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F335D));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F33A0;
    LIFT_BLOCK(label_000B5320, UINT32_C(0x004B5320));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x00000068))));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004B4CE0, UINT32_C(0x004B532B));
    cpu->eax = (uint32_t)(SFERA_IMPORT_MSVCP100_basic_ios_vftable);
    LIFT_STORE32(cpu->esi, cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_IMPORT_MSVCP100_ios_base_vftable);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_ios_base_Ios_base_dtor, UINT32_C(0x004B533B), UINT32_C(0x004B5341));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F33A0, UINT32_C(0x004F33A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE60))));
    goto label_000B5320;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33AB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33AB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33B6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33B6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33C1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33C1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33CC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33CC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33D7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33D7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33DF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33DF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33E7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33E7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33EF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33EF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F33F7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33F7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3402(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3402));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3440(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3440;
    LIFT_BLOCK(label_000B4A80, UINT32_C(0x004B4A80));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x00000060))));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004B3A40, UINT32_C(0x004B4A8B));
    cpu->eax = (uint32_t)(SFERA_IMPORT_MSVCP100_basic_ios_vftable);
    LIFT_STORE32(cpu->esi, cpu->eax);
    cpu->ecx = (uint32_t)(SFERA_IMPORT_MSVCP100_ios_base_vftable);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(SFERA_IMPORT_MSVCP100_ios_base_Ios_base_dtor, UINT32_C(0x004B4A9B), UINT32_C(0x004B4AA1));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F3440, UINT32_C(0x004F3440));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE30))));
    goto label_000B4A80;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F344B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F344B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3456(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3456));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F345E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F345E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3469(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3469));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3474(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3474));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F347C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F347C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3487(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3487));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F348F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F348F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F349A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F349A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34A5(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F34A5));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F34E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34E8;
    LIFT_BLOCK(label_000AF880, UINT32_C(0x004AF880));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004AF470, UINT32_C(0x004AF888));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004AF890));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F34E8, UINT32_C(0x004F34E8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F34F6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34F6;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004B2C40, UINT32_C(0x004B3D15));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004B3D1E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F34F6, UINT32_C(0x004F34F6));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3504(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3504));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3512(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3512));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001E4), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3520(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3520;
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
    LIFT_BLOCK(label_000F3520, UINT32_C(0x004F3520));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000200), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F352E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F352E;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F352E, UINT32_C(0x004F352E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    goto label_000161C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3560(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3560));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F356B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F356B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3576(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3576));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3581(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3581));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F358C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F358C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3597(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3597));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35A2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35A2));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35AD(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35AD));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F35F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3630));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3638(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3638));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F363B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3641(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3641;
    LIFT_BLOCK(label_000AF880, UINT32_C(0x004AF880));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004AF470, UINT32_C(0x004AF888));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004AF890));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F3641, UINT32_C(0x004F3641));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AF880;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F364F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F364F;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->eax = (uint32_t)(UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(g_sfera_security_cookie);
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000014))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000024), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004B2C40, UINT32_C(0x004B3D15));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004B3D1E));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x00000010));
    (void)0; /* source SEH registration eliminated */
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F364F, UINT32_C(0x004F364F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F365D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F365D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F366B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F366B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001E4), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3679(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3679));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F367C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3682(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3682;
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
    LIFT_BLOCK(label_000F3682, UINT32_C(0x004F3682));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000200), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F36B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F36B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F36E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F36E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F36E9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3710));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3719));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F371B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F371B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3724));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3750(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3750));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_SUB(cpu->ecx, UINT32_C(0x00000048), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_ostream_dtor, UINT32_C(0x004F3756));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3780));
    cpu->eax = (uint32_t)(SFERA_STATIC_04DC068C_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04DC068C_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F378E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F378E));
    cpu->eax = (uint32_t)(SFERA_STATIC_04DC068C_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04DC068C_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F37C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F37C0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F37CD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F37D1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F37D1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3800(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3800));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F380D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3811(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3811));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3840(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3840));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFDA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F384C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3880(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3880));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3889));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F38B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFD94));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F38BC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F38F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F38F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F38F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3930));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3938(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3938));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3940));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3970(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3970));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F397D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F39A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F39A0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F39AD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F39B1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F39B1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F39E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F39E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF54));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000002), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F39FF, UINT32_C(0x004F39EF));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF54)))), UINT32_C(0xFFFFFFFD), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF54))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_ios_dtor, UINT32_C(0x004F39F9));
    LIFT_BLOCK(label_000F39FF, UINT32_C(0x004F39FF));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_ostream_dtor, UINT32_C(0x004F3A06));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A0C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A0C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFF50));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_basic_streambuf_dtor, UINT32_C(0x004F3A12));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A18(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A18));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF5C))));
    LIFT_TAIL(sfera_sub_004B9200);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A23(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A23));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF54));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F3A44, UINT32_C(0x004F3A32));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF54)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF54))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFF58));
    LIFT_TAIL(sfera_sub_004061B0);
    LIFT_BLOCK(label_000F3A44, UINT32_C(0x004F3A44));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A70));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A7B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A7B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3A86(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A86));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3AC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3AC0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3AF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3AF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B40));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B48(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B48));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF7C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3B54));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B56(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B56));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_00406210);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3B90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B90));
    cpu->ecx = (uint32_t)(SFERA_STATIC_04F3B188_ADDR);
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F3B95));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3BC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3BC0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3BC8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3BC8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x0000019C), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3C00));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3C09));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3C30));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3C39));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3C60));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3C68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3C68;
    LIFT_BLOCK(label_000BFB50, UINT32_C(0x004BFB50));
    LIFT_PUSH2(cpu->ecx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000BFB76, UINT32_C(0x004BFB5A));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_004A3EF0, UINT32_C(0x004BFB6B));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004BFB73));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000BFB76, UINT32_C(0x004BFB76));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ecx);
    LIFT_BLOCK(label_000F3C68, UINT32_C(0x004F3C68));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001A0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000BFB50;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3CA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CA8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3CA8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3CE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3CE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3CED));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3D10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3D1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3D60));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3D6D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3D71(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3D71));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3D7E));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3DA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3DD0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3DD9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DDB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3DDB));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3DE3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3DE3;
    LIFT_BLOCK(label_000C26D0, UINT32_C(0x004C26D0));
    LIFT_PUSH2(cpu->ecx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000C26F6, UINT32_C(0x004C26DA));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_004C24B0, UINT32_C(0x004C26EB));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004C26F3));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000C26F6, UINT32_C(0x004C26F6));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ecx);
    LIFT_BLOCK(label_000F3DE3, UINT32_C(0x004F3DE3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000210), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000C26D0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3E10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3E1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3E40));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3E49));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3E70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3E70));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3ED0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3ED0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3ED8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3ED8;
    LIFT_BLOCK(label_000183C0, UINT32_C(0x004183C0));
    LIFT_PUSH2(cpu->ecx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000183E6, UINT32_C(0x004183CA));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00408FB0, UINT32_C(0x004183DB));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004183E3));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000183E6, UINT32_C(0x004183E6));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ecx);
    LIFT_BLOCK(label_000F3ED8, UINT32_C(0x004F3ED8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F21(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F21));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F2E));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F5D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3F80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F8D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3FB0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FB8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3FB8;
    LIFT_BLOCK(label_000183C0, UINT32_C(0x004183C0));
    LIFT_PUSH2(cpu->ecx, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000183E6, UINT32_C(0x004183CA));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_CALL_ENTER(sfera_sub_00408FB0, UINT32_C(0x004183DB));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004183E3));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000183E6, UINT32_C(0x004183E6));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), UINT32_C(0x00000000));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ecx);
    LIFT_BLOCK(label_000F3FB8, UINT32_C(0x004F3FB8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000183C0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F3FC6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3FC6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4000));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4008(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4040));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4049));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4070));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4078(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4078));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004CF160);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4086(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4086));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000260), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F40B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F40B9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40BB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F40BB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F40C4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F40C6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F40C6));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F40CF));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4120));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4150));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4180(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4180));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41B8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41F0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_TAIL(sfera_sub_004D37D0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F41F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41F8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4206(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4206));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F420F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4211(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4211));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F421A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4240));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4249));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F424B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F424B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4254));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4280));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4288(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4288));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F428B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F42B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F42B9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F42E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F42E9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F42EB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F42EB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F42F4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4320));
    cpu->eax = (uint32_t)(SFERA_STATIC_04F4A518_U32);
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    SFERA_STATIC_04F4A518_U32 = (uint32_t)(cpu->eax);
    LIFT_RET(0u);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4350));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F435B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F435B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000054), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4366(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4366));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000070), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4371(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4371));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000A0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F437F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F437F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000AC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F438D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F438D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_IMPORT_CALL_RETURN(SFERA_IMPORT_MSVCP100_Container_base12_dtor, UINT32_C(0x004F4390));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F4396(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4396;
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
    LIFT_BLOCK(label_000F4396, UINT32_C(0x004F4396));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000BC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B9CE0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43A4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43A4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000178), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004F43D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}
