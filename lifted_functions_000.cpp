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
__declspec(noinline) void sfera_sub_004013D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->eax <= 0) goto label_00001465;
    if (cpu->edi == 0u) goto label_0000142E;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = cpu->ecx + cpu->ebp;
    cpu->ebx = cpu->eax * 8u;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ebx) goto label_00001465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, (uintptr_t)" ERROR(1): putbitstream: bufer will overload: bitT = %d, count = %d, bufsize = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inter.h";
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x25Fu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401429u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x401429u));
    cpu->esp += 0x14u;
    goto label_00001465;
    label_0000142E:
    cpu->ecx = cpu->eax * 8u;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ecx) goto label_00001465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, (uintptr_t)" ERROR(2): putbitstream: bufer will overload: count = %d, bufsize = %d"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x24u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inter.h";
    *(uint32_t*)(cpu->esp + 0x28u) = 0x265u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401462u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x401462u));
    cpu->esp += 0x10u;
    label_00001465:
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if (cpu->edi == 0u) goto label_0000146F;
    cpu->edx = *(uint32_t*)(cpu->edi);
    label_0000146F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->eax==0u) goto label_00001479;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_00001479:
    cpu->eax = cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edi = cpu->eax * 8u;
    cpu->ecx -= cpu->edi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (((uint8_t)((cpu->ebx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = cpu->eax + cpu->ecx;
    cpu->eax = cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->ecx = cpu->eax * 8u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx -= cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->esi += cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_000014D5;
    cpu->eax = cpu->ebp;
    label_000014B6:
    if ((uint8_t)((*(uint8_t*)(cpu->edi)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_000014BE;
    *(uint8_t*)(cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->esi)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000014C4;
    label_000014BE:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->esi) = (uint64_t)(*(uint8_t*)(cpu->esi)) & (uint64_t)((cpu->ecx & 0xFFu));
    label_000014C4:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000014CB;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_000014CB:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ebx + cpu->ebx) & 0xFFu);
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000014D2;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edi;
    label_000014D2:
    if ((--cpu->eax) != 0u) goto label_000014B6;
    label_000014D5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax == 0u) goto label_000014DF;
    *(uint32_t*)(cpu->eax) = (uint64_t)(*(uint32_t*)(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    label_000014DF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->eax == 0u) goto label_000014E9;
    *(uint32_t*)(cpu->eax) = (uint64_t)(*(uint32_t*)(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    label_000014E9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    label_00001578:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001578;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401590(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi < 0x25823Fu) goto label_000015A5;
    cpu->esi = 0x25823Fu;
    label_000015A5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_config_text_runtime.owned_text[0]);
    g_sfera_config_text_runtime.current_text = (uintptr_t)&g_sfera_config_text_runtime.owned_text[0];
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4015BAu));
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    cpu->eax = (uintptr_t)"";
    cpu->edx = cpu->edi;
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->ecx + cpu->esi) = 0u;
    cpu->edx -= cpu->eax;
    label_000015D5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000015D5;
    cpu->edi = lift_pop32(cpu);
    g_sfera_config_text_runtime.text_length = cpu->esi;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004015F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_config_text_runtime.text_length;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
static uint32_t sfera_config_lookup(uint32_t key_address) {
    const uint32_t text_address = g_sfera_config_text_runtime.current_text;
    const uint32_t text_length = g_sfera_config_text_runtime.text_length;
    if (text_address == 0u || key_address == 0u) {
        return 0u;
    }
    std::size_t key_length = 0u;
    while (key_length != 4096u && *(uint8_t*)(key_address + static_cast<uint32_t>(key_length)) != 0u) {
        ++key_length;
    }
    if (key_length == 4096u) {
        return 0u;
    }
    const std::size_t bounded_length = text_length < 0x25823Fu ? text_length : 0x25823Fu;
    const std::size_t scan_limit = bounded_length + 1u;
    if (static_cast<uint64_t>(text_address) + scan_limit > 0x100000000ull) {
        return 0u;
    }
    std::size_t line = 0u;
    while (line < scan_limit) {
        std::size_t token_end = line;
        while (token_end < scan_limit) {
            const uint8_t value = *(uint8_t*)(text_address + static_cast<uint32_t>(token_end));
            if (value == ' ' || value == '\t' || value == '\r' || value == 0u) {
                break;
            }
            ++token_end;
        }
        bool matches = token_end - line == key_length;
        for (std::size_t index = 0u; matches && index != key_length; ++index) {
            matches = *(uint8_t*)(text_address + static_cast<uint32_t>(line + index)) == *(uint8_t*)(key_address + static_cast<uint32_t>(index));
        }
        if (matches) {
            std::size_t value = token_end;
            while (value < scan_limit) {
                const uint8_t current = *(uint8_t*)(text_address + static_cast<uint32_t>(value));
                if (current != ' ' && current != '\t') {
                    break;
                }
                ++value;
            }
            return value < scan_limit ? text_address + static_cast<uint32_t>(value) : 0u;
        }
        std::size_t next_line = token_end;
        while (next_line < scan_limit) {
            const uint8_t current = *(uint8_t*)(text_address + static_cast<uint32_t>(next_line));
            if (current == '\n' || current == 0u) {
                break;
            }
            ++next_line;
        }
        if (next_line == scan_limit || *(uint8_t*)(text_address + static_cast<uint32_t>(next_line)) == 0u) {
            return 0u;
        }
        line = next_line + 1u;
    }
    return 0u;
}
__declspec(noinline) void sfera_sub_00401600(LiftCpu* cpu, uint32_t stop_address) {
    static_cast<void>(stop_address);
    const uint32_t key_address = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = sfera_config_lookup(key_address);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x401689u));
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x40169Au));
    cpu->esi = cpu->eax;
    cpu->esp += 0x14u;
    if (cpu->esi != 0xFFFFFFFFu) goto label_000016B0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000016B0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4016BBu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4016C2u));
    cpu->esp += 0x10u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    g_sfera_config_text_runtime.text_length = 0u;
    g_sfera_config_text_runtime.current_text = (uintptr_t)&g_sfera_config_text_runtime.owned_text[0];
    g_sfera_config_text_runtime.owned_text[0] = 0u;
    cpu->edx -= cpu->eax;
    label_00001723:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001723;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    g_sfera_config_text_runtime.current_text = cpu->eax;
    cpu->edx = cpu->eax + 1u;
    lift_push32(cpu, cpu->ebx);
    label_00001740:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00001740;
    cpu->eax -= cpu->edx;
    g_sfera_config_text_runtime.text_length = cpu->eax;
    cpu->eax = (uintptr_t)"";
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_00001758:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001758;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40177Au)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x40177Au));
    if (cpu->eax != 0u) goto label_00001783;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00001783:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x40178Eu));
    cpu->esp += 0xCu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004017A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4017AAu)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x4017AAu));
    if (cpu->eax != 0u) goto label_000017B3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000017B3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4017BEu));
    cpu->esp += 0xCu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004017D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4017DAu)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x4017DAu));
    if (cpu->eax != 0u) goto label_000017E3;
    label_000017DE:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000017E3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0x22u) goto label_000017DE;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->esi == 0u) goto label_00001823;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    label_000017F8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ecx & 0xFFu) == 0x22u) goto label_0000181F;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0000181F;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) == 0xAu) goto label_00001815;
    if ((cpu->ecx & 0xFFu) == 0xDu) goto label_00001812;
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    goto label_00001815;
    label_00001812:
    *(uint8_t*)(cpu->edx) = 0x20u;
    label_00001815:
    ++cpu->edx;
    if ((--cpu->esi) != 0u) goto label_000017F8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000181F:
    if (cpu->esi != 0u) goto label_00001829;
    label_00001823:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00001829:
    *(uint8_t*)(cpu->edx) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40184Bu)); sfera_sub_00401600(cpu, LIFT_CODE_TOKEN_VA(0x40184Bu));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00001857;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00001857:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((cpu->edx & 0xFFu) == 0x23u) goto label_0000192F;
    label_00001870:
    if ((cpu->edx & 0xFFu) == 0u) goto label_0000192B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ebp = cpu->ecx + 6u;
    cpu->eax += cpu->eax;
    if (cpu->ebp > cpu->eax) goto label_00001979;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->edx + 0xFFFFFFD0u;
    cpu->esi = (int32_t)(cpu->esi) >> 3u;
    cpu->edx = cpu->esi * 8u;
    cpu->ecx -= cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->edi;
    cpu->ecx += cpu->esi;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000018B1;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018B7;
    label_000018B1:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018B7:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018BE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018BE:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_000018C6;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018CC;
    label_000018C6:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018CC:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018D3;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018D3:
    if ((((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000018DB;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018E1;
    label_000018DB:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018E1:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018E8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018E8:
    if ((((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_000018F0;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_000018F6;
    label_000018F0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000018F6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_000018FD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_000018FD:
    if ((((cpu->eax & 0xFFu)) & (0x10u)) == 0u) goto label_00001905;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_0000190B;
    label_00001905:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0000190B:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_00001912;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_00001912:
    if ((((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_0000191A;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu));
    goto label_0000191E;
    label_0000191A:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->edx & 0xFFu));
    label_0000191E:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->ecx = cpu->ebp;
    if ((cpu->edx & 0xFFu) != 0x23u) goto label_00001870;
    label_0000192B:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    label_0000192F:
    if (*(uint8_t*)(cpu->edi) != 0x23u) goto label_00001970;
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->edi + 1u));
    cpu->edx -= 0x30u;
    if ((int32_t)cpu->edx <= 0) goto label_00001970;
    cpu->eax = cpu->edx + cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    if (cpu->eax > cpu->ecx) goto label_0000197D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 2u));
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x28u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0x30u) - (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1970u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_RVA(0x1970u));
    label_00001970:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00001979:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    label_0000197D:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    g_sfera_config_text_runtime.text_length = 0u;
    g_sfera_config_text_runtime.current_text = (uintptr_t)&g_sfera_config_text_runtime.owned_text[0];
    g_sfera_config_text_runtime.owned_text[0] = 0u;
    cpu->edx -= cpu->eax;
    label_000019B8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000019B8;
    cpu->edi = g_sfera_config_text_runtime.current_text;
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
    cpu->ecx = g_sfera_config_text_runtime.current_text;
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
    cpu->edx = g_sfera_config_text_runtime.current_text;
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
    cpu->eax = g_sfera_config_text_runtime.current_text;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1AA0u)); sfera_sub_00401700(cpu, LIFT_CODE_TOKEN_RVA(0x1AA0u));
    label_00001AA0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001AA8:
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = g_sfera_config_text_runtime.current_text;
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
    cpu->edx = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    goto label_00001B3E;
    label_00001B1C:
    cpu->eax = g_sfera_config_text_runtime.text_length;
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401B34u)); sfera_sub_0047E900(cpu, LIFT_CODE_TOKEN_VA(0x401B34u));
    if (cpu->eax != 0u) goto label_00001B47;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    label_00001B3E:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401B45u)); sfera_sub_00401680(cpu, LIFT_CODE_TOKEN_VA(0x401B45u));
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
__declspec(noinline) void sfera_sub_00401B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_config_text_runtime.text_length;
    if (cpu->eax >= cpu->esi) goto label_00001B81;
    cpu->esi = cpu->eax;
    label_00001B81:
    cpu->eax = g_sfera_config_text_runtime.current_text;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x401B8Du));
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00401BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->esi < 4u) goto label_00001C07;
    label_00001BF3:
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_00001C0B;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if (cpu->esi >= 4u) goto label_00001BF3;
    label_00001C07:
    if (cpu->esi == 0u) goto label_00001C4F;
    label_00001C0B:
    cpu->eax = *(uint8_t*)(cpu->edx);
    cpu->edi = *(uint8_t*)(cpu->ecx);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001C46;
    if (cpu->esi <= 1u) goto label_00001C4F;
    cpu->eax = *(uint8_t*)(cpu->edx + 1u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 1u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001C46;
    if (cpu->esi <= 2u) goto label_00001C4F;
    cpu->eax = *(uint8_t*)(cpu->edx + 2u);
    cpu->edi = *(uint8_t*)(cpu->ecx + 2u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001C46;
    if (cpu->esi <= 3u) goto label_00001C4F;
    cpu->eax = *(uint8_t*)(cpu->edx + 3u);
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->eax -= cpu->ecx;
    label_00001C46:
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001C4F:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00401D30(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2];
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->esi != 0u) goto label_00001D4E;
    if (*(uint32_t*)(cpu->edi + 4u) != 0u) goto label_00001D4E;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001D4E:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((cpu->edx==0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((cpu->esi==0u)) ? 1u : 0u) & 0xFFu);
    if (cpu->ecx == cpu->eax) goto label_00001D6B;
    label_00001D63:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001D6B:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    if (cpu->ecx != *(uint32_t*)(cpu->edi)) goto label_00001D63;
    if (cpu->ecx < 4u) goto label_00001D8B;
    label_00001D77:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax != *(uint32_t*)(cpu->edx)) goto label_00001D8F;
    cpu->ecx -= 4u;
    cpu->edx += 4u;
    cpu->esi += 4u;
    if (cpu->ecx >= 4u) goto label_00001D77;
    label_00001D8B:
    if (cpu->ecx == 0u) goto label_00001DDD;
    label_00001D8F:
    cpu->edi = *(uint8_t*)(cpu->edx);
    cpu->eax = *(uint8_t*)(cpu->esi);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001DCA;
    if (cpu->ecx <= 1u) goto label_00001DDD;
    cpu->eax = *(uint8_t*)(cpu->esi + 1u);
    cpu->edi = *(uint8_t*)(cpu->edx + 1u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001DCA;
    if (cpu->ecx <= 2u) goto label_00001DDD;
    cpu->eax = *(uint8_t*)(cpu->esi + 2u);
    cpu->edi = *(uint8_t*)(cpu->edx + 2u);
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00001DCA;
    if (cpu->ecx <= 3u) goto label_00001DDD;
    cpu->eax = *(uint8_t*)(cpu->esi + 3u);
    cpu->ecx = *(uint8_t*)(cpu->edx + 3u);
    cpu->eax -= cpu->ecx;
    label_00001DCA:
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->eax |= 1u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = 0u;
    lift_test[0]=cpu->eax==0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((lift_test[0]) ? 1u : 0u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00001DDD:
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = 0u;
    lift_test[1]=cpu->eax==0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((lift_test[1]) ? 1u : 0u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00401F10(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_00001F4A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ecx) == 0x19285u);
    if ((cpu->eax & 0xFFu) == 0u) goto label_00001F4A;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00001F4A;
    switch (cpu->eax) {
        case 0u: goto label_00001F31;
        case 1u: goto label_00001F36;
        case 2u: goto label_00001F3B;
        case 3u: goto label_00001F40;
        case 4u: goto label_00001F45;
        default: cpu->eip = 0x401F2Au; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00001F31:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->destroy(); cpu->eax = 0u; cpu->esp += 4u; cpu->eip = stop_address; return;

label_00001F36:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->destroy(); cpu->eax = 0u; cpu->esp += 4u; cpu->eip = stop_address; return;

label_00001F3B:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->destroy(); cpu->eax = 0u; cpu->esp += 4u; cpu->eip = stop_address; return;

label_00001F40:
    goto label_00016170;

label_00001F45:
    goto label_00018080;

label_00001F4A:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00016170:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->destroy(); cpu->eax = 0u; cpu->esp += 4u; cpu->eip = stop_address; return;

label_00018080:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_000180B0;
    switch (cpu->eax) {
        case 0u: goto label_00018090;
        case 1u: goto label_00018098;
        case 2u: goto label_000180B0;
        case 3u: goto label_000180A0;
        case 4u: goto label_000180A8;
        default: cpu->eip = 0x418089u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00018090: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418095u)); sfera_sub_00417F20(cpu, LIFT_CODE_TOKEN_VA(0x418095u));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00018098:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41809Du)); sfera_sub_00417F20(cpu, LIFT_CODE_TOKEN_VA(0x41809Du));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000180A0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4180A5u)); sfera_sub_00417FA0(cpu, LIFT_CODE_TOKEN_VA(0x4180A5u));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000180A8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4180ADu)); sfera_sub_00418010(cpu, LIFT_CODE_TOKEN_VA(0x4180ADu));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000180B0:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402040(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00002040;
    label_00001E60:
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401E66u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00001EE3;
    switch (cpu->eax) {
        case 0u: goto label_00001E73;
        case 1u: goto label_00001E99;
        case 2u: goto label_00001EA7;
        case 3u: goto label_00001EB5;
        case 4u: goto label_00001ECC;
        default: cpu->eip = 0x401E6Cu; throw std::out_of_range("resolved jump-table index out of range"); return;
    }
label_00001E73: ;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401E78u);
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaScriptContainer::create(SferaDataContainerHeader::Kind::List, static_cast<SferaDataContainerHeader::ValueType>(cpu->ecx)))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x1E7Fu);
    label_00001E7F:
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00001E91;
    cpu->edx = 9u;
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x1E91u);
    label_00001E91:
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001E99:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401E9Eu);
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaScriptContainer::create(SferaDataContainerHeader::Kind::Vector, static_cast<SferaDataContainerHeader::ValueType>(cpu->ecx)))); cpu->eip = LIFT_CODE_TOKEN_VA(0x401EA5u);
    goto label_00001E7F;
    label_00001EA7:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401EACu);
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaScriptContainer::create(SferaDataContainerHeader::Kind::Set, static_cast<SferaDataContainerHeader::ValueType>(cpu->ecx)))); cpu->eip = LIFT_CODE_TOKEN_VA(0x401EB3u);
    goto label_00001E7F;
    label_00001EB5:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401EBAu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401EC1u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SferaScriptContainer::create(SferaDataContainerHeader::Kind::Map, static_cast<SferaDataContainerHeader::ValueType>(cpu->ecx), static_cast<SferaDataContainerHeader::ValueType>(cpu->edx)))); cpu->eip = LIFT_CODE_TOKEN_VA(0x401ECAu);
    goto label_00001E7F;
    label_00001ECC:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401ED1u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401ED8u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x401EE1u)); sfera_sub_00417C70(cpu, LIFT_CODE_TOKEN_VA(0x401EE1u));
    goto label_00001E7F;
    label_00001EE3:
    cpu->esi = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001F70:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401F75u);
    if (cpu->eax == 0u) goto label_00001F8E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->eax) == 0x19285u);
    if ((cpu->ecx & 0xFFu) == 0u) goto label_00001F8E;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001F8E:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001FA0:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x401FA5u);
    if (cpu->eax == 0u) goto label_00001FB6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->eax) == 0x19285u);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00001FBE;
    label_00001FB6:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001FBE:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    --cpu->ecx;
    if (cpu->ecx > 4u) goto label_00001FB6;
    switch (cpu->ecx) {
        case 0u: case 1u: goto label_00001FCE;
        case 2u: goto label_00001FB6;
        case 3u: case 4u: goto label_00001FD6;
        default: cpu->eip = 0x401FC7u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }
label_00001FCE: ;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00001FD6:
    cpu->ecx = reinterpret_cast<SferaDataContainerHeader*>(cpu->eax)->kind == SferaDataContainerHeader::Kind::Map ? static_cast<std::uint32_t>(reinterpret_cast<SferaScriptContainer*>(cpu->eax)->value_type) : *(uint32_t*)(cpu->eax + 0x10u);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00002000:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x402005u);
    if (cpu->eax == 0u) goto label_00002016;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->eax) == 0x19285u);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0000201E;
    label_00002016:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000201E:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->ecx == 3u) goto label_0000202E;
    cpu->ecx += 0xFFFFFFFCu;
    if (cpu->ecx > 1u) goto label_00002016;
    label_0000202E:
    cpu->ecx = reinterpret_cast<SferaDataContainerHeader*>(cpu->eax)->kind == SferaDataContainerHeader::Kind::Map ? static_cast<std::uint32_t>(reinterpret_cast<SferaScriptContainer*>(cpu->eax)->key_type) : *(uint32_t*)(cpu->eax + 0xCu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00002040:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x402045u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00002089;
    switch (cpu->eax) {
        case 0u: goto label_00002052;
        case 1u: goto label_00002057;
        case 2u: goto label_0000207A;
        case 3u: goto label_0000207F;
        case 4u: goto label_00002084;
        default: cpu->eip = 0x40204Bu; throw std::out_of_range("resolved jump-table index out of range"); return;
    }
label_00002052: ;
    goto label_00001E60;
    label_00002057:
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x40205Du);
    cpu->esi = cpu->eax;
    cpu->edx = 9u;
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->active_process->unregisterResource(cpu->ecx, cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x40206Bu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x402072u)); sfera_sub_00401F10(cpu, LIFT_CODE_TOKEN_VA(0x402072u));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0000207A:
    goto label_00001F70;
    label_0000207F:
    goto label_00001FA0;
    label_00002084:
    goto label_00002000;
    label_00002089:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00402720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x402733u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x40273Au);
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00002748;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0000275C;
    label_00002748:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->ecx == 0u) goto label_00002765;
    if (cpu->eax < cpu->ecx) goto label_0000275C;
    cpu->eax = cpu->eax + cpu->esi + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->edi + 8u)) goto label_00002765;
    label_0000275C:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x2765u);
    label_00002765:
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->edi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = 0x20u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    *(uint32_t*)(cpu->ebx) = cpu->esi;
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x40278Au));
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004027A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax >= cpu->edi) goto label_000027B7;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4027A0u); throw std::out_of_range("std::out_of_range");
    label_000027B7:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= cpu->edi;
    if (cpu->eax >= cpu->esi) goto label_000027C5;
    cpu->esi = cpu->eax;
    label_000027C5:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_000027D1;
    cpu->edx = cpu->ebx;
    label_000027D1:
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_000027DB;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    goto label_000027DD;
    label_000027DB:
    cpu->eax = cpu->ecx;
    label_000027DD:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4027EBu)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x4027EBu));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_00002806;
    if (cpu->esi >= cpu->ebx) goto label_000027FF;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000027FF:
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->ebx);
    label_00002806:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
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


__declspec(noinline) void sfera_sub_00402CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_00002D14;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00002D14:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00402D20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[0]) goto label_00002D71;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00002D71:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_00002D9A;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00002D9A:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00403120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_00003140;
    lift_push32(cpu, cpu->esi);
    label_00003130:
    cpu->esi = *(uint32_t*)(cpu->edx + 0xFFFFFFFCu);
    cpu->edx -= 4u;
    cpu->eax -= 4u;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    if (cpu->edx != cpu->ecx) goto label_00003130;
    cpu->esi = lift_pop32(cpu);
    label_00003140:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403150(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == cpu->edx) goto label_0000316C;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    label_00003160:
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->ecx += 4u;
    if (cpu->ecx != cpu->edx) goto label_00003160;
    cpu->esi = lift_pop32(cpu);
    label_0000316C:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403170(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edx = (uint32_t)(((uint64_t)0xCCCCCCCDu * (uint32_t)(cpu->edi)) >> 32u);
    cpu->edx >>= 3u;
    cpu->ecx = 0u;
    ++cpu->edx;
    cpu->esi = 0x811C9DC5u;
    if (cpu->edi == 0u) goto label_000031B2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0x14u);
    label_00003194:
    if (cpu->ebp < 0x10u) goto label_0000319D;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    goto label_0000319F;
    label_0000319D:
    cpu->eax = cpu->ebx;
    label_0000319F:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ecx));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    cpu->ecx += cpu->edx;
    cpu->esi ^= cpu->eax;
    if (cpu->ecx < cpu->edi) goto label_00003194;
    cpu->ebp = lift_pop32(cpu);
    label_000031B2:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
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


__declspec(noinline) void sfera_sub_004039D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003A00;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x1FFFFFFEu;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_000039F8;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4039D0u); throw std::length_error("std::length_error");
    label_000039F8:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003A00:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403A60(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003A90;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x7FFFFFEu;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00003A88;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403A60u); throw std::length_error("std::length_error");
    label_00003A88:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003A90:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403AF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003B20;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x4924923u;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00003B18;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403AF0u); throw std::length_error("std::length_error");
    label_00003B18:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003B20:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403B80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00003BB0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x71C71C6u;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00003BA8;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403B80u); throw std::length_error("std::length_error");
    label_00003BA8:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00003BB0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00403C10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx + 8u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[0]) goto label_00003C62;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00003C62:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_00003C8B;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00003C8B:
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00404EF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00004F20;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x15555554u;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00004F18;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404EF0u); throw std::length_error("std::length_error");
    label_00004F18:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00004F20:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00404F80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->esi) goto label_00004FB0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0xFFFFFFEu;
    cpu->edi -= cpu->edx;
    sub_pred[0] = cpu->edi < cpu->eax;
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00004FA8;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404F80u); throw std::length_error("std::length_error");
    label_00004FA8:
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_00004FB0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00405050(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->edx == 0u) goto label_0000506F;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    label_00005060:
    if (cpu->ecx == 0u) goto label_00005068;
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    label_00005068:
    cpu->ecx += 4u;
    if ((--cpu->edx) != 0u) goto label_00005060;
    cpu->esi = lift_pop32(cpu);
    label_0000506F:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00405080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_000050A3;
    lift_push32(cpu, cpu->esi);
    label_00005090:
    if (cpu->eax == 0u) goto label_00005098;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    label_00005098:
    cpu->ecx += 4u;
    cpu->eax += 4u;
    if (cpu->ecx != cpu->edx) goto label_00005090;
    cpu->esi = lift_pop32(cpu);
    label_000050A3:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004050B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000050EB;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_000050E5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    label_000050E5:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000050EB:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405119u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x405119u));
    cpu->eip = 0x405119u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00405120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0000515B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->ecx == 0u) goto label_00005155;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(float*)(cpu->ecx + 4u) = (double)*(float*)(cpu->edx + 4u);
    cpu->esi = lift_pop32(cpu);
    label_00005155:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000515B:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x405189u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x405189u));
    cpu->eip = 0x405189u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00405190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000051DF;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == 0u) goto label_000051D9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 8u) = 0u;
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    cpu->edi = lift_pop32(cpu);
    label_000051D9:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000051DF:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40520Du)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40520Du));
    cpu->eip = 0x40520Du; ::DebugBreak(); return;
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


__declspec(noinline) void sfera_sub_004061B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000061C4;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_000061C4:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00406690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000066DE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == 0u) goto label_000066D8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    *(uint32_t*)(cpu->ecx) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    label_000066D8:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000066DE:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40670Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40670Cu));
    cpu->eip = 0x40670Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00406710(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0000675E;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == 0u) goto label_00006758;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = 0u;
    *(uint32_t*)(cpu->ecx) = 0u;
    *(float*)(cpu->edx + 8u) = x87_v0; 
    cpu->edi = lift_pop32(cpu);
    label_00006758:
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000675E:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40678Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40678Cu));
    cpu->eip = 0x40678Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00406790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x18u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esi = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->esi) goto label_000067E6;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = cpu->eax + 8u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->edx == cpu->esi) goto label_000067DF;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->esi;
    cpu->edi = lift_pop32(cpu);
    label_000067DF:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000067E6:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x406810u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x406810u));
    cpu->eip = 0x406810u; ::DebugBreak(); return;
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


__declspec(noinline) void sfera_sub_00406BA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_00006BFD;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0xCu) == 0u) goto label_00006BE2;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00006BE2:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006BFD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00406DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_00006E1E;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    *(uint32_t*)(cpu->esi + cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006E1E:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406E30(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_00006E7B;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->edx;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x18u)) goto label_00006E77;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    *(uint32_t*)(cpu->esi + cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006E77:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_00006E7B:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406E90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00006ECA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x406EABu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006ECA:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406EE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00006F26;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00006F22;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x406F04u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->edx + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006F22:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00006F26:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406F30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00006F6A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x406F4Bu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006F6A:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406F80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00006FC6;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00006FC2;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x406FA4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->edx + 0x10u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00006FC2:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00006FC6:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00406FE0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->edx) goto label_0000701E;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    x87_v0 = (double)*(float*)(cpu->edx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->eax) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000701E:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407030(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    if (*(uint8_t*)(cpu->ecx + 8u) == 0u) goto label_0000707B;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x40u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x40u) = cpu->edx;
    if (cpu->eax == *(uint32_t*)(cpu->ecx + 0x18u)) goto label_00007077;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->esi + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    x87_v0 = (double)*(float*)(cpu->edx + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->eax) = x87_v0; 
    *(uint8_t*)(cpu->ecx + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007077:
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    label_0000707B:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407090(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000070C9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x4070ABu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000070C9:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004070E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007127;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00007123;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x407104u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->edx + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007123:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007127:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407130(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00007169;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x40714Bu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(float*)(cpu->eax + cpu->edx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007169:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407180(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000071C7;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_000071C3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x4071A4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->edx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000071C3:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000071C7:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004071D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_0000720A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x407200u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000720A:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007266;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00007262;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x407258u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007262:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007266:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000072A4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x40728Bu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x40729Au);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000072A4:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004072B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000072F1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_000072ED;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x4072D4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x4072E3u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000072ED:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000072F1:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00007334;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x40731Bu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x40732Au);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007334:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407340(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007381;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_0000737D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x407364u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x407373u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000737D:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007381:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000073CA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x4073C0u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000073CA:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004073E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007426;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_00007422;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x407418u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007422:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007426:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407430(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_00007464;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x40744Bu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x40745Au);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007464:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_000074B1;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_000074AD;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x407494u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x4074A3u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000074AD:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_000074B1:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004074C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_000074F4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x4074DBu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x4074EAu);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000074F4:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407500(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 8u) == 0u) goto label_00007541;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 0x18u)) goto label_0000753D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 8u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x407524u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x407533u);
    *(uint8_t*)(cpu->esi + 8u) = 1u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000753D:
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    label_00007541:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407550(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x407562u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_00007581;
    cpu->edx += 0x7FFFFFFFu;
    label_00007581:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_00007596;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007596:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    cpu->eax = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_000075A8:
    if (cpu->edi != cpu->esi) goto label_000075B0;
    cpu->ecx = cpu->esi;
    goto label_000075B5;
    label_000075B0:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000075B5:
    if (cpu->eax == cpu->ecx) goto label_000075F6;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx == *(uint32_t*)(cpu->ebx)) goto label_000075C4;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_000075A8;
    label_000075C4:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (*(uint32_t*)(cpu->ebx) == cpu->ecx) goto label_000075E3;
    cpu->eax = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000075E3:
    cpu->eax = cpu->esp + 0x18u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000075F6:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407610(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->esi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_00007640;
    label_00007630:
    cpu->edi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->edi;
    if (cpu->eax != cpu->edx) goto label_00007630;
    label_00007640:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    if (*(uint32_t*)(cpu->ecx + 0x24u) > cpu->eax) goto label_00007655;
    cpu->edx >>= 1u;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_00007655:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->edx + (cpu->eax * 8u));
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = cpu->edx + (cpu->eax * 8u);
    cpu->esi = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_00007667:
    if (cpu->ebp != cpu->edi) goto label_0000766F;
    cpu->eax = cpu->edi;
    goto label_00007674;
    label_0000766F:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007674:
    if (cpu->esi == cpu->eax) goto label_000076CE;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407685u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x407685u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000768D;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_00007667;
    label_0000768D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->esi += 8u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40769Eu)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40769Eu));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000076BA;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0x18u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000076BA:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0xCu;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000076CE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004076E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_00007711;
    label_00007701:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_00007701;
    label_00007711:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->edi + 0x24u) > cpu->eax) goto label_00007726;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007726:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = cpu->ecx + (cpu->eax * 8u);
    cpu->esi = cpu->ebp;
    label_00007734:
    if (cpu->ebp != cpu->edi) goto label_0000773C;
    cpu->eax = cpu->edi;
    goto label_00007741;
    label_0000773C:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_00007741:
    if (cpu->esi == cpu->eax) goto label_000077A1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407752u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x407752u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000775A;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_00007734;
    label_0000775A:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_00007760:
    if (cpu->ebp != cpu->edi) goto label_00007768;
    cpu->eax = cpu->edi;
    goto label_0000776D;
    label_00007768:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    label_0000776D:
    if (cpu->esi == cpu->eax) goto label_00007786;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->esi + 8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40777Eu)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40777Eu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00007786;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_00007760;
    label_00007786:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx == cpu->esi) goto label_000077A1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000077A1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004077C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x4077D3u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_000077F2;
    cpu->edx += 0x7FFFFFFFu;
    label_000077F2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_00007807;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007807:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->ecx + (cpu->eax * 8u);
    cpu->ecx = cpu->ebx;
    label_00007815:
    if (cpu->ebx != cpu->edx) goto label_0000781D;
    cpu->eax = cpu->edx;
    goto label_00007822;
    label_0000781D:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007822:
    if (cpu->ecx == cpu->eax) goto label_00007872;
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->eax == *(uint32_t*)(cpu->ebp)) goto label_00007832;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    goto label_00007815;
    label_00007832:
    cpu->ebp = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_00007840:
    if (cpu->ebx != cpu->edx) goto label_00007848;
    cpu->eax = cpu->edx;
    goto label_0000784D;
    label_00007848:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000784D:
    if (cpu->ecx == cpu->eax) goto label_0000785A;
    if (cpu->ebp != *(uint32_t*)(cpu->ecx + 8u)) goto label_0000785A;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    goto label_00007840;
    label_0000785A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->edx == cpu->ecx) goto label_00007872;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007872:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4078A6u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x4078A6u));
    cpu->eax &= cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_000078B6;
    cpu->edi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->edi;
    cpu->eax += cpu->ecx;
    label_000078B6:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->eax * 8u));
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->esi = 0x10u;
    label_000078E0:
    if (cpu->ecx != cpu->edi) goto label_000078E8;
    cpu->eax = cpu->edi;
    goto label_000078ED;
    label_000078E8:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000078ED:
    if (cpu->edx == cpu->eax) goto label_000079CD;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->edx + 8u;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->esi) goto label_00007905;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00007907;
    label_00007905:
    cpu->edx = cpu->ebp;
    label_00007907:
    cpu->edi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->edi;
    if (cpu->ecx >= cpu->edi) goto label_00007910;
    label_00007910:
    cpu->ecx = cpu->edi;
    if (cpu->edi < cpu->ebx) goto label_00007918;
    cpu->ecx = cpu->ebx;
    label_00007918:
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_0000791F;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000791F:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407927u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x407927u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000793B;
    if (cpu->edi < cpu->ebx) goto label_0000793B;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != cpu->ebx);
    if (cpu->eax == 0u) goto label_00007953;
    label_0000793B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    goto label_000078E0;
    label_00007953:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x18u);
    cpu->eax += 8u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_00007964;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007964:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->edi;
    if (cpu->edi < cpu->ebx) goto label_00007971;
    cpu->edx = cpu->ebx;
    label_00007971:
    if (*(uint32_t*)(cpu->ebp + 0x14u) < cpu->esi) goto label_0000797B;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    goto label_0000797D;
    label_0000797B:
    cpu->ecx = cpu->ebp;
    label_0000797D:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407985u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x407985u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_00007999;
    if (cpu->edi < cpu->ebx) goto label_00007999;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != cpu->ebx);
    if (cpu->eax == 0u) goto label_000079B7;
    label_00007999:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0x14u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000079B7:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esp + 0x20u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000079CD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004079E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x20u);
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4079FAu)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x4079FAu));
    cpu->eax &= cpu->esi;
    if (*(uint32_t*)(cpu->edi + 0x24u) > cpu->eax) goto label_00007A0A;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->eax += cpu->ecx;
    label_00007A0A:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->eax * 8u));
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    label_00007A28:
    if (cpu->ecx != cpu->edx) goto label_00007A30;
    cpu->eax = cpu->edx;
    goto label_00007A35;
    label_00007A30:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007A35:
    if (cpu->ebx == cpu->eax) goto label_00007BB0;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebx + 8u;
    if (*(uint32_t*)(cpu->ebp + 0x14u) < 0x10u) goto label_00007A4E;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    goto label_00007A50;
    label_00007A4E:
    cpu->edx = cpu->ebp;
    label_00007A50:
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if (cpu->ecx >= cpu->esi) goto label_00007A59;
    label_00007A59:
    cpu->ecx = cpu->esi;
    if (cpu->esi < cpu->edi) goto label_00007A61;
    cpu->ecx = cpu->edi;
    label_00007A61:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_00007A69;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007A69:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x407A71u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x407A71u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_00007A85;
    if (cpu->esi < cpu->edi) goto label_00007A85;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != cpu->edi);
    if (cpu->eax == 0u) goto label_00007A9F;
    label_00007A85:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_00007A28;
    label_00007A9F:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    label_00007AB0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint32_t*)(cpu->esp + 0x18u) == cpu->eax) goto label_00007AC3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    label_00007AC3:
    if (cpu->ebx == cpu->eax) goto label_00007B91;
    cpu->eax = cpu->ebx + 8u;
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->esi) goto label_00007ADD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00007ADD:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    if (cpu->ecx >= cpu->edi) goto label_00007AE6;
    cpu->edi = cpu->ecx;
    label_00007AE6:
    cpu->edx = cpu->edi;
    if (cpu->edi < cpu->ebx) goto label_00007AEE;
    cpu->edx = cpu->ebx;
    label_00007AEE:
    if (*(uint32_t*)(cpu->esp + 0x24u) < cpu->esi) goto label_00007AF9;
    cpu->esi = *(uint32_t*)(cpu->ebp);
    goto label_00007AFB;
    label_00007AF9:
    cpu->esi = cpu->ebp;
    label_00007AFB:
    cpu->ecx = cpu->eax;
    if (cpu->edx < 4u) goto label_00007B16;
    label_00007B02:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_00007B1A;
    cpu->edx -= 4u;
    cpu->ecx += 4u;
    cpu->esi += 4u;
    if (cpu->edx >= 4u) goto label_00007B02;
    label_00007B16:
    if (cpu->edx == 0u) goto label_00007B65;
    label_00007B1A:
    cpu->ebp = *(uint8_t*)(cpu->ecx);
    cpu->eax = *(uint8_t*)(cpu->esi);
    if ((cpu->eax -= cpu->ebp) != 0u) goto label_00007B55;
    if (cpu->edx <= 1u) goto label_00007B61;
    cpu->eax = *(uint8_t*)(cpu->esi + 1u);
    cpu->ebp = *(uint8_t*)(cpu->ecx + 1u);
    if ((cpu->eax -= cpu->ebp) != 0u) goto label_00007B55;
    if (cpu->edx <= 2u) goto label_00007B61;
    cpu->eax = *(uint8_t*)(cpu->esi + 2u);
    cpu->ebp = *(uint8_t*)(cpu->ecx + 2u);
    if ((cpu->eax -= cpu->ebp) != 0u) goto label_00007B55;
    if (cpu->edx <= 3u) goto label_00007B61;
    cpu->eax = *(uint8_t*)(cpu->esi + 3u);
    cpu->ecx = *(uint8_t*)(cpu->ecx + 3u);
    cpu->eax -= cpu->ecx;
    label_00007B55:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = (int32_t)(cpu->eax) >> 31u;
    cpu->eax |= 1u;
    goto label_00007B67;
    label_00007B61:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    label_00007B65:
    cpu->eax = 0u;
    label_00007B67:
    if (cpu->eax != 0u) goto label_00007B8D;
    if (cpu->edi < cpu->ebx) goto label_00007B8D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != cpu->ebx);
    if (cpu->eax != 0u) goto label_00007B8D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ebx = cpu->eax;
    goto label_00007AB0;
    label_00007B8D:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00007B91:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ecx == cpu->ebx) goto label_00007BAC;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00007BAC:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_00007BB0:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00407BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x407BE1u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_00007C00;
    cpu->edx += 0x7FFFFFFFu;
    label_00007C00:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->ecx) goto label_00007C15;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ecx += cpu->edx;
    label_00007C15:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = cpu->eax + (cpu->ecx * 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->edx + 4u) != cpu->eax) goto label_00007C41;
    if (*(uint32_t*)(cpu->edx) != cpu->eax) goto label_00007C39;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 8u) + 4u) = cpu->eax;
    goto label_00007C49;
    label_00007C39:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    goto label_00007C49;
    label_00007C41:
    if (*(uint32_t*)(cpu->edx) != cpu->eax) goto label_00007C4D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_00007C49:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00007C4D:
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_00007C6F;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 8u);
    label_00007C6F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00408A50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_00008AA3;
    lift_push32(cpu, cpu->ebx);
    label_00008A70:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_00008A93;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00008A93:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if (cpu->ebx != *(uint32_t*)(cpu->edi)) goto label_00008A70;
    cpu->ebx = lift_pop32(cpu);
    label_00008AA3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00408D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_00008D7D;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_00008D62;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00008D62:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00008D7D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00408D90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xCu);
    if (cpu->edi == 0u) goto label_00008F98;
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->edx = 0x3FFFFFFFu;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->edi) goto label_00008DEA;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408D90u); throw std::length_error("std::length_error");
    label_00008DEA:
    cpu->edx = cpu->eax + cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax >= cpu->edx) goto label_00008EE3;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 1u;
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->ecx;
    if (cpu->ebx >= cpu->eax) goto label_00008E18;
    *(uint32_t*)(cpu->ebp + 0xCu) = 0u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    goto label_00008E1D;
    label_00008E18:
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    label_00008E1D:
    if (cpu->eax >= cpu->edx) goto label_00008E26;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->edx;
    cpu->eax = cpu->edx;
    label_00008E26:
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E2Fu)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x408E2Fu));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx -= *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->ebx = (int32_t)(cpu->ebx) >> 2u;
    cpu->ecx = cpu->eax + (cpu->ebx * 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E59u)); sfera_sub_00405050(cpu, LIFT_CODE_TOKEN_VA(0x408E59u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E71u)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408E71u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx + cpu->edi;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebx + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408E90u)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408E90u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx -= cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    cpu->edi += cpu->ecx;
    if (cpu->eax == 0u) goto label_00008EA9;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00008EA9:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = cpu->ebx + (cpu->edx * 4u);
    cpu->ecx = cpu->ebx + (cpu->edi * 4u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00008EE3:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    sub_pred[0] = cpu->eax < cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    if (!sub_pred[0]) goto label_00008F57;
    cpu->edx = cpu->edi * 4u;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F1Au)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408F1Au));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->ecx;
    cpu->edx -= *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    lift_push32(cpu, 0u);
    cpu->edi -= cpu->edx;
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F43u)); sfera_sub_00405050(cpu, LIFT_CODE_TOKEN_VA(0x408F43u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx -= cpu->eax;
    goto label_00008F93;
    label_00008F57:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->edi * 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esi + 0xCu;
    cpu->edi = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edi -= cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F79u)); sfera_sub_00405080(cpu, LIFT_CODE_TOKEN_VA(0x408F79u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x408F87u)); sfera_sub_00403120(cpu, LIFT_CODE_TOKEN_VA(0x408F87u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->ecx;
    label_00008F93:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8F98u)); sfera_sub_00403150(cpu, LIFT_CODE_TOKEN_RVA(0x8F98u));
    label_00008F98:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00409130(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->edi) goto label_0000919A;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000914D;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000914D:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x14u) >= 0x10u) goto label_00009176;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40916Bu));
    cpu->esp += 0xCu;
    goto label_00009180;
    label_00009176:
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    *(uint32_t*)(cpu->edi) = 0u;
    label_00009180:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x10u) = 0u;
    *(uint32_t*)(cpu->edi + 0x14u) = 0u;
    label_0000919A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00409C90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409CA5u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409CA5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009CC5;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009CC5:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409CD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409CE5u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409CE5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009D05;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009D05:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409D10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409D25u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409D25u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009D45;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009D45:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409D50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409D65u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409D65u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009D86;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->eax + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009D86:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409D90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409DA5u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409DA5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009DC6;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009DC6:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409DD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409DE5u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409DE5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009E06;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->ecx) = x87_v0; 
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009E06:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409E10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409E25u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409E25u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009E40;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x409E3Bu);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009E40:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409E50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409E65u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409E65u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009E80;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x24u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x409E7Bu);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009E80:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409E90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409EA5u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409EA5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009EC0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x10u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[5] < 16u ? cpu->edx : *reinterpret_cast<const std::uint32_t*>(cpu->edx)), reinterpret_cast<const std::uint32_t*>(cpu->edx)[4] + 1u); cpu->eip = LIFT_CODE_TOKEN_VA(0x409EBBu);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009EC0:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409ED0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409EE5u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x409EE5u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009F00;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0xCu;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x409EFBu);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009F00:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409F10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409F25u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x409F25u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009F40;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x24u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x409F3Bu);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009F40:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00409F50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x409F65u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x409F65u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esi + 0x18u);
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00009F80;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = cpu->eax + 0x10u;
    g_sfera_mbc_runtime->exportSlice(*reinterpret_cast<SferaSliceReference32*>(cpu->ecx), reinterpret_cast<const void*>(reinterpret_cast<const std::uint32_t*>(cpu->edx)[1]), reinterpret_cast<const std::uint32_t*>(cpu->edx)[0]); cpu->eip = LIFT_CODE_TOKEN_VA(0x409F7Bu);
    cpu->eax = 0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00009F80:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0040A060(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000A0B3;
    lift_push32(cpu, cpu->ebx);
    label_0000A080:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0xCu) == 0u) goto label_0000A0A3;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000A0A3:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if (cpu->ebx != *(uint32_t*)(cpu->edi)) goto label_0000A080;
    cpu->ebx = lift_pop32(cpu);
    label_0000A0B3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A0C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = 0u;
    if (cpu->edi == *(uint32_t*)(cpu->ebx)) goto label_0000A167;
    label_0000A0FD:
    cpu->ebp = *(uint32_t*)(cpu->edi);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0xCu) == 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (sub_pred[0]) goto label_0000A12F;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000A12F:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    if (sub_pred[1]) goto label_0000A158;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000A158:
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->edi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->ebx)) goto label_0000A0FD;
    label_0000A167:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A180(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40A191u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_0000A1B0;
    cpu->edx += 0x7FFFFFFFu;
    label_0000A1B0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_0000A1C5;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_0000A1C5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) == cpu->edx;
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000A1F2;
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000A1EA;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->edx;
    goto label_0000A1FA;
    label_0000A1EA:
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000A1FA;
    label_0000A1F2:
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000A1FE;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0000A1FA:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000A1FE:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A20Cu)); sfera_sub_00408D20(cpu, LIFT_CODE_TOKEN_VA(0x40A20Cu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000A258;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A248u)); sfera_sub_00403C10(cpu, LIFT_CODE_TOKEN_VA(0x40A248u));
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000A258:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

} // namespace lifted
