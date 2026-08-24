#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

static int sfera_cp1251_is_russian_vowel_or_sign(uint8_t value) { switch (value) { case UINT8_C(0xF3): case UINT8_C(0xE5): case UINT8_C(0xFB): case UINT8_C(0xE0): case UINT8_C(0xEE): case UINT8_C(0xFD): case UINT8_C(0xFF): case UINT8_C(0xE8): case UINT8_C(0xFE): case UINT8_C(0xFC): case UINT8_C(0xFA): return 1; default: return 0; } }
static int sfera_identifier_char_is_keyboard_ambiguous(uint8_t value) { switch (value) { case UINT8_C(0xE5): case 'e': case UINT8_C(0xF3): case 'y': case UINT8_C(0xEA): case 'k': case UINT8_C(0xE3): case 'r': case UINT8_C(0xE7): case '3': case UINT8_C(0xF5): case 'x': case UINT8_C(0xE8): case 'u': case UINT8_C(0xEE): case '0': case 'o': case UINT8_C(0xF0): case 'p': case UINT8_C(0xF1): case 'c': case UINT8_C(0xE0): case 'a': case UINT8_C(0xF2): case 'm': case 'E': case UINT8_C(0xC5): case UINT8_C(0xD3): case 'Y': case 'K': case UINT8_C(0xCA): case UINT8_C(0xC7): case 'X': case UINT8_C(0xD5): case 'O': case UINT8_C(0xCE): case UINT8_C(0xD0): case 'P': case 'C': case UINT8_C(0xD1): case 'A': case UINT8_C(0xC0): return 1; default: return 0; } }

static void sfera_apply_character_alias_group(uint32_t* table, const char* group) { const uint32_t canonical = (uint8_t)group[0]; for (uint32_t alias_index = 1u; group[alias_index] != 0; ++alias_index) { const uint32_t alias = (uint8_t)group[alias_index]; for (uint32_t index = 0u; index < kMaterialFilterCharCount; ++index) { if (table[index] == alias) { table[index] = canonical; } } } }

static float sfera_grass_jitter_x(uint32_t index) { switch (index) { case 0u: return 6.24f; case 1u: return 2.21f; case 2u: return 2.21f; default: return 6.24f; } }
static float sfera_grass_jitter_y(uint32_t index) { switch (index) { case 0u: return 3.73f; case 1u: return 1.17f; case 2u: return 5.60f; default: return 7.15f; } }

LIFT_ENTRY void LIFT_CDECL sfera_sub_00477FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x477FB0u);
    cpu->esp -= 0x4E4u;
    { uint64_t l=(uint64_t)(g_sfera_recovered_static_runtime.scene_state_09), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_shadow_runtime.manager;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00077FF3;
    if ((uint32_t)(cpu->esi) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_00077FF3;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x477FEEu); lift_push32(cpu, r); sfera_sub_00460D50(cpu,r); if (cpu->eip != r) return; }
    g_sfera_recovered_static_runtime.scene_state_09 = (uint32_t)(cpu->eax);
    label_00077FF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x477FF3u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00078001;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78001u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00078001: cpu->eip = LIFT_CODE_TOKEN_VA(0x478001u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00078015;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78015u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00078015: cpu->eip = LIFT_CODE_TOKEN_VA(0x478015u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_000781EE;
    label_00078025: cpu->eip = LIFT_CODE_TOKEN_VA(0x478025u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478038u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_world_render_runtime.active_model = (uint32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x141u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00079092;
    cpu->ebp = cpu->esi;
    cpu->edx = (uint32_t)(cpu->ebp + 0x14u);
    cpu->ebp += 8u;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_character_frame_matrix.m[0][0]);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x54u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478066u); lift_push32(cpu, r); sfera_sub_0044E2B0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_character_rotation_matrix.m[0][0];
    lift_movs32(cpu, 1u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_character_rotation_matrix.m[2][3], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_character_rotation_matrix.m[1][3], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_character_rotation_matrix.m[0][3], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->esi = (uint32_t)(cpu->esp + 0x90u);
    cpu->edi += 0xE8u;
    lift_store32(cpu->esp + 0x14u, 8u);
    label_000780A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4780A4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->esi, cpu->ecx);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    lift_store32(cpu->esi + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4780C0u); lift_push32(cpu, r); sfera_sub_0041AE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi += 0xCu;
    cpu->esi += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000780A4;
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x94u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4780DFu); lift_push32(cpu, r); sfera_sub_0044C210(cpu,r); if (cpu->eip != r) return; }
    g_sfera_client_main_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00079092;
    cpu->edi = lift_load32(cpu->esp + 0x44u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4780F7u); lift_push32(cpu, r); sfera_sub_0045F060(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.lighting_enabled) = (uint8_t)(0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x194u));
    lift_store_f64(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478162u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x48u)) / (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x1A8u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.20000000298023224);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00078188;
    (*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.lighting_enabled) = (uint8_t)(1u);
    label_00078188: cpu->eip = LIFT_CODE_TOKEN_VA(0x478188u);
    lift_x87_push(cpu, 1.0);
    cpu->esi = lift_load32(cpu->esp + 0x40u);
    cpu->eax = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    lift_x87_push(cpu, (double)-1.0f);
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP2();
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    cpu->eax = g_sfera_view_spatial_runtime.position_offset.z.u32;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    cpu->ecx = g_sfera_view_spatial_runtime.position_offset.x.u32;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_store32(cpu->esp + 0x58u, cpu->edx);
    cpu->edx = g_sfera_view_spatial_runtime.position_offset.y.u32;
    lift_x87_push(cpu, (double)0.009999999776482582f);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00078240;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    goto label_0007829C;
    label_000781EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4781EEu);
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_00078025;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47820Au); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00078213;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_00078213: cpu->eip = LIFT_CODE_TOKEN_VA(0x478213u);
    lift_push32(cpu, 0x273Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xFCu);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47822Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x478231u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xF0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78240u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00078240: cpu->eip = LIFT_CODE_TOKEN_VA(0x478240u);
    lift_x87_push(cpu, (double)0.0007999999797903001f);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x34u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007825E;
    lift_x87_push(cpu, (double)7.999999797903001e-05f);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007825E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47825Eu);
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.lighting_state)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007828A;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x34u))));
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00078293;
    label_0007828A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47828Au);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00078293: cpu->eip = LIFT_CODE_TOKEN_VA(0x478293u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x34u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0007829C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47829Cu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00078361;
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    lift_x87_push(cpu, 0.0);
    g_sfera_view_spatial_runtime.position_offset.x.u32 = (uint32_t)(cpu->ecx);
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x80u);
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    g_sfera_view_spatial_runtime.position_offset.y.u32 = (uint32_t)(cpu->edx);
    g_sfera_view_spatial_runtime.position_offset.z.u32 = (uint32_t)(cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.1693706972350526));
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478335u); lift_push32(cpu, r); sfera_sub_0044E140(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (4500.0));
    lift_x87_set(cpu, 0u, (45.0) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].x, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].y, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[3].z, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00078363;
    label_00078361: cpu->eip = LIFT_CODE_TOKEN_VA(0x478361u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00078363: cpu->eip = LIFT_CODE_TOKEN_VA(0x478363u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x88u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x98u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4783D3u); lift_push32(cpu, r); sfera_sub_004681A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4783DAu); lift_push32(cpu, r); sfera_sub_00468750(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_00078611;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xA0u)) >= (uint8_t)(4u)) goto label_00078611;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00078611;
    lift_x87_push(cpu, (double)50.0f);
    cpu->eax = 0u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_03) <= (int32_t)(uint32_t)(cpu->eax)) goto label_000785D9;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][4];
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00078430: cpu->eip = LIFT_CODE_TOKEN_VA(0x478430u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_active[0]))) == (uint32_t)(0u)) goto label_00078501;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00078501;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 4u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47849Au); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000784FF;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000784FF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000784FF;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFCu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x84u, cpu->ecx);
    lift_store32(cpu->esp + 0x88u, cpu->edx);
    lift_store32(cpu->esp + 0x8Cu, cpu->eax);
    goto label_00078501;
    label_000784FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4784FFu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00078501: cpu->eip = LIFT_CODE_TOKEN_VA(0x478501u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    cpu->edi += 0x3Cu;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_03)) goto label_00078430;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(0u)) goto label_000785D9;
    { uint64_t l=(uint64_t)(g_sfera_view_spatial_runtime.alternate_projection), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x88u))));
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x8Cu))));
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (15.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000785C2;
    lift_x87_push(cpu, (double)0.25f);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_000785C0;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.8299999833106995);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000785C2;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_scale));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000785C0;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000785C2;
    label_000785C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4785C0u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000785C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4785C2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x785D9u); lift_push32(cpu, r); sfera_sub_0048C860(cpu,r); if (cpu->eip != r) return; }
    label_000785D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4785D9u);
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) == (uint8_t)(0u)) goto label_00078611;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) != (uint32_t)(0u)) goto label_00078611;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0x7Cu);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78611u); lift_push32(cpu, r); sfera_sub_0048C860(cpu,r); if (cpu->eip != r) return; }
    label_00078611: cpu->eip = LIFT_CODE_TOKEN_VA(0x478611u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load8(cpu->edi + 0x40u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478623u); lift_push32(cpu, r); sfera_sub_00454FF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_scene_vector_runtime.transform_scratch.x.u32;
    lift_store32(cpu->esi + 0x190u, cpu->eax);
    cpu->ecx = g_sfera_scene_vector_runtime.transform_scratch.y.u32;
    lift_store32(cpu->esi + 0x194u, cpu->ecx);
    cpu->edx = g_sfera_scene_vector_runtime.transform_scratch.z.u32;
    lift_store32(cpu->esi + 0x198u, cpu->edx);
    cpu->eax = g_sfera_scene_vector_runtime.frame_101_position.x.u32;
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    cpu->ecx = g_sfera_scene_vector_runtime.frame_101_position.y.u32;
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esi + 0x1A0u, cpu->ecx);
    cpu->edx = g_sfera_scene_vector_runtime.frame_101_position.z.u32;
    lift_store32(cpu->esi + 0x1A4u, cpu->edx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_00078829;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xA0u)) >= (uint8_t)(4u)) goto label_00078829;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00078829;
    { uint64_t l=(uint64_t)(g_sfera_world_objects.object_handles.capacity), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_000786BB;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x786BBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000786BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4786BBu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 4u))));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478711u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 15.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00078769;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (30.0));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x18u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007876B;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007876D;
    label_00078769: cpu->eip = LIFT_CODE_TOKEN_VA(0x478769u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007876B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47876Bu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007876D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47876Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1B4u));
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478780u); lift_push32(cpu, r); sfera_sub_0045DA60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0xB0u);
    cpu->edx = lift_load32(cpu->ebx + 0xACu);
    cpu->ecx = lift_load32(cpu->ebx + 0xB4u);
    lift_store32(cpu->esp + 0x7Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x78u, cpu->edx);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x80u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp"));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x14u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000787CA;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000787CC;
    label_000787CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4787CAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000787CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4787CCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4787D5u); lift_push32(cpu, r); sfera_sub_004EED5A(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4787E2u); lift_push32(cpu, r); sfera_sub_004EED54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x8Cu));
    lift_push32(cpu, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x80u))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1B4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_x87_set(cpu, 0u, (1.4900000095367432) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->edi + 0x1B4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78829u); lift_push32(cpu, r); sfera_sub_0048CA90(cpu,r); if (cpu->eip != r) return; }
    label_00078829: cpu->eip = LIFT_CODE_TOKEN_VA(0x478829u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00078858;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x148u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478849u); lift_push32(cpu, r); sfera_sub_00450AB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78858u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    label_00078858: cpu->eip = LIFT_CODE_TOKEN_VA(0x478858u);
    cpu->edx = lift_load32(cpu->edi + 0x1E0u);
    cpu->eax = (uint32_t)(cpu->edi + 0x1D4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47886Cu); lift_push32(cpu, r); sfera_sub_0044EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x30u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00078C2E;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    label_00078883: cpu->eip = LIFT_CODE_TOKEN_VA(0x478883u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->ecx + 0x34u);
    cpu->esi += lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load8(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x7Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000788A0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x788A0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000788A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4788A0u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(g_sfera_scene_array_runtime.model_matrices.capacity), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000788B4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.model_matrices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x788B4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_000788B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4788B4u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(6u), 32u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(g_sfera_scene_array_runtime.model_matrices.data), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_right(cpu, (cpu->edx & 0xFFu), (uint32_t)(7u), 8u)) & 0xFFu);
    cpu->eax = cpu->edi;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((*(uint8_t*)(void*)&g_sfera_main_command_state_runtime.lighting_enabled))) goto label_00078C0F;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->edx + 0x3Cu);
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->ecx &= 0x7Fu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xACu);
    cpu->ecx = lift_load8(cpu->ecx + cpu->edx + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_00078908;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x66u)) goto label_00078C0F;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x67u)) goto label_00078C0F;
    label_00078908: cpu->eip = LIFT_CODE_TOKEN_VA(0x478908u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x30u));
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x34u));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x38u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x2Cu));
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x3Cu));
    cpu->eax = (uint32_t)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->eax);
    lift_store_f32(cpu->esp + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x100u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4789BFu); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4789D4u); lift_push32(cpu, r); sfera_sub_0048D170(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load16(cpu->esi + 2u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x88u);
    cpu->edi += (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.basis[2].x.f32)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4789F2u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x6Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.basis[2].y.f32)));
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478A02u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.basis[2].z.f32)));
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478A12u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(0xFFu)) goto label_00078A1F;
    cpu->ebp = 0xFFu;
    label_00078A1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x478A1Fu);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(0xFFu)) goto label_00078A2C;
    cpu->ebx = 0xFFu;
    label_00078A2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x478A2Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFu)) goto label_00078A38;
    cpu->eax = 0xFFu;
    label_00078A38: cpu->eip = LIFT_CODE_TOKEN_VA(0x478A38u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    cpu->ebp |= cpu->edx;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x8Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478A5Fu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load16(cpu->esi + 2u);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx += cpu->eax;
    cpu->eax = lift_load32(cpu->edx + 0x144u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0x28u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(cpu->edi)) goto label_00078AA7;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478A8Eu); lift_push32(cpu, r); sfera_sub_0049A490(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478A9Cu); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478AA3u); lift_push32(cpu, r); sfera_sub_0049A4B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_00078AA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x478AA7u);
    cpu->ecx = lift_load16(cpu->esi + 0xAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478AB0u); lift_push32(cpu, r); sfera_sub_0044EFE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load16(cpu->esi + 8u);
    cpu->edx = g_sfera_world_render_runtime.active_model;
    cpu->edx = lift_load32(cpu->edx + 0x24u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edi = 0u;
    cpu->edx = 0u;
    if ((uint16_t)((cpu->edi & 0xFFFFu)) >= (uint16_t)(lift_load16(cpu->esi + 0xAu))) goto label_00078B0E;
    cpu->eax += 0x1Cu;
    label_00078AD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x478AD0u);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0xFFFFFFE4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0xFFFFFFE8u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0xFFFFFFECu, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_store_f32(cpu->eax + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    ++cpu->edx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1Cu));
    cpu->eax += 0x20u;
    lift_store_f32(cpu->eax + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->eax + 0xFFFFFFD0u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->eax + 0xFFFFFFD4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x14u);
    lift_store32(cpu->eax + 0xFFFFFFD8u, cpu->edi);
    cpu->edi = lift_load16(cpu->esi + 0xAu);
    cpu->ecx += 0x24u;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->edi)) goto label_00078AD0;
    label_00078B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x478B0Eu);
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478B22u); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load16(cpu->esi + 6u);
    cpu->edi = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebx) * 2u));
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(0xBB8u)) goto label_000790AB;
    cpu->eax = lift_load16(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->eax + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = 0u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_collision_scratch_runtime.dynamic_indices_aux[0];
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00078B76;
    label_00078B51: cpu->eip = LIFT_CODE_TOKEN_VA(0x478B51u);
    cpu->ebx = lift_load16(cpu->ecx);
    lift_store16(cpu->eax, cpu->ebx & 0xFFFFu);
    cpu->ebx = lift_load16(cpu->ecx + 2u);
    lift_store16(cpu->eax + 2u, cpu->ebx & 0xFFFFu);
    cpu->ebx = lift_load16(cpu->ecx + 4u);
    lift_store16(cpu->eax + 4u, cpu->ebx & 0xFFFFu);
    cpu->ebx = lift_load16(cpu->esi + 6u);
    ++cpu->edx;
    cpu->eax += 6u;
    cpu->ecx += 0xCu;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00078B51;
    label_00078B76: cpu->eip = LIFT_CODE_TOKEN_VA(0x478B76u);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(g_sfera_client_main_scalar_runtime.mode_01), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00078B8F;
    cpu->ebp = 0u;
    label_00078B8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x478B8Fu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478B96u); lift_push32(cpu, r); sfera_sub_0044F370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_collision_scratch_runtime.dynamic_indices_aux[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x478BA0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x478BA5u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478BBDu); lift_push32(cpu, r); sfera_sub_004D8AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_06;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load16(cpu->esi + 0xAu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_sky_runtime.draw_resource;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ebp |= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478BF7u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_08, (uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_08)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->edx = lift_load16(cpu->esi + 0xAu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.timing_accumulator, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x50u);
    label_00078C0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x478C0Fu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x12u) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x30u))) goto label_00078883;
    cpu->esi = lift_load32(cpu->esp + 0x40u);
    label_00078C2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x478C2Eu);
    lift_push32(cpu, 0x44u);
    cpu->edx = (uint32_t)(cpu->esp + 0x94u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x478C3Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x478C3Fu);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->esp + 0x90u);
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478CB4u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00078D4C;
    lift_push32(cpu, 0x44u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x94u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x478CD5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x478CDAu);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0x90u);
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478D41u); lift_push32(cpu, r); sfera_sub_004D8BC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78D4Cu); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    label_00078D4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x478D4Cu);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03) = (uint32_t)(1u);
    cpu->edi = (uint32_t)(cpu->esi + 0xF8u);
    lift_store32(cpu->esp + 0x3Cu, 5u);
    label_00078D64: cpu->eip = LIFT_CODE_TOKEN_VA(0x478D64u);
    cpu->ecx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00078D6F;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x78D6Fu); lift_push32(cpu, r); sfera_sub_00477020(cpu,r); if (cpu->eip != r) return; }
    label_00078D6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x478D6Fu);
    cpu->edi += 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x3Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x3Cu, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00078D64;
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    g_sfera_view_spatial_runtime.basis[3].x.u32 = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    g_sfera_view_spatial_runtime.position_offset.x.u32 = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    g_sfera_view_spatial_runtime.basis[3].y.u32 = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    g_sfera_view_spatial_runtime.basis[3].z.u32 = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_03) = (uint32_t)(0u);
    g_sfera_view_spatial_runtime.position_offset.y.u32 = (uint32_t)(cpu->ecx);
    g_sfera_view_spatial_runtime.position_offset.z.u32 = (uint32_t)(cpu->edx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_00078FEF;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xA0u)) >= (uint8_t)(4u)) goto label_00078FEF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x148u));
    lift_x87_push(cpu, 1.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00078FEF;
    cpu->edx = lift_load32(cpu->ebx + 0xB8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    cpu->ecx = lift_load32(cpu->ebx + 0xB4u);
    cpu->eax = lift_load32(cpu->ebx + 0xBCu);
    cpu->esi = lift_load32(cpu->ebx + 0xACu);
    cpu->edi = lift_load32(cpu->ebx + 0xB0u);
    lift_store32(cpu->esp + 0x78u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x78u))));
    lift_store32(cpu->esp + 0x74u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xC0u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_store32(cpu->esp + 0x80u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x80u))));
    cpu->esp -= 0xCu;
    lift_store32(cpu->esp + 0x88u, cpu->eax);
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478E6Bu); lift_push32(cpu, r); sfera_sub_0045A8E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 4u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 8u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.800000011920929));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->esp -= 0xCu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->esp + 0x6Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    lift_store32(cpu->esp + 0x64u, cpu->edx);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    lift_store32(cpu->esp + 0x70u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x84u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x88u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x98u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    cpu->esp -= 0x10u;
    cpu->eax = cpu->esp;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x7Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478FC6u); lift_push32(cpu, r); sfera_sub_0046F280(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.active_input_handle;
    cpu->eax = g_sfera_scene_array_runtime.scene_points.data;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478FDAu); lift_push32(cpu, r); sfera_sub_0048D580(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x478FE1u); lift_push32(cpu, r); sfera_sub_0048DA20(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->ecx + 0x1B4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00078FEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x478FEFu);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_03) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00079092;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00079000: cpu->eip = LIFT_CODE_TOKEN_VA(0x479000u);
    if ((uint32_t)(lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_active[0]))) != (uint32_t)(1u)) goto label_00079085;
    cpu->esi = lift_load32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_light_runtime.render_candidate_indices[0]));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00079023;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79023u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079023: cpu->eip = LIFT_CODE_TOKEN_VA(0x479023u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_00079037;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79037u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079037: cpu->eip = LIFT_CODE_TOKEN_VA(0x479037u);
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_00079085;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.light_update_counter, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00079057;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79057u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079057: cpu->eip = LIFT_CODE_TOKEN_VA(0x479057u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_light_runtime.active_handles.capacity)) goto label_0007906B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7906Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007906B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47906Bu);
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, 0u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->esi) * 4u), 0u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79085u); lift_push32(cpu, r); sfera_sub_004D8C60(cpu,r); if (cpu->eip != r) return; }
    label_00079085: cpu->eip = LIFT_CODE_TOKEN_VA(0x479085u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_client_main_scalar_runtime.counter_03)) goto label_00079000;
    label_00079092: cpu->eip = LIFT_CODE_TOKEN_VA(0x479092u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4E4u;
    lift_return(cpu, 0u, stop_address); return;
    label_000790AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4790ABu);
    cpu->ecx = (uint32_t)(uintptr_t)"MNO_INDICES_IN_PRIMITIVE exceed";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4790B5u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4790B5u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004790C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4790C0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x4B4u;
    cpu->eax = 1u;
    g_sfera_grass_map_runtime.alternating_update_phase ^= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    g_sfera_recovered_static_runtime.input_state_b = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_world_objects.extended_object_count;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->esi)) goto label_000794CB;
    label_00079108: cpu->eip = LIFT_CODE_TOKEN_VA(0x479108u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00079116;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79116u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079116: cpu->eip = LIFT_CODE_TOKEN_VA(0x479116u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_0007912A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7912Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007912A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47912Au);
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_0007913C;
    ++cpu->esi;
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    goto label_00079108;
    label_0007913C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47913Cu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007914A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7914Au); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007914A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47914Au);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_0007915E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7915Eu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007915E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47915Eu);
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    cpu->ebx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_00079179;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79179u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079179: cpu->eip = LIFT_CODE_TOKEN_VA(0x479179u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007918D;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7918Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007918D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47918Du);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u));
    if ((uint32_t)(cpu->edi) == 0u) goto label_000791A7;
    if ((uint8_t)(lift_load8(cpu->edi + 0x138u)) == (uint8_t)(0u)) goto label_000794E2;
    label_000791A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4791A7u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x274u)) == (uint8_t)(0u)) goto label_000794B3;
    if ((uint8_t)(lift_load8(cpu->edi + 0x141u)) == (uint8_t)(0u)) goto label_000794B3;
    if ((uint32_t)(lift_load32(cpu->edi + 0x184u)) != (uint32_t)(0u)) goto label_000794B3;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 0x275u)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000791E5;
    if ((uint32_t)(g_sfera_grass_map_runtime.alternating_update_phase) == (uint32_t)(0u)) goto label_000794B3;
    label_000791E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4791E5u);
    cpu->eax = lift_load32(cpu->edi + 0x18Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007920D;
    if ((uint16_t)(lift_load16(cpu->eax + 0x9Au)) != (uint16_t)(0u)) goto label_0007920D;
    cpu->eax = g_sfera_recovered_static_runtime.simulation_tick;
    cpu->eax -= lift_load32(cpu->edi + 0x2F0u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x78u)) goto label_000794B3;
    label_0007920D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47920Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00079220;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00079222;
    label_00079220: cpu->eip = LIFT_CODE_TOKEN_VA(0x479220u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00079222: cpu->eip = LIFT_CODE_TOKEN_VA(0x479222u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x140u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x294u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000792AF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000792AD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x288u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x27Cu))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x280u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x290u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x284u))));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000792AD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000792AD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000794B3;
    goto label_000792AF;
    label_000792AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4792ADu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000792AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4792AFu);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.input_state_b, (uint64_t)(g_sfera_recovered_static_runtime.input_state_b) + 1u);
    cpu->ecx = 5u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4792BFu); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->edx = 4u;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4792CDu); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00079456;
    label_000792DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4792DFu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000792ED;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x792EDu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_000792ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4792EDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.clip_indices.capacity)) goto label_00079301;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79301u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079301: cpu->eip = LIFT_CODE_TOKEN_VA(0x479301u);
    cpu->ecx = g_sfera_scene_array_runtime.clip_indices.data;
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(1u)) goto label_00079445;
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x479316u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47931Cu);
    cpu->ebx = 1u;
    cpu->esp += 4u;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47932Bu); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00079354;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x479337u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47933Du);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x47933Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479344u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x479345u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47934Bu);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = (uint32_t)(cpu->ebx);
    label_00079354: cpu->eip = LIFT_CODE_TOKEN_VA(0x479354u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47935Bu); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00079384;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)" = ");
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x479367u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47936Du);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x47936Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479374u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x479375u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47937Bu);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = (uint32_t)(cpu->ebx);
    label_00079384: cpu->eip = LIFT_CODE_TOKEN_VA(0x479384u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479393u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 1u;
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47939Fu); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000793C8;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4793A7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4793ADu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x4793AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4793B4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4793B5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4793BBu);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = (uint32_t)(1u);
    label_000793C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4793C8u);
    cpu->eax = g_sfera_recovered_static_runtime.simulation_tick;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    cpu->edx = cpu->eax;
    cpu->edx -= lift_load32(cpu->edi + 0x2F0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_store_f64(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_store_f64(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)" = %f %f %f = %d = %d = %d\n"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4793FDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479403u);
    cpu->esp += 0x2Cu;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479410u); lift_push32(cpu, r); sfera_sub_0044BE30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0007943D;
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x47941Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479422u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x479423u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479429u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x47942Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479430u);
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[1].has_written = (uint32_t)(1u);
    label_0007943D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47943Du);
    cpu->esi = lift_load32(cpu->esp + 0x38u);
    cpu->ebx = lift_load32(cpu->esp + 0x34u);
    label_00079445: cpu->eip = LIFT_CODE_TOKEN_VA(0x479445u);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state))) goto label_000792DF;
    label_00079456: cpu->eip = LIFT_CODE_TOKEN_VA(0x479456u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x276u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007947F;
    cpu->edx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47947Du); lift_push32(cpu, r); sfera_sub_00473C20(cpu,r); if (cpu->eip != r) return; }
    goto label_000794A5;
    label_0007947F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47947Fu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x278u)) != (uint32_t)(0u)) goto label_0007948F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47948Du); lift_push32(cpu, r); sfera_sub_004748E0(cpu,r); if (cpu->eip != r) return; }
    goto label_000794A5;
    label_0007948F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47948Fu);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479496u); lift_push32(cpu, r); sfera_sub_00473C20(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x794A5u); lift_push32(cpu, r); sfera_sub_00474120(cpu,r); if (cpu->eip != r) return; }
    label_000794A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4794A5u);
    cpu->ecx = 5u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4794AFu); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    label_000794B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4794B3u);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    ++cpu->eax;
    ++cpu->esi;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x40u))) goto label_00079108;
    label_000794CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4794CBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000794E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4794E2u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4794F1u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000794FA;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_000794FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4794FAu);
    lift_push32(cpu, 0x33DAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xC4u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x479512u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479518u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xB8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479527u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x479527u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00479530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x479530u);
    cpu->esp -= 0x40Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000797B3;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00079562;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79562u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079562: cpu->eip = LIFT_CODE_TOKEN_VA(0x479562u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00079576;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79576u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079576: cpu->eip = LIFT_CODE_TOKEN_VA(0x479576u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_000797B3;
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) != (uint8_t)(0u)) goto label_000795CE;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47959Eu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000795A7;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_000795A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4795A7u);
    lift_push32(cpu, 0x35A8u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4795BCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4795C2u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x795CEu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000795CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4795CEu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x294u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x414u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00079604;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00079608;
    label_00079604: cpu->eip = LIFT_CODE_TOKEN_VA(0x479604u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00079608: cpu->eip = LIFT_CODE_TOKEN_VA(0x479608u);
    lift_x87_push(cpu, 333.0);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_02)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000796CC;
    if ((uint8_t)(g_sfera_graphics_runtime.render_mode_enabled) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000796CC;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 8u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)0.5f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007970D;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007970D;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 8u)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007970F;
    label_000796CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4796CCu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000796CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4796CEu);
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, 0u);
    cpu->edx = 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4796E0u); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x418u));
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x276u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007972C;
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47970Bu); lift_push32(cpu, r); sfera_sub_00475430(cpu,r); if (cpu->eip != r) return; }
    goto label_00079759;
    label_0007970D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47970Du);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007970F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47970Fu);
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_03) = (uint8_t)((cpu->ebx & 0xFFu));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000796CE;
    label_0007972C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47972Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x278u)) != (uint32_t)(0u)) goto label_0007973C;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47973Au); lift_push32(cpu, r); sfera_sub_00475DC0(cpu,r); if (cpu->eip != r) return; }
    goto label_00079759;
    label_0007973C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47973Cu);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479743u); lift_push32(cpu, r); sfera_sub_00475430(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x418u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79759u); lift_push32(cpu, r); sfera_sub_004755E0(cpu,r); if (cpu->eip != r) return; }
    label_00079759: cpu->eip = LIFT_CODE_TOKEN_VA(0x479759u);
    if ((uint8_t)(g_sfera_graphics_runtime.render_mode_enabled) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000797B2;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_02) = (uint8_t)((cpu->ebx & 0xFFu));
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
    label_000797B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4797B2u);
    cpu->ebx = lift_pop32(cpu);
    label_000797B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4797B3u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x40Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004797D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4797D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47980Cu); lift_push32(cpu, r); sfera_sub_00404900(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_model_registry_runtime.sentinel)) goto label_0007983F;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_00079826;
    cpu->eax = lift_load32(cpu->eax);
    label_00079826: cpu->eip = LIFT_CODE_TOKEN_VA(0x479826u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479835u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0007983F;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    goto label_0007984D;
    label_0007983F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47983Fu);
    cpu->ecx = g_sfera_model_registry_runtime.sentinel;
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    label_0007984D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47984Du);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_model_registry_runtime.sentinel)) goto label_000798C1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, 0u);
    lift_store8(cpu->esp + 0x20u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47987Au); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x30u, 1u);
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    lift_store32(cpu->esp + 0x48u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47989Bu); lift_push32(cpu, r); sfera_sub_00410950(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4798ABu); lift_push32(cpu, r); sfera_sub_0040C9F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(0x10u)) goto label_000798C4;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4798BCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000798C4;
    label_000798C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4798C1u);
    lift_store32(cpu->eax + 0x28u, (uint64_t)(lift_load32(cpu->eax + 0x28u)) + 1u);
    label_000798C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4798C4u);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004798E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4798E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    cpu->edi = 0x77A10u;
    cpu->ebp = (uint32_t)(cpu->ebx + 0xFu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00079920: cpu->eip = LIFT_CODE_TOKEN_VA(0x479920u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007992E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7992Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007992E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47992Eu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00079942;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79942u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079942: cpu->eip = LIFT_CODE_TOKEN_VA(0x479942u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00079995;
    lift_push32(cpu, 0xCu); lift_push32(cpu, (uintptr_t)"<empty slot>");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    lift_store8(cpu->esp + 0x38u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47996Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x58u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479977u); lift_push32(cpu, r); sfera_sub_004797D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x44u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x58u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00079A02;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479990u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_00079A02;
    label_00079995: cpu->eip = LIFT_CODE_TOKEN_VA(0x479995u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4799A4u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store8(cpu->esp + 0x14u, cpu->ebx & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    label_000799B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4799B5u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000799B5;
    cpu->ecx -= cpu->esi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4799C9u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x58u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4799DAu); lift_push32(cpu, r); sfera_sub_004797D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x58u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000799F6;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4799F3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000799F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4799F6u);
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store8(cpu->esp + 0x14u, cpu->ebx & 0xFFu);
    label_00079A02: cpu->eip = LIFT_CODE_TOKEN_VA(0x479A02u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x7A120u)) goto label_00079920;
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00479A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x479A30u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479A4Du); lift_push32(cpu, r); sfera_sub_0047F210(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00079AB8;
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->edi;
    label_00079A64: cpu->eip = LIFT_CODE_TOKEN_VA(0x479A64u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00079A64;
    cpu->ecx = 0xAu;
    cpu->esi = (uint32_t)(uintptr_t)"CreateObject: no model with such name: ";
    cpu->eax = cpu->ebp;
    lift_movs32(cpu, 1u);
    cpu->esi = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00079A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x479A80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00079A80;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    cpu->eax -= cpu->esi;
    --cpu->edi;
    (void)cpu;
    label_00079A90: cpu->eip = LIFT_CODE_TOKEN_VA(0x479A90u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00079A90;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479AABu); lift_push32(cpu, r); sfera_sub_0044F500(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
    label_00079AB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x479AB8u);
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = g_sfera_client_main_scalar_runtime.mode_02;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_model_registry_runtime;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479AD1u); lift_push32(cpu, r); sfera_sub_0040B940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    cpu->ebx = 0u;
    lift_store32(cpu->eax + 8u, cpu->eax);
    lift_store32((uintptr_t)&g_sfera_model_registry_runtime.size, cpu->ebx);
    label_00079AF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x479AF0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x7A120u)) goto label_00079B00;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479AFDu); lift_push32(cpu, r); sfera_sub_004798E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00079B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B00u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00079B0E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79B0Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B0Eu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00079B22;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79B22u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079B22: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B22u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(cpu->ebx)) goto label_00079B30;
    ++cpu->edi;
    goto label_00079AF0;
    label_00079B30: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479B35u); lift_push32(cpu, r); sfera_sub_0045CBB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) == (uint32_t)(cpu->ebx)) goto label_00079BA2;
    cpu->ebp = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00079B40: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B40u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00079B4E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79B4Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079B4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B4Eu);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_00079B62;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79B62u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079B62: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B62u);
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 4u))) == (uint32_t)(cpu->ebx)) goto label_00079B6F;
    ++cpu->ebp;
    goto label_00079B40;
    label_00079B6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B6Fu);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00079B7D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79B7Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079B7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B7Du);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_world_objects.extended_object_handles.capacity)) goto label_00079B91;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79B91u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079B91: cpu->eip = LIFT_CODE_TOKEN_VA(0x479B91u);
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebp) * 4u), cpu->edi);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_world_objects.extended_object_count, (uint64_t)(g_sfera_world_objects.extended_object_count) + 1u);
    goto label_00079BA5;
    label_00079BA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x479BA2u);
    cpu->ebp |= 0xFFFFFFFFu;
    label_00079BA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x479BA5u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) != (uint32_t)(cpu->ebx)) goto label_00079BF3;
    lift_push32(cpu, 0x23CCu);
    cpu->ecx = 0x13Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479BBFu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00079BCF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79BCFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079BCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x479BCFu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00079BE3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79BE3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079BE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x479BE3u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    lift_push32(cpu, 0x13Cu);
    goto label_00079C33;
    label_00079BF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x479BF3u);
    lift_push32(cpu, 0x23D1u);
    cpu->ecx = 0x2F4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479C02u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00079C12;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79C12u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_00079C12: cpu->eip = LIFT_CODE_TOKEN_VA(0x479C12u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_00079C26;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79C26u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_00079C26: cpu->eip = LIFT_CODE_TOKEN_VA(0x479C26u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    lift_push32(cpu, 0x2F4u);
    label_00079C33: cpu->eip = LIFT_CODE_TOKEN_VA(0x479C33u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x479C35u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479C3Au);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x3Cu)) & 0xFFu);
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + 0x138u, cpu->ecx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(g_sfera_world_objects.max_occupied_object_handle)) goto label_00079C55;
    g_sfera_world_objects.max_occupied_object_handle = (uint32_t)(cpu->edi);
    label_00079C55: cpu->eip = LIFT_CODE_TOKEN_VA(0x479C55u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->edi + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    g_sfera_client_main_scalar_runtime.mode_02 = (uint32_t)(cpu->edx);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)-1.0f);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esi + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x20u, cpu->ebx);
    lift_store8(cpu->esi + 0x139u, 1u);
    lift_store32(cpu->esi + 0x38u, cpu->ecx);
    lift_store32(cpu->esi + 0x24u, 0xF4240u);
    lift_store32(cpu->esi + 0xF4u, cpu->ebx);
    lift_store32(cpu->esi + 0xF8u, cpu->ebx);
    lift_store32(cpu->esi + 0xFCu, cpu->ebx);
    lift_store32(cpu->esi + 0x100u, cpu->ebx);
    lift_store32(cpu->esi + 0x104u, cpu->ebx);
    lift_store32(cpu->esi + 0x108u, cpu->ebx);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0x10Cu, cpu->eax);
    lift_store32(cpu->esi + 0x110u, cpu->eax);
    lift_store32(cpu->esi + 0x114u, cpu->eax);
    lift_store32(cpu->esi + 0x118u, cpu->eax);
    lift_store32(cpu->esi + 0x11Cu, cpu->eax);
    lift_store32(cpu->esi + 0x120u, cpu->eax);
    lift_store32(cpu->esi + 0x124u, cpu->eax);
    lift_store32(cpu->esi + 0x128u, cpu->eax);
    lift_store32(cpu->esi + 0x12Cu, cpu->eax);
    lift_store32(cpu->esi + 0x130u, cpu->eax);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x138u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esi + 0x134u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00079F7A;
    lift_store_f32(cpu->esi + 0x178u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x13Cu, cpu->ebp);
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 0x174u, cpu->ebx);
    lift_store_f32(cpu->esi + 0x148u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x170u, cpu->ebx);
    lift_store32(cpu->esi + 0x144u, cpu->ebx);
    lift_store16(cpu->esi + 0x141u, 1u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi + 0x27Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x280u, cpu->eax);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esi + 0x294u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x284u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x288u, cpu->edx);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esi + 0x2B0u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x28Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x290u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x2A4u, cpu->edx);
    lift_store32(cpu->esi + 0x2A8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x2ACu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store16(cpu->esi + 0x274u, cpu->ebx & 0xFFFFu);
    lift_store8(cpu->esi + 0x276u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esi + 0x140u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x278u, 1u);
    lift_store16(cpu->esi + 0x2A0u, cpu->ebx & 0xFFFFu);
    cpu->edx = g_sfera_recovered_static_runtime.simulation_tick;
    lift_store32(cpu->esi + 0x2F0u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x164u, cpu->eax);
    lift_store32(cpu->esi + 0x158u, cpu->eax);
    lift_store32(cpu->esi + 0x14Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x168u, cpu->ecx);
    lift_store32(cpu->esi + 0x15Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x150u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x16Cu, cpu->edx);
    lift_store32(cpu->esi + 0x160u, cpu->edx);
    lift_store32(cpu->esi + 0x154u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x190u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x194u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x198u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x19Cu, cpu->eax);
    lift_store32(cpu->esi + 0x1A0u, cpu->ecx);
    lift_store32(cpu->esi + 0x184u, cpu->ebx);
    lift_store32(cpu->esi + 0x188u, cpu->ebx);
    lift_store32(cpu->esi + 0x1A4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x228u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x22Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esi + 0x230u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esi + 0x2B4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esi + 0x18Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x2B8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x2C0u, cpu->ecx);
    lift_store32(cpu->esi + 0x2CCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esi + 0x2BCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->esi + 0x2C4u, cpu->edx);
    lift_store32(cpu->esi + 0x2D0u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esi + 0x2D8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esi + 0x2C8u, cpu->eax);
    lift_store32(cpu->esi + 0x2D4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x2DCu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->esi + 0x2E4u, cpu->ecx);
    lift_store32(cpu->esi + 0x2E0u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->esi + 0x2E8u, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esi + 0x2ECu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x479F78u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    goto label_00079F83;
    label_00079F7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x479F7Au);
    cpu->ecx = cpu->edi;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x79F83u); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    label_00079F83: cpu->eip = LIFT_CODE_TOKEN_VA(0x479F83u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_render_runtime.world_object_count, (uint64_t)(g_sfera_main_render_runtime.world_object_count) + 1u);
    lift_push32(cpu, (uintptr_t)"crt04"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x479F93u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x479F99u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00079FA7;
    lift_store32(cpu->esi + 0x38u, 5u);
    label_00079FA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x479FA7u);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00479FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x479FD0u);
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0007A00D;
    lift_push32(cpu, (uintptr_t)"Wrong handle: Link_object_to_object\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A005u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    goto label_0007A0E0;
    label_0007A00D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A00Du);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007A021;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7A021u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007A021: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A021u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007A032;
    cpu->ebp = 0u;
    goto label_0007A07C;
    label_0007A032: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A032u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_0007A07A;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A04Au); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007A053;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0007A053: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A053u);
    lift_push32(cpu, 0x373Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47A068u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47A06Eu);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7A07Au); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007A07A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A07Au);
    cpu->ebp = cpu->eax;
    label_0007A07C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A07Cu);
    if ((uint32_t)(lift_load32(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u) + 0xF8u)) == (uint32_t)(0u)) goto label_0007A08F;
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7A08Fu); lift_push32(cpu, r); sfera_sub_004593C0(cpu,r); if (cpu->eip != r) return; }
    label_0007A08F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A08Fu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A09Cu); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007A0AC;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7A0ACu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007A0AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A0ACu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007A0C0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7A0C0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007A0C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A0C0u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007A0FA;
    label_0007A0CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A0CCu);
    lift_store32(cpu->ebp + ((uint32_t)(cpu->ebx) * 4u) + 0xF8u, cpu->esi);
    lift_store32(cpu->eax + 0x184u, cpu->edi);
    lift_store32(cpu->eax + 0x188u, cpu->ebx);
    cpu->ebp = lift_pop32(cpu);
    label_0007A0E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A0E0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 4u, stop_address); return;
    label_0007A0FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A0FAu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_0007A0CC;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A112u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007A11B;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0007A11B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A11Bu);
    lift_push32(cpu, 0x3740u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47A130u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47A136u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A142u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x47A142u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047A150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A150u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xA0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xB0u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    cpu->esi = lift_load32(cpu->ebp + 8u);
    cpu->edi = 0u;
    { uint64_t l=(uint64_t)((g_sfera_grass_map_runtime.init_guard & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A1CD;
    g_sfera_grass_map_runtime.init_guard |= 1u;
    cpu->ecx = (uintptr_t)&g_sfera_grass_map_runtime.manager;
    lift_store32(cpu->esp + 0xB8u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A1C2u); lift_push32(cpu, r); sfera_sub_00430BB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xB8u, 0xFFFFFFFFu);
    label_0007A1CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A1CDu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x44u)))));
    cpu->ebx = native_function_address32(&::rand);
    lift_x87_push(cpu, 8.33329963684082);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_store32(cpu->esi, cpu->edi);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store8(cpu->esp + 0x27u, 0u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x18u))))));
    lift_store32(cpu->esp + 0x4Cu, cpu->edi);
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A20C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A20Cu);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_x87_push(cpu, (double)sfera_grass_jitter_x(cpu->eax >> 2u));
    cpu->edx = (uint32_t)(cpu->esp + 0x74u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x54u))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)sfera_grass_jitter_y(cpu->eax >> 2u));
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A250u); lift_push32(cpu, r); sfera_sub_0046D270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store32(cpu->esp + 0x30u, (uint64_t)(lift_load32(cpu->esp + 0x30u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esp + 0x74u);
    cpu->eax = lift_load32(cpu->esp + 0x5Cu);
    lift_store32(cpu->esp + 0x2Cu, (uint64_t)(lift_load32(cpu->esp + 0x2Cu)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uintptr_t)&g_sfera_grass_map_runtime.manager;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A284u); lift_push32(cpu, r); sfera_sub_00430920(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007A605;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A294u); lift_push32(cpu, r); sfera_sub_00457020(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007A29B;
    cpu->esi += 0xFu;
    label_0007A29B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A29Bu);
    cpu->ecx = 0u;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[1].id;
    label_0007A2A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A2A2u);
    if ((uint32_t)(lift_load32(cpu->eax + 0xFFFFFFC8u)) == (uint32_t)(cpu->esi)) goto label_0007A2EB;
    if ((uint32_t)(lift_load32(cpu->eax)) == (uint32_t)(cpu->esi)) goto label_0007A2D6;
    if ((uint32_t)(lift_load32(cpu->eax + 0x38u)) == (uint32_t)(cpu->esi)) goto label_0007A2D9;
    if ((uint32_t)(lift_load32(cpu->eax + 0x70u)) == (uint32_t)(cpu->esi)) goto label_0007A2DE;
    if ((uint32_t)(lift_load32(cpu->eax + 0xA8u)) == (uint32_t)(cpu->esi)) goto label_0007A2E3;
    if ((uint32_t)(lift_load32(cpu->eax + 0xE0u)) == (uint32_t)(cpu->esi)) goto label_0007A2E8;
    cpu->eax += 0x150u;
    cpu->ecx += 6u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[1].id + 0x690u))) goto label_0007A2A2;
    goto label_0007A2EB;
    label_0007A2D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A2D6u);
    ++cpu->ecx;
    goto label_0007A2EB;
    label_0007A2D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A2D9u);
    cpu->ecx += 2u;
    goto label_0007A2EB;
    label_0007A2DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A2DEu);
    cpu->ecx += 3u;
    goto label_0007A2EB;
    label_0007A2E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A2E3u);
    cpu->ecx += 4u;
    goto label_0007A2EB;
    label_0007A2E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A2E8u);
    cpu->ecx += 5u;
    label_0007A2EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A2EBu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x1Eu)) goto label_0007A876;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->esi -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->esi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[0].id));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x50u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A332u); lift_push32(cpu, r); sfera_sub_00470640(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_0007A431;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A33Cu), LIFT_CODE_TOKEN_RVA(0x7A33Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A33Cu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"grass") + 4u)) & 0xFFFFu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32((uintptr_t)"grass");
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0xFu), 32u);
    lift_store32(cpu->esp + 0x94u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 4u);
    lift_store16(cpu->esp + 0x98u, cpu->ecx & 0xFFFFu);
    cpu->esi = cpu->eax;
    label_0007A370: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A370u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007A370;
    cpu->edi = (uint32_t)(cpu->esp + 0x94u);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0007A381: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A381u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A381;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = g_sfera_model_runtime.repository;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x2F4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A3B4u); lift_push32(cpu, r); sfera_sub_0047F210(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->edx = lift_load32(cpu->esp + 0x7Cu);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    lift_store_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_x), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].model_handle), cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_store_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_z), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].state_01), cpu->ecx);
    lift_store_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_y), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].state_02), cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_store32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].state_03), cpu->eax);
    lift_store_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].vector_x), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_store_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].vector_y), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_store_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].vector_z), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].scale), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007A605;
    label_0007A431: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A431u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x2F4u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_x);
    cpu->edi = 8u;
    label_0007A446: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A446u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A448u), LIFT_CODE_TOKEN_RVA(0x7A446u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A448u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.25));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.33329963684082));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A472u), LIFT_CODE_TOKEN_RVA(0x7A470u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A472u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->esp -= 8u;
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.25));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.33329963684082));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A4B9u); lift_push32(cpu, r); sfera_sub_00470350(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007A5FE;
    lift_store8(cpu->esp + 0x27u, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A4C8u), LIFT_CODE_TOKEN_RVA(0x7A4C6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A4C8u);
    cpu->ecx = lift_load32((uintptr_t)"grass_s00");
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"grass_s00") + 4u);
    lift_store32(cpu->esp + 0x94u, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"grass_s00") + 8u)) & 0xFFFFu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0xFu), 32u);
    lift_store32(cpu->esp + 0x98u, cpu->edx);
    lift_store16(cpu->esp + 0x9Cu, cpu->ecx & 0xFFFFu);
    cpu->ecx = g_sfera_model_runtime.repository;
    cpu->edx = (uint32_t)(cpu->esp + 0x94u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0xA0u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A51Du); lift_push32(cpu, r); sfera_sub_0047F210(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->eax);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A536u), LIFT_CODE_TOKEN_RVA(0x7A534u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A536u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.6000000238418579));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esi + 0x144u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.1745329648256302));
    lift_x87_set(cpu, 0u, (0.3141593337059021) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A570u), LIFT_CODE_TOKEN_RVA(0x7A56Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A570u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_push(cpu, 6.283185958862305);
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x34u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f64(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A59Bu), LIFT_CODE_TOKEN_RVA(0x7A599u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A59Bu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_load_f64(cpu->esp + 0x34u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.0));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7A5B8u), LIFT_CODE_TOKEN_RVA(0x7A5B6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A5B8u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    cpu->esi += 0x2F4u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_load_f64(cpu->esp + 0x34u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.0));
    lift_store_f32(cpu->esi + 0xFFFFFD20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_store_f32(cpu->esi + 0xFFFFFE5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    lift_store_f32(cpu->esi + 0xFFFFFE60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_store_f32(cpu->esi + 0xFFFFFE64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A5FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A5FEu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A446;
    label_0007A605: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A605u);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->eax += 4u;
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x10u)) goto label_0007A20C;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 3u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A808;
    if ((uint8_t)(lift_load8(cpu->esp + 0x27u)) != (uint8_t)(0u)) goto label_0007A813;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47A662u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47A668u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0xFu), 32u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0007A813;
    cpu->esi = native_function_address32(&::rand);
    cpu->ebx = (uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[4].position_x;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_0007A692: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A692u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7A694u), LIFT_CODE_TOKEN_RVA(0x7A692u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A694u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.33329963684082));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7A6B2u), LIFT_CODE_TOKEN_RVA(0x7A6B0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A6B2u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    cpu->esp -= 8u;
    cpu->edx = (uint32_t)(cpu->esp + 0x58u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (8.33329963684082));
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A6EDu); lift_push32(cpu, r); sfera_sub_00470350(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007A7FE;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7A6F7u), LIFT_CODE_TOKEN_RVA(0x7A6F5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47A6F7u);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0xFu), 32u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->edx + 0x1Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0x1Du);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007A7FE;
    cpu->ecx = lift_load32((uintptr_t)"flower");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"flower") + 4u)) & 0xFFFFu);
    lift_store32(cpu->esp + 0x94u, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"flower") + 6u)) & 0xFFu);
    lift_store16(cpu->esp + 0x98u, cpu->edx & 0xFFFFu);
    lift_store8(cpu->esp + 0x9Au, cpu->ecx & 0xFFu);
    cpu->esi = cpu->eax;
    label_0007A747: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A747u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007A747;
    cpu->edi = (uint32_t)(cpu->esp + 0x94u);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_0007A758: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A758u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A758;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->edx = (uint32_t)(cpu->esp + 0x94u);
    lift_movs8(cpu, 1u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47A781u); lift_push32(cpu, r); sfera_sub_0047F210(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0xFFFFFFFCu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->ebx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store_f32(cpu->ebx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47A798u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47A79Eu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    cpu->esi = native_function_address32(&::rand);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    cpu->ebx += 0x2F4u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_store_f32(cpu->ebx + 0xFFFFFD18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ebx + 0xFFFFFD1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0xFFFFFD20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_store_f32(cpu->ebx + 0xFFFFFE5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    lift_store_f32(cpu->ebx + 0xFFFFFE60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_store_f32(cpu->ebx + 0xFFFFFE64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->ebx + 0xFFFFFE50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A7FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A7FEu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x18u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A692;
    label_0007A808: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A808u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) == (uint32_t)(0u)) goto label_0007AAFE;
    label_0007A813: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A813u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_y));
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = 1u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0007A99C;
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0007A949;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFBu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    ++cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[2].position_y;
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ecx) * 4u) + 1u);
    label_0007A855: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A855u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xFFFFFD0Cu));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A881;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007A898;
    label_0007A876: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A876u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"Grass pattern not found. Type=%d");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7A881u); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    label_0007A881: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A881u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A896;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0007A898;
    label_0007A896: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A896u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A898: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A898u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A8B5;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007A8CC;
    label_0007A8B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A8B5u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A8CA;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0007A8CC;
    label_0007A8CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A8CAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A8CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A8CCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x2F4u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A8ED;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007A904;
    label_0007A8ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A8EDu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A902;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0007A904;
    label_0007A902: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A902u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A904: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A904u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x5E8u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A925;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007A93C;
    label_0007A925: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A925u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A93A;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0007A93C;
    label_0007A93A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A93Au);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A93C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A93Cu);
    cpu->edx += 0xBD0u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A855;
    label_0007A949: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A949u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edi)) goto label_0007A99C;
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x2F4u);
    cpu->edx = cpu->edi;
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_y);
    cpu->edx -= cpu->esi;
    label_0007A95F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A95Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A97C;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007A993;
    label_0007A97C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A97Cu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007A991;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0007A993;
    label_0007A991: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A991u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007A993: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A993u);
    cpu->ecx += 0x2F4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A95F;
    label_0007A99C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A99Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (2.5));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_push(cpu, 4.16664981842041);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0007AA23;
    cpu->edi = lift_load32(cpu->esp + 0x58u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi += 8u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_grass_placement_runtime.slots[0].position_z;
    label_0007A9EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47A9EAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AA15u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    cpu->edi += 4u;
    cpu->esi += 0x2F4u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007A9EA;
    label_0007AA23: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AA23u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x14u))));
    cpu->edi = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->edi + 4u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_client_config_runtime.auto_grass_object);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AA50u); lift_push32(cpu, r); sfera_sub_00469090(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"grass1_21";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AA60u); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->edi, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007AA72;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7AA72u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007AA72: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AA72u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007AA86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7AA86u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007AA86: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AA86u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store8(cpu->eax + 0x139u, 0u);
    cpu->edx = lift_load8((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.color_remap_a[cpu->ecx]);
    cpu->ecx = lift_load8(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load8((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.color_remap_b[cpu->ecx]);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->ecx = lift_load8(cpu->esp + 0x28u);
    cpu->ecx = lift_load8((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.color_remap_c[cpu->ecx]);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx |= cpu->ecx;
    lift_store32(cpu->eax + 0x134u, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7AAFEu); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    label_0007AAFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AAFEu);
    cpu->ecx = lift_load32(cpu->esp + 0xB0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047AB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47AB30u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x418u);
    (void)0; /* source SEH registration eliminated */
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)) == (uint32_t)(1u)) goto label_0007AF8D;
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = g_sfera_graphics_runtime.display_height;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_graphics_runtime.display_width;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AB98u); lift_push32(cpu, r); sfera_sub_004BB800(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = native_function_address32(&::Sleep);
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7ABA2u), LIFT_CODE_TOKEN_RVA(0x7ABA0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ABA2u);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ABB2u); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    g_sfera_graphics_runtime.rebuild_percent = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ABBFu); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ABC6u); lift_push32(cpu, r); sfera_sub_0042AFB0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7ABCAu), LIFT_CODE_TOKEN_RVA(0x7ABC8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ABCAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ABCFu); lift_push32(cpu, r); sfera_sub_0042A630(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7ABD3u), LIFT_CODE_TOKEN_RVA(0x7ABD1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ABD3u);
    cpu->ecx = (uint32_t)(uintptr_t)"models\\materls.mtr";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ABDDu); lift_push32(cpu, r); sfera_sub_00462740(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7ABE1u), LIFT_CODE_TOKEN_RVA(0x7ABDFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ABE1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ABE6u); lift_push32(cpu, r); sfera_sub_0045B370(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7ABEAu), LIFT_CODE_TOKEN_RVA(0x7ABE8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ABEAu);
    cpu->edx = 0x42C7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ABF9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1030u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AC03u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007AC27;
    lift_push32(cpu, (uint32_t)(uintptr_t)"sky.txt");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AC25u); lift_push32(cpu, r); sfera_sub_00494A10(cpu,r); if (cpu->eip != r) return; }
    goto label_0007AC29;
    label_0007AC27: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AC27u);
    cpu->eax = 0u;
    label_0007AC29: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AC29u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x420u, cpu->edi);
    g_sfera_font_runtime.renderer = (uint32_t)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007AC89;
    cpu->edx = 0x42C9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AC4Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1030u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AC57u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007AC7B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"landscape_hr\\sky_hr.txt");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AC79u); lift_push32(cpu, r); sfera_sub_00494A10(cpu,r); if (cpu->eip != r) return; }
    goto label_0007AC7D;
    label_0007AC7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AC7Bu);
    cpu->eax = 0u;
    label_0007AC7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AC7Du);
    lift_store32(cpu->esp + 0x420u, cpu->edi);
    g_sfera_main_aux_runtime.secondary_world_manager = (uint32_t)(cpu->eax);
    label_0007AC89: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AC89u);
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7AC8Du), LIFT_CODE_TOKEN_RVA(0x7AC8Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47AC8Du);
    cpu->edx = 0x42CDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AC9Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ACA6u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007ACC5;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ACC3u); lift_push32(cpu, r); sfera_sub_0047EDD0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007ACC7;
    label_0007ACC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ACC5u);
    cpu->eax = 0u;
    label_0007ACC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ACC7u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"models\\");
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x424u, cpu->edi);
    g_sfera_model_runtime.repository = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ACDFu); lift_push32(cpu, r); sfera_sub_0047EEE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(0u)) goto label_0007ACF8;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, (uint32_t)(uintptr_t)"models_hr\\");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7ACF8u); lift_push32(cpu, r); sfera_sub_0047EEE0(cpu,r); if (cpu->eip != r) return; }
    label_0007ACF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ACF8u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21)) == (uint32_t)(0u)) goto label_0007AD11;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, (uint32_t)(uintptr_t)"models_ph\\");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7AD11u); lift_push32(cpu, r); sfera_sub_0047EEE0(cpu,r); if (cpu->eip != r) return; }
    label_0007AD11: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AD11u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22)) == (uint32_t)(0u)) goto label_0007AD2A;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, (uint32_t)(uintptr_t)"models_rd\\");
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7AD2Au); lift_push32(cpu, r); sfera_sub_0047EEE0(cpu,r); if (cpu->eip != r) return; }
    label_0007AD2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AD2Au);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AD35u); lift_push32(cpu, r); sfera_sub_0047F1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x42DCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_store32(cpu->esp + 0x10u, (uintptr_t)"xadd\\");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AD4Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7540u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AD56u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007AD7C;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AD7Au); lift_push32(cpu, r); sfera_sub_0041CDA0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007AD7E;
    label_0007AD7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AD7Cu);
    cpu->eax = 0u;
    label_0007AD7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AD7Eu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.minimum_lod_distance.f32));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_input_device_runtime.lod_distance.f32));
    lift_store32(cpu->esp + 0x428u, cpu->edi);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_recovered_static_runtime.render_state_08 = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ADA7u); lift_push32(cpu, r); sfera_sub_0041C1B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7ADABu), LIFT_CODE_TOKEN_RVA(0x7ADA9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ADABu);
    cpu->edx = 0x42E3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ADBAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC8D4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ADC4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007ADED;
    lift_push32(cpu, 0xBB7u); lift_push32(cpu, 0x7D0u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ADEBu); lift_push32(cpu, r); sfera_sub_0041F2B0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007ADEF;
    label_0007ADED: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ADEDu);
    cpu->eax = 0u;
    label_0007ADEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ADEFu);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x420u, cpu->edi);
    g_sfera_client_process_runtime.client_object = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AE02u); lift_push32(cpu, r); sfera_sub_0041F360(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7AE06u), LIFT_CODE_TOKEN_RVA(0x7AE04u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47AE06u);
    cpu->edx = 0x42F3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AE15u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7E80u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AE1Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 5u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007AE43;
    lift_push32(cpu, (uint32_t)(uintptr_t)"landscape\\weather.txt");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AE41u); lift_push32(cpu, r); sfera_sub_0049BAC0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007AE45;
    label_0007AE43: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AE43u);
    cpu->eax = 0u;
    label_0007AE45: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AE45u);
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x420u, cpu->edi);
    g_sfera_weather_runtime.standard_object = (uint32_t)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007AEA5;
    cpu->edx = 0x42F5u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AE69u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7E80u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AE73u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007AE97;
    lift_push32(cpu, (uint32_t)(uintptr_t)"landscape_hr\\weather_hr.txt");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AE95u); lift_push32(cpu, r); sfera_sub_0049BAC0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007AE99;
    label_0007AE97: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AE97u);
    cpu->eax = 0u;
    label_0007AE99: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AE99u);
    lift_store32(cpu->esp + 0x420u, cpu->edi);
    g_sfera_weather_runtime.highres_object = (uint32_t)(cpu->eax);
    if (g_sfera_weather_runtime.highres_object == 0u) g_sfera_weather_runtime.highres_object = g_sfera_weather_runtime.standard_object;
    label_0007AEA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AEA5u);
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7AEA9u), LIFT_CODE_TOKEN_RVA(0x7AEA7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47AEA9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AEAEu); lift_push32(cpu, r); sfera_sub_00461220(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"cam_cube";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AEBEu); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(0u)) goto label_0007AED3;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7AED3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007AED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AED3u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007AF34;
    label_0007AEDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AEDFu);
    lift_push32(cpu, 1u); lift_push32(cpu, 5u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"cam_cube";
    lift_store8(cpu->eax + 0x141u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AEF6u); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AEFBu); lift_push32(cpu, r); sfera_sub_00468BD0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x32u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7AEFFu), LIFT_CODE_TOKEN_RVA(0x7AEFDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47AEFFu);
    cpu->edx = 0x4304u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AF0Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AF15u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x420u, 7u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007AF7C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AF32u); lift_push32(cpu, r); sfera_sub_0047DB70(cpu,r); if (cpu->eip != r) return; }
    goto label_0007AF7E;
    label_0007AF34: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AF34u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_0007AEDF;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AF4Cu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007AF55;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0007AF55: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AF55u);
    lift_push32(cpu, 0x42FAu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47AF6Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47AF70u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7AF7Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007AF7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AF7Cu);
    cpu->eax = 0u;
    label_0007AF7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AF7Eu);
    g_sfera_input_device_runtime.shared_object = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19) = (uint32_t)(1u);
    label_0007AF8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47AF8Du);
    cpu->ecx = lift_load32(cpu->esp + 0x418u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x418u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047AFC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47AFC0u);
    cpu->esp -= 0x34u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store8(cpu->esp + 0x14u, cpu->edx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47AFF3u); lift_push32(cpu, r); sfera_sub_00470640(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0007B007;
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
    label_0007B007: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B007u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x4Cu)));
    lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007B17F;
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007B172;
    label_0007B023: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B023u);
    lift_push32(cpu, 1u); lift_push32(cpu, 4u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"treeput";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B033u); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007B043;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B043u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007B043: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B043u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007B057;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B057u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007B057: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B057u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, 0.0);
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store_f32(cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x18u, lift_x87_get(cpu, 0u));
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->edi + 0x139u, cpu->ebx & 0xFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B092u); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B0A2u); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    label_0007B0B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B0B0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    cpu->ebp = 0u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.03999999910593033));
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B0D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B0D0u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.125));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B0EFu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B10Bu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ecx = cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x4Cu))));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B125u); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B136u); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(2u)) goto label_0007B16B;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0007B144;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + 1u);
    label_0007B144: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B144u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(8u)) goto label_0007B0D0;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(8u)) goto label_0007B2C9;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x64u)) goto label_0007B0B0;
    label_0007B16B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B16Bu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B172u); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    label_0007B172: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B172u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
    label_0007B17F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B17Fu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B023;
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x10u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B19Eu); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007B1AE;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B1AEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007B1AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B1AEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007B1C2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B1C2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007B1C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B1C2u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store32(cpu->edi + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->edi + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->edi + 0x14u, cpu->eax);
    lift_store32(cpu->edi + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    lift_store32(cpu->edi + 0x18u, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->edi + 0x139u, cpu->ebx & 0xFFu);
    lift_store32(cpu->edi + 0x1Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B21Au); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B22Au); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007B230: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B230u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_push32(cpu, 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.10000000149011612));
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B24Du); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(2u)) goto label_0007B16B;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0007B274;
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x32u)) goto label_0007B230;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B267u); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
    label_0007B274: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B274u);
    cpu->ebp = 0u;
    label_0007B280: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B280u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_push32(cpu, 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.019999999552965164));
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B29Du); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(2u)) goto label_0007B16B;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_0007B3BE;
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x64u)) goto label_0007B280;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B2BCu); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
    label_0007B2C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B2C9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B2D7u); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x10u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B2EFu); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007B2FF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B2FFu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007B2FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B2FFu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007B313;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B313u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007B313: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B313u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    cpu->edi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_store32(cpu->edi + 8u, cpu->eax);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->edi + 0xCu, cpu->ecx);
    lift_store8(cpu->edi + 0x139u, cpu->ebx & 0xFFu);
    lift_store32(cpu->edi + 0x10u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47B34Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47B355u);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x48u)))));
    cpu->ecx = cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B37Du); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = (uint32_t)(1u);
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.clip_indices.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0007B39B;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.clip_indices.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B39Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007B39B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B39Bu);
    cpu->eax = g_sfera_scene_array_runtime.clip_indices.data;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->eax, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B3B0u); lift_push32(cpu, r); sfera_sub_00471E70(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_state) = (uint32_t)(cpu->ebx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0007B16B;
    label_0007B3BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B3BEu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047B3D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47B3D0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(g_sfera_window_runtime.input_state)) goto label_0007B8B6;
    if ((uint32_t)(g_sfera_world_render_runtime.render_queue_count) == (uint32_t)(0xDACu)) goto label_0007B8B6;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x468u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_planting_table_runtime.records[0].descriptor);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B414u); lift_push32(cpu, r); sfera_sub_0041FBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0007B8B6;
    label_0007B430: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B430u);
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B43Cu); lift_push32(cpu, r); sfera_sub_0041FBC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(0x3E7u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x38u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007B8A7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    cpu->esi = lift_load32(cpu->edi + 4u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = 1u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x118u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007B6D2;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0007B655;
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFBu);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    ++cpu->edx;
    cpu->ecx = (uint32_t)(cpu->edi + 0x11Cu);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edx) * 4u) + 1u);
    label_0007B49F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B49Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B4BC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B4BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B4BCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B4D9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B4D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B4D9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B4EE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B4EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B4EEu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B507;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_0007B507: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B507u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF04u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B524;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF04u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B524: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B524u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF04u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B541;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF04u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B541: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B541u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B558;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B558: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B558u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B573;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_0007B573: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B573u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF08u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B590;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF08u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B590: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B590u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF08u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B5AD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF08u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B5AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B5ADu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B5C4;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B5C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B5C4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B5DF;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_0007B5DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B5DFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF0Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B5FC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF0Cu));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B5FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B5FCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF0Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B619;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF0Cu));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B619: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B619u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B630;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B630: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B630u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B64B;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_0007B64B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B64Bu);
    cpu->ecx += 0x10u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007B49F;
    label_0007B655: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B655u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0007B6D2;
    cpu->esi -= cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->ebx) * 4u) + 0x118u);
    cpu->edx = cpu->esi;
    label_0007B664: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B664u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B681;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B681: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B681u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B69E;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFF00u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B69E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B69Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B6B3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B6B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B6B3u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B6CC;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_0007B6CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B6CCu);
    cpu->ecx += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007B664;
    label_0007B6D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B6D2u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ecx)))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f64(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B8A5;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_0007B6FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B6FDu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f64(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007B884;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B71C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B71Cu);
    cpu->esi = native_function_address32(&::rand);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7B726u), LIFT_CODE_TOKEN_RVA(0x7B724u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47B726u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x30u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7B742u), LIFT_CODE_TOKEN_RVA(0x7B740u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47B742u);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 8u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B77Au); lift_push32(cpu, r); sfera_sub_0041FBF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007B859;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->eax + 0x464u);
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0007B7B4;
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->eax += 0x34u;
    ++cpu->ecx;
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->ecx);
    label_0007B7A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B7A5u);
    cpu->esi += lift_load32(cpu->eax + 0xFFFFFFE4u);
    cpu->edi += lift_load32(cpu->eax);
    cpu->eax += 0x38u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007B7A5;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_0007B7B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B7B4u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0007B7C5;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ebx) * 8u));
    cpu->edx -= cpu->ebx;
    cpu->ebp = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x18u);
    label_0007B7C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B7C5u);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x47B7C5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47B7CBu);
    cpu->edi += cpu->esi;
    cpu->edi += cpu->ebp;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->edi + 0x464u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0x7FFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0xFu), 32u);
    cpu->esi = 0u;
    cpu->ecx = 0u;
    cpu->edx = (uint32_t)(cpu->edi + 0x18u);
    (void)cpu;
    label_0007B7F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B7F0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007B8BE;
    cpu->esi += lift_load32(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->eax)) goto label_0007B804;
    ++cpu->ecx;
    cpu->edx += 0x1Cu;
    goto label_0007B7F0;
    label_0007B804: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B804u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->eax -= cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 0x1Cu));
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B834u); lift_push32(cpu, r); sfera_sub_0047AFC0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0007B855;
    cpu->ecx = g_sfera_world_render_runtime.render_queue_count;
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_world_render_queue_runtime.entries[1]), cpu->eax);
    ++cpu->ecx;
    g_sfera_world_render_runtime.render_queue_count = (uint32_t)(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xDACu)) goto label_0007B8B6;
    label_0007B855: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B855u);
    cpu->edi = lift_load32(cpu->esp + 0x38u);
    label_0007B859: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B859u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_load_f64(cpu->esp + 0x40u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007B71C;
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x48u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0007B884: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B884u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007B6FD;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B8A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B8A5u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007B8A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B8A7u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x3Cu))) goto label_0007B430;
    label_0007B8B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B8B6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0007B8BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B8BEu);
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 743827592";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B8C8u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x47B8C8u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047B8D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47B8D0u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_28;
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    cpu->eax += cpu->ebp;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_28) = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(5u)) goto label_0007BD10;
    cpu->edx = g_sfera_main_render_runtime.grass_depth_mode;
    cpu->eax = g_sfera_input_device_runtime.input_generation;
    lift_push32(cpu, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_28) = (uint32_t)(0u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0007B910;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007B910;
    cpu->edi = cpu->ebp;
    goto label_0007B912;
    label_0007B910: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B910u);
    cpu->edi = 0u;
    label_0007B912: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B912u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0007B91E;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007B91E;
    cpu->eax = cpu->ebp;
    goto label_0007B920;
    label_0007B91E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B91Eu);
    cpu->eax = 0u;
    label_0007B920: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B920u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    g_sfera_input_device_runtime.input_generation = (uint32_t)(cpu->edx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007B96E;
    cpu->ecx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0007B96E;
    label_0007B938: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B938u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0007B962;
    cpu->edi = cpu->edi;
    label_0007B940: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B940u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ecx += cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x98u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B956u); lift_push32(cpu, r); sfera_sub_00459420(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->esi += cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0007B940;
    label_0007B962: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B962u);
    cpu->ebx += cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0007B938;
    cpu->edx = g_sfera_main_render_runtime.grass_depth_mode;
    label_0007B96E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B96Eu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0007BD0D;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0007B98A;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B98Au); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007B98A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B98Au);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B9A1u); lift_push32(cpu, r); sfera_sub_004246B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_0007B9B4;
    cpu->eax = 0xF4240u;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05) = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07) = (uint32_t)(cpu->eax);
    label_0007B9B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B9B4u);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0007B9C8;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7B9C8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007B9C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47B9C8u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.11999999731779099));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (100000.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47B9E5u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFE7960u);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebp)) goto label_0007BA03;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BA03u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007BA03: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BA03u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.11999999731779099));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (100000.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BA20u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFE7960u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05;
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_0007BA3F;
    if ((uint32_t)(cpu->edi) == (uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07))) goto label_0007BD0D;
    label_0007BA3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BA3Fu);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03;
    cpu->esi -= cpu->eax;
    cpu->eax = g_sfera_landscape_render_runtime.grid_buffer_bytes;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ebp = cpu->edi;
    cpu->ebp -= (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47BA5Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47BA62u);
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->edx = cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->esp += 0xCu;
    cpu->ecx = 0u;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0007BAA3;
    label_0007BA80: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BA80u);
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 8u), cpu->ecx);
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->ecx);
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->edx = cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebx);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0007BA80;
    label_0007BAA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BAA3u);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(1u)) goto label_0007BC4F;
    cpu->eax = cpu->ebp;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = cpu->eax;
    cpu->edi ^= cpu->edx;
    cpu->edi -= cpu->edx;
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(1u)) goto label_0007BC4B;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0007BB05;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ecx)) goto label_0007BAF5;
    cpu->eax = 1u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0007BAEB;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 763927845";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BAEBu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007BAEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BAEBu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_0007BB19;
    label_0007BAF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BAF5u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x14u, 1u);
    goto label_0007BB19;
    label_0007BB05: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BB05u);
    cpu->ecx = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFEu);
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    cpu->ecx = 0u;
    label_0007BB19: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BB19u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_0007BB4C;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ecx)) goto label_0007BB3E;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(1u)) goto label_0007BB31;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 764554745";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BB31u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007BB31: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BB31u);
    cpu->ebp = 1u;
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    goto label_0007BB5A;
    label_0007BB3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BB3Eu);
    cpu->ebp = 0u;
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x18u, 1u);
    goto label_0007BB5A;
    label_0007BB4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BB4Cu);
    cpu->ebp = (uint32_t)(cpu->ebx + 0xFFFFFFFEu);
    cpu->edx = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    label_0007BB5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BB5Au);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    cpu->ecx -= cpu->edi;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0007BC4B;
    cpu->ecx = cpu->ebx;
    cpu->ecx -= lift_load32(cpu->esp + 0x28u);
    cpu->edx -= cpu->ebp;
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0007BB80: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BB80u);
    lift_store32(cpu->esp + 0x24u, 0u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0007BC35;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0007BBA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BBA0u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base;
    cpu->edx += cpu->ebp;
    cpu->edi = cpu->edx;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ebx);
    cpu->esi = cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebx += cpu->eax;
    cpu->esi += cpu->eax;
    cpu->edi += cpu->ebx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x98u);
    cpu->esi += cpu->ecx;
    cpu->edi += cpu->ecx;
    cpu->ecx = 0x26u;
    lift_movs32(cpu, 1u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(g_sfera_landscape_interpolation_runtime.subdivision_count);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ecx;
    cpu->ecx = g_sfera_window_runtime.landscape_grid_records;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edx) * 8u) + 4u, 1u);
    cpu->edx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->ecx = g_sfera_window_runtime.landscape_grid_records;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->edx += cpu->eax;
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edx) * 8u), 1u);
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = cpu->ebx;
    cpu->ecx -= lift_load32(cpu->esp + 0x28u);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0007BBA0;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->edi = lift_load32(cpu->esp + 0x3Cu);
    label_0007BC35: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC35u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + 1u);
    cpu->ebp += lift_load32(cpu->esp + 0x18u);
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->edi;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (int32_t)(uint32_t)(cpu->edx)) goto label_0007BB80;
    label_0007BC4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC4Bu);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    label_0007BC4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC4Fu);
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0007BC94;
    label_0007BC55: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC55u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0007BC8F;
    label_0007BC60: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC60u);
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx += cpu->esi;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u))) != (uint32_t)(0u)) goto label_0007BC8A;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x98u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_03);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BC84u); lift_push32(cpu, r); sfera_sub_00459420(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    label_0007BC8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC8Au);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0007BC60;
    label_0007BC8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC8Fu);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0007BC55;
    label_0007BC94: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BC94u);
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0007BCFD;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0007BCA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BCA0u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0007BCF8;
    label_0007BCB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BCB0u);
    cpu->edx = g_sfera_window_runtime.landscape_grid_records;
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx += cpu->esi;
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 4u)) != (uint32_t)(0u)) goto label_0007BCF3;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x98u);
    cpu->ecx += (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.landscape_texture_base);
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->ecx += cpu->eax;
    cpu->edx += cpu->ebp;
    cpu->ecx += cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BCEDu); lift_push32(cpu, r); sfera_sub_0047A150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = g_sfera_landscape_interpolation_runtime.subdivision_count;
    label_0007BCF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BCF3u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0007BCB0;
    label_0007BCF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BCF8u);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0007BCA0;
    label_0007BCFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BCFDu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_05) = (uint32_t)(cpu->edx);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_07) = (uint32_t)(cpu->edi);
    label_0007BD0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BD0Du);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    label_0007BD10: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BD10u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047BD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47BD30u);
    cpu->esp -= 0x4A8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esp + 0x14u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_14)) != (uint32_t)(cpu->esi)) goto label_0007C608;
    cpu->edi = g_sfera_shadow_runtime.manager;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_0007BDF1;
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) != (uint8_t)(0u)) goto label_0007BDF1;
    lift_x87_push(cpu, 0.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_scale, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_x87_push(cpu, 0.4000000059604645);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007BDB2;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (1.399999976158142));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_scale, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007BDB6;
    label_0007BDB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BDB2u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007BDB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BDB6u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_scale));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_scale, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_scale));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BDEAu); lift_push32(cpu, r); sfera_sub_0048C860(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BDF1u); lift_push32(cpu, r); sfera_sub_0048D9D0(cpu,r); if (cpu->eip != r) return; }
    label_0007BDF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BDF1u);
    cpu->edi = g_sfera_world_objects.controlled_object_handle;
    cpu->eax = g_sfera_main_render_runtime.grass_depth_mode;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0007BE4A;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0007BE13;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BE13u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007BE13: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE13u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007BE27;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BE27u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007BE27: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE27u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_0007BE93;
    cpu->eax = 0u;
    label_0007BE36: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE36u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1000.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007BEE1;
    label_0007BE4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE4Au);
    g_sfera_main_render_runtime.grass_depth_mode = (uint32_t)(cpu->esi);
    label_0007BE50: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE50u);
    cpu->edi = 1u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_0007BE5F;
    label_0007BE5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE5Au);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BE5Fu); lift_push32(cpu, r); sfera_sub_0047B8D0(cpu,r); if (cpu->eip != r) return; }
    label_0007BE5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE5Fu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13)) == (uint32_t)(cpu->esi)) goto label_0007BF23;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0007BE7F;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BE7Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007BE7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE7Fu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)80.0f);
    cpu->eax = lift_load32(cpu->edx + 4u);
    goto label_0007BF46;
    label_0007BE93: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BE93u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(0u)) goto label_0007BE36;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BEABu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_0007BEB4;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0007BEB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BEB4u);
    lift_push32(cpu, 0x2873u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xC0u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47BECCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47BED2u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xB4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BEE1u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007BEE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BEE1u);
    if ((uint32_t)(g_sfera_main_render_runtime.grass_depth_mode) != (uint32_t)(2u)) goto label_0007BE50;
    cpu->edi = 1u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_0007BE5F;
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BF07u); lift_push32(cpu, r); sfera_sub_00424A40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.grass_depth_mode), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BF1Eu); lift_push32(cpu, r); sfera_sub_00424AC0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007BE5A;
    label_0007BF23: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BF23u);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0007BF37;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BF37u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007BF37: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BF37u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_y));
    cpu->eax = lift_load32(cpu->ecx + 4u);
    label_0007BF46: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BF46u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esp -= 0x10u;
    cpu->ecx = cpu->esp;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47BF65u); lift_push32(cpu, r); sfera_sub_0046DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_landscape_patch_lookup_runtime.active_count;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state) = (uint32_t)(cpu->ecx);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0007BF85;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BF85u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007BF85: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BF85u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state;
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0007C17C;
    cpu->ebp = 0u;
    label_0007BFB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BFB2u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007BFC0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BFC0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007BFC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BFC0u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_character_index_map.capacity)) goto label_0007BFD4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BFD4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007BFD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BFD4u);
    cpu->ecx = g_sfera_character_index_map.data;
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007BFEB;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BFEBu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007BFEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BFEBu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_0007BFFF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7BFFFu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007BFFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47BFFFu);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    lift_store32(cpu->eax + cpu->ebp, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007C017;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C017u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C017: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C017u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_character_index_map.capacity)) goto label_0007C02B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C02Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C02B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C02Bu);
    cpu->ecx = g_sfera_character_index_map.data;
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0007C042;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C042u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C042: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C042u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007C056;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C056u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C056: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C056u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x4Cu))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C0A9u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007C0C3;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C0C3u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C0C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C0C3u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_0007C0D7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C0D7u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C0D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C0D7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    lift_store_f32(cpu->eax + cpu->ebp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007C0F2;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C0F2u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C0F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C0F2u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_character_index_map.capacity)) goto label_0007C106;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_character_index_map.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C106u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C106: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C106u);
    cpu->ecx = g_sfera_character_index_map.data;
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0007C11D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C11Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C11D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C11Du);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007C131;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C131u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C131: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C131u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007C148;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C148u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C148: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C148u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_0007C15C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C15Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C15C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C15Cu);
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    lift_store32(cpu->edx + cpu->ebp + 4u, cpu->ecx);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state;
    ++cpu->esi;
    cpu->ebp += 0xCu;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0007BFB2;
    label_0007C17C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C17Cu);
    cpu->esi = 1u;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0007C18F;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C18Fu); lift_push32(cpu, r); sfera_sub_00456880(cpu,r); if (cpu->eip != r) return; }
    label_0007C18F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C18Fu);
    cpu->edi = 2u;
    if ((uint32_t)(g_sfera_main_render_runtime.grass_depth_mode) != (uint32_t)(cpu->edi)) goto label_0007C1CE;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_0007C1CE;
    if ((int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity) > (int32_t)(uint32_t)(0u)) goto label_0007C1B6;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C1B6u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C1B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C1B6u);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state;
    cpu->ecx = g_sfera_scene_array_runtime.object_positions.data;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C1CEu); lift_push32(cpu, r); sfera_sub_004249C0(cpu,r); if (cpu->eip != r) return; }
    label_0007C1CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C1CEu);
    { uint64_t l=(uint64_t)(g_sfera_main_render_runtime.secondary_render_pass), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator) = (uint32_t)(0x7530u);
    g_sfera_window_runtime.render_state_word = (uint32_t)(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007C1F3;
    if ((int32_t)(uint32_t)(g_sfera_options_dialog_runtime.reflection_quality) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0007C2DA;
    label_0007C1F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C1F3u);
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0007C2DA;
    cpu->ebx = 0u;
    label_0007C203: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C203u);
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0007C211;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C211u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C211: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C211u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_0007C225;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C225u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C225: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C225u);
    cpu->edx = g_sfera_scene_array_runtime.object_positions.data;
    cpu->esi = lift_load32(cpu->ebx + cpu->edx);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007C23C;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C23Cu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C23C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C23Cu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007C250;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C250u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C250: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C250u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->edi = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->esi) == (uint32_t)(1u)) goto label_0007C2C1;
    if ((uint8_t)(lift_load8(cpu->edi + 0x138u)) != (uint8_t)(1u)) goto label_0007C26F;
    if ((uint8_t)(lift_load8(cpu->edi + 0x141u)) == (uint8_t)(0u)) goto label_0007C2C1;
    label_0007C26F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C26Fu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C27Eu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->eax + 0x50u)) != (uint8_t)(0u)) goto label_0007C2C1;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C293u); lift_push32(cpu, r); sfera_sub_0047F230(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007C2BC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C2A5u); lift_push32(cpu, r); sfera_sub_00456760(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) != (uint8_t)(1u)) goto label_0007C2B3;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C2B3u); lift_push32(cpu, r); sfera_sub_00477020(cpu,r); if (cpu->eip != r) return; }
    label_0007C2B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C2B3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007C2C1;
    label_0007C2BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C2BCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C2C1u); lift_push32(cpu, r); sfera_sub_00477020(cpu,r); if (cpu->eip != r) return; }
    label_0007C2C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C2C1u);
    ++cpu->ebp;
    cpu->ebx += 0xCu;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state))) goto label_0007C203;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x14u)) & 0xFFu);
    cpu->edi = 2u;
    label_0007C2DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C2DAu);
    if ((uint32_t)(g_sfera_main_render_runtime.grass_depth_mode) != (uint32_t)(cpu->edi)) goto label_0007C2F2;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_0007C2F2;
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C2F2u); lift_push32(cpu, r); sfera_sub_004255D0(cpu,r); if (cpu->eip != r) return; }
    label_0007C2F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C2F2u);
    if ((uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == (uint32_t)(0u)) goto label_0007C307;
    if ((int32_t)(uint32_t)(g_sfera_options_dialog_runtime.reflection_quality) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0007C5FE;
    label_0007C307: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C307u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0007C5FE;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0007C320: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C320u);
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0007C32E;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C32Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C32E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C32Eu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.object_positions.capacity)) goto label_0007C342;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.object_positions.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C342u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C342: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C342u);
    cpu->eax = g_sfera_scene_array_runtime.object_positions.data;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_load32(cpu->ecx + cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(1u)) goto label_0007C5E8;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007C369;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C369u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007C369: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C369u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007C37D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C37Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007C37D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C37Du);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) == (uint8_t)(0u)) goto label_0007C5E8;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C3A2u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x50u)) & 0xFFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007C5E8;
    if ((uint8_t)(lift_load8(cpu->esi + 0x138u)) == (uint8_t)(0u)) goto label_0007C621;
    if ((uint8_t)(lift_load8(cpu->esi + 0x141u)) == (uint8_t)(0u)) goto label_0007C5E8;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x144u)) < (int32_t)(uint32_t)(0u)) goto label_0007C54F;
    cpu->edx = lift_load32(cpu->esi + 0x170u);
    cpu->ebp = lift_load32(cpu->esi + 0x174u);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->edi)) goto label_0007C3FB;
    cpu->ecx = cpu->eax & 0xFFu;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0007C417;
    label_0007C3FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C3FBu);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, (uintptr_t)"DrawObjects: wrong animation. Name=%s\n"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47C406u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47C40Cu);
    cpu->esp += 0xCu;
    cpu->edx = 0u;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    label_0007C417: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C417u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0007C451;
    cpu->eax = lift_load32(cpu->ebx + 0x5Cu);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    ++cpu->ecx;
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    label_0007C432: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C432u);
    cpu->ebx = lift_load16(cpu->eax);
    cpu->edi += cpu->ebx;
    cpu->ebx = lift_load16(cpu->eax + 2u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007C432;
    cpu->ebx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_0007C451: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C451u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0007C45E;
    cpu->ecx = lift_load32(cpu->ebx + 0x5Cu);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    goto label_0007C462;
    label_0007C45E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C45Eu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    label_0007C462: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C462u);
    cpu->edi += lift_load32(cpu->esp + 0x24u);
    cpu->ecx = 0u;
    cpu->eax += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0007C479;
    cpu->edi = lift_load32(cpu->ebx + 0x5Cu);
    cpu->edx = lift_load16(cpu->edi + ((uint32_t)(cpu->edx) * 2u));
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->edx)) goto label_0007C47B;
    label_0007C479: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C479u);
    cpu->ebp = 0u;
    label_0007C47B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C47Bu);
    lift_x87_push(cpu, (double)0.009999999776482582f);
    cpu->eax += cpu->ebp;
    g_sfera_client_main_scalar_runtime.state_06 = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = (uint32_t)(cpu->ecx);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x178u)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007C54F;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = (uint32_t)(1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x178u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x180u);
    cpu->eax = lift_load32(cpu->esi + 0x17Cu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0007C4D5;
    cpu->edi = lift_load8(cpu->ebx + 0x50u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->edi)) goto label_0007C4DD;
    label_0007C4D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C4D5u);
    cpu->edx = 0u;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_0007C4DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C4DDu);
    cpu->edi = 0u;
    cpu->ebp = 0u;
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0007C51D;
    cpu->eax = lift_load32(cpu->ebx + 0x5Cu);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    ++cpu->ecx;
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    label_0007C500: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C500u);
    cpu->ebx = lift_load16(cpu->eax);
    cpu->edi += cpu->ebx;
    cpu->ebx = lift_load16(cpu->eax + 2u);
    cpu->ebp += cpu->ebx;
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007C500;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ebx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0007C51D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C51Du);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0007C52E;
    cpu->eax = lift_load32(cpu->ebx + 0x5Cu);
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    goto label_0007C532;
    label_0007C52E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C52Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    label_0007C532: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C532u);
    cpu->edi += cpu->ebp;
    cpu->ecx += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0007C545;
    cpu->edi = lift_load32(cpu->ebx + 0x5Cu);
    cpu->edx = lift_load16(cpu->edi + ((uint32_t)(cpu->edx) * 2u));
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0007C547;
    label_0007C545: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C545u);
    cpu->eax = 0u;
    label_0007C547: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C547u);
    cpu->ecx += cpu->eax;
    g_sfera_render_sample_runtime.material_base = (uint32_t)(cpu->ecx);
    label_0007C54F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C54Fu);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->ebx + 0x1C0u)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007C59A;
    if ((uint32_t)(g_sfera_main_render_runtime.grass_depth_mode) != (uint32_t)(2u)) goto label_0007C59A;
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) != (uint8_t)(1u)) goto label_0007C59A;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1C0u));
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C598u); lift_push32(cpu, r); sfera_sub_004246E0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007C59E;
    label_0007C59A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C59Au);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0007C59E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C59Eu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x144u)) < (int32_t)(uint32_t)(0u)) goto label_0007C5B0;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C5AEu); lift_push32(cpu, r); sfera_sub_00477FB0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007C5E4;
    label_0007C5B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C5B0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    cpu->ecx = lift_load32(cpu->ebx + 0x1E0u);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C5CBu); lift_push32(cpu, r); sfera_sub_0044ECA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C5E4u); lift_push32(cpu, r); sfera_sub_0041D3C0(cpu,r); if (cpu->eip != r) return; }
    label_0007C5E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C5E4u);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    label_0007C5E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C5E8u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    ++cpu->edi;
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.draw_selection_state))) goto label_0007C320;
    label_0007C5FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C5FEu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    g_sfera_main_render_runtime.grass_depth_mode = (uint32_t)(cpu->ecx);
    label_0007C608: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C608u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4A8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007C621: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C621u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C630u); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007C639;
    cpu->eax = (uint32_t)(uintptr_t)"<none>";
    label_0007C639: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C639u);
    lift_push32(cpu, 0x28CBu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xC0u);
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x47C651u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47C657u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xB4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C666u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x47C666u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047C670(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0007C670;
    label_00076B40: cpu->eip = LIFT_CODE_TOKEN_VA(0x476B40u);
    cpu->esp -= 0x38u;
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_00076DBD;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476B66u); lift_push32(cpu, r); sfera_sub_004766E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_00076DBD;
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.camera_step));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, 0.20000000298023224);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00076BA0;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.camera_step, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.camera_step));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00076BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x476BA0u);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00076DCC;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.camera_step, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.camera_step));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    label_00076BD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x476BD1u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.cursor_accumulator));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 4u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00076BFC;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.cursor_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.cursor_accumulator));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    label_00076BFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x476BFCu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 3u)));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 5u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00076DD3;
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.cursor_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.cursor_accumulator));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    label_00076C2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x476C2Du);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ebp);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00076C63;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476C5Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.20000000298023224);
    label_00076C63: cpu->eip = LIFT_CODE_TOKEN_VA(0x476C63u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_scene_array_runtime.reflection_targets.capacity)) goto label_00076C7F;
    cpu->edx = cpu->esi;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476C79u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.20000000298023224);
    label_00076C7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x476C7Fu);
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->edx = 0x5F317777u;
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3030)) & 0xFFFFu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store16(cpu->esp + 0x40u, cpu->eax & 0xFFFFu);
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store8(cpu->esp + 0x42u, cpu->ecx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esp + 0x3Eu, cpu->edx & 0xFFu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xAu;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_view_spatial_runtime.basis[3].x.f32)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.basis[2].x.f32)));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x40u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x41u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476D35u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_view_spatial_runtime.basis[3].y.f32)));
    cpu->esi = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.basis[2].y.f32)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476D4Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)g_sfera_view_spatial_runtime.basis[3].z.f32)));
    cpu->ebp = cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_view_spatial_runtime.basis[2].z.f32)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476D5Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(0xFFu)) goto label_00076D6C;
    cpu->esi = 0xFFu;
    label_00076D6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x476D6Cu);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(0xFFu)) goto label_00076D79;
    cpu->ebp = 0xFFu;
    label_00076D79: cpu->eip = LIFT_CODE_TOKEN_VA(0x476D79u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(0xFFu)) goto label_00076D86;
    cpu->ebx = 0xFFu;
    label_00076D86: cpu->eip = LIFT_CODE_TOKEN_VA(0x476D86u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476D99u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x476DB9u); lift_push32(cpu, r); sfera_sub_0044FF80(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00076DBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x476DBDu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
    label_00076DCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x476DCCu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00076BD1;
    label_00076DD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x476DD3u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00076C2D;
    label_0007C670: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C670u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(1u)) goto label_0007C686;
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    if ((uint32_t)(cpu->esi) != (uint32_t)(2u)) goto label_0007C68B;
    label_0007C686: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C686u);
    cpu->ecx = 0x100u;
    label_0007C68B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C68Bu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(1u)) goto label_0007C69A;
    cpu->eax = g_sfera_graphics_runtime.display_height;
    if ((uint32_t)(cpu->esi) != (uint32_t)(2u)) goto label_0007C69F;
    label_0007C69A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C69Au);
    cpu->eax = 0x100u;
    label_0007C69F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C69Fu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C6ACu); lift_push32(cpu, r); sfera_sub_0046BD40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C6CAu); lift_push32(cpu, r); sfera_sub_004D87E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if ((uint32_t)(cpu->esi) == (uint32_t)(2u)) goto label_0007C6EB;
    cpu->eax = g_sfera_view_spatial_runtime.basis[0].y.u32;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C6E2u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_view_spatial_runtime.basis[0].z.u32;
    lift_push32(cpu, cpu->ecx);
    goto label_0007C70D;
    label_0007C6EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C6EBu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C707u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_view_spatial_runtime.scale.y.u32;
    lift_push32(cpu, cpu->eax);
    label_0007C70D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C70Du);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x25u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C71Au); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C71Fu); lift_push32(cpu, r); sfera_sub_00450A00(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != 0u) goto label_0007C72D;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C728u); lift_push32(cpu, r); sfera_sub_0044E1B0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C72Du); lift_push32(cpu, r); sfera_sub_0044E230(cpu,r); if (cpu->eip != r) return; }
    label_0007C72D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C72Du);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C73Cu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) != (uint8_t)(0u)) goto label_0007C74E;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)) == (uint32_t)(1u)) goto label_0007C753;
    label_0007C74E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C74Eu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_0007C789;
    label_0007C753: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C753u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C758u); lift_push32(cpu, r); sfera_sub_00457E80(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C769u); lift_push32(cpu, r); sfera_sub_0045C230(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C76Eu); lift_push32(cpu, r); sfera_sub_00457020(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0007C77D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_view_render_objects_runtime.primary.storage[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C77Du); lift_push32(cpu, r); sfera_sub_00454DC0(cpu,r); if (cpu->eip != r) return; }
    label_0007C77D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C77Du);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_view_render_objects_runtime.alternate.storage[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C787u); lift_push32(cpu, r); sfera_sub_00454DC0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007C7B2;
    label_0007C789: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C789u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0xFFu); lift_push32(cpu, (uintptr_t)"black"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7C7B2u); lift_push32(cpu, r); sfera_sub_0044FCD0(cpu,r); if (cpu->eip != r) return; }
    label_0007C7B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C7B2u);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C7D0u); lift_push32(cpu, r); sfera_sub_004D87E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C7DFu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C7E4u); lift_push32(cpu, r); sfera_sub_00470DA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].x));
    lift_store16(cpu->esp + 4u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 4u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 8u));
    lift_store64(cpu->esp + 8u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].y));
    lift_store16(cpu->esp + 4u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 4u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 8u));
    lift_store64(cpu->esp + 8u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->edx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[1].z));
    lift_store16(cpu->esp + 4u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 4u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 8u));
    lift_store64(cpu->esp + 8u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->eax &= 0xFFu;
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 8u));
    lift_push32(cpu, 0x22u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C885u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_0007C895;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_0047BD30(cpu, stop_address); return;
    label_0007C895: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C895u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C89Cu); lift_push32(cpu, r); sfera_sub_0047BD30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != 0u) goto label_0007C96D;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C8A9u); lift_push32(cpu, r); sfera_sub_00450A00(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x));
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].x.u32;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->edx = g_sfera_view_spatial_runtime.basis[3].y.u32;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax, cpu->ecx);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_view_spatial_runtime.basis[3].z.u32;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.position_offset.z));
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C90Au); lift_push32(cpu, r); sfera_sub_004681A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C90Fu); lift_push32(cpu, r); sfera_sub_0046A070(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C914u); lift_push32(cpu, r); sfera_sub_0041A0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C91Bu); lift_push32(cpu, r); sfera_sub_0041A560(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C929u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_server_wall;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C933u); lift_push32(cpu, r); sfera_sub_0048A740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C938u); lift_push32(cpu, r); sfera_sub_00450260(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_flare_projection.y.f32));
    cpu->eax = g_sfera_recovered_static_runtime.scene_state_09;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xDCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C94Eu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_flare_projection.x.f32));
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C95Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C964u); lift_push32(cpu, r); sfera_sub_0042ADA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    goto label_00076B40;
    label_0007C96D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47C96Du);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047C980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47C980u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, cpu->edi);
    cpu->edi = 1u;
    { uint64_t l=(uint64_t)(g_sfera_world_render_runtime.feature_toggle), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, (uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x); lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C9A9u); lift_push32(cpu, r); sfera_sub_00457510(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32(cpu->esp + 4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C9BCu); lift_push32(cpu, r); sfera_sub_004DA310(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007CB92;
    lift_push32(cpu, cpu->esi);
    g_sfera_world_render_runtime.scene_active = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C9D0u); lift_push32(cpu, r); sfera_sub_004C3A20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47C9D7u); lift_push32(cpu, r); sfera_sub_004C3AB0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x98u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7C9F3u), LIFT_CODE_TOKEN_RVA(0x7C9F1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47C9F3u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0xA0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CA0Cu), LIFT_CODE_TOKEN_RVA(0x7CA0Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CA0Cu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CA1Bu), LIFT_CODE_TOKEN_RVA(0x7CA19u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CA1Bu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007CB31;
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x94u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7CA3Du), LIFT_CODE_TOKEN_RVA(0x7CA3Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CA3Du);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CA4Du); lift_push32(cpu, r); sfera_sub_00464600(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CA55u); lift_push32(cpu, r); sfera_sub_0047C670(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27)) == (uint32_t)(0u)) goto label_0007CAAF;
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0007CAAF;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007CA77;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CA77u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007CA77: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CA77u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007CA8B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CA8Bu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007CA8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CA8Bu);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_saved_controlled_position.x;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->ecx = g_sfera_saved_controlled_position.y;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx = g_sfera_saved_controlled_position.z;
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    label_0007CAAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CAAFu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0007CAC3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CAC3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007CAC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CAC3u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_34;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = g_sfera_client_main_scalar_runtime.state_35;
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_36;
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->edi)) goto label_0007CAFA;
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CAFAu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007CAFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CAFAu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0];
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1];
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2];
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CB25u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7CB31u), LIFT_CODE_TOKEN_RVA(0x7CB2Fu))) { return; }
    label_0007CB31: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CB31u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x94u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CB4Cu), LIFT_CODE_TOKEN_RVA(0x7CB4Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CB4Cu);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x9Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7CB64u), LIFT_CODE_TOKEN_RVA(0x7CB62u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CB64u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CB70u), LIFT_CODE_TOKEN_RVA(0x7CB6Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CB70u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CB7Cu), LIFT_CODE_TOKEN_RVA(0x7CB7Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CB7Cu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CB87u); lift_push32(cpu, r); sfera_sub_004D8840(cpu,r); if (cpu->eip != r) return; }
    g_sfera_world_render_runtime.scene_active = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    label_0007CB92: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CB92u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047CBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CBA0u);
    cpu->esp -= 0x20u;
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) != (uint8_t)(0u)) goto label_0007CD85;
    lift_x87_push(cpu, (double)100000.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_window_runtime.distance_scratch.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)1000000.0f);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CBD8u); lift_push32(cpu, r); sfera_sub_0046D6A0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)99999.0f);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_window_runtime.distance_scratch.f32));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0007CD83;
    lift_x87_push(cpu, 0.0);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)-1.0f);
    g_sfera_main_render_runtime.secondary_render_pass = (uint32_t)(1u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xDCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7CC2Fu), LIFT_CODE_TOKEN_RVA(0x7CC2Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CC2Fu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CC41u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CC4Cu); lift_push32(cpu, r); sfera_sub_004DA310(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007CD58;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x98u);
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CC6Eu), LIFT_CODE_TOKEN_RVA(0x7CC6Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CC6Eu);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xA0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7CC86u), LIFT_CODE_TOKEN_RVA(0x7CC84u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CC86u);
    cpu->ecx = g_sfera_render_sample_runtime.active_record;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CC9Eu), LIFT_CODE_TOKEN_RVA(0x7CC9Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CC9Eu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x94u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7CCB8u), LIFT_CODE_TOKEN_RVA(0x7CCB6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CCB8u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_window_runtime.distance_scratch.f32));
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 1u;
    g_sfera_world_render_runtime.scene_active = (uint32_t)(1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CCD8u); lift_push32(cpu, r); sfera_sub_00464600(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CCE2u); lift_push32(cpu, r); sfera_sub_0047C670(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CCEEu); lift_push32(cpu, r); sfera_sub_00464AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CCFAu), LIFT_CODE_TOKEN_RVA(0x7CCF8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CCFAu);
    cpu->edx = lift_load32(cpu->esp);
    cpu->eax = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x94u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x7CD13u), LIFT_CODE_TOKEN_RVA(0x7CD11u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CD13u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x9Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CD2Cu), LIFT_CODE_TOKEN_RVA(0x7CD2Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CD2Cu);
    cpu->eax = lift_load32(cpu->esp);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CD37u), LIFT_CODE_TOKEN_RVA(0x7CD35u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CD37u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x7CD43u), LIFT_CODE_TOKEN_RVA(0x7CD41u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47CD43u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CD4Eu); lift_push32(cpu, r); sfera_sub_004D8840(cpu,r); if (cpu->eip != r) return; }
    g_sfera_world_render_runtime.scene_active = (uint32_t)(0u);
    label_0007CD58: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CD58u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CD6Au); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    g_sfera_main_render_runtime.secondary_render_pass = (uint32_t)(0u);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007CD83: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CD83u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007CD85: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CD85u);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047CDA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0007CDA0;
    label_0001C0A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C0A0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C0ADu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x7528u);
    cpu->edi = lift_load32(cpu->esi + 0x752Cu);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esi + 0x7528u, cpu->eax);
    lift_store32(cpu->esi + 0x752Cu, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0001C1A1;
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x7530u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    cpu->ecx = cpu->edx;
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->edi) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(5u)) goto label_0001C132;
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (9.999999747378752e-05));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.100000023841858);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C107u); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x7538u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esi + 0x7538u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0001C185;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    goto label_0001C17F;
    label_0001C132: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C132u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xAu)) goto label_0001C185;
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00039999998989515007));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.8999999761581421);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41C154u); lift_push32(cpu, r); sfera_sub_004EE9FE(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x7538u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esi + 0x7538u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0001C185;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    label_0001C17F: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C17Fu);
    lift_store_f32(cpu->esi + 0x7538u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001C185: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C185u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x7538u));
    lift_store32(cpu->esi + 0x7530u, 0u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.699999988079071));
    lift_store_f32(cpu->esi + 0x7534u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0001C1A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x41C1A1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007CDA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CDA0u);
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) != (uint32_t)(0u)) goto label_0007CDBE;
    if ((uint32_t)(g_sfera_window_runtime.windowed) == (uint32_t)(0u)) goto label_0007D03F;
    lift_push32(cpu, 0x64u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7CDB8u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x7CDBEu);
    label_0007CDBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CDBEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CDC3u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->ecx -= g_sfera_grass_map_runtime.last_frame_timestamp.low;
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_25)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.lighting_state) = (uint32_t)(cpu->ecx);
    g_sfera_grass_map_runtime.last_frame_timestamp.low = (uint32_t)(cpu->eax);
    g_sfera_grass_map_runtime.last_frame_timestamp.high = (uint32_t)(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007CDED;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.saved_fog_distance));
    goto label_0007CDF3;
    label_0007CDED: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CDEDu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.fog_distance));
    label_0007CDF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CDF3u);
    { uint64_t l=(uint64_t)(g_sfera_window_runtime.runtime_debug_enabled), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007CE0E;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_parameter));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007CE0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CE0Eu);
    if ((uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) == (uint8_t)(0u)) goto label_0007CE1C;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CE1Cu); lift_push32(cpu, r); sfera_sub_0047C980(cpu,r); if (cpu->eip != r) return; }
    label_0007CE1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CE1Cu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    { uint64_t l=(uint64_t)(g_sfera_world_render_runtime.feature_toggle), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, (uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x); lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CE41u); lift_push32(cpu, r); sfera_sub_00457510(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(g_sfera_options_dialog_runtime.reflection_quality) <= (int32_t)(uint32_t)(0u)) goto label_0007CE58;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13)) != (uint32_t)(0u)) goto label_0007CE58;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CE58u); lift_push32(cpu, r); sfera_sub_0047CBA0(cpu,r); if (cpu->eip != r) return; }
    label_0007CE58: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CE58u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CE63u); lift_push32(cpu, r); sfera_sub_004DA310(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007D033;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CE76u); lift_push32(cpu, r); sfera_sub_004D8360(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0007CE99;
    if ((uint32_t)(g_sfera_graphics_runtime.post_effects_enabled) != (uint32_t)(cpu->ebx)) goto label_0007CE99;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CE8Eu); lift_push32(cpu, r); sfera_sub_004DAF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CE99u); lift_push32(cpu, r); sfera_sub_004DACD0(cpu,r); if (cpu->eip != r) return; }
    label_0007CE99: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CE99u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    g_sfera_world_render_runtime.scene_active = (uint32_t)(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CEAEu); lift_push32(cpu, r); sfera_sub_00464600(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CEB5u); lift_push32(cpu, r); sfera_sub_0047C670(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CEBAu); lift_push32(cpu, r); sfera_sub_0044DE30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CEC8u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CED6u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CEDBu); lift_push32(cpu, r); sfera_sub_0045E560(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CEEAu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CEF9u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CF04u); lift_push32(cpu, r); sfera_sub_004D8360(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0007CF1B;
    if ((uint32_t)(g_sfera_graphics_runtime.post_effects_enabled) != (uint32_t)(cpu->ebx)) goto label_0007CF1B;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_02;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CF1Bu); lift_push32(cpu, r); sfera_sub_004DB030(cpu,r); if (cpu->eip != r) return; }
    label_0007CF1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CF1Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CF20u); lift_push32(cpu, r); sfera_sub_00451EB0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CF25u); lift_push32(cpu, r); sfera_sub_0044D5A0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47CF2Au); lift_push32(cpu, r); sfera_sub_0044DF90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27)) == (uint32_t)(0u)) goto label_0007CF86;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_world_objects.controlled_object_handle;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0007CF85;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0007CF4D;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CF4Du); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0007CF4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CF4Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity)) goto label_0007CF61;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CF61u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007CF61: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CF61u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_saved_controlled_position.x;
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = g_sfera_saved_controlled_position.y;
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->ecx = g_sfera_saved_controlled_position.z;
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    label_0007CF85: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CF85u);
    cpu->esi = lift_pop32(cpu);
    label_0007CF86: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CF86u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13)) == (uint32_t)(0u)) goto label_0007D006;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0007CFA3;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CFA3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007CFA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CFA3u);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_34;
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = g_sfera_client_main_scalar_runtime.state_35;
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->ecx = g_sfera_client_main_scalar_runtime.state_36;
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0007CFDB;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7CFDBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007CFDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47CFDBu);
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[0];
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[1];
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.reference_position[2];
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D006u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    label_0007D006: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D006u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D011u); lift_push32(cpu, r); sfera_sub_004D8840(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D016u); lift_push32(cpu, r); sfera_sub_0044E020(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    g_sfera_world_render_runtime.scene_active = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D033u); lift_push32(cpu, r); sfera_sub_004D8880(cpu,r); if (cpu->eip != r) return; }
    label_0007D033: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D033u);
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    cpu->ebx = lift_pop32(cpu);
    goto label_0001C0A0;
    label_0007D03F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D03Fu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047D040(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D040u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->esi = 1u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_04) = (uint32_t)(cpu->esi);
    cpu->edi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D067u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    (void)cpu;
    label_0007D070: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D070u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D075u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->ecx -= lift_load32(cpu->esp + 0x28u);
    cpu->edi += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x2710u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0007D08A;
    cpu->edi = 0x2710u;
    label_0007D08A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D08Au);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->edi + 0x1Au);
    cpu->eax = 0x4EC4EC4Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->ebp = cpu->edx;
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(0x1Fu), 32u);
    cpu->ebp += cpu->edx;
    cpu->edx = cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xFFFFFFCCu);
    cpu->edi += cpu->edx;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_0007D0E5;
    cpu->ecx = 0x34u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x32u)) goto label_0007D0D9;
    cpu->eax = 0x14u;
    goto label_0007D0DD;
    label_0007D0D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D0D9u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0007D0E5;
    label_0007D0DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D0DDu);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7D0DFu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x7D0E5u);
    label_0007D0E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D0E5u);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D0ECu); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007D47C;
    label_0007D100: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D100u);
    cpu->eax = g_sfera_pending_key_runtime.count;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0007D136;
    cpu->ecx = g_sfera_pending_key_runtime.key_codes[0];
    --cpu->eax;
    g_sfera_world_load_runtime.active_tool_context = (uint32_t)(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007D131;
    cpu->ecx = cpu->eax;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_pending_key_runtime.key_codes[1];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_pending_key_runtime.key_codes[0];
    lift_movs32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->esi = 1u;
    label_0007D131: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D131u);
    g_sfera_pending_key_runtime.count = (uint32_t)(cpu->eax);
    label_0007D136: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D136u);
    cpu->eax = g_sfera_scene_control_runtime.context_count;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0007D16C;
    cpu->edx = g_sfera_scene_control_runtime.context_queue[0];
    --cpu->eax;
    g_sfera_scene_control_runtime.active_context = (uint32_t)(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007D167;
    cpu->ecx = cpu->eax;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.context_queue[1];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.context_queue[0];
    lift_movs32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->esi = 1u;
    label_0007D167: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D167u);
    g_sfera_scene_control_runtime.context_count = (uint32_t)(cpu->eax);
    label_0007D16C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D16Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D171u); lift_push32(cpu, r); sfera_sub_0044CC70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_recovered_static_runtime.graphics_state = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_0007D186;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.escape_without_query)) == (uint32_t)(cpu->esi)) goto label_0007D71A;
    label_0007D186: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D186u);
    if ((uint32_t)(g_sfera_input_device_runtime.render_state) != (uint32_t)(cpu->ebx)) goto label_0007D735;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x58u)) goto label_0007D19F;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_landscape_map_runtime.show_fps, (uint64_t)(g_sfera_landscape_map_runtime.show_fps) ^ (uint64_t)(cpu->esi));
    goto label_0007D1AA;
    label_0007D19F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D19Fu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x41u)) goto label_0007D1AA;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.client_state_05, (uint64_t)(g_sfera_recovered_static_runtime.client_state_05) ^ (uint64_t)(cpu->esi));
    label_0007D1AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D1AAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D1AFu); lift_push32(cpu, r); sfera_sub_0044CBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.cursor_x;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D1B9u); lift_push32(cpu, r); sfera_sub_00462F00(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8((uint32_t)(uintptr_t)&g_sfera_direct_input_runtime.view_adjust_state)) & (0x80u)) == 0u) goto label_0007D226;
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.0005000000237487257));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)g_sfera_graphics_runtime.view_parameter)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_parameter, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_parameter));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007D1FF;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_parameter, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_parameter));
    label_0007D1FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D1FFu);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007D218;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.view_parameter, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007D21A;
    label_0007D218: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D218u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007D21A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D21Au);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y) = (uint32_t)(cpu->ebx);
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x) = (uint32_t)(cpu->ebx);
    label_0007D226: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D226u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D22Bu); lift_push32(cpu, r); sfera_sub_00467A70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_flags;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    cpu->edx = g_sfera_world_load_runtime.active_tool_context;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_scene_control_runtime.active_context;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D249u); lift_push32(cpu, r); sfera_sub_004BAFB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08)) != (uint32_t)(cpu->esi)) goto label_0007D2CF;
    if ((uint32_t)(g_sfera_recovered_static_runtime.interaction_enabled) != (uint32_t)(cpu->ebx)) goto label_0007D2CF;
    if ((uint32_t)(g_sfera_recovered_static_runtime.render_gate) != (uint32_t)(cpu->ebx)) goto label_0007D2CF;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_13)) == (uint32_t)(cpu->ebx)) goto label_0007D2C8;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0007D27D;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D27Du); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007D27D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D27Du);
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x)))));
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0007D2AB;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D2ABu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007D2AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D2ABu);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = lift_load32(cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)(((int32_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007D322;
    label_0007D2C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D2C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D2CDu); lift_push32(cpu, r); sfera_sub_00476DE0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007D322;
    label_0007D2CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D2CFu);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[5], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[4], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[3], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[2], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[1], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_view_state_runtime.view_coefficients[0], lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.z.f32, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.y.f32, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.secondary_vector.x.f32, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.z.f32, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.y.f32, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D322u); lift_push32(cpu, r); sfera_sub_00462F00(cpu,r); if (cpu->eip != r) return; }
    label_0007D322: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D322u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D329u); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D330u); lift_push32(cpu, r); sfera_sub_004496F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D337u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 2u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D341u); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08)) != (uint32_t)(cpu->ebx)) goto label_0007D358;
    lift_x87_push(cpu, (double)0.0052083334885537624f);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D358u); lift_push32(cpu, r); sfera_sub_00479530(cpu,r); if (cpu->eip != r) return; }
    label_0007D358: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D358u);
    cpu->ecx = 2u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D362u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_0007D396;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D37Du); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)0.02083333395421505f);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D38Cu); lift_push32(cpu, r); sfera_sub_004790C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 3u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D396u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    label_0007D396: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D396u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(6u)) goto label_0007D3D7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D3AAu); lift_push32(cpu, r); sfera_sub_004517D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_16)) != (uint32_t)(cpu->ebx)) goto label_0007D3D7;
    cpu->ecx = 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D3C0u); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)) != (uint32_t)(cpu->esi)) goto label_0007D3CD;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D3CDu); lift_push32(cpu, r); sfera_sub_00429C10(cpu,r); if (cpu->eip != r) return; }
    label_0007D3CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D3CDu);
    cpu->ecx = 4u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D3D7u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    label_0007D3D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D3D7u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(6u)) goto label_0007D40B;
    cpu->eax = g_sfera_landscape_render_runtime.rotation_step;
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    g_sfera_landscape_render_runtime.rotation_step = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x20u)) goto label_0007D401;
    g_sfera_landscape_render_runtime.rotation_step = (uint32_t)(cpu->ebx);
    label_0007D401: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D401u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D406u); lift_push32(cpu, r); sfera_sub_00456A90(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D40Bu); lift_push32(cpu, r); sfera_sub_00432880(cpu,r); if (cpu->eip != r) return; }
    label_0007D40B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D40Bu);
    cpu->ecx = 5u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D415u); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D41Au); lift_push32(cpu, r); sfera_sub_0045EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 5u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D424u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.animation_phase));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.0005000000237487257));
    g_sfera_scene_control_runtime.active_context = (uint32_t)(cpu->ebx);
    g_sfera_world_load_runtime.active_tool_context = (uint32_t)(cpu->ebx);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.animation_phase, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.animation_phase));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007D463;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.animation_phase, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0007D465;
    label_0007D463: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D463u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0007D465: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D465u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D46Au); lift_push32(cpu, r); sfera_sub_00451580(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0007D100;
    label_0007D47C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D47Cu);
    cpu->eax = g_sfera_frame_runtime.frame_state;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0007D49D;
    cpu->eax += cpu->esi;
    g_sfera_frame_runtime.frame_state = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D492u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    g_sfera_frame_runtime.frame_state_anchor.high = (uint32_t)(cpu->edx);
    g_sfera_frame_runtime.frame_state_anchor.low = (uint32_t)(cpu->eax);
    label_0007D49D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D49Du);
    cpu->ecx = 6u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D4A7u); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 6u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D4B1u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 7u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D4BBu); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)) != (uint32_t)(cpu->esi)) goto label_0007D5D4;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20)) == (uint32_t)(cpu->ebx)) goto label_0007D528;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_0007D4E3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D4E3u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007D4E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D4E3u);
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    lift_x87_push(cpu, (double)300.0f);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->edx + 0xCu)));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007D528;
    if ((int32_t)(uint32_t)(g_sfera_world_objects.object_handles.capacity) > (int32_t)(uint32_t)(cpu->esi)) goto label_0007D510;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D510u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0007D510: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D510u);
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 800.0);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007D544;
    label_0007D528: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D528u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.environment_lookup_result); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D53Cu); lift_push32(cpu, r); sfera_sub_00433E10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_weather_runtime.standard_object;
    if (cpu->ecx == 0u) cpu->ecx = (uint32_t)(g_sfera_weather_runtime.highres_object);
    goto label_0007D55E;
    label_0007D544: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D544u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, (uintptr_t)&g_sfera_recovered_static_runtime.environment_lookup_result); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D558u); lift_push32(cpu, r); sfera_sub_00433E10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_weather_runtime.highres_object;
    if (cpu->ecx == 0u) cpu->ecx = (uint32_t)(g_sfera_weather_runtime.standard_object);
    label_0007D55E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D55Eu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D564u); lift_push32(cpu, r); sfera_sub_0049CC90(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10)) != (uint32_t)(cpu->esi)) goto label_0007D5C8;
    if ((int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007D589;
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x47D574u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47D579u);
    cpu->ecx = (uint32_t)(cpu->esi + cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D581u); lift_push32(cpu, r); sfera_sub_004982F0(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11) = (uint32_t)(cpu->ebx);
    goto label_0007D59D;
    label_0007D589: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D589u);
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x47D589u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47D58Eu);
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D597u); lift_push32(cpu, r); sfera_sub_004982F0(cpu,r); if (cpu->eip != r) return; }
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_11) = (uint32_t)(cpu->esi);
    label_0007D59D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D59Du);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.scalar_01));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.scalar_01, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.scalar_01));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 50.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007D5C8;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10) = (uint32_t)(cpu->ebx);
    label_0007D5C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D5C8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D5CDu); lift_push32(cpu, r); sfera_sub_0047CDA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D5D2u); lift_push32(cpu, r); sfera_sub_00499EE0(cpu,r); if (cpu->eip != r) return; }
    goto label_0007D635;
    label_0007D5D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D5D4u);
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) != (uint32_t)(cpu->ebx)) goto label_0007D5EC;
    if ((uint32_t)(g_sfera_window_runtime.windowed) == (uint32_t)(cpu->ebx)) goto label_0007D635;
    lift_push32(cpu, 0x64u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_RVA(0x7D5E6u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x7D5ECu);
    label_0007D5EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D5ECu);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0xFF000000u); lift_push32(cpu, 3u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D607u); lift_push32(cpu, r); sfera_sub_004D87E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D612u); lift_push32(cpu, r); sfera_sub_004DA310(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0007D635;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D61Bu); lift_push32(cpu, r); sfera_sub_0044DF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D626u); lift_push32(cpu, r); sfera_sub_004D8840(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D635u); lift_push32(cpu, r); sfera_sub_004D8880(cpu,r); if (cpu->eip != r) return; }
    label_0007D635: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D635u);
    cpu->ecx = 7u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D63Fu); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D649u); lift_push32(cpu, r); sfera_sub_0049A690(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)) != (uint32_t)(cpu->esi)) goto label_0007D656;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D656u); lift_push32(cpu, r); sfera_sub_00497ED0(cpu,r); if (cpu->eip != r) return; }
    label_0007D656: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D656u);
    cpu->ecx = 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D660u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D665u); lift_push32(cpu, r); sfera_sub_0044C160(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_render_lookup_runtime.initialized) == (uint32_t)(cpu->esi)) goto label_0007D752;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D678u); lift_push32(cpu, r); sfera_sub_0049A6D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_profiler_runtime.accumulated_ticks[0].high), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0007D070;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0007D696;
    if ((uint32_t)(g_sfera_profiler_runtime.accumulated_ticks[0].low) <= (uint32_t)(0xF4240u)) goto label_0007D070;
    label_0007D696: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D696u);
    cpu->ebp = 0u;
    cpu->esi = 1u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_profiler_runtime.report_percent[1];
    label_0007D6B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D6B0u);
    cpu->edx = g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].high;
    cpu->eax = g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].low;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D6C8u); lift_push32(cpu, r); sfera_sub_004EED20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, g_sfera_profiler_runtime.accumulated_ticks[0].high); lift_push32(cpu, g_sfera_profiler_runtime.accumulated_ticks[0].low); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D6DBu); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].low = (uint32_t)(cpu->ebx);
    g_sfera_profiler_runtime.accumulated_ticks[cpu->esi].high = (uint32_t)(cpu->ebx);
    cpu->edi += 4u;
    cpu->ebp += cpu->eax;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_profiler_runtime.report_percent[8]))) goto label_0007D6B0;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_profiler_runtime.report_percent[0]), cpu->ebp);
    g_sfera_profiler_runtime.accumulated_ticks[0].low = (uint32_t)(cpu->ebx);
    g_sfera_profiler_runtime.accumulated_ticks[0].high = (uint32_t)(cpu->ebx);
    cpu->esi = 1u;
    goto label_0007D070;
    label_0007D71A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D71Au);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_warning_log_runtime.object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D724u); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D729u); lift_push32(cpu, r); sfera_sub_0049A730(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D72Eu); lift_push32(cpu, r); sfera_sub_004595F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x7D72Fu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x7D735u);
    label_0007D735: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D735u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x13u)) & 0xFFu);
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x17u);
    lift_push32(cpu, cpu->edx);
    g_sfera_input_device_runtime.render_state = (uint32_t)(cpu->ebx);
    lift_store8(cpu->esp + 0x1Bu, cpu->ecx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D752u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_0007D752: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D752u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D757u); lift_push32(cpu, r); sfera_sub_004595F0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D75Cu); lift_push32(cpu, r); sfera_sub_0042EB70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_VA(0x47D75Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47D763u);
    lift_trap(cpu, 0x47D763u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047D770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D770u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    lift_native_call(cpu, native_function_address32(&::GetCurrentThread), LIFT_CODE_TOKEN_VA(0x47D773u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47D779u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetThreadAffinityMask), LIFT_CODE_TOKEN_VA(0x47D77Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47D780u);
    cpu->ecx = LIFT_CALLBACK(sfera_sub_0044D7E0);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D78Au); lift_push32(cpu, r); sfera_sub_004EC1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = LIFT_CALLBACK(sfera_sub_00434D50);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D794u); lift_push32(cpu, r); sfera_sub_004EBF20(cpu,r); if (cpu->eip != r) return; }
    const uint32_t launch_guard = (uint32_t)(uintptr_t)"/15FCE220-0246-58ec-3EH2-968B3072ACF8";
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_strstr_address32();
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, launch_guard); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7D7C4u), LIFT_CODE_TOKEN_RVA(0x7D7C2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D7C4u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007D7E5;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340 \347\340\357\363\361\352\340."); lift_push32(cpu, (uintptr_t)"\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 Sphere.exe."); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x47D7D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47D7DDu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0007D7E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D7E5u);
    cpu->eax = 0u;
    lift_push32(cpu, (uintptr_t)"/locale"); lift_push32(cpu, cpu->edi);
    (*(uint32_t*)(void*)&g_sfera_client_process_runtime.locale[0]) = (uint32_t)(cpu->eax);
    (*(uint32_t*)(void*)&g_sfera_client_process_runtime.locale[4]) = (uint32_t)(cpu->eax);
    (*(uint16_t*)(void*)&g_sfera_client_process_runtime.locale[8]) = (uint16_t)(cpu->eax & 0xFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7D7FFu), LIFT_CODE_TOKEN_RVA(0x7D7FDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D7FFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007D845;
    cpu->eax += 7u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007D810: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D810u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_0007D81C;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(9u)) goto label_0007D81F;
    label_0007D81C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D81Cu);
    ++cpu->eax;
    goto label_0007D810;
    label_0007D81F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D81Fu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->edx = 0u;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_0007D845;
    label_0007D828: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D828u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(9u)) goto label_0007D845;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0007D845;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(0xAu)) goto label_0007D845;
    ++cpu->eax;
    lift_store8(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_client_process_runtime.locale[0]), cpu->ecx & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_0007D828;
    label_0007D845: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D845u);
    lift_push32(cpu, (uintptr_t)"/login"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7D84Du), LIFT_CODE_TOKEN_RVA(0x7D84Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D84Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007D85D;
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.gamexp_sid_present) = (uint8_t)(1u);
    goto label_0007D8B4;
    label_0007D85D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D85Du);
    lift_push32(cpu, (uintptr_t)"/gamexp_sid"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7D865u), LIFT_CODE_TOKEN_RVA(0x7D863u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D865u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007D9A0;
    cpu->eax += 0xBu;
    label_0007D873: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D873u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_0007D87F;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(9u)) goto label_0007D882;
    label_0007D87F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D87Fu);
    ++cpu->eax;
    goto label_0007D873;
    label_0007D882: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D882u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->edx = 0u;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_0007D8AD;
    label_0007D890: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D890u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(9u)) goto label_0007D8AD;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0007D8AD;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(0x1Eu)) goto label_0007D8AD;
    ++cpu->eax;
    lift_store8(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0]), cpu->ecx & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_0007D890;
    label_0007D8AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D8ADu);
    lift_store8(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0]), 0u);
    label_0007D8B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D8B4u);
    cpu->ecx = (uint32_t)(uintptr_t)"connect.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D8BEu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007D8ED;
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    cpu->ecx = (uint32_t)(uintptr_t)"CONNECT_TYPE";
    lift_store32(cpu->esp + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D8D4u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007D8E6;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 8u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) = (uint8_t)(1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007D8ED;
    label_0007D8E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D8E6u);
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) = (uint8_t)(0u);
    label_0007D8ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D8EDu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D8F4u); lift_push32(cpu, r); sfera_sub_0042E920(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = native_function_address32(&::InitializeCriticalSection);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_network_send_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7D901u), LIFT_CODE_TOKEN_RVA(0x7D8FFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D901u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7D908u), LIFT_CODE_TOKEN_RVA(0x7D906u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D908u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.scene_lock[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x7D90Fu), LIFT_CODE_TOKEN_RVA(0x7D90Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D90Fu);
    cpu->ebp = native_function_address32(&::CreateFileA);
    cpu->ebx = native_function_address32(&::CreateDirectoryA);
    cpu->edi = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0007D920: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D920u);
    cpu->esi = (uintptr_t)(cpu->edi == 0u ? ".\\logs" : ".\\players");
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x7D935u), LIFT_CODE_TOKEN_RVA(0x7D933u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D935u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0007D941;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7D93Fu), LIFT_CODE_TOKEN_RVA(0x7D93Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D93Fu);
    goto label_0007D948;
    label_0007D941: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D941u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x7D942u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x7D948u);
    label_0007D948: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D948u);
    cpu->edi += 4u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(8u)) goto label_0007D920;
    lift_x87_push(cpu, 0.30000001192092896);
    cpu->esp -= 0x10u;
    lift_store_f64(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D967u); lift_push32(cpu, r); sfera_sub_0044EBC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object) = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_startup_command_line_runtime.text[0];
    cpu->ebp = lift_pop32(cpu);
    lift_store32((uintptr_t)&g_sfera_startup_command_line_runtime.parser_state, cpu->ecx);
    cpu->edx -= cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_0007D987: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D987u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0007D987;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D996u); lift_push32(cpu, r); sfera_sub_00464BA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47D99Bu); lift_push32(cpu, r); sfera_sub_0045BC60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7D9A0u); lift_push32(cpu, r); sfera_sub_0047D040(cpu,r); if (cpu->eip != r) return; }
    label_0007D9A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47D9A0u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340 \347\340\357\363\361\352\340"); lift_push32(cpu, (uintptr_t)"\307\340\357\363\361\352 \357\360\356\350\347\342\356\344\350\362\361\377 \357\360\356\343\360\340\354\354\356\351 launchpoint.exe."); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x47D9AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47D9B4u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047D9C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47D9C0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"BM")) & 0xFFFFu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_store16(cpu->esp + 0x10u, cpu->eax & 0xFFFFu);
    cpu->ebx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->eax = (uint32_t)(cpu->ebx + 3u);
    cpu->eax &= 0xFFFFFFFCu;
    cpu->edx = cpu->eax;
    cpu->esi = cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"BM") + 2u)) & 0xFFu);
    lift_store8(cpu->esp + 0x12u, cpu->ecx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->edx + 0x39u);
    cpu->ecx &= 0xFFFFFFFCu;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->ecx -= cpu->edx;
    cpu->ecx -= 0x36u;
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    cpu->eax -= cpu->ebx;
    lift_store32(cpu->esi + 0x64u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi + 0x60u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA15u); lift_push32(cpu, r); sfera_sub_0042EE20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 0x58u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA25u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA33u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    cpu->ebx = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA47u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, 0x36u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA5Du); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA73u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA85u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DA97u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DAADu); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DAC3u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DAD5u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DAE3u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, 0xB12u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DAF9u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DB07u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DB19u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x58u);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DB27u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047DB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47DB30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x4Eu);
    cpu->edx = (uint32_t)(uintptr_t)"MapGenerator.cpp";
    cpu->ecx = 0xC0000u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DB44u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x2000u);
    lift_store32(cpu->esi + 0x54u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0x2000u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DB5Du); lift_push32(cpu, r); sfera_sub_0047D9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047DB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47DB70u);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 1u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DB92u); lift_push32(cpu, r); sfera_sub_004815D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32((uintptr_t)"xadd\\matbase");
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"xadd\\matbase") + 4u);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"xadd\\matbase") + 8u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"xadd\\matbase") + 0xCu)) & 0xFFu);
    lift_store8(cpu->esp + 0x30u, cpu->eax & 0xFFu);
    cpu->ebp = 0u;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x31u, cpu->eax);
    lift_store32(cpu->esp + 0x35u, cpu->eax);
    lift_store32(cpu->esp + 0x39u, cpu->eax);
    lift_store32(cpu->esp + 0x3Du, cpu->eax);
    lift_store16(cpu->esp + 0x41u, cpu->eax & 0xFFFFu);
    lift_store8(cpu->esp + 0x43u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_font_runtime.language_suffix[0];
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->ecx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007DBE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DBE0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007DBE0;
    cpu->edi = (uint32_t)(cpu->esp + 0x24u);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0007DBF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DBF0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007DBF0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_movs8(cpu, 1u);
    --cpu->eax;
    label_0007DC10: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DC10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007DC10;
    cpu->ecx = lift_load32((uintptr_t)".dat");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)".dat") + 4u)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DC2Eu); lift_push32(cpu, r); sfera_sub_0042EBE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DC37u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DC3Eu); lift_push32(cpu, r); sfera_sub_0042EBD0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx, cpu->ebp);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0007E0D3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->ebx, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DC58u); lift_push32(cpu, r); sfera_sub_00482170(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)"words";
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DC68u); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0007DC7A;
    cpu->ecx = (uint32_t)(uintptr_t)"CMatFilter::CMatFilter: \354\340\361\361\350\342 words \355\345 \355\340\351\344\345\355 \342 matbase.dat";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7DC7Au); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007DC7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DC7Au);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 8u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0007DD44;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007DC90: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DC90u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)"words";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DCA3u); lift_push32(cpu, r); sfera_sub_00481300(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"w";
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DCB6u); lift_push32(cpu, r); sfera_sub_00481180(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007DCC4;
    cpu->ecx = (uint32_t)(uintptr_t)"CMatFilter::CMatFilter: field 'w' absent in one of array's elements";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7DCC4u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007DCC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DCC4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007DCD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DCD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007DCD0;
    cpu->eax -= cpu->edx;
    cpu->edx = (uint32_t)(uintptr_t)"e";
    cpu->ecx = cpu->ebp;
    cpu->edi = (uint32_t)(cpu->edi + cpu->eax + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DCE9u); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0007DD2A;
    label_0007DCF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DCF1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(uintptr_t)"e";
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DD03u); lift_push32(cpu, r); sfera_sub_004812A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007DD11;
    cpu->ecx = (uint32_t)(uintptr_t)"CMatFilter::CMatFilter: error reading exceptions";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7DD11u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007DD11: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DD11u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007DD18: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DD18u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007DD18;
    cpu->eax -= cpu->edx;
    ++cpu->esi;
    cpu->edi = (uint32_t)(cpu->edi + cpu->eax + 1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0007DCF1;
    label_0007DD2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DD2Au);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_0007DC90;
    cpu->ebp = 0u;
    cpu->ebx = cpu->ecx;
    label_0007DD44: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DD44u);
    lift_push32(cpu, 0x55u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebx + 4u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DD55u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x56u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_store32(cpu->ebx + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DD6Bu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x57u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_store32(cpu->ebx + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DD81u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x58u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    lift_store32(cpu->ebx + 0x14u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DD97u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    lift_store32(cpu->ebx + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 8u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0007DEED;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007DDB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DDB0u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)"words";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DDC3u); lift_push32(cpu, r); sfera_sub_00481300(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)"w";
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DDD8u); lift_push32(cpu, r); sfera_sub_00481180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += cpu->esi;
    label_0007DDE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DDE5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->edx;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007DDE5;
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    lift_store32(cpu->ecx + cpu->ebp, cpu->esi);
    cpu->edx = lift_load32(cpu->edi + 0x14u);
    cpu->edx += cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)"t";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DE17u); lift_push32(cpu, r); sfera_sub_00481120(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007DE25;
    cpu->ecx = (uint32_t)(uintptr_t)"CMatFilter::CMatFilter: field 't' absent in one of array's elements";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7DE25u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007DE25: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DE25u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007DE30: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DE30u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007DE30;
    cpu->eax -= cpu->edx;
    cpu->edx = (uint32_t)(uintptr_t)"e";
    cpu->ecx = cpu->ebx;
    cpu->esi = (uint32_t)(cpu->esi + cpu->eax + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DE49u); lift_push32(cpu, r); sfera_sub_004811B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFFu)) goto label_0007DE5C;
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    lift_store32(cpu->eax + cpu->ebp, 0u);
    goto label_0007DED7;
    label_0007DE5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DE5Cu);
    lift_push32(cpu, 0x6Bu);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebx) * 4u) + 4u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DE6Fu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    lift_store32(cpu->edx + cpu->ebp, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x18u);
    cpu->ecx = lift_load32(cpu->eax + cpu->ebp);
    cpu->edi = 0u;
    lift_store32(cpu->ecx, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0007DED7;
    label_0007DE85: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DE85u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(uintptr_t)"e";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DE99u); lift_push32(cpu, r); sfera_sub_004812A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += cpu->esi;
    label_0007DEA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DEA6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->edx;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007DEA6;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = lift_load32(cpu->edx + cpu->ebp);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 4u, cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007DEC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DEC5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007DEC5;
    cpu->eax -= cpu->edx;
    ++cpu->edi;
    cpu->esi = (uint32_t)(cpu->esi + cpu->eax + 1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0007DE85;
    label_0007DED7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DED7u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_0007DDB0;
    label_0007DEED: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DEEDu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47DEF6u); lift_push32(cpu, r); sfera_sub_004815C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = (uint32_t)(cpu->eax + 0x20u);
    label_0007DF00: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF00u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x41u)) goto label_0007DF0A;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x5Au)) goto label_0007DF39;
    label_0007DF0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF0Au);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x61u)) goto label_0007DF14;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x7Au)) goto label_0007DF39;
    label_0007DF14: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF14u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0xC0u)) goto label_0007DF39;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xA8u)) goto label_0007DF39;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xB8u)) goto label_0007DF39;
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0]), cpu->esi);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0]), cpu->esi);
    goto label_0007DF6E;
    label_0007DF39: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF39u);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFBFu);
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->edi) > (uint32_t)(0x19u)) goto label_0007DF46;
    cpu->ecx = (uint32_t)(cpu->eax + 0x20u);
    label_0007DF46: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF46u);
    cpu->edx = (uint32_t)(cpu->ecx + 0xFFFFFF40u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(0x1Fu)) goto label_0007DF53;
    cpu->ecx += cpu->esi;
    label_0007DF53: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF53u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0xA8u)) goto label_0007DF60;
    cpu->ecx = 0xB8u;
    label_0007DF60: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF60u);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0]), cpu->ecx);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0]), cpu->ecx);
    label_0007DF6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47DF6Eu);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_0007DF00;
    g_sfera_material_filter_runtime.character_map[0][0x30] = 0x30u;
    g_sfera_material_filter_runtime.character_map[0][0x33] = 0x33u;
    g_sfera_material_filter_runtime.character_map[0][0x36] = 0x36u;
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\345\270e");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\344g");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\3416b");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\363y");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\352k");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\343r");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\3473");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\365x");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\350\351u");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\3560o");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\360p");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\361c");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\340a");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\354m");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[0][0], "\355h");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\350\351i");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\363u");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\352k");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\345e\270");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\366c");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\355n");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\343g");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\347z");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\365h");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\344d");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\353l");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\356o");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\360r");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\357p");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\340a");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\342v");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\364f");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\361s");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\354m");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\362t");
    sfera_apply_character_alias_group(&g_sfera_material_filter_runtime.character_map[1][0], "\341b");
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007E0D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E0D3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E0F0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 8u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0007E12D;
    label_0007E100: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E100u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007E127;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0xB8u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E11Du); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u), 0u);
    label_0007E127: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E127u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0007E100;
    label_0007E12D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E12Du);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    lift_push32(cpu, 0xB9u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E13Fu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, 0xBAu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E151u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, 0xBBu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E163u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, 0xBCu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\matfilter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E175u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E180u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0];
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007E190;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0];
    label_0007E190: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E190u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_0007E1AE;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007E1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E1A0u);
    cpu->edx = lift_load8(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(cpu->edx) * 4u))) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0u)) goto label_0007E1A0;
    label_0007E1AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E1AEu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E1C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E1C0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 8u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0007E468;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007E1E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E1E0u);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax += lift_load32(cpu->edi + 0xCu);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    cpu->edi = cpu->edi;
    label_0007E1F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E1F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    ++cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E1F0;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0];
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007E20A;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0];
    label_0007E20A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E20Au);
    if ((uint8_t)(((uint8_t)g_sfera_material_filter_runtime.filter_word[0])) == (uint8_t)(0u)) goto label_0007E226;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    label_0007E218: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E218u);
    cpu->edx = lift_load8(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(cpu->edx) * 4u))) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0u)) goto label_0007E218;
    label_0007E226: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E226u);
    cpu->eax = lift_load32(cpu->edi + 0x14u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_0007E45A;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0007E23C;
        case 1u: goto label_0007E279;
        case 2u: goto label_0007E29B;
        case 3u: goto label_0007E2BD;
        case 4u: goto label_0007E301;
        default: lift_trap(cpu, 0x47E235u, "resolved jump-table index out of range"); return;
    }
label_0007E23C: ;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    label_0007E247: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E247u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007E267;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0007E263;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007E267;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007E247;
    label_0007E263: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E263u);
    cpu->eax = 0u;
    goto label_0007E26C;
    label_0007E267: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E267u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0007E26C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E26Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007E364;
    goto label_0007E45A;
    label_0007E279: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E279u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E283u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E289u);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_0007E364;
    goto label_0007E45A;
    label_0007E29B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E29Bu);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E2A5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E2ABu);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0007E364;
    goto label_0007E45A;
    label_0007E2BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E2BDu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E2C7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E2CDu);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0007E45A;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0007E364;
    cpu->eax = sfera_cp1251_is_russian_vowel_or_sign(lift_load8(cpu->ebp + 0xFFFFFFFFu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007E45A;
    goto label_0007E364;
    label_0007E301: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E301u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.filter_word[0]); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x47E30Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E311u);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_0007E45A;
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007E323: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E323u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E323;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_0007E336: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E336u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E336;
    cpu->eax -= cpu->esi;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_0007E360;
    cpu->ecx = cpu->ebx;
    cpu->eax = sfera_cp1251_is_russian_vowel_or_sign(lift_load8(cpu->eax + cpu->ecx));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007E456;
    label_0007E360: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E360u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_0007E364: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E364u);
    cpu->edx = lift_load32(cpu->edi + 0x18u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u))) == (uint32_t)(0u)) goto label_0007E474;
    cpu->ebx = 0u;
    label_0007E373: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E373u);
    cpu->eax = lift_load32(cpu->edi + 0x18u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(lift_load32(cpu->eax))) goto label_0007E474;
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u) + 4u);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edx + 1u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0];
    label_0007E391: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E391u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0007E391;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0]);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E3A7u); lift_push32(cpu, r); sfera_sub_0047E180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_0007E3B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E3B0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E3B0;
    cpu->ecx = lift_load32(cpu->edi + 0x18u);
    cpu->eax -= cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ebx) * 4u) + 4u);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->ecx = (int8_t)(lift_load8(cpu->ecx + cpu->edx));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x30u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007E420;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007E450;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.filter_word[0];
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->edi = cpu->edi;
    label_0007E3E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E3E0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007E3E0;
    cpu->ecx -= cpu->esi;
    cpu->esi = (uint32_t)(cpu->ecx + cpu->ebp);
    cpu->ecx = cpu->esi;
    cpu->edi = (uint32_t)(cpu->ecx + 1u);
    label_0007E3F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E3F1u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007E3F1;
    cpu->ecx -= cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_0007E448;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x47E405u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E40Bu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007E45A;
    ++cpu->ebx;
    goto label_0007E373;
    label_0007E420: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E420u);
    cpu->ecx = cpu->ebp;
    cpu->ecx -= lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_0007E450;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp;
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.exception_scratch[0]); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x47E435u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E43Bu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007E45A;
    ++cpu->ebx;
    goto label_0007E373;
    label_0007E448: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E448u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_0007E450: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E450u);
    ++cpu->ebx;
    goto label_0007E373;
    label_0007E456: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E456u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_0007E45A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E45Au);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0007E1E0;
    label_0007E468: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E468u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_0007E474: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E474u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E4A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E4A0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esp + 0x13u, 0u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007E4B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E4B3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E4B3;
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x1000u);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47E4CAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E4CFu);
    cpu->esp += 0xCu;
    cpu->ebp = 0u;
    cpu->eax = cpu->esi;
    cpu->edi -= cpu->esi;
    label_0007E4D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E4D8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x3Cu)) goto label_0007E4EA;
    lift_store8(cpu->esp + 0x13u, 1u);
    lift_store8(cpu->edi + cpu->eax, 0x20u);
    goto label_0007E4FA;
    label_0007E4EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E4EAu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) != (uint8_t)(1u)) goto label_0007E4F7;
    lift_store8(cpu->edi + cpu->eax, 0x20u);
    goto label_0007E4FA;
    label_0007E4F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E4F7u);
    lift_store8(cpu->edi + cpu->eax, cpu->ecx & 0xFFu);
    label_0007E4FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E4FAu);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x3Eu)) goto label_0007E504;
    lift_store8(cpu->esp + 0x13u, 0u);
    label_0007E504: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E504u);
    ++cpu->ebp;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0007E4D8;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E520u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->edx -= cpu->eax;
    label_0007E538: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E538u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E538;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[0][0];
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->ebp)) goto label_0007E551;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.character_map[1][0];
    label_0007E551: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E551u);
    if ((uint8_t)(((uint8_t)g_sfera_material_filter_runtime.normalized_input[0])) == (uint8_t)(0u)) goto label_0007E56E;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    (void)cpu;
    label_0007E560: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E560u);
    cpu->edx = lift_load8(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(cpu->edx) * 4u))) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0u)) goto label_0007E560;
    label_0007E56E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E56Eu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    cpu->esi = 0u;
    --cpu->eax;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    label_0007E580: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E580u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0007E58E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) == (uint8_t)(lift_load8((uintptr_t)&g_sfera_material_filter_runtime.normalized_input[cpu->esi - 1u]))) goto label_0007E597;
    label_0007E58E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E58Eu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0]), cpu->edx & 0xFFu);
    ++cpu->esi;
    label_0007E597: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E597u);
    ++cpu->eax;
    ++cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0u)) goto label_0007E580;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_starts[0];
    cpu->esi = 0u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0007E5B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E5B0u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x20u)) goto label_0007E5BB;
    label_0007E5B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E5B5u);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x20u)) goto label_0007E5B5;
    label_0007E5BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E5BBu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E5C5;
    cpu->ecx = 0u;
    goto label_0007E5E6;
    label_0007E5C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E5C5u);
    cpu->edx = 0u;
    cpu->ebx = cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_0007E5DE;
    cpu->edi = cpu->edi;
    label_0007E5D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E5D0u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0007E5DE;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    ++cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_0007E5D0;
    label_0007E5DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E5DEu);
    lift_store32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0]), cpu->edx);
    cpu->ecx = cpu->ebx;
    label_0007E5E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E5E6u);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0]));
    ++cpu->ebp;
    lift_store32(cpu->edi, cpu->ecx);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ebp) * 4u));
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]));
    cpu->eax += cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0xFFFFFFFCu)) != (uint32_t)(0u)) goto label_0007E5B0;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007E6E2;
    if ((uint8_t)(((uint8_t)g_sfera_material_filter_runtime.normalized_input[0])) == (uint8_t)(0u)) goto label_0007E62E;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.normalized_input[0];
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0007E620: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E620u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x20u)) goto label_0007E628;
    lift_store8(cpu->eax, 0u);
    label_0007E628: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E628u);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0u)) goto label_0007E620;
    label_0007E62E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E62Eu);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_0007E6E2;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007E640: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E640u);
    cpu->eax = lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E651u); lift_push32(cpu, r); sfera_sub_0047E1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007E6EC;
    cpu->eax = lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]));
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.match_buffer[0];
    cpu->edx -= cpu->eax;
    label_0007E667: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E667u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E667;
    if ((int32_t)(uint32_t)(lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0]))) > (int32_t)(uint32_t)(3u)) goto label_0007E6D5;
    cpu->ebx = (uint32_t)(cpu->ebp + 1u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0007E6D5;
    label_0007E682: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E682u);
    if ((int32_t)(uint32_t)(lift_load32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_lengths[0]))) > (int32_t)(uint32_t)(3u)) goto label_0007E6D5;
    cpu->eax = lift_load32(((uint32_t)(cpu->ebx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.token_starts[0]));
    cpu->ecx = cpu->eax;
    label_0007E695: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E695u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007E695;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.match_buffer[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0007E6A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E6A6u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007E6A6;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.match_buffer[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E6CAu); lift_push32(cpu, r); sfera_sub_0047E1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007E6EC;
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_0007E682;
    label_0007E6D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E6D5u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->esi)) goto label_0007E640;
    label_0007E6E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E6E2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0007E6EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E6ECu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E700u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)&g_sfera_material_filter_runtime.tag_stripped_input[0]); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E712u); lift_push32(cpu, r); sfera_sub_0047E4A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(0u)) goto label_0007E71D;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0007E71D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E71Du);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.tag_stripped_input[0]);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E730u); lift_push32(cpu, r); sfera_sub_0047E520(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007E73D;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0007E73D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E73Du);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_material_filter_runtime.tag_stripped_input[0]);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 4u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E750u); lift_push32(cpu, r); sfera_sub_0047E520(cpu,r); if (cpu->eip != r) return; }
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E760u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007E772: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E772u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007E772;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0007E82E;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0007E790: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E790u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x2Du)) goto label_0007E7E6;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x20u)) goto label_0007E7E6;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x5Fu)) goto label_0007E7E6;
    if ((uint8_t)((cpu->ecx & 0xFFu)) < (uint8_t)(0x30u)) goto label_0007E7AC;
    if ((uint8_t)((cpu->ecx & 0xFFu)) <= (uint8_t)(0x39u)) goto label_0007E7E6;
    label_0007E7AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E7ACu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) < (uint8_t)(0x61u)) goto label_0007E7B6;
    if ((uint8_t)((cpu->ecx & 0xFFu)) <= (uint8_t)(0x7Au)) goto label_0007E7BD;
    label_0007E7B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E7B6u);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFBFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(0x19u)) goto label_0007E7CA;
    label_0007E7BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E7BDu);
    cpu->eax = 1u;
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007E7EA;
    cpu->edi = cpu->eax;
    goto label_0007E825;
    label_0007E7CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E7CAu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) >= (uint8_t)(0xC0u)) goto label_0007E7D9;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0xB8u)) goto label_0007E7D9;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0xA8u)) goto label_0007E838;
    label_0007E7D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E7D9u);
    cpu->eax = 2u;
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007E7EA;
    cpu->edi = cpu->eax;
    goto label_0007E825;
    label_0007E7E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E7E6u);
    cpu->eax = 0u;
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    label_0007E7EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E7EAu);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0007E825;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_0007E825;
    if (sfera_identifier_char_is_keyboard_ambiguous((uint8_t)cpu->ecx)) { goto label_0007E838; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    label_0007E825: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E825u);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->edx)) goto label_0007E790;
    label_0007E82E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E82Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007E838: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E838u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E850u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(0xEu)) goto label_0007E863;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(0x52485053u)) goto label_0007E863;
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007E863: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E863u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E870u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xEu)) goto label_0007E8F2;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"SPHR"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x47E88Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E893u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007E8F2;
    if ((uint32_t)(lift_load32(cpu->edi)) != (uint32_t)(cpu->eax)) goto label_0007E8BA;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0xEu)) & 0xFFu);
    lift_store8(cpu->edi, (uint64_t)(lift_load8(cpu->edi)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->edi + 1u, (uint64_t)(lift_load8(cpu->edi + 1u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->edi + 2u, (uint64_t)(lift_load8(cpu->edi + 2u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->edi + 3u, (uint64_t)(lift_load8(cpu->edi + 3u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0007E8BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E8BAu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 8u)) & 0xFFu);
    lift_store8(cpu->esi + 9u, (uint64_t)(lift_load8(cpu->esi + 9u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 0x11u, (uint64_t)(lift_load8(cpu->esi + 0x11u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 0x14u, (uint64_t)(lift_load8(cpu->esi + 0x14u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0xEu)) & 0xFFu);
    lift_store8(cpu->esi + 4u, (uint64_t)(lift_load8(cpu->esi + 4u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 5u, (uint64_t)(lift_load8(cpu->esi + 5u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 6u, (uint64_t)(lift_load8(cpu->esi + 6u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 7u, (uint64_t)(lift_load8(cpu->esi + 7u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    cpu->ebp += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E8E4u); lift_push32(cpu, r); sfera_sub_004DD810(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->ebp = lift_pop32(cpu);
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0007E8F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E8F2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFEu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E900u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ebx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47E91Eu); lift_push32(cpu, r); sfera_sub_004DD8E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007E92F;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0007E92F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E92Fu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx)) & 0xFFu);
    lift_store8(cpu->esi + 9u, (uint64_t)(lift_load8(cpu->esi + 9u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 0x11u, (uint64_t)(lift_load8(cpu->esi + 0x11u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 0x14u, (uint64_t)(lift_load8(cpu->esi + 0x14u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0xEu)) & 0xFFu);
    lift_store32(cpu->esi + 4u, cpu->ebp);
    lift_store8(cpu->esi + 4u, (uint64_t)(lift_load8(cpu->esi + 4u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 5u, (uint64_t)(lift_load8(cpu->esi + 5u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 6u, (uint64_t)(lift_load8(cpu->esi + 6u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store8(cpu->esi + 7u, (uint64_t)(lift_load8(cpu->esi + 7u)) ^ (uint64_t)((cpu->eax & 0xFFu)));
    lift_store32(cpu->esi, 0x52485053u);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E960u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)g_sfera_string_utility_runtime.format_buffer);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x47E96Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47E975u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_string_utility_runtime.format_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047E990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47E990u);
    cpu->ecx = 1u;
    if ((uint32_t)(g_sfera_string_utility_runtime.case_tables_initialized) == (uint32_t)(cpu->ecx)) goto label_0007EA11;
    cpu->eax = 0u;
    (void)cpu;
    label_0007E9A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E9A0u);
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)g_sfera_string_utility_runtime.lowercase), cpu->eax & 0xFFu);
    cpu->eax += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_0007E9A0;
    cpu->eax = 0u;
    label_0007E9B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x47E9B1u);
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)g_sfera_string_utility_runtime.uppercase), cpu->eax & 0xFFu);
    cpu->eax += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_0007E9B1;
    for (uint32_t letter = 'A'; letter <= 'Z'; ++letter) { LIFT_STORE8(letter + ((uint32_t)(uintptr_t)g_sfera_string_utility_runtime.lowercase), (uint8_t)(letter + ('a' - 'A'))); LIFT_STORE8(letter + ('a' - 'A') + ((uint32_t)(uintptr_t)g_sfera_string_utility_runtime.uppercase), (uint8_t)letter); }
    g_sfera_string_utility_runtime.case_tables_initialized = (uint32_t)(cpu->ecx);
    label_0007EA11: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA11u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA20u);
    { uint64_t l=(uint64_t)(g_sfera_string_utility_runtime.case_tables_initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007EA31;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7EA31u); lift_push32(cpu, r); sfera_sub_0047E990(cpu,r); if (cpu->eip != r) return; }
    label_0007EA31: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA31u);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_0007EA51;
    cpu->eax = cpu->esi;
    label_0007EA40: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA40u);
    cpu->ecx = lift_load8(cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(uintptr_t)g_sfera_string_utility_runtime.lowercase))) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0u)) goto label_0007EA40;
    label_0007EA51: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA51u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EA60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0007EA6B;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edx)) goto label_0007EA83;
    label_0007EA6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA6Bu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"check_index: wrong index %d, File:%s, Line:%d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EA80u); lift_push32(cpu, r); sfera_sub_0047E960(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0007EA83: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA83u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EA90u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_0007EAA4;
    cpu->eax += lift_load32(cpu->esp + 8u);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_0007EABC;
    label_0007EAA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EAA4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"check_pointer: wrong pointer or size %d, File:%s, Line:%d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EAB9u); lift_push32(cpu, r); sfera_sub_0047E960(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0007EABC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EABCu);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EAC0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_0007EAF1;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edx);
    cpu->ebp = (uint32_t)(cpu->esi + cpu->edi);
    if ((uint32_t)(cpu->ebp) > (uint32_t)(cpu->ecx)) goto label_0007EAF1;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->eax)) goto label_0007EAF1;
    cpu->ebp = (uint32_t)(cpu->ebx + cpu->edi);
    if ((uint32_t)(cpu->ebp) > (uint32_t)(cpu->ecx)) goto label_0007EAF1;
    if ((int32_t)(uint32_t)(cpu->edi) > 0) goto label_0007EB0D;
    label_0007EAF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EAF1u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"memmove_safe: pDest=%x, pSrc=%x, len=%d, pGuard=%x, guardLen=%d; File:%s, Line:%d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EB0Au); lift_push32(cpu, r); sfera_sub_0047E960(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x20u;
    label_0007EB0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EB0Du);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x47EB10u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47EB16u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EB20u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_0007EB5A;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (uint32_t)(cpu->esi + cpu->ebx);
    cpu->ebp += cpu->eax;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ebp)) goto label_0007EB5A;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ecx)) goto label_0007EB5A;
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    cpu->edx = (uint32_t)(cpu->edi + cpu->ebx);
    cpu->ebp += cpu->ecx;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ebp)) goto label_0007EB5A;
    if ((int32_t)(uint32_t)(cpu->ebx) > 0) goto label_0007EB80;
    label_0007EB5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EB5Au);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"memcpy_safe: pDest=%x, pSrc=%x, len=%d, pGuard1=%x, guardLen1=%d, pGuard2=%x, guardLen2=%d; File:%s, Line:%d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EB7Du); lift_push32(cpu, r); sfera_sub_0047E960(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x28u;
    label_0007EB80: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EB80u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47EB83u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47EB88u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EBA0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"check_error: FALSE, File:%s, Line:%d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EBACu); lift_push32(cpu, r); sfera_sub_0047E960(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EBB0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->edi;
    cpu->ebx = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_0007EBC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EBC0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007EBC0;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->edx = cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_0007EBD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EBD5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007EBD5;
    cpu->eax -= cpu->esi;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edx + 1u);
    lift_push32(cpu, 0xF3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EBF1u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx, cpu->eax);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_0007EBF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EBF7u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0007EBF7;
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    label_0007EC06: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EC06u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007EC06;
    cpu->edi = lift_load32(cpu->ebx);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0007EC12: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EC12u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007EC12;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EC40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EC40u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_0007EC50: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EC50u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007EC50;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007EC62: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EC62u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007EC62;
    cpu->eax -= cpu->edx;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_0007EC74: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EC74u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007EC74;
    cpu->eax -= cpu->esi;
    cpu->eax += cpu->ecx;
    lift_push32(cpu, 0xFBu);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EC92u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp, cpu->eax);
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007ECA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ECA0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0007ECA0;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax;
    label_0007ECB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ECB0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007ECB0;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    (void)cpu;
    label_0007ECC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ECC0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007ECC0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007ECE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ECE0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007ECE0;
    cpu->edi = lift_load32(cpu->ebp);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    (void)cpu;
    label_0007ECF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ECF0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007ECF0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047ED10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007ED2E;
    lift_push32(cpu, 0x103u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ED28u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, 0u);
    label_0007ED2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED2Eu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047ED30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED30u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047ED40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED40u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0007ED50: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED50u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007ED50;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x127u);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47ED6Bu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->eax;
    label_0007ED71: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED71u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0007ED71;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_0007ED82: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED82u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007ED82;
    cpu->eax -= cpu->edi;
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0007ED9B;
    label_0007ED90: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED90u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->eax)) == (uint8_t)(0x2Eu)) goto label_0007ED9B;
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_0007ED90;
    label_0007ED9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47ED9Bu);
    lift_store8(cpu->ecx + cpu->eax, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EDB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007EDCE;
    lift_push32(cpu, 0x130u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\miscell.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EDC8u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, 0u);
    label_0007EDCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EDCEu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EDD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EDD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x420u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47EDFCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47EE01u);
    cpu->esp += 0xCu;
    cpu->edx = 0x2Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EE13u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20018u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EE1Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007EE42;
    lift_push32(cpu, 0x4B0u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0x20u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EE40u); lift_push32(cpu, r); sfera_sub_00430F60(cpu,r); if (cpu->eip != r) return; }
    goto label_0007EE44;
    label_0007EE42: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EE42u);
    cpu->eax = 0u;
    label_0007EE44: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EE44u);
    cpu->edx = 0x2Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_store32(cpu->esi, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EE5Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EE64u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007EE80;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EE7Eu); lift_push32(cpu, r); sfera_sub_00480380(cpu,r); if (cpu->eip != r) return; }
    goto label_0007EE82;
    label_0007EE80: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EE80u);
    cpu->eax = 0u;
    label_0007EE82: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EE82u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"models\\mdlparam.txt");
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x404u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EE9Cu); lift_push32(cpu, r); sfera_sub_004803B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x31u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    cpu->ecx = 0x2580u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EEADu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x3F8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EEB8u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x410u, cpu->eax);
    lift_store32(cpu->esi + 0x414u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047EEE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47EEE0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x138u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x3ECu)) < (int32_t)(uint32_t)(0xAu)) goto label_0007EF30;
    cpu->ecx = (uint32_t)(uintptr_t)"ModelsMngr::register_folder: MAX_MDL_PATH_NUM exceeded";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7EF30u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007EF30: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EF30u);
    cpu->edi = lift_load32(cpu->esp + 0x15Cu);
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = 0u;
    cpu->edi = cpu->edi;
    label_0007EF40: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EF40u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0007EF40;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x64u)) goto label_0007EF58;
    cpu->ecx = (uint32_t)(uintptr_t)"ModelsMngr::register_folder: MAX_MDL_PATH_LEN exceeded";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7EF58u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007EF58: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EF58u);
    cpu->eax = lift_load32(cpu->esi + 0x3ECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->ecx = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + cpu->esi + 4u);
    cpu->ebp = 1u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007EF70: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EF70u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    cpu->ecx += cpu->ebp;
    cpu->edx += cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0007EF70;
    lift_store32(cpu->esi + 0x3ECu, (uint64_t)(lift_load32(cpu->esi + 0x3ECu)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 0x3ECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi + 0xFFFFFFA0u);
    lift_push32(cpu, (uintptr_t)"*.mdl"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EF9Eu); lift_push32(cpu, r); sfera_sub_0047EBB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x158u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EFB1u); lift_push32(cpu, r); sfera_sub_0047ED30(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x47EFB2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47EFB8u);
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->esp + 0x154u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47EFD5u); lift_push32(cpu, r); sfera_sub_0047ED10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F19A;
    cpu->edi = cpu->edi;
    label_0007EFE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47EFE0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x20u)), r=(uint64_t)(0x10u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007F108;
    cpu->eax = lift_load32(cpu->esi + 0x400u);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(4u), 32u);
    cpu->edi += lift_load32(cpu->esi + 0x3F8u);
    lift_push32(cpu, 0x30u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47F001u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47F006u);
    cpu->esp += 0xCu;
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F017u); lift_push32(cpu, r); sfera_sub_0047ED40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x154u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F025u); lift_push32(cpu, r); sfera_sub_0047ED30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0007F030: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F030u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    cpu->eax += cpu->ebp;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0007F030;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x154u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F04Fu); lift_push32(cpu, r); sfera_sub_0047EDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0007F054: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F054u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0007F054;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x20u)) goto label_0007F06C;
    cpu->ecx = (uint32_t)(uintptr_t)"Too long mdl name";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F06Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0007F06C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F06Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x3ECu);
    cpu->ecx -= cpu->ebp;
    lift_store32(cpu->edi + 0x20u, cpu->ecx);
    lift_store32(cpu->esi + 0x400u, (uint64_t)(lift_load32(cpu->esi + 0x400u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 0x400u);
    cpu->edx = lift_load32(cpu->esi + 0x3F4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F097u); lift_push32(cpu, r); sfera_sub_004311D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x400u)), r=(uint64_t)(0xC8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007F108;
    cpu->eax = lift_load32(cpu->esi + 0x3F4u);
    cpu->ecx = lift_load32(cpu->esi + 0x3F0u);
    lift_push32(cpu, 0x63u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u) + 0x258u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp");
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F0C5u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x400u);
    cpu->edx = lift_load32(cpu->esi + 0x3F8u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x3F4u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x3F0u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47F0EEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47F0F3u);
    cpu->edx = lift_load32(cpu->esi + 0x400u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x3F4u, (uint64_t)(lift_load32(cpu->esi + 0x3F4u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x400u, cpu->ebx);
    label_0007F108: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F108u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x47F112u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47F118u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007EFE0;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x47F124u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47F12Au);
    cpu->ecx = lift_load32(cpu->esi + 0x400u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0007F19A;
    cpu->eax = lift_load32(cpu->esi + 0x3F4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esi + 0x3F0u);
    lift_push32(cpu, 0x6Du);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp");
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F157u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x400u);
    cpu->edx = lift_load32(cpu->esi + 0x3F8u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x3F4u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x3F0u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x47F180u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47F185u);
    cpu->edx = lift_load32(cpu->esi + 0x400u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x3F4u, (uint64_t)(lift_load32(cpu->esi + 0x3F4u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    lift_store32(cpu->esi + 0x400u, cpu->ebx);
    label_0007F19A: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F19Au);
    cpu->ecx = lift_load32(cpu->esp + 0x14Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x144u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F1D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x3F4u)) < (int32_t)(uint32_t)(0x1388u)) goto label_0007F1EE;
    cpu->edx = 0x7Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F1EEu); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0007F1EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F1EEu);
    cpu->ecx = lift_load32(cpu->esi + 0x3F8u);
    lift_push32(cpu, 0x7Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F200u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F210u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F21Eu); lift_push32(cpu, r); sfera_sub_00430F20(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F230u);
    cpu->eax = 0x1388u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esp + 4u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F240u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007F265;
    lift_push32(cpu, 0xC2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F25Eu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x24u, 0u);
    label_0007F265: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F265u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007F288;
    lift_push32(cpu, 0xC3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F27Eu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1C8u, 0u);
    label_0007F288: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F288u);
    cpu->ecx = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007F2AB;
    lift_push32(cpu, 0xC4u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F2A1u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1CCu, 0u);
    label_0007F2AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F2ABu);
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007F2BF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x47F2B6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47F2BCu);
    cpu->esp += 4u;
    label_0007F2BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F2BFu);
    lift_push32(cpu, 0xC8u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F2D0u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F2E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F2E0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->ebx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x3F4u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0007F3B7;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    label_0007F301: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F301u);
    cpu->eax = lift_load32(cpu->ebp + 0x3F0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + cpu->eax + 0x24u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->edi + cpu->eax + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007F395;
    cpu->esi = lift_load32(cpu->edi);
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0007F330;
    lift_push32(cpu, 0xC2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F32Du); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    label_0007F330: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F330u);
    cpu->ecx = lift_load32(cpu->esi + 0x1C8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0007F34F;
    lift_push32(cpu, 0xC3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F349u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1C8u, cpu->ebx);
    label_0007F34F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F34Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x1CCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0007F36E;
    lift_push32(cpu, 0xC4u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F368u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x1CCu, cpu->ebx);
    label_0007F36E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F36Eu);
    cpu->eax = lift_load32(cpu->esi + 0x1D0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0007F382;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x47F379u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47F37Fu);
    cpu->esp += 4u;
    label_0007F382: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F382u);
    lift_push32(cpu, 0xC8u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F393u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->ebx);
    label_0007F395: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F395u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 0x30u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0x3F4u))) goto label_0007F301;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0007F3B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F3B7u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F3C0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F3CBu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x410u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x418u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += lift_load32(cpu->esi + 0x3F0u);
    lift_store32(cpu->esi + 0x414u, cpu->edx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x24u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->eax + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007F41E;
    cpu->ecx = lift_load32(cpu->esi + 0x410u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->eax + 0x28u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x414u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->eax + 0x2Cu)), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0007F41E;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0007F416;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0x895440u)) goto label_0007F41E;
    label_0007F416: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F416u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F41Eu); lift_push32(cpu, r); sfera_sub_0047F240(cpu,r); if (cpu->eip != r) return; }
    label_0007F41E: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F41Eu);
    lift_store32(cpu->esi + 0x418u, (uint64_t)(lift_load32(cpu->esi + 0x418u)) + 1u);
    cpu->eax = lift_load32(cpu->esi + 0x418u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x3F4u))) goto label_0007F43C;
    lift_store32(cpu->esi + 0x418u, 0u);
    label_0007F43C: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F43Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F450u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F459u); lift_push32(cpu, r); sfera_sub_0047F2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x3Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F468u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x404u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0007F482;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F479u); lift_push32(cpu, r); sfera_sub_00480390(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F47Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0007F482: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F482u);
    cpu->edx = 0x3Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F491u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0007F4A7;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F49Eu); lift_push32(cpu, r); sfera_sub_00430BC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F4A4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0007F4A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F4A7u);
    cpu->ecx = lift_load32(cpu->esi + 0x3F0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007F4C7;
    lift_push32(cpu, 0x3Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F4BDu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x3F0u, 0u);
    label_0007F4C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F4C7u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F4D0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_0007F4EE;
    cpu->ecx = (uint32_t)(uintptr_t)"get_model_by_id: id == -1";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F4E7u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0007F4EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F4EEu);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0x1388u)) goto label_0007F4FD;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0007F4FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F4FDu);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_0007F509;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x3F4u))) goto label_0007F518;
    label_0007F509: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F509u);
    cpu->edx = 0x9Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ModelsMngr.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F518u); lift_push32(cpu, r); sfera_sub_0047EBA0(cpu,r); if (cpu->eip != r) return; }
    label_0007F518: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F518u);
    cpu->eax = lift_load32(cpu->esi + 0x3F0u);
    cpu->ecx = lift_load32(cpu->esi + 0x410u);
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->edi += cpu->edi;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 0x28u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x414u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 0x2Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x3F0u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + 0x24u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->edx + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007F560;
    cpu->eax = lift_load32(cpu->esi + 0x404u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x20u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F560u); lift_push32(cpu, r); sfera_sub_00465B80(cpu,r); if (cpu->eip != r) return; }
    label_0007F560: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F560u);
    lift_store32(cpu->esi + 0x408u, (uint64_t)(lift_load32(cpu->esi + 0x408u)) + 1u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x408u)) <= (int32_t)(uint32_t)(0x186A0u)) goto label_0007F583;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x408u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F583u); lift_push32(cpu, r); sfera_sub_0047F3C0(cpu,r); if (cpu->eip != r) return; }
    label_0007F583: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F583u);
    cpu->ecx = lift_load32(cpu->esi + 0x3F0u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 0x24u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F5A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F5A0u);
    cpu->eax = g_sfera_nature_runtime.manager;
    lift_store32(cpu->eax + 0x1Cu, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F5C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F5C0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F5E2u); lift_push32(cpu, r); sfera_sub_00426180(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F5EDu); lift_push32(cpu, r); sfera_sub_00426160(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->eax + 0x5Cu)) > (uint32_t)(0u)) goto label_0007F5F7;
    cpu->esi = 0u;
    goto label_0007F5FA;
    label_0007F5F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F5F7u);
    cpu->esi = lift_load32(cpu->eax + 4u);
    label_0007F5FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F5FAu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F606u); lift_push32(cpu, r); sfera_sub_00455E40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    lift_store32(cpu->edi + 0x14u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->edi + 0x18u, cpu->edx);
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
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F665u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    lift_x87_pop(cpu);
    cpu->ecx = 0x13BCu;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0007F687;
    cpu->ecx = 0x13BBu;
    label_0007F687: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F687u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F68Cu); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esp += 0x20u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F6B0u);
    cpu->eax = g_sfera_nature_runtime.manager;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F6C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F6C0u);
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F6DB;
    cpu->ecx = 0x190u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F6D8u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    label_0007F6DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F6DBu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F6E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi |= 0xFFFFFFFFu;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0007F6F3;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F6F3u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    label_0007F6F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F6F3u);
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0007F705;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F702u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    label_0007F705: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F705u);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0007F714;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F711u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    label_0007F714: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F714u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0007F723;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F720u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    label_0007F723: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F723u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F730u);
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F74B;
    cpu->ecx = 0x19Au;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F748u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    label_0007F74B: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F74Bu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F750u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F760;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F760u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    label_0007F760: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F760u);
    lift_store32(cpu->esi + 0x28u, 0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F770u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x1Cu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0007F7AC;
    if ((uint32_t)(g_sfera_world_objects.controlled_object_handle) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F7AC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (640.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (320.0));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F7A2u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F7ACu); lift_push32(cpu, r); sfera_sub_00425F40(cpu,r); if (cpu->eip != r) return; }
    label_0007F7AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F7ACu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F7B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F7B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_nature_runtime.manager;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F7CC;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F7C5u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2Cu, 0xFFFFFFFFu);
    label_0007F7CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F7CCu);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F7E0;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F7D9u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x30u, 0xFFFFFFFFu);
    label_0007F7E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F7E0u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F807;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F7EDu); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_nature_runtime.manager;
    lift_store32(cpu->esi + 0x34u, 0xFFFFFFFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x10u, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0007F807: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F807u);
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F820u);
    cpu->eax = g_sfera_nature_runtime.manager;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007F834;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0007F834: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F834u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) == (uint32_t)(1u)) goto label_0007F857;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown effect classID for lighting.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F849u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F84Fu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_nature_runtime.manager;
    cpu->esp += 8u;
    label_0007F857: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F857u);
    lift_store32(cpu->eax + 0x1Cu, cpu->esi);
    if ((uint32_t)(g_sfera_world_objects.controlled_object_handle) == (uint32_t)(0xFFFFFFFFu)) goto label_0007F88D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (640.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (320.0));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F883u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7F88Du); lift_push32(cpu, r); sfera_sub_00425F40(cpu,r); if (cpu->eip != r) return; }
    label_0007F88D: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F88Du);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->edi + 4u, 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F8A0u);
    lift_x87_push(cpu, (double)0.5f);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 4u, cpu->ebx);
    std::construct_at(reinterpret_cast<NatureRainListener*>(cpu->esi));
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    std::construct_at(reinterpret_cast<LightingListener*>(cpu->esi + 8u));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u));
    cpu->eax = 0u;
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = 0x190u;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    lift_store32(cpu->esi + 0x28u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F8E1u); lift_push32(cpu, r); sfera_sub_0042AA90(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    cpu->ecx = 0x19Au;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F8EEu); lift_push32(cpu, r); sfera_sub_0042AA90(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x30u, cpu->ebx);
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047F900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47F900u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007F926;
    cpu->ecx = lift_load32(cpu->esi + 0x2Cu);
    cpu->edi |= 0xFFFFFFFFu;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0007F957;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F921u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    goto label_0007F957;
    label_0007F926: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F926u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_push(cpu, 0.4000000059604645);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0007F968;
    cpu->edi |= 0xFFFFFFFFu;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) != (uint32_t)(cpu->edi)) goto label_0007F957;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F954u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    label_0007F957: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F957u);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0007F9B7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F963u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    goto label_0007F9B7;
    label_0007F968: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F968u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0007F9C9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.800000011920929);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0007F9C9;
    cpu->edi |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) != (uint32_t)(cpu->edi)) goto label_0007F99F;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F99Cu); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    label_0007F99F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F99Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) != (uint32_t)(cpu->edi)) goto label_0007F9B7;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F9B4u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    label_0007F9B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F9B7u);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0007FA14;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F9C3u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0007F9C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F9C9u);
    cpu->edi |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) != (uint32_t)(cpu->edi)) goto label_0007F9E4;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F9E1u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    label_0007F9E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F9E4u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) != (uint32_t)(cpu->edi)) goto label_0007F9FC;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47F9F9u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    label_0007F9FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47F9FCu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x34u)) != (uint32_t)(cpu->edi)) goto label_0007FA14;
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    cpu->ecx = 0x13BAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FA11u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x34u, cpu->eax);
    label_0007FA14: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FA14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FA20u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007FA42;
    if ((uint32_t)(g_sfera_world_objects.controlled_object_handle) == (uint32_t)(0xFFFFFFFFu)) goto label_0007FA42;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0x18u))));
    lift_store_f32(cpu->eax + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7FA42u); lift_push32(cpu, r); sfera_sub_0047F900(cpu,r); if (cpu->eip != r) return; }
    label_0007FA42: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FA42u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FA50u);
    cpu->ecx = g_sfera_nature_runtime.manager;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x10u)) == (uint32_t)(0u)) goto label_0007FA61;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 12u, stop_address); return;
    label_0007FA61: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FA61u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) == (uint32_t)(3u)) goto label_0007FA85;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown effect classID for rain.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FA76u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FA7Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->esp += 8u;
    label_0007FA85: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FA85u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(uintptr_t)"rain";
    lift_push32(cpu, cpu->ebx);
    cpu->edi = cpu->edi;
    label_0007FA90: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FA90u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007FAB0;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0007FAAC;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007FAB0;
    cpu->eax += 2u;
    cpu->edx += 2u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_0007FA90;
    label_0007FAAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FAACu);
    cpu->eax = 0u;
    goto label_0007FAB5;
    label_0007FAB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FAB0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0007FAB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FAB5u);
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007FAD3;
    lift_push32(cpu, (uint32_t)(uintptr_t)"Unknown effect manager for 'rain' not found.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FAC4u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FACAu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->esp += 8u;
    label_0007FAD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FAD3u);
    lift_x87_push(cpu, (double)60.0f);
    lift_store32(cpu->ecx + 0x10u, cpu->esi);
    lift_store_f32(cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(g_sfera_world_objects.controlled_object_handle), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0007FB09;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (60.0));
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x7FB09u); lift_push32(cpu, r); sfera_sub_0047F900(cpu,r); if (cpu->eip != r) return; }
    label_0007FB09: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FB09u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FB10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    if ((uint32_t)(g_sfera_nature_runtime.manager) != (uint32_t)(0u)) goto label_0007FB86;
    cpu->edx = 0xA6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\NatureManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FB49u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FB50u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0007FB7F;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FB6Au); lift_push32(cpu, r); sfera_sub_0047F8A0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_nature_runtime.manager = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007FB7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FB7Fu);
    cpu->eax = 0u;
    g_sfera_nature_runtime.manager = (uint32_t)(cpu->eax);
    label_0007FB86: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FB86u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FBA0u);
    if ((uint32_t)(g_sfera_nature_runtime.manager) == (uint32_t)(0u)) goto label_0007FBE6;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0xB0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\NatureManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FBB9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_nature_runtime.manager;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0007FBDB;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FBCAu); lift_push32(cpu, r); sfera_sub_00429990(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FBD2u); lift_push32(cpu, r); sfera_sub_00429990(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FBD8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0007FBDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FBDBu);
    g_sfera_nature_runtime.manager = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    label_0007FBE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FBE6u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FBF0u);
    cpu->esp -= 0x45Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x44u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x47FC10u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FC15u);
    cpu->ebx = native_function_address32(&::timeGetTime);
    cpu->eax = 0u;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x20u, 0x44u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7FC3Au), LIFT_CODE_TOKEN_RVA(0x7FC38u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FC3Au);
    lift_push32(cpu, 0x400u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebp = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::GetSystemDirectoryA), LIFT_CODE_TOKEN_VA(0x47FC46u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FC4Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    --cpu->eax;
    label_0007FC51: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FC51u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007FC51;
    cpu->edx = lift_load32((uintptr_t)"\\ping.exe -n 1 ");
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"\\ping.exe -n 1 ") + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"\\ping.exe -n 1 ") + 8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"\\ping.exe -n 1 ") + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->eax = (uint32_t)(uintptr_t)g_sfera_network_probe_runtime.host;
    cpu->edx = cpu->eax;
    label_0007FC83: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FC83u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0007FC83;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esp + 0x68u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0007FC92: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FC92u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007FC92;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 0u);
    cpu->ecx &= 3u;
    lift_push32(cpu, 0u);
    lift_movs8(cpu, 1u);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateProcessA), LIFT_CODE_TOKEN_VA(0x47FCCDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FCD3u);
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0007FD07;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x47FCD8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FCDEu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CreateProcess error: %d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FCE9u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0007FCEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FCECu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0007FD07: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD07u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0x7530u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::WaitForSingleObject), LIFT_CODE_TOKEN_VA(0x47FD11u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD17u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x102u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0007FD51;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateProcess), LIFT_CODE_TOKEN_VA(0x47FD25u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD2Bu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x47FD30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD36u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0007FD51: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD51u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeProcess), LIFT_CODE_TOKEN_VA(0x47FD57u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD5Du);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x47FD64u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD6Au);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0007FCEC;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(1u)) goto label_0007FD96;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFEu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0007FD96: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD96u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x7FD98u), LIFT_CODE_TOKEN_RVA(0x7FD96u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FD98u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax -= cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x45Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FDC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FDC0u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0007FDD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FDD0u);
    cpu->esi = 0u;
    label_0007FDD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FDD2u);
    lift_push32(cpu, 0xC8u);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x47FDD7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FDDDu);
    if ((uint8_t)(g_sfera_network_probe_runtime.stop_requested) == (uint8_t)(1u)) goto label_0007FE97;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x14u)) goto label_0007FDD2;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x47FDF5u); lift_push32(cpu, r); sfera_sub_0047FBF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->esi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x47FDF9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FDFFu);
    cpu->ecx = g_sfera_network_probe_runtime.context_b;
    cpu->ebx = g_sfera_network_probe_runtime.context_a;
    cpu->esp += 4u;
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_network_probe_runtime.context_c;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x47FE24u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FE2Au);
    lift_push32(cpu, 0x1C8u); lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.samples[0]); lift_push32(cpu, (uintptr_t)&g_sfera_network_probe_runtime.samples[1]);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x47FE39u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FE3Fu);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32((uintptr_t)&g_sfera_network_probe_runtime.samples[0].context_c, cpu->eax);
    cpu->eax = g_sfera_network_probe_runtime.sample_count;
    ++cpu->eax;
    cpu->esp += 0xCu;
    g_sfera_network_probe_runtime.samples[0].timestamp.low = (uint32_t)(cpu->edi);
    lift_store32((uintptr_t)&g_sfera_network_probe_runtime.samples[0].timestamp.high, cpu->ebp);
    lift_store32((uintptr_t)&g_sfera_network_probe_runtime.samples[0].probe_result, cpu->esi);
    lift_store32((uintptr_t)&g_sfera_network_probe_runtime.samples[0].context_a, cpu->ebx);
    lift_store32((uintptr_t)&g_sfera_network_probe_runtime.samples[0].context_b, cpu->edx);
    g_sfera_network_probe_runtime.sample_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x14u)) goto label_0007FE87;
    g_sfera_network_probe_runtime.sample_count = (uint32_t)(0x14u);
    label_0007FE87: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FE87u);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x47FE8Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FE92u);
    goto label_0007FDD0;
    label_0007FE97: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FE97u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FEB0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    g_sfera_network_probe_runtime.context_a = (uint32_t)(cpu->ecx);
    g_sfera_network_probe_runtime.context_c = (uint32_t)(cpu->edx);
    g_sfera_network_probe_runtime.context_b = (uint32_t)(cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FED0u);
    cpu->esp -= 0x8Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0007FEF6;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_0007FEF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FEF6u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"Net.log";
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x47FEFDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF03u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0007FF56;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x47FF12u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x47FF1Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF23u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m %H:%M:%S ");
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x47FF33u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF39u);
    cpu->edi = native_function_address32(&::fputs);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x7FF47u), LIFT_CODE_TOKEN_RVA(0x7FF45u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF47u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x7FF4Bu), LIFT_CODE_TOKEN_RVA(0x7FF49u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF4Bu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x47FF4Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF52u);
    cpu->esp += 0x2Cu;
    cpu->edi = lift_pop32(cpu);
    label_0007FF56: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF56u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x8Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0047FF70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF70u);
    cpu->esp -= 0x104u;
    cpu->eax = (uint32_t)(uintptr_t)"Net.log";
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x47FF90u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FF96u);
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_0007FFB5;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x104u;
    lift_return(cpu, 0u, stop_address); return;
    label_0007FFB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x47FFB5u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x47FFBCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FFC2u);
    cpu->ecx = 0x78u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_network_probe_runtime.samples[0];
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_network_probe_runtime.snapshot[0];
    lift_movs32(cpu, 1u);
    cpu->ecx = g_sfera_network_probe_runtime.sample_count;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    g_sfera_network_probe_runtime.snapshot_count = (uint32_t)(cpu->ecx);
    g_sfera_network_probe_runtime.sample_count = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x47FFEEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x47FFF4u);
    cpu->edi = g_sfera_network_probe_runtime.snapshot_count;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00080069;
    cpu->esi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fputs);
    cpu->esi = (uint32_t)(((uint32_t)(cpu->esi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_network_probe_runtime.snapshot[0].context_a));
    cpu->edi = cpu->edi;
    label_00080010: cpu->eip = LIFT_CODE_TOKEN_VA(0x480010u);
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFF4u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x480014u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48001Au);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d/%m %H:%M:%S ");
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x48002Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480030u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x80038u), LIFT_CODE_TOKEN_RVA(0x80036u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480038u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d\n"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480051u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480057u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8005Fu), LIFT_CODE_TOKEN_RVA(0x8005Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48005Fu);
    cpu->esp += 0x3Cu;
    cpu->esi -= 0x18u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00080010;
    cpu->ebx = lift_pop32(cpu);
    label_00080069: cpu->eip = LIFT_CODE_TOKEN_VA(0x480069u);
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x48006Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480070u);
    cpu->eax = g_sfera_network_probe_runtime.snapshot_count;
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x104u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480090u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    cpu->eax = cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)g_sfera_network_probe_runtime.host;
    g_sfera_network_probe_runtime.sample_count = (uint32_t)(cpu->ebx);
    cpu->edx -= cpu->eax;
    label_000800A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4800A3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000800A3;
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x4800B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4800B8u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0047FDC0)); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    g_sfera_network_probe_runtime.stop_requested = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_probe_runtime.context_a = (uint32_t)(cpu->ebx);
    g_sfera_network_probe_runtime.context_c = (uint32_t)(cpu->ebx);
    g_sfera_network_probe_runtime.context_b = (uint32_t)(cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x4800DEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4800E4u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_network_probe_runtime.thread_handle = (uint32_t)(cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00080102;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4800EEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4800F4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CreateThread error: %d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4800FFu); lift_push32(cpu, r); sfera_sub_004623C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00080102: cpu->eip = LIFT_CODE_TOKEN_VA(0x480102u);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480110u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::GetExitCodeThread);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::Sleep);
    lift_store8(cpu->esp + 0xCu, cpu->ecx & 0xFFu);
    g_sfera_network_probe_runtime.stop_requested = (uint8_t)(1u);
    cpu->esi = 0u;
    (void)cpu;
    label_00080130: cpu->eip = LIFT_CODE_TOKEN_VA(0x480130u);
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000801A3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x80149u), LIFT_CODE_TOKEN_RVA(0x80147u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480149u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080161;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) != (uint32_t)(0x103u)) goto label_00080161;
    lift_push32(cpu, 7u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8015Bu), LIFT_CODE_TOKEN_RVA(0x80159u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48015Bu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x28u)) goto label_00080130;
    label_00080161: cpu->eip = LIFT_CODE_TOKEN_VA(0x480161u);
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000801A3;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x8017Au), LIFT_CODE_TOKEN_RVA(0x80178u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48017Au);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000801A3;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) != (uint32_t)(0x103u)) goto label_000801A3;
    cpu->eax = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x480190u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480196u);
    cpu->ecx = g_sfera_network_probe_runtime.thread_handle;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x8019Du));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x801A3u);
    label_000801A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4801A3u);
    lift_push32(cpu, (uint32_t)(uintptr_t)g_sfera_network_probe_runtime.critical_section_words);
    lift_native_call(cpu, native_function_address32(&::DeleteCriticalSection), LIFT_CODE_TOKEN_VA(0x4801A8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4801AEu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000801CE;
    cpu->edx = (uintptr_t)"NetError.log";
    cpu->eax = (uint32_t)(uintptr_t)"Net.log";
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x4801C5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4801CBu);
    cpu->esp += 8u;
    label_000801CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4801CEu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004801E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4801E0u);
    cpu->eax = g_sfera_network_connection_checker.instance;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080217;
    cpu->edx = (uint32_t)(cpu->eax + 0x1Eu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\NetworkConnectionChecker.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4801F6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4801FDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080210;
    lift_store32(cpu->eax, 0u);
    g_sfera_network_connection_checker.instance = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
    label_00080210: cpu->eip = LIFT_CODE_TOKEN_VA(0x480210u);
    cpu->eax = 0u;
    g_sfera_network_connection_checker.instance = (uint32_t)(cpu->eax);
    label_00080217: cpu->eip = LIFT_CODE_TOKEN_VA(0x480217u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480220(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480220u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::Sleep);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00080230: cpu->eip = LIFT_CODE_TOKEN_VA(0x480230u);
    lift_push32(cpu, 0xB8u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x2BF20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x17u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_store8(cpu->esp + 0x1Bu, 5u);
    lift_store32(cpu->esp + 0x20u, 1u);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x80272u), LIFT_CODE_TOKEN_RVA(0x80270u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480272u);
    lift_push32(cpu, 0x7D0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x80279u), LIFT_CODE_TOKEN_RVA(0x80277u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480279u);
    goto label_00080230;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480280u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000802AE;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x48029Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4802A0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000802AE;
    if ((uint32_t)(lift_load32(cpu->esp + 4u)) == (uint32_t)(0x103u)) goto label_000802ED;
    label_000802AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4802AEu);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00480220)); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x4802C0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4802C6u);
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000802ED;
    cpu->ecx = (uint32_t)(uintptr_t)"CClNetworkConnectionChecker::Start(): CreateThread error: ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4802D6u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4802D6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4802DCu);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4802E3u); lift_push32(cpu, r); sfera_sub_0044BEC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x802EDu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    label_000802ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4802EDu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480300u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->edx = 0x26u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\NetworkConnectionChecker.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480311u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_network_connection_checker.instance;
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080367;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008035E;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_native_call(cpu, native_function_address32(&::GetExitCodeThread), LIFT_CODE_TOKEN_VA(0x480330u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480336u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008035E;
    if ((uint32_t)(lift_load32(cpu->esp + 4u)) != (uint32_t)(0x103u)) goto label_0008035E;
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::TerminateThread), LIFT_CODE_TOKEN_VA(0x480349u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48034Fu);
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x480352u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480358u);
    lift_store32(cpu->esi, 0u);
    label_0008035E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48035Eu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480364u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00080367: cpu->eip = LIFT_CODE_TOKEN_VA(0x480367u);
    g_sfera_network_connection_checker.instance = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480380u);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->eax, 0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480390u);
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000803A2;
    lift_push32(cpu, 0x18u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x803A2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_000803A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4803A2u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004803B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4803B0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4803C0u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000803D1;
    cpu->ecx = (uint32_t)(uintptr_t)"CObjParamManager::Open: object already initialized";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x803D1u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000803D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4803D1u);
    lift_push32(cpu, 0x21u);
    cpu->ecx = (uint32_t)(cpu->esi + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4803E0u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = cpu->ebx;
    lift_store8(cpu->eax + cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4803EFu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4803FBu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480402u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480410u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0008041C;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0xDu)) goto label_0008041C;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_0008041C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48041Cu);
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480430u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00080494;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebp = native_function_address32(&::_stricmp);
    label_00080446: cpu->eip = LIFT_CODE_TOKEN_VA(0x480446u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xDu)) goto label_0008044F;
    cpu->edi += 2u;
    goto label_0008048E;
    label_0008044F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48044Fu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_00080481;
    cpu->esi = cpu->edi;
    label_00080455: cpu->eip = LIFT_CODE_TOKEN_VA(0x480455u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00080461;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xDu)) goto label_0008046B;
    label_00080461: cpu->eip = LIFT_CODE_TOKEN_VA(0x480461u);
    cpu->ecx = (uint32_t)(uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8046Bu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008046B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48046Bu);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x20u)) goto label_00080455;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x80477u), LIFT_CODE_TOKEN_RVA(0x80475u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480477u);
    cpu->esp += 8u;
    lift_store8(cpu->esi, 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008049D;
    label_00080481: cpu->eip = LIFT_CODE_TOKEN_VA(0x480481u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48048Au); lift_push32(cpu, r); sfera_sub_00480410(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00080481;
    label_0008048E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48048Eu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00080446;
    label_00080494: cpu->eip = LIFT_CODE_TOKEN_VA(0x480494u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0008049D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48049Du);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_000804A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4804A1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000804AD;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xDu)) goto label_000804B7;
    label_000804AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4804ADu);
    cpu->ecx = (uint32_t)(uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x804B7u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000804B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4804B7u);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x20u)) goto label_000804A1;
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->edi;
    label_000804C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4804C0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_000804D8;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Cu)) goto label_000804D8;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x3Du)) goto label_000804D8;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000804D8;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xDu)) goto label_000804C0;
    label_000804D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4804D8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esi, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x804E1u), LIFT_CODE_TOKEN_RVA(0x804DFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4804E1u);
    cpu->esp += 8u;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008050A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->ebx & 0xFFu)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Cu)) goto label_000804A1;
    label_000804F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4804F0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000805BF;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xDu)) goto label_000805BF;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Cu)) goto label_000804F0;
    goto label_000804A1;
    label_0008050A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48050Au);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000805B3;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == (uint8_t)(0x2Cu)) goto label_00080524;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_00080524;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(0xDu)) goto label_0008052E;
    label_00080524: cpu->eip = LIFT_CODE_TOKEN_VA(0x480524u);
    cpu->ecx = (uint32_t)(uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8052Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008052E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48052Eu);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x20u)) goto label_00080539;
    label_00080533: cpu->eip = LIFT_CODE_TOKEN_VA(0x480533u);
    ++cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x20u)) goto label_00080533;
    label_00080539: cpu->eip = LIFT_CODE_TOKEN_VA(0x480539u);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x3Du)) goto label_00080548;
    cpu->ecx = (uint32_t)(uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80548u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080548: cpu->eip = LIFT_CODE_TOKEN_VA(0x480548u);
    ++cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x20u)) goto label_00080556;
    cpu->edi = cpu->edi;
    label_00080550: cpu->eip = LIFT_CODE_TOKEN_VA(0x480550u);
    ++cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x20u)) goto label_00080550;
    label_00080556: cpu->eip = LIFT_CODE_TOKEN_VA(0x480556u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080566;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%f");
    goto label_0008059A;
    label_00080566: cpu->eip = LIFT_CODE_TOKEN_VA(0x480566u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00080594;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->ecx = cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Cu)) goto label_00080585;
    label_00080573: cpu->eip = LIFT_CODE_TOKEN_VA(0x480573u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00080585;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xDu)) goto label_00080585;
    ++cpu->esi;
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Cu)) goto label_00080573;
    label_00080585: cpu->eip = LIFT_CODE_TOKEN_VA(0x480585u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->ecx, 0u);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00080594: cpu->eip = LIFT_CODE_TOKEN_VA(0x480594u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d");
    label_0008059A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48059Au);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x48059Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4805A1u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000805B3;
    cpu->ecx = (uint32_t)(uintptr_t)"CObjParamManager::GetObjParam: wrong file format";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x805B3u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000805B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4805B3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_000805BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4805BFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 2u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004805D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4805D0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00080624;
    cpu->edi = (uint32_t)(cpu->esi + 1u);
    (void)cpu;
    label_000805E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4805E0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Fu)) goto label_000805F4;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 1u)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_000805F4;
    cpu->edx += 2u;
    lift_store32(cpu->ecx, cpu->edx);
    cpu->esi = cpu->edi;
    goto label_0008061C;
    label_000805F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4805F4u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00080606;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_0008061A;
    g_sfera_config_parser_runtime.line_number += cpu->edi;
    cpu->esi = 0u;
    goto label_0008061A;
    label_00080606: cpu->eip = LIFT_CODE_TOKEN_VA(0x480606u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_00080612;
    g_sfera_config_parser_runtime.line_number += cpu->edi;
    goto label_0008061A;
    label_00080612: cpu->eip = LIFT_CODE_TOKEN_VA(0x480612u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_0008061A;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xDu)) goto label_00080629;
    label_0008061A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48061Au);
    lift_store32(cpu->ecx, (uint64_t)(lift_load32(cpu->ecx)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    label_0008061C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48061Cu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000805E0;
    label_00080624: cpu->eip = LIFT_CODE_TOKEN_VA(0x480624u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00080629: cpu->eip = LIFT_CODE_TOKEN_VA(0x480629u);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480630u);
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480641u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480647u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    sfera_sub_00459B10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480660u);
    cpu->esp -= 8u;
    lift_store32(cpu->esp, cpu->ecx);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    cpu->ebx = 0u;
    g_sfera_config_parser_runtime.line_number = (uint32_t)(1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48067Cu); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080E8B;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_00080687: cpu->eip = LIFT_CODE_TOKEN_VA(0x480687u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x7Du)) goto label_0008078A;
    cpu->esi = g_sfera_config_parser_runtime.frame_depth;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000806CA;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x24u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4806B1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4806B7u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4806C4u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_config_parser_runtime.frame_depth;
    label_000806CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4806CAu);
    --cpu->esi;
    g_sfera_config_parser_runtime.frame_depth = (uint32_t)(cpu->esi);
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    ++cpu->edi;
    ++cpu->ebx;
    { uint64_t l=(uint64_t)(lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00080E77;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4806F1u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080E77;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x2Cu)) goto label_00080E77;
    cpu->edi = 1u;
    g_sfera_config_parser_runtime.frame_depth += cpu->edi;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end), cpu->edi);
    cpu->ebx += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480728u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080752;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x25u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x48073Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480745u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80752u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080752: cpu->eip = LIFT_CODE_TOKEN_VA(0x480752u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x7Bu)) goto label_00080781;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x26u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x48076Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480774u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80781u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080781: cpu->eip = LIFT_CODE_TOKEN_VA(0x480781u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    goto label_00080E77;
    label_0008078A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48078Au);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_00080792;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_000807C4;
    label_00080792: cpu->eip = LIFT_CODE_TOKEN_VA(0x480792u);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_0008079A;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_000807C4;
    label_0008079A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48079Au);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x5Fu)) goto label_000807C4;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4807B1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4807B7u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x807C4u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000807C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4807C4u);
    cpu->esi = native_function_address32(&::sprintf);
    cpu->ebp = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000807D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4807D0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store8(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.token[0]), cpu->eax & 0xFFu);
    ++cpu->ebp;
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(0xFAu)) goto label_00080804;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x807F7u), LIFT_CODE_TOKEN_RVA(0x807F5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4807F7u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80804u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080804: cpu->eip = LIFT_CODE_TOKEN_VA(0x480804u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_0008080E;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_000807D0;
    label_0008080E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48080Eu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_00080816;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_000807D0;
    label_00080816: cpu->eip = LIFT_CODE_TOKEN_VA(0x480816u);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_0008081E;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_000807D0;
    label_0008081E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48081Eu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x5Fu)) goto label_000807D0;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store8(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.token[0]), 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480836u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008085C;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x8084Fu), LIFT_CODE_TOKEN_RVA(0x8084Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48084Fu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8085Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008085C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48085Cu);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edi)) == (uint8_t)(0x3Cu)) goto label_00080886;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 5u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x80879u), LIFT_CODE_TOKEN_RVA(0x80877u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480879u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80886u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080886: cpu->eip = LIFT_CODE_TOKEN_VA(0x480886u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    cpu->esi = 0u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x61u)) goto label_00080894;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x41u)) goto label_0008089A;
    label_00080894: cpu->eip = LIFT_CODE_TOKEN_VA(0x480894u);
    cpu->esi = 0x80u;
    ++cpu->edi;
    label_0008089A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48089Au);
    cpu->eax = (int8_t)(lift_load8(cpu->edi));
    cpu->eax += 0xFFFFFFBAu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x2Fu)) goto label_000808C5;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: case 32u: goto label_000808B3;
        case 3u: case 35u: goto label_000808EB;
        case 13u: case 45u: goto label_000808C0;
        case 14u: case 46u: goto label_000808B6;
        case 15u: case 47u: goto label_000808BB;
        default: goto label_000808C5;
    }
label_000808B3: ;
    ++cpu->esi;
    goto label_000808EB;
    label_000808B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4808B6u);
    cpu->esi += 2u;
    goto label_000808EB;
    label_000808BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4808BBu);
    cpu->esi += 3u;
    goto label_000808EB;
    label_000808C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4808C0u);
    cpu->esi += 4u;
    goto label_000808EB;
    label_000808C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4808C5u);
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4808D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4808DEu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x808EBu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000808EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4808EBu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x83u)) goto label_00080918;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480905u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48090Bu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80918u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080918: cpu->eip = LIFT_CODE_TOKEN_VA(0x480918u);
    if ((uint8_t)(lift_load8(cpu->edi + 1u)) == (uint8_t)(0x3Eu)) goto label_00080944;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480931u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480937u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80944u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080944: cpu->eip = LIFT_CODE_TOKEN_VA(0x480944u);
    cpu->edi += 2u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480954u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = native_function_address32(&::sprintf);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080980;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 9u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80973u), LIFT_CODE_TOKEN_RVA(0x80971u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480973u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80980u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080980: cpu->eip = LIFT_CODE_TOKEN_VA(0x480980u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x3Du)) goto label_000809AB;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xAu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8099Eu), LIFT_CODE_TOKEN_RVA(0x8099Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48099Eu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x809ABu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000809AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4809ABu);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4809B8u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000809DE;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xBu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x809D1u), LIFT_CODE_TOKEN_RVA(0x809CFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4809D1u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x809DEu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000809DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4809DEu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00080E2F;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x80u)) goto label_00080A9E;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080A00;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080A25;
    label_00080A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x480A00u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_00080A25;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80A18u), LIFT_CODE_TOKEN_RVA(0x80A16u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480A18u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80A25u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080A25: cpu->eip = LIFT_CODE_TOKEN_VA(0x480A25u);
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 0xAu);
    goto label_00080A34;
    label_00080A30: cpu->eip = LIFT_CODE_TOKEN_VA(0x480A30u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_00080A34: cpu->eip = LIFT_CODE_TOKEN_VA(0x480A34u);
    cpu->ebx += 4u;
    label_00080A37: cpu->eip = LIFT_CODE_TOKEN_VA(0x480A37u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080A43;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080A37;
    label_00080A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x480A43u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480A50u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080E77;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x2Cu)) goto label_00080E77;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480A72u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080A30;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x11u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480A89u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480A8Fu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480A9Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00080A30;
    label_00080A9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x480A9Eu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(1u)) goto label_00080AF9;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080AB1;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080ADA;
    label_00080AB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x480AB1u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00080ADA;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_00080ADA;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x12u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80ACDu), LIFT_CODE_TOKEN_RVA(0x80ACBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480ACDu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80ADAu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080ADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x480ADAu);
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 7u);
    cpu->edi = cpu->edi;
    label_00080AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x480AE0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080AEC;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080AE0;
    label_00080AEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x480AECu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00080AE0;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    goto label_00080E77;
    label_00080AF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x480AF9u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x81u)) goto label_00080BA2;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080B13;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080B25;
    label_00080B13: cpu->eip = LIFT_CODE_TOKEN_VA(0x480B13u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00080B25;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_00080B25;
    cpu->ecx = 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80B25u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080B25: cpu->eip = LIFT_CODE_TOKEN_VA(0x480B25u);
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 0xAu);
    goto label_00080B34;
    label_00080B30: cpu->eip = LIFT_CODE_TOKEN_VA(0x480B30u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_00080B34: cpu->eip = LIFT_CODE_TOKEN_VA(0x480B34u);
    cpu->ebx += 4u;
    label_00080B37: cpu->eip = LIFT_CODE_TOKEN_VA(0x480B37u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080B43;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080B37;
    label_00080B43: cpu->eip = LIFT_CODE_TOKEN_VA(0x480B43u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00080B37;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480B54u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080E77;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x2Cu)) goto label_00080E77;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480B76u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080B30;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x16u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480B8Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480B93u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480BA0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00080B30;
    label_00080BA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x480BA2u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(2u)) goto label_00080BFF;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x22u)) goto label_00080BBA;
    cpu->ecx = 0x17u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80BBAu); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080BBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x480BBAu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 5u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x22u)) goto label_00080BF4;
    label_00080BC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x480BC6u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00080BEB;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x18u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80BDEu), LIFT_CODE_TOKEN_RVA(0x80BDCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480BDEu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80BEBu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080BEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x480BEBu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    ++cpu->ebx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x22u)) goto label_00080BC6;
    label_00080BF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x480BF4u);
    ++cpu->ebx;
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    goto label_00080E77;
    label_00080BFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x480BFFu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x82u)) goto label_00080CD5;
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 9u);
    (void)cpu;
    label_00080C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x480C10u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x22u)) goto label_00080C3B;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x19u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80C2Eu), LIFT_CODE_TOKEN_RVA(0x80C2Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480C2Eu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80C3Bu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080C3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x480C3Bu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    cpu->ebx += 2u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x22u)) goto label_00080C75;
    label_00080C46: cpu->eip = LIFT_CODE_TOKEN_VA(0x480C46u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00080C6C;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x1Au); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80C5Fu), LIFT_CODE_TOKEN_RVA(0x80C5Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480C5Fu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80C6Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080C6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x480C6Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    ++cpu->ebx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x22u)) goto label_00080C46;
    label_00080C75: cpu->eip = LIFT_CODE_TOKEN_VA(0x480C75u);
    ++cpu->esi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480C84u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00080E77;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x2Cu)) goto label_00080E77;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480CA6u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080C10;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1Bu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80CC3u), LIFT_CODE_TOKEN_RVA(0x80CC1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480CC3u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480CD0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00080C10;
    label_00080CD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x480CD5u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(3u)) goto label_00080D7E;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080CEC;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080CF6;
    label_00080CEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x480CECu);
    cpu->ecx = 0x1Cu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80CF6u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080CF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x480CF6u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 7u);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x480D05u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480D0Bu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00080D20;
    cpu->ecx = 0x1Du;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480D1Du); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00080D20: cpu->eip = LIFT_CODE_TOKEN_VA(0x480D20u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080D2C;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080D20;
    label_00080D2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x480D2Cu);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0x3Au)) goto label_00080D3B;
    cpu->ecx = 0x1Eu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80D3Bu); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080D3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x480D3Bu);
    ++cpu->esi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480D49u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080D55;
    cpu->ecx = (uint32_t)(cpu->eax + 0x1Fu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80D55u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080D55: cpu->eip = LIFT_CODE_TOKEN_VA(0x480D55u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ebx += cpu->eax;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u) + 6u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_00080E77;
    label_00080D7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x480D7Eu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(4u)) goto label_00080DD1;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end), 0u);
    ++cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    g_sfera_config_parser_runtime.frame_depth = (uint32_t)(cpu->eax);
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480DA9u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080DB5;
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80DB5u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080DB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x480DB5u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edx)) == (uint8_t)(0x7Bu)) goto label_00080DC8;
    cpu->ecx = 0x21u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80DC8u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080DC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x480DC8u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    goto label_00080E77;
    label_00080DD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x480DD1u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x84u)) goto label_00080E25;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->esi = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end), cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 0xDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480DFAu); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080E06;
    cpu->ecx = (uint32_t)(cpu->esi + 0x21u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80E06u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080E06: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E06u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x7Bu)) goto label_00080E19;
    cpu->ecx = 0x23u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80E19u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080E19: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E19u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    g_sfera_config_parser_runtime.frame_depth += cpu->esi;
    goto label_00080E77;
    label_00080E25: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E25u);
    cpu->ecx = 0xCu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80E2Fu); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00080E2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E2Fu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080E3D;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080E63;
    label_00080E3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E3Du);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_00080E63;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xDu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80E56u), LIFT_CODE_TOKEN_RVA(0x80E54u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480E56u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80E63u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080E63: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E63u);
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->ebp + 7u);
    label_00080E67: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E67u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00080E77;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00080E67;
    label_00080E77: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E77u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x480E80u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00080687;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00080E8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x480E8Bu);
    if ((uint32_t)(g_sfera_config_parser_runtime.frame_depth) == (uint32_t)(0u)) goto label_00080EB9;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x480EA6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x480EACu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80EB9u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080EB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x480EB9u);
    cpu->eax = (uint32_t)(cpu->ebx + 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480F10u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00080F91;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::sprintf);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00080F30: cpu->eip = LIFT_CODE_TOKEN_VA(0x480F30u);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_00080F3B;
    if ((uint8_t)(lift_load8(cpu->esi + 1u)) != (uint8_t)(0u)) goto label_00080F5C;
    label_00080F3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x480F3Bu);
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x27u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x80F4Fu), LIFT_CODE_TOKEN_RVA(0x80F4Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480F4Fu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x80F5Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00080F5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x480F5Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    cpu->eax = lift_load8(cpu->esi);
    cpu->ecx = 7u;
    cpu->ecx -= cpu->edi;
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(0x30u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x30u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->edi;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    ++cpu->ebp;
    ++cpu->esi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ebp + 0xFFFFFFFFu, cpu->edx & 0xFFu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(6u)) goto label_00080F82;
    ++cpu->esi;
    label_00080F82: cpu->eip = LIFT_CODE_TOKEN_VA(0x480F82u);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(7u)) goto label_00080F8A;
    cpu->edi = 0u;
    label_00080F8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x480F8Au);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00080F30;
    cpu->ebx = lift_pop32(cpu);
    label_00080F91: cpu->eip = LIFT_CODE_TOKEN_VA(0x480F91u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00480FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480FA0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->edi = cpu->edi;
    label_00080FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x480FB0u);
    cpu->eax = lift_load8(cpu->esi);
    ++cpu->esi;
    g_sfera_config_parser_runtime.current_value_type = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x84u)) goto label_0008101C;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: case 1u: goto label_00080FCE;
        case 2u: goto label_00080FE3;
        case 3u: case 4u: case 130u: case 132u: goto label_00080FFB;
        case 5u: case 6u: goto label_00081028;
        case 128u: case 129u: goto label_00081012;
        default: goto label_0008101C;
    }
label_00080FCE: ;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->esi;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80FD5u), LIFT_CODE_TOKEN_RVA(0x80FD3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480FD5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00081031;
    cpu->ecx = cpu->ebx & 0xFFu;
    cpu->esi += cpu->ecx;
    goto label_00080FB0;
    label_00080FE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x480FE3u);
    cpu->ebx = lift_load16(cpu->esi);
    cpu->esi += 2u;
    cpu->edx = (uint32_t)(cpu->esi + 1u);
    label_00080FEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x480FECu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x80FF0u), LIFT_CODE_TOKEN_RVA(0x80FEEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x480FF0u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00081031;
    cpu->esi += cpu->ebx;
    goto label_00080FB0;
    label_00080FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x480FFBu);
    cpu->ebx = lift_load32(cpu->esi);
    cpu->esi += 4u;
    cpu->ecx = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81007u), LIFT_CODE_TOKEN_RVA(0x81005u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481007u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00081031;
    cpu->esi += cpu->ebx;
    goto label_00080FB0;
    label_00081012: cpu->eip = LIFT_CODE_TOKEN_VA(0x481012u);
    cpu->ebx = lift_load32(cpu->esi);
    cpu->esi += 4u;
    cpu->edx = (uint32_t)(cpu->esi + 4u);
    goto label_00080FEC;
    label_0008101C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48101Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: wrong address or corrupted data";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481026u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00080FB0;
    label_00081028: cpu->eip = LIFT_CODE_TOKEN_VA(0x481028u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00081031: cpu->eip = LIFT_CODE_TOKEN_VA(0x481031u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00081057;
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_config_parser_runtime.current_value_type)) goto label_0008106C;
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: wrong type of parameter. Name:";
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48104Eu); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00081057: cpu->eip = LIFT_CODE_TOKEN_VA(0x481057u);
    if ((uint8_t)((((uint8_t)g_sfera_config_parser_runtime.current_value_type)) & (0x80u)) != 0u) goto label_0008106C;
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: get size for non array. Name:";
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8106Cu); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0008106C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48106Cu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00481120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481120u);
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481127u); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008112E;
    lift_return(cpu, 4u, stop_address); return;
    label_0008112E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48112Eu);
    cpu->ecx = lift_load8(cpu->eax + 0xFFFFFFFFu);
    cpu->edx = lift_load32(cpu->ecx + cpu->eax + 0xFFFFFFFCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->eax = 1u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00481150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481150u);
    lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481157u); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008115E;
    lift_return(cpu, 4u, stop_address); return;
    label_0008115E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48115Eu);
    cpu->ecx = lift_load8(cpu->eax + 0xFFFFFFFFu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->eax + 0xFFFFFFFCu));
    cpu->eax = 1u;
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00481180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481180u);
    lift_push32(cpu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481187u); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008118E;
    lift_return(cpu, 4u, stop_address); return;
    label_0008118E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48118Eu);
    cpu->ecx = lift_load8(cpu->eax);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->eax = 1u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004811B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4811B0u);
    lift_push32(cpu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4811B7u); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000811E6;
    cpu->ecx = g_sfera_config_parser_runtime.current_value_type;
    cpu->ecx += 0xFFFFFF80u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(4u)) goto label_000811DC;
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: case 1u: goto label_000811D0;
        case 2u: case 4u: goto label_000811D3;
        case 3u: goto label_000811DC;
        default: lift_trap(cpu, 0x4811C9u, "resolved jump-table index out of range"); return;
    }
label_000811D0: ;
    cpu->eax = lift_load32(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
    label_000811D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4811D3u);
    cpu->ecx = lift_load8(cpu->eax);
    cpu->eax = lift_load16(cpu->ecx + cpu->eax + 1u);
    lift_return(cpu, 0u, stop_address); return;
    label_000811DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4811DCu);
    cpu->ecx = (uint32_t)(uintptr_t)"getCfgArraySize: internal error";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x811E6u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000811E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4811E6u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00481200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481200u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x80u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48120Bu); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00081215;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00081215: cpu->eip = LIFT_CODE_TOKEN_VA(0x481215u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00081222;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0008122C;
    label_00081222: cpu->eip = LIFT_CODE_TOKEN_VA(0x481222u);
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: index out of range";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8122Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008122C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48122Cu);
    cpu->edi -= lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFFCu);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx = lift_load32(cpu->ecx + cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00481250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481250u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x81u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48125Bu); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00081265;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00081265: cpu->eip = LIFT_CODE_TOKEN_VA(0x481265u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00081272;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0008127C;
    label_00081272: cpu->eip = LIFT_CODE_TOKEN_VA(0x481272u);
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: index out of range";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8127Cu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008127C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48127Cu);
    cpu->edi -= lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFFCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->esi));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004812A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4812A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x82u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4812ABu); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000812B5;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000812B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4812B5u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_000812CA;
    cpu->eax = lift_load8(cpu->esi);
    cpu->ecx = (int16_t)(lift_load16(cpu->eax + cpu->esi + 1u));
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ecx)) goto label_000812D4;
    label_000812CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4812CAu);
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: index out of range";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x812D4u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000812D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4812D4u);
    cpu->edx = lift_load8(cpu->esi);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 3u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000812EA;
    (void)cpu;
    label_000812E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4812E0u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->ecx = lift_load16(cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 2u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000812E0;
    label_000812EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4812EAu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += 2u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00481300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481300u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x84u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48130Bu); lift_push32(cpu, r); sfera_sub_00480FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00081315;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00081315: cpu->eip = LIFT_CODE_TOKEN_VA(0x481315u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_0008132A;
    cpu->eax = lift_load8(cpu->esi);
    cpu->ecx = lift_load16(cpu->eax + cpu->esi + 1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00081334;
    label_0008132A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48132Au);
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: index out of range";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81334u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081334: cpu->eip = LIFT_CODE_TOKEN_VA(0x481334u);
    cpu->edx = lift_load8(cpu->esi);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 3u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00081349;
    (void)cpu;
    label_00081340: cpu->eip = LIFT_CODE_TOKEN_VA(0x481340u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00081340;
    label_00081349: cpu->eip = LIFT_CODE_TOKEN_VA(0x481349u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00481360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481360u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = 0u;
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00081397;
    label_00081372: cpu->eip = LIFT_CODE_TOKEN_VA(0x481372u);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x481379u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48137Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081392;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)"openCfg: duplicate name: ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81392u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_00081392: cpu->eip = LIFT_CODE_TOKEN_VA(0x481392u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_00081372;
    label_00081397: cpu->eip = LIFT_CODE_TOKEN_VA(0x481397u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->eax)) goto label_000813BA;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, 0x410u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp");
    cpu->edx = (uint32_t)(cpu->eax + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4813B5u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx, cpu->eax);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(0x64u) + (uint64_t)(0u));
    label_000813BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4813BAu);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 4u), cpu->ebp);
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + 1u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004813D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4813D0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x422u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    cpu->ecx = 0x190u;
    lift_store32(cpu->esp + 0x18u, 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4813F5u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    label_00081401: cpu->eip = LIFT_CODE_TOKEN_VA(0x481401u);
    cpu->edi = lift_load8(cpu->esi);
    ++cpu->esi;
    if ((uint32_t)(cpu->edi) > (uint32_t)(0x84u)) goto label_000814EA;
    switch ((uint32_t)(cpu->edi)) {
        case 0u: case 1u: goto label_0008141F;
        case 2u: goto label_0008143C;
        case 3u: case 4u: case 130u: case 132u: goto label_0008145C;
        case 5u: case 6u: goto label_000814F9;
        case 128u: case 129u: goto label_000814C8;
        default: goto label_000814EA;
    }
label_0008141F: ;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->esi;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481435u); lift_push32(cpu, r); sfera_sub_00481360(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->ebx & 0xFFu;
    cpu->esi += cpu->edx;
    goto label_00081401;
    label_0008143C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48143Cu);
    cpu->edi = lift_load16(cpu->esi);
    cpu->esi += 2u;
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481458u); lift_push32(cpu, r); sfera_sub_00481360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += cpu->edi;
    goto label_00081401;
    label_0008145C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48145Cu);
    cpu->ebp = lift_load32(cpu->esi);
    cpu->esi += 4u;
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481477u); lift_push32(cpu, r); sfera_sub_00481360(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) != (uint32_t)(4u)) goto label_0008148F;
    cpu->edx = lift_load8(cpu->esi);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->esi + 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481488u); lift_push32(cpu, r); sfera_sub_004813D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += cpu->ebp;
    goto label_00081401;
    label_0008148F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48148Fu);
    if ((uint32_t)(cpu->edi) != (uint32_t)(0x84u)) goto label_000814C1;
    cpu->eax = lift_load8(cpu->esi);
    cpu->ecx = lift_load16(cpu->eax + cpu->esi + 1u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->esi + 3u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_000814C1;
    cpu->ebx = cpu->ecx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000814B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4814B0u);
    cpu->ecx = (uint32_t)(cpu->edi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4814B8u); lift_push32(cpu, r); sfera_sub_004813D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edi = (uint32_t)(cpu->edi + cpu->ecx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000814B0;
    label_000814C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4814C1u);
    cpu->esi += cpu->ebp;
    goto label_00081401;
    label_000814C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4814C8u);
    cpu->edi = lift_load32(cpu->esi);
    cpu->esi += 4u;
    cpu->edx = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4814E3u); lift_push32(cpu, r); sfera_sub_00481360(cpu,r); if (cpu->eip != r) return; }
    cpu->esi += cpu->edi;
    goto label_00081401;
    label_000814EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4814EAu);
    cpu->ecx = (uint32_t)(uintptr_t)"getCfg: wrong address or corrupted data";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4814F4u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00081401;
    label_000814F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4814F9u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0x44Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48150Cu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004815C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4815C0u);
    lift_push32(cpu, 0x4A3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\objparam.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4815CFu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004815D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4815D0u);
    g_sfera_config_parser_runtime.open_mode = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004815E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4815E0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_store32(cpu->esp + 4u, cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    g_sfera_config_parser_runtime.line_number = (uint32_t)(1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481602u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = native_function_address32(&::sprintf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000820E9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    label_00081612: cpu->eip = LIFT_CODE_TOKEN_VA(0x481612u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x7Du)) goto label_0008176B;
    if ((uint32_t)(g_sfera_config_parser_runtime.frame_depth) != (uint32_t)(0u)) goto label_0008164B;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x24u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8163Eu), LIFT_CODE_TOKEN_RVA(0x8163Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48163Eu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8164Bu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008164B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48164Bu);
    lift_store8(cpu->esi, 5u);
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->ebx = 1u;
    cpu->eax -= cpu->ebx;
    g_sfera_config_parser_runtime.frame_depth = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->esi += cpu->ebx;
    cpu->eax += cpu->eax;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008168B;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin));
    cpu->ecx -= cpu->eax;
    cpu->ecx -= 4u;
    cpu->ebp += cpu->ebx;
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    goto label_000820D6;
    label_0008168B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48168Bu);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].count_or_cursor));
    lift_store16(cpu->eax, (uint64_t)(lift_load16(cpu->eax)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u));
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end));
    cpu->ecx -= cpu->eax;
    cpu->ecx -= 4u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebp += cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4816B9u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008174E;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edx)) != (uint8_t)(0x2Cu)) goto label_0008174E;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end), cpu->esi);
    cpu->eax += cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->esi += 4u;
    g_sfera_config_parser_runtime.frame_depth = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4816F4u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008171A;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x25u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8170Du), LIFT_CODE_TOKEN_RVA(0x8170Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48170Du);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8171Au); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008171A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48171Au);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x7Bu)) goto label_00081745;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x26u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81738u), LIFT_CODE_TOKEN_RVA(0x81736u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481738u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81745u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081745: cpu->eip = LIFT_CODE_TOKEN_VA(0x481745u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    goto label_000820D6;
    label_0008174E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48174Eu);
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin));
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->ecx -= 4u;
    lift_store32(cpu->eax, cpu->ecx);
    goto label_000820D6;
    label_0008176B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48176Bu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_00081773;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_000817A1;
    label_00081773: cpu->eip = LIFT_CODE_TOKEN_VA(0x481773u);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_0008177B;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_000817A1;
    label_0008177B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48177Bu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x5Fu)) goto label_000817A1;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81794u), LIFT_CODE_TOKEN_RVA(0x81792u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481794u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x817A1u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000817A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4817A1u);
    cpu->ebx = 0u;
    label_000817A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4817A3u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    lift_store8(cpu->ebx + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.token[0]), cpu->eax & 0xFFu);
    ++cpu->ebx;
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(0xFAu)) goto label_000817D8;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x817CBu), LIFT_CODE_TOKEN_RVA(0x817C9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4817CBu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x817D8u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000817D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4817D8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_000817E3;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_000817A3;
    label_000817E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4817E3u);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_000817EB;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_000817A3;
    label_000817EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4817EBu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_000817F3;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_000817A3;
    label_000817F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4817F3u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x5Fu)) goto label_000817A3;
    lift_store8(cpu->ebx + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.token[0]), 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48180Cu); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081832;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81825u), LIFT_CODE_TOKEN_RVA(0x81823u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481825u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81832u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081832: cpu->eip = LIFT_CODE_TOKEN_VA(0x481832u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ebp)) == (uint8_t)(0x3Cu)) goto label_0008185D;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 5u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81850u), LIFT_CODE_TOKEN_RVA(0x8184Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481850u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8185Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008185D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48185Du);
    ++cpu->ebp;
    lift_store8(cpu->esi, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x61u)) goto label_0008186C;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x41u)) goto label_00081870;
    label_0008186C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48186Cu);
    lift_store8(cpu->esi, 0x80u);
    ++cpu->ebp;
    label_00081870: cpu->eip = LIFT_CODE_TOKEN_VA(0x481870u);
    cpu->eax = (int8_t)(lift_load8(cpu->ebp));
    cpu->eax += 0xFFFFFFBAu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x2Fu)) goto label_0008189D;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: case 32u: goto label_0008188A;
        case 3u: case 35u: goto label_000818BF;
        case 13u: case 45u: goto label_00081898;
        case 14u: case 46u: goto label_0008188E;
        case 15u: case 47u: goto label_00081893;
        default: goto label_0008189D;
    }
label_0008188A: ;
    lift_store8(cpu->esi, (uint64_t)(lift_load8(cpu->esi)) + 1u);
    goto label_000818BF;
    label_0008188E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48188Eu);
    lift_store8(cpu->esi, (uint64_t)(lift_load8(cpu->esi)) + (uint64_t)(2u) + (uint64_t)(0u));
    goto label_000818BF;
    label_00081893: cpu->eip = LIFT_CODE_TOKEN_VA(0x481893u);
    lift_store8(cpu->esi, (uint64_t)(lift_load8(cpu->esi)) + (uint64_t)(3u) + (uint64_t)(0u));
    goto label_000818BF;
    label_00081898: cpu->eip = LIFT_CODE_TOKEN_VA(0x481898u);
    lift_store8(cpu->esi, (uint64_t)(lift_load8(cpu->esi)) + (uint64_t)(4u) + (uint64_t)(0u));
    goto label_000818BF;
    label_0008189D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48189Du);
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 6u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x818B2u), LIFT_CODE_TOKEN_RVA(0x818B0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4818B2u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x818BFu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000818BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4818BFu);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x83u)) goto label_000818E5;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x818D8u), LIFT_CODE_TOKEN_RVA(0x818D6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4818D8u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x818E5u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000818E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4818E5u);
    if ((uint8_t)(lift_load8(cpu->ebp + 1u)) == (uint8_t)(0x3Eu)) goto label_0008190D;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 8u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81900u), LIFT_CODE_TOKEN_RVA(0x818FEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481900u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8190Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008190D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48190Du);
    cpu->ebp += 2u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48191Du); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081943;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 9u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81936u), LIFT_CODE_TOKEN_RVA(0x81934u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481936u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81943u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081943: cpu->eip = LIFT_CODE_TOKEN_VA(0x481943u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x3Du)) goto label_0008196E;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xAu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81961u), LIFT_CODE_TOKEN_RVA(0x8195Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481961u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8196Eu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008196E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48196Eu);
    cpu->ebp = 1u;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481980u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000819A6;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xBu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81999u), LIFT_CODE_TOKEN_RVA(0x81997u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481999u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x819A6u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000819A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4819A6u);
    cpu->eax = lift_load8(cpu->esi);
    cpu->esi += cpu->ebp;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008203A;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x80u)) goto label_00081AD5;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_000819CD;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_000819F2;
    label_000819CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4819CDu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_000819F2;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0xFu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x819E5u), LIFT_CODE_TOKEN_RVA(0x819E3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4819E5u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x819F2u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000819F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4819F2u);
    cpu->ecx = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->esi += 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->edi, 0u);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481A0Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481A14u);
    cpu->esp += 0xCu;
    cpu->esi += cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    goto label_00081A24;
    label_00081A20: cpu->eip = LIFT_CODE_TOKEN_VA(0x481A20u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    label_00081A24: cpu->eip = LIFT_CODE_TOKEN_VA(0x481A24u);
    lift_store32(cpu->ebx, (uint64_t)(lift_load32(cpu->ebx)) + (uint64_t)(4u) + (uint64_t)(0u));
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + 1u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481A30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481A36u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00081A64;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481A51u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481A57u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81A64u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081A64: cpu->eip = LIFT_CODE_TOKEN_VA(0x481A64u);
    cpu->esi += 4u;
    label_00081A67: cpu->eip = LIFT_CODE_TOKEN_VA(0x481A67u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00081A73;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00081A67;
    label_00081A73: cpu->eip = LIFT_CODE_TOKEN_VA(0x481A73u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481A80u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000820D0;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x2Cu)) goto label_000820D0;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481AA2u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081A20;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x11u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481ABDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481AC3u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481AD0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00081A20;
    label_00081AD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x481AD5u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_00081B7E;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00081AEC;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00081B16;
    label_00081AEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x481AECu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00081B16;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_00081B16;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x12u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81B09u), LIFT_CODE_TOKEN_RVA(0x81B07u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481B09u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81B16u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081B16: cpu->eip = LIFT_CODE_TOKEN_VA(0x481B16u);
    cpu->eax = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    ++cpu->esi;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481B23u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481B29u);
    cpu->esi += cpu->ebx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481B32u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481B38u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00081B62;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x13u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x81B55u), LIFT_CODE_TOKEN_RVA(0x81B53u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481B55u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81B62u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081B62: cpu->eip = LIFT_CODE_TOKEN_VA(0x481B62u);
    cpu->esi += 4u;
    label_00081B65: cpu->eip = LIFT_CODE_TOKEN_VA(0x481B65u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00081B71;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00081B65;
    label_00081B71: cpu->eip = LIFT_CODE_TOKEN_VA(0x481B71u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00081B65;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    goto label_000820D6;
    label_00081B7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x481B7Eu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x81u)) goto label_00081C94;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00081B98;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00081BAA;
    label_00081B98: cpu->eip = LIFT_CODE_TOKEN_VA(0x481B98u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00081BAA;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_00081BAA;
    cpu->ecx = 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81BAAu); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081BAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x481BAAu);
    cpu->edx = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi, cpu->edx);
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->esi += 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->edi, 0u);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481BC6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481BCCu);
    cpu->esp += 0xCu;
    cpu->esi += cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    goto label_00081BE0;
    label_00081BD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x481BD7u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    label_00081BE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x481BE0u);
    lift_store32(cpu->ebx, (uint64_t)(lift_load32(cpu->ebx)) + (uint64_t)(4u) + (uint64_t)(0u));
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + 1u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481BECu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481BF2u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00081C1F;
    cpu->eax = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0x15u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481C0Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481C12u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81C1Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081C1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x481C1Fu);
    cpu->esi += 4u;
    label_00081C22: cpu->eip = LIFT_CODE_TOKEN_VA(0x481C22u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00081C2E;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00081C22;
    label_00081C2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x481C2Eu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00081C22;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481C3Fu); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000820D0;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x2Cu)) goto label_000820D0;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481C61u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081BD7;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x16u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481C7Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481C82u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481C8Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00081BD7;
    label_00081C94: cpu->eip = LIFT_CODE_TOKEN_VA(0x481C94u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00081D25;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ebp)) == (uint8_t)(0x22u)) goto label_00081CAF;
    cpu->ecx = (uint32_t)(cpu->eax + 0x15u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81CAFu); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081CAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x481CAFu);
    cpu->eax = (uint32_t)(cpu->ebx + 2u);
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi + 2u, cpu->ebx & 0xFFu);
    cpu->edi = cpu->esi;
    cpu->esi += 3u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    ++cpu->ebp;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481CC5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481CCBu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    cpu->esp += 0xCu;
    cpu->esi += cpu->ebx;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x22u)) goto label_00081D17;
    cpu->ebx = native_function_address32(&::sprintf);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00081CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x481CE0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00081D06;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x18u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x81CF9u), LIFT_CODE_TOKEN_RVA(0x81CF7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x481CF9u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81D06u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081D06: cpu->eip = LIFT_CODE_TOKEN_VA(0x481D06u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    lift_store8(cpu->esi, cpu->edx & 0xFFu);
    lift_store16(cpu->edi, (uint64_t)(lift_load16(cpu->edi)) + 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x22u)) goto label_00081CE0;
    label_00081D17: cpu->eip = LIFT_CODE_TOKEN_VA(0x481D17u);
    lift_store8(cpu->esi, 0u);
    ++cpu->esi;
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    goto label_000820D0;
    label_00081D25: cpu->eip = LIFT_CODE_TOKEN_VA(0x481D25u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x82u)) goto label_00081E54;
    cpu->eax = (uint32_t)(cpu->ebx + 3u);
    lift_store32(cpu->esi, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi + 4u, cpu->ebx & 0xFFu);
    cpu->ebp = cpu->esi;
    cpu->esi += 5u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481D44u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481D4Au);
    cpu->esi += cpu->ebx;
    cpu->ecx = 0u;
    cpu->esp += 0xCu;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_store16(cpu->esi, cpu->ecx & 0xFFFFu);
    cpu->esi += 2u;
    label_00081D60: cpu->eip = LIFT_CODE_TOKEN_VA(0x481D60u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edi)) == (uint8_t)(0x22u)) goto label_00081D8F;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x19u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481D7Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481D82u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81D8Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081D8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x481D8Fu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store16(cpu->eax, (uint64_t)(lift_load16(cpu->eax)) + 1u);
    lift_store32(cpu->ebp, (uint64_t)(lift_load32(cpu->ebp)) + (uint64_t)(3u) + (uint64_t)(0u));
    cpu->eax = 1u;
    ++cpu->edi;
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->ebx = cpu->esi;
    cpu->esi += 2u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x22u)) goto label_00081DED;
    cpu->edi = cpu->edi;
    label_00081DB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x481DB0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00081DDA;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1Au); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481DC7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481DCDu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81DDAu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00081DDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x481DDAu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store8(cpu->esi, cpu->edx & 0xFFu);
    lift_store32(cpu->ebp, (uint64_t)(lift_load32(cpu->ebp)) + 1u);
    lift_store16(cpu->ebx, (uint64_t)(lift_load16(cpu->ebx)) + 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x22u)) goto label_00081DB0;
    label_00081DED: cpu->eip = LIFT_CODE_TOKEN_VA(0x481DEDu);
    lift_store8(cpu->esi, 0u);
    ++cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481DFFu); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000820D0;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x2Cu)) goto label_000820D0;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481E21u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081D60;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1Bu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x481E3Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481E42u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481E4Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    goto label_00081D60;
    label_00081E54: cpu->eip = LIFT_CODE_TOKEN_VA(0x481E54u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_00081F2E;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00081E6C;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00081E76;
    label_00081E6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x481E6Cu);
    cpu->ecx = 0x1Cu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81E76u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081E76: cpu->eip = LIFT_CODE_TOKEN_VA(0x481E76u);
    cpu->edx = (uint32_t)(cpu->ebx + 1u);
    lift_store32(cpu->esi, cpu->edx);
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi + 4u, cpu->ebx & 0xFFu);
    cpu->edi = cpu->esi;
    cpu->esi += 5u;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481E8Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481E90u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->ebp);
    cpu->esi += cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x481E9Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481EA3u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00081EB5;
    cpu->ecx = 0x1Du;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81EB5u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081EB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x481EB5u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00081EC1;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_00081EB5;
    label_00081EC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x481EC1u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    if ((uint8_t)(lift_load8(cpu->ebp)) == (uint8_t)(0x3Au)) goto label_00081ED7;
    cpu->ecx = 0x1Eu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81ED7u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081ED7: cpu->eip = LIFT_CODE_TOKEN_VA(0x481ED7u);
    ++cpu->ebp;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481EE5u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081EF1;
    cpu->ecx = (uint32_t)(cpu->eax + 0x1Fu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81EF1u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081EF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x481EF1u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481F03u); lift_push32(cpu, r); sfera_sub_00480F10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esi += cpu->eax;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u) + 6u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->ebx += cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    goto label_000820D0;
    label_00081F2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x481F2Eu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_00081FA2;
    cpu->ecx = g_sfera_config_parser_runtime.frame_depth;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin), cpu->esi);
    cpu->ecx += cpu->ebp;
    cpu->esi += 4u;
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end), 0u);
    g_sfera_config_parser_runtime.frame_depth = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    cpu->esi += cpu->ebp;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481F66u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481F6Cu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->esi += cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x481F7Au); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081F86;
    cpu->ecx = (uint32_t)(cpu->eax + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81F86u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081F86: cpu->eip = LIFT_CODE_TOKEN_VA(0x481F86u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x7Bu)) goto label_00081F99;
    cpu->ecx = 0x21u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x81F99u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00081F99: cpu->eip = LIFT_CODE_TOKEN_VA(0x481F99u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    goto label_000820D6;
    label_00081FA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x481FA2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x84u)) goto label_00082030;
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_store32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].container_begin), cpu->esi);
    cpu->esi += 4u;
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    cpu->esi += cpu->ebp;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x481FCAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x481FD0u);
    cpu->eax = 0u;
    lift_store16(cpu->esi + cpu->ebx, cpu->eax & 0xFFFFu);
    cpu->eax = g_sfera_config_parser_runtime.frame_depth;
    cpu->esi += cpu->ebx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].count_or_cursor), cpu->esi);
    cpu->esi += 2u;
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.frames[0].payload_end), cpu->esi);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->esi += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x482002u); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008200E;
    cpu->ecx = (uint32_t)(cpu->eax + 0x22u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8200Eu); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_0008200E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48200Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(0x7Bu)) goto label_00082021;
    cpu->ecx = 0x23u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x82021u); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_00082021: cpu->eip = LIFT_CODE_TOKEN_VA(0x482021u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    g_sfera_config_parser_runtime.frame_depth += cpu->ebp;
    goto label_000820D6;
    label_00082030: cpu->eip = LIFT_CODE_TOKEN_VA(0x482030u);
    cpu->ecx = 0xCu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8203Au); lift_push32(cpu, r); sfera_sub_00480630(cpu,r); if (cpu->eip != r) return; }
    label_0008203A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48203Au);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_00082049;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_0008206F;
    label_00082049: cpu->eip = LIFT_CODE_TOKEN_VA(0x482049u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Du)) goto label_0008206F;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xDu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82062u), LIFT_CODE_TOKEN_RVA(0x82060u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482062u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8206Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0008206F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48206Fu);
    cpu->eax = (uint32_t)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ebx);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    ++cpu->esi;
    lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.token[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x48207Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x482082u);
    cpu->esi += cpu->ebx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x48208Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x482091u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_000820BB;
    cpu->ecx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xEu); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x820AEu), LIFT_CODE_TOKEN_RVA(0x820ACu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4820AEu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x820BBu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_000820BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4820BBu);
    cpu->esi += 4u;
    cpu->edi = cpu->edi;
    label_000820C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4820C0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x30u)) goto label_000820D0;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x39u)) goto label_000820C0;
    label_000820D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4820D0u);
    cpu->edi = native_function_address32(&::sprintf);
    label_000820D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4820D6u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4820DFu); lift_push32(cpu, r); sfera_sub_004805D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00081612;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000820E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4820E9u);
    if ((uint32_t)(g_sfera_config_parser_runtime.frame_depth) == (uint32_t)(0u)) goto label_00082114;
    cpu->edx = g_sfera_config_parser_runtime.line_number;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"parse_error: %d. Line %d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_parser_runtime.error_message[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x82107u), LIFT_CODE_TOKEN_RVA(0x82105u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x482107u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_parser_runtime.error_message[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x82114u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00082114: cpu->eip = LIFT_CODE_TOKEN_VA(0x482114u);
    cpu->eax = cpu->esi;
    cpu->eax -= lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi, 6u);
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}
