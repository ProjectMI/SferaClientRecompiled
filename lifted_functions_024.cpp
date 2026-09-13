#include "lifted_functions.h"
#include <cmath>
#include <cstdio>
#include <functional>
namespace lifted {

__declspec(noinline) void sfera_sub_004EBF40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->eax = 0x1204u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBF4Du)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x4EBF4Du));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = 0x14u;
    cpu->ecx = cpu->ebp + 0xFFFFEE0Cu;
    *(uint32_t*)(cpu->ebp + 0xFFFFEDFCu) = (uintptr_t)"stackdump.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFEE00u) = (uintptr_t)"errorsmgr.cpp";
    *(uint32_t*)(cpu->ebp + 0xFFFFEE04u) = (uintptr_t)"crt0.c";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EBF86u)); sfera_sub_004EE2C0(cpu, LIFT_CODE_TOKEN_VA(0x4EBF86u));
    *(uint8_t*)(cpu->ebp + 0xFFFFF6CCu) = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_000EC06D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ebp + 0xFFFFEE30u;
    *(uint32_t*)(cpu->ebp + 0xFFFFEE08u) = cpu->eax;
    label_000EBFA4:
    cpu->esi = 0u;
    cpu->edi = cpu->ebx + 0xFFFFFFDCu;
    label_000EBFB0:
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->esi * 4u) + 0xFFFFEDFCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4EBFB9u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000EBFCE;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)3u) goto label_000EBFB0;
    goto label_000EBFD3;
    label_000EBFCE:
    if ((int32_t)cpu->esi < (int32_t)3u) goto label_000EC026;
    label_000EBFD3:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x44u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"(%s:%u)\t(%hs+%I64X)\n");
    cpu->ecx = cpu->ebp + 0xFFFFFF8Cu;
    lift_push32(cpu, 0x6Fu); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EBFECu));
    cpu->eax = cpu->ebp + 0xFFFFFF8Cu;
    cpu->esp += 0x20u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    cpu->esi = cpu->eax;
    label_000EC000:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EC000;
    cpu->edi = cpu->ebp + 0xFFFFF6CCu;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000EC010:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000EC010;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    label_000EC026:
    cpu->ebx += 0x70u;
    if ((--*(uint32_t*)(cpu->ebp + 0xFFFFEE08u)) != 0u) goto label_000EBFA4;
    sub_pred[0] = *(uint8_t*)(cpu->ebp + 0xFFFFF6CCu) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000EC06D;
    cpu->edx = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFF6CCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Stack:\n");
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    reinterpret_cast<SferaDiagnosticLogObjectRuntime*>(cpu->ecx)->append(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->eax = cpu->ecx; cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    reinterpret_cast<SferaDiagnosticLogObjectRuntime*>(cpu->ecx)->append(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->eax = cpu->ecx; cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    reinterpret_cast<SferaDiagnosticLogObjectRuntime*>(cpu->ecx)->flush(); cpu->esp += 4u;
    label_000EC06D:
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    reinterpret_cast<SferaDiagnosticLogObjectRuntime*>(cpu->ecx)->appendScriptContext();
    label_000EC07D:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC090(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"critLogTmp.$$$"); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0ADu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000EC1A6;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x8000u); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0C9u));
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_000EC0ED;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC0DFu));
    cpu->esp += 8u;
    goto label_000EC1A6;
    label_000EC0ED:
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4EC0F8u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000EC11F;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4EC10Au));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4EC116u));
    cpu->esp += 0xCu;
    label_000EC11F:
    cpu->eax = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC126u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x4EC126u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_000EC189;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = 0u - (uint64_t)(cpu->edi);
    label_000EC140:
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x4EC144u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000EC189;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4EC158u));
    cpu->esp += 0xCu;
    if (cpu->eax != cpu->esi) goto label_000EC189;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4EC16Eu));
    cpu->esp += 0xCu;
    if (cpu->eax != cpu->esi) goto label_000EC189;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    ++cpu->eax;
    cpu->edi += cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebp + 8u)) goto label_000EC140;
    label_000EC189:
    cpu->esi = native_function_address32(&::_close);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_close)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, (uintptr_t)"critLogTmp.$$$");
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x4EC19Du));
    cpu->esp += 0xCu;
    label_000EC1A6:
    cpu->esp = cpu->ebp + 0xFFFFFFE4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC1E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x40u;
    cpu->eax = (uintptr_t)"Criticals.log";
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC202u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000EC2CC;
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::fputs);
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000EC273;
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC224u));
    cpu->edx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC22Eu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC240u));
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC258u));
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->ecx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0x38u;
    label_000EC273:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFC8u);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(cpu->edx, cpu->esi);

    if (*(uint8_t*)(cpu->ebp + 8u) == 0u) goto label_000EC28E;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))((uintptr_t)"\n", cpu->esi);

    label_000EC28E:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4EC28Fu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4EC296u));
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4EC29Fu));
    cpu->esp += 0xCu;
    if (*(uint8_t*)(cpu->ebp + 0xCu) == 0u) goto label_000EC2CB;
    if ((int32_t)cpu->edi <= (int32_t)0x108000u) goto label_000EC2CB;
    cpu->ecx = (uintptr_t)"Criticals.log";
    lift_push32(cpu, 0x200u);
    cpu->edx = 0x800u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC2CBu)); sfera_sub_004EC090(cpu, LIFT_CODE_TOKEN_RVA(0xEC2CBu));
    label_000EC2CB:
    cpu->edi = lift_pop32(cpu);
    label_000EC2CC:
    cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EC2E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x83Cu;
    cpu->eax = g_sfera_critical_diagnostics_runtime.processing_depth;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->edi);
    g_sfera_critical_diagnostics_runtime.processing_depth = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->esi) goto label_000EC3D0;
    if (cpu->eax != 2u) goto label_000EC3C1;
    cpu->eax = (uintptr_t)"Criticals.log";
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4EC322u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000EC3BC;
    cpu->ecx = cpu->ebp + 0xFFFFF7C4u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4EC33Cu));
    cpu->edx = cpu->ebp + 0xFFFFF7C4u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4EC349u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y %H:%M:%S ");
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4EC35Bu));
    cpu->ecx = g_sfera_critical_diagnostics_runtime.serial_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d ");
    cpu->edx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x4EC373u));
    cpu->edi = native_function_address32(&::fputs);
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFBu) = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->ecx = cpu->ebp + 0xFFFFFFECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Error processing reenter. Terminating");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4EC3A5u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4EC3ACu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4EC3B3u));
    cpu->esp += 0x14u;
    label_000EC3BC:
    cpu->esi = 1u;
    label_000EC3C1:
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EC3C3u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_RVA(0xEC3CAu));
    label_000EC3D0:
    cpu->eax = g_sfera_critical_diagnostics_runtime.serial_number;
    cpu->eax += cpu->esi;
    g_sfera_critical_diagnostics_runtime.serial_number = cpu->eax;
    if (cpu->eax != 0x3E8u) goto label_000EC3ED;
    g_sfera_critical_diagnostics_runtime.serial_number = 0u;
    label_000EC3ED:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = cpu->ebp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, 0x800u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x4EC401u));
    cpu->edi = cpu->ebp + 0xFFFFF7CCu;
    cpu->esp += 0x10u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFCBu) = 0u;
    --cpu->edi;
    label_000EC415:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EC415;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    if (cpu->eax == 0u) goto label_000EC4D4;
    if ((cpu->eax -= cpu->esi) == 0u) goto label_000EC47D;
    if ((cpu->eax -= cpu->esi) != 0u) goto label_000EC4E9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC451u)); sfera_sub_004EC1E0(cpu, LIFT_CODE_TOKEN_VA(0x4EC451u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    reinterpret_cast<SferaDiagnosticLogObjectRuntime*>(cpu->ecx)->writeLine(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC46Du)); sfera_sub_004EBF40(cpu, LIFT_CODE_TOKEN_VA(0x4EC46Du));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    cpu->eax = sfera_client_critical_error(reinterpret_cast<const char*>(static_cast<uintptr_t>(cpu->ecx)), cpu->edx);
    goto label_000EC4B9;
    label_000EC47D:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    reinterpret_cast<SferaDiagnosticLogObjectRuntime*>(cpu->ecx)->writeLine(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EC499u)); sfera_sub_004EBF40(cpu, LIFT_CODE_TOKEN_VA(0x4EC499u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = cpu->ebp + 0xFFFFF7CCu;
    cpu->eax = sfera_client_critical_error(reinterpret_cast<const char*>(static_cast<uintptr_t>(cpu->ecx)), cpu->edx);
    if ((cpu->eax & 0xFFu) != 0u) goto label_000EC4E9;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = (uintptr_t)"terminating cause of LERROR";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEC4B9u)); sfera_sub_004EC1E0(cpu, LIFT_CODE_TOKEN_RVA(0xEC4B9u));
    label_000EC4B9:
    WorldMemory::validateBeforeTermination();
    SferaDiagnosticLogObjectRuntime::drainAll();
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EC4C5u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_VA(0x4EC4CCu));
    goto label_000EC4E9;
    label_000EC4D4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx = cpu->ebp + 0xFFFFF7CCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_log_warnings_object;
    reinterpret_cast<SferaDiagnosticLogObjectRuntime*>(cpu->ecx)->writeLine(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    label_000EC4E9:
    g_sfera_critical_diagnostics_runtime.processing_depth = (uint64_t)(g_sfera_critical_diagnostics_runtime.processing_depth) - (uint64_t)(cpu->esi) - (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004ED5E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x14u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"operator[]: out of range. Size=%d, Index=%d"); lift_push32(cpu, 1u); lift_push32(cpu, 0x13u); lift_push32(cpu, (uintptr_t)"Containers\\Containers.cpp");
    cpu->ecx = cpu->ebp + 0xFFFFFFF4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED60Au)); sfera_sub_004013B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED60Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED610u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x4ED610u));
    cpu->esp += 0x10u;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x534u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAECu) = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF0u) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE027u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, 0xA4u);
    cpu->eax = cpu->ebp + 0xFFFFFB00u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF4u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE043u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xC4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB8u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u);
    cpu->eax = 3u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFB24u) = cpu->edx;
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFB08u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFB2Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFB20u) = cpu->eax;
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFB00u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xB4u);
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFB18u) = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp + 0xFFFFFB00u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u) = 0u;
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE0A9u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE0B6u));
    if (cpu->eax == 0u) goto label_000EE2A4;
    cpu->esi += 0x68u;
    label_000EE0D0:
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFB18u) == cpu->eax) goto label_000EE2A4;
    *(uint32_t*)(cpu->esi + 0xFFFFFFB8u) = cpu->eax;
    cpu->edx = 0x6E6B6E55u;
    cpu->ebx = cpu->esi + 0xFFFFFF98u;
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"Unknown") + 4u);
    cpu->edx = cpu->ebp + 0xFFFFFAD0u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0xFFFFFFBCu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->ebp + 0xFFFFFAFFu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAD4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAD8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFADCu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAE0u) = cpu->eax;
    cpu->eax = cpu->ebp + 0xFFFFFACCu;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAD0u) = 0x14u;
    lift_native_call(cpu, native_function_address32(&::SymGetLineFromAddr), LIFT_CODE_TOKEN_VA(0x4EE13Bu));
    if (cpu->eax == 0u) goto label_000EE1AD;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFADCu);
    cpu->eax = cpu->edx;
    *(uint8_t*)(cpu->ebp + 0xFFFFFAFFu) = 1u;
    cpu->edi = cpu->eax + 1u;
    label_000EE157:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EE157;
    cpu->eax -= cpu->edi;
    cpu->edi = cpu->eax;
    cpu->eax = cpu->edi + 0xFFFFFFFFu;
    if ((int32_t)cpu->eax < 0) goto label_000EE179;
    label_000EE170:
    if (*(uint8_t*)(cpu->eax + cpu->edx) == 0x5Cu) goto label_000EE179;
    if ((int32_t)(--cpu->eax) >= 0) goto label_000EE170;
    label_000EE179:
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    if ((int32_t)cpu->edi < (int32_t)0x1Fu) goto label_000EE18C;
    cpu->edi = 0x1Fu;
    goto label_000EE190;
    label_000EE18C:
    if ((int32_t)cpu->edi <= 0) goto label_000EE1AD;
    label_000EE190:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFAD8u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->eax + cpu->edx + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0xFFFFFFB8u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE1A0u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->ebx + cpu->edi) = 0u;
    label_000EE1AD:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFAF4u);
    cpu->ecx = cpu->ebp + 0xFFFFFBA4u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = 0u;
    cpu->edx = cpu->ebp + 0xFFFFFAE4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFAE4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAE8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFB00u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFBA4u) = 0x458u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFBF4u) = 0x400u;
    lift_native_call(cpu, native_function_address32(&::SymFromAddr), LIFT_CODE_TOKEN_VA(0x4EE1ECu));
    if (cpu->eax == 0u) goto label_000EE243;
    cpu->eax = cpu->ebp + 0xFFFFFBF8u;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_000EE200:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000EE200;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi < (int32_t)0x3Fu) goto label_000EE217;
    cpu->edi = 0x3Fu;
    goto label_000EE21B;
    label_000EE217:
    if ((int32_t)cpu->edi <= 0) goto label_000EE24C;
    label_000EE21B:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFAE4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp + 0xFFFFFBF8u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esi + 0xFFFFFFBCu;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4EE233u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->ebx + cpu->edi + 0x24u) = 0u;
    goto label_000EE24C;
    label_000EE243:
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFAFFu) == 0u) goto label_000EE26A;
    label_000EE24C:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u);
    ++cpu->eax;
    cpu->esi += 0x70u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0xFFFFFAECu)) goto label_000EE2AA;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFAF4u);
    label_000EE26A:
    cpu->edx = native_function_address32(&::SymGetModuleBase);
    cpu->eax = native_function_address32(&::SymFunctionTableAccess);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFAF0u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFB00u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x4EE289u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x14Cu);
    lift_native_call(cpu, native_function_address32(&::StackWalk), LIFT_CODE_TOKEN_VA(0x4EE296u));
    if (cpu->eax != 0u) goto label_000EE0D0;
    label_000EE2A4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFAF8u);
    label_000EE2AA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE2C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x2ECu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFD14u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFD18u) = cpu->ecx;
    lift_push32(cpu, 4u);
    lift_native_call(cpu, native_function_address32(&::SymSetOptions), LIFT_CODE_TOKEN_VA(0x4EE2E3u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4EE2EDu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4EE2F4u));
    if (*(uint32_t*)(cpu->ebp + 8u) == 0u) goto label_000EE315;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = cpu->ebp + 0xFFFFFD28u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),716u); cpu->esi += 716u; cpu->edi += 716u; cpu->ecx = 0u;
    goto label_000EE366;
    label_000EE315:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEE31Au));
    sfera_sub_004EE31A(cpu, stop_address); return;
    label_000EE366:
    cpu->edx = cpu->ebp + 0xFFFFFD28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFD14u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFD18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu)); sfera_sub_004EE000(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE31A(LiftCpu* cpu, uint32_t stop_address) {
    *(uint32_t*)(cpu->ebp + 0xFFFFFD24u) = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFD20u) = cpu->ebp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFD1Cu) = cpu->esp;
    lift_push32(cpu, 0x2CCu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFD28u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4EE33Au));
    cpu->esp += 0xCu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFD24u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFDE0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFD20u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFDDCu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFD1Cu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFDECu) = cpu->ecx;
    cpu->edx = cpu->ebp + 0xFFFFFD28u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFD14u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFD18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu)); sfera_sub_004EE000(cpu, LIFT_CODE_TOKEN_VA(0x4EE37Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
[[noreturn]] __declspec(noinline) void sfera_sub_004EE92A(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->eip = 0x4EE92Au; throw std::runtime_error("client C++ exception path reached"); }
__declspec(noinline) void sfera_sub_004EE940(LiftCpu* cpu, uint32_t stop_address, double value) {
    if (((uint32_t)(g_sfera_crt_startup_runtime.processor_feature_10) == 0u)) {
        sfera_sub_004EE976(cpu, stop_address, value);
        return;
    }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    cpu->esp &= 0xFFFFFFF8u;
    *(double*)(cpu->esp) = value;
    cpu->eax = (uint32_t)(int32_t)trunc(*(double*)(cpu->esp));
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
     cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EE976(LiftCpu* cpu, uint32_t stop_address, double value) { double value_0, value_1;
 bool sub_pred[1]; double x87_p0;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x20u;
    cpu->esp &= 0xFFFFFFF0u;
    x87_p0 = value;
    *(float*)(cpu->esp + 0x18u) = x87_p0;
    *(uint64_t*)(cpu->esp + 0x10u) = static_cast<int64_t>(std::nearbyint(x87_p0));
    x87_p0 = (double)(((int64_t)(*(uint64_t*)(cpu->esp + 0x10u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
     value_0 = x87_p0; if (cpu->eax == 0u) goto label_000EE9D5;
label_000EE999:
    value_1 = value - value_0; 
     if ((int32_t)cpu->edx >= 0) goto label_000EE9BD;
    *(float*)(cpu->esp) = value_1; 
    cpu->ecx = *(uint32_t*)(cpu->esp);
    cpu->ecx ^= 0x80000000u;
    cpu->ecx += 0x7FFFFFFFu;
    cpu->eax += (cpu->ecx < 0x7FFFFFFFu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += ((cpu->ecx < 0x7FFFFFFFu) && cpu->eax == 0u);
     goto label_000EE9E9;
label_000EE9BD:
    *(float*)(cpu->esp) = value_1; 
    cpu->ecx = *(uint32_t*)(cpu->esp);
    cpu->ecx += 0x7FFFFFFFu;
    sub_pred[0] = cpu->eax < 0u || ((cpu->ecx < 0x7FFFFFFFu) && cpu->eax == 0u); cpu->eax -= (cpu->ecx < 0x7FFFFFFFu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx -= (sub_pred[0]);
     goto label_000EE9E9;
label_000EE9D5:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (((cpu->edx) & (0x7FFFFFFFu)) != 0u) goto label_000EE999;
    *(float*)(cpu->esp + 0x18u) = value_0; 
    *(float*)(cpu->esp + 0x18u) = value; 
label_000EE9E9:
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004EEA10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 8u;
    cpu->ecx -= cpu->eax;
    cpu->ecx &= 0xFu;
    cpu->eax += cpu->ecx;
    cpu->ecx = (cpu->eax < cpu->ecx) ? 0xFFFFFFFFu : 0u;
    cpu->eax |= cpu->ecx;
    cpu->ecx = lift_pop32(cpu);
    sfera_sub_004EEAF0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004EEA40(LiftCpu* cpu, uint32_t stop_address) {
    const uint64_t left_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 8u) << 32u) | *(uint32_t*)(cpu->esp + 4u);
    const uint64_t right_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 0x10u) << 32u) | *(uint32_t*)(cpu->esp + 0xCu);
    const bool left_negative = (left_bits & 0x8000000000000000ull) != 0u, right_negative = (right_bits & 0x8000000000000000ull) != 0u;
    const uint64_t left = left_negative ? 0u - left_bits : left_bits, right = right_negative ? 0u - right_bits : right_bits;
    const bool negative = left_negative != right_negative;
    uint64_t quotient = left / right;
    if (negative) quotient = 0u - quotient;
    cpu->eax = (uint32_t)quotient; cpu->edx = (uint32_t)(quotient >> 32u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EEAF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 4u;
    sub_pred[0] = cpu->ecx < cpu->eax; cpu->ecx -= cpu->eax;
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 0u;
    cpu->eax = ~((uint64_t)(cpu->eax));
    cpu->ecx &= cpu->eax;
    cpu->eax = cpu->esp;
    cpu->eax &= 0xFFFFF000u;
    label_000EEB04:
    if (cpu->ecx < cpu->eax) goto label_000EEB12;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_pop32(cpu);
    {
        uint64_t left = cpu->esp;
        uint64_t right = cpu->eax;
        cpu->esp = right;
        cpu->eax = left;
    }
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EEB12:
    cpu->eax -= 0x1000u;
    (void)(*(uint32_t*)(cpu->eax));
    goto label_000EEB04;
}
__declspec(noinline) void sfera_sub_004EEC60(LiftCpu* cpu, uint32_t stop_address) {
    const uint64_t left_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 8u) << 32u) | *(uint32_t*)(cpu->esp + 4u);
    const uint64_t right_bits = ((uint64_t)*(uint32_t*)(cpu->esp + 0x10u) << 32u) | *(uint32_t*)(cpu->esp + 0xCu);
    const bool negative = (left_bits & 0x8000000000000000ull) != 0u, right_negative = (right_bits & 0x8000000000000000ull) != 0u;
    const uint64_t left = negative ? 0u - left_bits : left_bits, right = right_negative ? 0u - right_bits : right_bits;
    uint64_t remainder = left % right;
    if (negative) remainder = 0u - remainder;
    cpu->eax = (uint32_t)remainder; cpu->edx = (uint32_t)(remainder >> 32u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EED20(LiftCpu* cpu, uint32_t stop_address) {
    const uint64_t left = ((uint64_t)*(uint32_t*)(cpu->esp + 8u) << 32u) | *(uint32_t*)(cpu->esp + 4u);
    const uint64_t right = ((uint64_t)*(uint32_t*)(cpu->esp + 0x10u) << 32u) | *(uint32_t*)(cpu->esp + 0xCu);
    const uint64_t product = left * right;
    cpu->eax = (uint32_t)product; cpu->edx = (uint32_t)(product >> 32u);
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004EEE61(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.mainargs_result = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF088(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.managed_app = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF10Eu)); sfera_sub_004EF33C(cpu, LIFT_CODE_TOKEN_VA(0x4EF10Eu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF113u)); sfera_sub_004EF510(cpu, LIFT_CODE_TOKEN_VA(0x4EF113u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF12Du)); sfera_sub_004EF4E8(cpu, LIFT_CODE_TOKEN_VA(0x4EF12Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF142(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000EF142;
    label_000EEEAF:
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEEBBu)); sfera_sub_004EF270(cpu, LIFT_CODE_TOKEN_VA(0x4EEEBBu));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ebx;
    cpu->eax = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetStartupInfoW), LIFT_CODE_TOKEN_VA(0x4EEEC4u));
    if (g_sfera_crt_startup_runtime.heap_compatibility_flag != cpu->ebx) goto label_000EEEDD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::HeapSetInformation), LIFT_CODE_TOKEN_RVA(0xEEED7u));
    label_000EEEDD:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    cpu->esi = static_cast<uint32_t>(::GetCurrentThreadId());
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->ebx;
    cpu->edi = (uintptr_t)&g_sfera_crt_startup_runtime.startup_lock;
    label_000EEEF1:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedCompareExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->esi), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 12u;
    if (cpu->eax == cpu->ebx) goto label_000EEF17;
    if (cpu->eax != cpu->esi) goto label_000EEF0A;
    cpu->esi = 0u;
    ++cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) = cpu->esi;
    goto label_000EEF1A;
    label_000EEF0A:
    lift_push32(cpu, 0x3E8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x4EEF0Fu));
    goto label_000EEEF1;
    label_000EEF17:
    cpu->esi = 0u;
    ++cpu->esi;
    label_000EEF1A:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if (cpu->eax != cpu->esi) goto label_000EEF2D;
    lift_push32(cpu, 0x1Fu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF2Au)); sfera_sub_004EF336(cpu, LIFT_CODE_TOKEN_VA(0x4EEF2Au));
    cpu->ecx = lift_pop32(cpu);
    goto label_000EEF68;
    label_000EEF2D:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if (cpu->eax != 0u) goto label_000EEF62;
    g_sfera_crt_startup_runtime.startup_state = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF088(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
    if (cpu->eax == 0u) {
        lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF2C9(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
        if (cpu->eax == 0u) {
            lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu)); sfera_sub_004EF328(cpu, LIFT_CODE_TOKEN_VA(0x4EEF4Bu));
        }
    }
    if (cpu->eax == 0u) goto label_000EEF68;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    cpu->eax = 0xFFu;
    goto label_000EF082;
    label_000EEF62:
    g_sfera_crt_startup_runtime.has_cctor = cpu->esi;
    label_000EEF68:
    cpu->eax = g_sfera_crt_startup_runtime.startup_state;
    if (cpu->eax != cpu->esi) goto label_000EEF8C;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004EEE61(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004FA041(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F4E60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    g_sfera_effect_manager.clearListeners(); cpu->eax = 0u; cpu->eip = LIFT_CODE_TOKEN_VA(0x4EEF80u);
    g_sfera_effect_manager.render_slots.initialize(10000u, "..\\ShareClientSeverCode\\EffectManager.cpp", 125u); cpu->eax = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F50E0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F51D0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5570(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5580(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5590(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    g_sfera_recovered_static_runtime.legacy_light_arrays[2].initialize(126u, "..\\ShareClientSeverCode\\light.cpp", 934u); cpu->eax = 0u;
    g_sfera_recovered_static_runtime.legacy_light_arrays[1].initialize(126u, "..\\ShareClientSeverCode\\light.cpp", 935u); cpu->eax = 0u;
    g_sfera_recovered_static_runtime.legacy_light_arrays[0].initialize(126u, "..\\ShareClientSeverCode\\light.cpp", 936u); cpu->eax = 0u;

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5890(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5920(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F59B0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5A40(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5AD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5B60(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5BF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    g_sfera_camera = SphereRender::GameCamera{};
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5C90(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5D20(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F5DD0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    g_sfera_landscape_runtime.file_records.initialize(300u, "..\\ShareClientSeverCode\\main.cpp", 369u); cpu->eax = 0u;
    g_sfera_interface_runtime.window_handle_table.initialize(7000u, "..\\ShareClientSeverCode\\main.cpp", 403u); cpu->eax = 0u;
    g_sfera_world_objects.object_handles.initialize(500000u, "..\\ShareClientSeverCode\\main.cpp", 418u); cpu->eax = 0u;
    g_sfera_world_objects.extended_object_handles.initialize(30000u, "..\\ShareClientSeverCode\\main.cpp", 421u); cpu->eax = 0u;
    g_sfera_interface_runtime.windows.initialize(100u, "..\\ShareClientSeverCode\\main.cpp", 425u); cpu->eax = 0u;
    g_sfera_character_index_map.initialize(20000u, "..\\ShareClientSeverCode\\main.cpp", 447u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.object_visibility_indices.initialize(20000u, "..\\ShareClientSeverCode\\main.cpp", 448u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.object_sort_keys.initialize(20000u, "..\\ShareClientSeverCode\\main.cpp", 451u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.object_sort_indices.initialize(20000u, "..\\ShareClientSeverCode\\main.cpp", 452u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.object_draw_indices.initialize(20000u, "..\\ShareClientSeverCode\\main.cpp", 453u); cpu->eax = 0u;
    g_sfera_collision_runtime.candidate_handles.initialize(20000u, "..\\ShareClientSeverCode\\main.cpp", 454u); cpu->eax = 0u;

    g_sfera_scene_array_runtime.scene_points.initialize(900u, "..\\ShareClientSeverCode\\main.cpp", 828u); cpu->eax = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6470(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6510(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6580(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6650(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6720(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F67F0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F68C0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6B10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6B80(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6C10(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    g_sfera_light_runtime.handles.initialize(1000u, "..\\ShareClientSeverCode\\main.cpp", 4734u); cpu->eax = 0u;
    g_sfera_light_runtime.visible_handles.initialize(500u, "..\\ShareClientSeverCode\\main.cpp", 4736u); cpu->eax = 0u;
    g_sfera_light_runtime.active_handles.initialize(31u, "..\\ShareClientSeverCode\\main.cpp", 4738u); cpu->eax = 0u;

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F6FA0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7010(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7080(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    g_sfera_scene_array_runtime.model_matrices.initialize(256u, "..\\ShareClientSeverCode\\main.cpp", 9451u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.character_matrices.initialize(5u, "..\\ShareClientSeverCode\\main.cpp", 9457u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.object_positions.initialize(10000u, "..\\ShareClientSeverCode\\main.cpp", 9529u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.clip_vectors.initialize(200u, "..\\ShareClientSeverCode\\main.cpp", 10865u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.clip_indices.initialize(200u, "..\\ShareClientSeverCode\\main.cpp", 10871u); cpu->eax = 0u;
    g_sfera_scene_array_runtime.clip_points.initialize(40u, "..\\ShareClientSeverCode\\main.cpp", 10884u); cpu->eax = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7390(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    g_sfera_collision_runtime.near_result_handles.initialize(20u, "..\\ShareClientSeverCode\\main.cpp", 10886u); cpu->eax = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7470(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    cpu->eax = static_cast<std::uint32_t>(0u);

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7DF0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F7EE0(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9730(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9740(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u)); sfera_sub_004F9C00(cpu, LIFT_CODE_TOKEN_VA(0x4EEF80u));

    g_sfera_log_memory_object.initialize("LogMemory.log", "$d $t ", SferaDiagnosticLogObjectRuntime::ImmediateFlush | SferaDiagnosticLogObjectRuntime::SuppressRepeats, 1000000u, false, 512u); cpu->eax = 0u;
    g_sfera_log_warnings_object.initialize("Warnings.log", "$d $t $u", 0u, 1000000u, true, 2112u); cpu->eax = 0u;
    g_sfera_log_errors_object.initialize("Errors.log", "$d $t $u", SferaDiagnosticLogObjectRuntime::SessionMarkers | SferaDiagnosticLogObjectRuntime::ImmediateFlush | SferaDiagnosticLogObjectRuntime::SuppressRepeats, 1000000u, true, 2112u); cpu->eax = 0u;
    g_sfera_crt_startup_runtime.startup_state = 2u;
    label_000EEF8C:
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFDCu) != cpu->ebx) goto label_000EEF99;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<uint32_t>(::InterlockedExchange(reinterpret_cast<volatile LONG*>(static_cast<uintptr_t>(cpu->edi)), static_cast<LONG>(cpu->ebx)));
    cpu->esp += 8u;
    label_000EEF99:
    cpu->esi = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::GetCommandLineA()));
    label_000EEFC1:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->esi;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) > 0x20u) goto label_000EF013;
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000EEFD3;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) != cpu->ebx) goto label_000EF013;
    label_000EEFD3:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_000EEFE3;
    if ((cpu->eax & 0xFFu) > 0x20u) goto label_000EEFE3;
    ++cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->esi;
    goto label_000EEFD3;
    label_000EEFE3:
    if (((*(uint8_t*)(cpu->ebp + 0xFFFFFFC0u)) & (1u)) == 0u) goto label_000EEFEF;
    cpu->eax = *(uint16_t*)(cpu->ebp + 0xFFFFFFC4u);
    goto label_000EEFF2;
    label_000EEFEF:
    lift_push32(cpu, 0xAu);
    cpu->eax = lift_pop32(cpu);
    label_000EEFF2:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uint32_t)(uintptr_t)::GetModuleHandleW(nullptr));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EEFFFu)); sfera_sub_0047D770(cpu, LIFT_CODE_TOKEN_VA(0x4EEFFFu));
    g_sfera_crt_startup_runtime.main_return_code = cpu->eax;
    if (g_sfera_crt_startup_runtime.managed_app != cpu->ebx) goto label_000EF068;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0xEF00Du));
    label_000EF013:
    if ((cpu->eax & 0xFFu) != 0x22u) goto label_000EF022;
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) == cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ecx;
    label_000EF022:
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_ismbblead), LIFT_CODE_TOKEN_VA(0x4EF026u));
    cpu->ecx = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_000EF035;
    ++cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u) = cpu->esi;
    label_000EF035:
    ++cpu->esi;
    goto label_000EEFC1;
    label_000EF068:
    if (g_sfera_crt_startup_runtime.has_cctor != cpu->ebx) goto label_000EF076;
    lift_native_call(cpu, native_function_address32(&::_cexit), LIFT_CODE_TOKEN_RVA(0xEF070u));
    label_000EF076:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    cpu->eax = g_sfera_crt_startup_runtime.main_return_code;
    label_000EF082:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4EF087u)); sfera_sub_004EF2B5(cpu, LIFT_CODE_TOKEN_VA(0x4EF087u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000EF142:
    goto label_000EEEAF;
}
__declspec(noinline) void sfera_sub_004EF270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    cpu->ebp = cpu->esp + 0x10u;
    cpu->esp -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esp;
    lift_push32(cpu, *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFEu;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->eax = cpu->ebp + 0xFFFFFFF0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF2B5(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF2C9(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xAu);
    lift_native_call(cpu, native_function_address32(&::IsProcessorFeaturePresent), LIFT_CODE_TOKEN_VA(0x4EF2CBu));
    g_sfera_crt_startup_runtime.processor_feature_10 = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF328(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::SetUnhandledExceptionFilter(&sfera_cpp_exception_filter)));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
[[noreturn]] __declspec(noinline) void sfera_sub_004EF336(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF336u); throw std::runtime_error("CRT startup failure");
}
__declspec(noinline) void sfera_sub_004EF33C(LiftCpu* cpu, uint32_t stop_address) {  (void)stop_address; cpu->esp += 4u; cpu->eip = stop_address; return; }
__declspec(noinline) void sfera_sub_004EF4E8(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x30000u); lift_push32(cpu, 0x10000u);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_controlfp_s), LIFT_CODE_TOKEN_VA(0x4EF4F8u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_000EF50E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xEF50Eu)); sfera_sub_004EF5BA(cpu, LIFT_CODE_TOKEN_RVA(0xEF50Eu));
    label_000EF50E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004EF510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
[[noreturn]] __declspec(noinline) void sfera_sub_004EF5BA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4EF5BAu); std::terminate();
}
} // namespace lifted
