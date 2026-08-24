#include "lifted_functions.h"
#include "lifted_normalized_ops.h"
#include "semantic_zlib.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004D65B0));
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::SetUnhandledExceptionFilter), LIFT_CODE_TOKEN_VA(0x4D6729u));
    lift_push32(cpu, 0x104u); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]); lift_push32(cpu, 0u);
    g_sfera_crash_report_runtime.previous_exception_filter = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D6740u));
    cpu->edi = native_function_address32(&::lstrcpyA);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D675C;
    lift_push32(cpu, (uintptr_t)"Unknown"); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD675Cu), LIFT_CODE_TOKEN_RVA(0xD675Au))) { return; }
    label_000D675C:
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    label_000D6761:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D6761;
    label_000D6768:
    --cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]))) goto label_000D6778;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6768;
    ++cpu->eax;
    goto label_000D6785;
    label_000D6778:
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6780;
    ++cpu->eax;
    goto label_000D6785;
    label_000D6780:
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    label_000D6785:
    lift_push32(cpu, (uintptr_t)"ERRORLOG.TXT"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD678Du), LIFT_CODE_TOKEN_RVA(0xD678Bu))) { return; }
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4D678Du));
    lift_store32((uintptr_t)&g_sfera_crash_report_runtime.process_handle, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D67E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D67FA;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D67F0:
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D67F0;
    label_000D67FA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D681B;
    label_000D6810:
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6810;
    label_000D681B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) == (uint8_t)(0u)) goto label_000D6830;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D6830:
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D684F;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) != (uint8_t)(0u)) goto label_000D6871;
    label_000D6841:
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) == (uint8_t)(0u)) goto label_000D6841;
    lift_store32(cpu->eax, cpu->edx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D684F:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6869;
    label_000D6858:
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D6869;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6858;
    label_000D6869:
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) != (uint8_t)(0u)) goto label_000D6873;
    label_000D6871:
    lift_store32(cpu->eax, cpu->edx);
    label_000D6873:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6880(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x454u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x468u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x478u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x47Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"textures\\cursors"); lift_push32(cpu, (uintptr_t)"%s\\%s.bmp");
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, 0x400u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4D68E2u));
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store8(cpu->esp + 0x463u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D68FCu)); sfera_sub_00422A20(cpu, LIFT_CODE_TOKEN_VA(0x4D68FCu));
    cpu->edi = cpu->eax;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000D690E;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateCursor(): failed to load cursor image from file";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD690Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD690Eu));
    label_000D690E:
    if ((uint32_t)(lift_load32(cpu->edi + 4u)) != (uint32_t)(0x20u)) goto label_000D6920;
    if ((uint32_t)(lift_load32(cpu->edi + 8u)) != (uint32_t)(0x20u)) goto label_000D6920;
    if ((uint32_t)(lift_load32(cpu->edi + 0xCu)) == (uint32_t)(0x20u)) goto label_000D692A;
    label_000D6920:
    cpu->ecx = (uint32_t)(uintptr_t)"CreateCursor(): invalid cursor image format";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD692Au)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD692Au));
    label_000D692A:
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetDC), LIFT_CODE_TOKEN_VA(0x4D692Fu));
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000D6949;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CWindowDC::CWindowDC(): failed to retrieve DC";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD6949u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD6949u));
    label_000D6949:
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x474u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleDC), LIFT_CODE_TOKEN_VA(0x4D6951u));
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x60u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_000D696B;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CMemoryDC::CMemoryDC(): failed to create DC";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD696Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD696Bu));
    label_000D696B:
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0x484u, 1u);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CreateBitmap), LIFT_CODE_TOKEN_VA(0x4D698Cu));
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000D69A6;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CBitmap::CBitmap(): failed to create bitmap";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD69A6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD69A6u));
    label_000D69A6:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 2u);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D69B4u));
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetObjectType), LIFT_CODE_TOKEN_VA(0x4D69BFu));
    cpu->eax -= 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    --cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->eax)) goto label_000D69DF;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CObjectSelector::CObjectSelector(): failed to select object";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD69DFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD69DFu));
    label_000D69DF:
    cpu->ebx = 0u;
    lift_store8(cpu->esp + 0x470u, 3u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D6A29;
    label_000D69ED:
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) <= (uint32_t)(cpu->esi)) goto label_000D6A22;
    label_000D69F5:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D69FEu)); sfera_sub_004229F0(cpu, LIFT_CODE_TOKEN_VA(0x4D69FEu));
    cpu->eax &= 0xFF000000u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFF000001u;
    cpu->eax += 0xFFFFFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SetPixel), LIFT_CODE_TOKEN_VA(0x4D6A15u));
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000D69F5;
    label_000D6A22:
    ++cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000D69ED;
    label_000D6A29:
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 2u);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D6A37u));
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleBitmap), LIFT_CODE_TOKEN_VA(0x4D6A56u));
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D6A70;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CBitmap::CBitmap(): failed to create bitmap";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD6A70u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD6A70u));
    label_000D6A70:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 4u);
    lift_store32(cpu->esp + 0x60u, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D6A7Eu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x60u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetObjectType), LIFT_CODE_TOKEN_VA(0x4D6A8Bu));
    cpu->eax -= 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    --cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_000D6AA9;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CObjectSelector::CObjectSelector(): failed to select object";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD6AA9u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD6AA9u));
    label_000D6AA9:
    cpu->ebx = 0u;
    lift_store8(cpu->esp + 0x470u, 5u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) <= (uint32_t)(cpu->ebx)) goto label_000D6AEB;
    label_000D6AB9:
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) <= (uint32_t)(cpu->esi)) goto label_000D6AE0;
    label_000D6AC1:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6ACAu)); sfera_sub_004229F0(cpu, LIFT_CODE_TOKEN_VA(0x4D6ACAu));
    cpu->eax &= 0xFFFFFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SetPixel), LIFT_CODE_TOKEN_VA(0x4D6AD3u));
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000D6AC1;
    label_000D6AE0:
    ++cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000D6AB9;
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    label_000D6AEB:
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 4u);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D6AF9u));
    cpu->edx = 0x3Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorImageManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6B0Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D6B0Eu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6B15u)); sfera_sub_004229D0(cpu, LIFT_CODE_TOKEN_VA(0x4D6B15u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6B1Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D6B1Bu));
    cpu->edi = 0u;
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x480u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D6B44;
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    goto label_000D6B4C;
    label_000D6B44:
    lift_store32(cpu->esp + 0x48u, cpu->edi);
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    label_000D6B4C:
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CreateIconIndirect), LIFT_CODE_TOKEN_VA(0x4D6B5Du));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edi)) goto label_000D6B73;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateCursor(): failed to create cursor";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD6B73u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD6B73u));
    label_000D6B73:
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::DeleteObject);
    lift_store32(cpu->edi, cpu->ebx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6B90u), LIFT_CODE_TOKEN_RVA(0xD6B8Eu))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6B97u), LIFT_CODE_TOKEN_RVA(0xD6B95u))) { return; }
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_VA(0x4D6B98u));
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_VA(0x4D6BA5u));
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x468u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x460u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C2A;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C0D;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C0A;
    label_000D6C00:
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6C00;
    label_000D6C0A:
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D6C0D:
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C28;
    label_000D6C16:
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D6C28;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6C16;
    label_000D6C28:
    lift_store32(cpu->eax, cpu->edx);
    label_000D6C2A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)(0u)) goto label_000D6C48;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000D6C48:
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000D6C62;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D6C62:
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000D6C73;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D6C73:
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)(0u)) goto label_000D6C98;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000D6C98:
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000D6CB3;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D6CB3:
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_000D6CC7;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D6CC7:
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6CE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D6D5D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D6D00:
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D6D0E;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_000D6D10;
    label_000D6D0E:
    cpu->edx = cpu->ebp;
    label_000D6D10:
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000D6D19;
    label_000D6D19:
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000D6D21;
    cpu->ecx = cpu->ebx;
    label_000D6D21:
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000D6D29;
    cpu->eax = lift_load32(cpu->eax);
    label_000D6D29:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6D31u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4D6D31u));
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D6D43;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000D6D45;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000D6D43:
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D6D4A;
    label_000D6D45:
    cpu->edi = lift_load32(cpu->edi + 8u);
    goto label_000D6D50;
    label_000D6D4A:
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi = lift_load32(cpu->edi);
    label_000D6D50:
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)(0u)) goto label_000D6D00;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D6D5D:
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6D70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6D7Fu)); sfera_sub_004D6CE0(cpu, LIFT_CODE_TOKEN_VA(0x4D6D7Fu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D6DBB;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000D6D96;
    cpu->eax = lift_load32(cpu->eax);
    label_000D6D96:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6DA5u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x4D6DA5u));
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D6DBB;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D6DBB:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x6666665u)) goto label_000D6E25;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) < (uint32_t)(0x10u)) goto label_000D6E02;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6DFFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D6DFFu));
    cpu->esp += 4u;
    label_000D6E02:
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D6E17u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D6E17u));
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D6E02u), "std::length_error");
    label_000D6E25:
    ++cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000D6E4E;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_000D6E6F;
    label_000D6E4E:
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6E61;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D6E6F;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_000D6E6F;
    label_000D6E61:
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D6E6F;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_000D6E6F:
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D700D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_000D6E80:
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_000D6F4F;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6EB2;
    lift_store8(cpu->edx + 0x34u, 1u);
    lift_store8(cpu->esi + 0x34u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000D7000;
    label_000D6EB2:
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D6EF1;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6ECB;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000D6ECB:
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D6EDE;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_000D6EEC;
    label_000D6EDE:
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_000D6EE9;
    lift_store32(cpu->esi, cpu->edx);
    goto label_000D6EEC;
    label_000D6EE9:
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_000D6EEC:
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_000D6EF1:
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x34u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6F19;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_000D6F19:
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D6F32;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FFD;
    label_000D6F32:
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000D6F45;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FFD;
    label_000D6F45:
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FFD;
    label_000D6F4F:
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6F72;
    lift_store8(cpu->edx + 0x34u, 1u);
    lift_store8(cpu->esi + 0x34u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000D7000;
    label_000D6F72:
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D6FB2;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6F8A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000D6F8A:
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D6F9D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_000D6FAC;
    label_000D6F9D:
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000D6FAA;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FAC;
    label_000D6FAA:
    lift_store32(cpu->esi, cpu->edx);
    label_000D6FAC:
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_000D6FB2:
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x34u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6FDA;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_000D6FDA:
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D6FED;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_000D6FFB;
    label_000D6FED:
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000D6FF8;
    lift_store32(cpu->edi, cpu->esi);
    goto label_000D6FFB;
    label_000D6FF8:
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_000D6FFB:
    lift_store32(cpu->esi, cpu->edx);
    label_000D6FFD:
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_000D7000:
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6E80;
    cpu->edi = lift_pop32(cpu);
    label_000D700D:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x34u, 1u);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7030(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D704D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4D7030u), "std::out_of_range");
    label_000D704D:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D705Bu)); sfera_sub_004D6BE0(cpu, LIFT_CODE_TOKEN_VA(0x4D705Bu));
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) == (uint8_t)(0u)) goto label_000D7069;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    goto label_000D7081;
    label_000D7069:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7076;
    cpu->edi = cpu->ecx;
    goto label_000D7081;
    label_000D7076:
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_000D70E4;
    label_000D7081:
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D708D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000D708D:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebp)) goto label_000D709A;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_000D70A5;
    label_000D709A:
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebp)) goto label_000D70A2;
    lift_store32(cpu->esi, cpu->edi);
    goto label_000D70A5;
    label_000D70A2:
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_000D70A5:
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->ebp)) goto label_000D70BF;
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)(0u)) goto label_000D70B6;
    cpu->eax = cpu->esi;
    goto label_000D70BD;
    label_000D70B6:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD70BDu)); sfera_sub_004D67E0(cpu, LIFT_CODE_TOKEN_RVA(0xD70BDu));
    label_000D70BD:
    lift_store32(cpu->ebx, cpu->eax);
    label_000D70BF:
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->ebp)) goto label_000D713C;
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)(0u)) goto label_000D70D8;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_000D713C;
    label_000D70D8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D70DFu)); sfera_sub_004D6800(cpu, LIFT_CODE_TOKEN_VA(0x4D70DFu));
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_000D713C;
    label_000D70E4:
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_000D70F5;
    cpu->esi = cpu->eax;
    goto label_000D710F;
    label_000D70F5:
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D7101;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000D7101:
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_000D710F:
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebp)) goto label_000D711C;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_000D712A;
    label_000D711C:
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebp)) goto label_000D7127;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000D712A;
    label_000D7127:
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_000D712A:
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x34u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x34u)) & 0xFFu);
    lift_store8(cpu->eax + 0x34u, cpu->edx & 0xFFu);
    lift_store8(cpu->ebp + 0x34u, cpu->ecx & 0xFFu);
    label_000D713C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7246;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_000D7243;
    label_000D7157:
    if ((uint8_t)(lift_load8(cpu->edi + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7243;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000D71CD;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x34u)) != (uint8_t)(0u)) goto label_000D7183;
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x34u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D717Cu)); sfera_sub_004D6C30(cpu, LIFT_CODE_TOKEN_VA(0x4D717Cu));
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D7183:
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D71FF;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7198;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D71FB;
    label_000D7198:
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D71B6;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x34u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D71AFu)); sfera_sub_004D6C80(cpu, LIFT_CODE_TOKEN_VA(0x4D71AFu));
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D71B6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x34u)) & 0xFFu);
    lift_store8(cpu->eax + 0x34u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x34u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D71CBu)); sfera_sub_004D6C30(cpu, LIFT_CODE_TOKEN_VA(0x4D71CBu));
    goto label_000D7243;
    label_000D71CD:
    if ((uint8_t)(lift_load8(cpu->eax + 0x34u)) != (uint8_t)(0u)) goto label_000D71E6;
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x34u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D71E0u)); sfera_sub_004D6C80(cpu, LIFT_CODE_TOKEN_VA(0x4D71E0u));
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D71E6:
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D71FF;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7212;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7212;
    label_000D71FB:
    lift_store8(cpu->eax + 0x34u, 0u);
    label_000D71FF:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_000D7157;
    goto label_000D7243;
    label_000D7212:
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D722F;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x34u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7229u)); sfera_sub_004D6C30(cpu, LIFT_CODE_TOKEN_VA(0x4D7229u));
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D722F:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x34u)) & 0xFFu);
    lift_store8(cpu->eax + 0x34u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x34u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD7243u)); sfera_sub_004D6C80(cpu, LIFT_CODE_TOKEN_RVA(0xD7243u));
    label_000D7243:
    lift_store8(cpu->edi + 0x34u, cpu->ebx & 0xFFu);
    label_000D7246:
    if ((uint32_t)(lift_load32(cpu->ebp + 0x20u)) < (uint32_t)(0x10u)) goto label_000D7258;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7255u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D7255u));
    cpu->esp += 4u;
    label_000D7258:
    lift_store32(cpu->ebp + 0x20u, 0xFu);
    lift_store32(cpu->ebp + 0x1Cu, 0u);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->ebp + 0xCu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7270u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D7270u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D7285;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_000D7285:
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D72A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D72EF;
    label_000D72B3:
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D72BEu)); sfera_sub_004D72A0(cpu, LIFT_CODE_TOKEN_VA(0x4D72BEu));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D72D2;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D72CFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D72CFu));
    cpu->esp += 4u;
    label_000D72D2:
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D72E5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D72E5u));
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D72B3;
    label_000D72EF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D73FC;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D7330:
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D7392;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_000D7349;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_000D734B;
    label_000D7349:
    cpu->edx = cpu->ebp;
    label_000D734B:
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000D7354;
    label_000D7354:
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_000D735F;
    cpu->ecx = cpu->edi;
    label_000D735F:
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000D7367;
    cpu->eax = lift_load32(cpu->eax);
    label_000D7367:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D736Fu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4D736Fu));
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D738D;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_000D7384;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000D73DB;
    label_000D7384:
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000D738D:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000D73DB;
    label_000D7392:
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D739D;
    cpu->eax = lift_load32(cpu->eax);
    label_000D739D:
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_000D73AA;
    cpu->edx = cpu->edi;
    label_000D73AA:
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_000D73B5;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_000D73B7;
    label_000D73B5:
    cpu->ecx = cpu->ebp;
    label_000D73B7:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D73BFu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4D73BFu));
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D73D8;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_000D73CF;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_000D73D6;
    label_000D73CF:
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_000D73D6:
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000D73D8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000D73DB:
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000D73E7;
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_000D73EA;
    label_000D73E7:
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_000D73EA:
    if ((uint8_t)(lift_load8(cpu->ebx + 0x35u)) == (uint8_t)(0u)) goto label_000D7330;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_000D73FC:
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000D7442;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000D7435;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    label_000D741A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D741Fu)); sfera_sub_004D6DE0(cpu, LIFT_CODE_TOKEN_VA(0x4D741Fu));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D7435:
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D743Eu)); sfera_sub_004D6820(cpu, LIFT_CODE_TOKEN_VA(0x4D743Eu));
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_000D7442:
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ebx = 0x10u;
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000D7457;
    cpu->eax = lift_load32(cpu->ebp);
    goto label_000D7459;
    label_000D7457:
    cpu->eax = cpu->ebp;
    label_000D7459:
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7466u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x4D7466u));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D7480;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    goto label_000D741A;
    label_000D7480:
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000D7491;
    cpu->edx = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D748Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D748Eu));
    cpu->esp += 4u;
    label_000D7491:
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->ebp + 0x14u, 0xFu);
    lift_store32(cpu->ebp + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D74ADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D74ADu));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D74D0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7504u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D7504u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_000D7596;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esi = (uint32_t)(cpu->edi + 0xCu);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    lift_store16(cpu->edi + 0x34u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esi);
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000D756B;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7559u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4D7559u));
    cpu->edx = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebx + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    label_000D756B:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D7596:
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D75BBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D75BBu));
    lift_trap(cpu, 0x4D75BBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7581(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D758Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D758Au));
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7596u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D7596u));
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D75BBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D75BBu));
    lift_trap(cpu, 0x4D75BBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D75C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x88u);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x8Cu);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(4u)) goto label_000D761C;
    cpu->esi = sfera_cursor_texture_name(cpu->ecx);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000D7629;
    label_000D761C:
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    lift_store32(cpu->eax + 8u, cpu->ebx);
    goto label_000D776C;
    label_000D7629:
    cpu->eax = cpu->esi;
    lift_store32(cpu->esp + 0x44u, 0xFu);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store8(cpu->esp + 0x30u, cpu->ebx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000D7640:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7640;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7654u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4D7654u));
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x88u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D766Cu)); sfera_sub_004D6D70(cpu, LIFT_CODE_TOKEN_VA(0x4D766Cu));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x44u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x80u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D768D;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D768Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D768Au));
    cpu->esp += 4u;
    label_000D768D:
    lift_store32(cpu->esp + 0x44u, 0xFu);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store8(cpu->esp + 0x30u, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D7757;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = sfera_cursor_texture_name(cpu->eax);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)(0x5Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D76C5u)); sfera_sub_004D6880(cpu, LIFT_CODE_TOKEN_VA(0x4D76C5u));
    cpu->eax = cpu->esi;
    lift_store32(cpu->esp + 0x60u, 0xFu);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D76E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D76E0;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D76F4u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4D76F4u));
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x68u, cpu->esi);
    lift_store32(cpu->esp + 0x6Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x70u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x88u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7724u)); sfera_sub_004D74D0(cpu, LIFT_CODE_TOKEN_VA(0x4D7724u));
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7731u)); sfera_sub_004D7300(cpu, LIFT_CODE_TOKEN_VA(0x4D7731u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x60u)) < (uint32_t)(0x10u)) goto label_000D7745;
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7742u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D7742u));
    cpu->esp += 4u;
    label_000D7745:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    goto label_000D776C;
    label_000D7757:
    cpu->edx = lift_load32(cpu->ebp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0x2Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    label_000D776C:
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D77A2u)); sfera_sub_004D75C0(cpu, LIFT_CODE_TOKEN_VA(0x4D77A2u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D77B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D77C2u)); sfera_sub_004D75C0(cpu, LIFT_CODE_TOKEN_VA(0x4D77C2u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D77E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_000D782A;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_000D782A;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7802u)); sfera_sub_004D72A0(cpu, LIFT_CODE_TOKEN_VA(0x4D7802u));
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
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000D782A:
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000D789F;
    cpu->edi = cpu->edi;
    label_000D7830:
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D7888;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D7860;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D785A;
    label_000D7850:
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7850;
    label_000D785A:
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000D7888;
    label_000D7860:
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D7884;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D7870:
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000D7884;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7870;
    label_000D7884:
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000D7888:
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7895u)); sfera_sub_004D7030(cpu, LIFT_CODE_TOKEN_VA(0x4D7895u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000D7830;
    label_000D789F:
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x38u);
    lift_store32(cpu->esi + 8u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7994u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D7994u));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D79C1;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->ecx + 0x34u, cpu->eax & 0xFFu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store8(cpu->edx + 0x35u, cpu->eax & 0xFFu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D79C1:
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 8u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D79EFu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4D79EFu));
    lift_trap(cpu, 0x4D79EFu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D79F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0xAu;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7A23u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7A23u));
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7A2Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D7A2Au));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D7A46;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7A44u)); sfera_sub_004D7F70(cpu, LIFT_CODE_TOKEN_VA(0x4D7A44u));
    goto label_000D7A48;
    label_000D7A46:
    cpu->eax = 0u;
    label_000D7A48:
    cpu->edx = 0xBu;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_store32(cpu->esi, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7A61u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7A61u));
    lift_push32(cpu, 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7A68u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4D7A68u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D7A84;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7A82u)); sfera_sub_004D7BF0(cpu, LIFT_CODE_TOKEN_VA(0x4D7A82u));
    goto label_000D7A86;
    label_000D7A84:
    cpu->eax = 0u;
    label_000D7A86:
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D7B00;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_000D7B08;
    label_000D7B00:
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000D7B31;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    label_000D7B08:
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000D7B31;
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<CCursor*>(cpu->ecx)->copyStateFrom(cpu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D7B27;
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->deactivate(cpu);
    label_000D7B27:
    cpu->ecx = lift_load32(cpu->esi + 8u);
    reinterpret_cast<CCursor*>(cpu->ecx)->activate(cpu);
    label_000D7B31:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x24u)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x10u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7BD2;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000D7BC7;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_000D7BC7;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->ecx = g_sfera_window_runtime.main_window;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x4D7BA0u));
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    ++cpu->ecx;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    goto label_000D7BC9;
    label_000D7BC7:
    lift_push32(cpu, 0u);
    label_000D7BC9:
    lift_native_call(cpu, native_function_address32(&::ClipCursor), LIFT_CODE_TOKEN_VA(0x4D7BC9u));
    lift_store8(cpu->esi + 0x10u, cpu->ebx & 0xFFu);
    label_000D7BD2:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7BF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    std::construct_at(reinterpret_cast<CHardwareCursor*>(cpu->esi));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_store8(cpu->esi + 0x10u, cpu->eax & 0xFFu);
    lift_store32(cpu->esi + 0x14u, 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7C3Cu)); sfera_sub_0044C0D0(cpu, LIFT_CODE_TOKEN_VA(0x4D7C3Cu));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D7C82;
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->isSystemCursorVisible(cpu);
    lift_store8(cpu->esi + 0x11u, cpu->eax & 0xFFu);
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->cursorKind(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->getPosition(cpu);
    goto label_000D7C9B;
    label_000D7C82:
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esi + 0x11u, 1u);
    lift_store32(cpu->esi + 0x14u, 0xFFu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->getPosition(cpu);
    label_000D7C9B:
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7CB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load8(cpu->esi + 0x11u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->setSystemCursorVisible(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->setCursorKind(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);

    cpu->edx = lift_load32(cpu->esi + 0x18u);

    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->setPosition(cpu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7CF0(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_0044C0D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetCursor), LIFT_CODE_TOKEN_VA(0x4D7D04u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7D10(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_000D7D38;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::GetCursorPos), LIFT_CODE_TOKEN_VA(0x4D7D1Fu));
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::ScreenToClient), LIFT_CODE_TOKEN_VA(0x4D7D2Cu));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D7D38:
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->eax = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_000D7D9A;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp);
    lift_store32(cpu->esp, cpu->eax);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x4D7D85u));
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::SetCursorPos), LIFT_CODE_TOKEN_RVA(0xD7D94u));
    label_000D7D9A:
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000D7DC0;
    cpu->eax = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x5Fu)) goto label_000D7DC0;
    cpu->eax = 1u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7DBFu)); sfera_sub_004D7B50(cpu, LIFT_CODE_TOKEN_VA(0x4D7DBFu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D7DC0:
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7DC8u)); sfera_sub_004D7B50(cpu, LIFT_CODE_TOKEN_VA(0x4D7DC8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;

    cpu->edx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<CHardwareCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eax = lift_load32(cpu->esp);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D7E06;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_width)) goto label_000D7E06;
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D7E06;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_height)) goto label_000D7E06;
    cpu->eax = 1u;
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D7E06:
    cpu->eax = 0u;
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::ShowCursor);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD7E1Bu), LIFT_CODE_TOKEN_RVA(0xD7E19u))) { return; }
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD7E1Fu), LIFT_CODE_TOKEN_RVA(0xD7E1Du))) { return; }
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E30(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint8_t)(lift_load8(cpu->esp + 4u)) == (uint8_t)(0u)) goto label_000D7E3F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7E3Cu)); sfera_sub_0044C0F0(cpu, LIFT_CODE_TOKEN_VA(0x4D7E3Cu));
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D7E3F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7E44u)); sfera_sub_0044C0D0(cpu, LIFT_CODE_TOKEN_VA(0x4D7E44u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    cpu->ebx = 1u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000D7EA8;
    cpu->eax = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x5Fu)) goto label_000D7EA8;
    cpu->eax = cpu->ebx;
    goto label_000D7EAA;
    label_000D7EA8:
    cpu->eax = 0u;
    label_000D7EAA:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7EB0u)); sfera_sub_004D7B50(cpu, LIFT_CODE_TOKEN_VA(0x4D7EB0u));
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_texture_registry_guard)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_000D7EE5;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry_guard, (uint64_t)(g_sfera_cursor_texture_registry_guard) | (uint64_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7ED0u)); sfera_sub_004D7980(cpu, LIFT_CODE_TOKEN_VA(0x4D7ED0u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7EDAu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7EDAu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    label_000D7EE5:
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7EF3u)); sfera_sub_004D7790(cpu, LIFT_CODE_TOKEN_VA(0x4D7EF3u));

    lift_store32(cpu->esi + 0xCu, cpu->eax);

    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->apply(cpu);
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_texture_registry_guard)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_000D7F30;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry_guard, (uint64_t)(g_sfera_cursor_texture_registry_guard) | (uint64_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7F1Bu)); sfera_sub_004D7980(cpu, LIFT_CODE_TOKEN_VA(0x4D7F1Bu));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0D0));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7F25u)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7F25u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    label_000D7F30:
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7F43u)); sfera_sub_004D77B0(cpu, LIFT_CODE_TOKEN_VA(0x4D7F43u));
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7F70(LiftCpu* cpu, uint32_t stop_address) {
    lift_store32(cpu->ecx + 4u, 0u);
    lift_store32(cpu->ecx + 8u, 0u);
    std::construct_at(reinterpret_cast<CSoftwareCursor*>(cpu->ecx));
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx + 0xCu, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    lift_store8(cpu->ecx + 0x14u, 0u);
    cpu->eax = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D7FF8;
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->isSystemCursorVisible(cpu);
    lift_store8(cpu->edi + 0x15u, cpu->eax & 0xFFu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->cursorKind(cpu);
    lift_store32(cpu->edi + 0x18u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->getPosition(cpu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->edi + 0x1Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edi + 0x20u, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D7FF8:
    lift_store8(cpu->edi + 0x15u, 1u);
    lift_store32(cpu->edi + 0x18u, 0xFFu);
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->edi + 0x1Cu, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.display_height;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store32(cpu->edi + 0x20u, cpu->eax);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8040u), LIFT_CODE_TOKEN_RVA(0xD803Eu))) { return; }
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 5u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x34u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8056u), LIFT_CODE_TOKEN_RVA(0xD8054u))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8064;
    cpu->ecx = (uint32_t)(uintptr_t)"CSoftwareCursor::Activate(): SetCooperativeLevel() failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD8064u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD8064u));
    label_000D8064:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8071u), LIFT_CODE_TOKEN_RVA(0xD806Fu))) { return; }
    cpu->ecx = lift_load8(cpu->esi + 0x15u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setSystemCursorVisible(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setCursorKind(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);

    cpu->edx = lift_load32(cpu->esi + 0x1Cu);

    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setPosition(cpu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D80A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD80B0u), LIFT_CODE_TOKEN_RVA(0xD80AEu))) { return; }
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x34u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD80C6u), LIFT_CODE_TOKEN_RVA(0xD80C4u))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D80D4;
    cpu->ecx = (uint32_t)(uintptr_t)"CSoftwareCursor::Deactivate(): SetCooperativeLevel() failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD80D4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD80D4u));
    label_000D80D4:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD80E1u), LIFT_CODE_TOKEN_RVA(0xD80DFu))) { return; }

    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setSystemCursorVisible(cpu);

    lift_push32(cpu, 0xFFu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setCursorKind(cpu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8100(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x14u)) == (uint8_t)(0u)) goto label_000D8131;
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D811Au)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4D811Au));
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D812Eu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4D812Eu));
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000D8131:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0xCu, cpu->eax);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x14u)) == (uint8_t)(0u)) goto label_000D8264;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D81C1;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    --cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->ecx)) goto label_000D81C1;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D81C1;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(cpu->edx)) goto label_000D81C1;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) != (uint32_t)(0u)) goto label_000D82C6;
    label_000D81C1:

    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->cursorKind(cpu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000D81DB;
    cpu->eax = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Fu)) goto label_000D8220;
    label_000D81DB:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD81E8u), LIFT_CODE_TOKEN_RVA(0xD81E6u))) { return; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D81EDu)); sfera_sub_0044C0F0(cpu, LIFT_CODE_TOKEN_VA(0x4D81EDu));
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x4D8206u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::SetCursorPos), LIFT_CODE_TOKEN_VA(0x4D8216u));
    lift_store8(cpu->esi + 0x14u, 0u);
    label_000D8220:
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D8230;
    lift_store32(cpu->esi + 0xCu, 0u);
    goto label_000D823E;
    label_000D8230:
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    --cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D823E;
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    label_000D823E:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D8251;
    lift_store32(cpu->esi + 0x10u, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D8251:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    --cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D82C6;
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D8264:
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetCursorPos), LIFT_CODE_TOKEN_VA(0x4D8269u));
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::ScreenToClient), LIFT_CODE_TOKEN_VA(0x4D827Bu));
    cpu->ecx = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_000D82C6;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_width)) goto label_000D82C6;
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D82C6;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_height)) goto label_000D82C6;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_000D82C6;
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D82B5u)); sfera_sub_0044C0D0(cpu, LIFT_CODE_TOKEN_VA(0x4D82B5u));
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD82C2u), LIFT_CODE_TOKEN_RVA(0xD82C0u))) { return; }
    lift_store8(cpu->esi + 0x14u, 1u);
    label_000D82C6:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D82D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 0x14u)) & 0xFFu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D82E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000D82E0;
    label_000B84A0:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B84AC;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B84AC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D82E0:
    goto label_000B84A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D82F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 4u)) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D82F9u)); sfera_sub_004B8490(cpu, LIFT_CODE_TOKEN_VA(0x4D82F9u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8300(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000D8300;
    label_000B8410:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B841E;
    cpu->eax = lift_load8(cpu->eax + 8u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B841E:
    cpu->eax = 0xFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000D8300:
    goto label_000B8410;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8310(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D831Fu)); sfera_sub_004B83D0(cpu, LIFT_CODE_TOKEN_VA(0x4D831Fu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8326u)); sfera_sub_004B8430(cpu, LIFT_CODE_TOKEN_VA(0x4D8326u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8340(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 4u)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<CCursor*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D8359;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8356u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D8356u));
    cpu->esp += 4u;
    label_000D8359:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 0x1D8u)) & 0xFFu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0xCu, 0x15u);
    lift_store32(cpu->esp + 0x10u, 0x14u);
    lift_store32(cpu->esp + 0x14u, 0x1Du);
    lift_store32(cpu->esp + 0x18u, 0x18u);
    lift_store32(cpu->esp + 0x1Cu, 0x19u);
    lift_store32(cpu->esp + 0x20u, 0x1Eu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(1u)) goto label_000D83D6;
    cpu->edx = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x24u);
    goto label_000D83E6;
    label_000D83D6:
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x24u);
    label_000D83E6:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD83E8u), LIFT_CODE_TOKEN_RVA(0xD83E6u))) { return; }
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8484;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebx, 0x15u);
    cpu->edi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D8400:
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(1u)) goto label_000D841D;
    cpu->edx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x24u);
    goto label_000D842F;
    label_000D841D:
    cpu->ecx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x24u);
    label_000D842F:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8431u), LIFT_CODE_TOKEN_RVA(0xD842Fu))) { return; }
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8440;
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(6u)) goto label_000D8400;
    goto label_000D8446;
    label_000D8440:
    cpu->ecx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x10u);
    lift_store32(cpu->ebx, cpu->ecx);
    label_000D8446:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x40u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D8484;
    cpu->ecx = (uint32_t)(uintptr_t)"CheckDeviceType ERROR(windowed):";
    if ((uint32_t)(cpu->ebp) == (uint32_t)(1u)) goto label_000D845C;
    cpu->ecx = (uint32_t)(uintptr_t)"CheckDeviceType ERROR(fullscreen):";
    label_000D845C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8461u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D8461u));
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8469u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x4D8469u));
    cpu->ecx = (uint32_t)(uintptr_t)"bbuf=";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8473u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D8473u));
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D847Au)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x4D847Au));
    cpu->ecx = (uint32_t)(uintptr_t)"\310\347\342\350\355\350\362\345, \365\340\360\340\352\362\345\360\350\361\362\350\352\350 \302\340\370\345\343\356 3d-\363\361\352\356\360\350\362\345\353\377 \355\345\344\356\361\362\340\362\356\367\355\373 \344\353\377 \347\340\357\363\361\352\340 \350\343\360\373";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD8484u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xD8484u));
    label_000D8484:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D84A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, 0x47u);
    lift_store32(cpu->esp + 0x14u, 0x4Bu);
    lift_store32(cpu->esp + 0x18u, 0x4Du);
    lift_store32(cpu->esp + 0x1Cu, 0x4Fu);
    lift_store32(cpu->esp + 0x20u, 0x46u);
    lift_store32(cpu->esp + 0x24u, 0x50u);
    lift_store32(cpu->esp + 0x28u, 0x49u);
    lift_store32(cpu->ebp, 0x47u);
    cpu->esi = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000D8500:
    cpu->edx = lift_load32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x10u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8518u), LIFT_CODE_TOKEN_RVA(0xD8516u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D8537;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(7u)) goto label_000D8500;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D8537:
    cpu->ecx = lift_load32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebp, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8560(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    g_sfera_d3d9_semantic_state.sampler_min_filter = (uint32_t)(3u);
    g_sfera_d3d9_semantic_state.sampler_mag_filter = (uint32_t)(2u);
    g_sfera_d3d9_semantic_state.sampler_mip_filter = (uint32_t)(2u);
    cpu->edi = 0u;
    label_000D8585:
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_min_filter;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x114u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD859Du), LIFT_CODE_TOKEN_RVA(0xD859Bu))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D85C5;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D85ACu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D85ACu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A2u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D85C2u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D85C2u));
    cpu->esp += 0x14u;
    label_000D85C5:
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_mag_filter;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 5u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x114u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD85DDu), LIFT_CODE_TOKEN_RVA(0xD85DBu))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8605;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D85ECu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D85ECu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A4u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8602u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8602u));
    cpu->esp += 0x14u;
    label_000D8605:
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_mip_filter;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 7u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x114u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD861Du), LIFT_CODE_TOKEN_RVA(0xD861Bu))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8645;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D862Cu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D862Cu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A6u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8642u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8642u));
    cpu->esp += 0x14u;
    label_000D8645:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 4u); lift_push32(cpu, 0xAu); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8658u), LIFT_CODE_TOKEN_RVA(0xD8656u))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8680;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8667u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8667u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A8u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D867Du)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D867Du));
    cpu->esp += 0x14u;
    label_000D8680:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8693u), LIFT_CODE_TOKEN_RVA(0xD8691u))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D86BB;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D86A2u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D86A2u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1AAu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D86B8u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D86B8u));
    cpu->esp += 0x14u;
    label_000D86BB:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD86CEu), LIFT_CODE_TOKEN_RVA(0xD86CCu))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D86F6;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D86DDu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D86DDu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1ACu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D86F3u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D86F3u));
    cpu->esp += 0x14u;
    label_000D86F6:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 1u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8709u), LIFT_CODE_TOKEN_RVA(0xD8707u))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8731;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8718u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8718u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1AEu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D872Eu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D872Eu));
    cpu->esp += 0x14u;
    label_000D8731:
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(4u)) goto label_000D8585;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD875Cu), LIFT_CODE_TOKEN_RVA(0xD875Au))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8784;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D876Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D876Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8781u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8781u));
    cpu->esp += 0x14u;
    label_000D8784:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x114u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD87B1u), LIFT_CODE_TOKEN_RVA(0xD87AFu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D87D9;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D87C0u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D87C0u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x218u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D87D6u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D87D6u));
    cpu->esp += 0x14u;
    label_000D87D9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D87E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xACu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8813u), LIFT_CODE_TOKEN_RVA(0xD8811u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D883B;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8822u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8822u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x231u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8838u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8838u));
    cpu->esp += 0x14u;
    label_000D883B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8840(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xA8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8852u), LIFT_CODE_TOKEN_RVA(0xD8850u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D887A;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8861u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8861u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x259u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8877u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8877u));
    cpu->esp += 0x14u;
    label_000D887A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD88A3u), LIFT_CODE_TOKEN_RVA(0xD88A1u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x88760868u)) goto label_000D88D3;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D88D3;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D88BAu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D88BAu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x29Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D88D0u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D88D0u));
    cpu->esp += 0x14u;
    label_000D88D3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D88E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xB0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD88FEu), LIFT_CODE_TOKEN_RVA(0xD88FCu))) { return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x100u)) goto label_000D8918;
    cpu->edi += 0x198u;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    label_000D8918:
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D893B;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8922u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8922u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x2A7u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8938u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8938u));
    cpu->esp += 0x14u;
    label_000D893B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x198u);
    cpu->ecx = 0x10u;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xBCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8983u), LIFT_CODE_TOKEN_RVA(0xD8981u))) { return; }
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xC0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD89A7u), LIFT_CODE_TOKEN_RVA(0xD89A5u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D89CF;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D89B6u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D89B6u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2C9u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D89CCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D89CCu));
    cpu->esp += 0x14u;
    label_000D89CF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D89E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x2Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8A04u), LIFT_CODE_TOKEN_RVA(0xD8A02u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8A2C;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8A13u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8A13u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2F9u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8A29u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8A29u));
    cpu->esp += 0x14u;
    label_000D8A2C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x2Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8A64u), LIFT_CODE_TOKEN_RVA(0xD8A62u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8A8C;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8A73u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8A73u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x307u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8A89u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8A89u));
    cpu->esp += 0x14u;
    label_000D8A8C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8AB0u), LIFT_CODE_TOKEN_RVA(0xD8AAEu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8AD8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8ABFu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8ABFu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x311u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8AD5u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8AD5u));
    cpu->esp += 0x14u;
    label_000D8AD8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8AF0u), LIFT_CODE_TOKEN_RVA(0xD8AEEu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8B18;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8AFFu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8AFFu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x31Bu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8B15u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8B15u));
    cpu->esp += 0x14u;
    label_000D8B18:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1A0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8B37u), LIFT_CODE_TOKEN_RVA(0xD8B35u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8B5F;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8B46u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8B46u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x354u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8B5Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8B5Cu));
    cpu->esp += 0x14u;
    label_000D8B5F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x164u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8B87u), LIFT_CODE_TOKEN_RVA(0xD8B85u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8BAF;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8B96u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8B96u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x35Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8BACu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8BACu));
    cpu->esp += 0x14u;
    label_000D8BAF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xC4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8BD7u), LIFT_CODE_TOKEN_RVA(0xD8BD5u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8BFF;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8BE6u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8BE6u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x368u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8BFCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8BFCu));
    cpu->esp += 0x14u;
    label_000D8BFF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xCCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8C2Cu), LIFT_CODE_TOKEN_RVA(0xD8C2Au))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8C54;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8C3Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8C3Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x37Cu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8C51u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8C51u));
    cpu->esp += 0x14u;
    label_000D8C54:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xD4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8C7Cu), LIFT_CODE_TOKEN_RVA(0xD8C7Au))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8CA4;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8C8Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8C8Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x390u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8CA1u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8CA1u));
    cpu->esp += 0x14u;
    label_000D8CA4:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::D3DXGetShaderConstantTable), LIFT_CODE_TOKEN_VA(0x4D8CBAu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8CCE;
    lift_push32(cpu, (uint32_t)(uintptr_t)"D3DXGetShaderConstantTable failed");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8CCDu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8CCDu));
    cpu->ecx = lift_pop32(cpu);
    label_000D8CCE:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x158u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8CFCu), LIFT_CODE_TOKEN_RVA(0xD8CFAu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8D24;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8D0Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8D0Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x3E5u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8D21u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8D21u));
    cpu->esp += 0x14u;
    label_000D8D24:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8D4Cu), LIFT_CODE_TOKEN_RVA(0xD8D4Au))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8D74;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8D5Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8D5Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x3F9u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8D71u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8D71u));
    cpu->esp += 0x14u;
    label_000D8D74:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x15Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8D97u), LIFT_CODE_TOKEN_RVA(0xD8D95u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8DBF;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8DA6u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8DA6u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x403u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8DBCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8DBCu));
    cpu->esp += 0x14u;
    label_000D8DBF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x170u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8DE7u), LIFT_CODE_TOKEN_RVA(0xD8DE5u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8E0F;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8DF6u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8DF6u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x419u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8E0Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8E0Cu));
    cpu->esp += 0x14u;
    label_000D8E0F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1ACu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8E37u), LIFT_CODE_TOKEN_RVA(0xD8E35u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8E5F;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8E46u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8E46u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x423u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8E5Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8E5Cu));
    cpu->esp += 0x14u;
    label_000D8E5F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTexture), LIFT_CODE_TOKEN_VA(0x4D8E9Bu));
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8EC8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8EAFu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8EAFu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x434u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8EC5u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8EC5u));
    cpu->esp += 0x14u;
    label_000D8EC8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x24u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 1u); lift_push32(cpu, 0xFFFFFFFDu); lift_push32(cpu, 0u); lift_push32(cpu, 0xFFFFFFFDu); lift_push32(cpu, 0u);
    lift_push32(cpu, 0u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTextureFromFileInMemoryEx), LIFT_CODE_TOKEN_VA(0x4D8EFDu));
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXCreateCubeTextureFromFileInMemory), LIFT_CODE_TOKEN_VA(0x4D8F27u));
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x104u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8F5Cu), LIFT_CODE_TOKEN_RVA(0xD8F5Au))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8F84;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8F6Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8F6Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x493u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8F81u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8F81u));
    cpu->esp += 0x14u;
    label_000D8F84:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8FB1u), LIFT_CODE_TOKEN_RVA(0xD8FAFu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8FD9;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8FC0u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D8FC0u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x49Du); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D8FD6u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D8FD6u));
    cpu->esp += 0x14u;
    label_000D8FD9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x150u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD901Au), LIFT_CODE_TOKEN_RVA(0xD9018u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9042;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9029u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9029u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4C1u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D903Fu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D903Fu));
    cpu->esp += 0x14u;
    label_000D9042:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x24u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x14Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9076u), LIFT_CODE_TOKEN_RVA(0xD9074u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D909E;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9085u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9085u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4D3u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D909Bu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D909Bu));
    cpu->esp += 0x14u;
    label_000D909E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D90B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1D8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD90CBu), LIFT_CODE_TOKEN_RVA(0xD90C9u))) { return; }
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D90E7;
    cpu->ecx = (uint32_t)(uintptr_t)"Render err: cant create query:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D90DCu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D90DCu));
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D90E4u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x4D90E4u));
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    label_000D90E7:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D90F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x98u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD910Cu), LIFT_CODE_TOKEN_RVA(0xD910Au))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9134;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D911Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D911Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x52Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9131u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9131u));
    cpu->esp += 0x14u;
    label_000D9134:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x94u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD915Cu), LIFT_CODE_TOKEN_RVA(0xD915Au))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9184;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D916Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D916Bu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x535u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9181u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9181u));
    cpu->esp += 0x14u;
    label_000D9184:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9190(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Bu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD91A5u), LIFT_CODE_TOKEN_RVA(0xD91A3u))) { return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x13u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD91BAu), LIFT_CODE_TOKEN_RVA(0xD91B8u))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD91CFu), LIFT_CODE_TOKEN_RVA(0xD91CDu))) { return; }
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D91E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Bu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD91F2u), LIFT_CODE_TOKEN_RVA(0xD91F0u))) { return; }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD921Eu), LIFT_CODE_TOKEN_RVA(0xD921Cu))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9234u), LIFT_CODE_TOKEN_RVA(0xD9232u))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 3u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD924Au), LIFT_CODE_TOKEN_RVA(0xD9248u))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD926Eu), LIFT_CODE_TOKEN_RVA(0xD926Cu))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 5u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9284u), LIFT_CODE_TOKEN_RVA(0xD9282u))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD929Au), LIFT_CODE_TOKEN_RVA(0xD9298u))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D92A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9561;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(4u))) & 0xFFu);
    cpu->edx = cpu->edx & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(cpu->edx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edx += 2u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x16u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD92ECu), LIFT_CODE_TOKEN_RVA(0xD92EAu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D9314;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D92FBu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D92FBu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9311u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9311u));
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000D9314:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = cpu->edi;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx &= 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x89u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9330u), LIFT_CODE_TOKEN_RVA(0xD932Eu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9358;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D933Fu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D933Fu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9355u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9355u));
    cpu->esp += 0x14u;
    label_000D9358:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    cpu->edi = ~((uint64_t)(cpu->edi));
    cpu->edi &= 1u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x88u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9371u), LIFT_CODE_TOKEN_RVA(0xD936Fu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9399;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9380u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9380u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9396u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9396u));
    cpu->esp += 0x14u;
    label_000D9399:
    cpu->eax = lift_load32(cpu->ebp);
    cpu->edx = lift_load32(cpu->eax + 0x34u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD93A7u), LIFT_CODE_TOKEN_RVA(0xD93A5u))) { return; }
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x164u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD93C1u), LIFT_CODE_TOKEN_RVA(0xD93BFu))) { return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x4Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D94A9;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D93F4;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D93DBu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D93DBu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x35Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D93F1u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D93F1u));
    cpu->esp += 0x14u;
    label_000D93F4:
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x190u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9413u), LIFT_CODE_TOKEN_RVA(0xD9411u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D943B;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9422u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9422u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x34Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9438u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9438u));
    cpu->esp += 0x14u;
    label_000D943B:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9446;
    lift_push32(cpu, cpu->eax);
    goto label_000D9450;
    label_000D9446:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx);
    label_000D9450:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D945Bu)); sfera_sub_004D8B20(cpu, LIFT_CODE_TOKEN_VA(0x4D945Bu));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->eax = 0xAAAAAAABu;
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x4Cu), 32u, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x148u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD948Bu), LIFT_CODE_TOKEN_RVA(0xD9489u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D955F;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D949Eu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D949Eu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4E9u);
    goto label_000D954C;
    label_000D94A9:
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D94CC;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D94B3u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D94B3u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x35Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D94C9u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D94C9u));
    cpu->esp += 0x14u;
    label_000D94CC:
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x190u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD94EBu), LIFT_CODE_TOKEN_RVA(0xD94E9u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D9513;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D94FAu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D94FAu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x34Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9510u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9510u));
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000D9513:
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->eax = 0xAAAAAAABu;
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x44u), 32u, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x144u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0xD9537u), LIFT_CODE_TOKEN_RVA(0xD9535u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D955F;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9546u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9546u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4F9u);
    label_000D954C:
    lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D955Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D955Cu));
    cpu->esp += 0x14u;
    label_000D955F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000D9561:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x28u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9580(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D9737;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->edx = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx &= 1u;
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x89u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD95B7u), LIFT_CODE_TOKEN_RVA(0xD95B5u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D95DF;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D95C6u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D95C6u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D95DCu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D95DCu));
    cpu->esp += 0x14u;
    label_000D95DF:
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->esi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(4u))) & 0xFFu);
    cpu->edx = cpu->edx & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(cpu->edx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edx += 2u;
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x16u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9606u), LIFT_CODE_TOKEN_RVA(0xD9604u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D962E;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9615u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9615u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D962Bu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D962Bu));
    cpu->esp += 0x14u;
    label_000D962E:
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = ~((uint64_t)(cpu->esi));
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    cpu->esi &= 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x88u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD964Eu), LIFT_CODE_TOKEN_RVA(0xD964Cu))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9676;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D965Du)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D965Du));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9673u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9673u));
    cpu->esp += 0x14u;
    label_000D9676:
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D96E2;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, 0x65u); lift_push32(cpu, cpu->eax);
    cpu->eax = 0xAAAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x150u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0xD96B3u), LIFT_CODE_TOKEN_RVA(0xD96B1u))) { return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebp + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9734;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D96C2u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D96C2u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4C1u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D96D8u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D96D8u));
    cpu->esp += 0x14u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x20u; cpu->eip = stop_address; return;
    label_000D96E2:
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(6u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D9711;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(2u)) goto label_000D9734;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax += 0xFFFFFFFEu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D970Au)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4D970Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x20u; cpu->eip = stop_address; return;
    label_000D9711:
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = 0x55555556u;
    lift_multiply_accumulator(cpu, lift_load32(cpu->esp + 0x28u), 32u, 1u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD9734u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_RVA(0xD9734u));
    label_000D9734:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D9737:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x20u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->ecx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D97A4;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x68u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9775u), LIFT_CODE_TOKEN_RVA(0xD9773u))) { return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ecx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D97A1;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9788u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9788u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2DCu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D979Eu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D979Eu));
    cpu->esp += 0x14u;
    label_000D97A1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000D97A4:
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D97B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->ecx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D9814;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x6Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD97E5u), LIFT_CODE_TOKEN_RVA(0xD97E3u))) { return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ecx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9811;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D97F8u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D97F8u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2EBu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D980Eu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D980Eu));
    cpu->esp += 0x14u;
    label_000D9811:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000D9814:
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9820(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9839;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9832u), LIFT_CODE_TOKEN_RVA(0xD9830u))) { return; }
    lift_store32(cpu->esi + 4u, 0u);
    label_000D9839:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) != (uint32_t)(0u)) goto label_000D98BB;
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    cpu->ebp = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTexture), LIFT_CODE_TOKEN_VA(0x4D9887u));
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D98B8;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D989Fu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D989Fu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x434u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D98B5u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D98B5u));
    cpu->esp += 0x14u;
    label_000D98B8:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D98BB:
    cpu->eax = 1u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) == (uint32_t)(cpu->eax)) goto label_000D98C8;
    lift_store8(cpu->esi + 0x20u, cpu->eax & 0xFFu);
    label_000D98C8:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D98D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D98E0;
    cpu->eax = cpu->ecx;
    label_000D98E0:
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D98ED;
    lift_store32(cpu->ecx, 0u);
    label_000D98ED:
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D9915;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9961;
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->deallocate(cpu);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000D9915:
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0xCu)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000D994B;
    cpu->ecx = cpu->edi;
    label_000D9936:
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D9942;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->ecx, cpu->edx);
    label_000D9942:
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xCu))) goto label_000D9936;
    label_000D994B:
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D995D;
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->deallocate(cpu);
    label_000D995D:
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    label_000D9961:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 2u); lift_push32(cpu, 0x16u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9994u), LIFT_CODE_TOKEN_RVA(0xD9992u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D99BC;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D99A3u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D99A3u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x15Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D99B9u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D99B9u));
    cpu->esp += 0x14u;
    label_000D99BC:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 7u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD99CEu), LIFT_CODE_TOKEN_RVA(0xD99CCu))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D99F6;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D99DDu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D99DDu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x15Du); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D99F3u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D99F3u));
    cpu->esp += 0x14u;
    label_000D99F6:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9A08u), LIFT_CODE_TOKEN_RVA(0xD9A06u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9A30;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9A17u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9A17u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x160u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9A2Du)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9A2Du));
    cpu->esp += 0x14u;
    label_000D9A30:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 7u); lift_push32(cpu, 0x19u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9A42u), LIFT_CODE_TOKEN_RVA(0xD9A40u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9A6A;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9A51u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9A51u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x163u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9A67u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9A67u));
    cpu->esp += 0x14u;
    label_000D9A6A:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x18u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9A7Cu), LIFT_CODE_TOKEN_RVA(0xD9A7Au))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9AA4;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9A8Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9A8Bu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x166u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9AA1u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9AA1u));
    cpu->esp += 0x14u;
    label_000D9AA4:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0xFu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9AB6u), LIFT_CODE_TOKEN_RVA(0xD9AB4u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9ADE;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9AC5u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9AC5u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x169u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9ADBu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9ADBu));
    cpu->esp += 0x14u;
    label_000D9ADE:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9AF0u), LIFT_CODE_TOKEN_RVA(0xD9AEEu))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9B18;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9AFFu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9AFFu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x16Cu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9B15u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9B15u));
    cpu->esp += 0x14u;
    label_000D9B18:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x89u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9B2Du), LIFT_CODE_TOKEN_RVA(0xD9B2Bu))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9B55;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9B3Cu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9B3Cu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x16Fu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9B52u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9B52u));
    cpu->esp += 0x14u;
    label_000D9B55:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9B5Cu)); sfera_sub_004D8560(cpu, LIFT_CODE_TOKEN_VA(0x4D9B5Cu));
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0xBCu);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9BABu), LIFT_CODE_TOKEN_RVA(0xD9BA9u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9BD3;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9BBAu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9BBAu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x182u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9BD0u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9BD0u));
    cpu->esp += 0x14u;
    label_000D9BD3:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9BE5u), LIFT_CODE_TOKEN_RVA(0xD9BE3u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9C0D;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9BF4u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9BF4u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x185u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9C0Au)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9C0Au));
    cpu->esp += 0x14u;
    label_000D9C0D:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x8Cu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9C22u), LIFT_CODE_TOKEN_RVA(0xD9C20u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9C4A;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9C31u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9C31u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x188u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9C47u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9C47u));
    cpu->esp += 0x14u;
    label_000D9C4A:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9C5Cu), LIFT_CODE_TOKEN_RVA(0xD9C5Au))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9C84;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9C6Bu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9C6Bu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9C81u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9C81u));
    cpu->esp += 0x14u;
    label_000D9C84:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0x24u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9C96u), LIFT_CODE_TOKEN_RVA(0xD9C94u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9CBE;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9CA5u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9CA5u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18Cu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9CBBu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9CBBu));
    cpu->esp += 0x14u;
    label_000D9CBE:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0x96u); lift_push32(cpu, 0x25u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9CD3u), LIFT_CODE_TOKEN_RVA(0xD9CD1u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9CFB;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9CE2u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9CE2u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9CF8u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9CF8u));
    cpu->esp += 0x14u;
    label_000D9CFB:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x89u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9D10u), LIFT_CODE_TOKEN_RVA(0xD9D0Eu))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9D38;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9D1Fu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4D9D1Fu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x191u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9D35u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4D9D35u));
    cpu->esp += 0x14u;
    label_000D9D38:
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9D43u)); sfera_sub_00450AB0(cpu, LIFT_CODE_TOKEN_VA(0x4D9D43u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000D9D7D;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9D77u), LIFT_CODE_TOKEN_RVA(0xD9D75u))) { return; }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01) = (uint32_t)(cpu->esi);
    label_000D9D7D:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9D88u)); sfera_sub_004DAD30(cpu, LIFT_CODE_TOKEN_VA(0x4D9D88u));
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000D9DBA;
    label_000D9D90:
    cpu->ecx = lift_load32(cpu->edi + 0x184u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000D9DA1;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD9DA1u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0xD9DA1u));
    label_000D9DA1:
    cpu->eax = lift_load32(cpu->edi + 0x17Cu);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    reinterpret_cast<UnmanagedResourceBase*>(cpu->ecx)->releaseResource(cpu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u))) goto label_000D9D90;
    label_000D9DBA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9DC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9DCAu)); sfera_sub_004D9970(cpu, LIFT_CODE_TOKEN_VA(0x4D9DCAu));
    cpu->esi = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1D8u);
    lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.state_01); lift_push32(cpu, 8u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9DE5u), LIFT_CODE_TOKEN_RVA(0xD9DE3u))) { return; }
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D9E00;
    cpu->ecx = (uint32_t)(uintptr_t)"Render err: cant create query:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9DF8u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4D9DF8u));
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD9E00u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_RVA(0xD9E00u));
    label_000D9E00:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9E0Bu)); sfera_sub_004DAA60(cpu, LIFT_CODE_TOKEN_VA(0x4D9E0Bu));
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000D9E3E;
    label_000D9E15:
    cpu->ecx = lift_load32(cpu->edi + 0x184u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000D9E26;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xD9E26u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0xD9E26u));
    label_000D9E26:
    cpu->eax = lift_load32(cpu->edi + 0x17Cu);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    reinterpret_cast<UnmanagedResourceBase*>(cpu->ecx)->restoreResource(cpu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u))) goto label_000D9E15;
    label_000D9E3E:
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = (uint32_t)(cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = (uint32_t)(cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = (uint32_t)(cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.vertex32 = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.vertex28 = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.index_primary = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.index_secondary = (uint32_t)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9E73u)); sfera_sub_00456450(cpu, LIFT_CODE_TOKEN_VA(0x4D9E73u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_00468B40(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000D9EE6;
    cpu->edx = (uint32_t)(cpu->esi + cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0xCu))) goto label_000D9EE6;
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9EA6;
    lift_store32(cpu->eax, 0u);
    label_000D9EA6:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->eax -= cpu->esi;
    cpu->eax -= cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000D9EDB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edx) * 4u));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi) * 4u));
    label_000D9EC1:
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->esi = (uint32_t)(cpu->edi + cpu->edx);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D9ED0;
    cpu->edx = lift_load32(cpu->ebx + cpu->edx);
    lift_store32(cpu->esi, cpu->edx);
    label_000D9ED0:
    cpu->ebx += 4u;
    cpu->edi += 4u;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D9EC1;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D9EDB:
    lift_store32(cpu->ecx + 0xCu, (uint64_t)(lift_load32(cpu->ecx + 0xCu)) - (uint64_t)(cpu->ebp) - (uint64_t)(0u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000D9EE6:
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"bufSize=%d, elemsNum=%d"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_container_diagnostics_runtime.range_error[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4D9EFDu));
    lift_push32(cpu, (uintptr_t)&g_sfera_container_diagnostics_runtime.range_error[0]); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"BaseVect::erase: out of range. index=%d, num=%d. %s"); lift_push32(cpu, cpu->edx);
    lift_store8((uintptr_t)&g_sfera_container_diagnostics_runtime.range_error[127], 0u);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\BaseVect.h");
    lift_store32(cpu->esp + 0x34u, 0x115u);
    lift_store32(cpu->esp + 0x38u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D9F38u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4D9F38u));
    cpu->esp += 0x28u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9F50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9F63;
    lift_store32(cpu->eax, 0u);
    label_000D9F63:
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<UnmanagedResourceVector*>(cpu->esi)->reserve(cpu);
    cpu->ebp = lift_load32(cpu->esi + 0xCu);
    cpu->ebp -= lift_load32(cpu->esp + 0x14u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000D9FA0;
    label_000D9F82:
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax -= cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx + 0xFFFFFFFFu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    if ((uint32_t)(cpu->edx) == 0u) goto label_000D9F9B;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0xFFFFFFFCu);
    lift_store32(cpu->edx, cpu->eax);
    label_000D9F9B:
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000D9F82;
    label_000D9FA0:
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D9FCA;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000D9FCA;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    label_000D9FB6:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D9FC2;
    cpu->ebp = lift_load32(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->ecx, cpu->ebp);
    label_000D9FC2:
    ++cpu->eax;
    cpu->edx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000D9FB6;
    label_000D9FCA:
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x488u;
    cpu->eax = lift_load32(cpu->esp + 0x48Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x4A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0x10u)) goto label_000DA021;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0x20u)) goto label_000DA021;
    cpu->ebp = 0x20u;
    g_sfera_graphics_display_depth_bits = (uint32_t)(cpu->ebp);
    label_000DA021:
    cpu->eax = 0x320u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4A0u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000DA036;
    lift_store32(cpu->esp + 0x4A0u, cpu->eax);
    label_000DA036:
    cpu->eax = 0x258u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4A4u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000DA04B;
    lift_store32(cpu->esp + 0x4A4u, cpu->eax);
    label_000DA04B:
    cpu->ebx = lift_load32(cpu->esp + 0x4ACu);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA05Du)); sfera_sub_004CB790(cpu, LIFT_CODE_TOKEN_VA(0x4DA05Du));
    cpu->ecx = g_sfera_graphics_display_depth_bits;
    cpu->edx = lift_load32(cpu->esp + 0x4A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x4A4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA077u)); sfera_sub_004C9DF0(cpu, LIFT_CODE_TOKEN_VA(0x4DA077u));
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000DA0A1;
    cpu->edi = native_function_address32(&::GetSystemMetrics);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDA085u), LIFT_CODE_TOKEN_RVA(0xDA083u))) { return; }
    lift_push32(cpu, 1u);
    lift_store32(cpu->esp + 0x4A4u, cpu->eax);
    g_sfera_graphics_runtime.display_width = (uint32_t)(cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDA095u), LIFT_CODE_TOKEN_RVA(0xDA093u))) { return; }
    lift_store32(cpu->esp + 0x4A4u, cpu->eax);
    g_sfera_graphics_runtime.display_height = (uint32_t)(cpu->eax);
    label_000DA0A1:
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA0C4u), LIFT_CODE_TOKEN_RVA(0xDA0C2u))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA0EC;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA0D3u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA0D3u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xF3u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA0E9u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA0E9u));
    cpu->esp += 0x14u;
    label_000DA0EC:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 0x10u;
    cpu->eax += 0x16u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA128u)); sfera_sub_004D8370(cpu, LIFT_CODE_TOKEN_VA(0x4DA128u));
    lift_push32(cpu, 0x130u);
    cpu->edi = (uint32_t)(cpu->esi + 0x48u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA133u));
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x38u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDA14Au), LIFT_CODE_TOKEN_RVA(0xDA148u))) { return; }
    cpu->eax = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)((cpu->eax) & (0x10000u)) == 0u) goto label_000DA16A;
    cpu->ebx = 0x40u;
    if ((uint32_t)((cpu->eax) & (0x100000u)) == 0u) goto label_000DA165;
    cpu->ebx = 0x50u;
    label_000DA165:
    cpu->ebx |= 2u;
    goto label_000DA16F;
    label_000DA16A:
    cpu->ebx = 0x20u;
    label_000DA16F:
    if ((uint32_t)(lift_load32(cpu->esi + 0x10Cu)) < (uint32_t)(0xFFFE0200u)) goto label_000DA190;
    if ((uint32_t)(lift_load32(cpu->esi + 0x114u)) < (uint32_t)(0xFFFF0200u)) goto label_000DA190;
    lift_store8(cpu->esi + 0x1D8u, 1u);
    goto label_000DA197;
    label_000DA190:
    lift_store8(cpu->esi + 0x1D8u, 0u);
    label_000DA197:
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA1A8u)); sfera_sub_004D84A0(cpu, LIFT_CODE_TOKEN_VA(0x4DA1A8u));
    lift_push32(cpu, 0x38u);
    cpu->edi = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA1B0u));
    cpu->edx = lift_load32(cpu->esp + 0x4ACu);
    cpu->eax = lift_load32(cpu->esp + 0x4B0u);
    lift_store32(cpu->edi, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esi + 0x24u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x30u, cpu->edx);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x4ACu);
    cpu->edx = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = 1u;
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, 1u);
    lift_store32(cpu->esi + 0x10u, cpu->ebp);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    lift_store32(cpu->esi + 0x34u, 2u);
    lift_store32(cpu->esi + 0x3Cu, 0x80000000u);
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x40u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDA226u), LIFT_CODE_TOKEN_RVA(0xDA224u))) { return; }
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA2C3;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDA244u), LIFT_CODE_TOKEN_RVA(0xDA242u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000DA283;
    lift_push32(cpu, 0x1Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x22Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x47Cu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4DA25Au));
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"V='";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA26Du)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4DA26Du));
    cpu->ecx = (uint32_t)(cpu->esp + 0x474u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA279u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4DA279u));
    cpu->ecx = (uint32_t)(uintptr_t)"'\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA283u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_RVA(0xDA283u));
    label_000DA283:
    cpu->ecx = (uint32_t)(uintptr_t)"CreateDevice ERROR:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA28Du)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4DA28Du));
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA295u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x4DA295u));
    cpu->ecx = (uint32_t)(uintptr_t)"zbuf=";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA29Fu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4DA29Fu));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA2A8u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x4DA2A8u));
    cpu->ecx = (uint32_t)(uintptr_t)"bbuf=";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA2B2u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4DA2B2u));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA2B9u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_VA(0x4DA2B9u));
    cpu->ecx = (uint32_t)(uintptr_t)"\310\347\342\350\355\350\362\345, \365\340\360\340\352\362\345\360\350\361\362\350\352\350 \302\340\370\345\343\356 3d-\363\361\352\356\360\350\362\345\353\377 \355\345\344\356\361\362\340\362\356\367\355\373 \344\353\377 \347\340\357\363\361\352\340 \350\343\360\373";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA2C3u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0xDA2C3u));
    label_000DA2C3:
    cpu->edi = lift_load32(cpu->esi + 0x40u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA2E9;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA2D0u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA2D0u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x149u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA2E6u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA2E6u));
    cpu->esp += 0x14u;
    label_000DA2E9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA2F0u)); sfera_sub_004D9970(cpu, LIFT_CODE_TOKEN_VA(0x4DA2F0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x488u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA310(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA31Fu), LIFT_CODE_TOKEN_RVA(0xDA31Du))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x88760868u)) goto label_000DA331;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000DA331:
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x88760869u)) goto label_000DA380;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA340u)); sfera_sub_004D9D60(cpu, LIFT_CODE_TOKEN_VA(0x4DA340u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x40u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDA34Fu), LIFT_CODE_TOKEN_RVA(0xDA34Du))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA377;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA35Eu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA35Eu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x244u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA374u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA374u));
    cpu->esp += 0x14u;
    label_000DA377:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA37Eu)); sfera_sub_004D9DC0(cpu, LIFT_CODE_TOKEN_VA(0x4DA37Eu));
    goto label_000DA3A3;
    label_000DA380:
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA3A3;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA38Au)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA38Au));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x249u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA3A0u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA3A0u));
    cpu->esp += 0x14u;
    label_000DA3A3:
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xA4u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA3B1u), LIFT_CODE_TOKEN_RVA(0xDA3AFu))) { return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA3D9;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA3C0u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA3C0u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x24Du); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA3D6u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA3D6u));
    cpu->esp += 0x14u;
    label_000DA3D9:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x184u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000DA442;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    label_000DA400:
    cpu->ecx = lift_load32(cpu->eax + 0x184u);
    cpu->edi = (uint32_t)(cpu->eax + 0x178u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000DA41C;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA417u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x4DA417u));
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    label_000DA41C:
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(cpu->ebx)) goto label_000DA437;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->eax + 0x178u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA432u)); sfera_sub_004D9E80(cpu, LIFT_CODE_TOKEN_VA(0x4DA432u));
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    label_000DA437:
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x184u))) goto label_000DA400;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000DA442:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA450(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    std::construct_at(reinterpret_cast<UnmanagedResourceVB*>(cpu->esi));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA46F;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA468u), LIFT_CODE_TOKEN_RVA(0xDA466u))) { return; }
    lift_store32(cpu->esi + 4u, 0u);
    label_000DA46F:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA481;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA481u)); sfera_sub_004DA3E0(cpu, LIFT_CODE_TOKEN_RVA(0xDA481u));
    label_000DA481:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA490(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    std::construct_at(reinterpret_cast<UnmanagedResourceIB*>(cpu->esi));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA4AF;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA4A8u), LIFT_CODE_TOKEN_RVA(0xDA4A6u))) { return; }
    lift_store32(cpu->esi + 4u, 0u);
    label_000DA4AF:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA4C1;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA4C1u)); sfera_sub_004DA3E0(cpu, LIFT_CODE_TOKEN_RVA(0xDA4C1u));
    label_000DA4C1:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA4D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    std::construct_at(reinterpret_cast<UnmanagedResourceTexture*>(cpu->esi));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA4EF;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA4E8u), LIFT_CODE_TOKEN_RVA(0xDA4E6u))) { return; }
    lift_store32(cpu->esi + 4u, 0u);
    label_000DA4EF:
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) == (uint32_t)(1u)) goto label_000DA501;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA501u)); sfera_sub_004DA3E0(cpu, LIFT_CODE_TOKEN_RVA(0xDA501u));
    label_000DA501:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0xCu)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000DA53D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0xCu))))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA529u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4DA529u));
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(0xAu)) goto label_000DA535;
    cpu->eax = (uint32_t)(cpu->esi + 0xAu);
    label_000DA535:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA53Du)); sfera_sub_004D98D0(cpu, LIFT_CODE_TOKEN_RVA(0xDA53Du));
    label_000DA53D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA590(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_x87_push(cpu, (double)2.0f);
    cpu->ebx = 0u;
    lift_store32(cpu->esi, cpu->ebx);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    lift_store8(cpu->esi + 0x44u, cpu->ebx & 0xFFu);
    lift_store_f32(cpu->esi + 0x18Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    std::construct_at(reinterpret_cast<UnmanagedResourceVector*>(cpu->esi + 0x178u));
    lift_store32(cpu->esi + 0x17Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x180u, cpu->ebx);
    lift_store32(cpu->esi + 0x184u, cpu->ebx);
    lift_store32(cpu->esi + 0x188u, cpu->ebx);
    lift_store32(cpu->esi + 0x190u, cpu->ebx);
    lift_store32(cpu->esi + 0x194u, (uintptr_t)&g_sfera_std_allocator);
    lift_push32(cpu, 0x20u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::Direct3DCreate9), LIFT_CODE_TOKEN_VA(0x4DA60Au));
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000DA62F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x3Bu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, (uintptr_t)"CD3D9Device::CD3D9Device() => Direct3DCreate9() failed."); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA62Cu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA62Cu));
    cpu->esp += 0x14u;
    label_000DA62F:
    lift_push32(cpu, 0x38u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA636u));
    lift_push32(cpu, 0x130u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA645u));
    cpu->esp += 0x18u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA670(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000DA6B1;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA6AEu), LIFT_CODE_TOKEN_RVA(0xDA6ACu))) { return; }
    lift_store32(cpu->esi + 4u, cpu->edi);
    label_000DA6B1:
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000DA6C1;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA6BFu), LIFT_CODE_TOKEN_RVA(0xDA6BDu))) { return; }
    lift_store32(cpu->esi, cpu->edi);
    label_000DA6C1:
    cpu->eax = lift_load32(cpu->esi + 0x184u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x178u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    std::construct_at(reinterpret_cast<UnmanagedResourceVector*>(cpu->esi + 0x178u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA6E6u)); sfera_sub_004D9E80(cpu, LIFT_CODE_TOKEN_VA(0x4DA6E6u));
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x178u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA6F2u)); sfera_sub_004D98D0(cpu, LIFT_CODE_TOKEN_VA(0x4DA6F2u));
    cpu->eax = lift_load32(cpu->esi + 0x188u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000DA70D;
    lift_store32(cpu->eax, cpu->edi);
    cpu->ecx = lift_load32(cpu->esi + 0x188u);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    lift_store32(cpu->esi + 0x188u, cpu->edi);
    label_000DA70D:
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0u);
    cpu->ebp = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    std::construct_at(reinterpret_cast<UnmanagedResourceVB*>(cpu->esi));
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x68u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0xDA76Au), LIFT_CODE_TOKEN_RVA(0xDA768u))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->edx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA796;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA77Du)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA77Du));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x2DCu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA793u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA793u));
    cpu->esp += 0x14u;
    label_000DA796:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA7BF;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 0x184u);
    lift_push32(cpu, 1u);
    cpu->ecx += 0x178u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA7BFu)); sfera_sub_004D9F50(cpu, LIFT_CODE_TOKEN_RVA(0xDA7BFu));
    label_000DA7BF:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0u);
    cpu->ebp = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    std::construct_at(reinterpret_cast<UnmanagedResourceIB*>(cpu->esi));
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0xDA81Au), LIFT_CODE_TOKEN_RVA(0xDA818u))) { return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->edx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA846;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA82Du)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA82Du));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x2EBu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA843u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA843u));
    cpu->esp += 0x14u;
    label_000DA846:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA86F;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 0x184u);
    lift_push32(cpu, 1u);
    cpu->ecx += 0x178u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDA86Fu)); sfera_sub_004D9F50(cpu, LIFT_CODE_TOKEN_RVA(0xDA86Fu));
    label_000DA86F:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    std::construct_at(reinterpret_cast<UnmanagedResourceTexture*>(cpu->esi));
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    cpu->ebp = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTexture), LIFT_CODE_TOKEN_VA(0x4DA8D7u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->edx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA908;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA8EFu)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DA8EFu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x434u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA905u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DA905u));
    cpu->esp += 0x14u;
    label_000DA908:
    if ((uint32_t)(cpu->ebx) == (uint32_t)(1u)) goto label_000DA934;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 0x184u);
    lift_push32(cpu, 1u);
    cpu->ecx += 0x178u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DA930u)); sfera_sub_004D9F50(cpu, LIFT_CODE_TOKEN_VA(0x4DA930u));
    lift_store8(cpu->esi + 0x20u, 0u);
    label_000DA934:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = (uint32_t)(cpu->edi + 0xCu);
    cpu->ebx = 0u;
    lift_store32(cpu->edi, cpu->ebx);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    lift_store8(cpu->edi + 8u, cpu->ebx & 0xFFu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u));
    cpu->edx = 0u;
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u));
    lift_store16(cpu->esp + 0x1Cu, cpu->edx & 0xFFFFu);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_d3d9_semantic_state.vertex_declaration);
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax = 0u;
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edx);
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x18u, 0x90003u);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x1Cu, 0x100000u);
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x20u, 0x50001u);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x26u, 0x10018u);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x2Au, 0xFF0105u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x2Eu, 0x110000u);
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store16(cpu->esp + 0x32u, cpu->ebx & 0xFFFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x48u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x4Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x54u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->edi + 0x8Cu, cpu->ebx);
    lift_store32(cpu->edi + 0x90u, cpu->ebx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAA32u)); sfera_sub_004D8CE0(cpu, LIFT_CODE_TOKEN_VA(0x4DAA32u));
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DAA39u));
    cpu->esp += 0xCu;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAA60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->edi + 8u)) == (uint8_t)(0u)) goto label_000DAB93;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAA7Eu), LIFT_CODE_TOKEN_RVA(0xDAA7Cu))) { return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAAA0;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAA8Au)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DAA8Au));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x7Fu); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAA9Du)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DAA9Du));
    cpu->esp += 0x14u;
    label_000DAAA0:
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->edi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_graphics_runtime.display_height;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x16u); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x5Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDAACCu), LIFT_CODE_TOKEN_RVA(0xDAACAu))) { return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAAF1;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAAD8u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DAAD8u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x8Au); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAAEEu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DAAEEu));
    cpu->esp += 0x14u;
    label_000DAAF1:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x5Cu);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x90u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0x16u); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0x80u); lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAB1Du), LIFT_CODE_TOKEN_RVA(0xDAB1Bu))) { return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAB42;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAB29u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DAB29u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x98u); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAB3Fu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DAB3Fu));
    cpu->esp += 0x14u;
    label_000DAB42:
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x5Cu);
    lift_push32(cpu, 0u);
    cpu->edi += 0x8Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x16u); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0x80u); lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAB6Du), LIFT_CODE_TOKEN_RVA(0xDAB6Bu))) { return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAB92;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAB79u)); sfera_sub_004E787C(cpu, LIFT_CODE_TOKEN_VA(0x4DAB79u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xA3u); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAB8Fu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x4DAB8Fu));
    cpu->esp += 0x14u;
    label_000DAB92:
    cpu->esi = lift_pop32(cpu);
    label_000DAB93:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DABA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DABB0u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x4DABB0u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DABBFu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x4DABBFu));
    cpu->esi = 0u;
    label_000DABC1:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DABD1u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DABD1u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DABE1u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DABE1u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 6u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DABF1u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DABF1u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC01u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DAC01u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC11u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DAC11u));
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(2u)) goto label_000DABC1;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC24u)); sfera_sub_004D8DD0(cpu, LIFT_CODE_TOKEN_VA(0x4DAC24u));
    cpu->eax = g_sfera_d3d9_semantic_state.vertex_declaration;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC35u)); sfera_sub_004D8D80(cpu, LIFT_CODE_TOKEN_VA(0x4DAC35u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DACD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000DAD24;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DACE8u)); sfera_sub_004D90F0(cpu, LIFT_CODE_TOKEN_VA(0x4DACE8u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 8u, 0u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDAD02u), LIFT_CODE_TOKEN_RVA(0xDAD00u))) { return; }
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAD14u)); sfera_sub_004D9140(cpu, LIFT_CODE_TOKEN_VA(0x4DAD14u));
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD24;
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDAD24u), LIFT_CODE_TOKEN_RVA(0xDAD22u))) { return; }
    label_000DAD24:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAD30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x8Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD4F;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD45u), LIFT_CODE_TOKEN_RVA(0xDAD43u))) { return; }
    lift_store32(cpu->esi + 0x8Cu, 0u);
    label_000DAD4F:
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD6B;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD61u), LIFT_CODE_TOKEN_RVA(0xDAD5Fu))) { return; }
    lift_store32(cpu->esi + 0x90u, 0u);
    label_000DAD6B:
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD81;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD7Au), LIFT_CODE_TOKEN_RVA(0xDAD78u))) { return; }
    lift_store32(cpu->esi + 4u, 0u);
    label_000DAD81:
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD95;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD8Fu), LIFT_CODE_TOKEN_RVA(0xDAD8Du))) { return; }
    lift_store32(cpu->esi, 0u);
    label_000DAD95:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DADA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x50u;
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->esi = 0u;
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x48u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDADCCu), LIFT_CODE_TOKEN_RVA(0xDADCAu))) { return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x30u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDADDDu), LIFT_CODE_TOKEN_RVA(0xDADDBu))) { return; }
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DADFEu)); sfera_sub_004D9140(cpu, LIFT_CODE_TOKEN_VA(0x4DADFEu));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000DAE12;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAE0Eu), LIFT_CODE_TOKEN_RVA(0xDAE0Cu))) { return; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_000DAE12:
    lift_x87_push(cpu, (double)-0.5f);
    cpu->ebp = (uint32_t)(cpu->ebx + 0xCu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    cpu->esi = (uint32_t)(cpu->esp + 0x14u);
    lift_x87_push(cpu, 1.0);
    cpu->edi = cpu->ebp;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edi = (uint32_t)(cpu->ebx + 0x2Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x38u)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->ebx + 0x4Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    cpu->edi = (uint32_t)(cpu->ebx + 0x6Cu);
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_movs32(cpu, 1u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAF24u)); sfera_sub_004D87E0(cpu, LIFT_CODE_TOKEN_VA(0x4DAF24u));
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 2u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAF36u)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4DAF36u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAF50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 4u)) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000DAF6D;
    lift_store8(cpu->ecx + 8u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000DAF68;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAF65u)); sfera_sub_004DAA60(cpu, LIFT_CODE_TOKEN_VA(0x4DAF65u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DAF68:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDAF6Du)); sfera_sub_004DAD30(cpu, LIFT_CODE_TOKEN_RVA(0xDAF6Du));
    label_000DAF6D:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAF70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAF84u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4DAF84u));
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAF91u)); sfera_sub_004DD550(cpu, LIFT_CODE_TOKEN_VA(0x4DAF91u));
    cpu->ecx = lift_load32(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAF9Fu)); sfera_sub_004DADA0(cpu, LIFT_CODE_TOKEN_VA(0x4DAF9Fu));
    cpu->edx = lift_load32(cpu->esi + 0x8Cu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAFB3u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4DAFB3u));
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAFC0u)); sfera_sub_004DD550(cpu, LIFT_CODE_TOKEN_VA(0x4DAFC0u));
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAFCEu)); sfera_sub_004DADA0(cpu, LIFT_CODE_TOKEN_VA(0x4DAFCEu));
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAFE2u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4DAFE2u));
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAFEFu)); sfera_sub_004DD550(cpu, LIFT_CODE_TOKEN_VA(0x4DAFEFu));
    cpu->edx = lift_load32(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAFFDu)); sfera_sub_004DADA0(cpu, LIFT_CODE_TOKEN_VA(0x4DAFFDu));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB005u)); sfera_sub_004DAD30(cpu, LIFT_CODE_TOKEN_VA(0x4DB005u));
    cpu->eax = g_sfera_d3d9_semantic_state.vertex_declaration;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DB020;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDB016u), LIFT_CODE_TOKEN_RVA(0xDB014u))) { return; }
    g_sfera_d3d9_semantic_state.vertex_declaration = (uint32_t)(0u);
    label_000DB020:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB030(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000DB030;
    label_000DAC40:
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_000DAC43:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC53u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DAC53u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC63u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DAC63u));
    cpu->eax = g_sfera_d3d9_semantic_state.sampler_min_filter;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 6u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC77u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DAC77u));
    cpu->ecx = g_sfera_d3d9_semantic_state.sampler_mag_filter;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 5u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DAC8Cu)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DAC8Cu));
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_mip_filter;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 7u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DACA1u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x4DACA1u));
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(2u)) goto label_000DAC43;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 7u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DACB6u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x4DACB6u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DACC5u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x4DACC5u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000DB030:
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->ebx + 8u)) == (uint8_t)(0u)) goto label_000DB1EA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB045u)); sfera_sub_004DABA0(cpu, LIFT_CODE_TOKEN_VA(0x4DB045u));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB04Cu)); sfera_sub_004DAF70(cpu, LIFT_CODE_TOKEN_VA(0x4DB04Cu));
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB05Cu)); sfera_sub_004D9140(cpu, LIFT_CODE_TOKEN_VA(0x4DB05Cu));
    cpu->eax = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DB070;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDB06Au), LIFT_CODE_TOKEN_RVA(0xDB068u))) { return; }
    lift_store32(cpu->ebx, 0u);
    label_000DB070:
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB084u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4DB084u));
    cpu->ecx = lift_load32(cpu->ebx + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB098u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x4DB098u));
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 9u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB0A5u)); sfera_sub_004DD550(cpu, LIFT_CODE_TOKEN_VA(0x4DB0A5u));
    lift_x87_push(cpu, (double)-0.5f);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    cpu->eax = g_sfera_graphics_runtime.display_height;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_x87_push(cpu, 1.0);
    cpu->ebp = (uint32_t)(cpu->ebx + 0xCu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_x87_push(cpu, 0.0);
    cpu->edi = cpu->ebp;
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edi = (uint32_t)(cpu->ebx + 0x2Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->ebx + 0x4Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    cpu->edi = (uint32_t)(cpu->ebx + 0x6Cu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = 8u;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_movs32(cpu, 1u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB1CAu)); sfera_sub_004D87E0(cpu, LIFT_CODE_TOKEN_VA(0x4DB1CAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB1DCu)); sfera_sub_004D9050(cpu, LIFT_CODE_TOKEN_VA(0x4DB1DCu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    goto label_000DAC40;
    label_000DB1EA:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    cpu->edi = 0u;
    --cpu->esi;
    label_000DB202:
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x40u)) goto label_000DB236;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"CShaderMgr::calc_inst_code: to many PIN's in %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x20u, 0x59u);
    lift_store32(cpu->esp + 0x24u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB233u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DB233u));
    cpu->esp += 0xCu;
    label_000DB236:
    cpu->eax = (int8_t)(lift_load8(cpu->esi + 1u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (int8_t)(lift_load8(cpu->esi + 2u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFDF0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB250u)); sfera_sub_004EEDF0(cpu, LIFT_CODE_TOKEN_VA(0x4DB250u));
    cpu->esi += 3u;
    cpu->ebx |= cpu->eax;
    cpu->ebp |= cpu->edx;
    cpu->edi += 8u;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x5Fu)) goto label_000DB202;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x24u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DB26E;
    cpu->ebx |= 0x80u;
    label_000DB26E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ebx + 0x18u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDB29Cu), LIFT_CODE_TOKEN_RVA(0xDB29Au))) { return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000DB2CD;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"No constant %s in shader"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x1Cu, 0x142u);
    lift_store32(cpu->esp + 0x20u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB2CAu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DB2CAu));
    cpu->esp += 0xCu;
    label_000DB2CD:
    cpu->eax = lift_load32(cpu->ebx + 0x18u);
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x30u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDB2EDu), LIFT_CODE_TOKEN_RVA(0xDB2EBu))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DB31C;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"ID3DXConstantTable::SetValue failed. %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x1Cu, 0x146u);
    lift_store32(cpu->esp + 0x20u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB319u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DB319u));
    cpu->esp += 0xCu;
    label_000DB31C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x68u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    cpu->esi = 0u;
    label_000DB350:
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDB352u), LIFT_CODE_TOKEN_RVA(0xDB350u))) { return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.2831854820251465));
    lift_store_f32(cpu->esp + cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDB36Cu), LIFT_CODE_TOKEN_RVA(0xDB36Au))) { return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->esi += 4u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_store_f32(cpu->esp + cpu->esi + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x28u)) goto label_000DB350;
    lift_x87_push(cpu, (double)-1.0f);
    cpu->ebx = 0u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ebp += 0x120u;
    label_000DB3A2:
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->esi = 0u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.012271846644580364));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB3C0:
    cpu->edi = (uint32_t)(cpu->esi + 1u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x24u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB3E0u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x4DB3E0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x4Cu))));
    cpu->esi = cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xAu)) goto label_000DB3C0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000DB427;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000DB429;
    label_000DB427:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB429:
    ++cpu->ebx;
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x200u)) goto label_000DB3A2;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, 1.0);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax += 0x124u;
    cpu->ecx = 0x40u;
    cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    label_000DB45D:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    cpu->eax += 0x20u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFE0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFE4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0xFFFFFFE8u))));
    lift_store_f32(cpu->eax + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->eax + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0xFFFFFFF8u))));
    lift_store_f32(cpu->eax + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DB45D;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x68u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB4C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.3400000035762787f);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, (double)0.6600000262260437f);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_000DB533;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_000DB533;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.3499999940395355f);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000DB675;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.30000001192092896);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB51Du)); sfera_sub_004EE9FE(cpu, LIFT_CODE_TOKEN_VA(0x4DB51Du));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DB533:
    lift_x87_push(cpu, (double)0.1899999976158142f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_000DB629;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.8100000023841858);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_000DB62D;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000DB5C6;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.1899999976158142));
    lift_x87_push(cpu, 0.15000000596046448);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) / (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.19999998807907104));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000DB675;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.30000001192092896);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB5B0u)); sfera_sub_004EE9FE(cpu, LIFT_CODE_TOKEN_VA(0x4DB5B0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DB5C6:
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000DB673;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.6600000262260437));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (0.15000000596046448));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.19999998807907104));
    lift_x87_set(cpu, 0u, (0.3499999940395355) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000DB675;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.30000001192092896);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB613u)); sfera_sub_004EE9FE(cpu, LIFT_CODE_TOKEN_VA(0x4DB613u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DB629:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000DB62F;
    label_000DB62D:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB62F:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000DB675;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.30000001192092896);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB65Du)); sfera_sub_004EE9FE(cpu, LIFT_CODE_TOKEN_VA(0x4DB65Du));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.30000001192092896));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DB673:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB675:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x84u;
    lift_x87_push(cpu, (double)1.5f);
    cpu->eax = 0u;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    cpu->ecx += 0x924u;
    lift_x87_push(cpu, (double)-1.5f);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)-0.5f);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)0.5f);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    label_000DB747:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u)));
    cpu->eax += 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    cpu->ecx += 0x40u;
    lift_store_f32(cpu->ecx + 0xFFFFFFBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFC4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFC8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFCCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFDCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFE0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFDCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFE4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFF4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->ecx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x10u)) goto label_000DB747;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x84u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DB810:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DB810;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x14u)) goto label_000DB87B;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\sphereclient\\dx9render\\..\\..\\Service\\Containers\\Sstr.h");
    lift_store32(cpu->esp + 0x18u, 0x6Du);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB846u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DB846u));
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi + 0x10u)) & 0xFFFFu);
    lift_store16(cpu->esi + 0x10u, cpu->edx & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x12u)) & 0xFFu);
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + 0x12u, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0x13u, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DB87B:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DB87Fu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->esi;
    cpu->ebx = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DB8B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DB8B0;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x80u)) goto label_000DB907;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\sphereclient\\dx9render\\..\\..\\Service\\Containers\\Sstr.h");
    lift_store32(cpu->esp + 0x1Cu, 0x6Du);
    lift_store32(cpu->esp + 0x20u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB8E9u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DB8E9u));
    cpu->edi = cpu->ebx;
    cpu->ecx = 0x1Fu;
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->esp += 0xCu;
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ebx + 0x7Fu, 0u);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DB907:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DB90Bu));
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->esi;
    cpu->ebx = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DB930:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DB930;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x94u)) goto label_000DB98A;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\sphereclient\\dx9render\\..\\..\\Service\\Containers\\Sstr.h");
    lift_store32(cpu->esp + 0x1Cu, 0x6Du);
    lift_store32(cpu->esp + 0x20u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DB969u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DB969u));
    cpu->edi = cpu->ebx;
    cpu->ecx = 0x24u;
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->esp += 0xCu;
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ebx + 0x93u, 0u);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DB98A:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DB98Eu));
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB9A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store16(cpu->ecx + 0x5Au, cpu->eax & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000DB9F1;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000DB9C0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000DB9D0;
    cpu->edx = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]) & 0xFFu);
    label_000DB9D0:
    cpu->ebp = lift_load32(cpu->ecx + 0x10u);
    lift_store8(cpu->eax + cpu->ebp, cpu->edx & 0xFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + 0x5Au)) & 0xFFFFu);
    cpu->edx = cpu->edx & 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_shift_right(cpu, (cpu->ebp & 0xFFFFu), (uint32_t)(1u), 16u)) & 0xFFFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebp & 0xFFFFu)) + (uint64_t)(g_sfera_string_lookup_runtime.hash_mix[(uint8_t)cpu->edx]) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    lift_store16(cpu->ecx + 0x5Au, cpu->ebp & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_000DB9C0;
    label_000DB9F1:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + 0x20u)) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) - 1u)) & 0xFFFFu);
    lift_store16(cpu->ecx + 0x5Au, (uint64_t)(lift_load16(cpu->ecx + 0x5Au)) & (uint64_t)((cpu->eax & 0xFFFFu)));
    cpu->edx = lift_load16(cpu->ecx + 0x5Au);
    cpu->eax = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load16(cpu->ecx + 0x1Cu);
    lift_store16(cpu->ecx + 0x4Cu, cpu->eax & 0xFFFFu);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_000DBAF5;
    cpu->ebx = lift_load32(cpu->ecx + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->eax += lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->ecx + 0x54u, 0u);
    lift_store32(cpu->ecx + 0x50u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + 0x20u)) & 0xFFFFu);
    lift_store16(cpu->ecx + 0x58u, cpu->eax & 0xFFFFu);
    label_000DBA32:
    cpu->ebp = lift_load32(cpu->ecx + 0x50u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x1Cu)) != (uint32_t)(cpu->esi)) goto label_000DBA8C;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->esi;
    cpu->esi = lift_load32(cpu->ecx + 0x10u);
    cpu->edi = (uint32_t)(cpu->ebp + 0x22u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000DBA64;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000DBA50:
    cpu->edx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_000DBA88;
    cpu->eax -= 4u;
    cpu->esi += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000DBA50;
    label_000DBA64:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DBABA;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi))) goto label_000DBA88;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_000DBABA;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi + 1u))) goto label_000DBA88;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(2u)) goto label_000DBABA;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 2u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(lift_load8(cpu->edi + 2u))) goto label_000DBABA;
    label_000DBA88:
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000DBA8C:
    cpu->edx = lift_load16(cpu->ecx + 0x58u);
    cpu->eax = lift_load16(cpu->ecx + 0x1Cu);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) == (uint16_t)((cpu->eax & 0xFFFFu))) goto label_000DBAF5;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->edx;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ebx);
    cpu->eax += cpu->edi;
    lift_store32(cpu->ecx + 0x54u, cpu->ebp);
    lift_store32(cpu->ecx + 0x50u, cpu->eax);
    lift_store16(cpu->ecx + 0x4Cu, cpu->edx & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + 0x20u)) & 0xFFFFu);
    lift_store16(cpu->ecx + 0x58u, cpu->edx & 0xFFFFu);
    goto label_000DBA32;
    label_000DBABA:
    cpu->eax = lift_load32(cpu->ecx + 0x54u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DBAEA;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp + 0x20u)) & 0xFFFFu);
    lift_store16(cpu->eax + 0x20u, cpu->edx & 0xFFFFu);
    cpu->eax = lift_load16(cpu->ecx + 0x5Au);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 2u))) & 0xFFFFu);
    cpu->esi = lift_load32(cpu->ecx + 0x50u);
    lift_store16(cpu->esi + 0x20u, cpu->eax & 0xFFFFu);
    cpu->edx = lift_load16(cpu->ecx + 0x5Au);
    cpu->eax = lift_load32(cpu->ecx + 0x18u);
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + 0x4Cu)) & 0xFFFFu);
    lift_store16(cpu->eax + ((uint32_t)(cpu->edx) * 2u), cpu->esi & 0xFFFFu);
    label_000DBAEA:
    cpu->eax = lift_load16(cpu->ecx + 0x4Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000DBAF5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBB00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000DBB42;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, (uintptr_t)"SSTR::append: wrong count=%d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\sphereclient\\dx9render\\..\\..\\Service\\Containers\\Sstr.h");
    lift_store32(cpu->esp + 0x14u, 0xC0u);
    lift_store32(cpu->esp + 0x18u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBB36u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DBB36u));
    cpu->esp += 0xCu;
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000DBB42:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000DBB50:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DBB50;
    cpu->eax -= cpu->esi;
    cpu->ecx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000DBB61;
    cpu->ecx = cpu->edx;
    label_000DBB61:
    cpu->eax = cpu->ebx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000DBB66:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000DBB66;
    cpu->eax -= cpu->esi;
    cpu->edi = cpu->eax;
    cpu->esi = (uint32_t)(cpu->edi + cpu->ecx + 1u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(0x94u)) goto label_000DBBB3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"SSTR::append: buffer overflow!"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\sphereclient\\dx9render\\..\\..\\Service\\Containers\\Sstr.h");
    lift_store32(cpu->esp + 0x1Cu, 0xCBu);
    lift_store32(cpu->esp + 0x20u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBBA4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DBBA4u));
    cpu->ecx = 0x93u;
    cpu->esp += 8u;
    cpu->ecx -= cpu->edi;
    cpu->esi = 0x94u;
    label_000DBBB3:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edi += cpu->ebx;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DBBB8u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + cpu->ebx + 0xFFFFFFFFu, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esi + 0x28u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000DBC26;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::init: wrong _startSize=%d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0x9Au);
    lift_store32(cpu->esp + 0x20u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBC23u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DBC23u));
    cpu->esp += 0xCu;
    label_000DBC26:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(1u)) goto label_000DBC5B;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"HashMap::init: wrong _maxKeyLen=%d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x20u, 0x9Bu);
    lift_store32(cpu->esp + 0x24u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBC58u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DBC58u));
    cpu->esp += 0xCu;
    label_000DBC5B:
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = 1u;
    cpu->eax = 0u;
    label_000DBC66:
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000DBC72;
    ++cpu->eax;
    cpu->ecx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x20u)) goto label_000DBC66;
    label_000DBC72:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x20u)) goto label_000DBCA1;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::init:  hashTabSize must be power of 2"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0xA2u);
    lift_store32(cpu->esp + 0x20u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBC9Eu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DBC9Eu));
    cpu->esp += 8u;
    label_000DBCA1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBCA6u)); sfera_sub_004ED5C0(cpu, LIFT_CODE_TOKEN_VA(0x4DBCA6u));
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000DBCB3;
    lift_store32(cpu->esi + 0x48u, cpu->eax);
    goto label_000DBCBA;
    label_000DBCB3:
    lift_store32(cpu->esi + 0x48u, (uintptr_t)&g_sfera_std_allocator);
    label_000DBCBA:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x24u)) & 0xFFu);
    cpu->eax = 0xFFFFu;
    lift_store16(cpu->esi + 0x1Cu, cpu->eax & 0xFFFFu);
    cpu->eax = 0u;
    lift_store16(cpu->esi + 0x14u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esi, cpu->ebp);
    lift_store8(cpu->esi + 0x1Eu, cpu->ecx & 0xFFu);
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->ebp + 0x23u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    lift_store32(cpu->esi + 0x34u, cpu->eax);
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000DBD03;
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    goto label_000DBD1D;
    label_000DBD03:
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 8u), 32u, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0x14u)) goto label_000DBD1D;
    lift_store32(cpu->esi + 0xCu, 0x14u);
    label_000DBD1D:
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    cpu->ecx = lift_load32(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x48u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x48u);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DBD57u));
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->esp += 0xCu;
    --cpu->ecx;
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000DBD97;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000DBD70:
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store16(cpu->ecx + cpu->edi + 0x20u, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    lift_store32(cpu->edx + cpu->ecx + 0x1Cu, cpu->ebx);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    ++cpu->eax;
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000DBD70;
    label_000DBD97:
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = (cpu->edi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0x1Cu)) & 0xFFFFu);
    lift_store16(cpu->ecx + cpu->edx + 0x20u, cpu->edi & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx + cpu->edx + 0x1Cu, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBDD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DBDE6;
    lift_store32(cpu->eax, 0u);
    label_000DBDE6:
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = 1u;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000DBE03;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x1Eu)) != (uint8_t)(0u)) goto label_000DBE03;
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    goto label_000DBE0C;
    label_000DBE03:
    lift_store8(cpu->esp + 0x20u, 0u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000DBE20;
    label_000DBE0C:
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DBE11:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DBE11;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->edi = cpu->eax;
    label_000DBE20:
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(lift_load32(cpu->ebp))) goto label_000DBE58;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::insert: maxKeyLen exceed"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0x129u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBE48u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DBE48u));
    cpu->esp += 8u;
    label_000DBE4B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000DBE58:
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBE66u)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DBE66u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000DBE4B;
    cpu->eax = lift_load16(cpu->ebp + 0x1Cu);
    if ((uint16_t)(lift_load16(cpu->ebp + 0x14u)) != (uint16_t)((cpu->eax & 0xFFFFu))) goto label_000DBF60;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000DBEB5;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::insert: more than maxIndexVal elements"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0x134u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DBEA5u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DBEA5u));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000DBEB5:
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = cpu->eax;
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(1u), 32u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0xAu)) goto label_000DBEC6;
    cpu->esi = 0xAu;
    label_000DBEC6:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp + 0xCu)) & 0xFFFFu);
    lift_store32(cpu->ebp + 0xCu, (uint64_t)(lift_load32(cpu->ebp + 0xCu)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    lift_store16(cpu->ebp + 0x14u, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000DBEE1;
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->esi += cpu->edx;
    lift_store32(cpu->ebp + 0xCu, cpu->ecx);
    label_000DBEE1:
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    cpu->ecx = lift_load32(cpu->ebp + 0x48u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->reallocate(cpu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000DBF35;
    label_000DBF05:
    cpu->ecx = lift_load16(cpu->ebp + 0x14u);
    cpu->ebx = lift_load32(cpu->ebp + 4u);
    cpu->esi = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    lift_store16(cpu->ecx + cpu->ebx + 0x20u, cpu->esi & 0xFFFFu);
    cpu->ecx = lift_load16(cpu->ebp + 0x14u);
    cpu->esi = lift_load32(cpu->ebp + 4u);
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    ++cpu->eax;
    lift_store32(cpu->ecx + cpu->esi + 0x1Cu, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000DBF05;
    label_000DBF35:
    cpu->edx = lift_load16(cpu->ebp + 0x14u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp + 0x1Cu)) & 0xFFFFu);
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    lift_store16(cpu->edx + cpu->ecx + 0x20u, cpu->esi & 0xFFFFu);
    cpu->edx = lift_load16(cpu->ebp + 0x14u);
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->edx + cpu->eax + 0x1Cu, 0u);
    label_000DBF60:
    cpu->ebx = lift_load16(cpu->ebp + 0x14u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    cpu->ebx += lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x22u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DBF74u));
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    lift_store8(cpu->ebx + cpu->edi + 0x22u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebx + 0x20u)) & 0xFFFFu);
    cpu->eax = lift_load16(cpu->ebp + 0x14u);
    lift_store16(cpu->ebp + 0x14u, cpu->ecx & 0xFFFFu);
    cpu->ecx = 0u;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_000DBFA6;
    cpu->ecx = 7u;
    cpu->edi = cpu->ebx;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    goto label_000DBFAE;
    label_000DBFA6:
    lift_store8(cpu->ebx, cpu->ecx & 0xFFu);
    lift_store32(cpu->ebx + 0x14u, cpu->ecx);
    lift_store32(cpu->ebx + 0x18u, cpu->ecx);
    label_000DBFAE:
    cpu->edx = lift_load16(cpu->ebp + 0x5Au);
    cpu->ecx = lift_load32(cpu->ebp + 0x18u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u))) & 0xFFFFu);
    lift_store32(cpu->ebx + 0x1Cu, cpu->edi);
    lift_store16(cpu->ebx + 0x20u, cpu->edx & 0xFFFFu);
    cpu->ecx = lift_load16(cpu->ebp + 0x5Au);
    cpu->edx = lift_load32(cpu->ebp + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store16(cpu->edx + ((uint32_t)(cpu->ecx) * 2u), cpu->eax & 0xFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBFE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xECu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load8((uint32_t)(uintptr_t)&g_sfera_alpha_material_runtime.option_b);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8((uint32_t)(uintptr_t)&g_sfera_alpha_material_runtime.option_a)) & 0xFFu);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32((uint32_t)(uintptr_t)&g_sfera_alpha_material_runtime.selected_slot)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8((uint32_t)(uintptr_t)&g_sfera_alpha_material_runtime.option_c)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0xE0u, 0x80u);
    lift_store8(cpu->esp + 0xE1u, cpu->ecx & 0xFFu);
    lift_store8(cpu->esp + 0xE2u, cpu->edx & 0xFFu);
    lift_store8(cpu->esp + 0xE3u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0xE4u, cpu->eax & 0xFFu);
    lift_store16(cpu->esp + 0xE5u, 0u);
    lift_store8(cpu->esp + 0xE7u, 0u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DC09D;
    lift_push32(cpu, 0u); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC08Du)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DC08Du));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC09D;
    cpu->edi = lift_load32(cpu->esi + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi += lift_load32(cpu->esi + 4u);
    goto label_000DC0A0;
    label_000DC09D:
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    label_000DC0A0:
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = (uint32_t)(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC0F7;
    cpu->edx = lift_load8(cpu->esp + 0xE2u);
    cpu->eax = lift_load8(cpu->esp + 0xE1u);
    cpu->ecx = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x34u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x38u, 0xF6u);
    lift_store32(cpu->esp + 0x3Cu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC0F4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DC0F4u));
    cpu->esp += 0x1Cu;
    label_000DC0F7:
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->edi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC195;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store8(cpu->esp + 0x50u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC119u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DC119u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC128u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC128u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC13Bu)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC13Bu));
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC149u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DC149u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0xF4u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC15Du)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DC15Du));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC170u)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DC170u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC17Du)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DC17Du));
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0xF4u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC191u)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_VA(0x4DC191u));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    label_000DC195:
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC1A3u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DC1A3u));
    cpu->ecx = lift_load32(cpu->esp + 0xECu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC1D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xD0u, 0x83u);
    lift_store32(cpu->esp + 0xD4u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DC24B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC23Bu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DC23Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC24B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC24E;
    label_000DC24B:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC24E:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) != (uint32_t)(0xFFFFFFFFu)) goto label_000DC297;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x83u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0xECu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0xF0u, 0xF6u);
    lift_store32(cpu->esp + 0xF4u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC294u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DC294u));
    cpu->esp += 0x1Cu;
    label_000DC297:
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_000DC32A;
    cpu->edx = (uint32_t)(cpu->ebp + 0xA0u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x40u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC2B4u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DC2B4u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC2C3u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC2C3u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC2D6u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC2D6u));
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC2E4u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DC2E4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC2F4u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DC2F4u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC306u)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DC306u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC316u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DC316u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDC32Au)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDC32Au));
    label_000DC32A:
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC339u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DC339u));
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_alpha_material_runtime.alpha[0]); lift_push32(cpu, (uintptr_t)"gAlpha"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC34Du)); sfera_sub_004DB280(cpu, LIFT_CODE_TOKEN_VA(0x4DC34Du));
    cpu->ecx = lift_load32(cpu->esp + 0xE0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC380(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x82u);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DC3FB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC3EBu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DC3EBu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC3FB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC3FE;
    label_000DC3FB:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC3FE:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC445;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x82u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC442u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DC442u));
    cpu->esp += 0x1Cu;
    label_000DC445:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC4DC;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC465u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DC465u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC474u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC474u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC487u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC487u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC495u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DC495u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC4A5u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DC4A5u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC4BBu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DC4BBu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC4C8u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DC4C8u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDC4DCu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDC4DCu));
    label_000DC4DC:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC4F1u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DC4F1u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC520(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xECu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x81u);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DC59B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC58Bu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DC58Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC59B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC59E;
    label_000DC59B:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC59E:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC5EA;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x81u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0xF0u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0xF8u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0xFCu, 0xF6u);
    lift_store32(cpu->esp + 0x100u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC5E7u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DC5E7u));
    cpu->esp += 0x1Cu;
    label_000DC5EA:
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_000DC67A;
    cpu->edx = (uint32_t)(cpu->ebp + 0xA0u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC607u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DC607u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC616u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC616u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC629u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC629u));
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC637u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DC637u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF4u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC647u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DC647u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC656u)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DC656u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC666u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DC666u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF4u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDC67Au)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDC67Au));
    label_000DC67A:
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC688u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DC688u));
    lift_x87_push(cpu, 0.0);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC6A0u)); sfera_sub_004DB4C0(cpu, LIFT_CODE_TOKEN_VA(0x4DC6A0u));
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"gWaterGradientCoefficient"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC6B4u)); sfera_sub_004DB280(cpu, LIFT_CODE_TOKEN_VA(0x4DC6B4u));
    lift_push32(cpu, 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"gWaterSpecular"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC6C8u)); sfera_sub_004DB280(cpu, LIFT_CODE_TOKEN_VA(0x4DC6C8u));
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"gWaterReflectCoefficient"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC6DCu)); sfera_sub_004DB280(cpu, LIFT_CODE_TOKEN_VA(0x4DC6DCu));
    cpu->ecx = lift_load32(cpu->esp + 0xECu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC710(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x84u);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DC78B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC77Bu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DC77Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC78B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC78E;
    label_000DC78B:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC78E:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC7D5;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x84u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC7D2u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DC7D2u));
    cpu->esp += 0x1Cu;
    label_000DC7D5:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC86C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC7F5u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DC7F5u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC804u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC804u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC817u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC817u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC825u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DC825u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC835u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DC835u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC84Bu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DC84Bu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC858u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DC858u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDC86Cu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDC86Cu));
    label_000DC86C:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC881u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DC881u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC8B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x85u);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DC92B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC91Bu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DC91Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC92B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC92E;
    label_000DC92B:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC92E:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC975;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x85u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC972u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DC972u));
    cpu->esp += 0x1Cu;
    label_000DC975:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCA0C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC995u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DC995u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC9A4u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC9A4u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC9B7u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DC9B7u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC9C5u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DC9C5u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC9D5u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DC9D5u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC9EBu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DC9EBu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DC9F8u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DC9F8u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDCA0Cu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDCA0Cu));
    label_000DCA0C:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCA21u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DCA21u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCA50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xD0u, 0x86u);
    lift_store32(cpu->esp + 0xD4u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DCACB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCABBu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DCABBu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCACB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCACE;
    label_000DCACB:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCACE:
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) != (uint32_t)(0xFFFFFFFFu)) goto label_000DCB17;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x86u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0xECu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0xF0u, 0xF6u);
    lift_store32(cpu->esp + 0xF4u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB14u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DCB14u));
    cpu->esp += 0x1Cu;
    label_000DCB17:
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_000DCBAA;
    cpu->edx = (uint32_t)(cpu->ebp + 0xA0u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x40u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB34u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DCB34u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB43u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DCB43u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB56u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DCB56u));
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB64u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DCB64u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB74u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DCB74u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB86u)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DCB86u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCB96u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DCB96u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDCBAAu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDCBAAu));
    label_000DCBAA:
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCBB9u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DCBB9u));
    lift_push32(cpu, 0x80u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x920u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"gTexelCoordsDownFilter"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCBD2u)); sfera_sub_004DB280(cpu, LIFT_CODE_TOKEN_VA(0x4DCBD2u));
    cpu->ecx = lift_load32(cpu->esp + 0xE0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCC00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x87u);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DCC7B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCC6Bu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DCC6Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCC7B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCC7E;
    label_000DCC7B:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCC7E:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCCC5;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x87u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCCC2u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DCCC2u));
    cpu->esp += 0x1Cu;
    label_000DCCC5:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCD5C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCCE5u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DCCE5u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCCF4u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DCCF4u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCD07u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DCD07u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCD15u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DCD15u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCD25u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DCD25u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCD3Bu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DCD3Bu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCD48u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DCD48u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDCD5Cu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDCD5Cu));
    label_000DCD5C:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCD71u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DCD71u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCDA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x88u);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DCE1B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCE0Bu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DCE0Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCE1B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCE1E;
    label_000DCE1B:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCE1E:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCE65;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x88u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCE62u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DCE62u));
    cpu->esp += 0x1Cu;
    label_000DCE65:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCEFC;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCE85u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DCE85u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCE94u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DCE94u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCEA7u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DCEA7u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCEB5u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DCEB5u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCEC5u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DCEC5u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCEDBu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DCEDBu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCEE8u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DCEE8u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDCEFCu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDCEFCu));
    label_000DCEFC:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCF11u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DCF11u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCF40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x89u);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DCFBB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DCFABu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DCFABu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCFBB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCFBE;
    label_000DCFBB:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCFBE:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD005;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x89u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD002u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DD002u));
    cpu->esp += 0x1Cu;
    label_000DD005:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD09C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD025u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DD025u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD034u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DD034u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD047u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DD047u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD055u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DD055u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD065u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DD065u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD07Bu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DD07Bu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD088u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DD088u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDD09Cu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDD09Cu));
    label_000DD09C:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD0B1u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DD0B1u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD0E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x8Cu);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DD15B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD14Bu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DD14Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DD15B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DD15E;
    label_000DD15B:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DD15E:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD1A5;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x8Cu); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD1A2u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DD1A2u));
    cpu->esp += 0x1Cu;
    label_000DD1A5:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD23C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD1C5u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DD1C5u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD1D4u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DD1D4u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD1E7u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DD1E7u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD1F5u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DD1F5u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD205u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DD205u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD21Bu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DD21Bu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD228u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DD228u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDD23Cu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDD23Cu));
    label_000DD23C:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD251u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DD251u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD280(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xD4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xDCu, 0x8Du);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000DD2FB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD2EBu)); sfera_sub_004DB9A0(cpu, LIFT_CODE_TOKEN_VA(0x4DD2EBu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DD2FB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DD2FE;
    label_000DD2FB:
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DD2FE:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0xDCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD345;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x8Du); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x34u, 0xF6u);
    lift_store32(cpu->esp + 0x38u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD342u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DD342u));
    cpu->esp += 0x1Cu;
    label_000DD345:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD3DC;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD365u)); sfera_sub_004DB920(cpu, LIFT_CODE_TOKEN_VA(0x4DD365u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD374u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DD374u));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD387u)); sfera_sub_004DBB00(cpu, LIFT_CODE_TOKEN_VA(0x4DD387u));
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD395u)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x4DD395u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD3A5u)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x4DD3A5u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD3BBu)); sfera_sub_004D8D30(cpu, LIFT_CODE_TOKEN_VA(0x4DD3BBu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD3C8u)); sfera_sub_004D8CB0(cpu, LIFT_CODE_TOKEN_VA(0x4DD3C8u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xDD3DCu)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0xDD3DCu));
    label_000DD3DC:
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD3F1u)); sfera_sub_004D8E20(cpu, LIFT_CODE_TOKEN_VA(0x4DD3F1u));
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x15Cu;
    cpu->eax = lift_load32(cpu->esp + 0x160u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x4DD445u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_000DD52F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x174u);
    cpu->ebx = 0u;
    label_000DD464:
    if ((uint8_t)((lift_load8(cpu->esp + 0x40u)) & (0x10u)) != 0u) goto label_000DD50C;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD47Cu)); sfera_sub_004DB1F0(cpu, LIFT_CODE_TOKEN_VA(0x4DD47Cu));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store8(cpu->esp + 0x28u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD49Eu)); sfera_sub_004DB800(cpu, LIFT_CODE_TOKEN_VA(0x4DD49Eu));
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DD4A5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000DD4A5;
    cpu->eax -= cpu->edx;
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000DD4CA;
    label_000DD4B3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x24u)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x5Cu)) goto label_000DD4CA;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_000DD4C6;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000DD4B3;
    goto label_000DD4CA;
    label_000DD4C6:
    lift_store8(cpu->esp + cpu->eax + 0x24u, cpu->ebx & 0xFFu);
    label_000DD4CA:
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD4DDu)); sfera_sub_004DBDD0(cpu, LIFT_CODE_TOKEN_VA(0x4DD4DDu));
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000DD50C;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"CShaderMgr::load_folder: duplicate shader code"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x24u, 0x7Bu);
    lift_store32(cpu->esp + 0x28u, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD509u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DD509u));
    cpu->esp += 8u;
    label_000DD50C:
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x4DD512u));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DD464;
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4DD524u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000DD52F:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x15Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xDu)) goto label_000DD5EB;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000DD567;
        case 1u: goto label_000DD572;
        case 2u: goto label_000DD57D;
        case 3u: goto label_000DD588;
        case 4u: goto label_000DD593;
        case 5u: goto label_000DD59E;
        case 6u: goto label_000DD5A9;
        case 7u: goto label_000DD5B4;
        case 8u: goto label_000DD5BF;
        case 9u: goto label_000DD5CA;
        case 10u: case 11u: goto label_000DD616;
        case 12u: goto label_000DD5D5;
        case 13u: goto label_000DD5E0;
        default: lift_trap(cpu, 0x4DD560u, "resolved jump-table index out of range"); return;
    }
label_000DD567: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD56Cu)); sfera_sub_004DBFE0(cpu, LIFT_CODE_TOKEN_VA(0x4DD56Cu));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD572:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD577u)); sfera_sub_004DC520(cpu, LIFT_CODE_TOKEN_VA(0x4DD577u));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD57D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD582u)); sfera_sub_004DC380(cpu, LIFT_CODE_TOKEN_VA(0x4DD582u));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD588:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD58Du)); sfera_sub_004DC1D0(cpu, LIFT_CODE_TOKEN_VA(0x4DD58Du));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD593:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD598u)); sfera_sub_004DC710(cpu, LIFT_CODE_TOKEN_VA(0x4DD598u));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD59E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD5A3u)); sfera_sub_004DC8B0(cpu, LIFT_CODE_TOKEN_VA(0x4DD5A3u));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD5A9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD5AEu)); sfera_sub_004DCA50(cpu, LIFT_CODE_TOKEN_VA(0x4DD5AEu));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD5B4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD5B9u)); sfera_sub_004DCC00(cpu, LIFT_CODE_TOKEN_VA(0x4DD5B9u));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD5BF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD5C4u)); sfera_sub_004DCDA0(cpu, LIFT_CODE_TOKEN_VA(0x4DD5C4u));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD5CA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD5CFu)); sfera_sub_004DCF40(cpu, LIFT_CODE_TOKEN_VA(0x4DD5CFu));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD5D5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD5DAu)); sfera_sub_004DD0E0(cpu, LIFT_CODE_TOKEN_VA(0x4DD5DAu));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD5E0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD5E5u)); sfera_sub_004DD280(cpu, LIFT_CODE_TOKEN_VA(0x4DD5E5u));
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000DD5EB:
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, (uintptr_t)"CShaderMgr::set_ps: unknown psg = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x10u, 0xB6u);
    lift_store32(cpu->esp + 0x14u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD613u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4DD613u));
    cpu->esp += 0xCu;
    label_000DD616:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD660(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x420u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x434u);
    cpu->ebx = lift_load32(cpu->esp + 0x430u);
    cpu->ebp = cpu->ecx;
    cpu->esi = (uint32_t)(cpu->ebp + 4u);
    cpu->edi = 0u;
    lift_store8(cpu->esi, 0u);
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, cpu->edi);
    lift_store8(cpu->ebp + 0x20u, 0u);
    cpu->edx = (uint32_t)(cpu->edi + 0x2Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"dx9Render\\ShaderMgr.cpp";
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store8(cpu->ebp + 0xA0u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD6D5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4DD6D5u));
    lift_push32(cpu, 0x5Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD6DCu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4DD6DCu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x428u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000DD702;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x10000u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 8u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD700u)); sfera_sub_004DBBE0(cpu, LIFT_CODE_TOKEN_VA(0x4DD700u));
    goto label_000DD704;
    label_000DD702:
    cpu->eax = 0u;
    label_000DD704:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x428u, cpu->ecx);
    lift_store32(cpu->ebp + 0x18u, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->eax + 0x28u);
    lift_store32(cpu->ebp, cpu->eax);
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD727u)); sfera_sub_004DB8A0(cpu, LIFT_CODE_TOKEN_VA(0x4DD727u));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xA0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD737u)); sfera_sub_004DB8A0(cpu, LIFT_CODE_TOKEN_VA(0x4DD737u));
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    (void)cpu;
    label_000DD740:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DD740;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    --cpu->eax;
    (void)cpu;
    label_000DD750:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DD750;
    cpu->ecx = lift_load32((uintptr_t)"*.vsc");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"*.vsc") + 4u)) & 0xFFFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store16(cpu->eax + 4u, cpu->edx & 0xFFFFu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD779u)); sfera_sub_004DD420(cpu, LIFT_CODE_TOKEN_VA(0x4DD779u));
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_000DD781:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DD781;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    --cpu->eax;
    label_000DD790:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DD790;
    cpu->ecx = lift_load32((uintptr_t)"*.psc");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"*.psc") + 4u)) & 0xFFFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store16(cpu->eax + 4u, cpu->edx & 0xFFFFu);
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD7B9u)); sfera_sub_004DD420(cpu, LIFT_CODE_TOKEN_VA(0x4DD7B9u));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD7C0u)); sfera_sub_004DB330(cpu, LIFT_CODE_TOKEN_VA(0x4DD7C0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    cpu->esp -= 8u;
    cpu->ecx = cpu->ebp;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD7DDu)); sfera_sub_004DB680(cpu, LIFT_CODE_TOKEN_VA(0x4DD7DDu));
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_load32(cpu->esp + 0x420u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->ebp + 0xFFFFFFC4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    lift_store32(cpu->ebp + 0xFFFFFFC8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFC8u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->ebp + 0x14u))) goto label_000DD834;
    cpu->eax = 0xFFFFFFFBu;
    goto label_000DD8DC;
    label_000DD834:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFD0u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->ebp + 0xFFFFFFD4u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->eax))) goto label_000DD856;
    cpu->eax = 0xFFFFFFFBu;
    goto label_000DD8DC;
    label_000DD856:
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 0u);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0u);
    lift_push32(cpu, 0x38u); lift_push32(cpu, (uintptr_t)"1.1.3");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD874u)); sfera_sub_004DDC0A(cpu, LIFT_CODE_TOKEN_VA(0x4DD874u));
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0u)) goto label_000DD885;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    goto label_000DD8DC;
    label_000DD885:
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD890u)); sfera_sub_004DDC25(cpu, LIFT_CODE_TOKEN_VA(0x4DD890u));
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(1u)) goto label_000DD8C2;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD8A5u)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DD8A5u));
    cpu->esp += 4u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) != (uint32_t)(0u)) goto label_000DD8B7;
    lift_store32(cpu->ebp + 0xFFFFFFC0u, 0xFFFFFFFBu);
    goto label_000DD8BD;
    label_000DD8B7:
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    lift_store32(cpu->ebp + 0xFFFFFFC0u, cpu->edx);
    label_000DD8BD:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC0u);
    goto label_000DD8DC;
    label_000DD8C2:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD8D3u)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DD8D3u));
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000DD8DC:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD8E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->ebp + 0xFFFFFFC4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    lift_store32(cpu->ebp + 0xFFFFFFC8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ebp + 0xFFFFFFD0u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFD4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->edx))) goto label_000DD914;
    cpu->eax = 0xFFFFFFFBu;
    goto label_000DD9A5;
    label_000DD914:
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 0u);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0u);
    lift_push32(cpu, 0x38u); lift_push32(cpu, (uintptr_t)"1.1.3");
    cpu->ecx = lift_load32(cpu->ebp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD93Du)); sfera_sub_004DE540(cpu, LIFT_CODE_TOKEN_VA(0x4DD93Du));
    cpu->esp += 0x10u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0u)) goto label_000DD94E;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    goto label_000DD9A5;
    label_000DD94E:
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD959u)); sfera_sub_004DEBDE(cpu, LIFT_CODE_TOKEN_VA(0x4DD959u));
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(1u)) goto label_000DD98B;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD96Eu)); sfera_sub_004DF075(cpu, LIFT_CODE_TOKEN_VA(0x4DD96Eu));
    cpu->esp += 4u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) != (uint32_t)(0u)) goto label_000DD980;
    lift_store32(cpu->ebp + 0xFFFFFFC0u, 0xFFFFFFFBu);
    goto label_000DD986;
    label_000DD980:
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    lift_store32(cpu->ebp + 0xFFFFFFC0u, cpu->edx);
    label_000DD986:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC0u);
    goto label_000DD9A5;
    label_000DD98B:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DD99Cu)); sfera_sub_004DF075(cpu, LIFT_CODE_TOKEN_VA(0x4DD99Cu));
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000DD9A5:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD9D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DD9E2;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) != (uint32_t)(0u)) goto label_000DD9E9;
    label_000DD9E2:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDA39;
    label_000DD9E9:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x14u, 0u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 8u, 0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x18u, 0u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx + 0xCu);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 7u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, cpu->eax);
    lift_push32(cpu, 0u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDA34u)); sfera_sub_004E0950(cpu, LIFT_CODE_TOKEN_VA(0x4DDA34u));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_000DDA39:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDA3B(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DDA56;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) == (uint32_t)(0u)) goto label_000DDA56;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x24u)) != (uint32_t)(0u)) goto label_000DDA5D;
    label_000DDA56:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDAA2;
    label_000DDA5D:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) == (uint32_t)(0u)) goto label_000DDA7F;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDA7Cu)); sfera_sub_004E1E72(cpu, LIFT_CODE_TOKEN_VA(0x4DDA7Cu));
    cpu->esp += 8u;
    label_000DDA7F:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->eax + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDDA93u), LIFT_CODE_TOKEN_RVA(0xDDA90u))) { return; }
    cpu->esp += 8u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x1Cu, 0u);
    cpu->eax = 0u;
    label_000DDAA2:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDAA4(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x10u)) == (uint32_t)(0u)) goto label_000DDAC4;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (int32_t)(int8_t)lift_load8((uintptr_t)"1.1.3");
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000DDAC4;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) == (uint32_t)(0x38u)) goto label_000DDACE;
    label_000DDAC4:
    cpu->eax = 0xFFFFFFFAu;
    goto label_000DDC08;
    label_000DDACE:
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) != (uint32_t)(0u)) goto label_000DDADE;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDC08;
    label_000DDADE:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x18u, 0u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x20u)) != (uint32_t)(0u)) goto label_000DDB05;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 0x20u, LIFT_CALLBACK(sfera_sub_004E21BE));
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x28u, 0u);
    label_000DDB05:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x24u)) != (uint32_t)(0u)) goto label_000DDB18;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 0x24u, LIFT_CALLBACK(sfera_sub_004E21E7));
    label_000DDB18:
    lift_push32(cpu, 0x18u); lift_push32(cpu, 1u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->edx + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDDB29u), LIFT_CODE_TOKEN_RVA(0xDDB26u))) { return; }
    cpu->esp += 0xCu;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x1Cu)) != (uint32_t)(0u)) goto label_000DDB45;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DDC08;
    label_000DDB45:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx + 0x14u, 0u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 0xCu, 0u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xCu)) >= (int32_t)(uint32_t)(0u)) goto label_000DDB7A;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    lift_store32(cpu->ebp + 0xCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 0xCu, 1u);
    label_000DDB7A:
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xCu)) < (int32_t)(uint32_t)(8u)) goto label_000DDB86;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(0xFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000DDB99;
    label_000DDB86:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDB8Fu)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DDB8Fu));
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDC08;
    label_000DDB99:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->edx = 1u;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(cpu->edx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edx = ~((uint64_t)(cpu->edx));
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(LIFT_CALLBACK(sfera_sub_004E1F20)), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDBCFu)); sfera_sub_004E0A07(cpu, LIFT_CODE_TOKEN_VA(0x4DDBCFu));
    cpu->esp += 0xCu;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) != (uint32_t)(0u)) goto label_000DDBFA;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDBF0u)); sfera_sub_004DDA3B(cpu, LIFT_CODE_TOKEN_VA(0x4DDBF0u));
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DDC08;
    label_000DDBFA:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDC03u)); sfera_sub_004DD9D0(cpu, LIFT_CODE_TOKEN_VA(0x4DDC03u));
    cpu->esp += 4u;
    cpu->eax = 0u;
    label_000DDC08:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDC0A(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xFu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DDC20u)); sfera_sub_004DDAA4(cpu, LIFT_CODE_TOKEN_VA(0x4DDC20u));
    cpu->esp += 0x10u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDC25(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DDC42;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) == (uint32_t)(0u)) goto label_000DDC42;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(0u)) goto label_000DDC4C;
    label_000DDC42:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DDC4C:
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->edx;
    cpu->edx &= 0xFFFFFFFBu;
    lift_store32(cpu->ebp + 0xCu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0xFFFFFFFBu);
    label_000DDC63:
    cpu->eax = 1u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DE2BA;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF4u)) > (uint32_t)(0xDu)) goto label_000DE2AE;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: goto label_000DDC8F;
        case 1u: goto label_000DDD6A;
        case 2u: goto label_000DDE23;
        case 3u: goto label_000DDE86;
        case 4u: goto label_000DDEF4;
        case 5u: goto label_000DDF62;
        case 6u: goto label_000DDFE6;
        case 7u: goto label_000DE013;
        case 8u: goto label_000DE0BD;
        case 9u: goto label_000DE120;
        case 10u: goto label_000DE18E;
        case 11u: goto label_000DE1FC;
        case 12u: goto label_000DE2A0;
        case 13u: goto label_000DE2A7;
        default: lift_trap(cpu, 0x4DDC88u, "resolved jump-table index out of range"); return;
    }
label_000DDC8F: ;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(0u)) goto label_000DDCA0;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDCA0:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->eax &= 0xFu;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->edx += 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000DDD1C;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 0xDu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x18u, (uintptr_t)"unknown compression method");
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 4u, 5u);
    goto label_000DE2B5;
    label_000DDD1C:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += 8u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->edx + 0x10u))) goto label_000DDD5E;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx, 0xDu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 0x18u, (uintptr_t)"invalid window size");
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx + 4u, 5u);
    goto label_000DE2B5;
    label_000DDD5E:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 1u);
    label_000DDD6A:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(0u)) goto label_000DDD7B;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDD7B:
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx -= 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->ecx += 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(1u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax += lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx = 0u;
    cpu->ecx = 0x1Fu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000DDDFC;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 0xDu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x18u, (uintptr_t)"incorrect header check");
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 4u, 5u);
    goto label_000DE2B5;
    label_000DDDFC:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx &= 0x20u;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000DDE17;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 7u);
    goto label_000DE2B5;
    label_000DDE17:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 2u);
    label_000DDE23:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(0u)) goto label_000DDE34;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDE34:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->eax -= 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    cpu->eax += 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->edx += 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 3u);
    label_000DDE86:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(0u)) goto label_000DDE97;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDE97:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->eax -= 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    cpu->eax += 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x10u), 32u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->edx += cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax += 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 4u);
    label_000DDEF4:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(0u)) goto label_000DDF05;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDF05:
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx -= 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->ecx += 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx);
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->eax += cpu->edx;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx, 5u);
    label_000DDF62:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(0u)) goto label_000DDF73;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDF73:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->ecx += cpu->eax;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->edx += 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0x30u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 6u);
    cpu->eax = 2u;
    goto label_000DE2BA;
    label_000DDFE6:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 0xDu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x18u, (uintptr_t)"need dictionary");
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx + 4u, 0u);
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DE013:
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE02Au)); sfera_sub_004E0AFF(cpu, LIFT_CODE_TOKEN_VA(0x4DE02Au));
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)) != (uint32_t)(0xFFFFFFFDu)) goto label_000DE054;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 0xDu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx + 4u, 0u);
    goto label_000DE2B5;
    label_000DE054:
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)) != (uint32_t)(0u)) goto label_000DE060;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    label_000DE060:
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)) == (uint32_t)(1u)) goto label_000DE06E;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE06E:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE091u)); sfera_sub_004E0950(cpu, LIFT_CODE_TOKEN_VA(0x4DE091u));
    cpu->esp += 0xCu;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->eax + 0xCu)) == (uint32_t)(0u)) goto label_000DE0B1;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 0xCu);
    goto label_000DE2B5;
    label_000DE0B1:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx, 8u);
    label_000DE0BD:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(0u)) goto label_000DE0CE;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE0CE:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx, 9u);
    label_000DE120:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(0u)) goto label_000DE131;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE131:
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->edx -= 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->edx += 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->ecx += cpu->eax;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->edx += 1u;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 0xAu);
    label_000DE18E:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(0u)) goto label_000DE19F;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE19F:
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->eax -= 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    cpu->eax += 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->edx += cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax += 1u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 0xBu);
    label_000DE1FC:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(0u)) goto label_000DE20D;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE20D:
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx -= 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->ecx += 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = 0u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->eax += cpu->edx;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += 1u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000DE294;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 0xDu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x18u, (uintptr_t)"incorrect data check");
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax + 4u, 5u);
    goto label_000DE2B5;
    label_000DE294:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 0xCu);
    label_000DE2A0:
    cpu->eax = 1u;
    goto label_000DE2BA;
    label_000DE2A7:
    cpu->eax = 0xFFFFFFFDu;
    goto label_000DE2BA;
    label_000DE2AE:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DE2B5:
    goto label_000DDC63;
    label_000DE2BA:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DE540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 8u); lift_push32(cpu, 0xFu); lift_push32(cpu, 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE560u)); sfera_sub_004DE565(cpu, LIFT_CODE_TOKEN_VA(0x4DE560u));
    cpu->esp += 0x20u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DE565(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, 0u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x20u)) == (uint32_t)(0u)) goto label_000DE591;
    cpu->eax = lift_load32(cpu->ebp + 0x20u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (uintptr_t)"1.1.3";
    cpu->eax = (int8_t)(lift_load8(cpu->edx));
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_000DE591;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x24u)) == (uint32_t)(0x38u)) goto label_000DE59B;
    label_000DE591:
    cpu->eax = 0xFFFFFFFAu;
    goto label_000DE84D;
    label_000DE59B:
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) != (uint32_t)(0u)) goto label_000DE5AB;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE84D;
    label_000DE5AB:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x18u, 0u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x20u)) != (uint32_t)(0u)) goto label_000DE5D2;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x20u, LIFT_CALLBACK(sfera_sub_004E21BE));
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x28u, 0u);
    label_000DE5D2:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x24u)) != (uint32_t)(0u)) goto label_000DE5E5;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x24u, LIFT_CALLBACK(sfera_sub_004E21E7));
    label_000DE5E5:
    if ((uint32_t)(lift_load32(cpu->ebp + 0xCu)) != (uint32_t)(0xFFFFFFFFu)) goto label_000DE5F2;
    lift_store32(cpu->ebp + 0xCu, 6u);
    label_000DE5F2:
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) >= (int32_t)(uint32_t)(0u)) goto label_000DE607;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    lift_store32(cpu->ebp + 0x14u, cpu->ecx);
    label_000DE607:
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x18u)) < (int32_t)(uint32_t)(1u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x18u)) > (int32_t)(uint32_t)(9u)) goto label_000DE63D;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x10u)) != (uint32_t)(8u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (int32_t)(uint32_t)(8u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) > (int32_t)(uint32_t)(0xFu)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xCu)) < (int32_t)(uint32_t)(0u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xCu)) > (int32_t)(uint32_t)(9u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x1Cu)) < (int32_t)(uint32_t)(0u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x1Cu)) <= (int32_t)(uint32_t)(2u)) goto label_000DE647;
    label_000DE63D:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE84D;
    label_000DE647:
    lift_push32(cpu, 0x16B8u); lift_push32(cpu, 1u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDE65Bu), LIFT_CODE_TOKEN_RVA(0xDE658u))) { return; }
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DE671;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DE84D;
    label_000DE671:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0x1Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    lift_store32(cpu->edx + 0x28u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = 1u;
    cpu->ecx = lift_load32(cpu->ecx + 0x28u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->eax + 0x24u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    cpu->edx -= 1u;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->eax + 0x2Cu, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(7u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0x48u, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = 1u;
    cpu->ecx = lift_load32(cpu->eax + 0x48u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->eax + 0x44u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = lift_load32(cpu->ecx + 0x44u);
    cpu->edx -= 1u;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->eax + 0x4Cu, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = lift_load32(cpu->ecx + 0x48u);
    cpu->eax += 2u;
    cpu->edx = 0u;
    cpu->ecx = 3u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0x50u, cpu->eax);
    lift_push32(cpu, 2u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDE712u), LIFT_CODE_TOKEN_RVA(0xDE70Fu))) { return; }
    cpu->esp += 0xCu;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0x30u, cpu->eax);
    lift_push32(cpu, 2u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDE731u), LIFT_CODE_TOKEN_RVA(0xDE72Eu))) { return; }
    cpu->esp += 0xCu;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0x38u, cpu->eax);
    lift_push32(cpu, 2u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDE750u), LIFT_CODE_TOKEN_RVA(0xDE74Du))) { return; }
    cpu->esp += 0xCu;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0x3Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x18u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(6u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 1u;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->ecx + 0x1694u, cpu->eax);
    lift_push32(cpu, 4u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = lift_load32(cpu->edx + 0x1694u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->eax + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDE788u), LIFT_CODE_TOKEN_RVA(0xDE785u))) { return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0xCu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1694u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0xCu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x30u)) == (uint32_t)(0u)) goto label_000DE7CD;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x38u)) == (uint32_t)(0u)) goto label_000DE7CD;
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x3Cu)) == (uint32_t)(0u)) goto label_000DE7CD;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DE7EC;
    label_000DE7CD:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = (uintptr_t)"insufficient memory";
    lift_store32(cpu->ecx + 0x18u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE7E2u)); sfera_sub_004DF075(cpu, LIFT_CODE_TOKEN_VA(0x4DE7E2u));
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DE84D;
    label_000DE7EC:
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1694u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->edx + 0x169Cu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1694u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(3u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_store32(cpu->ecx + 0x1690u, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->edx + 0x7Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    lift_store32(cpu->ecx + 0x80u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x10u)) & 0xFFu);
    lift_store8(cpu->eax + 0x1Du, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4DE84Au)); sfera_sub_004DE9F1(cpu, LIFT_CODE_TOKEN_VA(0x4DE84Au));
    cpu->esp += 4u;
    label_000DE84D:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DE9F1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate_reset(lift_load32(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DEBDE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate(lift_load32(cpu->esp + 4u), (int32_t)lift_load32(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DEF60(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_deflate_put_short_msb(lift_load32(cpu->esp + 4u), lift_load32(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DEFB0(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_deflate_flush_pending(lift_load32(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF075(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DF088;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) != (uint32_t)(0u)) goto label_000DF092;
    label_000DF088:
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DF182;
    label_000DF092:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0x2Au)) goto label_000DF0BD;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0x71u)) goto label_000DF0BD;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0x29Au)) goto label_000DF0BD;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DF182;
    label_000DF0BD:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->edx + 8u)) == (uint32_t)(0u)) goto label_000DF0E3;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->edx + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDF0E0u), LIFT_CODE_TOKEN_RVA(0xDF0DDu))) { return; }
    cpu->esp += 8u;
    label_000DF0E3:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x3Cu)) == (uint32_t)(0u)) goto label_000DF109;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDF106u), LIFT_CODE_TOKEN_RVA(0xDF103u))) { return; }
    cpu->esp += 8u;
    label_000DF109:
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x38u)) == (uint32_t)(0u)) goto label_000DF12F;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->eax + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDF12Cu), LIFT_CODE_TOKEN_RVA(0xDF129u))) { return; }
    cpu->esp += 8u;
    label_000DF12F:
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->edx + 0x30u)) == (uint32_t)(0u)) goto label_000DF155;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->edx + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDF152u), LIFT_CODE_TOKEN_RVA(0xDF14Fu))) { return; }
    cpu->esp += 8u;
    label_000DF155:
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDF169u), LIFT_CODE_TOKEN_RVA(0xDF166u))) { return; }
    cpu->esp += 8u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 0x1Cu, 0u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)), r=(uint64_t)(0x71u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_000DF182:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF3D2(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_deflate_lm_init(lift_load32(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate_stored(lift_load32(cpu->esp + 4u), (int32_t)lift_load32(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF700(LiftCpu* cpu, uint32_t stop_address) {
    sfera_zlib_deflate_fill_window(lift_load32(cpu->esp + 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF93B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate_read_buf(lift_load32(cpu->esp + 4u), lift_load32(cpu->esp + 8u), lift_load32(cpu->esp + 12u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF9D3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate_fast(lift_load32(cpu->esp + 4u), (int32_t)lift_load32(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DFF2A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = sfera_zlib_deflate_longest_match(lift_load32(cpu->esp + 4u), lift_load32(cpu->esp + 8u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
