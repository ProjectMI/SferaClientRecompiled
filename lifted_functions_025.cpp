#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_004F4AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4E60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)"logs\\CurrentExecuting.log"); lift_push32(cpu, (uintptr_t)&g_sfera_execution_monitor_runtime.log_path[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4F4E6Au));
    cpu->esp += 8u;
    lift_push32(cpu, 4u);
    lift_native_call(cpu, native_function_address32(&::SymSetOptions), LIFT_CODE_TOKEN_VA(0x4F4E75u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentProcess), LIFT_CODE_TOKEN_VA(0x4F4E7Fu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SymInitialize), LIFT_CODE_TOKEN_VA(0x4F4E86u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA0D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4EA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F4FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4FFAu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4F4FFAu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000F503D;
    g_sfera_effect_manager.effect_listeners.sentinel = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint8_t*)(cpu->ecx + 0x14u) = cpu->eax & 0xFFu;
    cpu->edx = g_sfera_effect_manager.effect_listeners.sentinel;
    *(uint8_t*)(cpu->edx + 0x15u) = cpu->eax & 0xFFu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA1F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F503D:
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F506Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F506Au));
    cpu->eip = 0x4F506Au; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004F5070(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x17CDC0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5081u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5081u));
    lift_push32(cpu, 0x17CDC0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_effect_manager.render_slots.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F508Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    g_sfera_effect_manager.render_slots.capacity = 0x2710u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F50ACu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F50ACu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_effect_manager.render_slots.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F50B2u));
    g_sfera_effect_manager.render_slots.debug_file[15] = '\0';
    g_sfera_effect_manager.render_slots.debug_line = UINT32_C(125);
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA150) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F50E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA170) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F50F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F51D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ecx = (uintptr_t)&g_sfera_error_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F51DEu)); sfera_sub_0042E540(cpu, LIFT_CODE_TOKEN_VA(0x4F51DEu));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA270) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F53A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F53D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F5530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5570(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5570;
    label_00021FC0:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x4014u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x421FCBu));
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x421FDBu));
    cpu->esp += 0x18u;
    *(uint32_t*)(cpu->esi + 0x4008u) = 0xFFFFFFFFu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5570:
    cpu->ecx = (uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    goto label_00021FC0;
}
__declspec(noinline) void sfera_sub_004F5580(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5580;
    label_000016E0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->edx = (uintptr_t)"";
    cpu->esi = cpu->eax;
    cpu->esi -= cpu->edx;
    label_000016F0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->esi + cpu->edx) = cpu->ebx & 0xFFu;
    ++cpu->edx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000016F0;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5580:
    cpu->ecx = (uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    goto label_000016E0;
}
__declspec(noinline) void sfera_sub_004F5590(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    x87_v0 = 0.0;
    x87_v0 = (x87_v0) + (40.0);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    g_sfera_recovered_static_runtime.inverse_40 = x87_v0; 
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F5620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5631u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5631u));
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[2].data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F563Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].capacity) = 0x7Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F565Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F565Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5662u));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[2].debug_line) = 0x3A6u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA3E0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5690(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F56A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F56A1u));
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[1].data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F56AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].capacity) = 0x7Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F56CCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F56CCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F56D2u));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[1].debug_line) = 0x3A7u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA400) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5711u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5711u));
    lift_push32(cpu, 0x1F8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.legacy_light_arrays[0].data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F571Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\light.cpp";
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].capacity) = 0x7Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F573Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F573Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5742u));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_file[15]) = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_recovered_static_runtime.legacy_light_arrays[0].debug_line) = 0x3A8u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA420) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F5850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F58A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F58A1u));
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.secondary_auto_array.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F58AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_recovered_static_runtime.secondary_auto_array.capacity = 0x1F4u;
    g_sfera_recovered_static_runtime.secondary_auto_array.maximum = 0x1388u;
    g_sfera_recovered_static_runtime.secondary_auto_array.growth = 0x64u;
    g_sfera_recovered_static_runtime.secondary_auto_array.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F58EAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F58EAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F58F0u));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.secondary_auto_array.debug_file[15]) = 0u;
    g_sfera_recovered_static_runtime.secondary_auto_array.debug_line = 0xE6u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA470) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5920(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4650u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5931u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5931u));
    lift_push32(cpu, 0x4650u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e7_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F593Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.e7_records.capacity = 0x1F4u;
    g_sfera_client_array_runtime.e7_records.maximum = 0x1388u;
    g_sfera_client_array_runtime.e7_records.growth = 0x64u;
    g_sfera_client_array_runtime.e7_records.element_size = 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F597Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F597Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5980u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.e7_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.e7_records.debug_line = 0xE7u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA490) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F59B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F59C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F59C1u));
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e8_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F59CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.e8_indices.capacity = 0x1F4u;
    g_sfera_client_array_runtime.e8_indices.maximum = 0x1388u;
    g_sfera_client_array_runtime.e8_indices.growth = 0x64u;
    g_sfera_client_array_runtime.e8_indices.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5A0Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5A0Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5A10u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.e8_indices.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.e8_indices.debug_line = 0xE8u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA4B0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x320u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5A51u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5A51u));
    lift_push32(cpu, 0x320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.e9_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5A5Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.e9_indices.capacity = 0xC8u;
    g_sfera_client_array_runtime.e9_indices.maximum = 0x1F4u;
    g_sfera_client_array_runtime.e9_indices.growth = 0x64u;
    g_sfera_client_array_runtime.e9_indices.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5A9Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5A9Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5AA0u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.e9_indices.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.e9_indices.debug_line = 0xE9u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA4D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5AD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x109A0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5AE1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5AE1u));
    lift_push32(cpu, 0x109A0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.eb_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5AEEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.eb_records.capacity = 0x1F4u;
    g_sfera_client_array_runtime.eb_records.maximum = 0x3E8u;
    g_sfera_client_array_runtime.eb_records.growth = 0x32u;
    g_sfera_client_array_runtime.eb_records.element_size = 0x88u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5B2Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5B2Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5B30u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.eb_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.eb_records.debug_line = 0xEBu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA4F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5B60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5B71u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5B71u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.ed_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5B7Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.ed_indices.capacity = 0x32u;
    g_sfera_client_array_runtime.ed_indices.maximum = 0xC8u;
    g_sfera_client_array_runtime.ed_indices.growth = 0x14u;
    g_sfera_client_array_runtime.ed_indices.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5BBAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5BBAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5BC0u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.ed_indices.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.ed_indices.debug_line = 0xEDu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA510) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5BF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5C01u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5C01u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.contact_objects.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5C0Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.contact_objects.capacity = 0x32u;
    g_sfera_collision_runtime.contact_objects.maximum = 0x2710u;
    g_sfera_collision_runtime.contact_objects.growth = 0x14u;
    g_sfera_collision_runtime.contact_objects.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5C4Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5C4Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5C50u));
    *(uint8_t*)((uintptr_t)&g_sfera_collision_runtime.contact_objects.debug_file[15]) = 0u;
    g_sfera_collision_runtime.contact_objects.debug_line = 0xEFu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA530) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F5C90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5CA1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5CA1u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_102_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5CAEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_102_indices.capacity = 0x32u;
    g_sfera_client_array_runtime.line_102_indices.maximum = 0x64u;
    g_sfera_client_array_runtime.line_102_indices.growth = 0x14u;
    g_sfera_client_array_runtime.line_102_indices.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5CEAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5CEAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5CF0u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_102_indices.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_102_indices.debug_line = 0x102u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA550) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5D31u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5D31u));
    lift_push32(cpu, 0x3200u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_105_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5D3Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_105_records.capacity = 0xC8u;
    g_sfera_client_array_runtime.line_105_records.maximum = 0x1F4u;
    g_sfera_client_array_runtime.line_105_records.growth = 0x64u;
    g_sfera_client_array_runtime.line_105_records.element_size = 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5D7Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5D7Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5D80u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_105_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_105_records.debug_line = 0x105u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA570) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F5DD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000F5DD0;
    label_0009B950:
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B967u)); sfera_sub_0049B860(cpu, LIFT_CODE_TOKEN_VA(0x49B967u));
    lift_push32(cpu, 0x5320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49B96Fu));
    cpu->eax = 0x6E726157u;
    cpu->ecx = 0x73676E69u;
    cpu->edx = 0x6C2E3030u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x676F)) & 0xFFFFu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint16_t*)(cpu->esp + 0x14u) = cpu->eax & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0x16u) = cpu->ecx & 0xFFu;
    cpu->ebx=0u;
    label_0009B9B0:
    cpu->edx = (uint32_t)(((uint64_t)0xCCCCCCCDu * (uint32_t)(cpu->ebx)) >> 32u);
    cpu->edx >>= 3u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = cpu->edx + 0x30u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->eax & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ebx & 0xFFu) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = cpu->esp + 8u;
    *(uint8_t*)(cpu->esp + 0x11u) = cpu->eax & 0xFFu;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    if ((int32_t)cpu->eax <= (int32_t)0xF4240u) goto label_0009B9F3;
    cpu->edx = 0xF4240u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B9F3u)); sfera_sub_0044C020(cpu, LIFT_CODE_TOKEN_RVA(0x9B9F3u));
    label_0009B9F3:
    ++cpu->ebx;
    if ((int32_t)(cpu->ebx) < (int32_t)(0x14u)) goto label_0009B9B0;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5DD0:
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    goto label_0009B950;
}

__declspec(noinline) void sfera_sub_004F5E50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7F710u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5E61u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5E61u));
    lift_push32(cpu, 0x7F710u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_landscape_runtime.file_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5E6Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_runtime.file_records.capacity = 0x12Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5E8Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5E8Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5E92u));
    g_sfera_landscape_runtime.file_records.debug_file[15] = 0;
    g_sfera_landscape_runtime.file_records.debug_line = 0x171u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA5B0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5EC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x6D60u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5ED1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5ED1u));
    lift_push32(cpu, 0x6D60u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_interface_runtime.window_handle_table.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5EDEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_interface_runtime.window_handle_table.capacity = 0x1B58u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5EFCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5EFCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5F02u));
    *(uint8_t*)((uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[15]) = 0u;
    g_sfera_interface_runtime.window_handle_table.debug_line = 0x193u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA5D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5F30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E8480u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5F41u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5F41u));
    lift_push32(cpu, 0x1E8480u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_world_objects.object_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5F4Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_world_objects.object_handles.capacity = 0x7A120u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5F6Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5F6Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5F72u));
    g_sfera_world_objects.object_handles.debug_file[15] = 0;
    g_sfera_world_objects.object_handles.debug_line = 0x1A2u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA5F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1D4C0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5FB1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5FB1u));
    lift_push32(cpu, 0x1D4C0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_world_objects.extended_object_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5FBEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_world_objects.extended_object_handles.capacity = 0x7530u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5FDCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5FDCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5FE2u));
    g_sfera_world_objects.extended_object_handles.debug_file[15] = 0;
    g_sfera_world_objects.extended_object_handles.debug_line = 0x1A5u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA610) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x190u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6021u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6021u));
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_interface_runtime.windows.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F602Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_interface_runtime.windows.capacity = 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F604Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F604Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6052u));
    g_sfera_interface_runtime.windows.debug_file[15] = 0;
    g_sfera_interface_runtime.windows.debug_line = 0x1A9u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA630) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6091u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6091u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_character_index_map.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F609Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_character_index_map.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F60BCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F60BCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_character_index_map.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F60C2u));
    g_sfera_character_index_map.debug_file[15] = '\0';
    g_sfera_character_index_map.debug_line = 0x1BFu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA650) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F60F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6101u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6101u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_visibility_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F610Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_visibility_indices.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F612Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F612Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6132u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_visibility_indices.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.object_visibility_indices.debug_line = 0x1C0u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA670) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6171u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6171u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_sort_keys.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F617Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_sort_keys.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F619Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F619Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F61A2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_sort_keys.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.object_sort_keys.debug_line = 0x1C3u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA690) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F61D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F61E1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F61E1u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_sort_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F61EEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_sort_indices.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F620Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F620Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6212u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_sort_indices.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.object_sort_indices.debug_line = 0x1C4u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA6B0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6251u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6251u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_draw_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F625Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_draw_indices.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F627Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F627Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6282u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_draw_indices.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.object_draw_indices.debug_line = 0x1C5u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA6D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F62B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F62C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F62C1u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.candidate_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F62CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.candidate_handles.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F62ECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F62ECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.candidate_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F62F2u));
    g_sfera_collision_runtime.candidate_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.candidate_handles.debug_line = 0x1C6u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA6F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F6400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x2A30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6411u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6411u));
    lift_push32(cpu, 0x2A30u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.scene_points.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F641Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.scene_points.capacity = 0x384u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F643Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F643Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6442u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.scene_points.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.scene_points.debug_line = 0x33Cu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA750) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6481u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6481u));
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_config_runtime.text_length_01 = 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F64E4u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F64E4u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.text_01[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F64EAu));
    *(uint8_t*)((uintptr_t)&g_sfera_client_config_runtime.text_01[15]) = 0u;
    g_sfera_client_config_runtime.text_capacity_01 = 0x633u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA770) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x400u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6521u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6521u));
    lift_push32(cpu, 0x400u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F652Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_config_runtime.text_length_02 = 0x100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F654Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F654Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.text_02[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6552u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_config_runtime.text_02[15]) = 0u;
    g_sfera_client_config_runtime.text_capacity_02 = 0x6B0u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA790) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6580(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6591u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6591u));
    g_sfera_client_array_runtime.line_6b1_indices.data = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b1_indices.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_6b1_indices.capacity = 0xAu;
    g_sfera_client_array_runtime.line_6b1_indices.maximum = 0x14u;
    g_sfera_client_array_runtime.line_6b1_indices.growth = 5u;
    g_sfera_client_array_runtime.line_6b1_indices.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F661Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F661Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6620u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b1_indices.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_6b1_indices.debug_line = 0x6B1u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA7B0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6650(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6661u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6661u));
    g_sfera_recovered_static_runtime.primary_auto_array.data = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.primary_auto_array.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_recovered_static_runtime.primary_auto_array.capacity = 0xAu;
    g_sfera_recovered_static_runtime.primary_auto_array.maximum = 0x14u;
    g_sfera_recovered_static_runtime.primary_auto_array.growth = 5u;
    g_sfera_recovered_static_runtime.primary_auto_array.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F66EAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F66EAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F66F0u));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.primary_auto_array.debug_file[15]) = 0u;
    g_sfera_recovered_static_runtime.primary_auto_array.debug_line = 0x6B2u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA7D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6731u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6731u));
    g_sfera_client_array_runtime.line_6b3_indices.data = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b3_indices.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_6b3_indices.capacity = 0xAu;
    g_sfera_client_array_runtime.line_6b3_indices.maximum = 0x14u;
    g_sfera_client_array_runtime.line_6b3_indices.growth = 5u;
    g_sfera_client_array_runtime.line_6b3_indices.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F67BAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F67BAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F67C0u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b3_indices.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_6b3_indices.debug_line = 0x6B3u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA7F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F67F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6801u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6801u));
    g_sfera_client_array_runtime.line_6b4_indices.data = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_client_array_runtime.line_6b4_indices.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_6b4_indices.capacity = 0xAu;
    g_sfera_client_array_runtime.line_6b4_indices.maximum = 0x14u;
    g_sfera_client_array_runtime.line_6b4_indices.growth = 5u;
    g_sfera_client_array_runtime.line_6b4_indices.element_size = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F688Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F688Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6890u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b4_indices.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_6b4_indices.debug_line = 0x6B4u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA810) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F68C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F68D1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F68D1u));
    lift_push32(cpu, 0x1E0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_6b5_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F68DEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_6b5_records.capacity = 0xAu;
    g_sfera_client_array_runtime.line_6b5_records.maximum = 0x14u;
    g_sfera_client_array_runtime.line_6b5_records.growth = 5u;
    g_sfera_client_array_runtime.line_6b5_records.element_size = 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F691Au)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F691Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6920u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_6b5_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_6b5_records.debug_line = 0x6B5u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA830) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F6B10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xB7980u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B21u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6B21u));
    lift_push32(cpu, 0xB7980u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_124d_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6B2Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_124d_records.capacity = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B4Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6B4Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6B52u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_124d_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_124d_records.debug_line = 0x124Du;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA8D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6B80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA00u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6B91u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6B91u));
    lift_push32(cpu, 0xFA00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_recovered_static_runtime.tertiary_auto_array.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6B9Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_recovered_static_runtime.tertiary_auto_array.capacity = 0x7D0u;
    g_sfera_recovered_static_runtime.tertiary_auto_array.maximum = 0xBB8u;
    g_sfera_recovered_static_runtime.tertiary_auto_array.growth = 0x1F4u;
    g_sfera_recovered_static_runtime.tertiary_auto_array.element_size = 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6BDAu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6BDAu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6BE0u));
    *(uint8_t*)((uintptr_t)&g_sfera_recovered_static_runtime.tertiary_auto_array.debug_file[15]) = 0u;
    g_sfera_recovered_static_runtime.tertiary_auto_array.debug_line = 0x124Fu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA8F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6C10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C21u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6C21u));
    lift_push32(cpu, 0x30u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_pass_slots.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6C2Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_pass_slots.capacity = 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C49u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6C49u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6C4Fu));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.render_pass_slots.debug_line = 0x125Bu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA910) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F6D60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D71u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6D71u));
    lift_push32(cpu, 0xFA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6D7Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.handles.capacity = 0x3E8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D9Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6D9Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6DA2u));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.handles.debug_file[15]) = 0u;
    g_sfera_light_runtime.handles.debug_line = 0x127Eu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA970) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6DD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6DE1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6DE1u));
    lift_push32(cpu, 0x7D0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.visible_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6DEEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.visible_handles.capacity = 0x1F4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6E0Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6E0Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6E12u));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[15]) = 0u;
    g_sfera_light_runtime.visible_handles.debug_line = 0x1280u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA990) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6E40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6E51u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6E51u));
    lift_push32(cpu, 0x7Cu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.active_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6E5Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.active_handles.capacity = 0x1Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6E79u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6E79u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6E7Fu));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[15]) = 0u;
    g_sfera_light_runtime.active_handles.debug_line = 0x1282u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA9B0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F6FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x23280u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6FB1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6FB1u));
    lift_push32(cpu, 0x23280u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24de_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6FBEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_24de_records.capacity = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6FDCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6FDCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6FE2u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24de_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_24de_records.debug_line = 0x24DEu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA9F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x21D68u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7021u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7021u));
    lift_push32(cpu, 0x21D68u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e0_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F702Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_24e0_records.capacity = 0x26ACu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F704Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F704Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7052u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e0_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_24e0_records.debug_line = 0x24E0u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAA10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D00u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7091u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7091u));
    lift_push32(cpu, 0x7D00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e2_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F709Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_24e2_records.capacity = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F70BCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F70BCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F70C2u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_24e2_records.debug_line = 0x24E2u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAA30) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F70F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4000u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7101u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7101u));
    lift_push32(cpu, 0x4000u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.model_matrices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F710Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.model_matrices.capacity = 0x100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F712Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F712Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7132u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.model_matrices.debug_line = 0x24EBu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAA50) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x140u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7171u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7171u));
    lift_push32(cpu, 0x140u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.character_matrices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F717Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.character_matrices.capacity = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F719Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F719Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F71A2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.character_matrices.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.character_matrices.debug_line = 0x24F1u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAA70) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F71D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1D4C0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F71E1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F71E1u));
    lift_push32(cpu, 0x1D4C0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.object_positions.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F71EEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.object_positions.capacity = 0x2710u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F720Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F720Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7212u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.object_positions.debug_line = 0x2539u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAA90) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x960u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7251u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7251u));
    lift_push32(cpu, 0x960u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_vectors.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F725Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_vectors.capacity = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F727Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F727Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7282u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.clip_vectors.debug_line = 0x2A71u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAAB0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F72B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x320u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F72C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F72C1u));
    lift_push32(cpu, 0x320u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F72CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_indices.capacity = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F72ECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F72ECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F72F2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.clip_indices.debug_line = 0x2A77u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAAD0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7320(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1E0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7331u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7331u));
    lift_push32(cpu, 0x1E0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.clip_points.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F733Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.clip_points.capacity = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F735Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F735Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7362u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.clip_points.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.clip_points.debug_line = 0x2A84u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAAF0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x27100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F73A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F73A1u));
    lift_push32(cpu, 0x27100u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.cloud_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F73AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.cloud_records.capacity = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F73CCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F73CCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F73D2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.cloud_records.debug_line = 0x2A85u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAB10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7411u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7411u));
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_collision_runtime.near_result_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F741Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_collision_runtime.near_result_handles.capacity = 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7439u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F7439u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_collision_runtime.near_result_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F743Fu));
    g_sfera_collision_runtime.near_result_handles.debug_file[15] = 0;
    g_sfera_collision_runtime.near_result_handles.debug_line = 0x2A86u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAB30) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4C5BDA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7481u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7481u));
    lift_push32(cpu, 0x4C5BDA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.world_cell_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F748Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.world_cell_records.capacity = 0x1F4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F74ACu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F74ACu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F74B2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.world_cell_records.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.world_cell_records.debug_line = 0x2A94u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAB50) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F7DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAE40) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F7EE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F8200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F82B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F82D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F83D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F83F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F8480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F84A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F8530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F8660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F8780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F87A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F8830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F88E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F8990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F89B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F8E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F8F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F90F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F91A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F91C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F92C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F92E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F9370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F9420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F94D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F94F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F9580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F95A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F9630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F96E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F9730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBD10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBCD0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F97C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F97E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F98E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F9990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F99B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F9A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}




__declspec(noinline) void sfera_sub_004F9BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_crash_report_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C0Au)); sfera_sub_004D6720(cpu, LIFT_CODE_TOKEN_VA(0x4F9C0Au));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC090) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004F9FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x200u); lift_push32(cpu, 0u); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0xCu); lift_push32(cpu, (uintptr_t)"$d $t "); lift_push32(cpu, (uintptr_t)"LogMemory.log");
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9FC2u)); sfera_sub_004EC500(cpu, LIFT_CODE_TOKEN_VA(0x4F9FC2u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC130) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9FD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x840u); lift_push32(cpu, 1u); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"$d $t $u"); lift_push32(cpu, (uintptr_t)"Warnings.log");
    cpu->ecx = (uintptr_t)&g_sfera_log_warnings_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9FF5u)); sfera_sub_004EC500(cpu, LIFT_CODE_TOKEN_VA(0x4F9FF5u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC140) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x840u); lift_push32(cpu, 1u); lift_push32(cpu, 0xF4240u); lift_push32(cpu, 0xDu); lift_push32(cpu, (uintptr_t)"$d $t $u"); lift_push32(cpu, (uintptr_t)"Errors.log");
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA035u)); sfera_sub_004EC500(cpu, LIFT_CODE_TOKEN_VA(0x4FA035u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC150) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA041(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC15A) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::WaitForSingleObject);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(cpu->eax, 0u);
    if (cpu->eax == 0u) goto label_000FA117;
    cpu->ecx = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->ecx);
    g_sfera_execution_monitor_runtime.stop_requested = UINT16_C(1);
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u)); cpu->esp += 0x8u;
    if (cpu->eax == 0u) goto label_000FA10C;
    cpu->edx = g_sfera_execution_monitor_runtime.thread_handle;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_RVA(0xFA106u));
    label_000FA10C:
    lift_push32(cpu, (uintptr_t)&g_sfera_execution_monitor_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::DeleteCriticalSection), LIFT_CODE_TOKEN_RVA(0xFA111u));
    label_000FA117:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_effect_manager.render_slots.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA162u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA162u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA170(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    cpu->ecx = g_sfera_effect_items.block_vector_end;
    cpu->eax = g_sfera_effect_items.block_vector_begin;
    cpu->ecx -= cpu->eax;
    cpu->esi=0u;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if (cpu->ecx == 0u) goto label_000FA1BA;
    cpu->ecx = (uintptr_t)&g_sfera_effect_items;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA1B5u)); sfera_sub_0042A290(cpu, LIFT_CODE_TOKEN_VA(0x4FA1B5u));
    cpu->eax = g_sfera_effect_items.block_vector_begin;
    label_000FA1BA:
    if (cpu->eax == cpu->esi) goto label_000FA1C7;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA1C4u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4FA1C4u));
    cpu->esp += 4u;
    label_000FA1C7:
    g_sfera_effect_items.block_vector_begin = cpu->esi;
    g_sfera_effect_items.block_vector_end = cpu->esi;
    g_sfera_effect_items.block_vector_capacity_end = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA1F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA231u)); sfera_sub_00406340(cpu, LIFT_CODE_TOKEN_VA(0x4FA231u));
    cpu->ecx = g_sfera_effect_manager.effect_listeners.sentinel;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA23Du)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4FA23Du));
    cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    goto label_000FA270;
    label_0002E630:
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 8u) == 0u) goto label_0002E681;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x104u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E649u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E649u));
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->esi == 0u) goto label_0002E680;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    reinterpret_cast<CSphereError*>(cpu->esi)->~CSphereError();
    if (sub_pred[0]) goto label_0002E677;
    cpu->edx = 0x65u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E66Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E66Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E674u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x42E674u));
    cpu->esp += 4u;
    label_0002E677:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E67Du)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x42E67Du));
    cpu->esp += 4u;
    label_0002E680:
    cpu->esi = lift_pop32(cpu);
    label_0002E681:
    if (*(uint32_t*)(cpu->edi + 0xCu) == 0u) goto label_0002E6AD;
    cpu->edx = 0x105u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E696u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E696u));
    cpu->edi = *(uint32_t*)(cpu->edi + 0xCu);
    if (cpu->edi == 0u) goto label_0002E6AD;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6A4u)); sfera_sub_0042E250(cpu, LIFT_CODE_TOKEN_VA(0x42E6A4u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6AAu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x42E6AAu));
    cpu->esp += 4u;
    label_0002E6AD:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA270:
    cpu->ecx = (uintptr_t)&g_sfera_error_log_runtime.object[0];
    goto label_0002E630;
}

__declspec(noinline) void sfera_sub_004FA3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[2].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA3F2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA3F2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[1].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA412u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA412u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.legacy_light_arrays[0].data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA432u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA432u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FA470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.secondary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA482u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA482u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e7_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA4A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA4A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e8_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA4C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA4C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e9_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA4E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA4E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA4F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.eb_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA502u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA502u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.ed_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA522u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA522u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA542u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA542u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_102_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA562u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA562u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_105_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA582u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA582u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FA5B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA5C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA5C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA5D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA5E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA5E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA5F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA602u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA602u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA622u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA622u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA642u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA642u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_character_index_map.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA662u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA662u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_visibility_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA682u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA682u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_keys.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA6A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA6A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_sort_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA6C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA6C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_draw_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA6E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA6E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_collision_runtime.candidate_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA702u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA702u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004FA750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.scene_points.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA762u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA762u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA782u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA782u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA7A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA7A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA7B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA7C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA7C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA7E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA7E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA802u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA802u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA822u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA822u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b5_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA842u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA842u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FA8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_124d_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA8E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA8E2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA8F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.tertiary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA902u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA902u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.render_pass_slots.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA922u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA922u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004FA970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA982u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA982u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.visible_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA9A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA9A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA9C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA9C2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FA9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_24de_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA02u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA02u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_24e0_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA22u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA22u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_24e2_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA42u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA42u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.model_matrices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA62u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA62u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.character_matrices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAA82u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAA82u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAAA2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAAA2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAAC2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAAC2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.clip_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAAE2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAAE2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAAF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.clip_points.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB02u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB02u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.cloud_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB22u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB22u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_collision_runtime.near_result_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB42u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB42u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.world_cell_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB62u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB62u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FAE40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    cpu->ecx = g_sfera_sound_effect_items.block_vector_end;
    cpu->eax = g_sfera_sound_effect_items.block_vector_begin;
    cpu->ecx -= cpu->eax;
    cpu->esi=0u;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if (cpu->ecx == 0u) goto label_000FAE8A;
    cpu->ecx = (uintptr_t)&g_sfera_sound_effect_items;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAE85u)); sfera_sub_004974B0(cpu, LIFT_CODE_TOKEN_VA(0x4FAE85u));
    cpu->eax = g_sfera_sound_effect_items.block_vector_begin;
    label_000FAE8A:
    if (cpu->eax == cpu->esi) goto label_000FAE97;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAE94u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4FAE94u));
    cpu->esp += 4u;
    label_000FAE97:
    g_sfera_sound_effect_items.block_vector_begin = cpu->esi;
    g_sfera_sound_effect_items.block_vector_end = cpu->esi;
    g_sfera_sound_effect_items.block_vector_capacity_end = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FBCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    if (cpu->eax == 0u) goto label_000FBCE2;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBCDFu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4FBCDFu));
    cpu->esp += 4u;
    label_000FBCE2:
    g_sfera_options_dialog_runtime.chat_edit_fonts.begin = 0u;
    g_sfera_options_dialog_runtime.chat_edit_fonts.end = 0u;
    g_sfera_options_dialog_runtime.chat_edit_fonts.capacity_end = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBD10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.chat_list_fonts.begin;
    if (cpu->eax == 0u) goto label_000FBD22;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBD1Fu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4FBD1Fu));
    cpu->esp += 4u;
    label_000FBD22:
    g_sfera_options_dialog_runtime.chat_list_fonts.begin = 0u;
    g_sfera_options_dialog_runtime.chat_list_fonts.end = 0u;
    g_sfera_options_dialog_runtime.chat_list_fonts.capacity_end = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004FC090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::SetUnhandledExceptionFilter(reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(static_cast<uintptr_t>(g_sfera_crash_report_runtime.previous_exception_filter)))));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FC130(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC130;
    label_000ED1A0:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if (cpu->eax == 0u) goto label_000ED1E5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    goto label_000ED1EE;
    label_000ED1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = cpu->edx;
    label_000ED1EE:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000ED1F9;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000ED1F9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uintptr_t)"***** Quit  ");
    cpu->edi = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uintptr_t)"***** Quit  ");
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED238u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED238u));
    label_000ED238:
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu));
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u));
    cpu->esp += 0x18u;
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu));
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED296u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED296u));
    label_000ED296:
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au));
    cpu->esp += 4u;
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u));
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uintptr_t)" *****\n");
    cpu->eax = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u));
    label_000ED2D8:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu));
    label_000ED2DF:
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu));
    if ((int32_t)cpu->eax <= 0) goto label_000ED30D;
    label_000ED2F1:
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u));
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u));
    if ((int32_t)cpu->eax > 0) goto label_000ED2F1;
    label_000ED30D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u)); sfera_sub_004ECBB0(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000ED336;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED336:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->eax == 0u) goto label_000ED343;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED343:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if (cpu->eax == 0u) goto label_000ED350;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED350:
    cpu->ecx = cpu->esi + 0x38u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu)); sfera_sub_004EE470(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC130:
    cpu->ecx = (uintptr_t)&g_sfera_log_memory_object;
    goto label_000ED1A0;
}
__declspec(noinline) void sfera_sub_004FC140(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC140;
    label_000ED1A0:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if (cpu->eax == 0u) goto label_000ED1E5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    goto label_000ED1EE;
    label_000ED1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = cpu->edx;
    label_000ED1EE:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000ED1F9;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000ED1F9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uintptr_t)"***** Quit  ");
    cpu->edi = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uintptr_t)"***** Quit  ");
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED238u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED238u));
    label_000ED238:
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu));
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u));
    cpu->esp += 0x18u;
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu));
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED296u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED296u));
    label_000ED296:
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au));
    cpu->esp += 4u;
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u));
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uintptr_t)" *****\n");
    cpu->eax = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u));
    label_000ED2D8:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu));
    label_000ED2DF:
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu));
    if ((int32_t)cpu->eax <= 0) goto label_000ED30D;
    label_000ED2F1:
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u));
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u));
    if ((int32_t)cpu->eax > 0) goto label_000ED2F1;
    label_000ED30D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u)); sfera_sub_004ECBB0(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000ED336;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED336:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->eax == 0u) goto label_000ED343;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED343:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if (cpu->eax == 0u) goto label_000ED350;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED350:
    cpu->ecx = cpu->esi + 0x38u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu)); sfera_sub_004EE470(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC140:
    cpu->ecx = (uintptr_t)&g_sfera_log_warnings_object;
    goto label_000ED1A0;
}
__declspec(noinline) void sfera_sub_004FC150(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC150;
    label_000ED1A0:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    if (cpu->eax == 0u) goto label_000ED1E5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    goto label_000ED1EE;
    label_000ED1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    g_sfera_critical_diagnostics_runtime.log_chain_head = cpu->edx;
    label_000ED1EE:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000ED1F9;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_000ED1F9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_VA(0x4ED200u));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (1u)) == 0u) goto label_000ED2DF;
    lift_push32(cpu, (uintptr_t)"***** Quit  ");
    cpu->edi = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->esi + 0x24u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED21Eu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED238;
    lift_push32(cpu, (uintptr_t)"***** Quit  ");
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED238u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED238u));
    label_000ED238:
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4ED23Cu));
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4ED246u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m/%y");
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x4ED258u));
    cpu->esp += 0x18u;
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED26Eu));
    lift_push32(cpu, (uintptr_t)" "); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED27Cu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED296;
    lift_push32(cpu, (uintptr_t)" ");
    cpu->edx = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED296u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED296u));
    label_000ED296:
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x4ED29Au));
    cpu->esp += 4u;
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2B0u));
    lift_push32(cpu, (uintptr_t)" *****\n"); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_VA(0x4ED2BEu));
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED2D8;
    lift_push32(cpu, (uintptr_t)" *****\n");
    cpu->eax = cpu->esi + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u)); sfera_sub_004EC770(cpu, LIFT_CODE_TOKEN_RVA(0xED2D8u));
    label_000ED2D8:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu)); sfera_sub_004ECF60(cpu, LIFT_CODE_TOKEN_RVA(0xED2DFu));
    label_000ED2DF:
    if (((*(uint8_t*)(cpu->esi + 0x10u)) & (8u)) == 0u) goto label_000ED30D;
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2EDu));
    if ((int32_t)cpu->eax <= 0) goto label_000ED30D;
    label_000ED2F1:
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u)); sfera_sub_004EE4D0(cpu, LIFT_CODE_TOKEN_VA(0x4ED2F9u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u)); sfera_sub_004ECE80(cpu, LIFT_CODE_TOKEN_VA(0x4ED301u));
    cpu->ecx = cpu->esi + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u)); sfera_sub_004EE4B0(cpu, LIFT_CODE_TOKEN_VA(0x4ED309u));
    if ((int32_t)cpu->eax > 0) goto label_000ED2F1;
    label_000ED30D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u)); sfera_sub_004ECBB0(cpu, LIFT_CODE_TOKEN_VA(0x4ED314u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = native_function_address32(&::free);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(*(uint32_t*)(cpu->esp));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000ED336;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED336:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->eax == 0u) goto label_000ED343;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED343:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if (cpu->eax == 0u) goto label_000ED350;

    reinterpret_cast<void (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::free)))(cpu->eax);

    label_000ED350:
    cpu->ecx = cpu->esi + 0x38u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu)); sfera_sub_004EE470(cpu, LIFT_CODE_TOKEN_VA(0x4ED35Fu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC150:
    cpu->ecx = (uintptr_t)&g_sfera_log_errors_object;
    goto label_000ED1A0;
}
__declspec(noinline) void sfera_sub_004FC15A(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.reserved_dynamic_tls_dtors = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
