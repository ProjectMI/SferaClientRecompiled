#include "lifted_functions.h"
#include <cmath>
#include <cstddef>
namespace lifted {

static void sfera_prepare_msvc_string_storage(uint32_t address) { if (*(uint32_t*)(address + 0x10u) == 0u && *(uint32_t*)(address + 0x14u) == 0u) { *(uint8_t*)(address) = 0u; *(uint32_t*)(address + 0x14u) = 15u; } }
__declspec(noinline) void sfera_sub_004010F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"BoundCheckArray error: index less than zero\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4010FFu));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)g_sfera_array_error_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00401120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"BoundCheckArray error: index out of range %d\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x401130u));
    cpu->esp += 0x14u;
    cpu->ecx = (uintptr_t)g_sfera_array_error_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}

__declspec(noinline) void sfera_sub_004013B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00401990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    g_sfera_config_text_runtime.text_length = 0u;
    g_sfera_config_text_runtime.text_buffer = reinterpret_cast<char*>((uintptr_t)&g_sfera_config_text_runtime.text_storage[0]);
    g_sfera_config_text_runtime.text_storage[0] = 0u;
    cpu->edx -= cpu->eax;
    label_000019B8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000019B8;
    cpu->edi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_config_text_runtime.text_buffer));
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4019D0u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00001AA0;
    lift_push32(cpu, 0x25823Fu); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4019EBu));
    lift_push32(cpu, cpu->esi);
    g_sfera_config_text_runtime.text_length = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4019F7u));
    cpu->edx = g_sfera_config_text_runtime.text_length;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_config_text_runtime.text_buffer));
    cpu->esp += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A11u)); sfera_sub_0047E850(cpu, LIFT_CODE_TOKEN_VA(0x401A11u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00001AA8;
    cpu->edx = 0xC6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    *(uint32_t*)(cpu->esp + 0x10u) = 0x25823Fu;
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_config_text_runtime.text_buffer));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401A59u)); sfera_sub_0047E870(cpu, LIFT_CODE_TOKEN_VA(0x401A59u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00001A78;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    g_sfera_config_text_runtime.text_length = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_config_text_runtime.text_buffer));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x401A70u));
    cpu->esp += 0xCu;
    label_00001A78:
    cpu->edx = 0xCFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    if (cpu->edi == 0u) goto label_00001AA8;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->ebp;
    g_sfera_config_text_runtime.clear(reinterpret_cast<char*>(cpu->ecx), reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    label_00001AA0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001AA8:
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_config_text_runtime.text_buffer));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->edx + cpu->ecx) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401AC0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint8_t*)(cpu->edi) != 0u) goto label_00001AD0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001AD0:
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0xCu) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xCu) = 0x25823Fu;
    if (sub_pred[0]) goto label_00001B02;
    cpu->edx = 0xE3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    cpu->esi = cpu->eax;
    goto label_00001B04;
    label_00001B02:
    cpu->esi = 0u;
    label_00001B04:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (*(uint8_t*)(cpu->esp + 0x14u) != (cpu->ebx & 0xFFu)) goto label_00001B1C;
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_config_text_runtime.text_buffer));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    goto label_00001B3E;
    label_00001B1C:
    cpu->eax = g_sfera_config_text_runtime.text_length;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_config_text_runtime.text_buffer));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401B34u)); sfera_sub_0047E900(cpu, LIFT_CODE_TOKEN_VA(0x401B34u));
    if (cpu->eax != 0u) goto label_00001B47;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    label_00001B3E:
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(SferaConfigTextRuntime::writeFile(reinterpret_cast<const char*>(cpu->ecx), reinterpret_cast<const void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    label_00001B47:
    cpu->edx = 0xEBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ebx & 0xFFu) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00402810(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax >= cpu->ecx) goto label_00002829;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402810u); throw std::out_of_range("std::out_of_range");
    label_00002829:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax -= cpu->ecx;
    if (cpu->eax >= cpu->edi) goto label_00002836;
    cpu->edi = cpu->eax;
    label_00002836:
    if (cpu->edi == 0u) goto label_0000288A;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ebx);
    if (cpu->edx < 0x10u) goto label_00002847;
    cpu->ebx = *(uint32_t*)(cpu->esi);
    goto label_00002849;
    label_00002847:
    cpu->ebx = cpu->esi;
    label_00002849:
    if (cpu->edx < 0x10u) goto label_00002852;
    cpu->edx = *(uint32_t*)(cpu->esi);
    goto label_00002854;
    label_00002852:
    cpu->edx = cpu->esi;
    label_00002854:
    cpu->eax -= cpu->edi;
    cpu->ebx += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ebx += cpu->edi;
    cpu->edx += cpu->ecx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40285Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esp += 0xCu;
    cpu->eax -= cpu->edi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00002884;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->ecx + cpu->eax) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00002884:
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->ecx + cpu->eax) = 0u;
    label_0000288A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004028A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_000028ED;
    if (cpu->ecx > 0xFFFFFFFFu) goto label_000028BF;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000028ED;
    label_000028BF:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x28EDu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x28EDu));
    label_000028ED:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00403230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->eax;
    cpu->esi |= 0xFu;
    if (cpu->esi <= 0xFFFFFFFEu) goto label_00003271;
    cpu->esi = cpu->eax;
    goto label_00003298;
    label_00003271:
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->edx = (uint32_t)(((uint64_t)0xAAAAAAABu * (uint32_t)(cpu->esi)) >> 32u);
    cpu->ecx = cpu->ebx;
    cpu->ecx >>= 1u;
    cpu->edx >>= 1u;
    if (cpu->ecx <= cpu->edx) goto label_00003298;
    cpu->eax = 0xFFFFFFFEu;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx + cpu->ebx;
    if (cpu->ebx <= cpu->eax) goto label_00003298;
    cpu->esi = 0xFFFFFFFEu;
    label_00003298:
    cpu->eax = 0u;
    cpu->ecx = cpu->esi + 1u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    if (cpu->ecx <= cpu->eax) goto label_000032B6;
    if (cpu->ecx > 0xFFFFFFFFu) goto label_000032BB;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000032BB;
    label_000032B6:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    goto label_0000330D;
    label_000032BB:
    cpu->ecx = cpu->ebp + 0xFFFFFFE8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x32E4u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x32E4u));
    sfera_sub_004032E4(cpu, stop_address); return;
    label_0000330D:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->ebx == 0u) goto label_0000332E;
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000331E;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00003320;
    label_0000331E:
    cpu->eax = cpu->edi;
    label_00003320:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403326u));
    cpu->esp += 0xCu;
    label_0000332E:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000333F;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000333F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint8_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    if (cpu->esi < 0x10u) goto label_00003354;
    cpu->edi = cpu->eax;
    label_00003354:
    *(uint8_t*)(cpu->edi + cpu->ebx) = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004032E4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x18u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4032FEu)); sfera_sub_004028A0(cpu, LIFT_CODE_TOKEN_VA(0x4032FEu));
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    sfera_sub_00403307(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00403307(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->ebx == 0u) goto label_0000332E;
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000331E;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00003320;
    label_0000331E:
    cpu->eax = cpu->edi;
    label_00003320:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403326u));
    cpu->esp += 0xCu;
    label_0000332E:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0000333F;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000333F:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(uint8_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebx;
    if (cpu->esi < 0x10u) goto label_00003354;
    cpu->edi = cpu->eax;
    label_00003354:
    *(uint8_t*)(cpu->edi + cpu->ebx) = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00405210(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->esi = cpu->ecx;
    if (cpu->edi >= cpu->ebx) goto label_00005230;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405210u); throw std::out_of_range("std::out_of_range");
    label_00005230:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi -= cpu->ebx;
    if (cpu->eax >= cpu->edi) goto label_0000523C;
    cpu->edi = cpu->eax;
    label_0000523C:
    if (cpu->esi != cpu->ebp) goto label_0000525D;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->edi += cpu->ebx;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40524Au)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x40524Au));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405254u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x405254u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000525D:
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0000526D;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40525Du); throw std::length_error("std::length_error");
    label_0000526D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->edi) goto label_00005291;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40527Eu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x40527Eu));
    if (cpu->edi == 0u) goto label_000052EF;
    label_00005282:
    cpu->eax = 0x10u;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->eax) goto label_000052B7;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_000052B9;
    label_00005291:
    if (cpu->edi != 0u) goto label_00005282;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->eax < 0x10u) goto label_000052AB;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000052AB:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000052B7:
    cpu->ecx = cpu->ebp;
    label_000052B9:
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->eax) goto label_000052C2;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000052C4;
    label_000052C2:
    cpu->eax = cpu->esi;
    label_000052C4:
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4052C9u));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_000052E9;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000052E9:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_000052EF:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00406820(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sfera_prepare_msvc_string_storage(cpu->esi);
    if (cpu->ebx == 0u) goto label_00006885;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_00006838;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0000683A;
    label_00006838:
    cpu->eax = cpu->esi;
    label_0000683A:
    if (cpu->ebx < cpu->eax) goto label_00006885;
    if (cpu->ecx < 0x10u) goto label_00006847;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_00006849;
    label_00006847:
    cpu->eax = cpu->esi;
    label_00006849:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx += cpu->eax;
    if (cpu->edx <= cpu->ebx) goto label_00006885;
    if (cpu->ecx < 0x10u) goto label_0000686E;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406869u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x406869u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000686E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ebx -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406880u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x406880u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006885:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0000689A;
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406885u); throw std::length_error("std::length_error");
    label_0000689A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->edi) goto label_000068BB;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4068ADu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x4068ADu));
    if (cpu->edi == 0u) goto label_00006909;
    label_000068B1:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000068DF;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000068E1;
    label_000068BB:
    if (cpu->edi != 0u) goto label_000068B1;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->eax < 0x10u) goto label_000068D4;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000068D4:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000068DF:
    cpu->eax = cpu->esi;
    label_000068E1:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4068E4u));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_00006903;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006903:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_00006909:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

} // namespace lifted
