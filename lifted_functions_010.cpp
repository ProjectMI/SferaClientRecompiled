#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static int32_t sfera_neighbor_dx(uint32_t index) { if (index < 4u) { return index == 0u || index == 3u ? -1 : 1; } if (index == 6u) { return -1; } return index == 7u ? 1 : 0; }
static int32_t sfera_neighbor_dy(uint32_t index) { if (index < 4u) { return index < 2u ? -1 : 1; } if (index == 4u) { return 1; } return index == 5u ? -1 : 0; }
__declspec(noinline) void sfera_sub_00462A90(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x58u;
    lift_push32(cpu, 0x1DCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462ACAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x462ACAu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = 0u;
    if (cpu->eax == 0u) goto label_00062AE6;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462AE4u)); sfera_sub_004DA590(cpu, LIFT_CODE_TOKEN_VA(0x462AE4u));
    goto label_00062AE8;
    label_00062AE6:
    cpu->eax = 0u;
    label_00062AE8:
    cpu->ecx = g_sfera_window_runtime.windowed;
    cpu->edx = g_sfera_graphics_display_depth_bits;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->edi;
    g_sfera_graphics_runtime.d3d9_device_runtime = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B1Eu)); sfera_sub_004D9FE0(cpu, LIFT_CODE_TOKEN_VA(0x462B1Eu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B29u)); sfera_sub_004D8360(cpu, LIFT_CODE_TOKEN_VA(0x462B29u));
    if ((cpu->eax & 0xFFu) != 1u) goto label_00062B76;
    cpu->edx = 0xA76u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B3Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x462B3Cu));
    lift_push32(cpu, 0x94u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B46u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x462B46u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = 1u;
    if (cpu->eax == 0u) goto label_00062B62;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B60u)); sfera_sub_004DA940(cpu, LIFT_CODE_TOKEN_VA(0x462B60u));
    goto label_00062B64;
    label_00062B62:
    cpu->eax = 0u;
    label_00062B64:
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62B76u)); sfera_sub_004DAF50(cpu, LIFT_CODE_TOKEN_RVA(0x62B76u));
    label_00062B76:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B7Bu)); sfera_sub_00499C90(cpu, LIFT_CODE_TOKEN_VA(0x462B7Bu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B80u)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x462B80u));
    cpu->ecx = (uintptr_t)"__debug.mbc";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B8Au)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x462B8Au));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462B91u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x462B91u));
    if (cpu->esi == cpu->edi) goto label_00062B9F;
    cpu->ecx = (uintptr_t)"debug\\pics\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62B9Fu)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_RVA(0x62B9Fu));
    label_00062B9F:
    cpu->ecx = (uintptr_t)"landscape\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462BA9u)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_VA(0x462BA9u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_00062BBC;
    cpu->ecx = (uintptr_t)"landscape_hr\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62BBCu)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_RVA(0x62BBCu));
    label_00062BBC:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == 0u) goto label_00062BCF;
    cpu->ecx = (uintptr_t)"landscape_ph\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62BCFu)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_RVA(0x62BCFu));
    label_00062BCF:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == 0u) goto label_00062BE2;
    cpu->ecx = (uintptr_t)"landscape_rd\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62BE2u)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_RVA(0x62BE2u));
    label_00062BE2:
    cpu->ecx = (uintptr_t)"models\\textures\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462BECu)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_VA(0x462BECu));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_00062BFF;
    cpu->ecx = (uintptr_t)"models_hr\\textures\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62BFFu)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_RVA(0x62BFFu));
    label_00062BFF:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == 0u) goto label_00062C12;
    cpu->ecx = (uintptr_t)"models_ph\\textures\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62C12u)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_RVA(0x62C12u));
    label_00062C12:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == 0u) goto label_00062C25;
    cpu->ecx = (uintptr_t)"models_rd\\textures\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62C25u)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_RVA(0x62C25u));
    label_00062C25:
    cpu->ecx = (uintptr_t)"textures\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C2Fu)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_VA(0x462C2Fu));
    cpu->ecx = (uintptr_t)"textures\\fx\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C39u)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_VA(0x462C39u));
    cpu->ecx = (uintptr_t)"textures\\emblems\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C43u)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_VA(0x462C43u));
    cpu->ecx = (uintptr_t)"xadd\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C4Du)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_VA(0x462C4Du));
    cpu->ecx = (uintptr_t)"players\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C57u)); sfera_sub_00499CD0(cpu, LIFT_CODE_TOKEN_VA(0x462C57u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C5Cu)); sfera_sub_0049A100(cpu, LIFT_CODE_TOKEN_VA(0x462C5Cu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x89u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C6Eu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x462C6Eu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462C7Du)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x462C7Du));
    lift_push32(cpu, 0x44u);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x462C86u));
    x87_v0 = 1.0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0x18u) = x87_v0;
    cpu->eax = cpu->esp + 0x10u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    lift_push32(cpu, cpu->eax);
    x87_v1 = 0.0;
    *(float*)(cpu->esp + 0x34u) = x87_v1;
    *(float*)(cpu->esp + 0x38u) = x87_v1;
    *(float*)(cpu->esp + 0x3Cu) = x87_v1;
    *(float*)(cpu->esp + 0x54u) = x87_v1; 
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462CCEu)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x462CCEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 3u); lift_push32(cpu, 0x8Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462CE0u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x462CE0u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462CEFu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x462CEFu));
    *(float*)(cpu->esp + 0xCu) = (double)50.0f;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462D0Bu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x462D0Bu));
    x87_v0 = (double)100.0f;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x25u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462D27u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x462D27u));
    cpu->ecx = g_sfera_render_buffer_capacities.vertex32;
    cpu->ecx <<= 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462D35u)); sfera_sub_00499EF0(cpu, LIFT_CODE_TOKEN_VA(0x462D35u));
    lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462D3Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x462D3Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = 2u;
    if (cpu->eax==0u) goto label_00062D6E;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex32;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x112u);
    cpu->ecx <<= 5u;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462D6Cu)); sfera_sub_004DA720(cpu, LIFT_CODE_TOKEN_VA(0x462D6Cu));
    goto label_00062D70;
    label_00062D6E:
    cpu->eax = 0u;
    label_00062D70:
    g_sfera_sky_runtime.draw_resource = cpu->eax;
    cpu->eax = g_sfera_render_buffer_capacities.vertex28;
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462D90u)); sfera_sub_00499EF0(cpu, LIFT_CODE_TOKEN_VA(0x462D90u));
    lift_push32(cpu, 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462D97u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x462D97u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = 3u;
    if (cpu->eax == 0u) goto label_00062DD3;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    cpu->edx = cpu->ecx * 8u;
    lift_push32(cpu, 0u);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, 0x1C2u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, 0x200u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462DD1u)); sfera_sub_004DA720(cpu, LIFT_CODE_TOKEN_VA(0x462DD1u));
    goto label_00062DD5;
    label_00062DD3:
    cpu->eax = 0u;
    label_00062DD5:
    lift_push32(cpu, 0x18u);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    g_sfera_window_runtime.render_vertex_buffer = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462DE5u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x462DE5u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = 4u;
    if (cpu->eax == 0u) goto label_00062E14;
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = cpu->ecx + cpu->ecx;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462E12u)); sfera_sub_004DA7D0(cpu, LIFT_CODE_TOKEN_VA(0x462E12u));
    goto label_00062E16;
    label_00062E14:
    cpu->eax = 0u;
    label_00062E16:
    lift_push32(cpu, 0x18u);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462E26u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x462E26u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = 5u;
    if (cpu->eax == 0u) goto label_00062E55;
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = cpu->ecx + cpu->ecx;
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462E53u)); sfera_sub_004DA7D0(cpu, LIFT_CODE_TOKEN_VA(0x462E53u));
    goto label_00062E57;
    label_00062E55:
    cpu->eax = 0u;
    label_00062E57:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.gpu_sync_query); lift_push32(cpu, 8u);
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edi;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462E72u)); sfera_sub_004D90B0(cpu, LIFT_CODE_TOKEN_VA(0x462E72u));
    x87_v0 = 1.0;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462E90u)); sfera_sub_004D87E0(cpu, LIFT_CODE_TOKEN_VA(0x462E90u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462E95u)); sfera_sub_004617A0(cpu, LIFT_CODE_TOKEN_VA(0x462E95u));
    cpu->edx = 0xABEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462EA4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x462EA4u));
    lift_push32(cpu, 0x9A0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462EAEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x462EAEu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x60u) = 6u;
    if (cpu->eax == 0u) goto label_00062ED4;
    lift_push32(cpu, (uintptr_t)"Shaders\\Pixel\\"); lift_push32(cpu, (uintptr_t)"Shaders\\Vertex\\");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462ED2u)); sfera_sub_004DD660(cpu, LIFT_CODE_TOKEN_VA(0x462ED2u));
    goto label_00062ED6;
    label_00062ED4:
    cpu->eax = 0u;
    label_00062ED6:
    g_sfera_d3d9_semantic_state.shader_manager = cpu->eax;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462F5Au)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x462F5Au));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->isInsideViewport(cpu);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4634A0u)); sfera_sub_00457370(cpu, LIFT_CODE_TOKEN_VA(0x4634A0u));
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
    lift_trap(cpu, 0x4634D7u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004634E0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26;
 double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5, x87_p6, x87_p7;
    cpu->esp -= 0x438u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00063AE1;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00063513;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63513u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x63513u));
label_00063513:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00063AE1;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00063536;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63536u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x63536u));
label_00063536:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_000639EC;
label_00063547:
    x87_p0 = (double)*(float*)(cpu->esp + 0x440u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x440u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 0x30u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x444u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x444u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x448u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x2Cu) = x87_p0; 
    *(float*)(cpu->esp + 0x2Cu) = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x448u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = (double)*(float*)(cpu->esp + 8u); x87_p1 = x87_p0;
    x87_p2 = 0.0;
    x87_p1 = (x87_p1) * (x87_p2);
    x87_p3 = (double)*(float*)(cpu->esp + 0x30u); x87_p4 = x87_p3;
    x87_p4 = (x87_p1) - (x87_p4);
    *(float*)(cpu->esp + 8u) = x87_p4; 
    x87_p3 = (x87_p3) * (x87_p2);
    x87_p0 = (x87_p0) + (x87_p3);
    std::swap(x87_p3, x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p3; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 8u);
    x87_p3 = (double)*(float*)(cpu->esp + 0xCu); x87_p4 = x87_p3;
    x87_p5 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p6 = x87_p5;
    x87_p4 = x87_p4 * x87_p6; 
    x87_p6 = (double)*(float*)(cpu->esp + 4u); x87_p7 = x87_p6;
    x87_p7 = (x87_p7) * (x87_p2);
    x87_p4 = x87_p4 - x87_p7; 
    std::swap(x87_p6, x87_p4);
    *(float*)(cpu->esp + 8u) = x87_p6; 
    x87_p5 = (x87_p5) * (x87_p4);
    x87_p6 = x87_p3;
    x87_p2 = x87_p2 * x87_p6; 
    x87_p2 = x87_p2 + x87_p5; 
    std::swap(x87_p4, x87_p2);
    *(float*)(cpu->esp + 0x18u) = x87_p4; 
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->esp + 8u);
    x87_p4 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p5 = x87_p4;
    x87_p5 = (x87_p5) * (((double)*(float*)(cpu->esp + 0x14u)));
    x87_p6 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p6 = (x87_p6) * (((double)*(float*)(cpu->esp + 0x18u)));
    x87_p5 = x87_p5 - x87_p6; 
    *(float*)(cpu->esp + 8u) = x87_p5; 
    x87_p5 = x87_p4;
    x87_p5 = (x87_p5) * (((double)*(float*)(cpu->esp + 0x18u)));
    x87_p6 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p6 = (x87_p6) * (((double)*(float*)(cpu->esp + 0x14u)));
    x87_p5 = x87_p5 + x87_p6; 
    *(float*)(cpu->esp + 0x18u) = x87_p5; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 8u);
    x87_p5 = x87_p1;
    x87_p5 = (x87_p5) - (x87_p0);
    *(float*)(cpu->esp + 8u) = x87_p5; 
    std::swap(x87_p4, x87_p0);
    x87_p1 = x87_p1 + x87_p4; 
    std::swap(x87_p3, x87_p1);
    *(float*)(cpu->esp + 0x28u) = x87_p3; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 8u);
    x87_p3 = x87_p1;
    x87_p4 = (double)*(float*)(cpu->esp + 0x28u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    x87_p5 = x87_p2;
    x87_p5 = (x87_p5) * (-1.0);
    x87_p3 = x87_p3 - x87_p5; 
    std::swap(x87_p4, x87_p3);
    *(float*)(cpu->esp + 8u) = x87_p4; 
    x87_p2 = x87_p2 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p2 = (x87_p2) * (1.0);
    x87_p1 = x87_p1 - x87_p2; 
    *(float*)(cpu->esp + 0x24u) = x87_p1; 
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 8u);
    x87_p1 = x87_p0;
    x87_p2 = (double)*(float*)(cpu->esp + 0x20u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x10u); x87_p4 = x87_p3;
    x87_p5 = (double)*(float*)(cpu->esp + 0x24u); x87_p6 = x87_p5;
    x87_p4 = x87_p4 * x87_p6; 
    std::swap(x87_p5, x87_p1);
    x87_p4 = x87_p5 - x87_p4; 
    *(float*)(cpu->esp + 8u) = x87_p4; 
    std::swap(x87_p3, x87_p0);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x14u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x14u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 0x30u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x18u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x18u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x2Cu) = x87_p0; 
    *(float*)(cpu->esp + 0x2Cu) = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p0 = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = (double)*(float*)(cpu->esp + 8u); x87_p1 = x87_p0;
    x87_p2 = (double)*(float*)(cpu->esp + 0x14u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x30u); x87_p4 = x87_p3;
    x87_p5 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p6 = x87_p5;
    x87_p4 = x87_p4 * x87_p6; 
    std::swap(x87_p5, x87_p1);
    x87_p4 = x87_p5 - x87_p4; 
    *(float*)(cpu->esp + 8u) = x87_p4; 
    x87_p4 = x87_p0;
    x87_p1 = x87_p1 * x87_p4; 
    x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    std::swap(x87_p3, x87_p1);
    x87_p2 = x87_p2 + x87_p3; 
    *(float*)(cpu->esp + 0x1Cu) = x87_p2; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 8u);
    x87_p2 = (double)*(float*)(cpu->esp + 0xCu); x87_p3 = x87_p2;
    x87_p4 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 4u); x87_p6 = x87_p5;
    x87_p6 = (x87_p6) * (((double)*(float*)(cpu->esp + 0x18u)));
    x87_p3 = x87_p3 - x87_p6; 
    std::swap(x87_p5, x87_p3);
    *(float*)(cpu->esp + 8u) = x87_p5; 
    x87_p4 = (x87_p4) * (x87_p3);
    x87_p5 = x87_p2;
    x87_p5 = (x87_p5) * (((double)*(float*)(cpu->esp + 0x18u)));
    x87_p4 = x87_p4 + x87_p5; 
    *(float*)(cpu->esp + 0x18u) = x87_p4; 
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->esp + 8u);
    x87_p4 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p5 = x87_p4;
    x87_p5 = (x87_p5) * (((double)*(float*)(cpu->esp + 0x14u)));
    x87_p6 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p6 = (x87_p6) * (((double)*(float*)(cpu->esp + 0x18u)));
    x87_p5 = x87_p5 - x87_p6; 
    *(float*)(cpu->esp + 8u) = x87_p5; 
    x87_p5 = x87_p4;
    x87_p5 = (x87_p5) * (((double)*(float*)(cpu->esp + 0x18u)));
    x87_p6 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p6 = (x87_p6) * (((double)*(float*)(cpu->esp + 0x14u)));
    x87_p5 = x87_p5 + x87_p6; 
    *(float*)(cpu->esp + 0x18u) = x87_p5; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 8u);
    x87_p5 = x87_p0;
    x87_p5 = (x87_p5) * (((double)*(float*)(cpu->esp + 0x20u)));
    x87_p6 = x87_p1;
    x87_p6 = (x87_p6) * (((double)*(float*)(cpu->esp + 0x28u)));
    x87_p5 = x87_p5 - x87_p6; 
    *(float*)(cpu->esp + 8u) = x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p0 = x87_p0 * x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 0x20u);
    x87_p1 = x87_p1 * x87_p5; 
    std::swap(x87_p4, x87_p0);
    x87_p1 = x87_p1 + x87_p4; 
    std::swap(x87_p3, x87_p1);
    *(float*)(cpu->esp + 0x28u) = x87_p3; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 8u);
    x87_p3 = x87_p2;
    x87_p4 = (double)*(float*)(cpu->esp + 0x28u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    x87_p5 = x87_p1;
    x87_p6 = (double)*(float*)(cpu->esp + 0x24u); x87_p7 = x87_p6;
    x87_p5 = x87_p5 * x87_p7; 
    std::swap(x87_p6, x87_p3);
    x87_p5 = x87_p6 - x87_p5; 
    *(float*)(cpu->esp + 8u) = x87_p5; 
    x87_p1 = x87_p1 * x87_p4; 
    x87_p2 = x87_p2 * x87_p3; 
    x87_p1 = x87_p1 + x87_p2; 
    *(float*)(cpu->esp + 0x24u) = x87_p1; 
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 8u);
    x87_p1 = x87_p0;
    x87_p2 = (double)*(float*)(cpu->esp + 0x20u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 * x87_p3; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_p3 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_p4 = x87_p3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p5 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x14Cu) = cpu->ecx;
    x87_p6 = x87_p5;
    *(uint32_t*)(cpu->esi + 0x150u) = cpu->edx;
    x87_p4 = x87_p4 * x87_p6; 
    *(uint32_t*)(cpu->esi + 0x154u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    std::swap(x87_p5, x87_p1);
    x87_p4 = x87_p5 - x87_p4; 
    *(float*)(cpu->esp + 8u) = x87_p4; 
    std::swap(x87_p3, x87_p0);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_p0 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0x20u) = x87_p0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi + 0x158u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x15Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x160u) = cpu->eax;
    x87_p1 = (double)*(float*)(cpu->esi + 0x160u);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi + 0x150u)));
    x87_p2 = (double)*(float*)(cpu->esi + 0x15Cu);
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->esi + 0x154u)));
    x87_p1 = x87_p1 - x87_p2; 
    *(float*)(cpu->esi + 0x164u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esi + 0x158u);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi + 0x154u)));
    x87_p2 = (double)*(float*)(cpu->esi + 0x160u);
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->esi + 0x14Cu)));
    x87_p1 = x87_p1 - x87_p2; 
    *(float*)(cpu->esi + 0x168u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esi + 0x15Cu);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi + 0x14Cu)));
    x87_p2 = (double)*(float*)(cpu->esi + 0x158u);
    x87_p2 = (x87_p2) * (((double)*(float*)(cpu->esi + 0x150u)));
    x87_p1 = x87_p1 - x87_p2; 
    *(float*)(cpu->esi + 0x16Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x24u); x87_p2 = x87_p1;
    x87_p3 = x87_p0;
    x87_p4 = x87_p2;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p3 = (x87_p3) * (x87_p3);
    x87_p2 = x87_p2 + x87_p3; 
     value_1 = x87_p2; value_2 = x87_p1; value_3 = x87_p0; if (!((value_1)>(1e-06))) goto label_00063A38;
    value_4 = std::atan2(value_2, value_3); 
    *(float*)(cpu->esp + 4u) = value_4; 
    *(float*)(cpu->esp + 4u) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 4u))));
    value_5 = (double)*(float*)(cpu->esp + 4u);
    *(float*)(cpu->esi + 0x1Cu) = value_5;
    value_6 = std::cos(value_5);
    *(float*)(cpu->esp + 0xCu) = value_6; 
    *(float*)(cpu->esp + 0x2Cu) = (double)*(float*)(cpu->esp + 0xCu);
    value_7 = (double)*(float*)(cpu->esp + 4u);
    value_8 = std::sin(value_7);
    *(float*)(cpu->esp + 4u) = value_8; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 4u);
    value_9 = (double)*(float*)(cpu->esp + 0x2Cu); 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u); x87_p1 = x87_p0;
    value_10 = value_9 * x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u); x87_p2 = x87_p1;
    x87_p3 = (double)*(float*)(cpu->esp + 0x18u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    value_25 = x87_p3; x87_p3 = value_10;
    x87_p2 = x87_p3 - x87_p2; 
    *(float*)(cpu->esp + 8u) = x87_p2; 
    x87_p2 = value_9;
    value_11 = value_25 * x87_p2; 
    x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    value_26 = x87_p1; x87_p1 = value_11;
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x24u);
    value_12 = value_9 * x87_p0; 
    value_13 = (value_26) * (((double)*(float*)(cpu->esp + 0x20u)));
    value_14 = value_12 + value_13; 
    *(float*)(cpu->esp + 0x24u) = value_14; 
    value_15 = (double)*(float*)(cpu->esp + 0x24u);
     value_0 = value_15; goto label_00063A3F;
label_000639EC:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00063547;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x463A08u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x463A08u));
    if (cpu->eax != 0u) goto label_00063A11;
    cpu->eax = (uintptr_t)"<none>";
label_00063A11:
    lift_push32(cpu, 0xC85u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x463A26u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63A38u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x63A38u));
label_00063A38:
    *(float*)(cpu->esi + 0x1Cu) = (double)(0.0);
      value_0 = value_2;
label_00063A3F:
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    value_16 = std::atan2(value_0, x87_p0); 
    *(float*)(cpu->esp + 4u) = value_16; 
    *(float*)(cpu->esp + 4u) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 4u))));
    value_17 = (double)*(float*)(cpu->esp + 4u);
    value_18 = std::cos(value_17);
    *(float*)(cpu->esp + 0xCu) = value_18; 
    value_19 = (double)*(float*)(cpu->esp + 0xCu);
    value_20 = (value_19) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(double*)(cpu->esp + 0x30u) = value_20;
     value_21 = (double)*(float*)(cpu->esp + 4u);
    value_22 = std::sin(value_21);
    *(float*)(cpu->esp + 0xCu) = value_22; 
    *(float*)(cpu->esp + 0xCu) = ((*(double*)(cpu->esp + 0x30u)) - ((((((double)*(float*)(cpu->esp + 0xCu))) * (((double)*(float*)(cpu->esp + 0x18u)))))));
    value_23 = (double)*(float*)(cpu->esp + 0xCu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    value_24 = std::atan2(value_23, x87_p0); 
    *(float*)(cpu->esp + 0xCu) = value_24; 
    *(float*)(cpu->esp + 0xCu) = ((1.5707964897155762) - (((double)*(float*)(cpu->esp + 0xCu))));
    *(float*)(cpu->esi + 0x14u) = (-((double)*(float*)(cpu->esp + 0xCu)));
    *(float*)(cpu->esi + 0x18u) = (-((double)*(float*)(cpu->esp + 4u)));
    *(float*)(cpu->esi + 0x1Cu) = (-((double)*(float*)(cpu->esi + 0x1Cu)));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x438u;
     cpu->esp += 0x10u; cpu->eip = stop_address; return;
label_00063AE1:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    (void)cpu;
label_00063AF0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00063AF0;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"rotate_object: wrong handle"),28u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x463B09u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x463B09u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x438u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00463B30(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    cpu->esp -= 0x434u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00063E72;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00063B63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63B63u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x63B63u));
    label_00063B63:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00063E72;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00063B86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63B86u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x63B86u));
    label_00063B86:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_00063E26;
    label_00063B97:
    { const double lift_right=(double)*(float*)(cpu->esi + 0x14u); const double lift_left=(double)*(float*)(cpu->esi + 0x2CCu); if (lift_left!=lift_right) goto label_00063BD1; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + 0x2D0u); if (lift_left!=lift_right) goto label_00063BD1; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x1Cu); const double lift_left=(double)*(float*)(cpu->esi + 0x2D4u); if (lift_left==lift_right) goto label_00063E9C; }
    label_00063BD1:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x2CCu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2D0u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x2D4u) = cpu->eax;
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x14u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 0x2Cu) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x18u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x18u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 0x24u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 0x30u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    x87_v1 = (x87_v1) * (x87_v2);
    x87_v3 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v4 = x87_v3;
    x87_v4 = (x87_v1) - (x87_v4);
    *(float*)(cpu->esp + 8u) = x87_v4; 
    x87_v3 = (x87_v3) * (x87_v2);
    x87_v0 = (x87_v0) + (x87_v3);
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 8u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x28u); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x14u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 0x24u); x87_v7 = x87_v6;
    x87_v7 = (x87_v7) * (x87_v2);
    x87_v4 = x87_v4 - x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 8u) = x87_v6; 
    x87_v5 = (x87_v5) * (x87_v4);
    x87_v6 = x87_v3;
    x87_v2 = x87_v2 * x87_v6; 
    x87_v2 = x87_v2 + x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v4; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x30u); x87_v5 = x87_v4;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esp + 0xCu)));
    x87_v6 = (double)*(float*)(cpu->esp + 4u);
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x10u)));
    x87_v5 = x87_v5 - x87_v6; 
    *(float*)(cpu->esp + 8u) = x87_v5; 
    x87_v5 = x87_v4;
    x87_v5 = (x87_v5) * (((double)*(float*)(cpu->esp + 0x10u)));
    x87_v6 = (double)*(float*)(cpu->esp + 4u);
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0xCu)));
    x87_v5 = x87_v5 + x87_v6; 
    *(float*)(cpu->esp + 0x10u) = x87_v5; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v5 = (double)*(float*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0xCu) = x87_v5; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v5 = x87_v1;
    *(uint32_t*)(cpu->esi + 0x14Cu) = cpu->ecx;
    x87_v5 = (x87_v5) - (x87_v0);
    *(uint32_t*)(cpu->esi + 0x150u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x154u) = cpu->eax;
    *(float*)(cpu->esp + 8u) = x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x20u) = x87_v3; 
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->esp + 8u);
    x87_v3 = x87_v1;
    x87_v4 = (double)*(float*)(cpu->esp + 0x20u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = x87_v2;
    x87_v5 = (x87_v5) * (-1.0);
    x87_v3 = x87_v3 - x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 8u) = x87_v4; 
    x87_v2 = x87_v2 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v2 = (x87_v2) * (1.0);
    x87_v1 = x87_v1 - x87_v2; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 4u); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 8u) = x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v1 = x87_v1 * x87_v3; 
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0x158u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x15Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x160u) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 0x160u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 0x150u)));
    x87_v1 = (double)*(float*)(cpu->esi + 0x15Cu);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x154u)));
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esi + 0x164u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi + 0x158u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 0x154u)));
    x87_v1 = (double)*(float*)(cpu->esi + 0x160u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x14Cu)));
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esi + 0x168u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi + 0x14Cu);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 0x15Cu)));
    x87_v1 = (double)*(float*)(cpu->esi + 0x150u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x158u)));
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esi + 0x16Cu) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x434u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00063E26:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00063B97;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x463E42u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x463E42u));
    if (cpu->eax != 0u) goto label_00063E4B;
    cpu->eax = (uintptr_t)"<none>";
    label_00063E4B:
    lift_push32(cpu, 0xCE6u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x463E60u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63E72u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x63E72u));
    label_00063E72:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00063E80:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00063E80;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"recalk_orts: wrong handle"),26u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x463E9Bu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x463E9Bu));
    cpu->edi = lift_pop32(cpu);
    label_00063E9C:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x434u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00463EC0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    cpu->esp -= 0x43Cu;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)0u) goto label_00063EE9;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63EE9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x63EE9u));
    label_00063EE9:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebp);
    if (cpu->eax != 0u) goto label_00063EFD;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    goto label_00063F4B;
    label_00063EFD:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00063F45;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x463F15u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x463F15u));
    if (cpu->eax != 0u) goto label_00063F1E;
    cpu->eax = (uintptr_t)"<none>";
    label_00063F1E:
    lift_push32(cpu, 0xFB9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x463F33u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x63F45u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x63F45u));
    label_00063F45:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->ebp = cpu->eax;
    label_00063F4B:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x463F52u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_VA(0x463F52u));
    x87_v0 = (double)*(float*)(cpu->ebp + 0x150u);
    x87_v0 = (x87_v0) * (((double)g_sfera_scene_vector_runtime.render_scale.y.f32));
    x87_v1 = (double)*(float*)(cpu->ebp + 0x14Cu);
    x87_v1 = (x87_v1) * (((double)g_sfera_scene_vector_runtime.render_scale.x.f32));
    x87_v0 = x87_v0 + x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ebp + 0x154u);
    x87_v1 = (x87_v1) * (((double)g_sfera_scene_vector_runtime.render_scale.z.f32));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (fabs(((double)*(float*)(cpu->esp + 4u))));
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v1 = (1.100000023841858) - (x87_v1);
    x87_v1 = (x87_v1) * (8.000000093488779e-07);
    *(float*)(cpu->esp + 0x38u) = x87_v1; 
    { const double lift_left=x87_v0; const double lift_right=0.985;  if (lift_left>lift_right) goto label_00064327; }
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x154u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x150u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = g_sfera_scene_vector_runtime.render_scale.z.u32;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u); x87_v1 = x87_v0;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    x87_v2 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->ecx = g_sfera_scene_vector_runtime.render_scale.y.u32;
    x87_v3 = x87_v2;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    x87_v1 = x87_v1 * x87_v3; 
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    x87_v3 = (double)*(float*)(cpu->esp + 0x28u);
    cpu->eax = g_sfera_scene_vector_runtime.render_scale.x.u32;
    x87_v4 = x87_v3;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v5 = (double)*(float*)(cpu->esp + 0x14u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 0x2Cu) = x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u); x87_v5 = x87_v4;
    x87_v5 = (x87_v5) * (x87_v3);
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u); x87_v7 = x87_v6;
    x87_v0 = x87_v0 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v5; x87_v5 = temporary; }
    x87_v0 = x87_v6 - x87_v0; 
    { double temporary = x87_v5; x87_v5 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x30u) = x87_v5; 
    x87_v5 = x87_v0;
    x87_v1 = x87_v1 * x87_v5; 
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v1 = x87_v1 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x34u); x87_v4 = x87_v3;
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v5 = (double)*(float*)(cpu->esp + 0x30u); x87_v6 = x87_v5;
    x87_v6 = (x87_v6) * (x87_v1);
    x87_v4 = x87_v4 - x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v6 = x87_v5;
    x87_v1 = x87_v1 * x87_v6; 
    x87_v6 = x87_v0;
    x87_v3 = x87_v3 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v3 = x87_v5 - x87_v3; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v4; 
    x87_v0 = x87_v0 * x87_v3; 
    x87_v1 = x87_v1 * x87_v2; 
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u); x87_v3 = x87_v2;
    x87_v4 = x87_v1;
    x87_v1 = x87_v1 * x87_v4; 
    x87_v3 = (x87_v3) * (x87_v3);
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v2; const double lift_right=1e-06;  if (!(lift_left>lift_right)) goto label_00064134; }
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v0 = std::atan2(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 4u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 8u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 4u); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x24u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 8u) = x87_v4; 
    x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    x87_v4 = x87_v0;
    x87_v1 = x87_v1 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x24u) = x87_v2; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 8u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x10u)));
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    goto label_0006413C;
    label_00064134:
    x87_v0 = x87_v1; 
    *(float*)(cpu->esp + 0xCu) = (double)(0.0);
    label_0006413C:
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    x87_v0 = std::atan2(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x14u) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x34u)));
    *(double*)(cpu->esp + 0x1Cu) = x87_v0;
     x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((*(double*)(cpu->esp + 0x1Cu)) - ((((((double)*(float*)(cpu->esp + 0x10u))) * (((double)*(float*)(cpu->esp + 0x30u)))))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = std::atan2(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((1.5707964897155762) - (((double)*(float*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = -x87_v0;
    x87_v1 = 10430.37835;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = -x87_v1;
    cpu->esi = cpu->eax;
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->esi &= 0xFFFFu;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v1 = -x87_v1;
    cpu->ebx = cpu->eax;
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->ebx &= 0xFFFFu;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    x87_v1 = (double)*(float*)(cpu->ebp + 0x14u);
    cpu->eax &= 0xFFFFu;
    x87_v1 = (x87_v1) * (x87_v0);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    x87_v1 = (double)*(float*)(cpu->ebp + 0x18u);
    cpu->edi = cpu->eax;
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->edi &= 0xFFFFu;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->eax + 0x1Cu)));
    cpu->ebp &= 0xFFFFu;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->eax &= 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->edi;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0x8000u) goto label_0006425C;
    cpu->edi += 0xFFFF8000u;
    cpu->ecx = cpu->esi + 0xFFFF8000u;
    cpu->edi &= 0xFFFFu;
    cpu->ecx &= 0xFFFFu;
    cpu->ecx -= cpu->edi;
    label_0006425C:
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ebp;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)0x8000u) goto label_0006427A;
    cpu->ebx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    goto label_00064298;
    label_0006427A:
    cpu->ebp += 0xFFFF8000u;
    cpu->ebx += 0xFFFF8000u;
    cpu->ebp &= 0xFFFFu;
    cpu->ebx &= 0xFFFFu;
    cpu->ebx -= cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    label_00064298:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = cpu->esi;
    cpu->edi -= cpu->ebp;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0x8000u) goto label_000642CC;
    cpu->ebp += 0xFFFF8000u;
    cpu->edi = cpu->esi + 0xFFFF8000u;
    cpu->ebp &= 0xFFFFu;
    cpu->edi &= 0xFFFFu;
    cpu->edi -= cpu->ebp;
    label_000642CC:
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->eax > (int32_t)0x64u) goto label_000642F4;
    cpu->eax = cpu->ebx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax > (int32_t)0x64u) goto label_000642F4;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)0x64u) goto label_00064324;
    label_000642F4:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x44u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax + 0x14u);
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + 0x14u) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x18u)));
    *(float*)(cpu->eax + 0x18u) = x87_v1; 
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 0x1Cu)));
    *(float*)(cpu->eax + 0x1Cu) = x87_v0; 
    label_00064324:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00064327:
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x43Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00464340(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16;
 double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4;
    cpu->esp -= 0x438u;
    cpu->edx = 1u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0006436B;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6436Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6436Bu));
label_0006436B:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->esi != 0u) goto label_000644E7;
label_0006437C:
    x87_p0 = (double)*(float*)(cpu->esi + 0x150u);
    lift_push32(cpu, cpu->edi);
    x87_p0 = -x87_p0;
    *(float*)(cpu->esi + 0x150u) = x87_p0; 
    cpu->edi = *(uint32_t*)(cpu->esi + 0x14Cu);
    x87_p0 = (double)*(float*)(cpu->esi + 0x168u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x154u)));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x150u);
    x87_p1 = (double)*(float*)(cpu->esi + 0x16Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi + 0x150u)));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x154u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x14Cu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x16Cu)));
    x87_p1 = (double)*(float*)(cpu->esi + 0x164u);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi + 0x154u)));
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_p0 = (double)*(float*)(cpu->esi + 0x164u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x150u)));
    x87_p1 = (double)*(float*)(cpu->esi + 0x168u);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi + 0x14Cu)));
    *(uint32_t*)(cpu->esi + 0x158u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x15Cu) = cpu->ecx;
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x160u) = cpu->edx;
    x87_p1 = x87_p0;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    x87_p2 = (double)*(float*)(cpu->esp + 0x18u); x87_p3 = x87_p2;
    x87_p3 = (x87_p3) * (x87_p3);
    x87_p4 = x87_p1;
    x87_p1 = x87_p1 * x87_p4; 
    x87_p1 = x87_p1 + x87_p3; 
    std::swap(x87_p2, x87_p1);
     value_0 = x87_p2; value_1 = x87_p1; value_2 = x87_p0; if (!((value_0)>(1e-06))) goto label_00064533;
    value_3 = std::atan2(value_1, value_2); 
    *(float*)(cpu->esp + 8u) = value_3; 
    *(float*)(cpu->esp + 8u) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 8u))));
    value_4 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esi + 0x1Cu) = value_4;
    value_5 = std::cos(value_4);
    *(float*)(cpu->esp + 0xCu) = value_5; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0xCu);
    value_6 = (double)*(float*)(cpu->esp + 8u);
    value_7 = std::sin(value_6);
    *(float*)(cpu->esp + 0xCu) = value_7; 
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->esp + 0xCu);
    value_8 = (double)*(float*)(cpu->esp + 0x20u); 
    x87_p0 = (double)*(float*)(cpu->esp + 4u); x87_p1 = x87_p0;
    value_9 = value_8 * x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x24u); x87_p2 = x87_p1;
    x87_p3 = (double)*(float*)(cpu->esp + 0xCu); x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    value_15 = x87_p3; x87_p3 = value_9;
    x87_p2 = x87_p3 - x87_p2; 
    *(float*)(cpu->esp + 4u) = x87_p2; 
    x87_p2 = value_15;
    value_10 = value_8 * x87_p2; 
    x87_p1 = (x87_p1) * (x87_p0);
    value_11 = value_10 + x87_p1; 
    value_16 = x87_p0; x87_p0 = value_11;
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    value_12 = value_16 * x87_p0; 
    value_13 = (value_15) * (((double)*(float*)(cpu->esp + 0x14u)));
    value_14 = value_12 + value_13; 
    *(float*)(cpu->esp + 0x30u) = value_14; 
     goto label_0006453C;
label_000644E7:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0006437C;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464503u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x464503u));
    if (cpu->eax != 0u) goto label_0006450C;
    cpu->eax = (uintptr_t)"<none>";
label_0006450C:
    lift_push32(cpu, 0x185Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x464521u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64533u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x64533u));
label_00064533:
    *(float*)(cpu->esi + 0x1Cu) = (double)(0.0);
label_0006453C:
    x87_p0 = (double)*(float*)(cpu->esp + 0x30u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x34u);
    x87_p0 = std::atan2(x87_p0, x87_p1); 
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 8u) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 4u))));
    x87_p0 = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x28u)));
    *(double*)(cpu->esp + 0xCu) = x87_p0;
     x87_p0 = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = ((*(double*)(cpu->esp + 0xCu)) - ((((((double)*(float*)(cpu->esp + 4u))) * (((double)*(float*)(cpu->esp + 0x24u)))))));
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x20u);
    x87_p0 = std::atan2(x87_p0, x87_p1); 
    *(float*)(cpu->esp + 4u) = x87_p0; 
    *(float*)(cpu->esp + 4u) = ((1.5707964897155762) - (((double)*(float*)(cpu->esp + 4u))));
    *(float*)(cpu->esi + 0x14u) = (-((double)*(float*)(cpu->esp + 4u)));
    *(float*)(cpu->esi + 0x18u) = (-((double)*(float*)(cpu->esp + 8u)));
    *(float*)(cpu->esi + 0x1Cu) = (-((double)*(float*)(cpu->esi + 0x1Cu)));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x2CCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2D0u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2D4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x438u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4646F5u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_VA(0x4646F5u));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4647DBu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x4647DBu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x648EEu)); sfera_sub_00464340(cpu, LIFT_CODE_TOKEN_RVA(0x648EEu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x64A78u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_RVA(0x64A78u));
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
    sfera_sub_00463B30(cpu, stop_address); return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464BE4u)); sfera_sub_00480380(cpu, LIFT_CODE_TOKEN_VA(0x464BE4u));
    cpu->esi = 0u;
    g_sfera_file_runtime.error_reporting_enabled = 1u;
    *(uint32_t*)(cpu->esp + 0x210u) = cpu->esi;
    cpu->ecx = (uintptr_t)"params";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464C01u)); sfera_sub_0042F2D0(cpu, LIFT_CODE_TOKEN_VA(0x464C01u));
    cpu->ecx = (uintptr_t)"mbc";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464C0Bu)); sfera_sub_0042F2D0(cpu, LIFT_CODE_TOKEN_VA(0x464C0Bu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464CE4u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464CE4u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464D3Du)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464D3Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464D6Au)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464D6Au));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464DA5u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464DA5u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464DD2u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464DD2u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464E2Du)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464E2Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464E59u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464E59u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464E86u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x464E86u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464F98u)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x464F98u));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"loadcount.bin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464FA4u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x464FA4u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464FABu)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x464FABu));
    if (cpu->edi == 0xFFFFFFFFu) goto label_0006517E;
    lift_push32(cpu, 4u);
    cpu->edx = (uintptr_t)&g_sfera_world_load_runtime.loading_work_total;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464FC2u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x464FC2u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x464FC9u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x464FC9u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465448u)); sfera_sub_0042F2D0(cpu, LIFT_CODE_TOKEN_VA(0x465448u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == cpu->ebx) goto label_0006545A;
    cpu->ecx = (uintptr_t)"landscape_hr";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6545Au)); sfera_sub_0042F2D0(cpu, LIFT_CODE_TOKEN_RVA(0x6545Au));
label_0006545A:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == cpu->ebx) goto label_0006546C;
    cpu->ecx = (uintptr_t)"landscape_ph";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6546Cu)); sfera_sub_0042F2D0(cpu, LIFT_CODE_TOKEN_RVA(0x6546Cu));
label_0006546C:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == cpu->ebx) goto label_0006547E;
    cpu->ecx = (uintptr_t)"landscape_rd";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6547Eu)); sfera_sub_0042F2D0(cpu, LIFT_CODE_TOKEN_RVA(0x6547Eu));
label_0006547E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465483u)); sfera_sub_0045AA50(cpu, LIFT_CODE_TOKEN_VA(0x465483u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465488u)); sfera_sub_00462A90(cpu, LIFT_CODE_TOKEN_VA(0x465488u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465493u)); sfera_sub_004D8360(cpu, LIFT_CODE_TOKEN_VA(0x465493u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0006549D;
    g_sfera_graphics_runtime.post_effects_enabled = cpu->ebx;
label_0006549D:
    if ((((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_000654D3;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->ebp);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint8_t*)(cpu->esp + 0x210u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4654BEu)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x4654BEu));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA360) ? 0u : 0xFFFFFFFFu;
    *(uint8_t*)(cpu->esp + 0x210u) = 0u;
label_000654D3:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_graphics_runtime.hardware_cursor_enabled) != cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4654E9u)); sfera_sub_004D7AF0(cpu, LIFT_CODE_TOKEN_VA(0x4654E9u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4655D1u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4655D1u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46585Au)); sfera_sub_00499EF0(cpu, LIFT_CODE_TOKEN_VA(0x46585Au));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46587Bu)); sfera_sub_004D8E70(cpu, LIFT_CODE_TOKEN_VA(0x46587Bu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465B43u)); sfera_sub_004518E0(cpu, LIFT_CODE_TOKEN_VA(0x465B43u));
    cpu->ecx = cpu->esp + 0x30u;
    *(uint32_t*)(cpu->esp + 0x210u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465B57u)); sfera_sub_00480390(cpu, LIFT_CODE_TOKEN_VA(0x465B57u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x200u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00465B80(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6; double x87_p0;
    bool lift_cmp[1];
    cpu->esp -= 0xE0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xE8u);
    cpu->eax = cpu->edx;
    cpu->esi = (uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    cpu->esi -= cpu->ecx;
    label_00065BC0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00065BC0;
    cpu->ecx = cpu->eax;
    label_00065BD0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00065BD0;
    cpu->edi = (uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00065BE1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00065BE1;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    --cpu->eax;
    label_00065C00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00065C00;
    cpu->edx = *(uint32_t*)((uintptr_t)".mdl");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".mdl") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465C1Eu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x465C1Eu));
    cpu->ecx = (uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465C28u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x465C28u));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465C33u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x465C33u));
    if (cpu->esi != 0xFFFFFFFFu) goto label_00065C47;
    lift_push32(cpu, (uintptr_t)g_sfera_model_load_scratch_runtime.filename); lift_push32(cpu, (uintptr_t)"File not found: %s");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x65C47u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_RVA(0x65C47u));
    label_00065C47:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->edi = cpu->esi;
    lift_push32(cpu, 0x21C1u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465C5Cu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x465C5Cu));
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465C6Au)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x465C6Au));
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465C76u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x465C76u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465C7Du)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x465C7Du));
    cpu->edx = *(uint16_t*)(cpu->ebx + 4u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09) = cpu->edx;
    cpu->eax = *(uint16_t*)(cpu->ebx + 6u);
    g_sfera_recovered_static_runtime.render_state_07 = cpu->eax;
    cpu->ecx = *(uint16_t*)(cpu->ebx + 8u);
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state) = cpu->ecx;
    cpu->edx = *(uint8_t*)(cpu->ebx + 0xDu);
    g_sfera_recovered_static_runtime.input_state_a = cpu->edx;
    cpu->eax = *(uint8_t*)(cpu->ebx + 0xFu);
    g_sfera_input_device_runtime.keyboard_state_code = cpu->eax;
    cpu->edx = *(uint8_t*)(cpu->ebx + 0xEu);
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.viewport_state) = cpu->edx;
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0xAu);
    g_sfera_static_render_lookup_runtime.sample_state = cpu->ecx;
    cpu->ebp = *(uint8_t*)(cpu->ebx + 0x14u);
    g_sfera_world_load_runtime.packed_variant = cpu->ebp;
    cpu->eax = *(uint16_t*)(cpu->ebx + 0x15u);
    g_sfera_render_sample_runtime.material_code.u32 = cpu->eax;
    cpu->ecx = *(uint16_t*)(cpu->ebx + 0x10u);
    g_sfera_window_runtime.scene_record_count = cpu->ecx;
    cpu->eax = *(uint16_t*)(cpu->ebx + 0x12u);
    g_sfera_process_runtime.packed_record_count = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0x17u));
    (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled) = cpu->ecx & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->ebx + 0x18u));
    g_sfera_static_render_lookup_runtime.packed_format_code = cpu->eax & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1Eu);
    g_sfera_client_main_scalar_runtime.state_23 = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x22u);
    g_sfera_client_main_scalar_runtime.state_24 = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x26u);
    g_sfera_client_main_scalar_runtime.state_25 = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Au);
    g_sfera_client_main_scalar_runtime.state_26 = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x2Eu);
    g_sfera_client_main_scalar_runtime.state_27 = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x32u);
    g_sfera_client_main_scalar_runtime.state_28 = cpu->eax;
    std::memmove((void*)((uintptr_t)&g_sfera_client_bounds_corners),(void*)(cpu->ebx + 0x36u),96u);
    std::memmove((void*)((uintptr_t)&g_sfera_model_bounds_corners),(void*)(cpu->ebx + 0x96u),96u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1Au);
    g_sfera_recovered_static_runtime.client_state_06 = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.parameter.f32) = (double)*(float*)(cpu->ebx + 0xF6u);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xFAu);
    g_sfera_main_aux_runtime.resource_word = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xFEu);
    g_sfera_landscape_render_runtime.source_record_count = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebx + 0xBu);
    cpu->eax += 0x102u;
    cpu->ecx = cpu->eax + cpu->ebx;
    g_sfera_recovered_static_runtime.animation_state = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->ebx + 4u);
    cpu->ecx <<= 5u;
    cpu->eax += cpu->ecx;
    cpu->ecx = cpu->eax + cpu->ebx;
    g_sfera_client_main_scalar_runtime.state_04 = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->ebx + 6u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->eax = cpu->eax + (cpu->ecx * 2u);
    cpu->ecx = cpu->eax + cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06) = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->ebx + 8u);
    cpu->edi = cpu->ecx;
    cpu->edi <<= 4u;
    cpu->edi -= cpu->ecx;
    cpu->eax += cpu->edi;
    cpu->ecx = cpu->eax + cpu->ebx;
    g_sfera_recovered_static_runtime.client_state_04 = cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0xDu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x27u);
    cpu->eax += cpu->ecx;
    cpu->ecx = cpu->eax + cpu->ebx;
    cpu->eax += cpu->edx;
    g_sfera_render_sample_runtime.record_base = cpu->ecx;
    if (cpu->ebp == 0u) goto label_00065E1B;
    cpu->ecx = g_sfera_window_runtime.scene_record_count;
    cpu->edx = cpu->eax + cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_05) = cpu->edx;
    cpu->edx = cpu->ecx * 8u;
    cpu->edx -= cpu->ecx;
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->ecx = cpu->eax + cpu->ebx;
    g_sfera_spatial_index_runtime.quadtree_state = cpu->ecx;
    cpu->ecx = g_sfera_process_runtime.packed_record_count;
    cpu->edx = cpu->ecx + cpu->eax;
    cpu->eax = cpu->edx + (cpu->ecx * 2u);
    cpu->ecx = cpu->eax + cpu->ebx;
    g_sfera_scene_control_runtime.packed_section_base = cpu->ecx;
    cpu->eax = cpu->eax + (cpu->ebp * 2u);
    label_00065E1B:
    if (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled != 1u) goto label_00065E4C;
    cpu->ecx = g_sfera_static_render_lookup_runtime.packed_format_code;
    cpu->edx = cpu->eax + cpu->ebx;
    cpu->eax = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_07;
    g_sfera_recovered_static_runtime.render_state_10 = cpu->edx;
    cpu->edx = cpu->eax + cpu->ebx;
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags) = cpu->edx;
    cpu->eax = cpu->eax + (cpu->ecx * 2u);
    label_00065E4C:
    cpu->edi = 0u;
    if (cpu->ebp != cpu->edi) goto label_00065E67;
    cpu->ecx = g_sfera_recovered_static_runtime.input_state_a;
    cpu->edx = cpu->eax + cpu->ebx;
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    g_sfera_client_main_scalar_runtime.state_05 = cpu->edx;
    cpu->eax = cpu->eax + (cpu->ecx * 8u);
    label_00065E67:
    if ((uint32_t)(g_sfera_recovered_static_runtime.client_state_06) != 2u) goto label_00065E96;
    cpu->edx = cpu->eax + cpu->ebx;
    cpu->ecx = cpu->esi + (cpu->esi * 2u);
    cpu->eax = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = g_sfera_landscape_render_runtime.source_record_count;
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    g_sfera_landscape_render_runtime.source_section_base = cpu->edx;
    cpu->edx = cpu->eax + cpu->ebx;
    cpu->ecx <<= 4u;
    g_sfera_client_main_scalar_runtime.state_03 = cpu->edx;
    cpu->eax += cpu->ecx;
    label_00065E96:
    if (*(uint32_t*)(cpu->esp + 0x10u) == cpu->eax) goto label_00065EAB;
    cpu->edx = (uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->ecx = (uintptr_t)"load_model: wrong format. File: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x65EABu)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x65EABu));
    label_00065EAB:
    cpu->ecx = g_sfera_static_render_lookup_runtime.sample_state;
    lift_push32(cpu, 0x220Bu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465EC2u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x465EC2u));
    g_sfera_landscape_map_runtime.material_remap = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if ((int32_t)g_sfera_static_render_lookup_runtime.sample_state <= (int32_t)cpu->edi) goto label_00065F5B;
    label_00065EE0:
    cpu->esi = *(uint8_t*)(cpu->ebx + cpu->edi + 0x102u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx + cpu->edi + 0x103u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x465EF6u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + ((uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0])) = 0u;
    cpu->edi = cpu->edi + cpu->esi + 1u;
    cpu->ebp = 0u;
    cpu->esi = 0u;
    label_00065F10:
    if ((int32_t)cpu->ebp >= (int32_t)g_sfera_main_render_runtime.material_count) goto label_0006608D;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = cpu->esi + cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0]);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x465F2Au));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00065F40;
    ++cpu->ebp;
    cpu->esi += 0x88u;
    goto label_00065F10;
    label_00065F40:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = g_sfera_landscape_map_runtime.material_remap;
    *(uint16_t*)(cpu->edx + (cpu->eax * 2u)) = cpu->ebp & 0xFFFFu;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_static_render_lookup_runtime.sample_state) goto label_00065EE0;
    label_00065F5B:
    lift_push32(cpu, 0x2220u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x1E4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x465F6Fu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x465F6Fu));
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0x1E4u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x465F7Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->edx = cpu->ebp;
    cpu->esp += 0xCu;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_00065F90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00065F90;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09;
    *(uint32_t*)(cpu->ebp + 0x20u) = cpu->ecx;
    cpu->edx = g_sfera_recovered_static_runtime.render_state_07;
    *(uint32_t*)(cpu->ebp + 0x28u) = cpu->edx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state;
    *(uint32_t*)(cpu->ebp + 0x30u) = cpu->eax;
    cpu->ecx = g_sfera_recovered_static_runtime.input_state_a;
    *(uint32_t*)(cpu->ebp + 0x38u) = cpu->ecx;
    cpu->edx = g_sfera_static_render_lookup_runtime.sample_state;
    *(uint32_t*)(cpu->ebp + 0x44u) = cpu->edx;
    cpu->eax = *(uint8_t*)(void*)&g_sfera_input_device_runtime.keyboard_state_code;
    *(uint8_t*)(cpu->ebp + 0x40u) = cpu->eax & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(void*)&g_sfera_world_load_runtime.packed_variant);
    *(uint8_t*)(cpu->ebp + 0x50u) = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(void*)&g_sfera_render_sample_runtime.material_code.u32);
    *(uint16_t*)(cpu->ebp + 0x52u) = cpu->edx & 0xFFFFu;
    cpu->eax = *(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled;
    *(uint8_t*)(cpu->ebp + 0x60u) = cpu->eax & 0xFFu;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_23;
    *(uint32_t*)(cpu->ebp + 0x70u) = cpu->ecx;
    cpu->edx = g_sfera_client_main_scalar_runtime.state_24;
    *(uint32_t*)(cpu->ebp + 0x74u) = cpu->edx;
    cpu->eax = g_sfera_client_main_scalar_runtime.state_25;
    *(uint32_t*)(cpu->ebp + 0x78u) = cpu->eax;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_26;
    *(uint32_t*)(cpu->ebp + 0x7Cu) = cpu->ecx;
    cpu->edx = g_sfera_client_main_scalar_runtime.state_27;
    *(uint32_t*)(cpu->ebp + 0x80u) = cpu->edx;
    cpu->eax = g_sfera_client_main_scalar_runtime.state_28;
    *(uint32_t*)(cpu->ebp + 0x84u) = cpu->eax;
    std::memmove((void*)(cpu->ebp + 0x88u),(void*)((uintptr_t)&g_sfera_client_bounds_corners),96u);
    cpu->edi = cpu->ebp + 0xE8u;
    cpu->esi = (uintptr_t)&g_sfera_model_bounds_corners;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),96u); cpu->esi += 96u; cpu->edi += 96u;
    *(float*)(cpu->ebp + 0x194u) = (double)*(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.parameter.f32);
    x87_v0 = (double)2.0f;
    lift_cmp[0]=x87_v0<(((double)*(float*)(cpu->ebp + 0x194u)));
    cpu->ecx = g_sfera_recovered_static_runtime.client_state_06;
    *(uint32_t*)(cpu->ebp + 0x6Cu) = cpu->ecx;
    cpu->edx = g_sfera_main_aux_runtime.resource_word;
    *(uint32_t*)(cpu->ebp + 0x19Cu) = cpu->edx;
    if (!lift_cmp[0]) goto label_000660A1;
    if (*(uint8_t*)(cpu->ebp + 0x50u) != 0u) goto label_000660A1;
    cpu->eax = 1u;
    goto label_000660A3;
    label_0006608D:
    lift_push32(cpu, (uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0]);
    cpu->edx = (uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->ecx = (uintptr_t)"Model has material which not exist in library: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x660A1u)); sfera_sub_00459D10(cpu, LIFT_CODE_TOKEN_RVA(0x660A1u));
    label_000660A1:
    cpu->eax = 0u;
    label_000660A3:
    x87_v0 = 0.0;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->ebp + 0x1D4u) = x87_v0;
    lift_push32(cpu, 0u);
    *(float*)(cpu->ebp + 0x1D8u) = x87_v0;
    *(uint32_t*)(cpu->ebp + 0x1BCu) = cpu->eax;
    *(float*)(cpu->ebp + 0x1DCu) = x87_v0; 
    cpu->eax = cpu->ebp + 0x1A8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lod_f"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x1E0u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4660E5u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x4660E5u));
    if (cpu->eax == 1u) goto label_000660F6;
    *(float*)(cpu->ebp + 0x1A8u) = (double)1000.0f;
    label_000660F6:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x1ACu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lod_pow"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46610Cu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x46610Cu));
    if (cpu->eax == 1u) goto label_0006611D;
    *(float*)(cpu->ebp + 0x1ACu) = (double)-1.0f;
    label_0006611D:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x1B0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shad_f"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x466133u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x466133u));
    if (cpu->eax == 1u) goto label_00066144;
    *(float*)(cpu->ebp + 0x1B0u) = (double)0.5f;
    label_00066144:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x1B8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shad_sp"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46615Au)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x46615Au));
    if (cpu->eax == 1u) goto label_0006616B;
    *(float*)(cpu->ebp + 0x1B8u) = (double)0.8500000238418579f;
    label_0006616B:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x1B4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shad_s"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x466181u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x466181u));
    if (cpu->eax == 1u) goto label_00066192;
    *(float*)(cpu->ebp + 0x1B4u) = (double)2.0f;
    label_00066192:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0x1C0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"trace"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4661A8u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x4661A8u));
    if (cpu->eax == 1u) goto label_000661B9;
    *(float*)(cpu->ebp + 0x1C0u) = (double)-1.0f;
    label_000661B9:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"land_shade_affect_K"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4661CDu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x4661CDu));
    if (cpu->eax != 1u) goto label_0006621C;
    x87_v0 = (double)*(float*)(cpu->esp + 0x68u);
    cpu->esp -= 8u;
    x87_v0 = (x87_v0) * (255.0);
    x87_v0 = (x87_v0) + (0.5);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(double*)(cpu->esp) = x87_v0;
    x87_v0 = std::floor(*(double*)(cpu->esp));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->esp += 8u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->ebp + 0x1E0u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_0006621C;
    *(uint32_t*)(cpu->ebp + 0x1E0u) = 0xFFu;
    label_0006621C:
    cpu->esi = 0u;
    label_00066220:
    cpu->edi = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09;
    cpu->edi = cpu->edi + (cpu->edi * 8u);
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->eax = 0u;
    if (cpu->esi != 1u) goto label_0006624E;
    cpu->ecx = g_sfera_process_runtime.packed_layout_bytes;
    lift_push32(cpu, 0x21A7u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x466249u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x466249u));
    g_sfera_recovered_static_runtime.scene_counter = cpu->eax;
    label_0006624E:
    g_sfera_process_runtime.packed_layout_bytes = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->eax;
    cpu->eax = g_sfera_recovered_static_runtime.render_state_07;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_00066278;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066278:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x2Cu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state;
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_0006629E;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_0006629E:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x34u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.input_state_a;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xACu);
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_000662C5;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_000662C5:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x3Cu) = cpu->ecx;
    cpu->ecx = g_sfera_static_render_lookup_runtime.sample_state;
    cpu->ecx += cpu->ecx;
    cpu->eax = 0u;
    if (cpu->esi != 1u) goto label_000662E8;
    cpu->eax = g_sfera_recovered_static_runtime.scene_counter;
    cpu->eax += g_sfera_process_runtime.packed_layout_bytes;
    label_000662E8:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x48u) = cpu->eax;
    cpu->ecx = g_sfera_process_runtime.packed_layout_bytes;
    cpu->eax = 0u;
    if (cpu->esi != 1u) goto label_00066305;
    cpu->eax = g_sfera_recovered_static_runtime.scene_counter;
    cpu->eax += cpu->ecx;
    label_00066305:
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.viewport_state);
    g_sfera_process_runtime.packed_layout_bytes = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x4Cu) = cpu->eax;
    if (g_sfera_world_load_runtime.packed_variant == cpu->edx) goto label_00066392;
    cpu->ecx = g_sfera_window_runtime.scene_record_count;
    cpu->eax = cpu->ecx * 8u;
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_00066342;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066342:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x54u) = cpu->ecx;
    cpu->eax = g_sfera_process_runtime.packed_record_count;
    cpu->ecx = 0u;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    if (cpu->esi != 1u) goto label_00066366;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066366:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x58u) = cpu->ecx;
    cpu->ecx = g_sfera_world_load_runtime.packed_variant;
    cpu->ecx += cpu->ecx;
    cpu->eax = 0u;
    if (cpu->esi != 1u) goto label_00066389;
    cpu->eax = g_sfera_recovered_static_runtime.scene_counter;
    cpu->eax += g_sfera_process_runtime.packed_layout_bytes;
    label_00066389:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x5Cu) = cpu->eax;
    label_00066392:
    *(uint32_t*)(cpu->ebp + 0x68u) = cpu->edx;
    if (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled != 1u) goto label_000663EB;
    cpu->eax = g_sfera_static_render_lookup_runtime.packed_format_code;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_000663BC;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_000663BC:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x64u) = cpu->ecx;
    cpu->eax = g_sfera_recovered_static_runtime.render_state_07;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_000663E2;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_000663E2:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x68u) = cpu->ecx;
    label_000663EB:
    if (g_sfera_recovered_static_runtime.client_state_06 != 2u) goto label_00066449;
    cpu->eax = g_sfera_main_aux_runtime.resource_word;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_00066413;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066413:
    g_sfera_process_runtime.packed_layout_bytes += cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x1A0u) = cpu->ecx;
    cpu->eax = g_sfera_landscape_render_runtime.source_record_count;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax <<= 4u;
    cpu->ecx = 0u;
    if (cpu->esi != 1u) goto label_0006643D;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_0006643D:
    g_sfera_process_runtime.packed_layout_bytes = (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->ebp + 0x1A4u) = cpu->ecx;
    label_00066449:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)2u) goto label_00066220;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09 <= (int32_t)cpu->edx) goto label_000664ED;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    label_00066470:
    cpu->eax = g_sfera_recovered_static_runtime.animation_state;
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->eax);
    cpu->esi = cpu->ecx + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + cpu->edx + 4u) = cpu->edi;
    cpu->esi = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->eax + cpu->edx + 8u) = cpu->esi;
    cpu->eax = g_sfera_recovered_static_runtime.animation_state;
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->eax + 0xCu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x24u);
    *(uint32_t*)(cpu->esi + cpu->edx + 0xCu) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->eax + 0x10u);
    cpu->eax = cpu->ecx + cpu->eax + 0xCu;
    cpu->esi = cpu->esi + cpu->edx + 0xCu;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->esi = g_sfera_recovered_static_runtime.animation_state;
    x87_v0 = (double)*(float*)(cpu->ecx + cpu->esi + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x24u);
    *(float*)(cpu->eax + cpu->edx + 0x18u) = x87_v0; 
    cpu->esi = g_sfera_recovered_static_runtime.animation_state;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x24u);
    *(float*)(cpu->eax + cpu->edx + 0x1Cu) = (double)*(float*)(cpu->ecx + cpu->esi + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->ecx += 0x20u;
    cpu->edx += 0x24u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09) goto label_00066470;
    label_000664ED:
    cpu->edx = 0u;
    if ((int32_t)g_sfera_recovered_static_runtime.render_state_07 <= (int32_t)cpu->edx) goto label_00066557;
    cpu->ecx = 0u;
    cpu->eax = 0u;
    label_00066500:
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = *(uint32_t*)(cpu->eax + cpu->edi + 6u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x2Cu);
    *(uint32_t*)(cpu->ecx + cpu->esi + 8u) = cpu->edi;
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = *(uint16_t*)(cpu->eax + cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x2Cu);
    *(uint16_t*)(cpu->ecx + cpu->esi) = cpu->edi & 0xFFFFu;
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = *(uint16_t*)(cpu->eax + cpu->edi + 2u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x2Cu);
    *(uint16_t*)(cpu->ecx + cpu->esi + 2u) = cpu->edi & 0xFFFFu;
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = *(uint16_t*)(cpu->eax + cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x2Cu);
    *(uint16_t*)(cpu->ecx + cpu->esi + 4u) = cpu->edi & 0xFFFFu;
    ++cpu->edx;
    cpu->eax += 0xAu;
    cpu->ecx += 0xCu;
    if ((int32_t)cpu->edx < (int32_t)g_sfera_recovered_static_runtime.render_state_07) goto label_00066500;
    label_00066557:
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state) == 0u; sub_pred[2] = (int32_t)((uint32_t)(*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((sub_pred[0]) || (sub_pred[2])) goto label_00066677;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->eax = 0u;
    cpu->esi = 0u;
    label_00066573:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint8_t*)(cpu->esi + cpu->ecx);
    *(uint8_t*)(cpu->edi + cpu->eax) = cpu->edx & 0xFFu;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint8_t*)(cpu->esi + cpu->ecx + 1u);
    cpu->edi = g_sfera_landscape_map_runtime.material_remap;
    cpu->edx = *(uint16_t*)(cpu->edi + (cpu->edx * 2u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint16_t*)(cpu->eax + cpu->ecx + 2u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->edx + 2u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint16_t*)(cpu->eax + cpu->ecx + 4u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint16_t*)(cpu->eax + cpu->ecx + 6u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->edx + 6u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint16_t*)(cpu->eax + cpu->ecx + 8u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->edx + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint16_t*)(cpu->eax + cpu->ecx + 0xAu) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint8_t*)(cpu->esi + cpu->edx + 0xAu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint8_t*)(cpu->eax + cpu->ecx + 0xCu) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->edx + 0xBu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint16_t*)(cpu->eax + cpu->ecx + 0xEu) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = *(uint16_t*)(cpu->esi + cpu->edx + 0xDu);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    *(uint16_t*)(cpu->eax + cpu->ecx + 0x10u) = cpu->edx & 0xFFFFu;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->ecx = *(uint16_t*)(cpu->edi + cpu->eax + 2u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x88u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    if (*(uint8_t*)(cpu->ecx + 0x84u) == 0u) goto label_0006665C;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x78u);
    *(uint32_t*)(cpu->ebp + 0x1D4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x7Cu);
    *(uint32_t*)(cpu->ebp + 0x1D8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x80u);
    *(uint32_t*)(cpu->ebp + 0x1DCu) = cpu->ecx;
    label_0006665C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->esi += 0xFu;
    cpu->eax += 0x12u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state) goto label_00066573;
    label_00066677:
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (((uint32_t)(g_sfera_recovered_static_runtime.input_state_a) == 0u) || ((int32_t)((uint32_t)(g_sfera_recovered_static_runtime.input_state_a)) < (int32_t)(0u))) goto label_00066735;
    cpu->esi = 0u;
    cpu->edx = 0u;
    label_00066690:
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->edi = cpu->edx + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;
    label_000666A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->edi;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000666A0;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = *(uint8_t*)(cpu->edx + cpu->eax + 0x21u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x21u) = cpu->eax & 0xFFu;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = *(uint8_t*)(cpu->edx + cpu->eax + 0x22u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x22u) = cpu->eax & 0xFFu;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = *(uint8_t*)(cpu->edx + cpu->eax + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x20u) = cpu->eax & 0xFFu;
    if (*(uint8_t*)(cpu->ebp + 0x50u) == 0u) goto label_00066717;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = *(uint8_t*)(cpu->edx + cpu->eax + 0x23u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x25u) = cpu->eax & 0xFFu;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx + cpu->eax + 0x24u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint16_t*)(cpu->esi + cpu->ecx + 0x26u) = cpu->eax & 0xFFFFu;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = *(uint8_t*)(cpu->edx + cpu->eax + 0x26u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x24u) = cpu->eax & 0xFFu;
    label_00066717:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edx += 0x27u;
    cpu->esi += 0xACu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_recovered_static_runtime.input_state_a) goto label_00066690;
    label_00066735:
    cpu->ecx = g_sfera_static_render_lookup_runtime.sample_state;
    cpu->eax = g_sfera_landscape_map_runtime.material_remap;
    cpu->edx = cpu->ecx + cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x48u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466749u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.viewport_state;
    cpu->eax = g_sfera_render_sample_runtime.record_base;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x4Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46675Fu));
    cpu->esp += 0x18u;
    if (g_sfera_world_load_runtime.packed_variant == 0u) goto label_0006682A;
    cpu->esi = 0u;
    if ((int32_t)g_sfera_window_runtime.scene_record_count <= (int32_t)cpu->esi) goto label_000667D3;
    cpu->ecx = 0u;
    label_00066780:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_05;
    cpu->edi = *(uint32_t*)(cpu->edx + cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x54u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->edx + cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + cpu->ecx + 8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_05;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x54u);
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->eax + 0xCu);
    cpu->eax = cpu->ecx + cpu->eax + 0xCu;
    cpu->edx = cpu->ecx + cpu->edx + 0xCu;
    *(uint32_t*)(cpu->edx) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx + 8u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    ++cpu->esi;
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->eax;
    cpu->ecx += 0x1Cu;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_window_runtime.scene_record_count) goto label_00066780;
    label_000667D3:
    cpu->esi = 0u;
    if ((int32_t)g_sfera_process_runtime.packed_record_count <= (int32_t)cpu->esi) goto label_0006680E;
    cpu->eax = 0u;
    (void)cpu;
    label_000667E0:
    cpu->edx = g_sfera_spatial_index_runtime.quadtree_state;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax + cpu->edx));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x58u);
    *(uint16_t*)(cpu->eax + cpu->ecx) = cpu->edx & 0xFFFFu;
    cpu->edx = g_sfera_spatial_index_runtime.quadtree_state;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx + 2u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x58u);
    *(uint8_t*)(cpu->eax + cpu->ecx + 2u) = cpu->edx & 0xFFu;
    ++cpu->esi;
    cpu->eax += 3u;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_process_runtime.packed_record_count) goto label_000667E0;
    label_0006680E:
    cpu->eax = g_sfera_world_load_runtime.packed_variant;
    cpu->edx = g_sfera_scene_control_runtime.packed_section_base;
    cpu->ecx = cpu->eax + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x5Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466822u));
    cpu->esp += 0xCu;
    label_0006682A:
    if (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled != 1u) goto label_000668A3;
    cpu->ecx = g_sfera_static_render_lookup_runtime.packed_format_code;
    cpu->edx = g_sfera_recovered_static_runtime.render_state_10;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x64u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46684Au));
    cpu->ecx = 0u;
    cpu->esp += 0xCu;
    if ((int32_t)g_sfera_recovered_static_runtime.render_state_07 <= (int32_t)cpu->ecx) goto label_000668A3;
    cpu->eax = 0u;
    label_00066860:
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags;
    cpu->esi = *(uint16_t*)(cpu->eax + cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x68u);
    *(uint16_t*)(cpu->eax + cpu->edx) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags;
    cpu->esi = *(uint16_t*)(cpu->eax + cpu->esi + 2u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x68u);
    *(uint16_t*)(cpu->eax + cpu->edx + 2u) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags;
    cpu->esi = *(uint16_t*)(cpu->eax + cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x68u);
    *(uint16_t*)(cpu->eax + cpu->edx + 4u) = cpu->esi & 0xFFFFu;
    ++cpu->ecx;
    cpu->eax += 6u;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_recovered_static_runtime.render_state_07) goto label_00066860;
    label_000668A3:
    if (g_sfera_world_load_runtime.packed_variant != 0u) goto label_00066A09;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (((uint32_t)(g_sfera_recovered_static_runtime.input_state_a) == 0u) || ((int32_t)((uint32_t)(g_sfera_recovered_static_runtime.input_state_a)) < (int32_t)(0u))) goto label_00066A09;
    cpu->edi = 0u;
    cpu->esi = 0u;
    label_000668D0:
    cpu->eax = g_sfera_client_main_scalar_runtime.state_05;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->esi);
    *(uint32_t*)(cpu->edi + cpu->ecx + 0x84u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->esi + 4u);
    cpu->eax += cpu->esi;
    cpu->ecx = cpu->edi + cpu->ecx + 0x84u;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x14u);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->eax = cpu->edi + cpu->ecx;
    cpu->edx = cpu->eax + 0x24u;
    cpu->ecx = cpu->eax + 0x84u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46691Eu)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x46691Eu));
    cpu->eax = g_sfera_client_main_scalar_runtime.state_05;
    x87_v0 = (double)*(float*)(cpu->esi + cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + cpu->eax)));
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    *(float*)(cpu->esp + 0x38u) = ((((double)*(float*)(cpu->esi + cpu->eax + 0x10u))) + (((double)*(float*)(cpu->esi + cpu->eax + 4u))));
    x87_v0 = (double)*(float*)(cpu->esi + cpu->eax + 0x14u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + cpu->eax + 8u)));
    cpu->eax = cpu->edi + cpu->edx + 0x9Cu;
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v1 = 0.5;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->eax = g_sfera_client_main_scalar_runtime.state_05;
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esi + cpu->eax + 0xCu))) - (((double)*(float*)(cpu->esi + cpu->eax))));
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esi + cpu->eax + 0x10u))) - (((double)*(float*)(cpu->esi + cpu->eax + 4u))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esi + cpu->eax + 0x14u))) - (((double)*(float*)(cpu->esi + cpu->eax + 8u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    ++cpu->eax;
    *(float*)(cpu->edi + cpu->edx + 0xA8u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->esi += 0x18u;
    cpu->edi += 0xACu;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_recovered_static_runtime.input_state_a) goto label_000668D0;
    label_00066A09:
    if (*(uint32_t*)(cpu->ebp + 0x6Cu) != 2u) goto label_00066A51;
    cpu->eax = g_sfera_main_aux_runtime.resource_word;
    cpu->ecx = g_sfera_landscape_render_runtime.source_section_base;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1A0u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466A2Au));
    cpu->eax = g_sfera_landscape_render_runtime.source_record_count;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_03;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1A4u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax <<= 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466A49u));
    cpu->esp += 0x18u;
    label_00066A51:
    cpu->esi = 0u;
    if (g_sfera_world_load_runtime.packed_variant == cpu->esi) goto label_00066B7D;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if ((int32_t)g_sfera_recovered_static_runtime.input_state_a <= (int32_t)cpu->esi) goto label_00066B7D;
    cpu->edi = native_function_address32(&::_stricmp);
    label_00066A80:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->eax + 0x28u) = 0xFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    label_00066A90:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = (uintptr_t)(cpu->ecx == 0u ? "back_swo" : cpu->ecx == 1u ? "back_ara" : cpu->ecx == 2u ? "back_axe" : cpu->ecx == 3u ? "back_spe" : "back_cam");
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00066AB6;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x18u));
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x28u) = cpu->edx & 0xFFu;
    label_00066AB6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)5u) goto label_00066A90;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, (uintptr_t)"finl_m1o1");

    if (cpu->eax == 0u) goto label_00066AEC;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->ecx += cpu->esi;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->ecx, (uintptr_t)"fingl_m1o1");

    if (cpu->eax != 0u) goto label_00066AF4;
    label_00066AEC:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->edx + 0x28u) = 0x64u;
    label_00066AF4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, (uintptr_t)"finr_m1o1");

    if (cpu->eax == 0u) goto label_00066B1C;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->ecx += cpu->esi;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->ecx, (uintptr_t)"fingr_m1o1");

    if (cpu->eax != 0u) goto label_00066B24;
    label_00066B1C:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->edx + 0x28u) = 0x65u;
    label_00066B24:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, (uintptr_t)"neck_m1o1");

    if (cpu->eax != 0u) goto label_00066B40;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x28u) = 0x66u;
    label_00066B40:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    lift_push32(cpu, 4u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, (uintptr_t)"head"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_strnicmp), LIFT_CODE_TOKEN_VA(0x466B4Du));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_00066B62;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint8_t*)(cpu->esi + cpu->eax + 0x28u) = 0x67u;
    label_00066B62:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->esi += 0xACu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_recovered_static_runtime.input_state_a) goto label_00066A80;
    label_00066B7D:
    *(float*)(cpu->esp + 0x40u) = ((((double)*(float*)(cpu->ebp + 0xC4u))) - (((double)*(float*)(cpu->ebp + 0x88u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    x87_v0 = (double)*(float*)(cpu->ebp + 0xC8u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0x8Cu)));
    *(float*)(cpu->esp + 0x44u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    x87_v0 = (double)*(float*)(cpu->ebp + 0xCCu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0x90u)));
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    x87_v0 = (double)*(float*)(cpu->ebp + 0x88u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xACu)));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->ebp + 0x8Cu);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xB0u)));
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->ebp + 0x90u);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->ebp + 0xB4u)));
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->eax;
    x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (x87_v3);
    x87_v4 = x87_v1;
    x87_v1 = x87_v1 * x87_v4; 
    x87_v1 = x87_v1 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    { const double lift_left=x87_v2; const double lift_right=1e-06;  if (!(lift_left>lift_right)) goto label_00066CC7; }
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v0 = std::atan2(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x58u) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x58u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x58u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u); x87_v1 = x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u); x87_v4 = x87_v3;
    x87_v5 = (double)*(float*)(cpu->esp + 0x44u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v1; x87_v1 = temporary; }
    x87_v4 = x87_v5 - x87_v4; 
    *(float*)(cpu->esp + 0x10u) = x87_v4; 
    x87_v4 = x87_v2;
    x87_v1 = x87_v1 * x87_v4; 
    x87_v4 = x87_v3;
    x87_v0 = x87_v0 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x38u) = x87_v2; 
    *(float*)(cpu->esp + 0x34u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x28u)));
    x87_v2 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x60u) = x87_v0; 
    goto label_00066CD1;
    label_00066CC7:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    *(float*)(cpu->esp + 0x58u) = (double)(0.0);
    label_00066CD1:
    x87_v0 = (double)*(float*)(cpu->esp + 0x60u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x64u);
    x87_v0 = std::atan2(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x54u) = ((4.7123894691467285) - (((double)*(float*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(double*)(cpu->esp + 0x20u) = x87_v0;
     x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((*(double*)(cpu->esp + 0x20u)) - ((((((double)*(float*)(cpu->esp + 0x10u))) * (((double)*(float*)(cpu->esp + 0x38u)))))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v0 = std::atan2(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->esi = cpu->ebp + 0x148u;
    x87_v0 = (1.5707964897155762) - (x87_v0);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x54u;
    cpu->ecx = cpu->ebp + 0x88u;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp + 0x54u) = (-((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x58u) = (-((double)*(float*)(cpu->esp + 0x58u)));
    *(float*)(cpu->esp + 0x5Cu) = (-((double)*(float*)(cpu->esp + 0x5Cu)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x466D79u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x466D79u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xDCu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xE0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xE4u);
    *(uint32_t*)(cpu->ebp + 0x188u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x18Cu) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0x190u) = cpu->eax;
    cpu->edi = cpu->esp + 0x7Cu;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->edi;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u; cpu->ecx = 0u;
    x87_v0 = (double)*(float*)(cpu->ebp + 0x188u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + 0xCu)));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->ebp + 0x18Cu))) - (((double)*(float*)(cpu->eax + 0x1Cu))));
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->ebp + 0x190u))) - (((double)*(float*)(cpu->eax + 0x2Cu))));
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x20u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->eax)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x20u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->ebp + 0x188u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->eax + 4u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x24u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->ebp + 0x18Cu) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x18u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->eax + 8u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax + 0x28u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->ebp + 0x190u) = x87_v0; 
    if (*(uint32_t*)(cpu->ebp + 0x6Cu) != 0u) goto label_00066E8C;
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->ebp + 0x7Cu))) - (((double)*(float*)(cpu->ebp + 0x70u))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->ebp + 0x80u))) - (((double)*(float*)(cpu->ebp + 0x74u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x18u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_00066E68; }
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    goto label_00066E6A;
    label_00066E68:
    x87_v0 = x87_v0; 
    label_00066E6A:
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->ebp + 0x84u))) - (((double)*(float*)(cpu->ebp + 0x78u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    { const double lift_left=(double)*(float*)(cpu->esp + 0x18u); const double lift_right=x87_v0; if (lift_left>lift_right) goto label_00066ECC; }
    x87_v0 = x87_v0; 
    goto label_00066ED0;
    label_00066E8C:
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ebp + 0x188u);
    { const double lift_right=(double)*(float*)(cpu->ebp + 0x18Cu); const double lift_left=(double)*(float*)(cpu->esp + 0x18u); if (!(lift_left>lift_right)) goto label_00066EB3; }
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->ebp + 0x18Cu);
    label_00066EB3:
    { const double lift_right=(double)*(float*)(cpu->ebp + 0x190u); const double lift_left=(double)*(float*)(cpu->esp + 0x18u); if (!(lift_left>lift_right)) goto label_00066ED0; }
    x87_v0 = (double)*(float*)(cpu->ebp + 0x190u);
    label_00066ECC:
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    label_00066ED0:
    *(float*)(cpu->ebp + 0x198u) = (double)*(float*)(cpu->esp + 0x18u);
    { const double lift_left=(double)*(float*)(cpu->ebp + 0x198u); const double lift_right=0.05000000074505806; if (!(lift_left<lift_right)) goto label_00067439; }
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    cpu->edx = cpu->eax + 1u;
    label_00066F00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00066F00;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00066F43;
    cpu->eax = 0u;
    label_00066F10:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00066F10;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_00066F36;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_00066F3B;
    label_00066F36:
    cpu->eax = (uintptr_t)"at";
    label_00066F3B:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->ecx);
    goto label_00066F4D;
    label_00066F43:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_00066F4D:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x466F4Du));
    cpu->edi = native_function_address32(&::fputs);
    cpu->ebx = native_function_address32(&::fflush);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00066F87;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x466F74u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00066F87:
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_00066F90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00066F90;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00066FD3;
    cpu->eax = 0u;
    label_00066FA0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00066FA0;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_00066FC6;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_00066FCB;
    label_00066FC6:
    cpu->eax = (uintptr_t)"at";
    label_00066FCB:
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->eax);
    goto label_00066FDD;
    label_00066FD3:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_00066FDD:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x466FDDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0006700B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x466FF8u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_0006700B:
    x87_v0 = (double)*(float*)(cpu->ebp + 0x88u);
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = cpu->eax + 1u;
    label_00067020:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067020;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00067063;
    cpu->eax = 0u;
    label_00067030:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067030;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_00067056;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_0006705B;
    label_00067056:
    cpu->eax = (uintptr_t)"at";
    label_0006705B:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->ecx);
    goto label_0006706D;
    label_00067063:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006706D:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x46706Du));
    cpu->edi = native_function_address32(&::fprintf);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000670AB;
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = x87_v0;
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x67092u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467098u));
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_000670AB:
    x87_v0 = (double)*(float*)(cpu->ebp + 0xDCu);
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = cpu->eax + 1u;
    label_000670C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000670C0;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00067103;
    cpu->eax = 0u;
    label_000670D0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000670D0;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_000670F6;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_000670FB;
    label_000670F6:
    cpu->eax = (uintptr_t)"at";
    label_000670FB:
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->edx);
    goto label_0006710D;
    label_00067103:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006710D:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x46710Du));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00067145;
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = x87_v0;
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x6712Cu));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467132u));
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00067145:
    x87_v0 = (double)*(float*)(cpu->ebp + 0x8Cu);
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = cpu->eax + 1u;
    label_00067157:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067157;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00067197;
    cpu->eax = 0u;
    label_00067164:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067164;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_0006718A;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_0006718F;
    label_0006718A:
    cpu->eax = (uintptr_t)"at";
    label_0006718F:
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->eax);
    goto label_000671A1;
    label_00067197:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_000671A1:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4671A1u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000671D9;
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = x87_v0;
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x671C0u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4671C6u));
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_000671D9:
    x87_v0 = (double)*(float*)(cpu->ebp + 0xE0u);
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = cpu->eax + 1u;
    label_000671F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000671F0;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00067233;
    cpu->eax = 0u;
    label_00067200:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067200;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_00067226;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_0006722B;
    label_00067226:
    cpu->eax = (uintptr_t)"at";
    label_0006722B:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->ecx);
    goto label_0006723D;
    label_00067233:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006723D:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x46723Du));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00067275;
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = x87_v0;
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x6725Cu));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467262u));
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00067275:
    x87_v0 = (double)*(float*)(cpu->ebp + 0x90u);
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = cpu->eax + 1u;
    label_00067287:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067287;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_000672C7;
    cpu->eax = 0u;
    label_00067294:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067294;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_000672BA;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_000672BF;
    label_000672BA:
    cpu->eax = (uintptr_t)"at";
    label_000672BF:
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->edx);
    goto label_000672D1;
    label_000672C7:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_000672D1:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4672D1u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00067309;
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = x87_v0;
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x672F0u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4672F6u));
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00067309:
    x87_v0 = (double)*(float*)(cpu->ebp + 0xE4u);
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = cpu->eax + 1u;
    label_00067320:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067320;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00067363;
    cpu->eax = 0u;
    label_00067330:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00067330;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_00067356;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_0006735B;
    label_00067356:
    cpu->eax = (uintptr_t)"at";
    label_0006735B:
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->eax);
    goto label_0006736D;
    label_00067363:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006736D:
    cpu->ebp = native_function_address32(&::fopen);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000673A7;
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = x87_p0;
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x6738Eu));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467394u));
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_000673A7:
    cpu->eax = (uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_000673B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000673B0;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_000673F3;
    cpu->eax = 0u;
    label_000673C0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_log_runtime.files[0].path.text[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x6Cu) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000673C0;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != 1u) goto label_000673E6;
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_runtime.files[0].has_written)) == 0u) goto label_000673EB;
    label_000673E6:
    cpu->eax = (uintptr_t)"at";
    label_000673EB:
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->ecx);
    goto label_000673FD;
    label_000673F3:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_000673FD:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0006742B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x46740Eu));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467418u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_0006742B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = (uintptr_t)"Object has size < MIN_OBJECT_SIZE: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67439u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x67439u));
    label_00067439:
    sub_pred[1] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state) == 0u; sub_pred[3] = (int32_t)((uint32_t)(*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((sub_pred[1]) || (sub_pred[3])) goto label_00067675;
    x87_v0 = 0.0;
    cpu->edi = 0u;
    x87_v1 = 0.0;
    label_00067454:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->ecx = *(uint16_t*)(cpu->edi + cpu->edx + 2u);
    cpu->esi = *(uint16_t*)(cpu->edi + cpu->edx + 8u);
    cpu->eax = cpu->edi + cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    if ((cpu->edx & 0xFFFFu) >= *(uint16_t*)(cpu->eax + 0xAu)) goto label_000674B4;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x88u);
    cpu->eax = cpu->esi + (cpu->esi * 8u);
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->eax += cpu->eax;
    goto label_00067491;
    label_0006748D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00067491:
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->esi += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->edx + 0x20u) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->edx = *(uint16_t*)(cpu->edi + cpu->edx + 0xAu);
    ++cpu->ecx;
    cpu->eax += 0x24u;
    if ((int32_t)cpu->ecx < (int32_t)cpu->edx) goto label_0006748D;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    label_000674B4:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->ecx = cpu->edi + cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->ecx);
    cpu->eax &= 0x7Fu;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xACu);
    cpu->eax += *(uint32_t*)(cpu->ebp + 0x3Cu);
    if (*(uint8_t*)(cpu->eax) != 0x5Fu) goto label_00067659;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    if ((cpu->eax & 0xFFu) != 0x75u) goto label_00067530;
    cpu->eax = 0u;
    cpu->edx = 0u;
    if ((cpu->eax & 0xFFFFu) >= *(uint16_t*)(cpu->ecx + 0xAu)) goto label_00067659;
    *(float*)(cpu->esp + 0x5Cu) = x87_v1;
    cpu->ecx = cpu->esi + (cpu->esi * 8u);
    x87_v2 = (double)-1.0f;
    cpu->ecx += cpu->ecx;
    *(float*)(cpu->esp + 0x60u) = x87_v2; 
    cpu->ecx += cpu->ecx;
    *(float*)(cpu->esp + 0x64u) = x87_v1;
    label_00067500:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->eax = cpu->ecx + cpu->eax + 0xCu;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->eax = *(uint16_t*)(cpu->edi + cpu->eax + 0xAu);
    ++cpu->edx;
    cpu->ecx += 0x24u;
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_00067500;
    goto label_00067659;
    label_00067530:
    if ((cpu->eax & 0xFFu) != 0x73u) goto label_00067659;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if ((cpu->edx & 0xFFFFu) >= *(uint16_t*)(cpu->ecx + 0xAu)) goto label_00067659;
    x87_v2 = x87_v0;
    cpu->eax = cpu->esi + (cpu->esi * 8u);
    x87_v0 = x87_v0 * x87_v2; 
    cpu->eax += cpu->eax;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(double*)(cpu->esp + 0x50u) = x87_v1;
    label_00067561:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    x87_v1 = (x87_v1) + (*(double*)(cpu->esp + 0x50u));
    x87_v2 = x87_v0;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = (double)9.999999747378752e-06f;
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_000675F4; }
    x87_v0 = x87_v0; 
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x40u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x44u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(float*)(cpu->esp + 0x48u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    goto label_0006762E;
    label_000675F4:
    x87_v1 = 1.0;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x28u) = x87_v1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v0 = 0.0;
    label_0006762E:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->edx = *(uint16_t*)(cpu->edi + cpu->ecx + 0xAu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_00067561;
    x87_v1 = 0.0;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_00067659:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 0x12u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state) goto label_00067454;
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00067675:
    cpu->ecx = g_sfera_landscape_map_runtime.material_remap;
    lift_push32(cpu, 0x234Eu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46768Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x46768Au));
    lift_push32(cpu, 0x234Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46769Bu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x46769Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 2u);
    cpu->esi = cpu->ebp + 0x1C4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"dg_type"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4676B9u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x4676B9u));
    if (cpu->eax == 1u) goto label_000676C6;
    *(uint32_t*)(cpu->esi) = 0xFFFFFFFFu;
    goto label_000676CF;
    label_000676C6:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x676CFu)); sfera_sub_004255F0(cpu, LIFT_CODE_TOKEN_RVA(0x676CFu));
    label_000676CF:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004676F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    if ((((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_0006774E;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467739u)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x467739u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA360) ? 0u : 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    label_0006774E:
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if (cpu->ecx != 0u) goto label_00067762;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67762u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x67762u));
    label_00067762:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46795Bu)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x46795Bu));
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
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
    if ((((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_00067ACC;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467AB7u)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x467AB7u));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA360) ? 0u : 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    label_00067ACC:
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if (cpu->ecx != 0u) goto label_00067AE0;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x67AE0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x67AE0u));
    label_00067AE0:
    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467B22u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x467B22u));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setVisible(cpu);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467BE7u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x467BE7u));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467CA0u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x467CA0u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setPosition(cpu);
    goto label_00067CBF;
    label_00067CB5:
    g_sfera_window_runtime.active_window_index = 0xFFFFFFFFu;
    label_00067CBF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x467CC4u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x467CC4u));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->show(cpu);
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468074u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_VA(0x468074u));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468120u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x468120u));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46816Cu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x46816Cu));
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
    lift_trap(cpu, 0x46819Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004681A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0x78u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x88u);
    *(uint32_t*)(cpu->esp + 0xCu) = 3u;
    x87_v1 = 255.0;
    x87_v0 = (x87_v0) / (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x8Cu);
    x87_v1 = (x87_v1) / (x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v0 = (((double)*(float*)(cpu->esp + 0x90u))) / (x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0;
    *(float*)(cpu->esp + 0x20u) = x87_v0;
    *(float*)(cpu->esp + 0x24u) = x87_v0;
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0;
    x87_v1 = 0.0;
    *(float*)(cpu->esp + 0x30u) = x87_v1;
    *(float*)(cpu->esp + 0x34u) = x87_v1;
    *(float*)(cpu->esp + 0x38u) = x87_v1;
    *(float*)(cpu->esp) = x87_v1;
    *(float*)(cpu->esp + 4u) = x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esp);
    *(float*)(cpu->esp + 8u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(float*)(cpu->esp + 0x58u) = x87_v1;
    *(float*)(cpu->esp + 0x6Cu) = x87_v1;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    *(float*)(cpu->esp + 0x70u) = x87_v1; 
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->eax = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(float*)(cpu->esp + 0x5Cu) = x87_v0;
    *(float*)(cpu->esp + 0x60u) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    *(float*)(cpu->esp + 0x68u) = x87_v0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x6Cu) = x87_v0; 
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46827Du)); sfera_sub_004D8C10(cpu, LIFT_CODE_TOKEN_VA(0x46827Du));
    if ((int32_t)g_sfera_light_runtime.active_handles.capacity > (int32_t)0u) goto label_00068292;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68292u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68292u));
    label_00068292:
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->ecx) == 1u) goto label_000682FF;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)8u) goto label_000682CF;
    lift_push32(cpu, 0x3953u); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4682BCu));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x682CFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x682CFu));
    label_000682CF:
    if ((int32_t)g_sfera_light_runtime.active_handles.capacity > (int32_t)0u) goto label_000682E4;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x682E4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x682E4u));
    label_000682E4:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->edx) = 1u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x682FFu)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x682FFu));
    label_000682FF:
    cpu->esp += 0x78u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4684B4u)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x4684B4u));
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0xB8u;
    cpu->ecx = (uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4684C7u)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x4684C7u));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x98u) = x87_v0; 
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46869Cu)); sfera_sub_004D8C10(cpu, LIFT_CODE_TOKEN_VA(0x46869Cu));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6870Cu)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x6870Cu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46875Cu)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x46875Cu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468795u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x468795u));
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
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    cpu->ecx -= cpu->eax;
    cpu->edi = (cpu->ecx * 4u) + ((uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][0]);
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),60u); cpu->esi += 60u; cpu->edi += 60u;
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6899Du)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x6899Du));
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
    lift_trap(cpu, 0x4689D2u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004689E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->ebx + 3u;
    cpu->ebp = cpu->ebx + 0x1Du;
    label_000689F6:
    if (((*(uint32_t*)(cpu->esp + 0x10u)) & (cpu->ebx)) != 0u) goto label_00068A6D;
    if ((int32_t)cpu->esi >= 0) goto label_00068A0A;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68A0Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68A0Au));
    label_00068A0A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068A1E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68A1Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68A1Eu));
    label_00068A1E:
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->edi + cpu->ecx) == 0u) goto label_00068A6D;
    g_sfera_main_command_state_runtime.light_update_counter = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u;
    if ((int32_t)cpu->esi >= 0) goto label_00068A3E;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68A3Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68A3Eu));
    label_00068A3E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068A52;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68A52u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68A52u));
    label_00068A52:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->edi + cpu->edx) = 0u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68A6Du)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x68A6Du));
    label_00068A6D:
    cpu->ebx += cpu->ebx;
    cpu->edi += 4u;
    ++cpu->esi;
    if ((--cpu->ebp) != 0u) goto label_000689F6;
    cpu->ebx = 1u;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->ebp + 4u;
    label_00068A80:
    if (((*(uint32_t*)(cpu->esp + 0x10u)) & (cpu->ebx)) == 0u) goto label_00068B01;
    if ((int32_t)cpu->esi >= 0) goto label_00068A94;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68A94u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68A94u));
    label_00068A94:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068AA8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68AA8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68AA8u));
    label_00068AA8:
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->edi + cpu->ecx) == 1u) goto label_00068B01;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = cpu->eax;
    if ((int32_t)cpu->eax > (int32_t)8u) goto label_00068B19;
    if ((int32_t)cpu->esi >= 0) goto label_00068AD2;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68AD2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68AD2u));
    label_00068AD2:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068AE6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68AE6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68AE6u));
    label_00068AE6:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->edi + cpu->edx) = 1u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68B01u)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x68B01u));
    label_00068B01:
    ++cpu->esi;
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    cpu->ebx += cpu->ebx;
    cpu->edi += 4u;
    if ((int32_t)cpu->eax < (int32_t)0x1Eu) goto label_00068A80;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00068B19:
    lift_push32(cpu, 0x3BBAu); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x468B28u));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468B3Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x468B3Bu));
    lift_trap(cpu, 0x468B3Bu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00468B40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 3u;
    cpu->ebx = cpu->esi + 0x1Du;
    label_00068B50:
    if ((int32_t)cpu->esi >= 0) goto label_00068B5E;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68B5Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68B5Eu));
    label_00068B5E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068B72;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68B72u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68B72u));
    label_00068B72:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->edi + cpu->eax) == 0u) goto label_00068BC0;
    g_sfera_main_command_state_runtime.light_update_counter = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u;
    if ((int32_t)cpu->esi >= 0) goto label_00068B91;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68B91u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x68B91u));
    label_00068B91:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_00068BA5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68BA5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68BA5u));
    label_00068BA5:
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->edi + cpu->ecx) = 0u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68BC0u)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x68BC0u));
    label_00068BC0:
    cpu->edi += 4u;
    ++cpu->esi;
    if ((--cpu->ebx) != 0u) goto label_00068B50;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00468BD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->ecx = 0x6458u;
    lift_push32(cpu, 0x3F97u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_interpolation_runtime.subdivision_count = 0xDu;
    g_sfera_landscape_render_runtime.grid_buffer_bytes = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468C16u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x468C16u));
    cpu->ecx = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    lift_push32(cpu, 0x3F98u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468C30u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x468C30u));
    cpu->ecx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x3F99u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468C53u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x468C53u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    g_sfera_window_runtime.landscape_grid_records = cpu->eax;
    cpu->eax = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x468C67u));
    cpu->edx = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x468C7Bu));
    cpu->eax = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ecx = g_sfera_window_runtime.landscape_grid_records;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x468C98u));
    cpu->eax = 0x186A0u;
    cpu->esp += 0x24u;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07) = cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468CB4u)); sfera_sub_00460570(cpu, LIFT_CODE_TOKEN_VA(0x468CB4u));
    cpu->edx = 0x3FA0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468CC3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x468CC3u));
    lift_push32(cpu, 0x1598u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468CCDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x468CCDu));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->esi == 0u) goto label_00068D14;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)0u) goto label_00068CF7;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68CF7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x68CF7u));
    label_00068CF7:
    cpu->edx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468D12u)); sfera_sub_004253F0(cpu, LIFT_CODE_TOKEN_VA(0x468D12u));
    goto label_00068D16;
    label_00068D14:
    cpu->eax = 0u;
    label_00068D16:
    g_sfera_world_render_runtime.world_spatial_index = cpu->eax;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & ((cpu->eax & 0xFFu))) != 0u) goto label_00068DC1;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468DACu)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x468DACu));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA360) ? 0u : 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    label_00068DC1:
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if (cpu->ecx != 0u) goto label_00068DD5;
    cpu->ecx = (uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68DD5u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x68DD5u));
    label_00068DD5:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
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
__declspec(noinline) void sfera_sub_00468E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->ebx + (cpu->ebx * 4u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp + (cpu->eax * 2u);
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u) + 0x8Cu);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->edi = (uintptr_t)&g_sfera_terrain_neighbor_runtime.cells[0];
    cpu->edx = 0u;
    label_00068E80:
    cpu->ecx = sfera_neighbor_dy(cpu->edx);
    cpu->eax = sfera_neighbor_dx(cpu->edx);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->edi) = 0u;
    if ((int32_t)(cpu->eax) < 0) goto label_00068EBC;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ebp + 0x84u)) goto label_00068EB8;
    if ((int32_t)cpu->ecx < 0) goto label_00068EB8;
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->ebp + 0x88u)) goto label_00068EB8;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->ecx + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->ecx * 4u) + 0x8Cu);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    label_00068EB8:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    label_00068EBC:
    ++cpu->edx;
    cpu->edi += 4u;
    if ((int32_t)cpu->edx < (int32_t)8u) goto label_00068E80;
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[5];
    cpu->edi = 1u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->edx == 0u) goto label_00068EF5;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468EF1u)); sfera_sub_0045B620(cpu, LIFT_CODE_TOKEN_VA(0x468EF1u));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    label_00068EF5:
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[4];
    if (cpu->edx == 0u) goto label_00068F10;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468F0Cu)); sfera_sub_0045B620(cpu, LIFT_CODE_TOKEN_VA(0x468F0Cu));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_00068F10:
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[7];
    if (cpu->edx == 0u) goto label_00068F2B;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 3u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468F27u)); sfera_sub_0045B620(cpu, LIFT_CODE_TOKEN_VA(0x468F27u));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_00068F2B:
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[6];
    if (cpu->edx == 0u) goto label_00068F44;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 3u); lift_push32(cpu, 2u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x468F42u)); sfera_sub_0045B620(cpu, LIFT_CODE_TOKEN_VA(0x468F42u));
    cpu->edi = cpu->eax;
    label_00068F44:
    if (*(uint32_t*)(cpu->esp + 0x20u) == 0u) goto label_00069075;
    if (*(uint32_t*)(cpu->esp + 0x14u) == 0u) goto label_00069075;
    if (*(uint32_t*)(cpu->esp + 0x18u) == 0u) goto label_00069075;
    if (cpu->edi == 0u) goto label_00069075;
    if (*(uint8_t*)(cpu->esi + 0x689Cu) != 0u) goto label_00068F99;
    cpu->ecx = g_sfera_terrain_neighbor_runtime.cells[6];
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[4];
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[3];
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68F99u)); sfera_sub_00453D00(cpu, LIFT_CODE_TOKEN_RVA(0x68F99u));
    label_00068F99:
    if (*(uint8_t*)(cpu->esi + 0x689Du) != 0u) goto label_00068FC4;
    cpu->eax = g_sfera_terrain_neighbor_runtime.cells[7];
    cpu->ecx = g_sfera_terrain_neighbor_runtime.cells[4];
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[2];
    lift_push32(cpu, 0u); lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68FC4u)); sfera_sub_00453D00(cpu, LIFT_CODE_TOKEN_RVA(0x68FC4u));
    label_00068FC4:
    if (*(uint8_t*)(cpu->esi + 0x689Eu) != 0u) goto label_00068FEF;
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[6];
    cpu->eax = g_sfera_terrain_neighbor_runtime.cells[5];
    lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[0];
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x68FEFu)); sfera_sub_00453D00(cpu, LIFT_CODE_TOKEN_RVA(0x68FEFu));
    label_00068FEF:
    if (*(uint8_t*)(cpu->esi + 0x689Fu) != 0u) goto label_0006901B;
    cpu->ecx = g_sfera_terrain_neighbor_runtime.cells[7];
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[5];
    lift_push32(cpu, 2u); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[1];
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6901Bu)); sfera_sub_00453D00(cpu, LIFT_CODE_TOKEN_RVA(0x6901Bu));
    label_0006901B:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469022u)); sfera_sub_00452A00(cpu, LIFT_CODE_TOKEN_VA(0x469022u));
    cpu->esi = 0u;
    label_00069027:
    cpu->ecx = sfera_neighbor_dy(cpu->esi);
    cpu->eax = sfera_neighbor_dx(cpu->esi);
    cpu->ecx += cpu->ebp;
    if ((int32_t)(cpu->eax += cpu->ebx) < 0) goto label_00069060;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->edx + 0x84u)) goto label_00069060;
    if ((int32_t)cpu->ecx < 0) goto label_00069060;
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->edx + 0x88u)) goto label_00069060;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->ecx + (cpu->eax * 2u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0x8Cu);
    if (cpu->ecx == 0u) goto label_00069060;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69060u)); sfera_sub_00452A00(cpu, LIFT_CODE_TOKEN_RVA(0x69060u));
    label_00069060:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)8u) goto label_00069027;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00069075:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Smooth error in %s! Look at lndbug.tga");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469084u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x469084u));
    lift_trap(cpu, 0x469084u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00469090(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[7]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0xECu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x4423u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x1E4u;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4690BBu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4690BBu));
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    lift_push32(cpu, 0x1E4u);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4690C8u));
    cpu->eax = *(uint32_t*)((uintptr_t)"AutoGrass");
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"AutoGrass") + 4u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"AutoGrass") + 8u));
    cpu->esp += 0xCu;
    *(uint16_t*)(cpu->ebx + 8u) = cpu->edx & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    if ((int32_t)cpu->esi <= (int32_t)cpu->edi) goto label_00069152;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax += 4u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    label_0006910D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46911Fu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x46911Fu));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x20u);
    *(uint32_t*)(cpu->esp + 0x40u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x40u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->edi += *(uint32_t*)(cpu->eax + 0x28u);
    *(uint32_t*)(cpu->esp + 0x6Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x6Cu)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->esp + 0x3Cu)) goto label_0006913A;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    label_0006913A:
    if ((int32_t)cpu->edx <= (int32_t)*(uint32_t*)(cpu->esp + 0x28u)) goto label_00069144;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    label_00069144:
    *(uint32_t*)(cpu->esp + 0x38u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x38u)) + (uint64_t)(0x2F4u) + (uint64_t)(0u);
    if ((--*(uint32_t*)(cpu->esp + 0x34u)) != 0u) goto label_0006910D;
    label_00069152:
    x87_v0 = 141.12777709960938;
    *(uint32_t*)(cpu->ebx + 0x38u) = 1u;
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->esi;
    *(float*)(cpu->ebx + 0x194u) = x87_v0; 
    cpu->esi = cpu->esi + (cpu->esi * 8u);
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, 0x443Bu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->ebx + 0x28u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469194u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x469194u));
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x443Cu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4691ADu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4691ADu));
    lift_push32(cpu, 0x443Du);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xACu;
    *(uint32_t*)(cpu->ebx + 0x2Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4691C4u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4691C4u));
    *(uint32_t*)(cpu->ebx + 0x3Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x443Eu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4691E1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4691E1u));
    lift_push32(cpu, 0x4440u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x1C8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4691FCu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4691FCu));
    x87_v0 = (double)-5.0f;
    *(uint32_t*)(cpu->ebx + 0x1CCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(uint32_t*)(cpu->ebx + 0x1C4u) = 0u;
    cpu->ecx = *(uint32_t*)((uintptr_t)"_u_grass");
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"_u_grass") + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"_u_grass") + 8u));
    *(uint8_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(uint8_t*)(cpu->edx + 0x20u) = 1u;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(uint8_t*)(cpu->eax + 0x21u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(uint8_t*)(cpu->ecx + 0x22u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(float*)(cpu->edx + 0x84u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    x87_v1 = (double)5.0f;
    *(float*)(cpu->eax + 0x90u) = x87_v1;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(float*)(cpu->ecx + 0x88u) = (-((double)*(float*)(cpu->ebp + 0xCu)));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(float*)(cpu->edx + 0x94u) = (double)(0.0);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->eax + 0x8Cu) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(float*)(cpu->ecx + 0x98u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    cpu->edx = cpu->eax + 0x24u;
    cpu->ecx = cpu->eax + 0x84u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46929Au)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x46929Au));
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x50u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    x87_v1 = (double)-0.699999988079071f;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    *(float*)(cpu->esp + 0x54u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 0x9Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x58u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    x87_v0 = (double)8.0f;
    *(uint32_t*)(cpu->eax + 0xA0u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xA4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    *(float*)(cpu->eax + 0xA8u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x3Cu);
    x87_v0 = (double)0.5f;
    *(float*)(cpu->ebx + 0x1A8u) = x87_v0; 
    std::memmove((void*)(cpu->ebx + 0xE8u),(void*)(cpu->eax + 0x24u),96u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x84u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(uint32_t*)(cpu->ebx + 0x70u) = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x88u);
    *(uint32_t*)(cpu->ebx + 0x74u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x8Cu);
    *(uint32_t*)(cpu->ebx + 0x78u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x90u);
    *(uint32_t*)(cpu->ebx + 0x7Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x94u);
    *(uint32_t*)(cpu->ebx + 0x80u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x98u);
    *(uint32_t*)(cpu->ebx + 0x84u) = cpu->edx;
    lift_push32(cpu, 0x4454u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469355u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x469355u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46935Eu));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->esi;
    if ((int32_t)cpu->edi <= (int32_t)cpu->esi) goto label_000693B6;
    label_0006937D:
    if ((int32_t)cpu->esi >= 0) goto label_0006938B;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6938Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6938Bu));
    label_0006938B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_grass_runtime.model_handles.capacity) goto label_0006939F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6939Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6939Fu));
    label_0006939F:
    cpu->eax = g_sfera_grass_runtime.model_handles.data;
    cpu->edi = cpu->eax + (cpu->esi * 4u);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x4693A7u));
    ++cpu->esi;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x5Cu)) goto label_0006937D;
    label_000693B6:
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x6Cu) == 0u; sub_pred[3] = (int32_t)(*(uint32_t*)(cpu->esp + 0x6Cu)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x48u) = 0u;
    if ((sub_pred[0]) || (sub_pred[3])) goto label_00069D30;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x44u) = 0xFFFFFFEEu;
    label_000693E0:
    if (*(uint32_t*)(cpu->esp + 0x8Cu) != 0u) goto label_00069460;
    *(uint32_t*)(cpu->esp + 0x8Cu) = 1u;
    label_000693F5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->esi += 4u;
    label_00069405:
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if ((int32_t)cpu->edi >= (int32_t)*(uint32_t*)(cpu->esp + 0x5Cu)) goto label_0006A059;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469421u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x469421u));
    sub_pred[1] = *(uint32_t*)(cpu->eax + 0x1C8u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (sub_pred[1]) goto label_0006A04E;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    cpu->ecx = 0u;
    if ((int32_t)cpu->edx <= 0) goto label_0006944F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    (void)cpu;
    label_00069440:
    if (*(uint8_t*)(cpu->eax) == 0u) goto label_00069A48;
    ++cpu->ecx;
    ++cpu->eax;
    if ((int32_t)cpu->ecx < (int32_t)cpu->edx) goto label_00069440;
    label_0006944F:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    ++cpu->edi;
    cpu->esi += 0x2F4u;
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    goto label_00069405;
    label_00069460:
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x5Cu) == 0u; sub_pred[4] = (int32_t)(*(uint32_t*)(cpu->esp + 0x5Cu)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    if ((sub_pred[2]) || (sub_pred[4])) goto label_000693F5;
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    label_00069481:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469493u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x469493u));
    cpu->edi = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x30u) <= (int32_t)cpu->esi) goto label_0006954E;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_000694A8:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (*(uint8_t*)(cpu->edx + cpu->esi) != 0u) goto label_0006953F;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x44u) >= (int32_t)0u) goto label_000694C7;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x694C7u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x694C7u));
    label_000694C7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    if ((int32_t)cpu->eax < (int32_t)g_sfera_grass_runtime.type_records.capacity) goto label_000694DF;
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x694DFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x694DFu));
    label_000694DF:
    cpu->eax = g_sfera_grass_runtime.type_records.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx + cpu->eax + 2u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if ((cpu->edx & 0xFFFFu) != *(uint16_t*)(cpu->ecx + cpu->eax + 2u)) goto label_0006953F;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x44u) >= (int32_t)0u) goto label_0006950C;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6950Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6950Cu));
    label_0006950C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_grass_runtime.type_records.capacity) goto label_00069524;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69524u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x69524u));
    label_00069524:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->eax = g_sfera_grass_runtime.type_records.data;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0x80u))) & 0xFFu);
    if (*(uint8_t*)(cpu->edx + cpu->eax) == (cpu->ecx & 0xFFu)) goto label_00069576;
    label_0006953F:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x12u) + (uint64_t)(0u);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 0x30u)) goto label_000694A8;
    label_0006954E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x2F4u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esp + 0x5Cu)) goto label_00069481;
    goto label_000693F5;
    label_00069576:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx += cpu->esi;
    sub_pred[5] = (int32_t)(*(uint32_t*)(cpu->esp + 0x30u)) < (int32_t)(0u);
    *(uint8_t*)(cpu->edx + cpu->eax) = 1u;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ecx = cpu->esi + (cpu->esi * 8u);
    cpu->esi = cpu->edx + (cpu->ecx * 2u);
    if (!sub_pred[5]) goto label_000695A3;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x695A3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x695A3u));
    label_000695A3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    if ((int32_t)cpu->eax < (int32_t)g_sfera_grass_runtime.type_records.capacity) goto label_000695BB;
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x695BBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x695BBu));
    label_000695BB:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x2F4u);
    cpu->eax += g_sfera_grass_runtime.type_records.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 6u));
    *(uint16_t*)(cpu->eax + 6u) = (uint64_t)(*(uint16_t*)(cpu->eax + 6u)) + (uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)(0u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0xAu));
    *(uint16_t*)(cpu->eax + 0xAu) = (uint64_t)(*(uint16_t*)(cpu->eax + 0xAu)) + (uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)(0u);
    cpu->edi += *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->esp + 0xB8u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi + 0x14u;
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4695F5u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x4695F5u));
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 8u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint16_t*)(cpu->esi + 8u);
    cpu->edx = cpu->ecx + (cpu->ecx * 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->edx = cpu->ecx + (cpu->edx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x24u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469628u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x158u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x14Cu);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x15Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x160u);
    *(float*)(cpu->esp + 0x8Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0xF0u);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->edx;
    x87_v1 = (double)*(float*)(cpu->esp + 0xECu);
    cpu->edx = 0u;
    cpu->esp += 0xCu;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ecx;
    if ((cpu->edx & 0xFFFFu) >= *(uint16_t*)(cpu->esi + 0xAu)) goto label_0006974F;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0006967B:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    x87_v2 = (double)*(float*)(cpu->eax + cpu->ecx);
    cpu->eax += cpu->ecx;
    *(float*)(cpu->esp + 0x60u) = x87_v2; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    x87_v2 = (double)*(float*)(cpu->eax + 4u);
    ++cpu->edi;
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->esp + 0x80u)));
    *(float*)(cpu->esp + 0x34u) = x87_v2; 
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->eax + 8u);
    x87_v2 = (double)*(float*)(cpu->esp + 0xB8u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x60u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esp + 0xBCu);
    x87_v5 = (double)*(float*)(cpu->esp + 0x34u); x87_v6 = x87_v5;
    x87_v4 = x87_v4 * x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v2; x87_v2 = temporary; }
    x87_v4 = x87_v4 + x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0xC0u);
    x87_v6 = (double)*(float*)(cpu->esp + 0x20u); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v4; x87_v4 = temporary; }
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->esp + 0xC4u)));
    *(float*)(cpu->eax) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0xCCu);
    x87_v5 = (x87_v5) * (x87_v2);
    x87_v6 = (double)*(float*)(cpu->esp + 0xC8u);
    x87_v6 = (x87_v6) * (x87_v3);
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esp + 0xD0u);
    x87_v6 = (x87_v6) * (x87_v4);
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->esp + 0xD4u)));
    *(float*)(cpu->eax + 4u) = x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0xDCu);
    x87_v2 = x87_v2 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esp + 0xD8u);
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = x87_v1;
    x87_v2 = x87_v2 * x87_v4; 
    x87_v2 = x87_v2 + x87_v3; 
    x87_v2 = (x87_v2) + (x87_v0);
    *(float*)(cpu->eax + 8u) = x87_v2; 
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    cpu->eax = cpu->eax + cpu->ecx + 0xCu;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->ecx += 0x24u;
    if ((int32_t)cpu->edi < (int32_t)cpu->eax) goto label_0006967B;
    label_0006974F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = x87_v1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    x87_v0 = x87_v0; 
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->edx + (cpu->ecx * 4u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x1C8u);
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469787u));
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    cpu->edi = 0u;
    if ((cpu->eax & 0xFFFFu) >= *(uint16_t*)(cpu->esi + 0xAu)) goto label_000699B2;
    x87_v0 = (double)*(float*)(cpu->esp + 0xBCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x28u));
    x87_v1 = -0.15000000596046448;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(double*)(cpu->esp + 0xB0u) = x87_v1;
     x87_v1 = (double)*(float*)(cpu->esp + 0xCCu);
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(double*)(cpu->esp + 0x98u) = x87_v1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0xDCu)));
    cpu->edx = cpu->eax * 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += 8u;
    *(double*)(cpu->esp + 0x90u) = x87_v0;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_00069806:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0xCu) >= (int32_t)0u) goto label_0006981B;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469817u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x469817u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_0006981B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_grass_runtime.model_handles.capacity) goto label_00069837;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469833u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x469833u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00069837:
    cpu->edx = g_sfera_grass_runtime.model_handles.data;
    x87_v0 = (double)*(float*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x80u)));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx + (cpu->ecx * 4u)));
    *(uint16_t*)(cpu->eax + 0xFFFFFFFAu) = (uint64_t)(*(uint16_t*)(cpu->eax + 0xFFFFFFFAu)) + (uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)(0u);
    sub_pred[6] = (int32_t)(*(uint32_t*)(cpu->esp + 0x14u)) < (int32_t)(0u);
    *(float*)(cpu->eax) = x87_v0; 
    if (!sub_pred[6]) goto label_00069865;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69865u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x69865u));
    label_00069865:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->eax < (int32_t)g_sfera_grass_runtime.instance_indices.capacity) goto label_0006987D;
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6987Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6987Du));
    label_0006987D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = g_sfera_grass_runtime.instance_indices.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edx + cpu->ecx) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->esi + 8u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)(cpu->eax) >= 0) goto label_000698AC;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4698A8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x4698A8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000698AC:
    if ((int32_t)cpu->eax < (int32_t)g_sfera_grass_runtime.instance_offsets.capacity) goto label_000698C6;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4698C2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x4698C2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000698C6:
    cpu->ecx = g_sfera_grass_runtime.instance_offsets.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) = cpu->edx;
    cpu->eax = *(uint16_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->eax += cpu->edi;
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->ecx = cpu->edx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1CCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    x87_v0 = (double)*(float*)(cpu->ecx);
    cpu->eax = cpu->eax + cpu->edx + 0x18u;
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(4u) + (uint64_t)(0u);
    ++*(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->eax) = x87_v0; 
    ++cpu->edi;
    x87_v0 = (double)-0.15000000596046448f;
    cpu->edx += 0x24u;
    *(float*)(cpu->eax + 4u) = x87_v0; 
    *(float*)(cpu->esp + 0x60u) = (double)*(float*)(cpu->eax);
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->ecx + 8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->edx;
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0xB8u)));
    x87_v1 = (x87_v1) + (*(double*)(cpu->esp + 0xB0u));
    x87_v2 = (double)*(float*)(cpu->esp + 0xC0u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x1Cu); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    x87_v2 = x87_v2 + x87_v3; 
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0xC4u)));
    *(float*)(cpu->eax) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0xC8u);
    x87_v2 = (x87_v2) * (x87_v0);
    x87_v2 = (x87_v2) + (*(double*)(cpu->esp + 0x98u));
    x87_v3 = (double)*(float*)(cpu->esp + 0xD0u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v2 = x87_v2 + x87_v3; 
    x87_v2 = (x87_v2) + (((double)*(float*)(cpu->esp + 0xD4u)));
    *(float*)(cpu->eax + 4u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0xD8u);
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v1 = (x87_v1) + (*(double*)(cpu->esp + 0x90u));
    x87_v2 = (double)*(float*)(cpu->esp + 0xE0u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0xE4u)));
    *(float*)(cpu->eax + 8u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->eax += 0xCu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->edi < (int32_t)cpu->ecx) goto label_00069806;
    label_000699B2:
    cpu->eax = *(uint16_t*)(cpu->esi + 6u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint16_t*)(cpu->esi + 4u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->edi = cpu->edi + (cpu->edi * 2u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->edi += cpu->edi;
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4699E1u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = 0u;
    cpu->esp += 0xCu;
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    if ((cpu->edx & 0xFFFFu) >= *(uint16_t*)(cpu->esi + 6u)) goto label_00069A31;
    label_00069A02:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = cpu->ecx;
    cpu->edi -= cpu->edx;
    *(uint16_t*)(cpu->eax) = (uint64_t)(*(uint16_t*)(cpu->eax)) + (uint64_t)((cpu->edi & 0xFFFFu)) + (uint64_t)(0u);
    cpu->edi = cpu->ecx;
    cpu->edi -= cpu->edx;
    *(uint16_t*)(cpu->eax + 2u) = (uint64_t)(*(uint16_t*)(cpu->eax + 2u)) + (uint64_t)((cpu->edi & 0xFFFFu)) + (uint64_t)(0u);
    cpu->edi = cpu->ecx;
    cpu->edi -= cpu->edx;
    *(uint16_t*)(cpu->eax + 4u) = (uint64_t)(*(uint16_t*)(cpu->eax + 4u)) + (uint64_t)((cpu->edi & 0xFFFFu)) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = *(uint16_t*)(cpu->esi + 6u);
    ++cpu->edx;
    cpu->eax += 0xCu;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)cpu->edi) goto label_00069A02;
    label_00069A31:
    cpu->eax = *(uint16_t*)(cpu->esi + 6u);
    cpu->edx = *(uint16_t*)(cpu->esi + 0xAu);
    *(uint32_t*)(cpu->esp + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x4Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    goto label_00069D1D;
    label_00069A48:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu));
    cpu->eax += cpu->ecx;
    *(uint8_t*)(cpu->eax + cpu->edx) = 1u;
    cpu->eax = cpu->ecx + (cpu->ecx * 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    cpu->esi = cpu->edx + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469A75u)); sfera_sub_00451D90(cpu, LIFT_CODE_TOKEN_VA(0x469A75u));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x2F4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    cpu->edi += *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0x80u))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint16_t*)(cpu->esi + 2u);
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x4Cu);
    *(uint16_t*)(cpu->eax + 2u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->esp + 0x24u);
    *(uint16_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + 8u) = cpu->edx & 0xFFFFu;
    cpu->ecx = *(uint16_t*)(cpu->esi + 6u);
    *(uint16_t*)(cpu->eax + 6u) = cpu->ecx & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax + 0xEu) = cpu->ecx;
    cpu->ecx = cpu->esp + 0xB8u;
    *(uint16_t*)(cpu->eax + 0xAu) = cpu->edx & 0xFFFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x14u;
    cpu->ecx = cpu->edi + 8u;
    *(uint8_t*)(cpu->eax + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469ACBu)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x469ACBu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint16_t*)(cpu->esi + 8u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x24u);
    cpu->eax = cpu->eax + (cpu->eax * 8u);
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x24u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->ecx;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469AFEu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x158u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x15Cu);
    x87_v0 = (double)*(float*)(cpu->edi + 0x14Cu);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x160u);
    *(float*)(cpu->esp + 0x8Cu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x60u) = 0u;
    if ((cpu->eax & 0xFFFFu) >= *(uint16_t*)(cpu->esi + 0xAu)) goto label_00069B96;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00069B48:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x24u);
    x87_v0 = (double)*(float*)(cpu->edx + cpu->edi + 4u);
    cpu->edx += cpu->edi;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x80u)));
    cpu->ecx = cpu->esp + 0xB8u;
    *(float*)(cpu->edx + 4u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469B67u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x469B67u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->eax = cpu->ecx + cpu->edi + 0xCu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    ++cpu->eax;
    cpu->edi += 0x24u;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_00069B48;
    label_00069B96:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->edi = cpu->eax + (cpu->edx * 4u);
    cpu->eax = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint16_t*)(cpu->esi + 8u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1C8u);
    cpu->edx = cpu->ecx + (cpu->edx * 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469BC6u));
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((cpu->eax & 0xFFFFu) >= *(uint16_t*)(cpu->esi + 0xAu)) goto label_00069CBB;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x28u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->edi += 8u;
    label_00069C00:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.model_handles.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469C0Fu)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x469C0Fu));
    x87_v0 = (double)*(float*)(cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax));
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x80u)));
    *(uint16_t*)(cpu->edi + 0xFFFFFFFAu) = (uint64_t)(*(uint16_t*)(cpu->edi + 0xFFFFFFFAu)) + (uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->edi) = x87_v0; 
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_indices.data;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469C38u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x469C38u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint16_t*)(cpu->esi + 8u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_offsets.data;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469C55u)); sfera_sub_0041C1F0(cpu, LIFT_CODE_TOKEN_VA(0x469C55u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint16_t*)(cpu->esi + 8u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x24u);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->edx * 4u));
    cpu->eax = cpu->ecx + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x1CCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->ecx + cpu->edx + 0x18u;
    *(float*)(cpu->edx) = x87_v0; 
    cpu->ecx = cpu->esp + 0xB8u;
    *(float*)(cpu->edx + 4u) = (double)-0.15000000596046448f;
    *(float*)(cpu->edx + 8u) = (double)*(float*)(cpu->eax + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469C9Eu)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x469C9Eu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->esi + 0xAu);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->edi += 0xCu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_00069C00;
    label_00069CBB:
    cpu->eax = *(uint16_t*)(cpu->esi + 6u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x2Cu);
    cpu->ecx = cpu->eax + (cpu->ecx * 4u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + (cpu->edi * 2u);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469CE7u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint16_t*)(cpu->esi + 0xAu);
    cpu->edx = *(uint16_t*)(cpu->esi + 6u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esp + 0x44u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x44u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x3Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->edi += cpu->edx;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x44u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x44u)) + (uint64_t)(0x12u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edi;
    label_00069D1D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esp + 0x6Cu)) goto label_000693E0;
    label_00069D30:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, 0x44D9u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469D43u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x469D43u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->esi = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_00069FC7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    label_00069D59:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = 0xFDE8u;
    if (*(uint16_t*)(cpu->edx) >= (cpu->ecx & 0xFFFFu)) goto label_00069DD3;
    if ((int32_t)cpu->esi >= 0) goto label_00069D75;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69D75u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x69D75u));
    label_00069D75:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_grass_runtime.instance_indices.capacity) goto label_00069D89;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69D89u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x69D89u));
    label_00069D89:
    cpu->eax = g_sfera_grass_runtime.instance_indices.data;
    cpu->edi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x28u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint16_t*)(cpu->ecx);
    if ((int32_t)(cpu->edi += cpu->edx) >= 0) goto label_00069DAB;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69DABu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x69DABu));
    label_00069DAB:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_grass_runtime.instance_offsets.capacity) goto label_00069DBF;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69DBFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x69DBFu));
    label_00069DBF:
    cpu->eax = g_sfera_grass_runtime.instance_offsets.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax + (cpu->edi * 4u)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint16_t*)(cpu->edx) = cpu->ecx & 0xFFFFu;
    label_00069DD3:
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_00069D59;
    if ((int32_t)cpu->eax <= 0) goto label_00069FC7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x68u);
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    label_00069DFD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint16_t*)(cpu->edx);
    cpu->eax = 0xFDE8u;
    if ((cpu->ecx & 0xFFFFu) >= (cpu->eax & 0xFFFFu)) goto label_00069FB3;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    x87_v1 = (double)*(float*)(cpu->edi + cpu->eax);
    cpu->ecx = cpu->ecx + (cpu->ecx * 8u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + (cpu->ecx * 4u))));
    cpu->ecx = cpu->eax + (cpu->ecx * 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x1CCu);
    cpu->esi += cpu->edi;
    *(float*)(cpu->esp + 0x50u) = x87_v1; 
    *(float*)(cpu->esp + 0x54u) = ((((double)*(float*)(cpu->edi + cpu->eax + 4u))) - (((double)*(float*)(cpu->ecx + 4u))));
    *(float*)(cpu->esp + 0x58u) = ((((double)*(float*)(cpu->edi + cpu->eax + 8u))) - (((double)*(float*)(cpu->ecx + 8u))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x58u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(double*)(cpu->esp + 0xB0u) = x87_v1;
    x87_v2 = (double)*(float*)(cpu->esp + 0x54u); x87_v3 = x87_v2;
    *(double*)(cpu->esp + 0x80u) = x87_v3;
    x87_v3 = (x87_v1) - (x87_v3);
    *(float*)(cpu->esp + 0x74u) = x87_v3; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    x87_v4 = x87_v3;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v1 = x87_v4 - x87_v1; 
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x78u) = x87_v3; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    x87_v2 = (x87_v2) * (x87_v0);
    *(double*)(cpu->esp + 0x98u) = x87_v2;
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(double*)(cpu->esp + 0x60u) = x87_v1;
    x87_v0 = x87_v0 - x87_v1; 
    *(float*)(cpu->esp + 0x7Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    x87_v1 = (double)*(float*)(cpu->esi);
    x87_v2 = (double)*(float*)(cpu->esi + 8u);
    x87_v3 = (double)*(float*)(cpu->edx + 8u);
    *(double*)(cpu->esp + 0x90u) = x87_v3;
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x18u) = ((*(double*)(cpu->esp + 0x90u)) / (((double)*(float*)(cpu->esp + 0x18u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi)));
    *(float*)(cpu->esi) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esi + 4u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 8u)));
    *(float*)(cpu->esi + 8u) = x87_v0; 
    *(float*)(cpu->esp + 0xA4u) = (((*(double*)(cpu->esp + 0x98u))) - (*(double*)(cpu->esp + 0xB0u)));
    x87_v0 = (double)*(float*)(cpu->esp + 0x58u);
    x87_v1 = *(double*)(cpu->esp + 0x60u);
    x87_v0 = (x87_v0) - (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xA8u) = x87_v1; 
    x87_v0 = (x87_v0) - (*(double*)(cpu->esp + 0x80u));
    *(float*)(cpu->esp + 0xACu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xA4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xA8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xACu);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esi + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esi + 0xCu);
    x87_v2 = (double)*(float*)(cpu->esi + 0x14u);
    x87_v3 = (double)*(float*)(cpu->eax + 8u);
    *(double*)(cpu->esp + 0x90u) = x87_v3;
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x18u) = ((*(double*)(cpu->esp + 0x90u)) / (((double)*(float*)(cpu->esp + 0x18u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0xCu)));
    *(float*)(cpu->esi + 0xCu) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x10u)));
    *(float*)(cpu->esi + 0x10u) = x87_v1; 
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    x87_v0 = 0.0;
    label_00069FB3:
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    cpu->edi += 0x24u;
    if ((--*(uint32_t*)(cpu->esp + 0x48u)) != 0u) goto label_00069DFD;
    x87_v0 = x87_v0; 
    label_00069FC7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    lift_push32(cpu, 0x44F0u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->ebx + 0x30u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x469FE2u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x469FE2u));
    cpu->esi = 0u;
    *(uint32_t*)(cpu->ebx + 0x34u) = cpu->eax;
    if ((int32_t)g_sfera_grass_runtime.type_records.capacity > (int32_t)cpu->esi) goto label_00069FFB;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x69FFBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x69FFBu));
    label_00069FFB:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x30u);
    cpu->edx = g_sfera_grass_runtime.type_records.data;
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x34u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46A00Fu));
    *(float*)(cpu->ebx + 0x1B0u) = (double)(0.0);
    cpu->esp += 0xCu;
    x87_v0 = 1.0;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0x44u) = cpu->esi;
    *(float*)(cpu->ebx + 0x1B4u) = x87_v0;
    *(uint32_t*)(cpu->ebx + 0x1BCu) = cpu->esi;
    *(float*)(cpu->ebx + 0x1B8u) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ebx + 0x40u) = 0u;
    *(uint8_t*)(cpu->ebx + 0x50u) = 0u;
    *(uint32_t*)(cpu->ebx + 0x6Cu) = 3u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0006A04E:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"dg_type parameter not filled in mdlprms.txt for model  %s");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A059u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_RVA(0x6A059u));
    label_0006A059:
    cpu->ecx = (uintptr_t)"fatal error 58289563485";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46A063u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x46A063u));
    lift_trap(cpu, 0x46A063u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0046A070(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x214u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == cpu->esi) goto label_0006B7AD;
    if ((int32_t)cpu->eax <= (int32_t)1u) goto label_0006A0AB;
    cpu->edx = cpu->eax + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A0ABu)); sfera_sub_004564A0(cpu, LIFT_CODE_TOKEN_RVA(0x6A0ABu));
    label_0006A0AB:
    cpu->edi = 0u;
    g_sfera_window_runtime.landscape_grid_count = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04 <= (int32_t)cpu->esi) goto label_0006A1D2;
    label_0006A0C3:
    if ((int32_t)cpu->esi >= 0) goto label_0006A0D1;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A0D1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A0D1u));
    label_0006A0D1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_0006A0E5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A0E5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A0E5u));
    label_0006A0E5:
    cpu->eax = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x74u);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->eax + 0xCu);
    if ((int32_t)cpu->esi >= 0) goto label_0006A101;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A101u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A101u));
    label_0006A101:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_0006A115;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A115u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A115u));
    label_0006A115:
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edi = *(uint32_t*)(cpu->edi + cpu->ecx + 0x10u);
    if (cpu->esi != 0u) goto label_0006A130;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    goto label_0006A1BF;
    label_0006A130:
    if (cpu->ebx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0006A140;
    if (cpu->edi == *(uint32_t*)(cpu->esp + 0x20u)) goto label_0006A1BF;
    label_0006A140:
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)cpu->edi >= 0) goto label_0006A15C;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A15Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A15Cu));
    label_0006A15C:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.render_ranges.capacity) goto label_0006A170;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A170u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A170u));
    label_0006A170:
    cpu->edx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edx + (cpu->edi * 8u)) = cpu->eax;
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    if ((int32_t)cpu->edi >= 0) goto label_0006A191;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A191u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A191u));
    label_0006A191:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.render_ranges.capacity) goto label_0006A1A5;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A1A5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A1A5u));
    label_0006A1A5:
    cpu->edx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->ecx = cpu->esi;
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->edx + (cpu->edi * 8u) + 4u) = cpu->ecx;
    ++g_sfera_window_runtime.landscape_grid_count;
    label_0006A1BF:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04) goto label_0006A0C3;
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    label_0006A1D2:
    if ((int32_t)cpu->edi >= 0) goto label_0006A1E0;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A1E0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A1E0u));
    label_0006A1E0:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.render_ranges.capacity) goto label_0006A1F4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A1F4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A1F4u));
    label_0006A1F4:
    cpu->eax = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u)) = cpu->ecx;
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    if ((int32_t)cpu->edi >= 0) goto label_0006A214;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A214u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A214u));
    label_0006A214:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.render_ranges.capacity) goto label_0006A228;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A228u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A228u));
    label_0006A228:
    x87_v0 = 0.0;
    cpu->edx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->esi -= *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edx + (cpu->edi * 8u) + 4u) = cpu->esi;
    *(float*)(cpu->esp + 0xF8u) = x87_v0;
    cpu->eax = 0x5F317777u;
    *(float*)(cpu->esp + 0xF4u) = x87_v0;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3030)) & 0xFFFFu);
    *(float*)(cpu->esp + 0xF0u) = x87_v0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(float*)(cpu->esp + 0xECu) = x87_v0;
    ++g_sfera_window_runtime.landscape_grid_count;
    *(float*)(cpu->esp + 0xE4u) = x87_v0;
    *(float*)(cpu->esp + 0xE0u) = x87_v0;
    *(uint32_t*)(cpu->esp + 0x214u) = cpu->eax;
    *(float*)(cpu->esp + 0xDCu) = x87_v0;
    cpu->eax = cpu->esp + 0xC0u;
    *(float*)(cpu->esp + 0xD8u) = x87_v0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0xD4u) = x87_v0;
    *(uint16_t*)(cpu->esp + 0x21Cu) = cpu->ecx & 0xFFFFu;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0xD0u) = x87_v0;
    *(float*)(cpu->esp + 0xCCu) = x87_v0;
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0xCCu) = x87_v0; 
    *(uint8_t*)(cpu->esp + 0x222u) = cpu->edx & 0xFFu;
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x104u) = x87_v0;
    *(float*)(cpu->esp + 0xF0u) = x87_v0;
    *(float*)(cpu->esp + 0xDCu) = x87_v0;
    *(float*)(cpu->esp + 0xC8u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46A2F0u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x46A2F0u));
    lift_push32(cpu, 0x40u);
    cpu->ecx = cpu->esp + 0x194u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46A2FCu));
    x87_v0 = 1.0;
    lift_push32(cpu, 0x40u);
    *(float*)(cpu->esp + 0x1C8u) = x87_v0;
    cpu->edx = cpu->esp + 0x1E0u;
    *(float*)(cpu->esp + 0x1DCu) = x87_v0; 
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46A31Du));
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x1E8u) = x87_v0;
    cpu->esp += 0x18u;
    *(float*)(cpu->esp + 0x1E4u) = x87_v0;
    *(float*)(cpu->esp + 0x1F8u) = x87_v0;
    *(float*)(cpu->esp + 0x20Cu) = x87_v0; 
    x87_v0 = 0.6000000238418579;
    x87_v0 = std::tan(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(g_sfera_graphics_runtime.display_height))))) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width)))));
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (x87_v1) / (0.75);
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::atan(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = (x87_v0) + (x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) * (0.5));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::tan(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esp + 0x190u) = (-(((0.5) / (((double)*(float*)(cpu->esp + 0x18u))))));
    *(float*)(cpu->esp + 0x14u) = ((((double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step))))) * (0.19634956121444702));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    x87_v0 = (x87_v0) * (0.003000000026077032);
    lift_push32(cpu, 0u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x1Cu);
    x87_v1 = (0.5) / (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = -x87_v0;
    *(float*)(cpu->esp + 0x1ACu) = x87_v0; 
    x87_v0 = (double)0.5f;
    *(float*)(cpu->esp + 0x1B8u) = x87_v0;
    *(float*)(cpu->esp + 0x1BCu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46A41Au)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x46A41Au));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46A429u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x46A429u));
    *(uint32_t*)(cpu->esp + 0x34u) = 0u;
    if (((uint32_t)(g_sfera_window_runtime.landscape_grid_count) == 0u) || ((int32_t)((uint32_t)(g_sfera_window_runtime.landscape_grid_count)) < (int32_t)(0u))) goto label_0006B687;
    label_0006A43E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x34u);
    if ((int32_t)cpu->edi >= 0) goto label_0006A450;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A450u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A450u));
    label_0006A450:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.render_ranges.capacity) goto label_0006A464;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A464u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A464u));
    label_0006A464:
    cpu->eax = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 8u));
    if ((int32_t)cpu->esi >= 0) goto label_0006A47A;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A47Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A47Au));
    label_0006A47A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.scene_records.capacity) goto label_0006A48E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A48Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A48Eu));
    label_0006A48E:
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    cpu->esi += g_sfera_scene_array_runtime.scene_records.data;
    cpu->ebx = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)cpu->eax <= 0) goto label_0006A4AD;
    if ((int32_t)cpu->eax < (int32_t)0xAu) goto label_0006A4BC;
    label_0006A4AD:
    cpu->edx = 0x4941u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A4BCu)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x6A4BCu));
    label_0006A4BC:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x10u);
    if ((int32_t)cpu->esi >= 0) goto label_0006A4CD;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A4CDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A4CDu));
    label_0006A4CD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006A4E1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A4E1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A4E1u));
    label_0006A4E1:
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ecx = cpu->esi + (cpu->esi * 2u);
    x87_v0 = (double)*(float*)(cpu->edx + (cpu->ecx * 8u) + 0x14u);
    cpu->esi = 0u;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_0006A500:
    if ((int32_t)cpu->edi >= 0) goto label_0006A50E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A50Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A50Eu));
    label_0006A50E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.render_ranges.capacity) goto label_0006A522;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A522u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A522u));
    label_0006A522:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = g_sfera_scene_array_runtime.render_ranges.data;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->ecx + (cpu->edi * 8u) + 4u)) goto label_0006AE24;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax += 4u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u))));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    x87_v0 = (x87_v0) * (2.3561947345733643);
    *(double*)(cpu->esp + 0x28u) = x87_v0;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v1 = (x87_v1) * (3.9269912242889404);
    *(double*)(cpu->esp + 0x70u) = x87_v1;
    x87_v2 = (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step)));
    x87_v2 = (x87_v2) * (0.19634956121444702);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A58E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A58Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A58Eu));
    label_0006A58E:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity))) goto label_0006A5A2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A5A2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A5A2u));
    label_0006A5A2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax))));
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    cpu->edi = cpu->esi;
    cpu->edi <<= 5u;
    x87_v0 = (x87_v0) * (8.333333015441895);
    *(float*)(cpu->edi + cpu->ecx) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A5D7;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A5D7u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A5D7u));
    label_0006A5D7:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A5EB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A5EBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A5EBu));
    label_0006A5EB:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (x87_v0) + (1.0);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edx + 8u)));
    *(float*)(cpu->edi + cpu->eax + 4u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A617;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A617u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A617u));
    label_0006A617:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A62B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A62Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A62Bu));
    label_0006A62B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->ecx))));
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) * (8.333333015441895);
    *(float*)(cpu->edi + cpu->edx + 8u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A64F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A64Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A64Fu));
    label_0006A64F:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A663;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A663u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A663u));
    label_0006A663:
    x87_v0 = 0.0;
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->eax + 0xCu) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A67C;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A67Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A67Cu));
    label_0006A67C:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A690;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A690u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A690u));
    label_0006A690:
    x87_v0 = (double)-1.0f;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A6AE;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A6AEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A6AEu));
    label_0006A6AE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A6C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A6C2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A6C2u));
    label_0006A6C2:
    x87_v0 = 0.0;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x14u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A6DC;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A6DCu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A6DCu));
    label_0006A6DC:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A6F0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A6F0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A6F0u));
    label_0006A6F0:
    x87_v0 = 0.0;
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->eax + 0x18u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A709;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A709u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A709u));
    label_0006A709:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A71D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A71Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A71Du));
    label_0006A71D:
    ++cpu->esi;
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0x1Cu) = x87_v0; 
    cpu->ebx = cpu->ebx + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) * (3.9269912242889404);
    *(double*)(cpu->esp + 0x68u) = x87_v0;
    x87_v1 = (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step)));
    x87_v1 = (x87_v1) * (0.19634956121444702);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v1 = (x87_v1) + (*(double*)(cpu->esp + 0x28u));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)(cpu->esi) >= 0) goto label_0006A763;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A763u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A763u));
    label_0006A763:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity))) goto label_0006A777;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A777u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A777u));
    label_0006A777:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->ebx);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    cpu->edi = cpu->esi;
    cpu->edi <<= 5u;
    x87_v0 = (x87_v0) * (8.333333015441895);
    *(float*)(cpu->edi + cpu->eax) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A7B4;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A7B4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A7B4u));
    label_0006A7B4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A7C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A7C8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A7C8u));
    label_0006A7C8:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) + (1.0);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ebx + 8u)));
    *(float*)(cpu->edi + cpu->ecx + 4u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A7F1;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A7F1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A7F1u));
    label_0006A7F1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A805;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A805u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A805u));
    label_0006A805:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->edx))));
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) * (8.333333015441895);
    *(float*)(cpu->edi + cpu->eax + 8u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A828;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A828u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A828u));
    label_0006A828:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A83C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A83Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A83Cu));
    label_0006A83C:
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0xCu) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A856;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A856u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A856u));
    label_0006A856:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A86A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A86Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A86Au));
    label_0006A86A:
    x87_v0 = (double)-1.0f;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A888;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A888u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A888u));
    label_0006A888:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A89C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A89Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A89Cu));
    label_0006A89C:
    x87_v0 = 0.0;
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->eax + 0x14u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A8B5;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A8B5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A8B5u));
    label_0006A8B5:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A8C9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A8C9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A8C9u));
    label_0006A8C9:
    x87_v0 = 1.0;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0x18u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A8E3;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A8E3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A8E3u));
    label_0006A8E3:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A8F7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A8F7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A8F7u));
    label_0006A8F7:
    ++cpu->esi;
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x1Cu) = x87_v0; 
    cpu->eax = cpu->eax + 1u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    x87_v0 = (x87_v0) * (2.3561947345733643);
    *(double*)(cpu->esp + 0x38u) = x87_v0;
    x87_v1 = (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step)));
    x87_v1 = (x87_v1) * (0.19634956121444702);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    x87_v1 = (x87_v1) + (*(double*)(cpu->esp + 0x68u));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)(cpu->esi) >= 0) goto label_0006A941;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A941u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A941u));
    label_0006A941:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity))) goto label_0006A955;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A955u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A955u));
    label_0006A955:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    cpu->edi = cpu->esi;
    cpu->edi <<= 5u;
    x87_v0 = (x87_v0) * (8.333333015441895);
    *(float*)(cpu->edi + cpu->edx) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A98F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A98Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A98Fu));
    label_0006A98F:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A9A3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A9A3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A9A3u));
    label_0006A9A3:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) + (1.0);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ebx + 8u)));
    *(float*)(cpu->edi + cpu->eax + 4u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006A9CB;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A9CBu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6A9CBu));
    label_0006A9CB:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006A9DF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6A9DFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6A9DFu));
    label_0006A9DF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    *(float*)(cpu->edi + cpu->eax + 8u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (8.333333015441895));
    if ((int32_t)cpu->esi >= 0) goto label_0006AA0B;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AA0Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AA0Bu));
    label_0006AA0B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AA1F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AA1Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AA1Fu));
    label_0006AA1F:
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0xCu) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AA39;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AA39u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AA39u));
    label_0006AA39:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AA4D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AA4Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AA4Du));
    label_0006AA4D:
    x87_v0 = (double)-1.0f;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AA6B;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AA6Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AA6Bu));
    label_0006AA6B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AA7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AA7Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AA7Fu));
    label_0006AA7F:
    x87_v0 = 0.0;
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->eax + 0x14u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AA98;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AA98u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AA98u));
    label_0006AA98:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AAAC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AAACu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AAACu));
    label_0006AAAC:
    x87_v0 = 1.0;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0x18u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AAC6;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AAC6u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AAC6u));
    label_0006AAC6:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AADA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AADAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AADAu));
    label_0006AADA:
    ++cpu->esi;
    x87_v0 = 1.0;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x1Cu) = x87_v0; 
    x87_v0 = (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step)));
    x87_v0 = (x87_v0) * (0.19634956121444702);
    x87_v1 = *(double*)(cpu->esp + 0x38u);
    x87_v1 = (x87_v1) + (*(double*)(cpu->esp + 0x70u));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)(cpu->esi) >= 0) goto label_0006AB0D;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AB0Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AB0Du));
    label_0006AB0D:
    if ((int32_t)(cpu->esi) < (int32_t)((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity))) goto label_0006AB21;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AB21u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AB21u));
    label_0006AB21:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx))));
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    cpu->edi = cpu->esi;
    cpu->edi <<= 5u;
    x87_v0 = (x87_v0) * (8.333333015441895);
    *(float*)(cpu->edi + cpu->eax) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AB51;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AB51u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AB51u));
    label_0006AB51:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AB65;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AB65u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AB65u));
    label_0006AB65:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) + (1.0);
    x87_v0 = (x87_v0) * (((double)*(float*)(cpu->esp + 0x20u)));
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ebx + 8u)));
    *(float*)(cpu->edi + cpu->ecx + 4u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AB8E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AB8Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AB8Eu));
    label_0006AB8E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006ABA2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ABA2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6ABA2u));
    label_0006ABA2:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->edi + cpu->ecx + 8u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (8.333333015441895));
    if ((int32_t)cpu->esi >= 0) goto label_0006ABCF;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ABCFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6ABCFu));
    label_0006ABCF:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006ABE3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ABE3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6ABE3u));
    label_0006ABE3:
    x87_v0 = 0.0;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0xCu) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006ABFD;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ABFDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6ABFDu));
    label_0006ABFD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AC11;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AC11u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AC11u));
    label_0006AC11:
    x87_v0 = (double)-1.0f;
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->eax + 0x10u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AC2E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AC2Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AC2Eu));
    label_0006AC2E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AC42;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AC42u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AC42u));
    label_0006AC42:
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0x14u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AC5C;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AC5Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AC5Cu));
    label_0006AC5C:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AC70;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AC70u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AC70u));
    label_0006AC70:
    x87_v0 = 0.0;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x18u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006AC8A;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AC8Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AC8Au));
    label_0006AC8A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006AC9E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AC9Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AC9Eu));
    label_0006AC9E:
    x87_v0 = 1.0;
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->eax + 0x1Cu) = x87_v0; 
    ++cpu->esi;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0006ACC5;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ACC5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6ACC5u));
    label_0006ACC5:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006ACD9;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ACD9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6ACD9u));
    label_0006ACD9:
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = cpu->esi + 0xFFFFFFFCu;
    *(uint16_t*)(cpu->edx + (cpu->edi * 2u)) = cpu->ecx & 0xFFFFu;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0006AD01;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AD01u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AD01u));
    label_0006AD01:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006AD15;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AD15u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AD15u));
    label_0006AD15:
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ebx = cpu->esi + 0xFFFFFFFDu;
    *(uint16_t*)(cpu->eax + (cpu->edi * 2u)) = cpu->ebx & 0xFFFFu;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0006AD3C;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AD3Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AD3Cu));
    label_0006AD3C:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006AD50;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AD50u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AD50u));
    label_0006AD50:
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint16_t*)(cpu->ecx + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0006AD78;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AD78u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AD78u));
    label_0006AD78:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006AD8C;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AD8Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AD8Cu));
    label_0006AD8C:
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    *(uint16_t*)(cpu->edx + (cpu->edi * 2u)) = cpu->ebx & 0xFFFFu;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0006ADB1;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ADB1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6ADB1u));
    label_0006ADB1:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006ADC5;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ADC5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6ADC5u));
    label_0006ADC5:
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->eax = cpu->esi + 0xFFFFFFFEu;
    *(uint16_t*)(cpu->ecx + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0006ADED;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6ADEDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6ADEDu));
    label_0006ADED:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006AE01;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AE01u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AE01u));
    label_0006AE01:
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(0x74u) + (uint64_t)(0u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint16_t*)(cpu->edx + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x34u);
    goto label_0006A500;
    label_0006AE24:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xCu);
    cpu->edx = cpu->ebx + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AE2Fu)); sfera_sub_004689E0(cpu, LIFT_CODE_TOKEN_VA(0x46AE2Fu));
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    if ((int32_t)cpu->edi >= 0) goto label_0006AE40;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AE40u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AE40u));
    label_0006AE40:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006AE54;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AE54u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AE54u));
    label_0006AE54:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + (cpu->eax * 8u)));
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x216u) = cpu->edx & 0xFFu;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->ecx = 0xAu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xBu); lift_push32(cpu, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x224u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x225u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AEA0u)); sfera_sub_004D8F90(cpu, LIFT_CODE_TOKEN_VA(0x46AEA0u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AEB1u)); sfera_sub_004D8F90(cpu, LIFT_CODE_TOKEN_VA(0x46AEB1u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->edx = cpu->esp + 0x1D0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AEC6u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x46AEC6u));
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    x87_v0 = -x87_v0;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    *(float*)(cpu->esp + 0x50u) = x87_v0; 
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    x87_v0 = -x87_v0;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x60u) = x87_v0; 
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = -x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(float*)(cpu->esp + 0x64u) = x87_v0; 
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AF27u)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x46AF27u));
    cpu->ecx = cpu->esp + 0x214u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AF33u)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x46AF33u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AF41u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46AF41u));
    cpu->ecx = cpu->esp + 0x214u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AF4Du)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_VA(0x46AF4Du));
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    if ((int32_t)cpu->edi >= 0) goto label_0006AF5E;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AF5Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6AF5Eu));
    label_0006AF5E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006AF72;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6AF72u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6AF72u));
    label_0006AF72:
    lift_push32(cpu, 0x44u);
    cpu->eax = cpu->esp + 0x104u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46AF7Eu));
    x87_v0 = 1.0;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->esp + 0x10Cu) = x87_v0;
    *(float*)(cpu->esp + 0x110u) = x87_v0;
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    *(float*)(cpu->esp + 0x114u) = x87_v0;
    cpu->esp += 0xCu;
    x87_v1 = (double)*(float*)(cpu->edx + (cpu->ecx * 8u) + 8u);
    cpu->eax = cpu->esp + 0x100u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x10Cu) = x87_v1; 
    x87_v1 = 0.0;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x124u) = x87_v1;
    *(float*)(cpu->esp + 0x128u) = x87_v1;
    *(float*)(cpu->esp + 0x12Cu) = x87_v1;
    *(float*)(cpu->esp + 0x144u) = x87_v1; 
    *(float*)(cpu->esp + 0x114u) = x87_v0;
    *(float*)(cpu->esp + 0x118u) = x87_v0;
    *(float*)(cpu->esp + 0x11Cu) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46AFF7u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x46AFF7u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x112u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B007u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x46B007u));
    if ((int32_t)g_sfera_light_runtime.cell_light_ids.capacity > (int32_t)0u) goto label_0006B01C;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B01Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B01Cu));
    label_0006B01C:
    cpu->edi = g_sfera_light_runtime.cell_light_ids.data;
    if (((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity) != 0u) && ((int32_t)((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) >= (int32_t)(0u))) goto label_0006B037;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B037u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B037u));
    label_0006B037:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x14u); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B058u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x46B058u));
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    label_0006B064:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x34u) >= (int32_t)0u) goto label_0006B075;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B075u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B075u));
    label_0006B075:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if ((int32_t)cpu->eax < (int32_t)g_sfera_scene_array_runtime.render_ranges.capacity) goto label_0006B08D;
    cpu->edx = cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B08Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B08Du));
    label_0006B08D:
    cpu->ecx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u)) goto label_0006B2B1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    cpu->ebx += 0x2710u;
    cpu->ebx&=0x80000003u;
    if (((cpu->ebx)&0x80000000u)==0u) goto label_0006B0BE;
    --cpu->ebx;
    cpu->ebx |= 0xFFFFFFFCu;
    ++cpu->ebx;
    label_0006B0BE:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax += 0x2710u;
    cpu->eax&=0x80000003u; lift_test[0]=((cpu->eax)&0x80000000u)!=0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    if (!lift_test[0]) goto label_0006B0D6;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFCu;
    ++cpu->eax;
    label_0006B0D6:
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0006B0E8;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B0E8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B0E8u));
    label_0006B0E8:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B0FC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B0FCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B0FCu));
    label_0006B0FC:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u))));
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) * (0.25);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->edi + cpu->ecx + 0x18u) = (double)*(float*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->esi >= 0) goto label_0006B126;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B126u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B126u));
    label_0006B126:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B13A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B13Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B13Au));
    label_0006B13A:
    ++cpu->esi;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    x87_v0 = (x87_v0) * (0.25);
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    *(float*)(cpu->edi + cpu->edx + 0x1Cu) = (double)*(float*)(cpu->esp + 0x38u);
    if ((int32_t)(cpu->esi) >= 0) goto label_0006B163;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B163u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B163u));
    label_0006B163:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B177;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B177u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B177u));
    label_0006B177:
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(float*)(cpu->esp + 0x18u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (0.25));
    *(float*)(cpu->edi + cpu->eax + 0x38u) = (double)*(float*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->esi >= 0) goto label_0006B1A5;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B1A5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B1A5u));
    label_0006B1A5:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B1B9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B1B9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B1B9u));
    label_0006B1B9:
    ++cpu->esi;
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->ecx + 0x3Cu) = x87_v0; 
    if ((int32_t)(cpu->esi) >= 0) goto label_0006B1D4;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B1D4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B1D4u));
    label_0006B1D4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B1E8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B1E8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B1E8u));
    label_0006B1E8:
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x58u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006B204;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B204u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B204u));
    label_0006B204:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B218;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B218u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B218u));
    label_0006B218:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->eax;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0x38u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x28u)))))) * (0.25));
    *(float*)(cpu->edi + cpu->ecx + 0x5Cu) = (double)*(float*)(cpu->esp + 0x38u);
    if ((int32_t)(cpu->esi) >= 0) goto label_0006B24A;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B24Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B24Au));
    label_0006B24A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B25E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B25Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B25Eu));
    label_0006B25E:
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    *(float*)(cpu->edi + cpu->edx + 0x78u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_0006B27A;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B27Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B27Au));
    label_0006B27A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_scene_array_runtime.render_work_records.capacity) goto label_0006B28E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B28Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B28Eu));
    label_0006B28E:
    x87_v0 = (double)*(float*)(cpu->esp + 0x38u);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    ++*(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->edi + cpu->eax + 0x7Cu) = x87_v0; 
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->esi;
    cpu->edi -= 0xFFFFFF80u;
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(0x74u) + (uint64_t)(0u);
    goto label_0006B064;
    label_0006B2B1:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    if ((int32_t)cpu->edi >= 0) goto label_0006B2C2;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B2C2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B2C2u));
    label_0006B2C2:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006B2D6;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B2D6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B2D6u));
    label_0006B2D6:
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = cpu->edx + (cpu->ecx * 8u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0006B2F7;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B2F7u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B2F7u));
    label_0006B2F7:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006B30B;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B30Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B30Bu));
    label_0006B30B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    if (cpu->eax == *(uint32_t*)(cpu->edx + (cpu->ecx * 8u) + 4u)) goto label_0006B3AB;
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    if ((int32_t)cpu->edi >= 0) goto label_0006B335;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B335u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B335u));
    label_0006B335:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006B349;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B349u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B349u));
    label_0006B349:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + (cpu->eax * 8u) + 4u));
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x216u) = cpu->edx & 0xFFu;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->ecx = 0xAu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->ecx = cpu->esp + 0x214u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x218u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x219u) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B391u)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x46B391u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B39Fu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46B39Fu));
    cpu->ecx = cpu->esp + 0x214u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B3ABu)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_RVA(0x6B3ABu));
    label_0006B3AB:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    if ((int32_t)cpu->edi >= 0) goto label_0006B3BC;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B3BCu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B3BCu));
    label_0006B3BC:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006B3D0;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B3D0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B3D0u));
    label_0006B3D0:
    lift_push32(cpu, 0x44u);
    cpu->edx = cpu->esp + 0x14Cu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46B3DCu));
    x87_v0 = 1.0;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->esp + 0x154u) = x87_v0;
    *(float*)(cpu->esp + 0x158u) = x87_v0;
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    *(float*)(cpu->esp + 0x15Cu) = x87_v0;
    cpu->esp += 0xCu;
    x87_v1 = (double)*(float*)(cpu->ecx + (cpu->eax * 8u) + 0xCu);
    cpu->edx = cpu->esp + 0x148u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x154u) = x87_v1; 
    x87_v1 = 0.0;
    lift_push32(cpu, cpu->edx);
    *(float*)(cpu->esp + 0x16Cu) = x87_v1;
    *(float*)(cpu->esp + 0x170u) = x87_v1;
    *(float*)(cpu->esp + 0x174u) = x87_v1;
    *(float*)(cpu->esp + 0x18Cu) = x87_v1; 
    *(float*)(cpu->esp + 0x15Cu) = x87_v0;
    *(float*)(cpu->esp + 0x160u) = x87_v0;
    *(float*)(cpu->esp + 0x164u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B455u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x46B455u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x112u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B465u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x46B465u));
    if ((int32_t)g_sfera_light_runtime.cell_light_ids.capacity > (int32_t)0u) goto label_0006B47A;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B47Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B47Au));
    label_0006B47A:
    cpu->edi = g_sfera_light_runtime.cell_light_ids.data;
    if (((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity) != 0u) && ((int32_t)((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) >= (int32_t)(0u))) goto label_0006B495;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B495u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B495u));
    label_0006B495:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x14u); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B4B5u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x46B4B5u));
    if ((int32_t)g_sfera_options_dialog_runtime.reflection_quality <= (int32_t)0u) goto label_0006B672;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x20000u); lift_push32(cpu, 0xBu); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B4D6u)); sfera_sub_004D8F90(cpu, LIFT_CODE_TOKEN_VA(0x46B4D6u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x103u); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B4EAu)); sfera_sub_004D8F90(cpu, LIFT_CODE_TOKEN_VA(0x46B4EAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->edx = cpu->esp + 0x190u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B4FFu)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x46B4FFu));
    x87_v0 = (double)255.0f;
    *(float*)(cpu->esp + 0x64u) = x87_v0;
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x6Cu) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(float*)(cpu->esp + 0x68u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    x87_v0 = 0.0;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->esp + 0x50u) = x87_v0;
    x87_v1 = 1.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(float*)(cpu->esp + 0x54u) = x87_v1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 0x64u) = x87_v0; 
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B558u)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x46B558u));
    cpu->eax = g_sfera_render_sample_runtime.active_record;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B56Eu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46B56Eu));
    cpu->edi = *(uint32_t*)(cpu->ebx + 0x10u);
    if ((int32_t)cpu->edi >= 0) goto label_0006B57F;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B57Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6B57Fu));
    label_0006B57F:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity) goto label_0006B593;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B593u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B593u));
    label_0006B593:
    lift_push32(cpu, 0x44u);
    cpu->edx = cpu->esp + 0x7Cu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46B59Cu));
    x87_v0 = 1.0;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->esp + 0x84u) = x87_v0;
    *(float*)(cpu->esp + 0x88u) = x87_v0;
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    *(float*)(cpu->esp + 0x8Cu) = x87_v0;
    cpu->esp += 0xCu;
    x87_v1 = (double)*(float*)(cpu->ecx + (cpu->eax * 8u) + 0x10u);
    cpu->edx = cpu->esp + 0x78u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x84u) = x87_v1; 
    x87_v1 = 0.0;
    lift_push32(cpu, cpu->edx);
    *(float*)(cpu->esp + 0x9Cu) = x87_v1;
    *(float*)(cpu->esp + 0xA0u) = x87_v1;
    *(float*)(cpu->esp + 0xA4u) = x87_v1;
    *(float*)(cpu->esp + 0xBCu) = x87_v1; 
    *(float*)(cpu->esp + 0x8Cu) = x87_v0;
    *(float*)(cpu->esp + 0x90u) = x87_v0;
    *(float*)(cpu->esp + 0x94u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B612u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x46B612u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x112u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B622u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x46B622u));
    if ((int32_t)g_sfera_light_runtime.cell_light_ids.capacity > (int32_t)0u) goto label_0006B637;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B637u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B637u));
    label_0006B637:
    cpu->edi = g_sfera_light_runtime.cell_light_ids.data;
    if (((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity) != 0u) && ((int32_t)((uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) >= (int32_t)(0u))) goto label_0006B652;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B652u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B652u));
    label_0006B652:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x14u); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B672u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_RVA(0x6B672u));
    label_0006B672:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_window_runtime.landscape_grid_count) goto label_0006A43E;
    label_0006B687:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B692u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x46B692u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xBu); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B6A3u)); sfera_sub_004D8F90(cpu, LIFT_CODE_TOKEN_VA(0x46B6A3u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B6B4u)); sfera_sub_004D8F90(cpu, LIFT_CODE_TOKEN_VA(0x46B6B4u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->edx = cpu->esp + 0x1D0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B6C9u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x46B6C9u));
    lift_push32(cpu, 0x44u);
    cpu->eax = cpu->esp + 0x7Cu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46B6D2u));
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x84u) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0x7Cu) = x87_v0;
    cpu->ecx = cpu->esp + 0x78u;
    *(float*)(cpu->esp + 0x80u) = x87_v0;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0x88u) = x87_v0;
    x87_v1 = 0.0;
    *(float*)(cpu->esp + 0x9Cu) = x87_v1;
    *(float*)(cpu->esp + 0xA0u) = x87_v1;
    *(float*)(cpu->esp + 0xA4u) = x87_v1;
    *(float*)(cpu->esp + 0xBCu) = x87_v1; 
    *(float*)(cpu->esp + 0x8Cu) = x87_v0;
    *(float*)(cpu->esp + 0x90u) = x87_v0;
    *(float*)(cpu->esp + 0x94u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B738u)); sfera_sub_004D8BC0(cpu, LIFT_CODE_TOKEN_VA(0x46B738u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B73Du)); sfera_sub_00468B40(cpu, LIFT_CODE_TOKEN_VA(0x46B73Du));
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    x87_v0 = -x87_v0;
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    *(float*)(cpu->esp + 0x44u) = x87_v0; 
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    x87_v0 = -x87_v0;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(float*)(cpu->esp + 0x54u) = x87_v0; 
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    x87_v0 = -x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    *(float*)(cpu->esp + 0x58u) = x87_v0; 
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B79Eu)); sfera_sub_004681A0(cpu, LIFT_CODE_TOKEN_VA(0x46B79Eu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B7ADu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_RVA(0x6B7ADu));
    label_0006B7AD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046B7D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->edi < 0) goto label_0006B998;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006B804;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B804u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B804u));
    label_0006B804:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == 0u) goto label_0006B998;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006B827;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B827u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6B827u));
    label_0006B827:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    if (cpu->esi != 0u) goto label_0006B94C;
    label_0006B838:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B83Fu)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_VA(0x46B83Fu));
    x87_v0 = (double)*(float*)(cpu->esi + 0x14Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x418u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esi + 0x158u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x414u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v3 - x87_v2; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x410u); x87_v4 = x87_v3;
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esi + 0x164u)));
    x87_v2 = x87_v2 + x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.x.f32) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esi + 0x150u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->esi + 0x15Cu);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 - x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esi + 0x168u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.y.f32) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esi + 0x154u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esi + 0x160u);
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v2 - x87_v0; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x16Cu)));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.z.f32) = x87_v0; 
    *(float*)(cpu->esi + 8u) = ((((double)*(float*)((uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.x.f32))) + (((double)*(float*)(cpu->esi + 8u))));
    *(float*)(cpu->esi + 0xCu) = ((((double)*(float*)(cpu->esi + 0xCu))) + (((double)g_sfera_scene_vector_runtime.object_position_delta.y.f32)));
    *(float*)(cpu->esi + 0x10u) = ((((double)*(float*)(cpu->esi + 0x10u))) + (((double)g_sfera_scene_vector_runtime.object_position_delta.z.f32)));
    if (cpu->edi != g_sfera_world_objects.controlled_object_handle) goto label_0006B9C0;
    if (g_sfera_graphics_runtime.render_mode_enabled != 1u) goto label_0006B9C0;
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = (double)*(float*)(cpu->esi + 8u);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = (double)*(float*)(cpu->esi + 0xCu);
    g_sfera_main_input_state_runtime.motion_accumulator = (double)*(float*)(cpu->esi + 0x10u);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32);
    x87_v1 = 333.0;
    x87_v0 = (x87_v0) + (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = x87_v1; 
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32);
    x87_v1 = (x87_v1) + (x87_v0);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = x87_v1; 
    x87_v0 = (x87_v0) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator)));
    g_sfera_main_input_state_runtime.motion_accumulator = x87_v0; 
    goto label_0006B9C0;
    label_0006B94C:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0006B838;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46B968u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x46B968u));
    if (cpu->eax != 0u) goto label_0006B971;
    cpu->eax = (uintptr_t)"<none>";
    label_0006B971:
    lift_push32(cpu, 0xC64u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46B986u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B998u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6B998u));
    label_0006B998:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0006B9A5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0006B9A5;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"move_object: wrong handle"),26u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6B9C0u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x6B9C0u));
    label_0006B9C0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BEF8u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x46BEF8u));
    std::memmove((void*)(cpu->esp + 0x90u),(void*)((uintptr_t)&g_sfera_model_coordinate_matrix.m[0][0]),64u);
    cpu->edx = (uintptr_t)&g_sfera_model_transform_scratch_matrix;
    cpu->ecx = cpu->esp + 0x90u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BF1Cu)); sfera_sub_0044B920(cpu, LIFT_CODE_TOKEN_VA(0x46BF1Cu));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(float*)(cpu->esp + 0xF4u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xE4u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0xE8u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xECu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46BFD5u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x46BFD5u));
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C061u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x46C061u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.view_matrix); lift_push32(cpu, 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C073u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x46C073u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.projection_matrix); lift_push32(cpu, 3u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C085u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x46C085u));
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
__declspec(noinline) void sfera_sub_0046C0B0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[5]; double x87_v0;
    cpu->esp -= 0x30u;
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) == 1u; sub_pred[3] = (int32_t)((uint32_t)(*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) < (int32_t)(1u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    if ((sub_pred[0]) || (sub_pred[3])) goto label_0006C0D1;
    cpu->ecx = (uintptr_t)"Activate light error N3";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C0D1u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6C0D1u));
    label_0006C0D1:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0x7530u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C0DCu)); sfera_sub_0044EFE0(cpu, LIFT_CODE_TOKEN_VA(0x46C0DCu));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_0006CB8A;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = 0x7530u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C0F1u)); sfera_sub_0044F240(cpu, LIFT_CODE_TOKEN_VA(0x46C0F1u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0006C114;
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x30u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    sfera_sub_004D8AA0(cpu, stop_address); return;
    label_0006C114:
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    cpu->ebx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)cpu->ebp > (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0006C25E;
    label_0006C130:
    if ((int32_t)cpu->ebx >= 0) goto label_0006C13E;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C13Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C13Eu));
    label_0006C13E:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006C152;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C152u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C152u));
    label_0006C152:
    cpu->edx = g_sfera_light_runtime.cell_indices.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->ebx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x1B0Cu);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x1B14u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->ecx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ebp = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    cpu->edx += cpu->eax;
    if ((int32_t)cpu->edx > (int32_t)0x7530u) goto label_0006C348;
    cpu->edx = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_0006C24B;
    cpu->eax = cpu->ebp + 8u;
    label_0006C1B0:
    x87_v0 = (double)*(float*)(cpu->eax + 0xFFFFFFF8u);
    ++*(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (x87_v0) + (((double)g_sfera_view_spatial_runtime.world_anchor.x.f32));
    ++cpu->edx;
    cpu->edi += 0x20u;
    cpu->esi += 0x1Cu;
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v0 = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    cpu->eax += 0x28u;
    x87_v0 = (x87_v0) + (((double)g_sfera_view_spatial_runtime.world_anchor.y.f32));
    *(float*)(cpu->esp + 0x34u) = x87_v0; 
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 0xFFFFFFD8u)));
    *(uint32_t*)(cpu->esi + 0xFFFFFFE4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xFFFFFFE8u) = cpu->ebp;
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esi + 0xFFFFFFECu) = cpu->ebp;
    *(uint32_t*)(cpu->edi + 0xFFFFFFE0u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->edi + 0xFFFFFFE4u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 0xFFFFFFE8u) = cpu->ebp;
    cpu->ebx = *(uint32_t*)(cpu->eax + 0xFFFFFFDCu);
    *(uint32_t*)(cpu->edi + 0xFFFFFFECu) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->eax + 0xFFFFFFE0u);
    *(uint32_t*)(cpu->edi + 0xFFFFFFF0u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->eax + 0xFFFFFFE4u);
    *(uint32_t*)(cpu->edi + 0xFFFFFFF4u) = cpu->ebx;
    *(float*)(cpu->edi + 0xFFFFFFF8u) = (double)*(float*)(cpu->eax + 0xFFFFFFE8u);
    *(float*)(cpu->edi + 0xFFFFFFFCu) = (double)*(float*)(cpu->eax + 0xFFFFFFECu);
    *(float*)(cpu->esi + 0xFFFFFFF8u) = (double)*(float*)(cpu->eax + 0xFFFFFFF0u);
    x87_v0 = (double)*(float*)(cpu->eax + 0xFFFFFFF4u);
    *(uint32_t*)(cpu->esi + 0xFFFFFFF0u) = 0xFFB4B4B4u;
    *(float*)(cpu->esi + 0xFFFFFFFCu) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0xFFFFFFF4u) = 0x323232u;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->ecx)) goto label_0006C1B0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0006C24B:
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((int32_t)cpu->ebx <= (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0006C130;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    label_0006C25E:
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C272u)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x46C272u));
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C287u)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x46C287u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    cpu->eax += 0x7530u;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    lift_push32(cpu, 0xFFFFFFu);
    cpu->eax += 0x7530u;
    lift_push32(cpu, 0x22u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C2BFu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x46C2BFu));
    cpu->esi = 0u;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)cpu->ebp > (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0006C5F6;
    label_0006C2E1:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->edi >= 0) goto label_0006C2F3;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C2F3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C2F3u));
    label_0006C2F3:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006C307;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C307u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C307u));
    label_0006C307:
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x2Cu) == 1u;
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1B0Cu);
    cpu->edx = cpu->ecx + (cpu->edx * 4u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    if (!sub_pred[1]) goto label_0006C352;
    cpu->eax = *(uint16_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    goto label_0006C43A;
    label_0006C348:
    cpu->ecx = (uintptr_t)"VB_SIZE exceed!";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C352u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6C352u));
    label_0006C352:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint16_t*)(cpu->ebp + 0x10u) == (cpu->eax & 0xFFFFu)) goto label_0006C43A;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_18 == 0u) goto label_0006C37A;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C378u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46C378u));
    goto label_0006C3A3;
    label_0006C37A:
    cpu->eax = cpu->eax & 0xFFFFu;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->edi = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].name));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C38Eu)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x46C38Eu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C39Cu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46C39Cu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C3A3u)); sfera_sub_0049A4B0(cpu, LIFT_CODE_TOKEN_RVA(0x6C3A3u));
    label_0006C3A3:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C3AAu)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x46C3AAu));
    cpu->edi = cpu->eax;
    if (((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity) != 0u) && ((int32_t)((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) >= (int32_t)(0u))) goto label_0006C3C1;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C3C1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C3C1u));
    label_0006C3C1:
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C3CCu));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C3E9u)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x46C3E9u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C422u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x46C422u));
    g_sfera_client_config_runtime.state_08 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0x10u);
    cpu->edi += cpu->ebx;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->ebx = 0u;
    label_0006C43A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x1B18u);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->edi = cpu->edx + (cpu->ecx * 2u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 8u) <= (int32_t)cpu->eax) goto label_0006C50E;
    label_0006C461:
    if ((int32_t)cpu->esi >= 0) goto label_0006C46F;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C46Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C46Fu));
    label_0006C46F:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006C483;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C483u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C483u));
    label_0006C483:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->edi));
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->esi;
    *(uint16_t*)(cpu->ecx + (cpu->esi * 2u) + 0xFFFFFFFEu) = cpu->eax & 0xFFFFu;
    if ((int32_t)(cpu->esi) >= 0) goto label_0006C4A1;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C4A1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C4A1u));
    label_0006C4A1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006C4B5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C4B5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C4B5u));
    label_0006C4B5:
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edi + 2u));
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->esi;
    *(uint16_t*)(cpu->eax + (cpu->esi * 2u) + 0xFFFFFFFEu) = cpu->edx & 0xFFFFu;
    if ((int32_t)(cpu->esi) >= 0) goto label_0006C4D3;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C4D3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C4D3u));
    label_0006C4D3:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006C4E7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C4E7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C4E7u));
    label_0006C4E7:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edi + 4u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    *(uint16_t*)(cpu->edx + (cpu->esi * 2u)) = cpu->ecx & 0xFFFFu;
    ++cpu->eax;
    ++cpu->esi;
    cpu->edi += 6u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebp + 8u)) goto label_0006C461;
    label_0006C50E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ebx += *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0006C2E1;
    if (cpu->esi == 0u) goto label_0006C5F6;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_18 == 0u) goto label_0006C549;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C547u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46C547u));
    goto label_0006C574;
    label_0006C549:
    cpu->eax = *(uint16_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->edi = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].name));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C55Fu)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x46C55Fu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C56Du)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46C56Du));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C574u)); sfera_sub_0049A4B0(cpu, LIFT_CODE_TOKEN_RVA(0x6C574u));
    label_0006C574:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C57Bu)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x46C57Bu));
    cpu->edi = cpu->eax;
    if (((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity) != 0u) && ((int32_t)((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) >= (int32_t)(0u))) goto label_0006C592;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C592u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C592u));
    label_0006C592:
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C59Du));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C5BAu)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x46C5BAu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C5F0u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x46C5F0u));
    g_sfera_client_config_runtime.state_08 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    label_0006C5F6:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C605u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x46C605u));
    if (g_sfera_main_render_runtime.secondary_render_pass != 0u) goto label_0006C758;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C621u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x46C621u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax > (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0006C758;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    label_0006C637:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->esi >= 0) goto label_0006C649;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C649u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C649u));
    label_0006C649:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006C65D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C65Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C65Du));
    label_0006C65D:
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1B0Cu);
    lift_test[0]=(*(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0x10u)&0x40000000u)==0u;
    cpu->edi = cpu->eax + (cpu->ecx * 4u);
    if (!lift_test[0]) goto label_0006C745;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x14u) <= (int32_t)cpu->ebx) goto label_0006C745;
    label_0006C6A0:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C6A9u)); sfera_sub_0045BE50(cpu, LIFT_CODE_TOKEN_VA(0x46C6A9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C6B4u)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x46C6B4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1B18u);
    cpu->edx = cpu->ecx + (cpu->edx * 2u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C6CFu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C6EBu)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x46C6EBu));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C727u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x46C727u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->edx = cpu->eax + cpu->ecx;
    cpu->eax = cpu->edx + (cpu->eax * 2u);
    ++cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = cpu->eax;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esi + 0x14u)) goto label_0006C6A0;
    label_0006C745:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0006C637;
    label_0006C758:
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].x);
    *(uint64_t*)(cpu->esp + 0x30u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx&=0xFFu;
    cpu->ecx <<= 8u;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].y);
    *(uint64_t*)(cpu->esp + 0x30u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx &= 0xFFu;
    cpu->ecx|=cpu->edx;
    cpu->ecx <<= 8u;
    x87_v0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[1].z);
    *(uint64_t*)(cpu->esp + 0x30u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax &= 0xFFu;
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x22u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C7F9u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x46C7F9u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C808u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x46C808u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_02;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C815u)); sfera_sub_0049A490(cpu, LIFT_CODE_TOKEN_VA(0x46C815u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C824u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x46C824u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C82Bu)); sfera_sub_0049A4B0(cpu, LIFT_CODE_TOKEN_VA(0x46C82Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ebp = cpu->eax;
    if ((cpu->eax != *(uint32_t*)(cpu->esp + 0x44u)) && ((int32_t)(cpu->eax) >= (int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))) goto label_0006CAC7;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax <<= 5u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    (void)cpu;
    label_0006C850:
    if ((int32_t)cpu->ebp >= 0) goto label_0006C85E;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C85Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C85Eu));
    label_0006C85E:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_indices.capacity) goto label_0006C872;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C872u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C872u));
    label_0006C872:
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x1B0Cu);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edi = cpu->edi + (cpu->eax * 4u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    if ((uint32_t)(g_sfera_recovered_static_runtime.scene_state_09) == 0u) goto label_0006C8B1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C8ACu)); sfera_sub_00456E20(cpu, LIFT_CODE_TOKEN_VA(0x46C8ACu));
    g_sfera_recovered_static_runtime.scene_state_09 = cpu->eax;
    label_0006C8B1:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->eax &= 0x3FFFFFFFu;
    if (cpu->ebp != *(uint32_t*)(cpu->esp + 0x24u)) goto label_0006C8F4;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->ebp >= 0) goto label_0006C8D1;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C8D1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C8D1u));
    label_0006C8D1:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_records.capacity) goto label_0006C8E5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C8E5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C8E5u));
    label_0006C8E5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx += g_sfera_light_runtime.cell_records.data;
    goto label_0006C9D1;
    label_0006C8F4:
    if (cpu->eax == *(uint32_t*)(cpu->esp + 0x10u)) goto label_0006C9D5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C90Bu)); sfera_sub_004689E0(cpu, LIFT_CODE_TOKEN_VA(0x46C90Bu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C912u)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x46C912u));
    cpu->edi = cpu->eax;
    if (((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity) != 0u) && ((int32_t)((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) >= (int32_t)(0u))) goto label_0006C929;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C929u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C929u));
    label_0006C929:
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C935u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C951u)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x46C951u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46C987u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x46C987u));
    g_sfera_client_config_runtime.state_08 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax &= 0x3FFFFFFFu;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->ebp >= 0) goto label_0006C9AD;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C9ADu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6C9ADu));
    label_0006C9AD:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_light_runtime.cell_records.capacity) goto label_0006C9C1;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6C9C1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6C9C1u));
    label_0006C9C1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx += g_sfera_light_runtime.cell_records.data;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->ebx = 0u;
    label_0006C9D1:
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    label_0006C9D5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x1B18u);
    cpu->edi = cpu->eax + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    sub_pred[2] = *(uint32_t*)(cpu->ecx + 8u) == 0u; sub_pred[4] = (int32_t)(*(uint32_t*)(cpu->ecx + 8u)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if ((sub_pred[2]) || (sub_pred[4])) goto label_0006CAB1;
    (void)cpu;
    label_0006CA00:
    if ((int32_t)cpu->esi >= 0) goto label_0006CA0E;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CA0Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6CA0Eu));
    label_0006CA0E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006CA22;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CA22u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6CA22u));
    label_0006CA22:
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edi));
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->esi;
    *(uint16_t*)(cpu->eax + (cpu->esi * 2u) + 0xFFFFFFFEu) = cpu->edx & 0xFFFFu;
    if ((int32_t)(cpu->esi) >= 0) goto label_0006CA3F;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CA3Fu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6CA3Fu));
    label_0006CA3F:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006CA53;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CA53u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6CA53u));
    label_0006CA53:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edi + 2u));
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->esi;
    *(uint16_t*)(cpu->edx + (cpu->esi * 2u) + 0xFFFFFFFEu) = cpu->ecx & 0xFFFFu;
    if ((int32_t)(cpu->esi) >= 0) goto label_0006CA72;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CA72u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6CA72u));
    label_0006CA72:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.cell_light_ids.capacity) goto label_0006CA86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CA86u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6CA86u));
    label_0006CA86:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->edi + 4u));
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    *(uint16_t*)(cpu->ecx + (cpu->esi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->eax;
    ++cpu->esi;
    cpu->edi += 6u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edx + 8u)) goto label_0006CA00;
    label_0006CAB1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebx += *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x60u) + (uint64_t)(0u);
    ++cpu->ebp;
    if ((int32_t)cpu->ebp <= (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0006C850;
    label_0006CAC7:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CAD4u)); sfera_sub_004689E0(cpu, LIFT_CODE_TOKEN_VA(0x46CAD4u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CADBu)); sfera_sub_0044F370(cpu, LIFT_CODE_TOKEN_VA(0x46CADBu));
    cpu->edi = cpu->eax;
    if (((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity) != 0u) && ((int32_t)((uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) >= (int32_t)(0u))) goto label_0006CAF2;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CAF2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6CAF2u));
    label_0006CAF2:
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46CAFEu));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CB1Au)); sfera_sub_004D8AE0(cpu, LIFT_CODE_TOKEN_VA(0x46CB1Au));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CB50u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x46CB50u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    g_sfera_client_config_runtime.state_08 = (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CB61u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x46CB61u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CB70u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x46CB70u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CB75u)); sfera_sub_00468B40(cpu, LIFT_CODE_TOKEN_VA(0x46CB75u));
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter <= (int32_t)1u) goto label_0006CB88;
    cpu->ecx = (uintptr_t)"Activate light error N4";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CB88u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6CB88u));
    label_0006CB88:
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0006CB8A:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046CBA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0xA8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = cpu->esp + 0x4Cu;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_0006CBD7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CBD7;
    cpu->eax = cpu->esp + 0x50u;
    --cpu->eax;
    label_0006CBE6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CBE6;
    cpu->ecx = *(uint32_t*)((uintptr_t)"_00.lnd");
    cpu->edx = *(uint32_t*)(((uintptr_t)"_00.lnd") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->eax = cpu->esp + 0x50u;
    cpu->edx = cpu->eax + 1u;
    label_0006CC06:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CC06;
    cpu->eax -= cpu->edx;
    cpu->ecx = cpu->ebx + 0x30u;
    *(uint8_t*)(cpu->esp + cpu->eax + 0x4Au) = cpu->ecx & 0xFFu;
    cpu->eax = cpu->esp + 0x50u;
    cpu->ecx = cpu->eax + 1u;
    label_0006CC20:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0006CC20;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x28u));
    cpu->eax -= cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + cpu->eax + 0x4Bu) = cpu->edx & 0xFFu;
    lift_push32(cpu, 0x431Eu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x68C0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CC48u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x46CC48u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = cpu->eax;
    cpu->eax = cpu->ebx + (cpu->ebx * 4u);
    cpu->eax = cpu->ecx + (cpu->eax * 2u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 0x8Cu) = cpu->ebp;
    cpu->eax = cpu->esi + 0x1Eu;
    cpu->edx = cpu->esp + 0x64u;
    cpu->edx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    label_0006CC70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CC70;
    cpu->eax = cpu->esp + 0x50u;
    cpu->edx = cpu->eax;
    label_0006CC80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CC80;
    cpu->edi = cpu->esp + 0x64u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0006CC90:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0006CC90;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x64u;
    cpu->ecx = cpu->eax + 1u;
    (void)cpu;
    label_0006CCB0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0006CCB0;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->esp + 0x64u;
    *(uint32_t*)(cpu->esp + cpu->eax + 0x61u) = 0x6B736Du;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CCCAu)); sfera_sub_0045A9C0(cpu, LIFT_CODE_TOKEN_VA(0x46CCCAu));
    cpu->ebx = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CCDBu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x46CCDBu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x68C0u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CCEFu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x46CCEFu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x4325u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CD0Au)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x46CD0Au));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edx = cpu->ecx + (cpu->ecx * 4u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CD23u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x46CD23u));
    lift_push32(cpu, 0x4327u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x480u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CD37u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x46CD37u));
    x87_v0 = (double)1000.0f;
    *(uint32_t*)(cpu->ebp + 0x1B1Cu) = cpu->eax;
    cpu->ecx = 0u;
    cpu->eax = 0u;
    label_0006CD47:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->eax + cpu->edx) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->edx + cpu->eax + 8u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->edx + cpu->eax + 0x10u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->eax + cpu->edx + 0x18u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x24u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->edx + cpu->eax + 0x20u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x2Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->edx + cpu->eax + 0x28u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x34u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->edx + cpu->eax + 0x30u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x3Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->edx + cpu->eax + 0x38u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(uint32_t*)(cpu->edx + cpu->eax + 0x44u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    *(float*)(cpu->edx + cpu->eax + 0x40u) = x87_v0;
    cpu->eax += 0x48u;
    if ((int32_t)cpu->eax < (int32_t)0x480u) goto label_0006CD47;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = x87_v0; 
    cpu->eax += 0x1Eu;
    cpu->edx = cpu->esp + 0x8Cu;
    *(uint32_t*)(cpu->ebp + 0x1B0Cu) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x1B10u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x1B14u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0x1B18u) = cpu->ecx;
    cpu->edx -= cpu->eax;
    label_0006CE32:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CE32;
    cpu->eax = cpu->esp + 0x50u;
    cpu->edx = cpu->eax;
    label_0006CE42:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CE42;
    cpu->edi = cpu->esp + 0x8Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0006CE53:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0006CE53;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = cpu->esp + 0x8Cu;
    cpu->edx = cpu->eax + 1u;
    label_0006CE75:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006CE75;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + cpu->eax + 0x89u) = 0x727477u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CE8Eu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x46CE8Eu));
    cpu->ecx = cpu->esp + 0x8Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CE9Au)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x46CE9Au));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CEA1u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x46CEA1u));
    if (cpu->esi == 0xFFFFFFFFu) goto label_0006CECF;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x8Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CEB4u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x46CEB4u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x480u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CEC8u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x46CEC8u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6CECFu)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_RVA(0x6CECFu));
    label_0006CECF:
    cpu->eax = cpu->ebp + 0x1Cu;
    cpu->ecx = cpu->ebp + 0x2514u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0006CEF0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x34u) = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    label_0006CF10:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    label_0006CF24:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFF8u);
    cpu->ecx = cpu->eax * 8u;
    cpu->ecx -= cpu->eax;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x4345u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CF43u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x46CF43u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFF8u);
    cpu->edx = cpu->ecx * 8u;
    cpu->edx -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46CF62u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x46CF62u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFF4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFF0u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1B1Cu);
    sub_pred[0] = *(uint32_t*)(cpu->eax + (cpu->edx * 8u) + 4u) == 0u;
    cpu->eax = cpu->eax + (cpu->edx * 8u);
    if (sub_pred[0]) goto label_0006CFB4;
    x87_v0 = (double)*(float*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->esp + 0x4Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x4Cu);
    { const double lift_left=(double)*(float*)(cpu->edi); const double lift_right=x87_v0; if (lift_left<=lift_right) goto label_0006CFB2; }
    *(float*)(cpu->edi) = x87_v0;
    *(float*)(cpu->edi + 0xCu) = x87_v0;
    *(float*)(cpu->edi + 0x30u) = x87_v0;
    *(float*)(cpu->edi + 0x3Cu) = x87_v0;
    x87_v0 = (x87_v0) * (1024.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->edi + 0x4Cu) = cpu->eax;
    goto label_0006CFB4;
    label_0006CFB2:
    x87_v0 = x87_v0; 
    label_0006CFB4:
    cpu->eax = *(uint16_t*)(cpu->esi);
    if ((cpu->eax & 0xFFFFu) != 0u) goto label_0006CFC8;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (((uint16_t)g_sfera_graphics_runtime.base_microtexture_id));
    *(uint16_t*)(cpu->esi) = cpu->ecx & 0xFFFFu;
    goto label_0006CFE4;
    label_0006CFC8:
    cpu->edx = cpu->eax;
    cpu->eax = g_sfera_client_main_scalar_runtime.state_02;
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->edx * 2u));
    cpu->ecx = 0xFFFFu;
    if ((uint16_t)(cpu->eax) == (uint16_t)(cpu->ecx)) goto label_0006D1D0;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    label_0006CFE4:
    cpu->edx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edx) goto label_0006D017;
    cpu->eax = cpu->esi + 8u;
    label_0006CFF0:
    cpu->ecx = *(uint16_t*)(cpu->eax);
    cpu->edi = g_sfera_client_main_scalar_runtime.state_02;
    cpu->ecx = *(uint16_t*)(cpu->edi + (cpu->ecx * 2u));
    cpu->edi = 0xFFFFu;
    if ((uint16_t)(cpu->ecx) == (uint16_t)(cpu->edi)) goto label_0006D201;
    *(uint16_t*)(cpu->eax) = cpu->ecx & 0xFFFFu;
    ++cpu->edx;
    cpu->eax += 2u;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_0006CFF0;
    label_0006D017:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ebx));
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_0006D234;
    cpu->edi = cpu->eax + (cpu->eax * 8u);
    cpu->edi <<= 6u;
    if (cpu->edi == 0u) goto label_0006D04F;
    lift_push32(cpu, 0x4363u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D03Eu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x46D03Eu));
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebx + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46D047u));
    cpu->esp += 0xCu;
    label_0006D04F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(0x78u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->esi += 0x30u;
    cpu->ebx = cpu->ebx + cpu->edi + 1u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)9u) goto label_0006CF24;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x1B0u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x438u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0006CF10;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x10E0u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(0x6C0u) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0006CEF0;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D0B8u)); sfera_sub_0044D830(cpu, LIFT_CODE_TOKEN_VA(0x46D0B8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D0C1u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x46D0C1u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x46D0C6u));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D0D3u)); sfera_sub_00452B60(cpu, LIFT_CODE_TOKEN_VA(0x46D0D3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D0E7u)); sfera_sub_00468E50(cpu, LIFT_CODE_TOKEN_VA(0x46D0E7u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = cpu->ebp + 0x1Eu;
    label_0006D0F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006D0F0;
    cpu->eax = cpu->esp + 0x50u;
    cpu->edx = cpu->eax;
    label_0006D100:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0006D100;
    cpu->edi = cpu->esp + 0x64u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0006D110:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0006D110;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->eax = cpu->esp + 0x64u;
    cpu->ecx = cpu->eax + 1u;
    (void)cpu;
    label_0006D130:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0006D130;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->esp + 0x64u;
    *(uint32_t*)(cpu->esp + cpu->eax + 0x61u) = 0x736464u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D14Au)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x46D14Au));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x4376u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D15Du)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x46D15Du));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x64u;
    *(uint32_t*)(cpu->ebp + (cpu->ebx * 4u) + 0x3ACu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D173u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x46D173u));
    cpu->edx = *(uint32_t*)(cpu->ebp + (cpu->ebx * 4u) + 0x3ACu);
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D184u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x46D184u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D18Bu)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x46D18Bu));
    cpu->eax = cpu->esp + 0x50u;
    cpu->ecx = cpu->eax + 1u;
    label_0006D192:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0006D192;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->esp + 0x50u;
    *(uint8_t*)(cpu->esp + cpu->eax + 0x4Cu) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D1A8u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x46D1A8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xB4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebp + (cpu->ebx * 4u) + 0x21Cu) = cpu->eax;
    ++g_sfera_recovered_static_runtime.client_state_03;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xA8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0006D1D0:
    cpu->eax = *(uint16_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax &= 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Patch %s has microtexture which not exist: name=%c%c"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46D1EEu));
    cpu->esp += 0x14u;
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D201u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6D201u));
    label_0006D201:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax &= 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Patch %s has microtexture which not exist: name=%c%c"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46D221u));
    cpu->esp += 0x14u;
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D234u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6D234u));
    label_0006D234:
    cpu->ecx = (uintptr_t)"Number of layer masks is not the same in lnd and msk";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D23Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x46D23Eu));
    lift_trap(cpu, 0x46D23Eu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0046D240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->edx + (cpu->edx * 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + (cpu->ecx * 2u);
    if (*(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x8Cu) != 0u) goto label_0006D260;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D260u)); sfera_sub_0046CBA0(cpu, LIFT_CODE_TOKEN_RVA(0x6D260u));
    label_0006D260:
    *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0x53Cu) = 0x3E8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046D270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[5]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0xCu;
    sub_pred[0] = (uint8_t)((uint64_t)(g_sfera_color_expansion_runtime.initialized)) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if (!sub_pred[0]) goto label_0006D2BF;
    x87_v0 = 31.0;
    cpu->esi = 0u;
    x87_v1 = 255.0;
    g_sfera_color_expansion_runtime.initialized = (uint8_t)(1u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_0006D29D:
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v2 = (x87_v2) / (x87_v0);
    x87_v2 = (x87_v2) * (x87_v1);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0])) = cpu->eax;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x20u) goto label_0006D29D;
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_0006D2BF:
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v1 = 0.11999999731779099;
    *(uint32_t*)(cpu->ebx) = 0u;
    x87_v0 = (x87_v0) * (x87_v1);
    *(uint32_t*)(cpu->edi) = 0u;
    x87_v2 = 100000.0;
    *(uint32_t*)(cpu->esi) = 0u;
    x87_v0 = (x87_v0) + (x87_v2);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v2); 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x24u)));
    cpu->ecx = cpu->eax + 0x4E20u;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ecx))) >> 32u);
    x87_v0 = x87_v0 + x87_v1; 
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->ebp = cpu->edx + cpu->eax + 0xFFFFD8F0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ecx = cpu->eax + 0x4E20u;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x2AAAAAABu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 1u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->edx = cpu->edx + cpu->ecx + 0xFFFFD8F0u;
    cpu->eax = 0x27u;
    cpu->ecx = cpu->ebp + 0x28u;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if (cpu->ecx > 0x4Fu) goto label_0006D68F;
    if (cpu->eax > 0x4Fu) goto label_0006D68F;
    cpu->edx = cpu->ecx + (cpu->ecx * 4u);
    cpu->edx <<= 4u;
    cpu->eax += cpu->edx;
    cpu->ecx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edx = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    cpu->ebp = cpu->edx + (cpu->edx * 4u);
    cpu->ebp = cpu->eax + (cpu->ebp * 2u);
    sub_pred[1] = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u) + 0x8Cu) == 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    if (!sub_pred[1]) goto label_0006D397;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D393u)); sfera_sub_0046CBA0(cpu, LIFT_CODE_TOKEN_VA(0x46D393u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    label_0006D397:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u) + 0x53Cu) = 0x3E8u;
    x87_v0 = (x87_v0) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u)))));
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    x87_v1 = 100.0;
    x87_v0 = (x87_v0) / (x87_v1);
    x87_v2 = 254.0;
    x87_v0 = (x87_v0) * (x87_v2);
    x87_v3 = 1.0;
    x87_v0 = (x87_v0) + (x87_v3);
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    x87_v3 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    x87_v3 = (x87_v3) - ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(float*)(cpu->esp + 0x24u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x24u);
    x87_v1 = x87_v3 / x87_v1; 
    x87_v1 = x87_v1 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ecx = cpu->eax + 0xFFFFFFFEu;
    *(uint32_t*)(cpu->esp + 0x24u) = 5u;
    label_0006D410:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx += 0xFFFFFFFEu;
    cpu->eax = cpu->ecx;
    if ((int32_t)(cpu->edx) >= 0) goto label_0006D41F;
    cpu->edx = 0u;
    goto label_0006D42C;
    label_0006D41F:
    if ((int32_t)cpu->edx <= (int32_t)0xFFu) goto label_0006D42C;
    cpu->edx = 0xFFu;
    label_0006D42C:
    if ((int32_t)cpu->ecx >= 0) goto label_0006D434;
    cpu->eax=0u;
    goto label_0006D441;
    label_0006D434:
    if ((cpu->ecx == 0xFFu) || ((int32_t)(cpu->ecx) < (int32_t)(0xFFu))) goto label_0006D441;
    cpu->eax = 0xFFu;
    label_0006D441:
    cpu->eax <<= 8u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u) + 0x3ACu);
    cpu->eax = *(uint16_t*)(cpu->edx + (cpu->eax * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx >>= 11u;
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->edx = cpu->eax;
    cpu->edx >>= 6u;
    cpu->edx &= 0x1Fu;
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax &= 0x1Fu;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    --cpu->edx;
    cpu->eax = cpu->ecx;
    if ((int32_t)(cpu->edx) >= 0) goto label_0006D49A;
    cpu->edx = 0u;
    goto label_0006D4A7;
    label_0006D49A:
    if ((int32_t)cpu->edx <= (int32_t)0xFFu) goto label_0006D4A7;
    cpu->edx = 0xFFu;
    label_0006D4A7:
    if ((int32_t)cpu->ecx >= 0) goto label_0006D4AF;
    cpu->eax=0u;
    goto label_0006D4BC;
    label_0006D4AF:
    if ((cpu->ecx == 0xFFu) || ((int32_t)(cpu->ecx) < (int32_t)(0xFFu))) goto label_0006D4BC;
    cpu->eax = 0xFFu;
    label_0006D4BC:
    cpu->eax <<= 8u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u) + 0x3ACu);
    cpu->eax = *(uint16_t*)(cpu->edx + (cpu->eax * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx >>= 11u;
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->edx = cpu->eax;
    cpu->edx >>= 6u;
    cpu->edx &= 0x1Fu;
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax &= 0x1Fu;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->eax = cpu->ecx;
    if ((int32_t)cpu->edx >= 0) goto label_0006D51A;
    cpu->edx = 0u;
    goto label_0006D52B;
    label_0006D51A:
    sub_pred[2] = cpu->edx == 0xFFu; sub_pred[4] = (int32_t)(cpu->edx) < (int32_t)(0xFFu);
    cpu->edx = 0xFFu;
    if ((!sub_pred[2]) && (!sub_pred[4])) goto label_0006D52B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0006D52B:
    if ((int32_t)cpu->ecx >= 0) goto label_0006D533;
    cpu->eax=0u;
    goto label_0006D540;
    label_0006D533:
    if ((cpu->ecx == 0xFFu) || ((int32_t)(cpu->ecx) < (int32_t)(0xFFu))) goto label_0006D540;
    cpu->eax = 0xFFu;
    label_0006D540:
    cpu->eax <<= 8u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u) + 0x3ACu);
    cpu->eax = *(uint16_t*)(cpu->edx + (cpu->eax * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx >>= 11u;
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->edx = cpu->eax;
    cpu->edx >>= 6u;
    cpu->edx &= 0x1Fu;
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax &= 0x1Fu;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->edx;
    cpu->eax = cpu->ecx;
    if ((int32_t)(cpu->edx) >= 0) goto label_0006D599;
    cpu->edx = 0u;
    goto label_0006D5A6;
    label_0006D599:
    if ((int32_t)cpu->edx <= (int32_t)0xFFu) goto label_0006D5A6;
    cpu->edx = 0xFFu;
    label_0006D5A6:
    if ((int32_t)cpu->ecx >= 0) goto label_0006D5AE;
    cpu->eax=0u;
    goto label_0006D5BB;
    label_0006D5AE:
    if ((cpu->ecx == 0xFFu) || ((int32_t)(cpu->ecx) < (int32_t)(0xFFu))) goto label_0006D5BB;
    cpu->eax = 0xFFu;
    label_0006D5BB:
    cpu->eax <<= 8u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u) + 0x3ACu);
    cpu->eax = *(uint16_t*)(cpu->ebp + (cpu->eax * 2u) + 0x20u);
    cpu->ebp = cpu->eax;
    cpu->ebp = cpu->ebp >> 11u;
    *(uint32_t*)(cpu->ebx) = cpu->ebp;
    cpu->ebp = cpu->eax;
    cpu->eax&=0x1Fu;
    cpu->ebp = cpu->ebp >> 6u;
    cpu->ebp &= 0x1Fu;
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp += 2u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = cpu->ecx;
    if ((int32_t)(cpu->ebp) >= 0) goto label_0006D616;
    cpu->ebp = 0u;
    goto label_0006D623;
    label_0006D616:
    if ((int32_t)cpu->ebp <= (int32_t)0xFFu) goto label_0006D623;
    cpu->ebp = 0xFFu;
    label_0006D623:
    if ((int32_t)cpu->ecx >= 0) goto label_0006D62B;
    cpu->eax=0u;
    goto label_0006D638;
    label_0006D62B:
    if ((cpu->ecx == 0xFFu) || ((int32_t)(cpu->ecx) < (int32_t)(0xFFu))) goto label_0006D638;
    cpu->eax = 0xFFu;
    label_0006D638:
    cpu->eax <<= 8u;
    cpu->eax += cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->ebp * 4u) + 0x3ACu);
    cpu->eax = *(uint16_t*)(cpu->edx + (cpu->eax * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx >>= 11u;
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->edx = cpu->eax;
    cpu->edx >>= 6u;
    cpu->edx &= 0x1Fu;
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax &= 0x1Fu;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->ebx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    ++cpu->ecx;
    --*(uint32_t*)(cpu->esp + 0x24u); sub_pred[3] = *(uint32_t*)(cpu->esp + 0x24u) == 0u;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    if (!sub_pred[3]) goto label_0006D410;
    label_0006D68F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0046D6A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0006D6C0;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D6C0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6D6C0u));
    label_0006D6C0:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 8u);
    x87_v0 = (x87_v0) - (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    x87_v0 = (x87_v0) / (100.0);
    x87_v0 = (x87_v0) + (1000.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edi = cpu->eax + 0xFFFFFC18u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0006D6FC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D6FCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6D6FCu));
    label_0006D6FC:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v0 = (x87_v0) - (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    x87_v0 = (x87_v0) / (100.0);
    x87_v0 = (x87_v0) + (1000.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->esi = cpu->eax + 0xFFFFFC18u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0006D73D;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D73Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6D73Du));
    label_0006D73D:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    x87_v0 = (x87_v0) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    x87_v0 = (x87_v0) / (100.0);
    x87_v0 = (x87_v0) + (1000.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ebx = cpu->eax + 0xFFFFFC18u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->ebp) goto label_0006D77E;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D77Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6D77Eu));
    label_0006D77E:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 0x10u);
    x87_v0 = (x87_v0) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y)));
    x87_v0 = (x87_v0) / (100.0);
    x87_v0 = (x87_v0) + (1000.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->eax -= 0x3E8u;
    cpu->ebp = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_0006D89D;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x64u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    label_0006D7C0:
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_0006D88B;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x64u);
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = cpu->eax;
    cpu->edi = 0x27u;
    cpu->ecx -= cpu->esi;
    cpu->ebp += 0x28u;
    cpu->edi -= cpu->esi;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0006D7F0:
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.x) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.y) = (double)(0.0);
    *(float*)((uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    if (cpu->ebp > 0x4Fu) goto label_0006D876;
    if (cpu->edi > 0x4Fu) goto label_0006D876;
    cpu->eax = cpu->ebp + (cpu->ebp * 4u);
    cpu->eax <<= 4u;
    cpu->eax += cpu->edi;
    cpu->esi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edx = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = *(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    cpu->ecx = cpu->edx + (cpu->edx * 4u);
    cpu->ebx = cpu->eax + (cpu->ecx * 2u);
    if (*(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x8Cu) != 0u) goto label_0006D84F;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6D84Fu)); sfera_sub_0046CBA0(cpu, LIFT_CODE_TOKEN_RVA(0x6D84Fu));
    label_0006D84F:
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x8Cu);
    *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x53Cu) = 0x3E8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46D866u)); sfera_sub_00454410(cpu, LIFT_CODE_TOKEN_VA(0x46D866u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0006D876:
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x64u) + (uint64_t)(0u);
    --cpu->edi;
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->ecx != 0u) goto label_0006D7F0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0006D88B:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x64u) + (uint64_t)(0u);
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_0006D7C0;
    label_0006D89D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
