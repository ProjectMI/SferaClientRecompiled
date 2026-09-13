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

} // namespace lifted
