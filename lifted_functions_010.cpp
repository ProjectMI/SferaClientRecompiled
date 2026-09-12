#include "lifted_functions.h"
#include <cmath>
namespace lifted {


__declspec(noinline) void sfera_sub_00462F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    if (cpu->eax == 0u) goto label_00063007;
    if (g_sfera_texture_cache_runtime.cache_enabled == 0u) goto label_00063007;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x24u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x62F45u));
    if (cpu->eax == 0x8007001Eu) goto label_00062F55;
    if (cpu->eax != 0x8007000Cu) goto label_00062F96;
    label_00062F55:
    cpu->eax = SferaAbi::address(CCursorManager::instance().activeCursor());
    cpu->ecx = cpu->eax;
    cpu->eax = reinterpret_cast<CCursor*>(cpu->ecx)->isInsideViewport() ? 1u : 0u;
    if ((cpu->eax & 0xFFu) == 0u) goto label_00062F74;
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x62F72u));
    label_00062F74:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x24u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x62F86u));
    if (cpu->eax == 0x8007001Eu) goto label_00063007;
    if (cpu->eax == 0x8007000Cu) goto label_00063007;
    label_00062F96:
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x88888889u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 6u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    lift_push32(cpu, 0x17u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::GetSystemMetrics), LIFT_CODE_TOKEN_VA(0x462FBFu));
    cpu->ecx = *(uint8_t*)(cpu->esp + 0x11u);
    if (cpu->eax != 0u) goto label_00062FF3;
    cpu->edx = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->ecx&=0x80u;
    cpu->edx >>= 1u;
    cpu->ecx|=cpu->edx;
    cpu->ecx >>= 6u;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00062FF3:
    cpu->eax = *(uint8_t*)(cpu->esp + 0x10u);
    cpu->eax&=0x80u;
    cpu->ecx >>= 1u;
    cpu->eax|=cpu->ecx;
    cpu->eax >>= 6u;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_00063007:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00463020(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    cpu->esp -= 0x4D4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x4E8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4E8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    cpu->ebx = 0u;
    label_00063058:
    if ((int32_t)cpu->ebx >= 0) goto label_00063066;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63066u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x63066u));
    label_00063066:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0006307A;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6307Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6307Au));
    label_0006307A:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebx * 4u)) == 0u) goto label_00063088;
    ++cpu->ebx;
    goto label_00063058;
    label_00063088:
    lift_push32(cpu, 0xBBBu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xE84u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4630A0u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4630A0u));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_000630B0;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x630B0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x630B0u));
    label_000630B0:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000630C4;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x630C4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x630C4u));
    label_000630C4:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = cpu->edi;
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u)) = cpu->ebp;
    *(uint32_t*)(cpu->ebp) = 0u;
    cpu->edi = cpu->eax + 1u;
    label_000630E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000630E0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, 0xBBEu);
    cpu->ecx = cpu->eax + 2u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4630FBu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4630FBu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x990u) = cpu->eax;
    cpu->edx = cpu->eax;
    label_00063107:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00063107;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x990u);
    --cpu->edi;
    label_00063118:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00063118;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x990u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_00063158;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0006314C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6314Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6314Cu));
    label_0006314C:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 0u) goto label_0006318B;
    label_00063158:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00063165:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00063165;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"create_text: wrong window handle"),33u); cpu->edi += 33u; cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46317Fu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x46317Fu));
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    label_0006318B:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x463194u)); sfera_sub_0045DC60(cpu, LIFT_CODE_TOKEN_VA(0x463194u));
    *(float*)(cpu->ebp + 0x24u) = (double)(1.0);
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 4u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = 0xFFFFFFFFu;
    if ((int32_t)cpu->esi >= 0) goto label_000631B4;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x631B4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x631B4u));
    label_000631B4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_000631C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x631C8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x631C8u));
    label_000631C8:
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x6DA8u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x28u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x6DB4u);
    *(uint32_t*)(cpu->ebp + 0xE40u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x6DB0u);
    *(uint32_t*)(cpu->ebp + 0xE44u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xE80u) = 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx));
    cpu->edi = 0u;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000634CD;
    cpu->ecx = cpu->ebp + 0x990u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_00063220:
    if ((cpu->eax & 0xFFu) != 0xAu) goto label_00063269;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x6DB4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x30u));
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x30u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->edx) goto label_00063244;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->edx = cpu->eax;
    label_00063244:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++cpu->edi;
    if (cpu->edi == 0x12Cu) goto label_0006336F;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebx + 1u;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x30u) = 0u;
    goto label_000632BC;
    label_00063269:
    cpu->ecx = *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x30u);
    if ((cpu->ecx==0u) || (((cpu->ecx)&0x80000000u)!=0u)) goto label_00063288;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x6DB0u);
    cpu->ebx = *(uint32_t*)((cpu->ebx * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    cpu->ebx += cpu->ecx;
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x30u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00063288:
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    if (*(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].defined)) != 0u) goto label_000632A8;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x6DB0u);
    cpu->ecx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[124][0]));
    goto label_000632B8;
    label_000632A8:
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x6DB0u);
    cpu->ecx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    label_000632B8:
    *(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x30u) = (uint64_t)(*(uint32_t*)(cpu->esp + (cpu->edi * 4u) + 0x30u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    label_000632BC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 1u));
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00063220;
    if (cpu->edi == 0u) goto label_000634CD;
    if (cpu->edx == 0u) goto label_000634CD;
    *(uint32_t*)(cpu->ebp + 0x2Cu) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x6DB0u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = cpu->edi + 0xFFFFFFFFu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])));
    cpu->ecx += *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x6DB4u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx += 2u;
    g_sfera_recovered_static_runtime.text_size_height = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    g_sfera_input_device_runtime.process_value = cpu->ecx;
    lift_test[0]=(*(uint8_t*)(cpu->esi + 0x6DACu)&1u)==0u;
    cpu->edx = cpu->ecx + cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if (lift_test[0]) goto label_0006335A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->edx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->eax = cpu->ebx;
    label_0006335A:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x6DACu);
    if ((((cpu->edx & 0xFFu)) & (0x40u)) == 0u) goto label_00063379;
    cpu->eax -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    cpu->ebx = cpu->eax;
    goto label_0006338B;
    label_0006336F:
    cpu->ecx = (uintptr_t)"MNO_LINES_IN_TEXT exceeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63379u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x63379u));
    label_00063379:
    if ((((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_0006338B;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->ebx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    label_0006338B:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) <= (int32_t)cpu->eax) goto label_000633BC;
    if (((*(uint8_t*)(cpu->esi + 0x6DACu)) & (4u)) == 0u) goto label_000633BC;
    cpu->ecx = cpu->eax;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_000633BC:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ecx) goto label_000633D9;
    if (((*(uint8_t*)(cpu->esi + 0x6DACu)) & (8u)) == 0u) goto label_000633D9;
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->eax = cpu->ecx;
    label_000633D9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx >= 0) goto label_000633F6;
    if (((*(uint8_t*)(cpu->esi + 0x6DACu)) & (4u)) == 0u) goto label_000633F6;
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_000633F6:
    if ((int32_t)cpu->ebx >= 0) goto label_00063407;
    if (((*(uint8_t*)(cpu->esi + 0x6DACu)) & (8u)) == 0u) goto label_00063407;
    cpu->eax -= cpu->ebx;
    cpu->ebx = 0u;
    label_00063407:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->edi <= 0) goto label_00063488;
    cpu->ebp += 0x30u;
    label_00063424:
    if (((*(uint8_t*)(cpu->esi + 0x6DACu)) & (0x10u)) == 0u) goto label_00063443;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= *(uint32_t*)(cpu->esp + (cpu->ecx * 4u) + 0x30u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += *(uint32_t*)(cpu->esi + 0x1Cu);
    goto label_0006344A;
    label_00063443:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    label_0006344A:
    *(uint32_t*)(cpu->ebp) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x6DB0u);
    cpu->eax += cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->eax + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0]));
    cpu->eax += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->edx -= *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0]));
    ++cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x6DB4u));
    cpu->edx += *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ebp += 4u;
    cpu->edx += cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0x4ACu) = cpu->edx;
    if ((int32_t)cpu->ecx < (int32_t)cpu->edi) goto label_00063424;
    label_00063488:
    g_sfera_main_view_state_runtime.projection_sample_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) + 1u;
    if (((*(uint8_t*)(cpu->esi + 0x6DACu)) & (0x20u)) == 0u) goto label_000634BE;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    WorldGuiControls::destroyText(cpu->ecx);
    cpu->eax |= 0xFFFFFFFFu;
    label_000634A3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4D4u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000634BE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4634C7u)); sfera_sub_0045EBE0(cpu, LIFT_CODE_TOKEN_VA(0x4634C7u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    goto label_000634A3;
    label_000634CD:
    cpu->ecx = (uintptr_t)"Empty text created";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4634D7u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4634D7u));
    cpu->eip = 0x4634D7u; ::DebugBreak(); return;
}




__declspec(noinline) void sfera_sub_00464600(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9;
 bool sub_pred[1]; double x87_p0, x87_p1;
    cpu->esp -= 0x428u;
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (sub_pred[0]) goto label_0006481D;
    if (g_sfera_world_objects.controlled_object_handle == 0xFFFFFFFFu) goto label_0006481D;
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464641u)); sfera_sub_0045D4E0(cpu, LIFT_CODE_TOKEN_VA(0x464641u));
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00064658;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64658u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64658u));
label_00064658:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0006467A;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464675u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x464675u));
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
label_0006467A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00064693;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46468Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x46468Eu));
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
label_00064693:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_000646AC;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x646ACu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x646ACu));
label_000646AC:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000646C0;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x646C0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x646C0u));
label_000646C0:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u));
    x87_p0 = (double)*(float*)(cpu->eax + 0x14u);
    cpu->ebp = 1u;
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    cpu->ecx = cpu->ebp;
    *(float*)(cpu->edi + 8u) = (double)*(float*)(cpu->esi + 8u);
    *(float*)(cpu->edi + 0x10u) = (double)*(float*)(cpu->esi + 0x10u);
    *(float*)(cpu->edi + 0xCu) = ((((double)*(float*)(cpu->esp + 0x2Cu))) - (0.10000000149011612));
    g_sfera_world_objects.recalculateBasis(cpu->ecx);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00064709;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64709u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64709u));
label_00064709:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != 0u) goto label_000647BF;
label_0006471A:
    x87_p0 = (double)*(float*)(cpu->eax + 0x150u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    x87_p0 = (x87_p0) * (0.30000001192092896);
    (*(uint32_t*)(void*)&g_sfera_saved_controlled_position.x) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    g_sfera_saved_controlled_position.y = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    g_sfera_saved_controlled_position.z = cpu->eax;
    *(float*)(cpu->esi + 8u) = (((((((double)*(float*)(cpu->esi + 8u))) - (((double)*(float*)(cpu->esp + 0x28u)))))) + (((double)*(float*)(cpu->esi + 8u))));
    *(float*)(cpu->esi + 0x10u) = (((((((double)*(float*)(cpu->esi + 0x10u))) - (((double)*(float*)(cpu->esp + 0x30u)))))) + (((double)*(float*)(cpu->esi + 0x10u))));
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u);
     value_1 = x87_p1; value_2 = x87_p0; if (!((value_1)>(value_2))) goto label_0006480B;
    value_3 = (double)*(float*)(cpu->esi + 8u);
    *(double*)(cpu->esp + 0x20u) = value_3;
     value_4 = (double)*(float*)(cpu->esp + 0x18u);
    value_5 = std::sin(value_4);
    *(float*)(cpu->esp + 0x10u) = value_5; 
    *(float*)(cpu->esi + 8u) = ((*(double*)(cpu->esp + 0x20u)) - ((((((-((double)*(float*)(cpu->esp + 0x10u))))) * (((double)*(float*)(cpu->esp + 0x14u)))))));
    value_6 = (double)*(float*)(cpu->esi + 0x10u);
    *(double*)(cpu->esp + 0x20u) = value_6;
     value_7 = (double)*(float*)(cpu->esp + 0x18u);
    value_8 = std::cos(value_7);
    *(float*)(cpu->esp + 0x10u) = value_8; 
    *(float*)(cpu->esi + 0x10u) = ((*(double*)(cpu->esp + 0x20u)) - ((((((double)*(float*)(cpu->esp + 0x10u))) * (((double)*(float*)(cpu->esp + 0x14u)))))));
     goto label_00064822;
label_000647BF:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0006471A;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000647E4;
    cpu->eax = (uintptr_t)"<none>";
label_000647E4:
    lift_push32(cpu, 0x1915u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4647F9u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6480Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6480Bu));
label_0006480B:
    x87_p0 = (double)*(float*)(cpu->edi + 0xCu);
    value_9 = x87_p0; x87_p0 = value_1;
    x87_p0 = (x87_p0) * (0.20000000298023224);
    value_0 = value_9 - x87_p0; 
    *(float*)(cpu->edi + 0xCu) = value_0; 
     goto label_00064822;
label_0006481D:
    cpu->ebp = 1u;
label_00064822:
    if ((cpu->ebx & 0xFFu) == 0u) goto label_000648EE;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0006483E;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6483Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6483Eu));
label_0006483E:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    g_sfera_client_main_scalar_runtime.state_34 = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    g_sfera_client_main_scalar_runtime.state_35 = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    g_sfera_client_main_scalar_runtime.state_36 = cpu->edx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00064876;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64876u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64876u));
label_00064876:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0]) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x18u);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1]) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x1Cu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2]) = cpu->eax;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_000648AC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x648ACu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x648ACu));
label_000648AC:
    cpu->esi = g_sfera_world_objects.object_handles.data;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_000648C6;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x648C6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x648C6u));
label_000648C6:
    x87_p0 = (double)*(float*)(cpu->esp + 0x43Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_p0 = (x87_p0) + (x87_p0);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->eax + 0xCu) = (double)*(float*)(cpu->esp + 0x10u);
    g_sfera_world_objects.reflectReferenceOrientation();
label_000648EE:
    if (*(uint32_t*)(cpu->esp + 0x1Cu) == 2u) goto label_00064902;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 == 0u) goto label_00064A78;
label_00064902:
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00064916;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64916u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64916u));
label_00064916:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    g_sfera_client_main_scalar_runtime.state_34 = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    g_sfera_client_main_scalar_runtime.state_35 = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    g_sfera_client_main_scalar_runtime.state_36 = cpu->edx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0006494E;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6494Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6494Eu));
label_0006494E:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0]) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x18u);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1]) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x1Cu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2]) = cpu->eax;
    if (cpu->esi == 0xFFFFFFFFu) goto label_000649D7;
    if ((int32_t)cpu->esi >= 0) goto label_00064989;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64989u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x64989u));
label_00064989:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006499D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6499Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6499Du));
label_0006499D:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_000649BA;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x649BAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x649BAu));
label_000649BA:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
label_000649D7:
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_000649EB;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x649EBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x649EBu));
label_000649EB:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(float*)(cpu->eax + 0xCu) = ((((double)*(float*)(cpu->eax + 0xCu))) - (1000.0));
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00064A14;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64A14u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64A14u));
label_00064A14:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    x87_p0 = (double)-4.7123894691467285f;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(float*)(cpu->eax + 0x14u) = x87_p0; 
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00064A3A;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64A3Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64A3Au));
label_00064A3A:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    x87_p0 = (double)1.5707964897155762f;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(float*)(cpu->edx + 0x18u) = x87_p0; 
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_00064A60;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64A60u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64A60u));
label_00064A60:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    x87_p0 = (double)-1.5707964897155762f;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(float*)(cpu->ecx + 0x1Cu) = x87_p0; 
    cpu->ecx = cpu->ebp;
    g_sfera_world_objects.recalculateBasis(cpu->ecx);
label_00064A78:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x428u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00464AA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->edi = cpu->ecx;
    if (sub_pred[0]) goto label_00064B00;
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00064B00;
    if ((int32_t)cpu->esi >= 0) goto label_00064AC9;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64AC9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x64AC9u));
    label_00064AC9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00064ADD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64ADDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64ADDu));
    label_00064ADD:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_saved_controlled_position.x;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = g_sfera_saved_controlled_position.y;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->ecx = g_sfera_saved_controlled_position.z;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    label_00064B00:
    if (cpu->edi == 2u) goto label_00064B12;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13 != 0u) goto label_00064B12;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_00064B91;
    label_00064B12:
    cpu->esi = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->esi) goto label_00064B2B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64B2Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64B2Bu));
    label_00064B2B:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_34;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = g_sfera_client_main_scalar_runtime.state_35;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_36;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->esi) goto label_00064B63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64B63u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x64B63u));
    label_00064B63:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0];
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1];
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2];
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    g_sfera_world_objects.recalculateBasis(cpu->ecx);  cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00064B91:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00464BA0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20;
 bool lift_test[3]; bool sub_pred[1]; double x87_p0, x87_p1, x87_p2;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1F4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x208u;
    cpu->ecx = cpu->esp + 0x30u;
    cpu->eax = cpu->ecx;
    cpu->esi = 0u;
    g_sfera_files.setErrorReporting(true);
    *(uint32_t*)(cpu->esp + 0x210u) = cpu->esi;
    cpu->ecx = (uintptr_t)"params";
    g_sfera_files.addSearchPath(SferaAbi::pointer<const char>(cpu->ecx));
    cpu->ecx = (uintptr_t)"mbc";
    g_sfera_files.addSearchPath(SferaAbi::pointer<const char>(cpu->ecx));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"Error.log") + 8u));
    cpu->ecx = *(uint32_t*)(((uintptr_t)"Error.log") + 4u);
    cpu->eax = 0x6F727245u;
    cpu->ebx = native_function_address32(&::fflush);
    cpu->ebp = native_function_address32(&::fclose);
    g_sfera_log_runtime.files[0].path.words[1] = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"test.log") + 4u);
    *(uint16_t*)((uintptr_t)&g_sfera_log_runtime.files[0].path.text[8]) = cpu->edx & 0xFFFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"test.log") + 8u));
    g_sfera_log_runtime.files[0].path.words[0] = cpu->eax;
    cpu->eax = *(uint32_t*)((uintptr_t)"test.log");
    g_sfera_log_runtime.files[1].path.words[1] = cpu->ecx;
    cpu->ecx = *(uint32_t*)((uintptr_t)"logs\\memory.log");
    *(uint8_t*)((uintptr_t)&g_sfera_log_runtime.files[1].path.text[8]) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(((uintptr_t)"logs\\memory.log") + 4u);
    g_sfera_log_runtime.files[1].path.words[0] = cpu->eax;
    cpu->eax = 0x7A120u;
    g_sfera_log_runtime.files[2].path.words[0] = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"logs\\memory.log") + 8u);
    g_sfera_log_runtime.files[2].path.words[1] = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"logs\\memory.log") + 0xCu);
    g_sfera_log_runtime.files[0].truncate_on_first_write = cpu->esi;
    *(uint32_t*)((uintptr_t)&g_sfera_log_runtime.files[0].size_limit) = 0x989680u;
    *(uint32_t*)((uintptr_t)&g_sfera_log_runtime.files[1].truncate_on_first_write) = cpu->esi;
    *(uint32_t*)((uintptr_t)&g_sfera_log_runtime.files[1].size_limit) = cpu->eax;
    g_sfera_log_runtime.files[2].path.words[2] = cpu->ecx;
    g_sfera_log_runtime.files[2].path.words[3] = cpu->edx;
    *(uint32_t*)((uintptr_t)&g_sfera_log_runtime.files[2].truncate_on_first_write) = cpu->esi;
    *(uint32_t*)((uintptr_t)&g_sfera_log_runtime.files[2].size_limit) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode) = 3u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->edi = (uintptr_t)&g_sfera_log_runtime.files[0].has_written;
    goto label_00064CD2;
label_00064CD0:
    cpu->esi = 0u;
label_00064CD2:
    if (*(uint32_t*)(cpu->edi + 0xFFFFFFFCu) != cpu->esi) goto label_00064DF3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00064D05;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"**** Start: ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464CF0u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->edi) = 1u;
label_00064D05:
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x464D0Au));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x464D15u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y");
    cpu->edx = cpu->esp + 0x1B0u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x464D2Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esp += 0x18u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00064D61;
    cpu->eax = cpu->esp + 0x1A0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464D4Cu));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->edi) = 1u;
label_00064D61:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00064D8B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"  ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464D76u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->edi) = 1u;
label_00064D8B:
    cpu->ecx = cpu->esp + 0x1A0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x464D93u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00064DC9;
    cpu->edx = cpu->esp + 0x1A0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464DB4u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->edi) = 1u;
label_00064DC9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00064DF3;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464DDEu));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->edi) = 1u;
label_00064DF3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 0x40u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode) goto label_00064CD0;
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CoInitialize), LIFT_CODE_TOKEN_VA(0x464E0Du));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_00064EAB;
    if (cpu->esi == 1u) goto label_00064EAB;
    cpu->ecx = 0u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00064E52;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"ERROR: init_first2: CoInitialize error code = ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464E39u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
label_00064E52:
    cpu->ecx = 0u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00064E7F;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%d\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x464E66u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x14u;
    g_sfera_log_runtime.files[0].has_written = 1u;
label_00064E7F:
    cpu->ecx = 0u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00064EAB;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464E92u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
label_00064EAB:
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464EB5u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x464EB5u));
    cpu->edx = (uintptr_t)&g_sfera_client_config_runtime.state_09;
    cpu->ecx = (uintptr_t)"LANG";
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464ECEu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464ECEu));
    if (*(uint8_t*)(void*)&g_sfera_client_process_runtime.locale[0] == 0u) goto label_000650A7;
    cpu->edi = native_function_address32(&::strncmp);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncmp)))((uintptr_t)&g_sfera_client_process_runtime.locale[0], (uintptr_t)"ru", 2u);

    if (cpu->eax != 0u) goto label_00064FCE;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = cpu->eax;
label_00064EFF:
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = 0u;
label_00064F06:
    cpu->edx = (uintptr_t)&g_sfera_client_config_runtime.state_25;
    cpu->ecx = (uintptr_t)"AUTOFOG";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F15u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464F15u));
    cpu->edx = (uintptr_t)&g_sfera_graphics_runtime.fog_distance;
    cpu->ecx = (uintptr_t)"FOGDIST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F24u)); sfera_sub_004486E0(cpu, LIFT_CODE_TOKEN_VA(0x464F24u));
    cpu->edx = (uintptr_t)&g_sfera_options_dialog_runtime.reflection_quality;
    cpu->ecx = (uintptr_t)"REFLQUAL";
    g_sfera_options_dialog_runtime.reflection_quality = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F3Du)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464F3Du));
    cpu->edx = (uintptr_t)&g_sfera_client_config_runtime.state_26;
    cpu->ecx = (uintptr_t)"EFFECTS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F4Cu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464F4Cu));
    cpu->edx = (uintptr_t)&g_sfera_graphics_runtime.lods_enabled;
    cpu->ecx = (uintptr_t)"LODS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F5Bu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464F5Bu));
    cpu->edx = (uintptr_t)&g_sfera_graphics_runtime.hardware_cursor_enabled;
    cpu->ecx = (uintptr_t)"HARDWARE_CURSOR";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F6Au)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464F6Au));
    cpu->edx = (uintptr_t)&g_sfera_interface_runtime.description_auto_popup;
    cpu->ecx = (uintptr_t)"DESCR_AUTO_POPUP";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F79u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464F79u));
    cpu->edx = (uintptr_t)&g_sfera_interface_runtime.invite_messages;
    cpu->ecx = (uintptr_t)"INVITE_MESSAGES";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F88u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x464F88u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F93u)); sfera_sub_004261B0(cpu, LIFT_CODE_TOKEN_VA(0x464F93u));
    g_sfera_files.setErrorReporting(false);
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"loadcount.bin";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->edi = cpu->eax;
    g_sfera_files.setErrorReporting(true);
    if (cpu->edi == 0xFFFFFFFFu) goto label_0006517E;
    lift_push32(cpu, 4u);
    cpu->edx = (uintptr_t)&g_sfera_world_load_runtime.loading_work_total;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    goto label_00065188;
label_00064FCE:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncmp)))((uintptr_t)&g_sfera_client_process_runtime.locale[0], (uintptr_t)"en", 2u);

    if (cpu->eax != 0u) goto label_00064FF2;
label_00064FE3:
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = 1u;
    goto label_000650B1;
label_00064FF2:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncmp)))((uintptr_t)&g_sfera_client_process_runtime.locale[0], (uintptr_t)"es", 2u);

    if (cpu->eax != 0u) goto label_00065016;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = 5u;
    goto label_0006513B;
label_00065016:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncmp)))((uintptr_t)&g_sfera_client_process_runtime.locale[0], (uintptr_t)"pt", 2u);

    if (cpu->eax != 0u) goto label_0006503A;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = 2u;
    goto label_000650D3;
label_0006503A:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncmp)))((uintptr_t)&g_sfera_client_process_runtime.locale[0], (uintptr_t)"de", 2u);

    if (cpu->eax != 0u) goto label_0006505E;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = 4u;
    goto label_00065119;
label_0006505E:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncmp)))((uintptr_t)&g_sfera_client_process_runtime.locale[0], (uintptr_t)"fr", 2u);

    if (cpu->eax != 0u) goto label_00065082;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = 6u;
    goto label_0006515F;
label_00065082:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncmp)))((uintptr_t)&g_sfera_client_process_runtime.locale[0], (uintptr_t)"it", 2u);

    if (cpu->eax != 0u) goto label_00064FE3;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = 3u;
    goto label_000650F5;
label_000650A7:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    if (cpu->eax != 1u) goto label_000650CE;
label_000650B1:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x655F)) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"_e") + 2u));
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = cpu->eax & 0xFFFFu;
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = cpu->ecx & 0xFFu;
    goto label_00064F06;
label_000650CE:
    if (cpu->eax != 2u) goto label_000650F0;
label_000650D3:
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"_p"));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"_p") + 2u));
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = cpu->edx & 0xFFFFu;
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = cpu->eax & 0xFFu;
    goto label_00064F06;
label_000650F0:
    if (cpu->eax != 3u) goto label_00065114;
label_000650F5:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"_i"));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"_i") + 2u));
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = cpu->ecx & 0xFFFFu;
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = cpu->edx & 0xFFu;
    goto label_00064F06;
label_00065114:
    if (cpu->eax != 4u) goto label_00065136;
label_00065119:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"_d"));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"_d") + 2u));
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = cpu->eax & 0xFFFFu;
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = cpu->ecx & 0xFFu;
    goto label_00064F06;
label_00065136:
    if (cpu->eax != 5u) goto label_00065156;
label_0006513B:
    cpu->edx = *(uint32_t*)((uintptr_t)"_spa");
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"_spa") + 4u));
    (*(uint32_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = cpu->edx;
    *(uint8_t*)((uintptr_t)&g_sfera_font_runtime.language_suffix[4]) = cpu->eax & 0xFFu;
    goto label_00064F06;
label_00065156:
    if (cpu->eax != 6u) goto label_00064EFF;
label_0006515F:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"_f"));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"_f") + 2u));
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = cpu->ecx & 0xFFFFu;
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = cpu->edx & 0xFFu;
    goto label_00064F06;
label_0006517E:
    g_sfera_world_load_runtime.loading_work_total = 0x3A98u;
label_00065188:
    lift_native_call(cpu, native_function_address32(&::InitCommonControls), LIFT_CODE_TOKEN_VA(0x465188u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465193u)); sfera_sub_0045AFB0(cpu, LIFT_CODE_TOKEN_VA(0x465193u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465198u)); sfera_sub_00462690(cpu, LIFT_CODE_TOKEN_VA(0x465198u));
    cpu->ebx = 0u;
    cpu->eax = 0u;
label_000651A0:
    *(uint8_t*)(cpu->eax + ((uintptr_t)g_sfera_ascii_lower_runtime.table)) = cpu->eax & 0xFFu;
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x100u) goto label_000651A0;
    for (uint32_t letter = 'A'; letter <= 'Z'; ++letter) { *(uint8_t*)(letter + ((uintptr_t)g_sfera_ascii_lower_runtime.table)) = (uint8_t)(letter + ('a' - 'A')); }
    lift_push32(cpu, (uintptr_t)"SphereDebug"); lift_push32(cpu, 0x3E8u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 4u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFFFu);
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x4651D9u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0xFFFFFFFFu) goto label_000651F0;
    cpu->ecx = (uintptr_t)"CreateFileMapping failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x651F0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x651F0u));
label_000651F0:
    lift_push32(cpu, 0x3E8u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x4651FAu));
    lift_push32(cpu, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x465206u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode;
    if (cpu->eax != cpu->ebx) goto label_0006521F;
    cpu->ecx = (uintptr_t)"MapViewOfFile failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6521Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6521Fu));
label_0006521F:
    if (*(uint8_t*)(cpu->eax + 0x3E7u) != 2u) goto label_00065244;
    *(uint8_t*)(cpu->eax + 0x3E7u) = 1u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 0x3E7u));
label_00065240:
    if ((cpu->eax & 0xFFu) == 1u) goto label_00065240;
label_00065244:
    lift_push32(cpu, (uintptr_t)"Spider"); lift_push32(cpu, (uintptr_t)"SpiderWclName");
    lift_native_call(cpu, native_function_address32(&::FindWindowA), LIFT_CODE_TOKEN_VA(0x46524Eu));
    g_sfera_debug_window_runtime.spider_window = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = 1u;
    g_sfera_graphics_runtime.display_width = 0x280u;
    g_sfera_graphics_runtime.display_height = 0x1E0u;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.debug_config_enabled == cpu->ebx) goto label_000652B3;
    cpu->ecx = (uintptr_t)"debug.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465287u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x465287u));
    cpu->edx = cpu->esp + 0x34u;
    cpu->ecx = (uintptr_t)"SHOWVIDEO";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465295u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x465295u));
    cpu->edx = (uintptr_t)&g_sfera_client_config_runtime.state_23;
    cpu->ecx = (uintptr_t)"REFRESH";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4652A4u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4652A4u));
    cpu->edx = (uintptr_t)&g_sfera_recovered_static_runtime.memory_warning_as_error;
    cpu->ecx = (uintptr_t)"MEMORY_WARNING_AS_ERROR";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x652B3u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_RVA(0x652B3u));
label_000652B3:
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4652BDu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4652BDu));
    cpu->edx = (uintptr_t)&g_sfera_window_runtime.windowed;
    cpu->ecx = (uintptr_t)"WINDOWED";
    g_sfera_window_runtime.windowed = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4652D2u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4652D2u));
    cpu->edi = native_function_address32(&::GetSystemMetrics);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetSystemMetrics)))(cpu->ebx);
    lift_push32(cpu, 1u);
    g_sfera_graphics_runtime.display_width = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetSystemMetrics)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    cpu->edx = (uintptr_t)&g_sfera_graphics_runtime.display_width;
    cpu->ecx = (uintptr_t)"XRES";
    g_sfera_graphics_runtime.display_height = cpu->eax;
    g_sfera_graphics_display_depth_bits = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465302u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x465302u));
    cpu->edx = (uintptr_t)&g_sfera_graphics_runtime.display_height;
    cpu->ecx = (uintptr_t)"YRES";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465311u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x465311u));
    cpu->edx = (uintptr_t)&g_sfera_graphics_display_depth_bits;
    cpu->ecx = (uintptr_t)"DEPTH";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465320u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x465320u));
    cpu->edx = (uintptr_t)&g_sfera_main_render_runtime.grass_depth_mode;
    cpu->ecx = (uintptr_t)"GRASS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46532Fu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x46532Fu));
    cpu->edx = (uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32;
    cpu->ecx = (uintptr_t)"LOD_DISTANCE";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46533Eu)); sfera_sub_004486E0(cpu, LIFT_CODE_TOKEN_VA(0x46533Eu));
    cpu->edx = (uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32;
    cpu->ecx = (uintptr_t)"MIN_LOD_DIST";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46534Du)); sfera_sub_004486E0(cpu, LIFT_CODE_TOKEN_VA(0x46534Du));
    cpu->edx = (uintptr_t)&g_sfera_graphics_runtime.post_effects_enabled;
    cpu->ecx = (uintptr_t)"POSTEFFECTS";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46535Cu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x46535Cu));
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32);
    x87_p1 = 0.0;
    x87_p2 = x87_p1;
     value_7 = x87_p2; value_8 = x87_p1; value_9 = x87_p0; if ((value_7)!=(value_9)) goto label_0006537D;
    *(float*)((uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32) = (double)23.0f;
label_0006537D:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32);
     value_10 = x87_p0; if ((value_10)!=(value_8)) goto label_00065398;
    *(float*)((uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32) = (double)20.0f;
label_00065398:
    cpu->esi = native_function_address32(&::_findfirst64i32);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"landscape_hr");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findfirst64i32)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->ebp = native_function_address32(&::_errno);
    cpu->edi = native_function_address32(&::_findclose);
    cpu->esp += 8u;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0006550E;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::_errno)))();
label_000653C4:
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) = cpu->ebx;
label_000653CA:
    cpu->edx = cpu->esp + 0x38u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findfirst64i32)))((uintptr_t)"landscape_ph", cpu->edx);

    if (cpu->eax != 0xFFFFFFFFu) goto label_0006553A;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::_errno)))();
label_000653E4:
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21) = cpu->ebx;
label_000653EA:
    cpu->eax = cpu->esp + 0x38u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findfirst64i32)))((uintptr_t)"landscape_rd", cpu->eax);

    if (cpu->eax != 0xFFFFFFFFu) goto label_00065560;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::_errno)))();
label_00065404:
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22) = cpu->ebx;
    cpu->ebp = 1u;
label_0006540F:
    cpu->edx = (uintptr_t)&g_sfera_recovered_static_runtime.vertical_sync_enabled;
    cpu->ecx = (uintptr_t)"VERTSYNC";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46541Eu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x46541Eu));
    if (cpu->eax == cpu->ebx) goto label_00065439;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)"VERTSYNC";
    g_sfera_recovered_static_runtime.vertical_sync_enabled = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465434u)); sfera_sub_00448A20(cpu, LIFT_CODE_TOKEN_VA(0x465434u));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x65439u)); sfera_sub_00448490(cpu, LIFT_CODE_TOKEN_RVA(0x65439u));
label_00065439:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46543Eu)); sfera_sub_00459E40(cpu, LIFT_CODE_TOKEN_VA(0x46543Eu));
    cpu->ecx = (uintptr_t)"landscape";
    g_sfera_files.addSearchPath(SferaAbi::pointer<const char>(cpu->ecx));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == cpu->ebx) goto label_0006545A;
    cpu->ecx = (uintptr_t)"landscape_hr";
    g_sfera_files.addSearchPath(SferaAbi::pointer<const char>(cpu->ecx));
label_0006545A:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == cpu->ebx) goto label_0006546C;
    cpu->ecx = (uintptr_t)"landscape_ph";
    g_sfera_files.addSearchPath(SferaAbi::pointer<const char>(cpu->ecx));
label_0006546C:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == cpu->ebx) goto label_0006547E;
    cpu->ecx = (uintptr_t)"landscape_rd";
    g_sfera_files.addSearchPath(SferaAbi::pointer<const char>(cpu->ecx));
label_0006547E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465483u)); sfera_sub_0045AA50(cpu, LIFT_CODE_TOKEN_VA(0x465483u));
    g_sfera_graphics_runtime.initialize();
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->supports_post_effects);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0006549D;
    g_sfera_graphics_runtime.post_effects_enabled = cpu->ebx;
label_0006549D:
    CCursorManager::instance();
label_000654D3:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_runtime.hardware_cursor_enabled) != cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(&CCursorManager::instance());
    CCursorManager::instance().select(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); cpu->esp += 4u;
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    --cpu->edx;
    lift_push32(cpu, cpu->edx);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465503u)); sfera_sub_004556B0(cpu, LIFT_CODE_TOKEN_VA(0x465503u));
    x87_p0 = 1.0;
    x87_p1 = 0.0;
    cpu->eax = sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::z);
     value_11 = x87_p1; value_12 = x87_p0; goto label_00065589;
label_0006550E:
    lift_test[0]=(*(uint8_t*)(cpu->esp + 0x38u)&0x10u)==0u;
    lift_push32(cpu, cpu->eax);
    if (lift_test[0]) goto label_00065530;
    cpu->edi = native_function_address32(&::_findclose);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) = 1u;
    goto label_000653CA;
label_00065530:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    goto label_000653C4;
label_0006553A:
    lift_test[1]=(*(uint8_t*)(cpu->esp + 0x38u)&0x10u)==0u;
    lift_push32(cpu, cpu->eax);
    if (lift_test[1]) goto label_00065556;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21) = 1u;
    goto label_000653EA;
label_00065556:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    goto label_000653E4;
label_00065560:
    lift_test[2]=(*(uint8_t*)(cpu->esp + 0x38u)&0x10u)==0u;
    lift_push32(cpu, cpu->eax);
    if (lift_test[2]) goto label_0006557D;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findclose)))(*(uint32_t*)(cpu->esp));
    cpu->ebp = 1u;
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22) = cpu->ebp;
    goto label_0006540F;
label_0006557D:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_findclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 4u;
    goto label_00065404;
label_00065587:
label_00065589:
    *(float*)(cpu->eax) = value_11;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ebx;
    cpu->eax += 0x20u;
    *(float*)(cpu->eax + 0xFFFFFFE4u) = value_12;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)((uint32_t)((uint64_t)(sfera_screen_vertex_field_end_address(g_sfera_landscape_screen_vertices, &SferaScreenVertex::z))));
    if (sub_pred[0]) goto label_00065587;
    cpu->edi = native_function_address32(&::ShowCursor);

     cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(cpu->ebx);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(cpu->ebp);
    if ((int32_t)cpu->eax < (int32_t)cpu->ebx) goto label_000655B8;
label_000655B1:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(cpu->ebx);
    if ((int32_t)cpu->eax >= (int32_t)cpu->ebx) goto label_000655B1;
label_000655B8:
    cpu->edx = 0x1D1Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4655C7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4655C7u));
    lift_push32(cpu, 0x10A9ACu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4655D1u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x4655D1u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x210u) = 2u;
    if (cpu->eax == cpu->ebx) goto label_000655F2;
    lift_push32(cpu, (uintptr_t)"xadd\\snowpath.bin");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4655F0u)); sfera_sub_00495570(cpu, LIFT_CODE_TOKEN_VA(0x4655F0u));
    goto label_000655F4;
label_000655F2:
    cpu->eax = 0u;
label_000655F4:
    cpu->esi = native_function_address32(&::sprintf);
    g_sfera_world_load_runtime.snow_path_object = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    *(uint8_t*)(cpu->esp + 0x210u) = 0u;
    if (cpu->eax == cpu->ebx) goto label_0006562D;
    if (cpu->eax == cpu->ebp) goto label_0006562D;
    lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->ecx = cpu->esp + 0x164u;
    lift_push32(cpu, (uintptr_t)"fonts\\font1%s.pcx"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x65626u));
    cpu->esp += 0xCu;
    goto label_00065660;
label_0006562D:
    cpu->edx = *(uint32_t*)((uintptr_t)"fonts\\font1.pcx");
    cpu->eax = *(uint32_t*)(((uintptr_t)"fonts\\font1.pcx") + 4u);
    cpu->ecx = *(uint32_t*)(((uintptr_t)"fonts\\font1.pcx") + 8u);
    *(uint32_t*)(cpu->esp + 0x160u) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"fonts\\font1.pcx") + 0xCu);
    *(uint32_t*)(cpu->esp + 0x164u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x16Cu) = cpu->edx;
label_00065660:
    lift_push32(cpu, 5u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x16Cu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465672u)); sfera_sub_00459FA0(cpu, LIFT_CODE_TOKEN_VA(0x465672u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    if (cpu->eax == cpu->ebx) goto label_00065698;
    if (cpu->eax == cpu->ebp) goto label_00065698;
    lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = cpu->esp + 0x164u;
    lift_push32(cpu, (uintptr_t)"fonts\\font2%s.pcx"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x65691u));
    cpu->esp += 0xCu;
    goto label_000656CB;
label_00065698:
    cpu->ecx = *(uint32_t*)((uintptr_t)"fonts\\font2.pcx");
    cpu->edx = *(uint32_t*)(((uintptr_t)"fonts\\font2.pcx") + 4u);
    cpu->eax = *(uint32_t*)(((uintptr_t)"fonts\\font2.pcx") + 8u);
    *(uint32_t*)(cpu->esp + 0x160u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"fonts\\font2.pcx") + 0xCu);
    *(uint32_t*)(cpu->esp + 0x164u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x16Cu) = cpu->ecx;
label_000656CB:
    lift_push32(cpu, 3u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x16Cu;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4656DDu)); sfera_sub_00459FA0(cpu, LIFT_CODE_TOKEN_VA(0x4656DDu));
    x87_p0 = 0.0;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[0][0]) = x87_p0;
    cpu->eax = 0u;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[1][0]) = x87_p0;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_p1 = 1.0;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[2][0]) = x87_p1;
    std::swap(x87_p1, x87_p0);
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[3][0]) = x87_p1;
    x87_p2 = (double)-1.0f;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[0][1]) = x87_p2;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[1][2]) = x87_p2; 
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[1][1]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[2][1]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[3][1]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[0][2]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[2][2]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[3][2]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[0][3]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[1][3]) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[2][3]) = x87_p1; 
    *(float*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[3][3]) = x87_p0; 
    x87_p0 = 6.0;
     value_13 = x87_p0; 
label_00065755:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_p0 = (x87_p0) / (value_13);
    *(float*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.normalized_levels[0])) = x87_p0; 
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)7u) goto label_00065755;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[0].f32) = (double)2.0f;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[1].f32) = (double)0.20000000298023224f;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[2].f32) = (double)0.75f;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[3].f32) = (double)1.2000000476837158f;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[4].f32) = (double)2.5f;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[5].f32) = (double)3.0f;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.blend_weights[6].f32) = (double)4.0f;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4657C8u)); sfera_sub_0044DAC0(cpu, LIFT_CODE_TOKEN_VA(0x4657C8u));
    cpu->ebp = 0u;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
label_000657D0:
    *(float*)(cpu->esp + 0x18u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))))) / (12.0)))) + (1.0)))) - (0.041666666666666664));
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p0 = (x87_p0) + (0.5);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->ebx) goto label_0006580C;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6580Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6580Cu));
label_0006580C:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_scene_array_runtime.render_pass_slots.capacity) goto label_00065820;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x65820u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x65820u));
label_00065820:
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->edx = g_sfera_scene_array_runtime.render_pass_slots.data;
    x87_p0 = (x87_p0) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->edi += 0xFEu;
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    *(float*)(cpu->edx + (cpu->ebp * 4u) + 0xFFFFFFFCu) = x87_p0; 
    if ((int32_t)cpu->edi < (int32_t)0xBE8u) goto label_000657D0;
    cpu->ebp = (uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource;
label_00065850:
    cpu->ecx = 0x20000u;
    
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(D3DXCreateTexture(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device, *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), static_cast<D3DFORMAT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), static_cast<D3DPOOL>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)), SferaAbi::pointer<IDirect3DTexture9*>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u))), "D3DXCreateTexture")); cpu->esp += 32u;
    if (*(uint32_t*)(cpu->ebp) == cpu->ebx) goto label_00065A9C;
    cpu->ebp += 0x10u;
    if ((int32_t)cpu->ebp < (int32_t)((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource + kTextureCacheEntryCount * (uint32_t)sizeof(SferaTextureCacheEntry))) goto label_00065850;
    x87_p0 = 0.5;
    cpu->edi = 0u;
    cpu->ebp = 0u;
     value_14 = x87_p0;  value_0 = value_14;
label_00065899:
    if ((int32_t)cpu->edi >= 0) { value_1 = value_0; goto label_000658AF; }
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4658A9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x4658A9u));
    x87_p0 = 0.5;
     value_15 = x87_p0;  value_1 = value_15;
label_000658AF:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.render_pass_slots.capacity) goto label_000658CB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4658C5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x4658C5u));
    x87_p0 = 0.5;
label_000658CB:
    cpu->eax = g_sfera_scene_array_runtime.render_pass_slots.data;
    x87_p0 = (double)*(float*)(cpu->eax + (cpu->edi * 4u));
    cpu->esi = 0u;
    *(float*)(cpu->esp + 0x18u) = x87_p0;  value_2 = value_1;
label_000658D9:
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u); x87_p1 = x87_p0;
    x87_p1 = (x87_p1) + (value_2);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p1); 
    x87_p1 = x87_p0;
    cpu->ebx = cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    x87_p1 = (x87_p1) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))));
    x87_p1 = (x87_p1) - (value_2);
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p1 = (x87_p1) * (64.0);
    x87_p1 = (x87_p1) + (value_2);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p1); 
    x87_p0 = (x87_p0) + (0.0833333358168602);
    *(uint8_t*)(cpu->esi + cpu->ebp + ((uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_b[0])) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esi + cpu->ebp + ((uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_a[0])) = cpu->ebx & 0xFFu;
    ++cpu->esi;
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    if ((int32_t)cpu->esi < (int32_t)0x100u) goto label_000658D9;
    ++cpu->edi;
    cpu->ebp += 0x100u;
    if ((int32_t)cpu->edi < (int32_t)0xCu) { value_0 = value_2; goto label_00065899; }
    x87_p0 = 0.015625;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    x87_p1 = 255.0;
    cpu->ecx = (uintptr_t)&g_sfera_static_render_lookup_runtime.blend_lut[1];
     value_16 = x87_p1; value_17 = x87_p0;  value_3 = value_2;
label_00065954:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    x87_p0 = (x87_p0) * (value_17);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p1 = x87_p0;
    x87_p2 = 1.0;
    x87_p1 = x87_p2 - x87_p1; 
     value_18 = x87_p1; value_19 = x87_p0;  value_4 = value_3;
label_0006596E:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    ++cpu->edx;
    cpu->ecx += 4u;
    x87_p0 = (x87_p0) * (value_17);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p1 = x87_p0;
    x87_p2 = 1.0;
    x87_p1 = x87_p2 - x87_p1; 
    x87_p2 = x87_p1;
    x87_p2 = (x87_p2) * (value_18);
    *(float*)(cpu->esp + 0x1Cu) = x87_p2; 
    x87_p2 = x87_p0;
    x87_p2 = (x87_p2) * (value_18);
    *(float*)(cpu->esp + 0x2Cu) = x87_p2; 
    x87_p1 = (x87_p1) * (value_19);
    *(float*)(cpu->esp + 0x28u) = x87_p1; 
    x87_p0 = (x87_p0) * (value_19);
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p0 = (x87_p0) * (value_16);
    *(uint32_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_p0));
    cpu->eax = *(uint8_t*)(cpu->esp + 0x1Cu);
    *(uint8_t*)(cpu->ecx + 0xFFFFFFFBu) = cpu->eax & 0xFFu;
    x87_p0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p0 = (x87_p0) * (value_16);
    *(uint32_t*)(cpu->esp + 0x2Cu) = static_cast<int64_t>(std::trunc(x87_p0));
    cpu->eax = *(uint8_t*)(cpu->esp + 0x2Cu);
    *(uint8_t*)(cpu->ecx + 0xFFFFFFFCu) = cpu->eax & 0xFFu;
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = (x87_p0) * (value_16);
    *(uint32_t*)(cpu->esp + 0x28u) = static_cast<int64_t>(std::trunc(x87_p0));
    cpu->eax = *(uint8_t*)(cpu->esp + 0x28u);
    *(uint8_t*)(cpu->ecx + 0xFFFFFFFDu) = cpu->eax & 0xFFu;
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u);
    x87_p0 = (x87_p0) * (value_16);
    *(uint32_t*)(cpu->esp + 0x20u) = static_cast<int64_t>(std::trunc(x87_p0));
    cpu->eax = *(uint8_t*)(cpu->esp + 0x20u);
    *(uint8_t*)(cpu->ecx + 0xFFFFFFFEu) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)0x40u) goto label_0006596E;
    ++*(uint32_t*)(cpu->esp + 0x18u);
     if ((int32_t)cpu->ecx < (int32_t)((uintptr_t)&g_sfera_static_render_lookup_runtime.blend_lut[kRenderBlendLutStorageSize])) { value_3 = value_4; goto label_00065954; }
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    value_20 = 220.0;
      value_5 = value_4;
label_00065A83:
    if ((int32_t)cpu->ebx <= (int32_t)0xDCu) goto label_00065AA6;
    *(uint8_t*)((cpu->ebx * 2u) + ((uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][0])) = cpu->ebx & 0xFFu;
    *(uint8_t*)((cpu->ebx * 2u) + ((uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][1])) = 0u;
    value_6 = value_5; goto label_00065AEF;
label_00065A9C:
    cpu->ecx = (uintptr_t)"CreateTexture for landscape cash failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x65AA6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x65AA6u));
label_00065AA6:
    *(float*)(cpu->esp + 0x20u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u); x87_p1 = x87_p0;
    x87_p1 = (x87_p1) * (value_5);
    x87_p1 = (x87_p1) / (value_20);
    x87_p1 = (x87_p1) + (value_5);
    *(float*)(cpu->esp + 0x20u) = x87_p1; 
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x20u)));
    x87_p0 = (x87_p0) + (value_5);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x8Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    cpu->eax += cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 8u;
    *(uint8_t*)((cpu->ebx * 2u) + ((uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][0])) = cpu->ecx & 0xFFu;
    *(uint8_t*)((cpu->ebx * 2u) + ((uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][1])) = cpu->eax & 0xFFu; value_6 = value_5;
label_00065AEF:
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)0x100u) { value_5 = value_6; goto label_00065A83; }
    lift_push32(cpu, 0x100u);
    lift_push32(cpu, 0u);
    lift_push32(cpu, (uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0]);
     lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x465B0Cu));
    cpu->esp += 0xCu;
    g_sfera_static_render_lookup_runtime.glyph_presence[0xFF] = 1u;
    *(uint32_t*)((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0x23]) = 0x1010101u;
    *(uint16_t*)((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0x27]) = 0x101u;
    g_sfera_static_render_lookup_runtime.glyph_presence[0x2E] = 1u;
    *(uint16_t*)((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0x21]) = 0x101u;
    g_sfera_motion.initializeResponseCurve();
    cpu->ecx = cpu->esp + 0x30u;
    *(uint32_t*)(cpu->esp + 0x210u) = 0xFFFFFFFFu;
    
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x200u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004676F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    CCursorManager::instance();
label_0006774E:
    cpu->ecx = SferaAbi::address(CCursorManager::instance().currentCursor());
    if (cpu->ecx != 0u) goto label_00067762;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67762u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x67762u));
    label_00067762:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = 0u;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count <= (int32_t)cpu->esi) goto label_00067841;
    label_0006778A:
    if ((int32_t)cpu->esi >= 0) goto label_00067798;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67798u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x67798u));
    label_00067798:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_000677AC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x677ACu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x677ACu));
    label_000677AC:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 0u) goto label_000677BB;
    ++cpu->esi;
    goto label_0006778A;
    label_000677BB:
    if ((int32_t)cpu->esi >= 0) goto label_000677C9;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x677C9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x677C9u));
    label_000677C9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_000677DD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x677DDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x677DDu));
    label_000677DD:
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->ebx = cpu->edx + (cpu->esi * 4u);
    if ((int32_t)cpu->esi >= 0) goto label_000677F4;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x677F4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x677F4u));
    label_000677F4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00067808;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67808u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67808u));
    label_00067808:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x3Cu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xFFFFFC18u);
    cpu->eax -= *(uint32_t*)(cpu->ecx + 0x6DA4u);
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0])) = cpu->esi;
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0])) = cpu->eax;
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count) goto label_0006778A;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00067841:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    --cpu->edx;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46784Fu)); sfera_sub_0044F940(cpu, LIFT_CODE_TOKEN_VA(0x46784Fu));
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count <= (int32_t)cpu->edi) goto label_000678AD;
    label_00067859:
    cpu->esi = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    if ((int32_t)cpu->esi >= 0) goto label_0006786E;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6786Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6786Eu));
    label_0006786E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00067882;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67882u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67882u));
    label_00067882:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint32_t*)(cpu->eax) != 1u) goto label_000678A4;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->eax + 0xCu)) goto label_000678A4;
    if ((int32_t)cpu->ebp > (int32_t)*(uint32_t*)(cpu->eax + 0x10u)) goto label_000678A4;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->eax + 0x14u)) goto label_000678A4;
    if ((int32_t)cpu->ebx <= (int32_t)*(uint32_t*)(cpu->eax + 0x18u)) goto label_000678C3;
    label_000678A4:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count) goto label_00067859;
    label_000678AD:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000678C3:
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->eax + 0x1Cu)) goto label_000678F2;
    if ((int32_t)cpu->ebp > (int32_t)*(uint32_t*)(cpu->eax + 0x20u)) goto label_000678F2;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->eax + 0x24u)) goto label_000678F2;
    if ((int32_t)cpu->ebx > (int32_t)*(uint32_t*)(cpu->eax + 0x28u)) goto label_000678F2;
    cpu->eax = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000678F2:
    cpu->eax = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00467910(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->edx) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467926u)); sfera_sub_004676F0(cpu, LIFT_CODE_TOKEN_VA(0x467926u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_00067936;
    cpu->esi = 0u - (uint64_t)(cpu->esi);
    *(uint32_t*)(cpu->edi) = cpu->esi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00067936:
    *(uint32_t*)(cpu->edi) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0006794C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6794Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6794Cu));
    label_0006794C:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax = SferaAbi::address(CCursorManager::instance().activeCursor());
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ebx = 0u;
    cpu->ebp = cpu->esi + 0x44u;
    label_00067980:
    cpu->edi = *(uint32_t*)(cpu->ebp);
    if (cpu->edi == 0xFFFFFFFFu) goto label_00067A49;
    if ((int32_t)cpu->edi >= 0) goto label_0006799A;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6799Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6799Au));
    label_0006799A:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000679AE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x679AEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x679AEu));
    label_000679AE:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi + 0x34u)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<=lift_right)) goto label_00067A47; }
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi + 0x34u)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>=lift_right)) goto label_00067A49; }
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->eax += cpu->edx;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi + 0x38u)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<=lift_right)) goto label_00067A47; }
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi + 0x38u)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>=lift_right)) goto label_00067A49; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00067A47:
    x87_v0 = x87_v0; 
    label_00067A49:
    ++cpu->ebx;
    cpu->ebp += 4u;
    if ((int32_t)cpu->ebx < (int32_t)0x1B58u) goto label_00067980;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00467A70(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    CCursorManager::instance();
label_00067ACC:
    cpu->ecx = SferaAbi::address(CCursorManager::instance().currentCursor());
    if (cpu->ecx != 0u) goto label_00067AE0;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67AE0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x67AE0u));
    label_00067AE0:
    cpu->eax = reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind();
    if (g_sfera_recovered_static_runtime.interaction_enabled == 0u) goto label_00067CCD;
    x87_v0 = (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x))));
    cpu->eax = g_sfera_window_runtime.active_window_index;
    x87_v1 = 1.5; x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xCu) = x87_v1; 
    x87_v0 = (x87_v0) * ((double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y)))));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if (cpu->eax == 0u) goto label_00067B30;
    cpu->eax = SferaAbi::address(CCursorManager::instance().activeCursor());
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->updatePosition();
    cpu->eax = g_sfera_window_runtime.active_window_index;
    label_00067B30:
    if (cpu->eax != 0xFFFFFFFFu) goto label_00067B56;
    if ((((*(uint8_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state)) & (2u)) == 0u) goto label_00067CBF;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467B47u)); sfera_sub_004676F0(cpu, LIFT_CODE_TOKEN_VA(0x467B47u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    g_sfera_window_runtime.active_window_index = cpu->eax;
    goto label_00067CBF;
    label_00067B56:
    if ((((*(uint8_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state)) & (2u)) == 0u) goto label_00067CB5;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_00067B78;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467B73u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x467B73u));
    cpu->eax = g_sfera_window_runtime.active_window_index;
    label_00067B78:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00067B91;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467B8Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x467B8Cu));
    cpu->eax = g_sfera_window_runtime.active_window_index;
    label_00067B91:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->eax == 0u) goto label_00067CBF;
    if (*(uint32_t*)(cpu->esi + 4u) != 1u) goto label_00067CBF;
    x87_v0 = (double)*(float*)(cpu->esi + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x20u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0xCu)));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ecx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x30u);
    *(float*)(cpu->esi + 0x34u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi + 0x38u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 0x10u)));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = cpu->edx + cpu->eax + 0xFFFFFFFFu;
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->eax = SferaAbi::address(CCursorManager::instance().activeCursor());
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    x87_v0 = 0.0;
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esi + 0x34u)); if (!(lift_left>lift_right)) goto label_00067C14; }
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 0x34u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(float*)(cpu->esi + 0x34u) = x87_v0;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_00067C14:
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esi + 0x38u)); if (!(lift_left>lift_right)) goto label_00067C33; }
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 0x38u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_00067C35;
    label_00067C33:
    x87_v0 = x87_v0; 
    label_00067C35:
    *(float*)(cpu->esp + 0x18u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    x87_v0 = (double)*(float*)(cpu->esi + 0x34u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_00067C66; }
    x87_v1 = (double)*(float*)(cpu->esi + 0x34u);
    x87_v1 = (x87_v1) - (x87_v0);
    x87_v1 = (x87_v1) + ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(float*)(cpu->esi + 0x34u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_00067C68;
    label_00067C66:
    x87_v0 = x87_v0; 
    label_00067C68:
    *(float*)(cpu->esp + 0x1Cu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu))));
    x87_v0 = (double)*(float*)(cpu->esi + 0x38u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_00067C99; }
    x87_v1 = (double)*(float*)(cpu->esi + 0x38u);
    x87_v1 = (x87_v1) - (x87_v0);
    x87_v1 = (x87_v1) + ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_00067C9B;
    label_00067C99:
    x87_v0 = x87_v0; 
    label_00067C9B:
    cpu->eax = SferaAbi::address(CCursorManager::instance().activeCursor());
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setPosition(static_cast<int32_t>(*(uint32_t*)(cpu->esp)), static_cast<int32_t>(*(uint32_t*)(cpu->esp + 4u))); cpu->esp += 8u;
    goto label_00067CBF;
    label_00067CB5:
    g_sfera_window_runtime.active_window_index = 0xFFFFFFFFu;
    label_00067CBF:
    cpu->eax = SferaAbi::address(CCursorManager::instance().activeCursor());
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->show();
    label_00067CCD:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(void*)&g_sfera_recovered_static_runtime.interaction_input_flags);
    cpu->edi = 0u;
    cpu->eax&=1u;
    if (cpu->eax==0u) goto label_00067CE9;
    if ((((cpu->ecx & 0xFFu)) & (1u)) != 0u) goto label_00067CE9;
    cpu->edi = 1u;
    label_00067CE9:
    if (cpu->eax != 0u) goto label_00067CF7;
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_00067CF7;
    cpu->edi = cpu->eax + 2u;
    goto label_00067CFF;
    label_00067CF7:
    if (cpu->edi == 0u) goto label_00067E4B;
    label_00067CFF:
    cpu->edx = cpu->esp + 0xCu;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467D0Cu)); sfera_sub_00467910(cpu, LIFT_CODE_TOKEN_VA(0x467D0Cu));
    if (g_sfera_recovered_static_runtime.interaction_enabled != 0u) goto label_00067D21;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0xFFFFFFFFu;
    goto label_00067D33;
    label_00067D21:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->esi >= 0) goto label_00067D33;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67D33u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x67D33u));
    label_00067D33:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00067D47;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67D47u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67D47u));
    label_00067D47:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x6E08u) >= (int32_t)0xAu) goto label_00067E4B;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DD8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6E00u);
    *(uint32_t*)(cpu->eax + 0x6DDCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DD4u);
    *(uint32_t*)(cpu->eax + 0x6E04u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DFCu);
    *(uint32_t*)(cpu->eax + 0x6DD8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DD0u);
    *(uint32_t*)(cpu->eax + 0x6E00u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DF8u);
    *(uint32_t*)(cpu->eax + 0x6DD4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DCCu);
    *(uint32_t*)(cpu->eax + 0x6DFCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DF4u);
    *(uint32_t*)(cpu->eax + 0x6DD0u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DC8u);
    *(uint32_t*)(cpu->eax + 0x6DF8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DF0u);
    *(uint32_t*)(cpu->eax + 0x6DCCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DC4u);
    *(uint32_t*)(cpu->eax + 0x6DF4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DECu);
    *(uint32_t*)(cpu->eax + 0x6DC8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DC0u);
    *(uint32_t*)(cpu->eax + 0x6DF0u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DE8u);
    *(uint32_t*)(cpu->eax + 0x6DC4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DBCu);
    *(uint32_t*)(cpu->eax + 0x6DECu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DE4u);
    *(uint32_t*)(cpu->eax + 0x6DC0u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6DB8u);
    *(uint32_t*)(cpu->eax + 0x6DE8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DE0u);
    *(uint32_t*)(cpu->eax + 0x6DBCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 0x6DE4u) = cpu->ecx;
    ++*(uint32_t*)(cpu->eax + 0x6E08u);
    *(uint32_t*)(cpu->eax + 0x6DB8u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x6DE0u) = cpu->edi;
    label_00067E4B:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    g_sfera_recovered_static_runtime.interaction_input_flags = cpu->eax;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00467E70(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = cpu->edx;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)cpu->edi < 0) goto label_00067EA9;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00067E9F;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67E9Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67E9Fu));
    label_00067E9F:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) != cpu->ebx) goto label_00067ED3;
    label_00067EA9:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = cpu->ebx & 0xFFu;
    --cpu->edi;
    label_00067EB5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00067EB5;
    cpu->esi = (uintptr_t)"create_sprite: wrong window handle";
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),35u); cpu->esi += 35u; cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467ED1u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x467ED1u));
    cpu->edi = 0u;
    label_00067ED3:
    if ((int32_t)cpu->ebx >= 0) goto label_00067EE1;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67EE1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x67EE1u));
    label_00067EE1:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00067EF5;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67EF5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67EF5u));
    label_00067EF5:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->ebx * 4u)) == 0u) goto label_00067F04;
    ++cpu->ebx;
    goto label_00067ED3;
    label_00067F04:
    lift_push32(cpu, 0x30B0u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xE84u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467F18u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x467F18u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_00067F28;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67F28u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x67F28u));
    label_00067F28:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00067F3C;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67F3Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67F3Cu));
    label_00067F3C:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    *(uint32_t*)(cpu->edx + (cpu->ebx * 4u)) = cpu->esi;
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esi) = 1u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467F57u)); sfera_sub_0045DC60(cpu, LIFT_CODE_TOKEN_VA(0x467F57u));
    x87_v0 = 1.0;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(float*)(cpu->esi + 0x24u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->ecx + cpu->ebp + 0xFFFFFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    cpu->edx = cpu->ecx + cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->edx;
    if ((int32_t)cpu->edi >= 0) goto label_00067F9A;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67F9Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x67F9Au));
    label_00067F9A:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00067FAE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67FAEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67FAEu));
    label_00067FAE:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0xE48u) = cpu->edx;
    if ((int32_t)cpu->edi >= 0) goto label_00067FD1;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67FD1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x67FD1u));
    label_00067FD1:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00067FE5;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67FE5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x67FE5u));
    label_00067FE5:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0xE54u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0xE4Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0xE50u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xE80u) = cpu->ecx;
    cpu->esi -= cpu->eax;
    label_00068020:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax + 0xE58u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00068020;
    g_sfera_main_view_state_runtime.projection_sample_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) + 1u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46803Bu)); sfera_sub_0045EBE0(cpu, LIFT_CODE_TOKEN_VA(0x46803Bu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00468050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 1u;
    cpu->edi = cpu->edx;
    g_sfera_world_objects.recalculateBasis(cpu->ecx);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_0006808C;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6808Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6808Cu));
    label_0006808C:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->eax != 0u) goto label_00068108;
    label_00068098:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14Cu);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x150u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x154u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_000680CA;
    cpu->edx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x680CAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x680CAu));
    label_000680CA:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->eax != 0u) goto label_00068150;
    label_000680D7:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x158u);
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x15Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x408u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x160u);
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00068108:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00068098;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00068129;
    cpu->eax = (uintptr_t)"<none>";
    label_00068129:
    lift_push32(cpu, 0x38DEu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46813Eu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68150u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x68150u));
    label_00068150:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_000680D7;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00068175;
    cpu->eax = (uintptr_t)"<none>";
    label_00068175:
    lift_push32(cpu, 0x38DFu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46818Au));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46819Cu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x46819Cu));
    cpu->eip = 0x46819Cu; ::DebugBreak(); return;
}

__declspec(noinline) void sfera_sub_00468310(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    bool lift_cmp[1];
    cpu->esp -= 0x108u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_0006833D;
    cpu->edx = cpu->edi + 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6833Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6833Du));
    label_0006833D:
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0]);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    x87_v1 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    x87_v2 = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    lift_cmp[0]=x87_v2!=x87_v0;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    g_sfera_client_main_scalar_runtime.counter_01 = cpu->ecx;
    x87_v0 = x87_v1; 
    if (lift_cmp[0]) goto label_000683AE;
    { const double lift_right=(double)*(float*)((uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][1]); const double lift_left=x87_v0; if (lift_left!=lift_right) goto label_000683AE; }
    { const double lift_right=(double)*(float*)((uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][2]); const double lift_left=x87_v0; if (lift_left!=lift_right) goto label_000683AE; }
    { const double lift_right=(double)*(float*)((uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][3]); const double lift_left=x87_v0; if (lift_left==lift_right) goto label_00068738; }
    label_000683AE:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->esi);
    if ((int32_t)g_sfera_recovered_static_runtime.client_state_02 <= (int32_t)cpu->ecx) goto label_0006857C;
    x87_v0 = x87_v0; 
    label_000683C1:
    if ((int32_t)cpu->edi >= 0) goto label_000683CF;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x683CFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x683CFu));
    label_000683CF:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_000683E3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x683E3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x683E3u));
    label_000683E3:
    cpu->ecx = g_sfera_light_runtime.handles.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) != 0u) goto label_000683F2;
    ++cpu->edi;
    goto label_000683C1;
    label_000683F2:
    if ((int32_t)cpu->edi >= 0) goto label_00068400;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68400u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68400u));
    label_00068400:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_00068414;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68414u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68414u));
    label_00068414:
    cpu->edx = g_sfera_light_runtime.handles.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    x87_v0 = (double)*(float*)(cpu->esi + 0x1Cu);
    cpu->ecx = cpu->esi + 0x20u;
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    *(float*)(cpu->esp + 0x44u) = (double)*(float*)(cpu->esi + 0x1Cu);
    *(float*)(cpu->esp + 0x48u) = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->esi);
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v1 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    x87_v2 = (double)*(float*)(cpu->esp + 0x44u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = x87_v2; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v2 = (double)*(float*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    x87_v3 = (double)*(float*)(cpu->esp + 0x48u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x30u) = x87_v3; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v3 = (double)*(float*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v2; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x38u) = x87_v1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 8u)));
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edx;
    cpu->edx = cpu->esp + 0xB4u;
    *SferaAbi::pointer<SferaBoundsCornersRuntime>(cpu->edx) = SferaBoundsCornersRuntime::fromExtents(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->ecx + 12u));
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0xB8u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    cpu->eax = static_cast<std::uint32_t>((static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) <= 0 ? 0 : SferaAbi::pointer<const SferaFrustumF>(cpu->ecx)->classifyPoints(std::span<const SferaVec3F>(SferaAbi::pointer<const SferaVec3F>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))))); cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00068541;
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_01;
    cpu->ebx = cpu->eax;
    ++cpu->eax;
    g_sfera_client_main_scalar_runtime.counter_01 = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_000684E6;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x684E6u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x684E6u));
    label_000684E6:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_000684FA;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x684FAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x684FAu));
    label_000684FA:
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + (cpu->ebx * 4u)) = cpu->esi;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x20u))) - (((double)*(float*)(cpu->esi + 4u))));
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->esp + 0x24u))) - (((double)*(float*)(cpu->esi + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esi + 0x38u) = x87_v0; 
    label_00068541:
    ++cpu->ebp;
    ++cpu->edi;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_recovered_static_runtime.client_state_02) goto label_000683C1;
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_01;
    if ((int32_t)cpu->ecx <= (int32_t)1u) goto label_0006856A;
    cpu->edx = cpu->ecx + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468564u)); sfera_sub_00456100(cpu, LIFT_CODE_TOKEN_VA(0x468564u));
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_01;
    label_0006856A:
    x87_v0 = 0.0;
    if ((int32_t)cpu->ecx <= (int32_t)0x1Eu) goto label_0006857C;
    cpu->ecx = 0x1Eu;
    g_sfera_client_main_scalar_runtime.counter_01 = cpu->ecx;
    label_0006857C:
    x87_v1 = 1.0;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 1u;
    *(float*)(cpu->esp + 0x5Cu) = x87_v1;
    *(float*)(cpu->esp + 0x60u) = x87_v1;
    *(float*)(cpu->esp + 0x64u) = x87_v1;
    *(float*)(cpu->esp + 0x68u) = x87_v1;
    *(float*)(cpu->esp + 0x6Cu) = x87_v1;
    *(float*)(cpu->esp + 0x7Cu) = x87_v1;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x70u) = x87_v1;
    *(float*)(cpu->esp + 0x74u) = x87_v1;
    *(float*)(cpu->esp + 0x78u) = x87_v1;
    *(float*)(cpu->esp + 0x10u) = x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x18u) = x87_v1;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x9Cu) = x87_v1;
    *(float*)(cpu->esp + 0xA8u) = x87_v1; 
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->edx;
    *(float*)(cpu->esp + 0xA0u) = x87_v0;
    *(float*)(cpu->esp + 0xA4u) = x87_v0;
    *(float*)(cpu->esp + 0xACu) = x87_v0;
    *(float*)(cpu->esp + 0xB0u) = x87_v0; 
    if ((int32_t)cpu->ecx <= 0) goto label_0006871F;
    cpu->esi = 1u;
    cpu->ebx = cpu->esi + 3u;
    label_00068615:
    cpu->edi = cpu->esi + 0xFFFFFFFFu;
    if ((int32_t)cpu->edi >= 0) goto label_00068626;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68626u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68626u));
    label_00068626:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_0006863A;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6863Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6863Au));
    label_0006863A:
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ebx + cpu->eax + 0xFFFFFFFCu);
    x87_v0 = (double)*(float*)(cpu->eax + 0xCu);
    x87_v1 = 0.003921568859368563;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x50u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x54u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 0x14u)));
    *(float*)(cpu->esp + 0x58u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->esp + 0x4Cu;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->eax + 0x1Cu);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->esp + 0x98u) = x87_v0; 
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetLight(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<const D3DLIGHT9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetLight")); cpu->esp += 8u;
    if ((int32_t)cpu->esi >= 0) goto label_000686AA;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x686AAu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x686AAu));
    label_000686AA:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_000686BE;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x686BEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x686BEu));
    label_000686BE:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->ebx + cpu->eax) == 0u) goto label_0006870C;
    g_sfera_main_command_state_runtime.light_update_counter = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u;
    if ((int32_t)cpu->esi >= 0) goto label_000686DD;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x686DDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x686DDu));
    label_000686DD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_000686F1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x686F1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x686F1u));
    label_000686F1:
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->ebx + cpu->ecx) = 0u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->LightEnable(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) != 0u), "LightEnable")); cpu->esp += 8u;
    label_0006870C:
    ++cpu->esi;
    cpu->edx = cpu->esi + 0xFFFFFFFFu;
    cpu->ebx += 4u;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_client_main_scalar_runtime.counter_01) goto label_00068615;
    label_0006871F:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x108u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00068738:
    x87_v0 = x87_v0; 
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x108u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00468750(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    SphereWorld::ContactQuery::updateBounds(cpu->ecx);
    if ((int32_t)cpu->esi >= 0) goto label_0006876A;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6876Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6876Au));
    label_0006876A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006877E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6877Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6877Eu));
    label_0006877E:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ebx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    sub_pred[0] = *(uint8_t*)(cpu->eax + 0x50u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 7u;
    if (!sub_pred[0]) goto label_000687C4;
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x38u) <= (int32_t)2u) goto label_000687C4;
    { const double lift_left=(double)*(float*)(cpu->eax + 0x194u); const double lift_right=15.0; if (!(lift_left>lift_right)) goto label_000687C4; }
    *(uint32_t*)(cpu->esp + 0x10u) = 0x1Eu;
    label_000687C4:
    cpu->eax = 0u;
    cpu->ebp = 0u;
    g_sfera_client_main_scalar_runtime.counter_03 = cpu->eax;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_01 <= (int32_t)cpu->eax) goto label_00068907;
    label_000687E0:
    if ((int32_t)cpu->ebp >= 0) goto label_000687EE;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x687EEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x687EEu));
    label_000687EE:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.visible_handles.capacity) goto label_00068802;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68802u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68802u));
    label_00068802:
    cpu->edx = g_sfera_light_runtime.visible_handles.data;
    x87_v0 = (double)*(float*)(cpu->ebx + 0x7Cu);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u));
    x87_v1 = (double)*(float*)(cpu->ecx + 0x2Cu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left<lift_right) goto label_000688EC; }
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x80u); const double lift_left=(double)*(float*)(cpu->ecx + 0x30u); if (lift_left<lift_right) goto label_000688EC; }
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x84u); const double lift_left=(double)*(float*)(cpu->ecx + 0x34u); if (lift_left<lift_right) goto label_000688EC; }
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x88u); const double lift_left=(double)*(float*)(cpu->ecx + 0x20u); if (lift_left>lift_right) goto label_000688EC; }
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x8Cu); const double lift_left=(double)*(float*)(cpu->ecx + 0x24u); if (lift_left>lift_right) goto label_000688EC; }
    { const double lift_right=(double)*(float*)(cpu->ebx + 0x90u); const double lift_left=(double)*(float*)(cpu->ecx + 0x28u); if (lift_left>lift_right) goto label_000688EC; }
    if ((int32_t)cpu->ebp >= 0) goto label_00068892;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68892u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68892u));
    label_00068892:
    if ((int32_t)(cpu->ebp) < (int32_t)((uint32_t)(g_sfera_light_runtime.visible_handles.capacity))) goto label_000688A6;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x688A6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x688A6u));
    label_000688A6:
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_03;
    cpu->edx = g_sfera_light_runtime.visible_handles.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u));
    { const auto* source_light = SferaAbi::pointer<SferaLightRecord>(cpu->esi); if (source_light != nullptr) g_sfera_collision_scratch_runtime.light_candidates[cpu->eax] = *source_light; }
    cpu->ecx = cpu->ebp + 1u;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0])) = cpu->ecx;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) = 0u;
    ++cpu->eax;
    g_sfera_client_main_scalar_runtime.counter_03 = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->esp + 0x10u)) goto label_000688FE;
    goto label_000688F1;
    label_000688EC:
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_03;
    label_000688F1:
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_client_main_scalar_runtime.counter_01) goto label_000687E0;
    label_000688FE:
    if ((int32_t)cpu->eax > (int32_t)7u) goto label_000689AA;
    label_00068907:
    cpu->edi = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_000689AA;
    label_00068911:
    cpu->esi = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) = 1u;
    if ((int32_t)cpu->esi >= 0) goto label_00068931;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68931u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68931u));
    label_00068931:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068945;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68945u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68945u));
    label_00068945:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->edx + (cpu->esi * 4u)) == 1u) goto label_0006899D;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = cpu->eax;
    if ((int32_t)cpu->eax > (int32_t)8u) goto label_000689B0;
    if ((int32_t)cpu->esi >= 0) goto label_0006896F;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6896Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6896Fu));
    label_0006896F:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068983;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68983u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68983u));
    label_00068983:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = 1u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->LightEnable(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u) != 0u), "LightEnable")); cpu->esp += 8u;
    label_0006899D:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00068911;
    label_000689AA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000689B0:
    lift_push32(cpu, 0x39FEu); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4689BFu));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4689D2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4689D2u));
    cpu->eip = 0x4689D2u; ::DebugBreak(); return;
}



__declspec(noinline) void sfera_sub_00468D30(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_00068D6B;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68D6Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68D6Bu));
    label_00068D6B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00068D7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68D7Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68D7Fu));
    label_00068D7F:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->eax = 1u;
    CCursorManager::instance();
label_00068DC1:
    cpu->ecx = SferaAbi::address(CCursorManager::instance().currentCursor());
    if (cpu->ecx != 0u) goto label_00068DD5;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68DD5u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x68DD5u));
    label_00068DD5:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address(reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(SferaAbi::pointer<SferaCursorPosition>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->ebp < (int32_t)cpu->edi) goto label_00068E26;
    if ((int32_t)cpu->ebp >= (int32_t)*(uint32_t*)(cpu->esi + 0x20u)) goto label_00068E26;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esi + 0x24u)) goto label_00068E26;
    if ((int32_t)cpu->ebx >= (int32_t)*(uint32_t*)(cpu->esi + 0x28u)) goto label_00068E26;
    x87_v0 = (double)*(float*)(cpu->esi + 0x34u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= cpu->edi;
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 0x38u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->eax -= *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->edx) = cpu->eax;
    goto label_00068E3A;
    label_00068E26:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx) = 0xFFFFFFFFu;
    label_00068E3A:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}




__declspec(noinline) void sfera_sub_0046B9E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    cpu->esp -= 0x34u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BA29u)); sfera_sub_00430900(cpu, LIFT_CODE_TOKEN_VA(0x46BA29u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    std::memmove((void*)((uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0]),(void*)(*(uint32_t*)(cpu->edx + 0x1F0u)),96u);
    std::memmove((void*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x),(void*)(*(uint32_t*)(cpu->esp + 0x24u)),60u); cpu->ecx = 0u;
    *(float*)(cpu->esp + 8u) = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x);
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y);
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x18u) = x87_v1;
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x1Cu) = x87_v2;
    cpu->edi = lift_pop32(cpu);
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x);
    cpu->esi = lift_pop32(cpu);
    { const double lift_left=x87_v3; const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0006BA9A; }
    *(float*)(cpu->esp + 0xCu) = x87_v3;
    label_0006BA9A:
    { const double lift_left=x87_v3; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0006BB01; }
    x87_v0 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    label_0006BAAF:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y);
    { const double lift_left=x87_v3; const double lift_right=x87_v1; if (!(lift_left<lift_right)) goto label_0006BAC2; }
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    label_0006BAC2:
    { const double lift_left=x87_v3; const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0006BB05; }
    x87_v1 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    label_0006BAD9:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z);
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (!(lift_left<lift_right)) goto label_0006BAEC; }
    *(float*)(cpu->esp + 0x14u) = x87_v3;
    label_0006BAEC:
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (!(lift_left>lift_right)) goto label_0006BB09; }
    x87_v2 = x87_v3; 
    *(float*)(cpu->esp + 8u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 8u);
    goto label_0006BB0B;
    label_0006BB01:
    x87_v3 = x87_v3; 
    goto label_0006BAAF;
    label_0006BB05:
    x87_v3 = x87_v3; 
    goto label_0006BAD9;
    label_0006BB09:
    x87_v3 = x87_v3; 
    label_0006BB0B:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x);
    { const double lift_left=(double)*(float*)(cpu->esp + 0xCu); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BB22; }
    *(float*)(cpu->esp + 0xCu) = x87_v3;
    label_0006BB22:
    { const double lift_left=x87_v3; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0006BB91; }
    x87_v0 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    label_0006BB37:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BB4E; }
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    label_0006BB4E:
    { const double lift_left=x87_v3; const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0006BB95; }
    x87_v1 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    label_0006BB65:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BB7C; }
    *(float*)(cpu->esp + 0x14u) = x87_v3;
    label_0006BB7C:
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (!(lift_left>lift_right)) goto label_0006BB99; }
    x87_v2 = x87_v3; 
    *(float*)(cpu->esp + 8u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 8u);
    goto label_0006BB9B;
    label_0006BB91:
    x87_v3 = x87_v3; 
    goto label_0006BB37;
    label_0006BB95:
    x87_v3 = x87_v3; 
    goto label_0006BB65;
    label_0006BB99:
    x87_v3 = x87_v3; 
    label_0006BB9B:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].x);
    { const double lift_left=(double)*(float*)(cpu->esp + 0xCu); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BBB2; }
    *(float*)(cpu->esp + 0xCu) = x87_v3;
    label_0006BBB2:
    { const double lift_left=x87_v3; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0006BC21; }
    x87_v0 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    label_0006BBC7:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].y);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BBDE; }
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    label_0006BBDE:
    { const double lift_left=x87_v3; const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0006BC25; }
    x87_v1 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    label_0006BBF5:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].z);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BC0C; }
    *(float*)(cpu->esp + 0x14u) = x87_v3;
    label_0006BC0C:
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (!(lift_left>lift_right)) goto label_0006BC29; }
    x87_v2 = x87_v3; 
    *(float*)(cpu->esp + 8u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 8u);
    goto label_0006BC2B;
    label_0006BC21:
    x87_v3 = x87_v3; 
    goto label_0006BBC7;
    label_0006BC25:
    x87_v3 = x87_v3; 
    goto label_0006BBF5;
    label_0006BC29:
    x87_v3 = x87_v3; 
    label_0006BC2B:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x);
    { const double lift_left=(double)*(float*)(cpu->esp + 0xCu); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BC42; }
    *(float*)(cpu->esp + 0xCu) = x87_v3;
    label_0006BC42:
    { const double lift_left=x87_v3; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_0006BCB1; }
    x87_v0 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    label_0006BC57:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x10u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BC6E; }
    *(float*)(cpu->esp + 0x10u) = x87_v3;
    label_0006BC6E:
    { const double lift_left=x87_v3; const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_0006BCB5; }
    x87_v1 = x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    label_0006BC85:
    x87_v3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v3; if (!(lift_left>lift_right)) goto label_0006BC9C; }
    *(float*)(cpu->esp + 0x14u) = x87_v3;
    label_0006BC9C:
    { const double lift_left=x87_v3; const double lift_right=x87_v2; if (!(lift_left>lift_right)) goto label_0006BCB9; }
    x87_v2 = x87_v3; 
    *(float*)(cpu->esp + 8u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 8u);
    goto label_0006BCBB;
    label_0006BCB1:
    x87_v3 = x87_v3; 
    goto label_0006BC57;
    label_0006BCB5:
    x87_v3 = x87_v3; 
    goto label_0006BC85;
    label_0006BCB9:
    x87_v3 = x87_v3; 
    label_0006BCBB:
    x87_v3 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v4 = 1024.0;
    x87_v3 = (x87_v3) * (x87_v4);
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v4); 
    x87_v0 = (x87_v0) * (x87_v3);
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    g_sfera_view_geometry_runtime.projected_bounds.min_x = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v3 = (x87_v3) * (x87_v0);
    g_sfera_view_geometry_runtime.projected_bounds.max_x = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v2 = (x87_v2) * (x87_v0);
    g_sfera_view_geometry_runtime.projected_bounds.min_y = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v2 = (x87_v2) * (x87_v0);
    g_sfera_view_geometry_runtime.projected_bounds.max_y = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v0 = x87_v0 * x87_v1; 
    g_sfera_view_geometry_runtime.projected_bounds.min_z = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    g_sfera_view_geometry_runtime.projected_bounds.max_z = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BD20u)); sfera_sub_00468310(cpu, LIFT_CODE_TOKEN_VA(0x46BD20u));
    cpu->esp += 0x34u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046BD40(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x134u;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.z);
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    lift_push32(cpu, cpu->ebp);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.x);
    lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->ebp = cpu->edx;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.y);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0x134u;
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BD88u)); sfera_sub_00468050(cpu, LIFT_CODE_TOKEN_VA(0x46BD88u));
    cpu->edi = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006BDA1;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6BDA1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6BDA1u));
    label_0006BDA1:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->eax + 0xCu))) + (((double)*(float*)(cpu->esp + 0x24u))));
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->eax + 0x10u))) + (((double)*(float*)(cpu->esp + 0x28u))));
    *(float*)(cpu->esp + 0xD0u) = ((((double)*(float*)(cpu->eax + 8u))) + (((double)*(float*)(cpu->esp + 0x20u))));
    *(float*)(cpu->esp + 0xD4u) = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0xD8u) = (double)*(float*)(cpu->esp + 0x18u);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006BDF7;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6BDF7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6BDF7u));
    label_0006BDF7:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = cpu->esp + 0x134u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = cpu->esp + 0xD4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.view_matrix);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixLookAtRH), LIFT_CODE_TOKEN_VA(0x46BE18u));
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14Cu))));
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp + 0x24u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x15Cu))));
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0x20u))) / (((double)*(float*)(cpu->esp + 0x24u))));
    *(float*)(cpu->esp + 8u) = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.y);
    *(float*)(cpu->esp + 4u) = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.x);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.z))) * (0.5));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = std::tan(x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esp + 0x1Cu))) / (((double)*(float*)(cpu->esp + 0x28u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = std::atan(x87_v0);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (x87_v0) + (x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.projection_matrix);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixPerspectiveFovRH), LIFT_CODE_TOKEN_VA(0x46BEAAu));
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006BEC3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6BEC3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6BEC3u));
    label_0006BEC3:
    cpu->esi = g_sfera_world_objects.object_handles.data;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edi) goto label_0006BEDD;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6BEDDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6BEDDu));
    label_0006BEDD:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, (uintptr_t)&g_sfera_model_transform_scratch_matrix);
    cpu->edx += 0x14u;
    cpu->ecx += 8u;
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); *destination = SferaMatrix4x4F::fromEuler(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->edx)); cpu->eax = SferaAbi::address(destination); }; cpu->esp += 4u;
    std::memmove((void*)(cpu->esp + 0x90u),(void*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[0][0]),64u);
    cpu->edx = (uintptr_t)&g_sfera_model_transform_scratch_matrix;
    cpu->ecx = cpu->esp + 0x90u;
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(cpu->ecx); *destination = SferaAbi::pointer<const SferaMatrix4x4F>(cpu->edx)->multiplied(*destination); cpu->eax = cpu->ecx; };
    cpu->esp -= 0xCu;
    x87_v0 = (double)*(float*)(cpu->esp + 0x44u);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BF40u)); sfera_sub_0044B890(cpu, LIFT_CODE_TOKEN_VA(0x46BF40u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = (x87_v0) / (((double)*(float*)(cpu->esp + 0x14u)));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x148u);
    std::memmove((void*)(*(uint32_t*)(void*)&g_sfera_collision_scratch_runtime.view_transform[0]),(void*)(cpu->esp + 0x90u),64u); cpu->ecx = 0u;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x150u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    *(uint16_t*)((uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0x564]) = 0u;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BF94u)); sfera_sub_0044B7D0(cpu, LIFT_CODE_TOKEN_VA(0x46BF94u));
    *(float*)(cpu->esp + 0xECu) = (double)(0.0);
    cpu->ecx = cpu->esp + 0xDCu;
    x87_v0 = 1.0;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->esp + 0xF4u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xE4u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xE8u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xECu) = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetViewport(SferaAbi::pointer<const D3DVIEWPORT9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->esp += 4u;
    x87_v0 = 0.0;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    *(float*)(cpu->esp + 0x12Cu) = x87_v0;
    *(float*)(cpu->esp + 0x128u) = x87_v0;
    cpu->edx = cpu->esp + 0xF4u;
    *(float*)(cpu->esp + 0x124u) = x87_v0;
    lift_push32(cpu, cpu->edx);
    *(float*)(cpu->esp + 0x124u) = x87_v0;
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0x120u) = x87_v0;
    *(float*)(cpu->esp + 0x11Cu) = x87_v0;
    *(float*)(cpu->esp + 0x118u) = x87_v0;
    *(float*)(cpu->esp + 0x114u) = x87_v0;
    *(float*)(cpu->esp + 0x10Cu) = x87_v0;
    *(float*)(cpu->esp + 0x108u) = x87_v0;
    *(float*)(cpu->esp + 0x104u) = x87_v0;
    *(float*)(cpu->esp + 0x100u) = x87_v0; 
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x138u) = x87_v0;
    *(float*)(cpu->esp + 0x124u) = x87_v0;
    *(float*)(cpu->esp + 0x110u) = x87_v0;
    *(float*)(cpu->esp + 0xFCu) = x87_v0; 
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.view_matrix); lift_push32(cpu, 2u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.projection_matrix); lift_push32(cpu, 3u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setTransform(static_cast<D3DTRANSFORMSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const D3DMATRIX>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    --cpu->esi;
    lift_push32(cpu, cpu->esi);
    --cpu->edi;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C092u)); sfera_sub_0046B9E0(cpu, LIFT_CODE_TOKEN_VA(0x46C092u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x134u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}






} // namespace lifted
