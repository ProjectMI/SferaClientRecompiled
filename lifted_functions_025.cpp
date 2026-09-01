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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F4FFAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F4FFAu));
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
__declspec(noinline) void sfera_sub_004F51F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5201u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5201u));
    lift_push32(cpu, 0x50u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_file_runtime.open_files.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F520Bu));
    cpu->esp += 0xCu;
    cpu->eax = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    g_sfera_file_runtime.open_files.capacity = cpu->eax;
    g_sfera_file_runtime.open_files.maximum = UINT32_C(100);
    g_sfera_file_runtime.open_files.growth = cpu->eax;
    g_sfera_file_runtime.open_files.element_size = UINT32_C(8);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5242u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5242u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_file_runtime.open_files.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5248u));
    g_sfera_file_runtime.open_files.debug_file[15] = 0;
    g_sfera_file_runtime.open_files.debug_line = UINT32_C(25);
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA280) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5281u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5281u));
    g_sfera_file_runtime.search_paths.data = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 0x10u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 0x18u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->ecx;
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    cpu->eax = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    g_sfera_file_runtime.search_paths.capacity = cpu->eax;
    g_sfera_file_runtime.search_paths.maximum = UINT32_C(100);
    g_sfera_file_runtime.search_paths.growth = cpu->eax;
    g_sfera_file_runtime.search_paths.element_size = UINT32_C(4);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5305u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5305u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)g_sfera_file_runtime.search_paths.debug_file);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F530Bu));
    g_sfera_file_runtime.search_paths.debug_file[15] = 0;
    g_sfera_file_runtime.search_paths.debug_line = UINT32_C(27);
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA2A0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
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
__declspec(noinline) void sfera_sub_004F5450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[0u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[0u].transform;
    g_sfera_spatial_states[0u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5467u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F5467u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA340) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5480(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[0u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F54B9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F54B9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F54C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[1u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[1u].transform;
    g_sfera_spatial_states[1u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F54D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F54D7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA350) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F54F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[1u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5529u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F5529u));
    cpu->esp += 0x18u;
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
__declspec(noinline) void sfera_sub_004F55B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[2u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[2u].transform;
    g_sfera_spatial_states[2u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F55C7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F55C7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA3D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F55E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[2u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5619u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F5619u));
    cpu->esp += 0x18u;
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
__declspec(noinline) void sfera_sub_004F5770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[3u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[3u].transform;
    g_sfera_spatial_states[3u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5787u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F5787u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA440) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F57A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[3u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F57D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F57D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F57E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[4u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[4u].transform;
    g_sfera_spatial_states[4u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F57F7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F57F7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA450) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F5810(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[4u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5849u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F5849u));
    cpu->esp += 0x18u;
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
__declspec(noinline) void sfera_sub_004F5C80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    goto label_000F5C80;
    label_0004B620:
    lift_push32(cpu, cpu->ecx);
    x87_v0 = 1.0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esi + 0x10u;
    cpu->eax &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(float*)(cpu->eax) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esi);
    x87_v1 = 0.0;
    *(float*)(cpu->eax + 4u) = x87_v1;
    cpu->ebx = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->ecx + 8u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->edx + 0xCu) = x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->eax + 0x10u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ecx + 0x14u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esi);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->edx + 0x18u) = x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->eax + 0x1Cu) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->ecx + 0x20u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->edx + 0x24u) = x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esi);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + 0x28u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ecx + 0x2Cu) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->edx + 0x30u) = x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->eax + 0x34u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->ecx + 0x38u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esi);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->edx + 0x3Cu) = x87_v1;
    cpu->eax = cpu->esi + 0x13Bu;
    *(float*)(cpu->esi + 0x50u) = x87_v1;
    cpu->eax &= 0xFFFFFFF0u;
    x87_v2 = (double)100.0f;
    cpu->ecx = cpu->esi + 0x32Fu;
    *(float*)(cpu->esi + 0x54u) = x87_v2; 
    *(uint32_t*)(cpu->esi + 0x74u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x78u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x7Cu) = 0x280u;
    *(float*)(cpu->esi + 0x58u) = x87_v1;
    *(uint32_t*)(cpu->esi + 0x80u) = 0x1E0u;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ecx &= 0xFFFFFFF0u;
    *(float*)(cpu->esi + 0x6Cu) = x87_v1;
    *(float*)(cpu->esi + 0x70u) = (double)0.9999899864196777f;
    *(float*)(cpu->esi + 0x94u) = (double)0.75f;
    *(uint32_t*)(cpu->esi + 0x31Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x510u) = cpu->ecx;
    *(float*)(cpu->esi + 0x550u) = x87_v1;
    *(uint16_t*)(cpu->esi + 0x564u) = cpu->ebx & 0xFFFFu;
    *(float*)(cpu->esi + 0x554u) = x87_v1; 
    *(uint8_t*)(cpu->esi + 0x566u) = cpu->ebx & 0xFFu;
    *(float*)(cpu->esi + 0x558u) = x87_v0;
    *(float*)(cpu->esi + 0x55Cu) = x87_v0;
    *(float*)(cpu->esi + 0x560u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = ((((double)*(float*)(cpu->esi + 0x58u))) * (0.5));
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = std::tan(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esi + 0x514u) = cpu->ebx;
    *(float*)(cpu->esi + 0x98u) = x87_v0; 
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esi + 0x51Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x524u) = cpu->eax;
    cpu->eax = 3u;
    cpu->edx = 4u;
    cpu->ecx = 2u;
    *(uint32_t*)(cpu->esi + 0x534u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x53Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x548u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x520u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x52Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x538u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x88u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x8Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x518u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x528u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x530u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x540u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x544u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x54Cu) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F5C80:
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    goto label_0004B620;
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
__declspec(noinline) void sfera_sub_004F5DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_client_config_runtime.object_01[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5DBAu)); sfera_sub_0048A1A0(cpu, LIFT_CODE_TOKEN_VA(0x4F5DBAu));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA460) ? 0u : 0xFFFFFFFFu;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B9DEu)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x49B9DEu));
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
__declspec(noinline) void sfera_sub_004F5DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5DF1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F5DF1u));
    lift_push32(cpu, 0x9C40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_light_ids.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F5DFEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_light_ids.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F5E1Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F5E1Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F5E22u));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[15]) = 0u;
    g_sfera_light_runtime.cell_light_ids.debug_line = 0x16Cu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA590) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_004F6320(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x54F60u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6331u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6331u));
    lift_push32(cpu, 0x54F60u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.scene_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F633Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.scene_records.capacity = 0xBB8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F635Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F635Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6362u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.scene_records.debug_line = 0x1E3u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA710) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xF0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F63A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F63A1u));
    lift_push32(cpu, 0xF0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.reflection_targets.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F63AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.reflection_targets.capacity = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F63CCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F63CCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F63D2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.reflection_targets.debug_line = 0x236u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA730) ? 0u : 0xFFFFFFFFu;
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
__declspec(noinline) void sfera_sub_004F6950(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x240u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6961u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6961u));
    lift_push32(cpu, 0x240u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F696Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_indices.capacity = 0x90u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F698Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F698Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6992u));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[15]) = 0u;
    g_sfera_light_runtime.cell_indices.debug_line = 0x1247u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA850) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F69C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3600u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F69D1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F69D1u));
    lift_push32(cpu, 0x3600u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_light_runtime.cell_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F69DEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_light_runtime.cell_records.capacity = 0x90u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F69FCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F69FCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6A02u));
    *(uint8_t*)((uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[15]) = 0u;
    g_sfera_light_runtime.cell_records.debug_line = 0x1248u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA870) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6A30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6A41u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6A41u));
    lift_push32(cpu, 0x9C40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_landscape_runtime.microtexture_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6A4Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_runtime.microtexture_handles.capacity = 0x2710u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6A6Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6A6Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6A72u));
    *(uint8_t*)((uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[15]) = 0u;
    g_sfera_landscape_runtime.microtexture_handles.debug_line = 0x124Au;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA890) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6AA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x1F40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6AB1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6AB1u));
    lift_push32(cpu, 0x1F40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6ABEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_handles.capacity = 0x7D0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6ADCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6ADCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6AE2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_handles.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.surface_handles.debug_line = 0x124Bu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA8B0) ? 0u : 0xFFFFFFFFu;
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
__declspec(noinline) void sfera_sub_004F6C80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x61A80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6C91u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6C91u));
    lift_push32(cpu, 0x61A80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6C9Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_records.capacity = 0x2710u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6CBCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6CBCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6CC2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_records.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.surface_records.debug_line = 0x1264u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA930) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x13880u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D01u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6D01u));
    lift_push32(cpu, 0x13880u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.surface_index_map.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6D0Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.surface_index_map.capacity = 0x9C40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6D2Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6D2Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6D32u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.surface_index_map.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.surface_index_map.debug_line = 0x1266u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA950) ? 0u : 0xFFFFFFFFu;
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
__declspec(noinline) void sfera_sub_004F6EB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x3E8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6EC1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F6EC1u));
    lift_push32(cpu, 0x3E8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_mesh_partition_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6ECEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_mesh_partition_indices.capacity = 0x1F4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6EECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F6EECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mesh_partition_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6EF2u));
    g_sfera_mesh_partition_indices.debug_file[15] = '\0';
    g_sfera_mesh_partition_indices.debug_line = 0x1392u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA9D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F6F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6F2Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F6F2Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000F6F6D;
    g_sfera_model_registry_runtime.sentinel = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    *(uint8_t*)(cpu->ecx + 0x2Cu) = cpu->eax & 0xFFu;
    cpu->edx = g_sfera_model_registry_runtime.sentinel;
    *(uint8_t*)(cpu->edx + 0x2Du) = cpu->eax & 0xFFu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAC90) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F6F6D:
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F6F9Au)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F6F9Au));
    cpu->eip = 0x4F6F9Au; ::DebugBreak(); return;
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
__declspec(noinline) void sfera_sub_004F74E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xFA0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F74F1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F74F1u));
    lift_push32(cpu, 0xFA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_ranges.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F74FEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_ranges.capacity = 0x1F4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F751Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F751Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7522u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.render_ranges.debug_line = 0x3C0Du;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAB70) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7550(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x9C400u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7561u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7561u));
    lift_push32(cpu, 0x9C400u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_work_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F756Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_work_records.capacity = 0x4E20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F758Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F758Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7592u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.render_work_records.debug_line = 0x3C0Fu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAB90) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F75C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x168u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F75D1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F75D1u));
    lift_push32(cpu, 0x168u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.type_records.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F75DEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.type_records.capacity = 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F75FCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F75FCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7602u));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[15]) = 0u;
    g_sfera_grass_runtime.type_records.debug_line = 0x4409u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FABB0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7630(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xBB80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7641u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7641u));
    lift_push32(cpu, 0xBB80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.instance_offsets.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F764Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.instance_offsets.capacity = 0x2EE0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F766Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F766Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7672u));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[15]) = 0u;
    g_sfera_grass_runtime.instance_offsets.debug_line = 0x440Au;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FABD0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F76A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xBB80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F76B1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F76B1u));
    lift_push32(cpu, 0xBB80u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.instance_indices.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F76BEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.instance_indices.capacity = 0x2EE0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F76DCu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F76DCu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F76E2u));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[15]) = 0u;
    g_sfera_grass_runtime.instance_indices.debug_line = 0x440Bu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FABF0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7710(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0xC8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7721u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F7721u));
    lift_push32(cpu, 0xC8u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_grass_runtime.model_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F772Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_grass_runtime.model_handles.capacity = 0x32u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F774Cu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F774Cu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F7752u));
    *(uint8_t*)((uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[15]) = 0u;
    g_sfera_grass_runtime.model_handles.debug_line = 0x440Cu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAC10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[5u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[5u].transform;
    g_sfera_spatial_states[5u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7797u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7797u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FACF0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F77B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[5u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F77E9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F77E9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F77F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[6u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[6u].transform;
    g_sfera_spatial_states[6u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7807u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7807u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD00) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7820(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[6u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7859u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7859u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[7u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[7u].transform;
    g_sfera_spatial_states[7u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7877u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7877u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7890(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[7u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F78C9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F78C9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F78D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[8u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[8u].transform;
    g_sfera_spatial_states[8u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F78E7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F78E7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD20) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7900(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[8u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7939u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7939u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[9u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[9u].transform;
    g_sfera_spatial_states[9u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7957u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7957u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD30) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7970(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[9u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F79A9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F79A9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F79B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[10u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[10u].transform;
    g_sfera_spatial_states[10u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F79C7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F79C7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD40) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F79E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[10u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7A19u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7A19u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7A20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[11u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[11u].transform;
    g_sfera_spatial_states[11u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7A37u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7A37u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD50) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7A50(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[11u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7A89u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7A89u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[12u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[12u].transform;
    g_sfera_spatial_states[12u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7AA7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7AA7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD60) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7AC0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[12u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7AF9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7AF9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[13u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[13u].transform;
    g_sfera_spatial_states[13u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B17u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7B17u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD70) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7B30(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[13u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B69u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7B69u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[14u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[14u].transform;
    g_sfera_spatial_states[14u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7B87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7B87u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD80) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7BA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[14u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7BD9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7BD9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAD90) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_shadow_object_storage[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_shadow_runtime.aligned_global_object;
    g_sfera_shadow_runtime.aligned_global_object = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7C07u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7C07u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FADA0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7C20(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_shadow_object_storage[0x60];
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7C59u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7C59u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[15u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[15u].transform;
    g_sfera_spatial_states[15u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7CB7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7CB7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAE10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7CD0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[15u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D09u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7D09u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[16u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[16u].transform;
    g_sfera_spatial_states[16u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D27u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7D27u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAE20) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7D40(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[16u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D79u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7D79u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[17u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[17u].transform;
    g_sfera_spatial_states[17u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7D97u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7D97u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAE30) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7DB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[17u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7DE9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7DE9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAE40) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[18u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[18u].transform;
    g_sfera_spatial_states[18u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E17u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7E17u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAEC0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7E30(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[18u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E69u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7E69u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[19u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[19u].transform;
    g_sfera_spatial_states[19u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7E87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7E87u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAED0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7EA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[19u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7ED9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7ED9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7EE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAEE0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[20u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[20u].transform;
    g_sfera_spatial_states[20u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F07u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7F07u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAF20) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7F20(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[20u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F59u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7F59u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[21u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[21u].transform;
    g_sfera_spatial_states[21u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7F77u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7F77u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAF30) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7F90(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[21u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7FC9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F7FC9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[22u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[22u].transform;
    g_sfera_spatial_states[22u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F7FE7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F7FE7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAF40) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8000(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[22u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8039u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8039u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[23u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[23u].transform;
    g_sfera_spatial_states[23u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8057u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8057u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAF50) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8070(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[23u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F80A9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F80A9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F80B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x190u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F80C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4F80C1u));
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_weather_runtime.sky_texture_handles.data = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F80CEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\WeatherManager.cpp";
    g_sfera_weather_runtime.sky_texture_handles.capacity = 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F80ECu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x4F80ECu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F80F2u));
    *(uint8_t*)((uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[15]) = 0u;
    g_sfera_weather_runtime.sky_texture_handles.debug_line = 0x157u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAF60) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[24u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[24u].transform;
    g_sfera_spatial_states[24u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8137u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8137u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAF80) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8150(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[24u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8189u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8189u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[25u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[25u].transform;
    g_sfera_spatial_states[25u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F81A7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F81A7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAF90) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F81C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[25u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F81F9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F81F9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[26u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[26u].transform;
    g_sfera_spatial_states[26u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8257u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8257u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB000) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8270(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[26u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F82A9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F82A9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F82B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F82D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F82F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[27u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[27u].transform;
    g_sfera_spatial_states[27u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8307u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8307u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB070) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8320(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[27u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8359u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8359u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[28u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[28u].transform;
    g_sfera_spatial_states[28u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8377u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8377u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB080) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8390(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[28u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F83C9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F83C9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F83D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F83F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[29u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[29u].transform;
    g_sfera_spatial_states[29u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8427u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8427u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB0F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8440(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[29u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8479u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8479u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F84A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F84C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[30u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[30u].transform;
    g_sfera_spatial_states[30u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F84D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F84D7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB160) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F84F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[30u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8529u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8529u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[31u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[31u].transform;
    g_sfera_spatial_states[31u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8587u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8587u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB1D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F85A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[31u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F85D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F85D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F85E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB1E0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F85F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[32u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[32u].transform;
    g_sfera_spatial_states[32u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8607u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8607u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB220) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8620(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[32u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8659u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8659u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F86A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[33u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[33u].transform;
    g_sfera_spatial_states[33u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F86B7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F86B7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB290) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F86D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[33u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8709u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8709u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[34u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[34u].transform;
    g_sfera_spatial_states[34u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8727u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8727u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB2A0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8740(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[34u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8779u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8779u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F87A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F87C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[35u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[35u].transform;
    g_sfera_spatial_states[35u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F87D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F87D7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB310) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F87F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[35u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8829u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8829u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[36u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[36u].transform;
    g_sfera_spatial_states[36u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8887u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8887u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB380) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F88A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[36u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F88D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F88D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F88E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[37u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[37u].transform;
    g_sfera_spatial_states[37u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8937u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8937u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB3F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8950(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[37u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8989u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8989u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F89B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F89D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[38u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[38u].transform;
    g_sfera_spatial_states[38u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F89E7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F89E7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB460) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8A00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[38u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8A39u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8A39u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_interface_core_runtime.lookup_object[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_12;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_12) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8A97u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8A97u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB4D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8AB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.manager_object[0];
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8AE9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8AE9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8B3Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8B3Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000F8B61;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB540) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8B61:
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8B8Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8B8Eu));
    cpu->eip = 0x4F8B8Eu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004F8B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8B9Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8B9Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000F8BC1;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB590) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8BC1:
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8BEEu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8BEEu));
    cpu->eip = 0x4F8BEEu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004F8BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8BFAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8BFAu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000F8C21;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB5E0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8C21:
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8C4Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8C4Eu));
    cpu->eip = 0x4F8C4Eu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004F8C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB680) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8C60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->esi = 0u;
    lift_push32(cpu, 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8C91u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8C91u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->esi) goto label_000F8CE7;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head;
    *(uint32_t*)(cpu->eax) = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state) = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin) = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = cpu->esi;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB630) ? 0u : 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8CE7:
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D11u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8D11u));
    cpu->eip = 0x4F8D11u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004F8D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D2Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F8D2Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000F8D51;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB660) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F8D51:
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D7Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F8D7Eu));
    cpu->eip = 0x4F8D7Eu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004F8D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8D8Au)); sfera_sub_004CFE70(cpu, LIFT_CODE_TOKEN_VA(0x4F8D8Au));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB6D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[39u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[39u].transform;
    g_sfera_spatial_states[39u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8DB7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8DB7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB6E0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8DD0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[39u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8E09u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8E09u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[40u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[40u].transform;
    g_sfera_spatial_states[40u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8E67u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8E67u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB750) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8E80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[40u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8EB9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8EB9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[41u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[41u].transform;
    g_sfera_spatial_states[41u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8ED7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8ED7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB760) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8EF0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[41u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8F29u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8F29u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[42u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[42u].transform;
    g_sfera_spatial_states[42u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8F87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F8F87u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB7D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F8FA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[42u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F8FD9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F8FD9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[43u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[43u].transform;
    g_sfera_spatial_states[43u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9097u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9097u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB8D0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F90B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[43u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F90E9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F90E9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F90F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[44u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[44u].transform;
    g_sfera_spatial_states[44u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9147u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9147u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB940) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9160(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[44u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9199u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9199u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F91A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F91C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F91E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[45u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[45u].transform;
    g_sfera_spatial_states[45u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F91F7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F91F7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB9B0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9210(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[45u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9249u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9249u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[46u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[46u].transform;
    g_sfera_spatial_states[46u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9267u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9267u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FB9C0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9280(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[46u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F92B9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F92B9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F92C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F92E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[47u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[47u].transform;
    g_sfera_spatial_states[47u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9317u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9317u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBA30) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9330(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[47u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9369u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9369u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F93B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[48u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[48u].transform;
    g_sfera_spatial_states[48u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F93C7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F93C7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBAA0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F93E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[48u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9419u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9419u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[49u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[49u].transform;
    g_sfera_spatial_states[49u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9477u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9477u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBB10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9490(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[49u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F94C9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F94C9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F94D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F94F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[50u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[50u].transform;
    g_sfera_spatial_states[50u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9527u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9527u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBB80) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9540(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[50u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9579u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9579u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F95A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F95C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[51u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[51u].transform;
    g_sfera_spatial_states[51u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F95D7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F95D7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBBF0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F95F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[51u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9629u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9629u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_options_dialog_object_storage[0];
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_runtime.aligned_storage_token;
    g_sfera_options_dialog_runtime.aligned_storage_token = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9687u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9687u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBC60) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F96A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_options_dialog_object_storage[0x60];
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F96D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F96D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F96E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBD50) ? 0u : 0xFFFFFFFFu;
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
__declspec(noinline) void sfera_sub_004F9750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[52u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[52u].transform;
    g_sfera_spatial_states[52u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9767u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9767u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBD90) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9780(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[52u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F97B9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F97B9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F97C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F97E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[53u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[53u].transform;
    g_sfera_spatial_states[53u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9817u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9817u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBE00) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9830(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[53u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9869u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9869u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[54u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[54u].transform;
    g_sfera_spatial_states[54u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9887u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9887u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBE10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F98A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[54u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F98D9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F98D9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F98E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[55u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[55u].transform;
    g_sfera_spatial_states[55u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9937u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9937u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBE80) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9950(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[55u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9989u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9989u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F99B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F99D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[56u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[56u].transform;
    g_sfera_spatial_states[56u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F99E7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F99E7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBEF0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9A00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[56u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9A39u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9A39u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[57u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[57u].transform;
    g_sfera_spatial_states[57u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9A97u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9A97u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBF60) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9AB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[57u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9AE9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9AE9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9AFAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4F9AFAu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000F9B21;
    g_sfera_win32_dialog_registry.sentinel = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = g_sfera_win32_dialog_registry.sentinel;
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBF70) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000F9B21:
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9B4Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4F9B4Eu));
    cpu->eip = 0x4F9B4Eu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004F9B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[58u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[58u].transform;
    g_sfera_spatial_states[58u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9B67u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9B67u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBFC0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9B80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[58u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9BB9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9BB9u));
    cpu->esp += 0x18u;
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
__declspec(noinline) void sfera_sub_004F9C20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[59u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[59u].transform;
    g_sfera_spatial_states[59u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C37u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9C37u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC0A0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9C50(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[59u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C89u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9C89u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[60u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[60u].transform;
    g_sfera_spatial_states[60u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9CA7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9CA7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC0B0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9CC0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[60u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9CF9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9CF9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[61u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[61u].transform;
    g_sfera_spatial_states[61u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D17u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9D17u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC0C0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9D30(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[61u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D69u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9D69u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[62u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[62u].transform;
    g_sfera_spatial_states[62u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9D87u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9D87u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC0E0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9DA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[62u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9DD9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9DD9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[63u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[63u].transform;
    g_sfera_spatial_states[63u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9DF7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9DF7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC0F0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9E10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[63u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9E49u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9E49u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[64u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[64u].transform;
    g_sfera_spatial_states[64u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9E67u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9E67u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC100) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9E80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[64u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9EB9u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9EB9u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[65u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[65u].transform;
    g_sfera_spatial_states[65u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9ED7u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9ED7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC110) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9EF0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[65u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9F29u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9F29u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_spatial_states[66u].transform.matrix;
    cpu->eax &= 0xFFFFFFF0u;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[66u].transform;
    g_sfera_spatial_states[66u].transform.matrix_address = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9F47u)); sfera_sub_00401150(cpu, LIFT_CODE_TOKEN_VA(0x4F9F47u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC120) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9F60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x18u;
    x87_v0 = (double)-3.4028234663852886e+38f;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->ecx = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)3.4028234663852886e+38f;
    cpu->ecx = (uintptr_t)&g_sfera_spatial_states[66u].bounds;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9F99u)); sfera_sub_00401250(cpu, LIFT_CODE_TOKEN_VA(0x4F9F99u));
    cpu->esp += 0x18u;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA1C4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FA1C4u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA23Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FA23Du));
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
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if (sub_pred[0]) goto label_0002E677;
    cpu->edx = 0x65u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E66Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E66Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E674u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E674u));
    cpu->esp += 4u;
    label_0002E677:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E67Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E67Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6AAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E6AAu));
    cpu->esp += 4u;
    label_0002E6AD:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA270:
    cpu->ecx = (uintptr_t)&g_sfera_error_log_runtime.object[0];
    goto label_0002E630;
}
__declspec(noinline) void sfera_sub_004FA280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA292u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA292u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA2A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA2B2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA2B2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA360(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA360;
    label_000D7AB0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x13u;
    cpu->ecx = (uintptr_t)"CursorManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7AC2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7AC2u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_000D7AD0;
    lift_push32(cpu, 1u);
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    label_000D7AD0:
    cpu->edx = 0x14u;
    cpu->ecx = (uintptr_t)"CursorManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7ADFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4D7ADFu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esi = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_000D7AEF;
    lift_push32(cpu, 1u);
    reinterpret_cast<CCursor*>(cpu->ecx)->destroy(cpu);
    label_000D7AEF:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA360:
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    goto label_000D7AB0;
}
__declspec(noinline) void sfera_sub_004FA3D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_004FA440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA460(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FA460;
    label_0008A1B0:
    if (*(uint32_t*)(cpu->ecx) == 0u) goto label_0008A1BF;
    cpu->ecx = (uintptr_t)"CReadPathManager::~CReadPathManager: object not deinitialized";
    sfera_sub_00459B10(cpu, stop_address); return;
    label_0008A1BF:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA460:
    cpu->ecx = (uintptr_t)&g_sfera_client_config_runtime.object_01[0];
    goto label_0008A1B0;
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
__declspec(noinline) void sfera_sub_004FA590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA5A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA5A2u));
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
__declspec(noinline) void sfera_sub_004FA710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA722u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA722u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA742u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA742u));
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
__declspec(noinline) void sfera_sub_004FA850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA862u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA862u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_light_runtime.cell_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA882u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA882u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_landscape_runtime.microtexture_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA8A2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA8A2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA8B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.surface_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA8C2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA8C2u));
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
__declspec(noinline) void sfera_sub_004FA930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.surface_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA942u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA942u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.surface_index_map.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA962u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA962u));
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
__declspec(noinline) void sfera_sub_004FA9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mesh_partition_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FA9E2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FA9E2u));
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
__declspec(noinline) void sfera_sub_004FAB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.render_ranges.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAB82u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAB82u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAB90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FABA2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FABA2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FABB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.type_records.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FABC2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FABC2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FABD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.instance_offsets.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FABE2u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FABE2u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FABF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.instance_indices.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAC02u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAC02u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAC10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_grass_runtime.model_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAC22u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAC22u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAC90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_model_registry_runtime;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FACD1u)); sfera_sub_0040D400(cpu, LIFT_CODE_TOKEN_VA(0x4FACD1u));
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FACDDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FACDDu));
    cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FACF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_server_wall;
    sfera_sub_0048A6A0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004FADA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAE30(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAE94u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FAE94u));
    cpu->esp += 4u;
    label_000FAE97:
    g_sfera_sound_effect_items.block_vector_begin = cpu->esi;
    g_sfera_sound_effect_items.block_vector_end = cpu->esi;
    g_sfera_sound_effect_items.block_vector_capacity_end = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAEC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAEE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (g_sfera_sound_runtime.tracks.first == cpu->esi) goto label_000FAF0F;
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_000FAEF0:
    if (cpu->eax == cpu->esi) goto label_000FAF07;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_sound_runtime.tracks;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAF02u)); sfera_sub_00498C30(cpu, LIFT_CODE_TOKEN_VA(0x4FAF02u));
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_000FAF07:
    if (g_sfera_sound_runtime.tracks.first != cpu->esi) goto label_000FAEF0;
    label_000FAF0F:
    g_sfera_sound_runtime.tracks.last = cpu->esi;
    g_sfera_sound_runtime.tracks.first = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAF50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_weather_runtime.sky_texture_handles.data;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FAF72u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4FAF72u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAF80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB1E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_font_factory_runtime.fonts_begin;
    if (cpu->eax == 0u) goto label_000FB1F2;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB1EFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB1EFu));
    cpu->esp += 4u;
    label_000FB1F2:
    g_sfera_font_factory_runtime.fonts_begin = 0u;
    g_sfera_font_factory_runtime.fonts_end = 0u;
    g_sfera_font_factory_runtime.fonts_capacity = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB2A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB3F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor) = 0u;
    if (cpu->eax == cpu->ecx) goto label_000FB580;
    lift_push32(cpu, cpu->esi);
    label_000FB568:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB570u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB570u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if (cpu->esi != cpu->ecx) goto label_000FB568;
    cpu->esi = lift_pop32(cpu);
    label_000FB580:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB586u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB586u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor) = 0u;
    if (cpu->eax == cpu->ecx) goto label_000FB5D0;
    lift_push32(cpu, cpu->esi);
    label_000FB5B8:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB5C0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB5C0u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if (cpu->esi != cpu->ecx) goto label_000FB5B8;
    cpu->esi = lift_pop32(cpu);
    label_000FB5D0:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB5D6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB5D6u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count) = 0u;
    if (cpu->eax == cpu->ecx) goto label_000FB620;
    lift_push32(cpu, cpu->esi);
    label_000FB608:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB610u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB610u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if (cpu->esi != cpu->ecx) goto label_000FB608;
    cpu->esi = lift_pop32(cpu);
    label_000FB620:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB626u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB626u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB63Au)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4FB63Au));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB645u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB645u));
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_head) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB66Au)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x4FB66Au));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB675u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB675u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    if (cpu->ecx == 0u) goto label_000FB6AE;
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_core_runtime.object_aux);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB69Fu)); sfera_sub_004BC000(cpu, LIFT_CODE_TOKEN_VA(0x4FB69Fu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FB6ABu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FB6ABu));
    cpu->esp += 4u;
    label_000FB6AE:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head) = 0u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count) = 0u;
    g_sfera_interface_core_runtime.object_state = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    sfera_sub_004BC9F0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004FB6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FB9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBAA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    if (cpu->eax == 0u) goto label_000FBCE2;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBCDFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBCDFu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBD1Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBD1Fu));
    cpu->esp += 4u;
    label_000FBD22:
    g_sfera_options_dialog_runtime.chat_list_fonts.begin = 0u;
    g_sfera_options_dialog_runtime.chat_list_fonts.end = 0u;
    g_sfera_options_dialog_runtime.chat_list_fonts.capacity_end = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBD50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.graphics_modes.begin;
    if (cpu->eax == 0u) goto label_000FBD62;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBD5Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBD5Fu));
    cpu->esp += 4u;
    label_000FBD62:
    g_sfera_options_dialog_runtime.graphics_modes.begin = 0u;
    g_sfera_options_dialog_runtime.graphics_modes.end = 0u;
    *(uint32_t*)((uintptr_t)&g_sfera_options_dialog_cleanup_state) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBD90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBF60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    g_sfera_win32_dialog_registry.size = 0u;
    if (cpu->eax == cpu->ecx) goto label_000FBFB0;
    lift_push32(cpu, cpu->esi);
    label_000FBF98:
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBFA0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBFA0u));
    cpu->ecx = g_sfera_win32_dialog_registry.sentinel;
    cpu->esp += 4u;
    cpu->eax = cpu->esi;
    if (cpu->esi != cpu->ecx) goto label_000FBF98;
    cpu->esi = lift_pop32(cpu);
    label_000FBFB0:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FBFB6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FBFB6u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FBFC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC030(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = g_sfera_control_reference_registry.sentinel;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_control_reference_registry;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FC071u)); sfera_sub_004B2C40(cpu, LIFT_CODE_TOKEN_VA(0x4FC071u));
    cpu->ecx = g_sfera_control_reference_registry.sentinel;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4FC07Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4FC07Du));
    cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::SetUnhandledExceptionFilter(reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(static_cast<uintptr_t>(g_sfera_crash_report_runtime.previous_exception_filter)))));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC0D0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_000FC0D0;
    label_000D78B0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000D793C;
    cpu->ebx = native_function_address32(&::DestroyCursor);
    label_000D78F0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::DestroyCursor)))(cpu->eax);
    if (*(uint8_t*)(cpu->esi + 0x35u) != 0u) goto label_000D7937;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x35u) != 0u) goto label_000D791C;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->eax + 0x35u) != 0u) goto label_000D7937;
    (void)cpu;
    label_000D7910:
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->eax + 0x35u) == 0u) goto label_000D7910;
    goto label_000D7937;
    label_000D791C:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint8_t*)(cpu->eax + 0x35u) != 0u) goto label_000D7935;
    label_000D7925:
    if (cpu->esi != *(uint32_t*)(cpu->eax + 8u)) goto label_000D7935;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x35u) == 0u) goto label_000D7925;
    label_000D7935:
    cpu->esi = cpu->eax;
    label_000D7937:
    if (cpu->esi != *(uint32_t*)(cpu->edi + 4u)) goto label_000D78F0;
    label_000D793C:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7957u)); sfera_sub_004D77E0(cpu, LIFT_CODE_TOKEN_VA(0x4D7957u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4D7960u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4D7960u));
    cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FC0D0:
    cpu->ecx = (uintptr_t)&g_sfera_cursor_texture_registry;
    goto label_000D78B0;
}
__declspec(noinline) void sfera_sub_004FC0E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FC120(LiftCpu* cpu, uint32_t stop_address) {
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
