#include "lifted_functions.h"
#include "lifted_normalized_ops.h"
#include "semantic_zlib.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6720u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004D65B0));
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::SetUnhandledExceptionFilter), LIFT_CODE_TOKEN_VA(0x4D6729u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D672Fu);
    lift_push32(cpu, 0x104u); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]); lift_push32(cpu, 0u);
    g_sfera_crash_report_runtime.previous_exception_filter = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetModuleFileNameA), LIFT_CODE_TOKEN_VA(0x4D6740u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6746u);
    cpu->edi = native_function_address32(&::lstrcpyA);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D675C;
    lift_push32(cpu, (uintptr_t)"Unknown"); lift_push32(cpu, (uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD675Cu), LIFT_CODE_TOKEN_RVA(0xD675Au))) { return; }
    label_000D675C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D675Cu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    label_000D6761: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6761u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000D6761;
    label_000D6768: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6768u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0]))) goto label_000D6778;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6768;
    ++cpu->eax;
    goto label_000D6785;
    label_000D6778: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6778u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_000D6780;
    ++cpu->eax;
    goto label_000D6785;
    label_000D6780: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6780u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_crash_report_runtime.error_log_path[0];
    label_000D6785: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6785u);
    lift_push32(cpu, (uintptr_t)"ERRORLOG.TXT"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xD678Du), LIFT_CODE_TOKEN_RVA(0xD678Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D678Du);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4D678Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6793u);
    lift_store32((uintptr_t)&g_sfera_crash_report_runtime.process_handle, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D67E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67E0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D67FA;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D67F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67F0u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D67F0;
    label_000D67FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D67FAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6800u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D681B;
    label_000D6810: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6810u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6810;
    label_000D681B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D681Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6820u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) == (uint8_t)(0u)) goto label_000D6830;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000D6830: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6830u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D684F;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) != (uint8_t)(0u)) goto label_000D6871;
    label_000D6841: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6841u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) == (uint8_t)(0u)) goto label_000D6841;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_000D684F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D684Fu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6869;
    label_000D6858: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6858u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D6869;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6858;
    label_000D6869: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6869u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) != (uint8_t)(0u)) goto label_000D6873;
    label_000D6871: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6871u);
    lift_store32(cpu->eax, cpu->edx);
    label_000D6873: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6873u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6880u);
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
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4D68E2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D68E8u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store8(cpu->esp + 0x463u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D68FCu); lift_push32(cpu, r); sfera_sub_00422A20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_000D690E;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateCursor(): failed to load cursor image from file";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD690Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D690E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D690Eu);
    if ((uint32_t)(lift_load32(cpu->edi + 4u)) != (uint32_t)(0x20u)) goto label_000D6920;
    if ((uint32_t)(lift_load32(cpu->edi + 8u)) != (uint32_t)(0x20u)) goto label_000D6920;
    if ((uint32_t)(lift_load32(cpu->edi + 0xCu)) == (uint32_t)(0x20u)) goto label_000D692A;
    label_000D6920: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6920u);
    cpu->ecx = (uint32_t)(uintptr_t)"CreateCursor(): invalid cursor image format";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD692Au); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D692A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D692Au);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetDC), LIFT_CODE_TOKEN_VA(0x4D692Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6935u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000D6949;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CWindowDC::CWindowDC(): failed to retrieve DC";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD6949u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D6949: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6949u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x474u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleDC), LIFT_CODE_TOKEN_VA(0x4D6951u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6957u);
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x60u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_000D696B;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CMemoryDC::CMemoryDC(): failed to create DC";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD696Bu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D696B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D696Bu);
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0x484u, 1u);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CreateBitmap), LIFT_CODE_TOKEN_VA(0x4D698Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6992u);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000D69A6;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CBitmap::CBitmap(): failed to create bitmap";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD69A6u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D69A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D69A6u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 2u);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D69B4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D69BAu);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetObjectType), LIFT_CODE_TOKEN_VA(0x4D69BFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D69C5u);
    cpu->eax -= 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    --cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->eax)) goto label_000D69DF;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CObjectSelector::CObjectSelector(): failed to select object";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD69DFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D69DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D69DFu);
    cpu->ebx = 0u;
    lift_store8(cpu->esp + 0x470u, 3u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D6A29;
    label_000D69ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D69EDu);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) <= (uint32_t)(cpu->esi)) goto label_000D6A22;
    label_000D69F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D69F5u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D69FEu); lift_push32(cpu, r); sfera_sub_004229F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= 0xFF000000u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFF000001u;
    cpu->eax += 0xFFFFFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SetPixel), LIFT_CODE_TOKEN_VA(0x4D6A15u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A1Bu);
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000D69F5;
    label_000D6A22: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A22u);
    ++cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000D69ED;
    label_000D6A29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A29u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 2u);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D6A37u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A3Du);
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CreateCompatibleBitmap), LIFT_CODE_TOKEN_VA(0x4D6A56u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A5Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000D6A70;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CBitmap::CBitmap(): failed to create bitmap";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD6A70u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D6A70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A70u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 4u);
    lift_store32(cpu->esp + 0x60u, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D6A7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A84u);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x60u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetObjectType), LIFT_CODE_TOKEN_VA(0x4D6A8Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6A91u);
    cpu->eax -= 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    --cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_000D6AA9;
    cpu->ecx = (uint32_t)(uintptr_t)"GDI::CObjectSelector::CObjectSelector(): failed to select object";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD6AA9u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D6AA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6AA9u);
    cpu->ebx = 0u;
    lift_store8(cpu->esp + 0x470u, 5u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) <= (uint32_t)(cpu->ebx)) goto label_000D6AEB;
    label_000D6AB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6AB9u);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) <= (uint32_t)(cpu->esi)) goto label_000D6AE0;
    label_000D6AC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6AC1u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6ACAu); lift_push32(cpu, r); sfera_sub_004229F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= 0xFFFFFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::SetPixel), LIFT_CODE_TOKEN_VA(0x4D6AD3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6AD9u);
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_000D6AC1;
    label_000D6AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6AE0u);
    ++cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000D6AB9;
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    label_000D6AEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6AEBu);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->esp + 0x478u, 4u);
    lift_native_call(cpu, native_function_address32(&::SelectObject), LIFT_CODE_TOKEN_VA(0x4D6AF9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6AFFu);
    cpu->edx = 0x3Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorImageManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6B0Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6B15u); lift_push32(cpu, r); sfera_sub_004229D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6B1Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
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
    label_000D6B44: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6B44u);
    lift_store32(cpu->esp + 0x48u, cpu->edi);
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    label_000D6B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6B4Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::CreateIconIndirect), LIFT_CODE_TOKEN_VA(0x4D6B5Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6B63u);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edi)) goto label_000D6B73;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateCursor(): failed to create cursor";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD6B73u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D6B73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6B73u);
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::DeleteObject);
    lift_store32(cpu->edi, cpu->ebx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_store32(cpu->edi + 8u, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6B90u), LIFT_CODE_TOKEN_RVA(0xD6B8Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6B90u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD6B97u), LIFT_CODE_TOKEN_RVA(0xD6B95u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6B97u);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::DeleteDC), LIFT_CODE_TOKEN_VA(0x4D6B98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6B9Eu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ReleaseDC), LIFT_CODE_TOKEN_VA(0x4D6BA5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6BABu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->esp + 0x468u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x460u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6BE0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C2A;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C0D;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C0A;
    label_000D6C00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C00u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6C00;
    label_000D6C0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C0Au);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000D6C0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C0Du);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) != (uint8_t)(0u)) goto label_000D6C28;
    label_000D6C16: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C16u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D6C28;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x35u)) == (uint8_t)(0u)) goto label_000D6C16;
    label_000D6C28: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C28u);
    lift_store32(cpu->eax, cpu->edx);
    label_000D6C2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C2Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C30u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)(0u)) goto label_000D6C48;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000D6C48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C48u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000D6C62;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000D6C62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C62u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000D6C73;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000D6C73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C73u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C80u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)(0u)) goto label_000D6C98;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000D6C98: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6C98u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000D6CB3;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000D6CB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6CB3u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_000D6CC7;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000D6CC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6CC7u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6CE0u);
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
    label_000D6D00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D00u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D6D0E;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_000D6D10;
    label_000D6D0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D0Eu);
    cpu->edx = cpu->ebp;
    label_000D6D10: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D10u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000D6D19;
    label_000D6D19: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D19u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000D6D21;
    cpu->ecx = cpu->ebx;
    label_000D6D21: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D21u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000D6D29;
    cpu->eax = lift_load32(cpu->eax);
    label_000D6D29: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D29u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6D31u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D6D43;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000D6D45;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000D6D43: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D43u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D6D4A;
    label_000D6D45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D45u);
    cpu->edi = lift_load32(cpu->edi + 8u);
    goto label_000D6D50;
    label_000D6D4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D4Au);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi = lift_load32(cpu->edi);
    label_000D6D50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D50u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)(0u)) goto label_000D6D00;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D6D5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D5Du);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D70u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6D7Fu); lift_push32(cpu, r); sfera_sub_004D6CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D6DBB;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000D6D96;
    cpu->eax = lift_load32(cpu->eax);
    label_000D6D96: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6D96u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6DA5u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D6DBB;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000D6DBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6DBBu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D6DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6DE0u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x6666665u)) goto label_000D6E25;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) < (uint32_t)(0x10u)) goto label_000D6E02;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6DFFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D6E02: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6E02u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D6E17u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD6E25u);
    label_000D6E25: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6E25u);
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
    label_000D6E4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6E4Eu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6E61;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D6E6F;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_000D6E6F;
    label_000D6E61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6E61u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D6E6F;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_000D6E6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6E6Fu);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D700D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_000D6E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6E80u);
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
    label_000D6EB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6EB2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000D6EF1;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6ECB;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000D6ECB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6ECBu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D6EDE;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_000D6EEC;
    label_000D6EDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6EDEu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_000D6EE9;
    lift_store32(cpu->esi, cpu->edx);
    goto label_000D6EEC;
    label_000D6EE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6EE9u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_000D6EEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6EECu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_000D6EF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6EF1u);
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
    label_000D6F19: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6F19u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D6F32;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FFD;
    label_000D6F32: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6F32u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000D6F45;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FFD;
    label_000D6F45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6F45u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FFD;
    label_000D6F4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6F4Fu);
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
    label_000D6F72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6F72u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_000D6FB2;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6F8A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000D6F8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6F8Au);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_000D6F9D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_000D6FAC;
    label_000D6F9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6F9Du);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000D6FAA;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000D6FAC;
    label_000D6FAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FAAu);
    lift_store32(cpu->esi, cpu->edx);
    label_000D6FAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FACu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_000D6FB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FB2u);
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
    label_000D6FDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FDAu);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000D6FED;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_000D6FFB;
    label_000D6FED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FEDu);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000D6FF8;
    lift_store32(cpu->edi, cpu->esi);
    goto label_000D6FFB;
    label_000D6FF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FF8u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_000D6FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FFBu);
    lift_store32(cpu->esi, cpu->edx);
    label_000D6FFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D6FFDu);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_000D7000: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7000u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D6E80;
    cpu->edi = lift_pop32(cpu);
    label_000D700D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D700Du);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x34u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7030u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D704D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD704Du);
    label_000D704D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D704Du);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D705Bu); lift_push32(cpu, r); sfera_sub_004D6BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x35u)) == (uint8_t)(0u)) goto label_000D7069;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    goto label_000D7081;
    label_000D7069: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7069u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7076;
    cpu->edi = cpu->ecx;
    goto label_000D7081;
    label_000D7076: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7076u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_000D70E4;
    label_000D7081: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7081u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D708D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000D708D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D708Du);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebp)) goto label_000D709A;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_000D70A5;
    label_000D709A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D709Au);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebp)) goto label_000D70A2;
    lift_store32(cpu->esi, cpu->edi);
    goto label_000D70A5;
    label_000D70A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70A2u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_000D70A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70A5u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->ebp)) goto label_000D70BF;
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)(0u)) goto label_000D70B6;
    cpu->eax = cpu->esi;
    goto label_000D70BD;
    label_000D70B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70B6u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD70BDu); lift_push32(cpu, r); sfera_sub_004D67E0(cpu,r); if (cpu->eip != r) return; }
    label_000D70BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70BDu);
    lift_store32(cpu->ebx, cpu->eax);
    label_000D70BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70BFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->ebp)) goto label_000D713C;
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)(0u)) goto label_000D70D8;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_000D713C;
    label_000D70D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70D8u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D70DFu); lift_push32(cpu, r); sfera_sub_004D6800(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_000D713C;
    label_000D70E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70E4u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_000D70F5;
    cpu->esi = cpu->eax;
    goto label_000D710F;
    label_000D70F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D70F5u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D7101;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000D7101: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7101u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_000D710F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D710Fu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebp)) goto label_000D711C;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_000D712A;
    label_000D711C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D711Cu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebp)) goto label_000D7127;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_000D712A;
    label_000D7127: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7127u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_000D712A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D712Au);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x34u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x34u)) & 0xFFu);
    lift_store8(cpu->eax + 0x34u, cpu->edx & 0xFFu);
    lift_store8(cpu->ebp + 0x34u, cpu->ecx & 0xFFu);
    label_000D713C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D713Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7246;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_000D7243;
    label_000D7157: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7157u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7243;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000D71CD;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x34u)) != (uint8_t)(0u)) goto label_000D7183;
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x34u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D717Cu); lift_push32(cpu, r); sfera_sub_004D6C30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D7183: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7183u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D71FF;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7198;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D71FB;
    label_000D7198: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7198u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D71B6;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x34u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D71AFu); lift_push32(cpu, r); sfera_sub_004D6C80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D71B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D71B6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x34u)) & 0xFFu);
    lift_store8(cpu->eax + 0x34u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x34u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D71CBu); lift_push32(cpu, r); sfera_sub_004D6C30(cpu,r); if (cpu->eip != r) return; }
    goto label_000D7243;
    label_000D71CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D71CDu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x34u)) != (uint8_t)(0u)) goto label_000D71E6;
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x34u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D71E0u); lift_push32(cpu, r); sfera_sub_004D6C80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D71E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D71E6u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D71FF;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7212;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7212;
    label_000D71FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D71FBu);
    lift_store8(cpu->eax + 0x34u, 0u);
    label_000D71FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D71FFu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_000D7157;
    goto label_000D7243;
    label_000D7212: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7212u);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x34u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D722F;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x34u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x34u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7229u); lift_push32(cpu, r); sfera_sub_004D6C30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000D722F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D722Fu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x34u)) & 0xFFu);
    lift_store8(cpu->eax + 0x34u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x34u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x34u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD7243u); lift_push32(cpu, r); sfera_sub_004D6C80(cpu,r); if (cpu->eip != r) return; }
    label_000D7243: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7243u);
    lift_store8(cpu->edi + 0x34u, cpu->ebx & 0xFFu);
    label_000D7246: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7246u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x20u)) < (uint32_t)(0x10u)) goto label_000D7258;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7255u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D7258: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7258u);
    lift_store32(cpu->ebp + 0x20u, 0xFu);
    lift_store32(cpu->ebp + 0x1Cu, 0u);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->ebp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7270u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D7285;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_000D7285: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7285u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D72A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D72A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi + 0x35u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D72EF;
    label_000D72B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D72B3u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D72BEu); lift_push32(cpu, r); sfera_sub_004D72A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D72D2;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D72CFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D72D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D72D2u);
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D72E5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x35u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D72B3;
    label_000D72EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D72EFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7300u);
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
    label_000D7330: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7330u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D7392;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_000D7349;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_000D734B;
    label_000D7349: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7349u);
    cpu->edx = cpu->ebp;
    label_000D734B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D734Bu);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000D7354;
    label_000D7354: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7354u);
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_000D735F;
    cpu->ecx = cpu->edi;
    label_000D735F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D735Fu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000D7367;
    cpu->eax = lift_load32(cpu->eax);
    label_000D7367: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7367u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D736Fu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D738D;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_000D7384;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000D73DB;
    label_000D7384: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7384u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000D738D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D738Du);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000D73DB;
    label_000D7392: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7392u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D739D;
    cpu->eax = lift_load32(cpu->eax);
    label_000D739D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D739Du);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_000D73AA;
    cpu->edx = cpu->edi;
    label_000D73AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73AAu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_000D73B5;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_000D73B7;
    label_000D73B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73B5u);
    cpu->ecx = cpu->ebp;
    label_000D73B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73B7u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D73BFu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D73D8;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_000D73CF;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_000D73D6;
    label_000D73CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73CFu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_000D73D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73D6u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000D73D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73D8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000D73DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73DBu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000D73E7;
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_000D73EA;
    label_000D73E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73E7u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_000D73EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73EAu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x35u)) == (uint8_t)(0u)) goto label_000D7330;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_000D73FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D73FCu);
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000D7442;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_000D7435;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    label_000D741A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D741Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D741Fu); lift_push32(cpu, r); sfera_sub_004D6DE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000D7435: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7435u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D743Eu); lift_push32(cpu, r); sfera_sub_004D6820(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_000D7442: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7442u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ebx = 0x10u;
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000D7457;
    cpu->eax = lift_load32(cpu->ebp);
    goto label_000D7459;
    label_000D7457: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7457u);
    cpu->eax = cpu->ebp;
    label_000D7459: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7459u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7466u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D7480;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    goto label_000D741A;
    label_000D7480: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7480u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_000D7491;
    cpu->edx = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D748Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D7491: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7491u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->ebp + 0x14u, 0xFu);
    lift_store32(cpu->ebp + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D74ADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D74D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D74D0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7504u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7559u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x1Cu);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebx + 0x20u);
    lift_store32(cpu->esi + 0x20u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    label_000D756B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D756Bu);
    cpu->eax = cpu->edi;
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D7596: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7596u);
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D75BBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D75BBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7581(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7581u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D758Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7596u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D75BBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D75BBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D75C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D75C0u);
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
    label_000D761C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D761Cu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    lift_store32(cpu->eax + 8u, cpu->ebx);
    goto label_000D776C;
    label_000D7629: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7629u);
    cpu->eax = cpu->esi;
    lift_store32(cpu->esp + 0x44u, 0xFu);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store8(cpu->esp + 0x30u, cpu->ebx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000D7640: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7640u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D7640;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7654u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x88u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D766Cu); lift_push32(cpu, r); sfera_sub_004D6D70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x44u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x80u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000D768D;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D768Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D768D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D768Du);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D76C5u); lift_push32(cpu, r); sfera_sub_004D6880(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    lift_store32(cpu->esp + 0x60u, 0xFu);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000D76E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D76E0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000D76E0;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D76F4u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7724u); lift_push32(cpu, r); sfera_sub_004D74D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7731u); lift_push32(cpu, r); sfera_sub_004D7300(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x60u)) < (uint32_t)(0x10u)) goto label_000D7745;
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7742u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D7745: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7745u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->ebp);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    goto label_000D776C;
    label_000D7757: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7757u);
    cpu->edx = lift_load32(cpu->ebp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0x2Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    label_000D776C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D776Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7790u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D77A2u); lift_push32(cpu, r); sfera_sub_004D75C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D77B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D77B0u);
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D77C2u); lift_push32(cpu, r); sfera_sub_004D75C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D77E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D77E0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7802u); lift_push32(cpu, r); sfera_sub_004D72A0(cpu,r); if (cpu->eip != r) return; }
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
    label_000D782A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D782Au);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000D789F;
    cpu->edi = cpu->edi;
    label_000D7830: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7830u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x35u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D7888;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D7860;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D785A;
    label_000D7850: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7850u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7850;
    label_000D785A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D785Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000D7888;
    label_000D7860: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7860u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) != (uint8_t)(0u)) goto label_000D7884;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D7870: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7870u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000D7884;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x35u)) == (uint8_t)(0u)) goto label_000D7870;
    label_000D7884: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7884u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000D7888: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7888u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7895u); lift_push32(cpu, r); sfera_sub_004D7030(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000D7830;
    label_000D789F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D789Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7980u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x38u);
    lift_store32(cpu->esi + 8u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7994u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
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
    lift_return(cpu, 0u, stop_address); return;
    label_000D79C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D79C1u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 8u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D79EFu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4D79EFu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D79F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D79F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0xAu;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7A23u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7A2Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D7A46;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7A44u); lift_push32(cpu, r); sfera_sub_004D7F70(cpu,r); if (cpu->eip != r) return; }
    goto label_000D7A48;
    label_000D7A46: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7A46u);
    cpu->eax = 0u;
    label_000D7A48: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7A48u);
    cpu->edx = 0xBu;
    cpu->ecx = (uint32_t)(uintptr_t)"CursorManager.cpp";
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_store32(cpu->esi, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7A61u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7A68u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D7A84;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7A82u); lift_push32(cpu, r); sfera_sub_004D7BF0(cpu,r); if (cpu->eip != r) return; }
    goto label_000D7A86;
    label_000D7A84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7A84u);
    cpu->eax = 0u;
    label_000D7A86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7A86u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7AF0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D7B00;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_000D7B08;
    label_000D7B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7B00u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000D7B31;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    label_000D7B08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7B08u);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_000D7B31;
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<CCursor*>(cpu->ecx)->copyStateFrom(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7B1Au);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D7B27;
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->deactivate(cpu);
    label_000D7B27: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7B27u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    reinterpret_cast<CCursor*>(cpu->ecx)->activate(cpu);
    label_000D7B31: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7B31u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7B50u);
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
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x4D7BA0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7BA6u);
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
    label_000D7BC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7BC7u);
    lift_push32(cpu, 0u);
    label_000D7BC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7BC9u);
    lift_native_call(cpu, native_function_address32(&::ClipCursor), LIFT_CODE_TOKEN_VA(0x4D7BC9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7BCFu);
    lift_store8(cpu->esi + 0x10u, cpu->ebx & 0xFFu);
    label_000D7BD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7BD2u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7BF0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7C3Cu); lift_push32(cpu, r); sfera_sub_0044C0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7C50u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D7C82;
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->isSystemCursorVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7C68u);
    lift_store8(cpu->esi + 0x11u, cpu->eax & 0xFFu);
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7C74u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    reinterpret_cast<CCursor*>(cpu->edi)->getPosition(cpu);
    goto label_000D7C9B;
    label_000D7C82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7C82u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esi + 0x11u, 1u);
    lift_store32(cpu->esi + 0x14u, 0xFFu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->getPosition(cpu);
    label_000D7C9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7C9Bu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7CB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load8(cpu->esi + 0x11u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->setSystemCursorVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7CC1u);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->setCursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7CCEu);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);

    cpu->edx = lift_load32(cpu->esi + 0x18u);

    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7CDFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7CF0u);
    sfera_sub_0044C0D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D00u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetCursor), LIFT_CODE_TOKEN_VA(0x4D7D04u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D0Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D10u);
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_000D7D38;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::GetCursorPos), LIFT_CODE_TOKEN_VA(0x4D7D1Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D25u);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::ScreenToClient), LIFT_CODE_TOKEN_VA(0x4D7D2Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D32u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D7D38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D38u);
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
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D60u);
    cpu->esp -= 8u;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_000D7D9A;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp);
    lift_store32(cpu->esp, cpu->eax);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x4D7D85u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D8Bu);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::SetCursorPos), LIFT_CODE_TOKEN_RVA(0xD7D94u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0xD7D9Au);
    label_000D7D9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7D9Au);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7DA0u);
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000D7DC0;
    cpu->eax = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x5Fu)) goto label_000D7DC0;
    cpu->eax = 1u;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7DBFu); lift_push32(cpu, r); sfera_sub_004D7B50(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
    label_000D7DC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7DC0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7DC8u); lift_push32(cpu, r); sfera_sub_004D7B50(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7DD0u);
    cpu->esp -= 8u;

    cpu->edx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<CHardwareCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7DDEu);
    cpu->eax = lift_load32(cpu->esp);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D7E06;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_width)) goto label_000D7E06;
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D7E06;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_height)) goto label_000D7E06;
    cpu->eax = 1u;
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D7E06: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E06u);
    cpu->eax = 0u;
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::ShowCursor);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD7E1Bu), LIFT_CODE_TOKEN_RVA(0xD7E19u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E1Bu);
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0xD7E1Fu), LIFT_CODE_TOKEN_RVA(0xD7E1Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E1Fu);
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E30u);
    if ((uint8_t)(lift_load8(cpu->esp + 4u)) == (uint8_t)(0u)) goto label_000D7E3F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7E3Cu); lift_push32(cpu, r); sfera_sub_0044C0F0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
    label_000D7E3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E3Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7E44u); lift_push32(cpu, r); sfera_sub_0044C0D0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E50u);
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7E60u);
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
    label_000D7EA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7EA8u);
    cpu->eax = 0u;
    label_000D7EAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7EAAu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7EB0u); lift_push32(cpu, r); sfera_sub_004D7B50(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_texture_registry_guard)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_000D7EE5;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry_guard, (uint64_t)(g_sfera_cursor_texture_registry_guard) | (uint64_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    lift_store32(cpu->esp + 0x1Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7ED0u); lift_push32(cpu, r); sfera_sub_004D7980(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7EDAu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    label_000D7EE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7EE5u);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7EF3u); lift_push32(cpu, r); sfera_sub_004D7790(cpu,r); if (cpu->eip != r) return; }

    lift_store32(cpu->esi + 0xCu, cpu->eax);

    cpu->ecx = cpu->esi;
    reinterpret_cast<CHardwareCursor*>(cpu->esi)->apply(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7EFFu);
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_texture_registry_guard)) & ((cpu->ebx & 0xFFu))) != 0u) goto label_000D7F30;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry_guard, (uint64_t)(g_sfera_cursor_texture_registry_guard) | (uint64_t)(cpu->ebx));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7F1Bu); lift_push32(cpu, r); sfera_sub_004D7980(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FC0D0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7F25u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    label_000D7F30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7F30u);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_texture_registry;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D7F43u); lift_push32(cpu, r); sfera_sub_004D77B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7F70u);
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
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D7FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7FB0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D7FF8;
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->isSystemCursorVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7FC8u);
    lift_store8(cpu->edi + 0x15u, cpu->eax & 0xFFu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7FD4u);
    lift_store32(cpu->edi + 0x18u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->esi)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7FE5u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->edi + 0x1Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edi + 0x20u, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000D7FF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D7FF8u);
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
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8030u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8040u), LIFT_CODE_TOKEN_RVA(0xD803Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8040u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 5u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x34u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8056u), LIFT_CODE_TOKEN_RVA(0xD8054u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8056u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8064;
    cpu->ecx = (uint32_t)(uintptr_t)"CSoftwareCursor::Activate(): SetCooperativeLevel() failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD8064u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D8064: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8064u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8071u), LIFT_CODE_TOKEN_RVA(0xD806Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8071u);
    cpu->ecx = lift_load8(cpu->esi + 0x15u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setSystemCursorVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D807Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setCursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D808Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);

    cpu->edx = lift_load32(cpu->esi + 0x1Cu);

    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D809Du);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D80A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D80A0u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD80B0u), LIFT_CODE_TOKEN_RVA(0xD80AEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D80B0u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x34u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD80C6u), LIFT_CODE_TOKEN_RVA(0xD80C4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D80C6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D80D4;
    cpu->ecx = (uint32_t)(uintptr_t)"CSoftwareCursor::Deactivate(): SetCooperativeLevel() failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD80D4u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D80D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D80D4u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD80E1u), LIFT_CODE_TOKEN_RVA(0xD80DFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D80E1u);

    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setSystemCursorVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D80ECu);

    lift_push32(cpu, 0xFFu);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->setCursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D80FAu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8100u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0x14u)) == (uint8_t)(0u)) goto label_000D8131;
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D811Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D812Eu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000D8131: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8131u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8140u);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8160u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0xCu, cpu->eax);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8180u);
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
    label_000D81C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D81C1u);

    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoftwareCursor*>(cpu->esi)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D81CAu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000D81DB;
    cpu->eax = sfera_cursor_texture_name(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Fu)) goto label_000D8220;
    label_000D81DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D81DBu);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD81E8u), LIFT_CODE_TOKEN_RVA(0xD81E6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D81E8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D81EDu); lift_push32(cpu, r); sfera_sub_0044C0F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x4D8206u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D820Cu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::SetCursorPos), LIFT_CODE_TOKEN_VA(0x4D8216u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D821Cu);
    lift_store8(cpu->esi + 0x14u, 0u);
    label_000D8220: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8220u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D8230;
    lift_store32(cpu->esi + 0xCu, 0u);
    goto label_000D823E;
    label_000D8230: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8230u);
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    --cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D823E;
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    label_000D823E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D823Eu);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D8251;
    lift_store32(cpu->esi + 0x10u, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D8251: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8251u);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    --cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D82C6;
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_000D8264: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8264u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetCursorPos), LIFT_CODE_TOKEN_VA(0x4D8269u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D826Fu);
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::ScreenToClient), LIFT_CODE_TOKEN_VA(0x4D827Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8281u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_000D82C6;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_width)) goto label_000D82C6;
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000D82C6;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_graphics_runtime.display_height)) goto label_000D82C6;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_000D82C6;
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D82B5u); lift_push32(cpu, r); sfera_sub_0044C0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD82C2u), LIFT_CODE_TOKEN_RVA(0xD82C0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D82C2u);
    lift_store8(cpu->esi + 0x14u, 1u);
    label_000D82C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D82C6u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D82D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D82D0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 0x14u)) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D82E0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000D82E0;
    label_000B84A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B84A0u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B84AC;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
    label_000B84AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B84ACu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
    label_000D82E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D82E0u);
    goto label_000B84A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D82F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D82F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 4u)) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D82F9u); lift_push32(cpu, r); sfera_sub_004B8490(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8300(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000D8300;
    label_000B8410: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B8410u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000B841E;
    cpu->eax = lift_load8(cpu->eax + 8u);
    lift_return(cpu, 0u, stop_address); return;
    label_000B841E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4B841Eu);
    cpu->eax = 0xFFu;
    lift_return(cpu, 0u, stop_address); return;
    label_000D8300: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8300u);
    goto label_000B8410;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8310u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D831Fu); lift_push32(cpu, r); sfera_sub_004B83D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8326u); lift_push32(cpu, r); sfera_sub_004B8430(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8340u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 4u)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<CCursor*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D8359;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8356u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000D8359: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8359u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8360u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 0x1D8u)) & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8370u);
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
    label_000D83D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D83D6u);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x24u);
    label_000D83E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D83E6u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD83E8u), LIFT_CODE_TOKEN_RVA(0xD83E6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D83E8u);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8484;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebx, 0x15u);
    cpu->edi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000D8400: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8400u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(1u)) goto label_000D841D;
    cpu->edx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x24u);
    goto label_000D842F;
    label_000D841D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D841Du);
    cpu->ecx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x24u);
    label_000D842F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D842Fu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8431u), LIFT_CODE_TOKEN_RVA(0xD842Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8431u);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8440;
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(6u)) goto label_000D8400;
    goto label_000D8446;
    label_000D8440: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8440u);
    cpu->ecx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x10u);
    lift_store32(cpu->ebx, cpu->ecx);
    label_000D8446: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8446u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x40u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D8484;
    cpu->ecx = (uint32_t)(uintptr_t)"CheckDeviceType ERROR(windowed):";
    if ((uint32_t)(cpu->ebp) == (uint32_t)(1u)) goto label_000D845C;
    cpu->ecx = (uint32_t)(uintptr_t)"CheckDeviceType ERROR(fullscreen):";
    label_000D845C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D845Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8461u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8469u); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"bbuf=";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8473u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D847Au); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\310\347\342\350\355\350\362\345, \365\340\360\340\352\362\345\360\350\361\362\350\352\350 \302\340\370\345\343\356 3d-\363\361\352\356\360\350\362\345\353\377 \355\345\344\356\361\362\340\362\356\367\355\373 \344\353\377 \347\340\357\363\361\352\340 \350\343\360\373";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD8484u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000D8484: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8484u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D84A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D84A0u);
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
    label_000D8500: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8500u);
    cpu->edx = lift_load32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x10u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8518u), LIFT_CODE_TOKEN_RVA(0xD8516u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8518u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000D8537;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(7u)) goto label_000D8500;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
    label_000D8537: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8537u);
    cpu->ecx = lift_load32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebp, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8560u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    g_sfera_d3d9_semantic_state.sampler_min_filter = (uint32_t)(3u);
    g_sfera_d3d9_semantic_state.sampler_mag_filter = (uint32_t)(2u);
    g_sfera_d3d9_semantic_state.sampler_mip_filter = (uint32_t)(2u);
    cpu->edi = 0u;
    label_000D8585: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8585u);
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_min_filter;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x114u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD859Du), LIFT_CODE_TOKEN_RVA(0xD859Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D859Du);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D85C5;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D85ACu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A2u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D85C2u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D85C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D85C5u);
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_mag_filter;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 5u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x114u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD85DDu), LIFT_CODE_TOKEN_RVA(0xD85DBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D85DDu);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8605;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D85ECu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A4u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8602u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8605: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8605u);
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_mip_filter;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 7u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x114u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD861Du), LIFT_CODE_TOKEN_RVA(0xD861Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D861Du);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8645;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D862Cu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A6u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8642u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8645: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8645u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 4u); lift_push32(cpu, 0xAu); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8658u), LIFT_CODE_TOKEN_RVA(0xD8656u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8658u);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8680;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8667u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1A8u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D867Du); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8680: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8680u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8693u), LIFT_CODE_TOKEN_RVA(0xD8691u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8693u);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D86BB;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D86A2u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1AAu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D86B8u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D86BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D86BBu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD86CEu), LIFT_CODE_TOKEN_RVA(0xD86CCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D86CEu);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D86F6;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D86DDu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1ACu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D86F3u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D86F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D86F6u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x114u);
    lift_push32(cpu, 1u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8709u), LIFT_CODE_TOKEN_RVA(0xD8707u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8709u);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D8731;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8718u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x1AEu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D872Eu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8731: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8731u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(4u)) goto label_000D8585;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8740u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD875Cu), LIFT_CODE_TOKEN_RVA(0xD875Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D875Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8784;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D876Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8781u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8784: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8784u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8790u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D87B1u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D87D9;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D87C0u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x218u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D87D6u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D87D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D87D9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D87E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D87E0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8813u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D883B;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8822u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x231u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8838u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D883B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D883Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8840u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xA8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8852u), LIFT_CODE_TOKEN_RVA(0xD8850u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8852u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D887A;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8861u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x259u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8877u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D887A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D887Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8880u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D88A3u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x88760868u)) goto label_000D88D3;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D88D3;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D88BAu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x29Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D88D0u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D88D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D88D3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D88E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D88E0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D88FEu);
    cpu->ebx = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->ebx);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x100u)) goto label_000D8918;
    cpu->edi += 0x198u;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    label_000D8918: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8918u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000D893B;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8922u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x2A7u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8938u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D893B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D893Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8950u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x198u);
    cpu->ecx = 0x10u;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8970u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xBCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8983u), LIFT_CODE_TOKEN_RVA(0xD8981u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8983u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8990u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xC0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD89A7u), LIFT_CODE_TOKEN_RVA(0xD89A5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D89A7u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D89CF;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D89B6u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2C9u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D89CCu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D89CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D89CFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D89E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D89E0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8A04u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8A2C;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8A13u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2F9u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8A29u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8A2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8A2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8A40u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8A64u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8A8C;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8A73u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x307u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8A89u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8A8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8A8Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8AA0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8AB0u), LIFT_CODE_TOKEN_RVA(0xD8AAEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8AB0u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8AD8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8ABFu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x311u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8AD5u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8AD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8AD8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8AE0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD8AF0u), LIFT_CODE_TOKEN_RVA(0xD8AEEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8AF0u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8B18;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8AFFu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x31Bu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8B15u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8B18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8B18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8B20u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1A0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8B37u), LIFT_CODE_TOKEN_RVA(0xD8B35u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8B37u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8B5F;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8B46u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x354u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8B5Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8B5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8B5Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8B70u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x164u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8B87u), LIFT_CODE_TOKEN_RVA(0xD8B85u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8B87u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8BAF;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8B96u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x35Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8BACu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8BAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8BAFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8BC0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xC4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8BD7u), LIFT_CODE_TOKEN_RVA(0xD8BD5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8BD7u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8BFF;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8BE6u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x368u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8BFCu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8BFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8BFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8C10u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xCCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8C2Cu), LIFT_CODE_TOKEN_RVA(0xD8C2Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8C2Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8C54;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8C3Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x37Cu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8C51u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8C54: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8C54u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8C60u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xD4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8C7Cu), LIFT_CODE_TOKEN_RVA(0xD8C7Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8C7Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8CA4;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8C8Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x390u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8CA1u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8CA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8CA4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8CB0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::D3DXGetShaderConstantTable), LIFT_CODE_TOKEN_VA(0x4D8CBAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8CBFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D8CCE;
    lift_push32(cpu, (uint32_t)(uintptr_t)"D3DXGetShaderConstantTable failed");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8CCDu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu);
    label_000D8CCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8CCEu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8CE0u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x158u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8CFCu), LIFT_CODE_TOKEN_RVA(0xD8CFAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8CFCu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8D24;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8D0Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x3E5u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8D21u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8D24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8D24u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8D30u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1A8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8D4Cu), LIFT_CODE_TOKEN_RVA(0xD8D4Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8D4Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8D74;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8D5Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x3F9u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8D71u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8D74: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8D74u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8D80u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x15Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8D97u), LIFT_CODE_TOKEN_RVA(0xD8D95u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8D97u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8DBF;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8DA6u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x403u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8DBCu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8DBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8DBFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8DD0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x170u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8DE7u), LIFT_CODE_TOKEN_RVA(0xD8DE5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8DE7u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8E0F;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8DF6u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x419u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8E0Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8E0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8E0Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8E20u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1ACu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8E37u), LIFT_CODE_TOKEN_RVA(0xD8E35u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8E37u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8E5F;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8E46u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x423u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8E5Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8E5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8E5Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8E70u);
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
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTexture), LIFT_CODE_TOKEN_VA(0x4D8E9Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8EA0u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8EC8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8EAFu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x434u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8EC5u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8EC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8EC8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 32u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8ED0u);
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
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTextureFromFileInMemoryEx), LIFT_CODE_TOKEN_VA(0x4D8EFDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8F02u);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8F10u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::D3DXCreateCubeTextureFromFileInMemory), LIFT_CODE_TOKEN_VA(0x4D8F27u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8F2Cu);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8F40u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x104u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD8F5Cu), LIFT_CODE_TOKEN_RVA(0xD8F5Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8F5Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8F84;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8F6Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x493u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8F81u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8F84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8F84u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8F90u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8FB1u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D8FD9;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8FC0u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x49Du); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D8FD6u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D8FD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8FD9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D8FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D8FE0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D901Au);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9042;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9029u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4C1u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D903Fu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9042: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9042u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 32u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9050u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9076u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D909E;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9085u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4D3u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D909Bu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D909E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D909Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D90B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D90B0u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1D8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD90CBu), LIFT_CODE_TOKEN_RVA(0xD90C9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D90CBu);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D90E7;
    cpu->ecx = (uint32_t)(uintptr_t)"Render err: cant create query:";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D90DCu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D90E4u); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    label_000D90E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D90E7u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D90F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D90F0u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x98u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD910Cu), LIFT_CODE_TOKEN_RVA(0xD910Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D910Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9134;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D911Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x52Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9131u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9134: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9134u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9140u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x94u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD915Cu), LIFT_CODE_TOKEN_RVA(0xD915Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D915Cu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9184;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D916Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x535u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9181u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9184: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9184u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9190u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Bu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD91A5u), LIFT_CODE_TOKEN_RVA(0xD91A3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D91A5u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x13u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD91BAu), LIFT_CODE_TOKEN_RVA(0xD91B8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D91BAu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD91CFu), LIFT_CODE_TOKEN_RVA(0xD91CDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D91CFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D91E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D91E0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Bu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD91F2u), LIFT_CODE_TOKEN_RVA(0xD91F0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D91F2u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9200u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D921Eu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9234u), LIFT_CODE_TOKEN_RVA(0xD9232u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9234u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 3u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD924Au), LIFT_CODE_TOKEN_RVA(0xD9248u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D924Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9250u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D926Eu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 5u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9284u), LIFT_CODE_TOKEN_RVA(0xD9282u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9284u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + 0x10Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD929Au), LIFT_CODE_TOKEN_RVA(0xD9298u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D929Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D92A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D92A0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D92ECu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D9314;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D92FBu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9311u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000D9314: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9314u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = cpu->edi;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->edx &= 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x89u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xE4u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9330u), LIFT_CODE_TOKEN_RVA(0xD932Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9330u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9358;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D933Fu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9355u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9358: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9358u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    cpu->edi = ~((uint64_t)(cpu->edi));
    cpu->edi &= 1u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x88u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9371u), LIFT_CODE_TOKEN_RVA(0xD936Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9371u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9399;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9380u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9396u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9399: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9399u);
    cpu->eax = lift_load32(cpu->ebp);
    cpu->edx = lift_load32(cpu->eax + 0x34u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD93A7u), LIFT_CODE_TOKEN_RVA(0xD93A5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D93A7u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x164u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD93C1u), LIFT_CODE_TOKEN_RVA(0xD93BFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D93C1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x4Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D94A9;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D93F4;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D93DBu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x35Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D93F1u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D93F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D93F4u);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x190u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD9413u), LIFT_CODE_TOKEN_RVA(0xD9411u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9413u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D943B;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9422u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x34Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9438u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D943B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D943Bu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9446;
    lift_push32(cpu, cpu->eax);
    goto label_000D9450;
    label_000D9446: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9446u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx);
    label_000D9450: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9450u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D945Bu); lift_push32(cpu, r); sfera_sub_004D8B20(cpu,r); if (cpu->eip != r) return; }
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D948Bu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D955F;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D949Eu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4E9u);
    goto label_000D954C;
    label_000D94A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D94A9u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D94CC;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D94B3u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x35Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D94C9u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D94CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D94CCu);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x190u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xD94EBu), LIFT_CODE_TOKEN_RVA(0xD94E9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D94EBu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000D9513;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D94FAu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x34Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9510u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_000D9513: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9513u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9537u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D955F;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9546u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4F9u);
    label_000D954C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D954Cu);
    lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D955Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D955F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D955Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000D9561: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9561u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9580u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D95B7u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D95DF;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D95C6u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D95DCu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D95DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D95DFu);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9606u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->ebx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D962E;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9615u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D962Bu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D962E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D962Eu);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = ~((uint64_t)(cpu->esi));
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    cpu->esi &= 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x88u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD964Eu), LIFT_CODE_TOKEN_RVA(0xD964Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D964Eu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9676;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D965Du); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x20Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9673u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9676: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9676u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D96B3u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ebp + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9734;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D96C2u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4C1u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D96D8u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 28u, stop_address); return;
    label_000D96E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D96E2u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D970Au); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 28u, stop_address); return;
    label_000D9711: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9711u);
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
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD9734u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    label_000D9734: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9734u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D9737: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9737u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9740u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9775u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ecx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D97A1;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9788u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2DCu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D979Eu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D97A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D97A1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000D97A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D97A4u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D97B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D97B0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D97E5u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    lift_store32(cpu->ecx + 0x40u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000D9811;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D97F8u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x2EBu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D980Eu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9811: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9811u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000D9814: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9814u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9820u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9839;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9832u), LIFT_CODE_TOKEN_RVA(0xD9830u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9832u);
    lift_store32(cpu->esi + 4u, 0u);
    label_000D9839: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9839u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9840u);
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
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTexture), LIFT_CODE_TOKEN_VA(0x4D9887u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D988Cu);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D98B8;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D989Fu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x434u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D98B5u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D98B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D98B8u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D98BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D98BBu);
    cpu->eax = 1u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) == (uint32_t)(cpu->eax)) goto label_000D98C8;
    lift_store8(cpu->esi + 0x20u, cpu->eax & 0xFFu);
    label_000D98C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D98C8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D98D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D98D0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000D98E0;
    cpu->eax = cpu->ecx;
    label_000D98E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D98E0u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D98ED;
    lift_store32(cpu->ecx, 0u);
    label_000D98ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D98EDu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000D9915;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9961;
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->deallocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9903u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000D9915: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9915u);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D992Bu);
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0xCu)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000D994B;
    cpu->ecx = cpu->edi;
    label_000D9936: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9936u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000D9942;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->ecx, cpu->edx);
    label_000D9942: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9942u);
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xCu))) goto label_000D9936;
    label_000D994B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D994Bu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D995D;
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->deallocate(cpu);
    label_000D995D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D995Du);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    label_000D9961: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9961u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9970u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 2u); lift_push32(cpu, 0x16u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9994u), LIFT_CODE_TOKEN_RVA(0xD9992u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9994u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D99BC;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D99A3u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x15Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D99B9u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D99BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D99BCu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 7u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD99CEu), LIFT_CODE_TOKEN_RVA(0xD99CCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D99CEu);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D99F6;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D99DDu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x15Du); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D99F3u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D99F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D99F6u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9A08u), LIFT_CODE_TOKEN_RVA(0xD9A06u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9A08u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9A30;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9A17u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x160u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9A2Du); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9A30: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9A30u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 7u); lift_push32(cpu, 0x19u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9A42u), LIFT_CODE_TOKEN_RVA(0xD9A40u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9A42u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9A6A;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9A51u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x163u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9A67u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9A6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9A6Au);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x18u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9A7Cu), LIFT_CODE_TOKEN_RVA(0xD9A7Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9A7Cu);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9AA4;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9A8Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x166u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9AA1u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9AA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9AA4u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0xFu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9AB6u), LIFT_CODE_TOKEN_RVA(0xD9AB4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9AB6u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9ADE;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9AC5u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x169u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9ADBu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9ADE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9ADEu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9AF0u), LIFT_CODE_TOKEN_RVA(0xD9AEEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9AF0u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9B18;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9AFFu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x16Cu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9B15u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9B18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9B18u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x89u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9B2Du), LIFT_CODE_TOKEN_RVA(0xD9B2Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9B2Du);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9B55;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9B3Cu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x16Fu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9B52u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9B55u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9B5Cu); lift_push32(cpu, r); sfera_sub_004D8560(cpu,r); if (cpu->eip != r) return; }
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9BABu);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9BD3;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9BBAu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x182u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9BD0u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9BD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9BD3u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9BE5u), LIFT_CODE_TOKEN_RVA(0xD9BE3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9BE5u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9C0D;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9BF4u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x185u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9C0Au); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9C0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9C0Du);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 3u); lift_push32(cpu, 0x8Cu); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9C22u), LIFT_CODE_TOKEN_RVA(0xD9C20u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9C22u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9C4A;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9C31u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x188u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9C47u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9C4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9C4Au);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9C5Cu), LIFT_CODE_TOKEN_RVA(0xD9C5Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9C5Cu);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9C84;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9C6Bu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18Au); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9C81u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9C84: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9C84u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0x24u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9C96u), LIFT_CODE_TOKEN_RVA(0xD9C94u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9C96u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9CBE;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9CA5u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18Cu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9CBBu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9CBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9CBEu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 0x96u); lift_push32(cpu, 0x25u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9CD3u), LIFT_CODE_TOKEN_RVA(0xD9CD1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9CD3u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9CFB;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9CE2u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x18Eu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9CF8u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9CFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9CFBu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xE4u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x89u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9D10u), LIFT_CODE_TOKEN_RVA(0xD9D0Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9D10u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000D9D38;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9D1Fu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x191u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9D35u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000D9D38: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9D38u);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9D43u); lift_push32(cpu, r); sfera_sub_00450AB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9D60u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9D77u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_01) = (uint32_t)(cpu->esi);
    label_000D9D7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9D7Du);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9D88u); lift_push32(cpu, r); sfera_sub_004DAD30(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000D9DBA;
    label_000D9D90: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9D90u);
    cpu->ecx = lift_load32(cpu->edi + 0x184u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000D9DA1;
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD9DA1u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_000D9DA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9DA1u);
    cpu->eax = lift_load32(cpu->edi + 0x17Cu);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    reinterpret_cast<UnmanagedResourceBase*>(cpu->ecx)->releaseResource(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9DB1u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u))) goto label_000D9D90;
    label_000D9DBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9DBAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9DC0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9DCAu); lift_push32(cpu, r); sfera_sub_004D9970(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1D8u);
    lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.state_01); lift_push32(cpu, 8u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xD9DE5u), LIFT_CODE_TOKEN_RVA(0xD9DE3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9DE5u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000D9E00;
    cpu->ecx = (uint32_t)(uintptr_t)"Render err: cant create query:";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9DF8u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD9E00u); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    label_000D9E00: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9E00u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9E0Bu); lift_push32(cpu, r); sfera_sub_004DAA60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000D9E3E;
    label_000D9E15: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9E15u);
    cpu->ecx = lift_load32(cpu->edi + 0x184u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000D9E26;
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xD9E26u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_000D9E26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9E26u);
    cpu->eax = lift_load32(cpu->edi + 0x17Cu);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    reinterpret_cast<UnmanagedResourceBase*>(cpu->ecx)->restoreResource(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9E35u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x184u))) goto label_000D9E15;
    label_000D9E3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9E3Eu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = (uint32_t)(cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = (uint32_t)(cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_07) = (uint32_t)(cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.vertex32 = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.vertex28 = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.index_primary = (uint32_t)(cpu->ebx);
    g_sfera_render_buffer_capacities.index_secondary = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9E73u); lift_push32(cpu, r); sfera_sub_00456450(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_00468B40(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9E80u);
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
    label_000D9EA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9EA6u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->eax -= cpu->esi;
    cpu->eax -= cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000D9EDB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edx) * 4u));
    cpu->edi = (uint32_t)(((uint32_t)(cpu->esi) * 4u));
    label_000D9EC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9EC1u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->esi = (uint32_t)(cpu->edi + cpu->edx);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000D9ED0;
    cpu->edx = lift_load32(cpu->ebx + cpu->edx);
    lift_store32(cpu->esi, cpu->edx);
    label_000D9ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9ED0u);
    cpu->ebx += 4u;
    cpu->edi += 4u;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000D9EC1;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000D9EDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9EDBu);
    lift_store32(cpu->ecx + 0xCu, (uint64_t)(lift_load32(cpu->ecx + 0xCu)) - (uint64_t)(cpu->ebp) - (uint64_t)(0u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_000D9EE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9EE6u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"bufSize=%d, elemsNum=%d"); lift_push32(cpu, 0x80u); lift_push32(cpu, (uintptr_t)&g_sfera_container_diagnostics_runtime.range_error[0]);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4D9EFDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9F03u);
    lift_push32(cpu, (uintptr_t)&g_sfera_container_diagnostics_runtime.range_error[0]); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"BaseVect::erase: out of range. index=%d, num=%d. %s"); lift_push32(cpu, cpu->edx);
    lift_store8((uintptr_t)&g_sfera_container_diagnostics_runtime.range_error[127], 0u);
    lift_store32(cpu->esp + 0x30u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\BaseVect.h");
    lift_store32(cpu->esp + 0x34u, 0x115u);
    lift_store32(cpu->esp + 0x38u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4D9F38u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x28u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9F50u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000D9F63;
    lift_store32(cpu->eax, 0u);
    label_000D9F63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9F63u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<UnmanagedResourceVector*>(cpu->esi)->reserve(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9F75u);
    cpu->ebp = lift_load32(cpu->esi + 0xCu);
    cpu->ebp -= lift_load32(cpu->esp + 0x14u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000D9FA0;
    label_000D9F82: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9F82u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax -= cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx + 0xFFFFFFFFu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    if ((uint32_t)(cpu->edx) == 0u) goto label_000D9F9B;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 0xFFFFFFFCu);
    lift_store32(cpu->edx, cpu->eax);
    label_000D9F9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9F9Bu);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000D9F82;
    label_000D9FA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9FA0u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000D9FCA;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000D9FCA;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    label_000D9FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9FB6u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000D9FC2;
    cpu->ebp = lift_load32(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->ecx, cpu->ebp);
    label_000D9FC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9FC2u);
    ++cpu->eax;
    cpu->edx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000D9FB6;
    label_000D9FCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9FCAu);
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004D9FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4D9FE0u);
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
    label_000DA021: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA021u);
    cpu->eax = 0x320u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4A0u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000DA036;
    lift_store32(cpu->esp + 0x4A0u, cpu->eax);
    label_000DA036: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA036u);
    cpu->eax = 0x258u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x4A4u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_000DA04B;
    lift_store32(cpu->esp + 0x4A4u, cpu->eax);
    label_000DA04B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA04Bu);
    cpu->ebx = lift_load32(cpu->esp + 0x4ACu);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA05Du); lift_push32(cpu, r); sfera_sub_004CB790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_display_depth_bits;
    cpu->edx = lift_load32(cpu->esp + 0x4A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x4A4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA077u); lift_push32(cpu, r); sfera_sub_004C9DF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000DA0A1;
    cpu->edi = native_function_address32(&::GetSystemMetrics);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDA085u), LIFT_CODE_TOKEN_RVA(0xDA083u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA085u);
    lift_push32(cpu, 1u);
    lift_store32(cpu->esp + 0x4A4u, cpu->eax);
    g_sfera_graphics_runtime.display_width = (uint32_t)(cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDA095u), LIFT_CODE_TOKEN_RVA(0xDA093u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA095u);
    lift_store32(cpu->esp + 0x4A4u, cpu->eax);
    g_sfera_graphics_runtime.display_height = (uint32_t)(cpu->eax);
    label_000DA0A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA0A1u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA0C4u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA0EC;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA0D3u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xF3u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA0E9u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA0EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA0ECu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA128u); lift_push32(cpu, r); sfera_sub_004D8370(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x130u);
    cpu->edi = (uint32_t)(cpu->esi + 0x48u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA133u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA138u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x38u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDA14Au), LIFT_CODE_TOKEN_RVA(0xDA148u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA14Au);
    cpu->eax = lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)((cpu->eax) & (0x10000u)) == 0u) goto label_000DA16A;
    cpu->ebx = 0x40u;
    if ((uint32_t)((cpu->eax) & (0x100000u)) == 0u) goto label_000DA165;
    cpu->ebx = 0x50u;
    label_000DA165: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA165u);
    cpu->ebx |= 2u;
    goto label_000DA16F;
    label_000DA16A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA16Au);
    cpu->ebx = 0x20u;
    label_000DA16F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA16Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10Cu)) < (uint32_t)(0xFFFE0200u)) goto label_000DA190;
    if ((uint32_t)(lift_load32(cpu->esi + 0x114u)) < (uint32_t)(0xFFFF0200u)) goto label_000DA190;
    lift_store8(cpu->esi + 0x1D8u, 1u);
    goto label_000DA197;
    label_000DA190: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA190u);
    lift_store8(cpu->esi + 0x1D8u, 0u);
    label_000DA197: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA197u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA1A8u); lift_push32(cpu, r); sfera_sub_004D84A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x38u);
    cpu->edi = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA1B0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA1B5u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA226u);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA2C3;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDA244u), LIFT_CODE_TOKEN_RVA(0xDA242u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA244u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000DA283;
    lift_push32(cpu, 0x1Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x22Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x47Cu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4DA25Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA260u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)"V='";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA26Du); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x474u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA279u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"'\n";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA283u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    label_000DA283: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA283u);
    cpu->ecx = (uint32_t)(uintptr_t)"CreateDevice ERROR:";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA28Du); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA295u); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"zbuf=";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA29Fu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA2A8u); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"bbuf=";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA2B2u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA2B9u); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\310\347\342\350\355\350\362\345, \365\340\360\340\352\362\345\360\350\361\362\350\352\350 \302\340\370\345\343\356 3d-\363\361\352\356\360\350\362\345\353\377 \355\345\344\356\361\362\340\362\356\367\355\373 \344\353\377 \347\340\357\363\361\352\340 \350\343\360\373";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA2C3u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000DA2C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA2C3u);
    cpu->edi = lift_load32(cpu->esi + 0x40u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA2E9;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA2D0u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x149u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA2E6u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA2E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA2E9u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA2F0u); lift_push32(cpu, r); sfera_sub_004D9970(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x488u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA310u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA31Fu), LIFT_CODE_TOKEN_RVA(0xDA31Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA31Fu);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x88760868u)) goto label_000DA331;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000DA331: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA331u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x88760869u)) goto label_000DA380;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA340u); lift_push32(cpu, r); sfera_sub_004D9D60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x40u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDA34Fu), LIFT_CODE_TOKEN_RVA(0xDA34Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA34Fu);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA377;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA35Eu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x244u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA374u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA377: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA377u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA37Eu); lift_push32(cpu, r); sfera_sub_004D9DC0(cpu,r); if (cpu->eip != r) return; }
    goto label_000DA3A3;
    label_000DA380: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA380u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA3A3;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA38Au); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x249u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA3A0u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA3A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA3A3u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xA4u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA3B1u), LIFT_CODE_TOKEN_RVA(0xDA3AFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA3B1u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esi + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA3D9;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA3C0u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x24Du); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA3D6u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA3D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA3D9u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA3E0u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x184u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000DA442;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    label_000DA400: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA400u);
    cpu->ecx = lift_load32(cpu->eax + 0x184u);
    cpu->edi = (uint32_t)(cpu->eax + 0x178u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000DA41C;
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA417u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    label_000DA41C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA41Cu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(cpu->ebx)) goto label_000DA437;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->eax + 0x178u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA432u); lift_push32(cpu, r); sfera_sub_004D9E80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    label_000DA437: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA437u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x184u))) goto label_000DA400;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000DA442: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA442u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA450u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    std::construct_at(reinterpret_cast<UnmanagedResourceVB*>(cpu->esi));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA46F;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA468u), LIFT_CODE_TOKEN_RVA(0xDA466u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA468u);
    lift_store32(cpu->esi + 4u, 0u);
    label_000DA46F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA46Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA481;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA481u); lift_push32(cpu, r); sfera_sub_004DA3E0(cpu,r); if (cpu->eip != r) return; }
    label_000DA481: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA481u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA490u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    std::construct_at(reinterpret_cast<UnmanagedResourceIB*>(cpu->esi));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA4AF;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA4A8u), LIFT_CODE_TOKEN_RVA(0xDA4A6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA4A8u);
    lift_store32(cpu->esi + 4u, 0u);
    label_000DA4AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA4AFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA4C1;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA4C1u); lift_push32(cpu, r); sfera_sub_004DA3E0(cpu,r); if (cpu->eip != r) return; }
    label_000DA4C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA4C1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA4D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    std::construct_at(reinterpret_cast<UnmanagedResourceTexture*>(cpu->esi));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DA4EF;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA4E8u), LIFT_CODE_TOKEN_RVA(0xDA4E6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA4E8u);
    lift_store32(cpu->esi + 4u, 0u);
    label_000DA4EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA4EFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) == (uint32_t)(1u)) goto label_000DA501;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA501u); lift_push32(cpu, r); sfera_sub_004DA3E0(cpu,r); if (cpu->eip != r) return; }
    label_000DA501: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA501u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA510u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0xCu)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000DA53D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0xCu))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA529u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(0xAu)) goto label_000DA535;
    cpu->eax = (uint32_t)(cpu->esi + 0xAu);
    label_000DA535: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA535u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA53Du); lift_push32(cpu, r); sfera_sub_004D98D0(cpu,r); if (cpu->eip != r) return; }
    label_000DA53D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA53Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA590u);
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
    lift_native_call(cpu, native_function_address32(&::Direct3DCreate9), LIFT_CODE_TOKEN_VA(0x4DA60Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA60Fu);
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000DA62F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x3Bu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, (uintptr_t)"CD3D9Device::CD3D9Device() => Direct3DCreate9() failed."); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA62Cu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA62F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA62Fu);
    lift_push32(cpu, 0x38u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA636u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA63Bu);
    lift_push32(cpu, 0x130u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DA645u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA64Au);
    cpu->esp += 0x18u;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA670u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA6AEu);
    lift_store32(cpu->esi + 4u, cpu->edi);
    label_000DA6B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA6B1u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000DA6C1;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDA6BFu), LIFT_CODE_TOKEN_RVA(0xDA6BDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA6BFu);
    lift_store32(cpu->esi, cpu->edi);
    label_000DA6C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA6C1u);
    cpu->eax = lift_load32(cpu->esi + 0x184u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x178u);
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    std::construct_at(reinterpret_cast<UnmanagedResourceVector*>(cpu->esi + 0x178u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA6E6u); lift_push32(cpu, r); sfera_sub_004D9E80(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x178u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA6F2u); lift_push32(cpu, r); sfera_sub_004D98D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x188u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000DA70D;
    lift_store32(cpu->eax, cpu->edi);
    cpu->ecx = lift_load32(cpu->esi + 0x188u);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    lift_store32(cpu->esi + 0x188u, cpu->edi);
    label_000DA70D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA70Du);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA720u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA76Au);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->edx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA796;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA77Du); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x2DCu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA793u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA796: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA796u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA7BF;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 0x184u);
    lift_push32(cpu, 1u);
    cpu->ecx += 0x178u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA7BFu); lift_push32(cpu, r); sfera_sub_004D9F50(cpu,r); if (cpu->eip != r) return; }
    label_000DA7BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA7BFu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA7D0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA81Au);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->edx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA846;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA82Du); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x2EBu); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA843u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA846: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA846u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(1u)) goto label_000DA86F;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 0x184u);
    lift_push32(cpu, 1u);
    cpu->ecx += 0x178u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDA86Fu); lift_push32(cpu, r); sfera_sub_004D9F50(cpu,r); if (cpu->eip != r) return; }
    label_000DA86F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA86Fu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA880u);
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
    lift_native_call(cpu, native_function_address32(&::D3DXCreateTexture), LIFT_CODE_TOKEN_VA(0x4DA8D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA8DCu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->edx + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000DA908;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA8EFu); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x434u); lift_push32(cpu, (uintptr_t)"dx9Render\\CD3D9Device.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA905u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DA908: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA908u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(1u)) goto label_000DA934;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 0x184u);
    lift_push32(cpu, 1u);
    cpu->ecx += 0x178u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DA930u); lift_push32(cpu, r); sfera_sub_004D9F50(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x20u, 0u);
    label_000DA934: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA934u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DA940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DA940u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAA32u); lift_push32(cpu, r); sfera_sub_004D8CE0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DAA39u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAA3Eu);
    cpu->esp += 0xCu;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAA60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAA60u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->edi + 8u)) == (uint8_t)(0u)) goto label_000DAB93;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAA7Eu), LIFT_CODE_TOKEN_RVA(0xDAA7Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAA7Eu);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAAA0;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAA8Au); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x7Fu); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAA9Du); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DAAA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAAA0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAACCu);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAAF1;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAAD8u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x8Au); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAAEEu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DAAF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAAF1u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x5Cu);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edi + 0x90u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, 0x16u); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0x80u); lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAB1Du), LIFT_CODE_TOKEN_RVA(0xDAB1Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAB1Du);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAB42;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAB29u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x98u); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAB3Fu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DAB42: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAB42u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x5Cu);
    lift_push32(cpu, 0u);
    cpu->edi += 0x8Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x16u); lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0x80u); lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAB6Du), LIFT_CODE_TOKEN_RVA(0xDAB6Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAB6Du);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000DAB92;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAB79u); lift_push32(cpu, r); sfera_sub_004E787C(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xA3u); lift_push32(cpu, (uintptr_t)"dx9Render\\PostEffectsMgr.cpp"); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s : (%s, %d, %d)\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAB8Fu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000DAB92: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAB92u);
    cpu->esi = lift_pop32(cpu);
    label_000DAB93: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAB93u);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DABA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DABA0u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DABB0u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DABBFu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    label_000DABC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DABC1u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DABD1u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DABE1u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 6u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DABF1u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC01u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC11u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(2u)) goto label_000DABC1;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC24u); lift_push32(cpu, r); sfera_sub_004D8DD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_d3d9_semantic_state.vertex_declaration;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC35u); lift_push32(cpu, r); sfera_sub_004D8D80(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DACD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DACD0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000DAD24;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DACE8u); lift_push32(cpu, r); sfera_sub_004D90F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 8u, 0u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDAD02u), LIFT_CODE_TOKEN_RVA(0xDAD00u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD02u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAD14u); lift_push32(cpu, r); sfera_sub_004D9140(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD24;
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDAD24u), LIFT_CODE_TOKEN_RVA(0xDAD22u))) { return; }
    label_000DAD24: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD24u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x8Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD4F;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD45u), LIFT_CODE_TOKEN_RVA(0xDAD43u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD45u);
    lift_store32(cpu->esi + 0x8Cu, 0u);
    label_000DAD4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD4Fu);
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD6B;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD61u), LIFT_CODE_TOKEN_RVA(0xDAD5Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD61u);
    lift_store32(cpu->esi + 0x90u, 0u);
    label_000DAD6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD6Bu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD81;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD7Au), LIFT_CODE_TOKEN_RVA(0xDAD78u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD7Au);
    lift_store32(cpu->esi + 4u, 0u);
    label_000DAD81: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD81u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DAD95;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAD8Fu), LIFT_CODE_TOKEN_RVA(0xDAD8Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD8Fu);
    lift_store32(cpu->esi, 0u);
    label_000DAD95: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAD95u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DADA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DADA0u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DADCCu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x30u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0xDADDDu), LIFT_CODE_TOKEN_RVA(0xDADDBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DADDDu);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DADFEu); lift_push32(cpu, r); sfera_sub_004D9140(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000DAE12;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDAE0Eu), LIFT_CODE_TOKEN_RVA(0xDAE0Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAE0Eu);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_000DAE12: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAE12u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAF24u); lift_push32(cpu, r); sfera_sub_004D87E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 2u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAF36u); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAF50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAF50u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 4u)) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000DAF6D;
    lift_store8(cpu->ecx + 8u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000DAF68;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAF65u); lift_push32(cpu, r); sfera_sub_004DAA60(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
    label_000DAF68: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAF68u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDAF6Du); lift_push32(cpu, r); sfera_sub_004DAD30(cpu,r); if (cpu->eip != r) return; }
    label_000DAF6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAF6Du);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DAF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAF70u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAF84u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAF91u); lift_push32(cpu, r); sfera_sub_004DD550(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAF9Fu); lift_push32(cpu, r); sfera_sub_004DADA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x8Cu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAFB3u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAFC0u); lift_push32(cpu, r); sfera_sub_004DD550(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAFCEu); lift_push32(cpu, r); sfera_sub_004DADA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x90u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAFE2u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAFEFu); lift_push32(cpu, r); sfera_sub_004DD550(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x8Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAFFDu); lift_push32(cpu, r); sfera_sub_004DADA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB000u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB005u); lift_push32(cpu, r); sfera_sub_004DAD30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_d3d9_semantic_state.vertex_declaration;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DB020;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDB016u), LIFT_CODE_TOKEN_RVA(0xDB014u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB016u);
    g_sfera_d3d9_semantic_state.vertex_declaration = (uint32_t)(0u);
    label_000DB020: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB020u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB030(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000DB030;
    label_000DAC40: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAC40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_000DAC43: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DAC43u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC53u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC63u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_d3d9_semantic_state.sampler_min_filter;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 6u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC77u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_d3d9_semantic_state.sampler_mag_filter;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 5u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DAC8Cu); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_d3d9_semantic_state.sampler_mip_filter;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 7u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DACA1u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(2u)) goto label_000DAC43;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DACB6u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DACC5u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000DB030: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB030u);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->ebx + 8u)) == (uint8_t)(0u)) goto label_000DB1EA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB045u); lift_push32(cpu, r); sfera_sub_004DABA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB04Cu); lift_push32(cpu, r); sfera_sub_004DAF70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB05Cu); lift_push32(cpu, r); sfera_sub_004D9140(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DB070;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0xDB06Au), LIFT_CODE_TOKEN_RVA(0xDB068u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB06Au);
    lift_store32(cpu->ebx, 0u);
    label_000DB070: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB070u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB084u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB098u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_d3d9_semantic_state.shader_manager;
    lift_push32(cpu, 9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB0A5u); lift_push32(cpu, r); sfera_sub_004DD550(cpu,r); if (cpu->eip != r) return; }
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB1CAu); lift_push32(cpu, r); sfera_sub_004D87E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB1DCu); lift_push32(cpu, r); sfera_sub_004D9050(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    goto label_000DAC40;
    label_000DB1EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB1EAu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB1F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB1F0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    cpu->edi = 0u;
    --cpu->esi;
    label_000DB202: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB202u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x40u)) goto label_000DB236;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"CShaderMgr::calc_inst_code: to many PIN's in %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x20u, 0x59u);
    lift_store32(cpu->esp + 0x24u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB233u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000DB236: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB236u);
    cpu->eax = (int8_t)(lift_load8(cpu->esi + 1u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (int8_t)(lift_load8(cpu->esi + 2u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFDF0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB250u); lift_push32(cpu, r); sfera_sub_004EEDF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += 3u;
    cpu->ebx |= cpu->eax;
    cpu->ebp |= cpu->edx;
    cpu->edi += 8u;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x5Fu)) goto label_000DB202;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x24u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DB26E;
    cpu->ebx |= 0x80u;
    label_000DB26E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB26Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB280u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB29Cu);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000DB2CD;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"No constant %s in shader"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x1Cu, 0x142u);
    lift_store32(cpu->esp + 0x20u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB2CAu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000DB2CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB2CDu);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB2EDu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DB31C;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"ID3DXConstantTable::SetValue failed. %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x1Cu, 0x146u);
    lift_store32(cpu->esp + 0x20u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB319u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000DB31C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB31Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB330u);
    cpu->esp -= 0x68u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::rand);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    cpu->esi = 0u;
    label_000DB350: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB350u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDB352u), LIFT_CODE_TOKEN_RVA(0xDB350u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB352u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.2831854820251465));
    lift_store_f32(cpu->esp + cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0xDB36Cu), LIFT_CODE_TOKEN_RVA(0xDB36Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB36Cu);
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
    label_000DB3A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB3A2u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->esi = 0u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.012271846644580364));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB3C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB3C0u);
    cpu->edi = (uint32_t)(cpu->esi + 1u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + ((uint32_t)(cpu->esi) * 4u) + 0x24u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB3E0u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
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
    label_000DB427: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB427u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB429: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB429u);
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
    label_000DB45D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB45Du);
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
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB4C0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB51Du); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000DB533: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB533u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB5B0u); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000DB5C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB5C6u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB613u); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000DB629: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB629u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000DB62F;
    label_000DB62D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB62Du);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB62F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB62Fu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB65Du); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.30000001192092896));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000DB673: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB673u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000DB675: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB675u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB680u);
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
    label_000DB747: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB747u);
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
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB800u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DB810: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB810u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB846u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
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
    lift_return(cpu, 4u, stop_address); return;
    label_000DB87B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB87Bu);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DB87Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB884u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB8A0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->esi;
    cpu->ebx = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DB8B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB8B0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB8E9u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
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
    lift_return(cpu, 4u, stop_address); return;
    label_000DB907: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB907u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DB90Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB910u);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB920u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->esi;
    cpu->ebx = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DB930: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB930u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DB969u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
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
    lift_return(cpu, 4u, stop_address); return;
    label_000DB98A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB98Au);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DB98Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB993u);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DB9A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB9A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store16(cpu->ecx + 0x5Au, cpu->eax & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000DB9F1;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000DB9C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB9C0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000DB9D0;
    cpu->edx = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]) & 0xFFu);
    label_000DB9D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB9D0u);
    cpu->ebp = lift_load32(cpu->ecx + 0x10u);
    lift_store8(cpu->eax + cpu->ebp, cpu->edx & 0xFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + 0x5Au)) & 0xFFFFu);
    cpu->edx = cpu->edx & 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_shift_right(cpu, (cpu->ebp & 0xFFFFu), (uint32_t)(1u), 16u)) & 0xFFFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebp & 0xFFFFu)) + (uint64_t)(g_sfera_string_lookup_runtime.hash_mix[(uint8_t)cpu->edx]) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    lift_store16(cpu->ecx + 0x5Au, cpu->ebp & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_000DB9C0;
    label_000DB9F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DB9F1u);
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
    label_000DBA32: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBA32u);
    cpu->ebp = lift_load32(cpu->ecx + 0x50u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x1Cu)) != (uint32_t)(cpu->esi)) goto label_000DBA8C;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->esi;
    cpu->esi = lift_load32(cpu->ecx + 0x10u);
    cpu->edi = (uint32_t)(cpu->ebp + 0x22u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000DBA64;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000DBA50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBA50u);
    cpu->edx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_000DBA88;
    cpu->eax -= 4u;
    cpu->esi += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000DBA50;
    label_000DBA64: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBA64u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DBABA;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi))) goto label_000DBA88;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_000DBABA;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi + 1u))) goto label_000DBA88;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(2u)) goto label_000DBABA;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 2u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(lift_load8(cpu->edi + 2u))) goto label_000DBABA;
    label_000DBA88: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBA88u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000DBA8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBA8Cu);
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
    label_000DBABA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBABAu);
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
    label_000DBAEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBAEAu);
    cpu->eax = lift_load16(cpu->ecx + 0x4Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000DBAF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBAF5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBB00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBB00u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBB36u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_000DBB42: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBB42u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000DBB50: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBB50u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DBB50;
    cpu->eax -= cpu->esi;
    cpu->ecx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000DBB61;
    cpu->ecx = cpu->edx;
    label_000DBB61: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBB61u);
    cpu->eax = cpu->ebx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000DBB66: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBB66u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBBA4u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x93u;
    cpu->esp += 8u;
    cpu->ecx -= cpu->edi;
    cpu->esi = 0x94u;
    label_000DBBB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBBB3u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edi += cpu->ebx;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DBBB8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBBBDu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + cpu->ebx + 0xFFFFFFFFu, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBBE0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBC23u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000DBC26: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBC26u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(1u)) goto label_000DBC5B;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"HashMap::init: wrong _maxKeyLen=%d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x20u, 0x9Bu);
    lift_store32(cpu->esp + 0x24u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBC58u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000DBC5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBC5Bu);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = 1u;
    cpu->eax = 0u;
    label_000DBC66: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBC66u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000DBC72;
    ++cpu->eax;
    cpu->ecx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x20u)) goto label_000DBC66;
    label_000DBC72: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBC72u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x20u)) goto label_000DBCA1;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::init:  hashTabSize must be power of 2"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0xA2u);
    lift_store32(cpu->esp + 0x20u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBC9Eu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000DBCA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBCA1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBCA6u); lift_push32(cpu, r); sfera_sub_004ED5C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000DBCB3;
    lift_store32(cpu->esi + 0x48u, cpu->eax);
    goto label_000DBCBA;
    label_000DBCB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBCB3u);
    lift_store32(cpu->esi + 0x48u, (uintptr_t)&g_sfera_std_allocator);
    label_000DBCBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBCBAu);
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
    label_000DBD03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD03u);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 8u), 32u, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0x14u)) goto label_000DBD1D;
    lift_store32(cpu->esi + 0xCu, 0x14u);
    label_000DBD1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD1Du);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    cpu->ecx = lift_load32(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD2Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x48u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD3Du);
    cpu->ecx = lift_load32(cpu->esi + 0x48u);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD4Du);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4DBD57u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD5Cu);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->esp += 0xCu;
    --cpu->ecx;
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000DBD97;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000DBD70: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD70u);
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
    label_000DBD97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBD97u);
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
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBDD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBDD0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DBDE6;
    lift_store32(cpu->eax, 0u);
    label_000DBDE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBDE6u);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = 1u;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000DBE03;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x1Eu)) != (uint8_t)(0u)) goto label_000DBE03;
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    goto label_000DBE0C;
    label_000DBE03: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBE03u);
    lift_store8(cpu->esp + 0x20u, 0u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000DBE20;
    label_000DBE0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBE0Cu);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DBE11: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBE11u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DBE11;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->edi = cpu->eax;
    label_000DBE20: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBE20u);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(lift_load32(cpu->ebp))) goto label_000DBE58;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::insert: maxKeyLen exceed"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0x129u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBE48u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000DBE4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBE4Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000DBE58: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBE58u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBE66u); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DBEA5u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000DBEB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBEB5u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = cpu->eax;
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(1u), 32u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0xAu)) goto label_000DBEC6;
    cpu->esi = 0xAu;
    label_000DBEC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBEC6u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp + 0xCu)) & 0xFFFFu);
    lift_store32(cpu->ebp + 0xCu, (uint64_t)(lift_load32(cpu->ebp + 0xCu)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    lift_store16(cpu->ebp + 0x14u, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_000DBEE1;
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->esi += cpu->edx;
    lift_store32(cpu->ebp + 0xCu, cpu->ecx);
    label_000DBEE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBEE1u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    cpu->ecx = lift_load32(cpu->ebp + 0x48u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->reallocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBEF9u);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000DBF35;
    label_000DBF05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBF05u);
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
    label_000DBF35: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBF35u);
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
    label_000DBF60: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBF60u);
    cpu->ebx = lift_load16(cpu->ebp + 0x14u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(lift_load32(cpu->ebp + 8u));
    cpu->ebx += lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x22u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4DBF74u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBF79u);
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
    label_000DBFA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBFA6u);
    lift_store8(cpu->ebx, cpu->ecx & 0xFFu);
    lift_store32(cpu->ebx + 0x14u, cpu->ecx);
    lift_store32(cpu->ebx + 0x18u, cpu->ecx);
    label_000DBFAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBFAEu);
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
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DBFE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DBFE0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC08Du); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC09D;
    cpu->edi = lift_load32(cpu->esi + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi += lift_load32(cpu->esi + 4u);
    goto label_000DC0A0;
    label_000DC09D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC09Du);
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    label_000DC0A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC0A0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC0F4u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DC0F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC0F7u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->edi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC195;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store8(cpu->esp + 0x50u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC119u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC128u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC13Bu); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC149u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0xF4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC15Du); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC170u); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC17Du); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0xF4u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC191u); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    label_000DC195: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC195u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC1A3u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xECu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC1D0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC23Bu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC24B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC24E;
    label_000DC24B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC24Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC24E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC24Eu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) != (uint32_t)(0xFFFFFFFFu)) goto label_000DC297;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x83u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0xECu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0xF0u, 0xF6u);
    lift_store32(cpu->esp + 0xF4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC294u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DC297: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC297u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_000DC32A;
    cpu->edx = (uint32_t)(cpu->ebp + 0xA0u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x40u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC2B4u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC2C3u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC2D6u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC2E4u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC2F4u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC306u); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC316u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDC32Au); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DC32A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC32Au);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC339u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_alpha_material_runtime.alpha[0]); lift_push32(cpu, (uintptr_t)"gAlpha"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC34Du); lift_push32(cpu, r); sfera_sub_004DB280(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC380u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC3EBu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC3FB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC3FE;
    label_000DC3FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC3FBu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC3FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC3FEu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC442u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DC445: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC445u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC4DC;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC465u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC474u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC487u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC495u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC4A5u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC4BBu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC4C8u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDC4DCu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DC4DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC4DCu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC4F1u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC520u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC58Bu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC59B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC59E;
    label_000DC59B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC59Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC59E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC59Eu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC5EA;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x81u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0xF0u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0xF8u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0xFCu, 0xF6u);
    lift_store32(cpu->esp + 0x100u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC5E7u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DC5EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC5EAu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_000DC67A;
    cpu->edx = (uint32_t)(cpu->ebp + 0xA0u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC607u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC616u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC629u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC637u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC647u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC656u); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC666u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF4u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDC67Au); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DC67A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC67Au);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC688u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC6A0u); lift_push32(cpu, r); sfera_sub_004DB4C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"gWaterGradientCoefficient"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC6B4u); lift_push32(cpu, r); sfera_sub_004DB280(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"gWaterSpecular"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC6C8u); lift_push32(cpu, r); sfera_sub_004DB280(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"gWaterReflectCoefficient"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC6DCu); lift_push32(cpu, r); sfera_sub_004DB280(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xECu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC710u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC77Bu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC78B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC78E;
    label_000DC78B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC78Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC78E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC78Eu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC7D2u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DC7D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC7D5u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DC86C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC7F5u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC804u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC817u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC825u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC835u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC84Bu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC858u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDC86Cu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DC86C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC86Cu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC881u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DC8B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC8B0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC91Bu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DC92B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DC92E;
    label_000DC92B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC92Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DC92E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC92Eu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC972u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DC975: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DC975u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCA0C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC995u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC9A4u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC9B7u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC9C5u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC9D5u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC9EBu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DC9F8u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDCA0Cu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DCA0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCA0Cu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCA21u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCA50u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCABBu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCACB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCACE;
    label_000DCACB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCACBu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCACE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCACEu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) != (uint32_t)(0xFFFFFFFFu)) goto label_000DCB17;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x86u); lift_push32(cpu, (uintptr_t)"pixel");
    cpu->ecx = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, (uintptr_t)"Unexpected pin combination for %s shader. %d %d %d %d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0xECu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0xF0u, 0xF6u);
    lift_store32(cpu->esp + 0xF4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB14u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DCB17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCB17u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_000DCBAA;
    cpu->edx = (uint32_t)(cpu->ebp + 0xA0u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x40u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB34u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB43u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB56u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB64u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB74u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB86u); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCB96u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0xE8u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDCBAAu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DCBAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCBAAu);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCBB9u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x80u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x920u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"gTexelCoordsDownFilter"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCBD2u); lift_push32(cpu, r); sfera_sub_004DB280(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xD8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCC00u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCC6Bu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCC7B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCC7E;
    label_000DCC7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCC7Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCC7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCC7Eu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCCC2u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DCCC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCCC5u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCD5C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCCE5u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCCF4u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCD07u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCD15u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCD25u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCD3Bu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCD48u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDCD5Cu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DCD5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCD5Cu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCD71u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCDA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCDA0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCE0Bu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCE1B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCE1E;
    label_000DCE1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCE1Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCE1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCE1Eu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCE62u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DCE65: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCE65u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DCEFC;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCE85u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCE94u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCEA7u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCEB5u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCEC5u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCEDBu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCEE8u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDCEFCu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DCEFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCEFCu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCF11u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DCF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCF40u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DCFABu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DCFBB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DCFBE;
    label_000DCFBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCFBBu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DCFBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DCFBEu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD002u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DD005: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD005u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD09C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD025u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD034u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD047u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD055u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD065u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD07Bu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD088u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDD09Cu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DD09C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD09Cu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD0B1u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD0E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD0E0u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD14Bu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DD15B;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DD15E;
    label_000DD15B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD15Bu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DD15E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD15Eu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD1A2u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DD1A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD1A5u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD23C;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD1C5u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD1D4u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD1E7u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD1F5u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD205u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD21Bu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD228u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDD23Cu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DD23C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD23Cu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD251u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD280u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD2EBu); lift_push32(cpu, r); sfera_sub_004DB9A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000DD2FB;
    cpu->esi = lift_load32(cpu->edi + 8u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->eax);
    cpu->esi += lift_load32(cpu->edi + 4u);
    goto label_000DD2FE;
    label_000DD2FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD2FBu);
    cpu->esi = (uint32_t)(cpu->edi + 0x28u);
    label_000DD2FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD2FEu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD342u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_000DD345: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD345u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x18u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DD3DC;
    cpu->ebp += 0xA0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD365u); lift_push32(cpu, r); sfera_sub_004DB920(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD374u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".psc");
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD387u); lift_push32(cpu, r); sfera_sub_004DBB00(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD395u); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD3A5u); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD3BBu); lift_push32(cpu, r); sfera_sub_004D8D30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD3C8u); lift_push32(cpu, r); sfera_sub_004D8CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0xF0u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0xDD3DCu); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_000DD3DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD3DCu);
    cpu->ecx = lift_load32(cpu->esp + 0xDCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD3F1u); lift_push32(cpu, r); sfera_sub_004D8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD420u);
    cpu->esp -= 0x15Cu;
    cpu->eax = lift_load32(cpu->esp + 0x160u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x4DD445u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD44Bu);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_000DD52F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x174u);
    cpu->ebx = 0u;
    label_000DD464: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD464u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x40u)) & (0x10u)) != 0u) goto label_000DD50C;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD47Cu); lift_push32(cpu, r); sfera_sub_004DB1F0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store8(cpu->esp + 0x28u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD49Eu); lift_push32(cpu, r); sfera_sub_004DB800(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000DD4A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD4A5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000DD4A5;
    cpu->eax -= cpu->edx;
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000DD4CA;
    label_000DD4B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD4B3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x24u)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x5Cu)) goto label_000DD4CA;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_000DD4C6;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000DD4B3;
    goto label_000DD4CA;
    label_000DD4C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD4C6u);
    lift_store8(cpu->esp + cpu->eax + 0x24u, cpu->ebx & 0xFFu);
    label_000DD4CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD4CAu);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 8u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD4DDu); lift_push32(cpu, r); sfera_sub_004DBDD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000DD50C;
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"CShaderMgr::load_folder: duplicate shader code"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x24u, 0x7Bu);
    lift_store32(cpu->esp + 0x28u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD509u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000DD50C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD50Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x4DD512u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD518u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000DD464;
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4DD524u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD52Au);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000DD52F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD52Fu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x15Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD550u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD56Cu); lift_push32(cpu, r); sfera_sub_004DBFE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD572: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD572u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD577u); lift_push32(cpu, r); sfera_sub_004DC520(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD57D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD57Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD582u); lift_push32(cpu, r); sfera_sub_004DC380(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD588: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD588u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD58Du); lift_push32(cpu, r); sfera_sub_004DC1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD593: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD593u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD598u); lift_push32(cpu, r); sfera_sub_004DC710(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD59E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD59Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD5A3u); lift_push32(cpu, r); sfera_sub_004DC8B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD5A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD5A9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD5AEu); lift_push32(cpu, r); sfera_sub_004DCA50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD5B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD5B4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD5B9u); lift_push32(cpu, r); sfera_sub_004DCC00(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD5BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD5BFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD5C4u); lift_push32(cpu, r); sfera_sub_004DCDA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD5CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD5CAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD5CFu); lift_push32(cpu, r); sfera_sub_004DCF40(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD5D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD5D5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD5DAu); lift_push32(cpu, r); sfera_sub_004DD0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD5E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD5E0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD5E5u); lift_push32(cpu, r); sfera_sub_004DD280(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000DD5EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD5EBu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, (uintptr_t)"CShaderMgr::set_ps: unknown psg = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, (uintptr_t)"dx9Render\\ShaderMgr.cpp");
    lift_store32(cpu->esp + 0x10u, 0xB6u);
    lift_store32(cpu->esp + 0x14u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD613u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000DD616: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD616u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD660u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD6D5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x5Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD6DCu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x428u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000DD702;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x10000u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 8u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD700u); lift_push32(cpu, r); sfera_sub_004DBBE0(cpu,r); if (cpu->eip != r) return; }
    goto label_000DD704;
    label_000DD702: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD702u);
    cpu->eax = 0u;
    label_000DD704: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD704u);
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x428u, cpu->ecx);
    lift_store32(cpu->ebp + 0x18u, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->eax + 0x28u);
    lift_store32(cpu->ebp, cpu->eax);
    cpu->ecx = 7u;
    lift_movs32(cpu, 1u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD727u); lift_push32(cpu, r); sfera_sub_004DB8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD737u); lift_push32(cpu, r); sfera_sub_004DB8A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    (void)cpu;
    label_000DD740: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD740u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DD740;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    --cpu->eax;
    (void)cpu;
    label_000DD750: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD750u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD779u); lift_push32(cpu, r); sfera_sub_004DD420(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_000DD781: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD781u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000DD781;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    --cpu->eax;
    label_000DD790: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD790u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD7B9u); lift_push32(cpu, r); sfera_sub_004DD420(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD7C0u); lift_push32(cpu, r); sfera_sub_004DB330(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    cpu->esp -= 8u;
    cpu->ecx = cpu->ebp;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD7DDu); lift_push32(cpu, r); sfera_sub_004DB680(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_load32(cpu->esp + 0x420u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD810u);
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
    label_000DD834: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD834u);
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
    label_000DD856: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD856u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 0u);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0u);
    lift_push32(cpu, 0x38u); lift_push32(cpu, (uintptr_t)"1.1.3");
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD874u); lift_push32(cpu, r); sfera_sub_004DDC0A(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0u)) goto label_000DD885;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    goto label_000DD8DC;
    label_000DD885: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD885u);
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD890u); lift_push32(cpu, r); sfera_sub_004DDC25(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(1u)) goto label_000DD8C2;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD8A5u); lift_push32(cpu, r); sfera_sub_004DDA3B(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) != (uint32_t)(0u)) goto label_000DD8B7;
    lift_store32(cpu->ebp + 0xFFFFFFC0u, 0xFFFFFFFBu);
    goto label_000DD8BD;
    label_000DD8B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD8B7u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    lift_store32(cpu->ebp + 0xFFFFFFC0u, cpu->edx);
    label_000DD8BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD8BDu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC0u);
    goto label_000DD8DC;
    label_000DD8C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD8C2u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD8D3u); lift_push32(cpu, r); sfera_sub_004DDA3B(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000DD8DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD8DCu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD8E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD8E0u);
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
    label_000DD914: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD914u);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, 0u);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, 0u);
    lift_push32(cpu, 0x38u); lift_push32(cpu, (uintptr_t)"1.1.3");
    cpu->ecx = lift_load32(cpu->ebp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD93Du); lift_push32(cpu, r); sfera_sub_004DE540(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0u)) goto label_000DD94E;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    goto label_000DD9A5;
    label_000DD94E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD94Eu);
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD959u); lift_push32(cpu, r); sfera_sub_004DEBDE(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(1u)) goto label_000DD98B;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD96Eu); lift_push32(cpu, r); sfera_sub_004DF075(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) != (uint32_t)(0u)) goto label_000DD980;
    lift_store32(cpu->ebp + 0xFFFFFFC0u, 0xFFFFFFFBu);
    goto label_000DD986;
    label_000DD980: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD980u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    lift_store32(cpu->ebp + 0xFFFFFFC0u, cpu->edx);
    label_000DD986: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD986u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFC0u);
    goto label_000DD9A5;
    label_000DD98B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD98Bu);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFC4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DD99Cu); lift_push32(cpu, r); sfera_sub_004DF075(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    label_000DD9A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD9A5u);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DD9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD9D0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DD9E2;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) != (uint32_t)(0u)) goto label_000DD9E9;
    label_000DD9E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD9E2u);
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDA39;
    label_000DD9E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DD9E9u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DDA34u); lift_push32(cpu, r); sfera_sub_004E0950(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_000DDA39: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDA39u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDA3B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDA3Bu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DDA56;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) == (uint32_t)(0u)) goto label_000DDA56;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x24u)) != (uint32_t)(0u)) goto label_000DDA5D;
    label_000DDA56: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDA56u);
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDAA2;
    label_000DDA5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDA5Du);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) == (uint32_t)(0u)) goto label_000DDA7F;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DDA7Cu); lift_push32(cpu, r); sfera_sub_004E1E72(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000DDA7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDA7Fu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->eax + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDDA93u), LIFT_CODE_TOKEN_RVA(0xDDA90u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDA93u);
    cpu->esp += 8u;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x1Cu, 0u);
    cpu->eax = 0u;
    label_000DDAA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDAA2u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDAA4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDAA4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x10u)) == (uint32_t)(0u)) goto label_000DDAC4;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (int32_t)(int8_t)lift_load8((uintptr_t)"1.1.3");
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000DDAC4;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) == (uint32_t)(0x38u)) goto label_000DDACE;
    label_000DDAC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDAC4u);
    cpu->eax = 0xFFFFFFFAu;
    goto label_000DDC08;
    label_000DDACE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDACEu);
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) != (uint32_t)(0u)) goto label_000DDADE;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDC08;
    label_000DDADE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDADEu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x18u, 0u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x20u)) != (uint32_t)(0u)) goto label_000DDB05;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 0x20u, LIFT_CALLBACK(sfera_sub_004E21BE));
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x28u, 0u);
    label_000DDB05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDB05u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x24u)) != (uint32_t)(0u)) goto label_000DDB18;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 0x24u, LIFT_CALLBACK(sfera_sub_004E21E7));
    label_000DDB18: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDB18u);
    lift_push32(cpu, 0x18u); lift_push32(cpu, 1u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->edx + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDDB29u), LIFT_CODE_TOKEN_RVA(0xDDB26u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDB29u);
    cpu->esp += 0xCu;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x1Cu)) != (uint32_t)(0u)) goto label_000DDB45;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DDC08;
    label_000DDB45: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDB45u);
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
    label_000DDB7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDB7Au);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xCu)) < (int32_t)(uint32_t)(8u)) goto label_000DDB86;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(0xFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000DDB99;
    label_000DDB86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDB86u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DDB8Fu); lift_push32(cpu, r); sfera_sub_004DDA3B(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DDC08;
    label_000DDB99: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDB99u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DDBCFu); lift_push32(cpu, r); sfera_sub_004E0A07(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) != (uint32_t)(0u)) goto label_000DDBFA;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DDBF0u); lift_push32(cpu, r); sfera_sub_004DDA3B(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DDC08;
    label_000DDBFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDBFAu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DDC03u); lift_push32(cpu, r); sfera_sub_004DD9D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    label_000DDC08: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDC08u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDC0A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDC0Au);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xFu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DDC20u); lift_push32(cpu, r); sfera_sub_004DDAA4(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DDC25(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDC25u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DDC42;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) == (uint32_t)(0u)) goto label_000DDC42;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(0u)) goto label_000DDC4C;
    label_000DDC42: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDC42u);
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DDC4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDC4Cu);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xCu)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->edx;
    cpu->edx &= 0xFFFFFFFBu;
    lift_store32(cpu->ebp + 0xCu, cpu->edx);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0xFFFFFFFBu);
    label_000DDC63: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDC63u);
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
    label_000DDCA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDCA0u);
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
    label_000DDD1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDD1Cu);
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
    label_000DDD5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDD5Eu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 1u);
    label_000DDD6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDD6Au);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(0u)) goto label_000DDD7B;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDD7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDD7Bu);
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
    label_000DDDFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDDFCu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFFCu);
    cpu->ecx &= 0x20u;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000DDE17;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    lift_store32(cpu->eax, 7u);
    goto label_000DE2B5;
    label_000DDE17: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDE17u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 2u);
    label_000DDE23: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDE23u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(0u)) goto label_000DDE34;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDE34: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDE34u);
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
    label_000DDE86: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDE86u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(0u)) goto label_000DDE97;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDE97: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDE97u);
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
    label_000DDEF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDEF4u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(0u)) goto label_000DDF05;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDF05: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDF05u);
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
    label_000DDF62: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDF62u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(0u)) goto label_000DDF73;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DDF73: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDF73u);
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
    label_000DDFE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DDFE6u);
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
    label_000DE013: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE013u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DE02Au); lift_push32(cpu, r); sfera_sub_004E0AFF(cpu,r); if (cpu->eip != r) return; }
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
    label_000DE054: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE054u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)) != (uint32_t)(0u)) goto label_000DE060;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    label_000DE060: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE060u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)) == (uint32_t)(1u)) goto label_000DE06E;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE06E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE06Eu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DE091u); lift_push32(cpu, r); sfera_sub_004E0950(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x1Cu);
    if ((uint32_t)(lift_load32(cpu->eax + 0xCu)) == (uint32_t)(0u)) goto label_000DE0B1;
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 0xCu);
    goto label_000DE2B5;
    label_000DE0B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE0B1u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx, 8u);
    label_000DE0BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE0BDu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(0u)) goto label_000DE0CE;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE0CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE0CEu);
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
    label_000DE120: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE120u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(0u)) goto label_000DE131;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE131: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE131u);
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
    label_000DE18E: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE18Eu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(0u)) goto label_000DE19F;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE19F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE19Fu);
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
    label_000DE1FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE1FCu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(0u)) goto label_000DE20D;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    goto label_000DE2BA;
    label_000DE20D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE20Du);
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
    label_000DE294: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE294u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->edx, 0xCu);
    label_000DE2A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE2A0u);
    cpu->eax = 1u;
    goto label_000DE2BA;
    label_000DE2A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE2A7u);
    cpu->eax = 0xFFFFFFFDu;
    goto label_000DE2BA;
    label_000DE2AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE2AEu);
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE2BA;
    label_000DE2B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE2B5u);
    goto label_000DDC63;
    label_000DE2BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE2BAu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DE540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE540u);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DE560u); lift_push32(cpu, r); sfera_sub_004DE565(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x20u;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DE565(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE565u);
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
    label_000DE591: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE591u);
    cpu->eax = 0xFFFFFFFAu;
    goto label_000DE84D;
    label_000DE59B: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE59Bu);
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) != (uint32_t)(0u)) goto label_000DE5AB;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE84D;
    label_000DE5AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE5ABu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x18u, 0u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x20u)) != (uint32_t)(0u)) goto label_000DE5D2;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x20u, LIFT_CALLBACK(sfera_sub_004E21BE));
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ecx + 0x28u, 0u);
    label_000DE5D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE5D2u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x24u)) != (uint32_t)(0u)) goto label_000DE5E5;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 0x24u, LIFT_CALLBACK(sfera_sub_004E21E7));
    label_000DE5E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE5E5u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xCu)) != (uint32_t)(0xFFFFFFFFu)) goto label_000DE5F2;
    lift_store32(cpu->ebp + 0xCu, 6u);
    label_000DE5F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE5F2u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) >= (int32_t)(uint32_t)(0u)) goto label_000DE607;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    lift_store32(cpu->ebp + 0x14u, cpu->ecx);
    label_000DE607: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE607u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x18u)) < (int32_t)(uint32_t)(1u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x18u)) > (int32_t)(uint32_t)(9u)) goto label_000DE63D;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x10u)) != (uint32_t)(8u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (int32_t)(uint32_t)(8u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x14u)) > (int32_t)(uint32_t)(0xFu)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xCu)) < (int32_t)(uint32_t)(0u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xCu)) > (int32_t)(uint32_t)(9u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x1Cu)) < (int32_t)(uint32_t)(0u)) goto label_000DE63D;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x1Cu)) <= (int32_t)(uint32_t)(2u)) goto label_000DE647;
    label_000DE63D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE63Du);
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DE84D;
    label_000DE647: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE647u);
    lift_push32(cpu, 0x16B8u); lift_push32(cpu, 1u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x20u)), LIFT_CODE_TOKEN_RVA(0xDE65Bu), LIFT_CODE_TOKEN_RVA(0xDE658u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE65Bu);
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFF8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000DE671;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DE84D;
    label_000DE671: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE671u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE712u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE731u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE750u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE788u);
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
    label_000DE7CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE7CDu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = (uintptr_t)"insufficient memory";
    lift_store32(cpu->ecx + 0x18u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DE7E2u); lift_push32(cpu, r); sfera_sub_004DF075(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0xFFFFFFFCu;
    goto label_000DE84D;
    label_000DE7EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE7ECu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4DE84Au); lift_push32(cpu, r); sfera_sub_004DE9F1(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000DE84D: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE84Du);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DE9F1(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DE9F1u);
    cpu->eax = sfera_zlib_deflate_reset(lift_load32(cpu->esp + 4u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DEBDE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DEBDEu);
    cpu->eax = sfera_zlib_deflate(lift_load32(cpu->esp + 4u), (int32_t)lift_load32(cpu->esp + 8u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DEF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DEF60u);
    sfera_zlib_deflate_put_short_msb(lift_load32(cpu->esp + 4u), lift_load32(cpu->esp + 8u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DEFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DEFB0u);
    sfera_zlib_deflate_flush_pending(lift_load32(cpu->esp + 4u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF075(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF075u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_000DF088;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x1Cu)) != (uint32_t)(0u)) goto label_000DF092;
    label_000DF088: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF088u);
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DF182;
    label_000DF092: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF092u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0x2Au)) goto label_000DF0BD;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0x71u)) goto label_000DF0BD;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)) == (uint32_t)(0x29Au)) goto label_000DF0BD;
    cpu->eax = 0xFFFFFFFEu;
    goto label_000DF182;
    label_000DF0BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF0BDu);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF0E0u);
    cpu->esp += 8u;
    label_000DF0E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF0E3u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF106u);
    cpu->esp += 8u;
    label_000DF109: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF109u);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF12Cu);
    cpu->esp += 8u;
    label_000DF12F: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF12Fu);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF152u);
    cpu->esp += 8u;
    label_000DF155: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF155u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->edx + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(lift_load32(cpu->ecx + 0x24u)), LIFT_CODE_TOKEN_RVA(0xDF169u), LIFT_CODE_TOKEN_RVA(0xDF166u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF169u);
    cpu->esp += 8u;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 0x1Cu, 0u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xFFFFFFFCu)), r=(uint64_t)(0x71u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_000DF182: cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF182u);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF3D2(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF3D2u);
    sfera_zlib_deflate_lm_init(lift_load32(cpu->esp + 4u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF4C0u);
    cpu->eax = sfera_zlib_deflate_stored(lift_load32(cpu->esp + 4u), (int32_t)lift_load32(cpu->esp + 8u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF700u);
    sfera_zlib_deflate_fill_window(lift_load32(cpu->esp + 4u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF93B(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF93Bu);
    cpu->eax = sfera_zlib_deflate_read_buf(lift_load32(cpu->esp + 4u), lift_load32(cpu->esp + 8u), lift_load32(cpu->esp + 12u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DF9D3(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DF9D3u);
    cpu->eax = sfera_zlib_deflate_fast(lift_load32(cpu->esp + 4u), (int32_t)lift_load32(cpu->esp + 8u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004DFF2A(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4DFF2Au);
    cpu->eax = sfera_zlib_deflate_longest_match(lift_load32(cpu->esp + 4u), lift_load32(cpu->esp + 8u));
    lift_return(cpu, 0u, stop_address); return;
}
