#include "lifted_functions.h"
#include <cmath>
namespace lifted {





















































__declspec(noinline) void sfera_sub_004519B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->ecx = g_sfera_window_runtime.input_runtime_object;
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4519CDu)); sfera_sub_00489830(cpu, LIFT_CODE_TOKEN_VA(0x4519CDu));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) double sfera_sub_004519D0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
 double x87_p0, x87_p1;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    x87_p1 = 40.74365997314453;
    x87_p0 = (x87_p0) * (x87_p1);
    std::swap(x87_p1, x87_p0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p1); 
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0xCu)));
    cpu->esi = cpu->eax;
    cpu->esi &= 0xFFu;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->eax &= 0xFFu;
    cpu->esi -= cpu->eax;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)cpu->eax < (int32_t)0x80u) goto label_00051A1A;
    cpu->ecx = 0x100u;
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
label_00051A1A:
    *(float*)(cpu->esp + 4u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 4u)))))) * (0.024543695894260174));
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
     value_0 = x87_p0; cpu->esp += 0xCu; cpu->eip = stop_address; return value_0;
}



__declspec(noinline) void sfera_sub_00451CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00051D04;
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D04u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51D04u));
    label_00051D04:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00051D13;
    cpu->ecx = cpu->edi + 8u;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D13u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51D13u));
    label_00051D13:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi + (cpu->esi * 2u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00051D34;
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D34u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51D34u));
    label_00051D34:
    if ((int32_t)(cpu->esi) < (int32_t)(*(uint32_t*)(cpu->edi + 4u))) goto label_00051D43;
    cpu->ecx = cpu->edi + 8u;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D43u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51D43u));
    label_00051D43:
    cpu->eax = cpu->esi + (cpu->esi * 4u);
    cpu->eax <<= 4u;
    cpu->eax += *(uint32_t*)(cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->edi >= 0) goto label_00051D64;
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D64u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51D64u));
    label_00051D64:
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00051D73;
    cpu->ecx = cpu->esi + 8u;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51D73u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51D73u));
    label_00051D73:
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x27188u);
    cpu->eax += *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451D90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00051DA4;
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51DA4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x51DA4u));
    label_00051DA4:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00051DB3;
    cpu->ecx = cpu->edi + 8u;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x51DB3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x51DB3u));
    label_00051DB3:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = cpu->esi + (cpu->esi * 8u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00451DC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->ecx = 0u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00051DF5;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x451DD4u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x451DDBu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x451DE2u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00051DF5:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}












__declspec(noinline) void sfera_sub_00454E30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00054E78;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054E4B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54E4Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54E4Bu));
    label_00054E4B:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00054E78;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054E6A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54E6Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54E6Au));
    label_00054E6A:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax += 8u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054E78:
    cpu->eax = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->eax;
    label_00054E85:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00054E85;
    cpu->edx = *(uint32_t*)((uintptr_t)"GetPos: wrong handle");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetPos: wrong handle") + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"GetPos: wrong handle") + 0x14u));
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint8_t*)(cpu->eax + 0x14u) = cpu->ecx & 0xFFu;
    WorldDiagnostics::flushScriptContext();
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454ED0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00054F18;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054EEB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54EEBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54EEBu));
    label_00054EEB:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00054F18;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054F0A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54F0Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54F0Au));
    label_00054F0A:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax += 0x14u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054F18:
    cpu->eax = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->eax;
    label_00054F25:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00054F25;
    cpu->edx = *(uint32_t*)((uintptr_t)"GetAngles: wrong handle");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetAngles: wrong handle") + 0x14u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    WorldDiagnostics::flushScriptContext();
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00454F70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00054FB5;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054F8B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54F8Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54F8Bu));
    label_00054F8B:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00054FB5;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00054FAA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x54FAAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x54FAAu));
    label_00054FAA:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00054FB5:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00054FC3:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00054FC3;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetObjectPointer: wrong handle"),31u); cpu->ecx = 0u;
    WorldDiagnostics::flushScriptContext();
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004556B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    label_000556C0:
    if ((int32_t)cpu->ebx >= 0) goto label_000556CE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x556CEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x556CEu));
    label_000556CE:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_000556E2;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x556E2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x556E2u));
    label_000556E2:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebx * 4u)) == 0u) goto label_000556F0;
    ++cpu->ebx;
    goto label_000556C0;
    label_000556F0:
    lift_push32(cpu, 0x2E2Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x6E0Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455704u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x455704u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_00055714;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55714u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55714u));
    label_00055714:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00055728;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55728u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55728u));
    label_00055728:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u)) = cpu->esi;
    *(float*)(cpu->esi + 0x34u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->eax -= cpu->ebp;
    cpu->edx = 1u;
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ecx;
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    cpu->ecx += cpu->edx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x6E08u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    *(uint32_t*)(cpu->esi + 0x6DA4u) = cpu->ecx;
    std::memset((void*)(cpu->esi + 0x44u),0xFF,(0x1B58u)*4u); cpu->ecx = 0u;
    g_sfera_main_command_state_runtime.window_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00455820(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00055865;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005583B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5583Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5583Bu));
    label_0005583B:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00055865;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005585A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5585Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5585Au));
    label_0005585A:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00055865:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00055873:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00055873;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetWindowPointer: wrong handle"),31u); cpu->ecx = 0u;
    WorldDiagnostics::flushScriptContext();
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}




__declspec(noinline) void sfera_sub_00455E00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00055E11;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55E11u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x55E11u));
    label_00055E11:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00055E2F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x455E25u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x455E25u));
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00055E2F:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00455FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = 1u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00055FEA;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x55FEAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x55FEAu));
    label_00055FEA:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00456010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00056030;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x456027u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x456027u));
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00056030:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}










__declspec(noinline) void sfera_sub_004570A0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10;
 double x87_p0, x87_p1, x87_p2;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_000570B4;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x570B4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x570B4u));
label_000570B4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000570C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x570C8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x570C8u));
label_000570C8:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (!(((double)5.0f)>(((double)*(float*)(cpu->eax + 0x194u))))) goto label_00057100;
label_000570F2:
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
label_00057100:
    x87_p0 = (double)*(float*)(cpu->esi + 0x14u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45711Eu)); value_8 = sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x45711Eu));
    if ((value_8)<=(((double)0.15707965195178986f))) goto label_000570F2;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    x87_p1 = x87_p0;
    x87_p2 = 0.15707965195178986;
    x87_p1 = (x87_p1) + (x87_p2);
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0xCu) = x87_p2; 
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45715Cu)); value_9 = sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x45715Cu));
    *(float*)(cpu->esp + 0xCu) = value_9; 
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x10u);
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x457177u)); value_10 = sfera_sub_004519D0(cpu, LIFT_CODE_TOKEN_VA(0x457177u));
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu);
     value_1 = x87_p0; if (!((value_1)<(value_10))) goto label_000571B3;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    x87_p1 = 6.283185958862305;
     value_2 = x87_p1; value_3 = x87_p0; if (!((value_2)<(value_3))) goto label_000571E4;
    value_4 = value_3 - value_2; 
    *(float*)(cpu->esp + 4u) = value_4; 
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
     cpu->esp += 8u; cpu->eip = stop_address; return;
label_000571B3:
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
     value_5 = x87_p1; value_6 = x87_p0; { const double lift_left=value_5; const double lift_right=value_6;   if (!(lift_left<lift_right)) { value_0 = value_5; goto label_000571E6; } }
    value_7 = (value_5) + (6.283185958862305);
    *(float*)(cpu->esp + 4u) = value_7; 
    *(float*)(cpu->esi + 0x14u) = (double)*(float*)(cpu->esp + 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
     cpu->esp += 8u; cpu->eip = stop_address; return;
label_000571E4:
      value_0 = value_3;
label_000571E6:
    *(float*)(cpu->esi + 0x14u) = value_0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
     cpu->esp += 8u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00457490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_0005750C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    (void)cpu;
    label_000574A0:
    if ((int32_t)cpu->esi >= 0) goto label_000574AE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574AEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x574AEu));
    label_000574AE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000574C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574C2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x574C2u));
    label_000574C2:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_000574D0;
    ++cpu->esi;
    goto label_000574A0;
    label_000574D0:
    if ((int32_t)cpu->esi >= 0) goto label_000574DE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574DEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x574DEu));
    label_000574DE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000574F2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x574F2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x574F2u));
    label_000574F2:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint32_t*)(cpu->edx) != 0u) goto label_00057507;
    cpu->ecx = cpu->esi;
    WorldGuiControls::destroyText(cpu->ecx);
    label_00057507:
    ++cpu->esi;
    if ((--cpu->edi) != 0u) goto label_000574A0;
    cpu->edi = lift_pop32(cpu);
    label_0005750C:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}



} // namespace lifted
