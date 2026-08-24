#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

static int32_t sfera_neighbor_dx(uint32_t index) { if (index < 4u) { return index == 0u || index == 3u ? -1 : 1; } if (index == 6u) { return -1; } return index == 7u ? 1 : 0; }
static int32_t sfera_neighbor_dy(uint32_t index) { if (index < 4u) { return index < 2u ? -1 : 1; } if (index == 4u) { return 1; } return index == 5u ? -1 : 0; }

LIFT_ENTRY void LIFT_CDECL sfera_sub_00462A90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462A90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, 0x1DCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462ACAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062AE6;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462AE4u); lift_push32(cpu, r); sfera_sub_004DA590(cpu,r); if (cpu->eip != r) return; }
    goto label_00062AE8;
    label_00062AE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x462AE6u);
    cpu->eax = 0u;
    label_00062AE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x462AE8u);
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
    lift_store32(cpu->esp + 0x74u, cpu->edi);
    g_sfera_graphics_runtime.d3d9_device = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B1Eu); lift_push32(cpu, r); sfera_sub_004D9FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B29u); lift_push32(cpu, r); sfera_sub_004D8360(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_00062B76;
    cpu->edx = 0xA76u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B3Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x94u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B46u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062B62;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B60u); lift_push32(cpu, r); sfera_sub_004DA940(cpu,r); if (cpu->eip != r) return; }
    goto label_00062B64;
    label_00062B62: cpu->eip = LIFT_CODE_TOKEN_VA(0x462B62u);
    cpu->eax = 0u;
    label_00062B64: cpu->eip = LIFT_CODE_TOKEN_VA(0x462B64u);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62B76u); lift_push32(cpu, r); sfera_sub_004DAF50(cpu,r); if (cpu->eip != r) return; }
    label_00062B76: cpu->eip = LIFT_CODE_TOKEN_VA(0x462B76u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B7Bu); lift_push32(cpu, r); sfera_sub_00499C90(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B80u); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"__debug.mbc";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B8Au); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462B91u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00062B9F;
    cpu->ecx = (uint32_t)(uintptr_t)"debug\\pics\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62B9Fu); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    label_00062B9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x462B9Fu);
    cpu->ecx = (uint32_t)(uintptr_t)"landscape\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462BA9u); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(0u)) goto label_00062BBC;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_hr\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62BBCu); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    label_00062BBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x462BBCu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21)) == (uint32_t)(0u)) goto label_00062BCF;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_ph\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62BCFu); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    label_00062BCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x462BCFu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22)) == (uint32_t)(0u)) goto label_00062BE2;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_rd\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62BE2u); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    label_00062BE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x462BE2u);
    cpu->ecx = (uint32_t)(uintptr_t)"models\\textures\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462BECu); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(0u)) goto label_00062BFF;
    cpu->ecx = (uint32_t)(uintptr_t)"models_hr\\textures\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62BFFu); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    label_00062BFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x462BFFu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21)) == (uint32_t)(0u)) goto label_00062C12;
    cpu->ecx = (uint32_t)(uintptr_t)"models_ph\\textures\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62C12u); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    label_00062C12: cpu->eip = LIFT_CODE_TOKEN_VA(0x462C12u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22)) == (uint32_t)(0u)) goto label_00062C25;
    cpu->ecx = (uint32_t)(uintptr_t)"models_rd\\textures\\";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x62C25u); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    label_00062C25: cpu->eip = LIFT_CODE_TOKEN_VA(0x462C25u);
    cpu->ecx = (uint32_t)(uintptr_t)"textures\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C2Fu); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"textures\\fx\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C39u); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"textures\\emblems\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C43u); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"xadd\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C4Du); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"players\\";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C57u); lift_push32(cpu, r); sfera_sub_00499CD0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C5Cu); lift_push32(cpu, r); sfera_sub_0049A100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x89u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C6Eu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462C7Du); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x462C86u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x462C8Bu);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462CCEu); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462CE0u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462CEFu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)50.0f);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462D0Bu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)100.0f);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x25u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462D27u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_render_buffer_capacities.vertex32;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462D35u); lift_push32(cpu, r); sfera_sub_00499EF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462D3Cu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, 2u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00062D6E;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex32;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x112u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462D6Cu); lift_push32(cpu, r); sfera_sub_004DA720(cpu,r); if (cpu->eip != r) return; }
    goto label_00062D70;
    label_00062D6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x462D6Eu);
    cpu->eax = 0u;
    label_00062D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x462D70u);
    g_sfera_sky_runtime.draw_resource = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_render_buffer_capacities.vertex28;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->esp + 0x60u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462D90u); lift_push32(cpu, r); sfera_sub_00499EF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462D97u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062DD3;
    cpu->ecx = g_sfera_render_buffer_capacities.vertex28;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    lift_push32(cpu, 0u);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, 0x1C2u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, 0x200u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462DD1u); lift_push32(cpu, r); sfera_sub_004DA720(cpu,r); if (cpu->eip != r) return; }
    goto label_00062DD5;
    label_00062DD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x462DD3u);
    cpu->eax = 0u;
    label_00062DD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x462DD5u);
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    g_sfera_window_runtime.render_vertex_buffer = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462DE5u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062E14;
    cpu->ecx = g_sfera_render_buffer_capacities.index_primary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ecx);
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462E12u); lift_push32(cpu, r); sfera_sub_004DA7D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00062E16;
    label_00062E14: cpu->eip = LIFT_CODE_TOKEN_VA(0x462E14u);
    cpu->eax = 0u;
    label_00062E16: cpu->eip = LIFT_CODE_TOKEN_VA(0x462E16u);
    lift_push32(cpu, 0x18u);
    lift_store32(cpu->esp + 0x64u, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_05) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462E26u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, 5u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062E55;
    cpu->ecx = g_sfera_render_buffer_capacities.index_secondary;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x65u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ecx);
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462E53u); lift_push32(cpu, r); sfera_sub_004DA7D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00062E57;
    label_00062E55: cpu->eip = LIFT_CODE_TOKEN_VA(0x462E55u);
    cpu->eax = 0u;
    label_00062E57: cpu->eip = LIFT_CODE_TOKEN_VA(0x462E57u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, (uintptr_t)&g_sfera_client_config_runtime.state_01); lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0x68u, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462E72u); lift_push32(cpu, r); sfera_sub_004D90B0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462E90u); lift_push32(cpu, r); sfera_sub_004D87E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462E95u); lift_push32(cpu, r); sfera_sub_004617A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0xABEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462EA4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x9A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462EAEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x60u, 6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00062ED4;
    lift_push32(cpu, (uintptr_t)"Shaders\\Pixel\\"); lift_push32(cpu, (uintptr_t)"Shaders\\Vertex\\");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462ED2u); lift_push32(cpu, r); sfera_sub_004DD660(cpu,r); if (cpu->eip != r) return; }
    goto label_00062ED6;
    label_00062ED4: cpu->eip = LIFT_CODE_TOKEN_VA(0x462ED4u);
    cpu->eax = 0u;
    label_00062ED6: cpu->eip = LIFT_CODE_TOKEN_VA(0x462ED6u);
    g_sfera_d3d9_semantic_state.shader_manager = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00462F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462F00u);
    cpu->esp -= 0x14u;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00063007;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_00063007;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x24u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x62F47u), LIFT_CODE_TOKEN_RVA(0x62F45u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462F47u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007001Eu)) goto label_00062F55;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x8007000Cu)) goto label_00062F96;
    label_00062F55: cpu->eip = LIFT_CODE_TOKEN_VA(0x462F55u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x462F5Au); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->isInsideViewport(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462F63u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00062F74;
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x62F74u), LIFT_CODE_TOKEN_RVA(0x62F72u))) { return; }
    label_00062F74: cpu->eip = LIFT_CODE_TOKEN_VA(0x462F74u);
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x24u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x62F88u), LIFT_CODE_TOKEN_RVA(0x62F86u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x462F88u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007001Eu)) goto label_00063007;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007000Cu)) goto label_00063007;
    label_00062F96: cpu->eip = LIFT_CODE_TOKEN_VA(0x462F96u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = 0x88888889u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(6u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    lift_push32(cpu, 0x17u);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetSystemMetrics), LIFT_CODE_TOKEN_VA(0x462FBFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x462FC5u);
    cpu->ecx = lift_load8(cpu->esp + 0x11u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00062FF3;
    cpu->edx = lift_load8(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x80u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
    label_00062FF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x462FF3u);
    cpu->eax = lift_load8(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(6u), 32u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_00063007: cpu->eip = LIFT_CODE_TOKEN_VA(0x463007u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00463020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x463020u);
    cpu->esp -= 0x4D4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x4E8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x4E8u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    cpu->ebx = 0u;
    label_00063058: cpu->eip = LIFT_CODE_TOKEN_VA(0x463058u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00063066;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63066u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00063066: cpu->eip = LIFT_CODE_TOKEN_VA(0x463066u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0006307A;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6307Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006307A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46307Au);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u))) == (uint32_t)(0u)) goto label_00063088;
    ++cpu->ebx;
    goto label_00063058;
    label_00063088: cpu->eip = LIFT_CODE_TOKEN_VA(0x463088u);
    lift_push32(cpu, 0xBBBu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xE84u;
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4630A0u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000630B0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x630B0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000630B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4630B0u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000630C4;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x630C4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000630C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4630C4u);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = cpu->edi;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u), cpu->ebp);
    lift_store32(cpu->ebp, 0u);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000630E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4630E0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000630E0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, 0xBBEu);
    cpu->ecx = (uint32_t)(cpu->eax + 2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4630FBu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebp + 0x990u, cpu->eax);
    cpu->edx = cpu->eax;
    label_00063107: cpu->eip = LIFT_CODE_TOKEN_VA(0x463107u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00063107;
    cpu->edi = lift_load32(cpu->ebp + 0x990u);
    --cpu->edi;
    label_00063118: cpu->eip = LIFT_CODE_TOKEN_VA(0x463118u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00063118;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    lift_store16(cpu->edi, cpu->edx & 0xFFFFu);
    cpu->eax = lift_load32(cpu->ebp + 0x990u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00063158;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0006314C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6314Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006314C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46314Cu);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_0006318B;
    label_00063158: cpu->eip = LIFT_CODE_TOKEN_VA(0x463158u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00063165: cpu->eip = LIFT_CODE_TOKEN_VA(0x463165u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00063165;
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(uintptr_t)"create_text: wrong window handle";
    lift_movs32(cpu, 1u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46317Fu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x28u, 0u);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_0006318B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46318Bu);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463194u); lift_push32(cpu, r); sfera_sub_0045DC60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->ebp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    lift_store32(cpu->ebp + 4u, cpu->esi);
    lift_store32(cpu->ebp + 0x1Cu, 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000631B4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x631B4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000631B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4631B4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_000631C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x631C8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000631C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4631C8u);
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->esi + 0x6DA8u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebp + 0x28u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x6DB4u);
    lift_store32(cpu->ebp + 0xE40u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x6DB0u);
    lift_store32(cpu->ebp + 0xE44u, cpu->edx);
    lift_store32(cpu->ebp + 0xE80u, 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx)) & 0xFFu);
    cpu->edi = 0u;
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000634CD;
    cpu->ecx = (uint32_t)(cpu->ebp + 0x990u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00063220: cpu->eip = LIFT_CODE_TOKEN_VA(0x463220u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_00063269;
    cpu->eax = lift_load32(cpu->esi + 0x6DB4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x30u));
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x30u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edx)) goto label_00063244;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->edx = cpu->eax;
    label_00063244: cpu->eip = LIFT_CODE_TOKEN_VA(0x463244u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u));
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0x12Cu)) goto label_0006336F;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->ebx + 1u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x30u, 0u);
    goto label_000632BC;
    label_00063269: cpu->eip = LIFT_CODE_TOKEN_VA(0x463269u);
    cpu->ecx = lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x30u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00063288;
    cpu->ebx = lift_load32(cpu->esi + 0x6DB0u);
    cpu->ebx = lift_load32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x30u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_00063288: cpu->eip = LIFT_CODE_TOKEN_VA(0x463288u);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].defined))) != (uint32_t)(0u)) goto label_000632A8;
    cpu->eax = lift_load32(cpu->esi + 0x6DB0u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[124][0]));
    goto label_000632B8;
    label_000632A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4632A8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax += lift_load32(cpu->esi + 0x6DB0u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    label_000632B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4632B8u);
    lift_store32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x30u, (uint64_t)(lift_load32(cpu->esp + ((uint32_t)(cpu->edi) * 4u) + 0x30u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    label_000632BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4632BCu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 1u)) & 0xFFu);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00063220;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000634CD;
    if ((uint32_t)(cpu->edx) == 0u) goto label_000634CD;
    lift_store32(cpu->ebp + 0x2Cu, cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 0x6DB0u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])));
    cpu->ecx += lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x6DB4u));
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    cpu->edx += 2u;
    g_sfera_recovered_static_runtime.text_size_height = (uint32_t)(cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = cpu->ebx;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    g_sfera_input_device_runtime.process_value = (uint32_t)(cpu->ecx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x6DACu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006335A;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx -= cpu->eax;
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->eax = cpu->ebx;
    label_0006335A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46335Au);
    cpu->edx = lift_load32(cpu->esi + 0x6DACu);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (0x40u)) == 0u) goto label_00063379;
    cpu->eax -= cpu->ecx;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    cpu->ebx = cpu->eax;
    goto label_0006338B;
    label_0006336F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46336Fu);
    cpu->ecx = (uint32_t)(uintptr_t)"MNO_LINES_IN_TEXT exceeded";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63379u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00063379: cpu->eip = LIFT_CODE_TOKEN_VA(0x463379u);
    if ((uint8_t)(((cpu->edx & 0xFFu)) & (2u)) == 0u) goto label_0006338B;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->ebx -= cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    label_0006338B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46338Bu);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->eax -= lift_load32(cpu->esi + 0x1Cu);
    cpu->ecx -= lift_load32(cpu->esi + 0x24u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000633BC;
    if ((uint8_t)((lift_load8(cpu->esi + 0x6DACu)) & (4u)) == 0u) goto label_000633BC;
    cpu->ecx = cpu->eax;
    cpu->ecx -= lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_000633BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4633BCu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000633D9;
    if ((uint8_t)((lift_load8(cpu->esi + 0x6DACu)) & (8u)) == 0u) goto label_000633D9;
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->eax = cpu->ecx;
    label_000633D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4633D9u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000633F6;
    if ((uint8_t)((lift_load8(cpu->esi + 0x6DACu)) & (4u)) == 0u) goto label_000633F6;
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    lift_store32(cpu->esp + 0x10u, 0u);
    label_000633F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4633F6u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00063407;
    if ((uint8_t)((lift_load8(cpu->esi + 0x6DACu)) & (8u)) == 0u) goto label_00063407;
    cpu->eax -= cpu->ebx;
    cpu->ebx = 0u;
    label_00063407: cpu->eip = LIFT_CODE_TOKEN_VA(0x463407u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ebp + 0xCu, cpu->ecx);
    cpu->ecx = 0u;
    lift_store32(cpu->ebp + 0x10u, cpu->ebx);
    lift_store32(cpu->ebp + 0x14u, cpu->edx);
    lift_store32(cpu->ebp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00063488;
    cpu->ebp += 0x30u;
    label_00063424: cpu->eip = LIFT_CODE_TOKEN_VA(0x463424u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x6DACu)) & (0x10u)) == 0u) goto label_00063443;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax -= lift_load32(cpu->esp + ((uint32_t)(cpu->ecx) * 4u) + 0x30u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    cpu->eax += lift_load32(cpu->esi + 0x1Cu);
    goto label_0006344A;
    label_00063443: cpu->eip = LIFT_CODE_TOKEN_VA(0x463443u);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    label_0006344A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46344Au);
    lift_store32(cpu->ebp, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x6DB0u);
    cpu->eax += cpu->eax;
    cpu->edx = lift_load32(cpu->eax + cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0]));
    cpu->eax += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->edx -= lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0]));
    ++cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x6DB4u));
    cpu->edx += lift_load32(cpu->esi + 0x24u);
    cpu->ebp += 4u;
    cpu->edx += cpu->ebx;
    lift_store32(cpu->ebp + 0x4ACu, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->edi)) goto label_00063424;
    label_00063488: cpu->eip = LIFT_CODE_TOKEN_VA(0x463488u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_sample_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) + 1u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x6DACu)) & (0x20u)) == 0u) goto label_000634BE;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4634A0u); lift_push32(cpu, r); sfera_sub_00457370(cpu,r); if (cpu->eip != r) return; }
    cpu->eax |= 0xFFFFFFFFu;
    label_000634A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4634A3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4D4u;
    lift_return(cpu, 8u, stop_address); return;
    label_000634BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4634BEu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4634C7u); lift_push32(cpu, r); sfera_sub_0045EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    goto label_000634A3;
    label_000634CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4634CDu);
    cpu->ecx = (uint32_t)(uintptr_t)"Empty text created";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4634D7u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4634D7u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004634E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4634E0u);
    cpu->esp -= 0x438u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00063AE1;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00063513;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63513u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00063513: cpu->eip = LIFT_CODE_TOKEN_VA(0x463513u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00063AE1;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00063536;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63536u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00063536: cpu->eip = LIFT_CODE_TOKEN_VA(0x463536u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_000639EC;
    label_00063547: cpu->eip = LIFT_CODE_TOKEN_VA(0x463547u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x440u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463553u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x440u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46356Bu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x444u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463583u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x444u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46359Bu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x448u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4635B3u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x448u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4635CBu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 3u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 3u, (lift_x87_get(cpu, 3u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (-1.0));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.0));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4636EFu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463703u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463717u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46372Bu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46373Fu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463753u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->esi + 0x14Cu, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x150u, cpu->edx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x154u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esi + 0x158u, cpu->ecx);
    lift_store32(cpu->esi + 0x15Cu, cpu->edx);
    lift_store32(cpu->esi + 0x160u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x160u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x150u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x15Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x154u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x164u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x158u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x154u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x160u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x168u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x15Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14Cu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x158u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x150u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x16Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00063A38;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46395Bu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463979u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46398Eu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    goto label_00063A3F;
    label_000639EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4639ECu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_00063547;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463A08u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00063A11;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00063A11: cpu->eip = LIFT_CODE_TOKEN_VA(0x463A11u);
    lift_push32(cpu, 0xC85u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x463A26u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x463A2Cu);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63A38u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00063A38: cpu->eip = LIFT_CODE_TOKEN_VA(0x463A38u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00063A3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x463A3Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463A48u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463A63u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f64(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463A7Cu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x30u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463A9Du); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (1.5707964897155762) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x438u;
    lift_return(cpu, 12u, stop_address); return;
    label_00063AE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x463AE1u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    (void)cpu;
    label_00063AF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x463AF0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00063AF0;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"rotate_object: wrong handle";
    lift_movs32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463B09u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x438u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00463B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x463B30u);
    cpu->esp -= 0x434u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00063E72;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00063B63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63B63u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00063B63: cpu->eip = LIFT_CODE_TOKEN_VA(0x463B63u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00063E72;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00063B86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63B86u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00063B86: cpu->eip = LIFT_CODE_TOKEN_VA(0x463B86u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_00063E26;
    label_00063B97: cpu->eip = LIFT_CODE_TOKEN_VA(0x463B97u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2CCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00063BD1;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2D0u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00063BD1;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2D4u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00063E9C;
    label_00063BD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x463BD1u);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->esi + 0x2CCu, cpu->ecx);
    lift_store32(cpu->esi + 0x2D0u, cpu->edx);
    lift_store32(cpu->esi + 0x2D4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463BF4u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463C08u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463C1Cu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463C30u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463C44u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463C58u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 3u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 3u, (lift_x87_get(cpu, 3u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_store32(cpu->esi + 0x14Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 5u)));
    lift_store32(cpu->esi + 0x150u, cpu->edx);
    lift_store32(cpu->esi + 0x154u, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (-1.0));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.0));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi + 0x158u, cpu->ecx);
    lift_store32(cpu->esi + 0x15Cu, cpu->edx);
    lift_store32(cpu->esi + 0x160u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x160u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x150u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x15Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x154u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x164u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x158u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x154u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x160u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x168u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x15Cu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x150u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x158u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x16Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x434u;
    lift_return(cpu, 0u, stop_address); return;
    label_00063E26: cpu->eip = LIFT_CODE_TOKEN_VA(0x463E26u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_00063B97;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463E42u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00063E4B;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00063E4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x463E4Bu);
    lift_push32(cpu, 0xCE6u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x463E60u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x463E66u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63E72u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00063E72: cpu->eip = LIFT_CODE_TOKEN_VA(0x463E72u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_00063E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x463E80u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00063E80;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"recalk_orts: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463E9Bu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    label_00063E9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x463E9Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x434u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00463EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x463EC0u);
    cpu->esp -= 0x43Cu;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(0u)) goto label_00063EE9;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63EE9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00063EE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x463EE9u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00063EFD;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    goto label_00063F4B;
    label_00063EFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x463EFDu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_00063F45;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463F15u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00063F1E;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00063F1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x463F1Eu);
    lift_push32(cpu, 0xFB9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x463F33u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x463F39u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x63F45u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00063F45: cpu->eip = LIFT_CODE_TOKEN_VA(0x463F45u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->ebp = cpu->eax;
    label_00063F4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x463F4Bu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x463F52u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x150u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_scene_vector_runtime.render_scale.y.f32)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x14Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_scene_vector_runtime.render_scale.x.f32)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x154u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_scene_vector_runtime.render_scale.z.f32)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (1.100000023841858) - (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.000000093488779e-07));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.985);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00064327;
    cpu->edx = lift_load32(cpu->ebp + 0x154u);
    cpu->ecx = lift_load32(cpu->ebp + 0x150u);
    cpu->eax = lift_load32(cpu->ebp + 0x14Cu);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = g_sfera_scene_vector_runtime.render_scale.z.u32;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->ecx = g_sfera_scene_vector_runtime.render_scale.y.u32;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    cpu->eax = g_sfera_scene_vector_runtime.render_scale.x.u32;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 7u, lift_x87_get(cpu, 7u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 6u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00064134;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4640A4u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4640BFu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4640D4u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    goto label_0006413C;
    label_00064134: cpu->eip = LIFT_CODE_TOKEN_VA(0x464134u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006413C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46413Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464148u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464163u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f64(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46417Cu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x1Cu)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46419Du); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (1.5707964897155762) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 10430.37835);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4641C4u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->esi = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->esi &= 0xFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4641D9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ebx = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->ebx &= 0xFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4641EEu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x14u));
    cpu->eax &= 0xFFFFu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464201u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18u));
    cpu->edi = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->edi &= 0xFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464213u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    cpu->ebp &= 0xFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464227u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= 0xFFFFu;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->edi;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x8000u)) goto label_0006425C;
    cpu->edi += 0xFFFF8000u;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFF8000u);
    cpu->edi &= 0xFFFFu;
    cpu->ecx &= 0xFFFFu;
    cpu->ecx -= cpu->edi;
    label_0006425C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46425Cu);
    cpu->edi = cpu->ebx;
    cpu->edi -= cpu->ebp;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0x8000u)) goto label_0006427A;
    cpu->ebx = cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    goto label_00064298;
    label_0006427A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46427Au);
    cpu->ebp += 0xFFFF8000u;
    cpu->ebx += 0xFFFF8000u;
    cpu->ebp &= 0xFFFFu;
    cpu->ebx &= 0xFFFFu;
    cpu->ebx -= cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    label_00064298: cpu->eip = LIFT_CODE_TOKEN_VA(0x464298u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = cpu->esi;
    cpu->edi -= cpu->ebp;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x8000u)) goto label_000642CC;
    cpu->ebp += 0xFFFF8000u;
    cpu->edi = (uint32_t)(cpu->esi + 0xFFFF8000u);
    cpu->ebp &= 0xFFFFu;
    cpu->edi &= 0xFFFFu;
    cpu->edi -= cpu->ebp;
    label_000642CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4642CCu);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x64u)) goto label_000642F4;
    cpu->eax = cpu->ebx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x64u)) goto label_000642F4;
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x64u)) goto label_00064324;
    label_000642F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4642F4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x10u))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00064324: cpu->eip = LIFT_CODE_TOKEN_VA(0x464324u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00064327: cpu->eip = LIFT_CODE_TOKEN_VA(0x464327u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x43Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00464340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464340u);
    cpu->esp -= 0x438u;
    cpu->edx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_0006436B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6436Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006436B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46436Bu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000644E7;
    label_0006437C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46437Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x150u));
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x150u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esi + 0x14Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x168u));
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x154u))));
    cpu->edi = lift_load32(cpu->esi + 0x150u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x16Cu));
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x150u))));
    cpu->edi = lift_load32(cpu->esi + 0x154u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14Cu));
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x16Cu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x164u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x154u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x164u));
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x150u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x168u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14Cu))));
    lift_store32(cpu->esi + 0x158u, cpu->eax);
    lift_store32(cpu->esi + 0x15Cu, cpu->ecx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->esi + 0x160u, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00064533;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46445Cu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46447Au); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46448Fu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006453C;
    label_000644E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4644E7u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0006437C;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464503u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006450C;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0006450C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46450Cu);
    lift_push32(cpu, 0x185Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x464521u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464527u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64533u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00064533: cpu->eip = LIFT_CODE_TOKEN_VA(0x464533u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006453C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46453Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464549u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464564u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f64(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46457Du); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0xCu)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46459Eu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (1.5707964897155762) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->edx = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->esi + 0x2CCu, cpu->eax);
    lift_store32(cpu->esi + 0x2D0u, cpu->ecx);
    lift_store32(cpu->esi + 0x2D4u, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x438u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00464600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464600u);
    cpu->esp -= 0x428u;
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006481D;
    if ((uint32_t)(g_sfera_world_objects.controlled_object_handle) == (uint32_t)(0xFFFFFFFFu)) goto label_0006481D;
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464641u); lift_push32(cpu, r); sfera_sub_0045D4E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edx)) goto label_00064658;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64658u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064658: cpu->eip = LIFT_CODE_TOKEN_VA(0x464658u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = lift_load32(cpu->eax + 4u);
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0006467A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464675u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    label_0006467A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46467Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00064693;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46468Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    label_00064693: cpu->eip = LIFT_CODE_TOKEN_VA(0x464693u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000646AC;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x646ACu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000646AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4646ACu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_000646C0;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x646C0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000646C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4646C0u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    cpu->ebp = 1u;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->ebp;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.10000000149011612));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4646F5u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_00064709;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64709u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064709: cpu->eip = LIFT_CODE_TOKEN_VA(0x464709u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000647BF;
    label_0006471A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46471Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x150u));
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.30000001192092896));
    (*(uint32_t*)(void*)&g_sfera_saved_controlled_position.x) = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    g_sfera_saved_controlled_position.y = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_saved_controlled_position.z = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006480B;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464785u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x20u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4647AAu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x20u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00064822;
    label_000647BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4647BFu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_0006471A;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4647DBu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000647E4;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_000647E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4647E4u);
    lift_push32(cpu, 0x1915u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4647F9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4647FFu);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6480Bu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006480B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46480Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.20000000298023224));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00064822;
    label_0006481D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46481Du);
    cpu->ebp = 1u;
    label_00064822: cpu->eip = LIFT_CODE_TOKEN_VA(0x464822u);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_000648EE;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0006483E;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6483Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006483E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46483Eu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    g_sfera_client_main_scalar_runtime.state_34 = (uint32_t)(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    g_sfera_client_main_scalar_runtime.state_35 = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    g_sfera_client_main_scalar_runtime.state_36 = (uint32_t)(cpu->edx);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_00064876;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64876u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064876: cpu->eip = LIFT_CODE_TOKEN_VA(0x464876u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0]) = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x18u);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1]) = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x1Cu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2]) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000648AC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x648ACu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000648AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4648ACu);
    cpu->esi = g_sfera_world_objects.object_handles.data;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000648C6;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x648C6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000648C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4648C6u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x43Cu));
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x648EEu); lift_push32(cpu, r); sfera_sub_00464340(cpu,r); if (cpu->eip != r) return; }
    label_000648EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4648EEu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) == (uint32_t)(2u)) goto label_00064902;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13)) == (uint32_t)(0u)) goto label_00064A78;
    label_00064902: cpu->eip = LIFT_CODE_TOKEN_VA(0x464902u);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_00064916;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64916u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064916: cpu->eip = LIFT_CODE_TOKEN_VA(0x464916u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    g_sfera_client_main_scalar_runtime.state_34 = (uint32_t)(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    g_sfera_client_main_scalar_runtime.state_35 = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    g_sfera_client_main_scalar_runtime.state_36 = (uint32_t)(cpu->edx);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0006494E;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6494Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006494E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46494Eu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0]) = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x18u);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1]) = (uint32_t)(cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x1Cu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2]) = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000649D7;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00064989;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64989u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00064989: cpu->eip = LIFT_CODE_TOKEN_VA(0x464989u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0006499D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6499Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006499D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46499Du);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000649BA;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x649BAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000649BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4649BAu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    label_000649D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4649D7u);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_000649EB;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x649EBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000649EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4649EBu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1000.0));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_00064A14;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64A14u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064A14: cpu->eip = LIFT_CODE_TOKEN_VA(0x464A14u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)-4.7123894691467285f);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_00064A3A;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64A3Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064A3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x464A3Au);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)1.5707964897155762f);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store_f32(cpu->edx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_00064A60;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64A60u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064A60: cpu->eip = LIFT_CODE_TOKEN_VA(0x464A60u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)-1.5707964897155762f);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store_f32(cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64A78u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    label_00064A78: cpu->eip = LIFT_CODE_TOKEN_VA(0x464A78u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x428u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00464AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464AA0u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00064B00;
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00064B00;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00064AC9;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64AC9u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00064AC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x464AC9u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00064ADD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64ADDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064ADD: cpu->eip = LIFT_CODE_TOKEN_VA(0x464ADDu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_saved_controlled_position.x;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = g_sfera_saved_controlled_position.y;
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->ecx = g_sfera_saved_controlled_position.z;
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    label_00064B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x464B00u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(2u)) goto label_00064B12;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13)) != (uint32_t)(0u)) goto label_00064B12;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_00064B91;
    label_00064B12: cpu->eip = LIFT_CODE_TOKEN_VA(0x464B12u);
    cpu->esi = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00064B2B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64B2Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064B2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x464B2Bu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_34;
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = g_sfera_client_main_scalar_runtime.state_35;
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_36;
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00064B63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x64B63u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00064B63: cpu->eip = LIFT_CODE_TOKEN_VA(0x464B63u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0];
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1];
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2];
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_00463B30(cpu, stop_address); return;
    label_00064B91: cpu->eip = LIFT_CODE_TOKEN_VA(0x464B91u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00464BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464BA0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1F4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x208u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464BE4u); lift_push32(cpu, r); sfera_sub_00480380(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    cpu->ecx = LIFT_CALLBACK(sfera_sub_00459DC0);
    lift_store32(cpu->esp + 0x210u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464BF7u); lift_push32(cpu, r); sfera_sub_0042EBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"params";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464C01u); lift_push32(cpu, r); sfera_sub_0042F2D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"mbc";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464C0Bu); lift_push32(cpu, r); sfera_sub_0042F2D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"Error.log") + 8u)) & 0xFFFFu);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"Error.log") + 4u);
    cpu->eax = 0x6F727245u;
    cpu->ebx = native_function_address32(&::fflush);
    cpu->ebp = native_function_address32(&::fclose);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[0].path.words[1], cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"test.log") + 4u);
    lift_store16((uintptr_t)&g_sfera_log_runtime.files[0].path.text[8], cpu->edx & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"test.log") + 8u)) & 0xFFu);
    g_sfera_log_runtime.files[0].path.words[0] = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32((uintptr_t)"test.log");
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[1].path.words[1], cpu->ecx);
    cpu->ecx = lift_load32((uintptr_t)"logs\\memory.log");
    lift_store8((uintptr_t)&g_sfera_log_runtime.files[1].path.text[8], cpu->edx & 0xFFu);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"logs\\memory.log") + 4u);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[1].path.words[0], cpu->eax);
    cpu->eax = 0x7A120u;
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[2].path.words[0], cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"logs\\memory.log") + 8u);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[2].path.words[1], cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"logs\\memory.log") + 0xCu);
    g_sfera_log_runtime.files[0].truncate_on_first_write = (uint32_t)(cpu->esi);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[0].size_limit, 0x989680u);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[1].truncate_on_first_write, cpu->esi);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[1].size_limit, cpu->eax);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[2].path.words[2], cpu->ecx);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[2].path.words[3], cpu->edx);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[2].truncate_on_first_write, cpu->esi);
    lift_store32((uintptr_t)&g_sfera_log_runtime.files[2].size_limit, cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode) = (uint32_t)(3u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].has_written;
    goto label_00064CD2;
    label_00064CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x464CD0u);
    cpu->esi = 0u;
    label_00064CD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x464CD2u);
    if ((uint32_t)(lift_load32(cpu->edi + 0xFFFFFFFCu)) != (uint32_t)(cpu->esi)) goto label_00064DF3;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464CE4u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00064D05;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"**** Start: ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464CF0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464CF6u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64CF9u), LIFT_CODE_TOKEN_RVA(0x64CF7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464CF9u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64CFCu), LIFT_CODE_TOKEN_RVA(0x64CFAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464CFCu);
    cpu->esp += 0x10u;
    lift_store32(cpu->edi, 1u);
    label_00064D05: cpu->eip = LIFT_CODE_TOKEN_VA(0x464D05u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x464D0Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464D10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x464D15u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464D1Bu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y");
    cpu->edx = (uint32_t)(cpu->esp + 0x1B0u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x464D2Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464D31u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->esp += 0x18u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464D3Du); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00064D61;
    cpu->eax = (uint32_t)(cpu->esp + 0x1A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464D4Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464D52u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64D55u), LIFT_CODE_TOKEN_RVA(0x64D53u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464D55u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64D58u), LIFT_CODE_TOKEN_RVA(0x64D56u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464D58u);
    cpu->esp += 0x10u;
    lift_store32(cpu->edi, 1u);
    label_00064D61: cpu->eip = LIFT_CODE_TOKEN_VA(0x464D61u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464D6Au); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00064D8B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"  ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464D76u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464D7Cu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64D7Fu), LIFT_CODE_TOKEN_RVA(0x64D7Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464D7Fu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64D82u), LIFT_CODE_TOKEN_RVA(0x64D80u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464D82u);
    cpu->esp += 0x10u;
    lift_store32(cpu->edi, 1u);
    label_00064D8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x464D8Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1A0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x464D93u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464D99u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464DA5u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00064DC9;
    cpu->edx = (uint32_t)(cpu->esp + 0x1A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464DB4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464DBAu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64DBDu), LIFT_CODE_TOKEN_RVA(0x64DBBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464DBDu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64DC0u), LIFT_CODE_TOKEN_RVA(0x64DBEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464DC0u);
    cpu->esp += 0x10u;
    lift_store32(cpu->edi, 1u);
    label_00064DC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x464DC9u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464DD2u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00064DF3;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464DDEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464DE4u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64DE7u), LIFT_CODE_TOKEN_RVA(0x64DE5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464DE7u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64DEAu), LIFT_CODE_TOKEN_RVA(0x64DE8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464DEAu);
    cpu->esp += 0x10u;
    lift_store32(cpu->edi, 1u);
    label_00064DF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x464DF3u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 0x40u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode))) goto label_00064CD0;
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CoInitialize), LIFT_CODE_TOKEN_VA(0x464E0Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464E13u);
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00064EAB;
    if ((uint32_t)(cpu->esi) == (uint32_t)(1u)) goto label_00064EAB;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464E2Du); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00064E52;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"ERROR: init_first2: CoInitialize error code = ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464E39u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464E3Fu);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64E42u), LIFT_CODE_TOKEN_RVA(0x64E40u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464E42u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64E45u), LIFT_CODE_TOKEN_RVA(0x64E43u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464E45u);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00064E52: cpu->eip = LIFT_CODE_TOKEN_VA(0x464E52u);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464E59u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00064E7F;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%d\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x464E66u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464E6Cu);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64E6Fu), LIFT_CODE_TOKEN_RVA(0x64E6Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464E6Fu);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64E72u), LIFT_CODE_TOKEN_RVA(0x64E70u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464E72u);
    cpu->esp += 0x14u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00064E7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x464E7Fu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464E86u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00064EAB;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x464E92u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x464E98u);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x64E9Bu), LIFT_CODE_TOKEN_RVA(0x64E99u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464E9Bu);
    lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x64E9Eu), LIFT_CODE_TOKEN_RVA(0x64E9Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464E9Eu);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00064EAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x464EABu);
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464EB5u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_09;
    cpu->ecx = (uint32_t)(uintptr_t)"LANG";
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464ECEu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_process_runtime.locale[0])) == (uint8_t)(0u)) goto label_000650A7;
    cpu->edi = native_function_address32(&::strncmp);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"ru"); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.locale[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x64EEFu), LIFT_CODE_TOKEN_RVA(0x64EEDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464EEFu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00064FCE;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(cpu->eax);
    label_00064EFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x464EFFu);
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = (uint8_t)(0u);
    label_00064F06: cpu->eip = LIFT_CODE_TOKEN_VA(0x464F06u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_25;
    cpu->ecx = (uint32_t)(uintptr_t)"AUTOFOG";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F15u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance;
    cpu->ecx = (uint32_t)(uintptr_t)"FOGDIST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F24u); lift_push32(cpu, r); sfera_sub_004486E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_options_dialog_runtime.reflection_quality;
    cpu->ecx = (uint32_t)(uintptr_t)"REFLQUAL";
    g_sfera_options_dialog_runtime.reflection_quality = (uint32_t)(2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F3Du); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_26;
    cpu->ecx = (uint32_t)(uintptr_t)"EFFECTS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F4Cu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_runtime.lods_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"LODS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F5Bu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_runtime.hardware_cursor_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"HARDWARE_CURSOR";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F6Au); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.description_auto_popup;
    cpu->ecx = (uint32_t)(uintptr_t)"DESCR_AUTO_POPUP";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F79u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.invite_messages;
    cpu->ecx = (uint32_t)(uintptr_t)"INVITE_MESSAGES";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F88u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_26;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F93u); lift_push32(cpu, r); sfera_sub_004261B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464F98u); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"loadcount.bin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464FA4u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464FABu); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0006517E;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_world_load_runtime.loading_work_total;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464FC2u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x464FC9u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    goto label_00065188;
    label_00064FCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x464FCEu);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"en"); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.locale[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x64FDCu), LIFT_CODE_TOKEN_RVA(0x64FDAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x464FDCu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00064FF2;
    label_00064FE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x464FE3u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(1u);
    goto label_000650B1;
    label_00064FF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x464FF2u);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"es"); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.locale[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x65000u), LIFT_CODE_TOKEN_RVA(0x64FFEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465000u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00065016;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(5u);
    goto label_0006513B;
    label_00065016: cpu->eip = LIFT_CODE_TOKEN_VA(0x465016u);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"pt"); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.locale[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x65024u), LIFT_CODE_TOKEN_RVA(0x65022u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465024u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006503A;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(2u);
    goto label_000650D3;
    label_0006503A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46503Au);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"de"); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.locale[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x65048u), LIFT_CODE_TOKEN_RVA(0x65046u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465048u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006505E;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(4u);
    goto label_00065119;
    label_0006505E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46505Eu);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"fr"); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.locale[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x6506Cu), LIFT_CODE_TOKEN_RVA(0x6506Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46506Cu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00065082;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(6u);
    goto label_0006515F;
    label_00065082: cpu->eip = LIFT_CODE_TOKEN_VA(0x465082u);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"it"); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.locale[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x65090u), LIFT_CODE_TOKEN_RVA(0x6508Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465090u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00064FE3;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09) = (uint32_t)(3u);
    goto label_000650F5;
    label_000650A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4650A7u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_000650CE;
    label_000650B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4650B1u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x655F)) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"_e") + 2u)) & 0xFFu);
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = (uint16_t)((cpu->eax & 0xFFFFu));
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = (uint8_t)((cpu->ecx & 0xFFu));
    goto label_00064F06;
    label_000650CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4650CEu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_000650F0;
    label_000650D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4650D3u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"_p")) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"_p") + 2u)) & 0xFFu);
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = (uint16_t)((cpu->edx & 0xFFFFu));
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = (uint8_t)((cpu->eax & 0xFFu));
    goto label_00064F06;
    label_000650F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4650F0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_00065114;
    label_000650F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4650F5u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"_i")) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"_i") + 2u)) & 0xFFu);
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = (uint16_t)((cpu->ecx & 0xFFFFu));
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = (uint8_t)((cpu->edx & 0xFFu));
    goto label_00064F06;
    label_00065114: cpu->eip = LIFT_CODE_TOKEN_VA(0x465114u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_00065136;
    label_00065119: cpu->eip = LIFT_CODE_TOKEN_VA(0x465119u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"_d")) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"_d") + 2u)) & 0xFFu);
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = (uint16_t)((cpu->eax & 0xFFFFu));
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = (uint8_t)((cpu->ecx & 0xFFu));
    goto label_00064F06;
    label_00065136: cpu->eip = LIFT_CODE_TOKEN_VA(0x465136u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_00065156;
    label_0006513B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46513Bu);
    cpu->edx = lift_load32((uintptr_t)"_spa");
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"_spa") + 4u)) & 0xFFu);
    (*(uint32_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = (uint32_t)(cpu->edx);
    lift_store8((uintptr_t)&g_sfera_font_runtime.language_suffix[4], cpu->eax & 0xFFu);
    goto label_00064F06;
    label_00065156: cpu->eip = LIFT_CODE_TOKEN_VA(0x465156u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(6u)) goto label_00064EFF;
    label_0006515F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46515Fu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"_f")) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"_f") + 2u)) & 0xFFu);
    (*(uint16_t*)(void*)&g_sfera_font_runtime.language_suffix[0]) = (uint16_t)((cpu->ecx & 0xFFFFu));
    (*(uint8_t*)(void*)&g_sfera_font_runtime.language_suffix[2]) = (uint8_t)((cpu->edx & 0xFFu));
    goto label_00064F06;
    label_0006517E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46517Eu);
    g_sfera_world_load_runtime.loading_work_total = (uint32_t)(0x3A98u);
    label_00065188: cpu->eip = LIFT_CODE_TOKEN_VA(0x465188u);
    lift_native_call(cpu, native_function_address32(&::InitCommonControls), LIFT_CODE_TOKEN_VA(0x465188u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46518Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465193u); lift_push32(cpu, r); sfera_sub_0045AFB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465198u); lift_push32(cpu, r); sfera_sub_00462690(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    cpu->eax = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000651A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4651A0u);
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)g_sfera_ascii_lower_runtime.table), cpu->eax & 0xFFu);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_000651A0;
    for (uint32_t letter = 'A'; letter <= 'Z'; ++letter) { LIFT_STORE8(letter + ((uint32_t)(uintptr_t)g_sfera_ascii_lower_runtime.table), (uint8_t)(letter + ('a' - 'A'))); }
    lift_push32(cpu, (uintptr_t)"SphereDebug"); lift_push32(cpu, 0x3E8u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 4u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFFFu);
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x4651D9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4651DFu);
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000651F0;
    cpu->ecx = (uint32_t)(uintptr_t)"CreateFileMapping failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x651F0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000651F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4651F0u);
    lift_push32(cpu, 0x3E8u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x4651FAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x465200u);
    lift_push32(cpu, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode) = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x465206u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46520Cu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0006521F;
    cpu->ecx = (uint32_t)(uintptr_t)"MapViewOfFile failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6521Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006521F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46521Fu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x3E7u)) != (uint8_t)(2u)) goto label_00065244;
    lift_store8(cpu->eax + 0x3E7u, 1u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x3E7u)) & 0xFFu);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00065240: cpu->eip = LIFT_CODE_TOKEN_VA(0x465240u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(1u)) goto label_00065240;
    label_00065244: cpu->eip = LIFT_CODE_TOKEN_VA(0x465244u);
    lift_push32(cpu, (uintptr_t)"Spider"); lift_push32(cpu, (uintptr_t)"SpiderWclName");
    lift_native_call(cpu, native_function_address32(&::FindWindowA), LIFT_CODE_TOKEN_VA(0x46524Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x465254u);
    g_sfera_debug_window_runtime.spider_window = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x34u, 1u);
    g_sfera_graphics_runtime.display_width = (uint32_t)(0x280u);
    g_sfera_graphics_runtime.display_height = (uint32_t)(0x1E0u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.debug_config_enabled)) == (uint32_t)(cpu->ebx)) goto label_000652B3;
    cpu->ecx = (uint32_t)(uintptr_t)"debug.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465287u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    cpu->ecx = (uint32_t)(uintptr_t)"SHOWVIDEO";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465295u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_23;
    cpu->ecx = (uint32_t)(uintptr_t)"REFRESH";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4652A4u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.memory_warning_as_error;
    cpu->ecx = (uint32_t)(uintptr_t)"MEMORY_WARNING_AS_ERROR";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x652B3u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    label_000652B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4652B3u);
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4652BDu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_window_runtime.windowed;
    cpu->ecx = (uint32_t)(uintptr_t)"WINDOWED";
    g_sfera_window_runtime.windowed = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4652D2u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = native_function_address32(&::GetSystemMetrics);
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x652DBu), LIFT_CODE_TOKEN_RVA(0x652D9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4652DBu);
    lift_push32(cpu, 1u);
    g_sfera_graphics_runtime.display_width = (uint32_t)(cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x652E4u), LIFT_CODE_TOKEN_RVA(0x652E2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4652E4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_runtime.display_width;
    cpu->ecx = (uint32_t)(uintptr_t)"XRES";
    g_sfera_graphics_runtime.display_height = (uint32_t)(cpu->eax);
    g_sfera_graphics_display_depth_bits = (uint32_t)(0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465302u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_runtime.display_height;
    cpu->ecx = (uint32_t)(uintptr_t)"YRES";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465311u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_display_depth_bits;
    cpu->ecx = (uint32_t)(uintptr_t)"DEPTH";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465320u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_main_render_runtime.grass_depth_mode;
    cpu->ecx = (uint32_t)(uintptr_t)"GRASS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46532Fu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32;
    cpu->ecx = (uint32_t)(uintptr_t)"LOD_DISTANCE";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46533Eu); lift_push32(cpu, r); sfera_sub_004486E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32;
    cpu->ecx = (uint32_t)(uintptr_t)"MIN_LOD_DIST";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46534Du); lift_push32(cpu, r); sfera_sub_004486E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_graphics_runtime.post_effects_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"POSTEFFECTS";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46535Cu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006537D;
    lift_x87_push(cpu, (double)23.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006537D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46537Du);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00065398;
    lift_x87_push(cpu, (double)20.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00065398: cpu->eip = LIFT_CODE_TOKEN_VA(0x465398u);
    cpu->esi = native_function_address32(&::_findfirst64i32);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"landscape_hr");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x653AAu), LIFT_CODE_TOKEN_RVA(0x653A8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4653AAu);
    cpu->ebp = native_function_address32(&::_errno);
    cpu->edi = native_function_address32(&::_findclose);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0006550E;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x653C4u), LIFT_CODE_TOKEN_RVA(0x653C2u))) { return; }
    label_000653C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4653C4u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) = (uint32_t)(cpu->ebx);
    label_000653CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4653CAu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"landscape_ph");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x653D6u), LIFT_CODE_TOKEN_RVA(0x653D4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4653D6u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0006553A;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x653E4u), LIFT_CODE_TOKEN_RVA(0x653E2u))) { return; }
    label_000653E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4653E4u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21) = (uint32_t)(cpu->ebx);
    label_000653EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4653EAu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"landscape_rd");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x653F6u), LIFT_CODE_TOKEN_RVA(0x653F4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4653F6u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00065560;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x65404u), LIFT_CODE_TOKEN_RVA(0x65402u))) { return; }
    label_00065404: cpu->eip = LIFT_CODE_TOKEN_VA(0x465404u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22) = (uint32_t)(cpu->ebx);
    cpu->ebp = 1u;
    label_0006540F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46540Fu);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.vertical_sync_enabled;
    cpu->ecx = (uint32_t)(uintptr_t)"VERTSYNC";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46541Eu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00065439;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)"VERTSYNC";
    g_sfera_recovered_static_runtime.vertical_sync_enabled = (uint32_t)(cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465434u); lift_push32(cpu, r); sfera_sub_00448A20(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x65439u); lift_push32(cpu, r); sfera_sub_00448490(cpu,r); if (cpu->eip != r) return; }
    label_00065439: cpu->eip = LIFT_CODE_TOKEN_VA(0x465439u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46543Eu); lift_push32(cpu, r); sfera_sub_00459E40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"landscape";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465448u); lift_push32(cpu, r); sfera_sub_0042F2D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(cpu->ebx)) goto label_0006545A;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_hr";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6545Au); lift_push32(cpu, r); sfera_sub_0042F2D0(cpu,r); if (cpu->eip != r) return; }
    label_0006545A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46545Au);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21)) == (uint32_t)(cpu->ebx)) goto label_0006546C;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_ph";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6546Cu); lift_push32(cpu, r); sfera_sub_0042F2D0(cpu,r); if (cpu->eip != r) return; }
    label_0006546C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46546Cu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22)) == (uint32_t)(cpu->ebx)) goto label_0006547E;
    cpu->ecx = (uint32_t)(uintptr_t)"landscape_rd";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6547Eu); lift_push32(cpu, r); sfera_sub_0042F2D0(cpu,r); if (cpu->eip != r) return; }
    label_0006547E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46547Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465483u); lift_push32(cpu, r); sfera_sub_0045AA50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465488u); lift_push32(cpu, r); sfera_sub_00462A90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465493u); lift_push32(cpu, r); sfera_sub_004D8360(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0006549D;
    g_sfera_graphics_runtime.post_effects_enabled = (uint32_t)(cpu->ebx);
    label_0006549D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46549Du);
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_000654D3;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->ebp));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store8(cpu->esp + 0x210u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4654BEu); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4654C8u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store8(cpu->esp + 0x210u, 0u);
    label_000654D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4654D3u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(g_sfera_graphics_runtime.hardware_cursor_enabled), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4654E9u); lift_push32(cpu, r); sfera_sub_004D7AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    --cpu->edx;
    lift_push32(cpu, cpu->edx);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465503u); lift_push32(cpu, r); sfera_sub_004556B0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, 0.0);
    cpu->eax = sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::z);
    goto label_00065589;
    label_0006550E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46550Eu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x38u)), r=(uint64_t)(0x10u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00065530;
    cpu->edi = native_function_address32(&::_findclose);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x6551Eu), LIFT_CODE_TOKEN_RVA(0x6551Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46551Eu);
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20) = (uint32_t)(1u);
    goto label_000653CA;
    label_00065530: cpu->eip = LIFT_CODE_TOKEN_VA(0x465530u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x65532u), LIFT_CODE_TOKEN_RVA(0x65530u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465532u);
    cpu->esp += 4u;
    goto label_000653C4;
    label_0006553A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46553Au);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x38u)), r=(uint64_t)(0x10u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00065556;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x65544u), LIFT_CODE_TOKEN_RVA(0x65542u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465544u);
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21) = (uint32_t)(1u);
    goto label_000653EA;
    label_00065556: cpu->eip = LIFT_CODE_TOKEN_VA(0x465556u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x65558u), LIFT_CODE_TOKEN_RVA(0x65556u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465558u);
    cpu->esp += 4u;
    goto label_000653E4;
    label_00065560: cpu->eip = LIFT_CODE_TOKEN_VA(0x465560u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x38u)), r=(uint64_t)(0x10u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006557D;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x6556Au), LIFT_CODE_TOKEN_RVA(0x65568u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46556Au);
    cpu->ebp = 1u;
    cpu->esp += 4u;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22) = (uint32_t)(cpu->ebp);
    goto label_0006540F;
    label_0006557D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46557Du);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x6557Fu), LIFT_CODE_TOKEN_RVA(0x6557Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46557Fu);
    cpu->esp += 4u;
    goto label_00065404;
    label_00065587: cpu->eip = LIFT_CODE_TOKEN_VA(0x465587u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00065589: cpu->eip = LIFT_CODE_TOKEN_VA(0x465589u);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0xCu, cpu->ebx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax += 0x20u;
    lift_store_f32(cpu->eax + 0xFFFFFFE4u, lift_x87_get(cpu, 0u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(sfera_screen_vertex_field_end_address(g_sfera_landscape_screen_vertices, &SferaScreenVertex::z)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00065587;
    cpu->edi = native_function_address32(&::ShowCursor);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x655AAu), LIFT_CODE_TOKEN_RVA(0x655A8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4655AAu);
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x655ADu), LIFT_CODE_TOKEN_RVA(0x655ABu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4655ADu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000655B8;
    label_000655B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4655B1u);
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x655B4u), LIFT_CODE_TOKEN_RVA(0x655B2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4655B4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000655B1;
    label_000655B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4655B8u);
    cpu->edx = 0x1D1Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4655C7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x10A9ACu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4655D1u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store8(cpu->esp + 0x210u, 2u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000655F2;
    lift_push32(cpu, (uint32_t)(uintptr_t)"xadd\\snowpath.bin");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4655F0u); lift_push32(cpu, r); sfera_sub_00495570(cpu,r); if (cpu->eip != r) return; }
    goto label_000655F4;
    label_000655F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4655F2u);
    cpu->eax = 0u;
    label_000655F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4655F4u);
    cpu->esi = native_function_address32(&::sprintf);
    lift_store32((uintptr_t)&g_sfera_world_load_runtime.snow_path_object, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    lift_store8(cpu->esp + 0x210u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0006562D;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0006562D;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->ecx = (uint32_t)(cpu->esp + 0x164u);
    lift_push32(cpu, (uintptr_t)"fonts\\font1%s.pcx"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x65628u), LIFT_CODE_TOKEN_RVA(0x65626u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465628u);
    cpu->esp += 0xCu;
    goto label_00065660;
    label_0006562D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46562Du);
    cpu->edx = lift_load32((uintptr_t)"fonts\\font1.pcx");
    cpu->eax = lift_load32(((uint32_t)(uintptr_t)"fonts\\font1.pcx") + 4u);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"fonts\\font1.pcx") + 8u);
    lift_store32(cpu->esp + 0x160u, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"fonts\\font1.pcx") + 0xCu);
    lift_store32(cpu->esp + 0x164u, cpu->eax);
    lift_store32(cpu->esp + 0x168u, cpu->ecx);
    lift_store32(cpu->esp + 0x16Cu, cpu->edx);
    label_00065660: cpu->eip = LIFT_CODE_TOKEN_VA(0x465660u);
    lift_push32(cpu, 5u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x16Cu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465672u); lift_push32(cpu, r); sfera_sub_00459FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00065698;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_00065698;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = (uint32_t)(cpu->esp + 0x164u);
    lift_push32(cpu, (uintptr_t)"fonts\\font2%s.pcx"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x65693u), LIFT_CODE_TOKEN_RVA(0x65691u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465693u);
    cpu->esp += 0xCu;
    goto label_000656CB;
    label_00065698: cpu->eip = LIFT_CODE_TOKEN_VA(0x465698u);
    cpu->ecx = lift_load32((uintptr_t)"fonts\\font2.pcx");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"fonts\\font2.pcx") + 4u);
    cpu->eax = lift_load32(((uint32_t)(uintptr_t)"fonts\\font2.pcx") + 8u);
    lift_store32(cpu->esp + 0x160u, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"fonts\\font2.pcx") + 0xCu);
    lift_store32(cpu->esp + 0x164u, cpu->edx);
    lift_store32(cpu->esp + 0x168u, cpu->eax);
    lift_store32(cpu->esp + 0x16Cu, cpu->ecx);
    label_000656CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4656CBu);
    lift_push32(cpu, 3u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x16Cu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4656DDu); lift_push32(cpu, r); sfera_sub_00459FA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[0][0], lift_x87_get(cpu, 0u));
    cpu->eax = 0u;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[1][0], lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, 1.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[2][0], lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[3][0], lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)-1.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[0][1], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[1][2], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[1][1], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[2][1], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[3][1], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[0][2], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[2][2], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[3][2], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[0][3], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[1][3], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[2][3], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[3][3], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 6.0);
    label_00065755: cpu->eip = LIFT_CODE_TOKEN_VA(0x465755u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.normalized_levels[0]), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(7u)) goto label_00065755;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)2.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.blend_weights[0].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.20000000298023224f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.blend_weights[1].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.75f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.blend_weights[2].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)1.2000000476837158f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.blend_weights[3].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)2.5f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.blend_weights[4].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)3.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.blend_weights[5].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)4.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_render_sample_runtime.blend_weights[6].f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4657C8u); lift_push32(cpu, r); sfera_sub_0044DAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_000657D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4657D0u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (12.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.041666666666666664));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4657F9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    --cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0006580C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6580Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006580C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46580Cu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_pass_slots.capacity)) goto label_00065820;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x65820u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00065820: cpu->eip = LIFT_CODE_TOKEN_VA(0x465820u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->edx = g_sfera_scene_array_runtime.render_pass_slots.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x14u))))));
    cpu->edi += 0xFEu;
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store_f32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u) + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0xBE8u)) goto label_000657D0;
    cpu->ebp = (uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00065850: cpu->eip = LIFT_CODE_TOKEN_VA(0x465850u);
    cpu->ecx = 0x20000u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46585Au); lift_push32(cpu, r); sfera_sub_00499EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46587Bu); lift_push32(cpu, r); sfera_sub_004D8E70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->ebp)) == (uint32_t)(cpu->ebx)) goto label_00065A9C;
    cpu->ebp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource + kTextureCacheEntryCount * (uint32_t)sizeof(SferaTextureCacheEntry)))) goto label_00065850;
    lift_x87_push(cpu, 0.5);
    cpu->edi = 0u;
    cpu->ebp = 0u;
    label_00065899: cpu->eip = LIFT_CODE_TOKEN_VA(0x465899u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000658AF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4658A9u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.5);
    label_000658AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4658AFu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_pass_slots.capacity)) goto label_000658CB;
    cpu->edx = cpu->edi;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_pass_slots.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4658C5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.5);
    label_000658CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4658CBu);
    cpu->eax = g_sfera_scene_array_runtime.render_pass_slots.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->edi) * 4u)));
    cpu->esi = 0u;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000658D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4658D9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4658E6u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ebx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x18u))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (64.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46590Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.0833333358168602));
    lift_store8(cpu->esi + cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_b[0]), cpu->eax & 0xFFu);
    lift_store8(cpu->esi + cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_a[0]), cpu->ebx & 0xFFu);
    ++cpu->esi;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x100u)) goto label_000658D9;
    ++cpu->edi;
    cpu->ebp += 0x100u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0xCu)) goto label_00065899;
    lift_x87_push(cpu, 0.015625);
    lift_store32(cpu->esp + 0x18u, 0u);
    lift_x87_push(cpu, 255.0);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.blend_lut[1];
    label_00065954: cpu->eip = LIFT_CODE_TOKEN_VA(0x465954u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    label_0006596E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46596Eu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    ++cpu->edx;
    lift_store16(cpu->esp + 0x14u, cpu->fpu_control);
    cpu->ecx += 4u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->eax |= 0xC00u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load8(cpu->esp + 0x1Cu);
    lift_store8(cpu->ecx + 0xFFFFFFFBu, cpu->eax & 0xFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store16(cpu->esp + 0x14u, cpu->fpu_control);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x2Cu));
    lift_store32(cpu->esp + 0x2Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load8(cpu->esp + 0x2Cu);
    lift_store8(cpu->ecx + 0xFFFFFFFCu, cpu->eax & 0xFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store16(cpu->esp + 0x14u, cpu->fpu_control);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x28u));
    lift_store32(cpu->esp + 0x28u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load8(cpu->esp + 0x28u);
    lift_store8(cpu->ecx + 0xFFFFFFFDu, cpu->eax & 0xFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store16(cpu->esp + 0x14u, cpu->fpu_control);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x20u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load8(cpu->esp + 0x20u);
    lift_store8(cpu->ecx + 0xFFFFFFFEu, cpu->eax & 0xFFu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(0x40u)) goto label_0006596E;
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + 1u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.blend_lut[kRenderBlendLutStorageSize]))) goto label_00065954;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = 0u;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_x87_push(cpu, 220.0);
    label_00065A83: cpu->eip = LIFT_CODE_TOKEN_VA(0x465A83u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(0xDCu)) goto label_00065AA6;
    lift_store8(((uint32_t)(cpu->ebx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][0]), cpu->ebx & 0xFFu);
    lift_store8(((uint32_t)(cpu->ebx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][1]), 0u);
    goto label_00065AEF;
    label_00065A9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x465A9Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"CreateTexture for landscape cash failed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x65AA6u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00065AA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x465AA6u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465AC9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->ebx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x8Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store8(((uint32_t)(cpu->ebx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][0]), cpu->ecx & 0xFFu);
    lift_store8(((uint32_t)(cpu->ebx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.landscape_texture_lut[0][1]), cpu->eax & 0xFFu);
    label_00065AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x465AEFu);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x100u)) goto label_00065A83;
    lift_push32(cpu, 0x100u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0]);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x465B0Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x465B11u);
    cpu->esp += 0xCu;
    lift_store8((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0xFF], 1u);
    lift_store32((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0x23], 0x1010101u);
    lift_store16((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0x27], 0x101u);
    lift_store8((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0x2E], 1u);
    lift_store16((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0x21], 0x101u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465B43u); lift_push32(cpu, r); sfera_sub_004518E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x210u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465B57u); lift_push32(cpu, r); sfera_sub_00480390(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x208u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x200u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00465B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x465B80u);
    cpu->esp -= 0xE0u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xE8u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->esi -= cpu->ecx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00065BC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x465BC0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00065BC0;
    cpu->ecx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00065BD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x465BD0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00065BD0;
    cpu->edi = (uint32_t)(uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00065BE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x465BE1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00065BE1;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    lift_movs8(cpu, 1u);
    --cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00065C00: cpu->eip = LIFT_CODE_TOKEN_VA(0x465C00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00065C00;
    cpu->edx = lift_load32((uintptr_t)".mdl");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)".mdl") + 4u)) & 0xFFu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, cpu->ecx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465C1Eu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465C28u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465C33u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00065C47;
    lift_push32(cpu, (uintptr_t)g_sfera_model_load_scratch_runtime.filename); lift_push32(cpu, (uintptr_t)"File not found: %s");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x65C47u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    label_00065C47: cpu->eip = LIFT_CODE_TOKEN_VA(0x465C47u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->edi = cpu->esi;
    lift_push32(cpu, 0x21C1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465C5Cu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465C6Au); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465C76u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465C7Du); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load16(cpu->ebx + 4u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09) = (uint32_t)(cpu->edx);
    cpu->eax = lift_load16(cpu->ebx + 6u);
    g_sfera_recovered_static_runtime.render_state_07 = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load16(cpu->ebx + 8u);
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state) = (uint32_t)(cpu->ecx);
    cpu->edx = lift_load8(cpu->ebx + 0xDu);
    g_sfera_recovered_static_runtime.input_state_a = (uint32_t)(cpu->edx);
    cpu->eax = lift_load8(cpu->ebx + 0xFu);
    g_sfera_input_device_runtime.keyboard_state_code = (uint32_t)(cpu->eax);
    cpu->edx = lift_load8(cpu->ebx + 0xEu);
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.viewport_state) = (uint32_t)(cpu->edx);
    cpu->ecx = lift_load8(cpu->ebx + 0xAu);
    g_sfera_static_render_lookup_runtime.sample_state = (uint32_t)(cpu->ecx);
    cpu->ebp = lift_load8(cpu->ebx + 0x14u);
    g_sfera_world_load_runtime.packed_variant = (uint32_t)(cpu->ebp);
    cpu->eax = lift_load16(cpu->ebx + 0x15u);
    g_sfera_render_sample_runtime.material_code.u32 = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load16(cpu->ebx + 0x10u);
    g_sfera_window_runtime.scene_record_count = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load16(cpu->ebx + 0x12u);
    g_sfera_process_runtime.packed_record_count = (uint32_t)(cpu->eax);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x17u)) & 0xFFu);
    (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled) = (uint8_t)((cpu->ecx & 0xFFu));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebx + 0x18u)) & 0xFFFFu);
    g_sfera_static_render_lookup_runtime.packed_format_code = (uint16_t)((cpu->eax & 0xFFFFu));
    cpu->ecx = lift_load32(cpu->ebx + 0x1Eu);
    g_sfera_client_main_scalar_runtime.state_23 = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->ebx + 0x22u);
    g_sfera_client_main_scalar_runtime.state_24 = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 0x26u);
    g_sfera_client_main_scalar_runtime.state_25 = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->ebx + 0x2Au);
    g_sfera_client_main_scalar_runtime.state_26 = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 0x2Eu);
    g_sfera_client_main_scalar_runtime.state_27 = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->ebx + 0x32u);
    g_sfera_client_main_scalar_runtime.state_28 = (uint32_t)(cpu->eax);
    cpu->esi = (uint32_t)(cpu->ebx + 0x36u);
    cpu->ecx = 0x18u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_client_bounds_corners;
    lift_movs32(cpu, 1u);
    cpu->esi = (uint32_t)(cpu->ebx + 0x96u);
    cpu->ecx = 0x18u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_model_bounds_corners;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebx + 0x1Au);
    g_sfera_recovered_static_runtime.client_state_06 = (uint32_t)(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xF6u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.parameter.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->ebx + 0xFAu);
    g_sfera_main_aux_runtime.resource_word = (uint32_t)(cpu->esi);
    cpu->eax = lift_load32(cpu->ebx + 0xFEu);
    g_sfera_landscape_render_runtime.source_record_count = (uint32_t)(cpu->eax);
    cpu->eax = lift_load16(cpu->ebx + 0xBu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x102u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    g_sfera_recovered_static_runtime.animation_state = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load16(cpu->ebx + 4u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    g_sfera_client_main_scalar_runtime.state_04 = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load16(cpu->ebx + 6u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06) = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load16(cpu->ebx + 8u);
    cpu->edi = cpu->ecx;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(4u), 32u);
    cpu->edi -= cpu->ecx;
    cpu->eax += cpu->edi;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    g_sfera_recovered_static_runtime.client_state_04 = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load8(cpu->ebx + 0xDu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x27u);
    cpu->eax += cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    cpu->eax += cpu->edx;
    g_sfera_render_sample_runtime.record_base = (uint32_t)(cpu->ecx);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00065E1B;
    cpu->ecx = g_sfera_window_runtime.scene_record_count;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_05) = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    g_sfera_spatial_index_runtime.quadtree_state = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_process_runtime.packed_record_count;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    g_sfera_scene_control_runtime.packed_section_base = (uint32_t)(cpu->ecx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebp) * 2u));
    label_00065E1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x465E1Bu);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled)) != (uint8_t)(1u)) goto label_00065E4C;
    cpu->ecx = g_sfera_static_render_lookup_runtime.packed_format_code;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_07;
    g_sfera_recovered_static_runtime.render_state_10 = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags) = (uint32_t)(cpu->edx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    label_00065E4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x465E4Cu);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->edi)) goto label_00065E67;
    cpu->ecx = g_sfera_recovered_static_runtime.input_state_a;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    g_sfera_client_main_scalar_runtime.state_05 = (uint32_t)(cpu->edx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 8u));
    label_00065E67: cpu->eip = LIFT_CODE_TOKEN_VA(0x465E67u);
    { uint64_t l=(uint64_t)(g_sfera_recovered_static_runtime.client_state_06), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00065E96;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = g_sfera_landscape_render_runtime.source_record_count;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    g_sfera_landscape_render_runtime.source_section_base = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    g_sfera_client_main_scalar_runtime.state_03 = (uint32_t)(cpu->edx);
    cpu->eax += cpu->ecx;
    label_00065E96: cpu->eip = LIFT_CODE_TOKEN_VA(0x465E96u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) == (uint32_t)(cpu->eax)) goto label_00065EAB;
    cpu->edx = (uint32_t)(uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->ecx = (uint32_t)(uintptr_t)"load_model: wrong format. File: ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x65EABu); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_00065EAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x465EABu);
    cpu->ecx = g_sfera_static_render_lookup_runtime.sample_state;
    lift_push32(cpu, 0x220Bu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465EC2u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_landscape_map_runtime.material_remap = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_static_render_lookup_runtime.sample_state) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00065F5B;
    label_00065EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x465EE0u);
    cpu->esi = lift_load8(cpu->ebx + cpu->edi + 0x102u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->ebx + cpu->edi + 0x103u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0]);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x465EF6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x465EFCu);
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0]), 0u);
    cpu->edi = (uint32_t)(cpu->edi + cpu->esi + 1u);
    cpu->ebp = 0u;
    cpu->esi = 0u;
    cpu->edi = cpu->edi;
    label_00065F10: cpu->eip = LIFT_CODE_TOKEN_VA(0x465F10u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(g_sfera_main_render_runtime.material_count)) goto label_0006608D;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0]);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x465F2Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x465F30u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00065F40;
    ++cpu->ebp;
    cpu->esi += 0x88u;
    goto label_00065F10;
    label_00065F40: cpu->eip = LIFT_CODE_TOKEN_VA(0x465F40u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = g_sfera_landscape_map_runtime.material_remap;
    lift_store16(cpu->edx + ((uint32_t)(cpu->eax) * 2u), cpu->ebp & 0xFFFFu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_static_render_lookup_runtime.sample_state)) goto label_00065EE0;
    label_00065F5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x465F5Bu);
    lift_push32(cpu, 0x2220u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x1E4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x465F6Fu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 0x1E4u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->eax, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x465F7Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x465F84u);
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    cpu->edx = cpu->ebp;
    cpu->esp += 0xCu;
    cpu->edx -= cpu->eax;
    (void)cpu;
    label_00065F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x465F90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00065F90;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09;
    lift_store32(cpu->ebp + 0x20u, cpu->ecx);
    cpu->edx = g_sfera_recovered_static_runtime.render_state_07;
    lift_store32(cpu->ebp + 0x28u, cpu->edx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state;
    lift_store32(cpu->ebp + 0x30u, cpu->eax);
    cpu->ecx = g_sfera_recovered_static_runtime.input_state_a;
    lift_store32(cpu->ebp + 0x38u, cpu->ecx);
    cpu->edx = g_sfera_static_render_lookup_runtime.sample_state;
    lift_store32(cpu->ebp + 0x44u, cpu->edx);
    cpu->eax = *(uint8_t*)(void*)&g_sfera_input_device_runtime.keyboard_state_code;
    lift_store8(cpu->ebp + 0x40u, cpu->eax & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((*(uint8_t*)(void*)&g_sfera_world_load_runtime.packed_variant)) & 0xFFu);
    lift_store8(cpu->ebp + 0x50u, cpu->ecx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)((*(uint16_t*)(void*)&g_sfera_render_sample_runtime.material_code.u32)) & 0xFFFFu);
    lift_store16(cpu->ebp + 0x52u, cpu->edx & 0xFFFFu);
    cpu->eax = *(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled;
    lift_store8(cpu->ebp + 0x60u, cpu->eax & 0xFFu);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_23;
    lift_store32(cpu->ebp + 0x70u, cpu->ecx);
    cpu->edx = g_sfera_client_main_scalar_runtime.state_24;
    lift_store32(cpu->ebp + 0x74u, cpu->edx);
    cpu->eax = g_sfera_client_main_scalar_runtime.state_25;
    lift_store32(cpu->ebp + 0x78u, cpu->eax);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_26;
    lift_store32(cpu->ebp + 0x7Cu, cpu->ecx);
    cpu->edx = g_sfera_client_main_scalar_runtime.state_27;
    lift_store32(cpu->ebp + 0x80u, cpu->edx);
    cpu->eax = g_sfera_client_main_scalar_runtime.state_28;
    lift_store32(cpu->ebp + 0x84u, cpu->eax);
    cpu->edi = (uint32_t)(cpu->ebp + 0x88u);
    cpu->ecx = 0x18u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_client_bounds_corners;
    lift_movs32(cpu, 1u);
    cpu->edi = (uint32_t)(cpu->ebp + 0xE8u);
    cpu->ecx = 0x18u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_model_bounds_corners;
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.parameter.f32));
    lift_store_f32(cpu->ebp + 0x194u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)2.0f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ebp + 0x194u)));
    LIFT_X87_POP_STATUS_AX();
    cpu->ecx = g_sfera_recovered_static_runtime.client_state_06;
    lift_store32(cpu->ebp + 0x6Cu, cpu->ecx);
    cpu->edx = g_sfera_main_aux_runtime.resource_word;
    lift_store32(cpu->ebp + 0x19Cu, cpu->edx);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000660A1;
    if ((uint8_t)(lift_load8(cpu->ebp + 0x50u)) != (uint8_t)(0u)) goto label_000660A1;
    cpu->eax = 1u;
    goto label_000660A3;
    label_0006608D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46608Du);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_model_material_lookup_runtime.material_name[0]);
    cpu->edx = (uint32_t)(uintptr_t)g_sfera_model_load_scratch_runtime.filename;
    cpu->ecx = (uint32_t)(uintptr_t)"Model has material which not exist in library: ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x660A1u); lift_push32(cpu, r); sfera_sub_00459D10(cpu,r); if (cpu->eip != r) return; }
    label_000660A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4660A1u);
    cpu->eax = 0u;
    label_000660A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4660A3u);
    lift_x87_push(cpu, 0.0);
    cpu->esi = lift_load32(cpu->esp + 0x4Cu);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->ebp + 0x1D4u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0u);
    lift_store_f32(cpu->ebp + 0x1D8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ebp + 0x1BCu, cpu->eax);
    lift_store_f32(cpu->ebp + 0x1DCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1A8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lod_f"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0x1E0u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4660E5u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000660F6;
    lift_x87_push(cpu, (double)1000.0f);
    lift_store_f32(cpu->ebp + 0x1A8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000660F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4660F6u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1ACu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"lod_pow"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46610Cu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_0006611D;
    lift_x87_push(cpu, (double)-1.0f);
    lift_store_f32(cpu->ebp + 0x1ACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006611D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46611Du);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1B0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shad_f"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466133u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00066144;
    lift_x87_push(cpu, (double)0.5f);
    lift_store_f32(cpu->ebp + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00066144: cpu->eip = LIFT_CODE_TOKEN_VA(0x466144u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1B8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shad_sp"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46615Au); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_0006616B;
    lift_x87_push(cpu, (double)0.8500000238418579f);
    lift_store_f32(cpu->ebp + 0x1B8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006616B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46616Bu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1B4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"shad_s"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466181u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00066192;
    lift_x87_push(cpu, (double)2.0f);
    lift_store_f32(cpu->ebp + 0x1B4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00066192: cpu->eip = LIFT_CODE_TOKEN_VA(0x466192u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1C0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"trace"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4661A8u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000661B9;
    lift_x87_push(cpu, (double)-1.0f);
    lift_store_f32(cpu->ebp + 0x1C0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000661B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4661B9u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"land_shade_affect_K"); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4661CDu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0006621C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    cpu->esp -= 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.5));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4661F5u); lift_push32(cpu, r); sfera_sub_004EED66(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466205u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x1E0u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_0006621C;
    lift_store32(cpu->ebp + 0x1E0u, 0xFFu);
    label_0006621C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46621Cu);
    cpu->esi = 0u;
    cpu->edi = cpu->edi;
    label_00066220: cpu->eip = LIFT_CODE_TOKEN_VA(0x466220u);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09;
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 8u));
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_0006624E;
    cpu->ecx = g_sfera_process_runtime.packed_layout_bytes;
    lift_push32(cpu, 0x21A7u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466249u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_recovered_static_runtime.scene_counter = (uint32_t)(cpu->eax);
    label_0006624E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46624Eu);
    g_sfera_process_runtime.packed_layout_bytes = (uint32_t)(cpu->edi);
    lift_store32(cpu->ebp + 0x24u, cpu->eax);
    cpu->eax = g_sfera_recovered_static_runtime.render_state_07;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00066278;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066278: cpu->eip = LIFT_CODE_TOKEN_VA(0x466278u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x2Cu, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_0006629E;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_0006629E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46629Eu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x34u, cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.input_state_a;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xACu);
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_000662C5;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_000662C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4662C5u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x3Cu, cpu->ecx);
    cpu->ecx = g_sfera_static_render_lookup_runtime.sample_state;
    cpu->ecx += cpu->ecx;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_000662E8;
    cpu->eax = g_sfera_recovered_static_runtime.scene_counter;
    cpu->eax += g_sfera_process_runtime.packed_layout_bytes;
    label_000662E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4662E8u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x48u, cpu->eax);
    cpu->ecx = g_sfera_process_runtime.packed_layout_bytes;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00066305;
    cpu->eax = g_sfera_recovered_static_runtime.scene_counter;
    cpu->eax += cpu->ecx;
    label_00066305: cpu->eip = LIFT_CODE_TOKEN_VA(0x466305u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.viewport_state);
    g_sfera_process_runtime.packed_layout_bytes = (uint32_t)(cpu->ecx);
    lift_store32(cpu->ebp + 0x4Cu, cpu->eax);
    if ((uint32_t)(g_sfera_world_load_runtime.packed_variant) == (uint32_t)(cpu->edx)) goto label_00066392;
    cpu->ecx = g_sfera_window_runtime.scene_record_count;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00066342;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066342: cpu->eip = LIFT_CODE_TOKEN_VA(0x466342u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x54u, cpu->ecx);
    cpu->eax = g_sfera_process_runtime.packed_record_count;
    cpu->ecx = 0u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00066366;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066366: cpu->eip = LIFT_CODE_TOKEN_VA(0x466366u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x58u, cpu->ecx);
    cpu->ecx = g_sfera_world_load_runtime.packed_variant;
    cpu->ecx += cpu->ecx;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00066389;
    cpu->eax = g_sfera_recovered_static_runtime.scene_counter;
    cpu->eax += g_sfera_process_runtime.packed_layout_bytes;
    label_00066389: cpu->eip = LIFT_CODE_TOKEN_VA(0x466389u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x5Cu, cpu->eax);
    label_00066392: cpu->eip = LIFT_CODE_TOKEN_VA(0x466392u);
    lift_store32(cpu->ebp + 0x68u, cpu->edx);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled)) != (uint8_t)(1u)) goto label_000663EB;
    cpu->eax = g_sfera_static_render_lookup_runtime.packed_format_code;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_000663BC;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_000663BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4663BCu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x64u, cpu->ecx);
    cpu->eax = g_sfera_recovered_static_runtime.render_state_07;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_000663E2;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_000663E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4663E2u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x68u, cpu->ecx);
    label_000663EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4663EBu);
    if ((uint32_t)(g_sfera_recovered_static_runtime.client_state_06) != (uint32_t)(2u)) goto label_00066449;
    cpu->eax = g_sfera_main_aux_runtime.resource_word;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00066413;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_00066413: cpu->eip = LIFT_CODE_TOKEN_VA(0x466413u);
    { uint64_t l=(uint64_t)(g_sfera_process_runtime.packed_layout_bytes), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, v); }
    lift_store32(cpu->ebp + 0x1A0u, cpu->ecx);
    cpu->eax = g_sfera_landscape_render_runtime.source_record_count;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_0006643D;
    cpu->ecx = g_sfera_recovered_static_runtime.scene_counter;
    cpu->ecx += g_sfera_process_runtime.packed_layout_bytes;
    label_0006643D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46643Du);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_process_runtime.packed_layout_bytes, (uint64_t)(g_sfera_process_runtime.packed_layout_bytes) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->ebp + 0x1A4u, cpu->ecx);
    label_00066449: cpu->eip = LIFT_CODE_TOKEN_VA(0x466449u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(2u)) goto label_00066220;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09)) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000664ED;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    label_00066470: cpu->eip = LIFT_CODE_TOKEN_VA(0x466470u);
    cpu->eax = g_sfera_recovered_static_runtime.animation_state;
    cpu->edi = lift_load32(cpu->ecx + cpu->eax);
    cpu->esi = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    lift_store32(cpu->eax + cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + cpu->edx + 4u, cpu->edi);
    cpu->esi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->eax + cpu->edx + 8u, cpu->esi);
    cpu->eax = g_sfera_recovered_static_runtime.animation_state;
    cpu->edi = lift_load32(cpu->ecx + cpu->eax + 0xCu);
    cpu->esi = lift_load32(cpu->ebp + 0x24u);
    lift_store32(cpu->esi + cpu->edx + 0xCu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + cpu->eax + 0x10u);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0xCu);
    cpu->esi = (uint32_t)(cpu->esi + cpu->edx + 0xCu);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->esi = g_sfera_recovered_static_runtime.animation_state;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->esi + 0x18u));
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    lift_store_f32(cpu->eax + cpu->edx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = g_sfera_recovered_static_runtime.animation_state;
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->esi + 0x1Cu));
    lift_store_f32(cpu->eax + cpu->edx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->ecx += 0x20u;
    cpu->edx += 0x24u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_09))) goto label_00066470;
    label_000664ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4664EDu);
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.render_state_07) <= (int32_t)(uint32_t)(cpu->edx)) goto label_00066557;
    cpu->ecx = 0u;
    cpu->eax = 0u;
    label_00066500: cpu->eip = LIFT_CODE_TOKEN_VA(0x466500u);
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = lift_load32(cpu->eax + cpu->edi + 6u);
    cpu->esi = lift_load32(cpu->ebp + 0x2Cu);
    lift_store32(cpu->ecx + cpu->esi + 8u, cpu->edi);
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = lift_load16(cpu->eax + cpu->edi);
    cpu->esi = lift_load32(cpu->ebp + 0x2Cu);
    lift_store16(cpu->ecx + cpu->esi, cpu->edi & 0xFFFFu);
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = lift_load16(cpu->eax + cpu->edi + 2u);
    cpu->esi = lift_load32(cpu->ebp + 0x2Cu);
    lift_store16(cpu->ecx + cpu->esi + 2u, cpu->edi & 0xFFFFu);
    cpu->edi = g_sfera_client_main_scalar_runtime.state_04;
    cpu->edi = lift_load16(cpu->eax + cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->ebp + 0x2Cu);
    lift_store16(cpu->ecx + cpu->esi + 4u, cpu->edi & 0xFFFFu);
    ++cpu->edx;
    cpu->eax += 0xAu;
    cpu->ecx += 0xCu;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.render_state_07)) goto label_00066500;
    label_00066557: cpu->eip = LIFT_CODE_TOKEN_VA(0x466557u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00066677;
    cpu->edi = lift_load32(cpu->ebp + 0x34u);
    cpu->eax = 0u;
    cpu->esi = 0u;
    label_00066573: cpu->eip = LIFT_CODE_TOKEN_VA(0x466573u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load8(cpu->esi + cpu->ecx);
    lift_store8(cpu->edi + cpu->eax, cpu->edx & 0xFFu);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load8(cpu->esi + cpu->ecx + 1u);
    cpu->edi = g_sfera_landscape_map_runtime.material_remap;
    cpu->edx = lift_load16(cpu->edi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store16(cpu->eax + cpu->ecx + 2u, cpu->edx & 0xFFFFu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load16(cpu->esi + cpu->edx + 2u);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store16(cpu->eax + cpu->ecx + 4u, cpu->edx & 0xFFFFu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load16(cpu->esi + cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store16(cpu->eax + cpu->ecx + 6u, cpu->edx & 0xFFFFu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load16(cpu->esi + cpu->edx + 6u);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store16(cpu->eax + cpu->ecx + 8u, cpu->edx & 0xFFFFu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load16(cpu->esi + cpu->edx + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store16(cpu->eax + cpu->ecx + 0xAu, cpu->edx & 0xFFFFu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load8(cpu->esi + cpu->edx + 0xAu);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store8(cpu->eax + cpu->ecx + 0xCu, cpu->edx & 0xFFu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load16(cpu->esi + cpu->edx + 0xBu);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store16(cpu->eax + cpu->ecx + 0xEu, cpu->edx & 0xFFFFu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_06;
    cpu->edx = lift_load16(cpu->esi + cpu->edx + 0xDu);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    lift_store16(cpu->eax + cpu->ecx + 0x10u, cpu->edx & 0xFFFFu);
    cpu->edi = lift_load32(cpu->ebp + 0x34u);
    cpu->ecx = lift_load16(cpu->edi + cpu->eax + 2u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x88u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x84u)) == (uint8_t)(0u)) goto label_0006665C;
    cpu->edx = lift_load32(cpu->ecx + 0x78u);
    lift_store32(cpu->ebp + 0x1D4u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x7Cu);
    lift_store32(cpu->ebp + 0x1D8u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 0x80u);
    lift_store32(cpu->ebp + 0x1DCu, cpu->ecx);
    label_0006665C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46665Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->esi += 0xFu;
    cpu->eax += 0x12u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state))) goto label_00066573;
    label_00066677: cpu->eip = LIFT_CODE_TOKEN_VA(0x466677u);
    { uint64_t l=(uint64_t)(g_sfera_recovered_static_runtime.input_state_a), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00066735;
    cpu->esi = 0u;
    cpu->edx = 0u;
    label_00066690: cpu->eip = LIFT_CODE_TOKEN_VA(0x466690u);
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->edi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000666A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4666A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->edi;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000666A0;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = lift_load8(cpu->edx + cpu->eax + 0x21u);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->ecx + 0x21u, cpu->eax & 0xFFu);
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = lift_load8(cpu->edx + cpu->eax + 0x22u);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->ecx + 0x22u, cpu->eax & 0xFFu);
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = lift_load8(cpu->edx + cpu->eax + 0x20u);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->ecx + 0x20u, cpu->eax & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x50u)) == (uint8_t)(0u)) goto label_00066717;
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = lift_load8(cpu->edx + cpu->eax + 0x23u);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->ecx + 0x25u, cpu->eax & 0xFFu);
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + cpu->eax + 0x24u)) & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store16(cpu->esi + cpu->ecx + 0x26u, cpu->eax & 0xFFFFu);
    cpu->eax = g_sfera_recovered_static_runtime.client_state_04;
    cpu->eax = lift_load8(cpu->edx + cpu->eax + 0x26u);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->ecx + 0x24u, cpu->eax & 0xFFu);
    label_00066717: cpu->eip = LIFT_CODE_TOKEN_VA(0x466717u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edx += 0x27u;
    cpu->esi += 0xACu;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.input_state_a)) goto label_00066690;
    label_00066735: cpu->eip = LIFT_CODE_TOKEN_VA(0x466735u);
    cpu->ecx = g_sfera_static_render_lookup_runtime.sample_state;
    cpu->eax = g_sfera_landscape_map_runtime.material_remap;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x48u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466749u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46674Eu);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.viewport_state;
    cpu->eax = g_sfera_render_sample_runtime.record_base;
    cpu->ecx = lift_load32(cpu->ebp + 0x4Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46675Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466764u);
    cpu->esp += 0x18u;
    if ((uint32_t)(g_sfera_world_load_runtime.packed_variant) == (uint32_t)(0u)) goto label_0006682A;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_window_runtime.scene_record_count) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000667D3;
    cpu->ecx = 0u;
    label_00066780: cpu->eip = LIFT_CODE_TOKEN_VA(0x466780u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_05;
    cpu->edi = lift_load32(cpu->edx + cpu->ecx);
    cpu->eax = lift_load32(cpu->ebp + 0x54u);
    lift_store32(cpu->eax + cpu->ecx, cpu->edi);
    cpu->edi = lift_load32(cpu->edx + cpu->ecx + 4u);
    lift_store32(cpu->eax + cpu->ecx + 4u, cpu->edi);
    cpu->edx = lift_load32(cpu->edx + cpu->ecx + 8u);
    lift_store32(cpu->eax + cpu->ecx + 8u, cpu->edx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_05;
    cpu->edx = lift_load32(cpu->ebp + 0x54u);
    cpu->edi = lift_load32(cpu->ecx + cpu->eax + 0xCu);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0xCu);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 0xCu);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    ++cpu->esi;
    lift_store32(cpu->edx + 0xCu, cpu->eax);
    cpu->ecx += 0x1Cu;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_window_runtime.scene_record_count)) goto label_00066780;
    label_000667D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4667D3u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_process_runtime.packed_record_count) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0006680E;
    cpu->eax = 0u;
    (void)cpu;
    label_000667E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4667E0u);
    cpu->edx = g_sfera_spatial_index_runtime.quadtree_state;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + cpu->edx)) & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->ebp + 0x58u);
    lift_store16(cpu->eax + cpu->ecx, cpu->edx & 0xFFFFu);
    cpu->edx = g_sfera_spatial_index_runtime.quadtree_state;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edx + 2u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->ebp + 0x58u);
    lift_store8(cpu->eax + cpu->ecx + 2u, cpu->edx & 0xFFu);
    ++cpu->esi;
    cpu->eax += 3u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_process_runtime.packed_record_count)) goto label_000667E0;
    label_0006680E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46680Eu);
    cpu->eax = g_sfera_world_load_runtime.packed_variant;
    cpu->edx = g_sfera_scene_control_runtime.packed_section_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x5Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466822u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466827u);
    cpu->esp += 0xCu;
    label_0006682A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46682Au);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.command_enabled)) != (uint8_t)(1u)) goto label_000668A3;
    cpu->ecx = g_sfera_static_render_lookup_runtime.packed_format_code;
    cpu->edx = g_sfera_recovered_static_runtime.render_state_10;
    cpu->eax = lift_load32(cpu->ebp + 0x64u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46684Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46684Fu);
    cpu->ecx = 0u;
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.render_state_07) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_000668A3;
    cpu->eax = 0u;
    cpu->edi = cpu->edi;
    label_00066860: cpu->eip = LIFT_CODE_TOKEN_VA(0x466860u);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags;
    cpu->esi = lift_load16(cpu->eax + cpu->esi);
    cpu->edx = lift_load32(cpu->ebp + 0x68u);
    lift_store16(cpu->eax + cpu->edx, cpu->esi & 0xFFFFu);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags;
    cpu->esi = lift_load16(cpu->eax + cpu->esi + 2u);
    cpu->edx = lift_load32(cpu->ebp + 0x68u);
    lift_store16(cpu->eax + cpu->edx + 2u, cpu->esi & 0xFFFFu);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_flags;
    cpu->esi = lift_load16(cpu->eax + cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->ebp + 0x68u);
    lift_store16(cpu->eax + cpu->edx + 4u, cpu->esi & 0xFFFFu);
    ++cpu->ecx;
    cpu->eax += 6u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.render_state_07)) goto label_00066860;
    label_000668A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4668A3u);
    if ((uint32_t)(g_sfera_world_load_runtime.packed_variant) != (uint32_t)(0u)) goto label_00066A09;
    { uint64_t l=(uint64_t)(g_sfera_recovered_static_runtime.input_state_a), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00066A09;
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000668D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4668D0u);
    cpu->eax = g_sfera_client_main_scalar_runtime.state_05;
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    cpu->edx = lift_load32(cpu->eax + cpu->esi);
    lift_store32(cpu->edi + cpu->ecx + 0x84u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + cpu->esi + 4u);
    cpu->eax += cpu->esi;
    cpu->ecx = (uint32_t)(cpu->edi + cpu->ecx + 0x84u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x14u);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    cpu->eax = (uint32_t)(cpu->edi + cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + 0x24u);
    cpu->ecx = (uint32_t)(cpu->eax + 0x84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46691Eu); lift_push32(cpu, r); sfera_sub_004259C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_client_main_scalar_runtime.state_05;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->eax + 0xCu));
    cpu->edx = lift_load32(cpu->ebp + 0x3Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + cpu->eax))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + cpu->eax + 4u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + cpu->eax + 8u))));
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx + 0x9Cu);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->eax = g_sfera_client_main_scalar_runtime.state_05;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + cpu->eax))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + cpu->eax + 4u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + cpu->eax + 8u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4669D9u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = lift_load32(cpu->ebp + 0x3Cu);
    ++cpu->eax;
    lift_store_f32(cpu->edi + cpu->edx + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esi += 0x18u;
    cpu->edi += 0xACu;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.input_state_a)) goto label_000668D0;
    label_00066A09: cpu->eip = LIFT_CODE_TOKEN_VA(0x466A09u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x6Cu)) != (uint32_t)(2u)) goto label_00066A51;
    cpu->eax = g_sfera_main_aux_runtime.resource_word;
    cpu->ecx = g_sfera_landscape_render_runtime.source_section_base;
    cpu->edx = lift_load32(cpu->ebp + 0x1A0u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466A2Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466A2Fu);
    cpu->eax = g_sfera_landscape_render_runtime.source_record_count;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_03;
    cpu->edx = lift_load32(cpu->ebp + 0x1A4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x466A49u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466A4Eu);
    cpu->esp += 0x18u;
    label_00066A51: cpu->eip = LIFT_CODE_TOKEN_VA(0x466A51u);
    cpu->esi = 0u;
    if ((uint32_t)(g_sfera_world_load_runtime.packed_variant) == (uint32_t)(cpu->esi)) goto label_00066B7D;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.input_state_a) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00066B7D;
    cpu->edi = native_function_address32(&::_stricmp);
    label_00066A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x466A80u);
    cpu->eax = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->eax + 0x28u, 0xFFu);
    lift_store32(cpu->esp + 0x18u, 0u);
    label_00066A90: cpu->eip = LIFT_CODE_TOKEN_VA(0x466A90u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uintptr_t)(cpu->ecx == 0u ? "back_swo" : cpu->ecx == 1u ? "back_ara" : cpu->ecx == 2u ? "back_axe" : cpu->ecx == 3u ? "back_spe" : "back_cam");
    cpu->eax = lift_load32(cpu->ebp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66AA4u), LIFT_CODE_TOKEN_RVA(0x66AA2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466AA4u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00066AB6;
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x18u)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx + 0x28u, cpu->edx & 0xFFu);
    label_00066AB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x466AB6u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(5u)) goto label_00066A90;
    cpu->eax = lift_load32(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;
    lift_push32(cpu, (uintptr_t)"finl_m1o1"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66AD1u), LIFT_CODE_TOKEN_RVA(0x66ACFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466AD1u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00066AEC;
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, (uintptr_t)"fingl_m1o1"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66AE5u), LIFT_CODE_TOKEN_RVA(0x66AE3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466AE5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00066AF4;
    label_00066AEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x466AECu);
    cpu->edx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->edx + 0x28u, 0x64u);
    label_00066AF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x466AF4u);
    cpu->eax = lift_load32(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;
    lift_push32(cpu, (uintptr_t)"finr_m1o1"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66B01u), LIFT_CODE_TOKEN_RVA(0x66AFFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466B01u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00066B1C;
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, (uintptr_t)"fingr_m1o1"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66B15u), LIFT_CODE_TOKEN_RVA(0x66B13u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466B15u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00066B24;
    label_00066B1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x466B1Cu);
    cpu->edx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->edx + 0x28u, 0x65u);
    label_00066B24: cpu->eip = LIFT_CODE_TOKEN_VA(0x466B24u);
    cpu->eax = lift_load32(cpu->ebp + 0x3Cu);
    cpu->eax += cpu->esi;
    lift_push32(cpu, (uintptr_t)"neck_m1o1"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66B31u), LIFT_CODE_TOKEN_RVA(0x66B2Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466B31u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00066B40;
    cpu->ecx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->ecx + 0x28u, 0x66u);
    label_00066B40: cpu->eip = LIFT_CODE_TOKEN_VA(0x466B40u);
    cpu->edx = lift_load32(cpu->ebp + 0x3Cu);
    lift_push32(cpu, 4u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, (uintptr_t)"head"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_strnicmp), LIFT_CODE_TOKEN_VA(0x466B4Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466B53u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00066B62;
    cpu->eax = lift_load32(cpu->ebp + 0x3Cu);
    lift_store8(cpu->esi + cpu->eax + 0x28u, 0x67u);
    label_00066B62: cpu->eip = LIFT_CODE_TOKEN_VA(0x466B62u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->esi += 0xACu;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.input_state_a)) goto label_00066A80;
    label_00066B7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x466B7Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xC4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x88u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xC8u));
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x8Cu))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xCCu));
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x90u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x88u));
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xACu))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x8Cu));
    lift_store32(cpu->esp + 0x5Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xB0u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x90u));
    lift_store32(cpu->esp + 0x60u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xB4u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store32(cpu->esp + 0x64u, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00066CC7;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466C3Bu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466C56u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466C6Bu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00066CD1;
    label_00066CC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x466CC7u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00066CD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x466CD1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466CDEu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (4.7123894691467285) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466CF9u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f64(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466D12u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x20u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466D33u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->esi = (uint32_t)(cpu->ebp + 0x148u);
    lift_x87_set(cpu, 0u, (1.5707964897155762) - (lift_x87_get(cpu, 0u)));
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x88u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x466D79u); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xDCu);
    cpu->edx = lift_load32(cpu->ebp + 0xE0u);
    cpu->eax = lift_load32(cpu->ebp + 0xE4u);
    lift_store32(cpu->ebp + 0x188u, cpu->ecx);
    lift_store32(cpu->ebp + 0x18Cu, cpu->edx);
    lift_store32(cpu->ebp + 0x190u, cpu->eax);
    cpu->edi = (uint32_t)(cpu->esp + 0x7Cu);
    cpu->edi &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0x6Cu, cpu->edi);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x188u));
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x190u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0x188u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0x18Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0x190u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x6Cu)) != (uint32_t)(0u)) goto label_00066E8C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x7Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x70u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x80u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x74u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00066E68;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00066E6A;
    label_00066E68: cpu->eip = LIFT_CODE_TOKEN_VA(0x466E68u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00066E6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x466E6Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x84u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0x78u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00066ECC;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00066ED0;
    label_00066E8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x466E8Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x188u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00066EB3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18Cu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00066EB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x466EB3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x190u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00066ED0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x190u));
    label_00066ECC: cpu->eip = LIFT_CODE_TOKEN_VA(0x466ECCu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00066ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x466ED0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->ebp + 0x198u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x198u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.05000000074505806);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00067439;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00066F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00066F00;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00066F43;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00066F10: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00066F10;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_00066F36;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00066F3B;
    label_00066F36: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F36u);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00066F3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F3Bu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->ecx);
    goto label_00066F4D;
    label_00066F43: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F43u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_00066F4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F4Du);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x466F4Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466F53u);
    cpu->edi = native_function_address32(&::fputs);
    cpu->ebx = native_function_address32(&::fflush);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00066F87;
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66F70u), LIFT_CODE_TOKEN_RVA(0x66F6Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466F70u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x66F73u), LIFT_CODE_TOKEN_RVA(0x66F71u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466F73u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x466F74u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466F7Au);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00066F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F87u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_00066F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x466F90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00066F90;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00066FD3;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00066FA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x466FA0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00066FA0;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_00066FC6;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00066FCB;
    label_00066FC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x466FC6u);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00066FCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x466FCBu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->eax);
    goto label_00066FDD;
    label_00066FD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x466FD3u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_00066FDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x466FDDu);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x466FDDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466FE3u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0006700B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x66FF4u), LIFT_CODE_TOKEN_RVA(0x66FF2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466FF4u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x66FF7u), LIFT_CODE_TOKEN_RVA(0x66FF5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x466FF7u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x466FF8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x466FFEu);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_0006700B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46700Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x88u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00067020: cpu->eip = LIFT_CODE_TOKEN_VA(0x467020u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067020;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00067063;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00067030: cpu->eip = LIFT_CODE_TOKEN_VA(0x467030u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067030;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_00067056;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006705B;
    label_00067056: cpu->eip = LIFT_CODE_TOKEN_VA(0x467056u);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_0006705B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46705Bu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->ecx);
    goto label_0006706D;
    label_00067063: cpu->eip = LIFT_CODE_TOKEN_VA(0x467063u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006706D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46706Du);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x46706Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x467073u);
    cpu->edi = native_function_address32(&::fprintf);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000670AB;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x67094u), LIFT_CODE_TOKEN_RVA(0x67092u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467094u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x67097u), LIFT_CODE_TOKEN_RVA(0x67095u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467097u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467098u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46709Eu);
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_000670AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4670ABu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xDCu));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000670C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4670C0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000670C0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00067103;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000670D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4670D0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000670D0;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_000670F6;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000670FB;
    label_000670F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4670F6u);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000670FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4670FBu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->edx);
    goto label_0006710D;
    label_00067103: cpu->eip = LIFT_CODE_TOKEN_VA(0x467103u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006710D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46710Du);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x46710Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x467113u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00067145;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x6712Eu), LIFT_CODE_TOKEN_RVA(0x6712Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46712Eu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x67131u), LIFT_CODE_TOKEN_RVA(0x6712Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467131u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467132u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x467138u);
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00067145: cpu->eip = LIFT_CODE_TOKEN_VA(0x467145u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x8Cu));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00067157: cpu->eip = LIFT_CODE_TOKEN_VA(0x467157u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067157;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00067197;
    cpu->eax = 0u;
    label_00067164: cpu->eip = LIFT_CODE_TOKEN_VA(0x467164u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067164;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_0006718A;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006718F;
    label_0006718A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46718Au);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_0006718F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46718Fu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->eax);
    goto label_000671A1;
    label_00067197: cpu->eip = LIFT_CODE_TOKEN_VA(0x467197u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_000671A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4671A1u);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4671A1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4671A7u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000671D9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x671C2u), LIFT_CODE_TOKEN_RVA(0x671C0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4671C2u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x671C5u), LIFT_CODE_TOKEN_RVA(0x671C3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4671C5u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4671C6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4671CCu);
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_000671D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4671D9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE0u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000671F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4671F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000671F0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00067233;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00067200: cpu->eip = LIFT_CODE_TOKEN_VA(0x467200u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067200;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_00067226;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006722B;
    label_00067226: cpu->eip = LIFT_CODE_TOKEN_VA(0x467226u);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_0006722B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46722Bu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->ecx);
    goto label_0006723D;
    label_00067233: cpu->eip = LIFT_CODE_TOKEN_VA(0x467233u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006723D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46723Du);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x46723Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x467243u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00067275;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x6725Eu), LIFT_CODE_TOKEN_RVA(0x6725Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46725Eu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x67261u), LIFT_CODE_TOKEN_RVA(0x6725Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467261u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467262u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x467268u);
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00067275: cpu->eip = LIFT_CODE_TOKEN_VA(0x467275u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x90u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00067287: cpu->eip = LIFT_CODE_TOKEN_VA(0x467287u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067287;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000672C7;
    cpu->eax = 0u;
    label_00067294: cpu->eip = LIFT_CODE_TOKEN_VA(0x467294u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067294;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_000672BA;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000672BF;
    label_000672BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4672BAu);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000672BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4672BFu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->edx);
    goto label_000672D1;
    label_000672C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4672C7u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_000672D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4672D1u);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4672D1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4672D7u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00067309;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x672F2u), LIFT_CODE_TOKEN_RVA(0x672F0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4672F2u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x672F5u), LIFT_CODE_TOKEN_RVA(0x672F3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4672F5u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4672F6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4672FCu);
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_00067309: cpu->eip = LIFT_CODE_TOKEN_VA(0x467309u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE4u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00067320: cpu->eip = LIFT_CODE_TOKEN_VA(0x467320u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067320;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00067363;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00067330: cpu->eip = LIFT_CODE_TOKEN_VA(0x467330u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00067330;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_00067356;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006735B;
    label_00067356: cpu->eip = LIFT_CODE_TOKEN_VA(0x467356u);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_0006735B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46735Bu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->eax);
    goto label_0006736D;
    label_00067363: cpu->eip = LIFT_CODE_TOKEN_VA(0x467363u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0006736D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46736Du);
    cpu->ebp = native_function_address32(&::fopen);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x67375u), LIFT_CODE_TOKEN_RVA(0x67373u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467375u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000673A7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x67390u), LIFT_CODE_TOKEN_RVA(0x6738Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467390u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x67393u), LIFT_CODE_TOKEN_RVA(0x67391u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467393u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467394u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46739Au);
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_000673A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4673A7u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_000673B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4673B0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000673B0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000673F3;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000673C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4673C0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x6Cu, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000673C0;
    if ((uint32_t)(g_sfera_log_runtime.files[0].truncate_on_first_write) != (uint32_t)(1u)) goto label_000673E6;
    { uint64_t l=(uint64_t)(g_sfera_log_runtime.files[0].has_written), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000673EB;
    label_000673E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4673E6u);
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000673EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4673EBu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->ecx);
    goto label_000673FD;
    label_000673F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4673F3u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_000673FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4673FDu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x673FFu), LIFT_CODE_TOKEN_RVA(0x673FDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4673FFu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0006742B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x46740Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x467414u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x67417u), LIFT_CODE_TOKEN_RVA(0x67415u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467417u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x467418u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46741Eu);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_0006742B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46742Bu);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"Object has size < MIN_OBJECT_SIZE: ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67439u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_00067439: cpu->eip = LIFT_CODE_TOKEN_VA(0x467439u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00067675;
    lift_x87_push(cpu, 0.0);
    cpu->edi = 0u;
    lift_x87_push(cpu, 0.0);
    label_00067454: cpu->eip = LIFT_CODE_TOKEN_VA(0x467454u);
    cpu->edx = lift_load32(cpu->ebp + 0x34u);
    cpu->ecx = lift_load16(cpu->edi + cpu->edx + 2u);
    cpu->esi = lift_load16(cpu->edi + cpu->edx + 8u);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->eax + 0xAu))) goto label_000674B4;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x88u);
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->eax += cpu->eax;
    goto label_00067491;
    label_0006748D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46748Du);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_00067491: cpu->eip = LIFT_CODE_TOKEN_VA(0x467491u);
    cpu->esi = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->esi += cpu->edx;
    cpu->edx = lift_load32(cpu->ebp + 0x24u);
    lift_store32(cpu->eax + cpu->edx + 0x20u, cpu->esi);
    cpu->edx = lift_load32(cpu->ebp + 0x34u);
    cpu->edx = lift_load16(cpu->edi + cpu->edx + 0xAu);
    ++cpu->ecx;
    cpu->eax += 0x24u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->edx)) goto label_0006748D;
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    label_000674B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4674B4u);
    cpu->eax = lift_load32(cpu->ebp + 0x34u);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->eax);
    cpu->eax = lift_load8(cpu->ecx);
    cpu->eax &= 0x7Fu;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xACu);
    cpu->eax += lift_load32(cpu->ebp + 0x3Cu);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Fu)) goto label_00067659;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x75u)) goto label_00067530;
    cpu->eax = 0u;
    cpu->edx = 0u;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->ecx + 0xAu))) goto label_00067659;
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    lift_x87_push(cpu, (double)-1.0f);
    cpu->ecx += cpu->ecx;
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += cpu->ecx;
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u));
    label_00067500: cpu->eip = LIFT_CODE_TOKEN_VA(0x467500u);
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    cpu->esi = lift_load32(cpu->esp + 0x5Cu);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0xCu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->ebp + 0x34u);
    cpu->eax = lift_load16(cpu->edi + cpu->eax + 0xAu);
    ++cpu->edx;
    cpu->ecx += 0x24u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_00067500;
    goto label_00067659;
    label_00067530: cpu->eip = LIFT_CODE_TOKEN_VA(0x467530u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x73u)) goto label_00067659;
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->ecx + 0xAu))) goto label_00067659;
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += cpu->eax;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store_f64(cpu->esp + 0x50u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    label_00067561: cpu->eip = LIFT_CODE_TOKEN_VA(0x467561u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += lift_load32(cpu->ebp + 0x24u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x50u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4675B5u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000675F4;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    goto label_0006762E;
    label_000675F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4675F4u);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, 0.0);
    label_0006762E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46762Eu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ebp + 0x34u);
    cpu->edx = lift_load16(cpu->edi + cpu->ecx + 0xAu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_00067561;
    lift_x87_push(cpu, 0.0);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00067659: cpu->eip = LIFT_CODE_TOKEN_VA(0x467659u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 0x12u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.interface_state))) goto label_00067454;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00067675: cpu->eip = LIFT_CODE_TOKEN_VA(0x467675u);
    cpu->ecx = g_sfera_landscape_map_runtime.material_remap;
    lift_push32(cpu, 0x234Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46768Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x234Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46769Bu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 2u);
    cpu->esi = (uint32_t)(cpu->ebp + 0x1C4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"dg_type"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4676B9u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000676C6;
    lift_store32(cpu->esi, 0xFFFFFFFFu);
    goto label_000676CF;
    label_000676C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4676C6u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x676CFu); lift_push32(cpu, r); sfera_sub_004255F0(cpu,r); if (cpu->eip != r) return; }
    label_000676CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4676CFu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xE0u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004676F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4676F0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_0006774E;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store32(cpu->esp + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467739u); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467743u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    label_0006774E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46774Eu);
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00067762;
    cpu->ecx = (uint32_t)(uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67762u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00067762: cpu->eip = LIFT_CODE_TOKEN_VA(0x467762u);

    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46776Eu);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->esi = 0u;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00067841;
    label_0006778A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46778Au);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00067798;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67798u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00067798: cpu->eip = LIFT_CODE_TOKEN_VA(0x467798u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_000677AC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x677ACu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000677AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4677ACu);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_000677BB;
    ++cpu->esi;
    goto label_0006778A;
    label_000677BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4677BBu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000677C9;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x677C9u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000677C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4677C9u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_000677DD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x677DDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000677DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4677DDu);
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->ebx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000677F4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x677F4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000677F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4677F4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00067808;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67808u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067808: cpu->eip = LIFT_CODE_TOKEN_VA(0x467808u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->edx + 0x3Cu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xFFFFFC18u);
    cpu->eax -= lift_load32(cpu->ecx + 0x6DA4u);
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]), cpu->esi);
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0]), cpu->eax);
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count))) goto label_0006778A;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_00067841: cpu->eip = LIFT_CODE_TOKEN_VA(0x467841u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    --cpu->edx;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46784Fu); lift_push32(cpu, r); sfera_sub_0044F940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_000678AD;
    label_00067859: cpu->eip = LIFT_CODE_TOKEN_VA(0x467859u);
    cpu->esi = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006786E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6786Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006786E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46786Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00067882;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67882u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067882: cpu->eip = LIFT_CODE_TOKEN_VA(0x467882u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(1u)) goto label_000678A4;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_000678A4;
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x10u))) goto label_000678A4;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x14u))) goto label_000678A4;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x18u))) goto label_000678C3;
    label_000678A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4678A4u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count))) goto label_00067859;
    label_000678AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4678ADu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_000678C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4678C3u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x1Cu))) goto label_000678F2;
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x20u))) goto label_000678F2;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x24u))) goto label_000678F2;
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x28u))) goto label_000678F2;
    cpu->eax = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_000678F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4678F2u);
    cpu->eax = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00467910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467910u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->edx, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467926u); lift_push32(cpu, r); sfera_sub_004676F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00067936;
    cpu->esi = 0u - (uint64_t)(cpu->esi);
    lift_store32(cpu->edi, cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00067936: cpu->eip = LIFT_CODE_TOKEN_VA(0x467936u);
    lift_store32(cpu->edi, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_0006794C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6794Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006794C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46794Cu);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46795Bu); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467969u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ebx = 0u;
    cpu->ebp = (uint32_t)(cpu->esi + 0x44u);
    cpu->edi = cpu->edi;
    label_00067980: cpu->eip = LIFT_CODE_TOKEN_VA(0x467980u);
    cpu->edi = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00067A49;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006799A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6799Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006799A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46799Au);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_000679AE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x679AEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000679AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4679AEu);
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx = lift_load32(cpu->esi + 0x1Cu);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x34u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00067A47;
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x34u))));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_00067A49;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    cpu->eax += cpu->edx;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x38u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00067A47;
    cpu->ecx = lift_load32(cpu->ecx + 0x18u);
    cpu->ecx += cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x38u))));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_00067A49;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00067A47: cpu->eip = LIFT_CODE_TOKEN_VA(0x467A47u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00067A49: cpu->eip = LIFT_CODE_TOKEN_VA(0x467A49u);
    ++cpu->ebx;
    cpu->ebp += 4u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x1B58u)) goto label_00067980;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00467A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467A70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_00067ACC;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store32(cpu->esp + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467AB7u); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467AC1u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    label_00067ACC: cpu->eip = LIFT_CODE_TOKEN_VA(0x467ACCu);
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00067AE0;
    cpu->ecx = (uint32_t)(uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67AE0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00067AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x467AE0u);

    reinterpret_cast<CCursor*>(cpu->ecx)->cursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467AE7u);
    if ((uint32_t)(g_sfera_recovered_static_runtime.interaction_enabled) == (uint32_t)(0u)) goto label_00067CCD;
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x)))));
    cpu->eax = g_sfera_window_runtime.active_window_index;
    lift_x87_push(cpu, 1.5); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y))))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00067B30;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467B22u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->setVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467B2Bu);
    cpu->eax = g_sfera_window_runtime.active_window_index;
    label_00067B30: cpu->eip = LIFT_CODE_TOKEN_VA(0x467B30u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00067B56;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state)) & (2u)) == 0u) goto label_00067CBF;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467B47u); lift_push32(cpu, r); sfera_sub_004676F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    g_sfera_window_runtime.active_window_index = (uint32_t)(cpu->eax);
    goto label_00067CBF;
    label_00067B56: cpu->eip = LIFT_CODE_TOKEN_VA(0x467B56u);
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state)) & (2u)) == 0u) goto label_00067CB5;
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00067B78;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467B73u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_window_runtime.active_window_index;
    label_00067B78: cpu->eip = LIFT_CODE_TOKEN_VA(0x467B78u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00067B91;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467B8Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_window_runtime.active_window_index;
    label_00067B91: cpu->eip = LIFT_CODE_TOKEN_VA(0x467B91u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00067CBF;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) != (uint32_t)(1u)) goto label_00067CBF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    cpu->edx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edx -= lift_load32(cpu->esi + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0xCu))));
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    cpu->edx = lift_load32(cpu->esi + 0x30u);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    cpu->edx -= lift_load32(cpu->esi + 0x28u);
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467BE7u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467BF5u);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x34u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00067C14;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x34u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467C0Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_00067C14: cpu->eip = LIFT_CODE_TOKEN_VA(0x467C14u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x38u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00067C33;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x38u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467C2Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_00067C35;
    label_00067C33: cpu->eip = LIFT_CODE_TOKEN_VA(0x467C33u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00067C35: cpu->eip = LIFT_CODE_TOKEN_VA(0x467C35u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00067C66;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esp + 0x10u))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467C5Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_00067C68;
    label_00067C66: cpu->eip = LIFT_CODE_TOKEN_VA(0x467C66u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00067C68: cpu->eip = LIFT_CODE_TOKEN_VA(0x467C68u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00067C99;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esp + 0x14u))))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467C90u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_00067C9B;
    label_00067C99: cpu->eip = LIFT_CODE_TOKEN_VA(0x467C99u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00067C9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x467C9Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467CA0u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467CB3u);
    goto label_00067CBF;
    label_00067CB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x467CB5u);
    g_sfera_window_runtime.active_window_index = (uint32_t)(0xFFFFFFFFu);
    label_00067CBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x467CBFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467CC4u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->show(cpu);
    label_00067CCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x467CCDu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((*(uint8_t*)(void*)&g_sfera_recovered_static_runtime.interaction_input_flags)) & 0xFFu);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00067CE9;
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) != 0u) goto label_00067CE9;
    cpu->edi = 1u;
    label_00067CE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x467CE9u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00067CF7;
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_00067CF7;
    cpu->edi = (uint32_t)(cpu->eax + 2u);
    goto label_00067CFF;
    label_00067CF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x467CF7u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00067E4B;
    label_00067CFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x467CFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467D0Cu); lift_push32(cpu, r); sfera_sub_00467910(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_recovered_static_runtime.interaction_enabled) != (uint32_t)(0u)) goto label_00067D21;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0xCu, 0xFFFFFFFFu);
    goto label_00067D33;
    label_00067D21: cpu->eip = LIFT_CODE_TOKEN_VA(0x467D21u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00067D33;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67D33u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00067D33: cpu->eip = LIFT_CODE_TOKEN_VA(0x467D33u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00067D47;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67D47u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067D47: cpu->eip = LIFT_CODE_TOKEN_VA(0x467D47u);
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x6E08u)) >= (int32_t)(uint32_t)(0xAu)) goto label_00067E4B;
    cpu->edx = lift_load32(cpu->eax + 0x6DD8u);
    cpu->ecx = lift_load32(cpu->eax + 0x6E00u);
    lift_store32(cpu->eax + 0x6DDCu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DD4u);
    lift_store32(cpu->eax + 0x6E04u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DFCu);
    lift_store32(cpu->eax + 0x6DD8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DD0u);
    lift_store32(cpu->eax + 0x6E00u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DF8u);
    lift_store32(cpu->eax + 0x6DD4u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DCCu);
    lift_store32(cpu->eax + 0x6DFCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DF4u);
    lift_store32(cpu->eax + 0x6DD0u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DC8u);
    lift_store32(cpu->eax + 0x6DF8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DF0u);
    lift_store32(cpu->eax + 0x6DCCu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DC4u);
    lift_store32(cpu->eax + 0x6DF4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DECu);
    lift_store32(cpu->eax + 0x6DC8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DC0u);
    lift_store32(cpu->eax + 0x6DF0u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DE8u);
    lift_store32(cpu->eax + 0x6DC4u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DBCu);
    lift_store32(cpu->eax + 0x6DECu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DE4u);
    lift_store32(cpu->eax + 0x6DC0u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x6DB8u);
    lift_store32(cpu->eax + 0x6DE8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x6DE0u);
    lift_store32(cpu->eax + 0x6DBCu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 0x6DE4u, cpu->ecx);
    lift_store32(cpu->eax + 0x6E08u, (uint64_t)(lift_load32(cpu->eax + 0x6E08u)) + 1u);
    lift_store32(cpu->eax + 0x6DB8u, cpu->edx);
    lift_store32(cpu->eax + 0x6DE0u, cpu->edi);
    label_00067E4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x467E4Bu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    g_sfera_recovered_static_runtime.interaction_input_flags = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00467E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x467E70u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->ebp = cpu->edx;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00067EA9;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00067E9F;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67E9Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067E9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x467E9Fu);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(cpu->ebx)) goto label_00067ED3;
    label_00067EA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x467EA9u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->edi;
    label_00067EB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x467EB5u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00067EB5;
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(uintptr_t)"create_sprite: wrong window handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467ED1u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    label_00067ED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x467ED3u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00067EE1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67EE1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00067EE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x467EE1u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00067EF5;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67EF5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067EF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x467EF5u);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u))) == (uint32_t)(0u)) goto label_00067F04;
    ++cpu->ebx;
    goto label_00067ED3;
    label_00067F04: cpu->eip = LIFT_CODE_TOKEN_VA(0x467F04u);
    lift_push32(cpu, 0x30B0u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xE84u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467F18u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00067F28;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67F28u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00067F28: cpu->eip = LIFT_CODE_TOKEN_VA(0x467F28u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_00067F3C;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67F3Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x467F3Cu);
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u), cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esi, 1u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x467F57u); lift_push32(cpu, r); sfera_sub_0045DC60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x10u, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebp + 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x1Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x18u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00067F9A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67F9Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00067F9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x467F9Au);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00067FAE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67FAEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067FAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x467FAEu);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->edx += lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0xE48u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00067FD1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67FD1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00067FD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x467FD1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00067FE5;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x67FE5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00067FE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x467FE5u);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx += lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esi + 0xE54u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0xE4Cu, cpu->edx);
    lift_store32(cpu->esi + 0xE50u, cpu->ebp);
    lift_store32(cpu->esi + 0xE80u, cpu->ecx);
    cpu->esi -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00068020: cpu->eip = LIFT_CODE_TOKEN_VA(0x468020u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax + 0xE58u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00068020;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.projection_sample_count, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count)) + 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46803Bu); lift_push32(cpu, r); sfera_sub_0045EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00468050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468050u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 1u;
    cpu->edi = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468074u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(1u)) goto label_0006808C;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6808Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006808C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46808Cu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00068108;
    label_00068098: cpu->eip = LIFT_CODE_TOKEN_VA(0x468098u);
    cpu->ecx = lift_load32(cpu->eax + 0x14Cu);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x150u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x154u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(1u)) goto label_000680CA;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x680CAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000680CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4680CAu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00068150;
    label_000680D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4680D7u);
    cpu->ecx = lift_load32(cpu->eax + 0x158u);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x15Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x408u);
    lift_store32(cpu->edi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x160u);
    lift_store32(cpu->edi + 8u, cpu->eax);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_00068108: cpu->eip = LIFT_CODE_TOKEN_VA(0x468108u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_00068098;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468120u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00068129;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00068129: cpu->eip = LIFT_CODE_TOKEN_VA(0x468129u);
    lift_push32(cpu, 0x38DEu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46813Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x468144u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68150u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00068150: cpu->eip = LIFT_CODE_TOKEN_VA(0x468150u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_000680D7;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46816Cu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00068175;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00068175: cpu->eip = LIFT_CODE_TOKEN_VA(0x468175u);
    lift_push32(cpu, 0x38DFu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46818Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x468190u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46819Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x46819Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004681A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4681A0u);
    cpu->esp -= 0x78u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_store32(cpu->esp + 0xCu, 3u);
    lift_x87_push(cpu, 255.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) / (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x90u))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 4u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esp + 0x5Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46827Du); lift_push32(cpu, r); sfera_sub_004D8C10(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity) > (int32_t)(uint32_t)(0u)) goto label_00068292;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68292u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068292: cpu->eip = LIFT_CODE_TOKEN_VA(0x468292u);
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(1u)) goto label_000682FF;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(8u)) goto label_000682CF;
    lift_push32(cpu, 0x3953u); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4682BCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4682C2u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x682CFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000682CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4682CFu);
    if ((int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity) > (int32_t)(uint32_t)(0u)) goto label_000682E4;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x682E4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000682E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4682E4u);
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 1u);
    lift_store32(cpu->edx, 1u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x682FFu); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_000682FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4682FFu);
    cpu->esp += 0x78u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00468310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468310u);
    cpu->esp -= 0x108u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(1u)) goto label_0006833D;
    cpu->edx = (uint32_t)(cpu->edi + 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6833Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006833D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46833Du);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0]));
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = 0u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    g_sfera_client_main_scalar_runtime.counter_01 = (uint32_t)(cpu->ecx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000683AE;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][1]));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000683AE;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][2]));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000683AE;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][3]));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00068738;
    label_000683AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4683AEu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_recovered_static_runtime.client_state_02) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_0006857C;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000683C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4683C1u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000683CF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x683CFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000683CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4683CFu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_000683E3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x683E3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000683E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4683E3u);
    cpu->ecx = g_sfera_light_runtime.handles.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_000683F2;
    ++cpu->edi;
    goto label_000683C1;
    label_000683F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4683F2u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00068400;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68400u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068400: cpu->eip = LIFT_CODE_TOKEN_VA(0x468400u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.handles.capacity)) goto label_00068414;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68414u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068414: cpu->eip = LIFT_CODE_TOKEN_VA(0x468414u);
    cpu->edx = g_sfera_light_runtime.handles.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    cpu->ecx = (uint32_t)(cpu->esi + 0x20u);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->ecx, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esi + 0x34u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0xB4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4684B4u); lift_push32(cpu, r); sfera_sub_004259C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(cpu->esp + 0xB8u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4684C7u); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00068541;
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_01;
    cpu->ebx = cpu->eax;
    ++cpu->eax;
    g_sfera_client_main_scalar_runtime.counter_01 = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_000684E6;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x684E6u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000684E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4684E6u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_000684FA;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x684FAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000684FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4684FAu);
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u), cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00068541: cpu->eip = LIFT_CODE_TOKEN_VA(0x468541u);
    ++cpu->ebp;
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_recovered_static_runtime.client_state_02)) goto label_000683C1;
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_01;
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(1u)) goto label_0006856A;
    cpu->edx = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468564u); lift_push32(cpu, r); sfera_sub_00456100(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_client_main_scalar_runtime.counter_01;
    label_0006856A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46856Au);
    lift_x87_push(cpu, 0.0);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(0x1Eu)) goto label_0006857C;
    cpu->ecx = 0x1Eu;
    g_sfera_client_main_scalar_runtime.counter_01 = (uint32_t)(cpu->ecx);
    label_0006857C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46857Cu);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esp + 0x4Cu, 1u);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x8Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x90u, cpu->eax);
    lift_store32(cpu->esp + 0x94u, cpu->edx);
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0006871F;
    cpu->esi = 1u;
    cpu->ebx = (uint32_t)(cpu->esi + 3u);
    label_00068615: cpu->eip = LIFT_CODE_TOKEN_VA(0x468615u);
    cpu->edi = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00068626;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68626u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068626: cpu->eip = LIFT_CODE_TOKEN_VA(0x468626u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_0006863A;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6863Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006863A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46863Au);
    cpu->eax = g_sfera_light_runtime.visible_handles.data;
    cpu->eax = lift_load32(cpu->ebx + cpu->eax + 0xFFFFFFFCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_push(cpu, 0.003921568859368563);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x80u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x84u, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x88u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46869Cu); lift_push32(cpu, r); sfera_sub_004D8C10(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000686AA;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x686AAu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000686AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4686AAu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_000686BE;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x686BEu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000686BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4686BEu);
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->ebx + cpu->eax)) == (uint32_t)(0u)) goto label_0006870C;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.light_update_counter, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000686DD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x686DDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000686DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4686DDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_000686F1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x686F1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000686F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4686F1u);
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    lift_store32(cpu->ebx + cpu->ecx, 0u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6870Cu); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_0006870C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46870Cu);
    ++cpu->esi;
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    cpu->ebx += 4u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_01)) goto label_00068615;
    label_0006871F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46871Fu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x108u;
    lift_return(cpu, 0u, stop_address); return;
    label_00068738: cpu->eip = LIFT_CODE_TOKEN_VA(0x468738u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x108u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00468750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468750u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46875Cu); lift_push32(cpu, r); sfera_sub_0045DA60(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006876A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6876Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006876A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46876Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0006877E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6877Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006877E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46877Eu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ebx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468795u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x50u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x10u, 7u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000687C4;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x38u)) <= (int32_t)(uint32_t)(2u)) goto label_000687C4;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x194u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000687C4;
    lift_store32(cpu->esp + 0x10u, 0x1Eu);
    label_000687C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4687C4u);
    cpu->eax = 0u;
    cpu->ebp = 0u;
    g_sfera_client_main_scalar_runtime.counter_03 = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_01) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00068907;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000687E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4687E0u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_000687EE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x687EEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000687EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4687EEu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_light_runtime.visible_handles.capacity)) goto label_00068802;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68802u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068802: cpu->eip = LIFT_CODE_TOKEN_VA(0x468802u);
    cpu->edx = g_sfera_light_runtime.visible_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x7Cu));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x2Cu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000688EC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x80u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x30u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000688EC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x84u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x34u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000688EC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x88u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x20u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000688EC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x8Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x24u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000688EC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x90u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x28u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_000688EC;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00068892;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68892u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068892: cpu->eip = LIFT_CODE_TOKEN_VA(0x468892u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(g_sfera_light_runtime.visible_handles.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000688A6;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.visible_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x688A6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000688A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4688A6u);
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_03;
    cpu->edx = g_sfera_light_runtime.visible_handles.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx -= cpu->eax;
    cpu->edi = (uint32_t)(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][0]));
    cpu->ecx = 0xFu;
    lift_movs32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 1u);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]), cpu->ecx);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_active[0]), 0u);
    ++cpu->eax;
    g_sfera_client_main_scalar_runtime.counter_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000688FE;
    goto label_000688F1;
    label_000688EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4688ECu);
    cpu->eax = g_sfera_client_main_scalar_runtime.counter_03;
    label_000688F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4688F1u);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_01)) goto label_000687E0;
    label_000688FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4688FEu);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(7u)) goto label_000689AA;
    label_00068907: cpu->eip = LIFT_CODE_TOKEN_VA(0x468907u);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000689AA;
    label_00068911: cpu->eip = LIFT_CODE_TOKEN_VA(0x468911u);
    cpu->esi = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_active[0]), 1u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068931;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68931u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068931: cpu->eip = LIFT_CODE_TOKEN_VA(0x468931u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068945;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68945u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068945: cpu->eip = LIFT_CODE_TOKEN_VA(0x468945u);
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(1u)) goto label_0006899D;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(8u)) goto label_000689B0;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006896F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6896Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006896F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46896Fu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068983;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68983u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068983: cpu->eip = LIFT_CODE_TOKEN_VA(0x468983u);
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 1u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), 1u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6899Du); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_0006899D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46899Du);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_03)) goto label_00068911;
    label_000689AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4689AAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000689B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4689B0u);
    lift_push32(cpu, 0x39FEu); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4689BFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4689C5u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4689D2u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4689D2u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004689E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4689E0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->esi = cpu->ebx;
    cpu->edi = (uint32_t)(cpu->ebx + 3u);
    cpu->ebp = (uint32_t)(cpu->ebx + 0x1Du);
    label_000689F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4689F6u);
    if ((uint32_t)((lift_load32(cpu->esp + 0x10u)) & (cpu->ebx)) != 0u) goto label_00068A6D;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068A0A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68A0Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068A0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x468A0Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068A1E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68A1Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068A1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x468A1Eu);
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->edi + cpu->ecx)) == (uint32_t)(0u)) goto label_00068A6D;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.light_update_counter, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068A3E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68A3Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068A3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x468A3Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068A52;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68A52u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068A52: cpu->eip = LIFT_CODE_TOKEN_VA(0x468A52u);
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    lift_store32(cpu->edi + cpu->edx, 0u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68A6Du); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_00068A6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x468A6Du);
    cpu->ebx += cpu->ebx;
    cpu->edi += 4u;
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000689F6;
    cpu->ebx = 1u;
    cpu->esi = cpu->ebx;
    cpu->edi = (uint32_t)(cpu->ebp + 4u);
    label_00068A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x468A80u);
    if ((uint32_t)((lift_load32(cpu->esp + 0x10u)) & (cpu->ebx)) == 0u) goto label_00068B01;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068A94;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68A94u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068A94: cpu->eip = LIFT_CODE_TOKEN_VA(0x468A94u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068AA8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68AA8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068AA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x468AA8u);
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->edi + cpu->ecx)) == (uint32_t)(1u)) goto label_00068B01;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(8u)) goto label_00068B19;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068AD2;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68AD2u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068AD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x468AD2u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068AE6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68AE6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068AE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x468AE6u);
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 1u);
    lift_store32(cpu->edi + cpu->edx, 1u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68B01u); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_00068B01: cpu->eip = LIFT_CODE_TOKEN_VA(0x468B01u);
    ++cpu->esi;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    cpu->ebx += cpu->ebx;
    cpu->edi += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x1Eu)) goto label_00068A80;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00068B19: cpu->eip = LIFT_CODE_TOKEN_VA(0x468B19u);
    lift_push32(cpu, 0x3BBAu); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x468B28u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x468B2Eu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468B3Bu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x468B3Bu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00468B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468B40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 3u);
    cpu->ebx = (uint32_t)(cpu->esi + 0x1Du);
    cpu->edi = cpu->edi;
    label_00068B50: cpu->eip = LIFT_CODE_TOKEN_VA(0x468B50u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068B5E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68B5Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068B5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x468B5Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068B72;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68B72u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068B72: cpu->eip = LIFT_CODE_TOKEN_VA(0x468B72u);
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax)) == (uint32_t)(0u)) goto label_00068BC0;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.light_update_counter, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068B91;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68B91u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068B91: cpu->eip = LIFT_CODE_TOKEN_VA(0x468B91u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00068BA5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68BA5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068BA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x468BA5u);
    cpu->ecx = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    lift_store32(cpu->edi + cpu->ecx, 0u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68BC0u); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_00068BC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x468BC0u);
    cpu->edi += 4u;
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00068B50;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00468BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468BD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = 0x6458u;
    lift_push32(cpu, 0x3F97u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    g_sfera_landscape_interpolation_runtime.subdivision_count = (uint32_t)(0xDu);
    g_sfera_landscape_render_runtime.grid_buffer_bytes = (uint32_t)(cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468C16u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    lift_push32(cpu, 0x3F98u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468C30u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ecx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x3F99u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468C53u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    g_sfera_window_runtime.landscape_grid_records = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x468C67u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x468C6Cu);
    cpu->edx = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x468C7Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x468C80u);
    cpu->eax = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ecx = g_sfera_window_runtime.landscape_grid_records;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x468C98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x468C9Du);
    cpu->eax = 0x186A0u;
    cpu->esp += 0x24u;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07) = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468CB4u); lift_push32(cpu, r); sfera_sub_00460570(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x3FA0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468CC3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1598u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468CCDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00068D14;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(0u)) goto label_00068CF7;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68CF7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068CF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x468CF7u);
    cpu->edx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468D12u); lift_push32(cpu, r); sfera_sub_004253F0(cpu,r); if (cpu->eip != r) return; }
    goto label_00068D16;
    label_00068D14: cpu->eip = LIFT_CODE_TOKEN_VA(0x468D14u);
    cpu->eax = 0u;
    label_00068D16: cpu->eip = LIFT_CODE_TOKEN_VA(0x468D16u);
    g_sfera_world_render_runtime.world_spatial_index = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00468D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468D30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00068D6B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68D6Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00068D6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x468D6Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.windows.capacity)) goto label_00068D7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68D7Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00068D7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x468D7Fu);
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = 1u;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & ((cpu->eax & 0xFFu))) != 0u) goto label_00068DC1;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->eax));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store32(cpu->esp + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468DACu); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468DB6u); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, 0xFFFFFFFFu);
    label_00068DC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x468DC1u);
    cpu->ecx = g_sfera_cursor_manager_runtime.active_cursor;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00068DD5;
    cpu->ecx = (uint32_t)(uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68DD5u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00068DD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x468DD5u);

    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468DE1u);
    cpu->edi = lift_load32(cpu->esi + 0x1Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->edi)) goto label_00068E26;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x20u))) goto label_00068E26;
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x24u))) goto label_00068E26;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x28u))) goto label_00068E26;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468E07u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax -= cpu->edi;
    cpu->eax += cpu->ebp;
    lift_store32(cpu->ecx, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x38u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468E19u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax -= lift_load32(cpu->esi + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->eax += cpu->ebx;
    lift_store32(cpu->edx, cpu->eax);
    goto label_00068E3A;
    label_00068E26: cpu->eip = LIFT_CODE_TOKEN_VA(0x468E26u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax, 0xFFFFFFFFu);
    lift_store32(cpu->ecx, 0xFFFFFFFFu);
    label_00068E3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x468E3Au);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00468E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x468E50u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 4u));
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 2u));
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u) + 0x8Cu);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_terrain_neighbor_runtime.cells[0];
    cpu->edx = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00068E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x468E80u);
    cpu->ecx = sfera_neighbor_dy(cpu->edx);
    cpu->eax = sfera_neighbor_dx(cpu->edx);
    cpu->ecx += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->edi, 0u);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00068EBC;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x84u))) goto label_00068EB8;
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_00068EB8;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x88u))) goto label_00068EB8;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(cpu->ecx) * 4u) + 0x8Cu);
    lift_store32(cpu->edi, cpu->eax);
    label_00068EB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x468EB8u);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    label_00068EBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x468EBCu);
    ++cpu->edx;
    cpu->edi += 4u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(8u)) goto label_00068E80;
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[5];
    cpu->edi = 1u;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00068EF5;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468EF1u); lift_push32(cpu, r); sfera_sub_0045B620(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    label_00068EF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x468EF5u);
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[4];
    if ((uint32_t)(cpu->edx) == 0u) goto label_00068F10;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468F0Cu); lift_push32(cpu, r); sfera_sub_0045B620(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_00068F10: cpu->eip = LIFT_CODE_TOKEN_VA(0x468F10u);
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[7];
    if ((uint32_t)(cpu->edx) == 0u) goto label_00068F2B;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 3u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468F27u); lift_push32(cpu, r); sfera_sub_0045B620(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_00068F2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x468F2Bu);
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[6];
    if ((uint32_t)(cpu->edx) == 0u) goto label_00068F44;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 3u); lift_push32(cpu, 2u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x468F42u); lift_push32(cpu, r); sfera_sub_0045B620(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    label_00068F44: cpu->eip = LIFT_CODE_TOKEN_VA(0x468F44u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) == (uint32_t)(0u)) goto label_00069075;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(0u)) goto label_00069075;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(0u)) goto label_00069075;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00069075;
    if ((uint8_t)(lift_load8(cpu->esi + 0x689Cu)) != (uint8_t)(0u)) goto label_00068F99;
    cpu->ecx = g_sfera_terrain_neighbor_runtime.cells[6];
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[4];
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32((uintptr_t)&g_sfera_terrain_neighbor_runtime.cells[3]);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68F99u); lift_push32(cpu, r); sfera_sub_00453D00(cpu,r); if (cpu->eip != r) return; }
    label_00068F99: cpu->eip = LIFT_CODE_TOKEN_VA(0x468F99u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x689Du)) != (uint8_t)(0u)) goto label_00068FC4;
    cpu->eax = g_sfera_terrain_neighbor_runtime.cells[7];
    cpu->ecx = g_sfera_terrain_neighbor_runtime.cells[4];
    cpu->edx = lift_load32((uintptr_t)&g_sfera_terrain_neighbor_runtime.cells[2]);
    lift_push32(cpu, 0u); lift_push32(cpu, 3u); lift_push32(cpu, 2u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68FC4u); lift_push32(cpu, r); sfera_sub_00453D00(cpu,r); if (cpu->eip != r) return; }
    label_00068FC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x468FC4u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x689Eu)) != (uint8_t)(0u)) goto label_00068FEF;
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[6];
    cpu->eax = g_sfera_terrain_neighbor_runtime.cells[5];
    lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[0];
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x68FEFu); lift_push32(cpu, r); sfera_sub_00453D00(cpu,r); if (cpu->eip != r) return; }
    label_00068FEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x468FEFu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x689Fu)) != (uint8_t)(0u)) goto label_0006901B;
    cpu->ecx = g_sfera_terrain_neighbor_runtime.cells[7];
    cpu->edx = g_sfera_terrain_neighbor_runtime.cells[5];
    lift_push32(cpu, 2u); lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32((uintptr_t)&g_sfera_terrain_neighbor_runtime.cells[1]);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6901Bu); lift_push32(cpu, r); sfera_sub_00453D00(cpu,r); if (cpu->eip != r) return; }
    label_0006901B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46901Bu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469022u); lift_push32(cpu, r); sfera_sub_00452A00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    label_00069027: cpu->eip = LIFT_CODE_TOKEN_VA(0x469027u);
    cpu->ecx = sfera_neighbor_dy(cpu->esi);
    cpu->eax = sfera_neighbor_dx(cpu->esi);
    cpu->ecx += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00069060;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edx + 0x84u))) goto label_00069060;
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_00069060;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->edx + 0x88u))) goto label_00069060;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0x8Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00069060;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69060u); lift_push32(cpu, r); sfera_sub_00452A00(cpu,r); if (cpu->eip != r) return; }
    label_00069060: cpu->eip = LIFT_CODE_TOKEN_VA(0x469060u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(8u)) goto label_00069027;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_00069075: cpu->eip = LIFT_CODE_TOKEN_VA(0x469075u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Smooth error in %s! Look at lndbug.tga");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469084u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x469084u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00469090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x469090u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0xECu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x4423u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x1E4u;
    lift_store32(cpu->esp + 0x60u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4690BBu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->edi, cpu->ebx);
    lift_push32(cpu, 0x1E4u);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4690C8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4690CDu);
    cpu->eax = lift_load32((uintptr_t)"AutoGrass");
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"AutoGrass") + 4u);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"AutoGrass") + 8u)) & 0xFFFFu);
    cpu->esp += 0xCu;
    lift_store16(cpu->ebx + 8u, cpu->edx & 0xFFFFu);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x6Cu, cpu->edi);
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00069152;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->eax += 4u;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    label_0006910D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46910Du);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46911Fu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 0x30u);
    cpu->edx = lift_load32(cpu->eax + 0x20u);
    lift_store32(cpu->esp + 0x40u, (uint64_t)(lift_load32(cpu->esp + 0x40u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->edi += lift_load32(cpu->eax + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, (uint64_t)(lift_load32(cpu->esp + 0x6Cu)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x3Cu))) goto label_0006913A;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    label_0006913A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46913Au);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x28u))) goto label_00069144;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    label_00069144: cpu->eip = LIFT_CODE_TOKEN_VA(0x469144u);
    lift_store32(cpu->esp + 0x38u, (uint64_t)(lift_load32(cpu->esp + 0x38u)) + (uint64_t)(0x2F4u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x34u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x34u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006910D;
    label_00069152: cpu->eip = LIFT_CODE_TOKEN_VA(0x469152u);
    lift_x87_push(cpu, 141.12777709960938);
    lift_store32(cpu->ebx + 0x38u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469164u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_store32(cpu->ebx + 0x20u, cpu->esi);
    lift_store_f32(cpu->ebx + 0x194u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, 0x443Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebx + 0x28u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469194u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x443Cu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->ebx + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4691ADu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x443Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0xACu;
    lift_store32(cpu->ebx + 0x2Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4691C4u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x3Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x443Eu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4691E1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4440u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x6Cu, cpu->eax);
    lift_store32(cpu->ebx + 0x1C8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4691FCu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)-5.0f);
    lift_store32(cpu->ebx + 0x1CCu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_store32(cpu->ebx + 0x1C4u, 0u);
    cpu->ecx = lift_load32((uintptr_t)"_u_grass");
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"_u_grass") + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"_u_grass") + 8u)) & 0xFFu);
    lift_store8(cpu->eax + 8u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->ebx + 0x3Cu);
    lift_store8(cpu->edx + 0x20u, 1u);
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_store8(cpu->eax + 0x21u, 0u);
    cpu->ecx = lift_load32(cpu->ebx + 0x3Cu);
    lift_store8(cpu->ecx + 0x22u, 0u);
    cpu->edx = lift_load32(cpu->ebx + 0x3Cu);
    lift_store_f32(cpu->edx + 0x84u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_x87_push(cpu, (double)5.0f);
    lift_store_f32(cpu->eax + 0x90u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->ebx + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xCu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ebx + 0x3Cu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->edx + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->ebx + 0x3Cu);
    lift_store_f32(cpu->ecx + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    cpu->edx = (uint32_t)(cpu->eax + 0x24u);
    cpu->ecx = (uint32_t)(cpu->eax + 0x84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46929Au); lift_push32(cpu, r); sfera_sub_004259C0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_x87_push(cpu, (double)-0.699999988079071f);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 0x9Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_x87_push(cpu, (double)8.0f);
    lift_store32(cpu->eax + 0xA0u, cpu->ecx);
    lift_store32(cpu->eax + 0xA4u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_store_f32(cpu->eax + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebx + 0x3Cu);
    lift_x87_push(cpu, (double)0.5f);
    cpu->esi = (uint32_t)(cpu->eax + 0x24u);
    lift_store_f32(cpu->ebx + 0x1A8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->ebx + 0xE8u);
    cpu->ecx = 0x18u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->eax + 0x84u);
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    cpu->edi = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->ebx + 0x70u, cpu->ecx);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->edi);
    cpu->edx = lift_load32(cpu->eax + 0x88u);
    lift_store32(cpu->ebx + 0x74u, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 0x8Cu);
    lift_store32(cpu->ebx + 0x78u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x90u);
    lift_store32(cpu->ebx + 0x7Cu, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 0x94u);
    lift_store32(cpu->ebx + 0x80u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x98u);
    lift_store32(cpu->ebx + 0x84u, cpu->edx);
    lift_push32(cpu, 0x4454u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469355u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46935Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x469363u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x4Cu, cpu->esi);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    lift_store32(cpu->esp + 0x8Cu, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000693B6;
    label_0006937D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46937Du);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006938B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6938Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006938B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46938Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_grass_runtime.model_handles.capacity)) goto label_0006939F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6939Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006939F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46939Fu);
    cpu->eax = g_sfera_grass_runtime.model_handles.data;
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x4693A7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4693ADu);
    ++cpu->esi;
    lift_store32(cpu->edi, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x5Cu))) goto label_0006937D;
    label_000693B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4693B6u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x48u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00069D30;
    lift_store32(cpu->esp + 0x30u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x44u, 0xFFFFFFEEu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000693E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4693E0u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x8Cu)) != (uint32_t)(0u)) goto label_00069460;
    lift_store32(cpu->esp + 0x8Cu, 1u);
    label_000693F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4693F5u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->esi += 4u;
    label_00069405: cpu->eip = LIFT_CODE_TOKEN_VA(0x469405u);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x5Cu))) goto label_0006A059;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469421u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x1C8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006A04E;
    cpu->edx = lift_load32(cpu->eax + 0x30u);
    cpu->ecx = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0006944F;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    (void)cpu;
    label_00069440: cpu->eip = LIFT_CODE_TOKEN_VA(0x469440u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_00069A48;
    ++cpu->ecx;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->edx)) goto label_00069440;
    label_0006944F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46944Fu);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    ++cpu->edi;
    cpu->esi += 0x2F4u;
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    goto label_00069405;
    label_00069460: cpu->eip = LIFT_CODE_TOKEN_VA(0x469460u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x5Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000693F5;
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    label_00069481: cpu->eip = LIFT_CODE_TOKEN_VA(0x469481u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469493u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x70u, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x30u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0006954E;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_000694A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4694A8u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)(lift_load8(cpu->edx + cpu->esi)) != (uint8_t)(0u)) goto label_0006953F;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u)) >= (int32_t)(uint32_t)(0u)) goto label_000694C7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x694C7u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000694C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4694C7u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_grass_runtime.type_records.capacity)) goto label_000694DF;
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x694DFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000694DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4694DFu);
    cpu->eax = g_sfera_grass_runtime.type_records.data;
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + cpu->eax + 2u)) & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->edi + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) != (uint16_t)(lift_load16(cpu->ecx + cpu->eax + 2u))) goto label_0006953F;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u)) >= (int32_t)(uint32_t)(0u)) goto label_0006950C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6950Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006950C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46950Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_grass_runtime.type_records.capacity)) goto label_00069524;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69524u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00069524: cpu->eip = LIFT_CODE_TOKEN_VA(0x469524u);
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edx)) & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    cpu->eax = g_sfera_grass_runtime.type_records.data;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0x80u))) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->edx + cpu->eax)) == (uint8_t)((cpu->ecx & 0xFFu))) goto label_00069576;
    label_0006953F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46953Fu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x12u) + (uint64_t)(0u));
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x30u))) goto label_000694A8;
    label_0006954E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46954Eu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x2F4u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x5Cu))) goto label_00069481;
    goto label_000693F5;
    label_00069576: cpu->eip = LIFT_CODE_TOKEN_VA(0x469576u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x3Cu));
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx += cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->edx + cpu->eax, 1u);
    cpu->edx = lift_load32(cpu->edi + 0x34u);
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000695A3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x695A3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000695A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4695A3u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_grass_runtime.type_records.capacity)) goto label_000695BB;
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x695BBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000695BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4695BBu);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x2F4u);
    cpu->eax += g_sfera_grass_runtime.type_records.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 6u)) & 0xFFFFu);
    lift_store16(cpu->eax + 6u, (uint64_t)(lift_load16(cpu->eax + 6u)) + (uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)(0u));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0xAu)) & 0xFFFFu);
    lift_store16(cpu->eax + 0xAu, (uint64_t)(lift_load16(cpu->eax + 0xAu)) + (uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)(0u));
    cpu->edi += lift_load32(cpu->ebp + 8u);
    cpu->edx = (uint32_t)(cpu->esp + 0xB8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->edi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4695F5u); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load16(cpu->esi + 0xAu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load16(cpu->esi + 8u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->ecx = lift_load32(cpu->esp + 0x74u);
    cpu->ecx = lift_load32(cpu->ecx + 0x24u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = lift_load32(cpu->ebx + 0x24u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469628u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46962Du);
    cpu->edx = lift_load32(cpu->edi + 0x158u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14Cu));
    cpu->eax = lift_load32(cpu->edi + 0x15Cu);
    cpu->ecx = lift_load32(cpu->edi + 0x160u);
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xF0u));
    lift_store32(cpu->esp + 0x5Cu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xECu));
    cpu->edx = 0u;
    cpu->esp += 0xCu;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    lift_store32(cpu->esp + 0x58u, cpu->ecx);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->esi + 0xAu))) goto label_0006974F;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_0006967B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46967Bu);
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx));
    cpu->eax += cpu->ecx;
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    ++cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xBCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xC4u))));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xD0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xD4u))));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xDCu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xD8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = lift_load16(cpu->esi + 0xAu);
    cpu->ecx += 0x24u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0006967B;
    label_0006974F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46974Fu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load16(cpu->esi + 0xAu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load16(cpu->esi + 8u);
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    cpu->eax = lift_load32(cpu->eax + 0x1C8u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469787u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46978Cu);
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    cpu->edi = 0u;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->esi + 0xAu))) goto label_000699B2;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xBCu));
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x28u));
    lift_x87_push(cpu, -0.15000000596046448);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f64(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store_f64(cpu->esp + 0x98u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xDCu))));
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax += 8u;
    lift_store_f64(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x60u, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_00069806: cpu->eip = LIFT_CODE_TOKEN_VA(0x469806u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0xCu)) >= (int32_t)(uint32_t)(0u)) goto label_0006981B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469817u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_0006981B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46981Bu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_grass_runtime.model_handles.capacity)) goto label_00069837;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469833u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_00069837: cpu->eip = LIFT_CODE_TOKEN_VA(0x469837u);
    cpu->edx = g_sfera_grass_runtime.model_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x80u))));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->ecx) * 4u))) & 0xFFFFu);
    lift_store16(cpu->eax + 0xFFFFFFFAu, (uint64_t)(lift_load16(cpu->eax + 0xFFFFFFFAu)) + (uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00069865;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69865u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00069865: cpu->eip = LIFT_CODE_TOKEN_VA(0x469865u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_grass_runtime.instance_indices.capacity)) goto label_0006987D;
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6987Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006987D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46987Du);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = g_sfera_grass_runtime.instance_indices.data;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edx + cpu->ecx, cpu->eax);
    cpu->eax = lift_load16(cpu->esi + 8u);
    cpu->eax += lift_load32(cpu->esp + 0x34u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000698AC;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4698A8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    label_000698AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4698ACu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_grass_runtime.instance_offsets.capacity)) goto label_000698C6;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4698C2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    label_000698C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4698C6u);
    cpu->ecx = g_sfera_grass_runtime.instance_offsets.data;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u), cpu->edx);
    cpu->eax = lift_load16(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    cpu->eax += cpu->edi;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ebx + 0x1CCu);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0x18u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(4u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + 1u);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    ++cpu->edi;
    lift_x87_push(cpu, (double)-0.15000000596046448f);
    cpu->edx += 0x24u;
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_store32(cpu->esp + 0x60u, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xB8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0xB0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xC4u))));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x98u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xD0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xD4u))));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xD8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x90u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xE0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xE4u))));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load16(cpu->esi + 0xAu);
    cpu->eax += 0xCu;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00069806;
    label_000699B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4699B2u);
    cpu->eax = lift_load16(cpu->esi + 6u);
    cpu->edi = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load16(cpu->esi + 4u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x2Cu);
    cpu->ecx = lift_load32(cpu->ebx + 0x2Cu);
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edi += cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4699E1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4699E6u);
    cpu->eax = lift_load32(cpu->ebx + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->edx = 0u;
    cpu->esp += 0xCu;
    cpu->eax += cpu->edi;
    lift_store32(cpu->esp + 0xCu, 0u);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->esi + 6u))) goto label_00069A31;
    label_00069A02: cpu->eip = LIFT_CODE_TOKEN_VA(0x469A02u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = cpu->ecx;
    cpu->edi -= cpu->edx;
    lift_store16(cpu->eax, (uint64_t)(lift_load16(cpu->eax)) + (uint64_t)((cpu->edi & 0xFFFFu)) + (uint64_t)(0u));
    cpu->edi = cpu->ecx;
    cpu->edi -= cpu->edx;
    lift_store16(cpu->eax + 2u, (uint64_t)(lift_load16(cpu->eax + 2u)) + (uint64_t)((cpu->edi & 0xFFFFu)) + (uint64_t)(0u));
    cpu->edi = cpu->ecx;
    cpu->edi -= cpu->edx;
    lift_store16(cpu->eax + 4u, (uint64_t)(lift_load16(cpu->eax + 4u)) + (uint64_t)((cpu->edi & 0xFFFFu)) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_load16(cpu->esi + 6u);
    ++cpu->edx;
    cpu->eax += 0xCu;
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->edi)) goto label_00069A02;
    label_00069A31: cpu->eip = LIFT_CODE_TOKEN_VA(0x469A31u);
    cpu->eax = lift_load16(cpu->esi + 6u);
    cpu->edx = lift_load16(cpu->esi + 0xAu);
    lift_store32(cpu->esp + 0x4Cu, (uint64_t)(lift_load32(cpu->esp + 0x4Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ecx += cpu->edx;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    goto label_00069D1D;
    label_00069A48: cpu->eip = LIFT_CODE_TOKEN_VA(0x469A48u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x3Cu));
    cpu->eax += cpu->ecx;
    lift_store8(cpu->eax + cpu->edx, 1u);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->ecx + 0x34u);
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.data;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469A75u); lift_push32(cpu, r); sfera_sub_00451D90(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x2F4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->edi += lift_load32(cpu->ebp + 8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0x80u))) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    cpu->edx = lift_load16(cpu->esi + 2u);
    cpu->ecx = lift_load16(cpu->esp + 0x4Cu);
    lift_store16(cpu->eax + 2u, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load16(cpu->esp + 0x24u);
    lift_store16(cpu->eax + 4u, cpu->ecx & 0xFFFFu);
    lift_store16(cpu->eax + 8u, cpu->edx & 0xFFFFu);
    cpu->ecx = lift_load16(cpu->esi + 6u);
    lift_store16(cpu->eax + 6u, cpu->ecx & 0xFFFFu);
    cpu->edx = lift_load16(cpu->esi + 0xAu);
    cpu->ecx = 0u;
    lift_store32(cpu->eax + 0xEu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xB8u);
    lift_store16(cpu->eax + 0xAu, cpu->edx & 0xFFFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    lift_store8(cpu->eax + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469ACBu); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load16(cpu->esi + 0xAu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load16(cpu->esi + 8u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx + 0x24u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->ebx + 0x24u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->ecx;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469AFEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x469B03u);
    cpu->eax = lift_load32(cpu->edi + 0x158u);
    cpu->ecx = lift_load32(cpu->edi + 0x15Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14Cu));
    cpu->edx = lift_load32(cpu->edi + 0x160u);
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x80u, cpu->eax);
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x78u, cpu->ecx);
    lift_store32(cpu->esp + 0x7Cu, cpu->edx);
    lift_store32(cpu->esp + 0x60u, 0u);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->esi + 0xAu))) goto label_00069B96;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_00069B48: cpu->eip = LIFT_CODE_TOKEN_VA(0x469B48u);
    cpu->edx = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->edi + 4u));
    cpu->edx += cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x80u))));
    cpu->ecx = (uint32_t)(cpu->esp + 0xB8u);
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469B67u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x7Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x60u);
    cpu->ecx = lift_load16(cpu->esi + 0xAu);
    ++cpu->eax;
    cpu->edi += 0x24u;
    lift_store32(cpu->esp + 0x60u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00069B48;
    label_00069B96: cpu->eip = LIFT_CODE_TOKEN_VA(0x469B96u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esp + 0x68u);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load16(cpu->esi + 0xAu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load16(cpu->esi + 8u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x1C8u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469BC6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x469BCBu);
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->esi + 0xAu))) goto label_00069CBB;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x28u));
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->edi += 8u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00069C00: cpu->eip = LIFT_CODE_TOKEN_VA(0x469C00u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.model_handles.data;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469C0Fu); lift_push32(cpu, r); sfera_sub_0041C1F0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax)) & 0xFFFFu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x80u))));
    lift_store16(cpu->edi + 0xFFFFFFFAu, (uint64_t)(lift_load16(cpu->edi + 0xFFFFFFFAu)) + (uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax += lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.data;
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469C38u); lift_push32(cpu, r); sfera_sub_0041C1F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load16(cpu->esi + 8u);
    cpu->edx += lift_load32(cpu->esp + 0x34u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.data;
    cpu->edx += lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469C55u); lift_push32(cpu, r); sfera_sub_0041C1F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->eax = lift_load16(cpu->esi + 8u);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u)));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load32(cpu->ebx + 0x1CCu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 0x18u);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xB8u);
    lift_x87_push(cpu, (double)-0.15000000596046448f);
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469C9Eu); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->esi + 0xAu);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x24u) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->edi += 0xCu;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_00069C00;
    label_00069CBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x469CBBu);
    cpu->eax = lift_load16(cpu->esi + 6u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load16(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->edx + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = lift_load32(cpu->ebx + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x469CE7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x469CECu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load16(cpu->esi + 0xAu);
    cpu->edx = lift_load16(cpu->esi + 6u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->eax = 1u;
    lift_store32(cpu->esp + 0x44u, (uint64_t)(lift_load32(cpu->esp + 0x44u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x3Cu, (uint64_t)(lift_load32(cpu->esp + 0x3Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->edi += cpu->edx;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x44u, (uint64_t)(lift_load32(cpu->esp + 0x44u)) + (uint64_t)(0x12u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    label_00069D1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x469D1Du);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x6Cu))) goto label_000693E0;
    label_00069D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x469D30u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, 0x44D9u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469D43u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00069FC7;
    cpu->edx = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    label_00069D59: cpu->eip = LIFT_CODE_TOKEN_VA(0x469D59u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = 0xFDE8u;
    if ((uint16_t)(lift_load16(cpu->edx)) >= (uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00069DD3;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00069D75;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69D75u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00069D75: cpu->eip = LIFT_CODE_TOKEN_VA(0x469D75u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_grass_runtime.instance_indices.capacity)) goto label_00069D89;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69D89u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00069D89: cpu->eip = LIFT_CODE_TOKEN_VA(0x469D89u);
    cpu->eax = g_sfera_grass_runtime.instance_indices.data;
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x28u));
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load16(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00069DAB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69DABu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00069DAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x469DABu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_grass_runtime.instance_offsets.capacity)) goto label_00069DBF;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.instance_offsets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69DBFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00069DBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x469DBFu);
    cpu->eax = g_sfera_grass_runtime.instance_offsets.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_store16(cpu->edx, cpu->ecx & 0xFFFFu);
    label_00069DD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x469DD3u);
    lift_store32(cpu->esp + 0x2Cu, (uint64_t)(lift_load32(cpu->esp + 0x2Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_00069D59;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00069FC7;
    cpu->eax = lift_load32(cpu->esp + 0x68u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x48u, cpu->ecx);
    label_00069DFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x469DFDu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load16(cpu->edx);
    cpu->eax = 0xFDE8u;
    if ((uint16_t)((cpu->ecx & 0xFFFFu)) >= (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00069FB3;
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + cpu->eax));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u)))));
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->esi = lift_load32(cpu->ebx + 0x1CCu);
    cpu->esi += cpu->edi;
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f64(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store_f64(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 2u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store32(cpu->esi, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x78u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f64(cpu->esp + 0x98u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f64(cpu->esp + 0x60u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x7Cu);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store_f64(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469ED1u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x90u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x98u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_load_f64(cpu->esp + 0xB0u)));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x60u));
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_load_f64(cpu->esp + 0x80u)));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xA4u);
    cpu->ecx = lift_load32(cpu->esp + 0xA8u);
    cpu->edx = lift_load32(cpu->esp + 0xACu);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f64(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469F84u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x90u)) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    label_00069FB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x469FB3u);
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    cpu->edi += 0x24u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x48u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x48u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00069DFD;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00069FC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x469FC7u);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    lift_push32(cpu, 0x44F0u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->ebx + 0x30u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x469FE2u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    lift_store32(cpu->ebx + 0x34u, cpu->eax);
    if ((int32_t)(uint32_t)(g_sfera_grass_runtime.type_records.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_00069FFB;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_grass_runtime.type_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x69FFBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00069FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x469FFBu);
    cpu->eax = lift_load32(cpu->ebx + 0x30u);
    cpu->edx = g_sfera_grass_runtime.type_records.data;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->ebx + 0x34u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46A00Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46A014u);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ebx + 0x1B0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    lift_x87_push(cpu, 1.0);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0x44u, cpu->esi);
    lift_store_f32(cpu->ebx + 0x1B4u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ebx + 0x1BCu, cpu->esi);
    lift_store_f32(cpu->ebx + 0x1B8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ebx + 0x40u, 0u);
    lift_store8(cpu->ebx + 0x50u, 0u);
    lift_store32(cpu->ebx + 0x6Cu, 3u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0006A04E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A04Eu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"dg_type parameter not filled in mdlprms.txt for model  %s");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A059u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    label_0006A059: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A059u);
    cpu->ecx = (uint32_t)(uintptr_t)"fatal error 58289563485";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A063u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x46A063u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046A070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46A070u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x214u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0006B7AD;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(1u)) goto label_0006A0AB;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A0ABu); lift_push32(cpu, r); sfera_sub_004564A0(cpu,r); if (cpu->eip != r) return; }
    label_0006A0AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A0ABu);
    cpu->edi = 0u;
    g_sfera_window_runtime.landscape_grid_count = (uint32_t)(cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0006A1D2;
    label_0006A0C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A0C3u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A0D1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A0D1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A0D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A0D1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_0006A0E5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A0E5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A0E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A0E5u);
    cpu->eax = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x74u);
    cpu->ebx = lift_load32(cpu->edi + cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A101;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A101u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A101: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A101u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_0006A115;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A115u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A115: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A115u);
    cpu->ecx = g_sfera_scene_array_runtime.scene_records.data;
    cpu->edi = lift_load32(cpu->edi + cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0006A130;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    goto label_0006A1BF;
    label_0006A130: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A130u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0006A140;
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_0006A1BF;
    label_0006A140: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A140u);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006A15C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A15Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A15C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A15Cu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_ranges.capacity)) goto label_0006A170;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A170u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A170: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A170u);
    cpu->edx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 8u), cpu->eax);
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006A191;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A191u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A191: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A191u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_ranges.capacity)) goto label_0006A1A5;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A1A5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A1A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A1A5u);
    cpu->edx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->ecx = cpu->esi;
    cpu->ecx -= lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 8u) + 4u, cpu->ecx);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_window_runtime.landscape_grid_count, (uint64_t)(g_sfera_window_runtime.landscape_grid_count) + 1u);
    label_0006A1BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A1BFu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_04))) goto label_0006A0C3;
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    label_0006A1D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A1D2u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006A1E0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A1E0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A1E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A1E0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_ranges.capacity)) goto label_0006A1F4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A1F4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A1F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A1F4u);
    cpu->eax = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 8u), cpu->ecx);
    cpu->edi = g_sfera_window_runtime.landscape_grid_count;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006A214;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A214u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A214: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A214u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_ranges.capacity)) goto label_0006A228;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A228u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A228: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A228u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->esi -= lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 8u) + 4u, cpu->esi);
    lift_store_f32(cpu->esp + 0xF8u, lift_x87_get(cpu, 0u));
    cpu->eax = 0x5F317777u;
    lift_store_f32(cpu->esp + 0xF4u, lift_x87_get(cpu, 0u));
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3030)) & 0xFFFFu);
    lift_store_f32(cpu->esp + 0xF0u, lift_x87_get(cpu, 0u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store_f32(cpu->esp + 0xECu, lift_x87_get(cpu, 0u));
    lift_store32((uint32_t)(uintptr_t)&g_sfera_window_runtime.landscape_grid_count, (uint64_t)(g_sfera_window_runtime.landscape_grid_count) + 1u);
    lift_store_f32(cpu->esp + 0xE4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xE0u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x214u, cpu->eax);
    lift_store_f32(cpu->esp + 0xDCu, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esp + 0xC0u);
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u));
    lift_store16(cpu->esp + 0x21Cu, cpu->ecx & 0xFFFFu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x100u);
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esp + 0x222u, cpu->edx & 0xFFu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x104u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xF0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xDCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A2F0u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x40u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x194u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46A2FCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46A301u);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 0x40u);
    lift_store_f32(cpu->esp + 0x1C8u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0x1E0u);
    lift_store_f32(cpu->esp + 0x1DCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46A31Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46A322u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x1E8u, lift_x87_get(cpu, 0u));
    cpu->esp += 0x18u;
    lift_store_f32(cpu->esp + 0x1E4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1F8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x20Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.6000000238418579);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A34Eu); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width)))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (0.75));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A37Fu); lift_push32(cpu, r); sfera_sub_004EED60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A3A4u); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (0.5) / (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x190u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.19634956121444702));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A3D4u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.003000000026077032));
    lift_push32(cpu, 0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, 0x1Cu);
    lift_x87_set(cpu, 0u, (0.5) / (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1ACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.5f);
    lift_store_f32(cpu->esp + 0x1B8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1BCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A41Au); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A429u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_window_runtime.landscape_grid_count), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x34u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006B687;
    label_0006A43E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A43Eu);
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006A450;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A450u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A450: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A450u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_ranges.capacity)) goto label_0006A464;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A464u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A464: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A464u);
    cpu->eax = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A47A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A47Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A47A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A47Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.scene_records.capacity)) goto label_0006A48E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.scene_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A48Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A48E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A48Eu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x74u);
    cpu->esi += g_sfera_scene_array_runtime.scene_records.data;
    cpu->ebx = cpu->esi;
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0006A4AD;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xAu)) goto label_0006A4BC;
    label_0006A4AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A4ADu);
    cpu->edx = 0x4941u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A4BCu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0006A4BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A4BCu);
    cpu->esi = lift_load32(cpu->ebx + 0x10u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A4CD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A4CDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A4CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A4CDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006A4E1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A4E1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A4E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A4E1u);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 0x14u));
    cpu->esi = 0u;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = (uint32_t)(cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    cpu->edi = cpu->edi;
    label_0006A500: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A500u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006A50E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A50Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A50E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A50Eu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_ranges.capacity)) goto label_0006A522;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A522u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A522: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A522u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = g_sfera_scene_array_runtime.render_ranges.data;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 4u))) goto label_0006AE24;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax += 4u;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x38u)))));
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (2.3561947345733643));
    lift_store_f64(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.9269912242889404));
    lift_store_f64(cpu->esp + 0x70u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.19634956121444702));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A58E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A58Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A58E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A58Eu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_scene_array_runtime.render_work_records.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006A5A2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A5A2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A5A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A5A2u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax)))));
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    cpu->edi = cpu->esi;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A5C5u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A5D7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A5D7u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A5D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A5D7u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A5EB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A5EBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A5EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A5EBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 8u))));
    lift_store_f32(cpu->edi + cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A617;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A617u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A617: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A617u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A62B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A62Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A62B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A62Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ecx)))));
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A64F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A64Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A64F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A64Fu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A663;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A663u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A663: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A663u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A67C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A67Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A67C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A67Cu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A690;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A690u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A690: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A690u);
    lift_x87_push(cpu, (double)-1.0f);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A6AE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A6AEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A6AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A6AEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A6C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A6C2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A6C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A6C2u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A6DC;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A6DCu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A6DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A6DCu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A6F0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A6F0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A6F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A6F0u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->eax + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A709;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A709u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A709: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A709u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A71D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A71Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A71D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A71Du);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = (uint32_t)(cpu->ebx + 1u);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.9269912242889404));
    lift_store_f64(cpu->esp + 0x68u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.19634956121444702));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x28u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006A763;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A763u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A763: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A763u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_scene_array_runtime.render_work_records.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006A777;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A777u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A777: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A777u);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->ebx);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    { uint64_t l=(uint64_t)(cpu->edx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    cpu->edi = cpu->esi;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A7A2u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A7B4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A7B4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A7B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A7B4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A7C8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A7C8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A7C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A7C8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 8u))));
    lift_store_f32(cpu->edi + cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A7F1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A7F1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A7F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A7F1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A805;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A805u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A805: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A805u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edx)))));
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A828;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A828u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A828: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A828u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A83C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A83Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A83C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A83Cu);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A856;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A856u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A856: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A856u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A86A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A86Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A86A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A86Au);
    lift_x87_push(cpu, (double)-1.0f);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A888;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A888u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A888: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A888u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A89C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A89Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A89C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A89Cu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A8B5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A8B5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A8B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A8B5u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A8C9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A8C9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A8C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A8C9u);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A8E3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A8E3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A8E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A8E3u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A8F7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A8F7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A8F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A8F7u);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (2.3561947345733643));
    lift_store_f64(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.19634956121444702));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x68u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006A941;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A941u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A941: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A941u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_scene_array_runtime.render_work_records.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006A955;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A955u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A955: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A955u);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    cpu->edi = cpu->esi;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46A97Du); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A98F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A98Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A98F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A98Fu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A9A3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A9A3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A9A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A9A3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 8u))));
    lift_store_f32(cpu->edi + cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006A9CB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A9CBu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006A9CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A9CBu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006A9DF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6A9DFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006A9DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x46A9DFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->edx;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AA0B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AA0Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AA0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AA0Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AA1F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AA1Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AA1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AA1Fu);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AA39;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AA39u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AA39: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AA39u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AA4D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AA4Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AA4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AA4Du);
    lift_x87_push(cpu, (double)-1.0f);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AA6B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AA6Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AA6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AA6Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AA7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AA7Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AA7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AA7Fu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AA98;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AA98u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AA98: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AA98u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AAAC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AAACu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AAAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AAACu);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AAC6;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AAC6u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AAC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AAC6u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AADA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AADAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AADAu);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_x87_push(cpu, 1.0);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_landscape_render_runtime.rotation_step))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.19634956121444702));
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x70u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006AB0D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AB0Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AB0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AB0Du);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_scene_array_runtime.render_work_records.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0006AB21;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AB21u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AB21: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AB21u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx)))));
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    cpu->edi = cpu->esi;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AB3Fu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AB51;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AB51u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AB51: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AB51u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AB65;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AB65u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AB65: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AB65u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 8u))));
    lift_store_f32(cpu->edi + cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AB8E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AB8Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AB8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AB8Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006ABA2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ABA2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006ABA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ABA2u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.333333015441895));
    lift_store_f32(cpu->edi + cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006ABCF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ABCFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006ABCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ABCFu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006ABE3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ABE3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006ABE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ABE3u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006ABFD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ABFDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006ABFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ABFDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AC11;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AC11u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AC11: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AC11u);
    lift_x87_push(cpu, (double)-1.0f);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AC2E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AC2Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AC2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AC2Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AC42;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AC42u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AC42: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AC42u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AC5C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AC5Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AC5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AC5Cu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AC70;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AC70u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AC70: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AC70u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006AC8A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AC8Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AC8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AC8Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006AC9E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AC9Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AC9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AC9Eu);
    lift_x87_push(cpu, 1.0);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    ++cpu->esi;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006ACC5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ACC5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006ACC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ACC5u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006ACD9;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ACD9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006ACD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ACD9u);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFCu);
    lift_store16(cpu->edx + ((uint32_t)(cpu->edi) * 2u), cpu->ecx & 0xFFFFu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006AD01;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AD01u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AD01: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AD01u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006AD15;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AD15u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AD15: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AD15u);
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ebx = (uint32_t)(cpu->esi + 0xFFFFFFFDu);
    lift_store16(cpu->eax + ((uint32_t)(cpu->edi) * 2u), cpu->ebx & 0xFFFFu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006AD3C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AD3Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AD3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AD3Cu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006AD50;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AD50u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AD50: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AD50u);
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006AD78;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AD78u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AD78: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AD78u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006AD8C;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AD8Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AD8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AD8Cu);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    lift_store16(cpu->edx + ((uint32_t)(cpu->edi) * 2u), cpu->ebx & 0xFFFFu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006ADB1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ADB1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006ADB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ADB1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006ADC5;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ADC5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006ADC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ADC5u);
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006ADED;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6ADEDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006ADED: cpu->eip = LIFT_CODE_TOKEN_VA(0x46ADEDu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006AE01;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AE01u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AE01: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AE01u);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(0x74u) + (uint64_t)(0u));
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    lift_store16(cpu->edx + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->edi = lift_load32(cpu->esp + 0x34u);
    goto label_0006A500;
    label_0006AE24: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AE24u);
    cpu->ecx = lift_load32(cpu->ebx + 0xCu);
    cpu->edx = (uint32_t)(cpu->ebx + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AE2Fu); lift_push32(cpu, r); sfera_sub_004689E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006AE40;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AE40u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AE40: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AE40u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006AE54;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AE54u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AE54: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AE54u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 8u))) & 0xFFu);
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x216u, cpu->edx & 0xFFu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xAu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xBu); lift_push32(cpu, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x224u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x225u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AEA0u); lift_push32(cpu, r); sfera_sub_004D8F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AEB1u); lift_push32(cpu, r); sfera_sub_004D8F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->esp + 0x1D0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AEC6u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x70u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AF27u); lift_push32(cpu, r); sfera_sub_004681A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x214u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AF33u); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AF41u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x214u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AF4Du); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006AF5E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AF5Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006AF5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AF5Eu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006AF72;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6AF72u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006AF72: cpu->eip = LIFT_CODE_TOKEN_VA(0x46AF72u);
    lift_push32(cpu, 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 0x104u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46AF7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46AF83u);
    lift_x87_push(cpu, 1.0);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x110u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_store_f32(cpu->esp + 0x114u, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 8u));
    cpu->eax = (uint32_t)(cpu->esp + 0x100u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0x124u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x128u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x12Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x144u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x114u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x118u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x11Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46AFF7u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x112u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B007u); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity) > (int32_t)(uint32_t)(0u)) goto label_0006B01C;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B01Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B01C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B01Cu);
    { uint64_t l=(uint64_t)(g_sfera_scene_array_runtime.render_work_records.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = g_sfera_light_runtime.cell_light_ids.data;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006B037;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B037u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B037: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B037u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x14u); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B058u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    label_0006B064: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B064u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x34u)) >= (int32_t)(uint32_t)(0u)) goto label_0006B075;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B075u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B075: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B075u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_ranges.capacity)) goto label_0006B08D;
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_ranges.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B08Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B08D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B08Du);
    cpu->ecx = g_sfera_scene_array_runtime.render_ranges.data;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u))) goto label_0006B2B1;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->eax);
    cpu->ebx += 0x2710u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006B0BE;
    --cpu->ebx;
    cpu->ebx |= 0xFFFFFFFCu;
    ++cpu->ebx;
    label_0006B0BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B0BEu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax += 0x2710u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006B0D6;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFCu;
    ++cpu->eax;
    label_0006B0D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B0D6u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006B0E8;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B0E8u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B0E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B0E8u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B0FC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B0FCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B0FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B0FCu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.25));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->edi + cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006B126;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B126u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B126: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B126u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B13A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B13Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B13A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B13Au);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.25));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->edi + cpu->edx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006B163;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B163u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B163: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B163u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B177;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B177u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B177: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B177u);
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.25));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->edi + cpu->eax + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006B1A5;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B1A5u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B1A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B1A5u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B1B9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B1B9u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B1B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B1B9u);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->ecx + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006B1D4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B1D4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B1D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B1D4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B1E8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B1E8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B1E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B1E8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006B204;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B204u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B204: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B204u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B218;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B218u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B218: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B218u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.25));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->edi + cpu->ecx + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006B24A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B24Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B24A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B24Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B25E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B25Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B25E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B25Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store_f32(cpu->edi + cpu->edx + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006B27A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B27Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B27A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B27Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.render_work_records.capacity)) goto label_0006B28E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B28Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B28E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B28Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    cpu->eax = g_sfera_scene_array_runtime.render_work_records.data;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    lift_store_f32(cpu->edi + cpu->eax + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    ++cpu->esi;
    cpu->edi -= 0xFFFFFF80u;
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(0x74u) + (uint64_t)(0u));
    goto label_0006B064;
    label_0006B2B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B2B1u);
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006B2C2;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B2C2u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B2C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B2C2u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006B2D6;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B2D6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B2D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B2D6u);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u));
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006B2F7;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B2F7u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B2F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B2F7u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006B30B;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B30Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B30B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B30Bu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 4u))) goto label_0006B3AB;
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006B335;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B335u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B335: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B335u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006B349;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B349u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B349: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B349u);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u)) & 0xFFu);
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x216u, cpu->edx & 0xFFu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xAu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x214u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x218u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x219u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B391u); lift_push32(cpu, r); sfera_sub_0049A4A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B39Fu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x214u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B3ABu); lift_push32(cpu, r); sfera_sub_0049A4C0(cpu,r); if (cpu->eip != r) return; }
    label_0006B3AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B3ABu);
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006B3BC;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B3BCu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B3BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B3BCu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006B3D0;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B3D0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B3D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B3D0u);
    lift_push32(cpu, 0x44u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46B3DCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46B3E1u);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->esp + 0x154u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x158u, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_store_f32(cpu->esp + 0x15Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 0xCu));
    cpu->edx = (uint32_t)(cpu->esp + 0x148u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x154u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->edx);
    lift_store_f32(cpu->esp + 0x16Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x170u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x174u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x15Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x160u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x164u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B455u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x112u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B465u); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity) > (int32_t)(uint32_t)(0u)) goto label_0006B47A;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B47Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B47A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B47Au);
    { uint64_t l=(uint64_t)(g_sfera_scene_array_runtime.render_work_records.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = g_sfera_light_runtime.cell_light_ids.data;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006B495;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B495u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B495: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B495u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x14u); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B4B5u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_options_dialog_runtime.reflection_quality) <= (int32_t)(uint32_t)(0u)) goto label_0006B672;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20000u); lift_push32(cpu, 0xBu); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B4D6u); lift_push32(cpu, r); sfera_sub_004D8F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x103u); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B4EAu); lift_push32(cpu, r); sfera_sub_004D8F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->esp + 0x190u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B4FFu); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)255.0f);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x6Cu);
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    cpu->ecx = lift_load32(cpu->esp + 0x70u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B558u); lift_push32(cpu, r); sfera_sub_004681A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_render_sample_runtime.active_record;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B56Eu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006B57F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B57Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006B57F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B57Fu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_0006B593;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B593u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B593: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B593u);
    lift_push32(cpu, 0x44u);
    cpu->edx = (uint32_t)(cpu->esp + 0x7Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46B59Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46B5A1u);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 0x10u));
    cpu->edx = (uint32_t)(cpu->esp + 0x78u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->edx);
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B612u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x112u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B622u); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity) > (int32_t)(uint32_t)(0u)) goto label_0006B637;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B637u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B637: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B637u);
    { uint64_t l=(uint64_t)(g_sfera_scene_array_runtime.render_work_records.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = g_sfera_light_runtime.cell_light_ids.data;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006B652;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.render_work_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B652u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B652: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B652u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state;
    cpu->ecx = g_sfera_scene_array_runtime.render_work_records.data;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x14u); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B672u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    label_0006B672: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B672u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_window_runtime.landscape_grid_count)) goto label_0006A43E;
    label_0006B687: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B687u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B692u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xBu); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B6A3u); lift_push32(cpu, r); sfera_sub_004D8F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x18u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B6B4u); lift_push32(cpu, r); sfera_sub_004D8F90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->esp + 0x1D0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B6C9u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 0x7Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46B6D2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46B6D7u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x78u);
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B738u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B73Du); lift_push32(cpu, r); sfera_sub_00468B40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax, cpu->edx);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B79Eu); lift_push32(cpu, r); sfera_sub_004681A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B7ADu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    label_0006B7AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B7ADu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046B7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46B7D0u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_0006B998;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0006B804;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B804u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B804: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B804u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_0006B998;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0006B827;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B827u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006B827: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B827u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_0006B94C;
    label_0006B838: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B838u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B83Fu); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x418u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x158u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x414u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x410u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x164u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x150u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x15Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x168u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x154u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x160u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x16Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.z.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_vector_runtime.object_position_delta.x.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_scene_vector_runtime.object_position_delta.y.f32)));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_scene_vector_runtime.object_position_delta.z.f32)));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_0006B9C0;
    if ((uint8_t)(g_sfera_graphics_runtime.render_mode_enabled) != (uint8_t)(1u)) goto label_0006B9C0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32));
    lift_x87_push(cpu, 333.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006B9C0;
    label_0006B94C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B94Cu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_0006B838;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46B968u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0006B971;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0006B971: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B971u);
    lift_push32(cpu, 0xC64u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46B986u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46B98Cu);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B998u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006B998: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B998u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)(0u);
    --cpu->edi;
    label_0006B9A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B9A5u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0006B9A5;
    cpu->ecx = 6u;
    cpu->esi = (uint32_t)(uintptr_t)"move_object: wrong handle";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6B9C0u); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    label_0006B9C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46B9C0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046B9E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46B9E0u);
    cpu->esp -= 0x34u;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_store32(cpu->esp + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BA29u); lift_push32(cpu, r); sfera_sub_00430900(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->edx + 0x1F0u);
    cpu->ecx = 0x18u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_movs32(cpu, 1u);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = 0xFu;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x;
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x));
    cpu->esi = lift_pop32(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006BA9A;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    label_0006BA9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BA9Au);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB01;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_0006BAAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BAAFu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006BAC2;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    label_0006BAC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BAC2u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB05;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0006BAD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BAD9u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0006BAEC;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    label_0006BAEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BAECu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB09;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    goto label_0006BB0B;
    label_0006BB01: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB01u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BAAF;
    label_0006BB05: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB05u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BAD9;
    label_0006BB09: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB09u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006BB0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB0Bu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB22;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    label_0006BB22: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB22u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB91;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_0006BB37: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB37u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB4E;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    label_0006BB4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB4Eu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB95;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0006BB65: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB65u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB7C;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    label_0006BB7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB7Cu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BB99;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    goto label_0006BB9B;
    label_0006BB91: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB91u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BB37;
    label_0006BB95: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB95u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BB65;
    label_0006BB99: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB99u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006BB9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BB9Bu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].x));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BBB2;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    label_0006BBB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BBB2u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BC21;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_0006BBC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BBC7u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].y));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BBDE;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    label_0006BBDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BBDEu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BC25;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0006BBF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BBF5u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].z));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BC0C;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    label_0006BC0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC0Cu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BC29;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    goto label_0006BC2B;
    label_0006BC21: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC21u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BBC7;
    label_0006BC25: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC25u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BBF5;
    label_0006BC29: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC29u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006BC2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC2Bu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BC42;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    label_0006BC42: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC42u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BCB1;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_0006BC57: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC57u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BC6E;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    label_0006BC6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC6Eu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BCB5;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0006BC85: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC85u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BC9C;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    label_0006BC9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BC9Cu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0006BCB9;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    goto label_0006BCBB;
    label_0006BCB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BCB1u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BC57;
    label_0006BCB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BCB5u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0006BC85;
    label_0006BCB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BCB9u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006BCBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BCBBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 1024.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BCCEu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 3u, (lift_x87_get(cpu, 3u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    g_sfera_view_geometry_runtime.projected_bounds.min_x = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BCDCu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    g_sfera_view_geometry_runtime.projected_bounds.max_x = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BCECu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    g_sfera_view_geometry_runtime.projected_bounds.min_y = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BCFAu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    g_sfera_view_geometry_runtime.projected_bounds.max_y = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BD0Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_view_geometry_runtime.projected_bounds.min_z = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BD16u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    g_sfera_view_geometry_runtime.projected_bounds.max_z = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BD20u); lift_push32(cpu, r); sfera_sub_00468310(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x34u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046BD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46BD40u);
    cpu->esp -= 0x134u;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.z));
    lift_push32(cpu, cpu->ebx);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.x));
    lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = cpu->edx;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.y));
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x134u);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BD88u); lift_push32(cpu, r); sfera_sub_00468050(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 1u;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0006BDA1;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6BDA1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006BDA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BDA1u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0xD8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0006BDF7;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6BDF7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006BDF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BDF7u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = (uint32_t)(cpu->esp + 0x134u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xD4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.view_matrix);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixLookAtRH), LIFT_CODE_TOKEN_VA(0x46BE18u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46BE1Du);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14Cu)))));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x15Cu)))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.y));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.x));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BE76u); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BE8Fu); lift_push32(cpu, r); sfera_sub_004EED60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_d3d9_semantic_state.projection_matrix);
    lift_native_call(cpu, native_function_address32(&::D3DXMatrixPerspectiveFovRH), LIFT_CODE_TOKEN_VA(0x46BEAAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46BEAFu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0006BEC3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6BEC3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006BEC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BEC3u);
    cpu->esi = g_sfera_world_objects.object_handles.data;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0006BEDD;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6BEDDu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006BEDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x46BEDDu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_model_transform_scratch_matrix);
    cpu->edx += 0x14u;
    cpu->ecx += 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BEF8u); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_model_coordinate_matrix.m[0][0];
    cpu->edi = (uint32_t)(cpu->esp + 0x90u);
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_model_transform_scratch_matrix;
    cpu->ecx = (uint32_t)(cpu->esp + 0x90u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BF1Cu); lift_push32(cpu, r); sfera_sub_0044B920(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BF40u); lift_push32(cpu, r); sfera_sub_0044B890(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->edi = *(uint32_t*)(void*)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x14u))));
    cpu->ebx = lift_load32(cpu->esp + 0x148u);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->esp + 0x90u);
    lift_movs32(cpu, 1u);
    cpu->esi = lift_load32(cpu->esp + 0x150u);
    cpu->edi = lift_load32(cpu->esp + 0x14Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_store16((uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0x564], 0u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BF94u); lift_push32(cpu, r); sfera_sub_0044B7D0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0xECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0xF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0xE0u, cpu->ebp);
    lift_store32(cpu->esp + 0xE4u, cpu->ebx);
    lift_store32(cpu->esp + 0xE8u, cpu->edi);
    lift_store32(cpu->esp + 0xECu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46BFD5u); lift_push32(cpu, r); sfera_sub_004D8970(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x12Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x128u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0xF4u);
    lift_store_f32(cpu->esp + 0x124u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edx);
    lift_store_f32(cpu->esp + 0x124u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x100u);
    lift_store_f32(cpu->esp + 0x120u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x11Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x118u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x114u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x108u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x104u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x100u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x138u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x124u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x110u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C061u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.view_matrix); lift_push32(cpu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C073u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, (uintptr_t)&g_sfera_d3d9_semantic_state.projection_matrix); lift_push32(cpu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C085u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    --cpu->esi;
    lift_push32(cpu, cpu->esi);
    --cpu->edi;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C092u); lift_push32(cpu, r); sfera_sub_0046B9E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x134u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046C0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46C0B0u);
    cpu->esp -= 0x30u;
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006C0D1;
    cpu->ecx = (uint32_t)(uintptr_t)"Activate light error N3";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C0D1u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006C0D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C0D1u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0x7530u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C0DCu); lift_push32(cpu, r); sfera_sub_0044EFE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0006CB8A;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = 0x7530u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C0F1u); lift_push32(cpu, r); sfera_sub_0044F240(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0006C114;
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    sfera_sub_004D8AA0(cpu, stop_address); return;
    label_0006C114: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C114u);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, 0u);
    cpu->ebx = cpu->ebp;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0006C25E;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0006C130: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C130u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0006C13E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C13Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C13E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C13Eu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_indices.capacity)) goto label_0006C152;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C152u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C152: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C152u);
    cpu->edx = g_sfera_light_runtime.cell_indices.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->edx + 0x1B0Cu);
    cpu->edx = lift_load32(cpu->edx + 0x1B14u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ebp = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    cpu->edx += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(0x7530u)) goto label_0006C348;
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0006C24B;
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0006C1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C1B0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF8u));
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.world_anchor.x.f32)));
    ++cpu->edx;
    cpu->edi += 0x20u;
    cpu->esi += 0x1Cu;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    cpu->eax += 0x28u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.world_anchor.y.f32)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFD8u))));
    lift_store32(cpu->esi + 0xFFFFFFE4u, cpu->ebx);
    lift_store32(cpu->esi + 0xFFFFFFE8u, cpu->ebp);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esi + 0xFFFFFFECu, cpu->ebp);
    lift_store32(cpu->edi + 0xFFFFFFE0u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->edi + 0xFFFFFFE4u, cpu->ebx);
    lift_store32(cpu->edi + 0xFFFFFFE8u, cpu->ebp);
    cpu->ebx = lift_load32(cpu->eax + 0xFFFFFFDCu);
    lift_store32(cpu->edi + 0xFFFFFFECu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax + 0xFFFFFFE0u);
    lift_store32(cpu->edi + 0xFFFFFFF0u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax + 0xFFFFFFE4u);
    lift_store32(cpu->edi + 0xFFFFFFF4u, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFE8u));
    lift_store_f32(cpu->edi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFECu));
    lift_store_f32(cpu->edi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF0u));
    lift_store_f32(cpu->esi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF4u));
    lift_store32(cpu->esi + 0xFFFFFFF0u, 0xFFB4B4B4u);
    lift_store_f32(cpu->esi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xFFFFFFF4u, 0x323232u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->ecx))) goto label_0006C1B0;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0006C24B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C24Bu);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0006C130;
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    label_0006C25E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C25Eu);
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C272u); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C287u); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    cpu->eax += 0x7530u;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_push32(cpu, 0xFFFFFFu);
    cpu->eax += 0x7530u;
    lift_push32(cpu, 0x22u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_04) = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C2BFu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, 1u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0006C5F6;
    label_0006C2E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C2E1u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0006C2F3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C2F3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C2F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C2F3u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_indices.capacity)) goto label_0006C307;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C307u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C307: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C307u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + 0x1B0Cu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006C352;
    cpu->eax = lift_load16(cpu->ebp + 0x10u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    goto label_0006C43A;
    label_0006C348: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C348u);
    cpu->ecx = (uint32_t)(uintptr_t)"VB_SIZE exceed!";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C352u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006C352: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C352u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint16_t)(lift_load16(cpu->ebp + 0x10u)) == (uint16_t)((cpu->eax & 0xFFFFu))) goto label_0006C43A;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_18)) == (uint32_t)(0u)) goto label_0006C37A;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C378u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    goto label_0006C3A3;
    label_0006C37A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C37Au);
    cpu->eax = cpu->eax & 0xFFFFu;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edi = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].name));
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C38Eu); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C39Cu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C3A3u); lift_push32(cpu, r); sfera_sub_0049A4B0(cpu,r); if (cpu->eip != r) return; }
    label_0006C3A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C3A3u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C3AAu); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_light_runtime.cell_light_ids.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006C3C1;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C3C1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C3C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C3C1u);
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C3CCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46C3D1u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C3E9u); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C422u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_08, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->ecx = lift_load16(cpu->ebp + 0x10u);
    cpu->edi += cpu->ebx;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->ebx = 0u;
    label_0006C43A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C43Au);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->edx + 0x1B18u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 8u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0006C50E;
    label_0006C461: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C461u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006C46F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C46Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C46F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C46Fu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006C483;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C483u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C483: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C483u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi)) & 0xFFFFu);
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_store16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0xFFFFFFFEu, cpu->eax & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006C4A1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C4A1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C4A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C4A1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006C4B5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C4B5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C4B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C4B5u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi + 2u)) & 0xFFFFu);
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_store16(cpu->eax + ((uint32_t)(cpu->esi) * 2u) + 0xFFFFFFFEu, cpu->edx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006C4D3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C4D3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C4D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C4D3u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006C4E7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C4E7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C4E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C4E7u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi + 4u)) & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    lift_store16(cpu->edx + ((uint32_t)(cpu->esi) * 2u), cpu->ecx & 0xFFFFu);
    ++cpu->eax;
    ++cpu->esi;
    cpu->edi += 6u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_0006C461;
    label_0006C50E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C50Eu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ebx += lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0006C2E1;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0006C5F6;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_18)) == (uint32_t)(0u)) goto label_0006C549;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C547u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    goto label_0006C574;
    label_0006C549: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C549u);
    cpu->eax = lift_load16(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edi = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].name));
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C55Fu); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C56Du); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C574u); lift_push32(cpu, r); sfera_sub_0049A4B0(cpu,r); if (cpu->eip != r) return; }
    label_0006C574: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C574u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C57Bu); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_light_runtime.cell_light_ids.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006C592;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C592u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C592: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C592u);
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C59Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46C5A2u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C5BAu); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax += lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C5F0u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_08, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    label_0006C5F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C5F6u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C605u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) != (uint32_t)(0u)) goto label_0006C758;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C621u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0006C758;
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    label_0006C637: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C637u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006C649;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C649u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C649: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C649u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_indices.capacity)) goto label_0006C65D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C65Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C65D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C65Du);
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edx + 0x1B0Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 0x10u)), r=(uint64_t)(0x40000000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006C745;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0006C745;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0006C6A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C6A0u);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C6A9u); lift_push32(cpu, r); sfera_sub_0045BE50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C6B4u); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ecx + 0x1B18u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 2u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C6CFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46C6D4u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C6EBu); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_window_runtime.render_vertex_buffer;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C727u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 2u));
    ++cpu->ebx;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_0006C6A0;
    label_0006C745: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C745u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0006C637;
    label_0006C758: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C758u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].x));
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x30u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].y));
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x30u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].z));
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_store64(cpu->esp + 0x30u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->eax &= 0xFFu;
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_push32(cpu, 0x22u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C7F9u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 3u); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C808u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_02;
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C815u); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C824u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C82Bu); lift_push32(cpu, r); sfera_sub_0049A4B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ebp = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 0x44u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006CAC7;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    (void)cpu;
    label_0006C850: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C850u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0006C85E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C85Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C85E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C85Eu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_indices.capacity)) goto label_0006C872;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C872u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C872: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C872u);
    { uint64_t l=(uint64_t)(g_sfera_recovered_static_runtime.scene_state_09), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = g_sfera_light_runtime.cell_indices.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_load32(cpu->ecx + 0x1B0Cu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006C8B1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C8ACu); lift_push32(cpu, r); sfera_sub_00456E20(cpu,r); if (cpu->eip != r) return; }
    g_sfera_recovered_static_runtime.scene_state_09 = (uint32_t)(cpu->eax);
    label_0006C8B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C8B1u);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->eax &= 0x3FFFFFFFu;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_0006C8F4;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0006C8D1;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C8D1u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C8D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C8D1u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_records.capacity)) goto label_0006C8E5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C8E5u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C8E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C8E5u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx += g_sfera_light_runtime.cell_records.data;
    goto label_0006C9D1;
    label_0006C8F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C8F4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_0006C9D5;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C90Bu); lift_push32(cpu, r); sfera_sub_004689E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C912u); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_light_runtime.cell_light_ids.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006C929;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C929u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C929: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C929u);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46C935u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46C93Au);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C951u); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx += lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46C987u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_08, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->eax &= 0x3FFFFFFFu;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0006C9AD;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C9ADu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006C9AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C9ADu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_records.capacity)) goto label_0006C9C1;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_records.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C9C1u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006C9C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C9C1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx += g_sfera_light_runtime.cell_records.data;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->ebx = 0u;
    label_0006C9D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C9D1u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    label_0006C9D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x46C9D5u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->edx + 0x1B18u);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006CAB1;
    (void)cpu;
    label_0006CA00: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CA00u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0006CA0E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CA0Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006CA0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CA0Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006CA22;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CA22u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006CA22: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CA22u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi)) & 0xFFFFu);
    cpu->eax = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_store16(cpu->eax + ((uint32_t)(cpu->esi) * 2u) + 0xFFFFFFFEu, cpu->edx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006CA3F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CA3Fu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006CA3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CA3Fu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006CA53;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CA53u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006CA53: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CA53u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi + 2u)) & 0xFFFFu);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(cpu->esi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    lift_store16(cpu->edx + ((uint32_t)(cpu->esi) * 2u) + 0xFFFFFFFEu, cpu->ecx & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006CA72;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CA72u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0006CA72: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CA72u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.cell_light_ids.capacity)) goto label_0006CA86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CA86u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006CA86: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CA86u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi + 4u)) & 0xFFFFu);
    cpu->ecx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u), cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->eax;
    ++cpu->esi;
    cpu->edi += 6u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0006CA00;
    label_0006CAB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CAB1u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ebx += lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x60u) + (uint64_t)(0u));
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0006C850;
    label_0006CAC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CAC7u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CAD4u); lift_push32(cpu, r); sfera_sub_004689E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CADBu); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_light_runtime.cell_light_ids.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006CAF2;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.cell_light_ids.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CAF2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006CAF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CAF2u);
    cpu->edx = g_sfera_light_runtime.cell_light_ids.data;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->esi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46CAFEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46CB03u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CB1Au); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax += lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CB50u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_08, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CB61u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CB70u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CB75u); lift_push32(cpu, r); sfera_sub_00468B40(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) <= (int32_t)(uint32_t)(1u)) goto label_0006CB88;
    cpu->ecx = (uint32_t)(uintptr_t)"Activate light error N4";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CB88u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006CB88: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CB88u);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0006CB8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CB8Au);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046CBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46CBA0u);
    cpu->esp -= 0xA8u;
    cpu->eax = lift_load32(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_0006CBD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CBD7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CBD7;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    --cpu->eax;
    label_0006CBE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CBE6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CBE6;
    cpu->ecx = lift_load32((uintptr_t)"_00.lnd");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"_00.lnd") + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0006CC06: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CC06u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CC06;
    cpu->eax -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->ebx + 0x30u);
    lift_store8(cpu->esp + cpu->eax + 0x4Au, cpu->ecx & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0006CC20: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CC20u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0006CC20;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x28u)) & 0xFFu);
    cpu->eax -= cpu->ecx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x4Bu, cpu->edx & 0xFFu);
    lift_push32(cpu, 0x431Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x68C0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CC48u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ebp = cpu->eax;
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x8Cu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esi + 0x1Eu);
    cpu->edx = (uint32_t)(cpu->esp + 0x64u);
    cpu->edx -= cpu->eax;
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0006CC70: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CC70u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CC70;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    cpu->edx = cpu->eax;
    label_0006CC80: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CC80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CC80;
    cpu->edi = (uint32_t)(cpu->esp + 0x64u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_0006CC90: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CC90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006CC90;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_0006CCB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CCB0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0006CCB0;
    cpu->eax -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store32(cpu->esp + cpu->eax + 0x61u, 0x6B736Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CCCAu); lift_push32(cpu, r); sfera_sub_0045A9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CCDBu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x68C0u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CCEFu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x4325u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CD0Au); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebp + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CD23u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4327u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x480u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CD37u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)1000.0f);
    lift_store32(cpu->ebp + 0x1B1Cu, cpu->eax);
    cpu->ecx = 0u;
    cpu->eax = 0u;
    label_0006CD47: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CD47u);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->edx + cpu->eax + 8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0x10u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0x18u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0x24u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0x20u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0x2Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0x28u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0x34u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0x30u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0x3Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0x38u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store32(cpu->edx + cpu->eax + 0x44u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0x40u, lift_x87_get(cpu, 0u));
    cpu->eax += 0x48u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x480u)) goto label_0006CD47;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += 0x1Eu;
    cpu->edx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_store32(cpu->ebp + 0x1B0Cu, cpu->ecx);
    lift_store32(cpu->ebp + 0x1B10u, cpu->ecx);
    lift_store32(cpu->ebp + 0x1B14u, cpu->ecx);
    lift_store32(cpu->ebp + 0x1B18u, cpu->ecx);
    cpu->edx -= cpu->eax;
    label_0006CE32: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CE32u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CE32;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    cpu->edx = cpu->eax;
    label_0006CE42: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CE42u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CE42;
    cpu->edi = (uint32_t)(cpu->esp + 0x8Cu);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0006CE53: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CE53u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006CE53;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x8Cu);
    lift_movs8(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0006CE75: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CE75u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006CE75;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + cpu->eax + 0x89u, 0x727477u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CE8Eu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CE9Au); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CEA1u); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0006CECF;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CEB4u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0x1B1Cu);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x480u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CEC8u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CECFu); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    label_0006CECF: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CECFu);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x2514u);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_0006CEF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CEF0u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x34u, 0u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    label_0006CF10: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CF10u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, 0u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    label_0006CF24: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CF24u);
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFF8u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx -= cpu->eax;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x4345u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CF43u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFF8u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->edx -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CF62u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFF4u);
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFF0u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 0x1B1Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 8u) + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006CFB4;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0006CFB2;
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1024.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46CFADu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x4Cu, cpu->eax);
    goto label_0006CFB4;
    label_0006CFB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CFB2u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006CFB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CFB4u);
    cpu->eax = lift_load16(cpu->esi);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != 0u) goto label_0006CFC8;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint16_t)g_sfera_graphics_runtime.base_microtexture_id)) & 0xFFFFu);
    lift_store16(cpu->esi, cpu->ecx & 0xFFFFu);
    goto label_0006CFE4;
    label_0006CFC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CFC8u);
    cpu->edx = cpu->eax;
    cpu->eax = g_sfera_client_main_scalar_runtime.state_02;
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = 0xFFFFu;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFFFu)), r=(uint64_t)((cpu->ecx & 0xFFFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006D1D0;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    label_0006CFE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CFE4u);
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edx)) goto label_0006D017;
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    cpu->edi = cpu->edi;
    label_0006CFF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46CFF0u);
    cpu->ecx = lift_load16(cpu->eax);
    cpu->edi = g_sfera_client_main_scalar_runtime.state_02;
    cpu->ecx = lift_load16(cpu->edi + ((uint32_t)(cpu->ecx) * 2u));
    cpu->edi = 0xFFFFu;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFFFu)), r=(uint64_t)((cpu->edi & 0xFFFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0006D201;
    lift_store16(cpu->eax, cpu->ecx & 0xFFFFu);
    ++cpu->edx;
    cpu->eax += 2u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0006CFF0;
    label_0006D017: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D017u);
    cpu->eax = (int8_t)(lift_load8(cpu->ebx));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006D234;
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(6u), 32u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0006D04F;
    lift_push32(cpu, 0x4363u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D03Eu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->ebx + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x46D047u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46D04Cu);
    cpu->esp += 0xCu;
    label_0006D04F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D04Fu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(0x78u) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->esi += 0x30u;
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->edi + 1u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(9u)) goto label_0006CF24;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x1B0u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x438u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0006CF10;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x10E0u) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(0x6C0u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0006CEF0;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D0B8u); lift_push32(cpu, r); sfera_sub_0044D830(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D0C1u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x46D0C6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46D0CCu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D0D3u); lift_push32(cpu, r); sfera_sub_00452B60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D0E7u); lift_push32(cpu, r); sfera_sub_00468E50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1Eu);
    cpu->edi = cpu->edi;
    label_0006D0F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D0F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006D0F0;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    cpu->edx = cpu->eax;
    label_0006D100: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D100u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0006D100;
    cpu->edi = (uint32_t)(cpu->esp + 0x64u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_0006D110: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D110u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006D110;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_0006D130: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D130u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0006D130;
    cpu->eax -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store32(cpu->esp + cpu->eax + 0x61u, 0x736464u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D14Au); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x4376u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D15Du); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x40u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store32(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u) + 0x3ACu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D173u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u) + 0x3ACu);
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D184u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D18Bu); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    label_0006D192: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D192u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0006D192;
    cpu->eax -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store8(cpu->esp + cpu->eax + 0x4Cu, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D1A8u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xB4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u) + 0x21Cu, cpu->eax);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.client_state_03, (uint64_t)(g_sfera_recovered_static_runtime.client_state_03) + 1u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xA8u;
    lift_return(cpu, 4u, stop_address); return;
    label_0006D1D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D1D0u);
    cpu->eax = lift_load16(cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax &= 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Patch %s has microtexture which not exist: name=%c%c"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46D1EEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46D1F4u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D201u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006D201: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D201u);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax &= 0xFFu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Patch %s has microtexture which not exist: name=%c%c"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46D221u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x46D227u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D234u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0006D234: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D234u);
    cpu->ecx = (uint32_t)(uintptr_t)"Number of layer masks is not the same in lnd and msk";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D23Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x46D23Eu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046D240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46D240u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x8Cu)) != (uint32_t)(0u)) goto label_0006D260;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D260u); lift_push32(cpu, r); sfera_sub_0046CBA0(cpu,r); if (cpu->eip != r) return; }
    label_0006D260: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D260u);
    lift_store32(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0x53Cu, 0x3E8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046D270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46D270u);
    cpu->esp -= 0xCu;
    { uint64_t l=(uint64_t)(g_sfera_color_expansion_runtime.initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006D2BF;
    lift_x87_push(cpu, 31.0);
    cpu->esi = 0u;
    lift_x87_push(cpu, 255.0);
    g_sfera_color_expansion_runtime.initialized = (uint8_t)(1u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_0006D29D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D29Du);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D2AAu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]), cpu->eax);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x20u)) goto label_0006D29D;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0006D2BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D2BFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, 0.11999999731779099);
    lift_store32(cpu->ebx, 0u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->edi, 0u);
    lift_x87_push(cpu, 100000.0);
    lift_store32(cpu->esi, 0u);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D2F0u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    cpu->ecx = (uint32_t)(cpu->eax + 0x4E20u);
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->ebp = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFD8F0u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D31Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->eax + 0x4E20u);
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 0xFFFFD8F0u);
    cpu->eax = 0x27u;
    cpu->ecx = (uint32_t)(cpu->ebp + 0x28u);
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x4Fu)) goto label_0006D68F;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x4Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0006D68F;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax += cpu->edx;
    cpu->ecx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edx = lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    cpu->ebp = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebp) * 2u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u) + 0x8Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006D397;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D393u); lift_push32(cpu, r); sfera_sub_0046CBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    label_0006D397: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D397u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u) + 0x53Cu, 0x3E8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x20u))))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_push(cpu, 100.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) / (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, 254.0);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 3u, (lift_x87_get(cpu, 3u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D3D8u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esp + 0x24u))))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D402u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFEu);
    lift_store32(cpu->esp + 0x24u, 5u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0006D410: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D410u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFFFEu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006D41F;
    cpu->edx = 0u;
    goto label_0006D42C;
    label_0006D41F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D41Fu);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(0xFFu)) goto label_0006D42C;
    cpu->edx = 0xFFu;
    label_0006D42C: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D42Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0006D434;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    goto label_0006D441;
    label_0006D434: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D434u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006D441;
    cpu->eax = 0xFFu;
    label_0006D441: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D441u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u) + 0x3ACu);
    cpu->eax = lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0xBu), 32u);
    lift_store32(cpu->ebx, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(6u), 32u);
    cpu->edx &= 0x1Fu;
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax &= 0x1Fu;
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->ebx, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->esi, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006D49A;
    cpu->edx = 0u;
    goto label_0006D4A7;
    label_0006D49A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D49Au);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(0xFFu)) goto label_0006D4A7;
    cpu->edx = 0xFFu;
    label_0006D4A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D4A7u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0006D4AF;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    goto label_0006D4BC;
    label_0006D4AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D4AFu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006D4BC;
    cpu->eax = 0xFFu;
    label_0006D4BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D4BCu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u) + 0x3ACu);
    cpu->eax = lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0xBu), 32u);
    lift_store32(cpu->ebx, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(6u), 32u);
    cpu->edx &= 0x1Fu;
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax &= 0x1Fu;
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->ebx, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->esi, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->eax = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0006D51A;
    cpu->edx = 0u;
    goto label_0006D52B;
    label_0006D51A: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D51Au);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = 0xFFu;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0006D52B;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_0006D52B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D52Bu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0006D533;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    goto label_0006D540;
    label_0006D533: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D533u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006D540;
    cpu->eax = 0xFFu;
    label_0006D540: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D540u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u) + 0x3ACu);
    cpu->eax = lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0xBu), 32u);
    lift_store32(cpu->ebx, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(6u), 32u);
    cpu->edx &= 0x1Fu;
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax &= 0x1Fu;
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->ebx, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->esi, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006D599;
    cpu->edx = 0u;
    goto label_0006D5A6;
    label_0006D599: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D599u);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(0xFFu)) goto label_0006D5A6;
    cpu->edx = 0xFFu;
    label_0006D5A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D5A6u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0006D5AE;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    goto label_0006D5BB;
    label_0006D5AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D5AEu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006D5BB;
    cpu->eax = 0xFFu;
    label_0006D5BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D5BBu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ebp = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u) + 0x3ACu);
    cpu->eax = lift_load16(cpu->ebp + ((uint32_t)(cpu->eax) * 2u) + 0x20u);
    cpu->ebp = cpu->eax;
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(0xBu), 32u);
    lift_store32(cpu->ebx, cpu->ebp);
    cpu->ebp = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(6u), 32u);
    cpu->ebp &= 0x1Fu;
    lift_store32(cpu->edi, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->ebx, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    cpu->eax = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->edi, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0006D616;
    cpu->ebp = 0u;
    goto label_0006D623;
    label_0006D616: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D616u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(0xFFu)) goto label_0006D623;
    cpu->ebp = 0xFFu;
    label_0006D623: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D623u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0006D62B;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    goto label_0006D638;
    label_0006D62B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D62Bu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0006D638;
    cpu->eax = 0xFFu;
    label_0006D638: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D638u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u) + 0x3ACu);
    cpu->eax = lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 2u) + 0x20u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0xBu), 32u);
    lift_store32(cpu->ebx, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(6u), 32u);
    cpu->edx &= 0x1Fu;
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax &= 0x1Fu;
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->ebx, cpu->edx);
    cpu->eax = lift_load32(cpu->edi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_color_expansion_runtime.five_bit_to_eight_bit[0]));
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x24u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x24u, v); }
    lift_store32(cpu->esi, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006D410;
    label_0006D68F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D68Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0046D6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x46D6A0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0006D6C0;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D6C0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006D6C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D6C0u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1000.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D6E2u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFC18u);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0006D6FC;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D6FCu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006D6FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D6FCu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1000.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D71Fu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFFFC18u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0006D73D;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D73Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006D73D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D73Du);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1000.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D760u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (uint32_t)(cpu->eax + 0xFFFFFC18u);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0006D77E;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D77Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0006D77E: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D77Eu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_y))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1000.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D7A0u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax -= 0x3E8u;
    cpu->ebp = cpu->edi;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0006D89D;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x64u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->edi = cpu->edi;
    label_0006D7C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D7C0u);
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->eax)) goto label_0006D88B;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x64u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->edi = 0x27u;
    cpu->ecx -= cpu->esi;
    cpu->ebp += 0x28u;
    cpu->edi -= cpu->esi;
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0006D7F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D7F0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.world_anchor.z, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ebp) > (uint32_t)(0x4Fu)) goto label_0006D876;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x4Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0006D876;
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 4u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += cpu->edi;
    cpu->esi = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0]));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x16u);
    cpu->edx = lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x));
    cpu->eax = lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_y));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ebx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x8Cu)) != (uint32_t)(0u)) goto label_0006D84F;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6D84Fu); lift_push32(cpu, r); sfera_sub_0046CBA0(cpu,r); if (cpu->eip != r) return; }
    label_0006D84F: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D84Fu);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x8Cu);
    lift_store32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x53Cu, 0x3E8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x46D866u); lift_push32(cpu, r); sfera_sub_00454410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    label_0006D876: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D876u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x64u) + (uint64_t)(0u));
    --cpu->edi;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0006D7F0;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_0006D88B: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D88Bu);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x64u) + (uint64_t)(0u));
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0006D7C0;
    label_0006D89D: cpu->eip = LIFT_CODE_TOKEN_VA(0x46D89Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}
