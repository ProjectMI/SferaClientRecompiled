#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

void LIFT_CDECL sfera_sub_004EB520(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EB520));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F49C8)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x0000001C));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->edi = (uint32_t)(cpu->edx);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_CMP(cpu->esi, cpu->ebx, 32u);
    LIFT_JZ(label_000EB884, UINT32_C(0x004EB556));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000001));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), cpu->ebx);
    LIFT_CMP(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90414))))), (cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB57A, UINT32_C(0x004EB568));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_IMPORT_CALL(sfera_import_058_KERNEL32_dll_InitializeCriticalSection, UINT32_C(0x004EB56D), UINT32_C(0x004EB573));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F90414)), UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EB57A, UINT32_C(0x004EB57A));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_IMPORT_CALL(sfera_import_045_KERNEL32_dll_EnterCriticalSection, UINT32_C(0x004EB57F), UINT32_C(0x004EB585));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F90415)), UINT32_C(0x00000001));
    LIFT_CMP(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F8F770))))), UINT32_C(0x00000000), 8u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    LIFT_JNZ(label_000EB5BE, UINT32_C(0x004EB598));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515CB0)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), lift_image_va(UINT32_C(0x00515BEC)));
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
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EDDF0, UINT32_C(0x004EB5E4));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EB61A, UINT32_C(0x004EB5EC));
    LIFT_PUSH3(cpu->esi, cpu->ebx, cpu->edi);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515BBC)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), lift_image_va(UINT32_C(0x00515BEC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), UINT32_C(0x000000DB));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000001));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB612));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    goto label_000EB868;
    LIFT_BLOCK(label_000EB61A, UINT32_C(0x004EB61A));
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x04F4D760)));
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
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F8F771)), UINT32_C(0x00000001));
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
    cpu->edx = (uint32_t)(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90068))))));
    LIFT_PUSH4(cpu->edx, lift_image_va(UINT32_C(0x004FEB20)), cpu->ebx, lift_image_va(UINT32_C(0x005002E0)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax + cpu->edi + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515B84)));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EB68E));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x00525418)));
    LIFT_PUSH3(cpu->eax, lift_image_va(UINT32_C(0x00515B74)), cpu->ecx);
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8F780)));
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
    LIFT_CALL(sfera_sub_004ED380, lift_image_va(UINT32_C(0x004EB6DD)));
    LIFT_BLOCK(label_000EB6DD, UINT32_C(0x004EB6DD));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x0000000B)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EB789, UINT32_C(0x004EB6E7));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_STORE32(cpu->edx + cpu->eax + UINT32_C(0x00000004), UINT32_C(0x61CCC864));
    cpu->eax = (uint32_t)(cpu->edi);
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F8F771)), UINT32_C(0x00000001));
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
    cpu->ecx = (uint32_t)(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90068))))));
    LIFT_PUSH4(cpu->ecx, lift_image_va(UINT32_C(0x004FEB20)), cpu->ebx, lift_image_va(UINT32_C(0x005002E0)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + cpu->edi + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->edx, lift_image_va(UINT32_C(0x00515B84)));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EB73B));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525418)));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515B64)), cpu->eax);
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8F780)));
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
    LIFT_CALL(sfera_sub_004ED380, lift_image_va(UINT32_C(0x004EB789)));
    LIFT_BLOCK(label_000EB789, UINT32_C(0x004EB789));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_CALL_ENTER(sfera_sub_004EDE50, UINT32_C(0x004EB797));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB7C1, UINT32_C(0x004EB79B));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515B88)), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), lift_image_va(UINT32_C(0x00515BEC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), UINT32_C(0x000000E9));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB7BE));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EB7C1, UINT32_C(0x004EB7C1));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x00525440))))), 32u);
    LIFT_JNZ(label_000EB7D5, UINT32_C(0x004EB7CC));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525440)), cpu->ecx);
    LIFT_BLOCK(label_000EB7D5, UINT32_C(0x004EB7D5));
    LIFT_CMP(cpu->eax, lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x00525444))))), 32u);
    LIFT_JNZ(label_000EB7E6, UINT32_C(0x004EB7DD));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525444)), cpu->edx);
    LIFT_BLOCK(label_000EB7E6, UINT32_C(0x004EB7E6));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EB802, UINT32_C(0x004EB7F0));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    goto label_000EB80A;
    LIFT_BLOCK(label_000EB802, UINT32_C(0x004EB802));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525430)), cpu->eax);
    LIFT_BLOCK(label_000EB80A, UINT32_C(0x004EB80A));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EB826, UINT32_C(0x004EB814));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x0000000C), cpu->ecx);
    goto label_000EB82E;
    LIFT_BLOCK(label_000EB826, UINT32_C(0x004EB826));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525434)), cpu->eax);
    LIFT_BLOCK(label_000EB82E, UINT32_C(0x004EB82E));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8E770))))), 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8E770)))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8E770)))));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8D770))))), cpu->ecx, 0u, 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8D770)))), (uint32_t)(result)););
    LIFT_DEC(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F8F774))))), 32u, lift_store32(((uint32_t)(lift_image_va(UINT32_C(0x04F8F774)))), (uint32_t)(result)););
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8D770)))));
    LIFT_BLOCK(label_000EB868, UINT32_C(0x004EB868));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(sfera_import_351_MSVCR100_dll_free, UINT32_C(0x004EB869), UINT32_C(0x004EB86F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F90415)), UINT32_C(0x00000000));
    sfera_import_046_KERNEL32_dll_LeaveCriticalSection(cpu, lift_image_va(UINT32_C(0x004EB87E)));
    cpu->eip = lift_image_va(UINT32_C(0x004EB884));
    LIFT_BLOCK(label_000EB884, UINT32_C(0x004EB884));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EB8A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EB8A0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F49F8)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(12u, cpu->ebp);
    LIFT_BLOCK(label_000EB8FB, UINT32_C(0x004EB8FB));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x00000001));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->ebx);
    LIFT_CMP(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90414))))), (cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EB91F, UINT32_C(0x004EB90D));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_IMPORT_CALL(sfera_import_058_KERNEL32_dll_InitializeCriticalSection, UINT32_C(0x004EB912), UINT32_C(0x004EB918));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F90414)), UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EB91F, UINT32_C(0x004EB91F));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_IMPORT_CALL(sfera_import_045_KERNEL32_dll_EnterCriticalSection, UINT32_C(0x004EB924), UINT32_C(0x004EB92A));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F90415)), UINT32_C(0x00000001));
    LIFT_CMP(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F8F770))))), UINT32_C(0x00000000), 8u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    LIFT_JNZ(label_000EB95F, UINT32_C(0x004EB93D));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00001388)));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_CALL_ENTER(sfera_sub_004EDD40, UINT32_C(0x004EB94C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000032)));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4CF50)));
    LIFT_CALL_ENTER(sfera_sub_004EDA60, UINT32_C(0x004EB958));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F8F770)), UINT32_C(0x00000001));
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
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515D04)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), lift_image_va(UINT32_C(0x00515BEC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000001FB));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB99F));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EB9A2, UINT32_C(0x004EB9A2));
    LIFT_ADD(cpu->esi, UINT32_C(0xFFFFFFFC), 0u, 32u, cpu->esi = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000008), cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EDDF0, UINT32_C(0x004EB9B3));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EB9E5, UINT32_C(0x004EB9BA));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515C04)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), lift_image_va(UINT32_C(0x00515BEC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000000DE));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EB9DD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    goto label_000EBC39;
    LIFT_BLOCK(label_000EB9E5, UINT32_C(0x004EB9E5));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F4D760)));
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
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F8F771)), UINT32_C(0x00000001));
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
    cpu->edx = (uint32_t)(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90068))))));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_PUSH4(cpu->edx, lift_image_va(UINT32_C(0x004FEB20)), cpu->ecx, lift_image_va(UINT32_C(0x005002E0)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax + cpu->ebx + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->edx, lift_image_va(UINT32_C(0x00515B84)));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EBA5E));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x0052541C)));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515B74)), cpu->eax);
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8F780)));
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
    LIFT_CALL(sfera_sub_004ED380, lift_image_va(UINT32_C(0x004EBAAC)));
    LIFT_BLOCK(label_000EBAAC, UINT32_C(0x004EBAAC));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x0000000F)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EBB5D, UINT32_C(0x004EBAB6));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebx);
    LIFT_STORE32(cpu->ecx + cpu->edx + UINT32_C(0x00000004), UINT32_C(0x61CCC864));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F8F771)), UINT32_C(0x00000001));
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
    cpu->ecx = (uint32_t)(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90068))))));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000010));
    LIFT_PUSH4(cpu->ecx, lift_image_va(UINT32_C(0x004FEB20)), cpu->edx, lift_image_va(UINT32_C(0x005002E0)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax + cpu->ebx + UINT32_C(0x00000001))));
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515B84)));
    LIFT_CALL_ENTER(sfera_sub_004EA990, UINT32_C(0x004EBB0E));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x0052541C)));
    LIFT_PUSH3(cpu->eax, lift_image_va(UINT32_C(0x00515B64)), cpu->ecx);
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8F780)));
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
    LIFT_CALL(sfera_sub_004ED380, lift_image_va(UINT32_C(0x004EBB5D)));
    LIFT_BLOCK(label_000EBB5D, UINT32_C(0x004EBB5D));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_CALL_ENTER(sfera_sub_004EDE50, UINT32_C(0x004EBB6B));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EBB95, UINT32_C(0x004EBB6F));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515B88)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), lift_image_va(UINT32_C(0x00515BEC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000000E9));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EBB92));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EBB95, UINT32_C(0x004EBB95));
    LIFT_CMP(cpu->edi, lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x00525440))))), 32u);
    LIFT_JNZ(label_000EBBA6, UINT32_C(0x004EBB9D));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525440)), cpu->ecx);
    LIFT_BLOCK(label_000EBBA6, UINT32_C(0x004EBBA6));
    LIFT_CMP(cpu->edi, lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x00525444))))), 32u);
    LIFT_JNZ(label_000EBBB7, UINT32_C(0x004EBBAE));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525444)), cpu->edx);
    LIFT_BLOCK(label_000EBBB7, UINT32_C(0x004EBBB7));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EBBD3, UINT32_C(0x004EBBC1));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x0000000C));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x00000010), cpu->ecx);
    goto label_000EBBDB;
    LIFT_BLOCK(label_000EBBD3, UINT32_C(0x004EBBD3));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525430)), cpu->eax);
    LIFT_BLOCK(label_000EBBDB, UINT32_C(0x004EBBDB));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EBBF7, UINT32_C(0x004EBBE5));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    LIFT_IMUL32(cpu->eax, UINT32_C(0x0000001A));
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_STORE32(cpu->eax + cpu->edx + UINT32_C(0x0000000C), cpu->ecx);
    goto label_000EBBFF;
    LIFT_BLOCK(label_000EBBF7, UINT32_C(0x004EBBF7));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525434)), cpu->eax);
    LIFT_BLOCK(label_000EBBFF, UINT32_C(0x004EBBFF));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_DEC(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8E770))))), 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8E770)))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8E770)))));
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x000003FF), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_SUB(lift_load32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8D770))))), cpu->ecx, 0u, 32u, lift_store32(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8D770)))), (uint32_t)(result)););
    LIFT_DEC(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F8F774))))), 32u, lift_store32(((uint32_t)(lift_image_va(UINT32_C(0x04F8F774)))), (uint32_t)(result)););
    cpu->eax = (uint32_t)(((uint32_t)(((uint32_t)(cpu->eax) * 4u) + lift_image_va(UINT32_C(0x04F8D770)))));
    LIFT_BLOCK(label_000EBC39, UINT32_C(0x004EBC39));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi + UINT32_C(0x00000008))));
    LIFT_PUSH2(cpu->edx, cpu->esi);
    LIFT_IMPORT_CALL(sfera_import_355_MSVCR100_dll_realloc, UINT32_C(0x004EBC41), UINT32_C(0x004EBC47));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JNZ(label_000EBC77, UINT32_C(0x004EBC50));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515CD4)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), lift_image_va(UINT32_C(0x00515BEC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x00000203));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EBC74));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EBC77, UINT32_C(0x004EBC77));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->esi, UINT32_C(0x61CCC864));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_STORE32(cpu->esi + cpu->edi + UINT32_C(0x00000004), UINT32_C(0x61CCC864));
    LIFT_STORE32(cpu->ebp + UINT32_C(0x0000000C), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EDEF0, UINT32_C(0x004EBC9B));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JNS(label_000EBCC7, UINT32_C(0x004EBCA1));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515C20)), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), lift_image_va(UINT32_C(0x00515BEC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), UINT32_C(0x000000FE));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EBCC4));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EBCC7, UINT32_C(0x004EBCC7));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F4CF50)));
    LIFT_CALL_ENTER(sfera_sub_004EDC70, UINT32_C(0x004EBCD2));
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x00525430)));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    cpu->eax = (uint32_t)((cpu->eax & UINT32_C(0xFFFF)));
    LIFT_CMP(cpu->edx, UINT32_C(0x3B9ACA00), 32u);
    LIFT_JZ(label_000EBCFB, UINT32_C(0x004EBCE6));
    LIFT_LOAD32(cpu->ebx, lift_image_va(UINT32_C(0x04F4D760)));
    LIFT_IMUL32(cpu->edx, UINT32_C(0x0000001A));
    LIFT_STORE32(cpu->edx + cpu->ebx + UINT32_C(0x0000000C), cpu->edi);
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x00525430)));
    goto label_000EBD01;
    LIFT_BLOCK(label_000EBCFB, UINT32_C(0x004EBCFB));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525434)), cpu->edi);
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
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525430)), cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000010));
    LIFT_STORE32(cpu->edx + UINT32_C(0x00000010), cpu->edi);
    LIFT_ADD(cpu->eax, cpu->eax, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_ADD(lift_load32(((uint32_t)(cpu->eax + cpu->eax + lift_image_va(UINT32_C(0x04F8D770))))), cpu->ecx, 0u, 32u, lift_store32(((uint32_t)(cpu->eax + cpu->eax + lift_image_va(UINT32_C(0x04F8D770)))), (uint32_t)(result)););
    LIFT_ADD(cpu->eax, cpu->eax, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edx = (uint32_t)(UINT32_C(0x00000001));
    LIFT_ADD(lift_load32(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x04F8E770))))), cpu->edx, 0u, 32u, lift_store32(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x04F8E770)))), (uint32_t)(result)););
    LIFT_ADD(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F8F774))))), cpu->edx, 0u, 32u, lift_store32(((uint32_t)(lift_image_va(UINT32_C(0x04F8F774)))), (uint32_t)(result)););
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F90415)), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(sfera_import_046_KERNEL32_dll_LeaveCriticalSection, UINT32_C(0x004EBD5C), UINT32_C(0x004EBD62));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000004))));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(12u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EBD80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBD80));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F4A28)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    LIFT_CMP(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90414))))), UINT32_C(0x00000000), 8u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_JNZ(label_000EBDC7, UINT32_C(0x004EBDB5));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_IMPORT_CALL(sfera_import_058_KERNEL32_dll_InitializeCriticalSection, UINT32_C(0x004EBDBA), UINT32_C(0x004EBDC0));
    LIFT_STORE8(lift_image_va(UINT32_C(0x04F90414)), UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EBDC7, UINT32_C(0x004EBDC7));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    LIFT_IMPORT_CALL(sfera_import_039_KERNEL32_dll_TryEnterCriticalSection, UINT32_C(0x004EBDCC), UINT32_C(0x004EBDD2));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000001), 32u);
    LIFT_JNZ(label_000EBE07, UINT32_C(0x004EBDE1));
    LIFT_CMP(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90415))))), UINT32_C(0x00000000), 8u);
    LIFT_JNZ(label_000EBDFC, UINT32_C(0x004EBDEA));
    LIFT_PUSH3(UINT32_C(0x00000000), lift_image_va(UINT32_C(0x00515D2C)), UINT32_C(0xFFFFFFFF));
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CALL(sfera_sub_004EAA20, lift_image_va(UINT32_C(0x004EBDFC)));
    LIFT_BLOCK(label_000EBDFC, UINT32_C(0x004EBDFC));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F903FC))));
    sfera_import_046_KERNEL32_dll_LeaveCriticalSection(cpu, lift_image_va(UINT32_C(0x004EBE01)));
    cpu->eip = lift_image_va(UINT32_C(0x004EBE07));
    LIFT_BLOCK(label_000EBE07, UINT32_C(0x004EBE07));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EBE20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBE20));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000EBE4F, UINT32_C(0x004EBE2A));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F4CF48)));
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x00525438)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004EBE3B));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525438)), lift_image_va(UINT32_C(0x00509B68)));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F4CF48)), UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EBE4F, UINT32_C(0x004EBE4F));
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EBE60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBE60));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->eax, cpu->edx);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_CALL_ENTER(sfera_sub_004EB300, UINT32_C(0x004EBE6F));
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EBE80(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EBEA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBEA0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F4CF48)));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x00525438)));
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
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525438)), lift_image_va(UINT32_C(0x00509B68)));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F4CF48)), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->esi, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EBEF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBEF0));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F8FACC)));
    LIFT_PUSH3(cpu->esi, cpu->edi, cpu->eax);
    cpu->esi = (uint32_t)(cpu->edx);
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x00515D6C))));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_IMPORT_CALL(sfera_import_334_MSVCR100_dll__snprintf, UINT32_C(0x004EBF03), UINT32_C(0x004EBF09));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_STORE8(cpu->edi + cpu->esi + UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    LIFT_EPILOGUE2(0u, cpu->edi, cpu->esi);
}

void LIFT_CDECL sfera_sub_004EBF20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBF20));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F8FAD0)), cpu->ecx);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EBF30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBF30));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(sfera_import_250_MSVCR100_dll_printf, UINT32_C(0x004EBF31), UINT32_C(0x004EBF37));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOGIC((cpu->eax & UINT32_C(0xFF)), (cpu->eax & UINT32_C(0xFF)), ^, 8u, cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EBF40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EBF40));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    cpu->eax = (uint32_t)(UINT32_C(0x00001204));
    LIFT_CALL_ENTER(sfera_sub_004EEAF0, UINT32_C(0x004EBF4D));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(UINT32_C(0x00000014));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFEE0C))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFEDFC), lift_image_va(UINT32_C(0x00515DA8)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFEE00), lift_image_va(UINT32_C(0x00515D98)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFEE04), lift_image_va(UINT32_C(0x00515D90)));
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
    LIFT_IMPORT_CALL(sfera_import_308_MSVCR100_dll__stricmp, UINT32_C(0x004EBFB9), UINT32_C(0x004EBFBF));
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
    LIFT_PUSH6(cpu->ecx, cpu->edx, cpu->ebx, cpu->eax, cpu->edi, lift_image_va(UINT32_C(0x00515D78)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF8C))));
    LIFT_PUSH2(UINT32_C(0x0000006F), cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_334_MSVCR100_dll__snprintf, UINT32_C(0x004EBFEC), UINT32_C(0x004EBFF2));
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
    cpu->edx = (uint32_t)(lift_load8(((uint32_t)(lift_image_va(UINT32_C(0x04F90068))))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF6CC))));
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515D70)));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8FDA0)));
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EC05F));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004ED410, UINT32_C(0x004EC066));
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_CALL(sfera_sub_004ED380, lift_image_va(UINT32_C(0x004EC06D)));
    LIFT_BLOCK(label_000EC06D, UINT32_C(0x004EC06D));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F8FAD0)));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EC07D, UINT32_C(0x004EC076));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8FDA0)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004EC07D)), lift_image_va(UINT32_C(0x004EC07B)))) { return; }
    LIFT_BLOCK(label_000EC07D, UINT32_C(0x004EC07D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC087));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EC090(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC090));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515DB8)), cpu->edi);
    cpu->esi = (uint32_t)(cpu->edx);
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004EC0AD), UINT32_C(0x004EC0B3));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC1A6, UINT32_C(0x004EC0BE));
    LIFT_PUSH3(cpu->eax, UINT32_C(0x00008000), lift_image_va(UINT32_C(0x00515DB8)));
    LIFT_IMPORT_CALL(sfera_import_312_MSVCR100_dll___open__YAHPBDHH_Z, UINT32_C(0x004EC0C9), UINT32_C(0x004EC0CF));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EC0ED, UINT32_C(0x004EC0D9));
    LIFT_PUSH2(cpu->edi, lift_image_va(UINT32_C(0x00515DB8)));
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004EC0DF), UINT32_C(0x004EC0E5));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    goto label_000EC1A6;
    LIFT_BLOCK(label_000EC0ED, UINT32_C(0x004EC0ED));
    LIFT_PUSH3(UINT32_C(0x00000180), UINT32_C(0x00008302), cpu->edi);
    LIFT_IMPORT_CALL(sfera_import_312_MSVCR100_dll___open__YAHPBDHH_Z, UINT32_C(0x004EC0F8), UINT32_C(0x004EC0FE));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EC11F, UINT32_C(0x004EC109));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_IMPORT_CALL(sfera_import_310_MSVCR100_dll__close, UINT32_C(0x004EC10A), UINT32_C(0x004EC110));
    LIFT_PUSH2(cpu->edi, lift_image_va(UINT32_C(0x00515DB8)));
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004EC116), UINT32_C(0x004EC11C));
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
    LIFT_IMPORT_CALL(sfera_import_314_MSVCR100_dll__lseek, UINT32_C(0x004EC144), UINT32_C(0x004EC14A));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EC189, UINT32_C(0x004EC152));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_PUSH3(cpu->esi, cpu->eax, cpu->ebx);
    LIFT_IMPORT_CALL(sfera_import_311_MSVCR100_dll__read, UINT32_C(0x004EC158), UINT32_C(0x004EC15E));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EC189, UINT32_C(0x004EC165));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_PUSH3(cpu->esi, cpu->ecx, cpu->edx);
    LIFT_IMPORT_CALL(sfera_import_313_MSVCR100_dll__write, UINT32_C(0x004EC16E), UINT32_C(0x004EC174));
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
    LIFT_LOAD32(cpu->esi, lift_image_va(UINT32_C(0x004FD3B8)));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EC192)), lift_image_va(UINT32_C(0x004EC190)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC192));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EC198)), lift_image_va(UINT32_C(0x004EC196)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC198));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x00515DB8))));
    LIFT_IMPORT_CALL(sfera_import_303_MSVCR100_dll_remove, UINT32_C(0x004EC19D), UINT32_C(0x004EC1A3));
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

void LIFT_CDECL sfera_sub_004EC1C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC1C0));
    LIFT_STORE32(lift_image_va(UINT32_C(0x0052544C)), cpu->ecx);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JNZ(label_000EC1D4, UINT32_C(0x004EC1CA));
    LIFT_STORE32(lift_image_va(UINT32_C(0x0052544C)), lift_image_va(UINT32_C(0x004EBF30)));
    LIFT_BLOCK(label_000EC1D4, UINT32_C(0x004EC1D4));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EC1E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC1E0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000040));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525450)));
    LIFT_PUSH4(cpu->ebx, cpu->esi, lift_image_va(UINT32_C(0x004FE10C)), cpu->eax);
    cpu->ebx = (cpu->ebx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((cpu->edx & UINT32_C(0xFF))) & UINT32_C(0xFF));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFC8), cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_333_MSVCR100_dll_fopen, UINT32_C(0x004EC202), UINT32_C(0x004EC208));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000EC2CC, UINT32_C(0x004EC215));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, lift_image_va(UINT32_C(0x004FD36C)));
    LIFT_TEST((cpu->ebx & UINT32_C(0xFF)), 8u);
    LIFT_JZ(label_000EC273, UINT32_C(0x004EC220));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC0))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(sfera_import_345_MSVCR100_dll__time64, UINT32_C(0x004EC224), UINT32_C(0x004EC22A));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC0))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(sfera_import_344_MSVCR100_dll__localtime64, UINT32_C(0x004EC22E), UINT32_C(0x004EC234));
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515DC8)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_347_MSVCR100_dll_strftime, UINT32_C(0x004EC240), UINT32_C(0x004EC246));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x04F8FACC)));
    LIFT_PUSH2(cpu->ecx, lift_image_va(UINT32_C(0x00515D6C)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(sfera_import_334_MSVCR100_dll__snprintf, UINT32_C(0x004EC258), UINT32_C(0x004EC25E));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(cpu->esi, cpu->eax);
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFB), UINT32_C(0x00000000));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC269)), lift_image_va(UINT32_C(0x004EC267)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC269));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(cpu->esi, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC270)), lift_image_va(UINT32_C(0x004EC26E)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC270));
    LIFT_SP_ADD(UINT32_C(0x00000038));
    LIFT_BLOCK(label_000EC273, UINT32_C(0x004EC273));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFC8));
    LIFT_PUSH2(cpu->esi, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC27A)), lift_image_va(UINT32_C(0x004EC278)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC27A));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EC28E, UINT32_C(0x004EC283));
    LIFT_PUSH2(cpu->esi, lift_image_va(UINT32_C(0x004FEB20)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC28B)), lift_image_va(UINT32_C(0x004EC289)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC28B));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000EC28E, UINT32_C(0x004EC28E));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(sfera_import_259_MSVCR100_dll_fflush, UINT32_C(0x004EC28F), UINT32_C(0x004EC295));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(sfera_import_330_MSVCR100_dll_ftell, UINT32_C(0x004EC296), UINT32_C(0x004EC29C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_332_MSVCR100_dll_fclose, UINT32_C(0x004EC29F), UINT32_C(0x004EC2A5));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), UINT32_C(0x00000000), 8u);
    LIFT_JZ(label_000EC2CB, UINT32_C(0x004EC2AE));
    LIFT_CMP(cpu->edi, UINT32_C(0x00108000), 32u);
    LIFT_JLE(label_000EC2CB, UINT32_C(0x004EC2B6));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x00525450)));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000200)));
    cpu->edx = (uint32_t)(UINT32_C(0x00000800));
    LIFT_CALL(sfera_sub_004EC090, lift_image_va(UINT32_C(0x004EC2CB)));
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

void LIFT_CDECL sfera_sub_004EC2E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC2E0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000083C));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F8FAC8)));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(UINT32_C(0x00000001));
    LIFT_ADD(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F8FAC8)), cpu->eax);
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JLE(label_000EC3D0, UINT32_C(0x004EC30E));
    LIFT_CMP(cpu->eax, UINT32_C(0x00000002), 32u);
    LIFT_JNZ(label_000EC3C1, UINT32_C(0x004EC317));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525450)));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x004FE10C)), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_333_MSVCR100_dll_fopen, UINT32_C(0x004EC322), UINT32_C(0x004EC328));
    cpu->esi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000EC3BC, UINT32_C(0x004EC335));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7C4))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(sfera_import_345_MSVCR100_dll__time64, UINT32_C(0x004EC33C), UINT32_C(0x004EC342));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7C4))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(sfera_import_344_MSVCR100_dll__localtime64, UINT32_C(0x004EC349), UINT32_C(0x004EC34F));
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515DC8)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_347_MSVCR100_dll_strftime, UINT32_C(0x004EC35B), UINT32_C(0x004EC361));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x04F8FACC)));
    LIFT_PUSH2(cpu->ecx, lift_image_va(UINT32_C(0x00515D6C)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(sfera_import_334_MSVCR100_dll__snprintf, UINT32_C(0x004EC373), UINT32_C(0x004EC379));
    LIFT_LOAD32(cpu->edi, lift_image_va(UINT32_C(0x004FD36C)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_PUSH2(cpu->esi, cpu->eax);
    LIFT_STORE8(cpu->ebp + UINT32_C(0xFFFFFFFB), UINT32_C(0x00000000));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC38A)), lift_image_va(UINT32_C(0x004EC388)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC38A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(cpu->esi, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC391)), lift_image_va(UINT32_C(0x004EC38F)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC391));
    LIFT_PUSH2(cpu->esi, lift_image_va(UINT32_C(0x00515DF8)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC399)), lift_image_va(UINT32_C(0x004EC397)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC399));
    LIFT_SP_ADD(UINT32_C(0x00000040));
    LIFT_PUSH2(cpu->esi, lift_image_va(UINT32_C(0x004FEB20)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EC3A4)), lift_image_va(UINT32_C(0x004EC3A2)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC3A4));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(sfera_import_259_MSVCR100_dll_fflush, UINT32_C(0x004EC3A5), UINT32_C(0x004EC3AB));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(sfera_import_330_MSVCR100_dll_ftell, UINT32_C(0x004EC3AC), UINT32_C(0x004EC3B2));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(sfera_import_332_MSVCR100_dll_fclose, UINT32_C(0x004EC3B3), UINT32_C(0x004EC3B9));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_BLOCK(label_000EC3BC, UINT32_C(0x004EC3BC));
    cpu->esi = (uint32_t)(UINT32_C(0x00000001));
    LIFT_BLOCK(label_000EC3C1, UINT32_C(0x004EC3C1));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_IMPORT_CALL(sfera_import_056_KERNEL32_dll_GetCurrentProcess, UINT32_C(0x004EC3C3), UINT32_C(0x004EC3C9));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    sfera_import_080_KERNEL32_dll_TerminateProcess(cpu, lift_image_va(UINT32_C(0x004EC3CA)));
    cpu->eip = lift_image_va(UINT32_C(0x004EC3D0));
    LIFT_BLOCK(label_000EC3D0, UINT32_C(0x004EC3D0));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F8FACC)));
    LIFT_ADD(cpu->eax, cpu->esi, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F8FACC)), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0x000003E8), 32u);
    LIFT_JNZ(label_000EC3ED, UINT32_C(0x004EC3E3));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F8FACC)), UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EC3ED, UINT32_C(0x004EC3ED));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000010))));
    LIFT_PUSH2(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_PUSH2(UINT32_C(0x00000800), cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_287_MSVCR100_dll__vsnprintf, UINT32_C(0x004EC401), UINT32_C(0x004EC407));
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
    cpu->edx = (cpu->edx & UINT32_C(0xFFFF0000)) | ((uint32_t)(lift_load16(((uint32_t)(lift_image_va(UINT32_C(0x004FEB20)))))) & UINT32_C(0xFFFF));
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
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8FDA0)));
    LIFT_CALL_ENTER(sfera_sub_004ED100, UINT32_C(0x004EC466));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CALL_ENTER(sfera_sub_004EBF40, UINT32_C(0x004EC46D));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x0052544C)))))), lift_image_va(UINT32_C(0x004EC47B)), lift_image_va(UINT32_C(0x004EC475)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC47B));
    goto label_000EC4B9;
    LIFT_BLOCK(label_000EC47D, UINT32_C(0x004EC47D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8FDA0)));
    LIFT_CALL_ENTER(sfera_sub_004ED100, UINT32_C(0x004EC492));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CALL_ENTER(sfera_sub_004EBF40, UINT32_C(0x004EC499));
    LIFT_LOGIC((cpu->edx & UINT32_C(0xFF)), (cpu->edx & UINT32_C(0xFF)), ^, 8u, cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(result) & UINT32_C(0xFF)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x0052544C)))))), lift_image_va(UINT32_C(0x004EC4A7)), lift_image_va(UINT32_C(0x004EC4A1)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC4A7));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000EC4E9, UINT32_C(0x004EC4AB));
    LIFT_PUSH2(cpu->esi, cpu->esi);
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(UINT32_C(0x00000001)) & UINT32_C(0xFF));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x00515DDC)));
    LIFT_CALL(sfera_sub_004EC1E0, lift_image_va(UINT32_C(0x004EC4B9)));
    LIFT_BLOCK(label_000EC4B9, UINT32_C(0x004EC4B9));
    LIFT_CALL_ENTER(sfera_sub_004EBD80, UINT32_C(0x004EC4BE));
    LIFT_CALL_ENTER(sfera_sub_004ED150, UINT32_C(0x004EC4C3));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_IMPORT_CALL(sfera_import_056_KERNEL32_dll_GetCurrentProcess, UINT32_C(0x004EC4C5), UINT32_C(0x004EC4CB));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_080_KERNEL32_dll_TerminateProcess, UINT32_C(0x004EC4CC), UINT32_C(0x004EC4D2));
    goto label_000EC4E9;
    LIFT_BLOCK(label_000EC4D4, UINT32_C(0x004EC4D4));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x0000000C));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFF7CC))));
    LIFT_PUSH2(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F8FAD8)));
    LIFT_CALL(sfera_sub_004ED100, lift_image_va(UINT32_C(0x004EC4E9)));
    LIFT_BLOCK(label_000EC4E9, UINT32_C(0x004EC4E9));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_SUB(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F8FAC8))))), cpu->esi, 0u, 32u, lift_store32(((uint32_t)(lift_image_va(UINT32_C(0x04F8FAC8)))), (uint32_t)(result)););
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC4FB));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EC500(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC500));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F4A5B)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000010));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515E80)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), lift_image_va(UINT32_C(0x00515E70)));
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
    LIFT_LOAD32(cpu->ebx, lift_image_va(UINT32_C(0x004FD458)));
    LIFT_SUB(cpu->eax, cpu->edx, 0u, 32u, cpu->eax = (uint32_t)(result););
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax + UINT32_C(0x00000001))));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EC5A5)), lift_image_va(UINT32_C(0x004EC5A3)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC5A5));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000008), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC5D6, UINT32_C(0x004EC5AF));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515E48)), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), lift_image_va(UINT32_C(0x00515E70)));
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
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EC60F)), lift_image_va(UINT32_C(0x004EC60D)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC60F));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000000C), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC640, UINT32_C(0x004EC619));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515E48)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), lift_image_va(UINT32_C(0x00515E70)));
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
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EC672)), lift_image_va(UINT32_C(0x004EC670)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC672));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000024), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC6A3, UINT32_C(0x004EC67C));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515E48)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), lift_image_va(UINT32_C(0x00515E70)));
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
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EC6C2)), lift_image_va(UINT32_C(0x004EC6C0)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC6C2));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000018), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC6F7, UINT32_C(0x004EC6CC));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00002000)));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515E48)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), lift_image_va(UINT32_C(0x00515E70)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x00000043));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC6F4));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC6F7, UINT32_C(0x004EC6F7));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), UINT32_C(0x00000008), &, 8u);
    LIFT_JZ(label_000EC73A, UINT32_C(0x004EC6FD));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000030), cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EC703)), lift_image_va(UINT32_C(0x004EC701)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EC703));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000002C), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC734, UINT32_C(0x004EC70D));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515E48)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), lift_image_va(UINT32_C(0x00515E70)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), UINT32_C(0x0000004B));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EC731));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EC734, UINT32_C(0x004EC734));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x0000002C));
    LIFT_STORE8(cpu->edx, UINT32_C(0x00000000));
    LIFT_BLOCK(label_000EC73A, UINT32_C(0x004EC73A));
    LIFT_STORE32(cpu->esi, UINT32_C(0x00000000));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F9006C)));
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->eax);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9006C)), cpu->esi);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EC757, UINT32_C(0x004EC755));
    LIFT_STORE32(cpu->eax, cpu->esi);
    LIFT_BLOCK(label_000EC757, UINT32_C(0x004EC757));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(24u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EC770(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_355_MSVCR100_dll_realloc, UINT32_C(0x004EC7BF), UINT32_C(0x004EC7C5));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->edi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EC7FA, UINT32_C(0x004EC7CE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->edx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->edx));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00515ECC)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), lift_image_va(UINT32_C(0x00515E70)));
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

void LIFT_CDECL sfera_sub_004EC830(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC830));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
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
    LIFT_IMPORT_CALL(sfera_import_318_MSVCR100_dll__chmod, UINT32_C(0x004EC885), UINT32_C(0x004EC88B));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_IMPORT_CALL(sfera_import_303_MSVCR100_dll_remove, UINT32_C(0x004EC88C), UINT32_C(0x004EC892));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_LOAD32(cpu->ecx, cpu->eax + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004EC89A), UINT32_C(0x004EC8A0));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EC8B3));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EC8C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC8C0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000002C));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_345_MSVCR100_dll__time64, UINT32_C(0x004EC8DB), UINT32_C(0x004EC8E1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(sfera_import_344_MSVCR100_dll__localtime64, UINT32_C(0x004EC8E5), UINT32_C(0x004EC8EB));
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515F00)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->edx);
    LIFT_IMPORT_CALL(sfera_import_347_MSVCR100_dll_strftime, UINT32_C(0x004EC8F7), UINT32_C(0x004EC8FD));
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

void LIFT_CDECL sfera_sub_004EC980(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EC980));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000084));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
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
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004EC9D0)), lift_image_va(UINT32_C(0x004EC9CE)))) { return; }
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

void LIFT_CDECL sfera_sub_004ECA00(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_314_MSVCR100_dll__lseek, UINT32_C(0x004ECA37), UINT32_C(0x004ECA3D));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECA73, UINT32_C(0x004ECA45));
    LIFT_LOAD32(cpu->edx, cpu->edi + UINT32_C(0x00000018));
    LIFT_PUSH3(UINT32_C(0x00002000), cpu->edx, cpu->ebx);
    LIFT_IMPORT_CALL(sfera_import_311_MSVCR100_dll__read, UINT32_C(0x004ECA4F), UINT32_C(0x004ECA55));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECA73, UINT32_C(0x004ECA5D));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH3(UINT32_C(0x00002000), cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_313_MSVCR100_dll__write, UINT32_C(0x004ECA6A), UINT32_C(0x004ECA70));
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
    LIFT_IMPORT_CALL(sfera_import_314_MSVCR100_dll__lseek, UINT32_C(0x004ECA9F), UINT32_C(0x004ECAA5));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECAD6, UINT32_C(0x004ECAAD));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->edx, cpu->edi + UINT32_C(0x00000018));
    LIFT_PUSH3(cpu->esi, cpu->edx, cpu->ebx);
    LIFT_IMPORT_CALL(sfera_import_311_MSVCR100_dll__read, UINT32_C(0x004ECAB6), UINT32_C(0x004ECABC));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECAD6, UINT32_C(0x004ECAC4));
    LIFT_LOAD32(cpu->eax, cpu->edi + UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH3(cpu->esi, cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_313_MSVCR100_dll__write, UINT32_C(0x004ECACD), UINT32_C(0x004ECAD3));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000ECAD6, UINT32_C(0x004ECAD6));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(16u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ECAE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECAE0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
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
    LIFT_CALL(sfera_sub_004EC8C0, lift_image_va(UINT32_C(0x004ECB1C)));
    LIFT_BLOCK(label_000ECB1C, UINT32_C(0x004ECB1C));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x004FE10C)), cpu->edi);
    LIFT_IMPORT_CALL(sfera_import_333_MSVCR100_dll_fopen, UINT32_C(0x004ECB22), UINT32_C(0x004ECB28));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->edi, 32u);
    LIFT_JZ(label_000ECB93, UINT32_C(0x004ECB31));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->edi, cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_291_MSVCR100_dll_fputs, UINT32_C(0x004ECB36), UINT32_C(0x004ECB3C));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->esi + UINT32_C(0x00000010)))), UINT32_C(0x00000004), &, 8u);
    LIFT_JZ(label_000ECB4F, UINT32_C(0x004ECB45));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(sfera_import_259_MSVCR100_dll_fflush, UINT32_C(0x004ECB46), UINT32_C(0x004ECB4C));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000ECB4F, UINT32_C(0x004ECB4F));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), UINT32_C(0x00000000), 32u);
    LIFT_JLE(label_000ECB89, UINT32_C(0x004ECB55));
    LIFT_INC(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C)))), 32u, lift_store32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C))), (uint32_t)(result)););
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x0000001C)))), UINT32_C(0x000001F4), 32u);
    LIFT_JL(label_000ECB89, UINT32_C(0x004ECB61));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->esi + UINT32_C(0x0000001C), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(sfera_import_330_MSVCR100_dll_ftell, UINT32_C(0x004ECB69), UINT32_C(0x004ECB6F));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_332_MSVCR100_dll_fclose, UINT32_C(0x004ECB72), UINT32_C(0x004ECB78));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_CMP(cpu->ebx, lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000014)))), 32u);
    LIFT_JLE(label_000ECB93, UINT32_C(0x004ECB80));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004EC830, UINT32_C(0x004ECB87));
    goto label_000ECB93;
    LIFT_BLOCK(label_000ECB89, UINT32_C(0x004ECB89));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(sfera_import_332_MSVCR100_dll_fclose, UINT32_C(0x004ECB8A), UINT32_C(0x004ECB90));
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

void LIFT_CDECL sfera_sub_004ECBB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECBB0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000018));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
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
    LIFT_IMPORT_CALL(sfera_import_312_MSVCR100_dll___open__YAHPBDHH_Z, UINT32_C(0x004ECC0F), UINT32_C(0x004ECC15));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECC24, UINT32_C(0x004ECC1F));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    goto label_000ECC3E;
    LIFT_BLOCK(label_000ECC24, UINT32_C(0x004ECC24));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(sfera_import_349_MSVCR100_dll__filelength, UINT32_C(0x004ECC25), UINT32_C(0x004ECC2B));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_310_MSVCR100_dll__close, UINT32_C(0x004ECC2F), UINT32_C(0x004ECC35));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF8));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    LIFT_BLOCK(label_000ECC3E, UINT32_C(0x004ECC3E));
    LIFT_PUSH3(UINT32_C(0x00000000), UINT32_C(0x00008000), cpu->ebx);
    LIFT_IMPORT_CALL(sfera_import_312_MSVCR100_dll___open__YAHPBDHH_Z, UINT32_C(0x004ECC46), UINT32_C(0x004ECC4C));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECC5B, UINT32_C(0x004ECC56));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    goto label_000ECC7A;
    LIFT_BLOCK(label_000ECC5B, UINT32_C(0x004ECC5B));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(sfera_import_349_MSVCR100_dll__filelength, UINT32_C(0x004ECC5C), UINT32_C(0x004ECC62));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_310_MSVCR100_dll__close, UINT32_C(0x004ECC66), UINT32_C(0x004ECC6C));
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
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004ECC9E), UINT32_C(0x004ECCA4));
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
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004ECCD9), UINT32_C(0x004ECCDF));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000ECE61, UINT32_C(0x004ECCEA));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_PUSH3(UINT32_C(0x00000180), UINT32_C(0x00008302), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_312_MSVCR100_dll___open__YAHPBDHH_Z, UINT32_C(0x004ECCF8), UINT32_C(0x004ECCFE));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->edi, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECD34, UINT32_C(0x004ECD08));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(sfera_import_303_MSVCR100_dll_remove, UINT32_C(0x004ECD0C), UINT32_C(0x004ECD12));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->edx, cpu->ebx);
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004ECD17), UINT32_C(0x004ECD1D));
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
    LIFT_IMPORT_CALL(sfera_import_312_MSVCR100_dll___open__YAHPBDHH_Z, UINT32_C(0x004ECD47), UINT32_C(0x004ECD4D));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECD8D, UINT32_C(0x004ECD57));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_IMPORT_CALL(sfera_import_310_MSVCR100_dll__close, UINT32_C(0x004ECD58), UINT32_C(0x004ECD5E));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(sfera_import_303_MSVCR100_dll_remove, UINT32_C(0x004ECD62), UINT32_C(0x004ECD68));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_PUSH2(cpu->edx, cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004ECD70), UINT32_C(0x004ECD76));
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
    LIFT_IMPORT_CALL(sfera_import_312_MSVCR100_dll___open__YAHPBDHH_Z, UINT32_C(0x004ECD98), UINT32_C(0x004ECD9E));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000ECDE4, UINT32_C(0x004ECDA9));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, lift_image_va(UINT32_C(0x004FD3B8)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004ECDB2)), lift_image_va(UINT32_C(0x004ECDB0)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECDB2));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004ECDB5)), lift_image_va(UINT32_C(0x004ECDB3)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECDB5));
    LIFT_LOAD32(cpu->edx, cpu->esi + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(sfera_import_303_MSVCR100_dll_remove, UINT32_C(0x004ECDB9), UINT32_C(0x004ECDBF));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_281_MSVCR100_dll_rename, UINT32_C(0x004ECDC7), UINT32_C(0x004ECDCD));
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
    LIFT_LOAD32(cpu->edi, lift_image_va(UINT32_C(0x004FD3B8)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004ECE3B)), lift_image_va(UINT32_C(0x004ECE39)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE3B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004ECE41)), lift_image_va(UINT32_C(0x004ECE3F)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE41));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOAD32(cpu->esi, lift_image_va(UINT32_C(0x004FD39C)));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004ECE4D)), lift_image_va(UINT32_C(0x004ECE4B)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE4D));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000ECE61, UINT32_C(0x004ECE55));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004ECE58)), lift_image_va(UINT32_C(0x004ECE56)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ECE58));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004ECE5E)), lift_image_va(UINT32_C(0x004ECE5C)))) { return; }
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

void LIFT_CDECL sfera_sub_004ECE80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECE80));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000028));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
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
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515F14)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_PUSH2(UINT32_C(0x00000020), cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_334_MSVCR100_dll__snprintf, UINT32_C(0x004ECEC2), UINT32_C(0x004ECEC8));
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
    LIFT_CALL(sfera_sub_004ECAE0, lift_image_va(UINT32_C(0x004ECF41)));
    LIFT_BLOCK(label_000ECF41, UINT32_C(0x004ECF41));
    cpu->esp = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_POP3(cpu->edi, cpu->esi, cpu->ebx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ECF51));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ECF60(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_CALL(sfera_sub_004ECE80, lift_image_va(UINT32_C(0x004ECFA6)));
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
    LIFT_CALL(sfera_sub_004ECE80, lift_image_va(UINT32_C(0x004ECFC2)));
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

void LIFT_CDECL sfera_sub_004ECFE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ECFE0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000002C));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
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
    LIFT_IMPORT_CALL(sfera_import_345_MSVCR100_dll__time64, UINT32_C(0x004ED053), UINT32_C(0x004ED059));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_IMPORT_CALL(sfera_import_344_MSVCR100_dll__localtime64, UINT32_C(0x004ED05D), UINT32_C(0x004ED063));
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00515F08)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(sfera_import_347_MSVCR100_dll_strftime, UINT32_C(0x004ED06F), UINT32_C(0x004ED075));
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
    LIFT_IMPORT_CALL(sfera_import_290_MSVCR100_dll__strtime, UINT32_C(0x004ED098), UINT32_C(0x004ED09E));
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
    LIFT_CALL(sfera_sub_004EC980, lift_image_va(UINT32_C(0x004ED0CA)));
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
    LIFT_CALL(sfera_sub_004EC770, lift_image_va(UINT32_C(0x004ED0EB)));
    LIFT_BLOCK(label_000ED0EB, UINT32_C(0x004ED0EB));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_POP2(cpu->edi, cpu->ebx);
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED0F8));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED100(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_CALL(sfera_sub_004EC770, lift_image_va(UINT32_C(0x004ED13E)));
    LIFT_BLOCK(label_000ED13E, UINT32_C(0x004ED13E));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED145));
    LIFT_EPILOGUE2(8u, cpu->esi, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED150));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->esi, lift_image_va(UINT32_C(0x04F9006C)));
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

void LIFT_CDECL sfera_sub_004ED380(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED380));
    LIFT_CALL_ENTER(sfera_sub_004ECF60, UINT32_C(0x004ED385));
    LIFT_RET(4u);
}

void LIFT_CDECL sfera_sub_004ED390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED390));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000014));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000024));
    LIFT_CMP(lift_load8(((uint32_t)(cpu->eax))), UINT32_C(0x00000000), 8u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000024))));
    LIFT_JNZ(label_000ED3B4, UINT32_C(0x004ED3AF));
    LIFT_CALL(sfera_sub_004ECFE0, lift_image_va(UINT32_C(0x004ED3B4)));
    LIFT_BLOCK(label_000ED3B4, UINT32_C(0x004ED3B4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->ecx, lift_image_va(UINT32_C(0x004FDE7C)));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_PUSH2(UINT32_C(0x00000010), cpu->edx);
    LIFT_IMPORT_CALL(sfera_import_334_MSVCR100_dll__snprintf, UINT32_C(0x004ED3C3), UINT32_C(0x004ED3C9));
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
    LIFT_CALL(sfera_sub_004ECF60, lift_image_va(UINT32_C(0x004ED3EE)));
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

void LIFT_CDECL sfera_sub_004ED410(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_CALL(sfera_sub_004ECFE0, lift_image_va(UINT32_C(0x004ED427)));
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
    LIFT_CALL(sfera_sub_004EC770, lift_image_va(UINT32_C(0x004ED450)));
    LIFT_BLOCK(label_000ED450, UINT32_C(0x004ED450));
    cpu->ebx = (uint32_t)(lift_pop32(cpu));
    LIFT_CMP(cpu->edi, UINT32_C(0x00000800), 32u);
    LIFT_JLE(label_000ED460, UINT32_C(0x004ED459));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL(sfera_sub_004ECF60, lift_image_va(UINT32_C(0x004ED460)));
    LIFT_BLOCK(label_000ED460, UINT32_C(0x004ED460));
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE2(4u, cpu->esi, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED470(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_STORE16(((uint32_t)(cpu->edx) * 2u) + lift_image_va(UINT32_C(0x04F90070)), (cpu->ecx & UINT32_C(0xFFFF)));
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_CMP(cpu->edx, UINT32_C(0x00000100), 32u);
    LIFT_JL(label_000ED474, UINT32_C(0x004ED535));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004ED5C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000ED5C0;
    LIFT_BLOCK(label_000ED540, UINT32_C(0x004ED540));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000003C));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000006));
    cpu->esi = (uint32_t)(lift_image_va(UINT32_C(0x00515F50)));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->ecx = (uint32_t)(UINT32_C(0x00000006));
    cpu->esi = (uint32_t)(lift_image_va(UINT32_C(0x00515F34)));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC4))));
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->edi = (uint32_t)(lift_pop32(cpu));
    LIFT_ZERO(cpu->eax, 32u);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->ebx)));
    LIFT_BLOCK(label_000ED580, UINT32_C(0x004ED580));
    LIFT_STORE8(cpu->eax + lift_image_va(UINT32_C(0x04F90270)), (cpu->eax & UINT32_C(0xFF)));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_CMP(cpu->eax, UINT32_C(0x00000100), 32u);
    LIFT_JL(label_000ED580, UINT32_C(0x004ED58E));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_BLOCK(label_000ED590, UINT32_C(0x004ED590));
    cpu->ecx = (uint32_t)(lift_load8(((uint32_t)(cpu->ebp + cpu->eax + UINT32_C(0xFFFFFFE0)))));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ebp + cpu->eax + UINT32_C(0xFFFFFFC4))))) & UINT32_C(0xFF));
    LIFT_INC(cpu->eax, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE8(cpu->ecx + lift_image_va(UINT32_C(0x04F90270)), (cpu->edx & UINT32_C(0xFF)));
    LIFT_CMP(cpu->eax, UINT32_C(0x0000001B), 32u);
    LIFT_JB(label_000ED590, UINT32_C(0x004ED5A5));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->ebp, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004ED5AF));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ED5C0, UINT32_C(0x004ED5C0));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90370))))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000ED5DD, UINT32_C(0x004ED5C9));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90370)), UINT32_C(0x00000001));
    LIFT_CALL_ENTER(sfera_sub_004ED470, UINT32_C(0x004ED5D8));
    goto label_000ED540;
    LIFT_BLOCK(label_000ED5DD, UINT32_C(0x004ED5DD));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004ED5E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED5E0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000014));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_PUSH5(cpu->ecx, lift_image_va(UINT32_C(0x00515F88)), UINT32_C(0x00000001), UINT32_C(0x00000013), lift_image_va(UINT32_C(0x00515F6C)));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_CALL_ENTER(sfera_sub_004013B0, UINT32_C(0x004ED60A));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED610));
    LIFT_SP_ADD(UINT32_C(0x00000010));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED620(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_256_MSVCR100_dll_isalpha, UINT32_C(0x004ED644), UINT32_C(0x004ED64A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000ED6ED, UINT32_C(0x004ED655));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFF)))))));
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)(lift_load8(((uint32_t)(cpu->ecx + lift_image_va(UINT32_C(0x04F90270)))))) & UINT32_C(0xFF));
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
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ecx + lift_image_va(UINT32_C(0x04F90270))))))));
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
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx + lift_image_va(UINT32_C(0x04F90270))))))));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->ecx))))));
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx + lift_image_va(UINT32_C(0x04F90270))))))));
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
    cpu->ecx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x04F90270))))))));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    cpu->eax = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->edx))))));
    cpu->edx = (uint32_t)(((int8_t)(lift_load8(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x04F90270))))))));
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

void LIFT_CDECL sfera_sub_004ED770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED770));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(UINT32_C(0x00000017), lift_image_va(UINT32_C(0x00515FC8)));
    LIFT_CALL_ENTER(sfera_sub_004EB300, UINT32_C(0x004ED785));
    LIFT_EPILOGUE1(8u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED790(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED790));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->edx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH3(UINT32_C(0x0000001C), lift_image_va(UINT32_C(0x00515FC8)), cpu->eax);
    LIFT_CALL_ENTER(sfera_sub_004EB8A0, UINT32_C(0x004ED7A9));
    LIFT_EPILOGUE1(12u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED7B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004ED7B0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000021)));
    cpu->edx = (uint32_t)(lift_image_va(UINT32_C(0x00515FC8)));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x004ED7C2));
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED7D0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004ED7F0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00516070)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x00516020)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000075));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->edx);
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED82B));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_ZERO(cpu->eax, 32u);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000ED834, UINT32_C(0x004ED834));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x0051604C)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), lift_image_va(UINT32_C(0x00516020)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000072));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), cpu->edx);
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED853));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_ZERO(cpu->eax, 32u);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED860(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_PUSH2(lift_image_va(UINT32_C(0x005160BC)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x00516020)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000085));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED89D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_BLOCK(label_000ED8A0, UINT32_C(0x004ED8A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00516094)), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), lift_image_va(UINT32_C(0x00516020)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFEC), UINT32_C(0x00000087));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004ED8C7));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004ED8E0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_054_KERNEL32_dll_UnmapViewOfFile, UINT32_C(0x004ED8F5), UINT32_C(0x004ED8FB));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000ED925, UINT32_C(0x004ED8FF));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00516034)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x00516020)));
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

void LIFT_CDECL sfera_sub_004ED930(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_054_KERNEL32_dll_UnmapViewOfFile, UINT32_C(0x004ED946), UINT32_C(0x004ED94C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000ED976, UINT32_C(0x004ED950));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0x00000008))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00516034)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x00516020)));
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
    LIFT_IMPORT_CALL(sfera_import_346_MSVCR100_dll_strncpy, UINT32_C(0x004ED98D), UINT32_C(0x004ED993));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_PUSH7(UINT32_C(0x00000000), UINT32_C(0x08000000), UINT32_C(0x00000003), UINT32_C(0x00000000), UINT32_C(0x00000001), UINT32_C(0x80000000), cpu->edi);
    LIFT_STORE8(cpu->esi + UINT32_C(0x00000027), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(sfera_import_067_KERNEL32_dll_CreateFileA, UINT32_C(0x004ED9AD), UINT32_C(0x004ED9B3));
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
    LIFT_IMPORT_CALL(sfera_import_065_KERNEL32_dll_GetFileSize, UINT32_C(0x004ED9CE), UINT32_C(0x004ED9D4));
    LIFT_PUSH6(UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000002), UINT32_C(0x00000000), cpu->edi);
    LIFT_STORE32(cpu->esi + UINT32_C(0x00000004), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_076_KERNEL32_dll_CreateFileMappingA, UINT32_C(0x004ED9E2), UINT32_C(0x004ED9E8));
    cpu->ebx = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->ebx, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JZ(label_000EDA11, UINT32_C(0x004ED9EF));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    LIFT_LOAD32(cpu->edi, lift_image_va(UINT32_C(0x004FD088)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004ED9F8)), lift_image_va(UINT32_C(0x004ED9F6)))) { return; }
    LIFT_ENTER(UINT32_C(0x004ED9F8));
    LIFT_PUSH5(UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000000), UINT32_C(0x00000004), cpu->ebx);
    LIFT_IMPORT_CALL(sfera_import_075_KERNEL32_dll_MapViewOfFile, UINT32_C(0x004EDA01), UINT32_C(0x004EDA07));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_STORE32(cpu->esi, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), lift_image_va(UINT32_C(0x004EDA0C)), lift_image_va(UINT32_C(0x004EDA0A)))) { return; }
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

void LIFT_CDECL sfera_sub_004EDA30(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EDA50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDA50));
    LIFT_IMPORT_RETURN(sfera_import_184_dbghelp_dll_MiniDumpWriteDump, UINT32_C(0x004EDA50));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EDA60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EDA60));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x00000008));
    cpu->ebx = (uint32_t)(((uint32_t)(((uint32_t)(cpu->edi) * 8u))));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_350_MSVCR100_dll_malloc, UINT32_C(0x004EDA76), UINT32_C(0x004EDA7C));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EDAAB, UINT32_C(0x004EDA85));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x004FFD04)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x005160E4)));
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

void LIFT_CDECL sfera_sub_004EDB10(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_PUSH2(lift_image_va(UINT32_C(0x004FFD1C)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x005160E4)));
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
    LIFT_IMPORT_CALL(sfera_import_355_MSVCR100_dll_realloc, UINT32_C(0x004EDBA2), UINT32_C(0x004EDBA8));
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
    LIFT_PUSH2(lift_image_va(UINT32_C(0x005160F8)), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x005160E4)));
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

void LIFT_CDECL sfera_sub_004EDC70(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EDCE0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_346_MSVCR100_dll_strncpy, UINT32_C(0x004EDD26), UINT32_C(0x004EDD2C));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE8(cpu->edi + cpu->esi + UINT32_C(0xFFFFFFFF), UINT32_C(0x00000000));
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EDD35, UINT32_C(0x004EDD35));
    LIFT_EPILOGUE2(12u, cpu->edi, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EDD40(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_350_MSVCR100_dll_malloc, UINT32_C(0x004EDD54), UINT32_C(0x004EDD5A));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EDD89, UINT32_C(0x004EDD63));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00516154)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x0051613C)));
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

void LIFT_CDECL sfera_sub_004EDDF0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EDE50(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EDEF0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_355_MSVCR100_dll_realloc, UINT32_C(0x004EDF4A), UINT32_C(0x004EDF50));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EDF86, UINT32_C(0x004EDF59));
    LIFT_LOAD32(cpu->ecx, cpu->esi + UINT32_C(0x00000004));
    LIFT_IMUL32(cpu->ecx, UINT32_C(0x0000001A));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00516178)), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x0051613C)));
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

void LIFT_CDECL sfera_sub_004EE000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE000));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000534));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAEC), cpu->edx);
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAF0), cpu->ebx);
    LIFT_IMPORT_CALL(sfera_import_056_KERNEL32_dll_GetCurrentProcess, UINT32_C(0x004EE027), UINT32_C(0x004EE02D));
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
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x004FD67C)));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB08), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB2C), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB20), cpu->eax);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD680)));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB00), cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->ebx + UINT32_C(0x000000B4));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFB18), cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFB00))));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFAF8), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(sfera_import_057_KERNEL32_dll_GetCurrentThread, UINT32_C(0x004EE0A9), UINT32_C(0x004EE0AF));
    LIFT_PUSH3(cpu->eax, cpu->edi, UINT32_C(0x0000014C));
    LIFT_IMPORT_CALL(sfera_import_180_dbghelp_dll_StackWalk, UINT32_C(0x004EE0B6), UINT32_C(0x004EE0BC));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE2A4, UINT32_C(0x004EE0C4));
    LIFT_ADD(cpu->esi, UINT32_C(0x00000068), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_BLOCK(label_000EE0D0, UINT32_C(0x004EE0D0));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFB18)))), cpu->eax, 32u);
    LIFT_JZ(label_000EE2A4, UINT32_C(0x004EE0DE));
    LIFT_STORE32(cpu->esi + UINT32_C(0xFFFFFFB8), cpu->eax);
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x00509B68)));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->esi + UINT32_C(0xFFFFFF98))));
    LIFT_STORE32(cpu->ebx, cpu->edx);
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x00509B6C)));
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
    LIFT_IMPORT_CALL(sfera_import_181_dbghelp_dll_SymGetLineFromAddr, UINT32_C(0x004EE13B), UINT32_C(0x004EE141));
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
    LIFT_IMPORT_CALL(sfera_import_346_MSVCR100_dll_strncpy, UINT32_C(0x004EE1A0), UINT32_C(0x004EE1A6));
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
    LIFT_IMPORT_CALL(sfera_import_177_dbghelp_dll_SymFromAddr, UINT32_C(0x004EE1EC), UINT32_C(0x004EE1F2));
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
    LIFT_IMPORT_CALL(sfera_import_346_MSVCR100_dll_strncpy, UINT32_C(0x004EE233), UINT32_C(0x004EE239));
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
    LIFT_LOAD32(cpu->edx, lift_image_va(UINT32_C(0x004FD67C)));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD680)));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFAF0));
    LIFT_PUSH5(UINT32_C(0x00000000), cpu->edx, cpu->eax, UINT32_C(0x00000000), cpu->ecx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFB00))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_IMPORT_CALL(sfera_import_057_KERNEL32_dll_GetCurrentThread, UINT32_C(0x004EE289), UINT32_C(0x004EE28F));
    LIFT_PUSH3(cpu->eax, cpu->edi, UINT32_C(0x0000014C));
    LIFT_IMPORT_CALL(sfera_import_180_dbghelp_dll_StackWalk, UINT32_C(0x004EE296), UINT32_C(0x004EE29C));
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

void LIFT_CDECL sfera_sub_004EE2C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE2C0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x000002EC));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->eax);
    LIFT_PUSH2(cpu->esi, cpu->edi);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFD14), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFD18), cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000004)));
    LIFT_IMPORT_CALL(sfera_import_182_dbghelp_dll_SymSetOptions, UINT32_C(0x004EE2E3), UINT32_C(0x004EE2E9));
    LIFT_PUSH2(UINT32_C(0x00000001), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(sfera_import_056_KERNEL32_dll_GetCurrentProcess, UINT32_C(0x004EE2ED), UINT32_C(0x004EE2F3));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_183_dbghelp_dll_SymInitialize, UINT32_C(0x004EE2F4), UINT32_C(0x004EE2FA));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_000EE315, UINT32_C(0x004EE300));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->esi, cpu->eax + UINT32_C(0x00000004));
    cpu->ecx = (uint32_t)(UINT32_C(0x000000B3));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFD28))));
    lift_movs32(cpu, 1u);
    goto label_000EE366;
    LIFT_BLOCK(label_000EE315, UINT32_C(0x004EE315));
    LIFT_CALL(sfera_sub_004EE31A, lift_image_va(UINT32_C(0x004EE31A)));
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

void LIFT_CDECL sfera_sub_004EE31A(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EE390(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_LOAD32(cpu->ebx, lift_image_va(UINT32_C(0x004FD458)));
    LIFT_ADD(cpu->edi, UINT32_C(0x00000004), 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0x0000000C), UINT32_C(0x00000014));
    cpu->edi = (uint32_t)(cpu->edi);
    LIFT_BLOCK(label_000EE3E0, UINT32_C(0x004EE3E0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000004), cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EE3E6)), lift_image_va(UINT32_C(0x004EE3E4)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE3E6));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->edi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EE416, UINT32_C(0x004EE3EF));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x005161D4)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), lift_image_va(UINT32_C(0x005161BC)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), UINT32_C(0x0000001B));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), UINT32_C(0x00000002));
    LIFT_CALL_ENTER(sfera_sub_004EC2E0, UINT32_C(0x004EE413));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EE416, UINT32_C(0x004EE416));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->edi + UINT32_C(0x0000000C), cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EE41C)), lift_image_va(UINT32_C(0x004EE41A)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE41C));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_STORE32(cpu->edi + UINT32_C(0x00000008), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EE44D, UINT32_C(0x004EE426));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x005161D4)), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), lift_image_va(UINT32_C(0x005161BC)));
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

void LIFT_CDECL sfera_sub_004EE470(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE470));
    lift_push32(cpu, (uint32_t)(cpu->ebx));
    LIFT_LOAD32(cpu->ebx, lift_image_va(UINT32_C(0x004FD45C)));
    LIFT_PUSH2(cpu->esi, cpu->edi);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x0000000C))));
    cpu->edi = (uint32_t)(UINT32_C(0x00000014));
    LIFT_BLOCK(label_000EE481, UINT32_C(0x004EE481));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0xFFFFFFF8));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE48E, UINT32_C(0x004EE488));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EE48B)), lift_image_va(UINT32_C(0x004EE489)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE48B));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000EE48E, UINT32_C(0x004EE48E));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EE49A, UINT32_C(0x004EE494));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), lift_image_va(UINT32_C(0x004EE497)), lift_image_va(UINT32_C(0x004EE495)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE497));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_BLOCK(label_000EE49A, UINT32_C(0x004EE49A));
    LIFT_ADD(cpu->esi, UINT32_C(0x00000020), 0u, 32u, cpu->esi = (uint32_t)(result););
    LIFT_DEC(cpu->edi, 32u, cpu->edi = (uint32_t)(result););
    LIFT_JNZ(label_000EE481, UINT32_C(0x004EE4A0));
    LIFT_EPILOGUE3(0u, cpu->edi, cpu->esi, cpu->ebx);
}

void LIFT_CDECL sfera_sub_004EE4B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE4B0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000280));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EE4C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE4C0));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx + UINT32_C(0x00000280)))), UINT32_C(0x00000014), 32u);
    cpu->eax = (cpu->eax & UINT32_C(0xFFFFFF00)) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & UINT32_C(0xFF));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EE4D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE4D0));
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000280)))), UINT32_C(0x00000000), 32u);
    LIFT_JG(label_000EE508, UINT32_C(0x004EE4E2));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x005161F0)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x005161BC)));
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

void LIFT_CDECL sfera_sub_004EE540(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_355_MSVCR100_dll_realloc, UINT32_C(0x004EE572), UINT32_C(0x004EE578));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_STORE32(cpu->edi, cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EE5AA, UINT32_C(0x004EE581));
    LIFT_LOAD32(cpu->ecx, cpu->ebx);
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x0051621C)), cpu->edx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), lift_image_va(UINT32_C(0x005161BC)));
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

void LIFT_CDECL sfera_sub_004EE5D0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_IMPORT_CALL(sfera_import_345_MSVCR100_dll__time64, UINT32_C(0x004EE672), UINT32_C(0x004EE678));
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

void LIFT_CDECL sfera_sub_004EE690(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_PUSH2(lift_image_va(UINT32_C(0x00516254)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), lift_image_va(UINT32_C(0x005161BC)));
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
    LIFT_IMPORT_CALL(sfera_import_345_MSVCR100_dll__time64, UINT32_C(0x004EE6F5), UINT32_C(0x004EE6FB));
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

void LIFT_CDECL sfera_sub_004EE7D0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EE7F2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE7F2));
    LIFT_IMPORT_RETURN(sfera_import_203_Sound_dll__Play_CSound__UAEHH_Z, UINT32_C(0x004EE7F2));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE7F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE7F8));
    LIFT_IMPORT_RETURN(sfera_import_196_Sound_dll__Stop_CSound__UAEXXZ, UINT32_C(0x004EE7F8));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE7FE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE7FE));
    LIFT_IMPORT_RETURN(sfera_import_195_Sound_dll__Rewind_CSound__UAEHXZ, UINT32_C(0x004EE7FE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE804(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE804));
    LIFT_IMPORT_RETURN(sfera_import_315_MSVCR100_dll_memcpy, UINT32_C(0x004EE804));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE80A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE80A));
    LIFT_IMPORT_RETURN(sfera_import_316_MSVCR100_dll_memset, UINT32_C(0x004EE80A));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE810(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE810));
    LIFT_CMP(cpu->ecx, lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x00525490))))), 32u);
    LIFT_JNZ(label_000EE81A, UINT32_C(0x004EE818));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EE81A, UINT32_C(0x004EE81A));
    LIFT_ENTER(UINT32_C(0x004EF152));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000328));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90540)), cpu->eax);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9053C)), cpu->ecx);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90538)), cpu->edx);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90534)), cpu->ebx);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90530)), cpu->esi);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9052C)), cpu->edi);
    LIFT_STORE16(lift_image_va(UINT32_C(0x04F90558)), UINT32_C(0x23));
    LIFT_STORE16(lift_image_va(UINT32_C(0x04F9054C)), UINT32_C(0x1B));
    LIFT_STORE16(lift_image_va(UINT32_C(0x04F90528)), UINT32_C(0x23));
    LIFT_STORE16(lift_image_va(UINT32_C(0x04F90524)), UINT32_C(0x23));
    LIFT_STORE16(lift_image_va(UINT32_C(0x04F90520)), UINT32_C(0x3B));
    LIFT_STORE16(lift_image_va(UINT32_C(0x04F9051C)), UINT32_C(0));
    lift_push32(cpu, cpu->eflags);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90550)), lift_pop32(cpu));
    LIFT_LOAD32(cpu->eax, cpu->ebp);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90544)), cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90548)), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000008))));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90554)), cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFCE0));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90490)), UINT32_C(0x00010001));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F90548)));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90444)), cpu->eax);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90438)), UINT32_C(0xC0000409));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9043C)), UINT32_C(0x00000001));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFCD8), cpu->eax);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525494)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFCDC), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_030_KERNEL32_dll_IsDebuggerPresent, UINT32_C(0x004EF20D), UINT32_C(0x004EF213));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90488)), cpu->eax);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    LIFT_CALL_ENTER(sfera_sub_004EF5AE, UINT32_C(0x004EF21F));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000000)));
    LIFT_IMPORT_CALL(sfera_import_042_KERNEL32_dll_SetUnhandledExceptionFilter, UINT32_C(0x004EF222), UINT32_C(0x004EF228));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x00516288))));
    LIFT_IMPORT_CALL(sfera_import_032_KERNEL32_dll_UnhandledExceptionFilter, UINT32_C(0x004EF22D), UINT32_C(0x004EF233));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90488))))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000EF244, UINT32_C(0x004EF23C));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    LIFT_CALL_ENTER(sfera_sub_004EF5AE, UINT32_C(0x004EF243));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EF244, UINT32_C(0x004EF244));
    lift_push32(cpu, (uint32_t)(UINT32_C(0xC0000409)));
    LIFT_IMPORT_CALL(sfera_import_056_KERNEL32_dll_GetCurrentProcess, UINT32_C(0x004EF249), UINT32_C(0x004EF24F));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_080_KERNEL32_dll_TerminateProcess, UINT32_C(0x004EF250), UINT32_C(0x004EF256));
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EE81F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE81F));
    LIFT_PUSH2(UINT32_C(0x00000014), lift_image_va(UINT32_C(0x0051CFD8)));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EE82B));
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F9078C)))))));
    LIFT_LOAD32(cpu->esi, lift_image_va(UINT32_C(0x004FD060)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EE839)), lift_image_va(UINT32_C(0x004EE837)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE839));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->eax);
    LIFT_CMP(cpu->eax, UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EE84D, UINT32_C(0x004EE841));
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008))))));
    LIFT_IMPORT_CALL(sfera_import_229_MSVCR100_dll__onexit, UINT32_C(0x004EE844), UINT32_C(0x004EE84A));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    goto label_000EE8B1;
    LIFT_BLOCK(label_000EE84D, UINT32_C(0x004EE84D));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EF264, UINT32_C(0x004EE854));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F9078C)))))));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EE861)), lift_image_va(UINT32_C(0x004EE85F)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE861));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->eax);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90788)))))));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EE86C)), lift_image_va(UINT32_C(0x004EE86A)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE86C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_PUSH2(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))));
    LIFT_LOAD32(cpu->esi, lift_image_va(UINT32_C(0x004FD064)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EE882)), lift_image_va(UINT32_C(0x004EE880)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE882));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EF25E, UINT32_C(0x004EE888));
    LIFT_SP_ADD(UINT32_C(0x0000000C));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), cpu->eax);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))))));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EE893)), lift_image_va(UINT32_C(0x004EE891)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE893));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9078C)), cpu->eax);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))))));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), lift_image_va(UINT32_C(0x004EE89D)), lift_image_va(UINT32_C(0x004EE89B)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EE89D));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90788)), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EE8B7, UINT32_C(0x004EE8AE));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFDC));
    LIFT_BLOCK(label_000EE8B1, UINT32_C(0x004EE8B1));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EE8B6));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EE8B7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE8B7));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EF258, UINT32_C(0x004EE8BE));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004EE8C0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EE8D7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE8D7));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOGIC_FLAGS(lift_load8(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), UINT32_C(0x00000002), &, 8u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(cpu->ecx);
    LIFT_JZ(label_000EE90A, UINT32_C(0x004EE8E5));
    LIFT_PUSH2(cpu->esi, lift_image_va(UINT32_C(0x004EF5B4)));
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

void LIFT_CDECL sfera_sub_004EE924(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE924));
    LIFT_IMPORT_RETURN(sfera_import_321_MSVCR100_dll__what_exception_std__UBEPBDXZ, UINT32_C(0x004EE924));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE92A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE92A));
    LIFT_IMPORT_RETURN(sfera_import_324_MSVCR100_dll__CxxThrowException, UINT32_C(0x004EE92A));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE930));
    LIFT_IMPORT_RETURN(sfera_import_325_MSVCR100_dll___0exception_std__QAE_ABV01__Z, UINT32_C(0x004EE930));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE940));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F9077C))))), UINT32_C(0x00000000), 32u);
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

void LIFT_CDECL sfera_sub_004EE976(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EE9EC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9EC));
    LIFT_IMPORT_RETURN(sfera_import_337_MSVCR100_dll__CIsqrt, UINT32_C(0x004EE9EC));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE9F2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9F2));
    LIFT_IMPORT_RETURN(sfera_import_338_MSVCR100_dll__CIcos, UINT32_C(0x004EE9F2));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE9F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9F8));
    LIFT_IMPORT_RETURN(sfera_import_339_MSVCR100_dll__CIsin, UINT32_C(0x004EE9F8));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EE9FE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EE9FE));
    LIFT_IMPORT_RETURN(sfera_import_340_MSVCR100_dll__CIpow, UINT32_C(0x004EE9FE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EEA10(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EEA40(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EEAF0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EEB1C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB1C));
    LIFT_IMPORT_RETURN(sfera_import_351_MSVCR100_dll_free, UINT32_C(0x004EEB1C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EEB22(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB22));
    LIFT_IMPORT_RETURN(sfera_import_309_MSVCR100_dll__purecall, UINT32_C(0x004EEB22));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EEB28(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB28));
    LIFT_PUSH2(UINT32_C(0x00000014), lift_image_va(UINT32_C(0x0051CFF8)));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EEB34));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), UINT32_C(0x00000000), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_BLOCK(label_000EEB38, UINT32_C(0x004EEB38));
    LIFT_DEC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010))), (uint32_t)(result)););
    LIFT_JS(label_000EEB77, UINT32_C(0x004EEB3D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_SUB(cpu->ecx, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0x00000008), cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014))))), lift_image_va(UINT32_C(0x004EEB49)), lift_image_va(UINT32_C(0x004EEB46)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EEB49));
    goto label_000EEB38;
    LIFT_BLOCK(label_000EEB77, UINT32_C(0x004EEB77));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EEB83));
    LIFT_RET(16u);
}

void LIFT_CDECL sfera_sub_004EEB4B(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_CALL(sfera_sub_004EF2DA, lift_image_va(UINT32_C(0x004EEB74)));
    LIFT_TAIL(sfera_sub_004EEB74);
}

void LIFT_CDECL sfera_sub_004EEB74(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB74));
    LIFT_LOAD32(cpu->esp, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EEB83));
    LIFT_RET(16u);
}

void LIFT_CDECL sfera_sub_004EEB86(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEB86));
    LIFT_PUSH2(UINT32_C(0x0000000C), lift_image_va(UINT32_C(0x0051D018)));
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
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014))))), lift_image_va(UINT32_C(0x004EEBB4)), lift_image_va(UINT32_C(0x004EEBB1)))) { return; }
    LIFT_ENTER(UINT32_C(0x004EEBB4));
    goto label_000EEBA6;
    LIFT_BLOCK(label_000EEBB6, UINT32_C(0x004EEBB6));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), UINT32_C(0x00000001));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_CALL_ENTER(sfera_sub_004EEBD1, UINT32_C(0x004EEBC9));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EEBCE));
    LIFT_RET(16u);
}

void LIFT_CDECL sfera_sub_004EEBD1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEBD1));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000EEBE8, UINT32_C(0x004EEBD7));
    LIFT_PUSH4(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))));
    LIFT_CALL(sfera_sub_004EEB28, lift_image_va(UINT32_C(0x004EEBE8)));
    LIFT_BLOCK(label_000EEBE8, UINT32_C(0x004EEBE8));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EEBE9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEBE9));
    LIFT_PUSH2(UINT32_C(0x00000010), lift_image_va(UINT32_C(0x0051D038)));
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
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014))))), lift_image_va(UINT32_C(0x004EEC10)), lift_image_va(UINT32_C(0x004EEC0D)))) { return; }
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

void LIFT_CDECL sfera_sub_004EEC36(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEC36));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0)))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000EEC4D, UINT32_C(0x004EEC3C));
    LIFT_PUSH4(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000018)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))));
    LIFT_CALL(sfera_sub_004EEB28, lift_image_va(UINT32_C(0x004EEC4D)));
    LIFT_BLOCK(label_000EEC4D, UINT32_C(0x004EEC4D));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EEC4E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEC4E));
    LIFT_IMPORT_RETURN(sfera_import_297_MSVCR100_dll__CIatan2, UINT32_C(0x004EEC4E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EEC54(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEC54));
    LIFT_IMPORT_RETURN(sfera_import_296_MSVCR100_dll__CIexp, UINT32_C(0x004EEC54));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EEC60(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EED20(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EED54(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED54));
    LIFT_IMPORT_RETURN(sfera_import_276_MSVCR100_dll__CItan, UINT32_C(0x004EED54));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EED5A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED5A));
    LIFT_IMPORT_RETURN(sfera_import_262_MSVCR100_dll__CIacos, UINT32_C(0x004EED5A));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EED60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED60));
    LIFT_IMPORT_RETURN(sfera_import_261_MSVCR100_dll__CIatan, UINT32_C(0x004EED60));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EED66(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED66));
    LIFT_IMPORT_RETURN(sfera_import_260_MSVCR100_dll_floor, UINT32_C(0x004EED66));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EED6C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EED6C));
    LIFT_IMPORT_RETURN(sfera_import_255_MSVCR100_dll__CIasin, UINT32_C(0x004EED6C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EED80(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EEDF0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EEE10(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EEE30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE30));
    LIFT_IMPORT_RETURN(sfera_import_271_MSVCR100_dll___1bad_cast_std__UAE_XZ, UINT32_C(0x004EEE30));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EEE36(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE36));
    LIFT_IMPORT_RETURN(sfera_import_270_MSVCR100_dll___0bad_cast_std__QAE_ABV01__Z, UINT32_C(0x004EEE36));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EEE3C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE3C));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH6(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000014)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000010)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C)))), lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0x00000008)))), lift_image_va(UINT32_C(0x004EE810)), lift_image_va(UINT32_C(0x00525490)));
    LIFT_CALL_ENTER(sfera_sub_004EF2E0, UINT32_C(0x004EEE5C));
    LIFT_SP_ADD(UINT32_C(0x00000018));
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EEE61(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EEE61));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x004EF362))));
    LIFT_CALL_ENTER(sfera_sub_004EE8C0, UINT32_C(0x004EEE6B));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F90760)));
    LIFT_STORE32(cpu->esp, lift_image_va(UINT32_C(0x04F9042C)));
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F9075C)))))));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9042C)), cpu->eax);
    LIFT_PUSH3(lift_image_va(UINT32_C(0x04F9041C)), lift_image_va(UINT32_C(0x04F90420)), lift_image_va(UINT32_C(0x04F90418)));
    LIFT_IMPORT_CALL(sfera_import_225_MSVCR100_dll___getmainargs, UINT32_C(0x004EEE91), UINT32_C(0x004EEE97));
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90428)), cpu->eax);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNS(label_000EEEAB, UINT32_C(0x004EEEA3));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EF336, UINT32_C(0x004EEEAA));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EEEAB, UINT32_C(0x004EEEAB));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF038(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF038));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFD8), cpu->ecx);
    LIFT_PUSH2(cpu->eax, cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004EF388, UINT32_C(0x004EF049));
    LIFT_EPILOGUE2(0u, cpu->ecx, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004EF04C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF04C));
    LIFT_LOAD32(cpu->esp, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90430)), cpu->eax);
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90424))))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EF068, UINT32_C(0x004EF061));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    sfera_import_223_MSVCR100_dll__exit(cpu, lift_image_va(UINT32_C(0x004EF062)));
    cpu->eip = lift_image_va(UINT32_C(0x004EF068));
    LIFT_BLOCK(label_000EF068, UINT32_C(0x004EF068));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90434))))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EF076, UINT32_C(0x004EF070));
    sfera_import_224_MSVCR100_dll__cexit(cpu, lift_image_va(UINT32_C(0x004EF070)));
    cpu->eip = lift_image_va(UINT32_C(0x004EF076));
    LIFT_BLOCK(label_000EF076, UINT32_C(0x004EF076));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F90430)));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EF087));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF088(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF088));
    cpu->eax = (uint32_t)(UINT32_C(0x00005A4D));
    LIFT_CMP(lift_load16(((uint32_t)(lift_image_va(UINT32_C(0x00400000))))), (cpu->eax & UINT32_C(0xFFFF)), 16u);
    LIFT_JZ_GOTO(label_000EF09A);
    LIFT_BLOCK(label_000EF096, UINT32_C(0x004EF096));
    LIFT_ZERO(cpu->eax, 32u);
    goto label_000EF0CF;
    LIFT_BLOCK(label_000EF09A, UINT32_C(0x004EF09A));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x0040003C)));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x00400000))))), UINT32_C(0x00004550), 32u);
    LIFT_JNZ(label_000EF096, UINT32_C(0x004EF0AB));
    cpu->ecx = (uint32_t)(UINT32_C(0x0000010B));
    LIFT_CMP(lift_load16(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x00400018))))), (cpu->ecx & UINT32_C(0xFFFF)), 16u);
    LIFT_JNZ(label_000EF096, UINT32_C(0x004EF0B9));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x00400074))))), UINT32_C(0x0000000E), 32u);
    LIFT_JBE(label_000EF096, UINT32_C(0x004EF0C2));
    LIFT_ZERO(cpu->ecx, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax + lift_image_va(UINT32_C(0x004000E8))))), cpu->ecx, 32u);
    cpu->ecx = (cpu->ecx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & UINT32_C(0xFF));
    cpu->eax = (uint32_t)(cpu->ecx);
    LIFT_BLOCK(label_000EF0CF, UINT32_C(0x004EF0CF));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000002)));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90424)), cpu->eax);
    LIFT_IMPORT_CALL(sfera_import_237_MSVCR100_dll___set_app_type, UINT32_C(0x004EF0D6), UINT32_C(0x004EF0DC));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    lift_push32(cpu, (uint32_t)(UINT32_C(0xFFFFFFFF)));
    LIFT_IMPORT_CALL(sfera_import_038_KERNEL32_dll_EncodePointer, UINT32_C(0x004EF0DF), UINT32_C(0x004EF0E5));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x04F90768)));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90788)), cpu->eax);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9078C)), cpu->eax);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD290)));
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD28C)));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x04F90764)));
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_CALL_ENTER(sfera_sub_004EF33C, UINT32_C(0x004EF10E));
    LIFT_CALL_ENTER(sfera_sub_004EF510, UINT32_C(0x004EF113));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x005254BC))))), UINT32_C(0x00000000), 32u);
    LIFT_JNZ(label_000EF128, UINT32_C(0x004EF11C));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x004EF510))));
    LIFT_IMPORT_CALL(sfera_import_234_MSVCR100_dll___setusermatherr, UINT32_C(0x004EF121), UINT32_C(0x004EF127));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EF128, UINT32_C(0x004EF128));
    LIFT_CALL_ENTER(sfera_sub_004EF4E8, UINT32_C(0x004EF12D));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x005254B8))))), UINT32_C(0xFFFFFFFF), 32u);
    LIFT_JNZ(label_000EF13F, UINT32_C(0x004EF136));
    lift_push32(cpu, (uint32_t)(UINT32_C(0xFFFFFFFF)));
    LIFT_IMPORT_CALL(sfera_import_233_MSVCR100_dll__configthreadlocale, UINT32_C(0x004EF138), UINT32_C(0x004EF13E));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EF13F, UINT32_C(0x004EF13F));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF142(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF142;
    LIFT_BLOCK(label_000EEEAF, UINT32_C(0x004EEEAF));
    LIFT_PUSH2(UINT32_C(0x0000005C), lift_image_va(UINT32_C(0x0051D058)));
    LIFT_CALL_ENTER(sfera_sub_004EF270, UINT32_C(0x004EEEBB));
    LIFT_ZERO(cpu->ebx, 32u);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE4), cpu->ebx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF94))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_033_KERNEL32_dll_GetStartupInfoW, UINT32_C(0x004EEEC4), UINT32_C(0x004EEECA));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90780))))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EEEDD, UINT32_C(0x004EEED2));
    LIFT_PUSH4(cpu->ebx, cpu->ebx, UINT32_C(0x00000001), cpu->ebx);
    sfera_import_034_KERNEL32_dll_HeapSetInformation(cpu, lift_image_va(UINT32_C(0x004EEED7)));
    cpu->eip = lift_image_va(UINT32_C(0x004EEEDD));
    LIFT_BLOCK(label_000EEEDD, UINT32_C(0x004EEEDD));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), cpu->ebx);
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000018)))));
    LIFT_LOAD32(cpu->esi, cpu->eax + UINT32_C(0x00000004));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFDC), cpu->ebx);
    cpu->edi = (uint32_t)(lift_image_va(UINT32_C(0x04F90778)));
    LIFT_BLOCK(label_000EEEF1, UINT32_C(0x004EEEF1));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_IMPORT_CALL(sfera_import_035_KERNEL32_dll_InterlockedCompareExchange, UINT32_C(0x004EEEF4), UINT32_C(0x004EEEFA));
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
    LIFT_IMPORT_CALL(sfera_import_043_KERNEL32_dll_Sleep, UINT32_C(0x004EEF0F), UINT32_C(0x004EEF15));
    goto label_000EEEF1;
    LIFT_BLOCK(label_000EEF17, UINT32_C(0x004EEF17));
    LIFT_ZERO(cpu->esi, 32u);
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_BLOCK(label_000EEF1A, UINT32_C(0x004EEF1A));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F90774)));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EEF2D, UINT32_C(0x004EEF23));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000001F)));
    LIFT_CALL_ENTER(sfera_sub_004EF336, UINT32_C(0x004EEF2A));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    goto label_000EEF68;
    LIFT_BLOCK(label_000EEF2D, UINT32_C(0x004EEF2D));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F90774)));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JNZ(label_000EEF62, UINT32_C(0x004EEF36));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90774)), cpu->esi);
    LIFT_PUSH2(lift_image_va(UINT32_C(0x004FDC1C)), lift_image_va(UINT32_C(0x004FDC0C)));
    LIFT_CALL_ENTER(sfera_sub_004EF4E2, UINT32_C(0x004EEF4B));
    LIFT_POP2(cpu->ecx, cpu->ecx);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EEF68, UINT32_C(0x004EEF51));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    cpu->eax = (uint32_t)(UINT32_C(0x000000FF));
    goto label_000EF082;
    LIFT_BLOCK(label_000EEF62, UINT32_C(0x004EEF62));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90434)), cpu->esi);
    LIFT_BLOCK(label_000EEF68, UINT32_C(0x004EEF68));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F90774)));
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JNZ(label_000EEF8C, UINT32_C(0x004EEF71));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x004FDC08)), lift_image_va(UINT32_C(0x004FD6B4)));
    LIFT_CALL_ENTER(sfera_sub_004EF4DC, UINT32_C(0x004EEF80));
    LIFT_POP2(cpu->ecx, cpu->ecx);
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90774)), UINT32_C(0x00000002));
    LIFT_BLOCK(label_000EEF8C, UINT32_C(0x004EEF8C));
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC)))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EEF99, UINT32_C(0x004EEF91));
    LIFT_PUSH2(cpu->ebx, cpu->edi);
    sfera_import_036_KERNEL32_dll_InterlockedExchange(cpu, lift_image_va(UINT32_C(0x004EEF93)));
    cpu->eip = lift_image_va(UINT32_C(0x004EEF99));
    LIFT_BLOCK(label_000EEF99, UINT32_C(0x004EEF99));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90784))))), cpu->ebx, 32u);
    LIFT_JZ(label_000EEFBA, UINT32_C(0x004EEFA1));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x04F90784))));
    LIFT_CALL_ENTER(sfera_sub_004EF420, UINT32_C(0x004EEFAB));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EEFBA, UINT32_C(0x004EEFB0));
    LIFT_PUSH3(cpu->ebx, UINT32_C(0x00000002), cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90784)))))), lift_image_va(UINT32_C(0x004EEFBA)), lift_image_va(UINT32_C(0x004EEFB4)))) { return; }
    LIFT_BLOCK(label_000EEFBA, UINT32_C(0x004EEFBA));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD250)));
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
    LIFT_PUSH4(cpu->eax, cpu->esi, cpu->ebx, lift_image_va(UINT32_C(0x00400000)));
    LIFT_CALL_ENTER(sfera_sub_0047D770, UINT32_C(0x004EEFFF));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F90430)), cpu->eax);
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90424))))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EF068, UINT32_C(0x004EF00C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    sfera_import_288_MSVCR100_dll_exit(cpu, lift_image_va(UINT32_C(0x004EF00D)));
    cpu->eip = lift_image_va(UINT32_C(0x004EF013));
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
    LIFT_IMPORT_CALL(sfera_import_221_MSVCR100_dll__ismbblead, UINT32_C(0x004EF026), UINT32_C(0x004EF02C));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF035, UINT32_C(0x004EF031));
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE0), cpu->esi);
    LIFT_BLOCK(label_000EF035, UINT32_C(0x004EF035));
    LIFT_INC(cpu->esi, 32u, cpu->esi = (uint32_t)(result););
    goto label_000EEFC1;
    LIFT_BLOCK(label_000EF068, UINT32_C(0x004EF068));
    LIFT_CMP(lift_load32(((uint32_t)(lift_image_va(UINT32_C(0x04F90434))))), cpu->ebx, 32u);
    LIFT_JNZ(label_000EF076, UINT32_C(0x004EF070));
    sfera_import_224_MSVCR100_dll__cexit(cpu, lift_image_va(UINT32_C(0x004EF070)));
    cpu->eip = lift_image_va(UINT32_C(0x004EF076));
    LIFT_BLOCK(label_000EF076, UINT32_C(0x004EF076));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F90430)));
    LIFT_BLOCK(label_000EF082, UINT32_C(0x004EF082));
    LIFT_CALL_ENTER(sfera_sub_004EF2B5, UINT32_C(0x004EF087));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EF142, UINT32_C(0x004EF142));
    LIFT_CALL_ENTER(sfera_sub_004EF513, UINT32_C(0x004EF147));
    goto label_000EEEAF;
}

void LIFT_CDECL sfera_sub_004EF14C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF14C));
    LIFT_IMPORT_RETURN(sfera_import_251_MSVCR100_dll_calloc, UINT32_C(0x004EF14C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF258(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF258));
    LIFT_IMPORT_RETURN(sfera_import_249_MSVCR100_dll__unlock, UINT32_C(0x004EF258));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF25E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF25E));
    LIFT_IMPORT_RETURN(sfera_import_231_MSVCR100_dll___dllonexit, UINT32_C(0x004EF25E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF264(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF264));
    LIFT_IMPORT_RETURN(sfera_import_230_MSVCR100_dll__lock, UINT32_C(0x004EF264));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF270));
    LIFT_PUSH2(lift_image_va(UINT32_C(0x004EEE3C)), lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_LOAD32(cpu->eax, cpu->esp + UINT32_C(0x00000010));
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000010), cpu->ebp);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    LIFT_SP_SUB(cpu->eax);
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))), cpu->eax, ^, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC))), (uint32_t)(result)););
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), cpu->esp);
    lift_push32(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))))));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->eax);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF2B5(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2B5));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP5(cpu->ecx, cpu->edi, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    cpu->ebp = (uint32_t)(lift_pop32(cpu));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF2C9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2C9));
    lift_push32(cpu, (uint32_t)(UINT32_C(0x0000000A)));
    LIFT_IMPORT_CALL(sfera_import_031_KERNEL32_dll_IsProcessorFeaturePresent, UINT32_C(0x004EF2CB), UINT32_C(0x004EF2D1));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9077C)), cpu->eax);
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF2DA(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2DA));
    LIFT_IMPORT_RETURN(sfera_import_228_MSVCR100_dll__terminate__YAXXZ, UINT32_C(0x004EF2DA));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF2E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF2E0));
    LIFT_IMPORT_RETURN(sfera_import_227_MSVCR100_dll__except_handler4_common, UINT32_C(0x004EF2E0));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF2E6(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_CALL(sfera_sub_004EF2DA, lift_image_va(UINT32_C(0x004EF322)));
    LIFT_BLOCK(label_000EF322, UINT32_C(0x004EF322));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_EPILOGUE1(4u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EF328(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF328));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x004EF2E6))));
    LIFT_IMPORT_CALL(sfera_import_042_KERNEL32_dll_SetUnhandledExceptionFilter, UINT32_C(0x004EF32D), UINT32_C(0x004EF333));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF336(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF336));
    LIFT_IMPORT_RETURN(sfera_import_226_MSVCR100_dll__amsg_exit, UINT32_C(0x004EF336));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF33C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF33C));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517CA8)));
    cpu->esi = (uint32_t)(lift_image_va(UINT32_C(0x00517CA8)));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JAE_GOTO(label_000EF35F);
    LIFT_BLOCK(label_000EF350, UINT32_C(0x004EF350));
    LIFT_LOAD32(cpu->eax, cpu->edi);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF358, UINT32_C(0x004EF356));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004EF358)), lift_image_va(UINT32_C(0x004EF356)))) { return; }
    LIFT_BLOCK(label_000EF358, UINT32_C(0x004EF358));
    LIFT_ADD(cpu->edi, UINT32_C(0x00000004), 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_CMP(cpu->edi, cpu->esi, 32u);
    LIFT_JB_GOTO(label_000EF350);
    LIFT_BLOCK(label_000EF35F, UINT32_C(0x004EF35F));
    LIFT_EPILOGUE2(0u, cpu->edi, cpu->esi);
}

void LIFT_CDECL sfera_sub_004EF362(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF362));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517CB0)));
    cpu->esi = (uint32_t)(lift_image_va(UINT32_C(0x00517CB0)));
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->edi = (uint32_t)(cpu->eax);
    LIFT_CMP(cpu->eax, cpu->esi, 32u);
    LIFT_JAE_GOTO(label_000EF385);
    LIFT_BLOCK(label_000EF376, UINT32_C(0x004EF376));
    LIFT_LOAD32(cpu->eax, cpu->edi);
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF37E, UINT32_C(0x004EF37C));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004EF37E)), lift_image_va(UINT32_C(0x004EF37C)))) { return; }
    LIFT_BLOCK(label_000EF37E, UINT32_C(0x004EF37E));
    LIFT_ADD(cpu->edi, UINT32_C(0x00000004), 0u, 32u, cpu->edi = (uint32_t)(result););
    LIFT_CMP(cpu->edi, cpu->esi, 32u);
    LIFT_JB_GOTO(label_000EF376);
    LIFT_BLOCK(label_000EF385, UINT32_C(0x004EF385));
    LIFT_EPILOGUE2(0u, cpu->edi, cpu->esi);
}

void LIFT_CDECL sfera_sub_004EF388(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF388));
    LIFT_IMPORT_RETURN(sfera_import_222_MSVCR100_dll__XcptFilter, UINT32_C(0x004EF388));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF390(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF390));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(UINT32_C(0x00005A4D));
    LIFT_CMP(lift_load16(((uint32_t)(cpu->ecx))), (cpu->eax & UINT32_C(0xFFFF)), 16u);
    LIFT_JZ_GOTO(label_000EF3A6);
    LIFT_BLOCK(label_000EF3A2, UINT32_C(0x004EF3A2));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000EF3A6, UINT32_C(0x004EF3A6));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x0000003C));
    LIFT_ADD(cpu->eax, cpu->ecx, 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_CMP(lift_load32(((uint32_t)(cpu->eax))), UINT32_C(0x00004550), 32u);
    LIFT_JNZ(label_000EF3A2, UINT32_C(0x004EF3B3));
    LIFT_ZERO(cpu->edx, 32u);
    cpu->ecx = (uint32_t)(UINT32_C(0x0000010B));
    LIFT_CMP(lift_load16(((uint32_t)(cpu->eax + UINT32_C(0x00000018)))), (cpu->ecx & UINT32_C(0xFFFF)), 16u);
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & UINT32_C(0xFF));
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EF3D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF3D0));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ecx, cpu->eax + UINT32_C(0x0000003C));
    LIFT_ADD(cpu->ecx, cpu->eax, 0u, 32u, cpu->ecx = (uint32_t)(result););
    cpu->eax = (uint32_t)(lift_load16(((uint32_t)(cpu->ecx + UINT32_C(0x00000014)))));
    LIFT_PUSH2(cpu->ebx, cpu->esi);
    cpu->esi = (uint32_t)(lift_load16(((uint32_t)(cpu->ecx + UINT32_C(0x00000006)))));
    LIFT_ZERO(cpu->edx, 32u);
    lift_push32(cpu, (uint32_t)(cpu->edi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax + cpu->ecx + UINT32_C(0x00000018))));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000EF40D, UINT32_C(0x004EF3F2));
    LIFT_LOAD32(cpu->edi, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_BLOCK(label_000EF3F5, UINT32_C(0x004EF3F5));
    LIFT_LOAD32(cpu->ecx, cpu->eax + UINT32_C(0x0000000C));
    LIFT_CMP(cpu->edi, cpu->ecx, 32u);
    LIFT_JB(label_000EF405, UINT32_C(0x004EF3FC));
    LIFT_LOAD32(cpu->ebx, cpu->eax + UINT32_C(0x00000008));
    LIFT_ADD(cpu->ebx, cpu->ecx, 0u, 32u, cpu->ebx = (uint32_t)(result););
    LIFT_CMP(cpu->edi, cpu->ebx, 32u);
    LIFT_JB_GOTO(label_000EF40F);
    LIFT_BLOCK(label_000EF405, UINT32_C(0x004EF405));
    LIFT_INC(cpu->edx, 32u, cpu->edx = (uint32_t)(result););
    LIFT_ADD(cpu->eax, UINT32_C(0x00000028), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_CMP(cpu->edx, cpu->esi, 32u);
    LIFT_JB_GOTO(label_000EF3F5);
    LIFT_BLOCK(label_000EF40D, UINT32_C(0x004EF40D));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_BLOCK(label_000EF40F, UINT32_C(0x004EF40F));
    LIFT_EPILOGUE4(0u, cpu->edi, cpu->esi, cpu->ebx, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EF420(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF420));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_PUSH3(UINT32_C(0xFFFFFFFE), lift_image_va(UINT32_C(0x0051D078)), lift_image_va(UINT32_C(0x004EEE3C)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8)))), cpu->eax, ^, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))), (uint32_t)(result)););
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFE8), cpu->esp);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x00400000))));
    LIFT_CALL_ENTER(sfera_sub_004EF390, UINT32_C(0x004EF466));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF4C1, UINT32_C(0x004EF46D));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_SUB(cpu->eax, lift_image_va(UINT32_C(0x00400000)), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_PUSH2(cpu->eax, lift_image_va(UINT32_C(0x00400000)));
    LIFT_CALL_ENTER(sfera_sub_004EF3D0, UINT32_C(0x004EF480));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF4C1, UINT32_C(0x004EF487));
    LIFT_LOAD32(cpu->eax, cpu->eax + UINT32_C(0x00000024));
    cpu->eax = (uint32_t)(lift_shift_right(cpu, cpu->eax, (uint32_t)(UINT32_C(0x0000001F)), 32u));
    cpu->eax = (uint32_t)(~((uint64_t)(cpu->eax)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
    LIFT_BLOCK(label_000EF4C1, UINT32_C(0x004EF4C1));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFE));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP4(cpu->ecx, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EF4AB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4AB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_ZERO(cpu->edx, 32u);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->ecx))), UINT32_C(0xC0000005), 32u);
    cpu->edx = (cpu->edx & UINT32_C(0xFFFFFF00)) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & UINT32_C(0xFF));
    cpu->eax = (uint32_t)(cpu->edx);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF4BE(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EF4DC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4DC));
    LIFT_IMPORT_RETURN(sfera_import_219_MSVCR100_dll__initterm, UINT32_C(0x004EF4DC));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF4E2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF4E2));
    LIFT_IMPORT_RETURN(sfera_import_232_MSVCR100_dll__initterm_e, UINT32_C(0x004EF4E2));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF4E8(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_CALL(sfera_sub_004EF5BA, lift_image_va(UINT32_C(0x004EF50E)));
    LIFT_BLOCK(label_000EF50E, UINT32_C(0x004EF50E));
    LIFT_EPILOGUE1(0u, cpu->esi);
}

void LIFT_CDECL sfera_sub_004EF510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF510));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF513(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF513));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
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
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525494)), cpu->eax);
    goto label_000EF5AA;
    LIFT_BLOCK(label_000EF545, UINT32_C(0x004EF545));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_100_KERNEL32_dll_GetSystemTimeAsFileTime, UINT32_C(0x004EF54A), UINT32_C(0x004EF550));
    LIFT_LOAD32(cpu->esi, cpu->ebp + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->esi, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF8)))), ^, 32u, cpu->esi = (uint32_t)(result););
    LIFT_IMPORT_CALL(sfera_import_102_KERNEL32_dll_GetCurrentProcessId, UINT32_C(0x004EF556), UINT32_C(0x004EF55C));
    LIFT_LOGIC(cpu->esi, cpu->eax, ^, 32u, cpu->esi = (uint32_t)(result););
    LIFT_IMPORT_CALL(sfera_import_091_KERNEL32_dll_GetCurrentThreadId, UINT32_C(0x004EF55E), UINT32_C(0x004EF564));
    LIFT_LOGIC(cpu->esi, cpu->eax, ^, 32u, cpu->esi = (uint32_t)(result););
    LIFT_IMPORT_CALL(sfera_import_050_KERNEL32_dll_GetTickCount, UINT32_C(0x004EF566), UINT32_C(0x004EF56C));
    LIFT_LOGIC(cpu->esi, cpu->eax, ^, 32u, cpu->esi = (uint32_t)(result););
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_083_KERNEL32_dll_QueryPerformanceCounter, UINT32_C(0x004EF572), UINT32_C(0x004EF578));
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
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525490)), cpu->esi);
    cpu->esi = (uint32_t)(~((uint64_t)(cpu->esi)));
    LIFT_STORE32(lift_image_va(UINT32_C(0x00525494)), cpu->esi);
    cpu->esi = (uint32_t)(lift_pop32(cpu));
    LIFT_BLOCK(label_000EF5AA, UINT32_C(0x004EF5AA));
    LIFT_POP2(cpu->edi, cpu->ebx);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF5AE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5AE));
    LIFT_IMPORT_RETURN(sfera_import_238_MSVCR100_dll__crt_debugger_hook, UINT32_C(0x004EF5AE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF5B4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5B4));
    LIFT_IMPORT_RETURN(sfera_import_239_MSVCR100_dll___type_info_dtor_internal_method_type_info__QAEXXZ, UINT32_C(0x004EF5B4));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF5BA(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5BA));
    LIFT_IMPORT_RETURN(sfera_import_240_MSVCR100_dll__invoke_watson, UINT32_C(0x004EF5BA));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF5C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5C0));
    LIFT_IMPORT_RETURN(sfera_import_247_MSVCR100_dll__controlfp_s, UINT32_C(0x004EF5C0));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF5C6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5C6));
    LIFT_LOAD32(cpu->ecx, cpu->ecx + UINT32_C(0x00000004));
    LIFT_IMPORT_CALL(sfera_import_398_MSVCP100_dll___Decref_facet_locale_std__QAEPAV123_XZ, UINT32_C(0x004EF5C9), UINT32_C(0x004EF5CF));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF5DB, UINT32_C(0x004EF5D3));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    cpu->ecx = (uint32_t)(cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(((uint32_t)(cpu->edx)))), lift_image_va(UINT32_C(0x004EF5DB)), lift_image_va(UINT32_C(0x004EF5D9)))) { return; }
    LIFT_BLOCK(label_000EF5DB, UINT32_C(0x004EF5DB));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF5DC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF5DC));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000008)));
    LIFT_CALL_ENTER(sfera_sub_004EBEA0, UINT32_C(0x004EF5E8));
    cpu->ecx = (uint32_t)(lift_pop32(cpu));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF5FD, UINT32_C(0x004EF5ED));
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x04F9076C)));
    LIFT_STORE32(cpu->eax, cpu->ecx);
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->eax + UINT32_C(0x00000004), cpu->ecx);
    goto label_000EF5FF;
    LIFT_BLOCK(label_000EF5FD, UINT32_C(0x004EF5FD));
    LIFT_ZERO(cpu->eax, 32u);
    LIFT_BLOCK(label_000EF5FF, UINT32_C(0x004EF5FF));
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F9076C)), cpu->eax);
    LIFT_EPILOGUE1(0u, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EF656(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF656));
    LIFT_IMPORT_RETURN(sfera_import_385_MSVCP100_dll__showmanyc___basic_streambuf_DU__char_traits_D_std___std__MAE_JXZ, UINT32_C(0x004EF656));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF65C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF65C));
    LIFT_IMPORT_RETURN(sfera_import_384_MSVCP100_dll__xsgetn___basic_streambuf_DU__char_traits_D_std___std__MAE_JPAD_J_Z, UINT32_C(0x004EF65C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF662(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF662));
    LIFT_IMPORT_RETURN(sfera_import_383_MSVCP100_dll__xsputn___basic_streambuf_DU__char_traits_D_std___std__MAE_JPBD_J_Z, UINT32_C(0x004EF662));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF668(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF668));
    LIFT_IMPORT_RETURN(sfera_import_406_MSVCP100_dll___Lock___basic_streambuf_DU__char_traits_D_std___std__UAEXXZ, UINT32_C(0x004EF668));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF66E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF66E));
    LIFT_IMPORT_RETURN(sfera_import_405_MSVCP100_dll___Unlock___basic_streambuf_DU__char_traits_D_std___std__UAEXXZ, UINT32_C(0x004EF66E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF674(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF674));
    LIFT_IMPORT_RETURN(sfera_import_404_MSVCP100_dll__uflow___basic_streambuf_DU__char_traits_D_std___std__MAEHXZ, UINT32_C(0x004EF674));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF67A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF67A));
    LIFT_IMPORT_RETURN(sfera_import_403_MSVCP100_dll__setbuf___basic_streambuf_DU__char_traits_D_std___std__MAEPAV12_PAD_J_Z, UINT32_C(0x004EF67A));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF680(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF680));
    LIFT_IMPORT_RETURN(sfera_import_362_MSVCP100_dll__sync___basic_streambuf_DU__char_traits_D_std___std__MAEHXZ, UINT32_C(0x004EF680));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF686(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF686));
    LIFT_IMPORT_RETURN(sfera_import_361_MSVCP100_dll__imbue___basic_streambuf_DU__char_traits_D_std___std__MAEXABVlocale_2__Z, UINT32_C(0x004EF686));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004EF690(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF690));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi, lift_image_va(UINT32_C(0x00516290)));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF6AA, UINT32_C(0x004EF6A2));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), lift_image_va(UINT32_C(0x004EF6AA)), lift_image_va(UINT32_C(0x004EF6A8)))) { return; }
    LIFT_BLOCK(label_000EF6AA, UINT32_C(0x004EF6AA));
    LIFT_LOAD32(cpu->esi, cpu->esi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->esi, 32u);
    LIFT_JZ(label_000EF6B8, UINT32_C(0x004EF6B1));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    sfera_import_040_KERNEL32_dll_LocalFree(cpu, lift_image_va(UINT32_C(0x004EF6B2)));
    cpu->eip = lift_image_va(UINT32_C(0x004EF6B8));
    LIFT_BLOCK(label_000EF6B8, UINT32_C(0x004EF6B8));
    LIFT_EPILOGUE1(0u, cpu->esi);
}

void LIFT_CDECL sfera_sub_004EF6C0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    LIFT_ENTER(UINT32_C(0x004EF6C0));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_SP_SUB(UINT32_C(0x00000010));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(lift_image_va(UINT32_C(0x0051D0C0))));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    lift_push32(cpu, (uint32_t)(cpu->edx));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF0), lift_image_va(UINT32_C(0x00516290)));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF4), cpu->eax);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFF8), cpu->ecx);
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004EE92A, UINT32_C(0x004EF6F0));
    LIFT_TRAP_RETURN(UINT32_C(0x004EF6F0), "INT3");
}

void LIFT_CDECL sfera_sub_004EF700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF700));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esi, lift_image_va(UINT32_C(0x00516290)));
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
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), lift_image_va(UINT32_C(0x004EF732)), lift_image_va(UINT32_C(0x004EF730)))) { return; }
    LIFT_BLOCK(label_000EF732, UINT32_C(0x004EF732));
    cpu->eax = (uint32_t)(cpu->esi);
    LIFT_EPILOGUE2(4u, cpu->esi, cpu->ebp);
}

void LIFT_CDECL sfera_sub_004EF740(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF740));
    cpu->edi = (uint32_t)(cpu->edi);
    lift_push32(cpu, (uint32_t)(cpu->ebp));
    cpu->ebp = (uint32_t)(cpu->esp);
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x00000008));
    LIFT_STORE32(cpu->esi, lift_image_va(UINT32_C(0x00516290)));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF75D, UINT32_C(0x004EF755));
    LIFT_LOAD32(cpu->ecx, cpu->eax);
    LIFT_LOAD32(cpu->edx, cpu->ecx + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), lift_image_va(UINT32_C(0x004EF75D)), lift_image_va(UINT32_C(0x004EF75B)))) { return; }
    LIFT_BLOCK(label_000EF75D, UINT32_C(0x004EF75D));
    LIFT_LOAD32(cpu->eax, cpu->esi + UINT32_C(0x0000000C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000EF76B, UINT32_C(0x004EF764));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    sfera_import_040_KERNEL32_dll_LocalFree(cpu, lift_image_va(UINT32_C(0x004EF765)));
    cpu->eip = lift_image_va(UINT32_C(0x004EF76B));
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

void LIFT_CDECL sfera_sub_004EF781(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF781));
    LIFT_PUSH2(cpu->eax, lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    LIFT_SP_SUB(lift_load32(((uint32_t)(cpu->esp + UINT32_C(0x0000000C)))));
    LIFT_PUSH3(cpu->ebx, cpu->esi, cpu->edi);
    LIFT_STORE32(cpu->eax, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->ebp, ^, 32u, cpu->eax = (uint32_t)(result););
    LIFT_PUSH2(cpu->eax, lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFFC)))));
    LIFT_STORE32(cpu->ebp + UINT32_C(0xFFFFFFFC), UINT32_C(0xFFFFFFFF));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF4))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF7B4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF7B4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF4));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP5(cpu->ecx, cpu->edi, cpu->edi, cpu->esi, cpu->ebx);
    cpu->esp = (uint32_t)(cpu->ebp);
    cpu->ebp = (uint32_t)(lift_pop32(cpu));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF7D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF7D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EF7D8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF7D8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF7D8, UINT32_C(0x004EF7D8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF7E9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517D14)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF800(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF800;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF800, UINT32_C(0x004EF800));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF811));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517D78)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF820(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF820;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF820, UINT32_C(0x004EF820));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF831));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517DF8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF840(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF840;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF840, UINT32_C(0x004EF840));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF851));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517E5C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF860(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF860));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EF868(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF868));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EF870(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF870));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EF878(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF878;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF878, UINT32_C(0x004EF878));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF889));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517EC0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF8A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF8A0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EF8A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF8A8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF8A8, UINT32_C(0x004EF8A8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF8B9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517EEC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF8D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF8D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EF8D8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF8D8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF8D8, UINT32_C(0x004EF8D8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF8E9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517F18)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF900));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EF908(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF908;
    LIFT_BLOCK(label_00002CC0, UINT32_C(0x00402CC0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_00002CE4, UINT32_C(0x00402CC9));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x004FDEBC)));
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

void LIFT_CDECL sfera_sub_004EF910(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF910;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF910, UINT32_C(0x004EF910));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF921));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517F4C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF930));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EF938(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF938;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF938, UINT32_C(0x004EF938));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF949));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517F78)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF960(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF960));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EF968(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF968;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF968, UINT32_C(0x004EF968));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF979));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517FA4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF990));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EF998(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF998;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF998, UINT32_C(0x004EF998));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF9A9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00517FD0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF9C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF9C0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EF9CD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EF9D1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF9D1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EF9D1, UINT32_C(0x004EF9D1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EF9E2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518030)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EF9F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EF9F0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EF9FD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFA01(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFA01;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFA01, UINT32_C(0x004EFA01));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFA12));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518090)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFA20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA20));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFA2D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFA31(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFA31;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFA31, UINT32_C(0x004EFA31));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFA42));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005180CC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFA50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA50));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFA58(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA58));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFA60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFA60;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFA60, UINT32_C(0x004EFA60));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFA71));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518100)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFA80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFA80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFA8D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFA91(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFA91;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFA91, UINT32_C(0x004EFA91));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFAA2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518160)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFAB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFAB0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFABD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFAC1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFAC1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFAC1, UINT32_C(0x004EFAC1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFAD2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005181C0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFAE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFAE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFAED));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFAF1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFAF1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFAF1, UINT32_C(0x004EFAF1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFB02));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518220)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFB10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFB1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFB21(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB21));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFB29(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFB29;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFB29, UINT32_C(0x004EFB29));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFB3A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518288)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFB50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFB5D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFB61(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFB61;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFB61, UINT32_C(0x004EFB61));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFB72));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005182E8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFB80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFB88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB88));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFB90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFB98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFB98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFBA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFBA0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFBA0, UINT32_C(0x004EFBA0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFBB1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000004), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFBBE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051830C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFBD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFBD0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFBD0, UINT32_C(0x004EFBD0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFBE1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051838C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFBF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFBF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFBFD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFC01(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFC01;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFC01, UINT32_C(0x004EFC01));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFC12));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005183EC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFC20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC20));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFC2D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFC31(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFC31;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFC31, UINT32_C(0x004EFC31));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFC42));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051844C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFC50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFC5D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFC61(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFC61;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFC61, UINT32_C(0x004EFC61));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFC72));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005184AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFC80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFC8D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFC91(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFC91));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFC99(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFC99;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFC99, UINT32_C(0x004EFC99));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFCAA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518514)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFCC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFCC0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFCCD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFCD1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFCD1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFCD1, UINT32_C(0x004EFCD1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFCE2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518574)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFCF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFCF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004EFCFD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004EFD01(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD01));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFD09(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFD09;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFD09, UINT32_C(0x004EFD09));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFD1A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005185DC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFD30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFD38(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD38));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFD40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD40));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFD48(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFD48;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFD48, UINT32_C(0x004EFD48));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFD59));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFD66));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518618)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFD70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFD70));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFD78(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFD78;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFD78, UINT32_C(0x004EFD78));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFD89));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518644)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFDA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFDA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFDA8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFDA8;
    LIFT_BLOCK(label_00002CC0, UINT32_C(0x00402CC0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000008)))), UINT32_C(0x00000000), 32u);
    LIFT_JZ(label_00002CE4, UINT32_C(0x00402CC9));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x004FDEBC)));
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

void LIFT_CDECL sfera_sub_004EFDB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFDB0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFDB0, UINT32_C(0x004EFDB0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFDC1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518678)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFDD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFDD0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFDD8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFDD8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_TAIL(sfera_sub_00402D20);
}

void LIFT_CDECL sfera_sub_004EFDE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFDE0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFDE0, UINT32_C(0x004EFDE0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFDF1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005186AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFE00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFE00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFE08(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFE08;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFE08, UINT32_C(0x004EFE08));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFE19));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFE26));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005186D8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFE30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFE30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFE38(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFE38;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFE38, UINT32_C(0x004EFE38));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFCC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFE49));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFE56));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518704)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFE60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFE60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFE68(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004EFE70(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFE70;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFE70, UINT32_C(0x004EFE70));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFAC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFE81));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFE8E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518738)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFEA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFEA8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEA8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFEB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004EFEB8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFEB8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFEB8, UINT32_C(0x004EFEB8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF94))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF90));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFEC9));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFED6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518774)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFEE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFC0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFEE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFEE8;
    LIFT_BLOCK(label_00006260, UINT32_C(0x00406260));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F2238)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000020)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_JZ(label_000062B1, UINT32_C(0x00406296));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x004FDEBC)));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000EFEE8, UINT32_C(0x004EFEE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_00006260;
}

void LIFT_CDECL sfera_sub_004EFEF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFEF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFEF8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFEF8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFEF8, UINT32_C(0x004EFEF8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFF09));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFF16));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005187B0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFF20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFF28(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF28));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFF30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFF38(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFF38;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFF38, UINT32_C(0x004EFF38));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFF49));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005187EC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFF60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFF68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFF68;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFF68, UINT32_C(0x004EFF68));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFF79));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518818)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFF90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFF98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFF98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFFA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFFA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFFA8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFFA8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE8))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004EFFB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFFB0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFFB0, UINT32_C(0x004EFFB0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFFC1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051885C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004EFFD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004EFFD0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004EFFD8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EFFD8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000EFFD8, UINT32_C(0x004EFFD8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFFE9));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004EFFF6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518888)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0000));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0008(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0008;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0008, UINT32_C(0x004F0008));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0019));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0026));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005188B4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0030(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0030));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0038(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0040(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0040;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0040, UINT32_C(0x004F0040));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFAC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0051));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F005E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005188E8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0070));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0078(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0078));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0080));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004F0088(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0088;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0088, UINT32_C(0x004F0088));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF8C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF88));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0099));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F00A6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518924)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F00B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFBC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004F00B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F00B8;
    LIFT_BLOCK(label_00006260, UINT32_C(0x00406260));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F2238)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000020)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_JZ(label_000062B1, UINT32_C(0x00406296));
    cpu->edx = (uint32_t)(UINT32_C(0x00000027));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x004FDEBC)));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F00B8, UINT32_C(0x004F00B8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_00006260;
}

void LIFT_CDECL sfera_sub_004F00C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F00C8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F00C8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F00C8, UINT32_C(0x004F00C8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F00D9));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F00E6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518960)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F00F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F00F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F00F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0100(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0100;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0100, UINT32_C(0x004F0100));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0111));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F011E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518994)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0130(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0130));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0138(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0138));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0140(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0140));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0148(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0148;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0148, UINT32_C(0x004F0148));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0159));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0166));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005189D0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0170));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0178(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0178));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004F0180(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x004FDEBC)));
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

void LIFT_CDECL sfera_sub_004F0188(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0188;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0188, UINT32_C(0x004F0188));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0199));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F01A6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518A0C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F01B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F01B8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01B8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F01C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F01C8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F01C8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F01C8, UINT32_C(0x004F01C8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F01D9));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F01E6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518A48)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F01F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F01F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F01F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F01F8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F01F8, UINT32_C(0x004F01F8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0209));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0216));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518A74)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0220));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0228(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0228));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0230));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0238(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0240(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0240;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0240, UINT32_C(0x004F0240));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF9C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0251));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F025E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518AB8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0270));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0278(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0278));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004F0280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0280));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0288(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0288));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F0290(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0290;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0290, UINT32_C(0x004F0290));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F02A1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F02AE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518AFC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F02C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004F02C8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02C8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F02D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004F02D8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F02D8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00402CF0);
}

void LIFT_CDECL sfera_sub_004F02E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F02E0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F02E0, UINT32_C(0x004F02E0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F02F1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F02FE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518B40)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0310(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0310;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0310, UINT32_C(0x004F0310));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0318(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0318));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

void LIFT_CDECL sfera_sub_004F0323(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0323;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0323, UINT32_C(0x004F0323));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0334));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518B74)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0340(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0340;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0340, UINT32_C(0x004F0340));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0348(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0348;
    LIFT_BLOCK(label_00014B90, UINT32_C(0x00414B90));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0618)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_004149A0, UINT32_C(0x00414BC5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00414BCD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0348, UINT32_C(0x004F0348));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00014B90;
}

void LIFT_CDECL sfera_sub_004F0353(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0353;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0353, UINT32_C(0x004F0353));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0364));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518BA8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0370(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0370;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0370, UINT32_C(0x004F0370));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0378(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0383(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0383;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0383, UINT32_C(0x004F0383));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0394));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518BDC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F03A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03A0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03A9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F03AB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03AB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03B4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F03B6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03B6));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03BF));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F03C1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F03C1));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F03CA));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F03CC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03CC;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F03CC, UINT32_C(0x004F03CC));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F03DD));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518C20)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F03F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F03F0, UINT32_C(0x004F03F0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F03F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F03F8;
    LIFT_BLOCK(label_00015050, UINT32_C(0x00415050));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F03F8, UINT32_C(0x004F03F8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015050;
}

void LIFT_CDECL sfera_sub_004F0403(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0403;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0403, UINT32_C(0x004F0403));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0414));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518C54)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0420(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0428(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0428;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0428, UINT32_C(0x004F0428));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0439));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518C80)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0450(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0450;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0450, UINT32_C(0x004F0450));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0458(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0458;
    LIFT_BLOCK(label_00015300, UINT32_C(0x00415300));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0458, UINT32_C(0x004F0458));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015300;
}

void LIFT_CDECL sfera_sub_004F0463(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0463;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0463, UINT32_C(0x004F0463));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0474));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518CB4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0480(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0480;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0480, UINT32_C(0x004F0480));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0488(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0488;
    LIFT_BLOCK(label_000154E0, UINT32_C(0x004154E0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0488, UINT32_C(0x004F0488));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000154E0;
}

void LIFT_CDECL sfera_sub_004F0493(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0493;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0493, UINT32_C(0x004F0493));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F04A4));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518CE8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F04B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F04B0, UINT32_C(0x004F04B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F04B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04B8;
    LIFT_BLOCK(label_00015550, UINT32_C(0x00415550));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F04B8, UINT32_C(0x004F04B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015550;
}

void LIFT_CDECL sfera_sub_004F04C3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04C3;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F04C3, UINT32_C(0x004F04C3));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F04D4));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518D1C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F04E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F04E0, UINT32_C(0x004F04E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F04E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04E8;
    LIFT_BLOCK(label_000155C0, UINT32_C(0x004155C0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F04E8, UINT32_C(0x004F04E8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000155C0;
}

void LIFT_CDECL sfera_sub_004F04F3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F04F3;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F04F3, UINT32_C(0x004F04F3));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0504));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518D50)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0510(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0510;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0510, UINT32_C(0x004F0510));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0518(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0518;
    LIFT_BLOCK(label_00015630, UINT32_C(0x00415630));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0518, UINT32_C(0x004F0518));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00015630;
}

void LIFT_CDECL sfera_sub_004F0523(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0523;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0523, UINT32_C(0x004F0523));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0534));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518D84)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0540(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0540));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0549));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F054B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F054B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0554));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0556(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0556;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0556, UINT32_C(0x004F0556));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0567));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518DB8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0580;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0580, UINT32_C(0x004F0580));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0588(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0588;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0588, UINT32_C(0x004F0588));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

void LIFT_CDECL sfera_sub_004F0593(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0593;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0593, UINT32_C(0x004F0593));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F05A4));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518DEC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F05B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F05B0, UINT32_C(0x004F05B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F05B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05B8;
    LIFT_BLOCK(label_00016330, UINT32_C(0x00416330));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F05B8, UINT32_C(0x004F05B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016330;
}

void LIFT_CDECL sfera_sub_004F05C3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05C3;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F05C3, UINT32_C(0x004F05C3));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F05D4));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518E20)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F05E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F05E0, UINT32_C(0x004F05E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F05E8(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F05F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F05F0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F05F0, UINT32_C(0x004F05F0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0601));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518E54)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0610(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0618(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0618;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0618, UINT32_C(0x004F0618));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0629));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518E80)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0640(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0640;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0640, UINT32_C(0x004F0640));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0648(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0648));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

void LIFT_CDECL sfera_sub_004F0653(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0653));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F065E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F065E;
    LIFT_BLOCK(label_000166B0, UINT32_C(0x004166B0));
    LIFT_TAIL(sfera_sub_00416650);
    LIFT_BLOCK(label_000F065E, UINT32_C(0x004F065E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000166B0;
}

void LIFT_CDECL sfera_sub_004F0669(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0669;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0669, UINT32_C(0x004F0669));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F067A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518EC4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0690(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0690;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0690, UINT32_C(0x004F0690));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0698(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0698;
    LIFT_BLOCK(label_000166C0, UINT32_C(0x004166C0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0618)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040A060, UINT32_C(0x004166F5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004166FD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0698, UINT32_C(0x004F0698));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000166C0;
}

void LIFT_CDECL sfera_sub_004F06A3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F06A3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F06AE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06AE;
    LIFT_BLOCK(label_000167E0, UINT32_C(0x004167E0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0788)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F06AE, UINT32_C(0x004F06AE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000167E0;
}

void LIFT_CDECL sfera_sub_004F06B9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06B9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F06B9, UINT32_C(0x004F06B9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F06CA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518F08)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F06E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F06E0, UINT32_C(0x004F06E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F06E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06E8;
    LIFT_BLOCK(label_00016720, UINT32_C(0x00416720));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0618)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_00408A50, UINT32_C(0x00416755));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x0041675D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F06E8, UINT32_C(0x004F06E8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016720;
}

void LIFT_CDECL sfera_sub_004F06F3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F06F3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F06FE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F06FE;
    LIFT_BLOCK(label_00016850, UINT32_C(0x00416850));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0788)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F06FE, UINT32_C(0x004F06FE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016850;
}

void LIFT_CDECL sfera_sub_004F0709(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0709;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0709, UINT32_C(0x004F0709));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F071A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518F4C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0730(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0730;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0730, UINT32_C(0x004F0730));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0738(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0738;
    LIFT_BLOCK(label_00016780, UINT32_C(0x00416780));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0618)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040A0C0, UINT32_C(0x004167B5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004167BD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0738, UINT32_C(0x004F0738));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016780;
}

void LIFT_CDECL sfera_sub_004F0743(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0743));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F074E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F074E;
    LIFT_BLOCK(label_000168C0, UINT32_C(0x004168C0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0788)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F074E, UINT32_C(0x004F074E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000168C0;
}

void LIFT_CDECL sfera_sub_004F0759(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0759;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0759, UINT32_C(0x004F0759));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F076A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518F90)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0780(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0788(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0788;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0788, UINT32_C(0x004F0788));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0799));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00518FBC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F07B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F07B0, UINT32_C(0x004F07B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F07B8(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F07C3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F07C3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F07CE(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F07D9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F07D9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F07D9, UINT32_C(0x004F07D9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F07EA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519000)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0800(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0800;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0800, UINT32_C(0x004F0800));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0808(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0813(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0813));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F081E(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0829(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0829;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0829, UINT32_C(0x004F0829));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F083A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519044)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0850(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0850;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0850, UINT32_C(0x004F0850));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0858(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0863(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0863));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F086E(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0879(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0879;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0879, UINT32_C(0x004F0879));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F088A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519088)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F08A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F08A0, UINT32_C(0x004F08A0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F08A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08A8;
    LIFT_BLOCK(label_00016970, UINT32_C(0x00416970));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0618)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040D740, UINT32_C(0x004169A5));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004169AD));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F08A8, UINT32_C(0x004F08A8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00016970;
}

void LIFT_CDECL sfera_sub_004F08B3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F08B3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F08BE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08BE;
    LIFT_BLOCK(label_00017210, UINT32_C(0x00417210));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0788)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F08BE, UINT32_C(0x004F08BE));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00017210;
}

void LIFT_CDECL sfera_sub_004F08C9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08C9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F08C9, UINT32_C(0x004F08C9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F08DA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005190CC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F08F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F08F0, UINT32_C(0x004F08F0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F08F8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F08F8;
    LIFT_BLOCK(label_000169D0, UINT32_C(0x004169D0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0618)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_CALL_ENTER(sfera_sub_0040BC20, UINT32_C(0x00416A05));
    LIFT_LOAD32(cpu->eax, cpu->esi);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x00416A0D));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F08F8, UINT32_C(0x004F08F8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000004), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000169D0;
}

void LIFT_CDECL sfera_sub_004F0903(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0903));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F090E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F090E;
    LIFT_BLOCK(label_00017280, UINT32_C(0x00417280));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0788)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH4(cpu->eax, cpu->ecx, cpu->esi, cpu->edi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP3(cpu->ecx, cpu->edi, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F090E, UINT32_C(0x004F090E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000014), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_00017280;
}

void LIFT_CDECL sfera_sub_004F0919(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0919;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0919, UINT32_C(0x004F0919));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F092A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519110)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0940));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0949));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F094B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F094B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0954));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0956(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0956));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F095F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0961(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0961;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0961, UINT32_C(0x004F0961));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0972));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051914C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0980(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0980;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0980, UINT32_C(0x004F0980));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0988(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0990(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0990;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0990, UINT32_C(0x004F0990));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F09A1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519180)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F09B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09B0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F09B0, UINT32_C(0x004F09B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F09B8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F09B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F09C3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09C3;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F09C3, UINT32_C(0x004F09C3));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F09D4));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005191B4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F09E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09E0;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F09E0, UINT32_C(0x004F09E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F09E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F09E8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F09E8, UINT32_C(0x004F09E8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F09F9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005191E0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0A10(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A10;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0A10, UINT32_C(0x004F0A10));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0A18(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0A23(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A23;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0A23, UINT32_C(0x004F0A23));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0A34));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519214)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0A40(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A40;
    LIFT_BLOCK(label_00015040, UINT32_C(0x00415040));
    LIFT_TAIL(sfera_sub_00401E50);
    LIFT_BLOCK(label_000F0A40, UINT32_C(0x004F0A40));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_00015040;
}

void LIFT_CDECL sfera_sub_004F0A48(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F0A53(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0A53;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0A53, UINT32_C(0x004F0A53));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0A64));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519248)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0A70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A70));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A79));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0A7B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A7B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A84));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0A86(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A86));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A8F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0A91(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A91));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0A9A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0A9C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0A9C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0AA5));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0AA7(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0AA7;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0AA7, UINT32_C(0x004F0AA7));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0AB8));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051926C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0AD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0AD0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_0042B7D0);
}

void LIFT_CDECL sfera_sub_004F0AD8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0AD8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0AD8, UINT32_C(0x004F0AD8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0AE9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005192C0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0B00(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B00;
    LIFT_BLOCK(label_00018890, UINT32_C(0x00418890));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_046_KERNEL32_dll_LeaveCriticalSection, UINT32_C(0x00418893), UINT32_C(0x00418899));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0B00, UINT32_C(0x004F0B00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFF0))));
    goto label_00018890;
}

void LIFT_CDECL sfera_sub_004F0B08(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B08;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0B08, UINT32_C(0x004F0B08));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0B19));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005192EC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0B30));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_0042B7D0);
}

void LIFT_CDECL sfera_sub_004F0B38(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B38;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0B38, UINT32_C(0x004F0B38));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0B49));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519318)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0B60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B60;
    LIFT_BLOCK(label_00018890, UINT32_C(0x00418890));
    LIFT_LOAD32(cpu->eax, cpu->ecx);
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_IMPORT_CALL(sfera_import_046_KERNEL32_dll_LeaveCriticalSection, UINT32_C(0x00418893), UINT32_C(0x00418899));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F0B60, UINT32_C(0x004F0B60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFDD8))));
    goto label_00018890;
}

void LIFT_CDECL sfera_sub_004F0B6B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0B6B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0B6B, UINT32_C(0x004F0B6B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFDD0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFDCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0B82));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0B8F));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519344)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0BA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0BA0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0BA9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0BAB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0BAB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0BAB, UINT32_C(0x004F0BAB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0BBC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005193B4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0BD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0BD0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0BD9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0BDB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0BDB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0BDB, UINT32_C(0x004F0BDB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0BEC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519404)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0C00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_0047ED10);
}

void LIFT_CDECL sfera_sub_004F0C08(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0C08;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0C08, UINT32_C(0x004F0C08));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0C19));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0C23));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519430)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0C30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB4))));
    LIFT_TAIL(sfera_sub_0047ED10);
}

void LIFT_CDECL sfera_sub_004F0C3B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C3B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB0))));
    LIFT_TAIL(sfera_sub_0047EDB0);
}

void LIFT_CDECL sfera_sub_004F0C46(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0C46;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0C46, UINT32_C(0x004F0C46));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFEA0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE9C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0C5D));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0C6A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519464)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0C80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFB4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0C89));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0C8B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0C8B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0C8B, UINT32_C(0x004F0C8B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0C9C));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0CA9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519490)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0CC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0CC0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0CC9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0CCB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0CCB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0CCB, UINT32_C(0x004F0CCB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0CDC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005194BC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0CF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0CF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0CF9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0CFB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0CFB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D04));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D06(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D06));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D0F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D11(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D11));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D1A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D1C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D1C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D25));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D27(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0D27;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0D27, UINT32_C(0x004F0D27));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0D38));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005194E0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0D50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D5C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D5E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D5E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D6A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D6C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D6C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D78));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D7A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D7A));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D86));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D88));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0D94));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0D96(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0D96));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0DA2));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0DA4(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0DA4;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0DA4, UINT32_C(0x004F0DA4));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFECC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFEC8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0DBB));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0DC8));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051952C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0DE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0DE0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00425E70);
}

void LIFT_CDECL sfera_sub_004F0DE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0DE8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0DE8, UINT32_C(0x004F0DE8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0DF9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519588)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E19));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E1B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E24));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E26));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E2F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E31(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E31));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E3A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E3C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E3C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E45));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E47(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E47));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E50));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E52(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E52));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E5B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E5D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E5D));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0E66));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0E68(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0E68;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0E68, UINT32_C(0x004F0E68));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0E79));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005195AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0E90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0E90));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x00520244)));
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F0E9A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0E9A;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0E9A, UINT32_C(0x004F0E9A));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0EAB));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519618)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0EC0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0EC0;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F0EC0, UINT32_C(0x004F0EC0));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x00525FD8)));
    goto label_000161C0;
}

void LIFT_CDECL sfera_sub_004F0ECA(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0ECA;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0ECA, UINT32_C(0x004F0ECA));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0EDB));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519644)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0EF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0EF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0EF9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0EFB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0EFB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0EFB, UINT32_C(0x004F0EFB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0F0C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519670)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0F20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0F20));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_00425E70);
}

void LIFT_CDECL sfera_sub_004F0F28(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0F28;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0F28, UINT32_C(0x004F0F28));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0F39));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051969C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0F50));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_00425E70);
}

void LIFT_CDECL sfera_sub_004F0F58(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0F58;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0F58, UINT32_C(0x004F0F58));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0F69));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005196C8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0F80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0F80));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_00425E70);
}

void LIFT_CDECL sfera_sub_004F0F88(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0F88;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0F88, UINT32_C(0x004F0F88));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0F99));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005196F4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0FB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0FB0;
    LIFT_BLOCK(label_0002E1E0, UINT32_C(0x0042E1E0));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_CMP(lift_load32(((uint32_t)(cpu->esi + UINT32_C(0x00000004)))), UINT32_C(0x00000000), 32u);
    LIFT_STORE32(cpu->esi, lift_image_va(UINT32_C(0x004FF874)));
    LIFT_JZ(label_0002E20A, UINT32_C(0x0042E1EF));
    cpu->edx = (uint32_t)(UINT32_C(0x00000065));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x004FF878)));
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

void LIFT_CDECL sfera_sub_004F0FB8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0FB8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0FB8, UINT32_C(0x004F0FB8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F0FC9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519720)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F0FE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0FE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0FE9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0FEB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F0FEB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F0FF4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F0FF6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F0FF6;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F0FF6, UINT32_C(0x004F0FF6));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1007));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519754)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1020(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1028(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1028;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1028, UINT32_C(0x004F1028));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1039));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519780)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1050(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1058(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1058;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1058, UINT32_C(0x004F1058));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1069));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005197AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1080(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1080));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE14));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F108C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F108E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F108E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F108E, UINT32_C(0x004F108E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE08))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE04));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F10A5));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F10B2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005197D8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F10C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F10C0));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04DC068C)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04DC068C)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F10CE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F10CE;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F10CE, UINT32_C(0x004F10CE));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx)));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F10DE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519804)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F10F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F10F0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F10F9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F10FB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F10FB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F10FB, UINT32_C(0x004F10FB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F110C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519830)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1120));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1129));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F112B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F112B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1134));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1136(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1136;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1136, UINT32_C(0x004F1136));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE34))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE30));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F114D));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F115A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519864)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1170(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1170));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE44));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F117C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F117E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F117E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE44));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F118A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F118C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F118C;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F118C, UINT32_C(0x004F118C));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE40))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE3C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F11A3));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F11B0));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519898)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F11C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F11C0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFC8));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F11C8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F11C8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F11D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F11D0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F11D0, UINT32_C(0x004F11D0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F11E1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F11EE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005198CC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1200(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1200));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1208(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1208;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1208, UINT32_C(0x004F1208));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1219));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1226));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005198F8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1230));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1238(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1238));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1240(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1240;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1240, UINT32_C(0x004F1240));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1251));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F125E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051992C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1270(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1270));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04EDD0C8)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04EDD0C8)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F127E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F127E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F127E, UINT32_C(0x004F127E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F128F));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519958)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F12A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A0;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(lift_image_va(UINT32_C(0x004FF230)));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12A0, UINT32_C(0x004F12A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    goto label_00051CE0;
}

void LIFT_CDECL sfera_sub_004F12A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12A8;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(lift_image_va(UINT32_C(0x004FF230)));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12A8, UINT32_C(0x004F12A8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    goto label_00051CE0;
}

void LIFT_CDECL sfera_sub_004F12B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12B0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F12B0, UINT32_C(0x004F12B0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF48))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF44));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F12C7));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F12D4));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051998C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F12E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E0;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(lift_image_va(UINT32_C(0x004FF230)));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12E0, UINT32_C(0x004F12E0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    goto label_00051CE0;
}

void LIFT_CDECL sfera_sub_004F12E8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12E8;
    LIFT_BLOCK(label_00051CE0, UINT32_C(0x00451CE0));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000073)));
    cpu->edx = (uint32_t)(lift_image_va(UINT32_C(0x004FF230)));
    LIFT_CALL_ENTER(sfera_sub_004EB520, UINT32_C(0x00451CEE));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F12E8, UINT32_C(0x004F12E8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    goto label_00051CE0;
}

void LIFT_CDECL sfera_sub_004F12F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F12F0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F12F0, UINT32_C(0x004F12F0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF44))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF40));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1307));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1314));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x005199F4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1320));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE0))));
    LIFT_TAIL(sfera_sub_00480390);
}

void LIFT_CDECL sfera_sub_004F1328(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1328;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1328, UINT32_C(0x004F1328));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1339));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1346));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519A20)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1350));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1359));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F135B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F135B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1364));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1366(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1366));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F136F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1371(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1371));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F137A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F137C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F137C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1385));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1387(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1387));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1390));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1392(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1392));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F139B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F139D(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F139D;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F139D, UINT32_C(0x004F139D));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFAC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F13AE));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F13BB));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519A44)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F13D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F13D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE1C))));
    LIFT_TAIL(sfera_sub_00480390);
}

void LIFT_CDECL sfera_sub_004F13DB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F13DB));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04DC068C)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04DC068C)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F13E9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F13E9));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFE0C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F13F5));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F13F7(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F13F7;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F13F7, UINT32_C(0x004F13F7));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFDFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFDF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F140E));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F141B));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519AB8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1430(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1430));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04DC068C)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04DC068C)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F143E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F143E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F143E, UINT32_C(0x004F143E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F144F));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519AE4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1460(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1460));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1468(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1468;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1468, UINT32_C(0x004F1468));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFCC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1479));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000004), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1486));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519B10)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1490(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1490));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1498(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1498));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F14A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F14A0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F14A0, UINT32_C(0x004F14A0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F14B1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F14BE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519B44)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F14D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F14D0));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04EE0498)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04EE0498)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F14DE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F14DE;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F14DE, UINT32_C(0x004F14DE));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF54))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF50));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F14F5));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1502));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519B70)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1510(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1510));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F151C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F151E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F151E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F152A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F152C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F152C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1538));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F153A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F153A));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1546));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1548(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1548));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1554));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1556(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1556));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1562));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1564(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1564));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1570));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1572(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1572));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFBE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F157E));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1580;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1580, UINT32_C(0x004F1580));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFBEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFBE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1597));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F15A4));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519B94)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F15B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F15B0;
    LIFT_BLOCK(label_000161C0, UINT32_C(0x004161C0));
    LIFT_LOAD32(cpu->eax, cpu->ecx + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004161C9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
    LIFT_BLOCK(label_000F15B0, UINT32_C(0x004F15B0));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04EDCD70)));
    goto label_000161C0;
}

void LIFT_CDECL sfera_sub_004F15BA(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F15BA;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F15BA, UINT32_C(0x004F15BA));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F15CB));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519C00)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F15E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F15E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F15E9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F15EB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F15EB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F15F4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F15F6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F15F6;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F15F6, UINT32_C(0x004F15F6));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1607));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519C34)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1620(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1620));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEC4))));
    LIFT_TAIL(sfera_sub_0047ED10);
}

void LIFT_CDECL sfera_sub_004F162B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F162B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_0047EDB0);
}

void LIFT_CDECL sfera_sub_004F1636(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1636;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1636, UINT32_C(0x004F1636));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFEB8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFEB4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F164D));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F165A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519C68)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1670(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1670));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFBC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1679));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F167B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F167B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F167B, UINT32_C(0x004F167B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F168C));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1699));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519C94)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F16B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F16B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFBC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F16B9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F16BB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F16BB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F16BB, UINT32_C(0x004F16BB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF7C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF78));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F16D2));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F16DF));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519CC0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F16F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F16F0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFBC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F16F9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F16FB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F16FB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F16FB, UINT32_C(0x004F16FB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF8C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF88));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F170C));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1719));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519CEC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1730));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF68));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F173C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F173E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F173E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF68));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F174A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F174C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F174C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF58));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1758));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F175A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F175A;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F175A, UINT32_C(0x004F175A));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF30))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF2C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1771));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F177E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519D28)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1790(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1790));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1799));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F179B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F179B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F179B, UINT32_C(0x004F179B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF6C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF68));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F17B2));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F17BF));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519D54)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F17D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F17D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000C80), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00430BC0);
}

void LIFT_CDECL sfera_sub_004F17DE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F17DE;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F17DE, UINT32_C(0x004F17DE));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F17EF));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519D80)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1800(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1800));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFF2C4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000C80), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00430BC0);
}

void LIFT_CDECL sfera_sub_004F1811(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1811;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1811, UINT32_C(0x004F1811));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFF2C0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFF2BC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1828));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1835));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519DAC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1840(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1840;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1840, UINT32_C(0x004F1840));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1851));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519E10)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1860(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1860));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1868(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1868));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFAC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1871));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1873(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1873;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1873, UINT32_C(0x004F1873));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1884));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1891));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519E6C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F18A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F18A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F18A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F18A8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F18A8, UINT32_C(0x004F18A8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F18B9));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F18C6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519E98)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F18D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F18D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F18D8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F18D8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F18D8, UINT32_C(0x004F18D8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F18E9));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F18F6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519EC4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1900(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1919(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1919;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1919, UINT32_C(0x004F1919));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F192A));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1937));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519EF0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1950(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1969(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1969));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1971(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1971;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1971, UINT32_C(0x004F1971));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1982));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F198F));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519F24)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F19A0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F19B9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F19B9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F19B9, UINT32_C(0x004F19B9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F19CA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519F50)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F19E0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F19F9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F19F9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F19F9, UINT32_C(0x004F19F9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1A0A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519F7C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1A20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1A28(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1A41(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1A5A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1A5A;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1A5A, UINT32_C(0x004F1A5A));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF84))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF80));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1A6B));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1A78));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519FB8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1A90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1A98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1A98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1AA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1AA0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1AA0, UINT32_C(0x004F1AA0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1AB1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1ABE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x00519FEC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1AD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AD0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1AD8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AD8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1AE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1AEB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AEB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1AF3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AF3));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1AFE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1AFE));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B09(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B09));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B14(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B14));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B1C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B1C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B27(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B27));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B2F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B2F));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1B3B));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1B3D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B3D));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B45(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B45));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1B51));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1B53(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B53));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B5B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B5B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1B66(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1B66));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFEC8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1B72));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1B74(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1B74;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1B74, UINT32_C(0x004F1B74));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFEC0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFEBC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1B8B));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1B98));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A010)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1BB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE4C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1BBB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BBB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE30))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1BC6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BC6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFDF8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1BD1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BD1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1BDC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BDC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE84))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1BE7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BE7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE14))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1BF2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BF2));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1BFD(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1BFD));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C08(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C08));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C10));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C1B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C26));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE68))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C31(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C31));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEA0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C3C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C3C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C44(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C44));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C4F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C4F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C57(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C57));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C62(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1C62));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1C6A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1C6A;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1C6A, UINT32_C(0x004F1C6A));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFDCC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFDC8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1C81));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1C8E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A0B4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1CA0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1CB9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1CB9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1CB9, UINT32_C(0x004F1CB9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1CCA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A170)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1CE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1CE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1CE8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1CE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1CF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1CF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1CF8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1CF8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1CF8, UINT32_C(0x004F1CF8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF50))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF4C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1D0F));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1D1C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A1AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1D30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D30));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D39));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1D3B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D3B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1D43(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D43));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1D4B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D4B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D54));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1D56(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D56));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1D5E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D5E));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D67));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1D69(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D69));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D72));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1D74(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1D74));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF8C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F1D7D));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F1D7F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1D7F;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1D7F, UINT32_C(0x004F1D7F));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF88))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF84));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1D90));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1D9D));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A1D0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1DB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF70))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F1DB6));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F1DBC(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1DC7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DC7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1DCF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DCF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1DD7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DD7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1DDF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1DDF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1DE7(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1DE7;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1DE7, UINT32_C(0x004F1DE7));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF64))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF60));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1DFE));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1E0B));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A234)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1E20(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F1E23));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F1E29(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1E31(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E31));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1E39(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E39));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1E41(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E41));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1E49(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1E49;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1E49, UINT32_C(0x004F1E49));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF98))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF94));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1E5A));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1E67));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A288)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x0000003C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1E88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E88));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000020))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1E90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1E98(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1E98));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1EA3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EA3));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE84))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1EAE(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EAE));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE68))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1EB9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EB9));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1EC1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EC1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE4C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1ECC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1ECC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEA0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1ED7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1ED7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1EDF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EDF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1EEA(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EEA));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1EF5(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1EF5));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F08(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F08));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F13(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F13));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F1B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F26));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F31(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1F31;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1F31, UINT32_C(0x004F1F31));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE44))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE40));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1F48));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1F55));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A2D4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1F60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F60));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F68(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F68));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF4C))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F1F6E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F1F74(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1F7F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F7F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F87(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1F87));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1F8F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F1F8F;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F1F8F, UINT32_C(0x004F1F8F));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF44))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF40));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1FA6));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F1FB3));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A388)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F1FC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FC0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1FC8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FC8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF38))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F1FCE));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F1FD4(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F1FDF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FDF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1FE7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FE7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1FEF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FEF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1FF7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FF7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F1FFF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F1FFF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2007(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2007;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2007, UINT32_C(0x004F2007));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF30))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF2C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F201E));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F202B));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A3D4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2040));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x00000004))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2048(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2048));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF6C))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F204E));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F2054(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F205F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F205F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2067(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2067));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F206F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F206F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2077(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2077;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2077, UINT32_C(0x004F2077));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF68))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF64));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F208E));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F209B));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A438)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F20B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F20B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_00480390);
}

void LIFT_CDECL sfera_sub_004F20B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F20B8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F20B8, UINT32_C(0x004F20B8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFBC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F20C9));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F20D6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A494)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F20E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F20E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFDA4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F20EC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F20EE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F20EE;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F20EE, UINT32_C(0x004F20EE));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFD8C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFD88));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2105));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2112));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A4C0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2120));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x0052183C)));
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F212A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F212A;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F212A, UINT32_C(0x004F212A));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFFC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F213B));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A4EC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2150));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2159));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F215B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F215B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F215B, UINT32_C(0x004F215B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F216C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A518)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2180(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2180));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFED8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F218C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F218E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F218E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F218E, UINT32_C(0x004F218E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFED0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFECC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F21A5));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F21B2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A544)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F21C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F21C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFDC8))));
    LIFT_TAIL(sfera_sub_004ED8E0);
}

void LIFT_CDECL sfera_sub_004F21CB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F21CB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F21CB, UINT32_C(0x004F21CB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFDAC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFDA8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F21E2));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F21EF));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A570)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2200(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2200));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_00480390);
}

void LIFT_CDECL sfera_sub_004F2208(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2208;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2208, UINT32_C(0x004F2208));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2219));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2226));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A59C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2230(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2230));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2238(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2238;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2238, UINT32_C(0x004F2238));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2249));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A5FC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2260(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2260;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2260, UINT32_C(0x004F2260));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2271));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A654)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2280(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2280;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2280, UINT32_C(0x004F2280));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2291));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A6AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F22A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F22A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF88))));
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F22A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F22A8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F22A8, UINT32_C(0x004F22A8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF74))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF70));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F22BF));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F22CC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A6D8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F22E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F22E0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F22E0, UINT32_C(0x004F22E0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F22F1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A730)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2300(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2300;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2300, UINT32_C(0x004F2300));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF84));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2311));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A794)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2320));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F2328(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2328;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2328, UINT32_C(0x004F2328));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2339));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A7E8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2350));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F235D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F2361(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2361;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2361, UINT32_C(0x004F2361));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2372));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A848)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2380(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2380));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F238D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F2391(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2391;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2391, UINT32_C(0x004F2391));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F23A2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A8A8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F23B0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F23B0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F23B0, UINT32_C(0x004F23B0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F23C1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A900)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F23D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F23D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F23D8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F23D8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F23E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F23E0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F23E0, UINT32_C(0x004F23E0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F23F1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F23FE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A934)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2410(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2410));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2419));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F241B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F241B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F241B, UINT32_C(0x004F241B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F242C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A960)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2440(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2440;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2440, UINT32_C(0x004F2440));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2451));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051A9B8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2460(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2460;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2460, UINT32_C(0x004F2460));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2471));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AA10)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2480(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2480));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

void LIFT_CDECL sfera_sub_004F248B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F248B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000030), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F2496(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2496));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000040), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F24A1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24A1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F24AC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F24AC;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F24AC, UINT32_C(0x004F24AC));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F24BD));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AA54)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F24D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

void LIFT_CDECL sfera_sub_004F24DB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24DB));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000030), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F24E6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24E6));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000040), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F24F1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F24F1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F24FC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F24FC;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F24FC, UINT32_C(0x004F24FC));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F250D));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AA98)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2520(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2520));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2529));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F252B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F252B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F252B, UINT32_C(0x004F252B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F253C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AAC4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2550(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2550));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2558(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2558;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2558, UINT32_C(0x004F2558));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2569));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2576));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AAF0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2580(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2580));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2588(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2588;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2588, UINT32_C(0x004F2588));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFBC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2599));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F25A6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AB1C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F25B0(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F25B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F25B8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F25B8, UINT32_C(0x004F25B8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F25C9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AB48)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F25E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F25E0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F25E0, UINT32_C(0x004F25E0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F25F1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051ABA0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2600(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2600));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F2608(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2608;
    LIFT_BLOCK(label_000AA210, UINT32_C(0x004AA210));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F25B8)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2608, UINT32_C(0x004F2608));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AA210;
}

void LIFT_CDECL sfera_sub_004F2616(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2616));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F2624(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2624));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F2632(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2632));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001D0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004F2640(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2640));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000208), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F264E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F264E));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000224), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F265C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F265C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000288), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F266A(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F2672(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2672;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2672, UINT32_C(0x004F2672));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2683));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051ABC4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2690(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2690;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2690, UINT32_C(0x004F2690));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F26A1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AC64)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F26B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F26B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F26B3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F26B9(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F26C1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F26C1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F26C1, UINT32_C(0x004F26C1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F26D2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051ACCC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F26E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F26E0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F26E0, UINT32_C(0x004F26E0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F26F1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AD24)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2700(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2700));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2708(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2708;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2708, UINT32_C(0x004F2708));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2719));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AD50)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2730(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2730));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2738(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2738));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x0000001C), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2743(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F274E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F274E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F274E, UINT32_C(0x004F274E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F275F));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AD8C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2770(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2770));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF88))));
    LIFT_TAIL(sfera_sub_004AE200);
}

void LIFT_CDECL sfera_sub_004F2778(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2778;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2778, UINT32_C(0x004F2778));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF80))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF7C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F278C));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2799));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051ADB8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F27B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27B0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEBC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F27BB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27BB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F27C6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27C6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F27D1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27D1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004F27D9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27D9));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F27E4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27E4));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F27EF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27EF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004F27F7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F27F7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2802(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2802));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F280D(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F280D;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F280D, UINT32_C(0x004F280D));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE44))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE40));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2824));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2831));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051ADDC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2840(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2840));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F2848(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2848;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2848, UINT32_C(0x004F2848));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFBC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2859));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AE50)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2870(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2870;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2870, UINT32_C(0x004F2870));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF80));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2881));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AEB4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2890(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2890));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF88))));
    LIFT_TAIL(sfera_sub_004AE200);
}

void LIFT_CDECL sfera_sub_004F2898(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2898;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2898, UINT32_C(0x004F2898));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF78))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF74));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F28AF));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F28BC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AF08)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F28D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F28D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F28D8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F28D8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F28D8, UINT32_C(0x004F28D8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF9C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF98));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F28E9));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F28F6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AF34)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2900(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2900));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F2908(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2908));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F290B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F2911(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2911;
    LIFT_BLOCK(label_000AA210, UINT32_C(0x004AA210));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F25B8)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2911, UINT32_C(0x004F2911));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000AA210;
}

void LIFT_CDECL sfera_sub_004F291F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F291F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F292D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F292D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F293B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F293B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001D0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004F2949(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2949));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000208), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2957(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2957));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000224), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2965(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2965));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000288), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F2973(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2973;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2973, UINT32_C(0x004F2973));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2984));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AF58)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2990(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2990));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2998(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2998));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F29A1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F29A3(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F29BC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F29BC;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F29BC, UINT32_C(0x004F29BC));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF9C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F29CD));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F29DA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051AFE4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F29F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F29F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F29F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F29F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A0B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A0B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A13(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A13));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A1E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A1E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A26(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A26));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A2E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A2E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A36(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A36));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A3E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A3E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A49(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A49));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF18));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A55));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2A57(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A57));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF20));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A63));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2A65(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A65));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF20));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A71));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2A73(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A73));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A7B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A7B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF20));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2A87));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2A89(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A89));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A91(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A91));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2A9C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2A9C));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF0C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2AA8));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2AAA(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2AAA;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2AAA, UINT32_C(0x004F2AAA));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF08))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF04));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2AC1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2ACE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B008)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2AE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2AE0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2AE8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2AE8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x0000001C), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2AF3(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2AF3));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F2AF6));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F2AFC(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F2B07(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B07));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F2B12(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2B12;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2B12, UINT32_C(0x004F2B12));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2B23));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B0D4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2B30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEE4))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F2B36));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F2B3C(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F2B47(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B47));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2B4F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B4F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2B5A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B5A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2B62(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B62));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2B6A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B6A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2B75(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2B75));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2B7D(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2B7D;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2B7D, UINT32_C(0x004F2B7D));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFED0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFECC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2B94));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2BA1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B120)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2BB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2BB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F2BB3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F2BB9(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F2BC1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2BC1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2BC1, UINT32_C(0x004F2BC1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2BD2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B194)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2BE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2BE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F2BED));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F2BF1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2BF1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2BF1, UINT32_C(0x004F2BF1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2C02));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B1C0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2C10(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2C10;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2C10, UINT32_C(0x004F2C10));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2C21));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2C2E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C494)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2C40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2C40));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F2C48(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F2C56(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2C56;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2C56, UINT32_C(0x004F2C56));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2C67));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B1F4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2C80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2C80));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F2C88(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2C88));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F2C8B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F2C91(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2C91;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2C91, UINT32_C(0x004F2C91));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2CA2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B228)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2CB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2CB0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFB4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2CB9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2CBB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2CBB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2CC3(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2CC3;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2CC3, UINT32_C(0x004F2CC3));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFAC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2CD4));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2CE1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B25C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2CF0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2CF0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2CF0, UINT32_C(0x004F2CF0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF80));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2D01));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B2C0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2D10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2D19));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2D1B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2D1B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F2D24));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F2D26(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2D26;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2D26, UINT32_C(0x004F2D26));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2D37));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B31C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2D50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2D50));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFE4))));
    LIFT_IMPORT_RETURN(sfera_import_391_MSVCP100_dll___1_Lockit_std__QAE_XZ, UINT32_C(0x004F2D53));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F2D59(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2D59;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2D59, UINT32_C(0x004F2D59));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2D6A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B358)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2D80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2D80;
    LIFT_BLOCK(label_000B1300, UINT32_C(0x004B1300));
    LIFT_LOAD32(cpu->ecx, cpu->ecx);
    LIFT_TEST(cpu->ecx, 32u);
    LIFT_JZ(label_000B131A, UINT32_C(0x004B1306));
    LIFT_IMPORT_CALL(sfera_import_398_MSVCP100_dll___Decref_facet_locale_std__QAEPAV123_XZ, UINT32_C(0x004B1306), UINT32_C(0x004B130C));
    LIFT_TEST(cpu->eax, 32u);
    LIFT_JZ(label_000B131A, UINT32_C(0x004B1310));
    LIFT_LOAD32(cpu->edx, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->eax);
    LIFT_LOAD32(cpu->eax, cpu->edx);
    lift_push32(cpu, (uint32_t)(UINT32_C(0x00000001)));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B131A)), lift_image_va(UINT32_C(0x004B1318)))) { return; }
    LIFT_BLOCK(label_000B131A, UINT32_C(0x004B131A));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2D80, UINT32_C(0x004F2D80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0x0000000C))));
    goto label_000B1300;
}

void LIFT_CDECL sfera_sub_004F2D88(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2D88;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2D88, UINT32_C(0x004F2D88));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2D99));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B3AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2DB0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DB0, UINT32_C(0x004F2DB0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    goto label_000B1320;
}

void LIFT_CDECL sfera_sub_004F2DB8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DB8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2DB8, UINT32_C(0x004F2DB8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2DC9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B3D8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2DE0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DE0, UINT32_C(0x004F2DE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    goto label_000B1320;
}

void LIFT_CDECL sfera_sub_004F2DE8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DE8;
    LIFT_BLOCK(label_000B1950, UINT32_C(0x004B1950));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F2DB8)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(sfera_import_378_MSVCP100_dll__uncaught_exception_std__YA_NXZ, UINT32_C(0x004B1980), UINT32_C(0x004B1986));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000B1992, UINT32_C(0x004B198A));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    sfera_import_379_MSVCP100_dll___Osfx___basic_ostream_DU__char_traits_D_std___std__QAEXXZ(cpu, lift_image_va(UINT32_C(0x004B198C)));
    cpu->eip = lift_image_va(UINT32_C(0x004B1992));
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
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B19B2)), lift_image_va(UINT32_C(0x004B19B0)))) { return; }
    LIFT_BLOCK(label_000B19B2, UINT32_C(0x004B19B2));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DE8, UINT32_C(0x004F2DE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    goto label_000B1950;
}

void LIFT_CDECL sfera_sub_004F2DF0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2DF0, UINT32_C(0x004F2DF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    goto label_000B1320;
}

void LIFT_CDECL sfera_sub_004F2DF8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2DF8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2DF8, UINT32_C(0x004F2DF8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2E09));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B420)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2E20(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2E20, UINT32_C(0x004F2E20));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_000B1320;
}

void LIFT_CDECL sfera_sub_004F2E28(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E28;
    LIFT_BLOCK(label_000B1950, UINT32_C(0x004B1950));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F2DB8)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    LIFT_PUSH3(cpu->eax, cpu->ecx, cpu->esi);
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x0000000C))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000008), cpu->esi);
    LIFT_STORE32(cpu->esp + UINT32_C(0x00000014), UINT32_C(0x00000000));
    LIFT_IMPORT_CALL(sfera_import_378_MSVCP100_dll__uncaught_exception_std__YA_NXZ, UINT32_C(0x004B1980), UINT32_C(0x004B1986));
    LIFT_TEST((cpu->eax & UINT32_C(0xFF)), 8u);
    LIFT_JNZ(label_000B1992, UINT32_C(0x004B198A));
    LIFT_LOAD32(cpu->ecx, cpu->esi);
    sfera_import_379_MSVCP100_dll___Osfx___basic_ostream_DU__char_traits_D_std___std__QAEXXZ(cpu, lift_image_va(UINT32_C(0x004B198C)));
    cpu->eip = lift_image_va(UINT32_C(0x004B1992));
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
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B19B2)), lift_image_va(UINT32_C(0x004B19B0)))) { return; }
    LIFT_BLOCK(label_000B19B2, UINT32_C(0x004B19B2));
    LIFT_LOAD32(cpu->ecx, cpu->esp + UINT32_C(0x0000000C));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000010));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2E28, UINT32_C(0x004F2E28));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_000B1950;
}

void LIFT_CDECL sfera_sub_004F2E30(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2E30, UINT32_C(0x004F2E30));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    goto label_000B1320;
}

void LIFT_CDECL sfera_sub_004F2E38(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E38;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2E38, UINT32_C(0x004F2E38));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2E49));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B490)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2E60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E60;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2E60, UINT32_C(0x004F2E60));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2E71));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B510)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2E80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2E80));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2E88(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2E88;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2E88, UINT32_C(0x004F2E88));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2E99));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2EA6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B53C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2EB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2EB0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2EB8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EB8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2EB8, UINT32_C(0x004F2EB8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFCC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2EC9));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2ED6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B568)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2EE0(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2EE0, UINT32_C(0x004F2EE0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    goto label_000B1320;
}

void LIFT_CDECL sfera_sub_004F2EE8(LiftCpu* cpu, uint32_t stop_address) {
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
    LIFT_TAIL_INDIRECT((uint32_t)(cpu->eax), lift_image_va(UINT32_C(0x004B1336)));
    LIFT_BLOCK(label_000B1338, UINT32_C(0x004B1338));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F2EE8, UINT32_C(0x004F2EE8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFDC))));
    goto label_000B1320;
}

void LIFT_CDECL sfera_sub_004F2EF0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2EF0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2EF0, UINT32_C(0x004F2EF0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2F01));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B5D0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2F10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F10));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2F18(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F18));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2F20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2F20;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2F20, UINT32_C(0x004F2F20));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2F31));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2F3E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B60C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F50));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2F58(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F58));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2F60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2F60;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2F60, UINT32_C(0x004F2F60));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF9C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2F71));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2F7E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B648)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2F90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2F90));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2F98(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2F98;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2F98, UINT32_C(0x004F2F98));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFBC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2FA9));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2FB6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B674)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2FC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2FC0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F2FC8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F2FC8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F2FC8, UINT32_C(0x004F2FC8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2FD9));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000004), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F2FE6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B6A0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F2FF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F2FF0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F300C, UINT32_C(0x004F2FFC));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000060), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_RETURN(sfera_import_364_MSVCP100_dll___1__basic_ios_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3006));
    LIFT_BLOCK(label_000F300C, UINT32_C(0x004F300C));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F300D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F300D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_RETURN(sfera_import_363_MSVCP100_dll___1__basic_ostream_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3013));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3019(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3019));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_IMPORT_RETURN(sfera_import_387_MSVCP100_dll___1__basic_streambuf_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F301C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3022(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3022;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3022, UINT32_C(0x004F3022));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3033));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B6DC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3040));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_SUB(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_RETURN(sfera_import_363_MSVCP100_dll___1__basic_ostream_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3046));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F304C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F304C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_IMPORT_RETURN(sfera_import_387_MSVCP100_dll___1__basic_streambuf_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F304F));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3055(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3055;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3055, UINT32_C(0x004F3055));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3066));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B710)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3070));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_IMPORT_RETURN(sfera_import_387_MSVCP100_dll___1__basic_streambuf_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3073));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3079(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3079;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3079, UINT32_C(0x004F3079));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F308A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B73C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F30A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F30A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F30A8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F30A8));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F30B1));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F30B3(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F30CC(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F30CC;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F30CC, UINT32_C(0x004F30CC));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F30DD));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F30EA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B780)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3100(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3119(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3119;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3119, UINT32_C(0x004F3119));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F312A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B7AC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3140(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3140));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF7C))));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F3146));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F314C(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3157(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3157));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F315F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F315F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3167(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3167;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3167, UINT32_C(0x004F3167));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF74))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF70));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F317E));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F318B));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B7F0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F31A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F31A8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F31A8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F31A8, UINT32_C(0x004F31A8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F31B9));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F31C6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B81C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F31D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31D0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000001), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F31EC, UINT32_C(0x004F31DC));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC)))), UINT32_C(0xFFFFFFFE), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFEC))), (uint32_t)(result)););
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000068), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_RETURN(sfera_import_364_MSVCP100_dll___1__basic_ios_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F31E6));
    LIFT_BLOCK(label_000F31EC, UINT32_C(0x004F31EC));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F31ED(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31ED));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000010), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_RETURN(sfera_import_409_MSVCP100_dll___1__basic_istream_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F31F3));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F31F9(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F31F9));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x00000004));
    LIFT_IMPORT_RETURN(sfera_import_387_MSVCP100_dll___1__basic_streambuf_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F31FC));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3202(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3202;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3202, UINT32_C(0x004F3202));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3213));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B858)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3220(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3220));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_SUB(cpu->ecx, UINT32_C(0x00000058), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_RETURN(sfera_import_409_MSVCP100_dll___1__basic_istream_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3226));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F322C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F322C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_IMPORT_RETURN(sfera_import_387_MSVCP100_dll___1__basic_streambuf_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F322F));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3235(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3235;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3235, UINT32_C(0x004F3235));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3246));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B88C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3250(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3250));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F3258(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3258));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F325B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3261(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F326F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F326F;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F326F, UINT32_C(0x004F326F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

void LIFT_CDECL sfera_sub_004F327D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F327D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F328B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F328B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001E4), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3299(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3299));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F329C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F32A2(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F32A2;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F32A2, UINT32_C(0x004F32A2));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F32B3));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B8B0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F32C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32C0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F32C8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32C8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F32D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32D0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F32D8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32D8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F32E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F32E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF74));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F32EC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F32EE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F32EE;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F32EE, UINT32_C(0x004F32EE));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF70))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF6C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3305));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3312));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B90C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3320(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3342(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3342));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F334A(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F334A;
    LIFT_BLOCK(label_000B5320, UINT32_C(0x004B5320));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x00000068))));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004B4CE0, UINT32_C(0x004B532B));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD190)));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x004FD194)));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_410_MSVCP100_dll___Ios_base_dtor_ios_base_std__CAXPAV12__Z, UINT32_C(0x004B533B), UINT32_C(0x004B5341));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F334A, UINT32_C(0x004F334A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEEC))));
    goto label_000B5320;
}

void LIFT_CDECL sfera_sub_004F3355(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3355));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F335D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F335D));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3365(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3365;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3365, UINT32_C(0x004F3365));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFEE0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFEDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F337C));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3389));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B970)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F33A0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F33A0;
    LIFT_BLOCK(label_000B5320, UINT32_C(0x004B5320));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x00000068))));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004B4CE0, UINT32_C(0x004B532B));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD190)));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x004FD194)));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_410_MSVCP100_dll___Ios_base_dtor_ios_base_std__CAXPAV12__Z, UINT32_C(0x004B533B), UINT32_C(0x004B5341));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F33A0, UINT32_C(0x004F33A0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE60))));
    goto label_000B5320;
}

void LIFT_CDECL sfera_sub_004F33AB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33AB));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33B6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33B6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33C1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33C1));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33CC(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33CC));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33D7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33D7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33DF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33DF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33E7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33E7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33EF(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33EF));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F33F7(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F33F7));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3402(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3402));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F340D(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F340D;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F340D, UINT32_C(0x004F340D));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE54))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE50));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3424));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3431));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051B9BC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3440(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3440;
    LIFT_BLOCK(label_000B4A80, UINT32_C(0x004B4A80));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx + UINT32_C(0x00000060))));
    cpu->ecx = (uint32_t)(cpu->esi);
    LIFT_CALL_ENTER(sfera_sub_004B3A40, UINT32_C(0x004B4A8B));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x004FD190)));
    LIFT_STORE32(cpu->esi, cpu->eax);
    LIFT_LOAD32(cpu->ecx, lift_image_va(UINT32_C(0x004FD194)));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_STORE32(cpu->esi, cpu->ecx);
    LIFT_IMPORT_CALL(sfera_import_410_MSVCP100_dll___Ios_base_dtor_ios_base_std__CAXPAV12__Z, UINT32_C(0x004B4A9B), UINT32_C(0x004B4AA1));
    LIFT_SP_ADD(UINT32_C(0x00000004));
    LIFT_EPILOGUE1(0u, cpu->esi);
    LIFT_BLOCK(label_000F3440, UINT32_C(0x004F3440));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE30))));
    goto label_000B4A80;
}

void LIFT_CDECL sfera_sub_004F344B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F344B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3456(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3456));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F345E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F345E));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF2C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3469(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3469));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF10))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3474(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3474));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F347C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F347C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3487(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3487));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F348F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F348F));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF48))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F349A(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F349A));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEF4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F34A5(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F34A5));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F34AD(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34AD;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F34AD, UINT32_C(0x004F34AD));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE08))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE04));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F34C4));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F34D1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BA70)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F34E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F34E0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F34E8(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F34F6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F34F6;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F34F6, UINT32_C(0x004F34F6));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

void LIFT_CDECL sfera_sub_004F3504(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3504));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3512(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3512));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001E4), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3520(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F352E(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3536(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3536;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3536, UINT32_C(0x004F3536));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3547));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BB24)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3560(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3560));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F356B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F356B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3576(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3576));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3581(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3581));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F358C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F358C));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3597(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3597));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F35A2(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35A2));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F35AD(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35AD));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F35B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F35B8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F35B8, UINT32_C(0x004F35B8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE60))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE5C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F35CF));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F35DC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BB80)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F35F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F35F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F35F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3600(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3600;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3600, UINT32_C(0x004F3600));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3611));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F361E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BBF4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3630(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3630));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F3638(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3638));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F363B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3641(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F364F(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F364F;
    LIFT_BLOCK(label_000B3CD0, UINT32_C(0x004B3CD0));
    LIFT_PUSH2(UINT32_C(0xFFFFFFFF), lift_image_va(UINT32_C(0x004F0428)));
    cpu->eax = (uint32_t)(lift_fs_load32(cpu, ((uint32_t)(UINT32_C(0x00000000)))));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_SP_SUB(UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->esi));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x00525490)));
    LIFT_LOGIC(cpu->eax, cpu->esp, ^, 32u, cpu->eax = (uint32_t)(result););
    lift_push32(cpu, (uint32_t)(cpu->eax));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->esp + UINT32_C(0x00000010))));
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->eax));
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
    lift_fs_store32(cpu, ((uint32_t)(UINT32_C(0x00000000))), (uint32_t)(cpu->ecx));
    LIFT_POP2(cpu->ecx, cpu->esi);
    LIFT_SP_ADD(UINT32_C(0x00000014));
    LIFT_RET(0u);
    LIFT_BLOCK(label_000F364F, UINT32_C(0x004F364F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    goto label_000B3CD0;
}

void LIFT_CDECL sfera_sub_004F365D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F365D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001C8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F366B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F366B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001E4), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3679(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3679));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD4));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F367C));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3682(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3690(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3690;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3690, UINT32_C(0x004F3690));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F36A1));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BC18)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F36B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F36B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F36B8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F36B8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F36B8, UINT32_C(0x004F36B8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F36C9));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BC84)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F36E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F36E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F36E9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F36EB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F36EB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F36EB, UINT32_C(0x004F36EB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F36FC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BCB0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3710(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3710));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3719));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F371B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F371B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3724));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F3726(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3726;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3726, UINT32_C(0x004F3726));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3737));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BCE4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3750(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3750));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_SUB(cpu->ecx, UINT32_C(0x00000048), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_IMPORT_RETURN(sfera_import_363_MSVCP100_dll___1__basic_ostream_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3756));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F375C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F375C;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F375C, UINT32_C(0x004F375C));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F376D));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BD10)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3780(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3780));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04DC068C)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04DC068C)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F378E(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F378E));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04DC068C)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04DC068C)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F379C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F379C;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F379C, UINT32_C(0x004F379C));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F37AD));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BD44)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F37C0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F37C0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F37CD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F37D1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F37D1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F37D9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F37D9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F37D9, UINT32_C(0x004F37D9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F37EA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BD78)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3800(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3800));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F380D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3811(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3811));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3819(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3819;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3819, UINT32_C(0x004F3819));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F382A));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BDAC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3840(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3840));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFDA8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F384C));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F384E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F384E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F384E, UINT32_C(0x004F384E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFDA8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFDA4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3865));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3872));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BDD8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3880(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3880));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3889));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F388B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F388B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F388B, UINT32_C(0x004F388B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F389C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BE04)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F38B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F38B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFD94));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F38BC));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F38BE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F38BE;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F38BE, UINT32_C(0x004F38BE));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFD94))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFD90));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F38D5));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F38E2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BE30)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F38F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F38F0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F38F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F38F8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3900(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3900;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3900, UINT32_C(0x004F3900));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3911));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F391E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BE64)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3930(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3930));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3938(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3938));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3940(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3940));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3948(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3948;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3948, UINT32_C(0x004F3948));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3959));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3966));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BEA0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3970(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3970));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0x0000000C));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F397D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3981(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3981;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3981, UINT32_C(0x004F3981));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFDC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3992));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BF00)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F39A0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F39A0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F39AD));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F39B1(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F39B1));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F39B9(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F39B9;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F39B9, UINT32_C(0x004F39B9));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F39CA));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BF68)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F39E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F39E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF54));
    LIFT_LOGIC(cpu->eax, UINT32_C(0x00000002), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_JZ(label_000F39FF, UINT32_C(0x004F39EF));
    LIFT_LOGIC(lift_load32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF54)))), UINT32_C(0xFFFFFFFD), &, 32u, lift_store32(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF54))), (uint32_t)(result)););
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFAC))));
    LIFT_IMPORT_RETURN(sfera_import_364_MSVCP100_dll___1__basic_ios_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F39F9));
    LIFT_BLOCK(label_000F39FF, UINT32_C(0x004F39FF));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3A00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A00));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF64))));
    LIFT_IMPORT_RETURN(sfera_import_363_MSVCP100_dll___1__basic_ostream_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3A06));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3A0C(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A0C));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFF50));
    LIFT_IMPORT_RETURN(sfera_import_387_MSVCP100_dll___1__basic_streambuf_DU__char_traits_D_std___std__UAE_XZ, UINT32_C(0x004F3A12));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3A18(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A18));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF5C))));
    LIFT_TAIL(sfera_sub_004B9200);
}

void LIFT_CDECL sfera_sub_004F3A23(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3A45(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3A45;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3A45, UINT32_C(0x004F3A45));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF54))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF50));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3A5C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BF8C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3A70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A70));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFEB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3A7B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A7B));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFE9C))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3A86(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3A86));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFED4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3A91(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3A91;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3A91, UINT32_C(0x004F3A91));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFE90))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFE8C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3AA8));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3AB5));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051BFF0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3AC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3AC0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3AC8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3AC8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3AC8, UINT32_C(0x004F3AC8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3AD9));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3AE6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C01C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3AF0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3AF0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFCC))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3AF8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3AF8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3AF8, UINT32_C(0x004F3AF8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3B09));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3B16));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C048)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3B20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3B20;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3B20, UINT32_C(0x004F3B20));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3B31));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C0A0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3B40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B40));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004F3B48(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B48));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFF7C));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3B54));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F3B56(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B56));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFF80))));
    LIFT_TAIL(sfera_sub_00406210);
}

void LIFT_CDECL sfera_sub_004F3B5E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3B5E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3B5E, UINT32_C(0x004F3B5E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFF70))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFF6C));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3B75));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3B82));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C0DC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3B90(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3B90));
    cpu->ecx = (uint32_t)(lift_image_va(UINT32_C(0x04F3B188)));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F3B95));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F3B9B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3B9B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3B9B, UINT32_C(0x004F3B9B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3BAC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C108)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3BC0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3BC0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F3BC8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3BC8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x0000019C), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00429AF0);
}

void LIFT_CDECL sfera_sub_004F3BD6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3BD6;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3BD6, UINT32_C(0x004F3BD6));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3BE7));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C13C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3C00(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3C00));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3C09));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F3C0B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3C0B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3C0B, UINT32_C(0x004F3C0B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3C1C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C168)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3C30(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3C30));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3C39));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F3C3B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3C3B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3C3B, UINT32_C(0x004F3C3B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3C4C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C194)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3C60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3C60));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F3C68(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3C76(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3C76;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3C76, UINT32_C(0x004F3C76));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3C87));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C1C8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3CA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3CA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3CA8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3CA8));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB0))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3CB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3CB0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3CB0, UINT32_C(0x004F3CB0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3CC1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3CCE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C1FC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3CE0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3CE0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3CED));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3CF1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3CF1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3CF1, UINT32_C(0x004F3CF1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3D02));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C25C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3D10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3D10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3D1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3D21(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3D21;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3D21, UINT32_C(0x004F3D21));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3D32));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C2BC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3D40(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3D40;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3D40, UINT32_C(0x004F3D40));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3D51));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C314)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3D60(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3D60));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3D6D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3D71(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3D71));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3D7E));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3D82(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3D82;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3D82, UINT32_C(0x004F3D82));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3D93));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C348)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3DA0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3DA0));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3DA8(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3DA8;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3DA8, UINT32_C(0x004F3DA8));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3DB9));
    LIFT_ADD(cpu->eax, UINT32_C(0x0000000C), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3DC6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C374)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3DD0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3DD0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3DD9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F3DDB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3DDB));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F3DE3(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3DF1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3DF1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3DF1, UINT32_C(0x004F3DF1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3E02));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C3B0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3E10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3E10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3E1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3E21(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3E21;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3E21, UINT32_C(0x004F3E21));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3E32));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C410)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3E40(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3E40));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F3E49));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F3E4B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3E4B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3E4B, UINT32_C(0x004F3E4B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3E5C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C43C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3E70(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3E70));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3E78(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3E78;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3E78, UINT32_C(0x004F3E78));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3E89));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3E96));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C468)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3EA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3EA0;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3EA0, UINT32_C(0x004F3EA0));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3EB1));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3EBE));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C494)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3ED0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3ED0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F3ED8(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3EE6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3EE6;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3EE6, UINT32_C(0x004F3EE6));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3EF7));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C4C8)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3F10(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F10));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F1D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3F21(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F21));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F2E));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3F32(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3F32;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3F32, UINT32_C(0x004F3F32));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3F43));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C4FC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3F50(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F50));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F5D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3F61(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3F61;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3F61, UINT32_C(0x004F3F61));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFE8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3F72));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C528)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3F80(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3F80));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFEC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->ecx));
    LIFT_CALL_ENTER(sfera_sub_0042B7D0, UINT32_C(0x004F3F8D));
    LIFT_SP_ADD(UINT32_C(0x00000008));
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F3F91(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3F91;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3F91, UINT32_C(0x004F3F91));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3FA2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C554)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F3FB0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3FB0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F3FB8(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F3FC6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F3FC6));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F3FCE(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F3FCE;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F3FCE, UINT32_C(0x004F3FCE));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3FDF));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F3FEC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C590)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4000(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4000));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFB8))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4008(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4008));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4010(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4010;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4010, UINT32_C(0x004F4010));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFA4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFA0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4021));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F402E));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C5C4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4040(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4040));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4049));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F404B(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F404B;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F404B, UINT32_C(0x004F404B));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F405C));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C5F0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4070(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4070));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F4078(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4078));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000001B8), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004CF160);
}

void LIFT_CDECL sfera_sub_004F4086(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4086));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000260), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4094(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4094;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4094, UINT32_C(0x004F4094));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F40A5));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C62C)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F40B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F40B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F40B9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F40BB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F40BB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F40C4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F40C6(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F40C6));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFCC));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F40CF));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F40D1(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F40D1;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F40D1, UINT32_C(0x004F40D1));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFCC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F40E2));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F40EF));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C668)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4100(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4100;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4100, UINT32_C(0x004F4100));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4111));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C6C0)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4120(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4120));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F4128(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4128;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4128, UINT32_C(0x004F4128));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4139));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C6EC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4150(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4150));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4158(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4158;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4158, UINT32_C(0x004F4158));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFD8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4169));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000008), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4176));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C718)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4180(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4180));
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebp + UINT32_C(0xFFFFFFD4))));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4188(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4188;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4188, UINT32_C(0x004F4188));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFB8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFB4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4199));
    LIFT_ADD(cpu->eax, UINT32_C(0x00000010), 0u, 32u, cpu->eax = (uint32_t)(result););
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFFC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F41A6));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C744)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F41B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41B0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F41B8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41B8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFF0));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F41C6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F41C6;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F41C6, UINT32_C(0x004F41C6));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF4))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFF0));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F41D7));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C778)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F41F0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41F0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_TAIL(sfera_sub_004D37D0);
}

void LIFT_CDECL sfera_sub_004F41F8(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F41F8));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFEC));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000198), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4206(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4206));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F420F));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F4211(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4211));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFE8));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F421A));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F421C(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F421C;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F421C, UINT32_C(0x004F421C));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F422D));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C7BC)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4240(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4240));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4249));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F424B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F424B));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000008));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F4254));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F4256(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4256;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4256, UINT32_C(0x004F4256));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0x0000000C))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4267));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C868)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4280(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4280));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE0));
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4288(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4288));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE4));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F428B));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F4291(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F4291;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F4291, UINT32_C(0x004F4291));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFDC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFD8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F42A2));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C8F4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F42B0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F42B0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F42B9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F42BB(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F42BB;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F42BB, UINT32_C(0x004F42BB));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F42CC));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C920)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F42E0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F42E0));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0x00000004));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F42E9));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F42EB(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F42EB));
    LIFT_LOAD32(cpu->eax, cpu->ebp + UINT32_C(0xFFFFFFF0));
    lift_push32(cpu, (uint32_t)(cpu->eax));
    LIFT_CALL_ENTER(sfera_sub_004EBE20, UINT32_C(0x004F42F4));
    LIFT_EPILOGUE1(0u, cpu->ecx);
}

void LIFT_CDECL sfera_sub_004F42F6(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F42F6;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F42F6, UINT32_C(0x004F42F6));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFF0))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFEC));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F4307));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C954)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4320(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4320));
    LIFT_LOAD32(cpu->eax, lift_image_va(UINT32_C(0x04F4A518)));
    LIFT_LOGIC(cpu->eax, UINT32_C(0xFFFFFFFE), &, 32u, cpu->eax = (uint32_t)(result););
    LIFT_STORE32(lift_image_va(UINT32_C(0x04F4A518)), cpu->eax);
    LIFT_RET(0u);
}

void LIFT_CDECL sfera_sub_004F432E(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F432E;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F432E, UINT32_C(0x004F432E));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFEC))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFE8));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F433F));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C980)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F4350(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4350));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F435B(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F435B));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000054), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4366(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4366));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000070), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F4371(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F4371));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000A0), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

void LIFT_CDECL sfera_sub_004F437F(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F437F));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x000000AC), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_00416610);
}

void LIFT_CDECL sfera_sub_004F438D(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F438D));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD0));
    LIFT_IMPORT_RETURN(sfera_import_399_MSVCP100_dll___1_Container_base12_std__QAE_XZ, UINT32_C(0x004F4390));
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

void LIFT_CDECL sfera_sub_004F4396(LiftCpu* cpu, uint32_t stop_address) {
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

void LIFT_CDECL sfera_sub_004F43A4(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43A4));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFD8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000178), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}

void LIFT_CDECL sfera_sub_004F43B2(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F43B2;
    LIFT_BLOCK(label_000EE936, UINT32_C(0x004EE936));
    LIFT_IMPORT_RETURN(sfera_import_326_MSVCR100_dll___CxxFrameHandler3, UINT32_C(0x004EE936));
    LIFT_BLOCK(label_000F43B2, UINT32_C(0x004F43B2));
    LIFT_LOAD32(cpu->edx, cpu->esp + UINT32_C(0x00000008));
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx + UINT32_C(0xFFFFFFC8))));
    LIFT_LOAD32(cpu->ecx, cpu->edx + UINT32_C(0xFFFFFFC4));
    LIFT_LOGIC(cpu->ecx, cpu->eax, ^, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_CALL_ENTER(sfera_sub_004EE810, UINT32_C(0x004F43C3));
    cpu->eax = (uint32_t)(lift_image_va(UINT32_C(0x0051C9A4)));
    goto label_000EE936;
}

void LIFT_CDECL sfera_sub_004F43D0(LiftCpu* cpu, uint32_t stop_address) {
    LIFT_ENTER(UINT32_C(0x004F43D0));
    LIFT_LOAD32(cpu->ecx, cpu->ebp + UINT32_C(0xFFFFFFE8));
    LIFT_ADD(cpu->ecx, UINT32_C(0x00000008), 0u, 32u, cpu->ecx = (uint32_t)(result););
    LIFT_TAIL(sfera_sub_004061B0);
}
