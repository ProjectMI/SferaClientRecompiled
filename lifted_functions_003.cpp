#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_00422000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x418u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebp + 0x4000u) != cpu->esi) goto label_00022253;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x4014u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42202Eu));
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42203Eu));
    *(uint32_t*)(cpu->ebp + 0x4008u) = 0xFFFFFFFFu;
    cpu->eax = 0x5C63626Du;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->esp += 0x18u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    cpu->ebx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    label_00022075:
    if (*(uint8_t*)(cpu->ebx) == 0u) goto label_00022105;
    cpu->eax = 0u;
    label_00022080:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x24u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022080;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->ebx;
    label_00022091:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022091;
    cpu->edi = cpu->esp + 0x24u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_000220A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000220A0;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x24u;
    --cpu->eax;
    label_000220C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000220C0;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(reinterpret_cast<const char*>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((int32_t)cpu->esi <= 0) goto label_00022105;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_00022105:
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->ebx += 0x8D8u;
    if ((int32_t)cpu->ebx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022075;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_00022251;
    lift_push32(cpu, 0x6Fu);
    cpu->ecx = cpu->eax * 8u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x70u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    *(uint32_t*)(cpu->ebp + 0x4000u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    cpu->edx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    *(uint32_t*)(cpu->ebp + 0x4004u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    label_00022166:
    if (*(uint8_t*)(cpu->edx) == 0u) goto label_0002223B;
    cpu->eax = 0u;
    label_00022171:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x24u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022171;
    cpu->eax = cpu->edx;
    label_00022180:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022180;
    cpu->edi = cpu->esp + 0x24u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00022190:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00022190;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x24u;
    --cpu->eax;
    label_000221B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000221B0;
    cpu->ecx = 0x6264612Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(reinterpret_cast<const char*>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((cpu->esi==0u) || (((cpu->esi)&0x80000000u)!=0u)) goto label_00022237;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esi;
    cpu->eax >>= 3u;
    *(uint32_t*)(cpu->ebx + cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx >>= 2u;
    *(uint32_t*)(cpu->ebx + cpu->eax + 4u) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(reinterpret_cast<const char*>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ebx + cpu->ecx + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4004u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->ebx += 8u;
    label_00022237:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0002223B:
    cpu->edx += 0x8D8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022166;
    label_00022251:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00022253:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (*(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) == cpu->eax) goto label_000223D2;
    if (*(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag)) == 3u) goto label_000223D2;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int16_t)((uint16_t)(cpu->eax)) >= (int16_t)(*(uint16_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)))) goto label_000223D2;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids);
    cpu->edx = cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    (void)cpu;
    label_000222C0:
    cpu->eax = *(uint16_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->eax * 4u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00022380;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x4000u);
    cpu->edi = *(uint32_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi += *(uint32_t*)(cpu->ebp);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if ((int32_t)cpu->edx <= 0) goto label_00022380;
    cpu->ebp = cpu->eax * 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    label_00022300:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4004u);
    cpu->esi = *(uint32_t*)(cpu->eax + cpu->ebp);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    cpu->ebp += 8u;
    if (*(uint32_t*)(cpu->esi + cpu->edi) == 0xDEEDDEEDu) goto label_00022344;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + cpu->edi) = 0xDEEDDEEDu;
    cpu->eax = *(uint16_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    reinterpret_cast<SferaWarningLogRuntime*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))->appendFormatted(true, reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)), reinterpret_cast<char*>(cpu->esp + 8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022344:
    if (*(uint8_t*)(cpu->ebx + cpu->edi) == 0xDEu) goto label_00022372;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->ebx + cpu->edi) = 0xDEu;
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    reinterpret_cast<SferaWarningLogRuntime*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))->appendFormatted(true, reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)), reinterpret_cast<char*>(cpu->esp + 8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x14u;
    label_00022372:
    --*(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != 0u) goto label_00022300;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00022380:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = (int16_t)(*(uint16_t*)(cpu->ebx + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->ecx += 2u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000222C0;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x18u) == 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (sub_pred[0]) goto label_000223D2;
    if (*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error == 0u) goto label_000223D2;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime;
    reinterpret_cast<SferaWarningLogRuntime*>(cpu->ecx)->flush();
    cpu->ecx = (uintptr_t)"Memory Error! See at Warnings.log";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4223CAu)); sfera_sub_0044C0A0(cpu, LIFT_CODE_TOKEN_VA(0x4223CAu));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x223CCu));
    label_000223D2:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004223E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x4008u);
    if (cpu->esi == 0xFFFFFFFFu) goto label_000225DB;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->eax * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->edi + (cpu->ecx * 4u));
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_00022431;
    cpu->edx = 0xF5u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x22431u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x22431u));
    label_00022431:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4000u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4010u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = cpu->eax + (cpu->edx * 2u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->edx * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset));
    cpu->ebx += *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    label_00022460:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x4004u);
    cpu->ebp = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 4u);
    cpu->ecx += 2u;
    sub_pred[0] = *(uint32_t*)(cpu->ebx + cpu->ebp) == 0xDEEDDEEDu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (sub_pred[0]) goto label_000224BB;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + cpu->ebp) = 0xDEEDDEEDu;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->eax * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Start of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime);
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    reinterpret_cast<SferaWarningLogRuntime*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))->appendFormatted(true, reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)), reinterpret_cast<char*>(cpu->esp + 8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224BB:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) == 0xDEu) goto label_000224F4;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->eax + cpu->ebx) = 0xDEu;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0x2D4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"End of script array corrupted. ModuleTag=%d, ArrayOffsBeg=%d, ArrayOffsEnd=%d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime);
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    reinterpret_cast<SferaWarningLogRuntime*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))->appendFormatted(true, reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)), reinterpret_cast<char*>(cpu->esp + 8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0x14u;
    label_000224F4:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    ++*(uint32_t*)(cpu->edi + 0x4010u);
    if (*(uint32_t*)(cpu->edi + 0x4010u) != cpu->edx) goto label_000225A3;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->edi + 0x4010u) = cpu->edx;
    label_00022520:
    ++cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x400Cu) = cpu->ecx;
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    if (cpu->ecx != cpu->eax) goto label_0002256A;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x4008u);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->edi + 0x400Cu) = cpu->edx;
    label_00022540:
    sub_pred[1] = cpu->eax == (uint32_t)(g_sfera_mbc_runtime->process_chain_last);
    cpu->eax = g_sfera_mbc_runtime->process_chain_first;
    if (sub_pred[1]) goto label_00022550;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    label_00022550:
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    *(uint32_t*)(cpu->edi + 0x4008u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag)) == 3u) goto label_00022540;
    label_0002256A:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u) + 0x2D4u);
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->eax * 4u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00022520;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->eax = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x400Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 0x324u);
    cpu->ebx += *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ecx = cpu->eax;
    label_000225A3:
    if ((--*(uint32_t*)(cpu->esp + 0x24u)) != 0u) goto label_00022460;
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x14u) == 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (sub_pred[2]) goto label_000225DB;
    if (*(uint32_t*)(void*)&g_sfera_recovered_static_runtime.memory_warning_as_error == 0u) goto label_000225DB;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime;
    reinterpret_cast<SferaWarningLogRuntime*>(cpu->ecx)->flush();
    cpu->ecx = (uintptr_t)"Memory Error! See at Warnings.log";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4225D3u)); sfera_sub_0044C0A0(cpu, LIFT_CODE_TOKEN_VA(0x4225D3u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x225D5u));
    label_000225DB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004225F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) == 0xFFFFFFFFu) goto label_00022611;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_00022611:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422620(LiftCpu* cpu, uint32_t stop_address) {
    *(uint32_t*)(cpu->ecx + 0x4008u) = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax != *(uint32_t*)(cpu->ecx + 0x4008u)) goto label_0002265D;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) == 0xFFFFFFFFu) goto label_0002265D;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_0002265D:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00422660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x4008u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000226AF;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += *(uint32_t*)(cpu->ecx + 0x400Cu);
    cpu->eax = *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if (cpu->edx != cpu->eax) goto label_000226AF;
    cpu->edx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) == 0xFFFFFFFFu) goto label_000226AF;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x4010u) = cpu->eax;
    label_000226AF:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004226C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x414u;
    cpu->eax = 0x5C63626Du;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ebx = 0u;
    cpu->edx = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ecx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    label_00022700:
    if (*(uint8_t*)(cpu->edx) == 0u) goto label_000228CC;
    if (*(uint32_t*)(cpu->ebp + (cpu->ebx * 4u)) == 0xFFFFFFFFu) goto label_000228CC;
    cpu->eax = 0u;
    label_00022716:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0x18u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x20u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022716;
    cpu->eax = cpu->edx;
    label_00022725:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022725;
    cpu->edi = cpu->esp + 0x20u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00022733:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00022733;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x20u;
    --cpu->eax;
    label_00022750:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00022750;
    cpu->edx = 0x6264612Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    g_sfera_files.setErrorReporting(false);
    cpu->ecx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(reinterpret_cast<const char*>(cpu->ecx)));
    cpu->esi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if ((cpu->esi!=0u) && (((cpu->esi)&0x80000000u)==0u)) goto label_0002278F;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42278Au)); sfera_sub_00422660(cpu, LIFT_CODE_TOKEN_VA(0x42278Au));
    goto label_000228CC;
    label_0002278F:
    cpu->edx = *(uint32_t*)(cpu->ebp + (cpu->ebx * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->ecx = cpu->esi;
    cpu->ecx >>= 3u;
    if (cpu->ecx == *(uint32_t*)(cpu->eax + (cpu->edx * 8u))) goto label_000227B0;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4227ABu)); sfera_sub_00422660(cpu, LIFT_CODE_TOKEN_VA(0x4227ABu));
    goto label_000228CC;
    label_000227B0:
    lift_push32(cpu, 0x19Au);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x20u;
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(reinterpret_cast<const char*>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), reinterpret_cast<void*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->edx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4000u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4004u);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    cpu->edx = cpu->ebx;
    if (cpu->esi < 4u) goto label_00022817;
    label_00022803:
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_0002281F;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if (cpu->esi >= 4u) goto label_00022803;
    label_00022817:
    if (cpu->esi == 0u) goto label_000228B7;
    label_0002281F:
    cpu->eax = *(uint8_t*)(cpu->edx);
    cpu->edi = *(uint8_t*)(cpu->ecx);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 1u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 1u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 1u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 2u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 2u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 2u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_0002285E;
    if (cpu->esi <= 3u) goto label_000228B7;
    cpu->eax = *(uint8_t*)(cpu->edx + 3u);
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->eax -= cpu->ecx;
    label_0002285E:
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->eax|=1u;
    if (cpu->eax==0u) goto label_000228B7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ebp + (cpu->edx * 4u)) = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4008u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_000228B7;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A4u);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0x400Cu);
    cpu->eax = *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]));
    if (cpu->edx != cpu->eax) goto label_000228B7;
    cpu->ecx = g_sfera_mbc_runtime->processes[0].code_range_ids[0];
    if (*(uint32_t*)(cpu->ebp + (cpu->ecx * 4u)) == 0xFFFFFFFFu) goto label_000228B7;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ebp + 0x4008u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x400Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x4010u) = cpu->eax;
    label_000228B7:
    lift_push32(cpu, 0x1A1u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\DebugScriptArrays.cpp";
    cpu->ecx = cpu->ebx;
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000228CC:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx += 0x8D8u;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[4096])) goto label_00022700;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
