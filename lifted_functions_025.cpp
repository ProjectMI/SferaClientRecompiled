#include "lifted_functions.h"
#include <cmath>
namespace lifted {

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

__declspec(noinline) void sfera_sub_004F50E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA170) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F51D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ecx = (uintptr_t)&g_sfera_error_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F51DEu)); sfera_sub_0042E540(cpu, LIFT_CODE_TOKEN_VA(0x4F51DEu));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA270) ? 0u : 0xFFFFFFFFu;
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


__declspec(noinline) void sfera_sub_004F5890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x7D0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(reinterpret_cast<const char*>(cpu->ecx)));
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

__declspec(noinline) void sfera_sub_004F6470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x24u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x400u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F652Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_config_runtime.text_length_02 = 0x100u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0xB7980u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_124d_records.data = reinterpret_cast<decltype(g_sfera_client_array_runtime.line_124d_records.data)>(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6B2Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_124d_records.capacity = 0x7D0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x30u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.render_pass_slots.data = reinterpret_cast<decltype(g_sfera_scene_array_runtime.render_pass_slots.data)>(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6C2Bu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.render_pass_slots.capacity = 0xCu;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F6C4Fu));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.render_pass_slots.debug_line = 0x125Bu;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA910) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F6FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x23280u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x23280u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24de_records.data = reinterpret_cast<decltype(g_sfera_client_array_runtime.line_24de_records.data)>(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F6FBEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_24de_records.capacity = 0xFA0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x21D68u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e0_records.data = reinterpret_cast<decltype(g_sfera_client_array_runtime.line_24e0_records.data)>(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F702Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_24e0_records.capacity = 0x26ACu;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x7D00u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_client_array_runtime.line_24e2_records.data = reinterpret_cast<decltype(g_sfera_client_array_runtime.line_24e2_records.data)>(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F709Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_client_array_runtime.line_24e2_records.capacity = 0xFA0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F70C2u));
    *(uint8_t*)((uintptr_t)&g_sfera_client_array_runtime.line_24e2_records.debug_file[15]) = 0u;
    g_sfera_client_array_runtime.line_24e2_records.debug_line = 0x24E2u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAA30) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x27100u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x27100u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.cloud_records.data = reinterpret_cast<decltype(g_sfera_scene_array_runtime.cloud_records.data)>(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F73AEu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.cloud_records.capacity = 0x7D0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4F73D2u));
    *(uint8_t*)((uintptr_t)&g_sfera_scene_array_runtime.cloud_records.debug_file[15]) = 0u;
    g_sfera_scene_array_runtime.cloud_records.debug_line = 0x2A85u;
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FAB10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F7470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x40u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x4C5BDA0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x4C5BDA0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    g_sfera_scene_array_runtime.world_cell_records.data = reinterpret_cast<decltype(g_sfera_scene_array_runtime.world_cell_records.data)>(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4F748Eu));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_scene_array_runtime.world_cell_records.capacity = 0x1F4u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaStringLookupRuntime::fileName(reinterpret_cast<const char*>(cpu->ecx))));
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

__declspec(noinline) void sfera_sub_004F9730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBD10) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004F9740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FBCD0) ? 0u : 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004F9C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uintptr_t)&g_sfera_crash_report_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4F9C0Au)); sfera_sub_004D6720(cpu, LIFT_CODE_TOKEN_VA(0x4F9C0Au));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FC090) ? 0u : 0xFFFFFFFFu;
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
__declspec(noinline) void sfera_sub_004FA170(LiftCpu* cpu, uint32_t stop_address) { g_sfera_effect_items.clear(); cpu->esp += 4u; cpu->eip = stop_address; }

__declspec(noinline) void sfera_sub_004FA270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    goto label_000FA270;
    label_0002E630:
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 8u) == 0u) goto label_0002E681;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x104u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (cpu->esi == 0u) goto label_0002E680;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    reinterpret_cast<CSphereError*>(cpu->esi)->~CSphereError();
    if (sub_pred[0]) goto label_0002E677;
    cpu->edx = 0x65u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0002E677:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0002E680:
    cpu->esi = lift_pop32(cpu);
    label_0002E681:
    if (*(uint32_t*)(cpu->edi + 0xCu) == 0u) goto label_0002E6AD;
    cpu->edx = 0x105u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->edi = *(uint32_t*)(cpu->edi + 0xCu);
    if (cpu->edi == 0u) goto label_0002E6AD;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6A4u)); sfera_sub_0042E250(cpu, LIFT_CODE_TOKEN_VA(0x42E6A4u));
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0002E6AD:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000FA270:
    cpu->ecx = (uintptr_t)&g_sfera_error_log_runtime.object[0];
    goto label_0002E630;
}

__declspec(noinline) void sfera_sub_004FA470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.secondary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e7_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e8_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.e9_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA4F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.eb_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.ed_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_102_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_105_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FA770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_29;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_30;
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA7B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b1_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.primary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b3_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b4_indices.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_client_array_runtime.line_6b5_records.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FA8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_client_array_runtime.line_124d_records.data));
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA8F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_recovered_static_runtime.tertiary_auto_array.data;
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FA910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_scene_array_runtime.render_pass_slots.data));
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_004FA9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_client_array_runtime.line_24de_records.data));
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_client_array_runtime.line_24e0_records.data));
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_client_array_runtime.line_24e2_records.data));
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_scene_array_runtime.cloud_records.data));
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004FAB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_scene_array_runtime.world_cell_records.data));
    lift_push32(cpu, 0x4Bu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004FAE40(LiftCpu* cpu, uint32_t stop_address) { g_sfera_sound_effect_items.clear(); cpu->esp += 4u; cpu->eip = stop_address; }

__declspec(noinline) void sfera_sub_004FBCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_options_dialog_runtime.chat_edit_fonts.begin;
    if (cpu->eax == 0u) goto label_000FBCE2;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
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
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
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

__declspec(noinline) void sfera_sub_004FC15A(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_crt_startup_runtime.reserved_dynamic_tls_dtors = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
