#include "lifted_functions.h"
#include <cmath>
#include <cstddef>
#include <cstring>
namespace lifted {

static void sfera_u32_to_sso_decimal(LiftCpu* cpu) {
    const uint32_t destination = cpu->ecx;
    uint32_t value = *(uint32_t*)(cpu->edx);
    uint8_t reversed[16]{};
    std::size_t length = 0u;
    do {
        reversed[length++] = static_cast<uint8_t>('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);
    for (std::size_t index = 0u; index != 16u; ++index) {
        const uint8_t output = index < length ? reversed[length - index - 1u] : 0u;
        *(uint8_t*)(destination + static_cast<uint32_t>(index)) = output;
    }
    *(uint32_t*)(destination + 0x10u) = static_cast<uint32_t>(length);
    *(uint32_t*)(destination + 0x14u) = 15u;
    cpu->eax = destination;
}
__declspec(noinline) void sfera_sub_004B9A10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    *(uint32_t*)(cpu->ecx) = 0x31564955u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx + 4u;
    if (cpu->edx == cpu->eax) goto label_000B9A6B;
    lift_push32(cpu, cpu->esi);
    label_000B9A26:
    cpu->eax = cpu->edx + 8u;
    if (*(uint32_t*)(cpu->edx + 0x1Cu) < 0x10u) goto label_000B9A31;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9A31:
    cpu->esi = cpu->edi;
    cpu->esi -= cpu->eax;
    label_000B9A35:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000B9A35;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->edx + 0x24u))));
    cpu->eax = *(uint32_t*)(cpu->edx + 0x18u);
    cpu->eax = cpu->eax + cpu->edi + 1u;
    cpu->edi = cpu->eax + 8u;
    x87_v0 = (x87_v0) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    *(float*)(cpu->eax) = x87_v0; 
    *(float*)(cpu->eax + 4u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->edx + 0x28u)))))) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height)))));
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10) goto label_000B9A26;
    cpu->esi = lift_pop32(cpu);
    label_000B9A6B:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9A70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if (cpu->ebx != 0u) goto label_000B9A7B;
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9A7B:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    if (cpu->esi == cpu->eax) goto label_000B9AB5;
    cpu->edi = native_function_address32(&::_stricmp);
    label_000B9A90:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000B9AA0;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000B9AA0:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->ebx);

    if (cpu->eax == 0u) goto label_000B9ABB;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) goto label_000B9A90;
    label_000B9AB5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9ABB:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9AD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->ecx == cpu->esi) goto label_000B9AF9;
    label_000B9AE0:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x24u);
    cpu->eax >>= 3u;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000B9AF3;
    if (*(uint8_t*)(cpu->edx + 0x48u) == 0u) goto label_000B9AFE;
    label_000B9AF3:
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx != cpu->esi) goto label_000B9AE0;
    label_000B9AF9:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000B9AFE:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (cpu->ecx == cpu->esi) goto label_000B9B4D;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    label_000B9B28:
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    if (cpu->edx > cpu->eax) goto label_000B9B39;
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    label_000B9B39:
    --cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = cpu->ecx;
    if (cpu->ecx != 0u) goto label_000B9B49;
    cpu->eax = 0u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    label_000B9B49:
    if (cpu->ecx != cpu->esi) goto label_000B9B28;
    label_000B9B4D:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9B77u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4B9B77u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000B9B91;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4B9B60u); throw std::length_error("std::length_error");
    label_000B9B91:
    ++cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->esi == 0u) goto label_000B9C2E;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9C08u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B9C08u));
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, 0u);
    cpu->edi += 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x24u) = 1u;
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9C2Eu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xB9C2Eu));
    label_000B9C2E:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9C50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (cpu->esi == 0u) goto label_000B9CCE;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9CA8u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4B9CA8u));
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, 0u);
    cpu->edi += 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x28u) = 1u;
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9CCEu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xB9CCEu));
    label_000B9CCE:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9D00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (g_sfera_interface_runtime.cross_enabled == cpu->edi) goto label_000B9F33;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_000B9D3A;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9D3Au)); sfera_ui_window_get_absolute_position(cpu, LIFT_CODE_TOKEN_RVA(0xB9D3Au));
    label_000B9D3A:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx += cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->eax)) goto label_000B9F33;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    goto label_000B9D82;
    label_000B9D80:
    cpu->edi = 0u;
    label_000B9D82:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_000B9F18;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000B9F18;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 0xE0u));
    if ((cpu->eax & 0xFFu)==0u) goto label_000B9DB5;
    if (*(uint8_t*)(cpu->esi + 0x11Cu) != 0u) goto label_000B9F18;
    label_000B9DB5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx >>= 4u;
    if ((((cpu->ecx & 0xFFu)) & (1u)) != 0u) goto label_000B9F18;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000B9F18;
    if (*(uint8_t*)(cpu->esi + 0xE1u) != (cpu->eax & 0xFFu)) goto label_000B9F18;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    if (cpu->ecx == cpu->edi) goto label_000B9DF9;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xB9DF9u)); sfera_ui_window_get_absolute_position(cpu, LIFT_CODE_TOKEN_RVA(0xB9DF9u));
    label_000B9DF9:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx = cpu->edi + cpu->eax;
    cpu->ebp = cpu->esi + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebp;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_000B9F18;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x38u) < (int32_t)cpu->eax) goto label_000B9F18;
    cpu->ebx = cpu->ebp;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_000B9F14;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x3Cu) < (int32_t)cpu->ecx) goto label_000B9F14;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    sub_pred[0] = cpu->eax == cpu->ebx; sub_pred[3] = (int32_t)(cpu->eax) < (int32_t)(cpu->ebx);
    if ((int32_t)(cpu->eax) >= (int32_t)(cpu->ebx)) goto label_000B9E7C;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x38u) >= (int32_t)cpu->edx) goto label_000B9E7A;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) <= (int32_t)cpu->ecx) goto label_000B9E7A;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if ((int32_t)cpu->ebx >= (int32_t)cpu->ebp) goto label_000B9E76;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx + 0xACu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9E71u)); sfera_sub_004B9B60(cpu, LIFT_CODE_TOKEN_VA(0x4B9E71u));
    goto label_000B9F18;
    label_000B9E76:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000B9E7A:
    sub_pred[0] = cpu->eax == cpu->ebx; sub_pred[3] = (int32_t)(cpu->eax) < (int32_t)(cpu->ebx);
    label_000B9E7C:
    if ((sub_pred[0]) || (sub_pred[3])) goto label_000B9E9C;
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->esp + 0x38u)) goto label_000B9E9C;
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_000B9E9C;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x4Cu);
    if ((int32_t)cpu->ebx >= (int32_t)*(uint32_t*)(cpu->esp + 0x3Cu)) goto label_000B9E98;
    cpu->edx = cpu->edi;
    goto label_000B9ED8;
    label_000B9E98:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_000B9E9C:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
    sub_pred[1] = (int32_t)(cpu->ebx) < (int32_t)(cpu->eax);
    if ((cpu->ebx == cpu->eax) || ((int32_t)(cpu->ebx) < (int32_t)(cpu->eax))) goto label_000B9EC6;
    if ((int32_t)cpu->esi >= (int32_t)cpu->edx) goto label_000B9EC4;
    cpu->edx = cpu->esi;
    label_000B9EAA:
    cpu->edx -= cpu->ebx;
    label_000B9EAC:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x4Cu);
    sub_pred[2] = (int32_t)(cpu->edi) < (int32_t)(cpu->ecx);
    if ((cpu->edi == cpu->ecx) || ((int32_t)(cpu->edi) < (int32_t)(cpu->ecx))) goto label_000B9ED0;
    if ((int32_t)cpu->eax >= (int32_t)cpu->esi) goto label_000B9ECE;
    cpu->eax -= cpu->edi;
    goto label_000B9EDA;
    label_000B9EC4:
    sub_pred[1] = (int32_t)(cpu->ebx) < (int32_t)(cpu->eax);
    label_000B9EC6:
    if (!sub_pred[1]) goto label_000B9EAA;
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->eax;
    goto label_000B9EAC;
    label_000B9ECE:
    sub_pred[2] = (int32_t)(cpu->edi) < (int32_t)(cpu->ecx);
    label_000B9ED0:
    if (!sub_pred[2]) goto label_000B9ED6;
    cpu->eax -= cpu->ecx;
    goto label_000B9EDA;
    label_000B9ED6:
    cpu->esi -= cpu->edi;
    label_000B9ED8:
    cpu->eax = cpu->esi;
    label_000B9EDA:
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x20u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))))) / ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))))));
    { const double lift_left=(double)*(float*)(cpu->esp + 0x20u); const double lift_right=((double)0.30000001192092896f); if (!(lift_left>lift_right)) goto label_000B9F18; }
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx + 0xACu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4B9F12u)); sfera_sub_004B9B60(cpu, LIFT_CODE_TOKEN_VA(0x4B9F12u));
    goto label_000B9F18;
    label_000B9F14:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    label_000B9F18:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (cpu->eax != *(uint32_t*)(cpu->ecx)) goto label_000B9D80;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_000B9F33:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004B9F40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x25Cu;
    lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = cpu->esp + 0x15Cu;
    lift_push32(cpu, (uintptr_t)"Language\\*%s.hts"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4B9F8Cu));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x15Cu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x4B9FA2u));
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != 0xFFFFFFFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if (cpu->eax == 0u) goto label_000BA14E;
    cpu->ebp = native_strrchr_address32();
    label_000B9FC4:
    if (((*(uint8_t*)(cpu->esp + 0x18u)) & (0x10u)) != 0u) goto label_000BA136;
    cpu->eax = *(uint32_t*)((uintptr_t)"Language\\");
    cpu->ecx = *(uint32_t*)(((uintptr_t)"Language\\") + 4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"Language\\") + 8u));
    *(uint32_t*)(cpu->esp + 0x158u) = cpu->eax;
    cpu->eax = cpu->esp + 0x44u;
    *(uint32_t*)(cpu->esp + 0x15Cu) = cpu->ecx;
    *(uint16_t*)(cpu->esp + 0x160u) = cpu->edx & 0xFFFFu;
    cpu->esi = cpu->eax;
    label_000BA000:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BA000;
    cpu->edi = cpu->esp + 0x158u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000BA011:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000BA011;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->edx = 0x182u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA036u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA036u));
    lift_push32(cpu, 0x68u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA03Du)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4BA03Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x264u) = 0u;
    if (cpu->eax == 0u) goto label_000BA05E;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA05Au)); sfera_sub_004A78F0(cpu, LIFT_CODE_TOKEN_VA(0x4BA05Au));
    cpu->esi = cpu->eax;
    goto label_000BA060;
    label_000BA05E:
    cpu->esi = 0u;
    label_000BA060:
    cpu->eax = cpu->esp + 0x158u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x268u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA07Eu)); sfera_sub_004A8610(cpu, LIFT_CODE_TOKEN_VA(0x4BA07Eu));
    if (cpu->eax == 0u) goto label_000BA113;
    if (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0] == 0u) goto label_000BA0C9;
    cpu->ecx = cpu->esp + 0x158u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_strrchr_address32()))(cpu->ecx, 0x5Fu);

    if (cpu->eax == 0u) goto label_000BA0C9;
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esp + 0x158u;
    --cpu->eax;
    label_000BA0B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BA0B0;
    cpu->edx = *(uint32_t*)((uintptr_t)".hts");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".hts") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    label_000BA0C9:
    cpu->edx = cpu->esp + 0x158u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA0D8u)); sfera_sub_004A5E90(cpu, LIFT_CODE_TOKEN_VA(0x4BA0D8u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.free_list_b;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA0F4u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA0F4u));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor);
    if (cpu->ecx < 1u) goto label_000BA17C;
    g_sfera_interface_core_runtime.free_list_b_cursor = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_b_cursor)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    goto label_000BA136;
    label_000BA113:
    cpu->edx = 0x197u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA122u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA122u));
    if (cpu->esi == 0u) goto label_000BA136;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA12Du)); sfera_sub_004A7A00(cpu, LIFT_CODE_TOKEN_VA(0x4BA12Du));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA133u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BA133u));
    cpu->esp += 4u;
    label_000BA136:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x4BA140u));
    if (cpu->eax != 0u) goto label_000B9FC4;
    label_000BA14E:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x4BA14Fu));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x258u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA17C:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA17Cu); throw std::length_error("std::length_error");
}
__declspec(noinline) void sfera_sub_004BA190(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = 0x1E6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA1C9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA1C9u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA1D3u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4BA1D3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (cpu->eax == 0u) goto label_000BA1F1;
    cpu->ecx = cpu->eax;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->initialize(); cpu->eax = cpu->ecx; }
    cpu->edi = cpu->eax;
    goto label_000BA1F3;
    label_000BA1F1:
    cpu->edi = 0u;
    label_000BA1F3:
    { const uint32_t __parser_arg_019_1_0 = static_cast<uint32_t>(cpu->ebx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->load(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_1_0))); }
    { const uint32_t __parser_arg_019_2_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setBlockRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_2_0))); }
    cpu->eax = cpu->esp + 0x10u;
    { const uint32_t __parser_arg_019_3_0 = static_cast<uint32_t>(cpu->eax); const uint32_t __parser_arg_019_3_1 = static_cast<uint32_t>((uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_3_1)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_3_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000BA319;
    label_000BA225:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA22Cu)); sfera_ui_create_control(cpu, LIFT_CODE_TOKEN_VA(0x4BA22Cu));
    cpu->esi = cpu->eax;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(reinterpret_cast<const char*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp))), *reinterpret_cast<SferaSimpleParser*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 4u))), *reinterpret_cast<const SferaParserRange*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 8u)))); cpu->esp += 12u;
    if (cpu->eax != 0u) goto label_000BA264;
    cpu->edx = 0x1F7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA254u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA254u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { auto* destroyed_window = reinterpret_cast<SphereUI::Window*>(cpu->ecx); destroyed_window->destroy((*(uint32_t*)(cpu->esp) & 1u) != 0u); cpu->eax = address32(destroyed_window); } cpu->esp += 4u;
    goto label_000BA300;
    label_000BA264:
    cpu->eax = cpu->esi + 0x178u;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) < 0x10u) goto label_000BA275;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BA275:
    cpu->ecx = (uintptr_t)"";
    label_000BA280:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000BA2A0;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000BA29C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000BA2A0;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BA280;
    label_000BA29C:
    cpu->eax = 0u;
    goto label_000BA2A5;
    label_000BA2A0:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000BA2A5:
    if (cpu->eax != 0u) goto label_000BA2C7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"WindowUI(%s,%d %d). Window name not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA2BEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BA2BEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA2C4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA2C4u));
    cpu->esp += 0x14u;
    label_000BA2C7:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA2E3u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA2E3u));
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor);
    if (cpu->edx < 1u) goto label_000BA356;
    g_sfera_interface_core_runtime.free_list_a_cursor = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_000BA300:
    cpu->edx = cpu->esp + 0x10u;
    { const uint32_t __parser_arg_019_4_0 = static_cast<uint32_t>(cpu->edx); const uint32_t __parser_arg_019_4_1 = static_cast<uint32_t>((uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_4_1)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_4_0))) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000BA225;
    label_000BA319:
    cpu->edx = 0x209u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA328u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA328u));
    if (cpu->edi == 0u) goto label_000BA33C;
    cpu->ecx = cpu->edi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->release(); }
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA339u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BA339u));
    cpu->esp += 4u;
    label_000BA33C:
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BA356:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA356u); throw std::length_error("std::length_error");
}
__declspec(noinline) void sfera_sub_004BA370(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x264u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x270u;
    cpu->ecx = (uintptr_t)"Effects\\*.ui";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA3B9u)); sfera_sub_00425950(cpu, LIFT_CODE_TOKEN_VA(0x4BA3B9u));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Effects\\*.ui");
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x4BA3C7u));
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    x87_v1 = 1.0;
    cpu->esi = cpu->eax;
    x87_v0 = x87_v1 / x87_v0; 
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != 0xFFFFFFFFu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = (double)(0.0);
    if (cpu->eax == 0u) goto label_000BA647;
    label_000BA3F5:
    if (((*(uint8_t*)(cpu->esp + 0x24u)) & (0x10u)) != 0u) goto label_000BA633;
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, (uintptr_t)"loadscreen.ui"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BA40Au));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000BA633;
    cpu->eax = 0x5C737463u;
    cpu->edx = 0x65666645u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->eax;
    cpu->eax = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->esp + 0x164u) = cpu->edx;
    *(uint8_t*)(cpu->esp + 0x16Cu) = cpu->ecx & 0xFFu;
    cpu->esi = cpu->eax;
    label_000BA447:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BA447;
    cpu->edi = cpu->esp + 0x164u;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_000BA458:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000BA458;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->edx = 0x1E6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA47Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA47Du));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA487u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4BA487u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x278u) = 0u;
    if (cpu->eax == 0u) goto label_000BA4A8;
    cpu->ecx = cpu->eax;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->initialize(); cpu->eax = cpu->ecx; }
    cpu->edi = cpu->eax;
    goto label_000BA4AA;
    label_000BA4A8:
    cpu->edi = 0u;
    label_000BA4AA:
    cpu->edx = cpu->esp + 0x164u;
    { const uint32_t __parser_arg_019_7_0 = static_cast<uint32_t>(cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x278u) = 0xFFFFFFFFu;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->load(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_7_0))); }
    { const uint32_t __parser_arg_019_8_0 = static_cast<uint32_t>(0u);
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setBlockRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_8_0))); }
    cpu->eax = cpu->esp + 0x14u;
    { const uint32_t __parser_arg_019_9_0 = static_cast<uint32_t>(cpu->eax); const uint32_t __parser_arg_019_9_1 = static_cast<uint32_t>((uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_9_1)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_9_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000BA5E6;
    label_000BA4E6:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA4EDu)); sfera_ui_create_control(cpu, LIFT_CODE_TOKEN_VA(0x4BA4EDu));
    cpu->esi = cpu->eax;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x16Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->loadUi(reinterpret_cast<const char*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp))), *reinterpret_cast<SferaSimpleParser*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 4u))), *reinterpret_cast<const SferaParserRange*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp + 8u)))); cpu->esp += 12u;
    if (cpu->eax != 0u) goto label_000BA52C;
    cpu->edx = 0x1F7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA51Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA51Cu));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { auto* destroyed_window = reinterpret_cast<SphereUI::Window*>(cpu->ecx); destroyed_window->destroy((*(uint32_t*)(cpu->esp) & 1u) != 0u); cpu->eax = address32(destroyed_window); } cpu->esp += 4u;
    goto label_000BA5CD;
    label_000BA52C:
    cpu->eax = cpu->esi + 0x178u;
    if (*(uint32_t*)(cpu->esi + 0x18Cu) < 0x10u) goto label_000BA53D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BA53D:
    cpu->ecx = (uintptr_t)"";
    label_000BA542:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000BA562;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000BA55E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000BA562;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BA542;
    label_000BA55E:
    cpu->eax = 0u;
    goto label_000BA567;
    label_000BA562:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000BA567:
    if (cpu->eax != 0u) goto label_000BA590;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x16Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"WindowUI(%s,%d %d). Window name not specified.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA587u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BA587u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA58Du)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA58Du));
    cpu->esp += 0x14u;
    label_000BA590:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.free_list_a;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA5ACu)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA5ACu));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor);
    if (cpu->ecx < 1u) goto label_000BA671;
    g_sfera_interface_core_runtime.free_list_a_cursor = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.free_list_a_cursor)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_000BA5CD:
    cpu->eax = cpu->esp + 0x14u;
    { const uint32_t __parser_arg_019_10_0 = static_cast<uint32_t>(cpu->eax); const uint32_t __parser_arg_019_10_1 = static_cast<uint32_t>((uintptr_t)"windowUI");
    cpu->ecx = cpu->edi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_10_1)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_10_0))) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000BA4E6;
    label_000BA5E6:
    cpu->edx = 0x209u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA5F5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BA5F5u));
    if (cpu->edi == 0u) goto label_000BA609;
    cpu->ecx = cpu->edi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->release(); }
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA606u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BA606u));
    cpu->esp += 4u;
    label_000BA609:
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esp + 0xCu))) + (((double)*(float*)(cpu->esp + 0x20u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v1 = 30.0;
    x87_v0 = (x87_v0) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA62Fu)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BA62Fu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000BA633:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x4BA639u));
    if (cpu->eax != 0u) goto label_000BA3F5;
    label_000BA647:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x4BA648u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA671:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA671u); throw std::length_error("std::length_error");
}
__declspec(noinline) void sfera_sub_004BA6B0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->esp -= 0xCu;
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_000BA6C6;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA6C6:
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA6D5u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4BA6D5u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx == 0u) goto label_000BA6DD;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_000BA6DD:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edx > cpu->eax) goto label_000BA6E9;
    cpu->eax -= cpu->edx;
    label_000BA6E9:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->edi += 28u;
    sub_pred[1] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) == 0u;
    cpu->ecx = 1u;
    cpu->esi = lift_pop32(cpu);
    if (sub_pred[1]) goto label_000BA736;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    cpu->eax += cpu->ecx;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin > cpu->eax) goto label_000BA724;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = 0u;
    label_000BA724:
    if ((g_sfera_interface_core_runtime.queue_cursor -= cpu->ecx) != 0u) goto label_000BA736;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = 0u;
    label_000BA736:
    g_sfera_interface_core_runtime.state_01 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    cpu->eax = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    if (cpu->ecx == 0u) goto label_000BA7DD;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    if (cpu->eax == cpu->edx) goto label_000BA7DD;
    label_000BA768:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BA775;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BA768;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA775:
    if (cpu->eax == cpu->edx) goto label_000BA7DD;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA78Fu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BA78Fu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 4u;
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA7B4u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA7B4u));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->ecx >= 1u) goto label_000BA7CF;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA775u); throw std::length_error("std::length_error");
    label_000BA7CF:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_000BA7DD:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA7E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    if (cpu->eax == cpu->edx) goto label_000BA865;
    label_000BA7F0:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BA7FD;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BA7F0;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BA7FD:
    if (cpu->eax == cpu->edx) goto label_000BA865;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA817u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BA817u));
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esp += 4u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA83Bu)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BA83Bu));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->ecx >= 1u) goto label_000BA856;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BA7FDu); throw std::length_error("std::length_error");
    label_000BA856:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_000BA865:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_000BA8FE;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    (void)cpu;
    label_000BA8D0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA8DCu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BA8DCu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA8ECu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BA8ECu));
    cpu->esi += 0x38u;
    cpu->edi += 0x38u;
    if (cpu->esi != cpu->ebx) goto label_000BA8D0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BA8FE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BA910(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x4Cu;
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    cpu->edi = cpu->ebx + 0x10u;
    if (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0] == (cpu->ebx & 0xFFu)) goto label_000BA9C6;
    lift_push32(cpu, (uintptr_t)"_e"); lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BA96Eu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000BA9C6;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_000BA980:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BA980;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA994u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BA994u));
    cpu->eax = (uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    cpu->edx = cpu->eax + 1u;
    label_000BA9A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BA9A0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA9B8u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4BA9B8u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (*(uint32_t*)(cpu->esp + 0x40u) >= cpu->edi) goto label_000BA9C6;
    cpu->esi = cpu->esp + 0x2Cu;
    label_000BA9C6:
    lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"Effects\\");
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BA9E6u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BA9E6u));
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x54u) = 1u;
    cpu->edx = cpu->eax + 1u;
    label_000BA9F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BA9F0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA04u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4BAA04u));
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)".sfn");
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA14u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4BAA14u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->esp + 0x24u) >= cpu->edi) goto label_000BAA22;
    cpu->ecx = cpu->esp + 0x10u;
    label_000BAA22:
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA29u)); sfera_sub_004A5540(cpu, LIFT_CODE_TOKEN_VA(0x4BAA29u));
    if (cpu->eax != 0u) goto label_000BAA41;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Can't load font '%s'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA38u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAA38u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA3Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BAA3Eu));
    cpu->esp += 0xCu;
    label_000BAA41:
    if (*(uint32_t*)(cpu->esp + 0x24u) < cpu->edi) goto label_000BAA54;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA51u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BAA51u));
    cpu->esp += 4u;
    label_000BAA54:
    *(uint32_t*)(cpu->esp + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x40u) < cpu->edi) goto label_000BAA77;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAA74u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BAA74u));
    cpu->esp += 4u;
    label_000BAA77:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BAAA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x114u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, 0x3Au); lift_push32(cpu, cpu->ebx);
    cpu->edi = cpu->edx;
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4BAABEu));
    cpu->esp += 8u;
    cpu->ecx = cpu->ebx;
    if (cpu->eax == 0u) goto label_000BAAE7;
    cpu->esi = cpu->esp + 0x1Cu;
    cpu->esi -= cpu->ebx;
    label_000BAAD3:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BAAD3;
    cpu->eax -= cpu->ebx;
    *(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu) = cpu->edx & 0xFFu;
    cpu->ecx = cpu->esp + 0x1Cu;
    label_000BAAE7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAAECu)); sfera_sub_004B9850(cpu, LIFT_CODE_TOKEN_VA(0x4BAAECu));
    if (cpu->eax == 0u) goto label_000BACC5;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->ebp);
    cpu->eax = address32(reinterpret_cast<SphereUI::Window*>(cpu->ecx)->clone());
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if (cpu->ebp != 0u) goto label_000BAB1C;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CreateWindow(%s) -> Can't create reference class");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB13u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAB13u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB19u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BAB19u));
    cpu->esp += 0xCu;
    label_000BAB1C:
    cpu->edx = cpu->ebx;
    if (cpu->ebx != 0u) goto label_000BAB27;
    cpu->edx = (uintptr_t)"";
    label_000BAB27:
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_000BAB30:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BAB30;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB43u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BAB43u));
    if (((*(uint8_t*)(cpu->esp + 0x12Cu)) & (1u)) == 0u) goto label_000BAB65;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x128u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(static_cast<std::int32_t>(*(uint32_t*)(cpu->esp)), static_cast<std::int32_t>(*(uint32_t*)(cpu->esp + 4u))); cpu->esp += 8u;
    goto label_000BAC2C;
    label_000BAB65:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x17u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAB76u)); sfera_sub_004B92D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAB76u));
    if (cpu->eax == 0u) goto label_000BAB9D;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    cpu->ecx += 0xFFFFFFF1u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) < (int32_t)cpu->ecx) goto label_000BAB98;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->edx += 0xFFFFFFF1u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) >= (int32_t)cpu->edx) goto label_000BAB9D;
    label_000BAB98:
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    label_000BAB9D:
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == cpu->edi) goto label_000BABF1;
    label_000BABB0:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 0x178u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_000BABC0;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BABC0:
    cpu->ecx = cpu->ebx;
    label_000BABC2:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000BABE2;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000BABDE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000BABE2;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BABC2;
    label_000BABDE:
    cpu->eax = 0u;
    goto label_000BABE7;
    label_000BABE2:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000BABE7:
    if (cpu->eax == 0u) goto label_000BAC14;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != cpu->edi) goto label_000BABB0;
    label_000BABF1:
    if (*(uint8_t*)(cpu->esp + 0x13u) == 0u) goto label_000BAC14;
    if (*(uint8_t*)(cpu->ebp + 0x4Eu) == 0u) goto label_000BAC14;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->setPosition(static_cast<std::int32_t>(*(uint32_t*)(cpu->esp)), static_cast<std::int32_t>(*(uint32_t*)(cpu->esp + 4u))); cpu->esp += 8u;
    goto label_000BAC2C;
    label_000BAC14:
    if (((*(uint8_t*)(cpu->esp + 0x12Cu)) & (8u)) == 0u) goto label_000BAC25;
    *(uint32_t*)(cpu->ebp + 0x38u) = 0x24u;
    label_000BAC25:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBAC2Cu)); sfera_ui_window_align_to_screen(cpu, LIFT_CODE_TOKEN_RVA(0xBAC2Cu));
    label_000BAC2C:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x12Cu));
    if ((((cpu->eax & 0xFFu)) & (2u)) != 0u) goto label_000BAC3B;
    *(uint8_t*)(cpu->ebp + 0x48u) = 0u;
    label_000BAC3B:
    if (*(uint8_t*)(cpu->ebp + 0x48u) != 0u) goto label_000BAC4E;
    if ((((cpu->eax & 0xFFu)) & (4u)) != 0u) goto label_000BAC4E;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBAC4Eu)); sfera_ui_window_start_animation(cpu, LIFT_CODE_TOKEN_RVA(0xBAC4Eu));
    label_000BAC4E:
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->ebp + 0x4Au) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAC59u)); sfera_sub_004B9D00(cpu, LIFT_CODE_TOKEN_VA(0x4BAC59u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xACu);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000BAC7E;
    label_000BAC65:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x79u);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->ebp + 0xACu)) goto label_000BAC65;
    label_000BAC7E:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAC9Au)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BAC9Au));
    cpu->ecx = 0x3FFFFFFEu;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->ecx >= 1u) goto label_000BACB5;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BAC7Eu); throw std::length_error("std::length_error");
    label_000BACB5:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    label_000BACC5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x114u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BACE0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx == 0u) goto label_000BAD0B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    if (cpu->edx != 0u) goto label_000BACF1;
    cpu->esi = (uintptr_t)"";
    label_000BACF1:
    cpu->eax = cpu->esi;
    cpu->edi = cpu->eax + 1u;
    label_000BACF6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000BACF6;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx += 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD09u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BAD09u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BAD0B:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BAD10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->edi != 0u) goto label_000BAD59;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    if (cpu->eax == 0u) goto label_000BAE50;
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->eax + 0xD8u) == cpu->ecx) goto label_000BAD43;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD3Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BAD3Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD40u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BAD40u));
    cpu->esp += 0xCu;
    label_000BAD43:
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD4Cu)); sfera_ui_window_begin_close(cpu, LIFT_CODE_TOKEN_VA(0x4BAD4Cu));
    cpu->edi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BAD59:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD5Eu)); sfera_sub_004B9350(cpu, LIFT_CODE_TOKEN_VA(0x4BAD5Eu));
    if (cpu->eax == 0u) goto label_000BAE50;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    if (cpu->eax != 0u) goto label_000BAD8E;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"help";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BAD7Du)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4BAD7Du));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05) = cpu->eax;
    SphereUI::bindEventHandler(reinterpret_cast<SphereUI::Window*>(cpu->eax), SphereUI::WindowEventHandler::help);
    goto label_000BADB1;
    label_000BAD8E:
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count == 0u) goto label_000BADA5;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (*(uint32_t*)(cpu->edx + 8u) == cpu->eax) goto label_000BADB1;
    label_000BADA5:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BADACu)); sfera_sub_004BA750(cpu, LIFT_CODE_TOKEN_VA(0x4BADACu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    label_000BADB1:
    if (cpu->eax == 0u) goto label_000BAE50;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BADCFu)); sfera_sub_004AEE90(cpu, LIFT_CODE_TOKEN_VA(0x4BADCFu));
    if (cpu->eax == 0u) goto label_000BADE2;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4BADD5u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000BAE50;
    label_000BADE2:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BADE9u)); sfera_sub_004AF340(cpu, LIFT_CODE_TOKEN_VA(0x4BADE9u));
    lift_push32(cpu, 0u);
    if ((cpu->eax & 0xFFu) != 0u) goto label_000BAE21;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    cpu->eax = *(uint32_t*)(cpu->edx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 1u); lift_push32(cpu, 0x70u);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xA8Fu);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BAE21:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_05;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x70u);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xA8Fu);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BAE50:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BAFB0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[3];
    cpu->esp -= 0x60u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    if (cpu->ebx != 0x7Bu) goto label_000BAFE3;
    if (g_sfera_direct_input_runtime.keyboard_state[0x1D] == 0u) goto label_000BAFF4;
    g_sfera_interface_runtime.primary_gate = (uint8_t)(g_sfera_interface_runtime.primary_gate) == 0u;
    goto label_000BAFF4;
    label_000BAFE3:
    if (cpu->ebx != 0x70u) goto label_000BAFF4;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uintptr_t)"Language\\helpindex.hts";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBAFF4u)); sfera_sub_004BAD10(cpu, LIFT_CODE_TOKEN_RVA(0xBAFF4u));
    label_000BAFF4:
    if (g_sfera_interface_runtime.primary_gate == 0u) goto label_000BB737;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if (g_sfera_client_process_runtime.ui_bridge == cpu->esi) goto label_000BB039;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state;
    if (cpu->ecx == cpu->esi) goto label_000BB039;
    if (g_sfera_interface_core_runtime.capture_control_binding == 0u) goto label_000BB039;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x50u) = 0xFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB031u)); sfera_ui_handle_control_options_event(cpu, LIFT_CODE_TOKEN_RVA(0xBB031u));
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state) = cpu->esi;
    label_000BB039:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB03Eu)); sfera_ui_description_window_has_instance(cpu, LIFT_CODE_TOKEN_VA(0x4BB03Eu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB04E;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB047u)); sfera_ui_description_window_instance(cpu, LIFT_CODE_TOKEN_VA(0x4BB047u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB04Eu)); sfera_ui_description_window_update(cpu, LIFT_CODE_TOKEN_RVA(0xBB04Eu));
    label_000BB04E:
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB054u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x4BB054u));
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x14u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint8_t*)(cpu->esp + 0x45u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->eax&=1u; lift_test[0]=cpu->eax==0u;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)g_sfera_interface_runtime.previous_input_modifiers));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->ebx = 4u;
    if (lift_test[0]) goto label_000BB0B3;
    if ((((cpu->edx & 0xFFu)) & (1u)) != 0u) goto label_000BB0B3;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 1u;
    goto label_000BB0C0;
    label_000BB0B3:
    if (cpu->eax != cpu->esi) goto label_000BB0C0;
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000BB0C0;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    label_000BB0C0:
    cpu->esi = 2u;
    cpu->eax = cpu->ecx;
    cpu->eax&=cpu->esi; lift_test[1]=cpu->eax==0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 6u;
    if (lift_test[1]) goto label_000BB0DA;
    if ((((cpu->edx & 0xFFu)) & (2u)) != 0u) goto label_000BB0DA;
    *(uint32_t*)(cpu->esp + 0x40u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x40u)) | (uint64_t)(cpu->esi);
    goto label_000BB0E7;
    label_000BB0DA:
    if (cpu->eax != 0u) goto label_000BB0E7;
    if ((((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_000BB0E7;
    *(uint32_t*)(cpu->esp + 0x40u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x40u)) | (uint64_t)(cpu->edi);
    label_000BB0E7:
    sub_pred[1] = (uint8_t)(g_sfera_direct_input_runtime.keyboard_state[0x2A]) == 0u;
    g_sfera_interface_runtime.previous_input_modifiers = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0u;
    if (sub_pred[1]) goto label_000BB106;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 1u;
    label_000BB106:
    if (g_sfera_direct_input_runtime.keyboard_state[0x36] == 0u) goto label_000BB113;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->esi);
    label_000BB113:
    if (g_sfera_direct_input_runtime.keyboard_state[0x1D] == 0u) goto label_000BB120;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->ebx);
    label_000BB120:
    if (g_sfera_direct_input_runtime.modifier_08 == 0u) goto label_000BB12D;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(cpu->edi);
    label_000BB12D:
    if (g_sfera_direct_input_runtime.keyboard_state[0x38] == 0u) goto label_000BB13B;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(0x10u);
    label_000BB13B:
    if (g_sfera_direct_input_runtime.modifier_20 == 0u) goto label_000BB149;
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) | (uint64_t)(0x20u);
    label_000BB149:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ebx = *(uint32_t*)(cpu->edx);
    if (cpu->ebx == cpu->edx) goto label_000BB245;
    label_000BB160:
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ebp = *(uint32_t*)(cpu->ebx);
    if (*(uint8_t*)(cpu->edi + 0xE1u) == 0u) goto label_000BB237;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xACu);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_000BB1C3;
    label_000BB180:
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax == cpu->edx) goto label_000BB1B9;
    label_000BB190:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BB19D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BB190;
    goto label_000BB1B9;
    label_000BB19D:
    if (*(uint8_t*)(cpu->ecx + 0xE0u) != 0u) goto label_000BB1B9;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x78u);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB1B9:
    cpu->esi = *(uint32_t*)(cpu->esi);
    if (cpu->esi != *(uint32_t*)(cpu->edi + 0xACu)) goto label_000BB180;
    label_000BB1C3:
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    if (*(uint32_t*)(cpu->edi + 0xD8u) == 0u) goto label_000BB1E9;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"DestroWindowUI(0x%X) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB1DAu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB1DAu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB1E0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB1E0u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 0xCu;
    label_000BB1E9:
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->ebx = cpu->edx;
    if (cpu->esi == cpu->edx) goto label_000BB217;
    label_000BB1F1:
    if (*(uint32_t*)(cpu->esi + 8u) != cpu->edi) goto label_000BB211;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB206u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BB206u));
    cpu->esp += 4u;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    goto label_000BB213;
    label_000BB211:
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_000BB213:
    if (cpu->esi != cpu->ebx) goto label_000BB1F1;
    label_000BB217:
    cpu->edx = 0x283u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB226u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB226u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { auto* destroyed_window = reinterpret_cast<SphereUI::Window*>(cpu->ecx); destroyed_window->destroy((*(uint32_t*)(cpu->esp) & 1u) != 0u); cpu->eax = address32(destroyed_window); } cpu->esp += 4u;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB237:
    cpu->ebx = cpu->ebp;
    if (cpu->ebp != cpu->edx) goto label_000BB160;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    label_000BB245:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ebx) goto label_000BB2C5;
    label_000BB255:
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000BB2B9;
    if (*(uint8_t*)(cpu->esi + 0x10Cu) != 0u) goto label_000BB2C1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->ecx == cpu->eax) goto label_000BB28D;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB28Du)); sfera_ui_window_get_absolute_position(cpu, LIFT_CODE_TOKEN_RVA(0xBB28Du));
    label_000BB28D:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax > (int32_t)cpu->ebp) goto label_000BB2B9;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edx) goto label_000BB2B9;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    if ((int32_t)cpu->ecx > (int32_t)cpu->eax) goto label_000BB2B9;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_000BB2C1;
    label_000BB2B9:
    cpu->eax = cpu->edi;
    if (cpu->eax != cpu->ebx) goto label_000BB255;
    goto label_000BB2C5;
    label_000BB2C1:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_000BB2C5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB2CAu)); sfera_ui_description_window_has_instance(cpu, LIFT_CODE_TOKEN_VA(0x4BB2CAu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB30B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB2D3u)); sfera_ui_description_window_instance(cpu, LIFT_CODE_TOKEN_VA(0x4BB2D3u));
    if (*(uint8_t*)(cpu->eax + 0x48u) != 0u) goto label_000BB30B;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->esi) goto label_000BB311;
    label_000BB2F0:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (*(uint8_t*)(cpu->ecx + 0x10Cu) != 0u) goto label_000BB305;
    if (cpu->eax != cpu->esi) goto label_000BB2F0;
    goto label_000BB311;
    label_000BB305:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    goto label_000BB311;
    label_000BB30B:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB311:
    if (((*(uint8_t*)(cpu->esp + 0x40u)) & (1u)) == 0u) goto label_000BB3BC;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx == 0u) goto label_000BB3BC;
    if (*(uint8_t*)(cpu->ecx + 0x4Du) == 0u) goto label_000BB3BC;
    if (*(uint8_t*)(cpu->ecx + 0x4Fu) != 0u) goto label_000BB3BC;
    if (*(uint8_t*)(cpu->ecx + 0x48u) != 0u) goto label_000BB3BC;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (cpu->eax == cpu->edx) goto label_000BB37D;
    label_000BB348:
    if (*(uint32_t*)(cpu->eax + 8u) == cpu->ecx) goto label_000BB355;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->edx) goto label_000BB348;
    goto label_000BB37D;
    label_000BB355:
    if (cpu->eax == cpu->edx) goto label_000BB37D;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB36Eu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BB36Eu));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->esp += 4u;
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) - 1u;
    label_000BB37D:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->esi = cpu->edx + 4u;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.list_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB394u)); sfera_sub_004B9190(cpu, LIFT_CODE_TOKEN_VA(0x4BB394u));
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count);
    if (cpu->edx >= 1u) goto label_000BB3AF;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BB37Du); throw std::length_error("std::length_error");
    label_000BB3AF:
    g_sfera_interface_core_runtime.list_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count)) + 1u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_000BB3BC:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB3C1u)); sfera_ui_description_window_has_instance(cpu, LIFT_CODE_TOKEN_VA(0x4BB3C1u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB3EE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB3CAu)); sfera_ui_description_window_instance(cpu, LIFT_CODE_TOKEN_VA(0x4BB3CAu));
    if (*(uint8_t*)(cpu->eax + 0x48u) != 0u) goto label_000BB3EE;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_count == 0u) goto label_000BB3E7;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint32_t*)(cpu->ecx + 8u) == cpu->eax) goto label_000BB3EE;
    label_000BB3E7:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB3EEu)); sfera_sub_004BA750(cpu, LIFT_CODE_TOKEN_RVA(0xBB3EEu));
    label_000BB3EE:
    sub_pred[2] = (uint8_t)(*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) == 0u;
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    if (sub_pred[2]) goto label_000BB5EE;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000BB481;
    cpu->ebx = 0x6Eu;
    cpu->ebp = 0u;
    label_000BB412:
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint8_t*)(cpu->esi + 0x4Cu) == 0u) goto label_000BB477;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000BB44B;
    if (((*(uint8_t*)(cpu->esi + 0x94u)) & (2u)) != 0u) goto label_000BB477;
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB442u)); sfera_ui_window_queue_event(cpu, LIFT_CODE_TOKEN_VA(0x4BB442u));
    *(uint32_t*)(cpu->esi + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x94u)) | (uint64_t)(2u);
    goto label_000BB477;
    label_000BB44B:
    if (((*(uint8_t*)(cpu->esi + 0x94u)) & (2u)) == 0u) goto label_000BB477;
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0x6Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB470u)); sfera_ui_window_queue_event(cpu, LIFT_CODE_TOKEN_VA(0x4BB470u));
    *(uint32_t*)(cpu->esi + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x94u)) & (uint64_t)(0xFFFFFFFDu);
    label_000BB477:
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head) goto label_000BB412;
    label_000BB481:
    if (((*(uint8_t*)(cpu->esp + 0x40u)) & (4u)) == 0u) goto label_000BB5EE;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = 0u;
    if (cpu->ecx == cpu->esi) goto label_000BB4B5;
    if (*(uint8_t*)(cpu->ecx + 0x4Cu) == 0u) goto label_000BB4B5;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->hitTest(static_cast<std::int32_t>(*(uint32_t*)(cpu->esp)), static_cast<std::int32_t>(*(uint32_t*)(cpu->esp + 4u))); cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000BB599;
    label_000BB4B5:
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) < 0x40u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = 0xDu;
    if (sub_pred[0]) goto label_000BB514;
    if (cpu->ecx == cpu->esi) goto label_000BB50E;
    label_000BB4F3:
    ++cpu->eax;
    if (cpu->edx > cpu->eax) goto label_000BB4FA;
    cpu->eax = 0u;
    label_000BB4FA:
    if ((--cpu->ecx) != 0u) goto label_000BB4FF;
    cpu->eax = 0u;
    label_000BB4FF:
    if (cpu->ecx != cpu->esi) goto label_000BB4F3;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = cpu->ecx;
    label_000BB50E:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01) = cpu->esi;
    label_000BB514:
    cpu->esi = cpu->ecx + 1u;
    if (cpu->edx > cpu->esi) goto label_000BB538;
    lift_push32(cpu, 1u);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.queue_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB527u)); sfera_sub_0049FBD0(cpu, LIFT_CODE_TOKEN_VA(0x4BB527u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_end;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_begin;
    label_000BB538:
    cpu->esi = cpu->eax + cpu->ecx;
    if (cpu->edx > cpu->esi) goto label_000BB541;
    cpu->esi -= cpu->edx;
    label_000BB541:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    if (*(uint32_t*)(cpu->edx + (cpu->esi * 4u)) != 0u) goto label_000BB56E;
    lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB554u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4BB554u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000BB623;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->eax;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    label_000BB56E:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_state;
    cpu->edi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->edi == 0u) goto label_000BB58C;
    cpu->esi = cpu->esp + 0x50u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),28u); cpu->esi += 28u;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor;
    label_000BB58C:
    ++cpu->ecx;
    g_sfera_interface_core_runtime.state_01 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_01)) + 1u;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.queue_cursor) = cpu->ecx;
    label_000BB599:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->edi == cpu->eax) goto label_000BB5E9;
    cpu->ebp = 0xFFFFFFFDu;
    cpu->ebx = cpu->ebp + 0x72u;
    label_000BB5B0:
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (((*(uint8_t*)(cpu->esi + 0x94u)) & (2u)) == 0u) goto label_000BB5E3;
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = 0u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB5D8u)); sfera_ui_window_queue_event(cpu, LIFT_CODE_TOKEN_VA(0x4BB5D8u));
    *(uint32_t*)(cpu->esi + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x94u)) & (uint64_t)(cpu->ebp);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    label_000BB5E3:
    cpu->edi = *(uint32_t*)(cpu->edi);
    if (cpu->edi != cpu->eax) goto label_000BB5B0;
    label_000BB5E9:
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    label_000BB5EE:
    if (*(uint8_t*)(cpu->esp + 0x48u) != 0x1Bu) goto label_000BB677;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->edi) goto label_000BB677;
    label_000BB604:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx >>= 3u;
    if ((((cpu->edx & 0xFFu)) & (1u)) == 0u) goto label_000BB61B;
    if (*(uint8_t*)(cpu->esi + 0x48u) == 0u) goto label_000BB651;
    label_000BB61B:
    cpu->eax = cpu->ecx;
    if (cpu->eax != cpu->edi) goto label_000BB604;
    goto label_000BB677;
    label_000BB623:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB651u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0xBB651u));
    label_000BB651:
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x54u) = 0u;
    *(uint32_t*)(cpu->esp + 0x58u) = 0x64u;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB677u)); sfera_ui_window_queue_event(cpu, LIFT_CODE_TOKEN_RVA(0xBB677u));
    label_000BB677:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    cpu->eax = 0u;
    g_sfera_texture_cache_runtime.render_gate = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if (cpu->edi == *(uint32_t*)(cpu->edi)) goto label_000BB70E;
    label_000BB6A0:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000BB6B4;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    label_000BB6B4:
    if (*(uint8_t*)(cpu->esi + 0x4Au) == 0u) goto label_000BB6D2;
    if (*(uint8_t*)(cpu->esi + 0x48u) != 0u) goto label_000BB6D2;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleInput(*reinterpret_cast<const SphereUI::WindowInput*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    label_000BB6D2:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_000BB6E2;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    label_000BB6E2:
    if (*(uint8_t*)(cpu->esi + 0xE0u) == 0u) goto label_000BB6F2;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB6F2u)); sfera_ui_window_update_animation(cpu, LIFT_CODE_TOKEN_RVA(0xBB6F2u));
    label_000BB6F2:
    if (!SphereUI::hasEventHandler(reinterpret_cast<SphereUI::Window*>(cpu->esi))) goto label_000BB702;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB702u)); sfera_ui_window_process_events(cpu, LIFT_CODE_TOKEN_RVA(0xBB702u));
    label_000BB702:
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.list_head;
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_000BB6A0;
    label_000BB70E:
    if (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.text_object_ready != 0u) goto label_000BB726;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.text_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBB726u)); sfera_ui_tool_tip_ctrl_handle_input(cpu, LIFT_CODE_TOKEN_RVA(0xBB726u));
    label_000BB726:
    if (*(uint8_t*)(cpu->esp + 0x13u) == 0u) goto label_000BB734;
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = 0u;
    label_000BB734:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000BB737:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x60u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BB750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi >= 0x64u) goto label_000BB786;
    if (cpu->esi == 0xAu) goto label_000BB7E6;
    if (cpu->esi == 0xEu) goto label_000BB7D1;
    lift_push32(cpu, 0x6A5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB77Du)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB77Du));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB783u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB783u));
    cpu->esp += 0x10u;
    label_000BB786:
    if (cpu->edi != 0u) goto label_000BB7A7;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB79Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB79Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7A4u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB7A4u));
    cpu->esp += 0x10u;
    label_000BB7A7:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7ADu)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB7ADu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7B4u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB7B4u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB7F5;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB7D1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB7DCu)); sfera_sub_004BAD10(cpu, LIFT_CODE_TOKEN_VA(0x4BB7DCu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB7E6:
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu);
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = cpu->eax & 0xFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB7F5:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BB800(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000BB852;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBE71;
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->eax + 0xD8u) == 0u) goto label_000BB837;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"DestroWindowUI(%d) -> Can't destroy controls.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB82Eu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB82Eu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB834u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB834u));
    cpu->esp += 0xCu;
    label_000BB837:
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB840u)); sfera_ui_window_begin_close(cpu, LIFT_CODE_TOKEN_VA(0x4BB840u));
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen) = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000BB852:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    cpu->esi = 0u;
    if (cpu->ecx != cpu->esi) goto label_000BB87F;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"loadscreen";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB86Du)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB86Du));
    cpu->ecx = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB879u)); sfera_sub_004BA7E0(cpu, LIFT_CODE_TOKEN_VA(0x4BB879u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    label_000BB87F:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x74u);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x7Au);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    cpu->ebx = 0x400u;
    cpu->edi = 0x300u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_000BB8CC;
    cpu->eax = cpu->ebp + 0xFFFFFC00u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_000BB8D2;
    label_000BB8CC:
    cpu->ebx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    label_000BB8D2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    if ((int32_t)cpu->eax <= (int32_t)0x300u) goto label_000BB8ED;
    cpu->eax += 0xFFFFFD00u;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_000BB8F3;
    label_000BB8ED:
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_000BB8F3:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == cpu->esi) goto label_000BB90D;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BB92A;
    label_000BB90D:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB921u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB921u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB927u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB927u));
    cpu->esp += 0x10u;
    label_000BB92A:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB930u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB930u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB937u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB937u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB950;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BB950:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBAB5;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BB98B;
    label_000BB96E:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB982u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB982u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB988u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB988u));
    cpu->esp += 0x10u;
    label_000BB98B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB991u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB991u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB998u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB998u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BB9A9;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BB9A9:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBABC;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BB9E2;
    label_000BB9C5:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9D9u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BB9D9u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9DFu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BB9DFu));
    cpu->esp += 0x10u;
    label_000BB9E2:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9E8u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BB9E8u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BB9EFu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BB9EFu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBA02;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBA02:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBAC3;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBA3B;
    label_000BBA1E:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA32u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA32u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA38u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA38u));
    cpu->esp += 0x10u;
    label_000BBA3B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA41u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBA41u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA48u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA48u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBA5D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBA5D:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (*(uint8_t*)(cpu->esp + 0x34u) == 0u) goto label_000BBACE;
    if (cpu->eax == 0u) goto label_000BBACA;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBA9B;
    label_000BBA7E:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA92u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA92u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBA98u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBA98u));
    cpu->esp += 0x10u;
    label_000BBA9B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA1u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA8u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBAA8u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBB26;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"english_sphere1");
    goto label_000BBB18;
    label_000BBAB5:
    cpu->esi = 0u;
    goto label_000BB96E;
    label_000BBABC:
    cpu->esi = 0u;
    goto label_000BB9C5;
    label_000BBAC3:
    cpu->esi = 0u;
    goto label_000BBA1E;
    label_000BBACA:
    cpu->esi = 0u;
    goto label_000BBA7E;
    label_000BBACE:
    if (cpu->eax == 0u) goto label_000BBB40;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBB00;
    label_000BBAE3:
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAF7u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBAF7u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBAFDu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBAFDu));
    cpu->esp += 0x10u;
    label_000BBB00:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB06u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBB06u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB0Du)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBB0Du));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBB26;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"russian_sphere1");
    label_000BBB18:
    lift_push32(cpu, 0xA29u);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBB26:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBB44;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    goto label_000BBB46;
    label_000BBB40:
    cpu->esi = 0u;
    goto label_000BBAE3;
    label_000BBB44:
    cpu->esi = 0u;
    label_000BBB46:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    cpu->eax = 0xE7Fu;
    *(double*)(cpu->esp + 0x24u) = x87_v0;
    x87_v0 = (x87_v0) * (0.3701171875);
    *(uint64_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->esi != 0u) goto label_000BBB9B;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB92u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBB92u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBB98u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBB98u));
    cpu->esp += 0x10u;
    label_000BBB9B:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA1u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA8u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBBA8u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBBEB;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.83203125);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBBEB:
    x87_v0 = *(double*)(cpu->esp + 0x24u);
    x87_v0 = (x87_v0) * (0.2490234375);
    cpu->eax = 0xE7Fu;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->esi != 0u) goto label_000BBC38;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC2Fu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC2Fu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC35u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC35u));
    cpu->esp += 0x10u;
    label_000BBC38:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC3Eu)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBC3Eu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC45u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC45u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBC82;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.0247395833);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, 0x7Au);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBC82:
    if (cpu->esi != 0u) goto label_000BBCA3;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBC9Au)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBC9Au));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA0u));
    cpu->esp += 0x10u;
    label_000BBCA3:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA9u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBCA9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCB0u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBCB0u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBCC6;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x64u); lift_push32(cpu, 0x7D1u);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBCC6:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBCE2;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    goto label_000BBCE4;
    label_000BBCE2:
    cpu->esi = 0u;
    label_000BBCE4:
    if (cpu->esi != 0u) goto label_000BBD05;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBCFCu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBCFCu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD02u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD02u));
    cpu->esp += 0x10u;
    label_000BBD05:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD0Bu)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBD0Bu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD12u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD12u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBD51;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.83203125);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBD51:
    if (cpu->esi != 0u) goto label_000BBD72;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD69u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD69u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD6Fu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD6Fu));
    cpu->esp += 0x10u;
    label_000BBD72:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD78u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBD78u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBD7Fu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBD7Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBDBC;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (0.0247395833);
    cpu->ecx = cpu->esi;
    *(uint64_t*)(cpu->esp + 0x24u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, 0x7Au);
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBDBC:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBDDA;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    goto label_000BBDDC;
    label_000BBDDA:
    cpu->esi = 0u;
    label_000BBDDC:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi += 0x177u;
    if (cpu->esi != 0u) goto label_000BBE07;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBDFEu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBDFEu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE04u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE04u));
    cpu->esp += 0x10u;
    label_000BBE07:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE0Du)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBE0Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE14u)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE14u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBE2B;
    cpu->ebp += 0x208u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x74u);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBE2B:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if (cpu->esi != 0u) goto label_000BBE4E;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE45u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE45u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE4Bu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE4Bu));
    cpu->esp += 0x10u;
    label_000BBE4E:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE54u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBE54u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBE5Bu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBE5Bu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBE71;
    lift_push32(cpu, 0x5Au); lift_push32(cpu, 0x26Cu); lift_push32(cpu, 0x7Au);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBE71:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BBE80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.load_screen;
    if (cpu->eax == 0u) goto label_000BBEF3;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->ecx >= 0) goto label_000BBE94;
    cpu->edi = 0u;
    goto label_000BBE9E;
    label_000BBE94:
    if ((int32_t)cpu->ecx <= (int32_t)0x64u) goto label_000BBE9E;
    cpu->edi = 0x64u;
    label_000BBE9E:
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA0u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->esi != 0u) goto label_000BBECF;
    lift_push32(cpu, 0x6A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBEC6u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BBEC6u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBECCu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BBECCu));
    cpu->esp += 0x10u;
    label_000BBECF:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBED5u)); sfera_sub_004D3430(cpu, LIFT_CODE_TOKEN_VA(0x4BBED5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBEDCu)); sfera_sub_004D2DA0(cpu, LIFT_CODE_TOKEN_VA(0x4BBEDCu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000BBEF1;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x7D1u);
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<SphereUI::Window*>(cpu->ecx)->handleMessage(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 4u), *(uint32_t*)(cpu->esp + 8u)); cpu->esp += 12u;
    label_000BBEF1:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_000BBEF3:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BBF00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x2Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBF32u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4BBF32u));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_000BBFB0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_000BBF85;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBF79u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BBF79u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ecx;
    label_000BBF85:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000BBFB0:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BBFD5u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4BBFD5u));
    cpu->eip = 0x4BBFD5u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004BC000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->ecx == cpu->edi) goto label_000BC058;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 0x30u;
    cpu->ebx = 0u;
    label_000BC010:
    if (*(uint32_t*)(cpu->esi) < 0x10u) goto label_000BC021;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC01Eu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC01Eu));
    cpu->esp += 4u;
    label_000BC021:
    *(uint32_t*)(cpu->esi) = 0xFu;
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xFFFFFFECu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xFFFFFFE4u) < 0x10u) goto label_000BC03F;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFD0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC03Cu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC03Cu));
    cpu->esp += 4u;
    label_000BC03F:
    *(uint32_t*)(cpu->esi + 0xFFFFFFE4u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0xFFFFFFE0u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xFFFFFFD0u) = cpu->ebx & 0xFFu;
    cpu->esi += 0x38u;
    cpu->edx = cpu->esi + 0xFFFFFFD0u;
    if (cpu->edx != cpu->edi) goto label_000BC010;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000BC058:
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC060(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    label_000BC0A0:
    if (cpu->edi == *(uint32_t*)(cpu->ebp + 0xFFFFFFECu)) goto label_000BC11A;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->ebx) goto label_000BC0E6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC0C7u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4BC0C7u));
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->edi + 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBC0E6u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0xBC0E6u));
    label_000BC0E6:
    cpu->esi += 0x38u;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    cpu->edi += 0x38u;
    goto label_000BC0A0;
    label_000BC11A:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC130(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_000BC181;
    lift_push32(cpu, cpu->ebp);
    label_000BC150:
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_000BC164;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC161u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC161u));
    cpu->esp += 4u;
    label_000BC164:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC177u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC177u));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_000BC150;
    cpu->ebp = lift_pop32(cpu);
    label_000BC181:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC290(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x160u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x174u;
    cpu->ecx = (uintptr_t)"fonts.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC2D6u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4BC2D6u));
    if (cpu->eax != 0u) goto label_000BC3F8;
    cpu->ebx = 0u;
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = (uintptr_t)"NEW_FONTS_NUMBER";
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC2F2u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4BC2F2u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0x18u) <= cpu->ebx) goto label_000BC411;
    cpu->edi = cpu->ebx + 0xFu;
    cpu->ebp = cpu->ebx + 0x10u;
    label_000BC310:
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x38u;
    sfera_u32_to_sso_decimal(cpu);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 9u); lift_push32(cpu, (uintptr_t)"NEW_FONT_");
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x184u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC342u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BC342u));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x58u;
    *(uint8_t*)(cpu->esp + 0x180u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC358u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4BC358u));
    *(uint8_t*)(cpu->esp + 0x17Cu) = 2u;
    if (*(uint32_t*)(cpu->eax + 0x14u) < cpu->ebp) goto label_000BC367;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_000BC367:
    cpu->edx = cpu->esp + 0x70u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC372u)); sfera_sub_00448880(cpu, LIFT_CODE_TOKEN_VA(0x4BC372u));
    if (*(uint32_t*)(cpu->esp + 0x68u) < cpu->ebp) goto label_000BC385;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC382u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC382u));
    cpu->esp += 4u;
    label_000BC385:
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x54u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x30u) < cpu->ebp) goto label_000BC3A4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC3A1u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC3A1u));
    cpu->esp += 4u;
    label_000BC3A4:
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x17Cu) = 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) < cpu->ebp) goto label_000BC3CE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC3CBu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC3CBu));
    cpu->esp += 4u;
    label_000BC3CE:
    cpu->ecx = cpu->esp + 0x70u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC3E3u)); sfera_sub_004BA910(cpu, LIFT_CODE_TOKEN_VA(0x4BC3E3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esp + 0x18u)) goto label_000BC310;
    goto label_000BC411;
    label_000BC3F8:
    cpu->eax = (uintptr_t)"fonts.cfg";
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"File '%s' doesn't exists.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC408u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4BC408u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC40Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4BC40Eu));
    cpu->esp += 0xCu;
    label_000BC411:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x16Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC650(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1]; double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x40u;
    cpu->ebx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11) == 0u) goto label_000BC69D;
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_10;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBC69Du)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_RVA(0xBC69Du));
    label_000BC69D:
    if (cpu->ebx == 0u) goto label_000BC807;
    if (cpu->esi == 0u) goto label_000BC807;
    if (*(uint32_t*)(cpu->esi) != 0x31564955u) goto label_000BC807;
    cpu->ebp = 0u;
    cpu->edi = cpu->esi + 4u;
    if (cpu->ebx == 0u) goto label_000BC807;
    label_000BC6C6:
    cpu->eax = 0u;
    cpu->ecx = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    if (*(uint8_t*)(cpu->edi) == (cpu->eax & 0xFFu)) goto label_000BC77B;
    goto label_000BC6EB;
    label_000BC6E7:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000BC6EB:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    if (cpu->edx <= 1u) goto label_000BC826;
    cpu->esi = cpu->eax + 1u;
    if (cpu->esi > 0xFFFFFFFEu) goto label_000BC826;
    if (cpu->ecx >= cpu->esi) goto label_000BC718;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC716u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x4BC716u));
    goto label_000BC730;
    label_000BC718:
    lift_test[0]=cpu->esi==0u;
    if (cpu->esi!=0u) goto label_000BC736;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if (cpu->ecx >= 0x10u) goto label_000BC72D;
    cpu->eax = cpu->esp + 0x18u;
    label_000BC72D:
    *(uint8_t*)(cpu->eax) = 0u;
    label_000BC730:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_test[0]=cpu->esi==0u;
    label_000BC736:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((!lift_test[0]) ? 1u : 0u) & 0xFFu);
    if ((cpu->ecx & 0xFFu) == 0u) goto label_000BC76D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) >= cpu->edx) goto label_000BC750;
    cpu->ecx = cpu->esp + 0x18u;
    label_000BC750:
    *(uint8_t*)(cpu->ecx + cpu->eax) = cpu->ebx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) >= cpu->edx) goto label_000BC765;
    cpu->eax = cpu->esp + 0x18u;
    label_000BC765:
    *(uint8_t*)(cpu->eax + cpu->esi) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_000BC76D:
    ++cpu->edi;
    if (*(uint8_t*)(cpu->edi) != 0u) goto label_000BC6E7;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000BC77B:
    x87_v0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 1u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->edi + 5u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_10;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->eax + 4u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.state_10;
    cpu->edi += 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC7BEu)); sfera_sub_004BBF00(cpu, LIFT_CODE_TOKEN_VA(0x4BC7BEu));
    cpu->ecx = 0x71C71C6u;
    cpu->ecx -= (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11);
    if (cpu->ecx < 1u) goto label_000BC831;
    g_sfera_interface_core_runtime.state_11 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_11)) + 1u;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x2Cu) < 0x10u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->ebp = cpu->edx + cpu->ebp + 9u;
    *(uint32_t*)(cpu->esp + 0x48u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_000BC7FF;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC7FCu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC7FCu));
    cpu->esp += 4u;
    label_000BC7FF:
    if (cpu->ebp < cpu->ebx) goto label_000BC6C6;
    label_000BC807:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BC826:
    lift_push32(cpu, (uintptr_t)"string too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC826u); throw std::length_error("std::length_error");
    label_000BC831:
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC831u); throw std::length_error("std::length_error");
}
__declspec(noinline) void sfera_sub_004BC840(LiftCpu* cpu, uint32_t stop_address) {
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
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->ebx <= 0x4924924u) goto label_000BC883;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC840u); throw std::length_error("std::length_error");
    label_000BC883:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= cpu->ebx) goto label_000BC92A;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC8AEu)); sfera_sub_004B8AA0(cpu, LIFT_CODE_TOKEN_VA(0x4BC8AEu));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC8CAu)); sfera_sub_004BC060(cpu, LIFT_CODE_TOKEN_VA(0x4BC8CAu));
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ecx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx == 0u) goto label_000BC904;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC8F9u)); sfera_sub_004BC000(cpu, LIFT_CODE_TOKEN_VA(0x4BC8F9u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BC901u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BC901u));
    cpu->esp += 4u;
    label_000BC904:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = cpu->eax + (cpu->ecx * 8u);
    cpu->ecx = cpu->edi * 8u;
    cpu->ecx -= cpu->edi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    cpu->edx = cpu->eax + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_000BC92A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BC960(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->esi))) >> 32u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx += cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = 0x4924924u;
    cpu->edx -= cpu->eax;
    if (cpu->edx >= cpu->esi) goto label_000BC996;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4BC960u); throw std::length_error("std::length_error");
    label_000BC996:
    cpu->esi += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->esi <= cpu->eax) goto label_000BC9DC;
    cpu->edx = cpu->eax;
    cpu->edx >>= 1u;
    cpu->edi = 0x4924924u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_000BC9C8;
    cpu->eax = 0u;
    goto label_000BC9CA;
    label_000BC9C8:
    cpu->eax += cpu->edx;
    label_000BC9CA:
    if (cpu->eax >= cpu->esi) goto label_000BC9D0;
    cpu->eax = cpu->esi;
    label_000BC9D0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    sfera_sub_004BC840(cpu, stop_address); return;
    label_000BC9DC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_ui_tool_tip_ctrl_release(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::ToolTipCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->ToolTipCtrl::destroy(false); cpu->esp += 4u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_sub_004BCA50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi >= cpu->ecx) goto label_000BCAAC;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax > cpu->edi) goto label_000BCAAC;
    cpu->edi -= cpu->eax;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x92492493u * (int32_t)(cpu->edi))) >> 32u);
    cpu->edx += cpu->edi;
    cpu->edx = (int32_t)(cpu->edx) >> 5u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 8u)) goto label_000BCA88;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBCA88u)); sfera_sub_004BC960(cpu, LIFT_CODE_TOKEN_RVA(0xBCA88u));
    label_000BCA88:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->edi * 8u;
    cpu->eax -= cpu->edi;
    cpu->edx = cpu->ecx + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCAA3u)); sfera_sub_004B9BB0(cpu, LIFT_CODE_TOKEN_VA(0x4BCAA3u));
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0x38u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000BCAAC:
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 8u)) goto label_000BCABA;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xBCABAu)); sfera_sub_004BC960(cpu, LIFT_CODE_TOKEN_RVA(0xBCABAu));
    label_000BCABA:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCAC4u)); sfera_sub_004B9C50(cpu, LIFT_CODE_TOKEN_VA(0x4BCAC4u));
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(0x38u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BCAD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x80u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x94u;
    cpu->ebx = 0u;
    cpu->edi = 0xFu;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"null");
    cpu->ecx = cpu->esp + 0x60u;
    *(uint32_t*)(cpu->esp + 0xA4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB44u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCB44u));
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"NULL");
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB54u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCB54u));
    lift_push32(cpu, 0x32u);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB60u)); sfera_sub_004BC840(cpu, LIFT_CODE_TOKEN_VA(0x4BCB60u));
    cpu->eax = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB6Fu)); sfera_sub_004BCA50(cpu, LIFT_CODE_TOKEN_VA(0x4BCB6Fu));
    cpu->edx = 0x1BCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB7Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCB7Eu));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCB88u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4BCB88u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x9Cu) = 1u;
    if (cpu->eax == cpu->ebx) goto label_000BCBA6;
    cpu->ecx = cpu->eax;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->initialize(); cpu->eax = cpu->ecx; }
    cpu->esi = cpu->eax;
    goto label_000BCBA8;
    label_000BCBA6:
    cpu->esi = 0u;
    label_000BCBA8:
    cpu->ecx = (uintptr_t)"Language\\strings.ui";
    *(uint8_t*)(cpu->esp + 0x9Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCBB9u)); sfera_sub_004B8150(cpu, LIFT_CODE_TOKEN_VA(0x4BCBB9u));
    { const uint32_t __parser_arg_019_13_0 = static_cast<uint32_t>(cpu->eax);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->load(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_13_0))); }
    { const uint32_t __parser_arg_019_14_0 = static_cast<uint32_t>(1u); const uint32_t __parser_arg_019_14_1 = static_cast<uint32_t>(cpu->ebx);
    cpu->ecx = cpu->esp + 0x14u;
    const uint32_t __parser_arg_019_14_2 = static_cast<uint32_t>(cpu->ecx); const uint32_t __parser_arg_019_14_3 = static_cast<uint32_t>((uintptr_t)"stringsUI");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->findBlock(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_14_3)), reinterpret_cast<SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_14_2)), reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_14_1)), static_cast<int32_t>(__parser_arg_019_14_0)) ? 1u : 0u; }
    cpu->ebp = 0x10u;
    if (cpu->eax == 0u) goto label_000BCCF0;
    cpu->edx = cpu->esp + 0x14u;
    { const uint32_t __parser_arg_019_15_0 = static_cast<uint32_t>(cpu->edx);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->setScanRange(reinterpret_cast<const SferaParserRange*>(static_cast<uintptr_t>(__parser_arg_019_15_0))); }
    { const uint32_t __parser_arg_019_16_0 = static_cast<uint32_t>((uintptr_t)"string");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_16_0))) ? 1u : 0u; }
    if (cpu->eax == 0u) goto label_000BCCE9;
    label_000BCC02:
    { const uint32_t __parser_arg_019_17_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0]); const uint32_t __parser_arg_019_17_1 = static_cast<uint32_t>(cpu->ebx);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readString(__parser_arg_019_17_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_019_17_0))))); }
    if (cpu->eax == 0u) goto label_000BCCD5;
    { const uint32_t __parser_arg_019_18_0 = static_cast<uint32_t>((uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0]); const uint32_t __parser_arg_019_18_1 = static_cast<uint32_t>(1u);
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(__parser_direct->readQuotedString(__parser_arg_019_18_1, reinterpret_cast<char*>(static_cast<uintptr_t>(__parser_arg_019_18_0))))); }
    if (cpu->eax == 0u) goto label_000BCCD5;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    cpu->eax = (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0];
    *(uint8_t*)(cpu->esp + 0x9Cu) = 2u;
    cpu->edx = cpu->eax + 1u;
    label_000BCC55:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BCC55;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_key[0]);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC6Du)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCC6Du));
    cpu->eax = (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0];
    cpu->edx = cpu->eax + 1u;
    label_000BCC75:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000BCC75;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_ui_load_scratch_runtime.localized_text[0]);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC8Du)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4BCC8Du));
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_interface_core_runtime.object_head;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCC9Cu)); sfera_sub_004BCA50(cpu, LIFT_CODE_TOKEN_VA(0x4BCC9Cu));
    *(uint8_t*)(cpu->esp + 0x9Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->ebp) goto label_000BCCB6;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCCB3u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BCCB3u));
    cpu->esp += 4u;
    label_000BCCB6:
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->ebp) goto label_000BCCD5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCCD2u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BCCD2u));
    cpu->esp += 4u;
    label_000BCCD5:
    { const uint32_t __parser_arg_019_19_0 = static_cast<uint32_t>((uintptr_t)"string");
    cpu->ecx = cpu->esi;
    SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = __parser_direct->nextValue(reinterpret_cast<const char*>(static_cast<uintptr_t>(__parser_arg_019_19_0))) ? 1u : 0u; }
    if (cpu->eax != 0u) goto label_000BCC02;
    label_000BCCE9:
    cpu->ecx = cpu->esi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->clearScanRange(); }
    label_000BCCF0:
    cpu->edx = 0x1DBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCCFFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCCFFu));
    if (cpu->esi == cpu->ebx) goto label_000BCD13;
    cpu->ecx = cpu->esi;
    { SferaSimpleParser* __parser_direct = reinterpret_cast<SferaSimpleParser*>(static_cast<uintptr_t>(cpu->ecx)); __parser_direct->release(); }
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCD10u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BCD10u));
    cpu->esp += 4u;
    label_000BCD13:
    if (*(uint32_t*)(cpu->esp + 0x88u) < cpu->ebp) goto label_000BCD29;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCD26u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BCD26u));
    cpu->esp += 4u;
    label_000BCD29:
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x6Cu) < cpu->ebp) goto label_000BCD4E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCD4Bu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BCD4Bu));
    cpu->esp += 4u;
    label_000BCD4E:
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BCD80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->ebx = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04 == cpu->ebx) goto label_000BCDBF;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BCDBF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDC4u)); sfera_sub_004A4B10(cpu, LIFT_CODE_TOKEN_VA(0x4BCDC4u));
    cpu->ecx = (uintptr_t)"control.cfg";
    g_sfera_interface_runtime.cross_enabled = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDD8u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4BCDD8u));
    cpu->edx = (uintptr_t)&g_sfera_interface_runtime.cross_enabled;
    cpu->ecx = (uintptr_t)"EN_CROSS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDE7u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4BCDE7u));
    cpu->edx = (uintptr_t)&g_sfera_interface_runtime.sounds_enabled;
    cpu->ecx = (uintptr_t)"INTFS_SOUNDS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCDF6u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4BCDF6u));
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02 != cpu->ebx) goto label_000BCE4F;
    cpu->edx = 0x364u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE0Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE0Du));
    lift_push32(cpu, 0x314u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE17u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4BCE17u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->eax == cpu->ebx) goto label_000BCE2F;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE2Du)); sfera_sub_004A17F0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE2Du));
    goto label_000BCE31;
    label_000BCE2F:
    cpu->eax = 0u;
    label_000BCE31:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE45u)); sfera_sub_004A18E0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE45u));
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    label_000BCE4F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE54u)); sfera_sub_004BC290(cpu, LIFT_CODE_TOKEN_VA(0x4BCE54u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    if (cpu->ecx == cpu->ebx) goto label_000BCE92;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->ecx + 8u) = 0xFFu;
    *(uint8_t*)(cpu->ecx + 1u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE6Eu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4BCE6Eu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    if (cpu->ecx == cpu->ebx) goto label_000BCE92;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE8Cu)); sfera_sub_004A1A20(cpu, LIFT_CODE_TOKEN_VA(0x4BCE8Cu));
    g_sfera_ui_load_scratch_runtime.cursor_name[0] = (uint8_t)((cpu->ebx & 0xFFu));
    label_000BCE92:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCE97u)); sfera_sub_004BCAD0(cpu, LIFT_CODE_TOKEN_VA(0x4BCE97u));
    lift_push32(cpu, (uintptr_t)"Effects\\loadscreen.ui");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEA1u)); sfera_sub_004BA190(cpu, LIFT_CODE_TOKEN_VA(0x4BCEA1u));
    lift_push32(cpu, (uintptr_t)"Effects\\sprites.ui");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEABu)); sfera_sub_004B8850(cpu, LIFT_CODE_TOKEN_VA(0x4BCEABu));
    cpu->ecx = 0xFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEB5u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BCEB5u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEBAu)); sfera_sub_004B9F40(cpu, LIFT_CODE_TOKEN_VA(0x4BCEBAu));
    cpu->ecx = 0x1Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC4u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC9u)); sfera_sub_004BA370(cpu, LIFT_CODE_TOKEN_VA(0x4BCEC9u));
    (*(uint8_t*)(void*)&g_sfera_interface_core_runtime.state_03) = cpu->ebx & 0xFFu;
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) = 1u;
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004BCEF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04 != cpu->edi) goto label_000BCF01;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000BCF01:
    lift_push32(cpu, cpu->esi);
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02 == cpu->edi) goto label_000BCF39;
    cpu->edx = 0x392u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF19u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCF19u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_000BCF33;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF2Au)); sfera_sub_004A1860(cpu, LIFT_CODE_TOKEN_VA(0x4BCF2Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF30u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BCF30u));
    cpu->esp += 4u;
    label_000BCF33:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_02) = cpu->edi;
    label_000BCF39:
    g_sfera_interface_runtime.cursor_kind = 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF48u)); sfera_sub_004B94A0(cpu, LIFT_CODE_TOKEN_VA(0x4BCF48u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF4Du)); sfera_sub_004B9410(cpu, LIFT_CODE_TOKEN_VA(0x4BCF4Du));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF52u)); sfera_sub_004B9390(cpu, LIFT_CODE_TOKEN_VA(0x4BCF52u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF57u)); sfera_sub_004A5460(cpu, LIFT_CODE_TOKEN_VA(0x4BCF57u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_head;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    if (cpu->eax == cpu->ecx) goto label_000BCF92;
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF73u)); sfera_sub_004BA8C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCF73u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_interface_core_runtime.object_aux);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF8Cu)); sfera_sub_004BC000(cpu, LIFT_CODE_TOKEN_VA(0x4BCF8Cu));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.object_count) = cpu->esi;
    label_000BCF92:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCF97u)); sfera_sub_004B9B10(cpu, LIFT_CODE_TOKEN_VA(0x4BCF97u));
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_04) = cpu->edi;
    if (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08 == cpu->edi) goto label_000BCFE3;
    cpu->edx = 0x3A4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Interface\\Interface.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCFB4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4BCFB4u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08;
    if (cpu->eax == cpu->edi) goto label_000BCFDD;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = cpu->eax + 0xFFFFFFFCu;
    { uint32_t current = cpu->eax + 0x98u * cpu->ecx; uint32_t count = cpu->ecx; while (count-- != 0u) { current -= 0x98u; cpu->ecx = current; lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCFD4u)); sfera_sub_004CF160(cpu, LIFT_CODE_TOKEN_VA(0x4BCFD4u)); } }
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4BCFDAu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4BCFDAu));
    cpu->esp += 4u;
    label_000BCFDD:
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_08) = cpu->edi;
    label_000BCFE3:
    cpu->esi = lift_pop32(cpu);
    (*(uint32_t*)(void*)&g_sfera_interface_core_runtime.state_09) = cpu->edi;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_ui_list_item_ctrl_item_at(LiftCpu* cpu, uint32_t stop_address) { cpu->eax = address32(reinterpret_cast<SphereUI::ListItemCtrl*>(static_cast<std::uintptr_t>(cpu->ecx))->itemAt(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)))); cpu->esp += 8u; cpu->eip = stop_address; }


__declspec(noinline) void sfera_ui_pointer_vector_reserve_additional(LiftCpu* cpu, uint32_t stop_address) { auto* self = reinterpret_cast<SphereUI::UiIndexVector*>(static_cast<std::uintptr_t>(cpu->ecx)); const auto additional = *reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u)); if (additional > 0x3fffffffu - self->size()) throw std::length_error("UI pointer vector too long"); self->reserve(self->size() + additional); cpu->esp += 8u; cpu->eip = stop_address; }
__declspec(noinline) void sfera_ui_pointer_vector_append(LiftCpu* cpu, uint32_t stop_address) { reinterpret_cast<SphereUI::UiIndexVector*>(static_cast<std::uintptr_t>(cpu->ecx))->append(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(cpu->esp + 4u))))); cpu->esp += 8u; cpu->eip = stop_address; }





} // namespace lifted
